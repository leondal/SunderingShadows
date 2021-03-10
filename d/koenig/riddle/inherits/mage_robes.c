//Template for breastplates - reward for Nereid's Riddle quest.  Circe 12/9/03
//Removed the AC point in rebalancing magerobes mudwide. Nienne, 05/07
#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

int OWNED;
string owner;

void create(){
        ::create();
	set_name("robes");
	set_weight(5);
	set_value(0);
	set_max_internal_encumbrance(21);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
//      set_ac(1);
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
                tell_object(ETO,"%^BOLD%^%^RED%^The clothing refuses to fit to your form!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries to put on the clothing.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You slip on the clothing and are surprised to find pockets hidden in the folds.");
        return 1;
}
