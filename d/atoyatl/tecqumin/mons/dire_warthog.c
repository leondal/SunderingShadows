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
      set_property("not random monster", 1);
        set_name("dire warthog");
        set_id(({"warthog","dire warthog","boar","giant boar"}));
        set_short("%^BOLD%^%^BLACK%^Dire %^RESET%^%^ORANGE%^warthog");
        set_long("A fearsome omnivore with a preference for meat, the dire Warthog is about 12 feet in length and 7 feet high at the shoulder, with
an intimidatingly muscular body. Its keen eyesight and wicked tusks and teeth help it hunt all but the most dangerous prey. Its sharp edged tusks and
powerful forelegs are equally useful for digging up deep tubers or trampling adversaries, and its hide is thick enough to keep it safe from most
attacks.");
    set_race("warthog");
    set_body_type("quadruped");


        set_class("barbarian");
        set_mlevel("barbarian",46);
        level = 46;
        set_guild_level("barbarian",46);
        set_max_level(47);
        set_property("swarm",1);
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
      }));
      set_hp(query_max_hp());
      set_property("swarm", 1);
      set_overall_ac(-65);
      set_size(3);
      add_attack_bonus(65);
    set_stats("strength",28);
    set_stats("dexterity",16);
    set_stats("intelligence",4);
    set_stats("wisdom",12);
    set_stats("constitution",30);
    set_stats("charisma",5);
    set_attacks_num(5);
    set_damage(3,9);
    set_property("swarm", 1);
    set_base_damage_type("piercing");
    set_attack_limbs(({"tusks", "left hoof", "right hoof", "teeth"}));
    set("aggressive", 6);
      set_new_exp(38, "normal");
      set_size(3);
      add_attack_bonus(64);
        set_alignment(4);
      set_property("full attacks",1);
      set_funcs(({"barge", "rush", "squeal" , "squeal", "squeal", "squeal", "squeal"}));
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
      set_skill("perception", 70);
      summoned = 0;
      set_new_exp(46, "normal");
}
void init()
{
  ::init();
}

void heart_beat(){
  ::heart_beat();
  
  if(!objectp(this_object()) || !environment(this_object()))
      return;
  
  if(present("player", ETO)){
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
  if (ob->reflex_save(50))
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
  myscore = 58 + random(58);
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

void report(string str){
  "/daemon/reporter_d.c"->report("lujke", "Pig report: " + str);
}

void squeal3(object where, object * hogs) //This time it's porksonal
{
  string * exits, roomname;
  object hogroom;
  int i, j, count, count2;
  report ("third squeal");
  if (!objectp(ETO)||!objectp(where) || where != ETO)
  {
    report ("There's a problem with the rooms, cap'n");
    if (objectp(where))
    {
      tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ calls seem to go unanswered");
      summoned = 0;
    }
    return;
  }
  count = sizeof(hogs);
  if (count<1)
  {
    report ("we ain't got no hogs, cap'n");
    tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ calls seem to go unanswered");
    summoned = 0;
    return;
  }
  report("Trying to move the hogs");
  for (i=0;i<count;i++){
    hogroom = environment(hogs[i]);
    if (!objectp(hogroom))
    {
      report ("This hog ain't in no valid room!");
      continue;
    }
    exits = hogroom->query_exits();
    count2 = sizeof(exits);
    if (count2<1)
    {
      report ("This hogroom ain't danged well got no dang exits!");
      continue;
    }
    for (j=0;j<count2;j++)
    {
      if (hogroom->query_exit(exits[j]) == base_name(ETO))
      {
        report ("Taking a hog to the " + exits[j]);
        hogs[i]->force_me(exits[j]);
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
    report ("There's a problem with the rooms, cap'n");
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
  if (!file_exists(roomname + ".c"))
  {
    report ("The file "+ roomname+ " does not exist, cap'n");
    tell_room(where, "The %^ORANGE%^warthog's%^RESET%^ seem to go unanswered");
    summoned = 0;
    return;
  }
  room = find_object_or_load(roomname);
  if (!objectp(room))
  {
    report ("There's an error loading the room "+ roomname+ " cap'n");
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
  report ("normal hogs summoned: " + count);
  if ((count == 1 && !random(15)) || (count ==2 && !random(10)) ||( count ==32 && !random(5)) ||(count>3 && !random(2)) )
  {
    hog = new(MOB + "greater_dire_warthog");
    if (objectp(hog))
    {
      hogs += ({hog});
      hog->set_summoned(1);
      hog->move(room);
    }
  }
  call_out("squeal3",2, where, hogs);
}

void squeal()
{
  object *hogs, hog;
  if (!objectp(ETO)|| summoned>0) return;
  hogs = all_present("warthog", ETO);
  tell_room(ETO, "The %^ORANGE%^warthog %^BOLD%^%^MAGENTA%^squeals%^RESET%^ loudly,"
    +" following it up with a series of %^BOLD%^%^YELLOW%^tr%^RESET%^%^ORANGE%^u"
    +"%^BOLD%^mp%^RESET%^%^ORANGE%^e%^BOLD%^t-l%^RESET%^%^ORANGE%^i%^BOLD%^ke"
    +" %^RESET%^squeaks");
  call_out("squeal2", 1, ETO);
  foreach(hog in hogs){
    if (random(3)>0) hog->set_summoned(1);
  }
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
  who = critters[random(sizeof(critters))]->query_name();
  force_me("rush " + who);
}
