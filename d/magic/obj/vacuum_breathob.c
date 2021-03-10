
#include <std.h>

inherit OBJECT;

int time, maxtime;

void destMe();

void create(){
    ::create();
    set_short("");
    set_long("");
    set_name("magic vacuum ob");
    set_id( ({"vacuum_breath_ob", "gvacuumob"}) );
    set_weight(0);
    set_heart_beat(1);
    set_property("no animate", 1);
}

void heart_beat(){
  if(!objectp(TO)) return;
    if(time > maxtime)
      destMe();
    time++;
}

void set_maxtime(int x){
    maxtime = x;
}

void destMe(){
    if(objectp(query_property("spell"))){
      query_property("spell")->dest_effect();
    } else {
      TO->remove();
    }
}

int save_me(string file){
    return 1;
}
