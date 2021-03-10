#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("white demon");
set_id(({ "demon", "a white demon"}));
set_short("A white demon");
set_long("This is a demon that lives in the island of antioch.\n");
set_level(15);
set("agressive", 18);
set_alignment(6);
set_body_type("demon");
set_gender("female");
set_size( 2 );
set_hp( 200 );
set("race", "demon");
set_hd(15,0);
set_exp( 1500 );
}


