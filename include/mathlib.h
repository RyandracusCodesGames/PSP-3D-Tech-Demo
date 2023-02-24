#ifndef MATHLIB_H
#define MATHLIB_H
/**Essential Data Types and Function Macros*/
#define PI 3.14159265
#define TRUE 1
#define FALSE 0
#define degToRad(a) ((a)*(PI/180.00))
#define radToDeg(a) ((a)*(180.00/PI))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define CLAMP(targetValue, minVal, maxVal) (MIN(MAX(targetValue, minVal), maxVal))
#define sqrt(a) ((a)*(a))
#define lerp(a, b, t) ((a)+t*(a-b))
#define flerp(a, b, t) ((1 - (t)) * (a) + (t) * (b))
#define inverse_lerp(a, b, t) (((t) - (a)) / ((b) - (a)))
/**Fundamental Linear Algebra Types and Functions*/
typedef struct
{
	float x, y, z, w;
}vec3f;

typedef struct
{
	float u, v, w;
}vec2f;

typedef struct
{
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;
}MATRIX;

typedef struct
{
	vec3f v1, v2, v3;
}SIMPLE_TRIANGLE;

typedef struct
{
	vec3f v1, v2, v3;
	vec2f vt1, vt2, vt3;
	int col;
}TRIANGLE;
/*Utility Functions*/
float fixAng(float a);
float Q_rsqrt(float number);
void SWAP(int *a, int *b);

/**Vector Functions*/
void vec3f_add(vec3f v1, vec3f v2, vec3f *out);
void vec3f_sub(vec3f v1, vec3f v2, vec3f *out);
void vec3f_mul_by_scalar(vec3f *v1, float factor);
void vec3f_div_by_scalar(vec3f *v1, float factor);
float dotProduct(vec3f v1, vec3f v2);
float length(vec3f v1);
void normalize(vec3f v1, vec3f *out);
void crossProduct(vec3f *v1, vec3f *v2, vec3f *out);
void inverseVector(vec3f *v1);
void copyVector(vec3f *v1, vec3f *v2);
int compareVectors(vec3f v1, vec3f v2);
int vectorsAreCloseEnough(vec3f v1, vec3f v2, float err);
int isFacingTowards(vec3f v1, vec3f v2);
/**Matrix Functions*/
void MatrixMakeIdentity(MATRIX *m);
void MatrixMakeTranslation(MATRIX *m, float tX, float tY, float tZ);
void MatrixMakeScale(MATRIX *m, float sX, float sY, float sZ);
void projectionMatrix(MATRIX *m, float a, float fov, float fNear, float fFar);
void MatrixMakeRotX(MATRIX *m, float angle);
void MatrixMakeRotY(MATRIX *m, float angle);
void MatrixMakeRotZ(MATRIX *m, float angle);
void MultiplyMatrixVector(vec3f *in, vec3f *out, MATRIX *m);
void MatrixMatrixMultiplication(MATRIX *m1, MATRIX *m2, MATRIX *out);
void pointAtMatrix();
void inverseMatrix(MATRIX *m);
#endif