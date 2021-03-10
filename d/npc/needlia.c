#include <std.h>;

inherit VENDOR;

void create() {
  	::create();
   set_name("Needlia Brisbane");
   set_id( ({ "Needlia", "needlia", "needlia brisbane", "Needlia Brisbane","cloth seller", "seller"}) );
   set_short("Needlia Brisbane, seller of fine cloths");
   set_long(
		"This comely, young woman is bent with many bolts "+
		"of cloth. She prides herself in having the best selection of materials. "+
		"Her hair is blonde, the color of straw, and long tied back with "+
		"a red silk ribbon. <help shop>"
   );
   set_gender("female");
   set_alignment(2);
   set_race("human");
   set_level(19);
   set_storage_room("/d/npc/storage/needlia_storage");
   set_hd(19,3);
   set_exp(100);
// set_property("generic db", 1);  // don't want them to have this on actually3
   set_items_allowed("material");
   set_speed(80);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
//   "daemon/place_d"->place_in("/d/dagger/Daggerdale/streets/",TO);
}

