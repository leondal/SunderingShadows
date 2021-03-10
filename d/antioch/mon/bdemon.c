#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/monster";

void create() {
     ::create();
set_name("black demon");
set_id( ({ "demon", "a black demon" }));
set_short("A black demon");
set_long("This is a demon that lives in the island of antioch.\n");
set_level(20);
set("agressive", 18);
set_alignment(3);
set_body_type("demon");
set_gender("male");
set_size( 2 );
set_hp( 200 );
set("race", "demon");
set_hd(20,0);
set_exp( 1600 );
add_money("gold",random(50));
  new(ARM + "shadowscale")->move(TO);
command("wear shadowscale");
}


