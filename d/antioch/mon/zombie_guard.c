#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("zombie guard");
set_id( ({ "guard", "a zombie guard", "zombie guard"}) );
set_short("A zombie guard");
set_long("This is a zombie that is under the command of Ignatius.");
set_level(10);
set("agressive", 18);
set_alignment(6);
set_body_type("undead");
set_gender("male");
set_size( 2 );
set_hp( 90 );
set("race", "undead");
set_hd(10,0);
set_exp( 400 );
}

