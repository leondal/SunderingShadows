#include <std.h>
//Raising the exp per Ares order to increase leveling speed. Dinji 8/14/07
#include "../meadow.h"
inherit WEAPONLESS;

void create()
{
   object ob;
  ::create();
  set_name("wereboar");
  set_id(({"wereboar","angry wereboar","were boar","lycanthrope","monster"}));
  set_short("An angry wereboar");
  set_long("If the beast were to straighten up, he would easily be "+
	"over six feet tall.  Instead, he stands stooped over, to the "+
	"point that his fingers nearly drag across the ground.  He "+
	"resembles a hairy human from the shoulders down, dressed in "+
        "ripped and torn clothing.  He has the haunches, hooves and head of a wild boar, "+
	"with two sharp tusks protruding from his lower jaw.  Wereboars "+
	"have a reputation for being...difficult, to say the least, but "+
	"this one seems enraged over something.");
  set_hd(11,5);
  set_race("wereboar");
  set_body_type("human");
  set_gender("male");
  set_size(3);
  set("aggressive",25);
  set_property("swarm",1);
  //set_level(14);
  //set_class("fighter");
  //set_mlevel("fighter",14);
  set_hp(random(25)+80);
   //set_exp(400);
   set_new_exp(7,"normal");
  set_damage(1,5);
  set_stats("strength",17);
  set_attacks_num(2);
  set_base_damage_type("piercing");
  add_limb("tusks","head",0,0,0);
  add_limb("left hoof","left leg",0,0,0);
  add_limb("right hoof","right leg",0,0,0);
  remove_limb("left foot");
  remove_limb("right foot");
  set_attack_limbs(({"tusks","right hand","left hand"}));
//  set_property("weapon resistance",1);  not appropriate now that it's a lowbie area
  set_ac(4);
  set_funcs(({"charge"}));
  set_func_chance(8);
  set_alignment(5);
  add_money("gold",random(50)+25);
  set_max_level(12);
   if(!random(3)) {
      new(OBJ+"luckyhorseshoes")->move(TO);
      command("wear horseshoes");
   }
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("werebeast fang");
      ob->move(TO);
    }
}

void charge(object targ)
{
  switch(random(20)) 
  {
    case 0..4:
      tell_object(targ,"%^CYAN%^The wereboar reaches out and tries "+
	  "to grab you, but you manage to slip out of his reach.%^RESET%^");
      tell_room(ETO,"%^CYAN%^"+TQCN+" scampers aside as the wereboar "+
	  "attempts to grab "+targ->query_subjective()+".%^RESET%^",targ);
    break;
    case 5..15:
      tell_object(targ,"%^CYAN%^The wereboar grabs a hold of your "+
	  "arms and pulls you towards him.  He thrusts his tusks towards "+
	  "you, impaling your chest!%^RESET%^");
      tell_room(ETO,"%^CYAN%^The wereboar grabs "+TQCN+" by the arms "+
	  "and thrusts his tusks into "+targ->query_possessive()+" "+
	  "chest!%^RESET%^",targ);
    targ->do_damage("torso",roll_dice(1,6));
    targ->set_tripped(1,"You're recovering from your chest being impaled!");
    break;
    case 16..19:
      tell_object(targ,"%^CYAN%^The wereboar grabs a hold of your "+
	  "arms and pulls you towards him.  He thrusts his tusks towards "+
	  "you, impaling your chest!%^RESET%^");
      tell_object(targ,"%^ORANGE%^The wereboar pulls you to the left "+
        "while he jerks his head to the right, tearing his tusks "+
	  "through your flesh!%^RESET%^");
      tell_room(ETO,"%^CYAN%^The wereboar grabs "+TQCN+" by the arms "+
	  "and thrusts his tusks into "+targ->query_subjective()+" "+
	  "chest!%^RESET%^",targ);
      tell_room(ETO,"%^ORANGE%^The wereboar then pulls "+TQCN+" to one side "+
	  "while jerking his head to the other.  Blood splatters across the "+
	  "the ground as his tusks tear into "+TQCN+"'s flesh.%^RESET%^",targ);
    targ->set_tripped(1,"You're recovering from your chest being impaled!");
    targ->do_damage("torso",roll_dice(2,4));
    break;      
  }
}
