//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MOB + "tabaxi";
#define EYECOLOUR ({"%^BOLD%^%^GREEN%^green%^RESET%^",\
                    "%^BOLD%^%^YELLOW%^yellow%^RESET%^"})

int climbed;
nosave int BEAT, heartcount;

void create()
{
      int i;
      object bow, arrows;
      ::create();
      climbed = 0;
  	set_name("tabaxi archer");
  	set_id(({"archer", "feline", "humanoid", "tabaxi","tabaxi archer"}));
  	set_short("tabaxi archer");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
  	set_long("%^ORANGE%^The tabaxi are a race of upright standing"
           +" humanoid jaguars. This tabaxi archer's brownish red coat has"
              +" rosetted spots. " + capitalize(QS) + " is tall and"
              +" slender, with eyes"
              +" of "+ EYECOLOUR[random(sizeof(EYECOLOUR))] +"%^ORANGE%^. "
              + capitalize(QS) + " has quick, stealthy movements, and " 
              + QP +" coat"
              +" pattern provides " + QO + " with natural camouflage. " 
              + QS +" is lightly armoured and carries a bone fused short"
              +" bow and a quiver of feather fletched arrows");
  	set_race("tabaxi");
  	set_body_type("humanoid");
  	set_hd(25,12);
  	set_size(2);
  	set("aggressive",6);
	set_class("fighter");
	set_mlevel("fighter",45);
	set_level(45);
	set_guild_level("fighter",45);
   	set_hp(random(750)+500);
	set_max_level(45);
	set_property("swarm",1);
  	set_overall_ac(-61);
      set_attack_bonus(64);
  	set_alignment(4);
      set_property("full attacks",1);
      bow = new(OBJ + "composite_bow");
      if (random(5)){
        bow->set_property("monsterweapon",1);
      }
      bow->move(TO);
      bow->set_property("enchantment", 6);
      for (i=0;i<3;i++){
        arrows = new("/d/common/obj/lrweapon/arrows");
        arrows->move(TO);
      }
      force_me("wield bow");
      set_no_clean(1);
      set_property("no random treasure", 1);
      set_property("not random monster", 1);
      set_new_exp(46, "normal");
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}

void init(){
  ::init();
  if (objectp(ETO) && present("orog", ETO)){
    force_me ("kill orog");
  }
}

void check_my_heart()
{
    if (heartcount>300){
      return;
    }
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}

void heart_beat(){
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

int clean_up(){return 1;}
