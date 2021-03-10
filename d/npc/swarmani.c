#include <std.h>;

inherit VENDOR;

void create() {
  	::create();
   set_name("Swarmani Menderson");
   set_id( ({ "Swarmani", "swarmani", "swarmani menderson", "Swarmani Menderson", "seller","cloth seller"}) );
   set_short("Swarmani Menderson, seller of fine cloths");
   set_level(19);
   set_long(
		"This handsome, middle aged woman is bent with many bolts "+
		"of cloth. She prides herself in having the best selection of materials. "+
		"Her hair is black and long and a hint if slightly pointed ears "+
		"sticks out of her hair. <help shop>"
   );
   set_gender("female");
   set_alignment(2);
   set_race("half-elf");
   set_body_type("human");
   set_storage_room("/d/npc/storage/swarmani_storage");
   set_hd(19,3);
   set_exp(10);
// set_property("generic db", 1);  // don't want them to have this on actually
   set_items_allowed("material");
   set_speed(80);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
//  "daemon/place_d"->place_in("/d/antioch/antioch2/rooms/",TO);
}

