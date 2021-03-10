#include <std.h>
inherit "/d/common/obj/weapon/club";
void create(){
  ::create();
  set_id(({"club","aklys"}));
  set_name("aklys");
  set_id(({"club","aklys"}));
  set_short("an aklys");
   set_long("This is a short heavy club.  It has a hook and it's attached to its wielder with a leather thong so in combat it can be thrown and used to jerk opponents off balance.");
  set_property("enchantment",2);
  set_weight(5);
  set_size(1);
  set_value(10);
   //set_wc(1,6);
   //set_large_wc(1,4);
   //set_typle("bludgeoning");
  set_wield("You wrap the leather thong around your wrist.");
set_unwield("The leather thong is undone and the weapon slips free.");
  set_hit((:TO,"extra_hit":));
}
int extra_hit(object ob){
  int roll;
  ob = ETO->query_current_attacker();
  roll=random(100)+1;
  if(!objectp(ob))return 1;
  if(roll>90){
   message("my_action","%^BOLD%^%^WHITE%^You throw your club at "+ob->query_cap_name()+" smacking "+ob->query_objective()+" painfully then you whip the club back to your hand with its cord!",ETO);
   message("other_action","%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" throws a club at "+ob->query_cap_name()+" smacking "+ob->query_objective()+" painfully then whips the club back with a cord, readying for another throw!",environment(ob),(({ETO,ob})));
   message("my_action","%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" throws a club at you and it smacks you painfully, before being whipped back into "+ETO->query_possessive()+" hand with a leather cord!",ob);
  if(roll>95){
   message("my_action","%^BOLD%^%^WHITE%^You snag "+ob->query_cap_name()+" with the hook on the club and pull "+ob->query_objective()+" off balance!",ETO);
   message("other_action","%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" snags "+ob->query_cap_name()+" with the hook on the club pulling "+ob->query_objective()+" off balance!",environment(ob),(({ETO,ob})));
   message("my_action","%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" catches you with the hook on the club and pulls you off balance!",ob);
  ob->set_tripped(1,"%^BOLD%^%^WHITE%^You are struggling to your feet!");
  }
  return (roll_dice(1,6));
  }
}
