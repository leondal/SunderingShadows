#include "../../newbie.h"
inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("The Writer's Quill");
	set_short("%^BOLD%^The Writer's Quill%^RESET%^");
	set_long("%^BOLD%^The Writer's Quill%^RESET%^\n"+
"This small shop takes much from its name, for despite its lack of space there are copies of %^CYAN%^prose %^RESET%^and "
"%^MAGENTA%^poetry %^RESET%^upon every shelf.  They line the walls in neat bundles, each clearly marked and impeccably "
"ordered.  The store itself is only dimly lit by a few covered %^YELLOW%^lanterns%^RESET%^, lending it an air of cosiness "
"and age.  A small %^ORANGE%^desk %^RESET%^sits at the back of the room, covered in half-finished writings that will "
"probably make their way to the shelves soon enough.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
	set_smell("default","The air is heavy with the thick smell of aged parchment.");
	set_listen("default","Only the sounds of the city beyond interrupt the quiet of this store.");
	set_items( ([
        ({"prose","poetry","copies","writings"}) : "%^CYAN%^The shelves are covered in copies of prose and poetry in "
"nearly every available space around the small shop.  Yet more, still unfinished, lie upon the desk at the back of the "
"room.%^RESET%^",
        "lanterns" : "%^YELLOW%^Covered lanterns shed dim light around the little room, lending it a cosy air.%^RESET%^",
        ({"desk","small desk"}) : "%^ORANGE%^A small desk sits tucked away near the back of the room.  Half-finished "
"writings are scattered across its surface, no doubt the next to be added to the bundles upon the shelves.%^RESET%^"
    ]) );
    set_exits(([
        "north" : MAINTOWN"instruments",
        "east" : MAINTOWN"nstreet2",
    ]) );
}

void reset(){
   ::reset();
   if(!present("vanessa")) find_object_or_load(MON"vanessa")->move(TO);
}