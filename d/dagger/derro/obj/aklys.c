//did some basic code cleanup while removing old gods in other files ~Circe~ 7/30/19
#include <std.h>
inherit "/d/common/obj/weapon/club";

void create(){
   ::create();
   set_id(({"club","aklys"}));
   set_name("aklys");
   set_id(({"club","aklys"}));
   set_short("an aklys");
   set_long("This is a short heavy club.  It has a hook, and it's attached to its wielder with a leather thong so in combat it can be thrown and used to jerk opponents off balance.");
   set_property("enchantment",2);
   set_weight(5);
   set_size(1);
   set_value(10);
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
      tell_object(ETO,"%^BOLD%^%^WHITE%^You throw your club at "+ob->QCN+", smacking "+ob->QO+" painfully, then you whip the club back to your hand with its cord!%^RESET%^",ETO);
      tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" throws a club at "+ob->QCN+", smacking "+ob->QO+" painfully before whipping the club back with a cord, readying for another throw!%^RESET%^",({ETO,ob}));
      tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->QCN+" throws a club at you, and it smacks you painfully before being whipped back into "+ETO->QP+" hand with a leather cord!%^RESET%^");
      if(roll>95){
         tell_object(ETO,"%^BOLD%^%^WHITE%^You snag "+ob->QCN+" with the hook on the club and pull "+ob->QO+" off balance!%^RESET%^",ETO);
         tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" snags "+ob->QCN+" with the hook on the club pulling "+ob->QO+" off balance!%^RESET%^",({ETO,ob}));
         tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->QCN+" catches you with the hook on the club and pulls you off balance!");
         ob->set_tripped(1,"%^BOLD%^%^WHITE%^You are struggling to your feet!%^RESET%^");
      }
   return (roll_dice(1,6));
   }
}
