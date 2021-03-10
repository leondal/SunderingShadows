//ranger_helm.c - Reward for Riddle Quest. Cythera 4.05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("helm bow");
   set_id(({"steel longbow","bow","longbow","long bow","bow of vigilance","steel bow"}));
   set_obvious_short("%^RESET%^%^CYAN%^A steel longbow%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Bow of %^RESET%^V%^CYAN%^i%^RESET%^g"+
		"%^CYAN%^i%^RESET%^l%^CYAN%^a%^RESET%^n%^CYAN%^c%^RESET%^e");
   set_long("%^CYAN%^Fashioned from steel, this martial looking bow "+
		"only slightly resembles those made of wood.  The curved "+
		"metal has been hammered and manipulated to create the "+
		"typical shape of a long bow.  The steel has been polished"+
		" to a %^BOLD%^glossy%^RESET%^%^CYAN%^ sheen, as is the "+
		"case with all weapons and armor in Helm's faith.  Pressed"+
		" into the metal above and below the %^BLUE%^steel blue%^CYAN%^"+
		" handgrip is the image of a gauntlet fist with a blue eye, "+
		"the symbol of Helm.\n%^RESET%^");
   set_lore("The Foresters of Vigilance is a very tiny and small order"+
		" in the Watcher's faith.  Seeking to carry the message of"+
		" guardianship and vigilance to the forest, the rangers "+
		"often serve as guides and body guards for those that have"+
		" to travel through wild woods.  The Foresters of Vigilance"+
		" are all known for the steel long bows they carry and the"+
		" suits of chain mail that they wear, forsaking the typical"+
		" ranger's leather armor.");
   set_property("lore difficulty",12);
	set_unwield("%^CYAN%^You relax your guard as you put your bow away.");
}