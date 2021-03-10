#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }

void create() {
    set_indoors(0);
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("You are in the Desert");
    set_long(
@MELNMARN
%^BOLD%^You are in a light forest%^RESET%^
This lightly wooded area continues to thin as you move east.
These trees are the remnants of the great forests to the north, 
west, and south.  It seems that an imposing structure once 
stood here, but now only burnt and charred remains are left.
MELNMARN
    );
    set_exits(([
        "west":"/d/shadow/virtual/desert/48,0.desert",
        "east":"/d/shadow/virtual/desert/48,2.desert",
        "north":"/d/shadow/virtual/desert/47,1.desert",
        "south":"/d/shadow/virtual/desert/49,1.desert",
    ]));
    set_smell("default","The smell of sulfur from the fissure fills the air.");
    set_listen("default","You can hear the breeze blowing over the sand, it is so quiet here.");
}
