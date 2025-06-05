//Aiden D'Antuono

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "arrow.h";
#include "bullet.h"

void drawScore(int width, int height, int score, int timePassed, ALLEGRO_FONT *font);

int main(void)
{
	arrowClass arrow;
	bullet mybullet[10];
	int score=0;
	bool redraw=true;
	const int FPS = 60;
	int timePassed = 0;

	//variables
	int width = 640;
	int height = 480;
	bool done = false;

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height + 40);			//create our display object

	if(!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	arrow.create_arrow_bitmap(display);
	
	for (int i = 0; i < 10; i++) {
		mybullet[i].create_bullet_bitmap(display);
	}

	ALLEGRO_FONT *font = al_load_font("PressStart2P.ttf", 16, 0);
	ALLEGRO_FONT *fontBig = al_load_font("PressStart2P.ttf", 64, 0);
	if (font == NULL || fontBig == NULL) {
		return -1;
	}

	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0,0,0));
	arrow.drawArrow();
	al_flip_display();
	al_start_timer(timer);

	while(!done)
	{
		//Wait until 30 seconds have passed then stop the game
		if (timePassed > 1800) {
			al_stop_timer(timer);
			al_draw_textf(fontBig, al_map_rgb(255, 0, 0), width / 2, height / 2 - 40, ALLEGRO_ALIGN_CENTER, "GAME OVER");
			al_flip_display();
		}
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			for(int i=0;i<10;i++)
			{
				if (!mybullet[i].getStatus()) {
					mybullet[i].fire();
				}
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				arrow.up();
				break;
			case ALLEGRO_KEY_DOWN:
				arrow.down();
				break;
			case ALLEGRO_KEY_LEFT:
				arrow.left();
				break;
			case ALLEGRO_KEY_RIGHT:
				arrow.right();
				break;
			}
		}
		if(redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false; 

			if (arrow.getSpeed()!=0){
				arrow.erase_arrow();
				arrow.move_arrow(width,height);
			}
			arrow.drawArrow();
			for(int i=0;i<10;i++)
			{
				mybullet[i].erase_bullet();
				score+=mybullet[i].move_bullet(arrow.getX(),arrow.getY(),64,64,height);
			}
		}
		drawScore(width, height, score, timePassed, font);
		al_flip_display();

		//Add one to the number of frames that have occurred
		timePassed++;
	}
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);						//destroy our display object
	system("pause");
	return 0;
}

//Makes an area at the bottom of the screen that displays the current score and time remaining
void drawScore(int width, int height, int score, int timePassed, ALLEGRO_FONT *font) {
	al_draw_filled_rectangle(0, height, width, height + 40, al_map_rgb(255, 255, 255));
	al_draw_textf(font, al_map_rgb(0, 0, 0), 10, height + 12, ALLEGRO_ALIGN_LEFT, "Score: %i", score);
	al_draw_textf(font, al_map_rgb(0, 0, 0), width - 10, height + 12, ALLEGRO_ALIGN_RIGHT, "Time: %i", 30 - (timePassed / 60));
}
