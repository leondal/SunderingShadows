//ranger_default.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
	set_name("ranger hide");
	set_id(({"hide","armor","hide armor","suit of hide armor","suit"}));
	set_short("A suit of hide armor");
	set_long(
        "This armor has been prepared from the thick hide of some creature and"+
      " has been double layered for protection.  The hide has been boiled "+
        " to toughen it, which also makes it stiff and harder to move in. "	);
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
        tell_object(ETO,"%^BOLD%^You carefully fasten the straps of the hide armor.");
        return 1;
}
