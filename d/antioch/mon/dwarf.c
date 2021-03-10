//  Created by Ignatius, for ShadowGate
//  Coded 05 March, 1995
//  Dwarf NPC for Charu Mountains

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
    ::create();
 set_name("dwarf");
 set_id( ({
    "dwarf", "short dwarf"
 }) );
 set("race", "dwarf");
 set_gender("male");
 set("short", "A burly dwarf" );
 set("long", "This dwarf seems hardened by the Charu Mountains.\n" );
 set_level( 8 );
 set_body_type("human");
   set("aggressive", 9);
   set_alignment( 7 );
   set_size( 2 );
    set_stats("intelligence", 6);
    set_stats("wisdom", 4);
    set_stats("strength", 14);
    set_stats("charisma", 5);
    set_stats("dexterity", 6);
    set_stats("constitution", 9);
    set_max_mp(0);
    set_mp(query_max_mp());
 set_hd(8, 1);
 set_max_hp(query_hp());
 set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/shortsword")->move(this_object());
       command("wield sword");
 add_money("silver",random(10));
 add_money("copper",random(20));
   
}
