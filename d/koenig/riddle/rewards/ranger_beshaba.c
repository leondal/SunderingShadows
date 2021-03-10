//ranger_beshaba.c - Reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("beshaba bow");
   set_id(({"bow","longbow","long bow","blackhorn bow","horn bow"}));
   set_obvious_short("%^BOLD%^%^BLACK%^A glossy black bow%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Blackhorn Bow%^RESET%^");
   set_long(
@CYTHERA
%^BOLD%^%^BLACK%^Fashioned out of a long horn, this long bow has a %^RESET%^g%^BOLD%^l%^RESET%^o%^BOLD%^s%^RESET%^s%^BOLD%^y%^BOLD%^%^BLACK%^ finish to it.  The ends of the bow features black spikes, similar to the points on antlers.  The horn bow has been left rough and uneven, letting the rippling texture come through.  In the center of the bow a %^BOLD%^%^MAGENTA%^mauve%^BOLD%^%^BLACK%^ strip of leather creates a handhold.  Strung with a thick ebony black string, the bow almost seems to laugh in a manic tone when released.%^RESET%^
CYTHERA
   );
   set_lore(
@CYTHERA
The Blackhorn Bow was used by a very small band of rangers that were dedicated to The Maid of Misfortune, Beshaba.  Seeking to show the calamities and unlucky side of nature, the rangers preyed on travelers in the woods.  The Blackhorn Agents as they came to be known were some of the most feared and dreaded rangers.  Not because they were savage and brutal like those that followed Malar, Talos or Auril, but because everyone was a target for their 'gifts'.
CYTHERA
   );
   	set_property("lore difficulty",12);
	set_unwield("%^BOLD%^%^BLACK%^You release the bow, but know your time to spread more misfortune will come soon.");
}