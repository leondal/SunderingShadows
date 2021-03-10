//ranger_selune.c - Reward for Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("selune bow");
   set_id(({"silver longbow","bow","longbow","long bow","moonbow","moon bow"}));
   set_obvious_short("A silver longbow");
   set_short("%^BOLD%^%^WHITE%^M%^RESET%^o%^BOLD%^o%^RESET%^n%^BOLD%^b%^RESET%^o%^BOLD%^w%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^This longbow is made of an unknown silver wood.  It is quite thin and looks delicate, but it can be pulled with great force.  There are no carvings along the smooth arms of the bow, but the handle bears carvings of all the phases of the moon.  The thickness of the bow is such that when the string is pulled fully, the string and bow seem to make a perfect circle, mimicing the full moon.
CIRCE
   );
   set_lore(
@CIRCE
Rangers of Selune dedicate themselves to the protection of the land, as do all rangers.  These, however, tend to focus on areas beset by evil lycanthropes and areas where the moon may shine down brightly upon the land.  They are often more concerned with valleys than forests, and so fill a niche much needed in the ranks of woodland protectors.  The first moonbow was carved by Alandrina the Fair, a female ranger of the Moonmaiden.  She was a great bowyer, and she made many attempts before she finally perfected her design - a bow which looked like the moon when it was being used.  Alandrina found great favor from her goddess, and she often heard whisperings and saw lights to guide her way to where she was most needed.  When she was older, she left the woods and spent the rest of her days contemplating the teachings of Selune and teaching all those younger than her the ways of the woods.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^BOLD%^The bow shimmers and then grows dim as you release it.");
}