//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit "/std/monster";

void create(){
   ::create();
   set_name("ogre");
   set_id(({"ogre","fighter","monster"}));
   set_short("A hulking ogre");
   set_long(
   "This is a very large smelly ogre. He's incredibly ugly and"+
	" looks very mean. In his hand is a large, worn club. The"+
	" only thing he's wearing is a loin cloth, but you are very"+
	" thankful for his modesty. His mouth is open, showing you"+
	" some yellow teeth. He is very repulsive."
   );
   set_gender("male");
   set_body_type("ogre");
   set_class("fighter");
   set_mlevel("fighter",15);
	set_hd(15,7);
	set_max_level(20);
   set_level(15);
	set_stats("strength",21);
	set_stats("constitution",20);
   set_alignment(9);
   set_size(3);
   set_max_hp(random(50)+100);
   set_overall_ac(3);
   set_hp(query_max_hp());
   set_race("ogre");
   set_wielding_limbs(({"right hand", "left hand"}));
   new(OBJ+"loin.c")->move(TO);
   command("wear loin cloth");
   switch(random(4)){
      case 0..2:  new(OBJ+"club.c")->move(TO);
                  break;
      case 3:  new(OBJ+"ogre_club")->move(TO);
               break;
   }
   command("wield club");
   add_money("electrum",random(50));
//   set_exp(1400);
	set_new_exp(15,"normal");
	set_property("swarm",1);
	set("aggressive",25);
}
