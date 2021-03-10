#include <std.h>;

inherit VENDOR;

void create() {
	::create();
   set_name("Whitson Broadaxe");
   set_id(({ "Whitson", "whitson", "whitson broadaxe", "Whitson Broadaxe","seller","wood seller"}) );
   set_short("Whitson Broadaxe, seller of fine woods");
   set_level(19);
   set_long(
   	"This half-elf carries many sacks filled with blocks of wood.  "+
   	"He prides himself on having a large selection of different "+
   	"woods in his inventory.  He wears a wool shirt, wool pants, "+
   	"and a leather apron with a few tools protruding.  He is "+
   	"tanned from his days in the outdoors and his hair shows "+
   	"signs of his advancing years. <help shop>"
      );
  set_gender("male");
  set_alignment(2);
  set("race", "half-elf");
  set_body_type("human");
  set_storage_room("/d/npc/storage/whitson_storage");
  set_hd(19,3);
  set_exp(10);
  set_moving(80);
// set_property("generic db", 1);  // don't want them to have this on actually
  set_items_allowed("material");
  
// "daemon/place_d"->place_in("/d/antioch/antioch2/rooms/",TO);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03

}

