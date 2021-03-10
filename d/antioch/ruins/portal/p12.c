#include <std.h>
#include "../ruins.h"
inherit PLANE;

void create()
{
   ::create();
   set_long(
   "%^RED%^You're standing on the edge of a %^YELLOW%^yellowish cloud%^RESET%^%^RED%^"+
   " that hangs motionlessly in this humid place. To the south it is"+
   " clearer, but who knows what lies to the northeast, the cloud is"+
   " much thicker there and the ridge seems to become even more narrow."
   );
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
   " simply hangs motionless in the air in this section. You are on the"+
   " very edge of it right now, but it gets thicker to the northeast.",
   ]));
   set_exits(([
   "northeast" : PORTAL+"p13",
   "south" : PORTAL+"p11",
   ]));
}
