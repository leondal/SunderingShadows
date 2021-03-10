//overloaded move_around per Garrett's suggestion to get rid of one of the
//layers of calling heart_beat. 
//testing it with scavengers and we_archers for now. - Styx 12/23/01

//fwander.c for for the forest type people

#include <std.h>

inherit MONSTER;


void create(){
	::create();
	set_moving(1);
	set_speed(100);
//	call_out("start_wonder",2);
	}
	
void start_wonder(){
	if(ETO && objectp(ETO))
		environment(TO)->init();
	}
	
int test_heart(){ return 1;}

void heart_beat() { ::heart_beat(); }

/*  Trying Garrett's idea to overwrite the std. wander instead of using hb
Styx 12/23/01

void heart_beat(){
	string *exits;
	int i,j;
   int counter;
	
        if(!objectp(TO)) return;
	::heart_beat();
//added check for objectp here to see if it fixes debug.log errors - Styx 12/23	
        if(!objectp(TO)) return;
	if(counter > 30 && objectp(TO) && objectp(ETO)){
	
		if((mixed *)TO->query_attackers() == ({})){
			exits = environment(TO)->query_exits();
		
			i = sizeof(exits);
			if(exits && i){
				j = random(i);
				if(exits[j] != "exit" && exits[j] != "out" && exits[j] != "up")
                           {
                                if(!objectp(TO)) return;
                                        force_me(exits[j]);
                                      }
			}
		}
		counter = 0;
	}
	counter++;
}
*/

void move_around() {
//   ::move_around();   don't think I need this but might
   string *exits;
   string exit;
   int which; 

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(ETO)
        exits = (string*)ETO->query_obvious_exits();
   else exits = 0;
   if(sizeof(exits)) {
      exit = exits[random(sizeof(exits))];
//added to std move_around for this area
      if(exit != "exit" && exit != "out" && exit != "up") {
        (ETO->query_exit(exit))->init();
        if(exit != "temple")
           command(exit);
      }
   }
   moving=0;
}
