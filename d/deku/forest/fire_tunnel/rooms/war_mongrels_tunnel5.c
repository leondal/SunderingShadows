#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The tunnel rises slightly to the "+
	"east and continues in a downward slope to the west here.%^RESET%^");

    set_exits(([
    		"east" : FTUN_ROOMS"war_mongrels_tunnel4",
		"west" : FTUN_ROOMS"war_mongrels_tunnel6"
    ] ));
}


