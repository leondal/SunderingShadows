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
	set_id(({ "tattoo", "hammer tattoo", "warhammer tattoo", "Tattoo" }));
	set_short("%^RESET%^%^CYAN%^A large tattoo of a %^BOLD%^runed %^RESET%^%^CYAN%^warhammer%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^CYAN%^This is a large stylized tattoo of a %^BOLD%^runecarved %^RESET%^%^CYAN%^metal warhammer.  Printed on the neck of a large bald human, the head of the %^BLUE%^hammer %^CYAN%^covers the wide cranium of the genasi, while the hammer's sturdy handle wrapped in %^ORANGE%^leather %^CYAN%^runs down his spine.  Carved into the head of the hammer are ancient runes that magically %^YELLOW%^glow %^RESET%^%^CYAN%^whenever the strike of a hammer is made near a %^RED%^forge%^CYAN%^.%^RESET%^

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

