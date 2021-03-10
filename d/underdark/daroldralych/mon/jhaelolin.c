#include <std.h>
#include "../defs.h"
inherit "/std/vendor";

void create() {
   ::create();
	set_name("Jhaelolin");
	set_id(({"shop clerk","shopkeeper","clerk","jhaelolin","smith"}));
	set_short("%^RESET%^%^BLUE%^Jhaelolin Aurach'nar, clerk of the Tempered Blaze%^RESET%^");
	set_long("%^BLUE%^Jhaelolin keeps her %^RESET%^pale hair %^BLUE%^cropped serviceably short and "
"undecorated, held back from her face with a few mundane pins.  While she carries herself with the same innate "
"grace common of her kin, her frame seems better muscled, almost to the point of %^RED%^stocky%^BLUE%^.  Her "
"clothes are conservative and resilient, obviously less designed for fashion than for the heavy work she "
"does.  A %^ORANGE%^brooch %^BLUE%^is pinned to the front of her collar, etched with the insignia of a noble "
"house.%^RESET%^");
   set("aggressive", 0);
   set_level(15);
   set_gender("female");
   set_alignment(9);
   set_race("drow");
   add_money("gold", random(200));
   set_body_type("human");
   set_storage_room(STORAGE"smith");
   set_hd(20,10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_exp(1);
   set_property("no bow",1);
}