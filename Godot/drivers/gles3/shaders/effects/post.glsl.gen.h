/**************************************************************************/
/*  post.glsl.gen.h                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

/* THIS FILE IS GENERATED. EDITS WILL BE LOST. */

#pragma once

#include "drivers/gles3/shader_gles3.h"

class PostShaderGLES3 : public ShaderGLES3 {
public:
	enum Uniforms {
		VIEW,
		LUMINANCE_MULTIPLIER,
		PIXEL_SIZE,
		GLOW_INTENSITY,
		SRGB_WHITE,
		SSAO_INTENSITY,
		SSAO_RADIUS_FRAC,
		SSAO_PRN_UV,
	};

	enum ShaderVariant {
		MODE_DEFAULT,
	};

	enum Specializations {
		USE_MULTIVIEW = 1,
		USE_GLOW = 2,
		USE_LUMINANCE_MULTIPLIER = 4,
		USE_BCS = 8,
		USE_COLOR_CORRECTION = 16,
		USE_1D_LUT = 32,
		USE_SSAO_ABYSS = 64,
		USE_SSAO_LOW = 128,
		USE_SSAO_MED = 256,
		USE_SSAO_HIGH = 512,
		USE_SSAO_MEGA = 1024,
	};

	_FORCE_INLINE_ bool version_bind_shader(RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		return _version_bind_shader(p_version, p_variant, p_specialization);
	}

	_FORCE_INLINE_ int version_get_uniform(Uniforms p_uniform, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		return _version_get_uniform(p_uniform, p_version, p_variant, p_specialization);
	}

	/* clang-format off */
#define TRY_GET_UNIFORM(var_name) int var_name = version_get_uniform(p_uniform, p_version, p_variant, p_specialization); if (var_name < 0) return
	/* clang-format on */

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, float p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1f(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, double p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1f(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, uint8_t p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1ui(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, int8_t p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1i(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, uint16_t p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1ui(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, int16_t p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1i(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, uint32_t p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1ui(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, int32_t p_value, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform1i(uniform_location, p_value);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Color &p_color, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		GLfloat col[4] = { p_color.r, p_color.g, p_color.b, p_color.a };
		glUniform4fv(uniform_location, 1, col);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Vector2 &p_vec2, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		GLfloat vec2[2] = { float(p_vec2.x), float(p_vec2.y) };
		glUniform2fv(uniform_location, 1, vec2);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Size2i &p_vec2, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		GLint vec2[2] = { GLint(p_vec2.x), GLint(p_vec2.y) };
		glUniform2iv(uniform_location, 1, vec2);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Vector3 &p_vec3, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		GLfloat vec3[3] = { float(p_vec3.x), float(p_vec3.y), float(p_vec3.z) };
		glUniform3fv(uniform_location, 1, vec3);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Vector4 &p_vec4, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		GLfloat vec4[4] = { float(p_vec4.x), float(p_vec4.y), float(p_vec4.z), float(p_vec4.w) };
		glUniform4fv(uniform_location, 1, vec4);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, float p_a, float p_b, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform2f(uniform_location, p_a, p_b);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, float p_a, float p_b, float p_c, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform3f(uniform_location, p_a, p_b, p_c);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, float p_a, float p_b, float p_c, float p_d, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		glUniform4f(uniform_location, p_a, p_b, p_c, p_d);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Transform3D &p_transform, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		const Transform3D &tr = p_transform;

		GLfloat matrix[16] = { /* build a 16x16 matrix */
			(GLfloat)tr.basis.rows[0][0],
			(GLfloat)tr.basis.rows[1][0],
			(GLfloat)tr.basis.rows[2][0],
			(GLfloat)0,
			(GLfloat)tr.basis.rows[0][1],
			(GLfloat)tr.basis.rows[1][1],
			(GLfloat)tr.basis.rows[2][1],
			(GLfloat)0,
			(GLfloat)tr.basis.rows[0][2],
			(GLfloat)tr.basis.rows[1][2],
			(GLfloat)tr.basis.rows[2][2],
			(GLfloat)0,
			(GLfloat)tr.origin.x,
			(GLfloat)tr.origin.y,
			(GLfloat)tr.origin.z,
			(GLfloat)1
		};

		glUniformMatrix4fv(uniform_location, 1, false, matrix);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Transform2D &p_transform, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		const Transform2D &tr = p_transform;

		GLfloat matrix[16] = { /* build a 16x16 matrix */
			(GLfloat)tr.columns[0][0],
			(GLfloat)tr.columns[0][1],
			(GLfloat)0,
			(GLfloat)0,
			(GLfloat)tr.columns[1][0],
			(GLfloat)tr.columns[1][1],
			(GLfloat)0,
			(GLfloat)0,
			(GLfloat)0,
			(GLfloat)0,
			(GLfloat)1,
			(GLfloat)0,
			(GLfloat)tr.columns[2][0],
			(GLfloat)tr.columns[2][1],
			(GLfloat)0,
			(GLfloat)1
		};

		glUniformMatrix4fv(uniform_location, 1, false, matrix);
	}

	_FORCE_INLINE_ void version_set_uniform(Uniforms p_uniform, const Projection &p_matrix, RID p_version, ShaderVariant p_variant, uint64_t p_specialization = 0) {
		TRY_GET_UNIFORM(uniform_location);
		GLfloat matrix[16];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i * 4 + j] = p_matrix.columns[i][j];
			}
		}

		glUniformMatrix4fv(uniform_location, 1, false, matrix);
	}

#undef TRY_GET_UNIFORM

protected:
	virtual void _init() override {
		static const char *_uniform_strings[] = {
			"view",
			"luminance_multiplier",
			"pixel_size",
			"glow_intensity",
			"srgb_white",
			"ssao_intensity",
			"ssao_radius_frac",
			"ssao_prn_UV"
		};
		static const char *_variant_defines[] = {
			"",
		};
		static TexUnitPair _texunit_pairs[] = {
			{ "source_color", 0 },
			{ "glow_color", 1 },
			{ "source_color_correction", 2 },
			{ "depth_buffer_array", 3 },
			{ "depth_buffer", 3 },
		};
		static UBOPair _ubo_pairs[] = {
			{ "TonemapData", 0 },
		};
		static Specialization _spec_pairs[] = {
			{ "USE_MULTIVIEW", false },
			{ "USE_GLOW", false },
			{ "USE_LUMINANCE_MULTIPLIER", false },
			{ "USE_BCS", false },
			{ "USE_COLOR_CORRECTION", false },
			{ "USE_1D_LUT", false },
			{ "USE_SSAO_ABYSS", false },
			{ "USE_SSAO_LOW", false },
			{ "USE_SSAO_MED", false },
			{ "USE_SSAO_HIGH", false },
			{ "USE_SSAO_MEGA", false },
		};
		static const Feedback *_feedbacks = nullptr;
		static const char _vertex_code[] = {
R"<!>(layout(location = 0) in vec2 vertex_attrib;

/* clang-format on */

out vec2 uv_interp;

void main() {
	uv_interp = vertex_attrib * 0.5 + 0.5;
	gl_Position = vec4(vertex_attrib, 1.0, 1.0);
}

/* clang-format off */
)<!>"
		};

		static const char _fragment_code[] = {
(R"<!>(/* clang-format on */

// If we reach this code, we always tonemap.
#define APPLY_TONEMAPPING

layout(std140) uniform TonemapData { //ubo:0
	float exposure;
	float white;
	int tonemapper;
	int pad;

	int pad2;
	float brightness;
	float contrast;
	float saturation;
};

// This expects 0-1 range input.
vec3 linear_to_srgb(vec3 color) {
	//color = clamp(color, vec3(0.0), vec3(1.0));
	//const vec3 a = vec3(0.055f);
	//return mix((vec3(1.0f) + a) * pow(color.rgb, vec3(1.0f / 2.4f)) - a, 12.92f * color.rgb, lessThan(color.rgb, vec3(0.0031308f)));
	// Approximation from http://chilliant.blogspot.com/2012/08/srgb-approximations-for-hlsl.html
	return max(vec3(1.055) * pow(color, vec3(0.416666667)) - vec3(0.055), vec3(0.0));
}

// This expects 0-1 range input, outside that range it behaves poorly.
vec3 srgb_to_linear(vec3 color) {
	// Approximation from http://chilliant.blogspot.com/2012/08/srgb-approximations-for-hlsl.html
	return color * (color * (color * 0.305306011 + 0.682171111) + 0.012522878);
}

#ifdef APPLY_TONEMAPPING

// Based on Reinhard's extended formula, see equation 4 in https://doi.org/cjbgrt
vec3 tonemap_reinhard(vec3 color, float p_white) {
	float white_squared = p_white * p_white;
	vec3 white_squared_color = white_squared * color;
	// Equivalent to color * (1 + color / white_squared) / (1 + color)
	return (white_squared_color + color * color) / (white_squared_color + white_squared);
}

vec3 tonemap_filmic(vec3 color, float p_white) {
	// exposure bias: input scale (color *= bias, white *= bias) to make the brightness consistent with other tonemappers
	// also useful to scale the input to the range that the tonemapper is designed for (some require very high input values)
	// has no effect on the curve's general shape or visual properties
	const float exposure_bias = 2.0f;
	const float A = 0.22f * exposure_bias * exposure_bias; // bias baked into constants for performance
	const float B = 0.30f * exposure_bias;
	const float C = 0.10f;
	const float D = 0.20f;
	const float E = 0.01f;
	const float F = 0.30f;

	vec3 color_tonemapped = ((color * (A * color + C * B) + D * E) / (color * (A * color + B) + D * F)) - E / F;
	float p_white_tonemapped = ((p_white * (A * p_white + C * B) + D * E) / (p_white * (A * p_white + B) + D * F)) - E / F;

	return color_tonemapped / p_white_tonemapped;
}

// Adapted from https://github.com/TheRealMJP/BakingLab/blob/master/BakingLab/ACES.hlsl
// (MIT License).
vec3 tonemap_aces(vec3 color, float p_white) {
	const float exposure_bias = 1.8f;
	const float A = 0.0245786f;
	const float B = 0.000090537f;
	const float C = 0.983729f;
	const float D = 0.432951f;
	const float E = 0.238081f;

	// Exposure bias baked into transform to save shader instructions. Equivalent to `color *= exposure_bias`
	const mat3 rgb_to_rrt = mat3(
			vec3(0.59719f * exposure_bias, 0.35458f * exposure_bias, 0.04823f * exposure_bias),
			vec3(0.07600f * exposure_bias, 0.90834f * exposure_bias, 0.01566f * exposure_bias),
			vec3(0.02840f * exposure_bias, 0.13383f * exposure_bias, 0.83777f * exposure_bias));

	const mat3 odt_to_rgb = mat3(
			vec3(1.60475f, -0.53108f, -0.07367f),
			vec3(-0.10208f, 1.10813f, -0.00605f),
			vec3(-0.00327f, -0.07276f, 1.07602f));

	color *= rgb_to_rrt;
	vec3 color_tonemapped = (color * (color + A) - B) / (color * (C * color + D) + E);
	color_tonemapped *= odt_to_rgb;

	p_white *= exposure_bias;
	float p_white_tonemapped = (p_white * (p_white + A) - B) / (p_white * (C * p_white + D) + E);

	return color_tonemapped / p_white_tonemapped;
}

// Polynomial approximation of EaryChow's AgX sigmoid curve.
// x must be within the range [0.0, 1.0]
vec3 agx_contrast_approx(vec3 x) {
	// Generated with Excel trendline
	// Input data: Generated using python sigmoid with EaryChow's configuration and 57 steps
	// Additional padding values were added to give correct intersections at 0.0 and 1.0
	// 6th order, intercept of 0.0 to remove an operation and ensure intersection at 0.0
	vec3 x2 = x * x;
	vec3 x4 = x2 * x2;
	return 0.021 * x + 4.0111 * x2 - 25.682 * x2 * x + 70.359 * x4 - 74.778 * x4 * x + 27.069 * x4 * x2;
}

// This is an approximation and simplification of EaryChow's AgX implementation that is used by Blender.
// This code is based off of the script that generates the AgX_Base_sRGB.cube LUT that Blender uses.
// Source: https://github.com/EaryChow/AgX_LUT_Gen/blob/main/AgXBasesRGB.py
vec3 tonemap_agx(vec3 color) {
	// Combined linear sRGB to linear Rec 2020 and Blender AgX inset matrices:
	const mat3 srgb_to_rec2020_agx_inset_matrix = mat3(
			0.54490813676363087053, 0.14044005884001287035, 0.088827411851915368603,
			0.37377945959812267119, 0.75410959864013760045, 0.17887712465043811023,
			0.081384976686407536266, 0.10543358536857773485, 0.73224999956948382528);

	// Combined inverse AgX outset matrix and linear Rec 2020 to linear sRGB matrices.
	const mat3 agx_outset_rec2020_to_srgb_matrix = mat3(
			1.9645509602733325934, -0.29932243390911083839, -0.16436833806080403409,
			-0.85585845117807513559, 1.3264510741502356555, -0.23822464068860595117,
			-0.10886710826831608324, -0.027084020983874825605, 1.402665347143271889);

	// LOG2_MIN      = -10.0
	// LOG2_MAX      =  +6.5
	// MIDDLE_GRAY   =  0.18
	const float min_ev = -12.4739311883324; // log2(pow(2, LOG2_MIN) * MIDDLE_GRAY)
	const float max_ev = 4.02606881166759; // log2(pow(2, LOG2_MAX) * MIDDLE_GRAY)

	// Large negative values in one channel and large positive values in other
	// channels can result in a colour that appears darker and more saturated than
	// desired after passing it through the inset matrix. For this reason, it is
	// best to prevent negative input values.
	// This is done before the Rec. 2020 transform to allow the Rec. 2020
	// transform to be combined with the AgX inset matrix. This results in a loss
	// of color information that could be correctly interpreted within the
	// Rec. 2020 color space as positive RGB values, but it is less common for Godot
	// to provide this function with negative sRGB values and therefore not worth
	// the performance cost of an additional matrix multiplication.
	// A value of 2e-10 intentionally introduces insignificant error to prevent
	// log2(0.0) after the inset matrix is applied; color will be >= 1e-10 after
	// the matrix transform.
	color = max(color, 2e-10);

	// Do AGX in rec2020 to match Blender and then apply inset matrix.
	color = srgb_to_rec2020_agx_inset_matrix * color;

	// Log2 space encoding.
	// Must be clamped because agx_contrast_approx may not work
	// well with values outside of the range [0.0, 1.0]
	color = clamp(log2(color), min_ev, max_ev);
	color = (color - min_ev) / (max_ev - min_ev);

	// Apply sigmoid function approximation.
	color = agx_contrast_approx(color);

	// Convert back to linear before applying outset matrix.
	color = pow(color, vec3(2.4));

	// Apply outset to make the result more chroma-laden and then go back to linear sRGB.
	color = agx_outset_rec2020_to_srgb_matrix * color;

	// Blender's lusRGB.compensate_low_side is too complex for this shader, so
	// simply return the color, even if it has negative components. These negative
	// components may be useful for subsequent color adjustments.
	return color;
}

#define TONEMAPPER_LINEAR 0
#define TONEMAPPER_REINHARD 1
#define TONEMAPPER_FILMIC 2
#define TONEMAPPER_ACES 3
#define TONEMAPPER_AGX 4

vec3 apply_tonemapping(vec3 color, float p_white) { // inputs are LINEAR
	// Ensure color values passed to tonemappers are positive.
	// They can be negative in the case of negative lights, which leads to undesired behavior.
	if (tonemapper == TONEMAPPER_LINEAR) {
		return color;
	} else if (tonemapper == TONEMAPPER_REINHARD) {
		return tonemap_reinhard(max(vec3(0.0f), color), p_white);
	} else if (tonemapper == TONEMAPPER_FILMIC) {
		return tonemap_filmic(max(vec3(0.0f), color), p_white);
	} else if (tonemapper == TONEMAPPER_ACES) {
		return tonemap_aces(max(vec3(0.0f), color), p_white);
	} else { // TONEMAPPER_AGX
		return tonemap_agx(color);
	}
}

#endif // APPLY_TONEMAPPING

#ifdef USE_MULTIVIEW
uniform sampler2DArray source_color; // texunit:0
#else
uniform sampler2D source_color; // texunit:0
#endif // USE_MULTIVIEW

uniform float view;
uniform float luminance_multiplier;

#ifdef USE_GLOW
uniform sampler2D glow_color; // texunit:1
uniform vec2 pixel_size;
uniform float glow_intensity;
uniform float srgb_white;

vec4 get_glow_color(vec2 uv) {
	vec2 half_pixel = pixel_size * 0.5;

	vec4 color = textureLod(glow_color, uv + vec2(-half_pixel.x * 2.0, 0.0), 0.0);
	color += textureLod(glow_color, uv + vec2(-half_pixel.x, half_pixel.y), 0.0) * 2.0;
	color += textureLod(glow_color, uv + vec2(0.0, half_pixel.y * 2.0), 0.0);
	color += textureLod(glow_color, uv + vec2(half_pixel.x, half_pixel.y), 0.0) * 2.0;
	color += textureLod(glow_color, uv + vec2(half_pixel.x * 2.0, 0.0), 0.0);
	color += textureLod(glow_color, uv + vec2(half_pixel.x, -half_pixel.y), 0.0) * 2.0;
	color += textureLod(glow_color, uv + vec2(0.0, -half_pixel.y * 2.0), 0.0);
	color += textureLod(glow_color, uv + vec2(-half_pixel.x, -half_pixel.y), 0.0) * 2.0;

#ifdef USE_LUMINANCE_MULTIPLIER
	color = color / luminance_multiplier;
#endif

	return color / 12.0;
}
#endif // USE_GLOW

#ifdef USE_COLOR_CORRECTION
#ifdef USE_1D_LUT
uniform sampler2D source_color_correction; //texunit:2

vec3 apply_color_correction(vec3 color) {
	color.r = texture(source_color_correction, vec2(color.r, 0.0f)).r;
	color.g = texture(source_color_correction, vec2(color.g, 0.0f)).g;
	color.b = texture(source_color_correction, vec2(color.b, 0.0f)).b;
	return color;
}
#else
uniform sampler3D source_color_correction; //texunit:2

vec3 apply_color_correction(vec3 color) {
	return textureLod(source_color_correction, color, 0.0).rgb;
}
#endif // USE_1D_LUT
#endif // USE_COLOR_CORRECTION

#if defined(USE_SSAO_ABYSS) || defined(USE_SSAO_LOW) || defined(USE_SSAO_MED) || defined(USE_SSAO_HIGH) || defined(USE_SSAO_MEGA)
#define USE_SOME_SSAO
uniform float ssao_intensity;
uniform float ssao_radius_frac;
uniform vec2 ssao_prn_UV;
#ifdef USE_MULTIVIEW
// VR will have 2 depth buffers.
uniform sampler2DArray depth_buffer_array; // texunit:3
#else
uniform sampler2D depth_buffer; // texunit:3
#endif
#if defined(USE_SSAO_ABYSS)
// Use the tiny 2-sample version.
// S4AO (Stupid Simple Screen Space Ambient Occlusion) - Jonathan Dummer (O1S)
// This micro version uses only 3 depth samples, the midpoint and a randomly-rotated, balanced pair.

const mediump float ssao_falloff_frac = 0.25;
// Perform the SSAO.
float s4ao(vec2 UV) {
#ifdef USE_MULTIVIEW
	mediump float depth = texture(depth_buffer_array, vec3(UV, view)).r;
#else
	mediump float depth = texture(depth_buffer, UV).r;
#endif
	mediump float inv_falloff = 1.0f / max(1e-4f, depth * ssao_falloff_frac);
	// Random 2D rotation per pixel (0..1 -> parabola approximating a 180 deg arc)
	mediump float r01 = fract(dot(UV, ssao_prn_UV));
	mediump vec2 duv = vec2(r01 - 0.5f, 2.0f * (r01 - r01 * r01)) * (2.0f * depth * ssao_radius_frac); // 180 degrees.
	// Grab the samples and determine the occlusion.
	mediump float occlusion = 0.0f;
	for (int s = 0; s < 2; ++s) {
#ifdef USE_MULTIVIEW
		mediump float dz = texture(depth_buffer_array, vec3(UV + duv, view)).r - depth;
#else
		mediump float dz = texture(depth_buffer, UV + duv).r - depth;
#endif
		// How 'directly overhead' is it?  Factor in the falloff depth.
		occlusion += normalize(vec3(duv, dz)).z * mix(1.0f, 0.0f, dz * inv_falloff);
		// Mirror the next sample.
		duv = -duv;
	}
	// Adjust the occlusion for intensity, and # samples.
	occlusion = 1.0f - clamp(occlusion * 0.5f * ssao_intensity, 0.0f, 1.0f);
	return occlusion * occlusion;
}
#elif defined(USE_SSAO_HIGH) || defined(USE_SSAO_MEGA)
// Use the rings version for the higher qualities.
// S4AO (Stupid Simple Screen Space Ambient Occlusion) - Jonathan Dummer (O1S)
// The mega version uses N concentric rings of samples.

#if defined(USE_SSAO_MEGA)
const int rings = 4; // Start with the outer ring.
const int samps[] = int[](24, 18, 12, 6); // ( 9, 6, 3 ) is a minimum, but I want better.
#else
const int rings = 3; // Start with the outer ring.
const int samps[] = int[](15, 10, 5, 1); // ( 9, 6, 3 ) is a minimum, but I want better.
#endif
const float average_samples = 1.0 / float(samps[0] + samps[1] * int(rings > 1) + samps[2] * int(rings > 2) + samps[3] * int(rings > 3));
const float ssao_falloff_frac = 0.25;
// Perform the SSAO.
float s4ao(vec2 UV) {
#ifdef USE_MULTIVIEW
	float depth = texture(depth_buffer_array, vec3(UV, view)).r;
#else
	float depth = texture(depth_buffer, UV).r;
#endif
	float inv_falloff = 1.0f / max(1e-4f, depth * ssao_falloff_frac);
	// Random 2D rotation per pixel (0..1 -> parabola approximating a 180 deg arc)
	float r01 = fract(dot(UV, ssao_prn_UV));
	vec2 rcos = vec2(r01 - 0.5f, 2.0f * (r01 - r01 * r01)) * (2.0f * depth * ssao_radius_frac); // 180 degrees.
	vec2 rsin = rcos.yx * vec2(-1, 1); // Perpendicular to the random cosine vector.
	// Grab the samples and determine the occlusion.
	float occlusion = 0.0f;
	float ring_shrink = 0.75f; // Shrink every ring.
	for (int r = 0; r < rings; ++r) {
		float dt = (6.283185307f) / float(samps[r]);
		float t = float(r & 1) * 0.5f * dt;
		for (int s = 0; s < samps[r]; ++s) {
			vec2 duv = cos(t) * rcos + sin(t) * rsin;
#ifdef USE_MULTIVIEW
			float dz = texture(depth_buffer_array, vec3(UV + duv, view)).r - depth;
#else
			float dz = texture(depth_buffer, UV + duv).r - depth;
#endif
			// How 'directly overhead' is it?  Factor in the falloff depth.
			occlusion += normalize(vec3(duv, dz)).z * smoothstep(1.0f, 0.0f, dz * inv_falloff);
			t += dt;
		}
		// The next ring will be smaller.
		rcos *= ring_shrink;
		rsin *= ring_shrink;
	}
	// Adjust the occlusion for intensity, and # samples.
	occlusion *= ssao_intensity * average_samples;
	occlusion = 1.0f - clamp(occlusion, 0.0f, 1.0f);
	return occlusion * occlusion;
}
#else
// Use the more generic NxN grid version.
// S4AO (Stupid Simple Screen Space Ambient Occlusion) - Jonathan Dummer (O1S)
)<!>" R"<!>(
// The sample_width should be even, else the midpoint is at UV.
// Takes sample_width^2 samples in a grid, with the corners notched.
#if defined(USE_SSAO_LOW)
const int sample_width = 2;
#elif defined(USE_SSAO_HIGH)
const int sample_width = 6;
#else
const int sample_width = 4;
#endif
const int notch_01 = int(sample_width > 3); // Set to 1 to skip the corner samples, 0 to include them.
const float sample_mid = (float(sample_width) - 1.0) * 0.50001; // Can't be exactly 0.5 in case sample_width is odd.
#if defined(USE_SSAO_LOW)
const float inv_half_width = 1.0 / sample_mid; // The 2x2 sampling looks wider as all samples are at radius.
#else
const float inv_half_width = 1.7 / sample_mid; // Bake in the 1.7 scale for the random rotation.
#endif
const float average_samples = 1.0 / float(sample_width * sample_width - 4 * notch_01); //  1 / number_of_samples
const float ssao_falloff_frac = 0.25;
// Perform the SSAO.
float s4ao(vec2 UV) {
#ifdef USE_MULTIVIEW
	float depth = texture(depth_buffer_array, vec3(UV, view)).r;
#else
	float depth = texture(depth_buffer, UV).r;
#endif
	float radius = max(1e-4f, depth * ssao_radius_frac);
	float inv_falloff = 1.0f / max(1e-4f, depth * ssao_falloff_frac);
	// Random 2D rotation per pixel (+/-45 deg, with 0 having a lower probability).
	// The random cosine vector is vec2( 0.5, -0.5 to +0.5 ) and *1.7 makes the average length ~ 1.
	vec2 rcos = (inv_half_width * radius) * vec2(0.5f, fract(dot(UV, ssao_prn_UV)) - 0.5f);
	vec2 rsin = rcos.yx * vec2(-1, 1); // Perpendicular to the random cosine vector.
	// Grab the samples and determine the occlusion.
	float occlusion = 0.0f;
	vec2 base_duv = -sample_mid * rsin;
	for (int j = sample_width; --j >= 0;) {
#if defined(USE_SSAO_LOW)
		// Low quality uses 2x2 samples, no notching.
		vec2 duv = -sample_mid * rcos + base_duv;
		for (int i = sample_width; --i >= 0;) {
#else
		//	Will uses 4x4 or 6x6 samples, with the corners notched out.
		int o = /*notch_01 &*/ int((j <= 0) || (j >= (sample_width - 1))); // Notch corners of the grid.
		vec2 duv = (float(o) - sample_mid) * rcos + base_duv;
		for (int i = sample_width - o - o; --i >= 0;) {
#endif
#ifdef USE_MULTIVIEW
			float dz = texture(depth_buffer_array, vec3(UV + duv, view)).r - depth;
#else
			float dz = texture(depth_buffer, UV + duv).r - depth;
#endif
			float validity = smoothstep(1.0f, 0.0f, dz * inv_falloff);
			occlusion += normalize(vec3(duv, dz)).z * validity; // How 'directly overhead' is it?
			duv += rcos; // March along the rcos direction with i.
		}
		base_duv += rsin; // March along the rsin direction with j.
	}
	// Adjust the occlusion for intensity, and # samples.
	occlusion *= ssao_intensity * average_samples;
	occlusion = clamp(1.0f - occlusion, 0.0f, 1.0f);
	return occlusion * occlusion;
}
#endif
#endif

in vec2 uv_interp;

layout(location = 0) out vec4 frag_color;

void main() {
#ifdef USE_MULTIVIEW
	vec4 color = texture(source_color, vec3(uv_interp, view));
#else
	vec4 color = texture(source_color, uv_interp);
#endif

#ifdef USE_LUMINANCE_MULTIPLIER
	color = color / luminance_multiplier;
#endif

#ifdef USE_GLOW
	// Glow blending is performed before srgb_to_linear because
	// the glow texture was created from a nonlinear sRGB-encoded
	// scene, so it only makes sense to add this glow to an equally
	// nonlinear sRGB-encoded scene.

	vec4 glow = get_glow_color(uv_interp) * glow_intensity;

	// Glow always uses the screen blend mode in the Compatibility renderer:

	// Glow cannot be above 1.0 after normalizing and should be non-negative
	// to produce expected results. It is possible that glow can be negative
	// if negative lights were used in the scene.
	// We clamp to srgb_white because glow will be normalized to this range.
	// Note: srgb_white cannot be smaller than the maximum output value (1.0).
	glow.rgb = clamp(glow.rgb, 0.0, srgb_white);

	// Normalize to srgb_white range.
	//glow.rgb /= srgb_white;
	//color.rgb /= srgb_white;
	//color.rgb = (color.rgb + glow.rgb) - (color.rgb * glow.rgb);
	// Expand back to original range.
	//color.rgb *= srgb_white;

	// The following is a mathematically simplified version of the above.
	color.rgb = color.rgb + glow.rgb - (color.rgb * glow.rgb / srgb_white);
#endif // USE_GLOW

	color.rgb = srgb_to_linear(color.rgb);

#if defined(USE_SOME_SSAO)
	// Putting SSAO after the conversion to linear color, though it might be better before the glow.
	color.rgb *= s4ao(uv_interp); // The USE_SSAO_X controls the number of samples.
#endif

	color.rgb = apply_tonemapping(color.rgb, white);

#ifdef USE_BCS
	// Apply brightness:
	// Apply to relative luminance. This ensures that the hue and saturation of
	// colors is not affected by the adjustment, but requires the multiplication
	// to be performed on linear-encoded values.
	color.rgb = color.rgb * brightness;

	color.rgb = linear_to_srgb(color.rgb);

	// Apply contrast:
	// By applying contrast to RGB values that are perceptually uniform (nonlinear),
	// the darkest values are not hard-clipped as badly, which produces a
	// higher quality contrast adjustment and maintains compatibility with
	// existing projects.
	color.rgb = mix(vec3(0.5), color.rgb, contrast);

	// Apply saturation:
	// By applying saturation adjustment to nonlinear sRGB-encoded values with
	// even weights the preceived brightness of blues are affected, but this
	// maintains compatibility with existing projects.
	color.rgb = mix(vec3(dot(vec3(1.0), color.rgb) * (1.0 / 3.0)), color.rgb, saturation);
#else
	color.rgb = linear_to_srgb(color.rgb);
#endif // USE_BCS

#ifdef USE_COLOR_CORRECTION
	color.rgb = apply_color_correction(color.rgb);
#endif

	frag_color = color;
}
)<!>")
		};

		_setup(_vertex_code, _fragment_code, "PostShaderGLES3",
				8, _uniform_strings, 1, _ubo_pairs,
				0, _feedbacks, 5, _texunit_pairs,
				11, _spec_pairs, 1, _variant_defines);
	}
};
