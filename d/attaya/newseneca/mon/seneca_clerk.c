#include <std.h>

inherit VENDOR;

void make_me();

void create() {
  ::create();
   make_me();
   set_hd(16,2);
   set("aggressive", 0);
   set_level(16);
   set_class("fighter");
   set_mlevel("fighter", 16);
   set_guild_level("fighter",16);
   set_alignment(5);
   set_race("human");
   add_money("gold", random(100));
   set_mob_magic_resistance("average");
   set_overall_ac(-15);
   set_stats("strength",18);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_property("full attacks",1);
   set_storage_room("/d/attaya/newseneca/storage/general");
   set_items_allowed("misc");
}

void make_me() {
   switch(random(2)) {
      case 0:
	set_name("Dulce Montero");
	set_id(({"shop clerk","shopkeeper","clerk", "dulce", "Dulce","dulce montero","montero","gstorekeeper"}));
	set_short("Dulce Montero, the shop clerk");
	set_long("Dulce Montero is an aging woman with fine lines "+
         "around her eyes and mouth.  She has long, chestnut brown "+
         "hair that curls down to the small of her back.  She keeps "+
         "it pulled back loosely and tied with a ribbon, making her "+
         "seem just a bit younger.  Her coffee eyes are intelligent "+
         "and kind, but she watches the store with the air of a shopkeeper "+
         "who will brook no theft."
	);
      set_gender("female");
	break;
     case 1:
	set_name("Bolivar Montero");
	set_id(({"shop clerk","shopkeeper","clerk", "bolivar", "Bolivar","bolivar montero","montero","gstorekeeper"}));
	set_short("Bolivar Montero, the shop clerk");
	set_long("Bolivar's salt-and-pepper hair reveals his advancing "+
         "years, as do the lines around his watery green eyes.  "+
         "He is a friendly man with an ever-present smile, and "+
         "he dresses simply, wearing leather breeches and a "+
         "cotton shirt.  He runs the shop with quiet efficiency, "+
         "and it is he who demands it be kept in such meticulous "+
         "order.");
      set_gender("male");
	break;
   }
}
