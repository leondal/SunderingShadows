// Chernobog (10/27/20)
// Chamber 10, Thief Tutorial Area
// Reward and Return to Beginning

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a solid %^WHITE%^plat%^RESET%^i%^BOLD%^num g%^RESET%^a%^BOLD%^te %^BOLD%^%^BLACK%^affixed in the eastern wall, and a strange series of %^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^c%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^e %^WHITE%^s%^CYAN%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^WHITE%^o%^CYAN%^l%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^ painted on the eastern wall. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	add_item("symbols","%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^c%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^e %^WHITE%^s%^CYAN%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^WHITE%^o%^CYAN%^l%^RESET%^%^CYAN%^s %^BOLD%^%^BLACK%^have been picked out on the western wall, and seem to waver in front of your eyes. You feel a need to %^RESET%^sign%^BOLD%^%^BLACK%^al who you are...%^RESET%^");
	set_exits(([
		"east" : ROOMS"chamber9",
		]));
	set_door("platinum gate",ROOMS"chamber9","east","tutor_2");
	set_door_description("platinum gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of %^WHITE%^plat%^RESET%^i%^BOLD%^num %^BLACK%^surrounding a small keyhole.%^RESET%^");
	set_locked("platinum gate",1,"lock");
	add_lock("platinum gate","tutor_4","lock","This is a simple lock, requiring a specific key to open.");
	
}

void reset(){
	::reset();
	if(!present("clockwork_puppet",TO)) new(OBJ+"clockwork4")->move(TO);
}

void init(){
	::init();
	add_action("make_fun","make");
	add_action("look_fun","look");
	add_action("steal_fun","steal");
}

// Lets the player steal the gloves, unless they already have one.
int steal_fun(string str){
	if((str!="gloves from puppet") && (str!="thief gloves from puppet") && (str!="leather gloves"))
		return 0;
	if(present("thief gloves",TP)){
		tell_object(TP,"You feel as if one is all you'll ever need.");
		return 1;
	}
	else{
		tell_object(TP,"%^BOLD%^%^BLACK%^Slipping a hand carefully into the puppet's pocket, you claim your prize from within.%^RESET%^");
		new(OBJ+"thief_gloves")->move(TP);
		tell_room(ETP,"");
		tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet comes to life, retrieving another pair of %^BOLD%^%^BLACK%^leat%^RESET%^h%^BOLD%^%^BLACK%^er glo%^RESET%^v%^BOLD%^%^BLACK%^es %^BOLD%^%^BLACK%^from a hidden compartment on its torso and casually dropping it into its pocket.%^RESET%^");
		return 1;
	}
}

// Teleports the player back to the entrance when they make a thief sign.
int make_fun(string str){
	if(str!="thief sign")
		return notify_fail("Make what?\n");
	tell_object(TP,"%^BOLD%^%^BLACK%^You make a subtle hand gesture towards the %^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^c%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^e %^WHITE%^s%^CYAN%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^WHITE%^o%^CYAN%^l%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^, which b%^RESET%^r%^BOLD%^ight%^RESET%^e%^BOLD%^%^BLACK%^n with a magical %^RESET%^%^CYAN%^gl%^BOLD%^o%^RESET%^%^CYAN%^w %^BOLD%^%^BLACK%^before teleporting you away...%^RESET%^");
	tell_room(ETP,"%^BOLD%^%^BLACK%^There is a %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^indi%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^%^CYAN%^f%^BOLD%^l%^WHITE%^a%^CYAN%^s%^RESET%^%^CYAN%^h%^BOLD%^%^BLACK%^, and then "+TP->QCN+" %^BOLD%^%^BLACK%^is gone!",TP);
	TP->move(ROOMS"entrance");
	TP->describe_current_room(1);
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
		tell_object(TP,"%^BOLD%^%^RED%^Congratulations. Use what you have learned to amass great wealth for yourself and the guild!");
		}
	return 1;
}

