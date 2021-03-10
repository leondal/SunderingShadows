#include <std.h>
#include "../keep.h"

inherit TUNNELBUR;

void create() {
    ::create();
	set_long(TO->query_long() + "%^BOLD%^%^RED%^  This massive chamber "+
	"opens up to another east of here.%^RESET%^");  
     set_exits(([
		"east": KEEPR + "burial_chamber_1"
     ] ));
}



