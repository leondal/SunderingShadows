//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

object grabbed;
int treed;

void breakout(object ob);

void create()
{
      ::create();
      set_property("not random monster", 1);
      grabbed = 0;
      treed = 1;
  	set_name("python");
  	set_id(({"massively huge python", "python",
               "huge python","snake","monster",
                       "huge snake",}));
  	set_short("%^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n %^GREEN%^in the trees");
      set_long( (:TO, "long_desc" :) );
  	set_race("snake");
  	set_body_type("snake");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
  	set_hd(35,12);
  	set_size(3);
  	set("aggressive",25);
	set_class("fighter");
	set_mlevel("fighter",28);
	set_level(28);
	set_guild_level("fighter",28);
   	set_hp(random(200)+500);
	set_speed(30);
 	set_nogo(({ ""}));
   	set_exp(5000);
	set_max_level(27);
	set_property("swarm",1);
  	set_overall_ac(-10);
  	set_alignment(4);
      set_property("full attacks",1);
      set_funcs(({"grab", "grab", "grab", "climb", "climb"}));
      set_func_chance(35);
      set_num_attacks(3);
  	set_emotes(10,({    	}),1);
  	set_emotes(10,({      	}),0);
}
void init()
{
  ::init();
  add_action("pull_python", "pull");
  add_action("pull_python", "drag");  
  add_action("pull_python", "yank");
  add_action("pull_python", "pull");
  add_action("pull_python", "jerk");
  add_action("pull_python", "pull");
  add_action("pull_python", "tug");
  add_action("pull_python", "wrench");
}

void die(mixed ob)
{
  ::die(ob);
  if (objectp(grabbed)){
    tell_object(grabbed, "You are freed from the python's coils as it dies");
    if (objectp(ETO)) {
      tell_room(ETO, grabbed->QCN + " is freed from the python's coils as it"
                    +" dies", grabbed);
    }
    grabbed->remove_paralyzed();
  }
}

int pull_python(string str){
  int how_strong, how_agile;
  string what, junk;
  if (sscanf (str, "$s from $s", what, junk)< 2){
    if (sscanf (str, "$s down $s", what, junk)< 1){
      what = str;
    }
  }
  if (!id(what)){
    return 0;
  }
  if (treed != 1){
    notify_fail("The python is already on the ground!");
    return 0;
  }
  how_strong = TP->query_stats("strength");
  how_agile = TP->query_stats("dexterity");
  if (random(how_agile)<9){
    tell_object(TP, "%^BLUE%^You grab for the"
               +" %^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n%^RESET%^%^BLUE%^, but don't"
               +" manage to get a hold of it%^RESET%^");
    tell_room(ETO, TPQCN + "%^RESET%^%^BLUE%^ tries to grab hold of the"
               +" %^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n%^RESET%^%^BLUE%^, but doesn't"
               +" manage to catch it.", TP);
    return 1;
  }
  if (random(how_strong)<9){
    tell_object(TP, "%^BLUE%^You grab the"
               +" %^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n%^RESET%^%^BLUE%^, but don't"
               +" manage to pull it down");
    tell_room(ETO, TPQCN + "%^RESET%^%^BLUE%^ grabs hold of the"
               +" %^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n%^RESET%^%^BLUE%^, but doesn't"
               +" manage to pull it down.", TP);
    return 1;
  }
  tell_object(TP, "%^ORANGE%^You grab hold of the"
                 +" p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^"
                 +"%^GREEN%^o%^ORANGE%^n%^RESET%^%^ORANGE%^ and drag it down"
                 +" to the ground");
  tell_room(ETO, TPQCN + "%^ORANGE%^ grabs hold of the "
                 +" p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^"
                 +"%^GREEN%^o%^ORANGE%^n%^RESET%^%^ORANGE%^ and drags it down"
                 +" to the ground", TP);
  treed = 0;
}

void fall(){
  if (objectp(ETO)){
    tell_room(ETO, "The massive %^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^"
                  +"t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
                  +"%^RESET%^ falls to the ground!");
  }
  	set_short("%^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n on the ground");
  treed = 0;
}

void climb(){
  if (treed==1){
    return 0;
  }
  if (objectp(grabbed) && present(grabbed, ETO)){
    return;
  }
  set_short("%^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^t%^BOLD%^%^GREEN%^h"
               +"%^RESET%^%^GREEN%^o%^ORANGE%^n %^GREEN%^in the trees");
  if (objectp(ETO)){
    tell_room(ETO, "The massive %^RESET%^%^ORANGE%^p%^GREEN%^y%^ORANGE%^"
                  +"t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
                  +"%^RESET%^ %^GREEN%^slithers up the bole of a tree to"
                  +" hide in the branches!");
  }
  treed = 1;
}

string long_desc(){
  switch(treed){
  case 1:
    return "%^ORANGE%^This massive snake must be at least twenty"
              +" five feet long, with a body as thick as a powerfully"
              +" built man's thigh. It is curled and looped around the"
              +" bough of a tree overhead.\n%^RESET%^It might be possible to"
              +" drag it down.";
     break;
   default:
    return "%^ORANGE%^This massive snake must be at least twenty"
              +" five feet long, with a body as thick as a powerfully"
              +" built man's thigh. It moves swiftly and agressively"
              +" over the ground.";
  }
}

void constrict(){
  int hp;
  if (!objectp(grabbed) || !objectp(ETO) ||!present(grabbed, ETO)){
    set_num_attacks(3);
    return;
  }
  if (!objectp(ETO)){ return;}
  tell_object(grabbed, "%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^p%^GREEN%^y"
               +"%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
               +"%^GREEN%^'s %^BOLD%^%^GREEN%^coils constrict, tightening"
               +" the pressure round your ribs and making it harder"
               +" and harder for you to breathe.");
  tell_room(ETO, "%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^p%^GREEN%^y"
               +"%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
            +"%^BOLD%^%^GREEN%^ tightens its coils around " 
            + (string)grabbed->QCN + "'s ribs, squeezing the life out of " 
            + (string)grabbed->QO, grabbed);
    hp = (int)grabbed->query_max_hp()/5;
    grabbed->do_damage(grabbed->return_target_limb(),random(hp));
    grabbed->add_attacker(TO);
    grabbed->continue_attack();
  call_out("constrict", 2 + random (2));
}


void grab(object targ){
  object room;
  room = ETO;
  if (grabbed !=0 || treed !=1){return;}
  if (!objectp(targ)||!objectp(room)) { return; }
  tell_object(targ, "%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^p%^GREEN%^y"
              +"%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
              +" %^BOLD%^%^GREEN%^loops its muscular, entangling coils around"
              +" you, trapping your arms and beginning to squeeze the"
              +" life out of you.");
  tell_room(room, "%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^p%^GREEN%^y"
               +"%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
               +"%^BOLD%^%^GREEN%^ loops its muscular, entangling"
                 +" coils around " + (string)targ->QCN 
                 +"'s body and begins to squeeze the life out of " 
                 + (string)targ->QO, targ);
  targ->set_paralyzed(1000, "%^GREEN%^You are %^BOLD%^%^GREEN%^trapped"
                         +"%^RESET%^%^GREEN%^ in the %^ORANGE%^p%^GREEN%^y"
              +"%^ORANGE%^t%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^o%^ORANGE%^n"
              +"%^BOLD%^%^GREEN%^'s coils!");
  grabbed = targ;
  set_num_attacks(0);
  call_out("constrict", 3 + random(3), targ);
  call_out("breakout", 4 + random (3), targ);
}

void breakout(object ob){
  object room;
  int str, skill, dex, level;
  room = ETO;
  if (!objectp(ob) || !objectp(room) ||!present(ob, room)){
    set_num_attacks(3);
    return;
  }
  if (grabbed != ob){
    tell_object(ob, "You are not in the python's clutches. You will probably"
                   +" get your breath back and be able to move again soon");
    return;
  }
  str = (int)TP->query_stats("strength");
  dex = (int)TP->query_stats("dexterity");
  skill = TP->query_nwp("escape");
  level = TP->query_max_level();
  if (random(185 - level)<skill){
    tell_object(ob, "Wriggling skillfully, you manage to work your way free"
                   +" from the python's coils.");
    tell_room(room, "Wriggling skillfully, " + ob->QCN + " manages to work"
                   + ob->QP + " way free of the python's coils", ob);
    ob->remove_paralyzed();
    grabbed = 0;
    set_num_attacks(3);
    return;
  }
  if (random(185 - level)<str){
    tell_object(ob, "With a mighty heave, you manage to force apart the"
                   +" entwining coils of the python and lift them over your"
                   +" head, freeing yourself");
    tell_room(room, "With a mighty heave, " + ob->QCN + " manages to force"
                   +" the coils of the python apart and thrust them over " 
                   + ob->QP + " head, breaking "+ ob->QO+"self free of its"
                   +" grip", ob);
    ob->remove_paralyzed();
    grabbed = 0;
    set_num_attacks(3);
    return;
  }
  if (random(185 - level)<dex){
    tell_object(ob, "Finding the smallest of gaps between the coils of the"
                   +" python, you manage to slip free with an agile twist.");
    tell_room(room, "With an agile twist, " + ob->QCN + " manages to slip"
                   +" free of the python's coils", ob);
    ob->remove_paralyzed();
    grabbed = 0;
    set_num_attacks(3);
    return;
  }
  tell_object(ob, "You struggle against the python's coils, but are unable to"
                 +" get free.");
  tell_room(room, ob->QCN + " struggles against the python's coils, but is"
                 +" unable to get free.", ob);
  set_num_attacks(0);
//  ob->remove_paralyzed();
//  ob->set_paralyzed(100, "You are entangled in the python's coils!");   
  call_out("breakout", 2 + random (3), ob);
}
