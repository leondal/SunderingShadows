// Chernobog (10/27/20)
// Chamber 3, Thief Tutorial Area
// Steal, Pick Pockets

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a solid %^RESET%^%^ORANGE%^copper gate %^BOLD%^%^BLACK%^affixed in the eastern wall, and an open passage leads back to the west. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber2",
		"east" : ROOMS"chamber4",
		]));
	set_door("copper gate",ROOMS"chamber4","east","tutor_1");
	set_door_description("copper gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of %^RESET%^%^ORANGE%^copper %^BOLD%^%^BLACK%^surrounding a small keyhole.%^RESET%^");
	set_locked("copper gate",1,"lock");
	add_lock("copper gate","tutor_1","lock","This is a simple lock, requiring a specific key to open.");
}

void reset(){
	::reset();
	if(!present("clockwork_puppet",TO)) new(OBJ+"clockwork3")->move(TO);
}

void init(){
	::init();
	add_action("pp_fun","pp");
	add_action("steal_fun","steal");
	add_action("plant_fun","plant");
	add_action("look_fun","look");
}

// This is here in case they use the OOC info and try it on the puppet.
int pp_fun(string str){
	if(str="puppet"){
		tell_object(TP,"You deftly grab a handful of coins from the puppet's pocket!");
		tell_object(TP,"...oh wait, it's just worthless scrap pieces of metal. Disappointing.");
		return 1;
	}
}

// This is here in case they use the OOC info and try to plant the key back on the puppet.
int plant_fun(string str){
	if((str!="key on puppet") && (str!="copper key on puppet"))
		return 0;
	else{
		tell_object(TP,"It looks like it already has another, no use planting this one now.");
		return 1;
	}
}

// Lets the player steal the key, unless they already have one.
int steal_fun(string str){
	if((str!="key from puppet") && (str!="copper key from puppet"))
		return 0;
	if(present("copper key",TP)){
		tell_object(TP,"You feel as if one is all you'll ever need.");
		return 1;
	}
	else{
		tell_object(TP,"%^BOLD%^%^BLACK%^Slipping a hand carefully into the puppet's pocket, you palm a small key within.%^RESET%^");
		new(OBJ+"copperkey")->move(TP);
		tell_room(ETP,"");
		tell_room(ETP,"%^BOLD%^%^BLACK%^The puppet comes to life, retrieving a %^RESET%^%^ORANGE%^copper key %^BOLD%^%^BLACK%^from a hidden compartment on its torso and casually dropping it into its pocket.%^RESET%^");
		return 1;
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
		tell_object(TP,"%^BOLD%^%^RED%^A thief must be stealthy and deft, to rob a mark without their knowledge. A skillful thief is a wealthy thief.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^You can %^WHITE%^<steal (item) from (target)> %^BLACK%^to steal an item from someone, and you can %^WHITE%^<pp (target)> %^BLACK%^to steal a percentage of their money. Both actions are based on your %^WHITE%^thievery %^BLACK%^and contested by their %^WHITE%^perception%^BLACK%^. The more people that are in the room, the easier it is to steal, but everyone also has a chance based on their perception to see what you are doing. You can also %^WHITE%^<plant (item) on (target)> %^BLACK%^to place an item secretly into someone's inventory.%^RESET%^");
	}
	return 1;
}

