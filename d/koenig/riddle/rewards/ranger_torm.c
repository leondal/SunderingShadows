//ranger_torm.c - reward for Riddle Quest. Circe 1/25/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("torm hide");
	set_id(({"hide","cord","cord armor","golden cord","lion","lion armor"}));
	set_short("%^BOLD%^%^RED%^Heart %^YELLOW%^of the Lion%^RESET%^");
	set_obvious_short("A suit of cord armor");
	set_long(
@CIRCE
%^YELLOW%^This armor is made up of thick cording that may be wrapped around the wearer to fit him perfectly.  The cord is light cream and seems to resist any stain of dirt or blood.  Woven throughout the cream-colored fibers are tiny threads of gold that give the armor a burnished appearance.  The armor is thin and could be easily worn under clothing so that the one wearing it could still hide in his surroundings.  Cord armor is favored by some warriors for its ease of movement, although it does not offer as much protection from crushing blows as plate.
CIRCE
	);
	set_lore(
@CIRCE
The golden-hued cord armor was first granted to Madison Rivenfel, a female ranger of Torm.  Through Madison's tireless efforts, the huge forests west of Shadow were preserved from the logger's axe, and the city of Shadow itself was built where it now stands.  She worked from the shadows, taking little credit for herself, but it was her decisions and wisdom that allowed the forces of nature to co-exist with society.  Not long after the city of Shadow was built, a golden lammasu appeared to Madison and granted her the armor with a message of blessing from Torm.  Many of the faithful believe that the lammasu was Torm himself appearing in one of his favored forms.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^YELLOW%^You feel the strength of the lion recede but know the time will come to don the armor again.");
}
