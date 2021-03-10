//shield_inherit.c - For cleric rewards for Riddle Quest.  Circe 1/2/04
//Update to inherit from /d/common/obj/armour for feats Octothorpe 5/6/09
#include <std.h>
inherit "/d/common/obj/armour/buckler.c"; //set to buckler as priests don't get shield feat by default. N, 3/11

int OWNED;
string owner;

void create() {
    ::create();
    set_name("shield");
    set_id(({"shield","medium shield","deity shield"}));
    set_weight(10);
    set_value(7);
    set_type("shield");
    set_limbs(({"right hand"}));
    set_ac(1);
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
        }
}

int wear_func()
{
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The shield burns you as you put it on.  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries to wear the shield.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel honored to be blessed with the shield of your faith.");
        return 1;
}
