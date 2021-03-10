// giantbee.c - Giant honeybees for Lothwaite.  Adapted from newbieland bees

#include <std.h>
#include "../lothwaite.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("bee");
  set_id(({"bee","giant bee"}));
  set_race("bee");
  set_gender("female");
  set_short("Giant bee");
  set_long("A giant bee with a body around six inches long and %^YELLOW%^yellow stripes %^RESET%^%^CYAN%^circling the abdomen and head.  This one is a worker bee, an undeveloped female.  It has a nasty sting and is fiercely protective of the hive.");
  set_hd(1,1);
  set_alignment(6);
  set_body_type("insectoid-winged");
  set_size(1);
  set_hp(50);
  set_stats("dexterity",20);
  set_overall_ac(-5);
  set_exp(550); 
  set("aggressive", 20);
  set_achats(6, ({ 
	"%^YELLOW%^The bee buzzes and flies around you angrily, diving in to try to sting!",
 	"%^YELLOW%^The bee buzzes around her hive protectively.", 
	"%^YELLOW%^The bees swarm around your face and head!!!!" 
  }) );
  set_funcs(({"sting","sting","sting","sting","swarm_em"}));
  set_func_chance(12);
}

void sting(object targ) {
    targ->do_damage("torso",random(6)+5);
    tell_object(targ, "%^BOLD%^%^RED%^The bee finds exposed skin to sting!\nIt feels like you've been hit hard with a red-hot dart as the stinger and venom shoot into you!\n");
    tell_room(ETO, "%^BOLD%^%^RED%^The bee finds some exposed skin and slams into "+targ->query_cap_name()+".\nIt leaves a nasty welt from the sting!", targ);
}

void swarm_em(object targ){
   targ->do_damage("torso",random(6)+5);
   targ->set_paralyzed(random(3)+1,"The bees are swarming around you, making it impossible to move!");
   tell_object(targ,"%^BOLD%^%^RED%^The bees suddenly swarm around you angrily, stinging you all over!");
   tell_room(ETO,"%^BOLD%^%^RED%^The bees swarm all around "+targ->QCN+"!",targ);
}