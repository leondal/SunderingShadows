#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_light(2);
    set_short("A small path up the side of the mountain.");
    set_long(
      "You are on a small path up the side of the mountain.  You wonder quietly where it could lead."
    );
    set_listen("default", "You hear the wind whistling, or at least you hope that's the wind.");
    set_smell("default", "somthing's burning...");
    set_items( ([
      "rock" : "Yes, that's a rock",
    ]) );
    set_exits( ([
      "northwest" : "/d/dagger/temp/tun5.c",
      "down" : "/d/dagger/temp/tun3.c",
    ]) );
}
