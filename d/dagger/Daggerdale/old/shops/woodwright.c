// /d/dagger/Daggerdale/shops/woodwright.c

#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_property("indoors",1);
set_short("Woodwright's");
  set("long",
@SIA
%^ORANGE%^You are standing in the waiting room, a half wall divides the room from the work area. The craft-master is directing two others, a junior apprentice and a young journeyman in oil finishing.  There is a three-drawered cabinet on display.
SIA
);
set_smell("default", "You smell sawdust and varnish.");
set_listen("default", "You hear the sound of a saw cutting wood.");
  set_items(([
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "Spans the entire length of the room, with a half door to the right.",
"room" : "Light colored wood paneling adorns the walls.",
"cabinet" : "Made from oak, the finish is superb, as are the proportions. The grain on the side panels is angled, not much, but enough to detract.",
]));

  set_exits(([
"out" : "/d/dagger/Daggerdale/streets/street16",
"back" : "/d/dagger/Daggerdale/shops/wood_back",
     ]));
}
