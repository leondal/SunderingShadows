#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_property("indoors",1);
set_short("Hallway");
  set("long",
@SIA
%^CYAN%^
The hallway is shrouded in shadows due to the dim lighting.
Green carpet adorns the floor and is worn in places by
many feet trampling along the hall over the years.
SIA
);
set_smell("default", "You smell stale beer and the faint aroma of lamb stew.");
set_listen("default", "You hear the old building creaking.");
  set_items(([
"room" : "Dark wood paneling adorns the walls.",
]));

  set_exits(([
"down" : "/d/dagger/Daggerdale/shops/inn",
"north" : "/d/dagger/Daggerdale/shops/inn_room1",
"east" : "/d/dagger/Daggerdale/shops/inn_hall2",
     ]));
}
