// Coded by Arson@ShadowGate 1/10/96

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "coif" );
    set( "id", ({ "coif", "elven coif", "chainmail coif", "armor" }) );
    set( "short", "an elven chainmail coif" );
    set( "long",
      "This is a magnificent piece of armor.  This coif is light and looks "
      "like it offers somewhat good protection for the head.  The delicate "
      "designs on it indicate that it must be of elven make."
    );
    set_weight( 10 );
    set( "value", 40 );
    set_type( "armour" );
    set_limbs( ({ "head" }) );
    set_ac( 1 );
}
