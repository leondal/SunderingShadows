//druid_default.c - reward for Riddle Quest. ~Circe~ 3/22/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
	set_wear((:TO,"wear_func":));
}

void init(){
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
                set_size(TP->query_size());
        }
}

int wear_func(){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The armor refuses to fit to your form!  You are not its master!");
                tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" screams"+
                " in pain as "+ETO->QS+" tries to put on the armor.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You find yourself wrapped within the blessings of "+capitalize(ETO->query_diety())+" as you wear the armor.");
        return 1;
}
