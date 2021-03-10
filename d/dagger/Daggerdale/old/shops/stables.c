#include <std.h>
#include "/d/shadow/room/city/melnmarn.h"

inherit STABLE;

void create(){
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_id("stables");
	set_short("Daggerdale stables");
	set("long",
@SIA
	%^BOLD%^%^RED%^ Daggerdale Stables %^RESET%^
The stables are small but clean and the horses are well cared
for.  Trusty steads wait to carry adventurers on their journies.
Stories of the invaluable services these mounts provided to
adventurer's are posted around the stable.
	You may purchase a horse for a small price.<buy horse>
SIA
);

set_exits((["west" : "/d/dagger/Daggerdale/streets/street31"]));
	set_items((["stalls":"These line the walls. Most contain good mounts."]));
	set_smell("default","The smell of hay and manure mix together.");
	set_listen("default","An occassional whiny reaches your ears, along with a snort or so.");
set_animal(({"horse"}),({"/d/shadow/mon/horse"}));
set_animal_price(({"horse"}),({75}));
   set_stalls(20);
   ::fill_stalls();
}

