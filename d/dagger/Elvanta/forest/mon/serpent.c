#include </d/antioch/areadefs.h>
inherit "/std/monster";

void create() {
     ::create();
set_name("serpent");
set_id(({"serpent"}));
set_short("A serpent");
set_long("This serpent is gray/green in colour and is deadly");
set_level(23);
set("agressive", 25);
set_body_type("serpant");
set_gender("male");
set_alignment( 200 );
set_size( 2 );
set("race", "serpant");
set_hp( 400 );
set_hd(23,0);
set_exp(2000);
add_money("gold", 100);
}


