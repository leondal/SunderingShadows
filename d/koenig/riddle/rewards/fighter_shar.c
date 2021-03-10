//fighter_shar.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/whip_dagger.c";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("shar weapon");
   set_id(({"sinuous whip dagger","whip dagger","whip","dagger","night's teeth","teeth"}));
   set_obvious_short("A sinuous whip dagger");
   set_short("%^BOLD%^%^BLACK%^Night's %^WHITE%^Teeth%^RESET%^");
   set_long(
@CIRCE
This sinuous whip dagger is made of lithe %^BOLD%^%^BLACK%^black leather %^RESET%^that is supple and well-oiled.  The %^BOLD%^%^BLACK%^bra%^WHITE%^i%^BLACK%^de%^WHITE%^d %^BLACK%^le%^WHITE%^a%^BLACK%^th%^WHITE%^e%^BLACK%^r %^RESET%^handle provides a steady grip even if the weapon is soaked in %^RED%^blood%^RESET%^.  Worked into the very end of the whip is an unusually sharp double-edged %^BOLD%^%^CYAN%^blade%^RESET%^.  When the whip is snapped, the blade leaves razor-like %^RED%^cuts %^RESET%^all along the
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This whip dagger is sacred to warriors who follow the ways of Shar.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Shar leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The whip dagger refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the whip dagger.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Shar as you wield the whip dagger.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   tell_object(ETO,"You crack the whip, slicing "+targ->QCN+"!");
   tell_object(targ,""+ETOQCN+" cracks "+ETO->QP+" whip, slicing you!");
   tell_room(EETO,""+ETOQCN+" cracks "+ETO->QP+" whip, slicing "+targ->QCN+"!",({ETO,targ}));
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^With a deafening %^WHITE%^CRACK,%^BLACK%^"+
         "your whip tears into "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^BLACK%^With a deafening %^WHITE%^CRACK,%^BLACK%^"+
         ""+ETOQCN+"'s whip tears into you!");
      tell_room(EETO,"%^BOLD%^%^BLACK%^With a deafening %^WHITE%^CRACK,%^BLACK%^"+
         ""+ETOQCN+"'s whip tears into "+targ->QCN+"!",({ETO,targ}));
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
