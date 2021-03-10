//fighter_auril.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/rapier";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("auril weapon");
   set_id(({"crystal cutlass","auril cutlass","cutlass","frostbite"}));
   set_obvious_short("A crystal cutlass");
   set_short("%^BOLD%^%^CYAN%^Frost%^WHITE%^bite%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^Rather than being made of any metal, this cutlass seems to be carved entirely from one large %^CYAN%^clear crystal%^WHITE%^!  The blade is rather thin, making it seem fragile, though there seems to be nothing that can break the crystal.  The blade is honed to a deadly edge, and the entire sword looks as though it is made of %^CYAN%^ice%^WHITE%^.  The hilt has been left bare, but it seems to have a good grip nonetheless.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This cutlass is sacred to warriors who follow the ways of Auril.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Auril leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The cutlass refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the cutlass.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Auril as you wield the cutlass.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^CYAN%^A sudden blast of %^WHITE%^frost %^CYAN%^"+
         "flies from your blade, "+
         "straight into "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s rapier freezes you with a sudden "+
         "blast of %^WHITE%^frost%^CYAN%^!");
      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s rapier freezes "+targ->QCN+" with a sudden "+
         "blast of %^WHITE%^frost%^CYAN%^!",({ETO,targ}));
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
