#include <std.h>
#include "../newbie.h"
inherit VENDOR;

void create() {
	::create();
      set_items_allowed("misc");
	set_name("Jake");
	set_short("Jake Feldspar, halfling musician");
	set_id(({"Jake","Jake Feldspar","jake","halfling","musician","halfling musician","bard"}));
	set_long("%^RESET%^%^CYAN%^Jake is a young halfling with a constant look of %^YELLOW%^energy %^RESET%^%^CYAN%^and "
"mischief about him.  A rogueish grin regularly lights his face as he espies a customer, while his nimble fingers are "
"often heard clicking together a series of %^ORANGE%^hollow wooden blocks %^CYAN%^with surprising dexterity.  His "
"garments are as bright as the store, entirely mismatched but %^BOLD%^%^MAGENTA%^cheerful %^RESET%^%^CYAN%^nonetheless.");
	set_race("halfling");
	set_gender("male");
	set_alignment(5);
	set_hd(19,2);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_storage_room(ROOMS"special/instrument_storage");
      new("/d/newbie/obj/misc/lpouch.c")->move(TO);
}
