#include <std.h>

inherit OBJECT;

object tp, env;

set_tp(object x) { tp = x; }

set_env(object x){env = x;}

void execute_attack(){

     if (!objectp(TO) || !objectp(tp) || !objectp(env) ) return remove() ;
	if(env == environment(tp)){
		tp->run_away();
              tp->remove_property("fled");
              tp->set_property("fled",time()+180);
            if (tp->isPkill()) {
              tp->set_property("PKfled",time()+180);
             tp->set_property("PKfled_delay",180);
             } else {
              tp->set_property("PKfled",time()+15);
             tp->set_property("PKfled_delay",15);
              }
	}
	remove();
}
