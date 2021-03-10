#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM5;
  s_room = "j_link5";
  w_room = "j_link4a";
  e_room = "j_link9";  
}

varargs int verify_maze(string p){
  int north_loc, east_loc, south_loc, * room_names, i, count, flag;
  mapping maze;
  ::verify_maze(p);
  report("%^B_GREEN%^%^YELLOW%^Doing special verify_maze from j_maze0");
  maze = MAZE_D->query_maze(get_path());
  if (sizeof(maze)<1){
    report("%^YELLOW%^No maze found in check_maze. Aborting");
    return;
  }

  room_names = keys(maze);
  if (sizeof(room_names)<1){
    report("%^YELLOW%^No room names found in check_maze. Aborting");
    return;
  }
  flag = 0;
  count = sizeof(room_names);
  if (count>0){
    for (i=0;i<count;i++){
      if (interact("rightbank", room_names[i])){
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0){
    report ("No room name including 'rightbank' loaded. Loaded rooms: ");
    count = sizeof(room_names);
    if (count>0){
      for (i=0;i<count;i++){
        report ("%^GREEN%^" + room_names[i]);
      }
    }
  } else {
    report ("%^BLUE%^Found a loaded room called rightbank1. Not placing river");
    return;
  }
  north_loc = MAZE_D->query_north_location(get_path());
  east_loc = MAZE_D->query_east_location(get_path());
  south_loc = MAZE_D->query_south_location(get_path());
  place_river(get_path(), north_loc, east_loc + 1000); 
  MAZE_D->place_south_exit(get_path(), s_room);
}


varargs void place_river(string path, int whatever, int dontcare){
  string * potential_locs, * exit_names;
  mapping exits;
  int i, count, right_loc, right_x, right_y, x, y, last_loc, rightbank_num;
  if (!stringp(path)){
    path = get_path();
  }
  report ("%^RED%^PLACING RIVER");
  potential_locs = MAZE_D->right_locations(path);
  count = sizeof(potential_locs);
  if (count<1){
    return;
  }
  rightbank_num = 1;
  right_loc = MAZE_D->query_east_location( path);
  report("%^YELLOW%^CHECKING LEFT LOC.  right_loc: " + right_loc);
  right_x = right_loc % 1000;
  right_y = right_loc / 1000;
  for (i=0;i<count;i++){
    x = potential_locs[i]%1000;
    y = potential_locs[i]/1000;
    report ("%^GREEN%^Testing river location. Location: " + potential_locs[i] + "  x: " + x + "right_x: " + right_x + " y: " + y + " right_y: " + right_y); 
    if (((y > right_y + 1 || y<right_y-1) && x> right_x-3) || x > right_x - 2){ // potential_locs[i] is in range to be a river location
      report("In range to be a river location");
      if (potential_locs[i]!=right_loc ){ // potential_locs[i] is not the rightmost location
        rightbank_num = y;
        MAZE_D->replace_room(path, MAZE_D->query_room(path, potential_locs[i]), "rightbank" + rightbank_num);
        MAZE_D->set_river_entry(path, "rightbank" + rightbank_num, "north");
        MAZE_D->set_river_exit(path, "rightbank" + rightbank_num, "south");
        exits = MAZE_D->query_room_exits(path, "rightbank" + rightbank_num);
        exit_names = keys(exits);
        if (sizeof(exits)>0){
          if (member_array("northeast", exit_names)!= -1){
            MAZE_D->set_river_entry(path, "rightbank" + rightbank_num, "northeast");
          } 
          if (member_array("southeast", exit_names)!= -1){
            MAZE_D->set_river_exit(path, "rightbank" + rightbank_num, "southeast");
          } 
        } else {
          MAZE_D->set_river_entry(path, "rightbank" + rightbank_num, "north");
          MAZE_D->set_river_exit(path, "rightbank" + rightbank_num, "south");
        }

        rightbank_num ++; 
      } else {
        report ("%^MAGENTA%^Not replacing right room");
      }
    }else {
      report("%^RED%^Location too far from canyon path");
    }
  }
}
