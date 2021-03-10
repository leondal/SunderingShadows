#include <std.h>
#include "../piratedefs.h"

inherit "/std/room";
void create(){
::create();
set_property("light",1);
  set_terrain(ROCKY);
  set_travel(FOOT_PATH);
set_short("Inside the Canyon");
set_long("%^BOLD%^Inside the Canyon%^RESET%^\n"+
"You are deep in the canyon now. "+
"It is cool and dark here. "+
"The canyon walls rise up on both sides, closing you in. "+
"This is an oppressive place. "+
"It is very dark and gloomy here.  The light that reaches the canyon "+
"from the outside is very dim."
"\n"
);

set_smell("default","It smells dank and wet.");
set_listen("default","You hear the sound of crumbling bits "+
            "of rock and dirt falling.");

set_items( ([
"west":"This leads towards the bend and eventually the exit, "+
       "maybe that's not such a bad choice.",
({"canyon walls","walls"}):"The granite canyon walls are cool to the touch, "
"small streams of %^BOLD%^%^CYAN%^water%^RESET%^ trickle from them.",
"water":"This is %^BOLD%^%^CYAN%^clear water%^RESET%^ running out of the rocks.",
"east":"This path leads further into the canyon.",
]) );

set_exits( ([
"east":CAVES+"canyon6",
"west":CAVES+"canyon4"
]) );
}
