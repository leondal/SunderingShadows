//wander code for laerad

#include <std.h>
#define PLDIR "/d/laerad/plains/"
#define SYSDIR "/d/laerad/parnelli/systyquah/"

inherit MONSTER;

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

        if(count > 20){
                if((mixed *)TO->query_attackers() == ({})){
                       if(objectp(environment(TO)))
                        exits = environment(TO)->query_exits();

                        i = sizeof(exits);
                        if(exits && i){
                                j = random(i);
                                exitn = (string)environment(TO)->query_exit(exits[j]);
				if(exitn != PLDIR+"plains28" && exitn != PLDIR+"plains41" && exitn != PLDIR+"plains54" && exitn != PLDIR+"plains65" && exitn != PLDIR+"plains78" && exitn != PLDIR+"plains77" && exitn != SYSDIR+"sys021" )
                                        TO->force_me(exits[j]);
                        }
                }
                count = 0;
        }
        count++;
}
