#include <std.h>
#include "../keep.h"

inherit TUNNELBUR;

void create() {
    ::create();
	set_long(TO->query_long() + "%^BOLD%^%^RED%^  This massive chamber "+
	"opens up to another west of here.%^RESET%^");  
     set_exits(([
		"west": KEEPR + "burial_chamber_1"
     ] ));
}



