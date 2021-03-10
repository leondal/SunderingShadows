#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
//   set_property("no teleport",1);
set_property("light", 2);
  set_short("The Eastern Gates of Daggerdale");
  set("day long",
@GIL
%^ORANGE%^These are the Eastern Gates of Daggerdale Village.
The gates are large and are attached to the granite walls with
big metal hinges.  Above the gateway you can see a porticullis 
raised into the wall.  Large heavy metal chains leading from 
the drawbridge enter holes on each side of the gates here.

A military compound opens to the east, with a great hall 
standing in its center.  Warriors can be seen traveling 
in and out of the great %^RED%^Temple of Tempus%^YELLOW%^.  
GIL
);
  set("night long",
@GIL
%^YELLOW%^These are the Eastern Gates of Daggerdale Village.
The gates are large and are attached to the granite walls with
big metal hinges.  Above the gateway you see a porticullis 
raised into the wall.  Large heavy metal chains leading from 
the drawbridge enter holes on each side of the gates here.

A military compound opens to the east, with a great hall 
standing in its center.  Warriors can be seen traveling 
in and out of the great %^RED%^Temple of Tempus%^YELLOW%^.  
GIL
);
set_smell("default", "The air smells of alchemists potions brewing.");
set_listen("default", "You can hear the sounds of the city bustling inside the walls.");
  set_items(([
"poles" : "They are 10 feet tall, made of finely sculptured metal. Large metal lanterns hang from the top. The metalwork is Dwarven.",
"gates" : "They are large and made of Ironwood, reinforced with Adamanite metal bands.",
"porticullis" : "Its very large and is made of Adamanite metal.",
"chains" : "They are forged from Adamanite metal.",
"walls" : "The walls are 50 foot high and made of polished Granite blocks.",
]));

  set_exits(([
// 	"temple" : "/d/magic/temples/selune",  // temple moved to Dagger Sea Coast Road
	"east" : "/d/dagger/road/p8", //temple moved slightly by Circe
	"west" : "/d/dagger/Daggerdale/streets/street25"
     ]));
}

/*
void reset(){
::reset();
  replaced with the statue lighting it up here
  if(!present("street lamp")) {
   // new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
   new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
  }
  if(!present("statue"))
     new("/d/dagger/Daggerdale/streets/items/objs/selune_statue")->move(TO);
}
*/

/*Old long desc addition:
What was once an entrance to the temple of Selune has been
completely closed off with stone and mortar.  Rumors have it 
that a few of the Selunites nearly started a war with Tonovi 
and the local residents wanted no part of it.  The temple was
ransacked and they were forced to build a new one elsewhere.  
A magnificent statue still stands here, however, having been 
left as a tribute to the lady of the moon.
*/