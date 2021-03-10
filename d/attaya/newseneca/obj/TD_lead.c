#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("hot lead");
	set_id(({ "pot", "lead", "hot lead", "pot of lead" }));
	set_short("%^BOLD%^%^BLACK%^a pot of lead%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a pot of lead%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This small pot is made of cast iron and resembles a small hand held cauldron.  A metal handle is affixed to either side and loops over the top allowing the pot to be suspended over a fire by hooking the handle onto a hook or spit.  Within the pot are several marble sized pieces of %^RESET%^lead%^BOLD%^%^BLACK%^.  When set over a flame, these small balls of %^RESET%^lead %^BOLD%^%^BLACK%^heat quickly and turn into a liquid much like %^RESET%^q%^BOLD%^%^BLACK%^u%^RESET%^i%^BOLD%^%^WHITE%^c%^RESET%^k%^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^e%^RESET%^r %^BOLD%^%^BLACK%^that can then be used to pour over a victim's flesh causing excruciating pain as it first burns and then quickly hardens into the skin, making the removal equally as painful.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(20);
}