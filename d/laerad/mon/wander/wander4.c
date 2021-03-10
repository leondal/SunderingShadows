// being retired by Styx 12/03 to have mobs use the standard set_moving wandering
// i.e. DO NOT USE this method or this file
//wander code for laerad

#include <std.h>
#define WADIR "/d/laerad/wasteland/"

inherit WEAPONLESS;

int count;

void create(){
    ::create();
    call_out("start_wonder",1);
}

void start_wonder(){
    if(objectp(ETO))
        environment(TO)->init();
}

int test_heart(){ return 1;}

void heart_beat(){
    string *exits, exitn;
    int i,j;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;

    if(!objectp(this_object())) return;
    if(!objectp(environment(this_object()))) return;
    if((int)TO->should_I_not_move()) return;
    if(count > 20){
      if((mixed *)TO->query_attackers() == ({})){
        exits = environment(TO)->query_exits();

        i = sizeof(exits);
        if(exits && i){
          j = random(i);
          exitn = (string)environment(TO)->query_exit(exits[j]);
          if(exitn != WADIR+"wportal1")
            TO->force_me(exits[j]);
        }
      }
      count = 0;
    }
    count++;
}
int should_I_not_move() { return sizeof(TO->query_attackers()); }
