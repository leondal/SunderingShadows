// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "bright red dress" );
    set( "id", ({ "dress", "armor", "red dress", "bright red dress" }) );
    set( "short", "a Bright Red Dress" );
    set( "long",
      "This is a bright red colored royal dress.  Golden runes are "
      "sewn onto it.  They symbolize that this is one of the royal "
      "dresses of the Elven Princess"
    );
    set_weight( 5 );
    set( "value", 918 );
    set_type( "clothing" );
    set_limbs( ({ "torso" }) );
    set_ac( 1 );
}
