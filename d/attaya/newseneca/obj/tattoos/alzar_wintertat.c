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
	set_id(({ "wintry tattoo", "tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A large %^BOLD%^%^WHITE%^w%^CYAN%^i%^WHITE%^n%^CYAN%^t%^WHITE%^r%^CYAN%^y %^BLACK%^t%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^tt%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^o%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The tattoo depicts a small village in a %^BOLD%^%^WHITE%^w%^CYAN%^i%^WHITE%^n%^CYAN%^t%^WHITE%^r%^CYAN%^y %^RESET%^%^ORANGE%^wasteland%^BOLD%^%^BLACK%^. Villagers flee a beautiful %^BOLD%^%^WHITE%^pl%^RESET%^a%^BOLD%^%^WHITE%^ti%^RESET%^n%^BOLD%^%^WHITE%^um%^BLACK%^ haired female half-elf whirling bla%^MAGENTA%^c%^BLACK%^k barbed daggers in a %^RED%^frenzy%^BLACK%^. Off to the side a man encased in %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^BLACK%^ full-plate can be seen chuckling lightly as the woman slowly slays another villager in a
%^RED%^m%^WHITE%^u%^RED%^r%^WHITE%^d%^RED%^e%^WHITE%^r%^RED%^o%^WHITE%^u%^RED%^s%^BLACK%^ rage.%^RESET%^

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

