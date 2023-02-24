#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "include/gfx_def.h"
#include "include/mathlib.h"

PSP_MODULE_INFO("PSP 3D Tech Demo", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

int exit_callback(int arg1, int arg2, void* common)
{
	sceKernelExitGame();
	return 0;
}

int callbackThread(SceSize args, void* argp)
{
	int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);
	
	sceKernelSleepThreadCB();
	return 0;
}

int SetupCallbacks()
{
	int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
	if(thid >= 0)
	{
		sceKernelStartThread(thid, 0, 0);
	}
	return thid;
}

MATRIX matProj;
MATRIX matWorld, matTrans, matRotX, matRotZ;

vec3f camera= {0, 0, 0, 1};

vec3f vectors[36] = 
{ 
	 [0] = {0, 0, 0, 1},  [1] = {0, 1, 0, 1},   [2] = {1, 1, 0, 1},
	 [3] = {0, 0, 0, 1},  [4] = {1, 1, 0, 1},   [5] = {1, 0, 0, 1},
	 
	 [6] = {1, 0, 0, 1},  [7] = {1, 1, 0, 1},   [8] = {1, 1, 1, 1},
	 [9] = {1, 0, 0, 1}, [10] = {1, 1, 1, 1},  [11] = {1, 0, 1, 1},
	 
	[12] = {1, 0, 1, 1}, [13] = {1, 1, 1, 1},  [14] = {0, 1, 1, 1},
	[15] = {1, 0, 1, 1}, [16] = {0, 1, 1, 1},  [17] = {0, 0, 1, 1},
	
	[18] = {0, 0, 1, 1}, [19] = {0, 1, 1, 1},  [20] = {0, 1, 0, 1},
	[21] = {0, 0, 1, 1}, [22] = {0, 1, 0, 1},  [23] = {0, 0, 0, 1},
	
	[24] = {0, 1, 0, 1}, [25] = {0, 1, 1, 1},  [26] = {1, 1, 1, 1},
	[27] = {0, 1, 0, 1}, [28] = {1, 1, 1, 1},  [29] = {1, 1, 0, 1},
	
	[30] = {1, 0, 1, 1}, [31] = {0, 0, 1, 1},  [32] = {0, 0, 0, 1},
	[33] = {1, 0, 1, 1}, [34] = {0, 0, 0, 1},  [35] = {1, 0, 0, 1},
};

int numOfVectors = sizeof(vectors)/sizeof(vec3f);
float w = 512.00f;
float h = 272.00f;
float theta = 0;

void init()
{
	//MatrixMakeIdentity(&matProj);
	projectionMatrix(&matProj, h/w, 90, 0.1f, 1000.00f);
	MatrixMakeTranslation(&matTrans, -0.5f, 0, 15.5f);
}

int main()
{
	SetupCallbacks();
	InitializeGraphicsContext();
	init();
	
	while(1)
	{
		/**Drawing Routines*/
		fill_screen(GREEN); draw_rect(50, 50, 50, 50, BLUE); fill_triangle(60, 120, 90, 120,  75, 90, PURPLE);
		fill_rect(100 + theta, 120, 50, 50, YELLOW); draw_line(10, 15, 15, 60, RED); draw_triangle(15, 15, 40, 15, 32, 32, GRAY);
		
		theta += 0.03;
		
		int i;
		for(i = 0; i < numOfVectors; i+=3)
		{
			SIMPLE_TRIANGLE tri = {vectors[i], vectors[i+1], vectors[i+2]};
			SIMPLE_TRIANGLE triProjected = {{0.0f,0.0f,0.0f,1.0f},{0.0f,0.0f,0.0f,1.0f},{0.0f,0.0f,0.0f,1.0f}};
			SIMPLE_TRIANGLE triTrans = {{0.0f,0.0f,0.0f,1.0f},{0.0f,0.0f,0.0f,1.0f},{0.0f,0.0f,0.0f,1.0f}};
			SIMPLE_TRIANGLE triRot = {{0.0f,0.0f,0.0f,1.0f},{0.0f,0.0f,0.0f,1.0f},{0.0f,0.0f,0.0f,1.0f}};
			
			MatrixMakeRotY(&matRotX, theta);
			
			MultiplyMatrixVector(&tri.v1, &triRot.v1, &matRotX);
			MultiplyMatrixVector(&tri.v2, &triRot.v2, &matRotX);
			MultiplyMatrixVector(&tri.v3, &triRot.v3, &matRotX);
			
			MultiplyMatrixVector(&triRot.v1, &triTrans.v1, &matTrans);
			MultiplyMatrixVector(&triRot.v2, &triTrans.v2, &matTrans);
			MultiplyMatrixVector(&triRot.v3, &triTrans.v3, &matTrans);
			
			vec3f line1 = {0,0,0,1}, line2 = {0,0,0,1}, normal = {0,0,0,1};
			
			vec3f_sub(triTrans.v2, triTrans.v1, &line1);
			vec3f_sub(triTrans.v3, triTrans.v1, &line2);
			crossProduct(&line1, &line2, &normal);
			normalize(normal, &normal);
			
			vec3f vCameraRay;
			
			vec3f_sub(triTrans.v1, normal, &vCameraRay);
			
			if(isFacingTowards(normal, vCameraRay))
			{
				/**PROJECT 3D GEOMETRICAL DATA TO NORMALIZED 2D SCREEN*/
				MultiplyMatrixVector(&triTrans.v1, &triProjected.v1, &matProj);
				MultiplyMatrixVector(&triTrans.v2, &triProjected.v2, &matProj);
				MultiplyMatrixVector(&triTrans.v3, &triProjected.v3, &matProj);
				/**TODO: IMPLEMENT PERSPECTIVE DIVIDE OUTSIDE PROJECTION MATRIX*/
				vec3f light_direction = {0, 0, -1, 1};
				normalize(light_direction, &light_direction);
				
				float dp = MAX(0.1f, dotProduct(light_direction, normal));

				
				/**SCALE TRIANGLE FROM PROJECTED SPACE TO SCREEN SPACE*/
				triProjected.v1.x += 1.0; triProjected.v2.x += 1.0; triProjected.v3.x += 1.0;
				triProjected.v1.y += 1.0; triProjected.v2.y += 1.0; triProjected.v3.y += 1.0;
				triProjected.v1.x *= (0.5f * w); triProjected.v2.x *= (0.5f * w); triProjected.v3.x *= (0.5f * w);
				triProjected.v1.y *= (0.5f * h); triProjected.v2.y *= (0.5f * h); triProjected.v3.y *= (0.5f * h);

				fill_triangle((int)triProjected.v1.x,(int)triProjected.v1.y,(int)triProjected.v2.x,(int)triProjected.v2.y,
				(int)triProjected.v3.x,(int)triProjected.v3.y, dotColor(WHITE, dp));
			}

			
		}
		
		/**Wait For all Scanlines and Swap Buffers*/
		sceDisplayWaitVblankStart();
		SwapBuffers();
	}
}