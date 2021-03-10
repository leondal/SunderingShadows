//shortened the length in the describe from 13 ft. which just didn't seem
//realistic for even a 10 ft. tall to wield two handed, lowered wt. to 60 
//since even stormhammers are only 35, added the obvious short and lore 
//Styx 12/29/01
//Set to giant bastard sword inherit for proper stats. Nienne, 07/09.

#include <std.h>
inherit "/d/common/obj/weapon/giant_bastard";

void create(){
  ::create();
  set_id(({"two handed sword","flaming greatsword","greatsword","sword"}));
  set_name("flaming greatsword");
  set_obvious_short("huge two handed sword");
  set_short("%^BOLD%^%^RED%^Flaming greatsword%^RESET%^");
   set_long("This massive two handed sword is eight feet long and is so heavy and "
      "unwieldy that even the largest races must use two hands to wield it.  "
      "Its edge shimmers like a spurt of flame.");
  set_lore("This sword is rumored to have been forged in the fiery lava itself "  
     "by giants who braved the inferno under their home along with powerful mages "
     "to imbue the steel with the fire of the lava itself.");
  set_value(8000);
  set_property("enchantment",4);
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
}

int extra_hit(object ob) {
  object vic;
  int dam;
  if(!random(5)){
   message("my_action","%^BOLD%^%^RED%^ The flameblade sizzles as it hits "+ob->query_cap_name()+".",ETO);
  message("other_action","%^BOLD%^%^RED%^" +ETO->query_cap_name()+"'s massive sword sizzles with intense heat as is slashes "+ob->query_cap_name()+"!",environment(ob),(({ETO,ob})));
  message("my_action","%^BOLD%^%^RED%^" +ETO->query_cap_name()+"'s sword sizzles with intense heat as it slashes you!",ob);
  dam=random(10)+5;
  if(!random(5))call_out("burn",5,ob,1);
  return dam;
  }
}

int extra_wield(){
  if((int)ETO->query_highest_level()<25) {
   tell_object(ETO,"%^BOLD%^You don't think you could control such an immense weapon till you train a little more.");
   tell_room(environment(ETO),"%^BOLD%^"+ETO->query_short()+" ponders a massive sword and decides "+ETO->query_subjective()+" doesn't want to risk cutting "+ETO->query_possessive()+" own head off wielding it.%^RESET%^",ETO);
  return 0;
  }
  return 1;
}

void burn(object ob, int time){
  if(!objectp(ob)) return;
  switch (time){
  case 1:
  tell_object(ob,"%^BOLD%^%^RED%^You realize that the sword has lit you on fire and you struggle to pat out the flames!");
  tell_room(environment(ob),"%^BOLD%^%^RED%^"+ob->query_cap_name()+" pats at the slash marks which have burst into flame!",ob);
  ob->do_damage("torso",random(10)+3);
  if(objectp(ob)) ob->add_attacker(TO);
  if(objectp(ob)) ob->continue_attack();
  if(!objectp(ob)) return;
  call_out("burn",5,ob,2);
  break;
  case 2:
  tell_object(ob,"%^BOLD%^%^RED%^The smoldering slash marks suddenly burst into flame engulfing you!");
  tell_room(environment(ob),"%^BOLD%^%^RED%^"+ob->query_cap_name()+" is engulfed in the flames that were started by the flaming sword!",ob);
  ob->do_damage("torso",random(3)+10);
  if(objectp(ob)) ob->add_attacker(TO);
  if(objectp(ob)) ob->continue_attack();
  if(!objectp(ob)) return;
  call_out("burn",5,ob,3);
  break;
  case 3:
  tell_object(ob,"%^BOLD%^%^RED%^The flames die down again and then sputter out as quickly as they came!");
  tell_room(environment(ob),"%^BOLD%^%^RED%^The flames on "+ob->query_cap_name()+" sputter and die out as quickly as they started!",ob);
  ob->do_damage("torso",random(10)+3);
  if(objectp(ob)) ob->add_attacker(TO);
  if(objectp(ob)) ob->continue_attack();
  if(!objectp(ob)) return;
  break;
  }
}
