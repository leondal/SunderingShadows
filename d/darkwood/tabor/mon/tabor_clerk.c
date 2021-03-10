#include <std.h>

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
   set_race("human");
   add_money("gold", random(100));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",18);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_storage_room("/d/darkwood/tabor/include/gstorage");
   set_items_allowed("misc");
   set_mymaxvalue(8);
}

void make_me() {
   switch(random(3)) {
      case 0:
	set_name("Miriam");
	set_id(({ "shop clerk","shopkeeper","clerk", "miriam", "Miriam","gstorekeeper"}));
	set_short("Miriam, the shop clerk");
	set_long("Miriam is a middle-aged woman who is beginning to "+
         "show signs of her age.  Her chestnut hair now has streaks "+
         "of gray, and signs of crow's feet can be seen around her "+
         "eyes.  She still has a kind smile, however, and she moves "+
         "well enough to keep the shop in order.  She is dressed "+
         "simply, wearing a well-made hemp dress with leather "+
         "shoes upon her feet."
	);
      set_gender("female");
	break;
     case 1:
	set_name("Toma");
	set_id(({ "shop clerk","shopkeeper","clerk", "Toma", "toma","gstorekeeper"}));
	set_short("Toma, the shop clerk");
	set_long("Toma is apparently of middle age, with a supple "+
         "frame and a few scars here and there. He was obviously "+
         "an adventurer himself at one point but has seemingly "+
         "retired and decided to sell his goods to the next "+
         "generation.  He is well dressed, but practically so, "+
         "always with a weapon of some sort easily at hand in "+
         "case of trouble.");
      set_gender("male");
	break;
     case 2:
	set_name("Aidan");
	set_id(({ "shop clerk","shopkeeper","clerk", "Aidan", "aidan","gstorekeeper"}));
	set_short("Aidan, the shop clerk");
	set_long("Aidan is a young man within his teens.  He has "+
         "curly blonde hair that he keeps cut short, presumably "+
         "to manage the curls.  He has freckles along the bridge "+
         "of his nose, and it seems he has taken this job to "+
         "talk with adventurers.  He'll tell anyone who'll listen "+
         "about his hopes of someday becoming an adventurer, but "+
         "sadly...dad says no.  Aidan is dressed in leather "+
         "breeches and a well-made shirt, and he seems to be from "+
         "a better class than most clerks.  Perhaps his father has "+
         "gotten him this job to keep him out of trouble.");
      set_gender("male");
	break;
   }
}

	
   