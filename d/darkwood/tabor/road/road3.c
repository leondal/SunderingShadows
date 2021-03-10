#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
    set_long(::query_long()+"
%^ORANGE%^A path branches off to the southeast here. There is a sign you can read in front of it.%^RESET%^
");
   set_exits(([
   "north" : PATH+"road2",
   "southwest" : PATH+"road4",
   "southeast" : "/d/shadow/room/goblin/rooms/gate1",
   ]));
}

void reset()
{
	::reset();
	if(!present("sign"))
	{
		new("/d/common/obj/areas/goblin_sign.c")->move(TO);
	}
}
