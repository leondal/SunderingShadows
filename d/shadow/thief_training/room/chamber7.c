// Chernobog (10/27/20)
// Chamber 7, Thief Tutorial Area
// Picking Locks

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^An open passage leads back to the east, and there is a solid %^YELLOW%^go%^WHITE%^l%^YELLOW%^d ga%^WHITE%^t%^YELLOW%^e %^BLACK%^affixed to the western wall. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber8",
		"east" : ROOMS"chamber6",
		]));
	set_door("gold gate",ROOMS"chamber8","west","tutor_2");
	set_door_description("gold gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of %^YELLOW%^go%^WHITE%^l%^YELLOW%^d %^BLACK%^surrounding a small keyhole.%^RESET%^");
	set_locked("gold gate",1,"lock");
	add_lock("gold gate","tutor_3","lock","This is a simple lock, requiring a specific key to open.");
}

void reset(){
	::reset();
	if(!present("thief toolx",TO)) new(OBJ+"thief_tools")->move(TO);
}

void init(){
	::init();
	add_action("get_fun","get");
	add_action("look_fun","look");
	add_action("hide_fun","hide");
	add_action("pick_fun","pick");
}

// This prevents the player from taking more than one set of picks.
int get_fun(string str){
	if((str!="tools") && (str!="thief tools") && (str!="lock picks") && (str!="picks") && (str!="locksmith tools"))
		return 0;
	else{
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

// This helps the player with syntax.
int pick_fun(string str){
	if(str!="lock on gold gate"){
		tell_object(TP,"You could try to <pick lock on gold gate>?");
		return 0;
	}
	else return 0;
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
		tell_object(TP,"%^BOLD%^%^RED%^Locks will be a common challenge in your pursuit of wealth. Learn their workings, in doors and chests and elsewhere. A crafty thief is a rich thief.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^You can %^WHITE%^<pick lock on (door)> %^BLACK%^while holding a set of thieves tools to pick the lock and gain entry. This is based on your %^WHITE%^dungeoneering %^BLACK%^skill, and failure can damage or even break your tools. Items such as chests can be picked with %^WHITE%^<pick (object)>%^BLACK%^, as they don't have a lock to target. And also be wary, because locks can also be trapped.%^RESET%^");
	}
	return 1;
}

