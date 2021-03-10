#include "/d/dagger/aketon/short.h"

inherit "/std/comp_vend.c";

create() {
   ::create();
   set_name("vourolyx");
   set_id( ({ "vourolyx","alchemist","clerk"}) );
   set_short("Vourolyx the alchemist");
   set("aggressive",0);
   set_level(20);
   set_hd(20,2);
   set_long("Vourolyx will sell you components for your spells.\n"
      "<help shop> will get you a list of shop commands.");
   set_gender("male");
   set_alignment(5);
   set("race","elf");
   set_exp(10);
   set_body_type("human");
   set_components(40);
}
