//ranger_tymora.c - Reward for Riddle Quest.  Circe 4/15/05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
   set_name("longbow");
   set_id(({"rosewood bow","bow","longbow","long bow","kismet's kiss","kiss"}));
   set_obvious_short("%^BOLD%^%^MAGENTA%^A carved rosewood longbow%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^K%^MAGENTA%^i%^CYAN%^s%^MAGENTA%^m%^CYAN%^e"+
      "%^MAGENTA%^t%^CYAN%^'%^MAGENTA%^s Kiss%^RESET%^");
   set_long(
@CIRCE
%^RESET%^%^MAGENTA%^This bow is made of fragrant %^BOLD%^rosewood %^RESET%^%^MAGENTA%^carved with fantastic %^BOLD%^%^CYAN%^symbols %^RESET%^%^MAGENTA%^with a slightly bluish cast.  The ends of the bow curve back toward the front, giving the bow the appearance of a recurve bow.  Slightly unusual, the string-nock has been plated with %^RESET%^silver %^MAGENTA%^etched with the image of a %^BOLD%^smiling woman's face%^RESET%^%^MAGENTA%^.  A grip of %^BOLD%^%^WHITE%^white leather %^RESET%^%^MAGENTA%^has been fitted in the middle of the bow.%^RESET%^
CIRCE
   );
   set_lore(
@CIRCE
Rangers of Tymora, while rare, fit in well with Lady Luck's charge.  They range far and wide, adventuring where few others dare.  Unlike the rest of Tymora's clergy, these members have a special affinity for nature.  Most choose one particular goal - whether it be defending a particular forest, saving a certain species of animal, or anything of the like - and focus much of their attention there.  Somehow, these rangers always seem to find a way to range far and wide to meet their goal, often exploring all of the known world - and sometimes finding many things unknown.
CIRCE
   );
   set_property("lore difficulty",12);
}