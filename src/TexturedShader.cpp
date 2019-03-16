#include "TexturedShader.h"

#include <Corrade/Containers/Reference.h>
#include <Corrade/Utility/Resource.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/Shader.h>
#include <Magnum/GL/Version.h>

namespace Magnum {

TexturedShader::TexturedShader(){
	MAGNUM_ASSERT_GL_VERSION_SUPPORTED(GL::Version::GL330);

	const Utility::Resource rs{"textured-triangle-data"};

	GL::Shader vert{GL::Version::GL330, GL::Shader::Type::Vertex};
	GL::Shader frag{GL::Version::GL330, GL::Shader::Type::Fragment};

	vert.addSource(rs.get("TexturedShader.vert"));
	frag.addSource(rs.get("TexturedShader.frag"));

	CORRADE_INTERNAL_ASSERT_OUTPUT(GL::Shader::compile({vert, frag}));

	attachShaders({vert, frag});

	CORRADE_INTERNAL_ASSERT_OUTPUT(link());

	_colorUniform = uniformLocation("color");

	setUniform(uniformLocation("textureData"), TextureLayer);
}


TexturedShader::TexturedShader& setColor(const Color3& color) {
	setUniform(_colorUniform, color);
	return *this;
}

TexturedShader::TexturedShader& bindTexture(GL::Texture2D& texture) {
	texture.bind(TextureLayer);
	return *this;
}

}
