//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

object seizee;
nosave int BEAT, heartcount;
int swallowing;
void breakout(object ob);




void create()
{
      ::create();
  	set_name("giant anaconda");
  	set_id(({"anaconda","giant anaconda","snake","giant snake","animal"}));
  	set_short("%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^ia%^BOLD%^nt %^RESET%^"
        +"%^GREEN%^an%^ORANGE%^a%^GREEN%^c%^BOLD%^o%^RESET%^%^GREEN%^n%^ORANGE%^d"
        +"%^GREEN%^a");
  	set_long("%^GREEN%^This enormous %^BOLD%^snake%^RESET%^ must be close to"
       +" forty feet in length, with girth nearly as thick as a man's waist. It"
       +" is coloured in %^BOLD%^m%^RESET%^%^GREEN%^o%^BOLD%^tt%^RESET%^%^GREEN%^"
       +"le%^BOLD%^d%^RESET%^%^GREEN%^ shades of green, with occasional patches"
       +" of %^ORANGE%^brown%^GREEN%^, allowing it to slip through the %^BOLD%^"
       +"j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^%^GREEN%^"
       +" in silence and %^BOLD%^c%^RESET%^%^GREEN%^a%^BOLD%^m%^RESET%^%^GREEN%^ou"
       +"%^BOLD%^f%^RESET%^%^GREEN%^l%^ORANGE%^a%^GREEN%^ge - though it is scary to"
       +" think that something so large could ever go unnoticed. It has the body"
       +" shape and size of a constrictor, so it might be wise to avoid getting"
       +" caught in its coils. ");
    set_race("snale");
    set_body_type("snake");
    swallowing = 0;

	set_class("fighter");
	set_mlevel("fighter",55);
	level = 55;
	set_guild_level("fighter",55);
	set_max_level(49);
	set_property("swarm",1);
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "damage resistance",
    }));

    set_level(55);
    set_class("fighter");
    set_mlevel("fighter", 55);
    set_max_hp(5000);
    set_hp(query_max_hp());
    set_exp(7000);
    set_property("swarm", 1);
    set_overall_ac(-71);
    set_size(3);
    add_attack_bonus(71);
    set_stats("strength",30);
    set_stats("dexterity",12);
    set_stats("intelligence",6);
    set_stats("wisdom",8);
    set_stats("constitution",30);
    set_stats("charisma",14);
    set_attacks_num(2);
    set_damage(8, 18);
    set_base_damage_type("piercing");
    set_fake_limbs(({"bite"}));
    set_attack_limbs(({"teeth"}));
    set("aggressive", 30);
      set_new_exp(55, "normal");
  	set_overall_ac(-60);
      set_size(2);
      add_attack_bonus(70);
  	set_alignment(4);
      set_property("full attacks",1);
      set_funcs(({"seize", }));
      set_func_chance(25);
  	set_emotes(10,({
    	}),1);
  	set_emotes(10,({
        "The anaconda blinks slowly, its milky white inner membrane passing briefly over the surface of its eye",
        "The anaconda tastes the air with its tongue",
        "The anaconda winds around a low branch, dangling a loop of its body down toward the ground",
        "The snake slithers silently forward"

    	}),0);
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
      set_skill("perception", 70);
}
void init()
{
  ::init();
  add_action("struggle", "struggle");
  add_action("struggle", "wriggle");
  add_action("struggle", "escape");
  add_action("break_free", "break");
}

int break_free(string str)
{
  if ("str"[0..2] != "out" && str[0..3] != "free" && str[0..4] != "loose")
  {
    return 0;
  }
  return struggle(str);
}

void break_loose(object ob){
  if (ob != seizee) return;
  if (!objectp(ETO) || !objectp(ob) || !present(ob, ETO)) return;
  tell_object(ob, "You manage to break free of the %^BOLD%^%^GREEN%^c"
    +"%^RESET%^%^GREEN%^oi%^BOLD%^l%^RESET%^%^GREEN%^s%^RESET%^ of the"
    +" %^GREEN%^a%^ORANGE%^na%^ORANGE%^c%^GREEN%^o%^ORANGE%^nd%^GREEN%^a"
    +"%^RESET%^!");
  tell_room(ETO, ob->QCN + "%^RESET%^ manages to break free of the %^BOLD%^%^GREEN%^c"
    +"%^RESET%^%^GREEN%^oi%^BOLD%^l%^RESET%^%^GREEN%^s%^RESET%^ of the"
    +" %^GREEN%^a%^ORANGE%^na%^ORANGE%^c%^GREEN%^o%^ORANGE%^nd%^GREEN%^a"
    +"%^RESET%^!", ob);
  seizee = 0;
}

void die(){
  object room;
  room = find_object_or_load(JUNG_ROOM7 + "snake_room");
  if (objectp(room))
  {
    room->set_snake_dead(1);
  }
  if (!catch(find_object_or_load(JUNG_ROOM3 + "snake_room")->query_short()))
  {
    room = find_object_or_load(JUNG_ROOM9 + "snake_room");
    if (objectp(room))
    {
      room->set_snake_dead(1);
    }
  }
  force_me("say ouch");
  ::die();
}

int struggle(string str)
{
  int freedom_percent, last_struggle, new_freedom;
  if (TP!= seizee)
  {
    return notify_fail("You don't need to break free");
  }
  freedom_percent = TP->query_property("freedom percent");
  last_struggle = TP->query_property("last_struggle");
  if (last_struggle > time()-5){
    tell_object(TP, "You need a bit more time before you try again");
    return 1;
  }
  new_freedom = TP->query_stats("strength");
  new_freedom += TP->query_stats("dexterity");
  new_freedom += random(60);
  new_freedom -= 30;
  new_freedom = 2 * new_freedom / 5;
  if (freedom_percent>99)
  {
    break_loose(TP);
    return 1;
  }
  if (new_freedom<0)
  {
    tell_object(TP, "You try to wriggle free of the snake's coils, but your efforts only make the situation worse!");
    tell_room(ETO, TPQCN + "%^RESET%^ tries to wriggle free of the snake's coils, but " + TP->QP + " efforts only make the situation worse!");
  }
  switch(new_freedom){
  case 0:
    tell_object(TP, "You try to wriggle free of the snake's coils, but your efforts make no noticeable difference");
    tell_room(ETO, TPQCN + " %^RESET%^%^tries to wriggle free of the snake's coils, but " + TP->QP + " efforts make no noticeable difference");
    break;
  case 1..20:
    tell_object(TP, "You squirm around and manage to get a little more free from the snake's coils");
    tell_room(ETO, TPQCN + " %^RESET%^squirms around and manages to get a little more free from the snake's coils");
    break;
  case 21..40:
    tell_object(TP, "You struggle against the snake's coils and manage to improve your position noticeably");
    tell_room(ETO, TPQCN + " %^RESET%^struggles against the snake's coils and manage to improve " + TP->QP + " position noticeably");
    break;
  case 41..60:
    tell_object(TP, "With a great effort, you manage to dislodge some of the coils holding you fast.");
    tell_room(ETO, "With a great effort, " + TPQCN + " %^RESET%^manages to dislodge some of the coils holding " + TP->QO + " fast.");
    break;
  case 61..80:
    tell_object(TP, "With a mighty heave, you manage to dislodge most of the coils wrapped around you.");
    tell_room(ETO, "With a mighty heave, "+TPQCN +" %^RESET%^manages to dislodge most of the coils wrapped around " + TP->QO + ".");
    break;
  case 81..200:!
    tell_object(TP, "Combining strength, dexterity and skill, you almost manage to break completely free with a single maneuver!");
    tell_room(ETO, "Combining strength, dexterity and skill, "+TPQCN+" %^RESET%^almost manages to break completely free with a single maneuver!");
    break;
  }
  if(freedom_percent<0)
  {
    tell_object(TP, "You are completely encased in coils. Getting free from here seems very unlikely");
  }
  switch(freedom_percent){
  case 0..10:
    tell_object(TP, "You are completely encased in coils. Getting free from here seems very unlikely");
    break;
  case 11..40:
    tell_object(TP, "You are mostly encased in coils. You have a lot of work to do to get free!");
  case 41..60:
    tell_object(TP, "There are still a lot of coils holding onto you. You have some work to do to get free!");
    break;
  case 61..80:
    tell_object(TP, "There are still a few coils holding onto you.");
    break;
  case 81..100:
    tell_object(TP, "You are almost free!");
  }
  TP->set_property("freedom percent", freedom_percent);
  TP->set_property("last struggle", time());
  return 1;
}

void heart_beat(){
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
  if (objectp(seizee))
  {
    constrict(seizee);
  }
}

void report(string str)
{
  "/daemon/reporter_d"->report("lujke", "Snake report: " + str);
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


void breakout(object ob){
  if (!objectp(ob)) { return;}
  tell_object(ob, "You manage to break free of the preying mantis's grasp");
  tell_room(ETO, (string)ob->QCN + "%^RESET%^ manages to break free of the preying mantis's grasp!", ob);
  ob->set_paralyzed(0);
  seizee = 0;
}

void sleep(){
  if (objectp(ETO))
  {
    tell_room(ETO, "%^GREEN%^The snake slithers off to digest its meal");
    remove();
  }
}

void digest(object stomach){
  object * critters;
  int i, count, flag;
  if (!objectp(stomach))
  {
    return;
  }
  if (!objectp(stomach)) return;
  if (!present("lining", stomach)) return;
  critters = all_living(stomach);
  count = sizeof(critters);
  if (count<1) return;
  flag = 0;
  for (i = 0; i<count;i++)
  {
    if (critters[i]->query_true_invis()) continue;
    if (critters[i]->query_hp()>0)
    {
      if (critters[i]->query_unconscious() && critters[i]->fort_save(30)){

        tell_object(critters[i], "%^BOLD%^%^GREEN%^A terrible, searing %^RED%^pain%^GREEN%^ brings you back to your senses!");
        critters[i]->set_condition(0);
      }
      tell_object(critters[i], "The snake's digestive juices eat away at you!");
      cause_typed_damage(critters[i], "head", 75 + random(100), "acid");
      flag = 1;
    }
  }
  if (flag ==1)
  {
    call_out("digest", 3, stomach);
  }
}

void swallow3(object meal)
{
  object stomach, * weapons, ob;
  int i, count;
  if (!objectp(ETO) || !objectp(meal) || !present(meal, ETO))
  {
   swallowing = 0;
   return;
  }
  swallowing  = 1;
  set_attackers(({}));
  tell_object(meal, "%^BOLD%^%^GREEN%^The snake swallows you whole!");
  weapons = meal->query_wielded();
  count = sizeof(weapons);
  if (count>0)
  {
    tell_object(meal, "%^RED%^You lose your grip on your weapons as you go down!");
    for (i=0;i<count;i++)
    {
      ob = weapons[i];
      if(ob->query_property("enchantment") &&
         (int)ob->query_property("enchantment") < 0)
      {
        write("The curse on this item prevents you from unwielding it.");
        continue;
      }
      ob->__ActuallyUnwield();
    }
  }
  tell_room(ETO, "%^BOLD%^%^GREEN%^The snake swallows "+ meal->QCN
   + " %^BOLD%^%^GREEN%^whole!", meal);
  stomach = find_object_or_load(ROOMS + "snakestomach");
  for (i=2;i<5;i++)
  {
    if (objectp(stomach->query_snake()) && stomach->query_snake()!=TO)
    {
      stomach = find_object_or_load(ROOMS + "snakestomach" + i);
    } else {
      break;
    }
  }
  stomach->set_snake(TO);
  stomach->reset();
  meal->move(stomach);
  seizee = 0;
  call_out("digest", 3, stomach);
  return;
}

void swallow2(object meal)
{
  if (!objectp(ETO) || !objectp(meal) || !present(meal, ETO))
  {
    swallowing = 0;
    return;
  }
  swallowing = 1;
  set_attackers(({}));
  tell_object(meal, "%^BOLD%^%^GREEN%^The snake fits its mouth"
    +" over your head and begins to swallow");
  tell_room(ETO, "%^BOLD%^%^GREEN%^The snake fits its mouth over"
    + meal->QCN + "%^BOLD%^%^GREEN%^'s head and begins to swallow.", meal);
  call_out("swallow3", 2, meal);
  return;
}

void swallow(object meal){
  report("Trying to swallow");
  if (!objectp(ETO) || !objectp(meal) || !present(meal, ETO))
  {
    return;
  }
  swallowing = 1;
  set_attackers(({}));
  tell_object(meal, "%^BOLD%^%^GREEN%^The snake stretches its mouth"
    +" open, dislocating its jaw as it begins an attempt to swallow"
    +" %^RESET%^you %^BOLD%^%^GREEN%^whole!");
  tell_room(ETO, "%^BOLD%^%^GREEN%^The snake stretches its mouth open,"
    +" dislocating its jaw as it begins an attempt to swallow %^RESET%^"
    + meal->QCN + " %^BOLD%^%^GREEN%^whole!", meal);
  call_out("swallow2", 2, meal);
  return;
}

void constrict(){
  object * foes;
  int constriction;
  if (!objectp(ETO)) return;
  if (!objectp(seizee)||!present(seizee, ETO))
  {
    seizee = 0;
    return;
  }
  seizee->set_paralyzed(40, "You are trapped within the %^GREEN%^co%^BOLD%^i"
    +"%^RESET%^%^ORANGE%^l%^GREEN%^s%^RESET%^ of a giant"
    +" %^GREEN%^an%^ORANGE%^a%^GREEN%^c%^ORANGE%^o%^GREEN%^nd%^ORANGE%^a%^RESET%^!");
  report ("Constricting " + seizee->query_name());
  foes = query_attackers();
  if (sizeof(foes)>0 && member_array(seizee, foes)!=-1)
  {  //It won't continue biting something that it's busy constricting. It will wait for them to go unconscious then swallow them whole. Muahahaha
    foes -=({seizee});
    set_attackers(foes);
  }
  if (seizee->query_unconscious())
  {
    report ("Subject already unconscious. Time to swallow");
    swallow(seizee);
    return;
  }
  report("seizee constriction: " + seizee->query_property("constriction"));
  report("seizee condition: " + seizee->query_condition());
  constriction = seizee->query_property("constriction") + ((3000 - seizee->query_condition()));
  switch(constriction)
  {
  case 0..1500:
    tell_object(seizee, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around you");
    tell_room(ETO, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around " + seizee->QCN, seizee);
     break;
  case 1501..2500:
    tell_object(seizee, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around you with each breath. It's getting hard to breathe in.");
     break;
    tell_room(ETO, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around " + seizee->QCN + "%^RESET%^. " + capitalize(seizee->QS) + "'s face is starting to go a shade of %^BOLD%^%^MAGENTA%^puce", seizee);
  case 2501..3500:
    tell_object(seizee, "As the coils tighten further, your bones are beginning to creak, and breathing is impossible.");
    tell_room(ETO, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around " + seizee->QCN + "%^RESET%^. " + capitalize(seizee->QS) + " is turning %^BOLD%^%^BLUE%^blue", seizee);
     break;
  case 3501..4300:
    tell_object(seizee, "%^BOLD%^RED%^Your vision is beginning to %^RESET%^go grey%^BOLD%^%^RED%^. You may pass out any moment");
    tell_room(ETO, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around " + seizee->QCN + "%^RESET%^. " + capitalize(seizee->QS) + " is completely %^BOLD%^%^WHITE%^pale and %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^%^BLACK%^y", seizee);

     break;
  case 4301..20000:
    tell_object(seizee, "%^BOLD%^%^BLUE%^You %^RESET%^pass out%^BOLD%^%^BLUE%^ from lack of %^CYAN%^a%^WHITE%^i%^CYAN%^r%^BLUE%^.");
    tell_room(ETO, "The %^GREEN%^an%^BOLD%^a%^RESET%^%^GREEN%^c%^ORANGE%^o%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^a's coils%^RESET%^ tighten around " + seizee->QCN + "%^RESET%^. " + capitalize(seizee->QS) + " is unconscious, possibly dead.", seizee);
    seizee->set_condition(seizee->query_used_stamina()+seizee->query_condition() + 40);
    break;
  }
  seizee->set_property("constriction", seizee->query_property("constriction") + 125);
  seizee->set_condition(seizee->query_used_stamina() + 125);
  report("new constriction: " + seizee->query_property("constriction"));
  report("new condition: " + seizee->query_condition());
}

void seize(object targ){
  object room;
  room = ETO;
  if (seizee !=0){return;}
  if (!objectp(targ)||!objectp(room)) { return; }
  //add in a saving throw
  if (targ->reflex_save(50))
  {
    tell_object(targ, "You %^BOLD%^%^GREEN%^dodge%^RESET%^ aside as the"
      +" %^GREEN%^snake%^RESET%^ attempts to catch you in one of its"
      +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^o%^ORANGE%^i%^BOLD%^"
      +"%^GREEN%^l%^RESET%^%^GREEN%^s!");
    tell_room(ETO, targ->QCN + " %^BOLD%^%^GREEN%^dodges%^RESET%^ aside as the"
      +" %^GREEN%^snake%^RESET%^ attempts to catch you in one of its"
      +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^o%^ORANGE%^i%^BOLD%^"
      +"%^GREEN%^l%^RESET%^%^GREEN%^s!", targ);
    return;
  }

  tell_object(targ, TO->QCN + "%^BOLD%^%^GREEN%^ loops one of its"
    +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^oi%^BOLD%^l%^RESET%^%^GREEN%^s"
    +"%^RESET%^ around you, trapping you tight!");
  tell_room(room, TO->QCN + "%^BOLD%^%^GREEN%^ loops one if its"
    +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^oi%^BOLD%^l%^RESET%^%^GREEN%^s"
    +" %^RESET%^around " + targ->QCN +"%^RESET%^, trapping "
    + targ->QO + " tight!", targ);
  targ->set_paralyzed(40, "You are trapped within the %^GREEN%^co%^BOLD%^i"
    +"%^RESET%^%^ORANGE%^l%^GREEN%^s%^RESET%^ of a giant"
    +" %^GREEN%^an%^ORANGE%^a%^GREEN%^c%^ORANGE%^o%^GREEN%^nd%^ORANGE%^"
    +"a%^RESET%^!");
  seizee = targ;
  call_out("constrict", 2, 3 + random(3));
}
