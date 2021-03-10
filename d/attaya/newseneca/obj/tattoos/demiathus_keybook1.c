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
	set_id(({ "tattoo", "book tattoo", "key tattoo", "wrist tattoo" }));
	set_short("A large tattoo of a book");
	set_long(
@MYLONG
This tattoo is on the inside of the wrist. It is an open
book, displaying two pages. On the right page is a %^BOLD%^%^YELLOW%^k%^WHITE%^e%^YELLOW%^y%^RESET%^,
ornate and gold. Written below the key in bold green ink
is the word %^BOLD%^%^GREEN%^KNOWLEDGE%^RESET%^. On the left page is a silver %^BOLD%^WHITE%^c%^BLACK%^r%^WHITE%^o%^BLACK%^w%^WHITE%^n%^RESET%^, adorned with %^GREEN%^emeralds, %^RED%^rubies,%^RESET%^ and %^BOLD%^%^WHITE%^diamonds%^RESET%^. Beneath 
the crown, %^BOLD%^%^BLUE%^POWER%^RESET%^ is written in bold blue.

MYLONG
	);
	set_limbs(({"left arm"}));
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

