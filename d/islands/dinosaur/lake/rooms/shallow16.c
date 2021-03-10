#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit LAKETOP;

void create(){
    ::create();
    set_surface(1);
    set_short("In the lake");
    set_long(
      "You are standing waist deep in marshy water of a lake in the middle of this island.  From this clearing you can see the mountains to the north, and the tall tower that sits on top of them.  The water you are standing in is just deep enough to swim around in, though all the plants in the water would make that hard.  The water gets deeper towards the center of the lake."
    );
    set_smell("default", "Ahhh, the smell of freshly walked through swamp water.");
    set_listen("default", "All around you can hear the calls of many different types of animals.");
    set_items( ([
      "tower" : "The tower on the cliff, tall and menacing, seems to be calling your name.",
      "water" : "The water all around you is dark with dirt and other material.",
      "cliffs" : "Even from here you can see a way to climb the cliffs far to the west of the tower.  There even seem to be some caves on the cliffs.",
      "caves" : "There are several caves on the face of the cliff.  You wonder where they could lead.",
    ]) );
    set_exits( ([
      "north" : "/d/islands/dinosaur/lake/rooms/shallow15.c",
      "east" : "/d/islands/dinosaur/lake/rooms/deep1u.c",
      "south" : "/d/islands/dinosaur/lake/rooms/shallow1.c",
    ]) );
}
