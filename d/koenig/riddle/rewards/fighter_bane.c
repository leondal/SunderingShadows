//fighter_bane.c - Reward for the Riddle Quest.  Circe 4/21/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/mclub";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("bane weapon");
   set_id(({"bane spiked gauntlet","spiked gauntlet","gauntlet","hand","master's hand"}));
   set_obvious_short("A black spiked gauntlet");
   set_short("%^BOLD%^%^BLACK%^Ma%^GREEN%^s%^BLACK%^ter's H%^GREEN%^a%^BLACK%^nd%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^This wicked looking gauntlet is made of blackened steel that is unyielding and seems unbreakable.  Long, curving spikes rise from the end of the gauntlet in a mockery of fingers and would probably puncture an opponent.  The purpose of this gauntlet, though, seems to be to provide brutal force to prove one's superiority.  Two oval-shaped sparkling %^GREEN%^em%^WHITE%^e%^GREEN%^ra%^WHITE%^l%^GREEN%^ds %^BLACK%^have been set into the back of the gauntlet and look eerily like a pair of judging eyes.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This spiked gauntlet is sacred to warriors who follow the ways of Bane.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Bane leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The spiked gauntlet refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" screams"+
                " in pain as "+ETO->QS+" tries wield the spiked gauntlet.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Bane as you wield the spiked gauntlet.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^GREEN%^With a vicious hiss, you backhand "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" hisses and "+
         "backhands you with a spiked gauntlet!");
      tell_room(EETO,"%^BOLD%^%^RED%^Blood %^GREEN%^flies as "+ETOQCN+" backhands "+
         ""+targ->QCN+" with a spiked gauntlet!",({ETO,targ}));
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
