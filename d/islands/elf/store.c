//store
#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Store");
    set_short("Store");
    set_long(
"%^ORANGE%^To one side of the keep stands what looks to be a bit of a store%^MAGENTA%^.%^ORANGE%^  A well "+
"carved table has some %^GREEN%^trinkets%^ORANGE%^ and %^GREEN%^clothes%^ORANGE%^ that have been designed by elves "+
"with knack for craftsmanship%^MAGENTA%^.%^ORANGE%^  A few younger elves tend to keeping things "+
"straightened gently ordered around by the master craftsman who runs the small "+
"store%^MAGENTA%^.%^ORANGE%^  Things can be bought from a booth against the wall%^MAGENTA%^.%^ORANGE%^ " +
"Purple lights float near the ceiling%^MAGENTA%^.%^ORANGE%^ %^RESET%^
");

	set_items(([
      (({"trinkets","clothes"})) :
        "Products are displayed at the booth and on the table.",
      (({"walls","stone","wall"})) : "The room is made of stone as a base.  The rest is decoration. ",

	  (({"lights","purple lights"})) : "Floating balls of purple lights cast a glow in this room. ",
	   ]));

   
      set_exits(([ "north" : ROOMS"hall3",
        "east" : ROOMS"hall8",	  ]));

   set_smell("default","One can smell the scent of crafting tools and trees.");
   set_listen("default",
   "%^RESET%^The clanging of %^YELLOW%^coins%^RESET%^ can be heard to one side.");
}
void reset(){
::reset();
if(!present("shop keeper")) new(MON"shopy")->move(TO);
}
