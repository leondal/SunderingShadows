#include "/d/dagger/aketon/short.h";

inherit WANDER;

void create() {
   ::create();
   set_name("youngster");
   set_id( ({"citizen","youngster"}) );
   set("race","elf");
   set_gender(random(2)?"male":"female");
   set("short","a youngster");
   set("long","This is a youngster who lives in Aketon.");
   set_level(3);
   set_hd(3,2);
   set_body_type("human");
   set_class("fighter");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_property("swarm",1);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("strength",14);
   set_stats("charisma",16);
   set_stats("dexterity",10);
   set_stats("constitution",8);
   set_max_hp(query_hp());
   add_money("silver",random(20));
   add_money("copper",random(10));
}

int test_heart() {
   return 1;
}
