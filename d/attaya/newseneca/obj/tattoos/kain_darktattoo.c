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
	set_id(({ "tattoo", "dark tattoo", "large tattoo", "kain's tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A large, dark tattoo of a %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^rp%^BOLD%^l%^RESET%^%^MAGENTA%^e di%^BOLD%^s%^RESET%^%^MAGENTA%^k%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^This is a tattoo of a %^RESET%^%^MAGENTA%^purple disk %^BOLD%^%^BLACK%^shrouded in a %^RED%^dark mist%^BLACK%^.  This disk is about four inches in diameter, but the %^RESET%^%^GREEN%^tattoo %^BOLD%^%^BLACK%^itself is around six inches long.  The tattoo of the disk is %^MAGENTA%^glowing %^BLACK%^softly and gives a radiation of mysterious energy.  The tattoo is on the right bicep of a male beastman.%^RESET%^

MYLONG
	);
	set_limbs(({"right arm"}));
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

