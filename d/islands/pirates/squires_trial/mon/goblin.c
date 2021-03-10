#include <std.h>
#include "../squires_trial.h"

inherit MONSTER;

void create(){
  object item;
  object falconsword;
  ::create();
  set_name("goblin");
  set_short("%^BOLD%^%^GREEN%^Injured Goblin%^BOLD%^%^RED%^");
  set_long(
      "%^BOLD%^%^GREEN%^" +
      "This hideous creature snarls as you approach, baring twisted, sharp " +
      "teeth.  He has " +
      "%^BLACK%^" +
      "beady black eyes %^GREEN%^and greasy hair.  Small bones are " +
      "tied into his leather necklaces and bracelets.  %^BOLD%^%^RED%^" +
      "His right arm is " +
      "obviously snapped, part of the bone sticks out through the skin!" +
      "%^RESET%^"
  ); 
  
  set_id( ({"goblin","injured goblin","goblin sorcerer"}) );
  set_race("goblin");
  set_body_type("human");
  set_gender("male");
  set_size(1);
  set_alignment(9);
  set_property("aggressive",1);
  set_stats("strength",12);
  set_stats("dexterity",16);
  set_stats("constitution",13);
  set_stats("intelligence",13);
  set_stats("wisdom",8);
  set_stats("charisma",18);
  set_class("sorcerer");
  set_mlevel("sorcerer",22);
  set_max_level(25);
  set_guild_level("sorcerer",22);
  set_property("full attacks",1);
  set_hp(275 + random(51));
//  set_exp(10000);
  set_overall_ac(2);
  set("aggressive","killtime");
  set_spells(({"vampiric touch","fireball","fireball","magic missile","magic missile"}));
  set_spell_chance(80);
  set_mob_magic_resistance("average");
  item = new(SQUIREITEMS + "bone_harness");
  add_money("gold", random(100)+50);
  add_money("electrum", random(250));
  set_new_exp(20, "high");
  if(objectp(item)){
    item->move(TO);
    command("wear harness");
  }
}

int killtime(){
  if(!objectp(TP)) return 0;
  if(TP->query_true_invis()) return 0;
  command("say I eat you!");
  command("emote drools disgustingly.");
  command("kill "+TPQN);
  return 1;
}

