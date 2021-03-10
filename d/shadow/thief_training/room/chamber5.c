// Chernobog (10/27/20)
// Chamber 5, Thief Tutorial Area
// Descend

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a solid s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^g%^BOLD%^a%^RESET%^t%^BOLD%^%^BLACK%^e affixed in the western wall, and a rather large %^RESET%^%^BLUE%^crack %^BOLD%^%^BLACK%^in the floor near the eastern wall. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	add_item("crack","%^BOLD%^%^BLACK%^There is a sizeable crack in the floor, just large enough that you could squeeze through and %^RESET%^descend %^BOLD%^%^BLACK%^further down.%^RESET%^");
	set_exits(([
		"west" : ROOMS"chamber4",
		]));
	set_door("silver gate",ROOMS"chamber4","west","tutor_2");
	set_door_description("silver gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r surrounding a small keyhole.%^RESET%^");
	set_locked("silver gate",1,"lock");
	add_lock("silver gate","tutor_2","lock","This is a simple lock, requiring a specific key to open.");
	set_climb_exits(([
		"descend" : ({ROOMS"chamber6",1,6,100}),
		]));
}

void init(){
	::init();
	add_action("look_fun","look");
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
		tell_object(TP,"%^BOLD%^%^RED%^A thief must be observant and explore every nook and cranny. A thorough thief is a wealthy thief.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^There will be areas that you can %^WHITE%^<climb> %^BLACK%^and %^WHITE%^<descend> %^BLACK%^that will not be immediately apparent. The ability to climb is based on your %^WHITE%^athletics%^BLACK%^, and can be aided by having climbing tools in your inventory. Failing can either stall your climb, or even make you fall and suffer damage.");
		}
	return 1;
}

