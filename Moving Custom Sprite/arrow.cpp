#include "arrow.h"
arrowClass::arrowClass()
{
	speed=0;
	x=100;
	y=100;
	dir=1;
	score = 0;
	arrow_bmp = NULL;
}
arrowClass::~arrowClass()
{
	for(int i=0; i<4; i++)
	{
		al_destroy_bitmap(arrow_bmp);
	}
}
void arrowClass::drawArrow()
{
    switch (dir) {
        case 0:
            al_draw_bitmap(arrow_bmp, getX(), getY(), 0);
            break;
        case 1:
            al_draw_rotated_bitmap(arrow_bmp, 0, 64, getX(), getY(), ALLEGRO_PI/2, 0);
            break;
        case 2:
            al_draw_bitmap(arrow_bmp, getX(), getY(), ALLEGRO_FLIP_VERTICAL);
            break;
        case 3:
            al_draw_rotated_bitmap(arrow_bmp, 64, 0, getX(), getY(), 3 * ALLEGRO_PI / 2, 0);
            break;
    }
}
void arrowClass::create_arrow_bitmap(ALLEGRO_DISPLAY *display)
{
	arrow_bmp = al_create_bitmap(64, 64);   
	if(!arrow_bmp) {
		exit(1);
		al_destroy_display(display);

	}

	al_set_target_bitmap(arrow_bmp);
	al_clear_to_color(al_map_rgb(0, 0, 0));

    //Palette
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR arcaneBlue = al_map_rgb(51, 164, 252);
    ALLEGRO_COLOR steel = al_map_rgb(113, 121, 126);
    ALLEGRO_COLOR wood = al_map_rgb(79, 32, 15);
    ALLEGRO_COLOR blue = al_map_rgb(48, 92, 222);
    ALLEGRO_COLOR gold = al_map_rgb(255, 215, 0);
    ALLEGRO_COLOR steelDark = al_map_rgb(88, 96, 100);

    //Spear
    //SpearHead
    al_draw_line(51, 1, 51, 4, black, 1);
    al_draw_line(50, 4, 50, 10, black, 1);
    al_draw_line(52, 4, 52, 10, black, 1);
    al_draw_line(49, 10, 49, 13, black, 1);
    al_draw_line(53, 10, 53, 13, black, 1);
    al_draw_line(49, 14, 52, 14, black, 1);
    al_draw_line(51, 4, 51, 7, arcaneBlue, 1);
    al_draw_line(50, 10, 50, 12, arcaneBlue, 1);
    al_draw_line(52, 10, 52, 12, arcaneBlue, 1);
    al_draw_line(51, 7, 51, 12, steel, 1);
    al_draw_line(49, 13, 52, 13, steel, 1);

    //Spear Haft
    al_draw_line(50, 14, 49, 58, black, 1);
    al_draw_line(52, 14, 51, 58, black, 1);
    al_draw_line(51, 14, 50, 58, wood, 1);
    al_draw_line(49, 59, 52, 59, black, 1);
    al_draw_line(48, 60, 53, 60, black, 1);
    al_draw_line(49, 60, 52, 60, arcaneBlue, 1);
    al_draw_line(49, 61, 52, 61, black, 1);

    //Shield
    al_draw_line(7, 18, 31, 18, black, 1);
    al_draw_line(3, 19, 7, 19, black, 1);
    al_draw_line(7, 19, 11, 19, blue, 1);
    al_draw_line(14, 19, 18, 19, blue, 1);
    al_draw_line(18, 19, 20, 19, gold, 1);
    al_draw_line(20, 19, 24, 19, blue, 1);
    al_draw_line(27, 19, 31, 19, blue, 1);
    al_draw_line(31, 19, 35, 19, black, 1);
    al_draw_line(1, 20, 3, 20, black, 1);
    al_draw_line(3, 20, 6, 20, blue, 1);
    al_draw_line(6, 20, 8, 20, gold, 1);
    al_draw_line(8, 20, 12, 20, blue, 1);
    al_draw_line(12, 20, 26, 20, gold, 1);
    al_draw_line(26, 20, 30, 20, blue, 1);
    al_draw_line(30, 20, 32, 20, gold, 1);
    al_draw_line(32, 20, 35, 20, blue, 1);
    al_draw_line(35, 20, 37, 20, black, 1);
    al_draw_line(2, 21, 4, 21, black, 1);
    al_draw_line(4, 21, 7, 21, blue, 1);
    al_draw_line(7, 21, 9, 21, gold, 1);
    al_draw_line(9, 21, 29, 21, blue, 1);
    al_draw_line(29, 21, 31, 21, gold, 1);
    al_draw_line(31, 21, 34, 21, blue, 1);
    al_draw_line(34, 21, 36, 21, black, 1);
    al_draw_line(3, 22, 35, 22, black, 1);
    al_draw_pixel(12, 19, gold);
    al_draw_pixel(13, 19, blue);
    al_draw_pixel(14, 19, gold);
    al_draw_pixel(25, 19, gold);
    al_draw_pixel(26, 19, blue);
    al_draw_pixel(27, 19, gold);

    //Body
    //Arm
    al_draw_line(14, 22, 14, 24, black, 1);
    al_draw_line(13, 24, 13, 28, black, 1);
    al_draw_line(12, 28, 12, 32, black, 1);
    al_draw_line(11, 32, 11, 34, black, 1);
    al_draw_line(19, 22, 19, 25, black, 1);
    al_draw_line(18, 25, 18, 29, black, 1);
    al_draw_line(17, 29, 17, 31, black, 1);
    al_draw_filled_rectangle(14, 22, 18, 25, steel);
    al_draw_filled_rectangle(13, 24, 17, 29, steel);
    al_draw_filled_rectangle(12, 28, 16, 32, steel);
    al_draw_filled_rectangle(11, 32, 14, 34, steel);

    //Torso
    al_draw_filled_rectangle(11, 34, 14, 48, steel);
    al_draw_filled_rectangle(50, 34, 53, 48, steel);
    al_draw_line(15, 33, 15, 49, gold, 1);
    al_draw_line(50, 34, 50, 49, gold, 1);
    al_draw_filled_rectangle(15, 33, 49, 49, blue);
    al_draw_filled_rectangle(16, 49, 48, 51, blue);
    al_draw_line(16, 33, 49, 33, blue, 1);

    al_draw_line(16, 32, 48, 32, black, 1);
    al_draw_line(14, 33, 16, 33, black, 1);
    al_draw_line(12, 34, 14, 34, black, 1);
    al_draw_line(10, 35, 12, 35, black, 1);
    al_draw_line(11, 35, 11, 47, black, 1);
    al_draw_pixel(12, 48, black);
    al_draw_line(12, 49, 14, 49, black, 1);
    al_draw_line(14, 50, 16, 50, black, 1);
    al_draw_line(16, 51, 18, 51, black, 1);
    al_draw_line(18, 52, 46, 52, black, 1);
    al_draw_line(46, 51, 48, 51, black, 1);
    al_draw_line(48, 50, 50, 50, black, 1);
    al_draw_line(50, 49, 52, 49, black, 1);
    al_draw_pixel(53, 48, black);
    al_draw_line(54, 35, 54, 47, black, 1);
    al_draw_pixel(53, 35, black);
    al_draw_line(50, 34, 52, 34, black, 1);
    al_draw_line(48, 33, 50, 33, black, 1);
    al_draw_line(46, 32, 48, 32, black, 1);

    //Chainmail
    al_draw_pixel(15, 23, steelDark);
    al_draw_pixel(17, 23, steelDark);
    al_draw_pixel(16, 24, steelDark);
    al_draw_pixel(18, 24, steelDark);
    al_draw_pixel(15, 25, steelDark);
    al_draw_pixel(17, 25, steelDark);
    al_draw_pixel(14, 26, steelDark);
    al_draw_pixel(16, 26, steelDark);
    al_draw_pixel(15, 27, steelDark);
    al_draw_pixel(17, 27, steelDark);
    al_draw_pixel(14, 28, steelDark);
    al_draw_pixel(16, 28, steelDark);
    al_draw_pixel(13, 29, steelDark);
    al_draw_pixel(15, 29, steelDark);
    al_draw_pixel(17, 29, steelDark);
    al_draw_pixel(14, 30, steelDark);
    al_draw_pixel(16, 30, steelDark);
    al_draw_pixel(13, 31, steelDark);
    al_draw_pixel(15, 31, steelDark);
    al_draw_pixel(14, 32, steelDark);
    al_draw_pixel(16, 32, steelDark);
    al_draw_pixel(13, 33, steelDark);
    al_draw_pixel(12, 34, steelDark);
    al_draw_pixel(13, 35, steelDark);
    al_draw_pixel(12, 36, steelDark);
    al_draw_pixel(14, 36, steelDark);
    al_draw_pixel(13, 37, steelDark);
    al_draw_pixel(12, 38, steelDark);
    al_draw_pixel(14, 38, steelDark);
    al_draw_pixel(13, 39, steelDark);
    al_draw_pixel(12, 40, steelDark);
    al_draw_pixel(14, 40, steelDark);
    al_draw_pixel(13, 41, steelDark);
    al_draw_pixel(12, 42, steelDark);
    al_draw_pixel(14, 42, steelDark);
    al_draw_pixel(13, 43, steelDark);
    al_draw_pixel(12, 44, steelDark);
    al_draw_pixel(14, 44, steelDark);
    al_draw_pixel(13, 45, steelDark);
    al_draw_pixel(12, 46, steelDark);
    al_draw_pixel(14, 46, steelDark);
    al_draw_pixel(13, 47, steelDark);
    al_draw_pixel(14, 48, steelDark);
    al_draw_pixel(52, 35, steelDark);
    al_draw_pixel(51, 36, steelDark);
    al_draw_pixel(53, 36, steelDark);
    al_draw_pixel(52, 37, steelDark);
    al_draw_pixel(51, 38, steelDark);
    al_draw_pixel(53, 38, steelDark);
    al_draw_pixel(51, 40, steelDark);
    al_draw_pixel(51, 42, steelDark);
    al_draw_pixel(51, 44, steelDark);
    al_draw_pixel(51, 46, steelDark);
    al_draw_pixel(51, 48, steelDark);
    al_draw_pixel(53, 40, steelDark);
    al_draw_pixel(53, 42, steelDark);
    al_draw_pixel(53, 44, steelDark);
    al_draw_pixel(53, 46, steelDark);
    al_draw_pixel(52, 39, steelDark);
    al_draw_pixel(52, 41, steelDark);
    al_draw_pixel(52, 43, steelDark);
    al_draw_pixel(52, 45, steelDark);
    al_draw_pixel(52, 47, steelDark);

    //Helmet (Head)
    //The Allegro circle doesn't match the GIMP circle so I'm making in
    al_draw_filled_rectangle(18, 35, 46, 45, steel);
    al_draw_filled_rectangle(27, 26, 37, 54, steel);
    al_draw_filled_rectangle(21, 29, 43, 51, steel);
    al_draw_filled_rectangle(19, 31, 21, 49, steel);
    al_draw_filled_rectangle(43, 31, 45, 49, steel);
    al_draw_filled_rectangle(23, 51, 41, 53, steel);
    al_draw_filled_rectangle(23, 27, 41, 29, steel);

    al_draw_line(27, 25, 37, 25, black, 1);
    al_draw_line(25, 26, 27, 26, black, 1);
    al_draw_line(23, 27, 25, 27, black, 1);
    al_draw_line(21, 28, 23, 28, black, 1);
    al_draw_line(21, 53, 23, 53, black, 1);
    al_draw_line(23, 54, 25, 54, black, 1);
    al_draw_line(25, 55, 27, 55, black, 1);
    al_draw_line(27, 56, 37, 56, black, 1);
    al_draw_line(37, 55, 39, 55, black, 1);
    al_draw_line(39, 54, 41, 54, black, 1);
    al_draw_line(41, 53, 43, 53, black, 1);
    al_draw_line(41, 28, 43, 28, black, 1);
    al_draw_line(39, 27, 41, 27, black, 1);
    al_draw_line(37, 26, 39, 26, black, 1);
    al_draw_line(20, 29, 20, 31, black, 1);
    al_draw_line(19, 31, 19, 33, black, 1);
    al_draw_line(18, 33, 18, 35, black, 1);
    al_draw_line(17, 35, 17, 45, black, 1);
    al_draw_line(18, 45, 18, 47, black, 1);
    al_draw_line(19, 47, 19, 49, black, 1);
    al_draw_line(20, 49, 20, 51, black, 1);
    al_draw_line(45, 29, 45, 31, black, 1);
    al_draw_line(46, 31, 46, 33, black, 1);
    al_draw_line(47, 33, 47, 35, black, 1);
    al_draw_line(48, 35, 48, 45, black, 1);
    al_draw_line(47, 45, 47, 47, black, 1);
    al_draw_line(46, 47, 46, 49, black, 1);
    al_draw_line(45, 49, 45, 51, black, 1);

    al_draw_pixel(21, 29, black);
    al_draw_pixel(44, 29, black);
    al_draw_pixel(21, 52, black);
    al_draw_pixel(44, 52, black);

    al_draw_line(27, 26, 37, 26, steelDark, 1);
    al_draw_line(25, 27, 27, 27, steelDark, 1);
    al_draw_line(23, 28, 25, 28, steelDark, 1);
    al_draw_line(21, 29, 23, 29, steelDark, 1);
    al_draw_line(41, 29, 43, 29, steelDark, 1);
    al_draw_line(39, 28, 41, 28, steelDark, 1);
    al_draw_line(37, 27, 39, 27, steelDark, 1);

    al_draw_line(21, 52, 23, 52, steelDark, 1);
    al_draw_line(23, 53, 25, 53, steelDark, 1);
    al_draw_line(25, 54, 27, 54, steelDark, 1);
    al_draw_line(27, 55, 37, 55, steelDark, 1);
    al_draw_line(37, 54, 39, 54, steelDark, 1);
    al_draw_line(39, 53, 41, 53, steelDark, 1);
    al_draw_line(41, 52, 43, 52, steelDark, 1);


    al_draw_line(21, 29, 21, 31, steelDark, 1);
    al_draw_line(20, 31, 20, 33, steelDark, 1);
    al_draw_line(19, 33, 19, 35, steelDark, 1);
    al_draw_line(18, 35, 18, 45, steelDark, 1);
    al_draw_line(19, 45, 19, 47, steelDark, 1);
    al_draw_line(20, 47, 20, 49, steelDark, 1);
    al_draw_line(21, 49, 21, 51, steelDark, 1);

    al_draw_line(44, 29, 44, 31, steelDark, 1);
    al_draw_line(45, 31, 45, 33, steelDark, 1);
    al_draw_line(46, 33, 46, 35, steelDark, 1);
    al_draw_line(47, 35, 47, 45, steelDark, 1);
    al_draw_line(46, 45, 46, 47, steelDark, 1);
    al_draw_line(45, 47, 45, 49, steelDark, 1);
    al_draw_line(44, 49, 44, 51, steelDark, 1);

    al_draw_line(27, 30, 37, 30, black, 1);
    al_draw_line(27, 51, 37, 51, black, 1);
    al_draw_line(22, 35, 22, 45, black, 1);
    al_draw_line(43, 35, 43, 45, black, 1);


    al_draw_line(22, 35, 27, 30, black, 1);
    al_draw_line(37, 30, 42, 35, black, 1);
    al_draw_line(22, 45, 27, 50, black, 1);
    al_draw_line(37, 50, 42, 45, black, 1);

    al_draw_line(27, 31, 37, 31, steelDark, 1);
    al_draw_line(27, 50, 37, 50, steelDark, 1);
    al_draw_line(23, 35, 23, 45, steelDark, 1);
    al_draw_line(42, 35, 42, 45, steelDark, 1);

    al_draw_line(23, 35, 27, 31, steelDark, 1);
    al_draw_line(37, 31, 41, 35, steelDark, 1);
    al_draw_line(23, 45, 27, 49, steelDark, 1);
    al_draw_line(37, 49, 41, 45, steelDark, 1);

	
}
void arrowClass::erase_arrow()
{

	int left = x ;
	int top = y;
	int right = x + 64;
	int bottom =y + 64;

	al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0, 0, 0));
}

void arrowClass::up()
{
	dir=0;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;
}

void arrowClass::down()
{
	dir=2;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}


void arrowClass::left()
{
	dir=3;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}

void arrowClass::right()
{
	dir=1;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}
int arrowClass::getDirection()
{
	return dir;
}
int arrowClass::getSpeed()
{
	return speed;
}
int arrowClass::getX()
{
	return x;
}
int arrowClass::getY()
{
	return y;
}
void arrowClass::move_arrow(int width, int height)
{

	//update arrow position based on direction
	switch(dir)
	{
	case 0:
		y -= speed;
		break;
	case 1:
		x += speed;
		break;
	case 2:
		y += speed;
		break;
	case 3:
		x -= speed;
	}

	//keep arrow inside the screen
	if (x > width-64)
	{
		x = width-64;
		speed = 0;
	}
	if (x < 0)
	{
		x = 0;
		speed = 0;
	}
	if (y > height-64)
	{
		y = height-64;
		speed = 0;
	}
	if (y < 0)
	{
		y = 0;
		speed = 0;
	}
}
