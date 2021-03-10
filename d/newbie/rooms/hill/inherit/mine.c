//mine.c

#include <std.h>
#include "../../../newbie.h"

inherit ROOM;
int to_find;
int max;

void set_gnome_max(int x);
void place_gnomes();

// These functions must be included in a room where mining with the
// /d/newbie/obj/mining_pick object is allowed.
int is_mind();
int query_to_find();
void set_found(int num);
object get_found_ob();

void create(){
   ::create();
   set_indoors(1);
   set_property("light",1);
   set_property("no teleport",1);
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
   set_short("Small Mine");
   set_smell("default","The smells of the hard-packed dirt and the pack animals fill the area.");
   set_listen("default","You hear the echo of picks ringing off the rock.");
   set_items(([
      "tracks":"There are tracks of small pack animals and people.",
      "rock":"The walls are composed mostly of rock but occasionally you see something glimmer brightly.",
      "walls":"The walls are composed mostly of rock but occasionally you see something glimmer brightly.",
      "carts":"There are carts that are completely empty, filled, or in between.",
   ]));
   set_search("walls","You take a closer look at the walls and see small gems glittering in the dim light.");
}

void reset(){
   ::reset();
   if(!random(3))
       to_find = random(10);
   else
       to_find = 0;
   if(!max) max = 3;
   place_gnomes();
   if( random(20) < 1 && !present("pick") ) 
	  	new("/d/newbie/obj/misc/mining_pick")->move(TO);
}

int is_mine(){return 1;}

int query_to_find(){return to_find;}

void set_found(int num){
    if(num <=0) return;
    if(num > to_find) num = to_find;
    to_find -= num;
}

object get_found_ob(){
    if(random(4))
        return new("/d/newbie/obj/misc/gem.c");
    else
        return new("/d/newbie/obj/misc/rock.c");
}

void place_gnomes(){
    int i;

    if(present("mining gnome "+max)) return;
    for(i=0;i<max;i++) {
        switch(random(6)){
        case 0..2:
            break;
        case 3:
            new(MON"gnome1")->move(TO);
            break;
        case 4:
            new(MON"gnome2")->move(TO);
            break;
        case 5:
            new(MON"gnome3")->move(TO);
        }

    }
}
