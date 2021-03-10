//wander code for invasion monsters//

#include <std.h>

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

void heart_beat(){
        string *exits, exitn;
        int i,j;
        ::heart_beat();

        if(count > 20){
                if((mixed *)TO->query_attackers() == ({})){
                        exits = environment(TO)->query_exits();

                        i = sizeof(exits);
                        if(exits && i){
                                j = random(i);
                                exitn = (string)environment(TO)->query_exit(exits[j]);
                                        TO->force_me(exits[j]);
                        }
                }
                count = 0;
        }
        count++;
}
