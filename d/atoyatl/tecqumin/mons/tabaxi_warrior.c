//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MOB + "tabaxi";
#define EYECOLOUR ({"%^BOLD%^%^GREEN%^green%^RESET%^",\
                    "%^BOLD%^%^YELLOW%^yellow%^RESET%^"})

void create()
{
      object bow;
      ::create();
      set_property("not random monster", 1);
  	set_name("tabaxi warrior");
  	set_id(({"warrior", "feline", "humanoid", "tabaxi","tabaxi warrior"}));
  	set_short("tabaxi warrior");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
  	set_long( (:TO, "long_desc" :) );
  	set_race("tabaxi");
  	set_body_type("humanoid");
	set_class("fighter");
	set_mlevel("fighter",53);
	set_guild_level("fighter",53);
   	set_hp(random(1000)+800 + random(400));
	set_max_level(49);
	set_property("swarm",1);
  	set_overall_ac(-66);
      set_size(2);
      set_attack_bonus(68); 
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "shatter",
        "sunder",
        "daze",
      })); 
      set_stats("strength",30);
      set_stats("intelligence",10);
      set_stats("dexterity",30);
      set_stats("charisma",6);
      set_stats("wisdom",20);
  	set_size(3);
        set("aggressive",8);
      set_skill("athletics", 45);
      set_skill("stealth", 45);
      set_skill("perception", 40);
  	set_alignment(7);
      set_property("full attacks",1);
      set_property("no random treasure", 1);
      set_property("not random monster", 1);
      set_new_exp(46, "normal");


}

void init(){
  ::init();
  if (objectp(ETO) && present("orog", ETO)){
    force_me ("kill orog");
  }
}
int clean_up(){return 1;}

string main_desc(){
       return "%^ORANGE%^The tabaxi are a race of upright standing"
              +" humanoid jaguars. This tabaxi warrior's brownish red coat has"
              +" rosetted spots. " + capitalize(QS) + " is tall and"
              +" slender, with eyes"
              +" of "+ EYECOLOUR[random(sizeof(EYECOLOUR))] +"%^ORANGE%^. "
              + capitalize(QS) + " has quick, stealthy movements, and " 
              + QP +" coat"
              +" pattern provides " + QO + " with natural camouflage. " 
              + QS +" is well armored and looks familiar with the use of " + QP
              +" carried weapons";
}
