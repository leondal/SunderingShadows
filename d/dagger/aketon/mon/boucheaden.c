#include "/d/dagger/aketon/short.h"

inherit "/std/vendor";

void create() {
   ::create();
   set_name("boucheaden");
   set_id( ({"boucheaden","clerk","jeweler"}) );
   set_short("Boucheaden the Jeweler");
   set("aggressive",0);
   set_long("Boucheaden is the local jeweler here in Aketon. He buys all "
      "sorts of rare and precious stones from sources all over the realm "
      "and then put them in sale here in his shop. <help shop> will get "
      "you a list of shop commands.");
   set_gender("male");
   set_alignment(5);
   set("race","elf");
   add_money( "gold",random(100) );
   set_body_type("human");
   set_storage_room(SPATH+"jewellery_storage");
   set_property("swarm",1);
   set_hd(20,4);
   set_exp(10);
   set_hp(150);
   set_max_hp(query_hp());
   set_items_allowed("misc");
}

void init() {
   ::init();
      set_heart_beat(1);
}
