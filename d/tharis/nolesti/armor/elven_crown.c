// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "elven crown" );
    set( "id", ({ "armor", "crown", "elven crown", "an elven crown" }) );
    set( "short", "an Elven Crown" );
    set( "long",
      "This is the most wonderful looking crown you have ever laid "
      "your eyes upon.  There are many bright gems mounted onto "
      "this golden crown.  Many runes are etched onto the sides in "
      "Elvish.  They are so old, you cannot read them.  Despite "
      "it's age, it is kept polished well and still gleams brightly in "
      "the light.  A slight glow surrounding this crown hints that it "
      "is no ordinary crown indeed."
    );
    set_weight( 10 );
    set( "value", 12000 );
    set_type( "clothing" );
    set_limbs( ({ "head" }) );
    set_ac( 2 );
}
