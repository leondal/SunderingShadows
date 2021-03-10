//goblincaptain.c - updated to use current code by Circe - 8/25/03
#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("goblin captain");
   set_id(({"goblin","captain","goblin captain","monster"}));
   set_race("goblin");
   set_gender("male");
   set_short("A goblin captain");
  set_long(
         "This goblin is a short, brutish looking humanoid with a flat face.  "+
         "His nose seems like it has been smeared across his face just above "+
         "his wide mouth filled with needle-like yellow teeth.  His dull, glazed "+
         "eyes are yellow-red and sparkle occasionally with the delicious thought "+
         "of inflicting pain on others.  This particular goblin stands a little taller "+
         "than most and seems to take his height as a mark of honor, bullying other "+
         "goblins whenever they are around."
      );
   set_level(8);
   set_body_type("human");
   set("aggressive",19);
   set_alignment(3);
   set_size(1);
   set_overall_ac(8);
   set_stats("intelligence",10);
   set_stats("wisdom",8);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",18);
   set_stats("constitution",7);
   set_hd(8, 1);
   set_max_hp(query_hp());
   set_wielding_limbs( ({ "right hand", "left hand"}) );
   new(WEAPONDIR+"shortsword")->move(TO);
   command("wield sword");
   new(WEAPONDIR+"dagger")->move(TO);
   command("wield dagger");
   new(ARMORDIR+"leather")->move(TO);
   command("wear leather");
   add_money("silver",random(25));
   add_money("gold",random(50)+50);
   add_money("electrum",random(50));
   set_max_level(10);
 	//set_exp(200);
   set_exp(900);
	set_hp(random(20)+40);
}
