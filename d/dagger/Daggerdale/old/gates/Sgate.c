#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
//   set_property("no teleport",1);
set_property("light", 2);
  set_short("The Southern Gates of Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^These are the Southern Gates of Daggerdale Village.
The gate are large and are attached to the granite walls with
big metal hinges.
Above the gateway you can see a porticullis raised into the wall.
Large heavy metal chains leading from the drawbridge enter holes
on each side of the gates here.
A metal pole holds an unlit lantern.
GIL
);
  set("night long",
@GIL
%^YELLOW%^These are the Southern Gates of Daggerdale Village.
The gates are large and are attached to the granite walls with
big metal hinges.
Above the gateway you see a porticullis raised into the wall.
Large heavy metal chains leading from the drawbridge enter holes
on each side of the gates here.
A metal pole hold a lit lantern that lights up the area brightly.
GIL
);
set_smell("default", "You can smell bread baking.");
set_listen("default", "You can hear the sounds of the city bustling inside the walls.");
  set_items(([
"poles" : "They are 10 feet tall, made of finely sculptured metal. Large metal lanterns hang from the top. The metalwork is Dwarven.",
"gates" : "They are large and made of Ironwood, reinforced with Adamanite metal bands.",
"porticullis" : "Its very large and is made of Adamanite metal.",
"chains" : "They are forged from Adamanite metal.",
"walls" : "The walls are 50 foot high and made of polished Granite blocks.",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street5",
// "south" : "/d/dagger/northroad/Nroad19",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole"))
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
  //if (!present("lantern pole 2"))
//new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
