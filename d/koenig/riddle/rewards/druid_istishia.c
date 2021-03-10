//druid_istishia.c - reward for Riddle Quest. Circe 1/1/16
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
	set_id(({"armor","wooden armor","wood armor","ocean's embrace"}));
	set_short("%^RESET%^%^CYAN%^O%^BOLD%^c%^BLUE%^e%^RESET%^%^BLUE%^a%^RESET%^"
         "n%^CYAN%^'%^BOLD%^s %^BLUE%^E%^RESET%^%^BLUE%^m%^RESET%^b%^CYAN%^r"
         "%^BOLD%^a%^BLUE%^c%^RESET%^%^BLUE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A suit of armor made of overlapping "
         "b%^BOLD%^l%^BLUE%^u%^RESET%^%^BLUE%^e p%^BOLD%^l%^CYAN%^a%^RESET%^"
         "%^CYAN%^t%^BLUE%^e%^BOLD%^s%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This suit of armor has been cobbled from smooth "
         "layers of wood painted in various shades of %^BOLD%^b%^BLUE%^l%^RESET%^%^BLUE%^"
         "u%^CYAN%^e with hints of %^RESET%^wh%^BOLD%^i%^RESET%^te%^CYAN%^. "
         "The overall effect is one of the o%^BOLD%^c%^BLUE%^e%^RESET%^%^BLUE%^a%^RESET%^"
         "n%^CYAN%^ lapping the shore, %^RESET%^wh%^BOLD%^i%^RESET%^te%^BOLD%^c%^RESET%^"
         "ap%^BOLD%^s %^RESET%^%^CYAN%^breaking against pearlescent sand. Beneath the "
         "wood, a shirt and breeches of cotton help protect the wearer's skin and "
         "provide some measure of comfort.%^RESET%^");
	set_lore("Ocean's Embrace is the name given to those sets of armor gifted "
         "to druids who dedicate themselves to Istishia. The cunning design ensures "
         "that the wearer hears the call of the water, no matter how far inland they "
         "might be. It is said that Istishian craftsmen soak each piece of wood in "
         "saltwater, strengthening it and embuing it with the blessings of the Water Queen.");
      set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the wooden armor.");
}
