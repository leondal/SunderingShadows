#include <std.h>;

inherit VENDOR;

void create() {
	::create();
   set_name("Nulipseas Metalleaf");
   set_id(({ "Nulipseas", "nulipseas", "nulipseas metalleaf", "Nulipseas Metalleaf","metal dealer", "dealer"}) );
   set_short("Nulipseas Metaleaf, metal dealer");
   set_long(
   	"Nulipseas is a wood elf carrying several large sacks "+
   	"filled with metals.  His age is hard to determine as with "+
   	"many elves and he moves with the grace of an elf, even under "+
   	"the heavy burden of the sacks. <help shop>"
      );
  set_gender("male");
  set_alignment(2);
  set_race("elf");
  set_level(19);
  set_storage_room("/d/npc/storage/nulipseas_storage");
  set_hd(19,3);
  set_exp(10);
  set_moving(80);
// set_property("generic db", 1);  // don't want them to have this on actually
   set_items_allowed("material");
//  "daemon/place_d"->place_in("/d/antioch/antioch2/rooms/",TO);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
  
}

