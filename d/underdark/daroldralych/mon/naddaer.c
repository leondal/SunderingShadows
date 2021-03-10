#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_name("naddaer");
   set_id(({"naddaer","teller","bank teller","banker"}));
   set_short("%^RESET%^%^BLUE%^Naddaer Phaeraan, the bank teller%^RESET%^");
   set_long("%^BLUE%^This drow male is particularly scrawny for his kind.  His %^WHITE%^lanky white hair "
"%^BLUE%^falls long and unrestrained over his shoulders, and his gaze is particularly %^RED%^piercing%^BLUE%^, "
"as he sizes up every newcomer to the bank.  He is clad in long, yet surprisingly plain robes of %^RED%^dark "
"crimson%^BLUE%^, with a %^YELLOW%^house insignia %^RESET%^%^BLUE%^pinned to the breast.  He is rarely without "
"a paper in hand, constantly counting over the figures written upon it.%^RESET%^");
   set_alignment(3);
   set_race("drow");
   set_class("mage");
   set_body_type("human");
   set_hd(25,10);
   set_max_hp(800);
   set_hp(800);
   set_gender("male");
   set_exp(1);
   set_property("no bow",1);
   add_dbs(({"teller"}));
   add_random_act_dbs(({"tellerrandom"}));
   remove_std_db();
}
