//fighter_selune.c - reward for Riddle Quest. Circe 2/5/04
//Thanks to Torm for describing this item!
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("selune hide");
	set_id(({"hide","leather","studded","moonstone studded","studded leather","armor"}));
	set_short("%^BOLD%^%^WHITE%^Mo%^MAGENTA%^o%^WHITE%^nstone "+
         "Stu%^CYAN%^d%^WHITE%^ded Leath%^GREEN%^e%^WHITE%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Moonstone Studded Leather%^RESET%^");
	set_long(
@CIRCE
%^BOLD%^%^WHITE%^This is a suit of studded leather armor.  The be%^MAGENTA%^z%^WHITE%^ainted discs that are secured to the leather with metal studs are made from polished m%^CYAN%^o%^WHITE%^onstone.  This combination of materials helps to keep the armor light and adds a distinctive sheen which is particularly apparent in moonli%^YELLOW%^g%^WHITE%^ht.
CIRCE
	);
	set_lore(
@CIRCE
%^BOLD%^%^WHITE%^It is said that over 500 individual moonstone gems were used to create all the discs for this suit of armor, and each one was blessed by the temple of Selune.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^BOLD%^%^WHITE%^You polish a couple of the "+
         "d%^GREEN%^i%^WHITE%^scs when you remove the armor%^RESET%^");
}
