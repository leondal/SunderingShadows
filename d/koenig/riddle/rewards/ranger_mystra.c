//ranger_mystra.c - Reward for Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("mystra bow");
   set_id(({"ornate longbow","bow","longbow","long bow","star","shooting star"}));
   set_obvious_short("An ornate longbow");
   set_short("%^RESET%^%^CYAN%^S%^BOLD%^h%^RESET%^%^BLUE%^o%^BOLD%^o%^CYAN%^t%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^g %^BOLD%^%^CYAN%^Star%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^This unusual longbow is made of several enlongated carvings of %^BOLD%^%^BLUE%^stars %^WHITE%^fused together.  There are nine %^BOLD%^%^BLUE%^stars %^WHITE%^all together.  Each one is made of dark wood that has been lacquered a %^BLUE%^deep blue %^WHITE%^and edged in %^RESET%^silver %^BOLD%^that sparkles when the light hits it.  The handle of the bow is made of %^RED%^cherry %^WHITE%^and is carved simply.  The bow string is a %^CYAN%^silvery blue %^WHITE%^and looks to be made of electrum, although it feels quite soft.
CIRCE
   );
   set_lore(
@CIRCE
Most rangers of Mystra belong to the Order of the Shooting Stars, and a bow that looks much like this one is often granted to new rangers who enter the order.  Most such rangers stain their arrows red and fit them with red fletchings to complete the look of Mystra's holy symbol when the bow is fired.  It is said that the power of Mystra is focused in these bows, and that rangers who wield them in her name can sometimes perform great feats.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^BOLD%^%^CYAN%^The power of magic leaves you as you lower the bow.");
}