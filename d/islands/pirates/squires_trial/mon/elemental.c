#include <std.h>
#include "../squires_trial.h"

//inherit MONSTER;
inherit WEAPONLESS;
int talked;
int rock_scrape(object targ);

void create(){
  ::create();
  set_name("massive rock elemental");
  set_short("%^RESET%^%^ORANGE%^Massive Rock Elemental%^BOLD%^%^RED%^");
  set_long(
      "%^RESET%^%^ORANGE%^" +
      "This elemental towers nearly twelve feet tall.  " +
      "Odd, misfigurations on what might be a head seem to " +
      "approximate a wide, slanted mouth, and two " +
      "%^BOLD%^%^BLACK%^dark but mismatched stones " +
      "%^RESET%^%^ORANGE%^" +
      "appear as close to eyes as anything else they could be.  " +
      "It appears very roughly bipedal, with a substance " +
      "and texture like brown sandstone.  Massive arms hang nearly to the " +
      "floor, and outscale it's oddly short legs.  It appears strange " +
      "that such a creature could exist, yet despite the " +
      "cracking stone form, this creature manages to move!  "
  ); 
  set_id( ({"elemental","rock elemental","massive elemental","massive rock elemental"}) );
  set_race("rock elemental");
  set_body_type("human");
  set_gender("neuter");
  set_size(3);
  set_hd(20,10);
  set_alignment(5);
  set_stats("strength",25);
  set_stats("dexterity",8);
  set_stats("constitution",18);
  set_stats("intelligence",4);
  set_stats("wisdom",11);
  set_stats("charisma",11);
  set_class("fighter");
  set_guild_level("fighter",20);
  set_property("full attacks",1);
  set_hp(300 + random(51));
  set_max_level(25);
  set_overall_ac(-4);
  set_funcs( ({"earth_smash"}) );
  set_func_chance(50);
  talked = 0;
  set_new_exp(20, "normal");
  set("aggressive","killtime");
  set_property("no tripped",1);
  set_property("no paralyze",1);
  add_attack_bonus(5);
  
  set_hit_funcs((["right hand":(:TO,"rock_scrape":),
                  "left hand":(:TO,"rock_scrape":),
                  "right arm":(:TO,"rock_scrape":),
                  "left arm":(:TO,"rock_scrape":),
                  "right leg":(:TO,"rock_scrape":),
                  "left leg":(:TO,"rock_scrape":),
                  "right foot":(:TO,"rock_scrape":),
                  "left foot":(:TO,"rock_scrape":)
  ]));
}

int rock_scrape(object targ){
  if(!objectp(targ)) return 0;
  tell_room(ETO, "%^RESET%^%^ORANGE%^The elemental grinds into " + 
        targ->QCN + "'s flesh with his strike!%^RESET%^%^WHITE%^",targ);
  tell_object(targ, "%^RESET%^%^ORANGE%^The elemental's rocky surface" +
        " rips at your flesh!%^RESET%^%^WHITE%^");
  //targ->do_damage("torso",random(6) + 4);
  return (random(6) + 4);
}

int earth_smash(){
  object *enemies;
  int i;
  enemies = all_living(ETO);
  if(sizeof(enemies) == 0) return 0;
  if(!talked){
    command("speech rumble the earth with words");
    command("say %^RESET%^%^ORANGE%^Should not be here!");
    command("say %^RESET%^%^ORANGE%^Earth's scar be cleansed!");
    talked = 1;
  }
  tell_room(TO,"%^RESET%^%^ORANGE%^The massive rock elemental lets out a " +
        "deafening cracking sound as he stretches up then %^BOLD%^%^RED%^" +
        "SLAMS %^RESET%^%^ORANGE%^his fists to the earth!");
  tell_object(enemies[i], "%^RESET%^%^ORANGE%^The elemental strikes " +
        "the ground causing waves of pain!" );
  for(i = 0; i < sizeof(enemies); i++){
    if(userp(enemies[i]) && !enemies->query_true_invis()){
      
      if( (random(14)+11) > enemies[i]->query_stats("dexterity")) {
        enemies[i]->do_damage("torso",random(30)+30); 
      }
      else{
        enemies[i]->do_damage("torso",random(15)+15);
      }
    }
  }  
}


int killtime(){
  if(!objectp(TP)) return 0;
  if(TP->query_true_invis()) return 0;
  command("kill "+TPQN);
  return 1;
}


