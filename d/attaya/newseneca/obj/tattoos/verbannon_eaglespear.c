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
	set_id(({ "tattoo", " tribal tattoo", " eagle tattoo", " spear tattoo", " tiger tattoo" }));
	set_short("A large tattoo of a %^ORANGE%^spea%^BOLD%^%^BLACK%^r%^RESET%^ wielding %^ORANGE%^e%^BOLD%^a%^RESET%^%^ORANGE%^gle%^RESET%^, stabbing a %^BOLD%^%^WHITE%^t%^BLACK%^i%^WHITE%^g%^BLACK%^e%^WHITE%^r%^RESET%^");
	set_long(
@MYLONG
Upon this man's shaved head is what appears to be a %^BOLD%^%^BLACK%^black e%^WHITE%^a%^BLACK%^gle%^RESET%^ viciously %^BOLD%^%^RED%^imp%^RESET%^%^RED%^a%^BOLD%^l%^RESET%^%^RED%^i%^BOLD%^ng%^RESET%^ a %^BOLD%^%^WHITE%^white s%^BLACK%^t%^WHITE%^r%^BLACK%^i%^WHITE%^p%^BLACK%^e%^WHITE%^d t%^BLACK%^i%^WHITE%^g%^BLACK%^e%^WHITE%^r%^RESET%^ with a %^ORANGE%^spea%^BOLD%^%^BLACK%^r%^RESET%^.

MYLONG
	);
	set_limbs(({"head"}));
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

