#include <std.h>
#include <daemons.h>
#include "../ruins.h"
inherit ROOM;

int OPEN;

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
   "%^RED%^You're standing on the edge of a %^YELLOW%^yellowish cloud%^RESET%^%^RED%^"+
   " that hangs motionlessly in this humid place. In the center of the"+
   " room is a %^MAGENTA%^portal%^RED%^ that opens out into the Antioch"+
   " Ruins. There is a brazier on the ground to the right of the portal"+
   " that burns with an intense %^BOLD%^%^CYAN%^blue flame%^RESET%^%^RED%^."+
   " The portal itself is hanging in the air, and its edges are"+
   " pulsing with a reddish-%^MAGENTA%^violet%^RED%^ light. Is it safe"+
   " to go through? There's only one way to find out."
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
   ({"cloud","yellow cloud"}) : "%^YELLOW%^There is a yellow cloud that"+
   " simply hangs motionless in the air in this section. You are on the"+
   " very edge of it right now, but it gets thicker to the northeast.",
   "brazier" : "There is a small and rather plain bronze brazier that"+
   " rests on the ground to the right of the portal. In the center a"+
   " small but very intense %^BOLD%^%^CYAN%^blue flame%^RESET%^ is"+
   " burning. Such braziers were sometimes used to offer a %^BOLD%^sacrifice%^RESET%^"+
   " of some sort of item, usually something valuable or specific to"+
   " the purpose it was to be sacrificed for, but what could you"+
   " possibly find in this desolate plane?",
   "portal" : "The portal hangs in the air in the middle of the room,"+
   " casting a faint light in the middle of the thick yellow cloud."+
   " The edges of the portal are constantly shifting, as though in"+
   " flux, and they pulse with an impatient %^RED%^reddish-%^MAGENTA%^violet%^RESET%^"+
   " light. In the center of the portal you can see the Antioch Ruins"+
   " on the other side, but you really have to wonder if it is safe to"+
   " travel through. You have the creepy feeling that the portal would"+
   " like to eat you.",
   ]));
   set_exits(([
   "west" : PORTAL+"p14",
   "portal" : ROOMS+"ruins18",
   ]));
   set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
}

void init()
{
   ::init();
   add_action("sacrifice","sacrifice");
}

void sacrifice(string str)
{
   object obj, *questors;
   int i;
   questors = ({});
   questors = filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);
   if(!str) {
      tell_object(TP,"You need to specify an item that you think will"+
      " appease the flames.");
      return 1;
   }
   if(!present(str,TP)) {
      tell_object(TP,"You don't even have that!");
      return 1;
   }
   obj = present(str,TP);
   if(!obj->query_property("brazier sacrifice")) {
      tell_object(TP,"That item just doesn't seem appropriate.");
      return 1;
   }
   if(obj->query_worn() || obj->query_wielded()) {
      tell_object(TP,"You need to remove it first.");
      return 1;
   }
   if(OPEN == 1) {
      tell_object(TP,"It seems rather pointless to sacrifice something"+
      " when the portal is already open, but you do it anyway.");
      tell_room(ETP,""+TPQCN+" throws a "+obj->query_short()+" into the"+
      " brazier which engulfs it in flames. Nothing happens.",TP);
      obj->remove();
      return 1;
   }
   tell_object(TP,"You throw the "+obj->query_short()+" into the"+
   " brazier which engulfs it in flames!");
   tell_room(ETP,""+TPQCN+" throws a "+obj->query_short()+" into the"+
   " brazier which engulfs it in flames!",TP);
   obj->remove();
   tell_room(ETP,"%^MAGENTA%^%^BOLD%^The flame changes color and begins"+
   " to glow a pale lavender.\n"+
   "%^WHITE%^The aura of the portal changes to an intense white and"+
   " the scene on the other side becomes much clearer!");
   add_item("portal","The portal hangs in the air in the middle of the"+
   " room, casting a soft white light in the middle of the thick yellow"+
   " cloud. The edges of the portal are a bright white light and seem"+
   " fairly stable, only rippling occasionaly. You can see the image on"+
   " the other side of the portal is that of the Antioch Ruins.");
   add_item("brazier","There is a small and rather plain bronze brazier"+
   " that rests on the ground to the right of the portal. In the center"+
   " a small but very intense %^BOLD%^%^MAGENTA%^lavender flame%^RESET%^"+
   " is burning contentedly.");
   for(i=0;i<sizeof(questors);i++){
      if(!objectp(questors[i])) { continue; }
      if(member_array("Plane of Fire",questors[i]->query_mini_quests()) == -1){
   questors[i]->set_mini_quest("Plane of Fire", 1000000, "%^BOLD%^%^RED%^Opened portal in the Plane of Fire\n");
      }
   }  
   OPEN = 1;  
   return 1;
}

int GoThroughDoor()
{
   if(OPEN != 1) {
      tell_object(TP,"%^RED%^%^BOLD%^You attempt to step through the"+
      " wild portal, but as you get close you can feel the portal"+
      " draining your energy away!\n"+
      "%^WHITE%^You barely manage to pull away and end up flat on your"+
      " back in pain!\n");
      set_property("magic",1);
      TP->do_damage("torso",random(20)+30);
      TP->add_attacker(TO);
      TP->continue_attack();
      TP->remove_attacker();
      remove_property("magic");
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" attempts to pass through"+
      " the portal but is suddenly drawn in!\n"+
      "%^WHITE%^There is a loud *SNAP* as "+TPQCN+" manages to pull"+
      " away from the portal, but "+TP->query_subjective()+" is thrown"+
      " across the room.",TP);
      TP->set_paralyzed(5,"You're in shock and in great pain, you may"+
      " have broken your back.");
      return 0;
   }
   tell_object(TP,"%^MAGENTA%^You experience a brief moment of"+
   " disorientation before you reach the other side.");
   return 1;
}

query_weather() { return "%^BOLD%^%^RED%^It is very hazy.%^RESET%^"; }
