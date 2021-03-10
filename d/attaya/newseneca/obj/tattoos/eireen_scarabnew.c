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
	set_id(({ "tattoo", "scarab", "scarab tattoo" }));
	set_short("%^BOLD%^%^WHITE%^tiny %^RESET%^%^ORANGE%^s%^GREEN%^c%^CYAN%^a%^GREEN%^r%^CYAN%^a%^ORANGE%^b %^BOLD%^%^WHITE%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^BLACK%^XXXXXXXXXX%^ORANGE%^|%^BLACK%^XX%^GREEN%^___%^BLACK%^XX%^ORANGE%^|
%^RESET%^%^BLACK%^XXXXXXXXXXX%^ORANGE%^V%^GREEN%^(%^BLACK%^XXX%^GREEN%^)%^ORANGE%^V
%^RESET%^%^BLACK%^X%^ORANGE%^ _________%^GREEN%^(%^BLACK%^XX%^GREEN%^_%^BLACK%^XX%^GREEN%^)%^ORANGE%^__________
%^RESET%^%^BLACK%^X%^ORANGE%^@@@@@@@@%^RESET%^%^ORANGE%^@%^GREEN%^(%^BLACK%^XX%^GREEN%^V%^ORANGE%^|%^GREEN%^V%^BLACK%^XX%^GREEN%^)%^ORANGE%^@@@@@@@@%^RESET%^%^ORANGE%^@
%^RESET%^%^BLACK%^X%^ORANGE%^@%^GREEN%^@@@@@@@%^ORANGE%^@%^GREEN%^(%^BLACK%^XXX%^ORANGE%^|%^BLACK%^XXX%^GREEN%^)%^ORANGE%^@%^GREEN%^@@@@@@@%^ORANGE%^@
%^RESET%^%^BLACK%^XX%^ORANGE%^@%^CYAN%^@@@@@@%^ORANGE%^@%^GREEN%^|%^BLACK%^XXX%^ORANGE%^|%^BLACK%^XXX%^GREEN%^|%^ORANGE%^@%^CYAN%^@@@@@@%^ORANGE%^@%^BLACK%^X
%^RESET%^%^BLACK%^XXXX%^ORANGE%^@@@@@%^BLACK%^X%^ORANGE%^(%^GREEN%^V__%^ORANGE%^A%^GREEN%^__V%^ORANGE%^)%^BLACK%^X%^ORANGE%^@@@@@@%^BLACK%^XXXX
%^RESET%^%^BLACK%^XXXXXXXXXXX%^ORANGE%^|%^BLACK%^XXXXX%^ORANGE%^|


This tiny tattoo is beside Eireen's left eye

MYLONG
	);
	set_limbs(({"head"}));
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

