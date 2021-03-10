//fighter_kossuth.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/flail";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("kossuth weapon");
   set_id(({"vicious spiked chain","spiked chain","chain","tendril","flame"}));
   set_obvious_short("A vicious spiked chain");
   set_short("%^BOLD%^%^RED%^Ten%^YELLOW%^d%^RED%^ril %^YELLOW%^of %^RED%^Fl%^YELLOW%^a%^RED%^me%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^RED%^This spiked chain is made out of an unusual red metal.  The links of the chain are rather thick but light, and there is enough chain to wrap it around the wielder's forearm.  The chain ends in a heavy ball that is fitted with %^RESET%^%^ORANGE%^orange %^BOLD%^%^RED%^and %^YELLOW%^yellow %^RED%^spikes, making it look like a flickering flame when the wielder whirls the chain over his head.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This spiked chain is sacred to warriors who follow the ways of Kossuth.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Kossuth leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The spiked chain refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the spiked chain.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Kossuth as you wield the spiked chain.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   tell_object(ETO,"%^RED%^You whirl the chain over your head before "+
      "hitting "+targ->QCN+" and retrieving it.");
   tell_object(targ,"%^RED%^The chain whirls in "+ETOQCN+"'s hand "+
      "before "+ETO->QS+" hits you with it.");
   tell_room(EETO,"%^RED%^"+ETOQCN+" whirls the chain over "+ETO->QP+" "+
      "head, before smacking "+targ->QCN+" and retrieving it.",({ETO,targ}));
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^RED%^The spiked ball %^YELLOW%^ignites %^RED%^"+
         "as it sears "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^RED%^The spiked ball on "+ETOQCN+"'s chain "+
         "%^YELLOW%^ignites %^RED%^as it sears your flesh!");
      tell_room(EETO,"%^BOLD%^%^RED%^The area is filled with the putrid smell of "+
         "burning flesh as "+ETOQCN+"'s chain sears "+targ->QCN+"!",({ETO,targ}));
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
