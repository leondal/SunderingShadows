// test NPC

#include <std.h>

inherit "/std/npc.c";

void create(){
   :: create();
   set_name("test NPC");
   set_id(({"test","test npc","npc"}));
   set_short("Test NPC");
   set_long("Test NPC. He is here to help you test out the databases.");
   set_gender("male");
   set_hd(1,1);
   set_size(2);
   set_hp(50);
   set_max_hp(50);
   set_exp(10);
   set_body_type("human");
   set_race("human");
   set_alignment(5);
   remove_property("swarm");
}

void heart_beat(){
   ::heart_beat();
   if(!query_interact()) remove();
}
