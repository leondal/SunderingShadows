//fighter_malar.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/claw";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("malar weapon");
   set_id(({"bloody clawed glove","claws","glove","clawed glove","claws of the beast"}));
   set_obvious_short("A bloody clawed glove");
   set_short("%^BOLD%^%^RED%^C%^WHITE%^law%^RED%^s %^WHITE%^of the %^RED%^Beast%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^This glove is made of tanned hide that has been bleached in the sun until it is almost bone white.  Long, curving %^BLACK%^claws %^WHITE%^that look to be constantly stained with %^RED%^blood %^WHITE%^are fitted at the base of the fingers, so that they cover the wearer's fingers.  The %^BLACK%^claws %^WHITE%^are razor-sharp and look to be taken from some great beast rather than made of any metal.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This claws is sacred to warriors who follow the ways of Malar.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Malar leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The claws refuse your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the claws.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Malar as you wield the claws.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^RED%^Blood flies as you slash "+targ->QCN+"'s face!");
      tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" slashes your face with "+ETO->QP+" "+
         "clawed hand!");
      tell_room(EETO,"%^BOLD%^%^RED%^Blood streaks "+ETOQCN+"'s face as "+ETO->QS+" "+
         "slashes "+targ->QCN+" with a clawed hand!",({ETO,targ}));
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
