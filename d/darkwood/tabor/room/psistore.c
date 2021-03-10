#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_indoors(1);
	set_name("Balanced Meditations");
	set_short("Balanced Meditations");
	set_long(
"%^BOLD%^Balanced Meditations, Tabor%^RESET%^\n"+
"%^CYAN%^Crafted of the same crystalline blue material as "+
"the rest of the enclave, this small shop features a carved, "+
"g%^BOLD%^l%^RESET%^%^CYAN%^i%^BOLD%^t%^RESET%^%^CYAN%^t%^BOLD%^e"+
"%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^g %^RESET%^"+
"%^CYAN%^entryway in the shape of an oval-cut crystal.  Slender "+
"%^BOLD%^glass shelves %^RESET%^%^CYAN%^spread around the room are "+
"draped in %^BOLD%^%^WHITE%^silk%^RESET%^%^CYAN%^, each supporting a "+
"different type of %^BOLD%^crystal %^RESET%^%^CYAN%^in various hues.  "+
"Shades of %^RED%^red%^CYAN%^, %^MAGENTA%^purple%^CYAN%^, %^GREEN%^"+
"green%^CYAN%^, %^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^, %^YELLOW%^"+
"gold%^RESET%^%^CYAN%^, and every hue in between capture the light "+
"of the tiny %^YELLOW%^globes %^RESET%^%^CYAN%^hovering near the ceiling.  "+
"Each of the %^BOLD%^psicrystals %^RESET%^%^CYAN%^is threaded onto "+
"a silken cord in a complimentary color.  A lavish pile of %^MAGENTA%^"+
"cushions %^CYAN%^in the central portion of the room stakes out the "+
"shopkeeper's ground, and from here he helps psions find their "+
"chosen crystals.%^RESET%^\n\n"+
"<help shop> will give you help on how to use the shop.\n"
	);
	set_smell("default","A crisp, clean fragrance of the outdoors permeates the air.");
	set_listen("default","Few sounds disturb the serenity of this small shop.");
	set_items( ([
         ({"crystal","crystals","gem","gems"}) : "The crystals "+
            "have been arranged on their silken beds according to "+
            "hue.  It is believed that a psicrystal's color reflects "+
            "the temperament of the psion.  The crystals are all strung "+
            "upon complimentary silken cords, giving them a finished "+
            "look.",
         ({"cushions","cushion","pile"}) : "The pile of silken cushions "+
            "looks to be heavenly soft.  They are fashioned in all shades "+
            "of purple from the lightest lavender to deep mulberry.",
         ({"shelves","glass shelves","shelf"}) : "The shelves are made "+
            "from thin, smooth glass covered with white silk.",
         ({"globes","light"}) : "Tiny globes of light float in the air "+
            "near the ceiling, bathing the area in a soft light."
    ]) );
    set_exits(([
        "south" : ROOMDIR+"psifoyer"
    ]) );
}

void reset(){
   ::reset();
   if(!present("hanif")) {
      find_object_or_load(MONDIR+"hanif")->move(TO);
   }
}
