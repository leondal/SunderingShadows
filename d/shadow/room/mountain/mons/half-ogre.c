//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit MONSTER;

void create() {
object obj;
  ::create();
  set_name("half-ogre");
  set_id(({"ogre","half-ogre","Half-ogre","cave_ogre"}));
  set_gender(random(2)?"male":"female");
  set_race("ogre");
  set_short("Half-ogre");
  if((string)TO->query_gender() == "female"){
     set_long(
@CIRCE
This hideous creature seems to be made of the worst of ogres 
mixed with the most dreadful parts of humans.  Her slack chin 
has stubbly black hair, above which protrude yellowing tusks 
that give her a boar-like appearance.  Her face seems misshapen, 
with the wide, sloping forehead of an ogre mismatched with the 
more pronounced human cheekbones.  Her watery eyes are a sickly 
lavender surrounded by red veins.  She wears a makeshift robe 
made of fur and skins, and she has a crude leather pouch at her
side.  Strangely, her forearms are covered with well-made bracers.
CIRCE
     );
  }else{
     set_long(
@CIRCE
This hideous creature seems to be made of the worst of ogres 
mixed with the most dreadful parts of humans.  His slack chin 
has stubbly black hair, above which protrude yellowing tusks 
that give him a boar-like appearance.  His face seems misshapen, 
with the wide, sloping forehead of an ogre mismatched with the 
more pronounced human cheekbones.  His watery eyes are a sickly 
green-yellow surrounded by red veins.  He wears a makeshift robe 
made of fur and skins, and he has a crude leather pouch at her
side.  Strangely, his forearms are covered with well-made bracers.
CIRCE
     );
  }
  set_body_type("human");
  set_alignment(9);
  set_hd(8,2);
  set_stats("strength",19);
  set_stats("aggressive",16);
  set_stats("intelligence", 18);
  set_stats("wisdom", 12);
  set_stats("charisma",3);
  set_class("mage");
  set_mlevel("mage",14);
  set_guild_level("mage",14);
  set_size(3);
  set_property("swarm",1);
  set_wielding_limbs(({"right hand","left hand"}));
  add_money("gold",random(150));
  set_overall_ac(4);
  set_hp(70+random(25));
  //set_exp(500);
//   set_exp(800);
  set_new_exp(14,"normal");
  set_max_level(16);
  obj = new("/d/common/obj/armour/bracers");
  obj->set_property("enchantment",1);
  if(random(3)){
     obj->set_property("monsterweapon",1);
  }
  obj->move(TO);
  command("wear bracers");
  set_spell_chance(40);
  set_spells(({"burning hands","scorcher","hideous laughter","ray of enfeeblement","lightning bolt","fireball"}));
  
}
