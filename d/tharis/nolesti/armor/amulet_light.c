// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "amulet of light" );
    set_property( "light", 5 );
    set( "id", ({ "armor", "amulet", "amulet of light", "light amulet" }) );
    set( "short", "Amulet of Light" );
    set( "long",
      "You hold in your hands a brightly shining amulet.  It seems "
      "to glow bright yellow.  The sorce of the light is unknown.  "
    );
    set_weight( 4 );
    set( "value", 1291 );
    set_type( "clothing" );
    set_limbs( ({ "neck" }) );
    set_ac( 1 );
}
