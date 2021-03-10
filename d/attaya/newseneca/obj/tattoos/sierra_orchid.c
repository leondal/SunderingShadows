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
	set_id(({ "tattoo", "orchid tattoo", "orchid" }));
	set_short("%^BOLD%^%^BLACK%^A tiny %^RESET%^%^MAGENTA%^o%^BOLD%^%^GREEN%^r%^RESET%^%^MAGENTA%^ch%^BOLD%^%^GREEN%^i%^RESET%^%^MAGENTA%^d %^BOLD%^%^BLACK%^tattoo");
	set_long(
@MYLONG
%^RESET%^%^MAGENTA%^A small image of an o%^BOLD%^%^GREEN%^r%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^id graces the right side of this girl's neck. Every detail of the flower is perfect, a flawless mimic of the real thing. The petals are deep violet flecked with %^BOLD%^%^BLACK%^black %^RESET%^%^MAGENTA%^and %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^n%^RESET%^%^MAGENTA%^, and delicate %^BOLD%^%^BLACK%^black stamens %^RESET%^%^MAGENTA%^protrude from the flower's center.

MYLONG
	);
	set_limbs(({"neck"}));
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

