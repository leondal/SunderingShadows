#include <std.h>

inherit VENDOR;

create() {
	::create();
	set_name("Toma");
	set_id( ({ "toma", "clerk", "shop keeper", "shopkeeper"}) );
	set_short("Toma, the clerk of the Tabor Dry Goods Store");
	set("aggressive", 0);
	set_level(19);
   set_long("Toma is apparently of middle age, with a supple frame and a few"+
   " scars here and there. He was obviously an adventurer himself at one point"+
   " but has seemingly retired and decided to sell his goods to the next generation."+
   " He is well dressed, but practically so, always with a weapon of some sort"+
   " easily at hand in case of trouble.\n"+
	"<help shop> will get you a list of shop commands.\n");
	set_gender("male");
	set_alignment(2);
	set_race("human");
	add_money("gold", random(500));
	set_body_type("human");
	set_storage_room("/d/darkwood/tabor/include/gstorage");
	set_property("no attack", 1);
	set_hd(19,3);
	set_exp(10);
	set_items_allowed("misc");
	set_hp(200);
	set_max_hp(query_hp());
}
