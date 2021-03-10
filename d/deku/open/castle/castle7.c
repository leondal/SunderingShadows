//	castle7.c
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
You are in the large castleyard. To the north there is the hall leading into the castle and here it is a good place for little animals to doze in the sun. Also the big balcony can be seen here.
CASTLEYARD
    );
set_smell("default", "You smell nothing special.");

set_listen("default","You hear some sounds from within the castle.");
    set_exits(([
       "south" : CASTLE+"castle6",
       "north" : CASTLE+"castle8"
    ] ));
    set_items(([
       "grass" : "The grass grows between the stones and makes the yard look very unpreserved !",
       "stones" : "The stones make up the yard, but grass is growing between them.",
       "balcony" : "The balcony is in front of the queens chambers. It is very big and wide and the emblem is carved into the pilars."
    ] ));
}
// For all that enter a little rabbit or mouse for trying !
/* mouse file was empty and not loading so taking out the mob entirely since we're on the verge of retiring this area
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
*/
