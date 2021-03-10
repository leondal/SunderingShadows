#include <std.h>
#include "../keep.h"

inherit TUNNEL;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  The tunnel continues into "+
		"%^BOLD%^%^BLACK%^darkness %^RESET%^%^YELLOW%^to the northeast "+
		"and to the south.%^RESET%^");  
    set_exits(([
		"south": KEEPR + "tunnel4", "northeast" : KEEPR + "tunnel2"
    ] ));
	
}

