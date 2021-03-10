#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("pillory");
	set_id(({ "pillory", "wooden restraint" }));
	set_short("%^RESET%^%^ORANGE%^a wooden pillory%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a wooden pillory%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This wooden device consists of a two foot wide beam which is split in half and has three holes through which a victim's head and hands can be placed.  When the top of the beam is lowered, this effectively traps the victim within its clutches.  The large beam is then secured by two %^BOLD%^%^BLACK%^metal locking devices%^RESET%^%^ORANGE%^, one to either side.  The beam can then be set upon supports, or suspended from %^CYAN%^metal chains %^ORANGE%^to raise or lower the trapped person's head and arms, thus straining the victim in additional manners by forcing them into uncomfortable positions, including suspending it from a ceiling so that they risk slow strangulation.%^RESET%^

AVATAR
	);
	set_weight(100);
	set_value(800);
}