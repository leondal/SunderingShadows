// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "royal cloak" );
    set( "id", ({ "cloak", "armor", "a royal cloak", "royal cloak" }) );
    set( "short", "a Royal Cloak" );
    set( "long",
      "This is a long flowing cloak.  There are a lot of runes sewn onto "
      "the front.  The royal symbol is sewn onto the back.  This cloak "
      "looks like it must have belonged to someone important."
    );
    set_weight( 5 );
    set( "value", 1192 );
    set_type( "clothing" );
    set_limbs( ({ "neck" }) );
    set_ac(1);
}
