#include "summoned_monster.h"
inherit MONSTER;

create() {
    ::create();
   set_name("spider");
   set_id( ({ "spider" }) );
   set_short("A harmless spider");
   set_level(1);
   set("long", "A little spider dangling in mid-air.\n");
   set_gender("female");
   set("race", "arachnoid");
   set_body_type("arachnoid");
    set_alignment(6);
   set_size(1);
   set_stats("intelligence",5);
   set_stats("wisdom",4);
   set_stats("strength",2);
   set_stats("charisma",3);
   set_stats("dexterity",6);
   set_stats("constitution",5);
   set_max_mp(0);
   set_hd(1,1);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
   add_money("copper",random(2));
   

}

