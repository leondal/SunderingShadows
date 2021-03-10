#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("fire drake");
set_id(({"drake", "fire drake"}));
set_short("A fire drake");
set_long("this is a wierd looking dragon which lives in the northern parts
of antioch's island.\n");
set_level(14);
set("agressive", 18);
  set_alignment(8);
set_body_type("dragon");
set_gender("female");
set_size( 2 );
set("race", "dragon");
set_hp( 200 );
set_hd(15,0);
set_exp( 1500 );
}


