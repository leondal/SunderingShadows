// Coded by Arson

inherit "/std/monster";

void create()
{
    ::create();
    set_name( "duran" );
    set_id( ({ "king", "duran", "king duran", "Duran" }) );
    set_short( "King Duran of Nolesti" );
    set( "long",
      "Standing boldly before you is a tall and strong looking Elf.  "
      "Even though he must be at least 500 years old, he still looks "
       "extremely healthy.  His long silver hair pours down to his "
      "shoulders.  His eyes look at you with sorrow.  He seems to "
      "be troubled deeply by something."
    );
    set( "race", "elf" );
    set_gender( "male" );
    set_body_type( "human" );
    set_level( 25 );
    set_class( "fighter" );
    set( "aggressive", 0 );
    set_alignment( 1000 );
    set_hd( 25, 2 );
    set_max_hp( 600 );
    set_hp( 600 );
    set_size( 2 );
    set_stats( "intelligence", 20 );
    set_stats( "wisdom", 20 );
    set_stats( "strength", 25 );
    set_stats( "charisma", 15 );
    set_stats( "dexterity", 25 );
    set_stats( "constitution", 20 );
    set_max_mp( 50 );
    set_mp( 50 );
    set_sp( 200 );
    set_max_sp( 200 );
    set_wielding_limbs( ({ "left hand", "right hand" }) );
    new( "/d/tharis/nolesti/armor/king_robe" )->move( this_object());
         command( "wear robe" );
    new( "/d/tharis/nolesti/armor/golden_sandals" )->move( this_object());
        command( "wear sandals" );
    new( "/d/tharis/nolesti/armor/amulet_light" )->move( this_object());
        command( "wear amulet" );
    new( "/d/tharis/nolesti/armor/elven_crown" )->move( this_object());
      command( "wear crown" );
    new( "/d/tharis/nolesti/weaps/sceptre.c" )->move( this_object());
      command( "wield sceptre in right hand" );
    add_money( "gold", 10+random(5) );
    set_emotes( 5,
      ({ "King Duran says: I've seen better days.",
        "King Duran sighs.",
        "King Duran gives you a sorrow filled look." }), 0 );
}
