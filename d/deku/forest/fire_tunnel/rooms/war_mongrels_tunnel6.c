#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The tunnel rises slightly to the "+
	"east and begins leveling off to the south here.%^RESET%^");

    set_exits(([
    		"east" : FTUN_ROOMS"war_mongrels_tunnel5",
		"south" : FTUN_ROOMS"war_mongrels_tunnel7"
    ] ));
}


