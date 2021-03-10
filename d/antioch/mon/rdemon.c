#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("red demon");
set_id(({"demon", "a red demon"}));
set_short("A red demon");
set_long("This is a demon that lives in the island of antioch.\n");
set_level(18);
set("agressive", 25);
set_body_type("demon");
set_gender("male");
set_alignment(3);
set_size( 2 );
set_hp( 300 );
set("race", "demon");
set_hd(20,0);
set_exp( 2000 );
}


