//Template for ranger's hide - reward for Nereid's Riddle quest.  Circe 1/19/04
//Updated to inherit from /d/common/obj/armour to conform to armor feats Octothorpe 5/6/09
#include <std.h>
inherit "/d/common/obj/armour/hide.c";

int OWNED;
string owner;

void create(){
      ::create();
	set_name("hide armor");
	set_weight(30);
	set_value(0);
	set_type("leather");
	set_limbs(({"torso"}));
      //set_ac(2);
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
                tell_object(ETO,"%^BOLD%^%^RED%^The armor refuses to fit to your form!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries to put on the armor.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You find yourself wrapped within the blessings of your deity as you wear the armor.");
        return 1;
}
