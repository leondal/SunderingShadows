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
	set_value(15000);
	set_id(({ "tat", "tattoo", "small tat", "small tattoo", "skulltat" }));
	set_short("a small BLUEISH-SILVER tattoo");
	set_long(
@MYLONG
Its a tattoo of a gnome-skull and crossed-banjoleles. The ink is vivid and colorful. The skull is SILVER and the banjoleles are BLUE (a shiney BLUEISH-SILVER). Under the skull and cross-banjoleles are the words "BARD LIFE" tatted in bold BLUE. The tat is on the upper arm, near the shoulder.

MYLONG
	);
	set_limbs(({"right arm"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "small"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

