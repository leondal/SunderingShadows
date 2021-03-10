#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
   ::create();
    set_property("indoors",1);
   set_terrain(NAT_TUNNEL); //needs a valid inside one so picked this -H
   set_travel(FOOT_PATH);
   set_property("no teleport",1);
   set_property("no lightning",1);
   set_climate("tropical");
   set_property("light",2);
   set_property("night light",3);
   set_property("no sticks",1);
   set_name("Plane of Fire");
   set_short("%^BOLD%^%^RED%^Plane of Fire%^RESET%^");
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
}

query_weather() { return "%^BOLD%^%^RED%^It is very hazy.%^RESET%^"; }

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(random(3)) return;
   switch(random(5)) {
      case 0:
         new(MONS+"shadow_demon")->move(TO);
         break;
      case 1:
         new(MONS+"shadow_demon")->move(TO);
         new(MONS+"shadow_demon")->move(TO);
         break;
      case 2:
         new(MONS+"efreeti")->move(TO);
         break;
      case 3:
         new(MONS+"salamander")->move(TO);
         new(MONS+"salamander")->move(TO);
         break;
      case 4:
         new(MONS+"salamander")->move(TO);
         new(MONS+"salamander")->move(TO);
         new(MONS+"salamander")->move(TO);
         break;
   }
}
