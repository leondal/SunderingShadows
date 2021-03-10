// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "golden sandals" );
    set( "id", ({ "armor", "sandals", "golden sandals" }) );
    set( "short", "a pair of golden sandals" );
    set( "long",
      "This is a pair of beautifully made golden sandals.  Silver "
      "thread lines the sides in spidery runes.  A slight "
      "glow surrounding these sandals hint that they are no ordinary sandals "
      "indeed."
    );
    set_weight( 3 );
    set( "value", 1000 );
    set_type( "clothing" );
    set_limbs( ({ "right foot", "left foot" }) );
    set_ac(1);
}
