//Jaws.c

#include <std.h>

inherit WEAPON;

void create(){
	::create();
	set_name("jaws");
	set_property("monsterweapon",1);
	set_id(({"teeth","jaws","jaw"}));
	set("short","Behir jaws");
	set("long","The strong hard jaws of the Behir.");
	set_weight(15);
	set_size(3);
   	set("value", 50);
    set_wc(3,4);
    set_type("pierce");
    set_hit((:TO,"hit":));
   }
   
int hit(object targ){
	object behir = environment(TO);
	
	if((string)behir->query_cap_name() == "Behir"){
		if(!behir->query_caught()){
			if(random(20) < 10){
				tell_object(targ,"%^BOLD%^%^RED%^As the Behir sinks it's jaws into you, it quickly"+
				" wraps its 30' tail around you strongly and squeezes!!");
				tell_room(environment(behir),"%^BOLD%^%^RED%^As the Behir sinks its jaws into "+
				targ->query_cap_name()+" it strongly wraps its long tail around "+targ->query_objective()
				+" and squeezes!!",targ);
				behir->set_caught(targ);
				targ->set_paralyzed(10,"%^BOLD%^You are caught in the Behir's grasp!");
				return 5;
			}
		}
	}
 	return 0;
 }
