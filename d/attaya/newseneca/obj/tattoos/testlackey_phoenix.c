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
	set_id(({ "tattoo", "phoenix tattoo", "tiny phoenix tattoo" }));
	set_short("%^RED%^a tiny tattoo of a %^BOLD%^ph%^YELLOW%^o%^RED%^en%^WHITE%^i%^RED%^x%^RESET%^");
	set_long(
@MYLONG
This is a tiny tattoo of a phoenix on Testlackey's shoulder.  Oooh, neat.

MYLONG
	);
	set_limbs(({"right arm"}));
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

