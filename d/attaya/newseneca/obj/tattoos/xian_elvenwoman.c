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
	set_id(({ "tattoo", "elven woman tattoo", "green elven woman tattoo", "medium tattoo" }));
	set_short("%^GREEN%^This is a medium tattoo of an Elven woman holding a small baby in her arms. Behind her in the %^BLACK%^%^BOLD%^shadows %^RESET%^%^GREEN%^is a figure wearing a %^BLACK%^%^BOLD%^black cloak. %^RESET%^%^GREEN%^The woman looks very frail and extremely %^WHITE%^beautiful.%^RESET%^ %^GREEN%^She holds what appears to be an Half-Elven baby.");
	set_long(
@MYLONG

MYLONG
	);
	set_limbs(({"right arm"}));
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

