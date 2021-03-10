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
	set_id(({ "tattoo" }));
	set_short("medium %^BOLD%^%^BLACK%^S%^RESET%^ku%^BOLD%^WHITE%^l%^RESET%^lb%^BOLD%^%^BLACK%^r%^RESET%^ea%^BOLD%^%^WHITE%^k%^RESET%^er%^BOLD%^%^BLACK%^s %^RESET%^RED%^C%^BOLD%^l%^RESET%^RED%^an%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^S%^RESET%^ku%^BOLD%^WHITE%^l%^RESET%^lb%^BOLD%^%^BLACK%^r%^RESET%^ea%^BOLD%^%^WHITE%^k%^RESET%^er%^BOLD%^%^BLACK%^s %^RESET%^RED%^C%^BOLD%^l%^RESET%^RED%^an%^RESET%^

MYLONG
	);
	set_limbs(({"right arm"}));
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

