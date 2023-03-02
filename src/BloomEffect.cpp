#include "BloomEffect.hpp"

glb::BloomEffect::BloomEffect(sf::RenderTarget& renderTarget)
    : renderTarget(renderTarget)
{
    if (!sf::Shader::isAvailable()) { return; }

    pingpong[0].create(renderTarget.getSize().x, renderTarget.getSize().y);
    pingpong[1].create(renderTarget.getSize().x, renderTarget.getSize().y);

    const std::string blurShaderCode = R"BLUR_SHADER(
        uniform sampler2D texture;
        uniform float tex_width;
        uniform float tex_height;
        uniform bool horizontal;

        void main()
        {
            // float weight[5] = float[5](0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);
            float weight[5];
            weight[0] = 0.227027;
            weight[1] = 0.1945946;
            weight[2] = 0.1216216;
            weight[3] = 0.054054;
            weight[4] = 0.016216;

            vec2 texel_size = 1.0 / vec2(tex_width, tex_height);
            int i, j;
            vec3 sum = texture2D(texture, gl_TexCoord[0].xy).rgb * weight[0];
            if(horizontal)
            {
                for(int i = 1; i < 5; ++i)
                {
                    sum += texture2D(texture, gl_TexCoord[0].xy + vec2(texel_size.x * float(i), 0.0)).rgb * weight[i];
                    sum += texture2D(texture, gl_TexCoord[0].xy - vec2(texel_size.x * float(i), 0.0)).rgb * weight[i];
                }
            }
            else
            {
                for(int i = 1; i < 5; ++i)
                {
                    sum += texture2D(texture, gl_TexCoord[0].xy + vec2(0.0, texel_size.y * float(i))).rgb * weight[i];
                    sum += texture2D(texture, gl_TexCoord[0].xy - vec2(0.0, texel_size.y * float(i))).rgb * weight[i];
                }
            }
            gl_FragColor = vec4(sum, 1.0);
        }
    )BLUR_SHADER";

    blurShader.loadFromMemory(blurShaderCode, sf::Shader::Fragment);
    blurShader.setUniform("texture", sf::Shader::CurrentTexture);

    const std::string combineShaderCode = R"COMBINE_SHADER(
        uniform sampler2D texture;
        uniform sampler2D blur_texture;
        uniform float exposure;

        void main()
        {
            const float gamma = 2.2;
            vec3 tex_color = texture2D(texture, gl_TexCoord[0].xy).rgb;
            vec3 blur_color = texture2D(blur_texture, gl_TexCoord[0].xy).rgb;
            tex_color += blur_color; // additive blending
            vec3 result = vec3(1.0) - exp(-tex_color * exposure); // tone mapping
            result = pow(result, vec3(1.0 / gamma)); // gamma correction
            gl_FragColor = vec4(result, 1.0); // TODO reuse alpha?
        }

    )COMBINE_SHADER";

    combineShader.loadFromMemory(combineShaderCode, sf::Shader::Fragment);
    combineShader.setUniform("texture", sf::Shader::CurrentTexture);
}

void glb::BloomEffect::render(const sf::Texture& texture)
{
    bool horizontal = true, firstIteration = true;
    int blurPassCount = 5;
    blurShader.setUniform("tex_width", float(texture.getSize().x));
    blurShader.setUniform("tex_height", float(texture.getSize().y));

    for (unsigned int blurPass = 0; blurPass < blurPassCount; blurPass++)
    {
        blurShader.setUniform("horizontal", horizontal);
        const sf::Texture& inputTexture = firstIteration
            ? texture
            : pingpong[!horizontal].getTexture();
        pingpong[horizontal].draw(sf::Sprite(inputTexture), &blurShader);

        horizontal = !horizontal;
        if (firstIteration) { firstIteration = false; }
    }

    combineShader.setUniform("blur_texture", pingpong[1].getTexture());
    combineShader.setUniform("exposure", 1.f);

    renderTarget.draw(sf::Sprite(texture), &combineShader);
}
