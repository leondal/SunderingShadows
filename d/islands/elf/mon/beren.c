#include <std.h>

inherit "/std/identifier";

void create(){
   ::create();
   set_name("Beren");
   set_id(({"Beren","wizard","mage","elven wizard","beren"}));
   set_short("Beren, an elven wizard");
   set_long("Beren is a bit of a outcast among the"+
   " elven magi.  He offers his services to most "+
   "anyone that has the gold.  His has long golden"+
   " hair and gold eyes like his gold elf cousins "+
   "and wears an ornate %^RED%^red%^RESET%^ and %^YELLOW%^yellow robe.%^RESET%^");
   set_race("elf");
   set_stats("intelligence",18);
   set_stats("strength",12);
   set_stats("charisma",15);
   set_stats("wisdom",14);
   set_stats("dexterity",11);
   set_stats("constitution",13);
   set_hp(200+random(76));
   set_max_hp(query_hp());
   set_class("mage");
   set_mlevel("mage",15);
   set_guild_level("mage",15);
   set_spells(({"lightning bolt","burning hands","scorcher",
   "magic missile","powerword stun"}));
   set_spell_chance(60);
   set_id_uses(3);
   set_detect_uses(4);
   set_highmod(4);
   command("message in walks in with long strides.");
   command("message out leaves $D, his robe flowing behind him.");
   command("speech speak confidently");
   command("speak elven");
   set_base_damage_type("bludgeoning"); 
  
}