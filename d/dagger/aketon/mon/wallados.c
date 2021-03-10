#include "/d/dagger/aketon/short.h"

inherit TOWNSMAN;

void create() {
   ::create();
   set_name("Wallados");
   set_id( ({"wallados","healer"}) );
   set_short("Wallados the healer of Aketon");
   set("aggressive", 0);
   set_long("He is an old gentleman, who tends to the injured people of "
      "Aketon.");
   set_gender("male");
   set_alignment(4);
   set("race","elf");
   add_money( "gold",random(100) );
   set_body_type("human");
   set_property("no attack",1);
   set_hd(20,3);
   set_hp(150);
   set_max_hp(query_hp());
}
