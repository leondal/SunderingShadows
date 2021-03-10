#include <std.h>

#define SCITY "/d/shadow/room/city/"
#define TCITY "/d/tharis/Tharis/"

inherit VENDOR;

void create() {
	::create();
   set_name("Cutter Woodbane");
   set_id(({ "Cutter", "cutter", "cutter woodbane", "Cutter Woodbane","wood","wood seller"}) );
   set_short("Cutter Woodbane, seller of fine woods");
   set_long(
   	"This man carries many sacks filled with blocks of wood.  "+
   	"He prides himself on having a large selection of different "+
   	"woods in his inventory.  He wears a wool shirt, wool pants, "+
   	"and a leather apron with a few tools protruding.  He is "+
   	"tanned from his days in the outdoors and his hair shows "+
   	"signs of his advancing years. <help shop>"
      );
  set_race("human");
  set_level(19);
  set_gender("male");
  set_alignment(2);
  set_storage_room("/d/npc/storage/cutter_storage");
  set_hd(19,3);
  set_hp(250);
  set_max_hp(250);
  set_exp(10);
//  set_property("generic db", 1);
  set_items_allowed("material");
  set_speed(80);
  set_nogo( ({ SCITY+"westgate", SCITY+"cguild/cleric/cleric1", SCITY+"southgate",
	SCITY+"entrance", SCITY+"eastgate", "/d/shadow/room/main/northgate", 
	TCITY+"tower6", TCITY+"tower1", TCITY+"tower9", TCITY+"tower4" }) );

/* changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
  if (random(2)) {
  	"daemon/place_d"->place_in("/d/shadow/room/city/",TO);
  }else {
  	"daemon/place_d"->place_in("/d/tharis/Tharis/",TO);
  }
*/
}

