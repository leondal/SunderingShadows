// Chernobog (10/27/20)
// Chamber 1, Thief Tutorial Area
// Hide_in_shadows, Sneak

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^A passage carved from this chamber leads off into the east, and a %^RESET%^%^ORANGE%^rope ladder %^BOLD%^%^BLACK%^leads up through a hole in the ceiling of the cavern. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	set_exits(([
		"east" : ROOMS"chamber2",
		"up" : ROOMS"entrance",
		]));
}

void reset(){
	::reset();
	if(!present("clockwork_puppet",TO)) new(OBJ+"clockwork1")->move(TO);
}

void init(){
	::init();
	add_action("east_fun","east");
	add_action("sneak_fun","sneak");
	add_action("look_fun","look");
}

// This prevents the player from moving east unless they sneak.
int east_fun(){
	tell_object(TP,"%^BOLD%^%^RED%^The puppet comes to life, twitching and whirling in a flurry of limbs to blocks your path! You need to be %^MAGENTA%^sneak%^RED%^ier...%^RESET%^");
	tell_room(TO,"%^BOLD%^%^RED%^The puppet comes to life, twitching and whirling in a flurry of limbs to leap in front of "+TP->QCN+"%^BOLD%^%^RED%^, blocking the way!%^RESET%^",TP);
	return 1;
}

// Just a message to clue the player that they successfully figured out what to do.
int sneak_fun(string str){
	if((str!="east") && (str!="e"))
		return 0;
	else
		tell_object(TP,"%^BOLD%^%^BLACK%^You quietly sneak past the watchful puppet...%^RESET%^");
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
		tell_object(TP,"%^BOLD%^%^RED%^The most basic rule of the cutpurse is to be silent. A noisy thief is a dead thief.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^%^(OOC Info: %^BOLD%^%^BLACK%^Stealth can be achieved by %^WHITE%^%^BOLD%^<hide_in_shadows> %^BLACK%^to become hidden within the room, and %^WHITE%^%^BOLD%^<sneak (direction)> %^BLACK%^to move quietly between rooms. You can be spotted by others, and it is a contest between your %^WHITE%^%^BOLD%^stealth %^BLACK%^and others' %^WHITE%^%^BOLD%^perception%^BLACK%^.)%^RESET%^");}
	return 1;
}

