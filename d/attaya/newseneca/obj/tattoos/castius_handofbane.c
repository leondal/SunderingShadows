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
	set_id(({ "hand", "tattoo", "hand tattoo", "bane tattoo", "hand of bane tattoo", "tiny tattoo", "hand of bane" }));
	set_short("%^BOLD%^%^BLACK%^a tiny %^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^l%^BOLD%^e%^BLACK%^n%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^h%^RESET%^%^GREEN%^e%^BOLD%^d %^BLACK%^fist facial tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^This tiny tattoo couldn%^GREEN%^'%^BLACK%^t be more than a square inch in size%^GREEN%^.%^BLACK%^ It is %^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^t%^BOLD%^f%^RESET%^%^MAGENTA%^u%^BOLD%^l%^RESET%^%^MAGENTA%^l%^BOLD%^y %^BLACK%^positioned on the wearer%^GREEN%^'%^BLACK%^s face below the corner of his right eye%^GREEN%^. %^BLACK%^The tattoo is simple in nature%^GREEN%^. %^BLACK%^It depicts a black hand with blackened and %^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^a%^BOLD%^r%^RESET%^%^RED%^p %^BOLD%^%^BLACK%^nails%^GREEN%^; %^BOLD%^%^BLACK%^clenched into a fist%^GREEN%^.%^BLACK%^ From in between the fingers %^RESET%^%^ORANGE%^b%^BOLD%^r%^RESET%^%^ORANGE%^i%^BOLD%^g%^RESET%^%^ORANGE%^h%^BOLD%^t %^RESET%^%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^n %^BOLD%^%^BLACK%^rays of %^WHITE%^l%^YELLOW%^i%^WHITE%^g%^YELLOW%^h%^WHITE%^t %^BLACK%^pour out%^GREEN%^. %^BLACK%^The %^RESET%^s%^BOLD%^%^BLACK%^h%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^BOLD%^%^BLACK%^and line%^GREEN%^-%^BLACK%^work appear to be %^RESET%^%^CYAN%^m%^BOLD%^a%^RESET%^%^CYAN%^s%^BOLD%^t%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^f%^BOLD%^u%^RESET%^%^CYAN%^l%^BOLD%^l%^RESET%^%^CYAN%^y %^BOLD%^%^BLACK%^done%^GREEN%^, %^BLACK%^showing this was done by none other than an %^RESET%^%^CYAN%^e%^BOLD%^x%^RESET%^%^CYAN%^p%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^t %^BLACK%^in their craft%^GREEN%^.%^RESET%^

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

