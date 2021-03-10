// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "golden circlet" );
    set( "id", ({ "crown", "circlet", "golden circlet" }) );
    set( "short", "a Golden Circlet" );
    set( "long",
      "Your eyes sparkle as you look at this jewel encrusted circlet made "
      "of pure gold.  It looks like only Elven hands could have "
      "made this wonderful prize."
    );
    set_weight( 6 );
    set( "value", 1492 );
    set_type( "clothing" );
    set_limbs( ({ "head" }) );
    set_ac( 1 );
}
