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
%^ORANGE%^Your at the Crossroads of Market Street and Bakers Avenue.
The Southern Gates of Daggerdale lie to the South.
The street runs North, East and West from here.
A metal pole holds an unlit lantern aloft here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^Your at the Crossroads of Market Street and Bakers Avenue.
The Southern Gates of Daggerdale lie to the South.
The street runs North, East and West from here.
A metal pole here holds a lit lantern aloft and brightens the night.
GIL
);
set_smell("default", "You can smell baking bread.");
set_listen("default", "You can hear the sounds of villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street11",
"south" : "/d/dagger/Daggerdale/gates/Sgate",
"west" : "/d/dagger/Daggerdale/streets/street4",
"east" : "/d/dagger/Daggerdale/streets/street6",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
