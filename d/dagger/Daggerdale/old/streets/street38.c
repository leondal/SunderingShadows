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
%^ORANGE%^Your at the Crossroads of Market Street and Justice Avenue.
The Northern Gates of Daggerdale lie to the North.
The streets run South, East and West from here.
A metal pole holds an unlit lantern aloft here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^Your at the Crossroads of Market Street and Justice Avenue.
The Northern Gate of Daggerdale lies to the North.
The streets run South, East and West from here.
A metal pole here holds a lit lantern aloft and brightens the night.
GIL
);
set_smell("default", "%^RESET%^%^ORANGE%^You catch the scent of the market.%^RESET%^");
set_listen("default", "%^RESET%^%^GREEN%^You can hear the sounds of villagers.%^RESET%^");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
]));

  set_exits(([
"south" : "/d/dagger/Daggerdale/streets/street32",
"north" : "/d/dagger/Daggerdale/gates/Ngate",
"west" : "/d/dagger/Daggerdale/streets/street37",
"east" : "/d/dagger/Daggerdale/streets/street39",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
