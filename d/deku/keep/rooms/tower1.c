#include <std.h>
#include "../keep.h"
inherit HTOWER;
void create() {
    ::create();
   set_long(TO->query_long() + "  The chamber is dominated by a spiral, %^BOLD%^%^WHITE%^stone "+
		"staircase%^RESET%^ leading to the level above.  A massive metal door in the southern wall "+
		"leads out of the tower.");
  set_exits(([
  "up" : KEEPR + "tower2",
  "out" : KEEPR + "keep2"
  ] ));
	set_door("tower door",KEEPR + "keep2", "out");
	set_door_description("tower door","This door is made from a %^BOLD%^%^WHITE%^gray%^RESET%^ metal.  An image of a %^RED%^red hawk%^RESET%^ in front of a %^BOLD%^%^BLACK%^black%^RESET%^ background is set into the front of it.%^RESET%^");
	
   
}
