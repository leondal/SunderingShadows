#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^ The portal back into the "+
	"%^BOLD%^%^WHITE%^white stone%^RESET%^%^RED%^ chamber looks "+
	"inviting.  %^RED%^The tunnel also continues southward here, in "+
	"a downward slope.%^RESET%^");

    set_exits(([
    		"south" : FTUN_ROOMS"war_mongrels_tunnel2",
		"portal" : FTUN_ROOMS"kinordas_chamber"
    ] ));
}


