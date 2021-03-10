//fighter_loviatar.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/shortsword";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("loviatar weapon");
   set_id(({"ornamental stiletto","stiletto","dagger","embrace","pain's embrace"}));
   set_obvious_short("An ornamental stiletto");
   set_short("%^BOLD%^%^RED%^Pain's %^BLACK%^Embrace%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^Designed entirely as a thrusting weapon, this stiletto is about nine inches long and would make a nasty off-hand weapon in the hands of a capable warrior.  Blades such as this one are often used to make small, deep wounds that are incredibly difficult to heal.  This particular stiletto has a unique eight-edged blade that produces gaping puncture wounds that bleed profusely.  The handle is made of ebony and wrapped in crisscrossing strips of %^RED%^red silk%^BLACK%^.  One would have to be depraved to use a weapon such as this.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This stiletto is sacred to warriors who follow the ways of Loviatar.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Loviatar leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The stiletto refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" screams"+
                " in pain as "+ETO->QS+" tries wield the stiletto.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Loviatar as you wield the stiletto.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^RED%^You smile wickedly as you thrust the stilleto "+
         "into "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" smiles with pleasure as "+ETO->QS+" "+
         "thrusts a stiletto between your ribs!");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" smiles with pleasure and thrusts "+
         "a stiletto deep into "+targ->QCN+"s chest!",({ETO,targ}));
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
