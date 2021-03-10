
#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
    set_long(::query_long()+"A %^BLACK%^stairway%^WHITE%^ begins here and climbs yet higher. You can see the Crystalline Tower walls just above you! The stairs are covered completely by snow.");
       set_exits(([
          "west":"/d/attaya/cliff39",
         "up":"/d/attaya/cliff41"
]));
	
      set_smell("default", "It is so very cold and lonely up here.");
      set_listen("default", "Cold winds rip past you.");
}

