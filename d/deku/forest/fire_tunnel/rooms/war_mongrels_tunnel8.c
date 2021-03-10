#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The tunnel turns sharply to "+
	"the northeast or southeast here.%^RESET%^");

    set_exits(([
    		"northeast" : FTUN_ROOMS"war_mongrels_tunnel7",
		"southeast" : FTUN_ROOMS"war_mongrels_tunnel9"
    ] ));
}


