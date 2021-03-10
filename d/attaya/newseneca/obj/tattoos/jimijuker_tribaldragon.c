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
	set_id(({ "tattoo", "tribaldragon" }));
	set_short("A huge FULL-SLEEVE, SOLID-BLACK TRIBAL TATTOO OF A DRAGON SWIRLING AROUND THE LEFT ARM");
	set_long(
@MYLONG
This highly detailed and masterfully done tattoo is that of Fuku-riu, a dragon of lore and ledgend. The solid black color of the tat signifies wisdom. The design of the tattoo expresses fearlessness and power. and the choice of the dragon brings luck and fortune.

MYLONG
	);
	set_limbs(({"left arm"}));
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

