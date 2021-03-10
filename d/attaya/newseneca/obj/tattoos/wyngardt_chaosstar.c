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
	set_id(({ "chaosstar", "tattoo" }));
	set_short("%^BOLD%^%^RED%^a huge intricate %^CYAN%^c%^RED%^h%^CYAN%^a%^RED%^o%^CYAN%^s %^RED%^star tattoo");
