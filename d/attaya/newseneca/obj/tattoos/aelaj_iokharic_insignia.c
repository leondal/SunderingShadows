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
	set_id(({ "purple rune tattoo", "tattoo", "Tattoo", "small tattoo", "urune" }));
	set_short("%^MAGENTA%^tiny v%^BOLD%^i%^WHITE%^o%^MAGENTA%^le%^RESET%^%^MAGENTA%^t i%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^k%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^c %^MAGENTA%^r%^RESET%^%^MAGENTA%^u%^BOLD%^n%^RESET%^%^MAGENTA%^e%^RESET%^");
	set_long(
@MYLONG
%^MAGENTA%^Tiny v%^BOLD%^i%^WHITE%^o%^MAGENTA%^le%^RESET%^%^MAGENTA%^t %^BOLD%^r%^RESET%^%^MAGENTA%^u%^BOLD%^n%^RESET%^%^MAGENTA%^e from %^BOLD%^%^BLACK%^iokharic %^RESET%^%^MAGENTA%^alphabet, %^BOLD%^%^WHITE%^u%^RESET%^%^MAGENTA%^, in the middle of the back of his hand. It %^BOLD%^g%^WHITE%^l%^MAGENTA%^o%^WHITE%^w%^MAGENTA%^s %^RESET%^%^MAGENTA%^just a little.%^RESET%^

MYLONG
	);
	set_limbs(({"right hand"}));
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

