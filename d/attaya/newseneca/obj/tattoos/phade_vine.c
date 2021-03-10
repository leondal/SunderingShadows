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
	set_value(30000);
	set_id(({ "tattoo", "vine tattoo", "vines" }));
	set_short("%^RESET%^%^ORANGE%^A huge %^GREEN%^t%^ORANGE%^w%^GREEN%^i%^ORANGE%^s%^GREEN%^t%^ORANGE%^i%^GREEN%^n%^ORANGE%^g tattoo of %^GREEN%^vin%^ORANGE%^e%^GREEN%^s%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^ORANGE%^This is an intricate tattoo of snaking %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes %^RESET%^%^ORANGE%^that run up both arms and meet at the back of the neck. Tiny %^RESET%^%^GREEN%^le%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^v%^RESET%^%^ORANGE%^e%^GREEN%^s %^ORANGE%^sprout from each of the %^GREEN%^vines %^ORANGE%^and intwine eachother in giving an illusion of infinite complexity. The work is done almost entirely in shades of %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n %^ORANGE%^from stark colours of %^BOLD%^%^GREEN%^newgrowth %^RESET%^%^ORANGE%^to the %^BOLD%^%^BLACK%^darker %^RESET%^%^ORANGE%^shades of o%^RESET%^%^GREEN%^a%^ORANGE%^k %^GREEN%^leaves%^ORANGE%^. When it reaches the hands the %^GREEN%^vines %^ORANGE%^split apart running down each finger to end just above the nail.%^RESET%^

MYLONG
	);
	set_limbs(({"neck"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

