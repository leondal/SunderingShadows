#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("indoors",0);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("Inside the Canyon");
   set_short("Inside the Canyon");
   set_long("%^BOLD%^Around the Bend%^RESET%^\n"
"You are deep in the canyon now.  It is cool and dark here.  The canyon walls rise up on both sides, closing "
"you in.  You can see the tip of a tower to the south.  Your only option besides going back the way you "
"came, would seem to be east.\n");
   set_smell("default","It smells dank and wet.");
   set_listen("default","You hear the sound of crumbling bits of rock and dirt falling.");

   set_items(([
     ({"canyon walls","walls"}):"The granite canyon walls are cool to the touch, small streams of "
"%^BOLD%^%^CYAN%^water%^RESET%^ trickle from them.",
     "water":"This is %^BOLD%^%^CYAN%^clear water%^RESET%^ running out of the rocks.",
     "tower":"The black tower seems to be on top of the canyon wall.  You can't see any way to get to it "
"from here."
   ]));

   set_exits( ([
     "east":CAVES"canyon4",
     "northwest":CAVES"canyon2"
   ]));
}
