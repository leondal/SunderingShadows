#include <std.h>
inherit VAULT;

void create(){
  	::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  	set_name("crypt16");
  	set_property("light", 0);
  	set_property("indoors", 1);
  	set_short("A Dark Room Far Beneath the Crypt");
  	set_long("%^BOLD%^%^BLACK%^Well there are only two directions to go here. Either "+
  		"back the way you came or down. Which shall you choose? Hmmm.%^RESET%^\n");
  	set_exits( ([
     		"south" : "/d/koenig/town/crypt14.c",
     		"down" : "/d/koenig/town/crypt9.c"
	]) );
  	set_trap_functions( ({"down"}),({"dart_shoot"}),({"down"}) );
}

void dart_shoot() {
	int i;
  	// say one dart is shot in the movement.
  	// say that the trap is set up with a THACO of 12.
  	int AC, damage, roll;
  	tell_object(TP,"%^BOLD%^%^BLACK%^A section of floor sinks a little as you step on it.");
  	tell_object(TP,"%^BOLD%^%^BLACK%^You realize a little late that you have set off a trap!");
  	tell_object(TP,"%^RESET%^%^CYAN%^You hear the %^RESET%^wiz%^CYAN%^ of darts being shot at you!");
  	TP->force_me("emote dodges suddenly to the left and right.");
  	tell_room(ETP,"%^BOLD%^%^BLACK%^You hear a low ominous rumbling...",TP);
  	tell_room(ETP,"%^BOLD%^%^WHITE%^ZZZIIIIPPP...PHT...PHT...PHT...");
  	tell_room(ETP,"%^CYAN%^Darts shoot from small holes in the walls!");
  	tell_room(ETP,"%^BOLD%^%^CYAN%^You realize that "+TPQCN+" has set off some sort of trap!", TP);
    	AC = TP->query_ac();
	for(i=0;i<5;i++){
    		roll = random(20);
    		if(roll > 10-AC) {
      		tell_object(TP,"%^BOLD%^%^RED%^You are hit!%^RESET%^");
      		tell_room(ETP,"You see "+TPQCN+" get hit by a dart!", TP);
    			damage = random(4);
        		TP->do_damage("torso",(random(10)));
			TP->add_attacker(TO);
			TP->continue_attack();
     		}
  	}
}
