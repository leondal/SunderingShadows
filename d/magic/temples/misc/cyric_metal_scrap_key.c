#include <std.h>

inherit OBJECT;

void create(){
	::create();
	
	set_name("jagged scrap of metal");
	set_id(({"scrap of metal", "scrap", "metal", "jagged scrap", "cyric_metal_scrap_key"}));
	set_short("%^BOLD%^%^WHITE%^ja%^RESET%^g%^YELLOW%^g%^WHITE%^ed "+
	"s%^RESET%^c%^BOLD%^r%^BLACK%^a%^WHITE%^p of m%^RESET%^e%^BOLD%^t%^RED%^a%^WHITE%^l%^RESET%^");

	set_long("%^RESET%^%^RED%^This long, %^BOLD%^%^WHITE%^ja%^RESET%^g%^YELLOW%^g%^WHITE%^ed "+
	"s%^RESET%^c%^BOLD%^r%^BLACK%^a%^WHITE%^p of m%^RESET%^e%^BOLD%^t%^RED%^a%^WHITE%^l "+
	"%^RESET%^%^RED%^has ridges and protrusions on one end. It could be some ruined piece "+
	"of %^RESET%^jewelry%^RED%^, but its original shape appears as lost as the "+
	"%^ORANGE%^corpse%^RED%^ from which it came. The scrap seems to faintly "+
	"%^CYAN%^thr%^BOLD%^%^GREEN%^u%^RESET%^%^CYAN%^m%^RED%^ in your hands with some "+
	"barely perceptible %^BOLD%^%^BLACK%^energy%^RESET%^%^RED%^.%^RESET%^");
	set_value(0);
	set_weight(1);
}

