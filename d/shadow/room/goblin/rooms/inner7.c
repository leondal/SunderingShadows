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
    set_short("%^BLUE%^Goblin sorceror's chamber%^RESET%^");
    set_long( "%^BLUE%^"
        "The chamber behind the %^MAGENTA%^curtains%^BLUE%^"
	" is filled with unusual "
	"items and devices. A %^ORANGE%^large workbench%^BLUE%^"
	" is covered with tomes "
	"and scrolls. A %^GREEN%^small cot%^BLUE%^"
	" lays in a corner of the room. On "
	"the west wall a %^RED%^bloody pentagram%^BLUE%^"
	" is scrawled onto the stone "
	"wallface. The floor is covered in elaborate %^CYAN%^runes%^BLUE%^"
	"."
        "%^RESET%^"
    );
    set_smell("default","It smells of evil magic.");
    set_listen("default","A faint cackle fills the chamber.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
	"cot":"The plain cot lays against a wall.",
	"pentagram":"%^RED%^The pentagram was made by spreading blood "
	"onto the west wall.%^RESET%^",
	"tomes":"The tomes are written in the native goblin tongue "
	"and are useless to you.",
	"scrolls":"The scrolls are of an unknown nature and useless "
	"to you.",
	"instruments":"It is not clear what the instruments are for.",
	"devices":"The various devices are used in the goblin magical "
	"rituals.",
	"table":"The table is littered with scrolls and tomes"
    ]));
    set_exits(([
        "east": RPATH "inner8",
    ]));
}

void reset() {
    ::reset();
    if(!random(3))
     if(!present("goblin")) {
        new( MPATH "mage.c" )->move(TO);
        if(!random(8))
          new( MPATH "royal.c" )->move(TO);
        if(!random(10))
          new( MPATH "archer.c" )->move(TO);
    }
}
