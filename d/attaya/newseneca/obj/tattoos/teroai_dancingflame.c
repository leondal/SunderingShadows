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
	set_id(({ "dancing flame tattoo", "tattoo" }));
	set_short("%^RESET%^A medium %^BOLD%^%^YELLOW%^f%^BOLD%^%^CYAN%^a%^BOLD%^%^YELLOW%^c%^BOLD%^%^CYAN%^e%^RESET%^ tattoo depicting %^BOLD%^%^RED%^Da%^BOLD%^%^YELLOW%^nc%^BOLD%^%^RED%^ing Fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^mes%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^RED%^This intricate face-tattoo covers nearly the entire right cheek and partly over the %^BOLD%^%^CYAN%^eye%^BOLD%^%^RED%^. The tatto depicts dancing %^BOLD%^%^YELLOW%^f%^RESET%^%^RED%^lam%^BOLD%^%^YELLOW%^es %^BOLD%^%^RED%^that contrast well with his obviously fire nature.

MYLONG
	);
	set_limbs(({"head"}));
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

