#include <std.h>
inherit OBJECT;
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}
void create() {
    ::create();
    set_name("ruby");
    set_id(({"gem1","hm_quest_ruby","ruby"}));
    set_short("%^RESET%^%^RED%^A ruby%^RESET%^");
    set_long(
	"%^RED%^A large red ruby gem that appears to be worth a bit "
	"of money. The ruby seems to glow with a slight magical light."
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
	    "The ruby vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}
