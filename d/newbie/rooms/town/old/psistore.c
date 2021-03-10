#include "../../newbie.h"
inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("Psychic Ventures");
	set_short("%^BOLD%^Psychic Ventures%^RESET%^");
	set_long("%^BOLD%^Psychic Ventures%^RESET%^\n"+
"This unusual room is filled with dozens of %^BOLD%^crystals %^RESET%^hovering in the air at different heights.  Crystals "
"and gems in all hues can be seen, already threaded on slender silken %^ORANGE%^cords %^RESET%^to be plucked from the air "
"as they are sold.  The crystals seem to move, allowing passage whenever someone merely approaches them, and they duck "
"quickly away from any thieving hands who might be foolish enough to try and snatch one.  There are no other features to "
"the room, not even a chair.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
	set_smell("default","A pleasing aroma of incense fills the air.");
	set_listen("default","A soft whoosh of crystals moving out of the way can be heard.");
	set_items( ([
         ({"crystal","crystals","gem","gems"}) : "%^BOLD%^%^WHITE%^The crystals and gems hovering in the air seem to hang "
"suspended from their silken cords.  These psicrystals have been carefully selected for their resonant psionic energies, "
"then shaped into their final forms.  When a psion needs a new psicrystal, the perfect crystal will resonate with the "
"psion.%^RESET%^"
    ]) );
    set_exits(([
        "west" : MAINTOWN"psifoyer"
    ]) );
}

void reset(){
   ::reset();
   if(!present("salha")) find_object_or_load(MON"salha")->move(TO);
}