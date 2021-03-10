#include "/d/dagger/aketon/short.h"

inherit "/std/vendor";

void create() {
   ::create();
   set_name("vavedos");
   set_id( ({"vavedos","clerk","shop keeper","shopkeeper"}) );
   set_short("Vavedos the clerk of Aketon Weapon Shop.");
   set("aggressive",0);
   set_long("He buys and sells weapons. <help shop> will get you a list "
      "of shop commands.");
   set_gender("male");
   set_alignment(4);
   set("race","elf");
   add_money( "gold",random(100) );
   set_body_type("human");
   set_storage_room(SPATH+"weapon_storage");
   set_property("no attack",1);
   set_hd(20,3);
   set_exp(10);
   set_hp(100);
   set_max_hp(query_hp());
   set_items_allowed("weapon");
}

void init() {
   ::init();
      set_heart_beat(1);
}
