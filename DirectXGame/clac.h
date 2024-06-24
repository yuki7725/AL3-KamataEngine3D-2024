#pragma once
#include <cmath>
#include <Matrix4x4.h>
#include <Vector3.h>

//Matrix4x4 MakeAffineMatrix(Matrix4x4 scaleMatrix, Matrix4x4 rotateXYZMatrix, Matrix4x4 translate) {
//	Matrix4x4 result = {};
//
//	result.m[0][0] = scaleMatrix.m[0][0] * rotateXYZMatrix.m[0][0];
//	result.m[0][1] = scaleMatrix.m[0][0] * rotateXYZMatrix.m[0][1];
//	result.m[0][2] = scaleMatrix.m[0][0] * rotateXYZMatrix.m[0][2];
//	result.m[0][3] = 0;
//
//	result.m[1][0] = scaleMatrix.m[1][1] * rotateXYZMatrix.m[1][0];
//	result.m[1][1] = scaleMatrix.m[1][1] * rotateXYZMatrix.m[1][1];
//	result.m[1][2] = scaleMatrix.m[1][1] * rotateXYZMatrix.m[1][2];
//	result.m[1][3] = 0;
//
//	result.m[2][0] = scaleMatrix.m[2][2] * rotateXYZMatrix.m[2][0];
//	result.m[2][1] = scaleMatrix.m[2][2] * rotateXYZMatrix.m[2][1];
//	result.m[2][2] = scaleMatrix.m[2][2] * rotateXYZMatrix.m[2][2];
//	result.m[2][3] = 0;
//
//	result.m[3][0] = translate.m[3][0];
//	result.m[3][1] = translate.m[3][1];
//	result.m[3][2] = translate.m[3][2];
//	result.m[3][3] = 1;
//
//	return result;
//}
//
//Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
//	Matrix4x4 result = {};
//
//	result.m[0][0] = scale.x;
//	result.m[0][1] = 0;
//	result.m[0][2] = 0;
//	result.m[0][3] = 0;
//
//	result.m[1][0] = 0;
//	result.m[1][1] = scale.y;
//	result.m[1][2] = 0;
//	result.m[1][3] = 0;
//
//	result.m[2][0] = 0;
//	result.m[2][1] = 0;
//	result.m[2][2] = scale.z;
//	result.m[2][3] = 0;
//
//	result.m[3][0] = 0;
//	result.m[3][1] = 0;
//	result.m[3][2] = 0;
//	result.m[3][3] = 1;
//
//	return result;
//}
//
//Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
//	Matrix4x4 result = {};
//
//	result.m[0][0] = 1;
//	result.m[0][1] = 0;
//	result.m[0][2] = 0;
//	result.m[0][3] = 0;
//
//	result.m[1][0] = 0;
//	result.m[1][1] = 1;
//	result.m[1][2] = 0;
//	result.m[1][3] = 0;
//
//	result.m[2][0] = 0;
//	result.m[2][1] = 0;
//	result.m[2][2] = 1;
//	result.m[2][3] = 0;
//
//	result.m[3][0] = translate.x;
//	result.m[3][1] = translate.y;
//	result.m[3][2] = translate.z;
//	result.m[3][3] = 1;
//
//	return result;
//}
//
//Matrix4x4 MakeRotateXMatrix(float radian) {
//	Matrix4x4 result = {};
//
//	result.m[0][0] = 1;
//	result.m[0][1] = 0;
//	result.m[0][2] = 0;
//	result.m[0][3] = 0;
//
//	result.m[1][0] = 0;
//	result.m[1][1] = std::cos(radian);
//	result.m[1][2] = std::sin(radian);
//	result.m[1][3] = 0;
//
//	result.m[2][0] = 0;
//	result.m[2][1] = -std::sin(radian);
//	result.m[2][2] = std::cos(radian);
//	result.m[2][3] = 0;
//
//	result.m[3][0] = 0;
//	result.m[3][1] = 0;
//	result.m[3][2] = 0;
//	result.m[3][3] = 1;
//
//	return result;
//}
//
//Matrix4x4 MakeRotateYMatrix(float radian) {
//	Matrix4x4 result = {};
//
//	result.m[0][0] = std::cos(radian);
//	result.m[0][1] = 0;
//	result.m[0][2] = -std::sin(radian);
//	result.m[0][3] = 0;
//
//	result.m[1][0] = 0;
//	result.m[1][1] = 1;
//	result.m[1][2] = 0;
//	result.m[1][3] = 0;
//
//	result.m[2][0] = std::sin(radian);
//	result.m[2][1] = 0;
//	result.m[2][2] = std::cos(radian);
//	result.m[2][3] = 0;
//
//	result.m[3][0] = 0;
//	result.m[3][1] = 0;
//	result.m[3][2] = 0;
//	result.m[3][3] = 1;
//
//	return result;
//}
//
//Matrix4x4 MakeRotateZMatrix(float radian) {
//	Matrix4x4 result = {};
//
//	result.m[0][0] = std::cos(radian);
//	result.m[0][1] = std::sin(radian);
//	result.m[0][2] = 0;
//	result.m[0][3] = 0;
//
//	result.m[1][0] = -std::sin(radian);
//	result.m[1][1] = std::cos(radian);
//	result.m[1][2] = 0;
//	result.m[1][3] = 0;
//
//	result.m[2][0] = 0;
//	result.m[2][1] = 0;
//	result.m[2][2] = 1;
//	result.m[2][3] = 0;
//
//	result.m[3][0] = 0;
//	result.m[3][1] = 0;
//	result.m[3][2] = 0;
//	result.m[3][3] = 1;
//
//	return result;
//}
//
//Matrix4x4 Multiply(const Matrix4x4 m1, const Matrix4x4 m2) {
//	Matrix4x4 result = {};
//
//	for (int m = 0; m < 4; m++) {
//		for (int n = 0; n < 4; n++) {
//			result.m[m][n] = 0;
//			for (int i = 0; i < 4; i++) {
//				result.m[m][n] += m1.m[m][i] * m2.m[i][n];
//			}
//		}
//	}
//
//	return result;
//}

static Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result = {};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return result;
};
static Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result = {};

	result.m[0][0] = 1.0f;
	result.m[1][1] = 1.0f;
	result.m[2][2] = 1.0f;
	result.m[3][3] = 1.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;

	return result;
};

static Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result = {};

	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;
	result.m[3][3] = 1.0f;

	return result;
};

static Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 result = {};
	result.m[0][0] = 1;
	result.m[3][3] = 1;
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = std::sin(radian);
	result.m[2][1] = -1 * std::sin(radian);
	result.m[2][2] = std::cos(radian);

	return result;
};
static Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 result = {};
	result.m[1][1] = 1;
	result.m[3][3] = 1;
	result.m[0][0] = std::cos(radian);
	result.m[0][2] = -1 * std::sin(radian);
	result.m[2][0] = std::sin(radian);
	result.m[2][2] = std::cos(radian);

	return result;
};
static Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 result = {};
	result.m[2][2] = 1;
	result.m[3][3] = 1;
	result.m[0][0] = std::cos(radian);
	result.m[0][1] = std::sin(radian);
	result.m[1][0] = -1 * std::sin(radian);
	result.m[1][1] = std::cos(radian);

	return result;
};

static Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result = {};

	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);

	Matrix4x4 rotateXYZMatrix = Multiply(Multiply(rotateXMatrix, rotateYMatrix), rotateZMatrix);

	result = Multiply(Multiply(MakeScaleMatrix(scale), rotateXYZMatrix), MakeTranslateMatrix(translate));

	return result;
}