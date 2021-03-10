#include "../newbie.h"

inherit "/std/vendor";

void create(){
   ::create();
   set_name("Nicculis Chaw");
   set_short("Nicculis Chaw, the clerk of Offestry Armory");
   set_long("This man is rather short, only about 5 feet tall.  His "
	"hands are rough from years of metalworking.  Although in his "
	"sixties, he is still muscular and agile.  He can easily lift "
	"a suit of very heavy plate armor.  He has been keeping this "
	"armory for so many years, he is very knowledgable about all "
	"kinds of armour that has been found in the realms. If you are "
	"interested in certain piece of armour in the shop, Nicculis "
	"is willing to show it to you before you want to buy it with "
	"your hard earned coins.");
   set_race("human");
   set_id(({"nicculis","chaw","Nicculis","clerk","armorer"}));
   set_gender("male");
   set_alignment(2);
   set_hd(19,4);
   set_items_allowed("armor");
   set_max_hp(200);
   set_hp(200);
   set_exp(10);
   set_storage_room(ROOMS"special/armor_storage");
   set_db("armors");
   set_nwp("armorsmithing", 4);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}
