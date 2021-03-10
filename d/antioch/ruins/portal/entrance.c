#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(BARREN);
   set_travel(FOOT_PATH);
   set_property("no teleport",1);
   set_property("no lightning",1);
   set_climate("tropical");
   set_property("light",2);
   set_property("no sticks",1);
   set_short("%^BOLD%^%^RED%^Plane of Fire%^RESET%^");
   set_long(
   "%^RED%^You are obviously on another plane of some sort, though none you've"+
   " ever heard of. This appears to be an area trapped between two"+
   " planes, actually. The sky is a dull red color and has no sun, moon,"+
   " or stars. Smoke hangs eternally in the air. Where ever it is, it is"+
   " certainly unpleasant. The air is hot and humid, the ground beneath"+
   " your feet is scorched and baked. You're actually standing on the"+
   " edge of a tall cliff that seems to be on fire, and far below there"+
   " is a river of molten lava. Directly in front of you is a small"+
   " plateau. You can see tendrils of the cliff branch out from there in"+
   " three directions, but the paths are lost in the haze."
   );
   set_smell("default","Smoke and noxious vapors fill the air.");
   set_listen("default","%^YELLOW%^The crackle of flames seems to be a constant thing around here.");
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
   "plateau" : "Just ahead is a plateau, it branches off in three"+
   " different directions. There's no sign of the portal that you"+
   " stepped through to get here.",
   ]));
   set_exits(([
   "north" : PORTAL+"p1",
   "northwest" : PORTAL+"p15",
   "northeast" : PORTAL+"p25",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
}

query_weather() { return "%^BOLD%^%^RED%^It is very hazy.%^RESET%^"; }
