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
%^ORANGE%^You are South Thorn Lane.
The street runs North and South from here.
A metal pole holds an unlit lantern aloft here.
The high city wall lies to the East of the street.
A sign hangs outside a shop to the West of here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on South Thorn Lane.
The street runs North and South from here.
A metal pole here holds a lit lantern aloft and brightens the night.
The high city wall lies to the East of the street.
A sign hangs outside a shop to the West of here.
GIL
);
set_smell("default", "You catch the scent of magic in the air.");
set_listen("default", "You can hear the sounds of villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
"shop" : "This is where you can buy magic accessories.",
"sign" : "<--- Ye Ole Majick Shoppe",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street17",
"south" : "/d/dagger/Daggerdale/streets/street9",
"west" : "/d/dagger/Daggerdale/shops/magicshop",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
