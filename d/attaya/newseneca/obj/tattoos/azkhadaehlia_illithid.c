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
	set_id(({ "illithid tattoo" }));
	set_short("%^RESET%^%^ORANGE%^A large tattoo of a %^BOLD%^%^BLACK%^m%^GREEN%^e%^BLACK%^n%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^c%^GREEN%^i%^BLACK%^ng %^MAGENTA%^i%^RESET%^%^MAGENTA%^ll%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^th%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^d%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^ORANGE%^An %^GREEN%^e%^BOLD%^%^GREEN%^e%^BLACK%^r%^GREEN%^i%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^y %^RESET%^%^ORANGE%^realistic rendition of an %^BOLD%^%^MAGENTA%^illithid's %^RESET%^%^ORANGE%^head is tattooed across the entire upper arm of this elf. Cold, calculating eyes are set deep in a b%^MAGENTA%^u%^ORANGE%^lb%^WHITE%^o%^MAGENTA%^u%^ORANGE%^s, bulging cranium. Its %^BOLD%^%^WHITE%^pallid %^RESET%^%^ORANGE%^flesh has a sickly, %^MAGENTA%^p%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^rp%^BOLD%^%^BLACK%^l%^WHITE%^i%^MAGENTA%^s%^BLACK%^h %^RESET%^%^ORANGE%^sheen making it look slippery and rubbery. Several th%^MAGENTA%^i%^ORANGE%^ck tentacles snake down and wrap around her toned %^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^cep %^RESET%^%^ORANGE%^as if seeking their next victim.%^RESET%^ 

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

