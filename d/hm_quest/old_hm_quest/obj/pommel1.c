#include <std.h>
inherit OBJECT;
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}
void create() {
    ::create();
    set_name("pommel");
    set_id(({"pommel1","hm_quest_skull","skull pommel","pommel"}));
    set_short("%^RESET%^%^BLUE%^Skull pommel%^RESET%^");
    set_long(
	"%^BLUE%^This strange glowing pommel from a sword of some kind is "
	"designed in the likeness of a small skull. The pommel is warm to the "
	"touch and you wonder where the rest of the sword could be."
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
	    "The skull pommel vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}