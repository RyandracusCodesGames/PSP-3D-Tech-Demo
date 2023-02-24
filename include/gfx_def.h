#ifndef GFX_DEF
#define GFX_DEF
/**Essential 24-Bit Color Palette*/
#define BLACK 0x000000
#define BLUE 0xFF0000
#define WHITE 0xFFFFFF
#define GREEN 0x00FF00
#define RED 0x0000FF
#define GRAY 0x808080
#define YELLOW 0x00FFFF
#define ORANGE 0xFFA500
#define PURPLE 0x800080
#define RGB(r, g, b) ((r << 16)+(g << 8)+(b))
/**Blend and Extract RGB Components*/
int blend(int col, int col2, float factor);
int getA(int col);
int getR(int col);
int getB(int col);
int getG(int col);
int dotColor(int col, float factor);
/**Fundamental Drawing Routines*/
void InitializeGraphicsContext();
void SwapBuffers();
void draw_pixel(int x, int y, int col);
void fill_screen(int col);
void draw_line(int x1, int y1, int x2, int y2, int col);
void drawLine(int sx, int ex, int ny, int col);
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int col);
void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int col);
void fill_rect(int x, int y, int width, int height, int col);
void draw_rect(int x, int y, int width, int height, int col);
void circleBres(int xc, int yc, int r, int color);
void drawCircle(int xc, int yc, int x, int y, int col);
void TexturedTriangle();
#endif