//weapon_inherit.c - For fighter and cleric weapons for Riddle Quest.  Circe 1/31/04
#include <std.h>
inherit WEAPON;

int OWNED;
string owner;

void create (){
   ::create();
   set_name("weapon");
   set_weapon_prof("simple");
   set_value(0);
   set_property("enchantment",2);
   if(TO->query_property("enchantment")< 2){
      remove_property("enchantment");
      set_property("enchantment",2);
   }
   set_wield((:TO,"wield_func":));
}

int wield_func() {
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The weapon refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the weapon.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
	  ETO->add_attack_bonus(1);
   	  ETO->add_damage_bonus(1);
        tell_object(ETO,"%^BOLD%^You grasp the weapon and feel the power of your deity flowing through it.");
        return 1;
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
