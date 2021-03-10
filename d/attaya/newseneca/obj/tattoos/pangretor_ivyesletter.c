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
	set_id(({ "tattoo", "small tattoo" }));
	set_short("%^RED%^A small neck tatt%^MAGENTA%^o%^RED%^o%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The letter %^RESET%^%^MAGENTA%^"%^RED%^I%^MAGENTA%^" %^BOLD%^%^BLACK%^is tattooed onto the back of his neck. It is shaded in %^RESET%^%^RED%^red%^BOLD%^%^BLACK%^ and outlined in %^YELLOW%^gold%^BLACK%^. The outside of the letter is shadowed %^RESET%^%^MAGENTA%^purple%^BOLD%^%^BLACK%^, making the %^YELLOW%^gold%^BOLD%^%^BLACK%^ lining easily seen.%^RESET%^

MYLONG
	);
	set_limbs(({"neck"}));
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

