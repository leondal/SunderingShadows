// Chernobog (10/27/20)
// Chamber 2, Thief Tutorial Area
// Stab

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

int gate;

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a %^RESET%^%^CYAN%^solid iron gate %^BOLD%^%^BLACK%^affixed in the eastern wall, and an open passage leads back to the west. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	add_item("gate","%^BOLD%^%^BLACK%^The gate is %^RESET%^%^CYAN%^wrought iron %^BOLD%^%^BLACK%^and appears to be connected to a series of g%^RESET%^e%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^s and %^RESET%^%^ORANGE%^m%^BOLD%^e%^WHITE%^c%^ORANGE%^h%^RESET%^%^ORANGE%^a%^BOLD%^n%^WHITE%^is%^ORANGE%^m%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^that lead elsewhere, out of sight.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber1",
		]));
	gate=1;
}

void reset(){
	::reset();
	if(!present("clockwork_puppet",TO)) new(OBJ+"clockwork2")->move(TO);
	if(!gate){
		tell_room(ETP,"%^BOLD%^%^BLACK%^You hear a series of gears shifting as the gate slides closed.%^RESET%^");
		remove_exit("east");
		gate=1;
	}
}

void init(){
	::init();
	add_action("stab_fun","stab");
	add_action("look_fun","look");
}

// This lets the player stab the puppet and open the door to advance through.
int stab_fun(string str){
	if(str!="puppet"){
		tell_object(TP,"You should try to <stab puppet>!");
		return 0;
	}
	else{
		tell_room(TO,"%^BOLD%^%^RED%^"+TP->QCN+" %^BOLD%^%^RED%^strikes the puppet solidly in the bullseye!%^RESET%^",TP);
		tell_object(TP,"%^BOLD%^%^RED%^You strike the puppet solidly in the bullseye!%^RESET%^");
		tell_room(ETP,"");
		tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet starts to convulse violently, miming in great detail a horrible and excruciating death! It finally collapses on the ground, only to snap back together on hidden strings and stand back up.%^RESET%^");
		if(gate){
			tell_room(ETP,"");
			tell_room(ETP,"%^RESET%^%^CYAN%^The sound of clockwork and rattling chains echo as the gate slowly opens.%^RESET%^");
			add_exit(ROOMS+"chamber3","east");
			gate=0;
		}
	}
	return 1;
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
		tell_object(TP,"%^BOLD%^%^RED%^Mistakes will happen, and you must be swift to correct them. Stab your opponent in a vital spot to silence it. A thief who hesitates is caught.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^You can %^WHITE%^<stab (target)> %^BLACK%^to strike them in a vulnerable spot for extra damage. This can only be done from outside combat, and you can even stab with your bare hands, but this will lock you in the room for a short time. They have an opporunity to catch you doing this and it is a contest between your %^WHITE%^stealth %^BLACK%^and your target's %^WHITE%^perception%^BLACK%^.)%^RESET%^");}
	return 1;
}

