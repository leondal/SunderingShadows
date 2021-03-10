#include <std.h>
#define SCITY "/d/shadow/room/city/"
#define TCITY "/d/tharis/Tharis/"

inherit VENDOR;

void create() {
   ::create();
   set_name("Finane Makehat");
   set_id( ({ "Finane", "finane", "finane makehat", "Finane Makehat","cloth","cloth seller"}) );
   set_short("Finane Makehat, seller of fine cloths");
   set_long(
@OLI
   This handsome, middle aged woman is bent with many bolts of cloth. She 
combs the world looking for the best cloth and then sells it to whomever
will buy it. Her long, silvered hair is tied back with a heavy scarf. A
worn but still lovely wool shawl covers her shoulders as she hefts the
collection of cloths. <help shop>
OLI
      );
   set_gender("female");
   set_alignment(2);
   set_race("human");
   set_level(19);
   set_storage_room("/d/npc/storage/finane_storage");
   set_hd(19,3);
   set_exp(10);
//   set_property("generic db", 1);
   set_items_allowed("material");
   set_speed(80);
   set_hp(150);
   set_max_hp(150);
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

