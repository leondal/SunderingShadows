// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "white dress" );
    set( "id", ({ "dress", "armor", "white dress", "a white dress" }) );
    set( "short", "a White Dress" );
    set( "long",
      "This is a rather large looking pure white dress.  It is lined with "
      "gold.  The royal symbol is sewn onto the front."
    );
    set_weight( 4 );
    set( "value", 569 );
    set_type( "clothing" );
    set_limbs( ({ "torso" }) );
    set_ac( 1 );
}
