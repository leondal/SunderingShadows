
//slide1.c

#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",1);
	set_property("indoors",1);
       set_short("%^BLUE%^A Dark Stairway");
        set_long("
%^ORANGE%^
You stand at the top of a short stone stairway. At the bottom of the stairs, you can see an area of blackness in the gloom; a doorway. Sand has blown in here from the outside, pushed by the incessant winds. This place has obviously not been disturbed for some time.%^RESET%^
");
   set_listen("default", "The winds howls eerily through the stone.");
       set_exits(([
       "out" : "/d/islands/common/eldebaro/room20",
       "down" : "/d/guilds/fist/hall/hall2.c",
]));
       set_items((["stairs" : "The stairs are steep, narrow, and strewn with sand."
]));
	
}
