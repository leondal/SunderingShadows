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
	set_value(20000);
	set_id(({ "tattoo", " tat" }));
	set_short("a medium sized BLACK tribal tattoo of a crow");
	set_long(
@MYLONG
On closer inspection ... you see that this tattoo was made by tallented gnomish skilled hands. Its inked with the BLACKEST of EBONY ink. Its of a crow with its wings spread and its sharp beak turned to the left. In its talons it holds two die, one with ONE PIP showing, and the other with SIX PIPS showing.

MYLONG
	);
	set_limbs(({"right arm"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "medium"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

