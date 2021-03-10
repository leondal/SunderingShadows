#include <std.h>
#include "../juran.h"
inherit VENDOR;

void create() {
	::create();
	set_name("Gratus");
	set_short("Gratus the skinflint");
	set_id(({"monster","Gratus","gratus","skinflint","shopkeeper","shop keeper"}));
    	set_long(
   		"Gratus is a bumbling greedy goblin of about 20 years of age. He "+
   		"tends the store with a careless manner.  He is dressed in skins "+
   		"and beads and covered in tribal runes.  He seems willing to sell "+
   		"you anything he has if the money is right."
    	);
	set_race("goblin");
	set_gender("male");
	set_alignment(3);
	set_size(1);
	set_hd(19,5);
	set_items_allowed("misc");
	set_max_hp(200);
	set_hp(200);
	set_exp(100);
	set_storage_room(JSTORE+"general_storage");
   	set_exp(100);
     	set_spoken("wizish");
	remove_std_db();
//   set_nwp("fast talking",20);
}
