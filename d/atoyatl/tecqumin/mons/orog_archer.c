//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MOB + "orog";
#define EYECOLOUR ({"%^BOLD%^%^GREEN%^green%^RESET%^",\
                    "%^BOLD%^%^YELLOW%^yellow%^RESET%^"})

int climbed;
nosave int BEAT, heartcount;

void create()
{
      object bow, bolt;
      ::create();
      climbed = 0;
  	set_name("orog archer");
  	set_id(({"archer", "orog", "humanoid", "orog archer", "crossbowman", "orog crossbowman"}));
  	set_short("orog archer");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
  	set_long("%^GREEN%^This orog crossbowman stands just over six feet in height, with a more"
              +"  upright posture than " + QP+ " orcish cousins. " + capitalize(QS) + " has a broad,"
              +" powerful back and chest and thick, muscular limbs. " + capitalize (QP) + " face is"
              +" thoroughly orcish in origin though, with a broad snout and large, tusklike canines.");
  	set_race("orog");
  	set_body_type("humanoid");
  	set_hd(50,12);
  	set_size(2);
  	set("aggressive",(:TO, "aggro_me":));
	set_class("fighter");
	set_mlevel("fighter",53);
	set_guild_level("fighter",53);
   	set_hp(random(1000)+800 + random(400));
	set_max_level(49);
	set_property("swarm",1);
  	set_overall_ac(-65);
      set_size(2);
      set_attack_bonus(67); 
      set_property("magic",1);
      set_new_exp(50, "normal");
	set_max_level(50);
	set_property("swarm",1);
  	set_alignment(4);
      set_property("full attacks",1);
      bolt = new ("/d/common/obj/lrweapon/hquarrels");
      bow = new("/d/common/obj/lrweapon/hcrossbow");
      bow->set_property("enchantment", 6);
      if (random(5)){
        bow->set_property("monsterweapon",1);
      }
      bolt->move(TO);
      bow->move(TO);
      force_me("wield bow");
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}
void init()
{
  ::init();
}

void heart_beat(){
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

void check_my_heart()
{
    if (heartcount>1000){
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

void aggro_me(){
  if (!TP->query_true_invis() && !TP->id("orog") && !TP->id("ram")){
    force_me("kill " + TP->query_race());
  }
}
/*
void catch_tell(string str){
  if (interact("out of nowhere hits you!", str)){
    tell_object(find_player("lujke"), "The orog has been hit!");
    if (random(6)>3){
      tell_room(ETO, query_short() + ARROWDEATH[random(sizeof(ARROWDEATH))]);
      call_out("die", 1,TO);
    }
  }
}*/

int clean_up(){return 1;}

void log(string str){
  object battler, *kids;
  int i;
  kids = children(TABAXOBJ + "tabaxi_battler.c");
  if (sizeof(kids)>0){
    for (i=0;i<sizeof(kids);i++){
      if (objectp(kids[i])){ 
        battler = kids[i];
        break;
      }
    }
  }
  if (objectp(battler)){
    battler->log(str);
  }
}
