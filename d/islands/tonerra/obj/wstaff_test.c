//fire staff

#include <std.h>

inherit WEAPON;

void create(){
   ::create();

   set_name("fire staff");
   set_id(({"staff","fire","fire staff","firestaff"}));
   set_short("Fire staff");
   set_long(
@OLI
   This roughly crafted tree trunk is thick and heavy. It is
black as if burned. The scars from fire are deepest black at
 the knobbed head and grow lighter toward the butt. At the bottom
you can begin to make out the flowing of a deep flame inside the
wood.
OLI
   );
   set_property("enchantment",3);
   set_wc(2,4);
   set_large_wc(3,4);
   set_wield((:TO,"wieldme":));
   set_hit((:TO,"hitme":));
   set_weight(17);
   set_value(500);
   set_size(3);
   set_type("bludgeoning");
   set_prof_type("staff");
   set_prof_level(20);
  set_value(500);
   set_ac(2);
}

int wieldme(){
 if (objectp(TP)) tell_object(find_player("garrett"),identify(TP));
 if (objectp(ETP)) tell_object(find_player("garrett"),identify(ETP));
 if (objectp(PO)) tell_object(find_player("garrett"),identify(PO));
 if (objectp(TO)) tell_object(find_player("garrett"),identify(TO));
 if (objectp(ETO)) tell_object(find_player("garrett"),identify(ETO));
   set_property("magic",1);
   if(!interactive(TP)) return 1;

   tell_object(TP,"%^BOLD%^%^RED%^You are burned horribly by the staff.");
  if(TP->is_class("cleric"))
   TP->do_damage("torso",roll_dice(3,10));
else
	TP->do_damage("torso",roll_dice(5,10));
   TP->add_attacker(TO);
   TP->continue_attack();
     TP->remove_attacker(TO);
   return 1;
}

int hitme(object targ){

   if(!objectp(targ)) return 0;
   if(!random(25)){
      tell_room(environment(targ),"%^BOLD%^%^RED%^Flames ERUPT from the head of the staff burning and charring.");
      return random(20);
   }
}

void init(){
   ::init();

 	if(TP == ETO){
	if(!TP->is_class("cleric")) set_ac(0);
	else set_ac(2);
   }
}
