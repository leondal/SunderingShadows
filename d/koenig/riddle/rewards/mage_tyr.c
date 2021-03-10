//mage_tyr.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robes of the hammer");
	set_id(({ "robe", "robe of the hammer" }));
	set_short("%^RESET%^%^BLUE%^Robe %^RESET%^of the %^MAGENTA%^Hammer%^RESET%^");
	set_obvious_short("A blue and purple striped robe");
	set_long(
@AVATAR
%^BLUE%^Sapphire blue%^RESET%^ and %^MAGENTA%^violet%^RESET%^ striped cotton has been used in the construction of this robe.  The stripes hang in a vertical fashion.  The robe seems cut in a style that makes it almost identical to any other robe one might find, other than the use of stripes, though upon a closer inspection there seems to be more than meets the eyes.  Interwoven in the %^BLUE%^sapphire blue%^RESET%^ and %^MAGENTA%^violet%^RESET%^ stripes there seems is a barely noticable tiny continious pattern of a warhammer.  To the naked eye and the general observer the image would not be seen, though it seems once you have knowledge of the pattern it becomes clear in similiar robes of this type.  A cotton %^BOLD%^white%^RESET%^ sash serves as a way to tie the robe closed.

AVATAR
	);
	set_lore(
@AVATAR
The Robes of the Hammer where first woven by Justinious Barthelmew, a Tyrran mage and judge who lived in Tharis.  Because of Justinious' faith and the seedy nature of Tharis, he knew that to so openly proclaim himself a Tyrran would lead to his death.  So he came up with a way to show his faith and to find others who were faithful to Tyr by hiding the image of Tyr's warhammer in the stripes of the robe.  His trick seems to have worked, for Justinious was able to deal with the criminals of Tharis for five years, until he caught a rare disease that took his life.  That was the first case of Jungle Rot that Tharis has seen, and the last it seems.  How odd.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^MAGENTA%^You slip the robe off, knowing soon the call of Tyr will go out and they will need to be used again.");
	return 1;
}
