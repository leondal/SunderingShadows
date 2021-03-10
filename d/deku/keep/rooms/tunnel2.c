#include <std.h>
#include "../keep.h"

inherit TUNNEL;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  The tunnel continues into "+
		"%^BOLD%^%^BLACK%^darkness %^RESET%^%^YELLOW%^to the northeast "+
		"and southwest.%^RESET%^");  
    set_exits(([
		"southwest": KEEPR + "tunnel3", "northeast" : KEEPR + "tunnel1"
    ] ));
	
}


