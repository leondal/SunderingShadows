// Coded by Arson

inherit "/std/armour";

void create()
{
    ::create();
    set_name( "robes" );
    set( "id", ({ "armor", "robe", "robes", "robes of the elven king" }) );
    set( "short", "Robes of the Elven King" );
    set( "long",
      "This is a long flowing robe that seems to be made of "
      "some very rich material.  It feels warm to the touch.  "
      "This robe was passed down for centuries in the Royal "
      "family.  Even though it is very old, it looks brand "
      "new.  A magical aura surrounding this robe suggests "
      "that it is no ordinary robe.  It must have been enchanted "
      "by an Elven priest."
    );
    set_weight( 18 );
    set( "value", 1200 );
    set_type( "clothing" );
    set_limbs( ({ "torso", "right leg", "left leg", "right arm", "left arm" }) );
    set_ac(1);
}
