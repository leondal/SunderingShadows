#include <std.h>
#include "/d/dagger/road/short.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
  set_property("light", 2);
  set_short("Under the Bridge");
  set_property("fill waterskin",1);
//added by ~Circe~ 5/4/11
  set("day long",
@GIL
%^GREEN%^This is a grassy area under the bridge over the river Shelk.
You notice a hut and a fire with a rack of mutton cooking over it.
West of you the river flows deep into the marsh and
East of you the river mouth empties into the Dagger Sea.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is a grassy area under the bridge over the river Shelk.
You see a light from the inside of a hut and the embers of a fire with
the remains of a rack of mutton over it.
West of you is the river leading deeper into the marsh and
East is the mouth of the river emptying into the Dagger Sea.
GIL
);
set_smell("default", "%^YELLOW%^You can smell the mutton.");
set_listen("default", "%^BOLD%^%^BLUE%^You can hear the river splashing against the river rocks.");
  set_items(([
"sea" : "You can see the surf on the beach to the east.",
"marsh" : "It looks deep and evil, monsters will abound there in droves.",
"bridge" : "It's made of white marble and looks very strong and sturdy. Theres metal rungs attached to one side.",
"river" : "The river current appears strong and the water looks cold and clean.",
"hut" : "It's a ramshackle hut thrown together under the bridge.",
   "fire" : "Obviously something's used it to cook with.",
]));

  set_exits(([
"up" : RPATH "bridge",
"hut" : RPATH "hut",
]));
}

