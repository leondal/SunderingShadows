#include <std.h>
inherit VENDOR;

void create() {
	::create();
      set_items_allowed("misc");
	set_name("Mayyadah");
	set_short("Mayyadah, artisan woodcrafter");
	set_id(({"Mayyadah","mayyadah","crafter","artisan","woodcrafter","bard"}));
	set_long("Mayyadah is a tall, lithe woman possessed of the olive skin more common in the desert reaches south of "
"the mountains.  Her short black hair is pulled away from her face with a wooden comb, revealing features that are "
"plain but not unpleasant upon the eye.  Her garments are simple and drab of hue, sleeveless so that her arms and hands "
"are left free for her work.  Slight calluses are visible on her fingers, hinting at a habit of work with her hands.");
	set_race("human");
	set_gender("female");
	set_alignment(5);
	set_hd(19,2);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_storage_room("/d/darkwood/tabor/include/instrument_storage");
}
