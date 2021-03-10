//  Created by Demonforce, for ShadowGate
//  Coded 16 nov., 1995
//  Goblin for Antioch Village

inherit "std/monster";

create() {
    ::create();
set_name("incartes");
 set_id( ({"incartes", "mage" }) );
set("race", "goblin");
set_gender("male");
 set("short","Incartes, the high mage" );
 set("long","The mage sits quietly, waiting for a good fight.  Oops he must have lost his spellbook.\n" );
set_level( 8 );
set_body_type("human");
set_spell_chance(100);
set_guild_level("mage",8);
set_spells(({
"cone of cold",
"scorcher",
"magic missile",
"acid arrow"
}));
     set("aggressive", 5);
  set_alignment(9);
   set_size( 2 );
set_hp(300);
set_sp(80);
set_exp(2000);
 add_money("silver",random(10));
add_money("gold",random(20));
   
}
