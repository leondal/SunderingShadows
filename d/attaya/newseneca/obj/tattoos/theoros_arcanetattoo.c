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
	set_id(({ "tattoo", "arcane tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A large %^RESET%^%^WHITE%^a%^CYAN%^r%^WHITE%^c%^CYAN%^a%^WHITE%^n%^CYAN%^i%^WHITE%^s%^CYAN%^t%^RESET%^%^BOLD%^%^BLACK%^ tattoo%^RESET%^");
	set_long(
@MYLONG
This is a plain black and white arcanist symbol. It has a triangle within a circle and three more circles within the triangle. A star underlies the circle. It's a very simple design and is in black and white.

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

