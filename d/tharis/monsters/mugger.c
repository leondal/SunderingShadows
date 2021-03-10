//mugger.c

#include <std.h>

inherit MONSTER;

string time;

void create(){
	::create();
	
	time = "daemon/events_d"->query_time_of_day(); 
	set_name("mugger");
	set_id(({"mugger","street thug","thug"}));
	if(time == "day"){
		set("short","Street thug");
		set_hd(10,5);
		set_hp(90);
		set_exp(1000);
	}
	else{
		set("short","mugger");
		set_hd(13,6);
		set_hp(110);
		set_exp(1200);
	}
	set_class("thief");
	set_gender("male");
	set_race("half orc");
	set_body_type("human");
	set_wielding_limbs(({"right hand","left hand"}));	
	new("/d/common/obj/weapon/longsword")->move(TO);
	command("wield long sword");
	set_overall_ac(4);
	set("aggressive","do_stuff");	
	set_thief_skill("move silently",70);
	set_thief_skill("hide in shadows",70);
	add_search_path("cmds/thief");
	set_invis();
}

void do_stuff(){
	if(interactive(TP) && !TP->query_invis()){
		set("aggressive",17);
		call_out("attack",5,TP);
	}
}	

void attack(object targ){
        if(!objectp(targ) && !objectp(TO))  return;
        if(targ->query_invis())   return;
	command("stab "+targ->query_name());
	set_invis();
}
