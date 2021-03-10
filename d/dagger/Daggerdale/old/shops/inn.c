#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_property("indoors",1);
set_short("Druid's Inn");
  set("long",
@SIA
%^CYAN%^You are standing in a parlour-like area of the inn, left of
a smooth-plained wooden counter. Right is a wide wooden stairway 
with a brownish-carpeted runner covering most of the stairs themselves.
Ahead is an archway which leads to a dining room. To the left is a
another archway that leads to a small room.
SIA
);
set_smell("default", "You smell the faint aroma of lamb stew.");
set_listen("default", "You hear the sound of many voices and the clinking of glass.");
  set_items(([
"counter" : "It is made from red-oak without any ornamentation, the wood is protected by a coat of dull varnish",
"stairs" : "They are polished smooth and engraved with vines and leaves up the banister.",
"room" : "Dark wood paneling adorns the walls.",
"archway" : "Vines and leaves are superbly carved around the arch.",
]));

  set_exits(([
"out" : "/d/dagger/Daggerdale/streets/street29",
"east" : "/d/dagger/Daggerdale/shops/inn_dining",
/*
"north" : "/d/dagger/Daggerdale/shops/inn_bar",
*/
"up" : "/d/dagger/Daggerdale/shops/inn_hall1",
     ]));
}
