//Coded by Lujke

#include <std.h>
#include "../tecqumin.h"
#define IGNORED_ROOMS ({"rightbank", "leftbank", "battlement",\
                        "high_field", "low_field", "main_field"})

inherit OBJ + "head.c";

string last_room_checked;

void create() {
    ::create();
  last_room_checked = "none";
}

void init(){
  ::init();
  add_action("ask_me", "ask");
}

void pre_exit_fun(){
  call_out("check_exits", 2);
  return 0;
}

int ask_me(string str){
  if (!objectp(ETO) ||TP != ETO){
    return 0;
  }
  if (!id(str) && str != "the head"){
    return notify_fail("Do you want to ask the head?");
  }
  tell_object(TP, "You ask " + nm + " what " + GP + " senses find here");
  if (objectp(EETO)){
    tell_room (EETO, TPQCN + "bends down and appears to whisper"
      +" something to a small object that " + TP->QS + " holds", TP);
  }
  if (last_room_checked == base_name(EETO)){
    tell_object(TP, "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers, "
      +"'%^BOLD%^%^WHITE%^I have already checked this"
      +" place.%^RESET%^%^CYAN%^'");
    return 1;
  }
  if (check_exits()<1){
    tell_object(TP, "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers, "
      +"'%^BOLD%^%^WHITE%^I can detect nothing here.%^RESET%^%^CYAN%^'");
  }
  return 1;
}

int check_exits(){
  string * exits, *hidden_exits, list, preamble, * climb_directions,* buried_exits, filename, ignorable;
  int i, count, res;
  mapping climb_exits;
  if (!objectp(ETO) || !interactive(ETO)|| !objectp(EETO)){
    return 0;
  }
  filename = file_name(EETO);
  foreach(ignorable in IGNORED_ROOMS)
  {
    if(interact(ignorable, filename)) return 1;
  }
  if (base_name(EETO) == last_room_checked){
    return 0;
  }
  // LIST HIDDEN EXITS
  exits = EETO->query_exits();
  count = sizeof(exits);
  if (count<1){
    return 0;
  }
  hidden_exits = ({});
//  tell_room(EETO, "Checking exits");
//  tell_room(EETO, "Checking " + count + " exits");
  for (i=0;i<count;i++){
    if (EETO->invis_exit(exits[i])){
//      tell_room(EETO, exits[i] + " is an invisible exit");
      hidden_exits += ({exits[i]});
    }
  }
  count = sizeof(hidden_exits);
  res = count;
//  tell_room(EETO, "" + count  + " invisible exit found");
  if (count > 0){
    list = "";
    preamble =  "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers,"
      +" %^BOLD%^%^WHITE%^'There is a hidden exit here: %^RESET%^";
    for (i=0;i<count;i++){
      if (i==1){
        preamble = "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers,"
      +" %^BOLD%^%^WHITE%^'There are hidden exits here: %^RESET%^";
      }
      list += hidden_exits[i];
      if (i<count-1){
        list += ", ";
      }
      if (i == count -1 && i>0 ){
        list += " and ";
      }
    }
    res += count;
    tell_object(ETO, preamble + list + "%^BOLD%^%^WHITE%^'");
  }
  // LIST CLIMB EXITS
  climb_exits = EETO->query_climb_exits();
  count = 0;
  if (sizeof(climb_exits)) {
      climb_directions = keys(climb_exits);
      count = sizeof(climb_directions);
  }
  if (count > 0){

    list = "";
    preamble =  "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers,"
      +" %^BOLD%^%^WHITE%^'You can %^RESET%^";
    for (i=0;i<count;i++){
      if (i==1){
        preamble =  "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers,"
          +" %^BOLD%^%^WHITE%^'You can %^RESET%^";
      }
      list += climb_directions[i];
      if (i<count-1){
        list += ", ";
      }
      if (i == count -1 && i>0 ){
        list += " or ";
      }
    }

    tell_object(ETO, preamble + list + "%^BOLD%^%^WHITE%^ here.'");
  }
  //LIST BURIED EXITS
  buried_exits = keys(EETO->query_orig_exits());
  count = sizeof(buried_exits);
  if (count>0){
    list = "";
    preamble =  "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers,"
      +" %^BOLD%^%^WHITE%^'There is a buried exit here, leading %^RESET%^";
    for (i=0;i<count;i++){
      if (i==1){
        preamble =  "%^RESET%^" + nm +" %^RESET%^%^CYAN%^whispers,"
          +" %^BOLD%^%^WHITE%^'There are buried exits here, leading %^RESET%^";
      }
      list += buried_exits[i];
      if (i<count-1){
        list += ", ";
      }
      if (i == count -1 && i>0 ){
        list += " and ";
      }
    }
    tell_object(ETO, preamble + list + "%^BOLD%^%^WHITE%^.'");
  }

  last_room_checked = base_name(EETO);
  return res;
}
