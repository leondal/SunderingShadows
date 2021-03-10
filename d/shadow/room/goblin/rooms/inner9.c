#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit ROOM;
 
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
   set_indoors(1);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin witch's chamber%^RESET%^");
    set_long( "%^BLUE%^"
	"The chamber here behind the %^GREEN%^curtains%^BLUE%^"
	" is as black as the night. "
	"The walls are painted black and seem to absorb the light. A pile "
	"of %^MAGENTA%^pillows%^BLUE%^"
	" lay in one corner of the room and a "
	"%^RED%^large cauldron%^BLUE%^"
	" sits in the "
	"center of the room."
        "%^RESET%^"
    );
    set_smell("default","It smells of evil magic.");
    set_listen("default","A faint cackle fills the chamber.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone and painted black.",
	"pillows":"The pillows lay in one corner of the room and are "
	"likely used for sleeping upon.",
	"cauldron":"%^RED%^The cauldron is jet black and filled with "
	"some vile substance.%^RESET%^",
	"substance":"The substance in the cauldron bubbles and boils "
	"and seems unsuitable for eating.",
	"curtains":"The curtains cover the opening leading out of the "
	"chamber",
    ]));
    set_exits(([
        "west": RPATH "inner8",
    ]));
}

void reset() {
    ::reset();
    if(!random(3))
      if(!present("goblin")) {
        new( MPATH "witch.c" )->move(TO);
      if(!random(5))
        new( MPATH "ranger.c")->move(TO);
    }
}
