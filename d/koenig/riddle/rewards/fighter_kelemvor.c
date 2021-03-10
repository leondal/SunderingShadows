//fighter_kelemvor.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/two_hand_sword";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("kelemvor weapon");
   set_id(({"massive greatsword","greatsword","sword","great sword","sleep","death's sleep"}));
   set_obvious_short("A massive greatsword");
   set_short("%^BOLD%^Death's Sleep%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLUE%^This massive greatsword would require two hands for even the largest human to wield.  The blade is well-made and extremely sharp, despite its ancient appearance.  The blade's steel no longer reflects light, covered as it is with the scratches and nicks caused by much use, but the %^WHITE%^bone hilt %^BLUE%^is highly polished and reveals that great care is taken in the upkeep of this sword.  Set within the round bone pommel is an etched symbol - a %^WHITE%^skeletal hand %^BLUE%^holding a set of %^YELLOW%^golden scales%^BLUE%^.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This greatsword is sacred to warriors who follow the ways of Kelemvor.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Kelemvor leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The greatsword refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the greatsword.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Kelemvor as you wield the greatsword.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^You swing your greatsword over your head, cleaving "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^Your very bones rattle as "+ETOQCN+" brings down "+
         ""+ETO->QP+" greatsword atop your head!");
      tell_room(EETO,"%^BOLD%^There is a sickening crunch as "+ETOQCN+" cracks open "+
         ""+targ->QCN+"'s head with a greatsword!",({ETO,targ}));
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
