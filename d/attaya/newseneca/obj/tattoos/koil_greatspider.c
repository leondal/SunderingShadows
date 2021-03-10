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
	set_value(30000);
	set_id(({ "tattoo", "spider tattoo", "huge tattoo", "huge spider tattoo", "Tattoo", "Spider Tattoo", "Spider tattoo" }));
	set_short("%^BLUE%^A %^BOLD%^huge%^RESET%^%^BLUE%^ %^CYAN%^u%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^s%^BOLD%^e%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^tl%^RESET%^%^CYAN%^i%^BLUE%^n%^BOLD%^g %^RESET%^sp%^BOLD%^%^BLACK%^i%^RESET%^d%^BOLD%^%^BLACK%^er t%^RESET%^a%^BOLD%^%^BLACK%^tt%^RESET%^o%^BOLD%^%^BLACK%^o%^RESET%^");
	set_long(
@MYLONG
%^BLUE%^Covering his entire back, a %^BOLD%^%^BLACK%^great spider %^RESET%^%^BLUE%^is tattooed. Its long spindly legs wrap around his torso, meeting in the centre of his chest with clawed %^CYAN%^ti%^BOLD%^p%^RESET%^%^CYAN%^s%^BLUE%^. Long %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^c%^RESET%^k f%^BOLD%^%^BLACK%^a%^RESET%^n%^BOLD%^g%^BLACK%^s %^RESET%^%^BLUE%^extend from chelicerae to %^RED%^h%^BOLD%^o%^RESET%^%^RED%^ok in%^BOLD%^t%^RESET%^%^RED%^o %^BLUE%^either side of his neck. The spider is tattooed with unsettling spiral patterns - following them is slightly %^GREEN%^na%^ORANGE%^u%^GREEN%^s%^BOLD%^e%^RESET%^%^GREEN%^at%^ORANGE%^i%^GREEN%^ng%^BLUE%^. The eyes are most unsettling however. The eight orbs glisten when the light is just right, and seem to sparkle with i%^BOLD%^n%^RESET%^%^BLUE%^si%^BOLD%^d%^RESET%^%^BLUE%^io%^BOLD%^u%^RESET%^%^BLUE%^s %^BOLD%^%^CYAN%^i%^BLUE%^nt%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^ll%^CYAN%^i%^BLUE%^genc%^RESET%^%^CYAN%^e%^BLUE%^.%^WHITE%^

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

