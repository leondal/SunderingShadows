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
%^ORANGE%^You are on North Woodbury Lane.
The street runs North and South from here.
A metal pole holds an unlit lantern aloft here.
The high city wall lies to the West of the street.
A Chapel entrance lies to the East.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on North Woodbury Lane.
The street runs North and South from here.
A metal pole here holds a lit lantern aloft and brightens the night.
The high city wall lies to the West of the street.
A Chapel entrance lies to the East.
GIL
);
set_smell("default", "You catch the scent of incense.");
set_listen("default", "You can hear the sounds of praying.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
"chapel" : "This is a place of worship.",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street31",
"south" : "/d/dagger/Daggerdale/streets/street18",
"east" : "/d/dagger/Daggerdale/shops/chapel",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
