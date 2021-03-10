#include <std.h>
inherit OBJECT;
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}
void create() {
    ::create();
    set_name("emerald");
    set_id(({"gem2","hm_quest_emerald","emerald"}));
    set_short("%^RESET%^%^GREEN%^An emerald%^RESET%^");
    set_long(
	"%^GREEN%^A large green emerald gem that appears to be worth a bit "
	"of money. The emerald seems to glow with a slight magical light."
	"%^RESET%^"
    );
    set_weight(1);
    set_value(500);
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
	    "The emerald vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}