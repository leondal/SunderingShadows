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
	set_id(({ "tattoo", "right eye" }));
	set_short("%^RESET%^%^ORANGE%^tiny right eye tattoo%^RESET%^");
	set_long(
@MYLONG
%^ORANGE%^You can't imagine the pain that must have been felt as a needle was carefully poked in and out of %^RED%^Verin's %^ORANGE%^right eye creating this $T tattoo.  Light and dark shades of brown have been placed all around the iris, being careful to leave the %^WHITE%^sclera %^ORANGE%^untouched.  A tiny %^BOLD%^%^RED%^red dot %^RESET%^%^ORANGE%^in the center serves reminder that these eyes aren't truly normal.  In some places around the iris, light splotches of %^RED%^red %^ORANGE%^still bleeds through.%^RESET%^

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

