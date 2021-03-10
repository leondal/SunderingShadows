//wfwander.c for for the forest type people
//overloaded move_around per Garrett's suggestion to get rid of one of the
//layers of calling heart_beat & added checks for valid object & ETO-Styx 5/11/02

#include <std.h>

inherit WEAPONLESS;

int count;

void create(){
	::create();
	set_moving(1);
	set_speed(80);
//	call_out("start_wonder",1);
}
	
void start_wonder(){
	if(objectp(environment(TO)))
		environment(TO)->init();
}
	
int test_heart(){ return 1;}

/* Using an overload of move_around instead now.
void heart_beat(){
	string *exits;
	int i,j;
	::heart_beat();
	
	if(count > 30 && objectp(TO)){
		if((mixed *)TO->query_attackers() == ({})){
                 if(objectp(ETO))
			exits = environment(TO)->query_exits();
		
			i = sizeof(exits);
			if(exits && i){
				j = random(i);
				if(exits[j] != "enter" && exits[j] != "out" && exits[j] != "up" )
                                        force_me(exits[j]);
			}
		}
		count = 0;
	}
	count++;
}
*/

void move_around() {
//   ::move_around();   don't think I need this but might
   string *exits;
   string exit;
   int which; 

   if(!objectp(TO)) return;
   if(!objectp(ETO) || !objectp(TO)) return;
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
//        if(exit != "temple")
           command(exit);
      }
   }
   moving=0;
}
