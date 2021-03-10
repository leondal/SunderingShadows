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
	set_id(({ "rose tattoo", "tattoo" }));
	set_short("This is a tiny image of a lovely %^BLUE%^blue %^RESET%^rose tattoo. The shades of %^BLUE%^blue %^RESET%^change throughout the rose, from %^CYAN%^light %^RESET%^to %^BLUE%^dark %^RESET%^with %^MAGENTA%^deep purple %^RESET%^color at the tips of each petal. The colors seems to %^CYAN%^s%^MAGENTA%^w%^BLUE%^i%^CYAN%^r%^BLUE%^l %^RESET%^about the image as you look at it.");
	set_long(
@MYLONG
This is the image of a lovely %^BLUE%^blue %^RESET%^rose tattoo. The shades of %^BLUE%^blue %^RESET%^change throughout the rose with an almost %^BLUE%^i%^RESET%^r%^MAGENTA%^i%^GREEN%^d%^BLUE%^e%^CYAN%^s%^RESET%^c%^GREEN%^e%^BLUE%^n%^MAGENTA%^t %^RESET%^tint, from %^CYAN%^light %^RESET%^to %^BLUE%^dark %^RESET%^with %^MAGENTA%^deep purple %^RESET%^petal tips. The colors seems to %^CYAN%^s%^MAGENTA%^w%^BLUE%^i%^MAGENTA%^r%^CYAN%^l %^RESET%^about the image as you look at it, almost drawing you in.

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

