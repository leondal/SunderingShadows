#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The tunnel rises slightly to the "+
	"northwest and continues in a downward slope to the west here.%^RESET%^");

    set_exits(([
    		"northwest" : FTUN_ROOMS"war_mongrels_tunnel2",
		"west" : FTUN_ROOMS"war_mongrels_tunnel4"
    ] ));
}


