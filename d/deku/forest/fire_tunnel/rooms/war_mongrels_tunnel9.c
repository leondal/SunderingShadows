#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The tunnel turns sharply to "+
	"the northwest and continues westward here.%^RESET%^");

    set_exits(([
    		"northwest" : FTUN_ROOMS"war_mongrels_tunnel8",
		"west" : FTUN_ROOMS"war_mongrels_tunnel10"
    ] ));
}


