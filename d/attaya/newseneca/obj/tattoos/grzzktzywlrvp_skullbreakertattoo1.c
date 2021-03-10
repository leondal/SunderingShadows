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
	set_id(({ "skull tattoo", "broken skull tattoo", "skullbreaker's tattoo" }));
	set_short("%^RESET%^%^MAGENTA%^A large sized m%^BOLD%^a%^RESET%^%^MAGENTA%^gen%^BOLD%^t%^RESET%^%^MAGENTA%^a b%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^oke%^BOLD%^%^BLACK%^n %^WHITE%^skull %^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^tt%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^o%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^MAGENTA%^This is a magenta colored %^BOLD%^%^WHITE%^skull %^RESET%^%^MAGENTA%^tattoo. The skull is broken from the top. The empty eye sockets are colored with black.%^RESET%^

MYLONG
	);
	set_limbs(({"left arm"}));
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

