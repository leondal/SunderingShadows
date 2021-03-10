//fighter_silvanus.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/hammer_lg";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("silvanus weapon");
   set_id(({"maul","hammer","stone maul","will","nature's will"}));
   set_obvious_short("A stone maul");
   set_short("%^GREEN%^Na%^ORANGE%^tu%^GREEN%^re's W%^ORANGE%^il%^GREEN%^l%^RESET%^");
   set_long(
@CIRCE
%^ORANGE%^This massive hammer seems to be made entirely of stone.  The double-headed hammer is extremely heavy and seems to carry the weight of the world behind it.  Even the handle is made out of a reddish gray stone, and it seems to be free of carvings or scratches of any kind.  The broad sides of the hammer heads have been carved with a huge oak leaf that wraps all around the hammer.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This maul is sacred to warriors who follow the ways of Silvanus.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Silvanus leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The maul refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the maul.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Silvanus as you wield the maul.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^GREEN%^With the might of the %^ORANGE%^oak%^GREEN%^, you "+
         "smite "+targ->QCN+"!");
      tell_object(targ,"%^GREEN%^"+ETOQCN+" gets a wild look in "+ETO->QP+" eyes as "+
         ""+ETO->QS+" strikes you with tremendous might!");
      tell_room(EETO,"%^GREEN%^"+ETOQCN+" gets a wild look in "+ETO->QP+" eyes as "+
         ""+ETO->QS+" strikes "+targ->QCN+" with tremendous might!",({ETO,targ}));
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
