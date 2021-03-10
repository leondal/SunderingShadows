#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 2);
    set_short("Path to the Chateau d'Arcy");
    set_long(
@DARCY
%^BOLD%^Path to the Chateau d'Arcy%^RESET%^
  You appear to be on a well-travelled path between the Royal
Southern Highway and the seat of the Marquis d'Arcy, a local noble
of much influence in the affairs of the Darkwood area.

  The dark trees appear to have been cleared a bit on both sides of
the path, leaving a strip of grass on each side of the path itself.
This path leads north towards the highway and south towards the
chateau.  You are now midway between the chateau and the highway.

  A dark cloud seems to hang over the great house, but its hard to
tell if its the lack of sun, or your senses warning you of great
danger.  Unfortunately, you are still not close enough to figure out
the problem.

DARCY
);
    set_exits(([
        "south" : ROOMDIR+"outside",
        "north" : ROOMDIR+"path1"
    ]));
    set_smell("default","You smell the grasses and weeds along the side of the path.");
    set_listen("default","You hear the sounds of birds and small animals in the forest beyond the path.");
}
