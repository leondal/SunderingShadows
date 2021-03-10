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
	set_value(20000);
	set_id(({ "tattoo", "tat" }));
	set_short("A medium sized BLACK tribal tattoo of a crow worn on the upper-right arm");
	set_long(
@MYLONG
On closer inspection, you see that this tat was inked by a tallented hand. Its done in BLACK, with DARK-EBONY INK. Its a BLACK CROW, with its wings spread and its sharp beak pointing to the left. The crow has a pair of dice in its talons. one die shows ONE PIP and the other shows SIX PIPS.

MYLONG
	);
	set_limbs(({"right arm"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "medium"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

