//orcadept.c - Coded by Circe to make sense of the undead in Koenig caves.  11/29/03
#include <std.h>
#include "../koenig.h"
inherit WEAPONLESS;

int dlevel;

void create()
{
   ::create();
   set_name("orc adept");
   set_short("An orc adept");
   set_id(({"orc","orc adept","adept","monster"}));
  dlevel = random(5)+6;
  set_hd(dlevel,5);
  set_race("orc");
  set_gender("female");
  set_body_type("human");
  set("aggressive",14);
  set_property("swarm",1);
  set_level(dlevel);
  set_class("cleric");
  set_mlevel("cleric",dlevel);
  set_guild_level("cleric",dlevel);
  set_hp(random(25)+80);
//  set_exp(dlevel *55);
  set_exp(dlevel * 100);
  set_damage(1,6);
  set_stats("wisdom",18);
  set_stats("charisma",8);
  set_stats("intelligence",12);
  set_stats("constitution",14);
  set_stats("strength",18);
  set_stats("dexterity",12);
  add_money("electrum",random(10)*dlevel);
  add_money("silver",random(10)*dlevel);
  add_money("gold",random(5)*dlevel);
  add_money("copper",random(20)*dlevel);
  set_attacks_num(2);
  set_base_damage_type("bludgeoning");
  set_attack_limbs(({"left hand","right hand"}));
  set_overall_ac(4);
  set_alignment(9);
  new(KOBJ"yellowrobe.c")->move(TO);
  if(!random(2)){
      present("yellow robe",TO)->set_property("monsterweapon",1);
   }
  command("wear yellow robe");
   set_long(
      "This orc seems somewhat cleaner than most.  Her long braids are coarse and "+
      "matted, but no lice can be seen crawling in them.  Her tusks are just as long as "+
      "her male counterparts, and indeed the only thing that suggests she is female is "+
      "the clothing she wears.  Her long %^YELLOW%^y%^GREEN%^e%^YELLOW%^l%^GREEN%^l%^YELLOW%^o"+
      "%^GREEN%^w%^YELLOW%^-%^GREEN%^g%^YELLOW%^r%^GREEN%^e%^YELLOW%^e%^GREEN%^n robes "+
      "%^RESET%^%^CYAN%^are bound with a hideous belt made of %^WHITE%^bones%^RESET%^%^CYAN%^.  "+
      "She carries a staff fitted with a %^BOLD%^%^WHITE%^human skull%^RESET%^%^CYAN%^, which "+
      "seems to have been taken from a child.  Her yellow eyes are quick and dangerous, "+
      "and you can tell she is hardly as defenseless as she seems."
   );
  set_emotes(2,({
    "The orc adept rattles a few bones on a string as she chants quietly.",
    "The orc adept moves swiftly around the cave, muttering to herself.",
    "The orc adept scoops up a handful of dirt and chants as she blows it through her fingertips."
  }),0);
  set_emotes(4,({
    "The orc adept rattles a few bones on a string and mutters fiercely.",
    "The orc adept keeps herself well-guarded as she chants!"
  }),1);
  set_max_level(10);
  set_spell_chance(60);
  set_spells(({"limb attack","sticks into snakes","cause critical wounds","beast claws"}));

}
