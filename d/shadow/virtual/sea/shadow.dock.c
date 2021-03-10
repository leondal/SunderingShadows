#include <std.h>

inherit "/d/shadow/city/room/dock2";
inherit "/d/shadow/virtual/sea/dock";


int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
    ::create();
    set_exits(([
               "north":"/d/shadow/city/room/dock1"
               ]));
    find_object_or_load("/d/shadow/virtual/sea/obj/ferryboat")->move(TO);
}

