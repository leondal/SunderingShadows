// wander.c for ravenloft

#include <std.h>
#define BADIR "/d/ravenloft/town/"

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

        if(count > 20){
                if((mixed *)TO->query_attackers() == ({})){
                       if(objectp(environment(TO)))
                        exits = environment(TO)->query_exits();

                        i = sizeof(exits);
                        if(exits && i){
                                j = random(i);
                                exitn = (string)environment(TO)->query_exit(exits[j]);
				if(exitn != BADIR+"bar03" && exitn != BADIR+"bar22")
                                        TO->force_me(exits[j]);
                        }
                }
                count = 0;
        }
        count++;
}
