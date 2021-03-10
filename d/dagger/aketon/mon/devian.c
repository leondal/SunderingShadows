#include "/d/dagger/aketon/short.h"

inherit "/std/vendor";

void create() {
   ::create();
   set_name("devian");
   set_id( ({"devian","clerk"}) );
   set_short("Devian the clerk of Aketon Garment Outlet");
   set("aggressive",0);
   set_long("She sells you some clothings you need. <help shop> will get "
      "you a list of shop commands.");
   set_gender("female");
   set_alignment(5);
   set("race","elf");
   add_money( "gold",random(100) );
   set_body_type("human");
   set_storage_room(SPATH+"garment_storage");
   set_property("swarm",1);
   set_hd(20,4);
   set_exp(10);
   set_hp(150);
   set_max_hp(query_hp());
   set_items_allowed("none");
}

void init() {
   ::init();
      set_heart_beat(1);
}
