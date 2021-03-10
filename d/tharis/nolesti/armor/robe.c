// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "royal robe" );
    set( "id", ({ "robe", "robes", "armor", "royal robe", "a royal robe" }) );
    set( "short", "a Royal Robe" );
    set( "long",
      "This is a large flowing robe made from what seems to be fine silk.  "
      "The royal symbol is sewn on the back.  There are many golden "
      "leaves sewn onto the front to decorate it."
    );
    set_weight( 5 );
    set( "value", 1921 );
    set_type( "clothing" );
    set_limbs( ({ "torso" }) );
    set_ac(1);
}
