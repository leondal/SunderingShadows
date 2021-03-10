#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"
#define SAFE 0
#define SEVERED 1
#define TAMPERED 2

inherit ROOM;
int vine_condition;

string long_desc();

void create() {
  string room_num, filename;
  ::create();
  vine_condition = SAFE;
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("Up in a tree");
  set_short("%^GREEN%^Up in a tree%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"clearing", "jungle clearing"}): "You can see a clearing"
          +" in the jungle nearby, with a massive higureon tree in the"
          +" centre of it.",
               ({"tree", "higureon tree"}) : "The tree is absolutely huge,"
          +" and you can see a wooden platform encircling the trunk at a"
          +" height of about thirty feet",
                ({"platform", "wooden platform"}):  "The platform"
          +" encircling the trunk of the higureon tree is approximately at"
          +" the same height as you are at the moment",
               ({"vine", "vines"}):(:TO, "vine_desc":),
               ({"loose vine", "loose vines"}):"Several of the vines are"
          +" within reach. You could probably swing on them if you wanted"
          +" to" ]) );
  set_search("","");
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds.");
  filename = file_name(TO);
  room_num = filename[strlen(filename)-2..strlen(filename)-1];
  set_climb_exits(([
    "descend":({TREEHOUSE + "/rooms/" + "treetop_base" + room_num,2,0, 30}),
  ]));

}
void init() {
   ::init();
   add_action("swing", "swing");
   add_action("cut_vine", "cut");
   add_action("cut_vine", "slash");
   add_action("cut_vine", "hack");
   add_action("cut_vine", "saw");
   add_action("cut_vine", "slice");
   add_action("cut_vine", "cleave");
   add_action("cut_vine", "hew");
   add_action("cut_vine", "prune");
   add_action("cut_vine", "slash");
   add_action("sever", "tamper");
   add_action("sever", "sever");
}

string long_desc(){
  string desc;
  desc =  "%^GREEN%^You are high in the branches of a vine-tangled tree,"
         +" overlooking a clearing in the %^BOLD%^%^GREEN%^j%^RESET%^"
         +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
         +"%^GREEN%^e%^RESET%^%^GREEN%^.";
  return desc;
}

string vine_desc(){
  switch(vine_condition){
  case SAFE:
    return "There are a number of loose vines"
          +" hanging from the branches above you, in addition to the"
          +" general tangle of vines around the trunk and limbs of the"
          +" tree";
  case TAMPERED:  
    return "There are a number of loose vines"
          +" hanging from the branches above you, in addition to the"
          +" general tangle of vines around the trunk and limbs of the"
          +" tree. They look like they might have been tampered with";
  case SEVERED:
    return "All the loose vines in reach have been severed, only the"
          +" stumpy ends remaining.";
  }
}

int sever(string str){
  string verb, wpn_type;
  object * things;
  int i, flag;
  verb = query_verb();
  flag = 0;
  if (str != "vine"){
    tell_object(TP, "What are you trying to " + verb + "?");  
    return 1;
  }
  things = TP->query_wielded();
  if (sizeof(things)>0){
    for(i=0;i<sizeof(things);i++){
      wpn_type = things[i]->query_prof_type();
//      tell_object(TP, "Your " + things[i]->query_short() 
//                + " has the prof type " + things[i]->query_prof_type());
      if (interact("blade", wpn_type)||interact("axe", wpn_type)
         ||wpn_type =="scythe"||wpn_type == "tool"||wpn_type == "polearm"){
        flag = 1;
        break;
      }

    }
  }
  if (flag ==0){
    tell_object(TP, "You need to be wielding some sort of blade, in"
                   +" order to cut things");
    return 1;
  }
  if (vine_condition == SEVERED){
    tell_object(TP, "All the vines you might have been able to reach have"
                   +" already been cut.");
    return 1;
  }
  switch(verb){
  case "sever":
    tell_object(TP, "Working swiftly, you sever all the vines within"
                   +" reach");
    tell_room(TO, "Working swiftly, "+ TPQCN + " severs all the vines"
                 +" within reach", TP);
    vine_condition = SEVERED;
    break;
  case "tamper":
    tell_object(TP, "Working swiftly, you cut part way through each of the"
                   +" vines within reach");
    tell_room(TO, "Working swiftly, "+ TPQCN + " cuts part way through"
                 +" each of the vines within reach", TP);
    vine_condition = TAMPERED;
    break;
  }
  return 1;
}

int cut_vine(string str){
  string verb;
  verb = query_verb();
  if (str != "vine" && str != "vines"){
    tell_object(TP, "What are you trying to " + verb + "?");  
    return 1;
  }
  tell_object(TP, "Did you want to %^BOLD%^%^YELLOW%^sever%^RESET%^ the"
                 +" vines, or just %^BOLD%^%^YELLOW%^tamper%^RESET%^ with"
                 +" them?");
  return 1;
}

int swing(string str){
  int i, hp;
  object base_room, target_room;
  string base_room_name, target_room_name, direction, reverse,* exits, room_num, where;
  base_room_name = TO->query_climb_exit("descend");
  base_room = find_object_or_load(base_room_name);
  if (!objectp(base_room)){
    tell_object(TP, "Error with the room below you. Please tell a wiz");
    return 1;
  }
  if (!stringp(str) ||sscanf(str, "to %s", where)<1){
    tell_object(TP, "Where do you want to swing to?");
    return 1;
  }
  exits = base_room->query_exits();
  if (where == "platform"){
    if (sizeof(exits)>0){
      for (i=0;i<sizeof(exits);i++){
        if ((string)base_room->query_exits(exits[i])
                                == TREEHOUSE + "/rooms/" + "t_house_base"){
          direction = exits[i];
          break;
        }
      }
    }
    room_num = file_name(base_room);
    room_num = room_num[strlen(room_num)-1..strlen(room_num)-1];
    target_room_name = TREEHOUSE + "/rooms/" + "platform0" + room_num;
    target_room = find_object_or_load(target_room_name);
  } else {
    if (member_array(where, exits)!=-1){
      direction = where;
    } else{
      tell_object(TP, "You can't swing that way. Too many trees in the way"
                     +" in this damn jungle.");
      return 1;
    }
    target_room_name = base_room->query_exit(direction);
    target_room = find_object_or_load(target_room_name);
  }
  switch(direction){
  case "north":
    reverse = "south";
    break;
  case "northeast":
    reverse = "southwest";
    break;
  case "east":
    reverse = "west";
    break;
  case "southeast":
    reverse = "northwest";
    break;
  case "south":
    reverse = "north";
    break;
  case "southwest":
    reverse = "northeast";
    break;
  case "west":
    reverse = "east";
    break;
  case "northwest":
    reverse = "southeast";
    break;
  default:
    reverse = "plane between this reality and the next";
  }
  if (!objectp(target_room)){
    tell_object(TP, "Error finding where you were going to swing to the " 
          + where + ". It appears you were trying to swing to " + target_room_name + " Please tell a Wiz.");
    return 1;
  }
  switch (vine_condition){
  case SAFE:
    tell_object(TP, "%^GREEN%^You grab a vine and swing to the " + where);
    tell_room(TO, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ grabs a vine"
                 +" and swings to the " + where, TP);
    tell_room(target_room,"%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ swings"
                         +" in on a jungle vine from the " + reverse, TP);
    tell_object(TP, "You manage not to fall off the vine as you arrive!");
    TP->move_player(target_room);
    return 1;
    break;
  case SEVERED:
    tell_object(TP, "You can't find any vines to swing on");
    return 1;
    break;
  case TAMPERED:
    tell_object(TP, "%^GREEN%^You grab a vine and swing to the " + where);
    tell_room(TO, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ grabs a vine"
                 +" and swings to the " + where, TP);
    tell_room(target_room,"%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ swings"
                         +" in on a jungle vine from the " + reverse, TP);
    tell_object(TP, "%^BOLD%^%^GREEN%^The vine %^CYAN%^snaps%^GREEN%^ and"
                   +" you %^CYAN%^crash%^GREEN%^ to the jungle floor!");
    tell_room(target_room, "%^BOLD%^%^GREEN%^The vine %^CYAN%^snaps"
                +"%^GREEN%^, and "
                + TPQCN + "%^BOLD%^%^GREEN%^ %^CYAN%^crashes%^GREEN%^ to"
                +" the jungle floor.", TP);
    tell_room(TO, "%^BOLD%^%^GREEN%^The vine %^CYAN%^snaps"
                +"%^GREEN%^, and "
                + TPQCN + "%^BOLD%^%^GREEN%^ %^CYAN%^crashes%^GREEN%^ to"
                +" the jungle floor.", TP);
    if (interactive(TP)||random(2)){
      hp = TP->query_max_hp();
      TP->do_damage(TP->return_target_limb(),random(hp/2));
      TP->add_attacker(TO);
      TP->continue_attack();
      if(objectp(TP)){  TP->remove_attacker(TO);}
    }else{
      tell_room(TO, TPQCN + " looks like " + TP->QO + " snapped " + TP->QP
                   +" neck.");
      tell_room(target_room, TPQCN + " looks like " + TP->QO + " snapped "
                   + TP->QP +" neck.");
      TP->die();
    }
    
  }
}