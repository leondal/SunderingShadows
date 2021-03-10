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
	set_value(25000);
	set_id(({ "tattoo", "skull", "skull tattoo", "symbol" }));
	set_short("%^BOLD%^%^BLACK%^large %^RESET%^%^WHITE%^s%^BOLD%^k%^RESET%^u%^BOLD%^l%^RESET%^l %^BOLD%^%^BLACK%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The entire upper back is marked with this disturbing ink. A %^GREEN%^grinning %^WHITE%^b%^RESET%^l%^BOLD%^e%^RESET%^a%^BOLD%^c%^RESET%^h%^BOLD%^e%^RESET%^d skull %^BOLD%^%^BLACK%^leers out at you, set within a flaring %^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^h%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^st %^BOLD%^%^BLACK%^sun that fades to black as it nears the skull. The dark pits of its eye sockets seem to be watching you, mocking you as they track your every move.%^RESET%^

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "large"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

