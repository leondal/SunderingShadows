#include <std.h>
#include "../valley.h"
inherit WEAPON;

void create()
{
	::create();
	d_weap->create_weapon(TO);
/*
   if(query_size() == 1) {
      set_weight(5);
   }
   if(query_size() == 2) {
      set_weight(7);
   }
   if(query_size() == 3) {
      set_weight(10);
   }
   if(query_size() > 3) {
      set_weight(15);
   }
*/
 set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;
        if(!random(6)) {
        tell_object(ETO,"%^BOLD%^You swipe "+targ->QCN+" quickly.");
        tell_object(targ,"%^BOLD%^"+ETO->QCN+" swipes "+
            " you quickly.");
        tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" swipe"+
                "s "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+3);
        return 1;
        }
        if(!random(18)) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You whip your weapon back around to follow"+
                " up your attack on "+targ->QCN+".");
        tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" follows through with "+
                ""+ETO->QP+" attack to strike you again!");
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" follows through with"+
                ""+ETO->QP+" attack to strike "+targ->QCN+" a second "+
                "time.",({ETO,targ})); 
                        ETO->execute_attack();
        return 1;
        }               
}       
int checkme()
{
   if(!objectp(ETO)) return 0;
   if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle()))
      ETO->force_me("drop lance");
   return 0;
}
