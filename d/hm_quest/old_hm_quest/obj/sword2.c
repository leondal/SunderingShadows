#include <std.h>
inherit OBJECT;
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}
void create() {
    ::create();
    set_name("sword");
    set_id(({"sword2","hm_quest_ages","sword of the ages","sword"}));
    set_short("%^RESET%^%^BLUE%^Sword of the Ages %^RED%^(%^BLUE%^sheathed%^RED%^)%^RESET%^");
    set_long(
	"%^RESET%^%^BLUE%^This superb weapon %^YELLOW%^blazes%^RESET%^%^BLUE%^ "
	"with an %^MAGENTA%^inner light%^BLUE%^ unlike any "
	"weapon you have ever seen. The scabbard it is sheathed in is covered "
	"with %^RED%^blazing runes%^BLUE%^. It must be meant for only an "
	"incredibly powerful being to ever wield as no matter how hard you "
   "try, you cannot remove it from its scabbard."
	"%^RESET%^"
    );
    set_weight(17);
    set_value(0);
    set_heart_beat(1);
}
void heart_beat() {
    object holder,env;
    if(!objectp(ETO)) return;
    env = ETO;
    if(interactive(env) ) {
        holder = env->query_true_name();
    } else {
	return;
    }
    if(holder != owner) {
	tell_object(env,
	    "The Sword of the Ages vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}
