#include "/d/dagger/aketon/short.h";

inherit WANDER;

void create() {
   ::create();
   set_name("small child");
   set_id( ({"citizen","child"}) );
   set("race","elf");
   set_gender(random(2)?"male":"female");
   set("short","a small child");
   set("long","This is a small child who lives in Aketon.");
   set_level(1);
   set_hd(1,1);
   set_body_type("human");
   set_class("fighter");
   set_alignment(2);
   set_size(2);
   set_stats("intelligence",8);
   set_stats("wisdom",8);
   set_stats("strength",10);
   set_stats("charisma",16);
   set_stats("dexterity",9);
   set_stats("constitution",5);
   set_max_hp(query_hp());
   add_money("silver",random(20));
   add_money("copper",random(10));
}

int test_heart() {
   return 1;
}
