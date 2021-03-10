//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;


nosave int BEAT, heartcount;
int summoned;
void breakout(object ob);


void create()
{
      ::create();
  	set_name("dire warthog alpha");
  	set_id(({"warthog","dire warthog","boar","giant boar", "alpha", "alpha warthog", "dire warthog alpha", "warthog alpha","animal"}));
  	set_short("%^ORANGE%^Alpha %^BOLD%^%^BLACK%^Dire %^RESET%^%^ORANGE%^warthog");
  	set_long("This huge, fearsome omnivore is the leader of its group, or sounder. It is about 18 feet in length and 12 feet high at the shoulder, and keeps watch over the lesser members of the sounder. Its physical size and greater aggression set it apart and make it even more dangerous. Dangerous hooves and powerful tusks are equally useful for digging up deep tubers or ripping apart adversaries, and its hide is thick enough to keep it safe from most attacks.");
    set_race("warthog");
    set_body_type("quadruped");

      set_property("not random monster", 1);
	set_class("barbarian");
	set_mlevel("barbarian",56);
	level = 56;
	set_guild_level("barbarian",56);
	set_max_level(50);
	set_property("swarm",1);
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",

      }));
      set_hp(query_max_hp());
      set_property("swarm", 1);
      set_overall_ac(-68);
      set_size(3);
      add_attack_bonus(69);
    set_stats("strength",30);
    set_stats("dexterity",16);
    set_stats("intelligence",4);
    set_stats("wisdom",12);
    set_stats("constitution",30);
    set_stats("charisma",5);
    set_attacks_num(5);
    set_damage(5,10);
    set_base_damage_type("piercing");
    set_attack_limbs(({"tusks", "left hoof", "right hoof", "teeth"}));
    set("aggressive", 6);
      set_new_exp(level, "normal");
      set_size(3);
      add_attack_bonus(71);
  	set_alignment(4);
      set_property("full attacks",1);
      set_funcs(({"barge", "rush", "toss" }));
      set_func_chance(75);
  	set_emotes(10,({

            "%^ORANGE%^The warthog %^RESET%^snuffles %^ORANGE%^around in the"
           +" %^GREEN%^undergrowth%^RESET%^",

            "%^ORANGE%^The warthog scents the air and glares around with its"
           +" %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d %^MAGENTA%^piggy"
           +" %^RED%^e%^RESET%^%^RED%^ye%^BOLD%^s%^RESET%^%^ORANGE%^.",

            "%^ORANGE%^The warthog digs frantically at the ground for a few"
           +" moments, creating quite a deep crater and coming up with a prize"
           +"%^RESET%^ tuber",

            "%^ORANGE%^The warthog scratches its back against the rough bark of a"
           +"%^BOLD%^%^GREEN%^ young tree%^RESET%^%^ORANGE%^, making the whole"
           +" thing shudder",
    	}),0);
  	set_emotes(10,({
            "%^ORANGE%^%^The warthog snorts angrily and paws aggressively at the"
          +" ground",
            "%^ORANGE%^The warthog %^RED%^gl%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^e"
           +"%^RESET%^%^RED%^s%^ORANGE%^ at its tormentors and shakes its"
           +" %^BOLD%^%^WHITE%^t%^RESET%^u%^BOLD%^%^WHITE%^sks"
           +" %^RESET%^%^ORANGE%^dangerously",
            "%^ORANGE%^The warthog lets out a sound that goes from a"
           +" %^BOLD%^%^BLACK%^deep rumbling growl%^RESET%^%^ORANGE%^ to an"
           +" earsplitting %^BOLD%^%^MAGENTA%^angry squeal"
    	}),1);
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
      set_skill("perception", 75);
      summoned = 0;
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

barge2(object ob){
  int myscore, targscore;
  if (!objectp(ETO)) return;
  if (!objectp(ob)|| !present(ob, ETO))
  {
    tell_room(ETO, "%^ORANGE%^The warthog %^RED%^charges%^ORANGE%^ into%^RESET%^"
      +" thin air%^ORANGE%^, then looks surprised as its target seems to have"
      +" disappeared");
    remove_property("using instant feat");
    return;
  }
  if (ob->reflex_save(55))
  {
    tell_object(ob, "You skip to one side as the %^ORANGE%^warthog%^RESET%^ charges"
      +" past you. Phew!");
    tell_room(ETO, ob->QCN + " skips to one side as the %^ORANGE%^warthog%^RESET%^"
      +" charges past", ob);
    remove_property("using instant feat");
    return;
  }
  tell_object(ob, "The %^ORANGE%^warthog%^RESET%^ slams into you, shoulder first!");
  tell_room(ETO, "The %^ORANGE%^warthog%^RESET%^ slams into " + ob->QCN + "%^RESET%^,"
    +" shoulder first!", ob);
  targscore = (ob->query_size()* 10) + ob->query_stats("strength");
  targscore = targscore + random(targscore);
  myscore = 65 + random(65);
  //Do damage
  ob->do_damage(175+random(125));
  if (targscore>myscore)
  {
    //resist knockback
    tell_object(ob, "%^BOLD%^%^BLUE%^You manage to stand firm, despite the"
      +" %^CYAN%^force %^BLUE%^of the impact!");
    tell_room(ETO, ob->QCN + "%^BOLD%^%^BLUE%^ manages to stand firm, despite the"
      +" %^CYAN%^force %^BLUE%^of the impact!", ob);
  } else
  {
    //do knockback
    tell_object(ob, "%^BOLD%^%^YELLOW%^You go flying and land, winded, flat on your"
      +" back!");
    tell_room(ETO, ob->QCN + "%^BOLD%^%^YELLOW%^ goes flying and lands, winded,"
      +" flat on "+ ob->QP + " back!", ob);
    ob->set_paralyzed(30 + random(20), "%^BOLD%^%^YELLOW%^You are winded from the%^RESET%^"
      +" %^ORANGE%^warthog's %^BOLD%^%^YELLOW%^shoulder barge!");
  }
  remove_property("using instant feat");
}

void squeal3(object where, object * hogs) //This time it's porksonal
{
  string * exits, roomname;
  object hogroom;
  int i, j, count, count2;
  if (!objectp(ETO)||!objectp(where) || where != ETO)
  {
    if (objectp(where))
    {
      tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ seem to go unanswered");
      summoned = 0;
    }
    return;
  }
  count = sizeof(hogs);
  if (sizeof(hogs)<1)
  {
    tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ seem to go unanswered");
    summoned = 0;
    return;
  }
  for (i=0;i<count;i++){
    hogroom = environment(hogs[i]);
    if (!objectp(hogroom))
    {
      continue;
    }
    exits = hogroom->query_exits();
    count2 = sizeof(exits);
    if (count2<1)
    {
      continue;
    }
    for (j=0;i<count2;j++)
    {
      if (hogroom->query_exit(exits[i]) == base_name(ETO))
      {
        hogs[i]->force_me(exits[i]);
        continue;
      }
    }
  }
}

void squeal2(object where) //the squeakuel
{
  object room, * hogs, hog;
  int i, count;
  string * exits, exit, roomname;
  if (!objectp(ETO)||!objectp(where) || where != ETO)
  {
    if (objectp(where))
    {
      tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ seem to go unanswered");
      summoned = 0;
    }
    return;
  }
  exits = ETO->query_exits();
  if (sizeof(exits)<1){
    return;
  }
  exit = exits[random(sizeof(exits))];
  roomname = ETO->query_exit(exit);
  if (!file_exists(roomname))
  {
    tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ seem to go unanswered");
    summoned = 0;
    return;
  }
  room = find_object_or_load(roomname);
  if (!objectp(room))
  {
    tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ seem to go unanswered");
    summoned = 0;
    return;
  }
  hogs = ({});
  count = sizeof(query_attackers()) + 1;
  for (i=0;i<count;i++)
  {
    tell_room(room, query_short() + "%^RESET%^ snuffles %^ORANGE%^its way out of"
      +" the %^GREEN%^undergrowth");
    hog = new(MOB+ "dire_warthog");
    hogs += ({hog});
    hog->set_summoned(1);
    hog->move(room);
  }
  hog = new(MOB + "greater_dire_warthog");
  hogs += ({hog});
  hog->set_summoned(1);
  hog->move(room);
  call_out("squeal3",2, where, hogs);
}

void squeal()
{
  if (!objectp(ETO)|| summoned>0) return;
  tell_room(ETO, "The %^ORANGE%^warthog %^BOLD%^%^MAGENTA%^squeals%^RESET%^ loudly,"
    +" following it up with a series of %^BOLD%^%^YELLOW%^tr%^RESET%^%^ORANGE%^u"
    +"%^BOLD%^mp%^RESET%^%^ORANGE%^e%^BOLD%^t-l%^RESET%^%^ORANGE%^i%^BOLD%^ke"
    +" %^RESET%^squeaks");
  call_out("squeal2", 1), ETO;
  summoned = 1;
}

void set_summoned(int s){
  summoned = s;
}

int query_summoned(){
  return summoned;
}

void barge(){
  object * critters, critter;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  critter = critters[random(sizeof(critters))];
  who = critter->query_name();
  tell_object(critter, "%^ORANGE%^The warthog snorts and fixes its"
    +" %^BOLD%^%^RED%^e%^BOLD%^%^RED%^ye%^RESET%^%^RED%^s %^RESET%^%^ORANGE%^on you"
    +" before charging %^BOLD%^%^MAGENTA%^madly %^RESET%^%^ORANGE%^in your"
    +" direction.");
  tell_room(ETO, "%^ORANGE%^The warthog snorts and fixes its"
    +" %^BOLD%^%^RED%^e%^BOLD%^%^RED%^ye%^RESET%^%^RED%^s %^RESET%^%^ORANGE%^on "
    + critter->QCN
    +" before charging %^BOLD%^%^MAGENTA%^madly %^RESET%^%^ORANGE%^in "
    + critter->QP
    +" direction.", critter);
  set_property("using instant feat",1);
  call_out("barge2", 2, critter);
}

void rush(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof (critters))]->query_name();
  force_me("rush " + who);
}


void toss(){
  string * exits, exit, roomname;
  object * critters, critter, room;
  critters = query_attackers();
  if (sizeof(critters)<1 || !objectp(ETO)) return;
  critter = critters[random(sizeof(critters))];
  if (critter->reflex_save(55))
  {
    tell_object(critter, "You dodge out of the way as the %^ORANGE%^Alpha warthog"
      +" %^MAGENTA%^dips%^RESET%^ its head and tries to flip you with its snout!");
    tell_room(ETO, critter->QCN + "%^RESET%^ dodges out of the way as the"
      +" %^ORANGE%^Alpha warthog %^MAGENTA%^dips%^RESET%^ its head and tries to"
      +" flip " + critter->QO + " with its snout!", critter);
     return;
  }
  tell_object(critter, "%^ORANGE%^The %^ORANGE%^alpha warthog%^RESET%^ suddenly"
    +" %^MAGENTA%^dips%^RESET%^ its head and uses its snout to"
    +" %^BOLD%^%^CYAN%^flip%^RESET%^ you through the %^BOLD%^%^CYAN%^a%^WHITE%^i"
    +"%^CYAN%^r%^RESET%^!");
  tell_room(ETO, "%^ORANGE%^The %^ORANGE%^alpha warthog%^RESET%^ suddenly"
    +" %^MAGENTA%^dips%^RESET%^ its head and uses its snout to"
    +" %^BOLD%^%^CYAN%^flip%^RESET%^ " + critter->QCN + "%^RESET%^ through the"
    +" %^BOLD%^%^CYAN%^a%^WHITE%^i%^CYAN%^r%^RESET%^!", critter);
  exits = ETO->query_exits();
  if (sizeof(exits)<1)
  {
    tell_object(critter, "%^BOLD%^%^RED%^You crash into the ground!");
    tell_room(ETO, critter->QCN + " %^BOLD%^%^RED%^crashes into the ground");
    critter->do_damage(225+random(155));
    return;
  }
  exit = exits[random(sizeof(exits))];
  roomname = ETO->query_exit(exit);
  if (!file_exits(roomname))
  {
    tell_object(critter, "%^BOLD%^%^RED%^You crash into the ground!");
    tell_room(ETO, critter->QCN + " %^BOLD%^%^RED%^crashes into the ground");
    critter->do_damage(225+random(155));
    return;
  }
  room = find_object_or_load(roomname);
  if (!objectp(room))
  {
    tell_object(critter, "%^BOLD%^%^RED%^You crash into the ground!");
    critter->do_damage(225+random(155));
    tell_room(ETO, critter->QCN + " %^BOLD%^%^RED%^crashes into the ground");
    return;
  }
  critter->move(room);
  tell_room(ETO, critter->QCN + " %^BOLD%^%^CYAN%^sails%^RESET%^ out of the room!");
  tell_room(room, critter->QCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the next"
    +" room!", critter);
  tell_object(critter, "You land with a %^BOLD%^%^RED%^CRASH%^RESET%^ in the next"
    +" room!");
  critter->do_damage(225+random(155));
  critter->force_me("look");
}
