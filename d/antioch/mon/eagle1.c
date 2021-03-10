// Created by DemonForce, for ShadowGate
//  Coded 16 nov., 1995
//  Demon for Antioch Village

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
    ::create();
set_name("bindegle");
 set_id( ({
"eagle", "bindegle"
 }) );
set("race", "eagle");
 set_gender("male");
set("short",
"Bindegle, the huge eagle"
 );
 set("long",
"This eagle is very large.  His feathers sharply brushed back with cold water, he might be able to be mounted.\n"
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
set_spell_chance(99);
set_spells(({
"chill touch",
"dispel magic",
"magic missile",
"freeze"
}));
    set_mp(query_max_mp());
 set_hd(5, 1);
 set_max_hp(query_hp());
set_exp(200);
 set_max_sp(query_hp());
 set_sp(query_max_sp());
 add_money("silver",random(10));
 add_money("copper",random(20));
}
void init() {
     ::init();
add_action("mount_eagle", "mount");
}
int mount_eagle(string str) {
write("You mount the eagle.\n");
say((string)this_player()->query_cap_name()+" Mounts the eagle.\n");
write("The eagle flies up towards the clouds.\n");
say((string)this_player()->query_cap_name()+"'s eagle flies up towards the clouds.\n");
write("The eagle stops.\n");
say((string)this_player()->query_cap_name()+"'s eagle stops.\n");
this_player()->move_player("/d/antioch/village/fly1.c");
return 1;
}
