//fighter_tempus.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/battle_axe";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("tempus weapon");
   set_id(({"silvered battle axe","battle axe","axe","fury","battle's fury"}));
   set_obvious_short("A silvered battle axe");
   set_short("%^RED%^Battle's %^BOLD%^%^WHITE%^Fury%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^This silvered battle axe has seen much use, judging from its dents and knicks.  It has two axe heads that balance each other, each one a wicked crescent moon that is honed to perfection.  The haft supporting the axeheads is made of solid %^RESET%^%^ORANGE%^oak %^BOLD%^%^WHITE%^covered in tiny depictions of battle.  Each figure represents a renowned warrior throughout the ages, though many of their names are now lost.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This battle axe is sacred to warriors who follow the ways of Tempus.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Tempus leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The battle axe refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the battle axe.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Tempus as you wield the battle axe.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^RED%^You swing the axe wide, cleaving "+targ->QCN+" with "+
         "all your might!");
      tell_object(targ,"%^RED%^"+ETOQCN+" swings "+ETO->QP+" axe wide, catching "+
         "you off-guard with a stunning blow!");
      tell_room(EETO,"%^RED%^"+ETOQCN+" swings "+ETO->QP+" axe wide, catching "+
         ""+targ->QCN+" off-guard with a stunning blow!",({ETO,targ}));
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
