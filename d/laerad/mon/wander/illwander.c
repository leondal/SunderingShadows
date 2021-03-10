//wander code for laerad

#include <std.h>
#define CADIR "/d/laerad/cavern1/"
#define CADIR2 "/d/laerad/cavern2/"

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

        if(count > 20){
                if((mixed *)TO->query_attackers() == ({})){
                      if(objectp(environment(TO)))
                        exits = environment(TO)->query_exits();
                        i = sizeof(exits);
                        if(exits && i){
                                j = random(i);
                                exitn = (string)environment(TO)->query_exit(exits[j]);
				if(exitn != CADIR+"cave" && exitn != CADIR2+"cav01")
                                        TO->force_me(exits[j]);
                        }
                }
                count = 0;
        }
        count++;
}
