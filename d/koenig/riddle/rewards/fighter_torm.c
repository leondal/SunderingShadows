//fighter_torm.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/two_hand_sword";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("torm weapon");
   set_id(({"golden greatsword","greatsword","sword","pride","lion's pride"}));
   set_obvious_short("A golden greatsword");
   set_short("%^BOLD%^%^WHITE%^Lion's %^YELLOW%^Pride%^RESET%^");
   set_long(
@CIRCE
%^YELLOW%^This massive greatsword looks to be made entirely of gold.  The crossguard is a piece of elegant curving scrollwork that has been set with %^RED%^rubies%^YELLOW%^ on either side, resembling eyes.  The hilt is made of burnished gold worked into a %^CYAN%^diamond %^YELLOW%^pattern and set with a massive %^RED%^ruby %^YELLOW%^in the pommel.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This greatsword is sacred to warriors who follow the ways of Torm.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Torm leave you as you sheath your weapon.");
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
        tell_object(ETO,"%^BOLD%^You feel the blessings of Torm as you wield the greatsword.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^YELLOW%^You deftly slip your sword through "+targ->QCN+"'s "+
         "defenses and slice "+targ->QO+" soundly!");
      tell_object(targ,"%^YELLOW%^"+ETOQCN+" slips through your defenses, slicing "+
         "you open!");
      tell_room(EETO,"%^YELLOW%^"+ETOQCN+" slips through "+targ->QCN+"'s defenses, slicing "+
         ""+targ->QO+" open!",({ETO,targ}));
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
