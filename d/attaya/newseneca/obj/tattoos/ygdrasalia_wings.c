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
	set_id(({ "tattoo", "wings tattoo", "huge tattoo", "silver wings" }));
	set_short("%^BOLD%^huge %^BOLD%^%^BLACK%^t%^WHITE%^a%^BLACK%^tt%^WHITE%^oo %^RESET%^of %^BOLD%^w%^CYAN%^i%^WHITE%^n%^CYAN%^g%^WHITE%^s");
	set_long(
@MYLONG
%^BOLD%^%^CYAN%^This is a %^RED%^p%^MAGENTA%^a%^RED%^in%^RED%^sta%^MAGENTA%^k%^RED%^i%^MAGENTA%^n%^RED%^g%^MAGENTA%^ly %^CYAN%^detailed tattoo depicting %^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^v%^CYAN%^e%^WHITE%^r %^CYAN%^wings on the back. The tattoo encompasses the entire back, and must have caused extraordinary pain considering how detailed it is. When looked at in different lighting, each, individually painted feather shimmers, creating a dazzling effect.

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
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

