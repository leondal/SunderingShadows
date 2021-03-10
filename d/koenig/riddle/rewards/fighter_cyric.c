//fighter_cyric.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/longsword";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("cyric weapon");
   set_id(({"ivory-hilted long sword","long sword","sword","Skullblade","skullblade","skull blade","blade"}));
   set_obvious_short("A long sword with an ivory hilt");
   set_short("%^BOLD%^%^BLACK%^Skullbl%^WHITE%^a%^BLACK%^de%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^This long sword has a darkened blade that contrasts sharply with the brilliant %^WHITE%^ivory hilt%^BLACK%^.  The sword has an excellent weight and a long fuller that runs the length of the blade.  Etched into either side of the blade are strange depictions of jawless skulls centered within starbursts.  The uppermost and lowermost tendrils of the starburst extend in a swirling arch all the way down the blade from hilt to tip.  The hilt itself is quite plain and cool to the touch.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This long sword is sacred to warriors who follow the ways of Cyric.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Cyric leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The long sword refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the long sword.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Cyric as you wield the long sword.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^A manaical laughter fills your ears as you smite "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^"+ETOQCN+" laughs insanely as "+ETO->QP+" long sword slices "+
         "you!");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" laughs insanely as "+ETO->QP+" long sword slices "+
         ""+targ->QCN+"!",({ETO,targ}));
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
