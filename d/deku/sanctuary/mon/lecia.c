#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create() {
object ob;
   ::create();
   set_name("lecia");
   set_id(({"lecia","kelun","mage"}));
   set_short("Lecia Kelun");
   set_long(
      "This woman looks more like a maturing young lady. Her golden"+
      " hair is tied up in a bun to not get in the way of her cyan eyes."+
      " She wears wizard regelia that flows down over her shoes and carries"+
      " a matching staff."
   );
   set_race("human");
   set_gender("female");
   set_hd(14,2);
   set_class("mage");
   set_mlevel("mage",14);
   set_guild_level("mage",14);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(289);
   set_hp(289);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no bows", 1);
   set_size(2);
   set("aggressive",30);
   set_exp(30000);
   set_stats("strength",12);
   set_stats("intelligence",18);
   set_stats("constitution",12);
   set_stats("wisdom",14);
   set_stats("dexterity",17);
   set_stats("charisma",17);
   ob = new(OBJ+"orchidgown")->move(TO);
   ob = new(OBJ+"wizardhat");
   if(random(2)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   force_me("wearall");
   force_me("wear hat");
   set_spells(({
      "powerword stun",
      "hideous laughter",
      "ray of enfeeblment",
      "hold person",
      "greater shout"
   }));
   set_spell_chance(100);
   set_max_level(23);
}
