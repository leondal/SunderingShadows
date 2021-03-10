//wander.c for the mundanoid (must not leave castle)

#include <std.h>

inherit WEAPONLESS;

int counter;

void create(){
	::create();
	call_out("start_wander",2);
	}
	
void start_wander(){
	if(ETO && objectp(ETO))
		environment(TO)->init();
	}
	
int test_heart(){ return 1;}

void heart_beat(){
	string *exits;
	int i,j;
	::heart_beat();
	
	if(counter > 20 && objectp(TO) && objectp(ETO)){
	
		if((mixed *)TO->query_attackers() == ({})){
			exits = environment(TO)->query_exits();
		
			i = sizeof(exits);
			if(exits && i){
				j = random(i);
				if(exits[j] != "gate")
					TO->force_me(exits[j]);
			}
		}
		counter = 0;
	}
	counter++;
}
