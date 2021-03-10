#include "/d/dagger/aketon/short.h"

inherit OBJECT;

void create() {
   ::create();
   set_name("southeast cable");
   set_id( ({"cable","green cable","southwest_cable"}) );
   set("short","%^RESET%^%^GREEN%^green long cable");
   set("long","This cable is made of enchanted steel. It extends down to "
      "a huge tree towards the southeast. It is fixed in place on a large "
      "steel rack. Looks like you can slide on it.");
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   add_action("slide_func","slide");
}

int slide_func(string str) {
   int check;
   object obj;
   if(!str) return notify_fail("Slide what?\n");
   if(!present("sliding leather",TP))
      return notify_fail("You want to burn your bare hands sliding down?\n");
   if(member_array(str,
      ({"southeast cable","se cable","green cable","southeast_cable"})) == -1)
      return notify_fail("Which cable you want to slide on?\n");
   tell_object(TP,"You wrap the leather around the cable and slide all the "
      "way down to the southeast with extreme speed!");
   tell_room(ETO,TPQCN+" wraps a leather stripe around the cable and slides "
      "away.",TP);
   present("sliding leather",TP)->add_used(1);
   check = TP->query_stats("dexterity") + TP->query_stats("strength");
   if(check < roll_dice(1,24)) {
      tell_object(TP,"As you slide down, you failed to hold on to the leather "
         "stripe and fall through the leaves!");
      tell_room(ETO,TPQCN+" falls through the leaves as "+TP->query_subjective()+
         " failed to hold on to the leather stripe!",TP);
      tell_object(TP,"You couldn't even grab a leaf!");
      tell_object(TP,"You felt your soul left your body as you landed heavily "
         "on the ground!");
      TP->move_player(RPATH1+"1ground");
      obj = new("/std/Object");
      obj->set_name("Falling");
      TP->do_damage("torso",(int)TP->query_hp()+10);
      TP->add_attacker(obj);
      TP->continue_attack();
      TP->remove_attacker(obj);
      obj->remove();
      return 1;
   }
   if(check < roll_dice(1,38)) {
      tell_object(TP,"As you slide down, you failed to hold on to the leather "
         "stripe and fall through the leaves!");
      tell_room(ETO,TPQCN+" falls through the leaves as "+TP->query_subjective()+
         " failed to hold on to the leather stripe!",TP);
      tell_object(TP,"Your bones almost smashed into pieces as you land heavily "
         "on the ground!");
      TP->move_player(RPATH1+"1ground");
      TP->do_damage("torso",(int)TP->query_hp()-1);
      return 1;
   }
   TP->move_player(RPATH3+"3top");
   return 1;
}
