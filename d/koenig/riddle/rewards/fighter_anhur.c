//fighter_anhur.c - Reward for the Riddle Quest.  Circe 5/26/08
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/scimitar";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("anhur weapon");
   set_id(({"talon","talon of the warhawk","scimitar","cord-wrapped scimitar","sword"}));
   set_obvious_short("A cord-wrapped scimitar");
   set_short("%^YELLOW%^Talon of the %^RED%^Warhawk%^RESET%^");
   set_long("Crafted from flawless %^BOLD%^mithril%^RESET%^, this "+
      "scimitar features a long, curving blade with a %^BOLD%^"+
      "%^BLACK%^blackened hilt %^RESET%^wrapped with %^BOLD%^"+
      "%^RED%^red cording%^RESET%^.  Where the blade meets the "+
      "hilt, the image of the cord continues with %^BOLD%^"+
      "etchings %^RESET%^snaking around the blade in imitation "+
      "of the wrappings.  Balancing the weight of the slender "+
      "blade is a detailed %^BOLD%^%^RED%^hawk's head %^RESET%^"+
      "with glittering %^YELLOW%^eyes %^RESET%^and a curving "+
      "%^BOLD%^%^BLACK%^beak %^RESET%^attached to the very end of "+
      "the hilt.  The weapon is exquisitely made and seems well-"+
      "tended, the edge sharp enough to slice almost painlessly.");
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This scimitar is sacred to warriors who follow the ways of Anhur.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Anhur leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The scimitar refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" screams"+
                " in pain as "+ETO->QS+" tries wield the scimitar.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Anhur as you wield the scimitar.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^RED%^You deftly whirl the scimitar, "+
         "slicing "+targ->QCN+" with finesse!%^RESET%^");
      tell_object(targ,"%^RED%^"+ETOQCN+" deftly whirls "+ETO->QP+" "+
         "scimitar, slicing you painfully!");
      tell_room(EETO,"%^RED%^"+ETOQCN+" deftly whirls "+
         ""+ETO->QP+" scimitar, slicing "+targ->QCN+" with "+
         "finesse!%^RESET%^",({ETO,targ}));
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
