// 3,10 - dock that leads to tonovi
#include <std.h>
inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_property("no teleport",1);
    set_light(2);
    set_short("You are on the Dagger Sea.");
    set_long("%^BOLD%^%^WHITE%^You are on the Dagger Sea.%^RESET%^\n"
"You have come up against a rocky cliff line here. There looks like a way between the stony ridges, where you could dock your boat.\n");
        set_exits(([
            "east":"/d/dagger/virtual/sea/10,4.sea",
            "south":"/d/dagger/virtual/sea/11,3.sea",
            "dock":"/d/shadow/virtual/sea/tonovi.dock",
                ]));
        
        set_smell("default","You can smell the fresh sea air.");
        set_listen("default","You hear the lapping of waves against the side of
the boat.");
}