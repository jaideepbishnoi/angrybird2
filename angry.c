//first left click on ball and move mouse backward by pressing left click press right click to throw ball
#include<allegro.h>
#include<stdio.h>
#include<math.h>
#define pi 3.14
int velocity=10;
float ang=10;
void click2();
int x=15,y=300,i,j;
static int p;
void thick_line(BITMAP *bmp, float x, float y, float x_, float y_,
float thickness, int color);
//void collission(BITMAP *buffer);
void draw_in();
int main()
{
	allegro_init();
	BITMAP *buffer=create_bitmap(1024,800);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,800,0,0);
	install_keyboard();
	install_mouse();
	while(!key[KEY_ESC])
	{
		show_mouse(screen);
		draw_in();
		click2();
	}
	return 0;
	allegro_exit();
}
void thick_line(BITMAP *bmp, float x, float y, float x_, float y_,
float thickness, int color)
{
	float dx = x - x_;
	float dy = y - y_;
	float d = sqrtf(dx * dx + dy * dy);
	if (!d)
	return;
	int v[4 * 2];
	/* left up */
	v[0] = x - thickness * dy / d;
	v[1] = y + thickness * dx / d;
	/* right up */
	v[2] = x + thickness * dy / d;
	v[3] = y - thickness * dx / d;
	/* right down */
	v[4] = x_ + thickness * dy / d;
	v[5] = y_ - thickness * dx / d;
	/* left down */
	v[6] = x_ - thickness * dy / d;
	v[7] = y_ + thickness * dx / d;
	polygon(bmp, 4, v, color);
}
void draw_in()
{
	BITMAP *buffer=create_bitmap(1024,800);
	acquire_screen();
	clear_to_color(buffer,200);
	thick_line(buffer,0,700,1024,700,50,makecol(0,255,1));
	thick_line(buffer,200,650,200,600,10,makecol(200,100,50));
	thick_line(buffer,200,600,165,550,3,makecol(227,50,150));
	thick_line(buffer,200,600,235,550,3,makecol(227,50,150));
	//arc(screen,55 ,320 ,230,450, 10, makecol(0, 255, 0));
	thick_line(buffer,165,550,x=105,y=570,2,makecol(2,50,250));
	thick_line(buffer,235,550,x=105,y=570,2,makecol(2,50,250));
	p=makecol(20,150,250);
	//circlefill(screen,200,390,10,p);
	circlefill(buffer,115,565,10,makecol(10,50,250));
	//target plot
	thick_line(buffer,900,650,900,500,5,makecol(90,100,50));
	thick_line(buffer,850,650,850,500,5,makecol(200,10,50));
	thick_line(buffer,850,500,900,500,4,makecol(20,100,50));
	circlefill(buffer,875,485,15,makecol(200,150,250));
	circlefill(buffer,872,485,3,makecol(0,0,25));
	circlefill(buffer,878,485,3,makecol(0,0,25));
	thick_line(buffer,890,480,895,460,2,makecol(20,100,50));
	thick_line(buffer,860,480,855,460,2,makecol(20,100,50));
	//end
	blit(buffer,screen,0,0,0,0,1020,800);
	release_screen();
	rest(10);
	clear_bitmap(buffer);
	//end
	//mouse_click();
}
void click2()
{
int l,m;
	BITMAP *buffer=create_bitmap(1024,800);
	int col=makecol(20,150,250);
	if(mouse_b & 1)
	{
		while(mouse_x>25 && mouse_y>500)
		{
			if(mouse_b & 1)
				{
//show_mouse(buffer);
					acquire_screen();
					clear_to_color(buffer,200);
					x=mouse_x;
					y=mouse_y;
					l=x+5;
					m=y-10;
					if(mouse_x>25)//modified code
					ang=ang+2;
					if(mouse_y>500) //here is need of modification : if mouse co-ordinates changes angle and velocity must also 						changes:---still to do
					velocity=velocity+3;	
				}
//target plot
			thick_line(buffer,900,650,900,500,5,makecol(90,100,50));	
			thick_line(buffer,850,650,850,500,5,makecol(200,10,50));
			thick_line(buffer,850,500,900,500,4,makecol(20,100,50));
			circlefill(buffer,875,485,15,makecol(200,150,250));
			circlefill(buffer,872,485,3,makecol(0,0,25));
			circlefill(buffer,878,485,3,makecol(0,0,25));
			thick_line(buffer,890,480,895,460,2,makecol(20,100,50));
			thick_line(buffer,860,480,855,460,2,makecol(20,100,50));
//end
//lines stretching
			thick_line(buffer,165,550,x,y,2,makecol(2,50,250));
			thick_line(buffer,235,550,x,y,2,makecol(2,50,250));
//
			circlefill(buffer,l,m,10,makecol(10,50,250));
			thick_line(buffer,0,700,1024,700,50,makecol(0,255,1));
			thick_line(buffer,200,650,200,600,10,makecol(200,100,50));
 			thick_line(buffer,200,600,165,550,3,makecol(227,50,150));
			thick_line(buffer,200,600,235,550,3,makecol(227,50,150));
			clear_to_color(screen,255);
			blit(buffer,screen,0,0,0,0,1020,800);
			release_screen();
			rest(10);
			clear_bitmap(buffer);
			rest(10);
			if(mouse_b & 2)// ball will start moving on right click......but it will move on constant angle and velocity:(modification requred here)
			{
				for(i=1;i<=1024;i=i+1)
					{acquire_screen();
						if(key[KEY_ESC])
						return;
						clear_to_color(buffer,200);
						float ang1=(pi*ang)/180;
						int m,n,r,s;
						m=i+x;
						n=y-j;
						circlefill(buffer,m,n,10,makecol(10,50,250));
						thick_line(buffer,0,700,1024,700,50,makecol(0,255,1));
						thick_line(buffer,200,650,200,600,10,makecol(200,100,50));
						thick_line(buffer,200,600,165,550,3,makecol(227,50,150));
						thick_line(buffer,200,600,235,550,3,makecol(227,50,150));
						//arc(screen,55 ,320 ,230,450, 10, makecol(0, 255, 0));
						thick_line(buffer,165,550,x=135,y=570,2,makecol(2,50,250));
						thick_line(buffer,235,550,x=135,y=570,2,makecol(2,50,250));
						p=makecol(20,150,250);

//target plot
						thick_line(buffer,900,650,900,500,5,makecol(90,100,50));
						thick_line(buffer,850,650,850,500,5,makecol(200,10,50));
						thick_line(buffer,850,500,900,500,4,makecol(20,100,50));
						circlefill(buffer,875,485,15,makecol(200,150,250));
						circlefill(buffer,872,485,3,makecol(0,0,25));
						circlefill(buffer,878,485,3,makecol(0,0,25));
						thick_line(buffer,890,480,895,460,2,makecol(20,100,50));
						thick_line(buffer,860,480,855,460,2,makecol(20,100,50));
						/*if(m<950 && getpixel(buffer,m,n)==makecol(200,10,50))
						{
							collission(buffer);
						}*/
//end
						blit(buffer,screen,0,0,0,0,1020,800);
						release_screen();
						rest(10);
						clear_bitmap(buffer);
						j=i*tan(ang1)-(9.8/(2*velocity*velocity*cos(ang1)*cos(ang1))*(i*i));
				}
			}
		}
	}
}
/*void collission(BITMAP *buffer)
{
	while(!key[KEY_ESC])
	{
		acquire_screen();
		clear_to_color(buffer,255);
		thick_line(buffer,0,700,1024,700,50,makecol(0,255,1));
		thick_line(buffer,200,650,200,600,10,makecol(200,100,50));
		thick_line(buffer,200,600,165,550,3,makecol(227,50,150));
		thick_line(buffer,200,600,235,550,3,makecol(227,50,150));
		//arc(screen,55 ,320 ,230,450, 10, makecol(0, 255, 0));
		thick_line(buffer,165,550,x=105,y=570,2,makecol(2,50,250));
		thick_line(buffer,235,550,x=105,y=570,2,makecol(2,50,250));
		p=makecol(20,150,250);
		//circlefill(screen,200,390,10,p);
		circlefill(buffer,115,565,10,makecol(10,50,250));
		//target plot
		thick_line(buffer,900,650,900,500,5,makecol(90,100,50));
		thick_line(buffer,850,650,850,500,5,255);
		thick_line(buffer,850,500,900,500,4,makecol(20,100,50));
		circlefill(buffer,875,485,15,255);
		circlefill(buffer,872,485,3,255);
		circlefill(buffer,878,485,3,255);
		thick_line(buffer,890,480,895,460,2,makecol(20,100,50));
		thick_line(buffer,860,480,855,460,2,makecol(20,100,50));
		//end
		blit(buffer,screen,0,0,0,0,1020,800);
		release_screen();
		rest(10);
		clear_bitmap(buffer);
	}
}*/



