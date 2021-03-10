#include <std.h>
#include "../keep.h"
inherit MONSTER;

void create()
{
  ::create();
  set_name("half-ogre");
  set_id(({"half-ogre"}));
  set_short("A half-ogre");
  set_long(
  "This half-ogre is incredibly large, even for one of his race, standing"+
  " over eight feet tall. He has wirey, greasy black hair and his skin"+
  " is a yellowish shade. He is quite ugly, with a large leering grin"+
  " on his face showing that he's also missing a couple of teeth. He"+
  " is fairly dirty and appears to use his clothing as a napkin judging"+
  " by the grease marks."
  );
  set_race("half-ogre");
  set_body_type("human");
  set_gender("male");
  set_size(3);
  set("aggressive",25);
  set_property("swarm",1);
  set_level(8);
  set_class("fighter");
  set_mlevel("fighter",8);
  set_max_hp(65);
  set_hp(65);
  set_exp(800);
  set_stats("strength",18);
  set_stats("dexterity",17);
  set_ac(5);
  set_alignment(9);
  new("/d/tharis/conforest/obj/lclub")->move(TO);
  command("wield club");
  new(OBJ2+"lrobe")->move(TO);
  command("wear robe");
   add_money("gold",random(100)+20);
  add_money("silver",random(700)+50);
  set_emotes(6,({
  "The half-ogre growls menacingly.",
  "The half-ogre roars and beats his chest.",
  "The half-ogre stomps his feet angrily.",
  }),1);
}
