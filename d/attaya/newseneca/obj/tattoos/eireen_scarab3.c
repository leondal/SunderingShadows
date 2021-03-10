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
	set_id(({ "tattoo", "scarab", "scarab tattoo", "tiny tattoo", " tat 1" }));
	set_short("%^BOLD%^%^WHITE%^tiny %^RESET%^%^ORANGE%^s%^GREEN%^c%^CYAN%^a%^GREEN%^r%^CYAN%^a%^ORANGE%^b %^BOLD%^%^WHITE%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^WHITE%^ This tiny tattoo is right beside Eireen's left eye%^RESET%^
%^RESET%^%^BLACK%^XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
%^RESET%^%^BLACK%^XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
%^RESET%^%^BLACK%^XXXXXXXXXXXX%^ORANGE%^|%^BLACK%^XX%^GREEN%^____%^BLACK%^X%^ORANGE%^|%^BLACK%^XXXXXXXXXXXX%^RESET%^
%^RESET%^%^BLACK%^XXXXXXXXXXXXX%^ORANGE%^\%^GREEN%^(%^BLACK%^XXX%^GREEN%^)%^ORANGE%^/%^BLACK%^XXXXXXXXXXXXXX%
%^RESET%^%^BLACK%^XXX%^ORANGE%^ _________%^GREEN%^(%^BLACK%^XX%^GREEN%^_%^BLACK%^XX%^GREEN%^)%^ORANGE%^__________%^BLACK%^XXX%^RESET%^
%^RESET%^%^BLACK%^XXX%^ORANGE%^@%^GREEN%^/%^CYAN%^\%^GREEN%^/%^CYAN%^\%^GREEN%^/%^CYAN%^\%^GREEN%^/%^ORANGE%^@%^GREEN%^(%^BLACK%^X%^GREEN%^\/%^ORANGE%^|%^GREEN%^\/%^BLACK%^X%^GREEN%^)%^ORANGE%^@%^GREEN%^\%^CYAN%^/%^GREEN%^\%^CYAN%^/%^GREEN%^\%^CYAN%^/%^GREEN%^\%^ORANGE%^@%^BLACK%^XX
%^RESET%^%^BLACK%^XXX%^ORANGE%^@%^GREEN%^/%^CYAN%^\%^GREEN%^/%^CYAN%^\%^GREEN%^/%^CYAN%^\%^GREEN%^/%^ORANGE%^@%^GREEN%^(%^BLACK%^X%^GREEN%^\/%^ORANGE%^|%^GREEN%^\/%^BLACK%^X%^GREEN%^)%^ORANGE%^@%^GREEN%^\%^CYAN%^/%^GREEN%^\%^CYAN%^/%^GREEN%^\%^CYAN%^/%^GREEN%^\%^ORANGE%^@%^BLACK%^XX
%^RESET%^%^BLACK%^XXXX%^ORANGE%^@%^CYAN%^\%^GREEN%^/%^CYAN%^\%^GREEN%^/%^CYAN%^\%^GREEN%^/%^ORANGE%^@%^GREEN%^|%^BLACK%^XXX%^ORANGE%^|%^BLACK%^XXX%^GREEN%^|%^ORANGE%^@%^GREEN%^\%^CYAN%^/%^GREEN%^\%^CYAN%^/%^GREEN%^\%^CYAN%^/%^ORANGE%^@%^BLACK%^XXX
%^RESET%^%^BLACK%^XXXXXX%^ORANGE%^@@@@@%^BLACK%^X%^ORANGE%^(%^GREEN%^\__%^ORANGE%^A%^GREEN%^__/%^ORANGE%^)%^BLACK%^X%^ORANGE%^@@@@@@%^BLACK%^XXXX
%^RESET%^%^BLACK%^XXXXXXXXXXXXX%^ORANGE%^|%^BLACK%^XXXXX%^ORANGE%^|%^BLACK%^XXXXXXXXXXXX
%^RESET%^%^BLACK%^XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX%^RESET%^
%^RESET%^%^BLACK%^XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX%^RESET%^

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

