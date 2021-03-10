//  Created by Demonforce, for ShadowGate
//  Coded 16 nov., 1995
//  Goblin for Antioch Village

inherit "std/monster";

create() {
    ::create();
set_name("goblin");
 set_id( ({
"goblin", "a goblin", "sled goblin", "a sled goblin"
 }) );
set("race", "goblin");
set_gender("female");
 set("short",
"A sled goblin"
 );
 set("long",
"This goblin is said to be very fast and slick.  She comes from "+
"the forest of Antioch, but now resides in the village.  Watch "+
"your back."
 );
set_level( 8 );
set_body_type("goblin");
   set("aggressive", 9);
   set_property("swarm",1);
set_alignment( 4 );
   set_size( 1 );
set_hp(50);
set_sp(80);
set_exp(600);
 add_money("silver",random(10));
add_money("gold",random(20));
   
}
