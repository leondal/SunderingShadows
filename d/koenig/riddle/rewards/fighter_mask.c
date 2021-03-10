//fighter_mask.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/rapier";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("mask weapon");
   set_id(({"slender rapier","rapier","sword","quickness","shadows","quickness of shadows"}));
   set_obvious_short("A slender rapier");
   set_short("%^BOLD%^%^BLACK%^Quickness of Shadows%^RESET%^");
   set_long(
@CIRCE
This slender rapier looks much like any other, with a narrow blade curving slightly to a razor-sharp point.  The blade ends in a %^BOLD%^platinum basket %^RESET%^protecting the swordsman's hand, and the hilt has been wrapped in deep %^BOLD%^%^BLACK%^gray leather %^RESET%^strips to provide a good grip.  The edges of the hilt are trimmed with a thin line of %^BOLD%^platinum%^RESET%^, adding a touch of elegance to this exceptional weapon.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This rapier is sacred to warriors who follow the ways of Mask.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Mask leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The rapier refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the rapier.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Mask as you wield the rapier.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows around you seem to coalesce, guiding "+
         "your hand for a powerful strike against "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^"+ETOQCN+" smiles smugly as "+ETO->QS+" strikes "+
         "you with great force!");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" smiles smugly as "+ETO->QS+" strikes "+
         ""+targ->QCN+" with great force!",({ETO,targ}));
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
