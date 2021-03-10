// Coded by Arson@ShadowGate 1/10/95

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "chainmail" );
    set( "id", ({ "armor", "chainmail", "elven chainmail", "suit" }) );
    set( "short", "a suit of elven chainmail" );
    set( "long",
      "You hold in your hands a truly magnificent piece of armor.  "
      "This finely made elven chainmail suit is light and also offers "
      "somewhat good protection.  This suit is made of thousands of "
      "interlocking metal chains.  They make it especially hard for "
      "swords to hit you."
    );
    set_weight( 25 );
    set( "value", 230 );
    set_type( "armour" );
    set_limbs( ({ "torso" }) );
    set_ac( 5 );
}
