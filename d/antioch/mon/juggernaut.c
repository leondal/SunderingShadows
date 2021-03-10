#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("juggernaut");
set_id(({ "juggernaut" }));
set_short("Juggernaut");
set_long("This creature seems to be here to keep people out of the great tower.  You wonder what could be in there.");
set_level(27);
set("agressive", 18);
set_alignment(9);
set_body_type("human");
set_gender("male");
set_size(3);
set("race", "juggernaut");
set_hp( 550 );
set_hd(27,0);
set_exp(2000);
 set_overall_ac(0);
set_property("swarm",1);
}


