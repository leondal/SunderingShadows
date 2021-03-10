//wander code for laerad

#include <std.h>

inherit MONSTER;

int count;

void create(){
    ::create();
    call_out("start_wonder",0);
}

void start_wonder(){
    if(objectp(ETO))
        environment(TO)->init();
}

void heart_beat(){
    string *exits, exitn;
    int i,j;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;

    if(count > 0){
      exits = environment(TO)->query_exits();

      i = sizeof(exits);
      if(exits && i){
        j = random(i);
        exitn = (string)environment(TO)->query_exit(exits[j]);
        TO->force_me(exits[j]);
      }
      count = 0;
    }
    count++;
}
