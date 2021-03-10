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
The Crossroads lie to the West.
The avenue runs East and West from here.
A metal pole holds an unlit lantern aloft here.
A Church entrance lies to the North.
A sign hangs outside of the shop to the South of here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on West Market Avenue.
The Crossroads lie to the West.
The avenue runs East and West from here.
A metal pole here holds a lit lantern aloft and brightens the night.
A Church entrance lies to the North.
A sign hangs outside of the shop to the South of here.
GIL
);
set_smell("default", "The wind whips the scent of incense by you.");
set_listen("default", "You can hear the sounds of praying.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"shop" : "This is where you can buy weapons.",
"sign" : "South : Ye Ole Weapon Shoppe",
"chapel" : "This is a place of worship",
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/streets/street18",
"east" : "/d/dagger/Daggerdale/streets/street20",
"north" : "/d/dagger/Daggerdale/shops/chapel",
"south" : "/d/dagger/Daggerdale/shops/weaponshop",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
