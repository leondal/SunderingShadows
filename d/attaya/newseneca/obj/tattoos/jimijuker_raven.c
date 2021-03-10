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
	set_id(({ "tattoo" }));
	set_short("A large full-sleeve tribal tattoo of a black bird on right arm");
	set_long(
@MYLONG
This masterfully drawn, entirely black tribal tattoo, depicts a Corvus Corax. its about to take flight, its long narrow wings are spread and its head is cocked to the left showing off its magnificent chisel-like bill.
Written, in gothic lettering, under the bird reads the following ...
"TO SEE ONE RAVEN IS LUCKY, 'TIS TRUE.
BUT IT'S CERTAIN MISFORTUNE TO LIGHT UPON TWO.
AND MEETING WITH THREE ... IS THE DEVIL!"

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

