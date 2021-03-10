#include "/d/dagger/aketon/short.h"

inherit "/std/vendor";

void create() {
   ::create();
   set_name("vathodouse");
   set_id( ({"vathodouse","clerk","merchant","tobacco merchant"}) );
   set_short("Vathodouse the tobacco merchant");
   set("aggressive",0);
   set_long("Vathodous makes a living in dealing tobaccos. He trades with "
       "other tobacco dealers for new tobaccos and supplies the need of the "
      "citizens and all adventurers who ever need a calm mind achieved by "
      "smoking tobaccos with a pipe. <help shop> will get you a list of "
      "shop commands.");
   set_gender("male");
   set_alignment(5);
   set("race","elf");
   add_money( "gold",random(100) );
   set_body_type("human");
   set_storage_room(SPATH+"tobacco_storage");
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
