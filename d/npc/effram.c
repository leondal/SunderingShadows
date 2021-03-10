#include <std.h>;

inherit VENDOR;

void create() {
	::create();
   set_name("Effram Smithson");
   set_id(({ "Effram", "effram", "effram smithson", "Effram Smithson","dealer","metal dealer"}) );
   set_short("Effram Smithson, metal dealer");
   set_long(
   	"Effram is bent over and perspiring from the weight of the "+
   	"sacks of metals he carries.  He is middle-aged, sandy-blonde "+
   	"with a scraggly beard.  His skin is ruddy and wrinkled from "+
   	"the sun. <help shop>"
      );
  set_race("human");
  set_level(19);
  set_gender("male");
  set_alignment(2);
  set_storage_room("/d/npc/storage/effram_storage");
  set_hd(19,3);
  set_exp(100);
  set_speed(100);
// set_property("generic db", 1);  // don't want them to have this on actually
   set_items_allowed("material");
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
//  "daemon/place_d"->place_in("/d/dagger/Daggerdale/streets/",TO);
}

