
#include "/d/dagger/road/short.h"
inherit ROOM;

void create()
{
  ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
  set_property("light", 2);
    set_property("indoors",1);
  set_short("The Tollbooth.");
  set("day long",
@GIL
%^YELLOW%^This is the inside of the tollbooth.
It's a standard tollbooth used by most governments and manufactured
by the gnomes of Mt. Firblesafehavenhome... Well, the name's too long
to put here, you know gnomes... let's just call it Mt. Firble.
The inside of this tollbooth contains a few cots, a chair, a table
and a chest.
GIL
);
  set("night long",
@GIL
%^YELLOW%^This is the inside of the tollbooth.
It's a standard tollbooth used by most governments and manufactured
by the gnomes of Mt. Firblesafehavenhome... Well, the name's too long
to put here, you know gnomes... let's just call it Mt. Firble.
The inside of this tollbooth contains a few cots, a chair, a table
and a chest.
GIL
);
set_smell("default", "%^YELLOW%^You can smell unwashed clothes and bodies.");
set_listen("default", "%^GREEN%^The sea sounds muffled in here.");

set_items(([
  "chair" : "This is a well worn in chair.",
  "cot" : "This well used cot is used by the guards to sleep of course.",
  "chest" : "This is a small locked chest, it probably contains the tolls the guards collect.",
"table" : "This rickedy table is covered with playing cards and has a few names carved into the top.",
  "tollbooth" : "HEY! We already covered this before.. I'm not gonna try to say that mountain's name again!."
]));

  set_exits(([
"west" : RPATH "road2b",
     ]));
}
void reset() {
  ::reset();
/*
  if(!present("human guard") && !random(2)){
    if(!present("dwarven guard"))
       new(MPATH "private1")->move(this_object());
    new(MPATH "sergeant")->move(this_object());
  }
*/
}
