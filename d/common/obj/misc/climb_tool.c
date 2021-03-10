//updated with new desc by Circe 6/12/04
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"climbing tool","climbing tools","tools",
       "mountaineer equipment","climb_tool"}) );
    set_name("climbing tools");
    set_short("Climbing tools");
    set_weight(3);
    set_long(
@LONG
This set of climbing tools contains ordinary items an explorer 
might need to climb a sheer rock face or scale a wall.  There is 
a solid leather harness with adjustable straps to fit any size, 
pitons, hooks, and boot tips to aid in climbing surfaces with 
cracks or that give a bit.  There are also gloves to protect 
the climbers hands.  Without these, many people find climbing 
in certain places impossible.
LONG
);
    set_value(30);
}

