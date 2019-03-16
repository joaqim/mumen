#pragma once

#include <Magnum/GL/AbstractShaderProgram.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/Math/Color.h>

namespace Magnum {

class TexturedShader: public GL::AbstractShaderProgram {
	public:
		typedef GL::Attribute<0, Vector2> Position;
		typedef GL::Attribute<1, Vector2> TextureCoordinates;

		explicit TexturedShader();

		TexturedShader& setColor(const Color3& color);

		TexturedShader& bindTexture(GL::Texture2D& texture);

	private:
enum: Int { TextureLayer = 0 };

      Int _colorUniform;
};

}
