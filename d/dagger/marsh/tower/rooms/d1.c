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
	"Old rusted torch brackets hang broken "
	"from the walls. Cobwebs fill the chamber, as though nothing has entered "
	"this area of the tower for years. A mysterious %^WHITE%^unholy light%^RESET%^%^RED%^ fills "
	"the entire chamber."
	"%^RESET%^" 
    );
    set_short("%^RED%^Inner Hallway%^RESET%^");
    set_listen("default",
        "A faint murmur is occasionally emitted from the walls."
    );
    set_smell("default",
        "The hunger of evil permeates the chamber."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	
    ]));
    set_exits(([
        "north": RPATH "d3",
	"northwest": RPATH "d2",
	"northeast": RPATH "d4"
    ]));

    set_pre_exit_functions(({"north"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("knight")) {
	write("The knight blocks your way!");
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
    if(!present("knight")) {
	new( MPATH "angel.c" )->move(TO);
    }
}
