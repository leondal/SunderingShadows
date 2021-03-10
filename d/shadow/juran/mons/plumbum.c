#include <std.h>
#include "../juran.h"
inherit VENDOR;

void create() {
	::create();
	set_name("Plumbum");
	set_short("Plumbum the Greedy");
	set_id(({"monster","Plumbum","plumbum","goblin","shopkeeper","shop keeper"}));
    	set_long(
   		"Plumbum is a small green goblin.  Tufts of white hair poke "+
   		"upward from the tops of his ears and several types of bones "+
   		"and beads are strung together to make the many necklaces that "+
   		"adorn his neck.  Plumbum continually wrings his hands while "+
   		"you look over his wares and even drools greedily as you look "+
   		"over the more pricey items."
    	);
	set_race("goblin");
	set_gender("male");
	set_alignment(3);
	set_size(1);
	set_hd(19,5);
	set_items_allowed("armor");
	set_max_hp(200);
	set_hp(200);
	set_exp(1000);
	set_storage_room(JSTORE+"armor_storage");
	remove_std_db();
     	set_spoken("wizish");
   set_nwp("armorsmithing",20);
}
