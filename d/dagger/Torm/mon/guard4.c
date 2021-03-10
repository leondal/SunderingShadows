#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create (){
  ::create ();
  set_moving(0);
  set_name("Torm city guard");
  set_id(({"private","guard","torm guard","soldier","Torm regular","infantry",
  "torm city guard","dayperson","torm guardsman"}));
  set_property("swarm",1);
  set_short("Torm city guard");
  set_long(
  "  This guardsman wanders about the city of Torm making sure everything goes smoothly in the markets and watching for thieves."
   "  His mithril armor and weapons shine brightly though and he looks proficient in his duties."
  );
set_property("swarm",1);
set_gender("male");
  if(!random(2)){
  set_race("human"); 
  } else {
  set_race("half-elf");
  }
set_body_type("human");
set_hd(18,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",18);
  set_property("full attacks",1);
  set_stats("strength",17);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(random(200)+40);
  set_hp(query_max_hp());
  set_exp(1500);
set("aggressive", 0);
  set_emotes(1,({"%^BOLD%^There is no where for a criminal to hide in Torm!!"}),1);
add_money("gold", 50 + random(100));
  set_overall_ac(8);
new(OBJ"Mspear+1.c")->move(TO);
  command("wield spear in left hand");
  new(OBJ"torm_scalemail.c")->move(TO);
 command("wearall");
}
