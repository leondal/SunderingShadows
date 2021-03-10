#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
       set_exits(([
          "west":"/d/attaya/cliff8",
         "east":"/d/attaya/cliff6"
]));
}

