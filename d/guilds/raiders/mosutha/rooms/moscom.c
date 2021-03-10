//Coded by Diego//
//add food and drink//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
    	::create();
   	set_short("Antechamber");
    	set_long(
    		"The antechamber is dimly lit from what may be hundreds or even thousands "+
    		"of minute points of light in the ceiling strongly resembling a view of a "+
    		"clear night sky.  Looking even closer you now see that you recognize "+
		"constellations you have seen many times while looking up into the sky "+
		"at night.  In the western part of the room you can see a hole in the "+
		"ceiling leading upward.\n"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The room smells fresh and very clean.");
    	set_listen("default","You hear traces of past present and future conversations.");
     	set_exits(([
   		"north" : MROOMS+"moslib",
   		"east" : MROOMS+"mossmok"
 	]));

    	set_door("green door",MROOMS+"moslib","north","guild earring");
    	set_locked("green door",1,"lock");
     		(MROOMS+"moslib")->set_locked("green door",1,"lock");
    	set_door_description("green door","The door is a normal "+
    		"looking door made from oak and painted %^GREEN%^green %^RESET%^with a "+
    		"simple lock.");
    	lock_difficulty("green door",10,"lock");
   	set_string("green door","open","You open the door noiselessly "+
   		"into a room full books, tomes, and parchments.\n");

    	set_door("black door",MROOMS+"mossmok","east","guild earring");
    	set_locked("black door",1,"lock");
     		(MROOMS+"mossmok")->set_locked("black door",1,"lock");
    	set_door_description("black door","The door is a normal "+
    		"looking door made from oak and painted %^BOLD%^%^BLACK%^black %^RESET%^with "+
    		"a simple lock.");
    	lock_difficulty("black door",10,"lock");
   	set_string("black door","open","You open the door noiselessly "+
   		"and the smell of tobacco assualts you.\n");


    	set_climb_exits((["climb":({MROOMS+"mosent",20,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");

	set_trap_functions(({"green door"}),({"blow_me"}),({"pick"}));

	restore_room();
}
void init() {
  	::init();
   	add_action("reset_em","reset");
 	add_action("open_em","open");
  	add_action("push_em","push");
}
int open_em(string str) {
  	if(!str) {
        	tell_object(TP,"Open what?");
        	return 1;
    	}
  	if(str == "green door"){
		tell_room(ETO,""+TPQCN+" tries to open the green door and fails.\n",TP);
		tell_object(TP,"You try to open the green door and fail.\n");
     		return 1;
     }
}
int push_em(string str) {
  	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
    	}
  	if(str == "green door"){
		tell_room(ETO,""+TPQCN+" pushes open the green door.\n",TP);
		tell_object(TP,"You push open the green door and see the next room.\n");
    		set_door_description("green door","The door is a normal "+
    			"looking door made from oak and painted %^GREEN%^green %^RESET%^with a "+
    			"simple lock and a %^BOLD%^%^RED%^red X %^RESET%^in the middle.");
    		(MROOMS+"moslib")->set_door_description("green door","The "+
			"door is a normal looking door made from oak and painted %^GREEN%^green "+
			"%^RESET%^with a simple lock.");
    	    	set_open("green door",1);
     			(MROOMS+"moslib")->set_open("green door",1);
    		save_room_shallow();
    			(MROOMS+"moslib")->save_room_shallow();
     		return 1;
     }
}
int reset_em(string str) {
  	if(!str) {
        	tell_object(TP,"Reset what?");
        	return 1;
    	}
  	if(str == "green door"){
		tell_room(ETO,""+TPQCN+" pushes on the door again making it flip around.\n",TP);
		tell_object(TP,"You push on the door and the %^BOLD%^%^RED%^red X "+
			"%^RESET%^flips around to the other side resetting the door.\n");
    		set_door_description("green door","The door is a normal looking door made "+
    			"from oak and painted %^GREEN%^green %^RESET%^with a simple lock.");
    		(MROOMS+"moslib")->set_door_description("green door","The door is a normal "+
			"looking door made from oak and painted %^GREEN%^green %^RESET%^with a "+
			"simple lock and a %^BOLD%^%^RED%^red X %^RESET%^in the middle.");
    	    	set_open("green door",0);
    			(MROOMS+"moslib")->set_open("green door",0);
     		save_room_shallow();
    			(MROOMS+"moslib")->save_room_shallow();
    		return 1;
     }
}
int blow_me(string str){
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^YELLOW%^You hear a crackling sound that builds to a "+
		"very loud crescendo.\n");
	tell_room(TO,"%^BOLD%^%^RED%^A bolt of %^YELLOW%^lightning%^RED%^ blasts out of the "+
		"door into "+TPQCN+"!%^RESET%^\n");
	tell_object(TP,"%^BOLD%^%^RED%^Your hair stands on end as a bolt of "+
		"%^YELLOW%^lightning%^RED%^ blasts you in the chest!%^RESET%^\n");
	tell_room(TO,"%^BOLD%^%^YELLOW%^The bolt flies into "+TPQCN+" and explodes in a loud "+
		"%^BOLD%^%^RED%^F%^BLUE%^L%^RED%^A%^BLUE%^S%^RED%^H%^YELLOW%^!\n",TP);
	tell_object(TP,"%^BOLD%^%^YELLOW%^The bolt explodes into your great pain and a loud "+
		"%^BOLD%^%^RED%^F%^BLUE%^L%^RED%^A%^BLUE%^S%^RED%^H%^YELLOW%^!\n");
	TP->do_damage("torso",roll_dice(30,10));
	TP->add_attacker(TO);
	TP->continue_attack();
      toggle_trap("green door","blow_me","lock"); //added by Circe to allow traps to be disabled
	return 0;
}
