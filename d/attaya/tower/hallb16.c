
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Grand dining room");
        set_long("
    You are standing in a large open part of the room.  To the north are several large tables and countless chairs.  Remarkable paintings and gold decorations line the walls, and the ceiling seems to have been hand carved or molded and is incredibly detailed.  Chandeliers similar to the ones in the library hang on gold chains far above.
    A stage and presentation area lie on a raised platform to the west.  You could not see it from the arch to the north.  Burgundy curtains hang open on either side.
    The floor is an array of variously shaped and colored tiles that probably make up a picture if viewed from above.  
    Looking up, you can see four balconies that open into this room.
");
       set_exits(([
       "stage" : "/d/attaya/tower/hallb17",
       "north" : "/d/attaya/tower/hallb15",
]));
       set_items(([
    "ceiling" : "The ceiling is an unbelievable image formed from plaster, and covered in gold and brass trim with colored glass accents.  You could spend an hour staring into it and not take in half the details!",
    "stage" : "The stage vanishes into the darkness to the west.  It is on a raised platform in the west wall.",
    "tables" : "Several long oak dining tables covered with white tablecloths fill the northern part of this vast room.",
    "chairs" : "They are polished mahogany chairs.",
    "chandeliers" : "Chandeliers of gold and crystal hang above you.  The detail is very fine.",
    "balconies" : "Four balconies peer into this room.  Two set into the east wall, two into the west wall.  You cannot see visible access to them.",
    "paintings" : "Beautiful paintings depict scenes of wealthy and prosperous people dancing beneath a sky of glass stars and dimly lit candles.",
    "floor" : "Thousands of tiles, each set within a gold frame, spread out across the floor.  From one of the balconies, you could probably make out the pattern.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}

void reset(){
        ::reset();
    if(!present("poltergeist")) {
       new("d/attaya/mon/poltergeist")->move(this_object());
       new("d/attaya/mon/poltergeist")->move(this_object());
       new("d/attaya/mon/poltergeist")->move(this_object());
    }
}
