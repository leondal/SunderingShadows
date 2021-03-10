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
	set_id(({ "tattoo", " sunrise tattoo" }));
	set_short("%^RESET%^%^CYAN%^A large tattoo of a %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^RESET%^%^MAGENTA%^s%^RESET%^%^RED%^u%^ORANGE%^n%^YELLOW%^r%^RESET%^%^ORANGE%^i%^RED%^s%^MAGENTA%^e%^RESET%^");
	set_long(
@MYLONG
This masterfully crafted %^CYAN%^tattoo %^RESET%^has been etched into the skin of this elf's forearm.  A beautiful, %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^ORANGE%^s%^RED%^u%^MAGENTA%^n %^RESET%^rises across a %^BOLD%^%^GREEN%^grassy green me%^YELLOW%^a%^GREEN%^dow %^RESET%^that is backed by a %^BOLD%^brilliant %^CYAN%^blue sky%^RESET%^.  Tones of %^MAGENTA%^purple%^RESET%^, %^BOLD%^%^MAGENTA%^pink%^RESET%^, and %^ORANGE%^orange %^RESET%^interweave themselves near the corona of the sun, giving the impression of the %^MAGENTA%^d%^RED%^a%^ORANGE%^w%^YELLOW%^n%^RESET%^.

MYLONG
	);
	set_limbs(({"right arm"}));
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

