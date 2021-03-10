//	castle3.c
//	Written by Pator@ShadowGate
//	Wed Apr 19 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_author("pator");
    set_light(2);
    set("indoors",0);
    set_short("In the castleyard");
    set("day long",
@CASTLEYARD
You enter the large castleyard. You look around and you see the well north of you. As you look more closely you see some grass between the stones and it looks like there aren't many people concerned about the well-being of this yard.
There is a sign here.
CASTLEYARD
    );
set("night long",
@CASTLEYARD
You enter the large castleyard. The moon lights your surroundings. As you look more closely you see some grass between the stones. Also a sign can be looked at.
CASTLEYARD
    );
set_smell("default", "You smell nothing special.");
set_smell("grass"  , "You smell at the grass as a cow would,but you don't think that it smells that good to eat.");
set_listen("default","You hear the sounds from the stables and the wind rushing here.");
    set_exits(([
       "south" : CASTLE+"castle2",
       "north" : CASTLE+"castle4"
    ] ));
    set_items(([
       "grass" : "The grass grows between the stones and makes the yard look very unpreserved !",
       "stones" : "The stones make up the yard, but grass is growing between them.",
       "sign" :
@SIGN
                          ** MARLEEN'S CASTLE **

The queen Marleen greets you all and especially you newbie's. This castle is filled with easy prey for good newbie-hunters and has some mindboggling presents for you too !

   The Queen wishes you a good stay and hopes to see you more around here !
SIGN
    ] ));
}

// For all that enter a little rabbit for trying !
void init() 
{ int x; 
  ::init();
  if (!(present("rabbit"))) {
    for (x = 0;x < random(3);x++) {
        new(CASTLE+MONSTERS+"rabbitP")->move(this_object());
      }
  }
}
