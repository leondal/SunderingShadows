#include "/realms/firedragon/obj/rooms/maze/maze.h"

inherit "/realms/firedragon/obj/rooms/maze/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : MAZEDIR+"1/c/II,I.c",
                "south" : MAZEDIR+"1/c/II,III.c",
                "east"  : MAZEDIR+"1/c/III,II.c",
                "west"  : MAZEDIR+"1/c/I,II.c"
           ]) );
}
