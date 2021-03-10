#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(BARREN);
   set_travel(FOOT_PATH);
   set_property("no teleport",1);
   set_climate("tropical");
   set_property("no lightning",1);
   set_property("light",2);
   set_property("no sticks",1);
   set_short("%^BOLD%^%^RED%^Plane of Fire%^RESET%^");
   set_long(
   "%^RED%^A reddish-orange haze is thick in the air here, preventing"+
   " anyone from seeing very far ahead. The ridge you are standing on"+
   " is almost ten feet wide here, and seems to widen further to the"+
   " northeast. You can see some sort of structure, but it is obscured"+
   " by more haze and smoke than normal. There is a slight decline to"+
   " the southeast and the path there seems to become more narrow."
   );
   set_smell("default","Smoke and noxious vapors fill the air.");
   set_listen("default","%^YELLOW%^The crackle of flames seems duller in the thick haze.");
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
   "haze" : "%^ORANGE%^There is a reddish-orange haze that hangs in"+
   " this area, preventing anyone from seeing too far ahead.",
   ]));
   set_exits(([
   "northeast" : PORTAL+"throne1",
   "southeast" : PORTAL+"p8",
   ]));
}

void reset()
{
   ::reset();
   if(!present("barbed devil 2")) {
      new(MONS+"devil")->move(TO);
      present("barbed devil")->force_me("block southeast");
      new(MONS+"devil")->move(TO);
      present("barbed devil")->force_me("block northeast");
   }
}

void init()
{
   ::init();
   if(!present("barbed devil 2")) return;
   present("barbed devil 2")->force_me("block southeast");
   present("barbed devil")->force_me("block northeast");
}

query_weather() { return "%^BOLD%^%^RED%^The haze is thick here.%^RESET%^"; }
