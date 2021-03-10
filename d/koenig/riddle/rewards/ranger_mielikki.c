//ranger_mielikki.c - Reward for Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("mielikki bow");
   set_id(({"carved oak longbow","bow","longbow","long bow","leaf","golden leaf","leaf bow"}));
   set_obvious_short("A carved oak longbow");
   set_short("%^RESET%^%^GREEN%^Bow of the %^YELLOW%^Golden %^GREEN%^L%^YELLOW%^e%^GREEN%^a%^YELLOW%^f%^RESET%^");
   set_long(
@CIRCE
%^WHITE%^The blonde wood of the oak has been varnished and polished to a high shine to make this bow.  The bow curves elegantly, reflecting the simple beauty of nature.  It is uncarved, save for the handle, which has been shaped into a beautiful folded %^YELLOW%^golden leaf%^RESET%^.  The leaf is unlike any you have ever seen before, and it seems to combine qualities of the oak, sycamore, and maple leaves.  The bow is relatively simple and radiates a subtle song of the woods.
CIRCE
   );
   set_lore(
@CIRCE
By far the most plentiful of the rangers, those who follow Mielikki are often thought to be the "true" rangers.  Ever protective of the forest, they spend much of their time walking the woods and tending to the animals.  This bow, simple though it appears, has a long history.  Ramiel Falthorn, a human ranger who spent his life in Mielikki's service, first crafted the bow after having a dream in which he walked beneath trees bearing such leaves at the side of a great unicorn.  A full year was spent on the crafting of this bow, and when it was finished, Ramiel fell asleep in a grove somewhere west of the Echoes Mountains.  He dreamt again that the unicorn walked with him, and when he awoke, the bow was glowing in his hands.  The tree in the midst of the grove had changed as well, splitting and bearing a carved unicorn's head.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^GREEN%^You hear a sound of leaves rustling as you set aside the bow.");
}