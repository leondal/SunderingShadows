#include <std.h>
#include "../ruins.h"
inherit PLANE;

void create()
{
   ::create();
   set_long(
   "%^RED%^You're standing in the midst of a %^YELLOW%^yellowish cloud%^RESET%^%^RED%^"+
   " that hangs motionlessly in this humid place. The cloud has a"+
   " sulfiric smell to it, and it blocks your vision of the surrounding"+
   " area. You think the ridge might continue to the east and southeast,"+
   " but for all you know it could drop off completely."
   );
   set_listen("default","%^YELLOW%^The crackle of flames is slightly muffled in this cloud.");
   set_items(([
   ({"ground","floor"}) : "The ground beneath your feet is a burnt"+
   " red, and has been baked, it is brittle and cracks beneath your"+
   " feet. It is also rather warm and you can see a bit of steam rising"+
   " from it in places. Walking around here barefoot would not be a"+
   " good idea.",
   "cliff" : "The cliff you are standing on is quite tall and the lower"+
   " portion seems to be on fire. There's no way to climb down it, and"+
   " even if there were, the only thing at the bottom is a river of"+
   " lava.",
   "fire" : "Fire burns the lower parts of the cliffs, releasing smoke"+
   " into the air.",
   "smoke" : "Smoke hangs in the air constantly, creating a haze that"+
   " prevents you from seeing too far in any direction.",
   ({"river","lava","molten lava"}) : "Far below a river of molten lava"+
   " flows around the cliffs.",
   ({"cloud","yellow cloud"}) : "%^YELLOW%^There is a yellow cloud that"+
   " simply hangs motionless in the air, completely surrounding you and"+
   " blocking your vision.",
   ]));
   set_property("no peer",1);
   set_peer_message("The yellow cloud prevents you from seeing anything.");
   set_exits(([
   "east" : PORTAL+"p14",
   "southwest" : PORTAL+"p12",
   ]));
}

query_weather() { return "%^YELLOW%^The room is filled with yellow haze.%^RESET%^"; }