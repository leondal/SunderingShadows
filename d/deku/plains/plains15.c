#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"There seems to be a break in the grass ahead.");
    set_listen("default","A low moan can be heard, or maybe it's the wind.");
    set_exits(([
       "east" : "/d/deku/plains/cave01",
       "west" : "/d/deku/plains/plains14"
    ] ));
    set_pre_exit_functions(({"east"}),({"go_east"}));
}

int go_east(){
  write("\n%^RED%^As you push the grass apart you stumble into a large hole.\n");
  return 1;
}
