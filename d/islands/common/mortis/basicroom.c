//slide1.c

#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",0);
       set_short("short");
        set_long("
");
   set_listen("default", "something!");
       set_exits(([
       "north" : "/d/islands/common/vv/bb",
       "south" : "/d/islands/common/vv/bb",
       "west" : "/d/islands/common/vv/bb",
       "east" : "/d/islands/common/vv/bb",
]));
       set_items(([
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/thing.c", "/d/islands/common/mon/thing.c", "/d/islands/common/mon/thing.c", "/d/islands/common/mon/thing.c", "/d/islands/common/mon/thing.c"}),15,1);
}
