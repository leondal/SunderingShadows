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
   " a round dias made of bones with a throne sitting on top of it. The"+
   " throne appears to be cast from lava that has cooled and hardened,"+
   " it is a solid and continuous black stone object that reaches seven"+
   " feet into the air. There seems to be an inordinate amount of haze"+
   " and smoke that clings to the edges of the cliff, protecting this"+
   " room from outside view."
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
   "dias" : "There is a large dias that is created from the"+
   " %^BOLD%^bones%^RESET%^ of various creatures. It is set in a"+
   " circular pattern but is not totally round.",
   "bones" : "%^BOLD%^The bones stand out as stark white when compared"+
   " with the black throne that sits atop them. There are various types"+
   " of bones, some human, others obviously animal, and some it is"+
   " hard to tell what they came from. The bones are mostly lashed"+
   " together and the outside and top of the dias is solid, but the"+
   " inside seems to have been left hollow.",
   "throne" : "The large, black throne dominates the center of the"+
   " room. It sits atop a dias of %^BOLD%^bones%^RESET%^ that are a"+
   " stark white contrast to the throne's lack luster black. The throne"+
   " almost appears to have been cast from molten lava, as it is one"+
   " solid piece of cooled lava and doesn't appear to have been crafted"+
   " in any way. You can see many rough patches from here, it would not"+
   " be pleasant for a thinly skinned creature to sit on. The back of"+
   " the throne is over seven feet tall, so whatever uses it must be"+
   " very big indeed.",
   ]));
   set_search("bones",(:TO,"search_bones":));
   set_property("no peer",1);
   set_peer_message("The smoke and haze prevents you from seeing anything.");
   set_exits(([
   "southwest" : PORTAL+"p9",
   ]));
}

int search_bones()
{
   if(FOUND == 1) {
      tell_object(TP,"%^BOLD%^You search through the bones but fail"+
      " to find anything useful.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" searches through the bones but"+
      " doesn't seem to find anything.",TP);
      return 1;
   }
   if(!random(2)) {
      tell_object(TP,"%^BOLD%^You search through the large pile of"+
      " bones but fail to find anything before giving up.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" searches through the large"+
      " pile of bones but eventually grows weary and gives up without"+
      " finding anything.",TP);
      return 1;
   }
   tell_object(TP,"%^BOLD%^You tirelessly search through the bones and"+
   " eventually find something within the dias.");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" searches through the bones and"+
   " seems to find something.",TP);
   switch(random(2)) {
      case 0:
         new(OBJ+"ruby_circlet")->move(TO);
         tell_object(TP,"%^BOLD%^You pull forth a %^RED%^ruby"+
         " circlet%^WHITE%^ from the dias of bones.");
         break;
      case 1:
         new(OBJ+"dust_pouch")->move(TO);
         tell_object(TP,"%^BOLD%^You pull forth a %^ORANGE%^pouch"+
         " of dust%^WHITE%^ from the dias of bones.");
         break;
   }
   tell_room(ETP,"%^BOLD%^"+TPQCN+" pulls something out from the bone"+
   " dias and sets it on the ground.",TP);
   FOUND = 1;
}

void reset() // turning up frequency of the demons so people don't have to cycle forever -Ares
{
   ::reset();
   if(present("greater demon")) return;
   //if(objectp(find_object("/d/antioch/ruins/mons/demon.c"))) return;
   //if(find_object("/d/antioch/ruins/portal/throne2.c") && find_object("/d/antioch/ruins/portal/throne3.c")) {
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
      obj->force_me("block southwest");
      obj->force_me("cackle");
      obj->force_me("say Pathetic mortal, I shall enjoy killing you!");
   }
}

query_weather() { return "%^RESET%^Smoke surrounds the edges of the room."; }
