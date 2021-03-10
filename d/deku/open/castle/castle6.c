//	castle6.c
//	Written by Pator@ShadowGate
//	Wed May 3  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_author("pator");
    set_light(2);
    set_indoors(0);
    set_short("In the castleyard.");
    set_long(
@CASTLEYARD
You are in the large castleyard. To the southeast there is the training area. This part of the yard is just there and has only the function of not having any building on it.
CASTLEYARD
    );
set_smell("default", "You smell nothing special.");

set_listen("default","You hear some sounds from within the castle.");
    set_exits(([
       "southeast" : CASTLE+"castle5",
       "north" : CASTLE+"castle7"
    ] ));
    set_items(([
       "grass" : "The grass grows between the stones and makes the yard look very unpreserved !",
       "stones" : "The stones make up the yard, but grass is growing between them."
    ] ));
}

void init() 
{ int x; 
  ::init();
  if (!(present("rabbit") || present("castle mouse"))) 
  {
    x = random(3);
    if (x==2) {
    for (x = 0;x < random(3);x++) {
        new(CASTLE+MONSTERS+"rabbitP")->move(this_object());
                                  }
            }
    else    {
    for (x = 0;x < random(2);x++) {
        new(CASTLE+MONSTERS+"C_mouse")->move(this_object());
                                  }
           }
  }
}
