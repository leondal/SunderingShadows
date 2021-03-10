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
	set_id(({ "tattoo", "elven woman tattoo", "green elven woman tattoo", "large tattoo" }));
	set_short("%^BLACK%^%^BOLD%^This is a large %^RESET%^%^GREEN%^tattoo, %^BLACK%^%^BOLD%^of an Elven woman, holding a baby. ");
	set_long(
@MYLONG
%^GREEN%^This is a tattoo of an %^WHITE%^extremely beautiful,%^RESET%^%^GREEN%^ but frail Elven woman, holding a small baby.  Behind her in the %^BLACK%^%^BOLD%^shadows %^RESET%^%^GREEN%^stands a %^BLACK%^%^BOLD%^hooded figure, you cannot see his face but you can tell he's just stalking the woman. %^RESET%^%^GREEN%^The womans vision is focused on the baby which appears to be Half-elven. 

MYLONG
	);
	set_limbs(({"torso"}));
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

