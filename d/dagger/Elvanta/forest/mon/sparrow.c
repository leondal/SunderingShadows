// Created by DemonForce, for ShadowGate
//  Coded 16 nov., 1995
// Eagle originally made by Demonforce modified for
// monster summoning ii spell on 1/23/96

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
    ::create();
set_name("sparrow");
 set_id( ({
"sparrow"
 }) );
set("race", "sparrow");
 set_gender("male");
set("short",
"A tiny sparrow"
 );
 set("long",
"This little fellow is small and harmless, he has muted brown feathers over all of his body, with pale gray beak and legs.  He has a chubby little body and his belly looks to be quite full.");
set_level(2);
set_body_type("fowl");
set("aggressive", 1);
   set_alignment( 7 );
set_size(1);
set_property("swarm", 1);
    set_stats("intelligence", 6);
    set_stats("wisdom", 4);
    set_stats("strength", 14);
    set_stats("charisma", 5);
    set_stats("dexterity", 6);
    set_stats("constitution", 9);
    set_max_mp(0);
 set_hd(5, 1);
 set_max_hp(query_hp());
set_exp(50);
 add_money("silver",random(10));
 add_money("copper",random(20));
}
