// Chernobog (10/27/20)
// Chamber 6, Thief Tutorial Area
// Traps

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

int trapped;

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^An open passage leads to the west, and there is a large %^RESET%^%^BLUE%^crack %^BOLD%^%^BLACK%^in the ceiling near the eastern wall. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	add_item("crack","%^BOLD%^%^BLACK%^There is a sizeable crack in the ceiling, just large enough that you could %^RESET%^climb %^BOLD%^%^BLACK%^the wall and squeeze through.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber7",
		]));
	set_climb_exits(([
		"climb" : ({ROOMS"chamber5",1,6,100}),
		]));
	trapped=1;
}

void reset(){
	::reset();
	trapped=1;
}

void init(){
	::init();
	add_action("look_fun","look");
	add_action("west_fun","west");
	add_action("sneak_fun","sneak");
	add_action("trap_fun","trap");
}

// Triggers the trap if the player goes west.
int west_fun(){
	if(!trapped)
		return 0;
	else{
		tell_object(TP,"%^BOLD%^%^RED%^As you step forward, a plate in the floor springs up and sends you flying back into the center of the room!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^RED%^As "+TP->QCN+" %^BOLD%^%^RED%^approaches the passage, a plate in the floor springs up and knocks them back!%^RESET%^",TP);
		return 1;
	}
}

// Triggers the trap if the player tries to sneak west.
int sneak_fun(){
	if(!trapped)
		return 0;
	else{
		tell_object(TP,"%^BOLD%^%^RED%^As you step forward, a plate in the floor springs up and sends you flying back into the center of the room!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^RED%^As "+TP->QCN+" %^BOLD%^%^RED%^approaches the passage, a plate in the floor springs up and knocks them back!%^RESET%^",TP);
		return 1;
	}
}

// Sets up the detection and disarming of the trap.
int trap_fun(string str){
	switch(str){
		case "find on west" :
			tell_object(TP,"%^BOLD%^%^BLACK%^There is indeed a pressure plate in the floor, set to spring whenever someone tries to leave through that passage.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^seems to be examining the floor near the western passage.%^RESET%^",TP);
			return 1;
			break;
		case "remove on west" :
			tell_object(TP,"%^BOLD%^%^BLACK%^You manage to disconnect the trigger, disarming the trap.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^seems to be fiddling with something near the western passage.%^RESET%^",TP);
			trapped=0;
			return 1;
			break;
		case "disarm on west" :
			tell_object(TP,"%^BOLD%^%^BLACK%^You manage to disconnect the trigger, disarming the trap.%^RESET%^");
			tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^seems to be fiddling with something near the western passage.%^RESET%^",TP);
			trapped=0;
			return 1;
			break;
		default :
			tell_object(TP,"Perhaps you should try to <trap find on west>?");
			return 0;
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
		tell_object(TP,"%^BOLD%^%^RED%^Many marks will try to stop a thief with contrivance and mechanical hazards. A clumsy thief is a dead thief.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^You can %^WHITE%^<trap find on (object/exit)> %^BLACK%^to search for traps, and then %^WHITE%^<trap disarm on (object/exit)> %^BLACK%^to neutralize the trap. Alternatively, you can attempt to %^WHITE%^<trap recover on (object/exit)> %^BLACK%^to not only disarm but claim the trap as your own to use later, but with a steeper difficulty. This skill is based on your %^WHITE%^dungeoneering%^BLACK%^, and at higher levels of the skill you can %^WHITE%^<trap detect on> %^BLACK%^to automatically look for trapped objects and exits, which will appear in %^RED%^red%^BLACK%^.%^RESET%^");
		}
	return 1;
}

