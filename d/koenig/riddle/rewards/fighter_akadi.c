//fighter_akadi.c - Reward for the Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/rapier";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("akadi weapon");
   set_id(({"electrum cutlass","cutlass","sting","wind's sting"}));
   set_obvious_short("An electrum cutlass");
   set_short("%^BOLD%^%^BLUE%^Wind's %^CYAN%^Sting%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^The blade of this beautiful cutlass is made of %^BLUE%^bluish ele%^WHITE%^c%^BLUE%^trum %^WHITE%^shot with fluid veins of %^RESET%^silver %^BOLD%^that seem to shift and move of their own accord as if blown by some fierce wind.  The blade of the cutlass narrows near the hilt, which has been wrapped in %^CYAN%^blue silk %^WHITE%^and crisscrossed with %^RESET%^silver wire%^BOLD%^.  The %^YELLOW%^crossguard %^WHITE%^of the cutlass is quite ornate, curving back over the wielder's hand and ending in a flourish where it attaches to the round %^BLUE%^sapphire pommel%^WHITE%^.
CIRCE
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CIRCE
This cutlass is sacred to warriors who follow the ways of Akadi.  Though many warriors may join the faith, only those who prove themselves truly dedicated are rewarded with a weapon such as this.  Those who wield it consider themselves blessed.
CIRCE
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Akadi leave you as you sheath your weapon.");
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
        tell_object(ETO,"%^BOLD%^You feel the blessings of Akadi as you wield the cutlass.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^CYAN%^The wind howls as your cutlass slices "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" slices you with "+ETO->QP+" cutlass as the "+
         "winds howl!");
      tell_room(EETO,"%^BOLD%^%^CYAN%^The winds howl as "+ETOQCN+" slices "+targ->QCN+" "+
         "with "+ETO->QP+" cutlass!",({ETO,targ}));
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
