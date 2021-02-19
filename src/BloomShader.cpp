#include "BloomShader.hpp"

glb::BloomShader::BloomShader()
{
    if (!sf::Shader::isAvailable()) { return; }
    const std::string code = R"FRAGMENT_SHADER(
        uniform sampler2D texture;
        uniform float tex_width;
        uniform float tex_height;
        uniform int blur_radius;

        void main()
        {
            vec2 texel_size = 1.0 / vec2(tex_width, tex_height);
            int i, j;
            vec4 sum = vec4(0);
            for(i = -blur_radius; i <= blur_radius; i++)
            {
                for(j = -blur_radius; j <= blur_radius; j++)
                {
                    vec2 offset = vec2(i, j) * texel_size;
                    sum += texture2D(texture, gl_TexCoord[0].xy + offset);
                }
            }
            float count = float((blur_radius * 2 + 1) * (blur_radius * 2 + 1));
            vec4 glow = (sum / count);
            gl_FragColor = texture2D(texture, gl_TexCoord[0].xy) + glow * 2.0;
        }
    )FRAGMENT_SHADER";

    loadFromMemory(code, sf::Shader::Fragment);
    setUniform("blur_radius", 5);
}

void glb::BloomShader::setTexture(const sf::Texture& texture)
{
    if (!sf::Shader::isAvailable()) { return; }
    setUniform("texture", texture);
    setUniform("tex_width", float(texture.getSize().x));
    setUniform("tex_height", float(texture.getSize().y));
}
