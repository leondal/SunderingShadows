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
	set_id(({ "asmodeus", "tattoo of asmodeus", "tattoo", "symbol of asmodeus", "symbol" }));
	set_short("%^BOLD%^%^BLACK%^a d%^RED%^e%^BLACK%^v%^RESET%^%^RED%^i%^BOLD%^%^RED%^l%^BLACK%^i%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^h symbol%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^This brand is a symbol whose meaning as been lost to most. Three black triangles of burnt flesh meet together forming one larger one. The bottom two of these triangles are larger and of equal size, mirroring eachother and coming together, with the up triange being smaller and fitting into the other two. The brand forever looks painful and fresh, as if it was just done.%^RESET%^

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
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

