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
	set_id(({ "tattoo", "nightmare", "nightmare tattoo" }));
	set_short("%^BOLD%^%^BLACK%^medium-sized tattoo of a n%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^BLUE%^t%^BOLD%^%^BLUE%^m%^BLACK%^a%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^e%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^This tattoo is placed on the left hip just above the stomach. A hellish black horse thrusts its head forward, mouth open in a silent cry of rage. The beast's %^RESET%^%^MAGENTA%^e%^BOLD%^%^RED%^y%^RESET%^%^MAGENTA%^es %^BOLD%^%^BLACK%^blaze and trail lines of %^RESET%^%^CYAN%^b%^BLUE%^l%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^e %^BLUE%^f%^BOLD%^%^BLACK%^i%^BLUE%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^. The coat of short, sleek fur covering its head and neck holds a bright sheen, reflecting light as if made of obsidian. A f%^RESET%^%^BLUE%^l%^BOLD%^%^BLUE%^a%^BLACK%^m%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^n%^BLACK%^g m%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ne emerges from the back of its neck, seeming to wave and flicker as you stare at it.%^RESET%^

MYLONG
	);
	set_limbs(({"waist"}));
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

