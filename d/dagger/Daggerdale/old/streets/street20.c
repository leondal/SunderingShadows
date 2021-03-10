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
%^ORANGE%^You are on West Market Avenue.
The Market square lies to the East.
The avenue runs East and West from here.
A metal pole holds an unlit lantern aloft here.
The trainer's arena lies to the South.
There is the backside of a building to the North.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on West Market Avenue.
The Market square lies to the East.
The avenue runs East and West from here.
The trainer's arena lies to the South.
A metal pole here holds a lit lantern aloft and brightens the night.
There is the backside of a building to the North.
GIL
);
set_smell("default", "The wind whips the scent of ale by you.");
set_listen("default", "You can hear the sounds of a fight.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/streets/street19",
"east" : "/d/dagger/Daggerdale/streets/street21",
"south" : "/d/dagger/Daggerdale/shops/trainer",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
