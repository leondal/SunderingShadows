#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
    set_long(::query_long()+" A ladder fastened to the cliff face here leads down to a nearby ledge.");
       set_exits(([
          "east":"/d/attaya/cliff76",
         "down":"/d/attaya/cliff74"
]));
}

