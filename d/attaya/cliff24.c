
#include <std.h>

inherit "/d/attaya/spec/ledge2";

void create(){
	::create();
    set_long(::query_long()+"
Far above you, are the walls to the %^WHITE%^Crys%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^line %^WHITE%^Tower%^BLACK%^ of the Black Dawn. You cannot see the tower itself because the walls are too high, and you are a long way beneath them.
");
       set_exits(([
          "up":"/d/attaya/cliff25",
         "east":"/d/attaya/cliff23"
]));
}

