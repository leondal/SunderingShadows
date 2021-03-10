#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. A small %^ORANGE%^cot%^RED%^ "
	"lays pressed against one wall. It appears as though "
	"someone has been living here for eons, but there are no "
	"signs of food or drink. The chamber is clear of rubbage, "
	"dust and debris."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Chamber%^RESET%^");
    set_listen("default",
        "The entire room seems to be filled with the sound of wind chimes."
    );
    set_smell("default",
        "You smell a great fiery power."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"cot":"The cot is very plain and bears no covers or blankets.",
    ]));
    set_exits(([
        "east": RPATH "b7",
    ]));
}
void reset() {
    ::reset();
    if(!present("nicodemus")) {
        new( MPATH "nico.c" )->move(TO);
    }
}
