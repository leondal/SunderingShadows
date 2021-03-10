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
	set_id(({ "tattoo", "tribal", "swirls" }));
	set_short("%^BOLD%^%^BLACK%^A huge mass of swirling tribal tattoos");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The main body of this ink is a thick, smoky tendril that twists and curves up her back. Several small hooks curl out from its length, and a much larger pair of black vines snake out onto each shoulderblade, traveling down the length of each arm. When the lines reach her forearms, they explode like fire, spreading into countless smaller swirls. The last few inches of the tattoo on her right arm shift to a br%^RESET%^%^GREEN%^ight %^BOLD%^%^GREEN%^gree%^RESET%^%^GREEN%^n co%^BOLD%^%^BLACK%^lor, ending at her wrist in the visage of a band of thorny vines. The left arm's ink becomes %^WHITE%^white%^BLACK%^, though this one's wrist is a ring of sharp, vicious teeth.

MYLONG
	);
	set_limbs(({"torso"}));
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

