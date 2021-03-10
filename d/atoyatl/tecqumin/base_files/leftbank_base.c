#include <std.h>
#include <daemons.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  add_item(({"canyon", "jungle_canyon"}), "The %^ORANGE%^canyon%^RESET%^ is"
    +" deep and wide, and a %^BOLD%^%^BLUE%^river%^RESET%^ flows through at"
    +" the bottom. There's no visible way down.");
  set_pre_exit_functions(({"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest"}), ({"GoNorth", "GoNortheast", "GoEast", "GoSoutheast", "GoSouth", "GoSouthwest", "GoWest", "GoNorthwest"}));
}

void on_enter(){
  set_basic_exits();
  update_exits();
}

string short_desc(){
  update_exits();
  return ::short_desc();
}

int isBlocked(string dir){
  string * blocked;
  blocked = query_blocked_exits();
  if (sizeof(blocked)>0 && member_array(dir, blocked)!=-1){
    return 1;
  }
  return 0;
}



int GoNorth(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going north");
  if (isBlocked("north")){
    if(TP->query_property("flying")){
      if (EVENTS_D->completed_event(TP->query_name(), "Crossed the rope bridge", 900000000)<1){
        tell_object(TP, "The %^BOLD%^%^WHITE%^winds%^RESET%^ blowing through the"
          +" %^ORANGE%^canyon%^RESET%^ seem more than natural. You sense that"
          +" attempting to fly across would be unwise for anyone unknown to the"
          +" %^CYAN%^spirits%^RESET%^ of this part of the %^BOLD%^%^GREEN%^j"
          +"%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e");
        return 0;
      }
      loc = query_location(get_name());
      dest_loc = loc + 1000;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoNorth();
}

int GoNortheast(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going northeast");
  if (isBlocked("northeast")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_loc = loc + 1001;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoNortheast();
}

int GoEast(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going east");
  if (isBlocked("east")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_loc = loc + 1;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoEast();
}

int GoSoutheast(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going southeast");
  if (isBlocked("southeast")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_loc = loc - 999;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoSoutheast();
}

int GoSouth(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going south");
  if (isBlocked("south")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_loc = loc - 1000;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoSouth();
}


int GoSouthwest(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going southwest");
  if (isBlocked("southwest")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_name = get_rightbank_name();
      dest_loc = MAZE_D->query_location(get_rightbank_path(), dest_name);
      if (dest_loc == -1){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoSouthwest();
}

int GoWest(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going west");
  if (isBlocked("southwest")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_loc = loc -1;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoWest();
}

int GoNorthwest(){
  int loc, dest_loc, *locs;
  object dest_room;
  mapping locations;
  string dest_name;
  report("Going northwest");
  if (isBlocked("northwest")){
    if(TP->query_property("flying")){
      loc = query_location(get_name());
      dest_loc = loc + 999;
      dest_name = MAZE_D->query_room(get_path(), dest_loc);
      if (dest_name == "none"){
        tell_object(TP, "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^e%^RESET%^ is too dense on the other side of the"
          +" %^ORANGE%^canyon%^RESET%^ for you to fly across");
        return 0;
      } else {
        tell_object(TP, "You %^BOLD%^%^CYAN%^fly%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side");
        tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ across the %^ORANGE%^canyon%^RESET%^ to the other side", TP);
        if (file_exists(get_path() + dest_name)){
          dest_room = find_object_or_load(get_path() + dest_name);
          if (objectp(dest_room)){
            tell_room(dest_room, TPQCN + " %^BOLD%^%^CYAN%^flies%^RESET%^ in from the other side of the %^ORANGE%^canyon%^RESET%^.");
            TP->move(dest_room);
            return 1;
          }
        }  
      }
    } else {
      tell_object(TP, "The canyon is in your way. You can't get across");
      return 0;
    }
  }
  return ::GoNorthwest();
}


string get_rightbank_path(){
  switch(get_path()){
  case JUNG_ROOM9:
    return JUNG_ROOM5;
  case JUNG_ROOM10:
    return CITY;
  }
}

string get_rightbank_name(){
  int y;
  y = MAZE_D->query_location(get_path(), get_name())/1000;
  return "rightbank" + y;
}


int is_straight(){
  string enter, exit;
  int entry_no, exit_no;
  enter = MAZE_D->query_river_entry(get_path(), get_name());
  exit =  MAZE_D->query_river_exit(get_path(), get_name());
  entry_no = dir_no();
  exit_no = dir_no(exit);
  if ((entry_no-exit_no)%4 ==0){
    return 1;
  }
  return 0;
}

string * query_blocked_exits(){
  int i, enter_no, exit_no;
  string * result, enter, exit;
  enter = MAZE_D->query_river_entry(get_path(), get_name());
  exit =  MAZE_D->query_river_exit(get_path(), get_name());
  result = ({});
  enter_no = dir_no(enter);
  exit_no = dir_no(exit);
  if (exit_no > enter_no){
    enter_no += 8;
  }
  if (exit_no+1 <= enter_no){
    for (i = exit_no+1; i<enter_no;i++){
      result += ({dir_name(i)});
    }
  }
  return result;
}

setup_invisible_exits(){
  string * blocked;
  int i, count, y, loc, target_y;
  loc = MAZE_D->query_location(get_path(), get_name());
  y = loc/1000;
  blocked = query_blocked_exits();
  count = sizeof(blocked);
  if (count>0){
    for(i=0;i<count;i++){
      switch(blocked[i]){
      case "northwest":
        target_y = y + 1;
        break;
      case "west":
        target_y = y;
        break;
      case "southwest":
        target_y = y-1;
        break;
      }
      add_base_exit(blocked[i], JUNG_ROOM5 + "rightbank" + target_y);
      add_invis_exit(blocked[i]);
      update_exits();
    }
  }
}

string blocked_exits_desc(){
  int i, enter_no, exit_no;
  string result, enter, exit, * blocked;
  enter = MAZE_D->query_river_entry(get_path(), get_name());
  exit =  MAZE_D->query_river_exit(get_path(), get_name());
  enter_no = dir_no(enter);
  exit_no = dir_no(exit);
  if (enter_no > exit_no){
    exit_no += 8;
  }
  blocked = query_blocked_exits();
  if (sizeof(blocked)>0){
    result = " It blocks travel to the %^RESET%^";
    for (i = 0;i<sizeof(blocked);i++){
      if (i==0){
        result += blocked[i] ;
        continue;
      } 
      if (i==sizeof(blocked)-1){
        result += "%^GREEN%^ and %^RESET%^" + blocked[i] + "%^GREEN%^.";
        continue;
      }
      result += "%^GREEN%^, %^RESET%^" + blocked[i];
    }
  }
  setup_invisible_exits();
  return result;
}

string river_desc(){
  string enter, exit;
  enter = MAZE_D->query_river_entry(get_path(), get_name());
  exit =  MAZE_D->query_river_exit(get_path(), get_name());
  if (is_straight()){
    return "A %^RESET%^%^ORANGE%^canyon%^GREEN%^ runs through the"
     +" %^BOLD%^j%^RESET%^%^GREEN%^u%^BOLD%^%^n%^RESET%^%^GREEN%^g"
     +"%^BOLD%^l%^RESET%^%^GREEN%^e here, entering from the %^RESET%^" 
     + enter + "%^GREEN%^, and leaving to the %^RESET%^" + exit 
     +"%^GREEN%^. It is broad and deep, with a fast"
     +" %^BOLD%^%^BLUE%^river%^RESET%^%^GREEN%^ flowing at the base"
     +" far below." + blocked_exits_desc();
  } else {
    return "A %^RESET%^%^ORANGE%^canyon%^GREEN%^ runs through the"
     +" %^BOLD%^j%^RESET%^%^GREEN%^u%^BOLD%^%^n%^RESET%^%^GREEN%^g"
     +"%^BOLD%^l%^RESET%^%^GREEN%^e here, entering from the %^RESET%^" 
     + enter + "%^GREEN%^, and bending round to flow out to the %^RESET%^"
     + exit +"%^GREEN%^. It is broad and deep, with a fast"
     +" %^BOLD%^%^BLUE%^river%^RESET%^%^GREEN%^ flowing at the base"
     +" far below." + blocked_exits_desc();
  }
}

void set_enter(string direction){
  MAZE_D->set_river_entry(get_path(), get_name(), direction);
}

void set_exit(string direction){
  MAZE_D->set_river_exit(get_path(), get_name(), direction);
}

string query_river_enter(){
  return MAZE_D->query_river_entry(get_path(), get_name());
}

string query_river_exit(){
  return MAZE_D->query_river_entry(get_path(), get_name());
}


string long_desc(){
  update_exits();
  return ::base_desc() + " " + river_desc();
}
