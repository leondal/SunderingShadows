#include <std.h>
#include "../ruins.h"
inherit ROOM;

int FOUND;

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
   "%^RED%^%^BOLD%^A Throne Room%^RESET%^\n"+
   "%^RED%^The ridge widens and comes to an end here. In the center is"+
   " a large throne that seems to rise up from the cliff itself, made"+
   " of the same scorched red dirt that comprises the cliff. The back"+
   " of the throne has flames springing up from behind it that arc in"+
   " beautiful displays of light. The front of the throne is inlaid"+
   " with some precious and semi-precious stones and a few gruesome"+
   " trophies from recent kills. The smoke is thick around the edges"+
   " but doesn't intrude into the center, as though even it is afraid"+
  " of whatever might occupy the large throne."
   );
   set_smell("default","Smoke and noxious vapors fill the air.");
   set_listen("default","%^YELLOW%^The flames crackle behind the throne.");
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
   "throne" : "The throne rises up from the center of the cliff, an"+
   " impressive sight that reaches over seven feet into the air. It"+
   " is made of the same scorched and red dirt that the cliffs are"+
   " made of, but it appears solid and sturdy enough. There are"+
   " several torches behind the throne that give it a backdrop of"+
   " beautifully colored flames. The throne itself is inset with a"+
   " few rubies and diamonds, as well as other large semi-precious"+
   " stones. There are also spots with eyeballs, tongues, and other"+
   " things from recent kills. It is an impressively gruesome effect.",
   ]));
   set_search("throne",(:TO,"search_throne":));
   set_property("no peer",1);
   set_peer_message("The smoke and haze prevents you from seeing anything.");
   set_exits(([
   "southeast" : PORTAL+"p24",
   ]));
}

int search_throne()
{
   if(FOUND == 1) {
      tell_object(TP,"%^RED%^You search the throne but fail to find"+
      " anything useful.");
      tell_room(ETP,"%^RED%^"+TPQCN+" searches the throne but doesn't"+
      " seem to find anything.",TP);
      return 1;
   }
   if(!random(2)) {
      tell_object(TP,"%^RED%^You search the throne carefully but"+
      " can't seem to find anything other than some wet body parts.");
      tell_room(ETP,"%^RED%^"+TPQCN+" searches the throne but doesn't"+
      " seem to find anything other than the gruesome body parts.",TP);
      return 1;
   }
   tell_object(TP,"%^RED%^You carefully search every part of the"+
   " throne and eventually find something.");
   tell_room(ETP,"%^RED%^"+TPQCN+" searches the throne carefully and"+
   " seems to find something.",TP);
   switch(random(2)) {
      case 0:
         new(OBJ+"feathers")->move(TO);
         tell_object(TP,"%^RED%^You discover a handful of"+
         " %^BOLD%^phoenix feathers%^RESET%^%^RED%^ on the edges"+
         " near the flames.");
         break;
      case 1:
         new(OBJ+"glyph")->move(TO);
         tell_object(TP,"%^RED%^You find that one of the stones in the"+
         " throne is loose and you pry it out.");
         break;
   }
   tell_room(ETP,"%^BOLD%^"+TPQCN+" removes something from the throne"+
   " and places it on the ground.",TP);
   FOUND = 1;
}

void reset() // turning up frequency of the demons so people don't have to cycle forever -Ares
{
   ::reset();
   if(present("greater demon")) return;
   //if(objectp(find_object("/d/antioch/ruins/mons/demon.c"))) return;
   //if(find_object("/d/antioch/ruins/portal/throne1.c") && find_object("/d/antioch/ruins/portal/throne3.c")) {
   //   find_object_or_load("/d/antioch/ruins/mons/demon.c")->move(TO);
   //}
   // allowing the escape items to actually respawn and not lock people in here! N, 8/20
   if(FOUND) FOUND = 0;
   if(random(5)) 
   {
      new("/d/antioch/ruins/mons/demon.c")->move(TO);
   }
}

void init()
{
   object obj;

   if(!objectp(TP)) { return; }
   if(TP->query_true_invis()) { return; }

   ::init();
   if(present("greater demon")) {
      obj = present("greater demon");
      obj->force_me("block southeast");
      obj->force_me("cackle");
      obj->force_me("say Pathetic mortal, I shall enjoy killing you!");
   }
}

query_weather() { return "%^RESET%^Smoke surrounds the edges of the room.";  }
