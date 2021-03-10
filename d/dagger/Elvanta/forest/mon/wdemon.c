#include </d/antioch/areadefs.h>
inherit "/std/monster";

void create() {
     ::create();
set_name("white demon");
set_id(({ "demon", "a white demon"}));
set_short("A white demon");
set_long("This is a demon that lives within the moat itself, set here ages past to guard the castly she once made war upon.  She will protect the castle but in her eyes you see the hatred she has for her captors.%^RESET%^");
set_level(15);
set("agressive", 18);
set_alignment( 50 );
set_body_type("demon");
set_gender("female");
set_size( 2 );
set_hp( 200 );
set("race", "demon");
set_hd(15,0);
set_exp( 1500 );
}


