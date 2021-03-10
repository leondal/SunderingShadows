//thief_default.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/shortsword";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("thief weapon");
   set_id(({"thief weapon","shortsword","short sword","sword"}));
   set_short("A well-made short sword");
   set_long(
     "This short sword is a perfect weapon for some, a good backup weapon "+
     "for others.  It's shorter than the average sword but that just "+
     "makes it more manageable, while its sharp edge and point could "+
     "never be counted completely out by an opponent.  The hilt of "+
     "this sword has been wrapped in brown leather cording to provide a "+
     "better grip, and the blade itself seems exceedingly well-made."
  ); 
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_wield((:TO,"wield_me":));
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The sword refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the sword.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You wrap your hand comfortably around the hilt of your sword.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^You savagely thrust your sword into "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^"+ETOQCN+" snarls as "+ETO->QS+" thrusts "+ETO->QP+" "+
         "sword into you!");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" snarls as "+ETO->QS+" thrusts "+ETO->QP+" "+
         "sword into "+targ->QCN+"!",({ETO,targ}));
      targ->do_damage("torso",random(5)+6);
      return 1;
   }
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}
