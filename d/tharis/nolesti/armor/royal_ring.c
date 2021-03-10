// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "royal ring" );
    set( "id", ({ "ring", "armor", "royal ring", "a royal ring" }) );
    set( "short", "a Royal Ring" );
    set( "long",
      "This is a small golden ring.  There are a lot of leaves carved "
      "onto it.  There is also a royal symbol mounted onto it."
    );
    set_weight( 1 );
    set( "value", 1293 );
    set_type( "ring" );
    set_limbs( ({ "right hand" }) );
    set_ac( 0 );
    set_property( "enchantment", 2 );
}
