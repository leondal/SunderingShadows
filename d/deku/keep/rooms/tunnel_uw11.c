#include <std.h>
#include "../keep.h"

inherit TUNNELUW;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  This tunnel continues here, westward "+
	"or eastward, it is your decision, for you are now "+
	"within the depths of this watery grave.%^RESET%^");
     set_exits(([
		"west": KEEPR + "tunnel_uw10", "east" : KEEPR + "tunnel_uw12"
    ] ));
	
}




