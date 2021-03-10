//cleric_akadi.c - Reward for Nereid's Riddle Quest - Circe 12/12/03
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

int OWNED;
string owner;

void create() {
   ::create();
   set_id(({"whip","blue whip","wind whip","zephyr's breath","zephyr","breath"}));
//   set_name("akadi whip");
   set_short("%^BOLD%^%^BLUE%^Zep%^CYAN%^h%^BLUE%^yr's %^CYAN%^Breath%^RESET%^");
   set_obvious_short("%^BOLD%^%^CYAN%^A slender blue whip%^RESET%^");
   set_long(
      "%^BOLD%^%^CYAN%^This unusual whip is incredibly light, and its "+
      "transluscent appearance suggests why.  The handle is carved from "+
      "pure %^BLUE%^sapphire %^CYAN%^that serves to emphasize the airy "+
      "quality of the whip itself.  Made of a strange material that seems "+
      "more air than substance, the whip undulates in a deadly dance."
   );
   set_lore("%^BOLD%^%^WHITE%^The whips known as %^BOLD%^%^BLUE%^Zep"+
      "%^CYAN%^h%^BLUE%^yr's %^CYAN%^Breath%^WHITE%^ are said to be crafted "+
      "of the wind itself in a ceremony known only to the most devout of "+
      "Akadi's clergy.  It is said to involve standing atop the highest mountain "+
      "with the sapphire handle as a focus, but so far none has been crafted without "+
      "the blessing of Akadi herself.");
   set_property("lore difficulty",12);
   set_weight(2);
   set_size(2);
   set_value(0);
   set_wc(1,2);
   set_large_wc(1,2);
   set_type("lash");
   set_prof_type("whip");
   set_weapon_speed(8);
   set_wield((:TO,"wield_me":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"extra_hit":));
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

int wield_me(string str) {
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The weapon refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries to wield the weapon.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^%^CYAN%^As you wield the whip, the winds "+
           "pick up, swirling around you!");
        tell_room(environment(ETO),"%^BOLD%^%^CYAN%^As "+ETOQCN+" wields the whip, winds "+
           "swirl through the area!",ETO);
        return 1;
}

int unwield_func(string str) 
{
        tell_object(ETO,"%^BOLD%^%^CYAN%^The winds recede as you unwield the whip.%^RESET%^");
        return 1;
}

int extra_hit(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(15)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^A rustling sound builds around the whip "+
         "before it explodes into your victim!");
      tell_object(victim,"%^BOLD%^%^WHITE%^You hear a growing rustling sound "+
         "before "+ETOQCN+"'s whip explodes into you!");
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The rustle of winds gathers "+
         "around "+ETOQCN+"'s whip before exploding into "+victim->query_cap_name()+"!", ({ETO,victim}));
      victim->do_damage("torso",random(10)+6);
      return 1;
   }
   else return 1;
}
