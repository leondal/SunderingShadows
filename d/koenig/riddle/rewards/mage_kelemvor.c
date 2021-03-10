//mage_kelemvor.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the gray");
	set_id(({ "robe", "robe of the gray" }));
	set_short("%^RESET%^Robe of the Gray%^RESET%^");
	set_obvious_short("A gray cotton robe");
	set_long(
@AVATAR
%^RESET%^This simple robe is lacking any trim, adornments, or decoration.  The blend of cotton and linen has been dyed a muted shade of gray.  The robe is cut in a simple, elegant shape.  Everything seems in near-perfect proportion, nothing too tight nor too loose, almost as if this robe had been tailor-made for you.  The inside of the robe is lined with a smooth cotton that carries a subtle print of a skeleton hand holding a set of balanced scales.  Other than the lining, the robe carries a somber feeling.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Gray is widely used by the faithful of Kelemvor in their mission to rid the world of undead and the nercromancers who create them.  Many of the magi in this order of Kelemvor's faith are, in fact, necromancers themselves, though called "White Necromancers".  These necromancers are commited to showing the world that necromancy does not need to be feared, it is those who abuse the magic to terrorize and distrupt nature that should be feared and hated.  With the aid of the Mystrans, the Mages of Kelemvor will indeed one day rid the world of the blight of the undead.  Be proud, you are one of them now.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^RESET%^You slip out of your robe, but know the time will soon come that you must wear them again.");
	return 1;
}
