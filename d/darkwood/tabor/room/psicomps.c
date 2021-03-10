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
	set_name("Forgotten Gems");
	set_short("Forgotten Gems");
	set_long(
"%^BOLD%^Forgotten Gems, Tabor%^RESET%^\n"+
"%^CYAN%^The exit to this shop is a large round archway, simple "+
"but effective in design.  The opening allows a full view of the "+
"foyer from here, so the shopkeeper may glance at passersby as "+
"he undertakes his work.  Unlike the other parts of this enclave, "+
"this particular room is filled with a bustling, busy, no-nonsense "+
"air of work.  Several low %^ORANGE%^wooden tables %^CYAN%^take up "+
"much of the floorspace, each scattered with various implements of "+
"gem cutting and shaping.  All around the tables, %^BOLD%^glass "+
"bins %^RESET%^%^CYAN%^stand, supporting neatly sorted crystals.  "+
"Each bin holds only one type of %^BOLD%^%^WHITE%^crystal%^RESET%^"+
"%^CYAN%^ in a certain cut, evidence that these crystals are used for "+
"something other than making jewelry.\n\n"+
"%^RESET%^<help shop> will give you help on how to use the shop.\n"
	);
	set_smell("default","A muted fragrance of wood mingles with the clean scent of water.");
	set_listen("default","The occasional sound of gems striking one another rises above the otherwise quiet of the store.");
	set_items( ([
         ({"archway","exit","entryway","arch"}) : "The archway is "+
            "a simple circle, carved from the blue stone of the "+
            "enclave.  It leads back into the main foyer.",
         ({"table","tables","wooden tables"}) : "The wooden tables "+
            "are rather low to the ground, too low for a human to "+
            "use comfortably.  They are covered with tools in "+
            "a neat state of use, ready to be taken up when "+
            "the need arrises.  Small hammers, chisels, polishing "+
            "clothes and stones, and all manner of items used in "+
            "finishing gems can be seen here.",
         ({"bin","bins","crystals","gems"}) : "The glass bins stand "+
            "upon pedastals, their contents easily visible.  "+
            "Crystals in all shapes, sizes, and colors are within, "+
            "ready to be used by the psions of the realms."
    ]) );
    set_exits(([
        "north" : ROOMDIR+"psifoyer"
    ]) );
}

void reset(){
   ::reset();
   if(!present("rusilas")) {
      find_object_or_load(MONDIR+"rusilas")->move(TO);
   }
}
