#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
set_name("zombie");
set_id(({"zombie", "a zombie"}));
set_short("a zombie");
set_long("This is a zombie that has fallen under the spell of Ignatius.  It stands here in what used to be a store, surrounded with various body parts.  Perhaps he was the original shopkeeper, or perhaps that unfortunate one is in pieces...");
set_level(19);
set("agressive", 18);
set_alignment( 9 );
set_gender("male");
  set_body_type("undead");
set_size( 2 );
  set_race("undead");
set_hp( 275 );
set_hd(19,0);
set_exp( 1200 );
}


