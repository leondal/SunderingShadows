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
	set_id(({ "tattoo", "chest tattoo", "crow tattoo" }));
	set_short("%^RESET%^%^MAGENTA%^A large tattoo of a %^BOLD%^%^BLACK%^black crow %^RESET%^%^MAGENTA%^and %^BOLD%^%^RED%^d%^RESET%^%^RED%^a%^ORANGE%^n%^MAGENTA%^ci%^RED%^n%^BOLD%^g f%^RESET%^%^RED%^l%^MAGENTA%^a%^ORANGE%^m%^RED%^e%^BOLD%^s%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^MAGENTA%^A large %^BOLD%^%^BLACK%^black crow%^RESET%^%^MAGENTA%^, its penetrating %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^a%^BOLD%^ze %^RESET%^%^MAGENTA%^glancing off to the left, is the centerpiece of this large chest piece. Some %^BOLD%^%^RED%^roses %^RESET%^%^MAGENTA%^are scattered around the bird, but the true art is found within the %^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^l%^RED%^a%^MAGENTA%^m%^ORANGE%^e%^BOLD%^%^RED%^s %^RESET%^%^MAGENTA%^that consume the space, their %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^MAGENTA%^e%^ORANGE%^r%^BOLD%^%^RED%^y t%^RESET%^%^RED%^e%^MAGENTA%^n%^ORANGE%^dr%^MAGENTA%^i%^RED%^l%^BOLD%^s %^RESET%^%^MAGENTA%^licking upwards to snake around the throat like vines. The colors are extraordinarily %^BOLD%^vibrant%^RESET%^%^MAGENTA%^, bringing the stunning image to life.%^WHITE%^

MYLONG
	);
	set_limbs(({"neck"}));
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

