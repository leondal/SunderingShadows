// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "golden diadem" );
    set( "id", ({ "armor", "diadem", "golden diadem", "a golden diadem" }) );
    set( "short", "a golden diadem" );
    set( "long",
      "This is a brightly gleaming golden diadem.  It looks "
      "like it must have belonged to someone with great power "
      "and wealth.  Many jewels are mounted onto this diadem.  "
      "They help make it shine even brighter.  The royal "
      "symbol of the Elves is etched onto the front."
    );
    set_weight( 5 );
    set( "value", 2000 );
    set_type( "clothing" );
    set_limbs( ({ "head" }) );
    set_ac( 1 );
}
