#include <pspge.h>
#include <pspdisplay.h>
#include <psputils.h>
#include <stdint.h>
#include "include/gfx_def.h"
#include "include/mathlib.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

uint32_t* draw_buffer;
uint32_t* disp_buffer;

void InitializeGraphicsContext()
{
	/**Direct Address Front and Back Frame Buffers*/
	draw_buffer = sceGeEdramGetAddr();
	disp_buffer = (uint32_t*)sceGeEdramGetAddr() + (272 * 512 * 4);
	/**Initialize Display Mode and Frame Buffer with the GE*/
	sceDisplaySetMode(0, 480, 272);
	sceDisplaySetFrameBuf(disp_buffer, 512, PSP_DISPLAY_PIXEL_FORMAT_8888, 1);
}

void SwapBuffers()
{
	uint32_t* temp = disp_buffer;
	disp_buffer = draw_buffer;
	draw_buffer = temp;
	
	sceKernelDcacheWritebackInvalidateAll();
	sceDisplaySetFrameBuf(disp_buffer, 512, PSP_DISPLAY_PIXEL_FORMAT_8888, PSP_DISPLAY_SETBUF_NEXTFRAME);
}

void draw_pixel(int x, int y, int col)
{
	if(x >= 0 && y >= 0 && x < 512 && y < 272)
	{
		disp_buffer[x+y*512] = col;
	}
}

void fill_screen(int col)
{
	int x, y;
	for(y = 0; y < 272; y++)
	{
		for(x = 0; x < 512; x++)
		{
			disp_buffer[x+y*512] = col;
		}
	}
}

void draw_line(int x1, int y1, int x2, int y2, int col)
{
	int dx, dy, sx, sy, err, e2;
	
	dx = ABS(x2 - x1);
	dy = ABS(y2 - y1);
	
	if(x1 < x2)
	{
		sx = 1;
	}
	else
	{
		sx = -1;
	}
	
	if(y1 < y2)
	{
		sy = 1;
	}
	else
	{
		sy = -1;
	}
	
	err = dx - dy;
	
	do
	{
		draw_pixel(x1, y1, col);
		e2 = err * 2;
		if (e2 > -dy) 
		{
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) 
		{
            err += dx;
            y1 += sy;
        }
	}while(x1 != x2 || y1 != y2);
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
	draw_line(x1, y1, x2, y2, color);
	draw_line(x2, y2, x3, y3, color);
	draw_line(x3, y3, x1, y1, color);
}

void fill_rect(int x, int y, int width, int height, int col)
{
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			draw_pixel(i + x, j + y, col);
		}
	}
}

void draw_rect(int x, int y, int width, int height, int col)
{
	draw_line(x, y, x , y + height, col);
	draw_line(x + width, y, x + width, y + height, col);
	draw_line(x, y + height, x + width, y + height, col);
	draw_line(x, y, x + width, y, col);
}

void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int col)
{
	int t1x, t2x, y, minx, maxx, t1xp, t2xp;
		int changed1 = FALSE;
		int changed2 = FALSE;
		int signx1, signx2, dx1, dy1, dx2, dy2;
		int e1, e2;
		// Sort vertices
		if (y1 > y2) { SWAP(&y1, &y2); SWAP(&x1, &x2); }
		if (y1 > y3) { SWAP(&y1, &y3); SWAP(&x1, &x3); }
		if (y2 > y3) { SWAP(&y2, &y3); SWAP(&x2, &x3); }

		t1x = t2x = x1; y = y1;   // Starting points
		dx1 = (int)(x2 - x1);
		if (dx1 < 0) { dx1 = -dx1; signx1 = -1; }
		else signx1 = 1;
		dy1 = (int)(y2 - y1);

		dx2 = (int)(x3 - x1);
		if (dx2 < 0) { dx2 = -dx2; signx2 = -1; }
		else signx2 = 1;
		dy2 = (int)(y3 - y1);

		if (dy1 > dx1) { SWAP(&dx1, &dy1); changed1 = TRUE; }
		if (dy2 > dx2) { SWAP(&dy2, &dx2); changed2 = TRUE; }

		e2 = (int)(dx2 >> 1);
		// Flat top, just process the second half
		if (y1 == y2) goto next;
		e1 = (int)(dx1 >> 1);

		for (int i = 0; i < dx1;) {
			t1xp = 0; t2xp = 0;
			if (t1x < t2x) { minx = t1x; maxx = t2x; }
			else { minx = t2x; maxx = t1x; }
			// process first line until y value is about to change
			while (i < dx1) {
				i++;
				e1 += dy1;
				while (e1 >= dx1) {
					e1 -= dx1;
					if (changed1) t1xp = signx1;//t1x += signx1;
					else          goto next1;
				}
				if (changed1) break;
				else t1x += signx1;
			}
			// Move line
		next1:
			// process second line until y value is about to change
			while (1) {
				e2 += dy2;
				while (e2 >= dx2) {
					e2 -= dx2;
					if (changed2) t2xp = signx2;//t2x += signx2;
					else          goto next2;
				}
				if (changed2)     break;
				else              t2x += signx2;
			}
		next2:
			if (minx > t1x) minx = t1x;
			if (minx > t2x) minx = t2x;
			if (maxx < t1x) maxx = t1x;
			if (maxx < t2x) maxx = t2x;
			drawLine(minx, maxx, y, col);    // Draw line from min to max points found on the y
										// Now increase y
			if (!changed1) t1x += signx1;
			t1x += t1xp;
			if (!changed2) t2x += signx2;
			t2x += t2xp;
			y += 1;
			if (y == y2) break;
		}
	next:
		// Second half
		dx1 = (int)(x3 - x2); if (dx1 < 0) { dx1 = -dx1; signx1 = -1; }
		else signx1 = 1;
		dy1 = (int)(y3 - y2);
		t1x = x2;

		if (dy1 > dx1) {   // swap values
			SWAP(&dy1, &dx1);
			changed1 = TRUE;
		}
		else changed1 = FALSE;

		e1 = (int)(dx1 >> 1);

		for (int i = 0; i <= dx1; i++) {
			t1xp = 0; t2xp = 0;
			if (t1x < t2x) { minx = t1x; maxx = t2x; }
			else { minx = t2x; maxx = t1x; }
			// process first line until y value is about to change
			while (i < dx1) {
				e1 += dy1;
				while (e1 >= dx1) {
					e1 -= dx1;
					if (changed1) { t1xp = signx1; break; }//t1x += signx1;
					else          goto next3;
				}
				if (changed1) break;
				else   	   	  t1x += signx1;
				if (i < dx1) i++;
			}
		next3:
			// process second line until y value is about to change
			while (t2x != x3) {
				e2 += dy2;
				while (e2 >= dx2) {
					e2 -= dx2;
					if (changed2) t2xp = signx2;
					else          goto next4;
				}
				if (changed2)     break;
				else              t2x += signx2;
			}
		next4:

			if (minx > t1x) minx = t1x;
			if (minx > t2x) minx = t2x;
			if (maxx < t1x) maxx = t1x;
			if (maxx < t2x) maxx = t2x;
			drawLine(minx, maxx, y, col);
			if (!changed1) t1x += signx1;
			t1x += t1xp;
			if (!changed2) t2x += signx2;
			t2x += t2xp;
			y += 1;
			if (y > y3) return;
		}
	}

void drawLine(int sx, int ex, int ny, int col)
{
   for (int i = sx; i <= ex; i++)
   {
	   draw_pixel(i, ny, col);
   }          
}

void circleBres(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y, color);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels
         
        x++;
 
        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y, color);
    }
}

void drawCircle(int xc, int yc, int x, int y, int col)
{
    draw_pixel(xc+x, yc+y, col);
    draw_pixel(xc-x, yc+y, col);
    draw_pixel(xc+x, yc-y, col);
    draw_pixel(xc-x, yc-y, col);
    draw_pixel(xc+y, yc+x, col);
    draw_pixel(xc-y, yc+x, col);
    draw_pixel(xc+y, yc-x, col);
    draw_pixel(xc-y, yc-x, col);
}

int dotColor(int col, float factor)
{
	int i1 = col;//blend(col, blend(col, CD_RED, factor), factor);
	
	int a1 = getA(i1);
	int r1 = getR(i1);
	int g1 = getG(i1);
	int b1 = getB(i1);
	
	int a = (int)(a1 * factor);
	int r = (int)(r1 * factor);
	int g = (int)(g1 * factor);
	int b = (int)(b1 * factor);
	
	return a << 24 | r << 16 | g << 8 | b;
}
    
int blend(int col, int col2, float ratio)
{
	if ( ratio > 1.0f ) ratio = 1.0f;
	else if ( ratio < 0.0f ) ratio = 0.0f;
	float iRatio = 1.0f - ratio;

	int i1 = col;
	int i2 = col2;

	int a1 = getA(i1);
	int r1 = getR(i1);
	int g1 = getG(i1);
	int b1 = getB(i1);

	int a2 = getA(i2);
	int r2 = getR(i2);
	int g2 = getG(i2);
	int b2 = getB(i2);

	int a = (int)((a1 * iRatio) + (a2 * ratio));
	int r = (int)((r1 * iRatio) + (r2 * ratio));
	int g = (int)((g1 * iRatio) + (g2 * ratio));
	int b = (int)((b1 * iRatio) + (b2 * ratio));

	return a << 24 | r << 16 | g << 8 | b ;
}

int getA(int col)
{
	return (col >> 24 & 0xff);
}

int getR(int col)
{
	return (col & 0xff);
}

int getB(int col)
{
	return ((col & 0xff0000) >> 16);
}

int getG(int col)
{
	return ((col & 0xff00) >> 8);
}



