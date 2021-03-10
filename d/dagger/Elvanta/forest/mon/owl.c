// Created by DemonForce, for ShadowGate
//  Coded 16 nov., 1995
// Eagle originally made by Demonforce modified for
// monster summoning ii spell on 1/23/96

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
    ::create();
set_name("owl");
 set_id( ({
"owl"
 }) );
set("race", "owl");
set_gender("female");
set("short",
"A very large owl"
 );
 set("long",
"You see a large owl, greyish brown in colour.  It has sharp talons and a very sharp beak."
 );
 set_level( 5 );
set_body_type("fowl");
set("aggressive", 1);
   set_alignment( 7 );
   set_size( 2 );
    set_stats("intelligence", 6);
    set_stats("wisdom", 4);
    set_stats("strength", 14);
    set_stats("charisma", 5);
    set_stats("dexterity", 6);
    set_stats("constitution", 9);
    set_max_mp(0);
 set_hd(5, 1);
 set_max_hp(query_hp());
set_exp(150);
 add_money("silver",random(10));
 add_money("copper",random(20));
}
