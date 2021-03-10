#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(15000);
	set_id(({ "tattoo", "feather tattoo", "black feather tattoo", "black tattoo", "small tattoo" }));
	set_short("%^BOLD%^%^BLACK%^small %^RESET%^%^WHITE%^bla%^BOLD%^%^BLACK%^c%^RESET%^%^WHITE%^k feat%^BOLD%^%^BLACK%^h%^RESET%^%^WHITE%^er %^BOLD%^%^BLACK%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^This is the tattoo of a %^RESET%^%^WHITE%^s%^BOLD%^%^BLACK%^m%^RESET%^%^WHITE%^all bla%^BOLD%^%^BLACK%^c%^RESET%^k feat%^BOLD%^%^BLACK%^h%^RESET%^%^WHITE%^er%^BOLD%^%^BLACK%^.  The tattoo is about two inches long and has been traced on the wrist of a beastman.  The tattoo looks like it is the mark of a certain clan.  Below the tattoo in cursive letters is written '%^RESET%^%^WHITE%^Swan%^BOLD%^%^BLACK%^'%^RESET%^

MYLONG
	);
	set_limbs(({"right arm"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "small"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

