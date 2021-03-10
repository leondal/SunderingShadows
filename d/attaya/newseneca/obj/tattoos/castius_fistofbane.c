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
	set_value(10000);
	set_id(({ "tattoo", "fist tattoo", "bane fist tattoo", "tiny tattoo", "facial tattoo", "bane tattoo", "clenched fist tattoo" }));
	set_short("%^BOLD%^%^BLACK%^a tiny %^RESET%^%^GREEN%^c%^BOLD%^l%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^c%^BOLD%^h%^RESET%^%^GREEN%^e%^BOLD%^d %^BLACK%^fist facial tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^This tiny tattoo couldn%^BOLD%^%^GREEN%^'%^BLACK%^t be more than a square inch in size%^GREEN%^.%^BLACK%^ It is %^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^t%^BOLD%^f%^RESET%^%^MAGENTA%^u%^BOLD%^l%^RESET%^%^MAGENTA%^l%^BOLD%^y %^BLACK%^positioned on the wearer%^GREEN%^'%^BLACK%^s face below the outer corner of his right eye%^GREEN%^. %^BLACK%^The tattoo is simple in nature%^GREEN%^. %^BLACK%^It depicts a black hand with blackened and %^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^a%^BOLD%^r%^RESET%^%^RED%^p %^BOLD%^%^BLACK%^nails%^GREEN%^; %^BOLD%^%^BLACK%^clenched into a fist. From in between the fingers %^RESET%^%^ORANGE%^b%^BOLD%^r%^RESET%^%^ORANGE%^i%^BOLD%^g%^RESET%^%^ORANGE%^h%^BOLD%^t %^RESET%^%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^n %^BOLD%^%^BLACK%^rays of %^WHITE%^l%^YELLOW%^i%^WHITE%^g%^YELLOW%^h%^WHITE%^t %^BLACK%^pour out%^GREEN%^.%^RESET%^

MYLONG
	);
	set_limbs(({"head"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "tiny"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

