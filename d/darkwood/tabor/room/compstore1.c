//updated by Circe 5/30/04 with new desc, color, etc.
// Euporium Arcana, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// tgate.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create()
{
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_name("Emporium Arcana, Tabor");
	set_short("Emporium Arcana, Tabor");
	set_long(
"%^BOLD%^RED%^Emporium %^CYAN%^Arcana%^WHITE%^, Tabor%^RESET%^\n"+
"%^BOLD%^Unlike the foyer, this room has been crafted from the "+
"same white marble as the outer walls of the tower.  Fantastic "+
"%^BLUE%^shelves %^WHITE%^made of %^BLUE%^blue marble %^WHITE%^"+
"veined in %^YELLOW%^gold %^WHITE%^hang suspended in mid-air along "+
"the walls.  No sign of support can be seen, but the %^BLUE%^shelves "+
"%^WHITE%^seem solid and sturdy enough.  Piled upon the shelves are "+
"a jumble of odds and ends, the %^GREEN%^components %^WHITE%^of "+
"%^CYAN%^arcane spells%^WHITE%^.  A %^BOLD%^%^BLACK%^gra%^WHITE%^"+
"n%^BLACK%^it%^WHITE%^e %^BLACK%^counter %^WHITE%^stands near the "+
"northern wall, covered in components in various stages of "+
"distillation.   %^CYAN%^Beakers %^WHITE%^and other implements "+
"are scattered across the counters surface, and it seems the "+
"shopkeeper must constantly be refining his components.  Despite "+
"the height of the ceiling and consequently the shelves, there is "+
"no ladder in sight.\n\n"+
"%^RESET%^<help shop> will give you help on how to use the shop.\n"
	);
	set_smell("default","You smell the odor of the sulfur and "+
		"various acids.");
	set_listen("default","You hear the buzzing of fireflies.");
	set_items( ([
        ({"components","store","counter","shelf","shelves"}):
            "Despite the jumble of materials on the counter, each "+
            "component on the shelves has been neatly categorized "+
            "and labeled.  They are all in their own containers, "+
            "and it seems it would be easy for the shopkeeper to "+
            "find most anything he needs.",
        ({"counter","granite counter","beakers","instruments"}) : "The "+
            "long counter in the "+
            "northern end of the room seems rather low for humans.  "+
            "It is covered in glass beakers, test tubes, and various "+
            "other instruments that aid in creating and distilling "+
            "spell components.",
    ]) );
    set_exits( ([
        "west" : ROOMDIR+"tfloor1",
        "foyer" : ROOMDIR+"tfoyer",
    ]) );
    new(MONDIR+"llewddyn")->move(TO);
}
