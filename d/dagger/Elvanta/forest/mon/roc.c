// Created by DemonForce, for ShadowGate
//  Coded 16 nov., 1995
// Eagle originally made by Demonforce modified for
// monster summoning ii spell on 1/23/96

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
    ::create();
set_name("roc");
 set_id( ({
"roc"
 }) );
set("race", "roc");
set_gender("female");
set("short",
"A roc"
 );
 set("long",
"This Roc is a huge bird, somewhat resembling an eagle.  It preys upon large creatures such as cattle, horses and elephants.  It is a fiercesome bird.");
set_level(12);
set_body_type("fowl");
set("aggressive", 10);
   set_alignment( 7 );
   set_size( 2 );
set_property("swarm", 1);
	set_stats("intelligence", 6);
    set_stats("wisdom", 4);
	set_stats("strength", 16);
    set_stats("charisma", 5);
	set_stats("dexterity", 15);
	set_stats("constitution", 10);
set_hd(18,0);
set_hp(100);
 set_max_hp(query_hp());
set_exp(300);
 add_money("silver",random(10));
 add_money("copper",random(20));
}
