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
%^ORANGE%^You are on North Market Street.
The street runs North and South from here.
A metal pole holds an unlit lantern aloft here.
Two signs hang outside offices to the East and West of here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on North Market Street.
The street runs North and South from here.
A metal pole here holds a lit lantern aloft and brightens the night.
Two signs hang outside offices to the East and West of here.
GIL
);
set_smell("default", "%^RESET%^%^ORANGE%^You catch the scent of the market.%^RESET%^");
set_listen("default", "%^RESET%^%^GREEN%^You can hear the sounds of villagers.%^RESET%^");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"offices" : "This is where the wheels of Justice grind day and night.",
"signs" : "<--- Ye Ole Jailhouse | Ye Ole Courthouse --->",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street38",
"south" : "/d/dagger/Daggerdale/streets/street28",
"east" : "/d/dagger/Daggerdale/shops/courthouse",
"west" : "/d/dagger/Daggerdale/shops/jailhouse",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
        
