#include <std.h>

inherit ROOM;

void create(){
   ::create();

   set_short("Path toward a grand stronghold");
   set_long(
@VOID
      %^BOLD%^%^YELLOW%^A cobbled road leading to Castle Tir-Na-Nog%^RESET%^
The road leads up a small hill towards the castle which rests on top. Along both sides of the walkway there are tall bushs, well kept by the look of it, which make it impossible to see anything but the road. You have not traveled so far so that you can not still see the Azha market place behind you though.
VOID
   );
    set_property("light",2);
  set_smell("default","The piny scent of the trees and bushes surrounding you is almost overwhelming.");
    set_listen("default","You can still hear the commotion of the market place.");

   set_exits(([
        "north":"/d/azha/town/south5",
      "south":"/d/guilds/order/hall/trail2"
   ]));
}
