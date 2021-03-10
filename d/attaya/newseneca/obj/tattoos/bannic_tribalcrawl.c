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
	set_id(({ "tattoo", "tribal", "tribe" }));
	set_short("A huge %^RED%^scrawling %^BLUE%^tri%^RED%^b%^BLUE%^al %^GREEN%^tattoo, %^RED%^with the word%^BOLD%^%^RED%^ "tribe"%^RESET%^%^BLUE%^ inscribed in drow characters, centered on the bicep%^RESET%^");
	set_long(
@MYLONG
A $T %^RED%^scrawling %^BLUE%^tri%^RED%^b%^BLUE%^al %^GREEN%^tattoo, %^RED%^with the word%^BOLD%^%^RED%^ "tribe"%^RESET%^%^BLUE%^ inscribed in drow characters, centered on the bicep%^RESET%^

MYLONG
	);
	set_limbs(({"right arm"}));
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

