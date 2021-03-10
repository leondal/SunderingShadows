#include <std.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit ROOM;


#define DIGMESSAGE ({" It's a bit of %^ORANGE%^dull%^RESET%^ job",\
 " %^MAGENTA%^You're getting good at it now",\
 " If you know any tunes, you could %^BOLD%^%^CYAN%^whistle%^RESET%^ while you work to keep your"\
   +" spirits up",\
 " If you're happy and you know it, clap your hands", " Gee this is boring",\
 " You'd think an adventurer would have more exciting things to occupy their time",\
 " I hope those villagers are going to appreciate all this effort", " Can you dig it? Yes, you can.",\
 " Ever considered a career in arable farming?", " Would this be a good time for a break?",\
 " You marvel that people get paid a pittance for doing stuff like this.",\
 " You wonder whether your parents would be proud of your acheivements right now.",\
 " Where's a %^BOLD%^%^CYAN%^+5 spade of digginess%^RESET%^ when you need one?",\
 " You wonder how long this is going to take",\
 " You seem to be making good progress", " Ugh. You're getting all %^ORANGE%^muddy%^RESET%^",\
 " Is this what you always wanted to do when you grew up?",\
 " You wonder how come there's a village full of peasants, but you're the one doing the digging",\
 " How long has this been going on?", " Think you could hurry it up a bit?",\
 " You %^BOLD%^%^RED%^die%^RESET%^ of backache.\n Just kidding",\
 " You're definitely going to need a bath after this.", " You're getting all %^GREEN%^sweaty",\
 " With a work ethic like this, you could have had a successful career in manual labour",\
 " Perhaps you feel a sense of camaraderie towards anyone who is digging with you - and a contempt of"\
   +" anyone too lazy to join in", " Why do these things always take so long?",\
 " Don't stop until you've finished the HOLE job.\n Geddit? The HOLE job! Hehehe",\
 " Is it possible to acheive enlightenment by carrying out so mundane a task?",\
 " Wouldn't you rather be %^BOLD%^RED%^killing %^RESET%^something?",\
 " A tip for life: When you reach rock bottom, stop digging",\
 " You feel that after this you will be entitled to call a spade a spade.",\
 " It's hard work, but where there's a will there's a way", " Never say die", \
 " You remember that winners never quit and quitters never win. Then again, winners usually get"\
   +" someone else to do the digging",\
 " No one's even come and offered you a drink, or a ploughman's lunch or anything",\
 " So this is what it's like to be a peasant.", " A bit of honest labour won't do you any harm",\
 " Do you know the difference between a spade and a shovel?", " I've run out of things to say to"\
   +" liven it up for you. Sorry.",\
 " The fresh air's probably good for you. You should get out more.", " Bored yet?",\
 " Here's five minutes of your life you'll never get back", " Come on, put your back into it!" })
#define CLEAR 0
#define PITS 1
#define COVERED_PITS 2
#define STAKED_PITS 3
#define COVERED_STAKED_PITS 4

int pitted, staked, pit_prog, stake_prog, bury_prog, cover_prog, last_cleaned, uncover_prog;
mapping positions, climb_positions;
object battlement;

void pitfall(object ob);
void set_battlement(object bat);
object query_battlement();
int query_pitted();
int query_staked();
void set_pitted(int pit);
void set_staked(int stake);
string pit_desc();
string stake_desc();
string how_high(int pos);
void reach_top(object ob);
void fall_off(object ob);
void set_position(object ob, int pos);
void reset_battlement(); // virtual func, defined in the files that inherit this one

void create(){
  string where;
  ::create();
  climb_positions = ([]);
  positions = ([]);
  pitted = 0;
  staked = 0;
  pit_prog = 0;
  stake_prog = 0;
  bury_prog = 0;
  cover_prog = 0;
  uncover_prog = 0;
  last_cleaned = hour(time());
  where=file_name(TO);
  DESTINATIONS_D->generate_waystations(where,3, 4);
  set_listen("default", "The sounds of the jungle behind you drift to your ears");
  set_smell("default", "You can smell the gentle aromas of maize and tilled earth");

}

void init(){
  ::init();
  add_action("dig_pits", "dig");
  add_action("plant_stakes", "plant");
  add_action("bury_stakes", "bury");
  add_action("improve", "improve");
  add_action("approach_fence", "approach");
  add_action("climb_fence", "climb");
  add_action("cover_pits", "cover");
  add_action("fire", "fire");
  add_action("fire", "shoot");
  reset_battlement();
  set_had_players(3);
}

void reset_battlement(){ // virtual func, defined in the files that inherit this one
}

int on_entry(object ob, object origin){
  string * rooms, message, batt;
  object room;
  int i, num, lower, higher;
  if (!objectp(ob)){
    return 0;
  }
  set_position(ob, 0);
  rooms = ({TABAXROOM + "watchtower"});
  if (!objectp(battlement)){
    reset_battlement();
  }
  batt = file_name(battlement);  // add the appropriate battlements to the list of rooms 
  rooms += ({batt});             // that will be messaged when something enters the field
  sscanf(batt, "battlement%d", num);
  lower = num -1;
  if (lower<1) { lower = 8;}
  higher = num +1;
  if (higher>8){ higher = 1;}
  batt = "battlement" + lower;
  rooms += ({batt});
  batt = "battlement" + higher;
  rooms += ({batt});              // room list complete
  if ((int)ob->query_true_invis()==1 || (string)ob->query_race() == "no_race"){
    return 1;
  }
  for (i=0;i<sizeof(rooms);i++){
    room = find_object_or_load(rooms[i]);
    if (!objectp(room)){
      continue;
    }
    message = "You see a " + (string)ob->query_gender() + " "+ (string)ob->query_race() 
            + "%^RESET%^ entering " + TO->query_name() + " from " + (string)origin->query_name();
    tell_room(room, message);
  }
  return 1;
}

string batt_desc(){
  string desc;
  object * critters, * removals;
  int i;
  critters = ({});
  removals = ({});
  if (objectp(battlement)){
    critters = all_living(battlement);
    if (sizeof(critters)>0){
      for (i=0;i<sizeof(critters);i++){
        if (wizardp(critters[i]) || critters[i]->query_true_invis()){
          removals += ({critters[i]}) ;
        }
        if (critters[i]->query_invis() || critters[i]->query_hidden() ){
          if (!TP->detecting_invis()){
            removals += ({critters[i]});
          }
        }
      }
    }
    critters -= removals;
  }
  desc = "The battlements on top of the %^ORANGE%^stockade wall%^RESET%^ are designed to provide cover"
        +" to the defenders atop the wall. ";
  desc += " If you have a missile weapon, you can %^BOLD%^%^YELLOW%^<fire at battlement>%^RESET%^,"
         +" but your chance of hitting anything will be significantly reduced due to the protection of"
         +" the battlement." ;
  if (sizeof(critters)>0){
    desc += " You think you can see some movement on the battlement.";
  }
  return desc;
}

int clean_up() { 
  if (hour(time())< last_cleaned + 2){
    return 0; // Never clean up! 
  }
  last_cleaned = hour(time());
  return ::clean_up();
} 

int fire(string str){
  string roomname, crittername, * names, lr_prof;
  object * critters, *removals, critter, batt_mob,* weapons, wpn;
  int i;
  reset_battlement();
  if (!str || str != "at battlement"){
    notify_fail("Try %^BOLD%^%^YELLOW%^<fire at battlement>%^RESET%^");
    return 0;
  }
  if (!objectp(battlement)){
    tell_object(TP, "Error with the battlement you are firing at. Please tell a wiz, preferably that"
                  +" fat lizard %^B_GREEN%^%^BOLD%^%^GREEN%^Lujke%^RESET%^. Or make a"
                  +" %^BOLD%^%^GREEN%^bug%^RESET%^ report, or something.");
    return 1;
  }
  weapons = TP->query_wielded();
  if (sizeof(weapons)<1){
    notify_fail("You will need to be wielding a ranged weapon to do that!");
  }
  for (i=0;i<sizeof(weapons);i++){
     wpn = weapons[i];
     lr_prof = (string)wpn->query_lr_prof_type();
     if (stringp(lr_prof)){
       break;
     }
  }
  if (!stringp(lr_prof)){
    notify_fail("You will need to be wielding a ranged weapon to do that!");
  }
  critters = all_living(battlement);
  removals = ({});
  for (i=0;i<sizeof(critters);i++){
    if (wizardp(critters[i]) || critters[i]->query_true_invis()){
      removals += ({critters[i]});      
      continue;
    }
  }
  critters -= removals;
  roomname = file_name(battlement);
  if (sizeof(critters)<1 || random(10)<7){
    batt_mob = new (MOB + "battlement");
    batt_mob->move(battlement);
    TO->add_exit(roomname, "upwards");
    TP->force_me("shoot battlement upwards 1");
    TO->remove_exit("upwards");
    batt_mob->remove();
    return 1;
  }
  if (sizeof(critters)>1){
    critter = critters[random(sizeof(critters)-1)];
  } else {
    critter = critters[0];
  }
  names = critter->query_id();
  crittername = names[0];
  TO->add_exit(roomname, "upwards");
  if (!interactive(present(crittername, battlement))){
      present(crittername, battlement)->set_paralyzed(1, "You are stunned after being shot by an"
                                                        +" arrow");
  }
  TP->force_me("shoot " + crittername + " upwards 1");
  TO->remove_exit("upwards");
  return 1;
}

void set_battlement(object bat){
  battlement = bat;
}

object query_battlement(){
  reset_battlement();
  return battlement;
}

int query_climb_position(object ob){
  return climb_positions[ob];
}

int plant_stakes(string str){ 
  object stakes;
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 1;
  }
  stakes = present("stakes", TP);
  if (!objectp(stakes)){
    tell_object(TP, "You don't have anything to plant here");
    return 1;
  }
  if (str != "stake" && str != "stakes"){
    tell_object(TP, "You could probably %^BOLD%^%^YELLOW%^<plant stakes>%^RESET%^ here to form"
                   +" defensive lines");
    return 1;
  }
  switch(staked){
  case 0:
    tell_object(TP, "You begin planting the %^ORANGE%^stakes%^RESET%^ in defensive lines in the"
                   +" field");
    tell_room(TO, TPQCN + "%^RESET%^ begins planting %^ORANGE%^sharpened wooden stakes%^RESET%^ in"
                +" defensive lines in the field");
    TP->set_property("busy", 1);
    call_out("plant2", 2, TP);
    break;
  case 1:
    tell_object(TP, "There are already stakes planted in this field. No need to plant any more.");
    break;
  }
  return 1;
}

void plant2(object ob){
  if (!objectp(ob)){return;}
  if (staked ==1){
    tell_object(ob, "The rows of stakes are completed. You stop planting them");
    ob->remove_property("busy");
    return;
  } 
  if (!present(ob, TO)){
    tell_object(ob, "You have left the field, so you stop planting stakes");
    ob->remove_property("busy");
    return;
  }
  stake_prog ++;
  if (stake_prog>20){  
    tell_object(ob, "You have finished planting the stakes");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ finishes planting the rows of defensive stakes", ob);
    staked = 1;
    add_item("stakes", "%^ORANGE%^There are some sharpened stakes here, planted in defensive lines on"
                     +" the ground. They have clearly been set up to slow down any attackers trying to"
                     +" make a dash for the stockade walls.");
    stake_prog = 0;
    ob->remove_property("busy");
    return;
  }
  tell_object(ob, "You continue planting rows of stakes");
  tell_room(TO, (string)ob->QCN + "%^RESET%^ carries on planting rows of stakes in the field", ob);  
  call_out("plant2", 2 + random(2), ob);
}

int query_pitted(){
  return pitted;
}
int query_staked(){
  return staked;
}
void set_pitted(int pit){
  pitted = pit;
}
void set_staked(int stake){
  staked = stake;
}

int climb_fence(string str){
  int i;
  object tools, * rooms, room, ladder;
  rooms = ({});
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something else.");
    return 1;
  }
  if (stringp(str) && interact("ladder", str)){
    ladder = present(str, TO);
    if (!objectp(ladder) || (string)ladder->query_raised_loc() != file_name(TO)){
      if (TP->id("orog")){
        TP->force_me("climb fence");
        TP->set_entry_method("scaled the fence to get onto the battlements");
        return 1;
      }
      tell_object(TP, "There's no " + str + " set up here for you to climb");
      return 1;
    }
    if (positions[TP]<10){
      if (TP->id("orog")){
        TP->force_me("approach fence");
        return 1;
      }
      tell_object(TP, "You aren't near enough to the fence at the moment. You will need to"
                     +" %^BOLD%^%^YELLOW%^approach%^RESET%^ it first");
      return 1;
    }
    if (!stringp(ladder->query_raised_loc() || (string)ladder->query_raised_loc()!= file_name(TO))){
      if (TP->id("orog")){
        TP->force_me("raise ladder");
        return 1;
      }
      tell_object(TP, "The " + (string)ladder->query_name() + " needs to be raised against the fence"
                       +" first");
      return 1;
    }
    tell_object(TP, "You begin climbing the %^ORANGE%^ladder%^RESET%^. This should be a quick way to"
                   +" the top of the fence");
    tell_room(TO, TPQCN + " %^RESET%^begins climbing a seige ladder toward the top of the fence.", TP);
    rooms += ({TABAXROOM + "watchtower1", TABAXROOM + "watchtower2"});
    if (objectp(battlement)){
      rooms += ({file_name(battlement) });
    }
    for (i=0;i<sizeof(rooms); i++){
      if (!objectp(rooms[i])) continue;
      room = find_object_or_load(rooms[i]);
      if (!objectp(room)) {continue;}
      tell_room(room, TPQCN + "%^RESET%^ begins climbing a ladder up the %^ORANGE%^stockade fence"
                       +"%^RESET%^, at"
                       +" the " + query_name() + "%^RESET%^.");
    }
    TP->set_property("busy", 1);
    TP->force_me("pose climbing a ladder");
    TP->set_property("climbing", 1); 
    call_out("ladder_climb2", 2, TP, ladder);
    return 1;
  }
  if (!stringp(str) ||(str != "fence" && str != "stockade" && str != "the fence")){
    tell_object(TP, "You could probably climb the fence, if you wanted.");
    return 1;
  }
  if (positions[TP]<10){
    if (TP->id("orog")){
      TP->force_me("approach fence");
      return 1;
    }
    tell_object(TP, "You aren't near enough to the fence at the moment. You will need to"
                   +" %^BOLD%^%^YELLOW%^approach%^RESET%^ it first");
    return 1;
  }
  tools = present("climb_tool", TP);
  if (TP->query_class_level("thief")==0 && TP->query_class_level("bard")==0){
    if (!objectp(tools)){
      tell_object(TP, "Only thieves and bards can climb unaided. Showoffs.");
      return 1;
    }
  }
  if (!objectp(tools)){
    tell_object(TP, "This wall will present quite a challenge to climb. Even you would probably"
                   +" benefit from climbing tools here.");
  }
  tell_object(TP, "You begin climbing the %^ORANGE%^stockade fence%^RESET%^. It would be quicker with"
                 +" a ladder or something");
  rooms += ({TABAXROOM + "watchtower1", TABAXROOM + "watchtower2"});
  if (objectp(battlement)){
    rooms += ({file_name(battlement) });
  }
  for (i=0;i<sizeof(rooms); i++){
    if (!objectp(rooms[i])) continue;
    room = find_object_or_load(rooms[i]);
    if (!objectp(room)) {continue;}
    tell_room(room, TPQCN + "%^RESET%^ begins climbing the %^ORANGE%^stockade fence%^RESET%^, at"
                       +" the " + query_short() + "%^RESET%^.");
  }
  tell_room(TO, TPQCN + "%^RESET%^ begins climbing the %^ORANGE%^stockade fence%^RESET%^, at"
                       +" the " + query_short() + "%^RESET%^.", TP);
  TP->set_property("busy", 1);
  TP->force_me("pose climbing the fence");
  TP->set_property("climbing", 1);
  call_out("climb2", 2, TP);
  return 1;
}

void ladder_climb2(object ob, object ladder){
  int pos, i;
  string here_name, bat_name;
  object * rooms, room;
  if (!objectp(ob)){
    return;
  }
  if (!present(ob, TO)){
    tell_object(ob, "You've left the field, so you're clearly not climbing the ladder any more.");
    return;
  }
  if (!objectp(ladder)){
    tell_object(ob, "The ladder you were climbing appears to have disappeared. That's odd. You can"
                   +" consider yourself on the ground again, and you might want to make a bug"
                   +" report.");
    return 1;
  }
  if  (!present(ladder, TO)){
    tell_object(ob, "The ladder you were climbing appears to have moved. That's odd. You can"
                   +" consider yourself on the ground again, and you might want to make a bug"
                   +" report.");
    ladder->remove_climber(ob);
    return 1;   
  }
  here_name = file_name(TO);
  if ((string)ladder->query_raised_loc() != here_name){
    if (TP->id("orog")){
      TP->force_me("raise ladder");
      return 1;
    }
    tell_object(ob, "Your ladder is no longer raised against the fence. You'll need to raise it again"
                   +" if you want to continue climbing!");
    return 1;
  }
  rooms = ({TABAXROOM + "watchtower1", TABAXROOM + "watchtower2"}); 
  if (stringp(here_name)){
    rooms += ({here_name});
  }
  if (objectp(battlement)){
    bat_name = file_name(battlement);
  }
  if (stringp(bat_name)){
    rooms += ({bat_name});
  }
  pos = ladder->query_climb_position(ob);
  pos += 5 + random(3);
  ladder->set_climb_position(ob, pos);
  tell_object(ob, "You climb quickly up the ladder. You are now " + how_high(pos) + ".");
  for (i=0;i<sizeof(rooms);i++){
    room = find_object_or_load(rooms[i]);
    if (!objectp(rooms[i])){continue;}
    tell_room(room, (string)ob->QCN + " climbs quickly up the ladder. " 
                       + capitalize((string)ob->QS) + " %^RESET%^is now " + how_high(pos) + ".", ob );
  }
  if (pos > 19){
    if (ob->id("orog")){
      ob->set_entry_method("climbing over the battlement on a ladder");
    }
    reach_top(ob);
    return;
  }
  call_out("ladder_climb2", 2+ random(2), ob, ladder);
}

void climb2(object ob){
  int pos, skill, i;
  string here_name, bat_name;
  object * rooms, room;
  skill = 0;
  if (!objectp(ob)){
    return;
  }
  if (!present(ob, TO)){
    tell_object(ob, "You've left the field, so you're clearly not climbing the fence any more.");
    return;
  }
  skill = ob->query_thief_skill("climb walls");
  skill -= 35;
  if (present("climb_tool", ob)){
    skill += 50;
  }
  if (skill < 45){
    skill = 45;
  }
  if (skill > 98){
    skill = 98;
  }
  if (random(100)+1 > skill){
    fall_off(ob);
    return;
  }
  rooms = ({TABAXROOM + "watchtower1", TABAXROOM + "watchtower2"}); 
  here_name = file_name(TO);
  if (stringp(here_name)){
    rooms += ({here_name});
  }
  if (objectp(battlement)){
    bat_name = file_name(battlement);
  }
  if (stringp(bat_name)){
    rooms += ({bat_name});
  }
  pos = climb_positions[ob];
  switch (random(3)){
  case 0:
    tell_object(ob, "You manage to hang onto the wall, but fail to make any progress.");
    break;
  case 1:
    pos += 1;
    climb_positions[ob] = pos;
    tell_object(ob, "You make a little progress up the wall. You are now " + how_high(pos) + ".");
    ob->force_me("pose " + how_high(pos));
    for (i=0;i<sizeof(rooms);i++){
      room = find_object_or_load(rooms[i]);
      if (!objectp(room)){continue;}
      tell_room(room, (string)ob->QCN + " makes a little progress climbing the wall. " 
                       + capitalize((string)ob->QS) + " %^RESET%^is now " + how_high(pos) + ".", ob );
    }
    break;
  case 2:
      pos += 2+random(2);
      climb_positions[ob] = pos;
      tell_object(ob, "You make good progress up the wall. You are now " + how_high(pos) + ".");
      ob->force_me("pose " + how_high(pos));
      for (i=0;i<sizeof(rooms);i++){
      room = find_object_or_load(rooms[i]);
      if (!objectp(rooms[i])){continue;}
      tell_room(room, (string)ob->QCN + " makes good progress climbing the wall. " 
                       + capitalize((string)ob->QS) + " %^RESET%^is now " + how_high(pos) + ".", ob );
    }
    break;
  }
  if (pos > 19){
    if (ob->id("orog")){
      ob->set_entry_method("climbing up the fence and over the battlement.");
      ob->force_me("pose clear");
    }
    reach_top(ob);
    return;
  }
  call_out("climb2", 2+ random(2), ob);
}

string how_high(int pos){
  switch (pos){
  case 0: 
    return "still on the ground";
  case 1..3:
    return "near the bottom of the wall";
  case 4..7:
    return "a few feet up the wall";
  case 8..11:
    return "half way up the wall";
  case 12..15:
     return "approaching the top of the wall";
  case 16..19:
     return "nearly at the top of the wall";
  default:
     return "at the top of the wall";
  }
}

void reach_top(object ob){
  int i;
  object * rooms, * ladders, * climbers;
  if (!objectp(ob)){ return;}
  if (!present(ob, TO)){
    ob->remove_property("busy");
    ob->remove_property("climbing");
    map_delete(climb_positions, ob);
    return;
  }
  if (!objectp(battlement)){
    tell_object(ob, "There seems to be an error with the battlement you're trying to climb onto, so"
                   +" you fall to the ground. Please blame Lujke, or make a bug report");
    ob->remove_property("busy");
    ob->remove_property("climbing");
    map_delete(climb_positions, ob);
    return;   
  }
  rooms = ({ find_object_or_load(TABAXROOM + "watchtower1"), 
              find_object_or_load(TABAXROOM + "watchtower2") });
  tell_room(TO, (string)ob->QCN + "%^RESET%^ disappears over the top of the battlement", ob);
  if (ob->id("orog")){
    ob->force_me("pose clear");
  }
  ob->move(battlement);
  map_delete(climb_positions, ob);
  ladders = all_inventory(TO);
  if (sizeof(ladders)>0){
    for (i=0;i<sizeof(ladders);i++){
      if (ladders[i]->id("ladder") && ladders[i]->query_climb_positions(ob)){
        ladders[i]->remove_climber(ob);
      }
    }
  }
  for(i=0;i<sizeof(rooms);i++){
    if (!objectp(rooms[i])){ 
      continue;
    }
    tell_room(rooms[i], (string)ob->QCN + " clambers onto the battlement above " + query_short());
  }
  tell_room(battlement, (string)ob->QCN + " clambers over the battlement", ob);
  tell_object(ob, "%^ORANGE%^You clamber over onto the battlements");
  if (objectp(ob)){
    ob->force_me("pose clear");
    ob->force_me("look");
    ob->remove_property("busy");
    ob->remove_property("climbing");
    if (ob->id("orog")){
      ob->reach_top();
    }
  }
}

void fall_off(object ob){
  int i, pos, hp;
  string * rooms, how_far;
  object room;
  if (!objectp(ob)){
    return;
  }
  ob->remove_property("busy");
  ob->remove_property("climbing");
  pos = climb_positions[ob];
  map_delete(climb_positions, ob);
  ob->force_me("pose clear");
  if (!present(ob, TO)){
    return;
  }
  switch(pos){
  case 0:
    tell_object(ob, "You fail to get a grip at the bottom of the wall");
    map_delete(climb_positions, ob);
    return;
    break;
  case 1..3:
    how_far = "a short distance";
    break;
  case 4..7:
    how_far = "a few feet";
    break;
  case 8..11:
    how_far = "half the height of the wall";
    break;
  case 12..15:
    how_far = "most of the height of the wall";
    break;
  case 16..19:
    how_far = "nearly the whole height of the wall";
    break;
  default:
    how_far = "the whole height of the wall";
    break;
  }
  rooms = ({TABAXROOM + "watchtower1", TABAXROOM + "watchtower2", file_name(TO)});
  for (i=0;i<sizeof(rooms);i++){
    if (!stringp(rooms[i])){
      continue;
    }
    room = find_object_or_load(rooms[i]);
    if (!objectp(room)){
      continue;
    }
    tell_room(room, (string)ob->QCN + " falls " + how_far + " and lands on the ground", ob);
  }
  tell_object(ob, "You fall " + how_far + " and land on the ground");
  if (ob->id("orrog") && random(20) + 5 < pos){
    ob->die();
    return;
  }
  hp = pos * 1 + random(2);
  ob->do_damage(ob->return_target_limb(),hp);
  ob->add_attacker(TO);
  ob->continue_attack();
  if(objectp(ob)){
    ob->remove_attacker(TO);
  }
  return;
}

int approach_fence(string str){
  str = lower_case(str);
  if (str != "fence" && str != "stockade" && str != "the fence" && str != "wall" && str != "the wall"){
    tell_object(TP, "You could probably approach the fence, if you wanted.");
    return 1;
  }
  if (TP->id("xxsquadxx")){
    if (objectp(battlement)){
      TP->move(battlement);
      TP->set_tactic(WAIT);
    } else {
      TP->force_me("tell lujke %^BOLD%^%^RED%^Serious problem with the battlement, dude");
    }
  }
  if (positions[TP]>9){
    if (present("seige ladder", TP)){
      if (TP->id("orog")){
        TP->force_me("raise ladder");
        TP->set_entry_method("scaled a seige ladder to get over the fence and onto the battlements");
        return 1;
      }
      tell_object(TP, "You are already beside the fence. You could probably %^BOLD%^%^YELLOW%^<raise>"
                   +" %^RESET%^ your ladder here if you wished");    
      return 1;
    }
    if (TP->id("orog")){
      TP->force_me("climb ladder");
      TP ->force_me("climb fence");
      TP->set_entry_method("scaled the fence to get onto the battlements");
      return 1;
    }
    tell_object(TP, "You are already beside the fence. You could probably %^BOLD%^%^YELLOW%^<climb>"
                   +" %^RESET%^it if you wished");
    return 1;
  }
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 1;
  }
  if (TP->query_property("approaching")>0){
    tell_object(TP, "You are already approaching the fence.");
    return 1;
  }
  tell_object(TP, "You start moving toward the fence");
  tell_room(TO, TPQCN + "%^RESET%^ starts moving toward the stockade fence", TP);
  TP->set_property("approaching");
  call_out("approach2", 2, TP);
  return 1;
}

void approach2(object ob){
  int pos;
  if (!objectp(ob)){
    return;
  }
  if (!present(ob, TO)){
    tell_object(ob, "You have moved away from the stockade, so you've clearly stopped approaching it");
    positions[ob] = 0;
    return;
  }

  pos = positions[ob];
  pos ++;
  if (pos >9){
    tell_room(TO, "%^BOLD%^%^CYAN%^" + (string)ob->QCN + "%^BOLD%^%^CYAN%^ has reached the"
                 +" %^RESET%^%^ORANGE%^fence%^BOLD%^%^CYAN%^!", ob);
    ob->remove_property("approaching");
    if( present("seige ladder", TP)){
      if (TP->id("orog")){
        TP->force_me("raise ladder");
        return;
      }
      tell_object(ob, "You have reached the fence! You could probably %^BOLD%^%^YELLOW%^<raise>"
                   +" %^RESET%^your ladder against it from here, if you wished.");
    } else {
      if (TP->id("orog")){ 
        TP->climb_fence();
      }
      tell_object(ob, "You have reached the fence! You could probably %^BOLD%^%^YELLOW%^<climb>"
                     +" %^RESET%^it if you wished.");
    }
    return;
  }
  switch(pitted){
  case CLEAR:
    switch(staked){
    case 0:
      tell_object(ob, "You make your way swiftly towards the fence");
      tell_room(TO, (string)ob->QCN + " moves swiftly towards the fence", ob);
      pos += 5;
      break;
    case 1:
      tell_object(ob, "You move slowly towards the fence, picking your way through the lines of"
                     +" %^ORANGE%^defensive stakes%^RESET%^ in the field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves slowly towards the fence, picking " 
                    + (string)ob->QP
                    + " way through the lines of %^ORANGE%^defensive stakes%^RESET%^ in the field"
                   , ob);
      pos += 1 + random(3);
      break;
    }
    break;
  case PITS:
    if (random(20)>18){
      pitfall(ob);
      break;
    }
    switch(staked){
    case 0:
      tell_object(ob, "You make your way carefully towards the fence, picking your way between the"
                     +" %^BOLD%^%^BLACK%^pits%^RESET%^ in the field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves carefully towards the fence, picking a path"
                    +" between the %^BOLD%^%^BLACK%^pits%^RESET%^.", ob);
      pos += 2 + random(2);
      break;
    case 1:
      tell_object(ob, "You make your way carefully towards the fence, picking your way between the"
                     +" %^BOLD%^%^BLACK%^pits%^RESET%^ and %^ORANGE%^defensive stakes%^RESET%^ in the"
                     +" field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves carefully towards the fence, picking a path"
                    +" between the %^BOLD%^%^BLACK%^pits%^RESET%^ and %^ORANGE%^defensive stakes"
                    +"%^RESET^.", ob);
      pos += 1 + random(2);
      break;
    }
    break;
  case COVERED_PITS:
    if (random(6)>3){
      pitfall(ob);
      break;
    }
    switch(staked){
    case 0:
      tell_object(ob, "You make your way swiftly towards the fence");
      tell_room(TO, (string)ob->QCN + " moves swiftly towards the fence", ob);
      pos += 5;
      break;
    case 1:
      tell_object(ob, "You move slowly towards the fence, picking your way through the lines of"
                     +" %^ORANGE%^defensive stakes%^RESET%^ in the field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves slowly towards the fence, picking " 
                    + (string)ob->QP
                    + " way through the lines of %^ORANGE%^defensive stakes%^RESET%^ in the field"
                   , ob);
      pos += 1 + random(3);
      break;
    }
    break;
  case STAKED_PITS:
    switch(staked){
    case 0:
      tell_object(ob, "You make your way carefully towards the fence, picking your way between the"
                     +" %^BOLD%^%^BLACK%^pits%^RESET%^ in the field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves carefully towards the fence, picking a path"
                    +" between the %^BOLD%^%^BLACK%^pits%^RESET%^.", ob);
      pos += 2 + random(2);
      break;
    case 1:
      tell_object(ob, "You make your way carefully towards the fence, picking your way between the"
                     +" %^BOLD%^%^BLACK%^pits%^RESET%^ and %^ORANGE%^defensive stakes%^RESET%^ in the"
                     +" field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves carefully towards the fence, picking a path"
                    +" between the %^BOLD%^%^BLACK%^pits%^RESET%^ and %^ORANGE%^defensive stakes"
                    +"%^RESET^.", ob);
      pos += 1 + random(2);
      break;
    }
    break;
  case COVERED_STAKED_PITS:
    if (random(6)>3){
      pitfall(ob);
      break;
    }
    switch(staked){
    case 0:
      tell_object(ob, "You make your way swiftly towards the fence");
      tell_room(TO, (string)ob->QCN + " moves swiftly towards the fence", ob);
      pos += 5;
      break;
    case 1:
      tell_object(ob, "You move slowly towards the fence, picking your way through the lines of"
                     +" %^ORANGE%^defensive stakes%^RESET%^ in the field");
      tell_room(TO, (string)ob->QCN + "%^RESET%^ moves slowly towards the fence, picking " 
                    + (string)ob->QP
                    + " way through the lines of %^ORANGE%^defensive stakes%^RESET%^ in the field"
                   , ob);
      pos += 1 + random(3);
      break;
    }
    break;
  }
  positions[ob] = pos;
  call_out("approach2", 2 + random(2), ob);
}
int query_position(object ob){
  return positions[ob];
}

void set_position(object ob, int pos){
  positions[ob] = pos;
}


void pitfall(object ob){
  int dam;
  if (!objectp(ob)||!present(ob, TO)){
    return;
  }
  switch (pitted){
  case PITS:
    tell_object(ob, "Despite taking care, you manage to fall into one of the pits in the ground!");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ falls into one of the pits in the ground!");
    dam = random(20+20);
    if (ob->id("orog") && random(6)>4){
      dam += 500;
    }
    break;
  case COVERED_PITS:
    tell_object(ob, "You fall into a cunningly hidden pit in the ground!");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ falls into a cunningly hidden pit in the ground!");
    dam = random(20+20);
    if (ob->id("orog") && random(5)>3){
      dam += 500;
    }
    break;
  case STAKED_PITS:
    tell_object(ob, "Despite taking care, you manage to fall into one of the %^BOLD%^%^RED%^staked"
                +" pits %^RESET%^in the ground!");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ falls into one of the %^BOLD%^%^RED%^staked pits"
                +" %^RESET%^in the ground!");
    dam = random(20+50);
    if (ob->id("orog") && random(7)>3){
      dam += 500;
    }
    break;  
  case COVERED_STAKED_PITS:
    tell_object(ob, "You fall into a cunningly hidden pit in the ground. It has %^BOLD%^%^RED%^stakes"
                   +" %^RESET%^in the bottom!");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ falls into a cunningly hidden pit in the ground!");
    dam = random(20+50);
    if (ob->id("orog") && random(7)>3){
      dam += 500;
    }
    break;
  }
  ob->do_damage(ob->return_target_limb(),dam);
  ob->add_attacker(TO);
  ob->continue_attack();
  if(objectp(ob)){
    ob->remove_attacker(TO);
    if (ob->query_hp()>0){
      call_out("resume_approach", 5 + random (5), ob);
    }
  }
  ob->set_paralyzed(50, "You're dazed from falling in the pit!");
}

void resume_approach(object ob){
  if (!objectp(ob)){
    return;
  }
  tell_object(ob, "You climb out of the pit and resume your approach toward the stockade fence");
  tell_room(TO, (string)ob->QCN + " climbs out of the pit and begins approaching the fence again");
  ob->remove_paralyzed();
  call_out("approach2",3, ob );
}

int improve(string str){
  if (pitted<1){
    tell_object(TP, "There's nothing here for you to improve on right now");
    return 1;
  }
  tell_object(TP, "The pits could maybe be improved on if you could find something to cover them over"
                 +" with, or something dangerous to put in the bottom of them.");
  return 1;
}

int dig_pits(string str){
  object * wielded;
  int i;
  if (str != "pit" && str != "pits"){
    tell_object(TP, "You could probably %^BOLD%^%^YELLOW%^<dig pits>%^RESET%^ here, if you wanted");
    return 1;
  }

  if (pitted>0){
    tell_object(TP, "Defensive pits have already been dug in the ground here, no more are needed\n");
    if (pitted<2){
      tell_object(TP, "It might be possible to improve on simple open pits, though.");
    }
    return 1;
  }
  if (str != "pits" && str != "defensive pits"){
    tell_object(TP, "You could dig defensive pits here");
    return 1;
  }
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 1;
  }
  wielded = TP->query_wielded();
  if (sizeof(wielded)<1){
    tell_object(TP, "You're going to need to be wielding something you can dig with");
    return 1;
  }
  if (!present("spade", TP) && !present("pick", TP)){
    wielded = TP->query_wielded();
    switch (sizeof(wielded)){
    case 0:
      tell_object(TP, "Dig with what? Your bare hands? ");
    case 1:
      tell_object(TP, "Dig with what? Your " + (string) wielded[0]->query_short() + "?"); 
    default:
      tell_object(TP, "Dig with what? Your " + (string) wielded[0]->query_short() + " and your "
                     + (string) wielded[1]->query_short() + "?"); 
    }
    return 1;
  }  
  if  (!wielded[0]->id("spade") && !wielded[0]->id("pick")){
    tell_object(TP, "Dig with what? Your " + (string) wielded[0]->query_short() + "?"); 
    return 1;
  }
  tell_object(TP, "%^ORANGE%^You set about digging some defensive pits in the field");
  tell_room(TO, TPQCN + "%^RESET%^%^ORANGE%^ sets about digging some defensive pits in the field", TP);
  TP->force_me("pose digging");
  TP->set_property("busy", 1);
  call_out("dig2",3, TP);
  return 1;
}

void dig2(object ob){
  string message;
  object * wielded;
  if (!objectp(ob)){ return;}
  if (environment(ob) != TO){
    tell_object(ob, "%^ORANGE%^You've wandered off and stopped digging");
    ob->remove_property("busy");
    return;
  }
  if (pit_prog > 20) {
    tell_object(ob, "%^ORANGE%^The pits are finished. You can stop digging now.");
    ob->remove_property("busy");
    ob->force_me("pose clear");
    return 1;
  }
  wielded = ob->query_wielded();
  if (!wielded[0]->id("spade") &&!wielded[0]->id("pick")){
    tell_object(ob, "%^ORANGE%^You've put away your digging implement, so you stop digging");
    tell_room(TO, (string)ob->QCN + "%^ORANGE%^ has put away " + (string)ob->QP + " digging tool, and"
                  +" given up on digging for now", ob);
    ob->force_me("pose clear");
    ob->remove_property("busy");
    return;
  }
  pit_prog ++;
  if (pit_prog <20){
    message = "%^CYAN%^You carry on digging.%^RESET%^";
    switch (random(3)){
    case 0:
      message += DIGMESSAGE[random(sizeof(DIGMESSAGE))];
      break;
    case 1:
      message += " It's real hard work.";
      break;
    }
    tell_object (ob, message);
    tell_room(TO, (string)ob->QCN + "%^RESET%^ continues digging, shoveling dirt with " 
                  + (string)ob->QP + " " + (string)wielded[0]->query_short(), ob);
    call_out("dig2", 2 + random(2), ob);
    return;
  }
  tell_object (ob, "%^ORANGE%^You finally finish the last of the pits.");
  tell_room(TO, (string)ob->QCN + "%^RESET%^%^ORANGE%^ finally finishes digging the last of the pits",
                     ob);
  add_item("pits", "You can see that defensive %^BOLD%^%^BLACK%^pits%^RESET%^ have been dug in the"
                 +" field, clearly designed to slow and delay any charge on the %^ORANGE%^stockade"
                 +"%^RESET%^.");
  pitted = PITS;
  pit_prog = 0; 
  ob->force_me("pose clear");
  ob->remove_property("busy");
}

int fix_stakes(string str){
  object stake;
  stake =present("stake", TP); 
  if (!objectp(stake)){
    tell_object(TP, "Fix what?");
    return 1;
  }
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 0;
  }
  if (!stake->id(str)){
    tell_object(TP, "You could probably %^BOLD%^%^YELLOW%^<fix stakes>%^RESET%^ here, to make the"
                   +" place more defensible.");
  }
  tell_object(TP, "%^GREEN%^You set about planting the %^ORANGE%^stakes%^GREEN%^ into the ground, in"
                 +" defensive lines.");
  tell_room(TO, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ set about planting %^ORANGE%^sharpened"
               +" stakes%^GREEN%^ into the ground, in defensive lines.");
  TP->force_me("pose planting stakes into the ground");
  TP->set_property("busy", 1);
  call_out("fix2", 2+ random(2), TP);
}


void fix2(object ob){
  object stakes;
  if (!objectp(ob)) {return;}
  if (!present(ob, TO)){ 
    tell_object(ob, "%^GREEN%^You have left the field, so you stop planting stakes for now");
    return;
  }
  stakes = present("stakes", ob);
  if (!objectp(stakes)){
    tell_object(ob, "%^BOLD%^%^CYAN%^You have run out of stakes to plant");
    ob->force_me("pose clear");
    ob->remove_property("busy");
    return;
  }
  if (staked ==1 || stake_prog >20){
    tell_object(ob, "%^BOLD%^%^CYAN%^At last the defensive stake formations are complete!");
    tell_room(TO, "%^CYAN%^" + (string)ob->QCN + "%^RESET%^%^CYAN%^ completes " + (string)ob->QP 
                + " work on the %^ORANGE%^defensive stake formations%^CYAN%^!", ob);
    if (stake_prog > 20 || staked ==0){
      stake_prog = 0;
      staked = 1;
      add_item("stakes", "Sharpened wooden stakes have been fixed in defensive formations in the"
               +" field. These will definitely slow up any attack on the stockade.");
      stakes->remove();
    }
    ob->force_me("pose clear");
    ob->remove_property("busy");
    return;
  }
  stake_prog ++;
  tell_object(ob, "%^GREEN%^You plant another %^ORANGE%^stake%^GREEN%^ in the ground");
  tell_room(TO, "%^GREEN%^" + (string)ob->QCN + "%^RESET%^%^GREEN%^ plants another %^ORANGE%^sharpened"
               +" stake%^GREEN%^ in the ground", ob);
  call_out("fix2", 2 + random (3), ob);
}

int bury_stakes(string str){
  object stake;
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 1;
  }
  stake =present("stakes", TP); 
  if (!objectp(stake)){
    tell_object(TP, "You don't have any stakes to bury.");
    return 1;
  }
  if (!stake->id(str)){
    tell_object(TP, "You could probably %^BOLD%^%^YELLOW%^<bury stakes>%^RESET%^ here, to make the"
                   +" pits more deadly.");
    return 1;
  }
  if (pitted <1){
    tell_object(TP, "There are no pits here for you to bury the stakes in. You could"
                   +" %^BOLD%^%^YELLOW%^<plant stakes>%^RESET%^ to build defensive lines of sharpened"
                   +" stakes in the field, if you wanted.");
    return 1;
  }
  if (pitted == 2){
    tell_object(TP, "The pits have been covered over. You can't bury stakes in them now");
    return 1;
  }
  tell_object(TP, "%^GREEN%^You set about burying %^ORANGE%^stakes%^GREEN%^ in the pits. That'll"
                 +" make it nasty to fall into them.");
  tell_room(TO, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ set about burying %^ORANGE%^sharpened"
               +" stakes%^GREEN%^ in the pits. That'll make it nasty to fall into them.", TP);
  TP->force_me("pose burying stakes in the pits");
  TP->set_property("busy", 1);
  call_out("bury2", 2+ random(2), TP);
  return 1;
}


void bury2(object ob){
  object stakes;
  if (!objectp(ob)) {return;}
  if (!present(ob, TO)){ 
    tell_object(ob, "%^GREEN%^You have left the field, so you stop burying stakes for now");
    ob->remove_property("busy");
    return;
  }
  if (pitted == 2){
    tell_object(ob, "The pits have been covered over. You can't bury stakes in them now");
    ob->remove_property("busy");
    ob->force_me("pose clear");
    return;
  }
  stakes = present("stakes", ob);
  if (!objectp(stakes)){
    tell_object(ob, "%^BOLD%^%^CYAN%^You have run out of stakes to bury");
    ob->remove_property("busy");
    ob->force_me("pose clear");
    return;
  }
  if (pitted >2 || bury_prog >20){
    tell_object(ob, "%^BOLD%^%^CYAN%^At last the pits are all staked!");
    tell_room(TO, "%^CYAN%^" + (string)ob->QCN + "%^RESET%^%^CYAN%^ completes " + (string)ob->QP 
                + " work burying %^ORANGE%^stakes %^CYAN%^ in the pits!", ob);
    ob->force_me("pose clear");
    ob->remove_property("busy");
    if (bury_prog > 20 || pitted<3){
      bury_prog = 0;
      pitted = 3;
      stakes->remove();
    }
    add_item("pits", "Defensive %^BOLD%^%^BLACK%^pits%^RESET%^ have beend dug here, presenting an"
                    +" obstacle against any attack on the stockade. You can also make out that they"
                    +" have had %^ORANGE%^sharpened stakes%^RESET%^ planted in the bottom of them."
                    +" Nasty.");
    return;
  }
  bury_prog ++;
  tell_object(ob, "%^GREEN%^You bury %^ORANGE%^stakes%^GREEN%^ in one of the pits");
  tell_room(TO, "%^GREEN%^" + (string)ob->QCN + "%^RESET%^%^GREEN%^ buries %^ORANGE%^sharpened"
               +" stake%^GREEN%^ in one of the pits", ob);
  call_out("bury2", 2 + random (3), ob);
}

int cover_pits(string str){
  object cover;
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 1;
  }
  cover =present("canvas", TP); 
  if (!objectp(cover)){
    tell_object(TP, "You don't have anything suitable to cover the pits with.");
    return 1;
  }
  str = lower_case(str);
  if (str != "pit" && str != "pits"){
    tell_object(TP, "You could probably cover the pits here with the canvas you have. Try"
                   +" %^BOLD%^%^YELLOW%^<cover pits>%^RESET%^");
    return 1;
  }
  if (pitted == 2 || pitted ==4){
    tell_object(TP, "The pits have already been covered over. You don't need to do that");
    return 1;
  }
  tell_object(TP, "%^GREEN%^You set about covering and " + CAMOUFLAGING + "%^GREEN%^ the"
                 +" pits. Tricksy.");
  tell_room(TO, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ set about covering and " + CAMOUFLAGING 
               +" %^GREEN%^the pits. Tricksy.", TP);
  TP->force_me("pose covering and camouflaging pits");
  TP->set_property("busy");
  call_out("cover2", 2+ random(2), TP);
  return 1;
}


void cover2(object ob){
  object canvas;
  if (!objectp(ob)) {return;}
  if (!present(ob, TO)){ 
    tell_object(ob, "%^GREEN%^You have left the field, so you stop " + CAMOUFLAGING + " the pits for"
                  +" now");
    ob->remove_property("busy");
    return;
  }
  if (pitted == 2 || pitted == 4){
    tell_object(ob, "The pits have all been covered over. You have finished");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ finishes " + (string)ob->QP + " work covering and"
                  +" " + CAMOUFLAGING + " the pits.", ob);
    ob->force_me("pose clear");
    ob->remove_property("busy");
    return;
  }
  canvas = present("canvas", ob);
  if (!objectp(canvas)){
    tell_object(ob, "%^BOLD%^%^CYAN%^You have run out of canvas to cover the pits with");
    ob->remove_property("busy");
    ob->force_me("pose clear");
    return;
  }
  if (cover_prog >15){
    tell_object(ob, "At last all the pits are covered and " + CAMOUFLAGED + "!");
    tell_room(TO, "%^CYAN%^" + (string)ob->QCN + "%^RESET%^%^CYAN%^ completes " + (string)ob->QP 
                + " work covering and " + CAMOUFLAGING + "%^BOLD%^%^CYAN%^ the pits!", ob);
    cover_prog = 0;
    if (pitted == 1){
      pitted = 2;
    }
    if (pitted == 3){
      pitted = 4;
    }
    ob->force_me("pose clear");
    ob->remove_property("busy");
    canvas->remove();
    remove_item("pits");
    add_item("ground", "The ground has been disturbed a bit here.");
    set_search("ground", "A careful scan of the ground identifies several areas where it appears that"
                        +" pits have been dug and then covered over and " + CAMOUFLAGED + "");
    return;
  }
  cover_prog ++;
  tell_object(ob, "You cover one of the pits with canvas, and drag dirt and debris over it as"
                 +" " + CAMOUFLAGE + ".");
  tell_room(TO, "%^GREEN%^" + (string)ob->QCN + "%^RESET%^%^GREEN%^ covers one of the pits with canvas"
             +" and drags dirt and debris over it as " + CAMOUFLAGE + "", ob);
  call_out("cover2", 2 + random (3), ob);
}

int uncover_pits(string str){
  if (TP->query_property("busy")){
    tell_object(TP, "You are busy doing something already");
    return 1;
  }
  if (pitted != 2 && pitted !=4){
    tell_object(TP, "The pits are not covered. You don't need to do that");
    return 1;
  }
  str = lower_case(str);
  if (str != "pit" && str != "pits"){
    tell_object(TP, "You could probably uncover the pits here by pulling the canvas off them. Try"
                   +" %^BOLD%^%^YELLOW%^<uncover pits>%^RESET%^");
    return 1;
  }
  tell_object(TP, "%^GREEN%^You set about dragging the canvases off the pits");
  tell_room(TO, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ sets about uncovering the " + CAMOUFLAGED 
               +"%^GREEN%^ pits.", TP);
  TP->force_me("pose uncovering " + CAMOUFLAGED + " pits");
  TP->set_property("busy");
  call_out("uncover2", 2+ random(2), TP);
  return 1;
}


void uncover2(object ob){
  if (!present(ob, TO)){ 
    tell_object(ob, "%^GREEN%^You have left the field, so you stop uncovering the pits for"
                  +" now");
    ob->remove_property("busy");
    return;
  }
  if (pitted != 2 && pitted != 4){
    tell_object(ob, "The pits have all been uncovered. You have finished");
    tell_room(TO, (string)ob->QCN + "%^RESET%^ finishes " + (string)ob->QP + " work uncovering the "
                  + CAMOUFLAGED + " pits.", ob);
    ob->force_me("pose clear");
    ob->remove_property("busy");
    return;
  }
  if (uncover_prog >15){
    tell_object(ob, "At last you have uncovered all the pits!");
    tell_room(TO, "%^CYAN%^" + (string)ob->QCN + "%^RESET%^%^CYAN%^ completes " + (string)ob->QP 
                + " work uncovering the pits in the field!", ob);
    uncover_prog = 0;
    if (pitted == 2){
      pitted = 1;
    }
    if (pitted == 4){
      pitted = 3;
    }
    ob->force_me("pose clear");
    ob->remove_property("busy");
    remove_item("ground");
    remove_search("ground");
    switch(pitted){
    case 1:
      add_item("pits", "You can see that defensive %^BOLD%^%^BLACK%^pits%^RESET%^ have been dug in the"
                 +" field, clearly designed to slow and delay any charge on the %^ORANGE%^stockade"
                 +"%^RESET%^.");
      break;
    case 4:
      add_item("pits", "Defensive %^BOLD%^%^BLACK%^pits%^RESET%^ have beend dug here, presenting an"
                    +" obstacle against any attack on the stockade. You can also make out that they"
                    +" have had %^ORANGE%^sharpened stakes%^RESET%^ planted in the bottom of them."
                    +" Nasty.");
      break;
    }
    return;
  }
  uncover_prog ++;
  tell_object(ob, "You uncover one of the pits");
  tell_room(TO, "%^GREEN%^" + (string)ob->QCN + "%^RESET%^%^GREEN%^ pulls away a sheet of " 
                   + CAMOUFLAGED + "canvas, revealing a pit underneath.", ob);
  call_out("uncover2", 2 + random (3), ob);
}



string corn_desc(){
  string corndesc;
  switch (lower_case(month(time()))){
  case "winterstime":
    corndesc = "%^BOLD%^%^WHITE%^It is the cold season and no crop grows here now, but the %^RESET%^"
              +"%^ORANGE%^ground%^BOLD%^%^WHITE%^ has been made ready for the next crop.%^RESET%^";
    break;
  case "renewal":
    corndesc = "%^GREEN%^The crop is newly sown, and tiny seedlings are sprouting up%^RESET%^";
    break;
  case "springstime":
    corndesc = "%^GREEN%^Young m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
              +" plants, standing three to four feet high, wave gently in the breeze.%^RESET%^";
    break;
  case "plantingdays":   
    corndesc = "%^GREEN%^The maize is almost fully grown; the plants stand at five feet or taller, the"
              +" %^BOLD%^%^YELLOW%^yellow ears%^RESET%^%^GREEN%^ unmistakeable against the dark green"
              +" leaves.%^RESET%^";
    break;
  case "sundays":
    corndesc = "%^GREEN%^The m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e plants are"
              +" fully grown and workers are have already begun harvesting them.%^RESET%^";
    break;
  case "summerstime":
    corndesc = "%^GREEN%^The crop is newly sown, and tiny seedlings are sprouting up%^RESET%^";
    break;
  case "growingdays":
    corndesc = "%^GREEN%^Young m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
              +" plants, standing three to four feet high, wave gently in the breeze.%^RESET%^";
    break;
  case "harvestdays":
    corndesc = "%^GREEN%^The maize is almost fully grown; the plants stand at five feet or taller, the"
              +" %^BOLD%^%^YELLOW%^yellow ears%^RESET%^%^GREEN%^ unmistakeable against the dark green"
              +" leaves.%^RESET%^";
    break;
  case "autumnstime":
    corndesc = "%^GREEN%^The m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e plants are"
              +" fully grown and workers are have already begun harvesting them";
    break;
  case "colddays":
    corndesc = "%^BOLD%^%^WHITE%^It is the cold season and no crop grows here now.%^RESET%^";
    break;
  }
  return corndesc;
}

string long_corndesc(){
  string corndesc;
  switch (lower_case(month(time()))){
  case "winterstime":
    corndesc = "The %^ORANGE%^ground%^RESET%^ lays bare, without crops, as the %^BOLD%^"
              +"%^WHITE%^winter's ch%^CYAN%^i%^WHITE%^ll%^RESET%^ still touches the %^BOLD%^"
              +"%^CYAN%^air%^RESET%^. There are signs of preparations for the next season's %^BOLD%^"
              +"%^YELLOW%^crop%^RESET%^, though. The %^ORANGE%^soil%^RESET%^ has been dug over, and"
              +" small basins prepared ready for the sewing of fresh %^BOLD%^%^YELLOW%^c%^RESET%^"
              +"%^ORANGE%^o%^BOLD%^%^YELLOW%^rn c%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^rcles"
              +"%^RESET%^.";
    break;
  case "renewal":
    corndesc = "Circles of tiny %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
              +" %^RESET%^seedlings have been planted through the field. Most are only a few inches"
              +" high, and they are sown six to eight inches apart, in spirals and concentric circles."
              +" In between the stands of %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^"
              +"%^GREEN%^e %^RESET%^, small crops of %^ORANGE%^bl%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^ck e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^ed pe%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^s%^RESET%^ and %^ORANGE%^squash%^RESET%^ are also growing.";
    break;
  case "springstime":
    corndesc = "Circular stands of sturdy %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^"
              +"%^GREEN%^e%^RESET%^ plants, three to four feet high occupy most of the field. They"
              +" are sown six to eight inches apart, in spirals and concentric circles."
              +" In between the stands of %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^"
              +"%^GREEN%^e, small crops of %^ORANGE%^bl%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^ck e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^ed pe%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^s%^RESET%^ and %^ORANGE%^squash%^RESET%^ are also growing.";
    break;
  case "plantingdays":   
    corndesc = "%^GREEN%^The maize is almost fully grown; the plants stand at five feet or taller, the"
              +" %^BOLD%^%^YELLOW%^yellow ears%^RESET%^%^GREEN%^ unmistakeable against the dark green"
              +" leaves. In between the circular stands of %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^"
              +"%^YELLOW%^z%^RESET%^%^GREEN%^e, small crops of %^ORANGE%^bl%^BOLD%^"
              +"%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^ck e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^ed pe%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^s%^RESET%^%^GREEN%^ and %^ORANGE%^squash%^RESET%^%^GREEN%^ are also growing.";

    break;
  case "sundays":
    corndesc = "%^GREEN%^The m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e plants are"
              +" fully grown and workers are have already begun harvesting them.%^RESET%^";
    break;
  case "summerstime":
    corndesc ="Circles of tiny %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
              +" %^RESET%^seedlings have been planted through the field. Most are only a few inches"
              +" high, and they are sown six to eight inches apart, in spirals and concentric circles."
              +" In between the stands of %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^"
              +"%^GREEN%^e %^RESET%^, small crops of %^ORANGE%^bl%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^ck e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^ed pe%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^s%^RESET%^ and %^ORANGE%^squash%^RESET%^ are also growing.";
    break;
  case "growingdays":
    corndesc = "Circular stands of sturdy %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^"
              +"%^GREEN%^e%^RESET%^ plants, three to four feet high occupy most of the field. They"
              +" are sown six to eight inches apart, in spirals and concentric circles."
              +" In between the stands of %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^"
              +"%^GREEN%^e%^RESET%^, small crops of %^ORANGE%^bl%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^ck e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^ed pe%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^s%^RESET%^ and %^ORANGE%^squash%^RESET%^ are also growing.";
    break;
  case "harvestdays":
    corndesc = "%^GREEN%^The maize is almost fully grown; the plants stand at five feet or taller, the"
              +" %^BOLD%^%^YELLOW%^yellow ears%^RESET%^%^GREEN%^ unmistakeable against the dark green"
              +" leaves. In between the circular stands of %^GREEN%^m%^ORANGE%^a%^GREEN%^i%^BOLD%^"
              +"%^YELLOW%^z%^RESET%^%^GREEN%^e%^RESET%^%^GREEN%^, small crops of %^ORANGE%^bl%^BOLD%^"
              +"%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^ck e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^ed pe%^BOLD%^%^BLACK%^a%^RESET%^"
              +"%^ORANGE%^s%^RESET%^%^GREEN%^ and %^ORANGE%^squash%^RESET%^%^GREEN%^ are also growing.";
    break;
  case "autumnstime":
    corndesc = "%^GREEN%^The m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e plants are"
              +" fully grown and workers are have already begun harvesting them";
    break;
  case "colddays":
    corndesc = "The %^ORANGE%^ground%^RESET%^ lays bare, without crops, as the %^BOLD%^"
              +"%^WHITE%^winter's ch%^CYAN%^i%^WHITE%^ll%^RESET%^ touches the %^BOLD%^"
              +"%^CYAN%^air%^RESET%^.";
    break;
  }
  return corndesc;
}

string pit_desc(){
  switch (pitted){
  case CLEAR:
    return "";
    break;
  case PITS:
    return "%^RESET%^Defensive pits have been dug in the field. These would make it more difficult to"
          +" charge the walls of the %^ORANGE%^stockade%^RESET%^ from here.\n";
    break;
  case COVERED_PITS:
    return "";
    break;
  case STAKED_PITS:
    return "%^RESET%^Defensive pits have been dug in the field, with vicious looking stakes planted at"
          +" the bottom of them. These would make it difficult and dangerous to charge the walls of"
          +" the %^ORANGE%^stockade%^RESET%^ from here.";
    break;
  case COVERED_STAKED_PITS:
    return "";
    break;
  }
}

string stake_desc(){
  switch (staked){
  case 1:
    return "%^RESET%^Rows of %^ORANGE%^sharpened stakes%^RESET%^ have been set up in defensive lines"
       +" in the field, to break up any charge against the walls of the %^ORANGE%^stockade%^RESET%^";
  default:
    switch (stake_prog){
    case 0:
      return "";
    case 1..100:
      return "%^RESET%^A few %^ORANGE%^sharpened stakes%^RESET%^ have been set up in defensive lines"
            +" in the field. Too few to make any difference to anything, though.";
    case 101..200:
      return "%^RESET%^Some %^ORANGE%^sharpened stakes%^RESET%^ have been set up in defensive lines"
            +" in the field. There are many gaps in the defenses, though.";
    default:
      return "%^RESET%^Lots of %^ORANGE%^sharpened stakes%^RESET%^ have been set up in defensive lines"
            +" in the field. There are still some gaps in the defenses, though.";
    }
  }
}
