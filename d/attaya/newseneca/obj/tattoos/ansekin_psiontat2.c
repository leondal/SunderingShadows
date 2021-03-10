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
	set_id(({ "tattoo", "huge tattoo", "skullcap tattoo", "psion tattoo" }));
	set_short("a huge tattoo covering his head beneath his hair");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The tattoo is made with thick black lines, strange %^RESET%^%^CYAN%^glyphs%^BOLD%^%^BLACK%^, and an unknown language using mathematical symbols the tattoo appears to fit somewhat like a skullcap existing almost entirely beneath the hairline.  The bold lines and symbols focus on a rendition of an eye centered just above his forehead.

MYLONG
	);
	set_limbs(({"head"}));
	set_wear((:TO,"wear_me":));
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

