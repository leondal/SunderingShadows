#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
set_property("light", 2);
  set_short("A Crossroads in Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^You are at the crossroads of Woodbury Lane and Market Avenue.
The streets run North, South and East from here.
To the West lie the Western Gates of Daggerdale.
A metal pole holds an unlit lantern aloft here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are at the crossroads of Woodbury Lane and Market Avenue.
The streets run North, South and East from here.
To the West lie the Western Gates of Daggerdale.
A metal pole here holds a lit lantern aloft and brightens the night.
GIL
);
set_smell("default", "You catch the scent of incense.");
set_listen("default", "You can hear the sounds of praying.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street26",
"south" : "/d/dagger/Daggerdale/streets/street13",
"east" : "/d/dagger/Daggerdale/streets/street19",
"west" : "/d/dagger/Daggerdale/gates/Wgate",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
