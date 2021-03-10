#include <std.h>

inherit ROOM;

void create(){
   ::create();

   set_short("Path toward a grand stronghold");
   set_long(
@VOID
      %^BOLD%^%^YELLOW%^A cobbled road leading to Castle Tir-Na-Nog%^RESET%^
The road has lead you up a small hill towards the gates of this mighty stronghold. Along both sides of the walkway tall bushes rise up, making it impossible to see what lies on the other side of them. You have nearly reached the castle, its gates are just ahead of you.
VOID
   );
    set_property("light",2);
  set_smell("default","The piny scent of the trees and bushes surrounding you is almost overwhelming.");
    set_listen("default","You hear birds singing from within the bushes.");

   set_exits(([
    "north":"/d/guilds/order/hall/trail2.c",
    "south":"/d/guilds/order/hall/enterance"
   ]));
}
