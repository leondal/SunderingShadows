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
%^ORANGE%^You are on South Market Street.
The street runs North and South from here.
A metal pole holds an unlit lantern aloft here.
Two signs hang outside shops to the East and West of here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on South Market Street.
The street runs North and South from here.
A metal pole here holds a lit lantern aloft and brightens the night.
Two signs hang outside shops to the East and West of here.
GIL
);
set_smell("default", "You catch the scent of bread baking.");
set_listen("default", "You can hear the sounds of villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"shops" : "This is where you can buy Equipment and Food.",
"signs" : "<--- Ye Ole General Store | Daggerdale Bank --->",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street15",
"south" : "/d/dagger/Daggerdale/streets/street5",
"east" : "/d/dagger/Daggerdale/shops/bank",
"west" : "/d/dagger/Daggerdale/shops/equipshop",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
        
