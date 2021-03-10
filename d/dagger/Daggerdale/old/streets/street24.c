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
The Crossroads lie to the East.
The avenue runs East and West from here.
A metal pole holds an unlit lantern aloft here.
Signs hang outside of the shops to the North and South of here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on West Market Avenue.
The Crossroads lie to the East.
The avenue runs East and West from here.
A metal pole here holds a lit lantern aloft and brightens the night.
Signs hang outside of the shops to the North and South of here.
GIL
);
set_smell("default", "The wind whips the scent of potions by you.");
set_listen("default", "You can hear the sounds of people moaning in pain.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"shops" : "This is were you can buy healing or potions, etc.",
"signs" : "North : Ye Ole Hospital  |  South : Ye Ole Alchemey Shoppe",
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/streets/street23",
"east" : "/d/dagger/Daggerdale/streets/street25",
"north" : "/d/dagger/Daggerdale/shops/hospital",
"south" : "/d/dagger/Daggerdale/shops/alchemistshop",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
