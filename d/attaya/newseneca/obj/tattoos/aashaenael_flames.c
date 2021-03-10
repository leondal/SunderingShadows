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
	set_id(({ "tattoo" }));
	set_short("%^RESET%^%^RED%^huge %^BOLD%^s%^YELLOW%^w%^RESET%^%^RED%^i%^BOLD%^%^YELLOW%^r%^RESET%^%^RED%^l%^BOLD%^i%^YELLOW%^n%^RESET%^%^RED%^g %^BOLD%^f%^RESET%^%^RED%^l%^BOLD%^a%^YELLOW%^m%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^");
