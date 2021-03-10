// a big mong with some neat stuff hades 4/6/11
#include <std.h>
#include "/d/islands/dinosaur/short.h"
#define LIMBS ({"right foot", "left foot", "right leg", "left leg", "right arm", "left arm", "head", "torso"})
#define MOB_TYPES ({"frog", "cat", "dog", "horse", "elephant", "fish","lizard"})

inherit MONSTER;

string *my_limbs;

string *choose_limbs(){
    string *lmbs, *lmbs2;
    int xyz, x, i;

    lmbs = ({"right foot", "left foot", "right leg", 
    "left leg", "right arm", "left arm", "head"});
    xyz = 20;
    while(xyz > 5){
      xyz = random(sizeof(lmbs)+1);
    }

    lmbs2 = ({});
    for(i=0;i<xyz;i++){
      x = random(sizeof(lmbs));
      lmbs2 += ({lmbs[x]});
      lmbs -= ({lmbs[x]});
    }

    return lmbs2;
}

void create_mong_body(string *str){
    string *lmbs;
    string temp, gtype;
    string lng;
    int i;

    lmbs = str;
    lng = "%^ORANGE%^This creature looks vaguely like"+
    " a %^BOLD%^giant%^RESET%^%^ORANGE%^ of some sort."+
    "  However closer inspection yields to a"+
    " %^RED%^monstrosity%^ORANGE%^ of body parts including";
    set_body_type("humanoid");
    for(i=0;i<sizeof(lmbs);i++){
      remove_limb(lmbs[i]);
      gtype = MOB_TYPES[random(sizeof(MOB_TYPES))];
      temp = gtype+"'s "+lmbs[i];
      lng = lng + ", a "+temp+"";
      my_limbs += ({temp});
      add_limb(temp, temp, 0, 0, 0);
    }
    if(!sizeof(lmbs)) lng += " well, it looks completely human.";
    set_long(lng);
}

void create(){
    string *duh;
    ::create();
    my_limbs = ({});
    duh = choose_limbs();
    create_mong_body(duh);
    set_name("mongrelman");
    set_id( ({"mong", "mongrelman", "humanoid", "dino"}) );
    set_short("%^RESET%^%^GREEN%^Giant Mo%^ORANGE%^n%^GREEN%^gre%^ORANGE%^l%^GREEN%^man");
    set_hd(20,1);
    set_gender("male");
    set_race("mongrelman");
    set_size(3);
    set_max_hp(600+random(900));
    set_hp(query_max_hp());
    set_exp(15000);
    set_alignment(6);
    set_max_level(35);
    set_class("fighter");
    set_mlevel("fighter",35);
    set_stats("intelligence",5);
    set_stats("wisdom",5);
    set_stats("strength",23);
    set_stats("charisma",3);
    set_stats("dexterity", 17);
    set_stats("constitution",20);
    add_search_path("/cmds/fighter");
    set_property("swarm",1);
	set_property("no disarm",1);
    add_money("platinum", roll_dice(5,10));
    set_moving(1);
    set_speed(10);
    if(random(3)){
      new(OPATH "gclub.c")->move(TO);
      command("wield club");
      new(OPATH "lg_armor.c")->move(TO);
      command("wear armor");
    } else {
       new(OPATH "human_club.c")->move(TO);
       command("wield club");
       new(OPATH "human_club.c")->move(TO);
       command("wield club");
       "/d/common/daemon/randgear_d"->armor_me(TO,"armorlt",20,4);
	   new(OPATH "tboots.c")->move(TO);
       command("wear armor");
    }
    set_property("add kits",20);
    set_property("full attacks", 1);
  set_monster_feats(({"light weapon","crushingstrike","blade block",
  "sweepingblow","impale","rush","powerattack","sunder"
  "two weapon fighting","ambidexterity","greater two weapon fighting",
  "two weapon defense","knockdown","exotic weapon proficiency"}));
  add_damage_bonus(6);
  set_property("damage resistance",7); //hard for melee
  set_funcs(({"kick"}));
  set_func_chance(30);
}
void kick(object targ)
{
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
                
   tell_object(targ,"%^ORANGE%^The you get a giant foot to the face!");
   tell_room(ETO,"%^ORANGE%^The giant mongrelman kicks"+
   " "+targ->query_cap_name()+" in the face!",targ);
   targ->do_damage(targ->return_target_limb(),random(60)+20);
   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-25))
    targ->set_paralyzed(10+random(20),
     "%^BLUE%^Your face hurts too much!");

   return 1;
}
void heart_beat(){
  object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return;
 
  if(!objectp(query_current_attacker())) { return ; } 
   if(query_attackers()==({ })) return;
  attackers = query_attackers();
  x = sizeof (attackers);
  if(random(2)==0)
    force_me("knockdown "+attackers[random(x)]->query_name());
  if(random(2)==0)
    force_me("rush "+attackers[random(x)]->query_name());
  if(random(2)==0)
    force_me("sunder "+attackers[random(x)]->query_name());
  force_me("flash");
  return;
}


int free_movement() { return 1; }
