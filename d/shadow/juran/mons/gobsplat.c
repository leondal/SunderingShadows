#include <std.h>
#include "../juran.h"
inherit VENDOR;

void create() {
	::create();
	set_name("Gobsplat");
	set_short("Gobsplat the Merciless");
	set_id(({"monster","Gobsplat","gobsplat","bugbear","shopkeeper","shop keeper"}));
    	set_long(
   		"Gobsplat is large for even a bugbear standing no less than 8' "+
   		"tall, but he looks to be the oldest bugbear you have ever seen "+
   		"as well.  Wearing armor with many cuts, burns, and dents this "+
   "bugbear's armor looks to have been through many battles.  Gobsplat "+
   		"moves about his shop slowly and occassionally groans from an old "+
   		"ache come to haunt him.  He will gladly show you anything in the "+
   		"store and let you walk out with it if the price is right."
    	);
	set_race("bugbear");
	set_gender("male");
	set_alignment(3);
	set_size(3);
	set_hd(19,5);
	set_items_allowed("weapon");
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_storage_room(JSTORE+"weapon_storage");
   	set_exp(100);
	remove_std_db();
     	set_spoken("wizish");
   set_nwp("weaponsmithing",20);
}
