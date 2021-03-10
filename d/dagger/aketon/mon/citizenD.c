#include "/d/dagger/aketon/short.h";

inherit WANDER;

void create() {
   ::create();
   set_name("elder citizen");
   set_id( ({"citizen","elder","elder citizen"}) );
   set("race","elf");
   set_gender(random(2)?"male":"female");
   set("short","an elder citizen");
   set("long","This is an elder citizen who lives in Aketon.");
   set_body_type("human");
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
   set_hd(10,4);
   set_spells( ({"acid arrow",
      "magic missle",
      "scorcher",
      "lightning bolt",
      "vampiric touch"}) );
   set_spell_chance(100);
   set_alignment(2);
   set_size(2);
   set_stats("intelligence",15);
   set_stats("wisdom",15);
   set_stats("strength",12);
   set_stats("charisma",14);
   set_stats("dexterity",8);
   set_stats("constitution",6);
   set_max_hp(query_hp());
   add_money("silver",random(20));
   add_money("gold",random(30));
   add_money("copper",random(10));
}

int test_heart() {
   return 1;
}
