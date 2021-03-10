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
   " a throne that stands over seven feet tall that appears to be made"+
   " of solid bronze. There are a few gem-stones set into the throne,"+
   " most of them are yellow or red in color and are very big but not"+
   " worth very much. A few statues have been placed around the edges"+
   " of the room, some in bronze, marble, and a few smaller ones in"+
   " ivory. They seem to be holding the smoke at bay, for it surrounds"+
   " the outside of the room but never comes into the center."
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
   "throne" : "The throne cast from bronze and stands over seven feet"+
   " tall. Large semi-precious stones decorate the throne, mostly"+
   " garnets, topaz, sunstones, and citrine. They give the throne a"+
   " regal stature, despite the fact that it looks so uncomfortable"+
   " you can't imagine anyone ever wanting to use it.",
   "statues" : "There are several statues that decorate the edges of"+
   " the room. There are two large %^ORANGE%^bronze statues%^RESET%^,"+
   " two smaller statues in %^RED%^red marble%^RESET%^, and three"+
   " %^BOLD%^ivory statues%^RESET%^ that are only a foot or so tall"+
   " but exquisitely detailed.",
   "bronze statues" : "%^ORANGE%^Two life-sized bronze statues stand on"+
   " the same horizontal line as the throne, one on either edge of the"+
   " cliff. One is a warrior that stands fiercely with a spear in his"+
   " hands and a menacing expression beneath his helm. He is wearing"+
   " body armor that is countoured to show his muscles and is a daunting"+
   " image. The one to the right of the stone appears to be a mage"+
   " and is dressed in long flowing robes that appear to have been blown"+
   " by the wind. His hair trails backwards behind him and he holds a"+
   " %^YELLOW%^golden rod%^RESET%^%^ORANGE%^ in one hand.%^RESET%^",
   ({"marble statues","red marble statues"}) : "%^RED%^The marble"+
   " statues are at the very front entrance of the room and they are"+
   " approximately five feet in height. They are almost identical"+
   " images of succubi, except for the fact they are slightly sideways"+
   " and seem to be inviting you in the room, so opposite hands are"+
   " raised and their tails trail to the west and east, away from the"+
   " path. They have slight smiles on their faces, showing rows of"+
   " wickedly sharp teeth. Their wings are slightly spread and they"+
   " are leaning forward a little ways. They are scantily clad in tight"+
   " dresses that leave little to the imagination.%^RESET%^",
   "ivory statues" : "%^BOLD%^The ivory statues are only a foot tall"+
   " but they are wonderfully detailed. There are two across from"+
   " eachother on either side of the room, inbetween the marble and"+
   " bronze statues. One is at the very back of the room, almost hidden"+
   " by the throne. The one on the left side is in the form of a"+
   " crouching tiger that seems almost ready to spring up at you."+
   " Its ears are flattened back and its teeth are bared as though"+
   " hissing at something. Its belly low to the ground and the muscles"+
   " bunched and ready in its legs. The one on the right is that of a"+
   " panther slowly walking down a large tree branch. Even the leaves"+
   " and bark are detailed in the statue. The panther has its right"+
   " forepaw off the ground with its tail extended for balance as"+
   " it carefully navigates the branch. The statue at the back of the"+
   " room is that of a large oriental dragon that extends its legs and"+
   " tail for some ways. Each scale has been carefully carved in precise"+
   " detail. Its eyes are %^RED%^small rubies%^WHITE%^ that seem to"+
   " stare at you no matter where you move to.",
   ]));
   set_search("statues","You try and search all the statues at once"+
   " but probably need to devote attention to just a few at a time.");
   set_search("bronze statues",(:TO,"search_statue":));
   set_property("no peer",1);
   set_peer_message("The smoke and haze prevents you from seeing anything.");
   set_exits(([
   "southwest" : PORTAL+"p34",
   ]));
}

int search_statue()
{
   if(FOUND == 1) {
      tell_object(TP,"%^ORANGE%^You search the bronze statues carefully"+
      " but discover only that the crafter made them well endowed.");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches the bronze statues"+
      " carefully but finds nothing.",TP);
      return 1;
   }
   if(!random(2)) {
      tell_object(TP,"%^ORANGE%^You search the large bronze statues"+
      " but can't seem to find much.");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches the large bronze"+
      " statues but can't seem to find anything.",TP);
      return 1;
   }
   tell_object(TP,"%^ORANGE%^You carefully search the bronze statues"+
   " and discover that the %^YELLOW%^golden rod%^RESET%^%^ORANGE%^"+
   " that the mage is holding is not attached to the statue itself.");
   tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches the bronze statues and"+
   " carefully removes the %^YELLOW%^rod%^RESET%^%^ORANGE%^ the mage"+
   " is holding.",TP);
   new(OBJ+"rod")->move(TO);
   add_item("bronze statues","%^ORANGE%^Two life-sized bronze statues"+
   " stand on the same horizontal line as the throne, one on either edge"+
   " of the cliff. One is a warrior that stands fiercely with a spear in"+
   " his hands and a menacing expression beneath his helm. He is wearing"+
   " body armor that is countoured to show his muscles and is a daunting"+
   " image. The one to the right of the stone appears to be a mage"+
   " and is dressed in long flowing robes that appear to have been blown"+
   " by the wind. His hair trails backwards behind him. The position"+
   " of his hands suggests that he should be holding something, but"+
   " his hands are strangely empty.%^RESET%^");
   FOUND = 1;
}

void reset() // turning up the frequency of the demons so people don't have to cycle forever -Ares
{
   ::reset();
   if(present("greater demon")) return;
   //if(objectp(find_object("/d/antioch/ruins/mons/demon.c"))) return;
   //if(find_object("/d/antioch/ruins/portal/throne2.c") && find_object("/d/antioch/ruins/portal/throne1.c")) {
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
