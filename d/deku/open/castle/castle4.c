//	castle4.c
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
    set_short("Near the well.");
    set_long(
@CASTLEYARD
 You enter the large castleyard. You see the well here. It isn't very
nice anymore, but all people living in this castle drink the water it
gives to them. You notice that the condition of the yard here is as
bad as the rest of the yard.
CASTLEYARD
    );
set_smell("default", "You smell nothing special.");
set_smell("grass"  , "You smell at the grass as a cow would,but you don't think that it smells that good to eat.");
set_listen("default","You hear the wind rushing here.");
    set_exits(([
       "south" : CASTLE+"castle3",
       "north" : CASTLE+"castle5"
    ] ));
    set_items(([
       "grass" : "The grass grows between the stones and makes the yard look very unpreserved !",
       "stones" : "The stones make up the yard, but grass is growing between them.",
       "well" : "This is a well made out of stone. There is water in it and it is drinkable. You can't get to the water though, while the stableboy has the bucket."
    ] ));
}

// For all that enter a little rabbit or mouse for trying !
void init() 
{ int x; 
  ::init();
/*  mouse file was empty & couldn't load *Styx*  11/22/02
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
*/
  if (!present("rabbit") && !random(3))
        new(CASTLE+MONSTERS+"rabbitP")->move(this_object());
}
