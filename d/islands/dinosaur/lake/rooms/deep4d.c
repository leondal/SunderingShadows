#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit LAKETOP;

void create(){
    ::create();
    set_light(1);
    set_short("Under the lake.");
    set_long(
      "You are under the water from the lake.  You can easily see your way to the top of the lake from here in the light.  In the gloom of the dirty water, you can see little else."
    );
    set_smell("default", "Don't sniff too deep, you don't want water in your nose!");
    set_listen("default", "You hear the water in your ears.");
    set_items( ([
      "light" : "The light upwards is probably the sky.",
    ]) );
    set_pre_exit_functions( ({"west"}), ({"climb_out"}) );
    set_exits( ([
      "north" : "/d/islands/dinosaur/lake/rooms/deep7d.c",
      "east" : "/d/islands/dinosaur/lake/rooms/deep5d.c",
      "south" : "/d/islands/dinosaur/lake/rooms/deep1d.c",
      "up" : "/d/islands/dinosaur/lake/rooms/deep4u.c",
      "west" : "/d/islands/dinosaur/lake/rooms/shallow15.c",
    ]) );
}
