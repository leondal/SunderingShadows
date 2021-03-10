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
%^ORANGE%^You are in the Southwest corner of the Market Square.
The street runs North and East from here.
A metal pole holds an unlit lantern aloft here.
Many carts line the square here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are in the Southwest corner of the Market Square.
The street runs North and East from here.
A metal pole here holds a lit lantern aloft and brightens the night.
Many carts line the square here.
GIL
);
   set_smell("default","You catch the scent of the market.");
   set_listen("default","You can hear the sounds of the villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
"carts" : "They sell many items not found in the shops.",
"square" : "This is the central square of Daggerdale, many people sell their wares here.",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street21",
"east" : "/d/dagger/Daggerdale/streets/street15",
/*
"west" : "/d/dagger/Daggerdale/shops/smithy",
*/
     ]));
}
void reset(){
   ::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
   if(query_night() != 1 && !present("jerat")) {
      new("/d/dagger/Daggerdale/shops/npcs/jerat")->move(TO);
   }
}
