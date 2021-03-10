#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
    set_exits(
        (["north" : "/d/darkwood/room/road20",
          "southwest" : "/d/darkwood/room/road6",
          "southeast" : "/d/tharis/conforest/rooms/path1",
          "east" : "/d/player_houses/amberly/rooms/garden",]));
    new("/d/darkwood/obj/darkwood_sign.c")->move(TO);
}

