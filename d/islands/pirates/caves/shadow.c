#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",-2);
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
   set_name("Entrance to the Realm of Shadows");
   set_short("Entrance to the Realm of Shadows");
   set_long("%^BOLD%^Entrance to the Realm of Shadows%^RESET%^\n"
"Darkness engulfs you.  There is nothing here but darkness.  But you are not alone, you can feel things at "
"the edge of your perception.  Things that no sane person wants to meet.");
   set_exits(([
     "portal":CAVES"cave10"
   ]));
}

void reset()
{
	::reset();
   	if(!present("shadow"))
		//find_object_or_load(MON"shadowmonster")->move(TO);
		new(MON"shadowmonster")->move(TO);
}
