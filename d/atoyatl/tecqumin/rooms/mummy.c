//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit WEAPONLESS;

object dragee;

void create()
{
      string gender_poss,gender_Subj, gender_subj, gender_obj;
      object guider;
      ::create();
  	set_name("Mummy");
  	set_id(({"mummy","tecqumin mummy","undead"}));
  	set_short("%^RESET%^%^ORANGE%^Tecqumin %^BOLD%^%^WHITE%^Mummy"
        +"%^RESET%^");
  	set_race("undead");
  	set_body_type("humanoid");
  	if (random(2)){
        set_gender("male");
        gender_poss = "his";
        gender_Subj = "He";
        gender_subj = "he";
        gender_obj = "him";
      } else {
        set_gender("female");
        gender_poss = "her";
        gender_Subj = "She";
        gender_subj = "she";
        gender_obj = "her";
      }
  	set_long("%^RESET%^The corpse of a %^CYAN%^Tecqumin %^RESET%^noble, wrapped"
        +" in %^BOLD%^%^WHITE%^cloth%^RESET%^, preserved with %^BLUE%^embalming"
        +" %^RESET%^fluids and animated with %^BLUE%^secret %^BOLD%^m%^RESET%^"
        +"%^MAGENTA%^a%^BOLD%^%^BLUE%^g%^RESET%^%^BLUE%^i%^BOLD%^cs%^RESET%^. "
        + gender_Subj + " moves with a deceptive, lurching speed, and "
        + gender_subj +" long dead limbs possess a horrible strength. The entire"
        +" body is swathed in %^BOLD%^%^WHITE%^wrappings%^RESET%^, with a%^BOLD%^"
        +" %^CYAN%^mask%^RESET%^ over the face, presumably representing how " 
        + gender_subj + " looked in life." );
  	set_hd(220,12);
  	set_size(2);
  	set("aggressive",25);
	set_class("fighter");
	set_mlevel("fighter",50);
	set_level(70);
	set_guild_level("fighter",50);
   	set_hp(random(600)+700 + random(400));
	set_speed(0);
   	set_exp(250000);
	set_max_level(50);
	set_property("swarm",1);
  	set_overall_ac(-12);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "shatter",
        "sunder",
        "daze",
        "unarmed fighting"
    }));
  	set_alignment(4);
      set_funcs(({"shatter", "sunder", "rush", "summon_help"}));
      set_func_chance(25);
      set_mob_magic_resistance("average");
      set_property("bludgeoning resistance", 30);
      set_property("slashing resistance", 20);
      set_property("piercing resistance", 10);
      set_property("full attacks",1);
      set_property("swarm", 1); 
      set_property("shapeshifted", 1); //So that it can rush without a weapon
}

void init(){
  ::init();
}

void sunder(){
  object * critters;
  string who;
  tell_room(ETO, "Trying to sunder");
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizof(critters))]->query_name();
  force_me("sunder " + who); 
}

void shatter(){
  object * critters;
  string who;
  tell_room(ETO, "Trying to shatter");
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizof(critters))]->query_name();
  force_me("shatter " + who); 
}

void rush(){
  object * critters;
  string who;
  tell_room(ETO, "Trying to rush");
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizof(critters))]->query_name();
  force_me("rush " + who); 
}

void summon_help(){
  int i, num, target;
  object room, ob;
  target = 1+ random(1);
  num = 0;
  if (!objectp(ETO)){
    return;
  }
  if ( !interact("corridor", base_name(ETO))){
    return;
  }
  tell_room(ETO, "The %^ORANGE%^mummy %^RESET%^tilts its head back and lets"
    +" out an unsettling, moaning cry");
  for (i=1;i<7;i++){
    if (!file_exists(ROOMS + "corridor"+ i + ".c")){
       continue;
    }
    room = find_object_or_load(ROOMS + "corridor"+ i);
    if (objectp(room)){
      if (room->query_mummy()<1){
        continue;
      }
      room->set_mummy(0);
      ob = new(MOB + "mummy");
      ob->move(room);
      DESTINATIONS_D->generate_waystations(base_name(ETO),2, 2);
      ob->start_walking(base_name(ETO));  
      num ++;
      if (num<target){
        break;
      }
    }
  }
}
