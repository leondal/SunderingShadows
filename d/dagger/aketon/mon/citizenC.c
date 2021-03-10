#include "/d/dagger/aketon/short.h";

inherit WANDER;

void create() {
   ::create();
   set_name("citizen");
   set_id( ({"citizen"}) );
   set("race","elf");
   set_gender(random(2)?"male":"female");
   set("short","a citizen");
   set("long","This is a common citizen who lives in Aketon.");
   set_level(5);
   set_hd(5,2);
   set_body_type("human");
   set_class("fighter");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_property("swarm",1);
   set_stats("intelligence",12);
   set_stats("wisdom",12);
   set_stats("strength",15);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",10);
   set_max_hp(query_hp());
   add_money("silver",random(20));
   add_money("gold",random(50));
   add_money("copper",random(10));
}

int test_heart() {
   return 1;
}
