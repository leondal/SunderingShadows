#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
set_property("light", 2);
  set_short("A Street in Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^You are on North Thorn Lane.
The street runs North and South from here.
A metal pole holds an unlit lantern aloft here.
The high city wall lies to the East of the street.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on North Thorn Lane.
The street runs North and South from here.
A metal pole here holds a lit lantern aloft and brightens the night.
The high city wall lies to the East of the street.
GIL
);
set_smell("default", "You catch the scent of potions.");
set_listen("default", "You can hear the sounds of people moaning.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
/*
"shop" : "This is where you can buy or sell strange things.",
"sign" : "<--- Ye Ole Pawn Shoppe ",
*/
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street42",
"south" : "/d/dagger/Daggerdale/streets/street30",
/*
"west" : "/d/dagger/Daggerdale/shops/pawn",
*/
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
