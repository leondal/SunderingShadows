#include <std.h>
inherit OBJECT;
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}
void create() {
    ::create();
    set_name("hilt");
    set_id(({"hilt1","hm_quest_steel","steel hilt","hilt"}));
    set_short("%^RESET%^%^CYAN%^Steel hilt%^RESET%^");
    set_long(
	"%^CYAN%^This steel hilt is all that remains of this piece of a long "
	"lost sword of obvious magical nature. The hilt still glows with a "
    "wonderous aura despite being separated from the rest of the sword. "
	"  Stranger so, there is a depression in the center of the hilt that "
    "appears to have held a jewel at one time, but has long since been pried "
	"out."
	"%^RESET%^"
    );
    set_weight(2);
    set_value(100);
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
	    "The steel hilt vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}
