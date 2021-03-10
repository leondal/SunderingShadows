#include <std.h>
#include "../piratedefs.h"
inherit "/std/room";
void create(){
::create();
  set_terrain(ROCKY);
  set_travel(FOOT_PATH);
set_property("light",1);
set_short("Around the bend");
set_long("%^BOLD%^Around the Bend%^RESET%^\n"+
"You are deep in the canyon now. "+
"It is cool and dark here. "+
"The canyon walls rise up on both sides, closing you in. "+
"You can see the tip of a tower to the south. "+
"Your only option besides going back the way you came, "+
"would seem to be east."
"\n"
);
set_items( ([
"northwest":"This leads to the canyon exit.",
({"canyon walls","walls"}):"The granite canyon walls are cool to the touch, "
"small streams of %^BOLD%^%^CYAN%^water%^RESET%^ trickle from them.",
"water":"This is %^BOLD%^%^CYAN%^clear water%^RESET%^ running out of the rocks.",
"east":"This path leads further into the canyon.",
"tower":"The black tower seems to be on top of the canyon wall. "+
"You can't see any way to get to it from here."
]) );
set_exits( ([
"east":CAVES+"canyon4",
"northwest":CAVES+"canyon2"
]) );
}
