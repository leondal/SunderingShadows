#include <std.h>

#define SCITY "/d/shadow/room/city/"
#define TCITY "/d/tharis/Tharis/"

inherit VENDOR;

void create() {
	::create();
   set_name("Billeas Hammerforge");
   set_id(({ "Billeas", "billeas", "billeas hammerforge", "Billeas Hammerforge","metal","metal seller"}) );
   set_short("Billeas Hammerforge, purveyor of fine metals");
   set_long(
   	"This dwarf is stooped from the great weight in the sacks he "+
   	"carries.  He is very broad in the shoulders, even for a dwarf "+
   	"and corded muscles bulge along his bare arms as he adjusts the "+
   	"sacks.  His sacks are filled with billets of different kinds of "+
   	"metals that he is offering for sale. <help shop>"
      );
  set_race("dwarf");
  set_level(19);
  set_gender("male");
  set_alignment(2);
  set_storage_room("/d/npc/storage/billeas_storage");
  set_hd(19,3);
  set_max_hp(150);
  set_hp(150);
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

