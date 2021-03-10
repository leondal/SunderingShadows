//ranger_oghma.c - Reward for Riddle Quest.  Circe 4/25/05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
   set_name("bow");
   set_id(({"bow","longbow","long bow","precise shot","shot","yewbow"}));
   set_obvious_short("a well-made yewbow");
   set_short("%^MAGENTA%^Pre%^BOLD%^c%^RESET%^%^MAGENTA%^ise %^BOLD%^Shot%^RESET%^");
   set_long(
@CIRCE
%^YELLOW%^This bow is made of aged yewood, considered by bowman to be one of the best materials available.  It has been formed over time, with great care taken in making sure that every curve and layer was perfected.  The bow is free from carvings, and it features a %^WHITE%^mithril grip %^YELLOW%^and %^WHITE%^arrow rest%^YELLOW%^.  The rest supports a most unusual creation - some sort of curved %^CYAN%^glass lens%^YELLOW%^ marked with tiny scratches evenly spaced.%^RESET%^
CIRCE
   );
   set_lore(
@CIRCE
This bow's name says it all.  It is called Precise Shot because that is what it allows.  The curved glass was invented by the Gnomish Experimenters' League in the year 648 SG.  The League has an arrangement with the church of Oghma to share all knowledge they gain, with the natural reciprocation by the Oghmanytes.  It is through this agreement that the gnomes have begun outfitting the small band of rangers with these new bows.  Rangers of Oghma are collectively known as Fellows of the Forest, and they typically serve as collectors and cataloguers of nature rather than defenders.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^MAGENTA%^You can't help but marvel at the craftsmanship of the bow as you set it aside.");
}