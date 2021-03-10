// Chernobog (10/27/20)
// Chamber 8, Thief Tutorial Area
// Spy, Make Thief Sign, and Fences

#include <std.h>
#include "../defs.h"
inherit INH+"chamber";

void create(){
	::create();
	add_item("symbols","%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^c%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^e %^WHITE%^s%^CYAN%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^WHITE%^o%^CYAN%^l%^RESET%^%^CYAN%^s %^BOLD%^%^BLACK%^have been picked out on the western wall, and seem to waver in front of your eyes. You feel a need to %^RESET%^sign%^BOLD%^%^BLACK%^al who you are...%^RESET%^");
	set_long(::query_long()+" %^BOLD%^%^BLACK%^There is a solid %^YELLOW%^go%^WHITE%^l%^YELLOW%^d ga%^WHITE%^t%^YELLOW%^e %^BLACK%^affixed to the eastern wall, and a strange series of %^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^c%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^e %^WHITE%^s%^CYAN%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^WHITE%^o%^CYAN%^l%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^ painted on the western wall. A series of odd %^RESET%^%^RED%^scratches %^BOLD%^%^BLACK%^stands out on one of the stone walls.%^RESET%^");
	set_exits(([
		"east" : ROOMS"chamber7",
		]));
	set_door("gold gate",ROOMS"chamber7","east","tutor_2");
	set_door_description("gold gate","%^BOLD%^%^BLACK%^The gate is wrought iron and features a ring of %^YELLOW%^go%^WHITE%^l%^YELLOW%^d %^BLACK%^surrounding a small keyhole.%^RESET%^");
	set_locked("gold gate",1,"lock");
	add_lock("gold gate","tutor_3","lock","This is a simple lock, requiring a specific key to open.");
}

void init(){
	::init();
	add_action("make_fun","make");
	add_action("look_fun","look");
}

// Teleports the player to the next chamber when they make a thief sign.
int make_fun(string str){
	if(str!="thief sign")
		return notify_fail("Make what?\n");
	tell_object(TP,"%^BOLD%^%^BLACK%^You make a subtle hand gesture towards the %^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^c%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^e %^WHITE%^s%^CYAN%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^WHITE%^o%^CYAN%^l%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^, which b%^RESET%^r%^BOLD%^ight%^RESET%^e%^BOLD%^%^BLACK%^n with a magical %^RESET%^%^CYAN%^gl%^BOLD%^o%^RESET%^%^CYAN%^w %^BOLD%^%^BLACK%^before teleporting you away...%^RESET%^");
	tell_room(ETP,"%^BOLD%^%^BLACK%^There is a %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^indi%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^%^CYAN%^f%^BOLD%^l%^WHITE%^a%^CYAN%^s%^RESET%^%^CYAN%^h%^BOLD%^%^BLACK%^, and then "+TP->QCN+" %^BOLD%^%^BLACK%^is gone!",TP);
	TP->move(ROOMS"chamber9");
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
		tell_object(TP,"%^BOLD%^%^RED%^You have learned the basics, and now you must learn to find your kind in other cities. We are in the taverns, the warehouses, the places where the lawman shies away from. Seek us out and %^RESET%^%^RED%^sign %^BOLD%^that you belong.%^RESET%^");
		tell_object(TP,"");
		tell_object(TP,"%^BOLD%^%^BLACK%^(OOC Info: %^BOLD%^%^BLACK%^There are severel additional tools at the thief's disposal. You can %^WHITE%^<spy (target)> %^BLACK%^to look at someone and their belongings without being noticed, unless the target is especially %^WHITE%^perceptive%^BLACK%^. You can also %^WHITE%^<make thief sign> %^BLACK%^to let all in the area know you are a thief. It is a deft motion, and only other thieves will notice your motion, a good way to subtly seek out other thieves. Lastly, you will want to locate the thieves guilds in all major cities, often in bars or warehouse districts. Some are hidden behind secret mechanisms, and some can be found with a thief sign. Be observant, and careful, and thorough.%^RESET%^");
	}
	return 1;
}

