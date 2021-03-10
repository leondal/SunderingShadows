#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  w_room = "j_link9a";
  s_room = "j_link10";  
  r_path = JUNG_ROOM9;
}


varargs int verify_maze(string p){
  int north_loc, west_loc, south_loc, * room_names, i, count, flag;
  mapping maze;
  ::verify_maze(p);
  report("%^YELLOW%^Doing special check_maze from j_maze0");
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
      if (interact("leftbank", room_names[i])){
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0){
    report ("No room name including 'leftbank' loaded. Loaded rooms: ");
    count = sizeof(room_names);
    if (count>0){
      for (i=0;i<count;i++){
        report ("%^GREEN%^" + room_names[i]);
      }
    }
  } else {
    report ("%^BLUE%^Found a loaded room called leftbank1. Not placing river");
    return;
  }
  north_loc = MAZE_D->query_north_location(get_path());
  west_loc = MAZE_D->query_west_location(get_path());
  south_loc = MAZE_D->query_south_location(get_path());
  place_river(get_path(), north_loc, west_loc + 1000); 
}


varargs void place_river(string path, int whatever, int dontcare){
  string * potential_locs, * exit_names;
  mapping exits;
  int i, count, left_loc, left_x, left_y, x, y, last_loc, leftbank_num;
  if (!stringp(path)){
    path = get_path();
  }
  report ("%^RED%^PLACING RIVER");
  potential_locs = MAZE_D->left_locations(path);
  count = sizeof(potential_locs);
  if (count<1){
    return;
  }
  leftbank_num = 1;
  left_loc = MAZE_D->query_west_location( path);
  report("%^YELLOW%^CHECKING LEFT LOC.  left_loc: " + left_loc);
  left_x = left_loc % 1000;
  left_y = left_loc / 1000;
  for (i=0;i<count;i++){
    x = potential_locs[i]%1000;
    y = potential_locs[i]/1000;
    report ("%^GREEN%^Testing river location. Location: " + potential_locs[i] + "  x: " + x + "left_x: " + left_x + " y: " + y + " left_y: " + left_y); 
    if (((y > left_y + 1 || y<left_y-1) && x < left_x+3) || x < left_x + 2){ // potential_locs[i] is in range to be a river location
      report("In range to be a river location");
      if (potential_locs[i]!=left_loc ){ // potential_locs[i] is not the leftmost location
        leftbank_num = y;
        MAZE_D->replace_room(path, MAZE_D->query_room(path, potential_locs[i]), "leftbank" + leftbank_num);
        MAZE_D->set_river_entry(path, "leftbank" + leftbank_num, "north");
        MAZE_D->set_river_exit(path, "leftbank" + leftbank_num, "south");
        exits = MAZE_D->query_room_exits(path, "leftbank" + leftbank_num);
        exit_names = keys(exits);
        if (sizeof(exits)>0){
          if (member_array("northwest", exit_names)!= -1){
            MAZE_D->set_river_entry(path, "leftbank" + leftbank_num, "northwest");
          } 
          if (member_array("southwest", exit_names)!= -1){
            MAZE_D->set_river_exit(path, "leftbank" + leftbank_num, "southwest");
          } 
        } else {
          MAZE_D->set_river_entry(path, "leftbank" + leftbank_num, "north");
          MAZE_D->set_river_exit(path, "leftbank" + leftbank_num, "south");
        }

        leftbank_num ++; 
      } else {
        report ("%^MAGENTA%^Not replacing left room");
      }
    }else {
      report("%^RED%^Location too far from canyon path");
    }
  }
}
