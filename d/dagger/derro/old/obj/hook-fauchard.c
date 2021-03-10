#include <std.h>
inherit WEAPON;
void create(){
  ::create();
set_id(({"polearm","pole arm","hook-fauchard","spear","hook"}));
  set_name("hook-fauchard");
  set_short("Hook-fauchard");
  set_long("This is a 6 foot long Derro pole arm.  It can be used to impale and then drag opponents off balance with its hooks");
  set_weight(10);
  set_size(2);
  set_value(10);
  set_wc(1,4);
  set_large_wc(2,3);
  set_type("slash");
  set_prof_type("polearm");
  set_property("enchantment",2);
  set_hit((:TO,"extra_hit":));
    set_weapon_prof("martial");
}
int extra_hit(object ob){
  int dam;
  ob = ETO->query_current_attacker();
  if(!objectp(ob))return 1;
  if(random(25)>2)  return 1;   
// changed from 15, was a little too frequent *Styx* 8/15/03
   message("my_action","%^BOLD%^%^WHITE%^You impale "+ob->query_cap_name()+" and then drag "+ob->query_objective()+" off balance with the hook!",ETO);
   message("other_action","%^BOLD%^%^WHITE%^" +ETO->query_cap_name()+ " impales "+ob->query_cap_name()+" with "+ETO->query_possessive()+" hooked pole arm and then pulls "+ob->query_objective()+" off ballance!",environment(ob),(({ETO,ob})));
   message("my_action","%^BOLD%^%^WHITE%^" +ETO->query_cap_name()+ " impales you with "+ETO->query_possessive()+" hooked pole arm and then pulls you off your feet!",ob);
   ob->set_tripped(1,"%^BOLD%^%^WHITE%^You are struggling to your feet!");
  return(random(5)+1);
}
