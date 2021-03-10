// Coded by Arson

#include <std.h>
#include <rooms.h>
inherit "/std/weapon";

int real_intell;

create()
{
    ::create();
    set_name( "Sceptre of Duran" );
    set_id( ({ "sceptre", "weapon", "sceptre of duran", "Sceptre of Duran" }) );
    set_short( "Sceptre of Duran" );
    set_long(
      "Gleaming brighty in the light, this magnificent sceptre "
      "catches your eyes right away.  Many beautiful jewels are "
      "mounted onto the length of this sceptre.  Sharp red diamonds "
      "are mounted onto the head of the sceptre, making it almost "
      "like a mace.  Many Elvish runes are etched along the length "
      "of the sceptre also.  They are so old, you cannot read them."
    );
    set_weight( 12 );
    set_size( 1 );
    set_wc( 1, 7 );
    set_large_wc( 1, 8 );
    set_hit( (: TO, "blast" :) );
    set_wield( (: TO, "intell" :) );
    set_unwield( (: TO, "reset" :) );
    set( "value", 1000 );
    set_type( "bludgeoning" );
}

void blast( object targ )
{
    if( !random( 4 ) )
    {
    tell_object( environment( TO ), "Your Sceptre suddenly glows "
      "bright yellow and strikes your opponent!" );
    tell_room(environment(environment(TO)), TPQCN+"'s Sceptre "
       "suddenly glows bright yellow and strikes "+targ->query_short()+"!", TP );
    return( 15 + random( 20 ) );
    }
    else
      return( 1 + random( 15 ) );
}

void init()
{
    ::init();
    add_action( "drop", "give" );
    add_action( "do_quit", "quit" );
}

drop( str )
{
    write( "The Sceptre cannot be dropped!" );
    return 1;
}

do_quit( str )
{
    write( "You cannot quit with the Sceptre wielded." );
    return 1;
}

int intell()
{
   real_intell = TP->query_stats("intelligence");
    TP->set_stats( "intelligence", (real_intell + 5 ) );
    write( "You feel much smarter as you wield the Sceptre.\n" );
    return 1;
}

int reset()
{
      TP->set_stats( "intelligence", real_intell );
    write( "You feel your regular intelligence returning as you unwield the Sceptre." );
    return 1;
}
