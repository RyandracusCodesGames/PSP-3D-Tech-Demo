#include "include/mathlib.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>

/**Lookup Tables(LUTS) For The Three Basic Trigonometric Functions
 /**
  Look-up table(LUT) for the radian values of the trig function sin
  with each index of the array representing a degree value.
*/
float sins[] = 
{0.0000f,0.0175f,0.0349f,0.0523f,0.0698f,0.0872f,0.1045f,0.1219f,0.1392f,0.1564f,0.1736f,0.1908f,0.2079f,0.2250f,0.2419f,0.2588f,0.2756f,0.2924f,0.3090f,0.3256f,0.3420f,
 0.3584f,0.3746f,0.3907f,0.4067f,0.4226f,0.4384f,0.4540f,0.4695f,0.4848f,0.5000f,0.5150f,0.5299f,0.5446f,0.5592f,0.5736f,0.5878f,0.6018f,0.6157f,0.6293f,0.6428f,
 0.6561f,0.6691f,0.6820f,0.6947f,0.7071f,0.7193f,0.7314f,0.7431f,0.7547f,0.7660f,0.7771f,0.7880f,0.7986f,0.8090f,0.8192f,0.8290f,0.8387f,0.8480f,0.8572f,0.8660f,
 0.8746f,0.8829f,0.8910f,0.8988f,0.9063f,0.9135f,0.9205f,0.9272f,0.9336f,0.9397f,0.9455f,0.9511f,0.9563f,0.9613f,0.9659f,0.9703f,0.9744f,0.9781f,0.9816f,0.9848f,
 0.9877f,0.9903f,0.9925f,0.9945f,0.9962f,0.9976f,0.9986f,0.9994f,0.9998f,1.0000f,0.9998f,0.9994f,0.9986f,0.9976f,0.9962f,0.9945f,0.9925f,0.9903f,0.9877f,0.9848f,
 0.9816f,0.9781f,0.9744f,0.9703f,0.9659f,0.9613f,0.9563f,0.9511f,0.9455f,0.9397f,0.9336f,0.9272f,0.9205f,0.9135f,0.9063f,0.8988f,0.8910f,0.8829f,0.8746f,0.8660f,
 0.8572f,0.8480f,0.8387f,0.8290f,0.8192f,0.8090f,0.7986f,0.7880f,0.7771f,0.7660f,0.7547f,0.7431f,0.7314f,0.7193f,0.7071f,0.6947f,0.6820f,0.6691f,0.6561f,0.6428f,
 0.6293f,0.6157f,0.6018f,0.5878f,0.5736f,0.5592f,0.5446f,0.5299f,0.5150f,0.5000f,0.4848f,0.4695f,0.4540f,0.4384f,0.4226f,0.4067f,0.3907f,0.3746f,0.3584f,0.3420f,
 0.3256f,0.3090f,0.2924f,0.2756f,0.2588f,0.2419f,0.2250f,0.2079f,0.1908f,0.1736f,0.1564f,0.1392f,0.1219f,0.1045f,0.0872f,0.0698f,0.0523f,0.0349f,0.0175f,0.0000f,
-0.0175f,-0.0349f,-0.0523f,-0.0698f,-0.0872f,-0.1045f,-0.1219f,-0.1392f,-0.1564f,-0.1736f,-0.1908f,-0.2079f,-0.2250f,-0.2419f,-0.2588f,-0.2756f,-0.2924f,-0.3090f,-0.3256f,-0.3420f,
-0.3584f,-0.3746f,-0.3907f,-0.4067f,-0.4226f,-0.4384f,-0.4540f,-0.4695f,-0.4848f,-0.5000f,-0.5150f,-0.5299f,-0.5446f,-0.5592f,-0.5736f,-0.5878f,-0.6018f,-0.6157f,-0.6293f,-0.6428f,
-0.6561f,-0.6691f,-0.6820f,-0.6947f,-0.7071f,-0.7193f,-0.7314f,-0.7431f,-0.7547f,-0.7660f,-0.7771f,-0.7880f,-0.7986f,-0.8090f,-0.8192f,-0.8290f,-0.8387f,-0.8480f,-0.8572f,-0.8660f,
-0.8746f,-0.8829f,-0.8910f,-0.8988f,-0.9063f,-0.9135f,-0.9205f,-0.9272f,-0.9336f,-0.9397f,-0.9455f,-0.9511f,-0.9563f,-0.9613f,-0.9659f,-0.9703f,-0.9744f,-0.9781f,-0.9816f,-0.9848f,
-0.9877f,-0.9903f,-0.9925f,-0.9945f,-0.9962f,-0.9976f,-0.9986f,-0.9994f,-0.9998f,-1.0000f,-0.9998f,-0.9994f,-0.9986f,-0.9976f,-0.9962f,-0.9945f,-0.9925f,-0.9903f,-0.9877f,-0.9848f,
-0.9816f,-0.9781f,-0.9744f,-0.9703f,-0.9659f,-0.9613f,-0.9563f,-0.9511f,-0.9455f,-0.9397f,-0.9336f,-0.9272f,-0.9205f,-0.9135f,-0.9063f,-0.8988f,-0.8910f,-0.8829f,-0.8746f,-0.8660f,
-0.8572f,-0.8480f,-0.8387f,-0.8290f,-0.8192f,-0.8090f,-0.7986f,-0.7880f,-0.7771f,-0.7660f,-0.7547f,-0.7431f,-0.7314f,-0.7193f,-0.7071f,-0.6947f,-0.6820f,-0.6691f,-0.6561f,-0.6428f,
-0.6293f,-0.6157f,-0.6018f,-0.5878f,-0.5736f,-0.5592f,-0.5446f,-0.5299f,-0.5150f,-0.5000f,-0.4848f,-0.4695f,-0.4540f,-0.4384f,-0.4226f,-0.4067f,-0.3907f,-0.3746f,-0.3584f,-0.3420f,
-0.3256f,-0.3090f,-0.2924f,-0.2756f,-0.2588f,-0.2419f,-0.2250f,-0.2079f,-0.1908f,-0.1736f,-0.1564f,-0.1392f,-0.1219f,-0.1045f,-0.0872f,-0.0698f,-0.0523f,-0.0349f,-0.0175f,-0.0000f
};

 /**
  Look-up table(LUT) for the radian values of the trig function cos
  with each index of the array representing a degree value.
*/
float coss[] =
{1.000f,0.9998f,0.9994f,0.9986f,0.9976f,0.9962f,0.9945f,0.9925f,0.9903f,0.9877f,0.9848f,0.9816f,0.9781f,0.9744f,0.9703f,0.9659f,0.9613f,0.9563f,0.9511f,0.9455f,0.9397f,
 0.9336f,0.9272f,0.9205f,0.9135f,0.9063f,0.8988f,0.8910f,0.8829f,0.8746f,0.8660f,0.8572f,0.8480f,0.8387f,0.8290f,0.8192f,0.8090f,0.7986f,0.7880f,0.7771f,0.7660f,
 0.7547f,0.7431f,0.7314f,0.7193f,0.7071f,0.6947f,0.6820f,0.6691f,0.6561f,0.6428f,0.6293f,0.6157f,0.6018f,0.5878f,0.5736f,0.5592f,0.5446f,0.5299f,0.5150f,0.5000f,
 0.4848f,0.4695f,0.4540f,0.4384f,0.4226f,0.4067f,0.3907f,0.3746f,0.3584f,0.3420f,0.3256f,0.3090f,0.2924f,0.2756f,0.2588f,0.2419f,0.2250f,0.2079f,0.1908f,0.1736f,
 0.1564f,0.1392f,0.1219f,0.1045f,0.0872f,0.0698f,0.0523f,0.0349f,0.0175f,0.0000f,-0.0175f,-0.0349f,-0.0523f,-0.0698f,-0.0872f,-0.1045f,-0.1219f,-0.1392f,-0.1564f,-0.1736f,
-0.1908f,-0.2079f,-0.2250f,-0.2419f,-0.2588f,-0.2756f,-0.2924f,-0.3090f,-0.3256f,-0.3420f,-0.3584f,-0.3746f,-0.3907f,-0.4067f,-0.4226f,-0.4384f,-0.4540f,-0.4695f,-0.4848f,-0.5000f,
-0.5150f,-0.5299f,-0.5446f,-0.5592f,-0.5736f,-0.5878f,-0.6018f,-0.6157f,-0.6293f,-0.6428f,-0.6561f,-0.6691f,-0.6820f,-0.6947f,-0.7071f,-0.7193f,-0.7314f,-0.7431f,-0.7547f,-0.7660f,
-0.7771f,-0.7880f,-0.7986f,-0.8090f,-0.8192f,-0.8290f,-0.8387f,-0.8480f,-0.8572f,-0.8660f,-0.8746f,-0.8829f,-0.8910f,-0.8988f,-0.9063f,-0.9135f,-0.9205f,-0.9272f,-0.9336f,-0.9397f,
-0.9455f,-0.9511f,-0.9563f,-0.9613f,-0.9659f,-0.9703f,-0.9744f,-0.9781f,-0.9816f,-0.9848f,-0.9877f,-0.9903f,-0.9925f,-0.9945f,-0.9962f,-0.9976f,-0.9986f,-0.9994f,-0.9998f,-1.0000f,
-0.9998f,-0.9994f,-0.9986f,-0.9976f,-0.9962f,-0.9945f,-0.9925f,-0.9903f,-0.9877f,-0.9848f,-0.9816f,-0.9781f,-0.9744f,-0.9703f,-0.9659f,-0.9613f,-0.9563f,-0.9511f,-0.9455f,-0.9397f,
-0.9336f,-0.9272f,-0.9205f,-0.9135f,-0.9063f,-0.8988f,-0.8910f,-0.8829f,-0.8746f,-0.8660f,-0.8572f,-0.8480f,-0.8387f,-0.8290f,-0.8192f,-0.8090f,-0.7986f,-0.7880f,-0.7771f,-0.7660f,
-0.7547f,-0.7431f,-0.7314f,-0.7193f,-0.7071f,-0.6947f,-0.6820f,-0.6691f,-0.6561f,-0.6428f,-0.6293f,-0.6157f,-0.6018f,-0.5878f,-0.5736f,-0.5592f,-0.5446f,-0.5299f,-0.5150f,-0.5000f,
-0.4848f,-0.4695f,-0.4540f,-0.4384f,-0.4226f,-0.4067f,-0.3907f,-0.3746f,-0.3584f,-0.3420f,-0.3256f,-0.3090f,-0.2924f,-0.2756f,-0.2588f,-0.2419f,-0.2250f,-0.2079f,-0.1908f,-0.1736f,
-0.1564f,-0.1392f,-0.1219f,-0.1045f,-0.0872f,-0.0698f,-0.0523f,-0.0349f,-0.0175f,-0.0000f,0.0175f,0.0349f,0.0523f,0.0698f,0.0872f,0.1045f,0.1219f,0.1392f,0.1564f,0.1736f,
 0.1908f,0.2079f,0.2250f,0.2419f,0.2588f,0.2756f,0.2924f,0.3090f,0.3256f,0.3420f,0.3584f,0.3746f,0.3907f,0.4067f,0.4226f,0.4384f,0.4540f,0.4695f,0.4848f,0.5000f,
 0.5150f,0.5299f,0.5446f,0.5592f,0.5736f,0.5878f,0.6018f,0.6157f,0.6293f,0.6428f,0.6561f,0.6691f,0.6820f,0.6947f,0.7071f,0.7193f,0.7314f,0.7431f,0.7547f,0.7660f,
 0.7771f,0.7880f,0.7986f,0.8090f,0.8192f,0.8290f,0.8387f,0.8480f,0.8572f,0.8660f,0.8746f,0.8829f,0.8910f,0.8988f,0.9063f,0.9135f,0.9205f,0.9272f,0.9336f,0.9397f,
 0.9455f,0.9511f,0.9563f,0.9613f,0.9659f,0.9703f,0.9744f,0.9781f,0.9816f,0.9848f,0.9877f,0.9903f,0.9925f,0.9945f,0.9962f,0.9976f,0.9986f,0.9994f,0.9998f,1.0000f
};
 /**
  Look-up table(LUT) for the radian values of the trig function tan
  with each index of the array representing a degree value.
*/
float tans[] =
{0.0000f,0.0175f,0.0349f,0.0524f,0.0699f,0.0875f,0.1051f,0.1228f,0.1405f,0.1584f,0.1763f,0.1944f,0.2126f,0.2309f,0.2493f,0.2679f,0.2867f,0.3057f,0.3249f,0.3443f,0.3640f,
 0.3839f,0.4040f,0.4245f,0.4452f,0.4663f,0.4877f,0.5095f,0.5317f,0.5543f,0.5774f,0.6009f,0.6249f,0.6494f,0.6745f,0.7002f,0.7265f,0.7536f,0.7813f,0.8098f,0.8391f,
 0.8693f,0.9004f,0.9325f,0.9657f,1.0000f,1.0355f,1.0724f,1.1106f,1.1504f,1.1918f,1.2349f,1.2799f,1.3270f,1.3764f,1.4281f,1.4826f,1.5399f,1.6003f,1.6643f,1.7321f,
 1.8040f,1.8807f,1.9626f,2.0503f,2.1445f,2.2460f,2.3559f,2.4751f,2.6051f,2.7475f,2.9042f,3.0777f,3.2709f,3.4874f,3.7321f,4.0108f,4.3315f,4.7046f,5.1446f,5.6713f,
 6.3138f,7.1154f,8.1443f,9.5144f,11.4300f,14.3007f,19.0811f,28.6362f,57.2899f,37320539.6344f,-57.2901f,-28.6363f,-19.0811f,-14.3007f,-11.4301f,-9.5144f,-8.1443f,-7.1154f,-6.3138f,-5.6713f,
-5.1446f,-4.7046f,-4.3315f,-4.0108f,-3.7321f,-3.4874f,-3.2709f,-3.0777f,-2.9042f,-2.7475f,-2.6051f,-2.4751f,-2.3559f,-2.2460f,-2.1445f,-2.0503f,-1.9626f,-1.8807f,-1.8040f,-1.7321f,
-1.6643f,-1.6003f,-1.5399f,-1.4826f,-1.4281f,-1.3764f,-1.3270f,-1.2799f,-1.2349f,-1.1918f,-1.1504f,-1.1106f,-1.0724f,-1.0355f,-1.0000f,-0.9657f,-0.9325f,-0.9004f,-0.8693f,-0.8391f,
-0.8098f,-0.7813f,-0.7536f,-0.7265f,-0.7002f,-0.6745f,-0.6494f,-0.6249f,-0.6009f,-0.5774f,-0.5543f,-0.5317f,-0.5095f,-0.4877f,-0.4663f,-0.4452f,-0.4245f,-0.4040f,-0.3839f,-0.3640f,
-0.3443f,-0.3249f,-0.3057f,-0.2867f,-0.2679f,-0.2493f,-0.2309f,-0.2126f,-0.1944f,-0.1763f,-0.1584f,-0.1405f,-0.1228f,-0.1051f,-0.0875f,-0.0699f,-0.0524f,-0.0349f,-0.0175f,-0.0000f,
0.0175f,0.0349f,0.0524f,0.0699f,0.0875f,0.1051f,0.1228f,0.1405f,0.1584f,0.1763f,0.1944f,0.2126f,0.2309f,0.2493f,0.2679f,0.2867f,0.3057f,0.3249f,0.3443f,0.3640f,
0.3839f,0.4040f,0.4245f,0.4452f,0.4663f,0.4877f,0.5095f,0.5317f,0.5543f,0.5774f,0.6009f,0.6249f,0.6494f,0.6745f,0.7002f,0.7265f,0.7536f,0.7813f,0.8098f,0.8391f,
0.8693f,0.9004f,0.9325f,0.9657f,1.0000f,1.0355f,1.0724f,1.1106f,1.1504f,1.1918f,1.2349f,1.2799f,1.3270f,1.3764f,1.4281f,1.4826f,1.5399f,1.6003f,1.6643f,1.7321f,
1.8040f,1.8807f,1.9626f,2.0503f,2.1445f,2.2460f,2.3559f,2.4751f,2.6051f,2.7475f,2.9042f,3.0777f,3.2709f,3.4874f,3.7320f,4.0108f,4.3315f,4.7046f,5.1446f,5.6713f,
6.3137f,7.1154f,8.1443f,9.5144f,11.4300f,14.3006f,19.0811f,28.6362f,57.2897f,12440179.8094f,-57.2902f,-28.6363f,-19.0812f,-14.3007f,-11.4301f,-9.5144f,-8.1444f,-7.1154f,-6.3138f,-5.6713f,
-5.1446f,-4.7046f,-4.3315f,-4.0108f,-3.7321f,-3.4874f,-3.2709f,-3.0777f,-2.9042f,-2.7475f,-2.6051f,-2.4751f,-2.3559f,-2.2460f,-2.1445f,-2.0503f,-1.9626f,-1.8807f,-1.8040f,-1.7321f,
-1.6643f,-1.6003f,-1.5399f,-1.4826f,-1.4281f,-1.3764f,-1.3270f,-1.2799f,-1.2349f,-1.1918f,-1.1504f,-1.1106f,-1.0724f,-1.0355f,-1.0000f,-0.9657f,-0.9325f,-0.9004f,-0.8693f,-0.8391f,
-0.8098f,-0.7813f,-0.7536f,-0.7265f,-0.7002f,-0.6745f,-0.6494f,-0.6249f,-0.6009f,-0.5774f,-0.5543f,-0.5317f,-0.5095f,-0.4877f,-0.4663f,-0.4452f,-0.4245f,-0.4040f,-0.3839f,-0.3640f,
-0.3443f,-0.3249f,-0.3057f,-0.2867f,-0.2679f,-0.2493f,-0.2309f,-0.2126f,-0.1944f,-0.1763f,-0.1584f,-0.1405f,-0.1228f,-0.1051f,-0.0875f,-0.0699f,-0.0524f,-0.0349f,-0.0175f,-0.0000f
};


float fixAng(float a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

float Q_rsqrt(float number)
{
    union {
        float f;
        uint32_t i;
    } conv;

    float x2;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    conv.f  = number;
    conv.i  = 0x5f3759df - ( conv.i >> 1 );
    conv.f  = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );
    return conv.f;
}
/**Vector Functions*/
void vec3f_add(vec3f v1, vec3f v2, vec3f *out)
{
	out->x = v1.x + v2.x;
	out->y = v1.y + v2.y;
	out->z = v1.z + v2.z;
}

void vec3f_sub(vec3f v1, vec3f v2, vec3f *out)
{
	out->x = v1.x - v2.x;
	out->y = v1.y - v2.y;
	out->z = v1.z - v2.z;
}

void vec3f_mul_by_scalar(vec3f *v1, float f)
{
	v1->x *= f;
	v1->y *= f;
	v1->z *= f;
}

void vec3f_div_by_scalar(vec3f *v1, float f)
{
	v1->x /= f;
	v1->y /= f;
	v1->z /= f;
}

float dotProduct(vec3f v1, vec3f v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float length(vec3f v1)
{
	return (1 / (Q_rsqrt(dotProduct(v1,v1))));
}

void normalize(vec3f v1, vec3f *out)
{
	float l = length(v1);
	
	out->x = v1.x / l;
	out->y = v1.y / l;
	out->z = v1.z / l;
}
void crossProduct(vec3f *v1, vec3f *v2, vec3f *out)
{
	out->x = v1->y * v2->z - v1->z * v2->y;
	out->y = v1->z * v2->x - v1->x * v2->z;
	out->z = v1->x * v2->y - v1->y * v2->x;
}

void inverseVector(vec3f *v1)
{
	v1->x = -v1->x;
	v1->y = -v1->y;
	v1->z = -v1->z;
}

int compareVectors(vec3f v1, vec3f v2)
{
	if(v1.x != v2.x)
	{
		return FALSE;
	}
	if(v1.y != v2.y)
	{
		return FALSE;
	}
	if(v1.z != v2.z)
	{
		return FALSE;
	}
	return TRUE;
}

int vectorsAreCloseEnough(vec3f v1, vec3f v2, float err)
{
	if(ABS(v1.x - v2.x) < err)
	{
		return TRUE;
	}
	if(ABS(v1.y - v2.y) < err)
	{
		return TRUE;
	}
	if(ABS(v1.z - v2.z) < err)
	{
		return TRUE;
	}
	return FALSE;
}

int isFacingTowards(vec3f v1, vec3f v2)
{
	return dotProduct(v1, v2) < 0;
}

/**Matrix Functions*/
void MatrixMakeIdentity(MATRIX *m)
{
	m->m11 = 1.0f; m->m12 = 0.0f; m->m13 = 0.0f; m->m14 = 0.0f;
	m->m21 = 0.0f; m->m22 = 1.0f; m->m23 = 0.0f; m->m24 = 0.0f;
	m->m31 = 0.0f; m->m32 = 0.0f; m->m33 = 1.0f; m->m34 = 0.0f;
	m->m41 = 0.0f; m->m42 = 0.0f; m->m43 = 0.0f; m->m44 = 1.0f;
}

void MatrixMakeTranslation(MATRIX *m, float tX, float tY, float tZ)
{
	m->m11 = 1.0f; m->m12 = 0.0f; m->m13 = 0.0f; m->m14 = 0.0f;
	m->m21 = 0.0f; m->m22 = 1.0f; m->m23 = 0.0f; m->m24 = 0.0f;
	m->m31 = 0.0f; m->m32 = 0.0f; m->m33 = 1.0f; m->m34 = 0.0f;
	m->m41 = tX;   m->m42 = tY;   m->m43 = tZ; 	 m->m44 = 1.0f;
}

void MatrixMakeScale(MATRIX *m, float sX, float sY, float sZ)
{
	m->m11 = sX;    m->m12 = 0;     m->m13 = 0.0f;  m->m14 = 0.0f;
	m->m21 = 0.0f;  m->m22 = sY;    m->m23 = 0.0f;  m->m24 = 0.0f;
	m->m31 = 0.0f;  m->m32 = 0.0f;  m->m33 = sZ;    m->m34 = 0.0f;
	m->m41 = 0.0f;  m->m42 = 0.0f;  m->m43 = 0.0f;  m->m44 = 1.0f;
}

void MatrixMakeRotX(MATRIX *m, float angle)
{
	float sine    = sinf(angle);
	float cosine	= cosf(angle);
	
	m->m11 = 1.0f; m->m12 = 0.0f;     m->m13 = 0.0f;    m->m14 = 0.0f;
	m->m21 = 0.0f; m->m22 = cosine;   m->m23 = sine;    m->m24 = 0.0f;
	m->m31 = 0.0f; m->m32 = -sine;    m->m33 = cosine;  m->m34 = 0.0f;
	m->m41 = 0.0f; m->m42 = 0.0f;     m->m43 = 0.0f;    m->m44 = 1.0f;
}
void MatrixMakeRotY(MATRIX *m, float angle)
{
	float sine    = sinf(angle);
	float cosine	= cosf(angle);
	
	m->m11 = cosine;  m->m12 = 0.0f;  m->m13 = -sine;	m->m14 = 0.0f;
	m->m21 = 0.0f;    m->m22 = 1.0f;  m->m23 = 0.0f;    m->m24 = 0.0f;
	m->m31 = sine; 	  m->m32 = 0.0f;  m->m33 = cosine;  m->m34 = 0.0f;
	m->m41 = 0.0f;    m->m42 = 0.0f;  m->m43 = 0.0f;    m->m44 = 1.0f;
}
void MatrixMakeRotZ(MATRIX *m, float angle)
{
	float sine    = sinf(angle);
	float cosine	= cosf(angle);
	
	m->m11 = cosine;	m->m12 = sine;		m->m13 = 0.0f;	m->m14 = 0.0f;
	m->m21 = -sine;		m->m22 = cosine;	m->m23 = 0.0f;	m->m24 = 0.0f;
	m->m31 = 0.0f;		m->m32 = 0.0f;		m->m33 = 0.0f;	m->m34 = 0.0f;
	m->m41 = 0.0f;		m->m42 = 0.0f;		m->m43 = 0.0f;	m->m44 = 1.0f;
}

void projectionMatrix(MATRIX *m, float a, float fov, float fNear, float fFar)
{
	float fovRad =  1.0f / tanf(degToRad(fov * 0.5f));
	
	m->m11 = a * fovRad;
	m->m22 = fovRad;
	m->m33 = fFar / (fFar - fNear);
	m->m34 = (-fFar * fNear) / (fFar - fNear);
	m->m43 = 1.0f;
	m->m44 = 0.0f;
}

void MultiplyMatrixVector(vec3f *in, vec3f *out, MATRIX *m)
{
	out->x = in->x * m->m11 + in->y * m->m21 + in->z * m->m31 + m->m41;
	out->y = in->x * m->m12 + in->y * m->m22 + in->z * m->m32 + m->m42;
	out->z = in->x * m->m13 + in->y * m->m23 + in->z * m->m33 + m->m43;
	float w = in->x * m->m14 + in->y * m->m24 + in->z * m->m34 + m->m44;
	
	if(w != 0.0){out->x /= w; out->y /= w; out->z /= w;}
	
}

void MatrixMatrixMultiplication(MATRIX *m1, MATRIX *m2, MATRIX *out)
{
	int ou[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int mat[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int mat2[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	mat[0][0] = m1->m11; mat[0][1] = m1->m12; mat[0][2] = m1->m13; mat[0][3] = m1->m14;
	mat[1][0] = m1->m21; mat[1][1] = m1->m22; mat[1][2] = m1->m23; mat[1][3] = m1->m24;
	mat[2][0] = m1->m31; mat[2][1] = m1->m32; mat[2][2] = m1->m33; mat[2][3] = m1->m34;
	mat[3][0] = m1->m41; mat[3][1] = m1->m42; mat[3][2] = m1->m43; mat[3][3] = m1->m44;
	
	mat2[0][0] = m2->m11; mat2[0][1] = m2->m12; mat2[0][2] = m2->m13; mat2[0][3] = m2->m14;
	mat2[1][0] = m2->m21; mat2[1][1] = m2->m22; mat2[1][2] = m2->m23; mat2[1][3] = m2->m24;
	mat2[2][0] = m2->m31; mat2[2][1] = m2->m32; mat2[2][2] = m2->m33; mat2[2][3] = m2->m34;
	mat2[3][0] = m2->m41; mat2[3][1] = m2->m42; mat2[3][2] = m2->m43; mat2[3][3] = m2->m44;
	
	 for(int c = 0; c < 4; c++)
	{
		for(int r = 0; r < 4; r++)
		{
			ou[r][c] = mat[r][0] * mat2[0][c] + mat[r][1] * mat2[1][c] +
			mat[r][2] * mat2[2][c] + mat[r][3] * mat2[3][c];
		}
	}
	 
   out->m11 = ou[0][0]; out->m12 = ou[0][1]; out->m13 = ou[0][2]; out->m14 = ou[0][3];
   out->m21 = ou[1][0]; out->m22 = ou[1][1]; out->m23 = ou[1][2]; out->m24 = ou[1][3];
   out->m31 = ou[2][0]; out->m32 = ou[2][1]; out->m33 = ou[2][2]; out->m34 = ou[2][3];
   out->m41 = ou[3][0]; out->m42 = ou[3][1]; out->m43 = ou[3][2]; out->m44 = ou[3][3];
}

void SWAP(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}