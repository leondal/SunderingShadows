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
west, and south.

MELNMARN
    );
    set_exits( ([
      "north" : "/d/shadow/virtual/desert/47,0.desert",
      "south" : "/d/shadow/virtual/desert/49,0.desert",
      "east" : "/d/shadow/virtual/desert/48,1.desert",
    ]));
    set_smell("default", "You can smell the fresh scent of pine to the west.");
    set_listen("default", "You can hear the rustling of trees to the west.");
}
