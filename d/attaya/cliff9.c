#include <std.h>

inherit "/d/attaya/spec/ledge";

void create(){
	::create();
       set_exits(([
          "west":"/d/attaya/cliff10",
         "east":"/d/attaya/cliff8"
]));
}

