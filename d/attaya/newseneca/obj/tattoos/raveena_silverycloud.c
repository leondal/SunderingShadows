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
	set_value(10000);
	set_id(({ "tattoo", "cloud" }));
	set_short("A tiny swirling cloud");
	set_long(
@MYLONG
A tattoo of an iridescent %^BOLD%^%^WHITE%^silvery cloud %^RESET%^with flecks of %^BOLD%^%^BLUE%^b%^BOLD%^%^CYAN%^lu%^BOLD%^%^BLUE%^es %^RESET%^that, upon closer inspection, appears to %^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^wi%^BOLD%^%^BLUE%^r%^BOLD%^%^WHITE%^l %^RESET%^as if being constantly blown by a slight %^BOLD%^%^WHITE%^b%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^ee%^BOLD%^%^CYAN%^z%^BOLD%^%^WHITE%^e %^RESET%^that only it seems aware of.

MYLONG
	);
	set_limbs(({"neck"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "tiny"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

