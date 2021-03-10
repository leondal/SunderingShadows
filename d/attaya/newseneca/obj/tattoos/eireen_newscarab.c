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
	set_id(({ "tattoo", "scarab", "scarab tattoo", "tiny tattoo" }));
	set_short("%^BOLD%^%^WHITE%^tiny %^RESET%^%^ORANGE%^s%^CYAN%^c%^ORANGE%^a%^GREEN%^r%^CYAN%^a%^ORANGE%^b %^BOLD%^%^WHITE%^tattoo%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^BLACK%^..........%^ORANGE%^|%^BLACK%^..%^GREEN%^___%^BLACK%^..%^ORANGE%^|
%^RESET%^%^BLACK%^..%^ORANGE%^A%^BLACK%^.........%^GREEN%^(%^BLACK%^...%^GREEN%^)%^BLACK%^.........%^ORANGE%^A
%^RESET%^%^BLACK%^.%^ORANGE%^AA________%^GREEN%^(%^BLACK%^..%^GREEN%^_%^BLACK%^..%^GREEN%^)%^ORANGE%^________AA
%^RESET%^%^BLACK%^.%^ORANGE%^A@@%^CYAN%^@@%^GREEN%^@@%^ORANGE%^@@%^GREEN%^(%^BLACK%^..%^CYAN%^X%^GREEN%^|%^CYAN%^X%^BLACK%^..%^GREEN%^)%^ORANGE%^@@%^GREEN%^@@%^CYAN%^@@%^ORANGE%^@@A
%^RESET%^%^BLACK%^.%^ORANGE%^A@%^CYAN%^@@@%^GREEN%^@@%^ORANGE%^@@%^GREEN%^(%^BLACK%^...%^ORANGE%^|%^BLACK%^...%^GREEN%^)%^ORANGE%^@@%^GREEN%^@@%^CYAN%^@@@%^ORANGE%^@A
%^RESET%^%^BLACK%^..%^ORANGE%^A@%^CYAN%^@@%^GREEN%^@@%^ORANGE%^@V%^GREEN%^|%^BLACK%^...%^ORANGE%^|%^BLACK%^...%^GREEN%^|%^ORANGE%^V@%^GREEN%^@@%^CYAN%^@@%^ORANGE%^@A
%^RESET%^%^BLACK%^...%^ORANGE%^V@%^CYAN%^@@%^ORANGE%^@V%^BLACK%^..%^GREEN%^(%^ORANGE%^V%^GREEN%^_%^ORANGE%^A%^GREEN%^_%^ORANGE%^V%^GREEN%^)%^BLACK%^..%^ORANGE%^V@%^CYAN%^@@%^ORANGE%^@V
%^RESET%^%^BLACK%^...........%^ORANGE%^|%^BLACK%^.....%^ORANGE%^|

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

