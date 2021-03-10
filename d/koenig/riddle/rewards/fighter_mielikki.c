//fighter_mielikki.c - reward for Riddle Quest. Circe 2/5/04
//Thanks to Torm for describing this item!
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("mielikki hide");
	set_id(({"hide","leaf armor","laced leaf armor","armor"}));
	set_short("%^RESET%^%^GREEN%^L%^ORANGE%^a%^GREEN%^c%^RED%^e%^BOLD%^"+
         "%^GREEN%^d%^RESET%^%^ORANGE%^ L%^GREEN%^e%^RED%^a%^ORANGE%^f "+
         "%^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^r%^RED%^m%^ORANGE%^o%^BOLD%^"+
         "%^GREEN%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^Leaf Armor%^RESET%^");
	set_long(
@CIRCE
%^GREEN%^This armour is made of thick fibrous l%^ORANGE%^e%^RED%^a%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^es that have been laced together with %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^eel wire%^RESET%^%^GREEN%^.  Row upon row of leaves have been laced together so that they overap one another.  The steel wire keeps the armour in shape as well as reinforcing the lea%^ORANGE%^t%^RED%^h%^GREEN%^ery leaves.
CIRCE
	);
	set_lore(
@CIRCE
%^GREEN%^The design of this armour has been attirbuted to Hickran Yelso, a ranger of Mielikki.  He observed a young doe seeking protection from the elements beneath the canopy of overlapping braches of a group of trees and cited this as his inspiration.  He sought to emulate the natural instinct of the forest creatures he was dedicated to protecting from harm.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^GREEN%^You notice the a%^RED%^u%^GREEN%^tum%^ORANGE%^n%^GREEN%^al "+
         "colors of the leaves as you remove the armor.%^RESET%^");
}
