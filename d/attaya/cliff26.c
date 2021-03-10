#include <std.h>

inherit "/d/attaya/spec/cliff2";

void create(){
	::create();
       set_exits(([
          "up":"/d/attaya/cliff27",
          "down":"/d/attaya/cliff25",
]));
}
