#include "/d/shadow/mon/melnmarn.h"
inherit "/std/vendor";
create() {
   ::create();
   set_name("zokrath");
   set_id( ({ "Zokrath", "zokrath","clerk", "shop keeper", "shopkeeper"}) );
set_short("Zokrath, the Drow armor merchant");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells armor.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set("race", "Drow");
   add_money("gold", random(1000));
   set_body_type("humanoid");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
set_storage_room("/d/dagger/drow/rooms/armor_storage.c");
  set_exp(0);
}
 
