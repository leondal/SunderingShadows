#include <std.h>
inherit VENDOR;

void create()
{
   ::create();
   set_name("Kedathia");
   set_short("Kedathia, a clothing vendor");
   set_id(({"vendor","clothing vendor","kedathia","Kedathia"}));
   set_long("Kedathia sells fine clothing here in the market place"+
   " of Daggerdale. She has curly brown hair that bounce down to"+
   " the middle of her back, and hazel eyes are set in a heart"+
   " shaped face. She always has a ready smile on her full lips."+
   " She tries her best to make clothes for all of the citizens"+
   " of Daggerdale and usually has a wide selection to choose from.");
   set_race("human");
   set_gender("female");
   set_hd(10,5);
	set_max_hp(50+random(25));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(5);
	set_level(10);
	set_exp(10);
	set_property("swarm",1);
   remove_std_db();
   remove_dbs(({"tailor"}));
   remove_random_act_dbs(({"tailorrandom"}));
   set_items_allowed("clothing");
   set_storage_room("/d/dagger/Daggerdale/shops/clothing.c");
	set("aggressive",0);
}
