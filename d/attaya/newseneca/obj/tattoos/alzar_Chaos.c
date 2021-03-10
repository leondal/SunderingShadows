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
	set_id(({ "tattoo", "mountain range tattoo", " chaos tatto" }));
	set_short("%^BOLD%^%^BLACK%^A medium sized cha%^CYAN%^o%^BLACK%^tic looking tattoo");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The tattoo depicts a small village in what appears to be a %^BOLD%^%^WHITE%^winter%^BLACK%^ wasteland. Snow covers the ground and trees surrounding the village as the villagers flee a %^WHITE%^platinum%^BLACK%^ haired beauty whirling bla%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k barbed daggers in a %^RED%^frenzy%^BLACK%^. Of to the side one can see a man encased in %^%^RESET%^silver%^%^BOLD%^%^BLACK%^ chuckling as the woman slowly slays another villager in what appears to be a %^RED%^m%^WHITE%^u%^RED%^r%^WHITE%^d%^RED%^e%^WHITE%^r%^RED%^o%^WHITE%^u%^RED%^s%^BLACK%^ rage. The tattoo covers the entire right shoulder blade.

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
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

