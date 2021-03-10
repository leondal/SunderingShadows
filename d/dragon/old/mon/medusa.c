// medusa.c

#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;


void create(){
  ::create();
  set_name("medusa");
  set_id(({"medusa","Medusa"}));
  set_short("A Medusa");
  set_long("%^BOLD%^%^BLUE%^
This medusa appears to be quite shapely and human.  However, her face is
of horrid visage, and its snakey hair writhes, so at a close distance this
gives here away.  She has glaring red-rimmed eyes.
  ");
  set_overall_ac(4);
  set_race("medusa");
  add_limb("right arm","body",0,0,0);
  add_limb("head","body",0,0,0);
  add_limb("left arm","body",0,0,0);
  add_limb("body","body",0,0,0);
  add_limb("right leg","body",0,0,0);
  add_limb("left leg","body",0,0,0);
  add_limb("left hand","left arm",0,0,0);
  add_limb("right hand","right arm",0,0,0);
  set_attack_limbs(({"right hand","left hand"}));
  set_attacks_num(2);
  set_funcs(({"bite","gaze"}));
  set_func_chance(50);
  set_size(2);
  set_alignment(9);
  set_damage(1,6);
  set_hd(8,10);
  set_hp(95);
  set_exp(9200);
  set_gender("female");
  call_out("start_wonder", 1);
}

void init() {
  string *exits;
  int i;
  object *inven;
  if(avatarp(TP)) return;
  kill_ob(TP,1);
tell_room(ETO, "%^BOLD%^GREEN%^The Medusa rushes you so that her asp-like head growth can bite you.");
  exits = (string *)environment(TO)->query_exits();
  for(i = 0;i<sizeof(exits);i++)
    add_action("chase",exits[i]);
  ::init();
}

int chase() {
  string verb;
  verb = query_verb();
  if((object *)TO->query_attackers() != ({}))
  call_out("go",1,verb);
  return 0;
}

void go(string verb) {
  command(verb);
}

int bite(object targ) {
  string dam;
  if(SAVING_D->saving_throw(targ, "poison")) {
    dam = "hurts";
  } else {
    dam = "poisons";
  }
  tell_object(targ, "Medusa rushes you, so that her asp-like head growth can bite you.");
  tell_room(environment(targ), "%^BOLD%^%^YELLOW%^Medusa rushes towards "+targ->query_cap_name()+", so that her asp-like head growths could bite "+targ->query_objective()+".",targ);
  if(dam == "poisons") {
    targ->die();
    tell_object(targ, "You feel the life drain from you as Medusa's asp-like head connects with a solid hit.");
  } else {
    targ->do_damage("torso", roll_dice(1,3));
    targ->set_paralyzed(40, "The venom of the bite siezes your muscles.");
  }
  return 1;
}

int gaze(object targ) {
  object ob, statue;
  if((string)targ->query_property("strength") == "petrifaction") {
    write("%^BOLD%^%^FLASH%^You avert the gaze of a Medusa.");
    return 1;
  }
  if(SAVING_D->saving_throw(targ, "petrifaction")) {
    tell_object(targ, "%^GREEN%^You avert the gazing eyes of Medusa!");
  } else {
    tell_object(targ, "%^RED%^You gaze into Medusa's glaring red-rimmed eyes.");
    tell_object(targ, "%^RED%^You feel your life escaping you, as the gaze causes your muscles to stiffen as hard as stone!");
    if(ob = present("corpse", environment(TO))) {
      statue = new(OBJECT);
      statue->set_name("statue");
      statue->set_id(({"statue"}));
      statue->set_short("%^BOLD%^%^YELLOW%^A stone statue of "+targ->query_cap_name());
      statue->set_weight(1000);
      statue->set_long("
This was once a famous warrior that adventured the lands of Shadowgate.
The accomplishments of this warrior vanished with this stone statue.");
      statue->move(environment(TO));
      ob->remove();
      "/d/dragon/sewer/statues_d"->add_statue(ETO,targ->query_name());
    }
  targ->die();
  }
  return 1;
}

void heart_beat() {
  ::heart_beat();
}

void start_wonder() {
  environment(this_object())->init();
  call_out("do_wonder", 30);
}

void do_wonder() {
  string *exits;
  int i,j;
  if((mixed *)this_object()->query_attackers() == ({})) {
    exits = environment(TO)->query_exits();
    i = sizeof(exits);
    if(exits && i) {
      j = random(i);
      if(exits[j] != "up")
        this_object()->force_me(exits[j]);
    }
  }
  call_out("do_wonder", 20);
}
