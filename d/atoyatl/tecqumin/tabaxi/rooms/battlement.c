#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

string query_ladders();

object field;
string field_name;

void create() {
  ::create();
  set_property("indoors", 0);
  set_travel(FOOT_PATH );
  set_terrain(WOOD_BUILDING);
  set_long( (: TO, "long_desc" :) );
}

void init(){
  ::init();
  add_action("target_em", "target");
  add_action("peek", "peek");
  add_action("view", "view");
  add_action("push_em", "push");
  add_action("push_em", "shove");
  add_action("push_em", "dislodge");
  add_action("push_em", "topple");
  add_action("kick_em", "kick");
  set_had_players(3);
  set_items(([  ({"battlement", "battlements"}): (: TO, "batt_desc" :) ,
                ({"field", "fields", "down", "downwards", "high field", "low field", "main field"}) : (:TO, "field_desc" :) , 
                ({"ladder", "ladders"}) : (:TO, "ladd_desc" :)  ]));
}

object query_field(){
  return field;
}

int query_unreachable(){
  return 1;
}

void set_field(object f){
  field = f;
}

string ladd_desc(){
  object ladder;
  string ladders, result;
  ladder = present("ladder", field);
  if (!objectp(ladder)) return "There aren't any ladders here";
  ladders = query_ladders();
  result = "" + ladders; 
  if (ladders == "a ladder") result +=" peeks above the battlement."; //blah
  else result += " peek above the battlement.";
  result += " You could try to <dislodge> one if you wish";
  return result;
}


void reset_field(){  
  field = find_object_or_load(field_name);
}

void clean_up(){
  string f = field_name;
  ::clean_up();
  field_name = f;
  field = find_object_or_load("field_name");
}

string batt_desc(){
  string desc;
  if (!objectp(field)){
    field = find_object_or_load(field_name);
  }
  if (!objectp(field)){
    return "The crennellated battlements provide a good defensive vantage point"
          +" for archers. Unfortunately, there is an error with the room below."
          +" Please make a bug report, stating that Lujke is an idiot, and that"
          +" someone should take a look at the base battlement file.";
  }
  desc = "The crennellated wooden battlement provides a good defensive vantage"
        +" point for archers, with a view of the %^ORANGE%^";
  desc +=  (string)field->query_name() + "%^RESET%^";
  desc += " below. If you have a ranged weapon, you could%^BOLD%^%^YELLOW%^ "
         +"<target>%^RESET%^ enemies who arrive there";
  return desc;
}

string field_desc(){
  string desc;
  if (!objectp(field)){
    field = find_object_or_load(field_name);
  }
  if (!objectp(field)){
    return "Unfortunately, there is an error with the room below."
          +" Please make a bug report, stating that Lujke is an idiot, and that"
          +" someone should take a look at the base battlement file.";
  }
  desc = capitalize(field->query_name());
  tell_object(TP, "%^ORANGE%^You peer over the battlement. Below, you can see:%^RESET%^");
  tell_object(TP, desc);
  TO->add_exit(field_name, "downwards");
  TP->force_me("peer downwards 1");
  TO->remove_exit("downwards");
  return "";
}

string long_desc(){
  string desc, * exits, room, * down_exits, new_exits;
  int i;
  desc = "You are on the battlement, above the main gate of the stockade. You can see over to the"
          +" main field outside from here. If you wanted, you could target enemies in the field"
          +", with a missile weapon.";
  exits = TO->query_exits();
  if (member_array("down", exits) != -1){
    desc +=  " There are some steps leading down into the stockade here.";
  } else {
    down_exits = ({});
    if (sizeof(exits)>0){
      for (i=0;i<sizeof(exits);i++){
        room = find_object_or_load(query_exit(exits[i]));
        if (objectp(room)){
          new_exits = room->query_exits();
          if (member_array("down", new_exits) != -1){
            down_exits += ({exits[i]});
          }
        }
      }
    }
    desc += " There doesn't appear to be an easy way down from here.";
    switch (sizeof(down_exits)){
    case 0:
      desc += ".";
      break;
    case 1:
      desc += ", but you can see steps leading down to the stockade to the " + down_exits[0] + ".";
      break;
    case 2:
      desc += ", but you can see steps leading down to the stockade to the " + down_exits[0] 
             +" and " + down_exits[1] + ".";
      break;
    } 
  }
  if (query_ladders() == ""){
    return desc;
  }
  desc += " The top";
  if (query_ladders() != "a ladder"){
    desc += "s";
  }
  desc += " of " + query_ladders() + " poke";
  if (query_ladders() == "a ladder"){
    desc += "s";
  }
  desc += " up over the battlements.";
  return desc;
}

string query_ladders(){
  object * ladders, * removals;
  int i;
  if (!objectp(field) && stringp(field_name)){
    field = find_object_or_load(field_name);
  }
  if (!objectp(field)){
    return "";
  }
  ladders = all_inventory(field);
  if (sizeof(ladders)<1){
    return "";
  }
  removals = ({});
  for (i=sizeof(ladders)-1;i>-1;i--){
    if (!ladders[i]->id("ladder")){
      removals += ({ladders[i]});
      continue;
    }
    if ((string)ladders[i]->query_raised_loc() != file_name(field)){
      removals += ({ladders[i]});
    }
  }
  if (sizeof(removals)>0){
    ladders -= removals;
  }
  i = sizeof(ladders);
  switch(i){
  case 0:
    return "";
    break;
  case 1:
    return "a ladder";
    break;
  case 2:
    return "two ladders";
    break;
  case 3:
    return "three ladders";
    break;
  default:
    return "several ladders";
    break;
  } 
}

int target_em(string str){
  object targetter, * targetters, *wielded;
  int i, flag;
  string where, what;
  if (!stringp(str)){
    tell_object(TP, "Try %^BOLD%^%^YELLOW%^'target <what> in field'");
    return 1;
  }
  sscanf(str, "%s in %s", what, where);
  if (where != "field"){
    tell_object(TP, "Try %^BOLD%^%^YELLOW%^'target <what> in field'");
    return 1;
  }
  wielded = TP->query_wielded();
  if (sizeof(wielded)<1){
    tell_object(TP, "You'll need to be wielding something to shoot them with");
    return 1;
  }
  flag = 0;
  for (i=0;i<sizeof(wielded);i++){
    if (wielded[i]->id("bow")||wielded[i]->id("sling")){
       flag = 1;
       break;
    }
  }
  if (flag ==0){
    tell_object(TP, "You'll need to be wielding something to shoot them with");
    return 1;   
  }
  tell_object(TP, "You take up a firing position, ready to fire on any " + what + "s who wander into"
             +" the field below");
  tell_room(TO, TPQCN + "%^RESET%^ takes up a firing position at the battlement", TP);
  TP->force_me("pose positioned by the battlement, taking aim on targets in the field below");
  targetters = children(TABAXOBJ + "targeter");
  if (sizeof(targetters)>0){
    for (i=0;i<sizeof(targetters);i++){
      if ((object)targetters[i]->query_who() == TP){
        targetters[i]->remove();
      }
    }
  }
  targetter = new(TABAXOBJ + "targeter");
  targetter->set_who(TP);
  targetter->set_targ(what);
  targetter->set_here(TO);
  targetter->move(TO);
  targetter->set_targ_loc(field);   
  return 1;
}


int peek(string str){
  if (!objectp(field)){
    tell_object(TP, "There seems to be a problem with the field you are trying to peek into. You can"
                    +" probably blame Lujke for that, so please tell him, or another wiz, or better"
                    +" yet make a bug report. Thanks!");
    return 1;
  }
  tell_object(TP, "%^BOLD%^%^BLUE%^You take a peek over the battlement:");
  tell_room(TO, TPQCN + "%^RESET%^ takes a peek over the battlement.");
  TP->move(field);
  TP->force_me("look");
  TP->move(TO);
  return 1;
}

int view(string str){
  object * critters, * climbers, critter, * stuff;
  int i, where, j, pos, k,l, flag;
  string result, laddername;
  flag = 0;
  if (str != "wall" && str != "walls" && str != "fence"){
    tell_object(TP, "You could probably %^BOLD%^%^YELLOW%^<view fence>%^RESET%^ to see who's climbing" 
                    +" up it");
  }
  if (!objectp(field)&& stringp(field_name)){
    field = find_object_or_load(field_name);
  }
  if (!objectp(field)){
    tell_object(TP, "There seems to be a problem with the field you are trying to peek into. You can"
                    +" probably blame Lujke for that, so please tell him, or another wiz, or better"
                    +" yet make a bug report. Thanks!");
    return 1;
  }
  critters = all_living(field);
  climbers = ({});
  if (sizeof(critters)<1){
    tell_object(TP, "You can't see anyone in the field at all");
    return 1;
  }
  for (i=0;i<sizeof(critters);i++){
    critter = critters[i];
    where = field->query_climb_position(critter);
    if (where > 0){
      climbers += ({critter});
      flag = 1;
    }
  }
  result = "%^BLUE%^On the %^ORANGE%^wall%^BLUE%^, you can make out:\n";
  for (i=0;i<sizeof(climbers);i++){
    critter = climbers[i];
    where = field->query_climb_position(critter);
    result += "%^CYAN%^" +(string)critter->QCN + "%^RESET%^%^CYAN%^, "+(string)field->how_high(where) 
            + "\n";
  }
  stuff = all_inventory(field);
  if (sizeof(stuff)>0){
    for (i=0;i<sizeof(stuff);i++){
      if (stuff[i]->id("ladder") && (string)stuff[i]->query_raised_loc() == file_name(field)){
        l =1;
        for (k=0;k<sizeof(stuff);k++){
          laddername = "ladder " + (l);
          if (stuff[i] == present(laddername, field)){
            result += "\n%^ORANGE%^Ladder " + l + ", with";
            l++;
          }
        } //        result += "\n%^ORANGE%^A ladder with%^RESET%^";
        climbers = keys((mapping)stuff[i]->query_climb_positions());
        if (sizeof(climbers)>0){
          flag = 1;
          for(j=0;j<sizeof(climbers);j++){
            result += "\n   " + (string)climbers[j]->QCN + " ";
            pos = (int)stuff[i]->query_climb_position(climbers[j]);
            result += (string)field->how_high(pos);
          }
        } else {
          result += "%^ORANGE%^ no-one climbing it%^RESET%^";
        }
      }
    }
  }
  if (flag < 1){
    tell_object(TP, "You can't see anyone climbing the fence");
    return 1;
  }
  tell_object(TP, result);
}

void topple (object ladder){
  object watchtower, *fallers, faller;
  mapping climb_pos;
  int i, dam;
  reset_field();
  if (!objectp(ladder) || !objectp(field) || !present(ladder, field)){
    tell_room(TO, "Something has gone wrong with the ladder toppling. Please tell a wiz, or make a"
                   +" bug report, or bug a draconian");
    return;
  }
  tell_room(field, "Somone on the battlement manages to topple a seige ladder, with everyone on it!");
  watchtower = find_object_or_load(TABAXROOM + "watchtower");
  if (objectp(watchtower)){
    tell_room(watchtower, "Somone on the battlement manages to topple a seige ladder, with everyone on"
                    +" it!");
  }
  ladder->set_raised_loc("");
  climb_pos = ladder->query_climb_positions();
  fallers = keys(climb_pos);
  if (sizeof(fallers)<1){
    return;
  }
  for (i=0;i<sizeof(fallers);i++){
    faller = fallers[i];
    dam = 20 * climb_pos[faller];
    tell_object(faller, "You fall to the ground!");
    tell_room(field, (string)faller->QCN + " falls to the ground!");
    faller->do_damage(faller->return_target_limb(),dam);
    faller->add_attacker(TO);
    faller->continue_attack();
    ladder->remove_climber(faller);
    faller->force_me("pose clear");
    faller->remove_property("busy");
    faller->remove_property("climbing");
  }
}

int push_em(string str){
  string what, withwhat, verb, type, raised_loc, orig_what;
  int scancount, push_str, num;
  object ladder, pole;
  reset_field();
  verb = query_verb();
  if (!stringp(str)){
    tell_object(TP, verb + " what?");
    return 1;
  }
  scancount = sscanf(str, "%s with %s", what, withwhat);
  if (scancount<1){
    if (stringp(str) && strlen(str)>0){
      scancount = 1;
      what = str;
    }
  }
  push_str = 0;
  switch(scancount){
  case 0:
    tell_object(TP, verb + " what?");
    return 1;
    break;
  case 2:
    pole = present(withwhat, TP);
    type = "wrong";
    if (objectp(pole)){
      if (pole->id("polearm")){
        type = "polearm";
      }
      if (pole->id("staff")){
        type = "staff";
      }
      if (pole->id("pole")){
        type = "pole";
      }
      switch(type){
      case "pole":
        push_str += 12;
        break;
      case "staff":
        push_str += 10;
        break;
      case "polearm":
        push_str += 8;
        break;
      case "wrong":
        if (objectp(pole)){
          tell_object(TP, "That " + withwhat + " wouldn't be much use for doing that with.");
          return 1;
        } else {
          tell_object(TP, "You don't have a " + withwhat + ".");
          return 1;
        }
      }
    }
    break;
  case 1:
    if (!interact("ladder", what)){
      notify_fail("You could try to %^BOLD%^%^YELLOW%^'" + verb + " ladder <number>'%^RESET%^");
      return 0;
    }
    if (present("pole", TP)){ 
      tell_object(TP, "You could use the pole to do that, you know. it'd be easier");
    } else{ 
      if (present("staff", TP)){ 
        tell_object(TP, "You could use your staff to do that, you know. it'd be easier");
      } else {
        if (present("polearm", TP)){ 
          tell_object(TP, "You could use your polearm to do that, you know. it'd be easier");
        }
      }
    }
    TP->set_paralyzed(5 + random(5), "You are recovering from your attempt to topple the ladder");
  }
  push_str += TP->query_stats("strength");
  ladder = present(what, field);
  if (!objectp(ladder)){
    tell_object(TP, "There is no " + what + " in the field");
    return 1;
  }
  raised_loc = (string)ladder->query_raised_loc();
  sscanf(what, "ladder %d", num);
  orig_what = what;
  while (raised_loc != field_name && num <20){
    num ++;
    what = "ladder " + num;
    ladder = present(what, field);
  }
  if (!objectp(ladder)){
    tell_object(TP, "There is no " + orig_what + " raised in the field");
    return 1;
  }
  if (18+random(40)<push_str){
    if (objectp(pole)){
      tell_object(TP, "You use the pole to push the ladder away from the battlement. It topples to the"
                     +" ground with everyone on it.");
      tell_room(TO, TPQCN + " uses a pole to push the ladder away from the battlement. It topples to"
                   +" the ground with everyone on it.", TP);
      return 1;
    } else {
      tell_object(TP, "You " + verb + " the ladder from the battlement. It topples to the"
                     +" ground with everyone on it.");
      tell_room(TO, TPQCN + " " + verb +"es the ladder from the battlement. It topples to"
                   +" the ground with everyone on it.", TP);
    }
    topple(ladder);
    return 1;
  } else {
    tell_object(TP, "You try to heave " + what + " aside, but you can't shift it.");
    tell_room(TO, TPQCN + " tries to heave " + what + " aside, but doesn't manage to shift it.", TP);
    return 1;
  }
}
