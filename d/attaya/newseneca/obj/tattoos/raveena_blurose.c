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
	set_id(({ "tattoo", "rose tattoo" }));
	set_short("A tiny %^BLUE%^blue rose");
	set_long(
@MYLONG
A lovely %^BLUE%^blue %^RESET%^rose tattoo with shades of %^BLUE%^blue %^RESET%^that change throughout the rose with an almost %^BLUE%^i%^RESET%^r%^MAGENTA%^i%^GREEN%^d%^BLUE%^e%^CYAN%^s%^RESET%^c%^GREEN%^e%^BLUE%^n%^MAGENTA%^t %^RESET%^tint. From %^CYAN%^light %^RESET%^to %^BLUE%^dark %^RESET%^with petal tips of %^MAGENTA%^deep purple%^RESET%^, the colors seems to %^CYAN%^s%^MAGENTA%^w%^BLUE%^i%^MAGENTA%^r%^CYAN%^l %^RESET%^about the image as you look at it, almost drawing you in.

MYLONG
	);
	set_limbs(({"neck"}));
	set_wear((:TO,"wear_me":));
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

