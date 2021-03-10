//orccaptain.c - updated to use current code by Circe - 8/27/03
#include "summoned_monster.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("orc captain");
   set_id(({"orc","orc captain","captain","monster"}) );
   set_race("orc");
   set_gender("male");
   set_short("A rough-looking orc captain");
   set_long(
      "This strong and brutish orc looks much like a primitive human.  "+
      "He has small, yellowed tusks that jut upward from his lower jaw, and "+
      "his eyes are reddish and feral.  His skin is an ugly, mottled gray "+
      "that looks almost sickly, though his thickly muscled body suggests "+
      "he is anything but weak.  His hide armor is well-maintained, as is the "+
      "large halberd he wields.  He looks defiant and confident and would "+
      "most likely not back down from any fight."
   );
   set_level(9);
   set_hd(9, 4);
   set_body_type("human");
   set("aggressive",20);
   set_alignment(3);
   set_size(2);
   set_overall_ac(8);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",14);
   set_stats("constitution",7);
   set_max_hp(query_hp());
   set_wielding_limbs( ({ "right hand", "left hand"}) );
   new(CWEAP"halberd")->move(TO);
   command("wield halberd in right hand and left hand");
   new(CARMOR"hide")->move(TO);
   command("wear armor");
   add_money("silver",random(10));
   add_money("gold",random(20));
   set_max_level(10);
   set_exp(200);
   set_hp(65+random(20));
}
