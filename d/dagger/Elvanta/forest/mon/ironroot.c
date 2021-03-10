#include </d/antioch/areadefs.h>
inherit "/std/monster";

void create() {
     ::create();
set_name("ironroot treefolk");
set_id( ({ "ironroot treefolk", "treefolk" }));
set_short("A ironroot treefolk");
set_long("This creature is one like you have never seen before.  It has
roots!\n");
set_level(19);
set("agressive", 18);
set_alignment( 9 );
set_property("swarm", 1);
set_gender("male");
set_body_type("treefolk");
set_size( 2 );
set("race", "treefolk");
set_hp( 275 );
set_hd(19,0);
set_exp(2500);
set_wielding_limbs(({"right hand", "left hand"}));
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
command("wield claw in right hand");
command("wield claw 2 in left hand");
}


