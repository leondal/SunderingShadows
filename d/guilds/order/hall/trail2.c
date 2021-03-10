#include <std.h>

inherit ROOM;

void create(){
   ::create();

   set_short("Path toward a grand stronghold");
   set_long(
@VOID
      %^BOLD%^%^YELLOW%^A cobbled road leading to Castle Tir-Na-Nog%^RESET%^
The road leads up a small hill towards the castle which rests on top. Along both sides of the walkway there are tall bushes, well kept by the look of it, though they make it impossible to see anything but the path your on. You are far enough up the hill now so that you can look down upon the entire market place of Azha, and the chaos it contains.
VOID
   );
    set_property("light",2);
  set_smell("default","The piny scent of the trees and bushes surrounding you is almost overwhelming.");
    set_listen("default","You hear birds singing from within the bushes.");

   set_exits(([
    "north":"/d/guilds/order/hall/trail1.c",
    "south":"/d/guilds/order/hall/trail3.c"
   ]));
}
