//lance_inherit.c - for Riddle Quest.  Circe 1/19/04
//Updated to inherit from /d/common/obj/weapon for feats Octothorpe 5/5/09
#include <std.h>
inherit "/d/common/obj/weapon/lance.c";

int OWNED;
string owner;

void create() {
    ::create();
    set_name("lance");
    set_weight(15);
    set("value",0);
    set_wc(1,12);
    set_large_wc(1,21);
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
    set_size(1);
    set_type("piercing");
    set_prof_type("lance");
    set_property("lance",1);
    set_wield((:TO,"wield":));
    set_unwield("You feel the power of your deity leave you as you sheath your lance.");
    set_hit((:TO,"check":));
}

int wield() {
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The lance refuses your hand!  You are not its master!");
                tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" screams"+
                " in pain as "+ETO->QS+" tries to wield the lance.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You grasp the lance and feel the power of your deity flowing through it.");
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

int query_size() {
    if(objectp(ETO)&&living(ETO))
        return(int)ETO->query_size()  ;
    return ::query_size();
}
