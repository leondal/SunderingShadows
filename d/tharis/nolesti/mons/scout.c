// Coded by Arson@ShadowGate 1/10/96

inherit "/std/monster";
#include "/realms/arson/combat.c";

void create()
{
    ::create();
    set_name( "scout" );
    set_id( ({ "scout", "elf", "elven scout", "an elven scout" }) );
    set_short( "an elven scout" );
    set( "long",
      "Standing before you is a tall and slender looking elf.  He seems "
      "to be looking for the enemy.  His eyes look at you, seeming to "
      "penetrate your soul.  He looks like a mighty foe indeed."
    );
    set( "race", "elf" );
    set_gender( "male" );
    set_body_type( "human" );
    set_level( 10 );
    set_class( "fighter" );
    set( "aggressive", 0 );
    set_alignment( 100 );
    set_hd( 5, 20 );
    set_max_hp( 60 );
    set_hp( 60 );
    set_size( 2 );
    set_stats( "intelligence", 10 );
    set_stats( "wisdom", 10 );
    set_stats( "strength", 40 );
    set_stats( "charisma", 10 );
    set_stats( "dexterity", 40 );
    set_stats( "constitution", 10 );
    set_max_mp( 50 );
    set_mp( 50 );
    set_sp( 70 );
    set_max_sp( 70 );
    set_wielding_limbs( ({ "left hand", "right hand" }) );
    new( "/realms/arson/armor/chainmail" )->move( this_object());
        command( "wear suit" );
    new( "/realms/arson/armor/coif" )->move( this_object() );
        command( "wear coif" );
    new( "/realms/arson/weaps/elven_sword" )->move( this_object() );
        command( "wield sword in right hand" );
    add_money( "gold", 10+random(5) );
    set_emotes( 5,
      ({ "a scout says: Better watch out!",
        "a scout askes: Have you see the dark ones?",
        "a scout says: I am looking for the dark ones!" }), 0 );
}
