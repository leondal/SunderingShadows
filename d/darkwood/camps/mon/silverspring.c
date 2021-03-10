#include <std.h>
inherit VENDOR;

void create() {
   ::create();
   set_name("silverspring");
   set_short("Elderthanal Silverspring");
   set_id(({"vendor","jeweler","elderthanal","silverspring"}));
   set_long(
      "Elderthanal Silverspring is a famous elven jeweler in these"+
      " parts. He is known for the quality, creativity, and thought"+
      " he puts into each piece he crafts. He has shortly cut black"+
      " hair and sparkling emerald eyes. He is garbed in colorful"+
      " clothing that he probably had custom made. He travels around"+
      " town selling his pieces to those who are intrested."
   );
   set_race("elf");
   set_gender("male");
   set_hd(10,5);
   set_max_hp(100);
   set_hp(100);
   set_alignment(4);
   set_overall_ac(5);
   set_level(10);
   set_exp(1);
   set_property("swarm",0);
   remove_std_db();
   remove_dbs(({"tailor"}));
   remove_random_act_dbs(({"tailorrandom"}));
   set_items_allowed("jewelry");
   set_storage_room("/d/darkwood/camps/rooms/special/jewl_storage.c");
   set_nwp("jewelling",18);
   set_mymaxvalue(15);

}
