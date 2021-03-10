#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The tunnel rises slightly to the "+
	"north and turns sharply in a southwestern direction here.%^RESET%^");

    set_exits(([
    		"north" : FTUN_ROOMS"war_mongrels_tunnel6",
		"southwest" : FTUN_ROOMS"war_mongrels_tunnel8"
    ] ));
}


