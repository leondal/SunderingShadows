#include "/d/dagger/aketon/short.h"

inherit "/std/vendor";

void create() {
   ::create();
   set_name("ziliot");
   set_id( ({"ziliot","fletcher","shopkeeper"}) );
   set_short("Ziliot the fletcher");
   set("aggressive",0);
    set_long("He is an old man with a white beard on his face. Ziliot was "
      "once the most skillful archer of Aketon. Now he retires and opened "
      "this shop to sell tools of archery. Regardless of his age, he can "
       "still shoot the bulls-eye from a great distance.");
   set_gender("male");
   set_alignment(5);
   set("race","elf");
   add_money( "gold",random(300) );
   set_body_type("human");
   set_storage_room(SPATH+"archery_storage");
   set_property("no animate",1);
   set_property("no steal",1);
   set_property("no animate",1);
   set_hd(27,3);
   set_exp(2250);
   set_hp(220);
   set_max_hp(query_hp());
   set_items_allowed("misc");
   new(OPATH+"rcrossbow")->move(TO);
   command("wield bow in left hand and right hand");
   new(OPATH+"rcarrows")->move(TO);
   new("/d/shadow/obj/armor/hide")->move(TO);
   command("wearall");
}

void init() {
   ::init();
      set_heart_beat(1);
}
