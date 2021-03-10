// Coded by Arson

#include <std.h>
inherit "/std/weapon";


create()
{
    ::create();
    set_name( "Sword of the Elves" );
    set_id( ({ "sword", "weapon", "sword of the elves", "elf sword" }) );
    set_short( "Sword of the Elves" );
    set_long(
      "This is a very powerful looking sword indeed.  It is a long, "
      "curved sword.  The razor-sharp blade sparkles in the light as "
      "you marvel at this sword.  The hilt is dark green colored "
      "and is decorated with leaves that are carved onto it.  The "
      "royal symbol of the Elven King is also carved onto the hilt.  The "
      "pommel of the hilt has a small crystal ball mounted onto it.  You "
      "can see swirls of multi-colored mists in it.  It is said that this "
      "is the sword the Great Elven Hero, Azlar himself forged."
    );
    set_weight( 10 );
    set_size( 2 );
    set_wc( 1, 12 );
    set_large_wc( 1, 13 );
    set_hit( (: TO, "slice" :) );
    set_wield( "You grasp the hilt of the Sword of the Elves!" );
    set_unwield( "You feel like a part of you is lost as you unwield the sword." );
    set( "value", 9382 );
    set_type( "slashing" );
}

void slice( object targ )
{
    if( !random( 4 ) )
    {
    tell_object( environment( TO ), "You swing your mighty sword around "
      "and land your opponent a mighty blow!" );
    tell_room(environment(environment(TO)), TPQCN+" swings their "
      "mighty sword around and lands "+targ->query_short()+" a mighty blow!", TP );
    return( 10 + random( 20 ) );
    }
    else
      return( 1 + random( 15 ) );
}
