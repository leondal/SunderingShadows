//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

nosave int BEAT, heartcount;

void create()
{
    ::create();
    set_name("ram");
    set_id( ({"ram","battering ram", "xxramxx"}) );
    set_short("%^BOLD%^%^BLACK%^battering ram%^RESET%^");
    set_weight(400);
    set_no_clean(1);
    set_long("%^RESET%^" 
            +"This is a covered %^BOLD%^%^BLACK%^battering ram%^RESET%^. The ram itself is a huge"
            +" chunk of %^ORANGE%^hardwood t%^GREEN%^re%^ORANGE%^etr%^BOLD%^%^GREEN%^u"
            +"%^RESET%^%^GREEN%^n%^ORANGE%^k%^RESET%^. It sits inside a %^ORANGE%^wheeled"
            +" frame%^RESET%^, which has a sloping roof in the shape of an inverted V. The"
            +" %^ORANGE%^ram%^RESET%^ is suspended from the top of the frame by strong ropes with"
            +" enough play in them to allow the ram to swing back and forth. The %^BOLD%^%^BLACK%^roof"
            +" %^RESET%^is covered with thick, %^BOLD%^%^BLACK%^water soaked leather hides%^RESET%^"
            +" designed to offer protection to the operating crew who push the whole thing along the"
            +" ground until it is in place at its intended target. Once there, they swing the"
            +" %^ORANGE%^ram%^RESET%^ into whatever it is they want to %^BOLD%^%^BLUE%^batter%^RESET%^"
            +" down.");
        set_race("ram");
      set_gender("neuter");
      set_body_type("snake");
      add_limb("frame", "frame", 0,0,0);
      add_limb("cover", "frame", 0,0,0);
      add_limb("ram head", "frame",0,0,0);
      add_limb("wheel", "frame",0,0,0);
      add_limb("wheel", "frame",0,0,0);
      remove_limb("tail");
      remove_limb("head");
      remove_limb("torso");
      remove_limb("mouth");
        set_overall_ac(0);
      set_max_hp(30000);
      set_hp(30000);
      set_num_attacks(0);
      set_no_clean(1);
      set_property("no random treasure", 1);
      set_new_exp(49, "normal");
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}

void init(){
  object interior;
  ::init();
  add_action("enter", "enter");
  interior = find_object_or_load(TABAXOBJ + "ram_interior");
  interior->set_ram(TO);
  interior->add_exit( interior->out_fun() , "out");
  set_no_clean(1);
}

int clean_up(){return 1;}

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
//  report("Ram_mob: My heart is beating");
}

void report(string str){
  "/daemon/reporter_d.c"->report("lujke", str);
}

void execute_attack(){
  return;
}

string * query_walk_path(){
  return path;
}

int force_me(string str){
  string * exits, command;
  object interior, * who;
  if (objectp(ETO)){
    exits = ETO->query_exits();
    if (member_array(str, exits)!=-1){
      interior = find_object_or_load(TABAXOBJ + "ram_interior");
      if (objectp(interior)){
        who = all_living(interior);
        if (sizeof(who)>0){
          command = "roll " + str;
          who[0]->force_me(command);
          return 1;
        }
      }
    }
  } else {
    ::force_me("tell lujke There is an error in the ram's environment. Dunno what the"
            +" heck is up");
  }
  return ::force_me(str);
}

int enter(string str){
  object interior, * critters;
  int i, critts;
  if (!id(str)){
    tell_object(TP, "You can type %^BOLD%^%^BLUE%^'enter ram'%^RESET%^ to get into the"
                   +" %^BOLD%^%^BLACK%^battering ram%^RESET%^");
    return 0;
  }
  interior = find_object_or_load(TABAXOBJ + "ram_interior");
  if (!objectp(interior)){
    tell_object(TP, "There seems to be a problem with the ram interior. Please tell a Wiz. Preferably"
                   +" that silly fool %^BOLD%^%^GREEN%^Lujke%^RESET%^, who's doubtless broken it."
                   +" Failing that, make a bug report on the ram.");
    return 1;
  }
  critters = all_living(interior);
  if (sizeof(critters)>0){
    critts = 0;
    for (i=0;i<sizeof(critters);i++){
      if (!critters[i]->query_true_invis() && !TP->id("xxsquadxx")){
        critts ++;
      }
    }
  }
  if (critts>3 && !TP->query_true_invis() && !TP->id("xxsquadxx")){
    tell_object(TP, "There doesn't appear to be enough room for you under the ram's cover");
    return 1;
  }
  tell_object(TP, "You duck under the cover of the %^BOLD%^%^BLACK%^battering ram%^RESET%^");
  if (!TP->query_true_invis()){
    tell_room(ETP, TPQCN + " %^RESET%^ ducks under the cover of the %^BOLD%^%^BLACK%^battering ram", TP);
    tell_room(interior, TPQCN + " enters");
  }
  TP->move(interior);
  TP->force_me("look");
  return 1;
}

int reach_destination(){
  object room, interior, * orogs, * critters, crit;
  string where;
  int i;
  room = ETO;
  orogs = ({});
  if (objectp(room)){
    where = file_name(room);
    if (where == TABAXROOM + "main_field"){
      force_me("tell lujke Ram has reached the main field. Checking whether any orogs are present");
      interior = find_object_or_load(TABAXOBJ + "ram_interior");
      if (objectp(interior)){
        critters = all_living(interior);
      }
      if (sizeof(critters)>0){
        for (i=0;i<sizeof(critters);i++){
          crit = critters[i];
          if ((string)crit->query_race() == "orog"){
            orogs += ({crit});
          }
        }
      }
    }
  }
  if (sizeof(orogs)>0){
    force_me("tell lujke Orogs present: attempting to batter the gate");
    orogs[0]->force_me("batter gate");
  } else {
    force_me("tell lujke No orogs present in ram");
  }
}
