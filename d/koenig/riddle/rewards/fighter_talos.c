//fighter_talos.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/mspear";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("talos weapon");
   set_id(({"darkwood spear","spear","spear of storms","storms"}));
   set_obvious_short("A darkwood spear");
   set_short("%^BOLD%^%^BLACK%^Spear of %^YELLOW%^St%^BLACK%^o%^YELLOW%^rm%^BLACK%^s%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^This unusual spear is made of nearly black darkwood that is twisted into a corkscrew.  Rather than making it hard to use, however, it seems to provide an excellent grip and somehow rides on the %^CYAN%^winds%^BLACK%^.  The spearhead is actually a highly-polished, multi-faceted piece of %^YELLOW%^amber %^BLACK%^that seems to flash like %^YELLOW%^lightning%^BLACK%^.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This spear is sacred to warriors who follow the ways of Talos.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Talos leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The spear refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the spear.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Talos as you wield the spear.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^CYAN%^A savage gust of wind guides the spearhead into "+
         ""+targ->QCN+", gutting "+targ->QO+"!");
      tell_object(targ,"%^CYAN%^A gust of wind rises suddenly, just as "+ETOQCN+""+
         "thrusts "+ETO->QP+" spear into you!");
      tell_room(EETO,"%^CYAN%^A gust of wind rises suddenly, just as "+ETOQCN+""+
         "thrusts "+ETO->QP+" spear into "+targ->QCN+"!",({ETO,targ}));
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
