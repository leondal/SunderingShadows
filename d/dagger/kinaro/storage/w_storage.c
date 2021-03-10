#include "std.h"
inherit "/d/common/inherit/wpn_storage.c";

void create() {
    ::create();
    set_property("no teleport", 1);
    set("short", "Weapon storage room for Kinaro.");
    set("long", "Only supplies and such here.\n");
    set_exits((["up" : "/d/dagger/kinaro/weap"]));
}

void reset() {
    ::reset();
}

