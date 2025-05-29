#include "bullet.h"
bullet::bullet()
{
	alive = false;;
	srand(time(0));
	bullet_bmp = NULL;
}
bool bullet::getStatus()
{
	return alive;
}

void bullet::fire()
{
	x=rand()%615+10;
	y = 10;
	alive=true;

}
void bullet::erase_bullet()
{
	al_draw_filled_rectangle(x,y,x+5,y+5,al_map_rgb(0,0,0)); //black color
}
int bullet::move_bullet (int arrowX, int arrowY, int width, int length, int height)
{
	y++;
	al_draw_bitmap(bullet_bmp, x, y, 0);
	//al_draw_filled_rectangle(x,y,x+5,y+5,al_map_rgb(255,255,0));//yellow color


	if (x > arrowX && x < arrowX+width && y > arrowY && y < arrowY+length) {
		al_draw_filled_rectangle(x,y,x+16,y+16,al_map_rgb(0,0,0)); //BLACK
		alive=false;
		return 1;
	}
	if (y> height)
		alive = false;
	return 0;


} 
void bullet::create_bullet_bitmap(ALLEGRO_DISPLAY *display) {
	bullet_bmp = al_create_bitmap(16, 16);
	if (!bullet_bmp) {
		exit(1);
		al_destroy_display(display);
	}

	//Palette
	ALLEGRO_COLOR arcaneBlue = al_map_rgb(51, 164, 252);
	ALLEGRO_COLOR gold = al_map_rgb(255, 215, 0);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

	al_set_target_bitmap(bullet_bmp);
	al_clear_to_color(black);

	al_draw_triangle(0, 8, 8, 0, 16, 8, black, 1);
	al_draw_triangle(0, 8, 8, 16, 16, 8, black, 1);
	al_draw_filled_triangle(1, 8, 8, 1, 16, 8, arcaneBlue);
	al_draw_filled_triangle(1, 8, 8, 15, 16, 8, arcaneBlue);
	al_draw_filled_circle(8, 8, 2, gold);


}


