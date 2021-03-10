//.
//.

#include <std.h>
inherit OBJECT;


object env, tp;
string dir;
int delay;

void create()
{
    ::create();
}

set_env(object e) { env = e;}
set_tp(object x){ tp = x; }
int set_delay(int x) { delay = x; }
int query_delay() { return delay; }
set_dir(string d) { dir = d; }
void execute_attack()
{
    if (!objectp(tp)) 
    {
        remove();
        return;
    }
    if (!objectp(env)) {
          remove();
        return;
    }
    if( environment(tp) != env){
        remove();
        return;
    }
    tp->set_property("true moving",dir);
    tp->force_me(dir);
    tp->remove_property("true moving");
    tp->set_property("fled",time()+180);
    if (tp->isPkill()) 
    {
        tp->set_property("PKfled",time()+180);
        tp->set_property("PKfled_delay",180);
    } 
    else 
    {
        tp->set_property("PKfled",time()+15);
        tp->set_property("PKfled_delay",15);
    }
    tp->remove_property("my_exiteffect");
    tp->remove_property("running_away_time");
    remove();
}
int clean_up() 
{ 
    if(!objectp(tp) || !objectp(env))
    {
        remove();
        return 1;
    }
    if(environment(tp) != env)
    {
        remove();
        return 1;
    }
    if(sizeof(tp->query_attackers()))
    {
        remove();
        return 1;
    }
    return 1;
}