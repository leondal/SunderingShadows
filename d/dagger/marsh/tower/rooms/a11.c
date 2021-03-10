#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The inner hallway of the tower is decorated similar to other parts of the tower. "
	"The stone is more subdued in tone here however; almost as though the strange force "
	"which runs through it is being slowly drained out, devoured by an evil "
	"greater than that which twisted it's shape into existance. "
	"Remarkably, the entire floor as been painted into a large historical mural."
	"The mural has a light covering of dust across it's surface.\n"
	"%^BOLD%^%^RED%^A voice deep in the back of your head, begins to scream in panic!"
	"%^RESET%^" 
    );
    set_short("%^RED%^Inner Hallway%^RESET%^");
    set_listen("default",
        "A faint murmur is occasionally emitted from the walls."
    );
    set_smell("default",
        "The smell of pestilence on a cold winter morning surrounds you."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"mural":"%^GREEN%^The mural depicts a battlefield in which a man of "
	"great nobility stands victorious on a battlefield surrounded by the slain "
	"bodies of his enemies. Deeper in the picture can be seen a small hill. "
	"Storm clouds gather only over this hill, and part of the hill resembles "
 	"the look of a grinning skull, with large black stones placed where "
	"the eye cavities would be located. A lone dark figure stands within the storm "
	"which rages atop the hill, hands outstretched. Long thin strands of energy "
	"stretch towards the victorious man who stands unaware, celebrating his victory. "
	"The wisps of energy seem as though they seek to drain or collect something, and drift "
	"in a zig-zag searching pattern across the land, ever relentlessly hell bent on their mission "
	"to bring the energy back to the master's...eyes...those glowing red eyes set in that darkened "
	"evil face..."
	"the power behind the eyes rages...you cannot "
	"stop looking into the eyes...Suddenly you jerk your gaze away from the "
	"mural, realising you narrowly avoided being drawn into a fixated trance by the figure in the "
	"mural.",
    ]));
    set_exits(([
        "north": RPATH "a13",
	"south": RPATH "a7",
    ]));

    set_pre_exit_functions(({"north"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("wraith")) {
	write("The wraith blocks your way!");
	return 0;
    }
    write("%^BOLD%^%^BLUE%^"
	"An evil cackle echoes down the hall as you move north.%^RESET%^"
    );
    say("%^BOLD%^%^BLUE%^"
	"An evil cackle comes from the north."
    ,TP);
    return 1;
}
void reset() {
    ::reset();
    if(!present("wraith")) {
	new( MPATH "wraith.c" )->move(TO);
    }
}
