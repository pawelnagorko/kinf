//
// Szablon gry w Allegro 5. (C) Kółko Informatyczne Szkoły Żagle
//

#include <queue>
#include <iostream>
#include <vector>
#include <sstream>

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;

//
// Konfiguracja gry
//

const int screen_w = 500;   // szerokość ekranu (screen width)
const int screen_h = 500;   // wysokość ekranu (screen height)

/****************************************
 * Tu rozpoczyna się istotna część kodu *
 ****************************************/
 
//
// Struktury danych
//

bool key[ALLEGRO_KEY_MAX];


//
// Zmienne
//
	int xgracza = screen_w/2, ygracza = screen_h/2;
	int xduszka = 100, yduszka = 100;
	int xs = screen_w, ys = screen_h;
	bool prawo = false, lewo = false, gora = false, dol = false;
	int xcel = 500, ycel = 281;
	bool koniec = false;

	
	ALLEGRO_BITMAP* pacman;
	ALLEGRO_BITMAP* duszek;
	ALLEGRO_FONT* font = NULL;
	
	


//
// Rysowanie planszy
//

void rysuj_plansze()
{	
	al_clear_to_color(al_map_rgb(0,0,0));

	al_draw_pixel(xduszka, yduszka, al_map_rgb(255,0,0));
	al_draw_pixel(xgracza, ygracza, al_map_rgb(255,255,0));
	
	if (koniec){
	al_clear_to_color(al_map_rgb(0,255,0));
	}
    
}

//
// Mechanika gry
//

void aktualizuj_plansze()
{
		
}

//
// Reakcja na akcje graczy
//

void co_robia_gracze()
{
	if (key[ALLEGRO_KEY_UP]) {
		ygracza -= 2;
 		if (ygracza < 0) { ygracza = ys - 1; }
		gora = true; dol = false; prawo = false; lewo = false;
	}else if (key[ALLEGRO_KEY_DOWN]) {
		ygracza += 2; 
		if (ygracza >= ys) { ygracza = 0; }
		gora = false; dol = true; prawo = false; lewo = false;
	}else if (key[ALLEGRO_KEY_LEFT]) {
		xgracza -= 2; 
		if (xgracza < 0) { xgracza = xs - 1; }
		gora = false; dol = false; prawo = false; lewo = true;
	}else if (key[ALLEGRO_KEY_RIGHT]) {
		xgracza += 2;
		if (xgracza >= xs) { xgracza = 0; }
		gora = false; dol = false; prawo = true; lewo = false;
	}

}

void co_robia_duszki() {
	

	xcel = xgracza - xduszka;
	if (xcel < 0){
		xduszka -=1;
	}else if (xcel > 0){
		xduszka +=1;
	}else if (ycel < 0){
		yduszka -=1;
	}else if (ycel > 0){
		yduszka +=1;
	}
	
	if (yduszka < 0) { yduszka = ys - 1; }
	if (yduszka > ys) { yduszka = 0; }
	if (xduszka < 0) { xduszka = xs - 1; }
	if (xduszka >= xs) { xduszka = 0; }
	
	if (xcel == 0 && ycel == 0){
		koniec = true;
	}

}

/****************************************
 * Kod poniżej jest w miarę generyczny  *
 ****************************************/
 
const float FPS = 60;       // Frames Per Second

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

int init()
{
    if(!al_init()) {
        cerr << "Błąd podczas inicjalizacji allegro." << endl;
        return -1;
    }
  
    if (!al_init_primitives_addon()) {
        cerr << "Błąd podczas inicjalizacji dodatku 'primitives'." << endl;
        return -1;
    }
    
    if (!al_install_keyboard()) {
        cerr << "Błąd podczas inicjalizacji klawiatury." << endl;
        return -1;
    }

    if (!al_install_mouse()) {
        cerr << "Błąd podczas inicjalizacji myszy." << endl;
        return -1;
    }
  
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        cerr << "Błąd podczas inicjalizacji zegara." << endl;
        return -1;
    }
 
    display = al_create_display(screen_w, screen_h);
    if(!display) {
        cerr << "Błąd podczas inicjalizacji ekranu." << endl;
        al_destroy_timer(timer);
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        cerr << "Błąd podczas inicjalizacji kolejki zdarzeń." << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
	
	 
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
        font = al_load_ttf_font("AdvoCut.ttf",16,0);
        if (!font) {
            cerr << "Nie mogę załadować czcionki AdvoCut.ttf" << endl;
            al_destroy_display(display);
            al_destroy_timer(timer);
            return -1;
        }
	   if(!al_init_image_addon()) {
		// blad
      return 0;
   }
  
    al_register_event_source(event_queue, al_get_display_event_source(display));  
    al_register_event_source(event_queue, al_get_timer_event_source(timer));  
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
  
    al_flip_display();  
    al_start_timer(timer);
	
	pacman = al_load_bitmap("Pacman.png");

	if (pacman == NULL) {
		cout << "Nie udalo sie zaladowac pliku." << endl;
		exit(1);	
	}
	duszek = al_load_bitmap("duszek.png");

	if (duszek == NULL) {
		cout << "Nie udalo sie zaladowac pliku." << endl;
		exit(1);	
	}


    return 0;
}

int main(int argc, char ** argv)
{
    if (init() != 0) {
        cerr << "Inicjalizacja nie powiodła się." << endl;
        return -1;
    }
 
    bool przerysuj = true;
    bool wyjdz = false;  

    //
    // Event loop - główna pętla programu
    //
        
    while(!wyjdz)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            //
            // minęła 1/60 (1/FPS) część sekundy
            //
            przerysuj = true;

	    co_robia_duszki();

            co_robia_gracze();

            aktualizuj_plansze();

        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            key[ev.keyboard.keycode] = true;
        } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            key[ev.keyboard.keycode] = false;
            
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                wyjdz = true;
            }
        }

        if(przerysuj && al_is_event_queue_empty(event_queue)) {
            przerysuj = false;

            rysuj_plansze();

            al_flip_display();
         }    
    }

    return 0;
}
