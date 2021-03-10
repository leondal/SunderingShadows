#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
   ::create();
   set_travel(FOOT_PATH);
   set_terrain(BARREN);
   set_property("no teleport",1);
   set_climate("tropical");
   set_property("no lightning",1);
   set_property("light",2);
   set_property("no sticks",1);
   set_short("%^BOLD%^%^RED%^Plane of Fire%^RESET%^");
   set_long(
   "%^RED%^The sky is a dull red color and smoke hangs in the air,"+
   " preventing you from seeing too far in any direction. The air is hot"+
   " and humid, the ground beneath your feet is scorched and baked."+
   " The ridge is wider here than to the southeast, and widens even"+
   " further to the northwest. Right now it is almost ten feet wide."+
   " You can see that there is some sort of structure to the northwest,"+
   " but the haze seems to cling to this area and makes it difficult to"+
   " tell, you never know what might be lurking in the smoke."
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
   ]));
   set_exits(([
   "northeast" : PORTAL+"p23",
   "northwest" : PORTAL+"throne2",
   ]));
}

void reset()
{
   ::reset();
   if(!present("barbed devil 2")) {
      new(MONS+"devil")->move(TO);
      new(MONS+"devil")->move(TO);
   }
}

void init()
{
   ::init();
   if(!present("barbed devil 2")) return;
   present("barbed devil 2")->force_me("block northwest");
   present("barbed devil")->force_me("block northeast");
}

query_weather() { return "%^BOLD%^%^RED%^The haze is thick here.%^RESET%^"; }
