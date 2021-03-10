// spits out spores every round
#include <std.h>
#include "../deep_echo.h"
#include <magic.h>
#include <daemons.h>

inherit "/std/monster";

int nom;
void create() {
object obj;
  ::create();
  set_name("%^RESET%^%^ORANGE%^mold man%^RESET%^");
  set_id(({"man","mold man","moldy figure","mold","moldman","figure"}));
  set_gender("male");
  set_race("mold man");
  set_short("%^RESET%^%^ORANGE%^moldy figure%^RESET%^");
  set_long(
"This looks like a person covered in a yellow gray "+
"fuzz.  He is average height for a human, just under"+
" six foot.  His build is impossible to tell, certain "+
"parts of his body look massive others look small."+
"  If he is strong or weak it is uncertain."+
"  His body is bloated and disfigured.  "+
"There is a hazy cloud of spores around him.  "+
"He wears no clothing, the fungus gives his whole body a spongy texture.");

  set_body_type("humanoid");
  set_class("fighter");
  add_search_path("/cmds/fighter"); 
  set_max_level(17);
  set_hd(17,10);
  set_hp(150+random(135));
  set_max_hp(query_hp());
  set_property("full attacks",1);
  set_property("swarm",1);
  set_stats("strength",15);
  set_stats("constitution",24);
  set_stats("intelligence", 6);
  set_stats("wisdom", 6);
  set_stats("charisma",25);
  set_stats("dexterity",6);
  set("aggressive",7);
  set_alignment(8);
  set_size(2);
  set_property("damage resistance",16);
  // set_exp(5000);
  set_new_exp(15,"normal");
  if(random(3)==1)
    new(OBJ"headband_acc")->move(TO);
  force_me("wearall");
}

void spork(){  //poof at ppl in room
  object *ppl;
  int i;
  if(!ETO) return;
  
  ppl=filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
  
  tell_room(ETO, 
    "%^ORANGE%^A puff of spores burst from mold man.");
  for (i = 0; i < sizeof (ppl); i++){
    if(!objectp(ppl[i])) continue;
    if(!"/daemon/saving_throw_d.c"->fort_save(ppl[i],-15)) {
	 tell_object(ppl[i],
	   "%^ORANGE%^The spores cause you to cough and choke.");
	 ppl[i]->set_paralyzed(40,"The spores eat through your body.");
	 ppl[i]->add_attacker(TO);
	 ppl[i]->cause_typed_damage(ppl[i],0,roll_dice(1,6),"acid");
	 }
	
  }
}
// spores each round
void heart_beat(){
  ::heart_beat();
  nom++;
  if( nom ==ROUND_LENGTH){
    spork();
	nom = 0;
  }

}
