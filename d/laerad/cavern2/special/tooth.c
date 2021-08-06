//Coded by Bane//
#include <std.h>
inherit OBJECT;
void save_me(string file){return 1;}
object owner;
void create(){
    ::create();
    set_id(({"tooth","liches tooth"}));
    set_name("tooth");
    set_short("An old tooth");
    set_long(
	"This is an old yellow tooth from a lich."
    );
    set_weight(2);
    set_value(0);
    set_property("no animate",1);
}
/*void init(){
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
}*/
/*void heart_beat(){
    object holder, env;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env) && interactive(env)){
        holder = env->query_name();
        } else {
        return;
    }
    if(holder != owner){
	tell_object(env,"The tooth starts shaking and crumbles into dust.");
        TO->remove();
        } else {
        return;
    }
}*/
