#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
set_property("light", 2);
  set_short("A Street in Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^You are on East Market Avenue.
The Market square lies to the West.
The street runs East and West from here.
A metal pole holds an unlit lantern aloft here.
The backside of buildings are to the North and South.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on West Market Avenue.
The Market square lies to the West.
The street runs East and West from here.
A metal pole here holds a lit lantern aloft and brightens the night.
The backside of buildings are to the North and South.
GIL
);
set_smell("default", "The wind whips the scent of food by you.");
set_listen("default", "You can hear the sounds of a Bard singing.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/streets/street22",
"east" : "/d/dagger/Daggerdale/streets/street24",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
