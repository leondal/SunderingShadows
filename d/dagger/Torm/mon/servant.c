#include <std.h>
inherit "/std/monster";
create(){
::create();
  set_name("servant");
  set_id(({
  "servant","simple servant"
  }));
  set_short(
    "Simple servant"
  );
  set_long(
  "  This simple man stands out of the way, waiting for an order from his master."
   "  He doesn't look terribly eager to do anything on his own, and really doesn't seem to want to do much else but keep out of the way."
  );
  set_race("human");
  set_gender("male");
set_body_type("human");
  set_hd(1,1);
set_max_hp(5);
set_hp(5);
set_overall_ac(10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
set("aggressive",5);
set_wielding_limbs( ({"left hand", "right hand"}) );
}
