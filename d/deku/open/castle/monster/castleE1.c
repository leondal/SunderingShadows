//	castleE1.c
//	Pator@ShadowGate
//	Tue Apr 11 1995

#include <castle.h>

inherit ROOM;

void create() 
{
    ::create();
    set_light(1);
    set_indoors(1);
    set_short("Inside the castle's stables");
    set("day long",
@DAY
You look around and you find that all the boxes are empty. The boy is cleaning up the floor and putting fresh food & drink for the horses in place so when they return they can drink and eat whenever they want.
DAY
);
    set("night long",
@NIGHT
You see that all the boxes are filled with sleeping or dozing horses.
NIGHT
    );
set_smell("default","You smell the familiar stable scent");
set_listen("default","Normal stables sounds tickle your ears.");
    set_exits(([
       "east"  : CASTLE+"castleE2.c",
       "west"  : CASTLE+"castle2.c"
    ]));
    set_items(([
                "torch" : "The torches aren't lit so it is hardly possible to see at all.",
                  "torch" : "The torches aren't lit so it is hardly possible to see at all.",
	        "boxes" : "The boxes are made of wood and straw is on the floor.",
		"bucket" : "The bucket is filled with water."
               ]));
   
}

void reset()
{
	::reset();
	if (!present("stableboy"))	{
	new(CASTLE+MONSTERS+"stableboy")->move(this_object());
			        }
}
