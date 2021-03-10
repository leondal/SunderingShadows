#include <std.h>
#include "../lothwaite.h"

inherit VENDOR;

void make_me();

void create() {
  ::create();
   make_me();
   set_hd(16,2);
   set("aggressive", 0);
   set_level(16);
//   set_gender("male");
   set_class("mage");
   set_mlevel("mage", 16);
   set_guild_level("mage",16);
   set_alignment(5);
   set_race("firbolg");
   set_size(3);
   add_money("gold", random(100));
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",19);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_storage_room(STORAGE"general_storage");
   set_items_allowed("misc");
}

void make_me() {
   if(!query_night()){
	set_name("Andreas");
	set_id(({ "shop clerk","shopkeeper","clerk", "andreas", "Andreas","gstorekeeper"}));
	set_short("Andreas, an aging shop clerk");
	set_long("Andreas is an aging firbolg with long gray "+
         "hair worn loose around his broad shoulders.  He "+
         "can always be found sitting in his wicker chair when "+
         "he is at work, though he has taken on a few helpers to "+
         "aid him in his task.  His light blue eyes still glitter "+
         "with a shrewd intelligence, and they twinkle when he "+
         "flashes his easy smile.  His thin skin is wrinkled, but "+
         "the angles of his face hint that he was once quite attractive.  "+
         "He is still very helpful to his customers, and he will most "+
         "likely answer any questions you have."
	);
      set_gender("male");
   }else{
	set_name("Eileen");
	set_id(({ "shop clerk","shopkeeper","clerk", "Eileen", "eileen","gstorekeeper"}));
	set_short("Eileen, a young shop clerk");
	set_long("Eileen is a very young firbolg - the rosy glow of "+
         "her cheeks hints that she is still within her teens.  She "+
         "has come to help her aging great uncle with his shop, and "+
         "she is quite efficient in her tasks.  She has long auburn "+
         "hair that falls in waves to her waist, and her thin frame "+
         "is rather unusual among firbolg women.  She wears a ready "+
         "smile and a cheerful expression.");
      set_gender("female");
   }
}

	
   