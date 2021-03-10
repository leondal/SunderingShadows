//wonder.c for tharis people

#include <std.h>
#define THDIR "/d/tharis/road/"

inherit MONSTER;

int count;

void create(){
	::create();
	call_out("start_wonder",1);
	}
	
void start_wonder(){
	environment(TO)->init();
	}
	
void heart_beat(){
	string *exits;
	int i,j;
	::heart_beat();
	
	if(count > 10){
		if((mixed *)TO->query_attackers() == ({})){
			exits = environment(TO)->query_exits();
		
			i = sizeof(exits);
			if(exits && i){
				j = random(i);
				if(exits[j] != "estair" && exits[j] != "wstair" && (string)environment(TO)->query_exit() != THDIR+"road9" && (string)environment(TO)->query_exit() != THDIR+"wroad1" && (string)environment(TO)->query_exit() != THDIR+"eroad1" )
					TO->force_me(exits[j]);
			}
		}
		count = 0;
	}
	count++;
}
