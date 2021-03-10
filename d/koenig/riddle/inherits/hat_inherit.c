//Template for boots - reward for Nereid's Riddle quest.  Circe 1/17/04
#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create(){
        ::create();
	set_name("hat");
	set_weight(5);
	set_value(0);
	set_type("leather");
	set_limbs(({"head"}));
	set_size(2);
	set_property("enchantment",2);
      if(TO->query_property("enchantment")< 2){
         remove_property("enchantment");
         set_property("enchantment",2);
      }
	set_wear((:TO,"wear_func":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
                set_size(TP->query_size());
        }
}

int wear_func()
{
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The "+TO->query_obvious_short()+" refuses to "+
                   "fit your head!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                   " in pain as "+ETO->query_subjective()+" tries to put on the "+
                   ""+TO->query_obvious_short()+".",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You slip on the "+TO->query_obvious_short()+" and feel "+
           "the blessings of your deity.");
        return 1;
}
