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
	set_id(({ "tattoo", " talos tattoo", " medium tattoo", " talos symbol" }));
	set_short("%^BOLD%^%^BLACK%^A medium sized neck tattoo");
	set_long(
@MYLONG
Three %^YELLOW%^lightning bolts%^RESET%^, one %^BOLD%^%^WHITE%^silver%^RESET%^, one %^YELLOW%^gold%^RESET%^, and one %^BOLD%^%^BLACK%^black%^RESET%^, radiating from a small %^BOLD%^%^GREEN%^"%^YELLOW%^T%^GREEN%^"%^RESET%^.

MYLONG
	);
	set_limbs(({"neck"}));
	set_wear((:TO,"wear_me":));
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

