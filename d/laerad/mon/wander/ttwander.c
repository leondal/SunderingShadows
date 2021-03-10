// Used specifically for the invasions into Asgard
//wander code for laerad

#include <std.h>
#define ASDIR "/d/laerad/parnelli/asgard/"
inherit WEAPONLESS;

int count;
int uses;

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
    if(!objectp(TO) || !objectp(ETO)) return;

	if(uses > 80){
	if(count > 10){
                if((mixed *)TO->query_attackers() == ({})){
                      if(!objectp(environment(TO))) return;
                        exits = environment(TO)->query_exits();

                        i = sizeof(exits);
                        if(exits && i){
                                j = random(i);
                                exitn = (string)environment(TO)->query_exit(exits[j]);
				if(exitn != ASDIR+"as59" && exitn != ASDIR+"as01")
                                        TO->force_me(exits[j]);
                        }
                }
                count = 0;
        }
        count++;
	}
	uses++;
}
