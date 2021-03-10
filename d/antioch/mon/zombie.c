#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("zombie");
set_id(({"zombie", "a zombie"}));
set_short("a zombie");
set_long("This is a zombie that is ruled by Ignatius.  It stands here and guards the many heads that the undead army has earned.");
set_light(10);
set("agressive", 18);
set_alignment( 9 );
set_gender("male");
set_body_type("undead");
set_size( 2 );
set("race", "undead");
set_hp( 90 );
set_hd(10,0);
set_exp( 400 );
}


