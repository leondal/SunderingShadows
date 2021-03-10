// Chernobog (10/27/20)
// Chamber 9, Thief Tutorial Area
// Everything at once.

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

int puppet;
int trapped;

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a solid %^WHITE%^plat%^RESET%^i%^BOLD%^num g%^RESET%^a%^BOLD%^te %^BOLD%^%^BLACK%^affixed in the western wall. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber10",
		]));
	set_door("platinum gate",ROOMS"chamber10","west","tutor_2");
	set_door_description("platinum gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of %^WHITE%^plat%^RESET%^i%^BOLD%^num %^BLACK%^surrounding a small keyhole.%^RESET%^");
	set_locked("platinum gate",1,"lock");
	add_lock("platinum gate","tutor_4","lock","This is a simple lock, requiring a specific key to open.");
	puppet=1;
	trapped=1;
}

void reset(){
	::reset();
	if(!present("clockwork_puppet",TO)) new(OBJ+"clockwork2")->move(TO);
	if(!present("thief toolx",TO)) new(OBJ+"thief_tools")->move(TO);
	if(!puppet){
		tell_room(ETP,"The puppet snaps to attention, taking a position near the gate.");
		puppet=1;
	}
	if(!trapped){
		tell_room(ETP,"You hear a faint whirring mechanism from the gate, followed by a faint CLICK.");
		trapped=1;
	}
}

void init(){
	::init();
	add_action("stab_fun","stab");
	add_action("look_fun","look");
	add_action("pick_fun","pick");
	add_action("hide_fun","hide");
	add_action("get_fun","get");
	add_action("trap_fun","trap");
}

// This lets the player stab the guardian puppet, removing the first barrier to exiting.
int stab_fun(string str){
	if(str!="puppet"){
		tell_object(TP,"You should try to <stab puppet>!");
		return 0;
	}
	else{
		if(puppet){
			tell_room(TO,"%^BOLD%^%^RED%^"+TP->QCN+" %^BOLD%^%^RED%^strikes the puppet solidly in the bullseye!%^RESET%^",TP);
			tell_object(TP,"%^BOLD%^%^RED%^You strike the puppet solidly in the bullseye!%^RESET%^");
			tell_room(ETP,"");
			tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet starts to convulse violently, miming in great detail a horrible and excruciating death! It finally collapses on the ground off to the side of the room.%^RESET%^");
			puppet=0;
		}
		else{
			tell_object(TP,"%^BOLD%^%^RED%^Stop, it's already dead!%^RESET%^");
			return 1;
		}
	}
	return 1;
}

// Sets up the detection and disarming of the trap, removing the second barrier to exiting.
int trap_fun(string str){
	switch(str){
		case "find on platinum gate" :
			tell_object(TP,"%^BOLD%^%^BLACK%^There is indeed a mechanism in place, set to stab at anyone who attempts to unlock the gate.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^seems to be examining the lock on the platinum gate.%^RESET%^",TP);
			return 1;
			break;
		case "remove on platinum gate" :
			tell_object(TP,"%^BOLD%^%^BLACK%^You manage to disconnect the trigger, disarming the trap.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^seems to be fiddling with something on the platinum gate.%^RESET%^",TP);
			trapped=0;
			return 1;
			break;
		case "disarm on platinum gate" :
			tell_object(TP,"%^BOLD%^%^BLACK%^You manage to disconnect the trigger, disarming the trap.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^seems to be fiddling with something on the platinum gate.%^RESET%^",TP);
			trapped=0;
			return 1;
			break;
		default :
			tell_object(TP,"Perhaps you should try to <trap find on platinum gate>?");
			return 0;
	}
}


// This helps the player with syntax, and also prevents the picking of the lock if the puppet or trap are still present.
int pick_fun(string str){
	if(str!="lock on platinum gate"){
		tell_object(TP,"You could try to <pick lock on platinum gate>?");
		return 0;
	}
	if(puppet){
		tell_object(TP,"%^BOLD%^%^RED%^The puppet jumps up, grabbing ahold of you and spinning you away from the gate!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^RED%^The puppet jumps up, grabbing ahold of "+TP->QCN+" %^BOLD%^%^RED%^and spinning them away from the gate!%^RESET%^",TP);
		return 1;
	}
	if(trapped){
		tell_object(TP,"%^BOLD%^%^RED%^As you start to pick the lock, you hear a click and a thin needle lashes out and stabs your hand!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^RED%^As "+TP->QCN+" %^BOLD%^%^RED%^fiddles with the lock on the gate, they let out a loud curse and slap at their hand!%^RESET%^",TP);
		return 1;
	}
	return 0;
}

// This prevents the player from taking more than one set of picks.
int get_fun(string str){
	if((str!="tools") && (str!="thief tools") && (str!="lock picks") && (str!="picks") && (str!="locksmith tools"))
		return 0;
	else{
		if(puppet){
			tell_object(TP,"%^BOLD%^%^BLACK%^The puppet whirls to life, slapping your hand away from the lock picks!%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet whirls to life, slapping at "+TP->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^",TP);
			return 1;
		}
		if(!present("thief toolx",TP)){
			tell_object(TP,"%^BOLD%^%^BLACK%^As you claim the small set of tools, a mechanical arm sprouts from a hidden compartment in the floor, retrieving a new set of tools from yet another hidden compartment and placing it carefully on the floor.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^As "+TP->QCN+" %^BOLD%^%^BLACK%^takes the tool set from the ground, a mechanical arm sprouts from a hidden compartment in the floor, retrieving a new set of tools from yet another hidden compartment and placing it carefully on the floor.%^RESET%^",TP);
			new(OBJ+"thief_tools")->move(TP);
			return 1;
		}
		else{
			tell_object(TP,"You feel as if one set is enough.");
			return 1;
		}
	}
}

// Keeps people from getting infinite tools.
int hide_fun(string str){
	if((str!="thief tools on me") && (str!="tools on me") && (str!="lock picks") && (str!="picks") && (str!="locksmith tools"))
		return 0;
	else{
		if(!present("thief toolx",TP)){
			tell_object(TP,"%^BOLD%^%^BLACK%^As you claim the small set of tools, a mechanical arm sprouts from a hidden compartment in the floor, retrieving a new set of tools from yet another hidden compartment and placing it carefully on the floor.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^As "+TP->QCN+" %^BOLD%^%^BLACK%^takes the tool set from the ground, a mechanical arm sprouts from a hidden compartment in the floor, retrieving a new set of tools from yet another hidden compartment and placing it carefully on the floor.%^RESET%^",TP);
			new(OBJ+"thief_tools")->move(TP);
			return 1;
		}
		else{
			tell_object(TP,"You feel as if one is all you'll ever need.");
			return 1;
		}
	}
}

// The IC and OOC information, only viewable by thieves.
int look_fun(string str){
	if((str!="scratches") && (str!="at scratches"))
		return 0;
	if((!TP->is_class("thief")) && (!TP->is_class("bard"))){
		tell_object(TP,"%^RESET%^%^RED%^You have no idea what these markings are about.%^RESET%^");
		tell_room(ETP, "%^RESET%^%^RED%^"+TP->QCN+" looks at the strange scratches with a confused expression.",TP);
	}
	else{
		tell_object(TP,"%^RESET%^%^RED%^The scratches are a form of thieves' cant. You work out the meaning to be:%^RESET%^");
		tell_object(TP,"%^BOLD%^%^RED%^Combine all you have learned. Slide past all that stands in your way and claim your prize.%^RESET%^");
	}
	return 1;
}