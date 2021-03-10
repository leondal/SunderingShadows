#include <std.h>
#include "../newbie.h"
inherit VENDOR;

void create() {
	::create();
        set_items_allowed("clothing");
	set_nwp("tailoring",0);  // items allowed clothing auto sets tailoring
        set_nwp("jewelling",4);  // has to go after set_items to over-ride default
	set_name("Selyvia");
	set_short("Selyvia, the talented jeweler of Offestry");
	set_id(({"Selyvia","selyvia","jeweler","shop keeper","shopkeeper","talented jeweler"}));
	set_long(
	"Selyvia is a rather nice looking young woman who has devoted her life to the"+
   " craft of jewelry. Her delicate hands have created all the splendid pieces"+
   " of jewelry in this shop. She is even wearing some of her own work, a silver"+
	" flower clasp holds her thick, dark hair back in a pretty fashion. There is"+
	" a fine silver necklace around her neck, and several sparkling bracelets on"+
	" her wrists. She obviously keeps the best pieces for herself, but anything"+
	" that's for sale she is willing to show to you so you can see what you're"+
	" getting before you spend a lot of money to buy it."
	);
	set_race("human");
	set_gender("female");
	set_alignment(2);
	set_hd(19,2);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_storage_room(ROOMS"special/jeweler_storage");
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}
