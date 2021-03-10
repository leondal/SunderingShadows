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
	set_id(({ "tattoo", "dragon tattoo", "sword tattoo", "green dragon tattoo", "black sword tattoo" }));
	set_short("%^RED%^A large tattoo of a %^BLACK%^%^BOLD%^Black Sword %^RESET%^%^RED%^with a %^GREEN%^Green dragon %^RED%^around it.%^RESET%^");
	set_long(
@MYLONG
%^RED%^There is a %^BLACK%^%^BOLD%^Black sword %^RESET%^%^RED%^coming down his arm with the hilt starting at his bicep and the tip ending just before his wrist. The sword looks like an ancient and p%^BLUE%^owerful swor%^RED%^d. It has markings, symbols of some kind that look very fascinating.  In the hilt of the sword is a glorious %^GREEN%^Green Emerald.%^RED%^  Wrapped all around the sword is a mysterious %^GREEN%^Green Dragon. %^RED%^The Dragon looks majestic, traveling from above the hilt down past the tip of the sword. The Dragon's face is on his shoulder and its looking at you with its %^BOLD%^red eyes %^RESET%^%^RED%^and it is growling at you and its teeth look razor sharp, its split tongue is out as well.  The tail travels all the way down to the middle of his hand.%^RESET%^

MYLONG
	);
	set_limbs(({"right arm"}));
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

