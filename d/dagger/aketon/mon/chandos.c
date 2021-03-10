#include "/d/dagger/aketon/short.h"

inherit "/std/vendor";

void create() {
   ::create();
   set_name("chandos");
   set_id( ({"chandos","clerk","shop keeper","shopkeeper"}) );
   set_short("Chandos the clerk of Aketon Armoury.");
   set("aggressive",0);
   set_long("He buys and sells armors. <help shop> will get you a list "
      "of the shop commands.");
   set_gender("male");
   set_alignment(4);
   set("race","elf");
   add_money("gold",random(100));
   set_body_type("human");
   set_storage_room(SPATH+"armor_storage");
   set_property("no attack",1);
   set_hd(20,3);
   set_hp(100);
   set_max_hp(query_hp());
   set_exp(10);
   set_items_allowed("armor");
}

void init() {
   ::init();
      set_heart_beat(1);
}
