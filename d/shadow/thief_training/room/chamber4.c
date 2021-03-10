// Chernobog (10/27/20)
// Chamber 4, Thief Tutorial Area
// Hide, Hide on me

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a solid %^RESET%^%^ORANGE%^copper gate %^BOLD%^%^BLACK%^affixed in the eastern wall, and a s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^g%^BOLD%^a%^RESET%^t%^BOLD%^%^BLACK%^e %^BLACK%^placed at the west. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber3",
		"east" : ROOMS"chamber5",
		]));
	set_door("silver gate",ROOMS"chamber5","east","tutor_2");
	set_door_description("silver gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r surrounding a small keyhole.%^RESET%^");
	set_locked("silver gate",1,"lock");
	add_lock("silver gate","tutor_2","lock","This is a simple lock, requiring a specific key to open.");
	set_door("copper gate",ROOMS"chamber3","west","tutor_1");
	set_door_description("copper gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of %^RESET%^%^ORANGE%^copper %^BOLD%^%^BLACK%^surrounding a small keyhole.%^RESET%^");
	set_locked("copper gate",1,"lock");
	add_lock("copper gate","tutor_1","lock","This is a simple lock, requiring a specific key to open.");
}

void reset(){
	::reset();
	if(!present("clockwork_puppet",TO)) new(OBJ+"clockwork1")->move(TO);
	if(!present("silver key",TO)) new(OBJ+"silverkey")->move(TO);
}

void init(){
	::init();
	add_action("get_fun","get");
	add_action("look_fun","look");
	add_action("hide_fun","hide");
}

// This prevents the player from just taking the key from the ground, but lets them pick up other stuff.
int get_fun(string str){
	if((str!="key") && (str!="all") && (str!="get silver key"))
		return 0;
	else{
		tell_object(TP,"%^BOLD%^%^BLACK%^The puppet whirls to life, slapping your hand away from the key!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet whirls to life, slapping at "+TP->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^",TP);
		return 1;
	}
}

// Keeps people from getting infinite keys.
int hide_fun(string str){
	if((str!="silver key on me") && (str!="key on me"))
		return 0;
	else{
		if(!present("silver key",TP)){
			tell_object(TP,"%^BOLD%^%^BLACK%^You quietly slip the key into your pocket.%^RESET%^");
			tell_room(ETP,"");
			tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet whirs into motion, retrieving another %^RESET%^k%^BOLD%^e%^RESET%^y %^BOLD%^%^BLACK%^from a secret compartment and placing it delicately on the ground.%^RESET%^");
			new(OBJ+"silverkey")->move(TP);
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
		tell_object(TP,"%^BOLD%^%^RED%^A thief must be nimble and quick to secret away valuables, both on their person and from under watchful eyes. A slow thief is a caught thief.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^You can %^WHITE%^<hide (item)> %^BLACK%^to hide something in the room or %^WHITE%^<hide (item) on me> %^BLACK%^to hide something on yourself. You can name an item on the ground in the room to secretly move it into your inventory, good for stealing a pile of coins when you're in a group. Items hidden have a chance to be seen by others, depending on a contest between your %^WHITE%^stealth %^BLACK%^and their %^WHITE%^perception%^BLACK%^.%^RESET%^");
	}
	return 1;
}

