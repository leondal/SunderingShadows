#include <std.h>

inherit "/d/attaya/spec/ledge2";

void create(){
	::create();
	set_name("Ledge on the Obsidian Staircase.");
    set_long(::query_long()+"The ledge disappears inside a small structure to the east.");
       set_exits(([
          "west":"/d/attaya/cliff22",
         "east":"/d/attaya/cliff20"
]));
}

