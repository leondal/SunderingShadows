// canoe_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>
#include "/daemon/river/river_blocks.h"
#include "/daemon/river/boat_symbols.h"
#define SAVE_FILE "/daemon/save/canoe"
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "canoe_log"

inherit DAEMON;

string * display, *temp_display;
string previous_direction;
string direction;
int current_x;
int current_y;
int top_edge;
int bottom_edge;
int left_edge;
int right_edge;
int right_x;
int left_x;
int right_y;
int left_y;
int * path;
int current_position;
int current_direction;
int current_progress;
int build_progress;
int * obstacle_placements;
string * obstacles;
void SAVE();
int add_south_block();


void create(){
  ::create();
  display = ({});
  top_edge = 0;
  bottom_edge = 0;
  left_edge = 0;
  right_edge = 0;
  current_x = 0;
  current_y = 0;
  left_x = 0;
  left_y = 8;
  right_x = 16;
  right_y = 8;
  path = ({});
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE,1);
  seteuid(getuid());
  previous_direction = "none";
  direction = "";
  current_progress = 0;
  current_direction = 0;
  current_position = 0;
  build_progress = 0;
  obstacles = ({});
  obstacle_placements = ({});
}

string * query_block(string dir){
  switch (dir){
  case "N":
    return N_BLOCK;
  case "NNE":
    return NNE_BLOCK;
  case "NE":
    return NE_BLOCK;
  case "ENE":
    return ENE_BLOCK;
  case "E":
    return E_BLOCK;
  case "ESE":
    return ESE_BLOCK;
  case "SE":
    return SE_BLOCK;
  case "SSE":
    return SSE_BLOCK;
  case "S":
    return N_BLOCK;
  case "SSW":
    return NNE_BLOCK;
  case "SW":
    return NE_BLOCK;
  case "WSW":
    return ENE_BLOCK;
  case "W":
    return E_BLOCK;
  case "WNW":
    return ESE_BLOCK;
  case "NW":
    return SE_BLOCK;
  case "NNW":
    return SSE_BLOCK;

  }
}

string * query_log(string dir){
  switch (dir)
  {
  case "N":    return N_LOG;
  case "NNE":  return NNE_LOG;
  case "NE":   return NE_LOG;
  case "ENE":  return ENE_LOG;
  case "E":    return E_LOG;
  case "ESE":  return ESE_LOG;
  case "SE":   return SE_LOG;
  case "SSE":  return SSE_LOG;
  case "S":    return N_LOG;
  case "SSW":  return NNE_LOG;
  case "SW":   return NE_LOG;
  case "WSW":  return ENE_LOG;
  case "W":    return E_LOG;
  case "WNW":  return ESE_LOG;
  case "NW":   return SE_LOG;
  case "NNW":   return SSE_LOG;
  }
}

string * query_waterfall(string dir){
  switch (dir)
  {
  case "N":    return N_WATERFALL;
  case "NNE":  return NNE_WATERFALL;
  case "NE":   return NE_WATERFALL;
  case "ENE":  return ENE_WATERFALL;
  case "E":    return E_WATERFALL;
  case "ESE":  return ESE_WATERFALL;
  case "SE":   return SE_WATERFALL;
  case "SSE":  return SSE_WATERFALL;
  case "S":    return N_WATERFALL;
  case "SSW":  return NNE_WATERFALL;
  case "SW":   return NE_WATERFALL;
  case "WSW":  return ENE_WATERFALL;
  case "W":    return E_WATERFALL;
  case "WNW":  return ESE_WATERFALL;
  case "NW":   return SE_WATERFALL;
  case "NNW":   return SSE_WATERFALL;
  }
}


string * query_rock(string dir){
  switch (dir)
  {
  case "N":    return N_ROCK;
  case "NNE":  return NNE_ROCK;
  case "NE":   return NE_ROCK;
  case "ENE":  return ENE_ROCK;
  case "E":    return E_ROCK;
  case "ESE":  return ESE_ROCK;
  case "SE":   return SE_ROCK;
  case "SSE":  return SSE_ROCK;
  case "S":    return N_ROCK;
  case "SSW":  return NNE_ROCK;
  case "SW":   return NE_ROCK;
  case "WSW":  return ENE_ROCK;
  case "W":    return E_ROCK;
  case "WNW":  return ESE_ROCK;
  case "NW":   return SE_ROCK;
  case "NNW":   return SSE_ROCK;
  }
}


string * query_weir(string dir){
  switch (dir)
  {
  case "N":    return N_WEIR;
  case "NNE":  return NNE_WEIR;
  case "NE":   return NE_WEIR;
  case "ENE":  return ENE_WEIR;
  case "E":    return E_WEIR;
  case "ESE":  return ESE_WEIR;
  case "SE":   return SE_WEIR;
  case "SSE":  return SSE_WEIR;
  case "S":    return N_WEIR;
  case "SSW":  return NNE_WEIR;
  case "SW":   return NE_WEIR;
  case "WSW":  return ENE_WEIR;
  case "W":    return E_WEIR;
  case "WNW":  return ESE_WEIR;
  case "NW":   return SE_WEIR;
  case "NNW":   return SSE_WEIR;
  }
}

string * query_sandbar(string dir){
  switch (dir)
  {
  case "N":    return N_SANDBAR;
  case "NNE":  return NNE_SANDBAR;
  case "NE":   return NE_SANDBAR;
  case "ENE":  return ENE_SANDBAR;
  case "E":    return E_SANDBAR;
  case "ESE":  return ESE_SANDBAR;
  case "SE":   return SE_SANDBAR;
  case "SSE":  return SSE_SANDBAR;
  case "S":    return N_SANDBAR;
  case "SSW":  return NNE_SANDBAR;
  case "SW":   return NE_SANDBAR;
  case "WSW":  return ENE_SANDBAR;
  case "W":    return E_SANDBAR;
  case "WNW":  return ESE_SANDBAR;
  case "NW":   return SE_SANDBAR;
  case "NNW":   return SSE_SANDBAR;
  }
}



int * query_obstacle_placements(){
  return obstacle_placements;
}

void set_obstacle_placements(int *ops){
  obstacle_placements = ops;
}

string * query_obstacles(){
  return obstacles;
}

void set_obstacles(string * obs){
  obstacles = obs;
}

int get_build_progress() {
  return build_progress;
}

int query_build_progress() {
  return build_progress;
}

void set_build_progress(int b){
  build_progress = b;
}

int get_current_position(){
  return current_position;
}

int set_current_position(int c){
  current_position = c;
}

int get_current_direction(){
  return current_direction;
}

int set_current_direction(int c){
  current_direction = c;
}

int get_current_progress(){
  return current_progress;
}

int set_current_progress(int c){
  current_progress = c;
}

string * get_boat(int dir){
  switch(dir)
  {
  case 0:
    return N_BOAT;
    break;
  case 1:
    return NNE_BOAT;
    break;
  case 2:
    return NE_BOAT;
    break;
  case 3:
    return ENE_BOAT;
    break;
  case 4:
    return E_BOAT;
    break;
  case 5:
    return ESE_BOAT;
    break;
  case 6:
    return SE_BOAT;
    break;
  case 7:
    return SSE_BOAT;
    break;
  case 8:
    return S_BOAT;
    break;
  case 9:
    return SSW_BOAT;
    break;
  case 10:
    return SW_BOAT;
    break;
  case 11:
    return WSW_BOAT;
    break;
  case 12:
    return W_BOAT;
    break;
  case 13:
    return WNW_BOAT;
    break;
  case 14:
    return NW_BOAT;
    break;
  case 15:
    return NNW_BOAT;
    break;
  }
}

void clean_up() {
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return;
}

void SAVE()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

int * get_path(){
  return path;
}

void set_path(int * p){
  path = p;
}

int query_current_progress(){
  return current_progress;
}

int query_current_direction(){
  return current_direction;
}

int query_current_position(){
  return current_position;
}

varargs int load_path(  object canoe){
  if (!objectp(canoe)) canoe = find_object("/d/atoyatl/tecqumin/rooms/canoe1.c");
  if (!objectp(canoe)){
    canoe = find_object_or_load("/d/atoyatl/tecqumin/rooms/canoe2.c");
  }
  if (!objectp(canoe)){
    canoe = find_object_or_load("/d/atoyatl/tecqumin/rooms/canoe1.c");
  }
  if (!objectp(canoe)) return 0;
  path = canoe->query_path();
//  current_progress = canoe->query_progress();
  current_position = canoe->query_position();
  current_direction = canoe->query_direction();
  if (!intp(current_progress) || current_progress<1) current_progress = 1;
  if (!intp(current_position) || current_position<1) current_position = 1;
  if (!intp(build_progress) || build_progress<1) build_progress = 1;
  if (!intp(current_direction) || current_direction<1) current_direction = 1;
  return 1;
}

varargs int build_map_section(int start, int length, object who){
  int * pth;
  if (!objectp(who)) who = TP;
  pth = path[start..start+length];
  return build_map(pth, start, who);
}

int pathreport(string str){
//  return "/daemon/reporter_d"->report("lujke", str);
}

varargs string * get_sprite(string spritename, string dir){
  switch(spritename)
  {
  case "a rock ":
    return query_rock(dir);
    break;
  case "a weir ":
    return query_weir(dir);
    break;
  case "a log ":
    return query_log(dir);
    break;
  case "a sandbar ":
    return query_sandbar(dir);
    break;
  case "is a waterfall ":
    return query_waterfall(dir);
  case "is an island ":
    return ISLAND;
  default:
    return ({" "});
  }
}

int query_sprite_x_correction (string spritename, int river_direction){
  int result;
  result = 0;
  switch(spritename)
  {
  case "is a waterfall ":
    // special_report("%^BOLD%^%^CYAN%^I am a waterfall. splash!");
    switch(river_direction){
    case 0:
      return -5;
      break;
    case 1:
      result =-5;
      break;
    case 2:
      result =-2;
      break;
    case 3:
      result = 0;
      break;
    case 4:
      break;
    case 5:
      result = 2;
      break;
    case 6:
      result = 1;
      break;
    case 7:
      result = -5;
      break;
    case 8:
      result = -6;
      break;
    case 9:
      result = -4;
      break;
    case 10:
      return -3;
      break;
    case 11:
      result = 3;
      break;
    case 12:
      break;
    case 13:
      result = -2;
      break;
    case 14:
      result = 2;
      break;
    case 15:
      result =-5;
      break;
    }
    break;
  case "is an island ":
    // special_report("%^BOLD%^%^CYAN%^I am a rock. I am an iiiisland");
    switch(river_direction){
    case 0:
      return -1;
      break;
    case 1:
      result =-2;
      break;
    case 2:
      result =-2;
      break;
    case 3:
      result = 2;
      break;
    case 4:
      break;
    case 5:
      result = 1;
      break;
    case 6:
      result = 0;
      break;
    case 7:
      result = -2;
      break;
    case 8:
      result = -2;
      break;
    case 9:
      result = -2;
      break;
    case 10:
      break;
    case 11:
      result = 3;
      break;
    case 12:
      break;
    case 13:
      result = -2;
      break;
    case 14:
      result = 2;
      break;
    case 15:
      result =0;
      break;
    }
    break;
  }
  // special_report("sprite x correction: " + result);
  return result;
}

int query_sprite_y_correction (string spritename, int river_direction){
  int result;
  result = 0;
  switch(spritename)
  {
  case "is a waterfall ":
    // special_report("%^BOLD%^%^CYAN%^I am a rock. I am an iiiisland");
    switch(river_direction){
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      result = -2;
      break;
    case 4:
      result = -3;
      break;
    case 5:
      return -1;
      break;
    case 6:
      result = 1;
      break;
    case 7:
      break;
    case 8:
      result = 0;
      break;
    case 9:
      break;
    case 10:
      return 0;
      break;
    case 11:
      return -3;
      break;
    case 12:
      return 0;
      break;
    case 13:
      result = 2;
      break;
    case 14:
      result = 0;
      break;
    case 15:
      return 0;
      break;
    }
    break;
  case "is an island ":
    // special_report("%^BOLD%^%^CYAN%^I am a rock. I am an iiiisland");
    switch(river_direction){
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      result = -2;
      break;
    case 4:
      result = -2;
      break;
    case 5:
      return -1;
      break;
    case 6:
      result = -1;
      break;
    case 7:
      result = - 2;
      break;
    case 8:
      result = 1;
      break;
    case 9:
      break;
    case 10:
      return -1;
      break;
    case 11:
      return -2;
      break;
    case 12:
      return -2;
      break;
    case 13:
      result = 2;
      break;
    case 14:
      result = 0;
      break;
    case 15:
      return 1;
      break;
    }
    break;
  }
  return result;
}

varargs int build_map(int *pth, int start_point, object who){
  int p, i, screen_width, display_width;
  string line;
  if (sizeof(path)<1) return 0;
  if (!objectp(who)) who = TP;
  if (!intp(start_point)) start_point = 0;
  display = ({});
  screen_width = atoi(who->getenv("SCREEN"));
  if (!intp(screen_width) || screen_width <10) screen_width = 75;
  i=start_point;
  foreach(p in pth)
  {
    temp_display = display;
    build_progress = i;
    switch(p)
    {
    case 0:
      pathreport("Adding north");
      add_north_block();
      break;
    case 1:
      add_northnortheast_block();
      pathreport("Adding northnortheast");
      break;
    case 2:
      add_northeast_block();
      pathreport("Adding northeast");
      break;
    case 3:
      add_eastnortheast_block();
      pathreport("Adding eastnortheast");
      break;
    case 4:
      add_east_block();
      pathreport("Adding east");
      break;
    case 5:
      add_eastsoutheast_block();
      pathreport("Adding eastsoutheast");
      break;
    case 6:
      add_southeast_block();
      pathreport("Adding southeast");
      break;
    case 7:
      add_southsoutheast_block();
      pathreport("Adding southsoutheast");
      break;
    case 8:
      add_south_block();
      pathreport("Adding south");
      break;
    case 9:
      add_southsouthwest_block();
      pathreport("Adding southsouthwest");
      break;
    case 10:
      add_southwest_block();
      pathreport("Adding southwest");
      break;
    case 11:
      add_westsouthwest_block();
      pathreport("Adding westsouthwest");
      break;
    case 12:
      add_west_block();
      pathreport("Adding west");
      break;
    case 13:
      add_westnorthwest_block();
      pathreport("Adding westnorthwest");
      break;
    case 14:
      add_northwest_block();
      pathreport("Adding northwest");
      break;
    case 15:
      add_northnorthwest_block();
      pathreport("Adding northnorthwest");
      break;
    }
//    line = display[sizeof(display)-1];
//    line = display[0];
    display_width = strlen(display[0]);
    if (display_width>= screen_width - 10)
    {
      display = temp_display;
      break;
    }
    i++;
  }
  return 0;
}

void show_my_block(object who, string * map){
  int i, height, width, count;
  if (!objectp(who)) return;
  if (!arrayp(map)) return;
  count = sizeof(map);
  if (count<1) return;
  height = sizeof(map);
  width = strlen(map[0]);
  for (i=0;i<count;i++)
  {
   tell_object(who, map[i]);
  }
}

string colour_line(string line){
  string newline,ch, bwch;
  int i, len, flag;
  len = strlen(line);
  if (len<1) return line;
  newline = "%^B_GREEN%^";
  flag = 0;
  for (i = 0; i<len;i++)
  {

    ch = line[i..i];

    if (ch != " ") ch = substitute_character(ch);
    bwch = strip_colors(ch);
    if (bwch =="\\"||bwch =="|"||bwch =="/"||bwch =="-"||bwch =="V"||bwch =="^"||bwch == "_")
    {
      switch(flag)
      {
      case 0:
        newline += "%^B_ORANGE%^%^BOLD%^%^WHITE%^";
        flag = 1;
        break;
      case 1:
        newline += "%^B_ORANGE%^";
        flag = 1;
        break;
      case 2:
        newline += "%^B_ORANGE%^";
        flag = 2;
        break;
      }
      newline += ch;
      continue;
    }
    if (bwch == "*"){
      switch(flag)
      {
      case 0:
      case 1:
        newline += "%^B_BLUE%^";
        flag = 2;
        break;
      case 2:
        break;
      }
      newline += "_";
      continue;
    }
    if (bwch == "."){
      switch(flag)
      {
      case 0:
      case 1:
        newline += "%^B_BLUE%^";
        flag = 2;
        break;
      case 2:
        break;
      }
      newline += " ";
      continue;
    } else
    {
      switch(flag)
      {
      case 0:
        break;
      case 1:
      case 2:
        newline += "%^B_GREEN%^";
        flag = 0;
        break;
      }
    }
    newline += ch;
//    if (flag ==2)
//    {
//      newline += "%^B_BLUE%^";
//    }
  }
  return newline;
}

string * colour_map(string * map){
  string * cm, line;
  cm = ({});
  foreach(line in map)
  {
    line = colour_line (line);
    cm += ({line});
  }
  return cm;
}

void show_map(object who, string * map){
  int i, j, height, width, count, lpos, rpos;
  string line_no, line;
  if (!objectp(who)) return;
  if (!arrayp(map)) return;
  count = sizeof(map);
  if (count<1) return;
  line_no = "";
  height = sizeof(display);
  width = strlen(display[0]);
  for (i=0;i<count;i++)
  {
    line_no = "";
    if (i<10) line_no += " ";
    line_no +=i;
    line  = map[i];
    j = height - i + bottom_edge;
    lpos = left_x - left_edge;
    rpos = right_x - left_edge;
///////////////////////////////////////////////////////////////////////////////////////////////
//These lines are for highlighting current left & right co-ordinates. Helpful for debugging  //
//    report ("%^BOLD%^%^YELLOW%^Checking for left-right match. Left_y: " + left_y + " Right_y: " + right_y + " i: " + i);
//    if (j==left_y ){
//      if ( j==right_y ){
//        if (left_x<right_x){
//          report("Inserting L. left_x = " + left_x + " left_edge = " + left_edge + ". Therefore inserting at position: " + lpos);
//          line = "/daemon/str_insert_d"->insert_string(line, "L", lpos);
//          report("Inserting R. right_x = " + right_x + " left_edge = " + left_edge + ". Therefore inserting at position: " + rpos);
//          line = "/daemon/str_insert_d"->insert_string(line, "R", rpos);
//        } else {
//          report("Inserting R. right_x = " + right_x + " left_edge = " + left_edge + ". Therefore inserting at position: " +rpos);
//          line = "/daemon/str_insert_d"->insert_string(line, "R", rpos);
//          report("Inserting L. left_x = " + left_x + " left_edge = " + left_edge + ". Therefore inserting at position: " +lpos);
//          line = "/daemon/str_insert_d"->insert_string(line, "L", lpos);
//        }
//      } else {
//        report("Inserting L. left_x = " + left_x + " left_edge = " + left_edge + ". Therefore inserting at position: " +lpos);
//        line = "/daemon/str_insert_d"->insert_string(line, "L", lpos);
//      }
//    } else {
//      if (j==right_y ){
//        report("Inserting R. right_x = " + right_x + " left_edge = " + left_edge + ". Therefore inserting at position: " +rpos);
//        line = "/daemon/str_insert_d"->insert_string(line, "R", rpos);
//      }
//    }
//    if (j==left_y + 1 || j == left_y-1){
//      if ( j==right_y +1 || j == right_y -1){
//        if (left_x<right_x){
//          line = "/daemon/str_insert_d"->insert_string(line, "l", lpos);
//          line = "/daemon/str_insert_d"->insert_string(line, "r", rpos);
//        } else {
//          line = "/daemon/str_insert_d"->insert_string(line, "r", rpos);
//          line = "/daemon/str_insert_d"->insert_string(line, "l", lpos);
//        }
//      } else {
//        line = "/daemon/str_insert_d"->insert_string(line, "l", lpos);
//      }
//    } else {
//      if (j==right_y + 1 || j == right_y-1 ){
//        line = "/daemon/str_insert_d"->insert_string(line, "r", rpos);
//      }
//    }
//
///////////////////////////////////////////////////////////////////////////////////////////////
    line = colour_line(line);
//    tell_object(who, ""+ line_no + "" + line);
    tell_object(who, line);
  }
}

void show_boat(int dir){
  string * boat, line, newline, ch;
  int i;
  boat = get_boat(dir);
  foreach(line in boat)
  {
    newline = "";
    for (i=0;i<strlen(line);i++)
    {
      ch = line[i..i];
      ch = substitute_character(ch);
      newline += ch;
    }
    tell_object(TP, newline);
  }
}


void show_boat_with_sprite(){
  string * block, * boat;
  block = N_BLOCK + N_BLOCK;
  boat = N_BOAT;
  tell_object(TP, "size of block: " + sizeof(block));
  show_map(TP, block);
  block = add_sprite_to_block(boat, block, 0, 0);
  tell_object(TP, "size of block: " + sizeof(block));

  show_map(TP, block);
}

int query_x_correction(int boat_direction, string river_direction){
    report("%^B_WHITE%^%^BOLD%^%^RED%^QUERYING X CORRECTION. boat_direction: " + boat_direction + " river_direction: " + river_direction + " current_direction: " + current_direction );
  switch(river_direction){
  case "north":
    switch(boat_direction)
    {
    case 0:
      if (current_position>4) return 1;
      return 0;
    case 8:
      if (current_position>4) return 1;
      return 0;
    case 1:
      if (current_position>3) return -1;
      return -2;
    case 7:
      if (current_position>3) return -1;
      if (current_position==3) return -2;
      return -3;
    case 2:
      if (current_position>3) return -3;
      return -4;
    case 6:
      if (current_position>3) return -3;
      if (current_position==3) return -4;
      return -5;
    case 3:
      if (current_position>3) return -5;
      return -6;
    case 5:
      if (current_position>3) return -4;
      return -5;
    case 4:
      if (current_position>3) return -4;
      return -5;
    case 9:
      if (current_position>3) return 1;
      return 0;
    case 10:
      if (current_position>3) return 1;
      return 0;
    case 11:
      if (current_position>3) return 0;
      return -1;
    case 12..13:
      if (current_position>3) return 1;
      return 0;
    case 14..15:
     if (current_position>3) return 1;
//      if (current_position==3) return 2;
      return 0;
    }
    break;
  case "northnortheast":
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 8:
      return -3;
    case 1:
      if (current_position<4) return -3;
      return -2;
    case 7:
      if (current_position<4) return -5;
      return -4;
    case 2:
      return -4;
    case 6:
      if (current_position<4) return -8;
      return -7;
    case 3:
      if (current_position<4) return -7;
      return -6;
    case 5:
      return -7;
    case 4:
      return -6;
    case 9..10:
      if (current_position<4) return -3;
      return -2;
    case 11:
      if (current_position<4) return -3;
      if (current_position==3) return -2;
      return -1;
    case 12:
    case 13:
      if (current_position<4) return -1;
      if (current_position==3) return 0;
      return 1;
    case 14..15:
      if (current_position<4) return -1;
      if (current_position==3) return 0;
      return 1;
    }
    break;
  case "northeast":
    switch(boat_direction)
    {
    case 0:
      return 1;
    case 8:
      if (current_position>3) return -6;
      return -7;
    case 1:
      return -3;
    case 7:
      if (current_position>3) return -7;
      return -7;
    case 2:
      return -4;
    case 6:
      if (current_position>3) return -11;
      return -11;
    case 3:
      if (current_position>3) return -8;
      return -7;
    case 5:
      if (current_position<4) return -7;
      return -8;
    case 4:
      if (current_position<4) return -7;
      return -6;
    case 9:
      report("%^B_WHITE%^%^BOLD%^%^RED%^CASE 9!");
      return -4;
    case 10:
      return -5;
    case 11:
      if (current_position>3) return -2;
      if (current_position ==3) return -2;
      return -3;
    case 12:
      if (current_position>3) return 1;
      if (current_position ==3) return 0;
      return -1;
    case 13:
      if (current_position>3) return 1;
      return 0;
    case 14-15:
      return 1;
    }
    break;
  case "eastnortheast":
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 8:
      if (current_position>3) return 0;
      return 1;
    case 1:
    case 7:
      return -1;
    case 2:
      if (current_position>3) return -4;
      return -3;
    case 3:
      if (current_position>3) return -5;
      return -4;
    case 4:
      if (current_position>3) return -5;
     if (current_position ==3) return -4;
      return -3;
    case 5:
      if (current_position>3) return -5;
      if (current_position ==3) return -4;
      return -3;
    case 6:
      if (current_position>3) return -4;
      return -3;
    case 9..11:
      if (current_position>3) return -1;
      return 0;
    case 12..13:
      if (current_position>3) return -1;
      if (current_position==3) return 0;
      return 1;
    case 14-15:
      if (current_position>3) return 1;
      if (current_position==3) return 2;
      return 3;
    }
    break;
  case "eastsoutheast":
    switch(boat_direction)
    {
    case 0:
      if (current_position<4) return 1;
      return 0;
    case 8:
      return 0;
    case 1:
      return -2;
    case 7:
      if (current_position >3) return -2;
      return -3;
    case 2:
      if (current_position >3) return -4;
      return -5;
    case 6:
      if (current_position >3) return -4;
//      if (current_position ==3) return -4;
      return -5;
    case 3:
      if (current_position >3) return -5;
      if (current_position ==3) return -5;
      return -6;
    case 4..5:
      if (current_position ==0) return -4;
      if (current_position ==3) return -5;
      return -6;
    case 9..10:
      return 0;
    case 11:
      return 0;
    case 12:
      return 1;
    case 13..14:
      return 0;
    case 15:
      if (current_position <4) return 1;
      return 0;
    }
    break;
  case "southeast":
    switch(boat_direction)
    {
    case 0:
      return -2;
    case 8:
      if (current_position>3) return -3;
      return -2;
    case 1:
      if (current_position>3) return -5;
      return -4;
    case 7:
      return -5;
    case 2:
      if (current_position>3) return -7;
      return -6;
    case 6:

      return -7;
    case 3:
      if (current_position>3) return -9;
      return -8;
    case 5:
      if (current_position>3) return -8;
      return -7;
    case 4:
      if (current_position>3) return -8;
      return -7;
    case 9..10:
      if (current_position>3) return -2;
      return -1;
    case 11:
      if (current_position>3) return -3;
      return -2;
    case 12..13:
      if (current_position>3) return -2;
      return -1;
    case 14..15:
      return -2;
    }
    break;
  case "southsoutheast":
    report("%^B_WHITE%^%^BOLD%^%^RED%^ADDING SPECIAL X CORRECTION");
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 8:
    report("%^B_WHITE%^%^BOLD%^%^RED%^ADDING SPECIAL X CORRECTION for SOUTH facing");
      if (current_position>3)return 3;
      return 4;
    case 1:
      if (current_position>3)return -2;
      return -1;
    case 7:
      if (current_position>3)return 0;
      return 1;
    case 2:
      if (current_position>3)return -4;
      return -3;
    case 6:
      if (current_position>3)return -1;
      return 0;
    case 3:
      if (current_position>3)return -7;
      return -6;
    case 5:
      if (current_position>3)return -5;
      return -4;
    case 4:
      if (current_position>3)return -6;
      return -5;
    case 9..10:
      if (current_position>3)return 3;
      return 4;
    case 11..13:
      if (current_position>3)return 1;
      return 2;
    case 14..15:
      if (current_position>3)return 0;
      return 1;
    }
    break;
  case "south":
    switch(boat_direction)
    {
    case 0:
      if (current_position>3) return -1;
      return 0;
    case 8:
      if (current_position>3) return -1;
      return 0;
    case 1:
      if (current_position>3) return -3;
      return -2;
    case 7:
      if (current_position>3) return -3;
      return -2;
    case 2:
      if (current_position>3) return -5;
      return -4;
    case 6:
      if (current_position>3) return -5;
      return -4;
    case 3:
      return -7;
    case 5:
    case 4:
      return -6;
    case 9..11:
      if (current_position>3) return -1;
      return 0;
    case 12..13:
      if (current_position>3) return 0;
      return 1;
    case 14..15:
      if (current_position>3) return -1;
      return 0;
    }
  case "southsouthwest":
    report("%^BOLD%^%^MAGENTA%^SWITCHING ON BOAT DIRECTION: " + boat_direction);
    switch(boat_direction)
    {
    case 0:
      report("%^BOLD%^%^MAGENTA%^THIS IS CASE 0!");
//      if (current_position>3) return 3;
      return 4;
    case 8:
      if (current_position>3) return 1;
      return 0;
    case 1:
      return 1;
    case 7:
      return -2;
    case 2:
      if (current_position>3) return 0;
      return -1;
    case 6:
      if (current_position>3) return -4;
      return -5;
    case 3:
      return -4;
    case 5:
      return -4;
    case 4:
      return -3;
    case 9:
      return 1;
    case 10:
      if (current_position>3) return 2;
      return 1;
    case 11:
      if (current_position>3) return 2;
      return 2;
    case 12..13:
      return 4;
    case 14..15:
      return 4;
    }
    break;
  case "southwest":
    switch(boat_direction)
    {
    case 0:
      return 8;
    case 8:
      return 1;
    case 1:
      return 4;
    case 2:
      if (current_position>3) return 4;
      return 3;
    case 3:
      if (current_position>3) return 1;
      return 0;
    case 4:
      return 1;
    case 5:
      if (current_position>3) return -2;
      return -1;
    case 6:
      return -3;
    case 7:
      return 1;
    case 9:
      return 3;
    case 10:
      if (current_position>3) return 3;
      return 2;
    case 11:
      if (current_position>3) return 5;
      return 4;
    case 12..13:
      if (current_position>3) return 8;
      return 7;
    case 14..15:
      return 7;
    }
    break;
  case "westsouthwest":
    report("%^BOLD%^%^MAGENTA%^%^B_CYAN%^This is WESTSOUTHWEST Option. Boat direction: " + boat_direction);
    switch(boat_direction)
    {
    case 0:
      if (current_position>4) return 0;
      return -1;
    case 1:
      if (current_position>3) return -2;
      return -3;
    case 2:
      if (current_position>3) return -1;
      return -2;
    case 3:
      if (current_position>3) return -3;
      return -3;
    case 4:
      if (current_position>3) return -1;
      return -2;
    case 5:
      if (current_position>4) return -5;
      if (current_position>2) return -4;
      if (current_position>0) return -3;
      return -2;
    case 6:
      if (current_position>3) return -3;
      if (current_position == 3) return -4;
      return -5;
    case 7:
      if (current_position>3) return -1;
      if (current_position>1) return -2;
      return -3;
    case 8..9:

    case 12..15:
      if (current_position>3) return 1;
      if (current_position>1) return 0;
      return -1;
    case 10:
      if (current_position>3) return 2;
      if (current_position>0) return 1;
      return -1;
    case 11:
      if (current_position>3) return 0;
      if (current_position>0) return -1;
      return -2;
    }
    return 0;
  case "northwest":
    switch(boat_direction)
    {
    case 0:
      return -8;
    case 1:
      return -9;
    case 2:
      return -12;
    case 6:
      return -7;
    case 3:
      if (current_position>3) return -14;
      return -15;
    case 5:
      if (current_position>3) return -6;
      return -7;
    case 4:
      if (current_position>3) return -13;
      return -14;
    case 7:
      return -5;
    case 8:
      return -1;
    case 9..10:
      return -2;
    case 11:
      return -5;
    case 12..13:
      return -6;
    case 14:
      return -6;
    case 15:
      return -6;
    }
    break;
  case "northnorthwest":
    switch(boat_direction)
    {
    case 0:
      return -1;
    case 1:
      if (current_position>3) return -2;
      return -3;
    case 2:
      if (current_position>3) return -4;
      return -5;
    case 3:
      if (current_position>3) return -6;
      return -7;
    case 4:
      if (current_position>3) return -5;
      return -6;
    case 5:
      if (current_position>3) return -4;
      return -5;
    case 6:
      if (current_position>3) return -1;
      return -2;
    case 7:
      if (current_position>3) return 0;
      return -1;
    case 8:
      if (current_position>3) return 2;
      return 2;
    case 9:
      if (current_position>3) return 2;
      return 1;
    case 10:
      if (current_position>3) return 3;
      if (current_position == 2) return 2;
      return 1;
    case 11..13:
      if (current_position>3) return 1;
      if (current_position==3) return 0;
      return -1;
    case 14:
      if (current_position>3) return 0;
      return -1;
    case 15:
      if (current_position>3) return 0;
      return -1;
    }
    break;
  case "westnorthwest":
    switch(boat_direction)
    {
    case 0:
    case 8:
      return 0;
    case 1:
      return 1;
    case 7:
      return 0;
    case 2:
    case 6:
      return -2;
    case 3:
      return -4;
    case 5:
      return -3;
    case 4:
      return -3;
    case 9..10:
      return 0;
    case 11:
      return -1;
    case 12..13:
      return 0;
    case 14..15:
      return 0;
    }
    break;
  default:
    switch(boat_direction)
    {
    case 0:
    case 8:
      return 0;
    case 1:
    case 7:
      return -1;
    case 2:
    case 6:
      return -4;
    case 3:
    case 5:
      return -6;
    case 4:
      return -5;
    case 9..13:
      return 0;
    case 14..15:
      return 1;
    }
    break;
  }
}

void show_river(object who){
  int i, flag, screen_width, screen_height, display_width, display_height;
  flag = 0;
  if (!objectp(who)) return;
  report("Showing river");
  display_width = 0;
  screen_width = atoi(who->getenv("SCREEN"));
  screen_height = atoi(who->getenv("LINES"));
  if (!intp(screen_width) || screen_width <10) screen_width = 75;
  if (!intp(screen_height) || screen_height <21) screen_height = 30;
  report("screen_width: " + screen_width);
  for (i = current_position; i<sizeof(path)-1; i++)
  {
    report("i: " + i);
    temp_display = display;
    build_map_section(current_progress, i - current_progress +1);
    if (sizeof(display)>0)
    {
      display_width = strlen(display[0]);
      display_height = sizeof(display);
    }
    if (display_width >= screen_width-2 || display_height >=screen_height-8)
    {
      report( "We broke out of the show river LOOP!");
      show_map(who, temp_display);
      return;
//      display = temp_display;
//      break;
    }
  }
  report("FInished loading map. Size of display: " + sizeof(display));
  report( "We DIDN'T break out of the show river LOOP!");
  show_map(who, display);
}

void special_report(string str){
  /* "/daemon/reporter_d"->report("lujke", str); */
}

varargs int query_y_correction(int boat_direction, string river_direction){
  if (!stringp(river_direction)) river_direction = "unspecified";
  report ("%^B_CYAN%^%^BOLD%^%^RED%^CHECKING Y CORRECTION. RIver direction: " + river_direction + " Boat direction: " + boat_direction);

switch(river_direction){
  case "eastsoutheast":
    switch(boat_direction)
    {
    case 0:
      return 1;
    case 15:
      return 2;
    case 8:
      return 5;
    case 5:
    case 11:
      return 3;
    case 9..10:
      return 4;
    case 6:
      return 5;
    case 7:
      return 4;
    case 1..4:
    case 12..13:
      return 2;
    case 14:
      return 2;
    }
    break;
  case "westsouthwest":
  report ("%^B_CYAN%^%^BOLD%^%^RED%^THIS IS A WESTSOUTHWEST OPTION");
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 3:
      return 2;
    case 15:
      return 1;
    case 8:
      return 4;
    case 4:
      return 2;
    case 5:
      if (current_position>3) return 2;
      return 3;
    case 11:
      return 2;
    case 9..10:
      return 3;
    case 6:
      if (current_position<4) return 4;
      return 5;
    case 7:
      return 3;
    case 1:
    case 12..13:
      return 1;
    case 2:
      if (current_position>3) return 2;
      return 2;
    case 14:
      return 1;
    }
    break;
  case "west":
    switch(boat_direction)
    {
    case 0:
      if (current_position>3) return -1;
      return 0;
    case 15:
      if (current_position>3) return 0;
      return 1;
    case 8:
      if (current_position>3) return 3;
      return 4;
    case 5:
    case 11:
      if (current_position>3) return 1;
      return 2;
    case 9..10:
      if (current_position>3) return 2;
      return 3;
    case 6:
      if (current_position>3) return 3;
      return 4;
    case 7:
      if (current_position>3) return 2;
      return 3;
    case 1..4:
    case 12..13:
      if (current_position>3) return 0;
      return 1;
    case 14:
      if (current_position>3) return 0;
      return 1;
    }
    break;
  case "westnorthwest":
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 15:
      return -1;
    case 8:
      return -4;
    case 5:
      return -1;
    case 11:
      return -2;
    case 9:
      return -3;
    case 10:
      if (current_position>3) return -3;
      return -3;
    case 6:
      return -3;
    case 7:
      if (current_position>3) return -2;
      return -2;
    case 1..4:
      return 0;
    case 12:
      return -1;
    case 13:
      return -1;
    case 14:
      return -1;
    }
    break;

  case "northwest":
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 8:
//      if (current_position >3) return 1;
      return 0;
    case 9..15:
//      if (current_position >3) return 1;
      return 0;
    case 6:
//      if (current_position >3) return 2;
      return 1;
    case 7:
//      if (current_position>3) return 1;
      return 0;
    case 2..4:
      return 1;
//      if (current_position >2) return 0;
      return -1;
    case 5:
//      if (current_position>3) return -1;
      return -2;
    case 1:
//      if (current_position >3) return 1;
      return 0;
    }
    break;
  case "eastnortheast":
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 15:
      return 1;
    case 8:
      return 4;
    case 5:
    case 11:
      return 2;
    case 9..10:
      return 3;
    case 6:
      return 4;
    case 7:
      return 3;
    case 1..4:
      return 0;
    case 12..13:
      return 1;
    case 14:
      return 1;
    }
    break;
  default:
    switch(boat_direction)
    {
    case 0:
      return 0;
    case 15:
      return 1;
    case 8:
      return 4;
    case 5:
    case 11:
      return 2;
    case 9..10:
      return 3;
    case 6:
      return 4;
    case 7:
      return 3;
    case 1..4:
    case 12..13:
      return 1;
    case 14:
      return 1;
    }
    break;
  }
}


int add_north_block(){
  string * block;
  int pos;
  block = N_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position *2;
//    if (pos>13) pos = 13;
    pos += query_x_correction(current_direction, "north");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, 0);
  }
  if (sizeof(obstacles)>build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "N"), block, ((2 * obstacle_placements[build_progress]))+1 , 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress);

  if(sizeof(display)<1)
  {
    display = N_BLOCK + block;
    left_x = 0;
    right_x = 15;
    left_y = 11;
    right_y = 11;
    left_edge = 0;
    right_edge = 15;
    top_edge = 10;
    bottom_edge = 0;
    trim_display();
    previous_direction = "north";
    return 1;
  }
  switch(previous_direction)
  {
  case "none":
    block = N_BLOCK;
    report("Adding n_block to top twice");
    add_block_top(N_BLOCK, 0, 5, 0, 5, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "north":
    report("Adding n_block to top twice");
    add_block_top(N_BLOCK, 0, 5, 0, 5, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "northeast":
    report("Adding ne_n_block to top");
    add_block_top(NE_N_BLOCK,6,6,6,6, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "northwest":
    report("adding se_s block to top");
    add_block_top(S_SE_BLOCK,-6, 5, -6, 5, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "northnorthwest":
    report("adding sse_s block to top");
    add_block_top(S_SSE_BLOCK,-2,5,-2,5, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "northnortheast":
    report("Adding nne_n block to top");
    add_block_top(NNE_N_BLOCK, 4, 6, 4, 6, "north");
    left_x--;
    right_x--;
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "eastnortheast":
    report("Adding ene_n block to right");
//a    left_y--;
//    right_y--;
    add_block_right(ENE_N_BLOCK, 4,2,19,9, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    left_y--;
    right_y--;
    break;
  case "east":
    report ("adding e_n_block to right");
    left_x++;
    right_x++;
    add_block_right(E_N_BLOCK, 2,1,17,8, "north");
    left_x--;
    right_x--;
    add_block_top(block, 0, 5, 0, 5, "north");
    break;

  case "west":
    report("Adding s_e block to left");
    add_block_left(S_E_BLOCK, -16,7, -1,0, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  case "westnorthwest":
    report("Adding s_ese block to left");
    add_block_left(S_ESE_BLOCK, -17,9,-2,2, "north");
    add_block_top(block, 0, 5, 0, 5, "north");
    break;
  }
  previous_direction = "north";
  return 1;
}

int add_northnortheast_block(){
  string * block;
  int pos, x_adjust, y_adjust;
  block = NNE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position *2;
//    if (current_position<4) pos --;
    pos += 4;
    pos += query_x_correction(current_direction, "northnortheast");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, 0);
  }
  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "NNE"), block, obstacle_placements[build_progress]*2+3, 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );

  if(sizeof(display)<1)
  {
    display = NNE_BLOCK;
    left_x = 5;
    right_x = 20;
    left_y = 6;
    right_y = 6;
    left_edge = 0;
    right_edge = 20;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "northnortheast";
    add_block_top(block, 5,5,5,5, "northnortheast");
    return 1;
  }
  switch(previous_direction)
  {
  case "northeast":
    report ("adding ne_nne_block to top");
    add_block_top(NE_NNE_BLOCK,8,5,8,5, "northnortheast");
    add_block_top(block, 5,5,5,5, "north");
    break;
  case "none":
  case "north":
    report ("adding n_nne_block to top");
    add_block_top(N_NNE_BLOCK,1,4,1,4, "northnortheast");
    left_x ++;
    right_x ++;
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
    case "northwest":
    report ("adding ssw_se_block to top");
    left_x-=3;
    right_x-=3;
    add_block_top(SSW_SE_BLOCK,-2,5,-2,5, "northnortheast");
    left_x+=3;
    right_x+=3;
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  case "northnorthwest":
    report ("adding ssw_se_block to top");
    add_block_top(SSW_SSE_BLOCK,2,5,2,5, "northnortheast");
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  case "northnortheast":
    report("Adding nne block to top twice");
    add_block_top(NNE_BLOCK, 5,5,5,5, "northnortheast");
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  case "east":
    report("Adding e_nne block to right");
    add_block_right(E_NNE_BLOCK, 3,1,18,8, "northnortheast");
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  case "eastsoutheast":
    report("Adding ese_NNE block to right");
    add_block_right(ESE_NNE_BLOCK, 5,2,20,9, "northnortheast");
    left_x++;
    right_x++;
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  case "eastnortheast":
    report("Adding e_nne block to right");
    add_block_right(ENE_NNE_BLOCK, 4,1,19,8, "northnortheast");
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  case "westnorthwest":
    report("Adding ese_NNE block to right");
    left_x-=7;
    right_x-=7;
    add_block_left(WNW_NNE_BLOCK, 7 ,11,22,4, "northnortheast");
    left_x+=2;
    right_x+=2;
    add_block_top(block, 5,5,5,5, "northnortheast");
    break;
  }
  previous_direction = "northnortheast";
  return 1;
}


int add_northeast_block(){
  string * block;
  int pos;
  block = NE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position *2;
    pos += 8;
    pos += query_x_correction(current_direction, "northeast");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, 0);
  }

  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "NE"), block, obstacle_placements[build_progress]*2 + 6, 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );


  if(sizeof(display)<1)
  {
    display = NE_BLOCK;
    left_x = 10;
    right_x = 25;
    left_y = 6;
    right_y = 6;
    left_edge = 0;
    right_edge = 24;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "northeast";
    add_block_top(block, 9, 5, 9, 5, "northeast");
    left_x++;
    right_x++;
    return 1;
  }

  switch(previous_direction)
  {
  case "northnortheast":
    report("Adding nne_ne block to top");
    add_block_top(NNE_NE_BLOCK, 9,5,9,5, "northeast");
    left_x--;
    right_x--;
    add_block_top(block, 9,5,9,5, "northeast");
    left_x++;
    right_x++;
    break;
  case "none":
  case "northeast":
    report ("Adding ne_block to top twice");
    add_block_top(NE_BLOCK, 9,5,9,5, "northeast");
    left_x++;
    right_x++;
    add_block_top(block, 9,5,9,5, "northeast");
    left_x++;
    right_x++;
    break;
  case "north":
    report("Adding n_ne block to top");
    add_block_top(N_NE_BLOCK,4,4,4,4, "northeast");
    add_block_top(block, 9,5,9,5, "northeast");
    break;
  case "northwest":
    report("Adding se_sw block to top");
    left_x-=3;
    right_x-=3;
    add_block_top(NW_NE_BLOCK,0,5,0,5, "northeast");
    left_x+=3;
    right_x+=3;
    add_block_top(block, 9,5,9,5, "northeast");
    break;
  case "eastnortheast":
    report("Adding ene_ne block to right");
//    left_y++;
//    right_y++;
    add_block_right(ENE_NE_BLOCK, 4,1,19,8, "northeast");
    add_block_top(block, 9,5,9,5, "northeast");
    break;
  case "east":
    report("Adding e_ne block to right");
    left_x++;
    right_x++;
    add_block_right(E_NE_BLOCK, 2,1,17,8, "northeast");
    add_block_top(block, 9,5,9,5, "northeast");
    left_x++;
    right_x++;
    break;
  case "eastsoutheast":
    report("Adding ese_ne block to right");
    add_block_right(ESE_NE_BLOCK,10,2,25,9, "northeast");
    left_x--;
    right_x--;
    add_block_top(NE_BLOCK, 9,5,9,5, "northeast");
    right_x++;
    left_x++;
    break;
  case "southeast":
    report("Adding sene block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SE_NE_BLOCK, 4,-1,32,-1, "northeast", 0, -6);
    left_y++;
    right_y++;
    left_x++;
    right_x+=3;
    break;
  case "northnorthwest":
    report ("adding sw_sse_block to top");
    left_x-=6;
    right_x-=6;
    add_block_top(SW_SSE_BLOCK,4,5,4,5, "northnortheast");
    left_x--;
    right_x--;
    add_block_top(block, 9,5,9,5, "northnortheast");
    break;
  }
  previous_direction = "northeast";
  return 1;
}

int add_eastnortheast_block(){
  string * block;
  int pos, sprite_x;
  block = ENE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position;
    sprite_x = 7 + query_x_correction(current_direction, "eastnortheast");// + current_position/4;
    pos ++;
    report("Y correction: " + query_y_correction(current_direction));
    if (query_y_correction(current_direction)!=0)  pos -= query_y_correction(current_direction);
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_eastnortheast_block");
  }

  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")

  {
    special_report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "ENE"), block, 0, obstacle_placements[build_progress]+2, obstacles[build_progress]);
  } else special_report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );

  if(sizeof(display)<1)
  {
    display = ENE_BLOCK;
    left_x = 11;
    right_x = 11;
    left_y = 11;
    right_y = 4;
    left_edge = 0;
    right_edge = 11;
    top_edge = 11;
    bottom_edge = 0;
    trim_display();
    previous_direction = "eastnortheast";
    left_x++;
    right_x++;
    add_block_top(block, 11, 4, 11, 4, "eastnortheast");
    left_y--;
    right_y--;
    return 1;
  }
  switch(previous_direction)
  {
  case "none":
  case "north":
    report("Adding n_ene block to top");
    add_block_top(N_ENE_BLOCK, 18,8,3,1, "eastnortheast");
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    break;
  case "northeast":
    report("Adding ne_ene block to top");
    left_x++;
    right_x++;
    add_block_top(NE_ENE_BLOCK, 20,9,5,2, "eastnortheast");
    left_x++;
    right_x ++;
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
//    left_x --;
//    right_x --;
    break;
  case "northnortheast":
    report("Adding nne_ene block to top");
    add_block_top(NNE_ENE_BLOCK, 20,9,5,2, "eastnortheast");
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    break;
  case "eastnortheast":
    report("Adding ene block to right twice");
    left_x++;
    right_x++;
    add_block_right(ENE_BLOCK, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    left_x++;
    right_x++;
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
 //   left_x++;
 //   right_x++;
    break;
  case "east":
    report("Adding e_ene block to right");
    add_block_right(E_ENE_BLOCK,13,2,13,2, "eastnortheast");
    left_y++;
    right_y++;
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    break;
  case "eastsoutheast":
    report("Adding ese_ene block to right");
    left_y-=2;
    right_y-=2;
    add_block_right(ESE_ENE_BLOCK,15,0,15,0, "eastnortheast");
    left_y+=2;
    right_y+=2;
    add_block_right(block, 11,4,11,4, "eastnortheast");
//    left_x--;
//    right_x--;
    left_y--;
    right_y--;
//    left_x++;
//    right_x++;
    break;
  case "southeast":
    report("Adding se_ene block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SE_ENE_BLOCK, 4,0,19,-7, "eastnortheast", 0, -1);
//    left_y+=2;
//    right_y+=2;
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    break;
  case "southsoutheast":
    report("Adding sse_ene block to bottom");
    left_y--;
    right_y--;
    add_block_bottom(SSE_ENE_BLOCK, 4,0,19,-7, "eastnortheast");
    left_y+=2;
    right_y+=2;
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    break;
  case "northnorthwest":
    report("Adding sse_ene block to bottom");
    add_block_top(WSW_SSE_BLOCK, 19,9,4,2, "eastnortheast");
    add_block_right(block, 11,4,11,4, "eastnortheast");
    left_y--;
    right_y--;
    break;
  }
  previous_direction = "eastnortheast";
  return 1;
}

int add_east_block(){
  string * block;
  int pos, sprite_x;
  block = E_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position;
    sprite_x = 4 + query_x_correction(current_direction, "east" );
    pos ++;
    report("Y correction: " + query_y_correction(current_direction));
//    if (current_position >2) pos ++;
    if (query_y_correction(current_direction)!=0)  pos -= query_y_correction(current_direction);
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_eastnortheast_block");
  }


  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "E"), block, 1, obstacle_placements[build_progress]+1, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );


  if(sizeof(display)<1)
  {
    display = E_BLOCK;
    left_x = 7;
    right_x = 7;
    left_y = 8;
    right_y = 1;
    left_edge = 0;
    right_edge = 7;
    top_edge = 8;
    bottom_edge = 0;
    trim_display();
    previous_direction = "east";
    add_block_right(block, 8, 0, 8, 0, "east");
    return 1;
  }
  switch(previous_direction)
  {
  case "none":
  case "north":
    report("Adding n_e block to top");
    add_block_top(N_E_BLOCK, 15,7,0,0, "east");
    add_block_right(block, 8,0,8,0, "east");
    break;
  case "northnortheast":
    report("Adding nne_e block to top");
    add_block_top(NNE_E_BLOCK, 18,8,3,1, "east");
    left_x ++;
    right_x ++;
    left_y++;
    right_y++;
    add_block_right(block, 8,0,8,0, "east");
    break;
  case "northeast":
    report("Adding ne_e block to top");
    add_block_top(NE_E_BLOCK, 20,9,5,2, "east");
    add_block_right(block, 8,0,8,0, "east");
    break;
  case "eastnortheast":
    report("Adding ene_e block to right");
//    left_y--;
//    right_y--;
    add_block_right(ENE_E_BLOCK,16,4,16,4, "east");
    add_block_right(block, 8,0,8,0, "east");
    left_x--;
    right_x--;
//    left_y--;
//    right_y--;
    break;
  case "east":
    report("Adding e block to right twice");
    left_x++;
    right_x++;
    add_block_right(E_BLOCK, 8,0,8,0, "east");
    add_block_right(block, 8,0,8,0, "east");
    left_x--;
    right_x--;
    break;
  case "eastsoutheast":
    report("Adding ese_e block to right");
    add_block_right(ESE_E_BLOCK,15,-4,15,-4, "east");
    add_block_right(block, 8,0,8,0, "east");
    break;
  case "southsoutheast":
    report("Adding sse_e block to bottom");
    add_block_bottom(SSE_E_BLOCK,2,-1,17,-8, "east");
    left_x++;
    right_x++;
    add_block_right(block, 8,0,8,0, "east");
    break;
  case "southeast":
    report("Adding se_e block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SE_E_BLOCK, 4,-2,19,-9, "east");
 //   left_y -=2;
 //   right_y -=2;
    add_block_right(block, 8,0,8,0, "east");
//    left_x--;
//    right_x--;
//    left_y++;
//    right_y++;
    break;
  case "south":
    report("Adding s_e block to bottom");
    add_block_bottom(S_E_BLOCK, 0,0, 15,-7);
//    add_block_right(block, 8,0,8,0);
    break;
  }
  previous_direction = "east";
  return 1;
}

int add_eastsoutheast_block(){
  string * block;
  int pos, sprite_x;
  block = ESE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position;
    sprite_x = 0; //
    if (current_position>1) sprite_x++;
    pos +=3;
    report("Y correction: " + query_y_correction(current_direction));
//    if (current_position>3) pos --;
    if (query_y_correction(current_direction)!=0)  pos -= query_y_correction(current_direction);
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_eastnortheast_block");
  }

  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "ESE"), block, 0, obstacle_placements[build_progress]+1, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );

  if(sizeof(display)<1)
  {
    display = ESE_BLOCK;
    left_x = 8;
    right_x = 8;
    left_y = 8;
    right_y = 1;
    left_edge = 0;
    right_edge = 8;
    top_edge = 11;
    bottom_edge = 0;
    trim_display();
    previous_direction = "eastsoutheast";
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    return 1;
  }
  switch(previous_direction)
  {
  case "none":
    report("Adding ese block to top");
    add_block_top(ESE_BLOCK, 9,-3,9,-3, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    break;
  case "northnortheast":
    report("Adding nne_ese block to top");
    add_block_top(NNE_ESE_BLOCK, 17,8,2,1, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    break;
  case "northeast":
    report("adding ne_ese block to top");
    add_block_top(NE_ESE_BLOCK, 16,8,1,1, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    break;
  case "eastsoutheast":
    report("Adding ese block to right twice");
    add_block_right(ESE_BLOCK, 9,-3,9,-3, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    break;
  case "east":
    report("Adding e_ese block to right");
    add_block_right(E_ESE_BLOCK,11,-3,11,-3, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    left_x++;
    right_x++;
    break;
  case "eastnortheast":
    report("Adding ene_ese block to right");
//    left_y++;
//    right_y++;
    add_block_right(ENE_ESE_BLOCK,14,0,14,0, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    break;
  case "southeast":
    report("Adding se_ese block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SE_ESE_BLOCK, 4,-2,19,-9, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    left_x--;
    right_x--;
    break;
  case "southsoutheast":
    report("Adding sse_ese block to bottom");
    add_block_bottom(SSE_ESE_BLOCK, 3,-2,18,-9, "eastsoutheast");
    left_x++;
    right_x++;
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    left_x--;
    right_x--;
    break;
  case "south":
    report("Adding s_ese block to bottom");
    add_block_bottom(S_ESE_BLOCK, 2,-2,17,-9, "eastsoutheast");
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    break;
  case "southsouthwest":
    report("Adding southsouthwest_eastsoutheast block to bottom");
    left_x-=4;
    right_x-=4;
    add_block_bottom(SSW_ESE_BLOCK,0,-12,15 ,-5, "eastsoutheast");
    left_x+=2;
    right_x+=2;
    left_y--;
    right_y--;
    add_block_right(block, 9,-3,9,-3, "eastsoutheast");
    left_x--;
    right_x--;
    left_y++;
    right_y++;
    break;
  }
  previous_direction = "eastsoutheast";
  return 1;
}

int add_southeast_block(){
  string * block;
  int pos, sprite_x;
  block = SE_BLOCK;
  if (build_progress == current_progress)
  {
    pos = 3;
    sprite_x = 21+ query_x_correction(current_direction, "southeast") - current_position*2;
    report("Y correction: " + query_y_correction(current_direction));
    if (query_y_correction(current_direction)!=0)  pos -= query_y_correction(current_direction);
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_eastnortheast_block");
  }

  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "SE"), block, 13-(obstacle_placements[build_progress]*2) , 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );



  if(sizeof(display)<1)
  {
    display = SE_BLOCK;
    left_x = 25;
    right_x = 10;
    left_y = 1;
    right_y = 1;
    left_edge = 0;
    right_edge = 25;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "southeast";
    add_block_bottom(block, 10,-5,10,-5, "southeast");
    left_x--; right_x--;
    return 1;
  }
  switch(previous_direction)
  {
  case "none":
  case "northeast":
    report("Adding ne_se block to top");
    add_block_top(NE_SE_BLOCK, 36,-1,6,-1, "southeast");
    break;
  case "eastsoutheast":
    report("Adding ese_se block to right");
    add_block_right(ESE_SE_BLOCK,21,-10,6,-3, "southeast");
    left_y--;
    right_y--;
    left_x+=2;
    right_x+=2;
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "eastnortheast":
    report("Adding ene_se block to right");
//    left_y++;
//    right_y++;
    add_block_right(ENE_SE_BLOCK,20,-8,5,-1, "southeast");
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "east":
    report("Adding e_se block to right");
    add_block_right(E_SE_BLOCK,17,-8,2,-1, "southeast");
    left_y--;
    right_y--;
    left_x ++;
    right_x ++;
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "southeast":
    report("Adding se block to bottom twice");
    left_x++;
    right_x++;
    add_block_bottom(SE_BLOCK, 9,-5,9,-5, "southeast");
    left_x++;
    right_x++;
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "southsoutheast":
    report("Adding sse_se block to bottom");
    left_y++;
    right_y++;
    add_block_bottom(SSE_SE_BLOCK, 8,-6,8,-6, "southeast");
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "south":
    report("Adding s_se block to bottom");
    add_block_bottom(S_SE_BLOCK, 6, -5, 6,-5, "southeast");
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "southsouthwest":
    report("Adding ssw_se block to bottom");
    left_x-=5;
    right_x-=5;
    add_block_bottom(SSW_SE_BLOCK, 2,-5,2,-5, "southeast");
    left_x+=3;
    right_x+=3;
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  case "southwest":
    report("Adding sw_se block to bottom");
    left_x-=3;
    right_x-=3;
    left_y--;
    right_y--;
    add_block_bottom(SW_SE_BLOCK, 2,-5,2,-5, "southeast");
    left_x+=2;
    right_x+=2;
    add_block_bottom(block, 9,-5,9,-5, "southeast");
    break;
  }
  previous_direction = "southeast";
  return 1;
}

int add_southsoutheast_block(){
  string * block, * temp_block;
  int pos, sprite_y;
  block = SSE_BLOCK;
  temp_block = block;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 13;
    else pos = 13- (current_position *2);
 //   if (current_position>2) pos --;
    sprite_y=0;
    pos += query_x_correction(current_direction, "southsoutheast");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, sprite_y);
  }
  if (sizeof(block)<1) block = temp_block;
  temp_block = block;


  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "SSE"), block, 15- (obstacle_placements[build_progress] *2) , 2, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress);

  if (sizeof(block)<1) block = temp_block;

  if(sizeof(display)<1)
  {
    display = SSE_BLOCK;
    left_x = 20;
    right_x = 5;
    left_y = 1;
    right_y = 1;
    left_edge = 0;
    right_edge = 20;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "southsoutheast";
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    return 1;
  }
  switch(previous_direction)
  {
  case "east":
    report("Adding e_sse block to right");
    left_x++;
    right_x++;
    left_y++;
    right_y++;
    add_block_right(E_SSE_BLOCK, 17,-8,2,-1, "southsoutheast");
    left_x++;
    right_x++;
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    break;
 case "eastnortheast":
    report("Adding ene_sse block");
    left_y--;
    right_y--;
    add_block_right(ENE_SSE_BLOCK, 19,-7,4,0, "southsoutheast");
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    break;
  case "eastsoutheast":
    report("Adding ese_sse block to right");
    left_y++;
    right_y++;
    add_block_right(ESE_SSE_BLOCK, 18,-8,3,-1, "southsoutheast");
    left_x--;
    right_x--;
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    break;
  case "southeast":
    report("Adding se_sse block to bottom");
    left_x++;
    right_x++;
    left_y++;
    right_y++;
    add_block_bottom(SE_SSE_BLOCK, 7,-6,7,-6, "southsoutheast");
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    break;
  case "southsoutheast":
    report("Adding sse block to bottom twice");
    add_block_bottom(SSE_BLOCK, 5,-5,5,-5, "southsoutheast");
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    break;
  case "none":
  case "south":
    report("Adding s_sse block to bottom");
    left_y++;
    right_y++;
    add_block_bottom(S_SSE_BLOCK, 2,-5,2,-5, "southsoutheast");
    left_y++;
    right_y++;
    add_block_bottom(SSE_BLOCK, 5,-5,5,-5, "southsoutheast");
    break;
  case "southwest":
    report("Adding sw_sse block to bottom");
    left_x-=8;
    right_x-=8;
    left_y++;
    right_y++;
    add_block_bottom(SW_SSE_BLOCK, 5,-6, 5,-6, "southsoutheast");
    left_x-=3;
    right_x-=3;
    add_block_bottom(block, 5,-5,5,-5, "southsoutheast");
    break;
  case "southsouthwest":
    report("Adding ssw_sse block to bottom");
    add_block_bottom(SSW_SSE_BLOCK, -2,-5, -2,-5, "southsoutheast");
    add_block_bottom(SSE_BLOCK, 5,-5,5,-5, "southsoutheast");
    break;
  case "westsouthwest":
    report("Adding wsw_sse  block to bottom");
    add_block_bottom(WSW_SSE_BLOCK, -4,-2, -19,-9, "southsoutheast");
    add_block_bottom(SSE_BLOCK, 5,-5,5,-5, "southsoutheast");
    break;
  }
  previous_direction = "southsoutheast";
  return 1;
}


int add_south_block(){
  string * block;
  int pos, sprite_y;
  block = N_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 13;
    else pos = 13- (current_position *2);
//    if (current_position>2) pos --;
    sprite_y=-1;
    pos += query_x_correction(current_direction, "south");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, sprite_y);
  }


  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "S"), block, 13-(obstacle_placements[build_progress]*2), 2, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );



  if(sizeof(display)<1)
  {
    display = N_BLOCK;
    left_x = 15;
    right_x = 0;
    left_y = 1;
    right_y = 1;
    left_edge = 0;
    right_edge = 15;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "south";
    add_block_bottom(block, 0,-5,0,-5, "south");
    return 1;
  }
  switch(previous_direction)
  {
  case "eastsoutheast":
    report("Adding ese_s block to right");
    add_block_right(ESE_S_BLOCK, 4,-8,18,-1, "south");
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "none":
    report("Adding n block to bottom twice");
    add_block_bottom(N_BLOCK, 0,-5,0,-5, "south");
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "east":
    report("Adding eastsouth block to right");
    add_block_right(E_S_BLOCK, 18,-9,3,-2, "south");
    left_x-=2;
    right_x-=2;
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "southeast":
    report("Adding se_s block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SE_S_BLOCK, 7,-6,7,-6, "south");
    left_y++;
    right_y++;
    left_x--;
    right_x--;
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "southsoutheast":
    report("Adding sse_s block to bottom");
    add_block_bottom(SSE_S_BLOCK, 4,-6,4,-6, "south");
    left_y++;
    right_y++;
    left_x--;
    right_x--;
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "south":
    report("Adding s_s block to bottom twice");
    add_block_bottom(N_BLOCK, 0,-5,0,-5, "south");
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "southsouthwest":
    report("Adding N_NNE block to bottom");
    add_block_bottom(N_NNE_BLOCK, -1,-4,-1,-4, "south");
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "southwest":
    report("Adding N_NE block to bottom");
    add_block_bottom(N_NE_BLOCK, -4,-4,-4,-4, "south");
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "westsouthwest":
    report("Adding N_ENE block to left");
    left_x--;
    right_x--;
    left_y--;
    right_y--;
    add_block_left(WSW_S_BLOCK ,-3,-2,-18,-9, "south");
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  case "west":
    report("Adding n_e block to left");
    add_block_left(N_E_BLOCK, -2,0,-17,-7, "south");
    left_y--;
    right_y--;
    add_block_bottom(block, 0,-5,0,-5, "south");
    break;
  }
  previous_direction = "south";
  return 1;
}

int add_southsouthwest_block(){
  string * block;
  int pos, sprite_y;
  block = NNE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 13;
    else pos = 13- (current_position *2);
    if (current_position>3) pos --;
    sprite_y=0;
    pos += query_x_correction(current_direction, "southsouthwest");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, sprite_y);
  }

  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "SSW"), block, 2*obstacle_placements[build_progress]+3, 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress);

  if(sizeof(display)<1)
  {
    display = NNE_BLOCK;
    left_x = 15;
    right_x = 0;
    left_y = 1;
    right_y = 1;
    left_edge = 0;
    right_edge = 24;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "southsouthwest";
    add_block_bottom(block, -5,-5,-5,-5, "southsouthwest");
    return 1;
  }
  switch(previous_direction)
  {
  case "eastsoutheast":
    report("Adding ese_ssw block to left");
    add_block_right(ESE_SSW_BLOCK, 18, -10, 4, -3, "southsouthwest");
    left_x++;
    right_x++;
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "west":
    report("Adding nne_e block to left");
    left_y--;
    right_y--;
    add_block_left(NNE_E_BLOCK, -3,-1,-18,-8, "southsouthwest");
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "westsouthwest":
    report("Adding nne_ese block to right");
    left_x--;
    right_x--;
    left_y++;
    right_y++;

    add_block_left(NNE_ENE_BLOCK, -3,-3,-18,-10, "southsouthwest");
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "none":
  case "south":
    report("Adding nne_n block to bottom");
    add_block_bottom(NNE_N_BLOCK, -3,-6,-3,-6, "southsouthwest");
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "southeast":
    report("Adding nne_nw block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(NNE_NW_BLOCK, 4,-6,4,-6, "southsouthwest");
    right_x++;
    left_x++;
//    left_y++;
//    right_y++;
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "southwest":
    report("Adding nne_ne block to bottom");
    add_block_bottom(NNE_NE_BLOCK, -8,-5,-8,-5, "southsouthwest");
//    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "southsoutheast":
    report("Adding nne_nnw block to bottom");
    add_width_right(5);
    add_block_bottom(SSE_SSW_BLOCK, 5,-6,1,-6, "southsouthwest");
    left_x-=4;
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "southsouthwest":
    report("Adding nne_nne block to bottom twice");
    add_block_bottom(NNE_BLOCK,-5,-5,-5,-5, "southsouthwest");
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  case "westnorthwest":
    report("Adding nne_ene block to bottom twice");
    add_block_left(NNE_ENE_BLOCK,-5,-2,-20,-9, "southsouthwest");
    add_block_bottom(block,-5,-5,-5,-5, "southsouthwest");
    break;
  }
  previous_direction = "southsouthwest";
  return 1;
}


int add_southwest_block(){
  string * block;
  int pos, sprite_y;
  block = NE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 13;
    else pos = 13- (current_position *2);
//    if (current_position>2) pos --;
    sprite_y=0;
    pos += query_x_correction(current_direction, "southwest");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, sprite_y);
  }


  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "SW"), block, 18-(obstacle_placements[build_progress]*2), 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );



  if(sizeof(display)<1)
  {
    display = NE_BLOCK;
    left_x = 15;
    right_x = 0;
    left_y = 1;
    right_y = 1;
    left_edge = 0;
    right_edge = 24;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "southwest";
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    return 1;
  }
  switch(previous_direction)
  {
  case "southeast":
    report("Adding se_sw block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SE_SW_BLOCK, 0,-7,0,-7, "southwest");
    left_y++;
    right_y++;
    left_x--;
    right_x--;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "none":
  case "south":
    report("Adding ne_n block to bottom");
    add_block_bottom(NE_N_BLOCK, -6,-6,-6,-6, "southwest");
    left_x--;
    right_x--;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "southsoutheast":
    report("Adding sse_sw block to bottom");
    left_x --;
    right_x --;
    add_block_bottom(SSE_SW_BLOCK, 0,-6,0,-6, "southwest");
//    left_x --;
//    right_x --;
//    left_y++;
//    right_y++;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "southsouthwest":
    report("Adding ss_sw block to bottom");
    left_y++;
    right_y++;
    left_x--;
    right_x--;
    add_block_bottom(NE_NNE_BLOCK, -7,-6,-7,-6, "southwest");
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "southwest":
    report("Adding ne block to bottom twice");
    add_block_bottom(NE_BLOCK,-10,-5,-10,-5, "southwest");
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "westnorthwest":
    report("Adding ne_ene block to left");
    add_block_left(NE_ENE_BLOCK, -4,-2,-19,-9, "southwest");
    left_y--;
    right_y--;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "west":
    report("Adding ne_e block to left");
    add_block_left(NE_E_BLOCK, -6,-2,-21,-9, "southwest");
    left_y--;
    right_y--;
    left_x--;
    right_x--;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "westsouthwest":
    report("Adding ne_ene block to left");
    left_x--;
    right_x--;
    add_block_left(NE_ENE_BLOCK, -5,-2,-19,-9, "southwest");
    left_y--;
    right_y--;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  case "northwest":
    report("Adding ne_se block to top");
    add_block_top(NE_SE_BLOCK, -7,0,-37,0, "southwest");
    left_x--;
    right_x--;
    left_y--;
    right_y--;
    add_block_bottom(block, -10,-5,-10,-5, "southwest");
    break;
  }
  previous_direction = "southwest";
  return 1;
}

int add_westsouthwest_block(){
  string * block;
  int pos, sprite_x;
  block = ENE_BLOCK;
  if (build_progress == current_progress)
  {
    pos = 6-current_position;
    sprite_x = 5 + query_x_correction(current_direction, "westsouthwest");// - current_position/3;
    pos +=2;
    report("Y correction: " + query_y_correction(current_direction), "westsouthwest");
//    if (current_position>3) pos --;
    if (query_y_correction(current_direction, "westsouthwest")!=0)  pos -= query_y_correction(current_direction, "westsouthwest");
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
  }
  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "WSW"), block, 0, 8-obstacle_placements[build_progress], obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress );

  if(sizeof(display)<1)
  {
    display = ENE_BLOCK;
    left_x = 0;
    right_x =0;
    left_y = 1;
    right_y = 8;
    left_edge = 0;
    right_edge = 12;
    top_edge = 24;
    bottom_edge = 0;
    trim_display();
    previous_direction = "westsouthwest";
    add_block_bottom(block, -12,-3,-12,-3, "westsouthwest");
    return 1;
  }
  switch(previous_direction)
  {
  case "none":
    report("Adding ene block to top");
    add_block_top(ENE_BLOCK,0,0,0,7, "westsouthwest");

    break;
  case "northnorthwest":
    report("Adding ene block to top");
    add_block_top(ENE_SSE_BLOCK, -3,1,-18,8, "westsouthwest");
    left_y++;
    right_y++;
    add_block_bottom(block, -11,-4,-11,-4, "southwest");
    break;
  case "northwest":
    report("Adding ene_se block to top");
    add_block_top(NW_WSW_BLOCK, -6,1,-21,8, "westsouthwest");
//    add_block_bottom(block, -11,-5,-11,-5, "southwest");
    break;
  case "westnorthwest":
    report ("adding ene_ese block to left");
    add_block_left(ENE_ESE_BLOCK, -14,0,-14,0, "westsouthwest");
    left_y++;
    right_y++;
    left_x--;
    right_x--;
    add_block_bottom(block, -11,-4,-11,-4, "southwest");
    break;
  case "west":
    report ("adding ene_e block to left");
    add_block_left(ENE_E_BLOCK, -14,-4,-14,-4, "westsouthwest");
    left_y++;
    right_y++;
    add_block_bottom(block, -11,-4,-11,-4, "southwest");
    break;
  case "westsouthwest":
    report("Adding ene block to left twice");
    left_x--;
    right_x--;
    left_y++;
    right_y++;
    add_block_bottom(ENE_BLOCK, -11,-4,-11,-4, "southwest");
    left_y++;
    right_y++;
    left_x--;
    right_x--;
    add_block_bottom(block, -11,-4,-11,-4, "southwest");
    break;
  case "south":
    report("Adding ene_n block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(ENE_N_BLOCK, -19,-8,-4,-1, "westsouthwest");
    left_x--;
    right_x--;
    left_y++;
    right_y++;
    add_block_bottom(block, -11,-4,-11,-4, "southwest");
    break;
  case "southsouthwest":
    report("Adding ene_nne block to bottom");
    add_block_bottom(ENE_NNE_BLOCK, -18,-8,-3,-1, "westsouthwest");
    left_x--;
    right_x--;
    left_y++;
    right_y++;
    add_block_bottom(block, -11,-4,-11,-4, "southwest");
    break;
  case "southwest":
    report("Adding ene_ne block to bottom");
    add_block_bottom(ENE_NE_BLOCK, -17,-8,-3,-1, "westsouthwest");
    add_block_bottom(block, -12,-3,-12,-3, "westsouthwest");
    break;
  case "southsoutheast":
    report("Adding sse_wsw block to bottom");
    left_x++;
    right_x++;
    add_block_bottom(SSE_WSW_BLOCK, -16,-10,-1,-3, "westsouthwest");
    left_x--;
    right_x--;
    left_y+=2;
    right_y+=2;
    add_block_bottom(ENE_BLOCK, -8,-4,-8,-4, "westsouthwest");
    left_y++;
    right_y++;
    break;
  }
  previous_direction = "westsouthwest";
  return 1;
}

int add_west_block(){
  string * block;
  int pos, sprite_x;
  block = E_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 6;
    else pos = 6 - current_position -1;
    sprite_x = 1 + query_x_correction(current_direction, "west" );
    pos ++;
    report("Y correction: " + query_y_correction(current_direction, "west"));
//    if (current_position >2) pos ++;
    if (query_y_correction(current_direction, "west")!=0)  pos -= query_y_correction(current_direction, "west");
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_west_block");
  }


  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "W"), block,0, 7-obstacle_placements[build_progress], obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT ");



  if(sizeof(display)<1)
  {
    display = E_BLOCK;
    left_x = 0;
    right_x = 0;
    left_y = 1;
    right_y = 8;
    left_edge = 0;
    right_edge = 8;
    top_edge = 8;
    bottom_edge = 0;
    trim_display();
    previous_direction = "west";
    add_block_left(block, -8,0,-8,0, "west");
    return 1;
  }
  switch(previous_direction)
  {
  case "south":
  case "none":
    report("Adding s_w block to bottom");
    add_block_bottom(S_W_BLOCK, -17,-7,-2,0, "west");
    left_y--;
    right_y--;
    add_block_left(block, -8,0,-8,0, "west");
    left_y++;
    right_y++;
    break;
  case "southwest":
    report("Adding e_ne block to bottom");
    add_block_bottom(E_NE_BLOCK, -17,-8,-2,-1, "west");
//    left_y--;
//    right_y--;
    add_block_left(block, -8,0,-8,0, "west");
 //   left_y++;
 //   right_y++;
    break;
  case "southsouthwest":
    report("Adding e_nne block to bottom");
    left_x--;
    right_x--;
    add_block_bottom(E_NNE_BLOCK, -16,-8,-1,-1, "west");
    add_block_left(block, -8,0,-8,0, "west");
    break;
  case "westsouthwest":
    report("Adding e_ene block to left");
    left_y++;
    right_y++;
    add_block_left(E_ENE_BLOCK, -11,-4,-11,-4, "west");
    add_block_left(block, -8,0,-8,0, "west");
    break;
  case "west":
    report("Adding e_block to left twice");
    add_block_left(E_BLOCK, -8, 0, -8, 0, "west");
    add_block_left(block, -8, 0, -8, 0, "west");
    break;
  case "northwest":
    report("Adding e_se block to top");
    add_block_top(NW_W_BLOCK, -1,1,-16,8, "west");
    left_y-=2;
    right_y-=2;
    left_x++;
    right_x++;
    add_block_left(block, -8, 0, -8, 0, "west");
    left_y ++;
    right_y ++;
    break;
  case "north":
    report("Adding n_w block to top");
    add_block_top(N_W_BLOCK, -2,1,-17,8, "west");
    left_x++;
    right_x++;
    add_block_left(block, -8, 0, -8, 0, "west");
    break;
  case "northnorthwest":
    report("Adding e_sse block to top");
    add_block_top(E_SSE_BLOCK, -2,0,-17,7, "west");
    add_block_left(block, -4,0,-4,0, "west");
    break;
  }
  previous_direction = "west";
  return 1;
}

int add_westnorthwest_block(){
  string * block;
  int pos, sprite_x;
  block = ESE_BLOCK;
  if (build_progress == current_progress)
  {
    pos = 8- current_position;
    sprite_x = 2;
    sprite_x += query_x_correction(current_direction, "westnorthwest");
    report("Y correction: " + query_y_correction(current_direction, "westnorthwest"));
    if (query_y_correction(current_direction)!=0)  pos += query_y_correction(current_direction, "westnorthwest");
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_eastnortheast_block");
  }

  if (sizeof(obstacles) > build_progress && sizeof(obstacle_placements)>build_progress && obstacles[build_progress] != "none" && intp(obstacle_placements[build_progress]))
  {

    pos = 8 - obstacle_placements[build_progress];
    sprite_x = 3; // 7 - obstacle_placements[build_progress];
    if (intp(query_sprite_y_correction (obstacles[build_progress], 13)))  pos -= query_sprite_y_correction(obstacles[build_progress], 13);
    if (intp(query_sprite_x_correction (obstacles[build_progress], 13)))  sprite_x += query_sprite_x_correction(obstacles[build_progress], 13);
    // special_report("%^BOLD%^%^GREEN%^Y correction: " + query_sprite_y_correction (obstacles[build_progress], 13));
    // special_report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + obstacles[build_progress]);
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "WNW"), block, sprite_x, pos );
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress);



  if(sizeof(display)<1)
  {
    display = ESE_BLOCK;
    left_x = -1;
    right_x = -1;
    left_y = 4;
    right_y = 11;
    left_edge = 0;
    right_edge = 9;
    top_edge = 11;
    bottom_edge = 0;
    trim_display();
    previous_direction = "westnorthwest";
    add_block_left(block, -9,3,-9,3, "westnorthwest");
    return 1;
  }
  switch(previous_direction)
  {
  case "northnortheast":
    report("Adding ene_sse block to top");
    left_x++;
    right_x++;
    add_block_top(ENE_SSW_BLOCK, -4, 3, -19, 10, "westnorthwest");
    left_y--;
    right_y--;
    add_block_left(block, -9,3,-9,3, "westnorthwest");     left_y++;
    right_y++;
    break;
  case "north":
  case "none":
    report("Adding n_wnw block to top");
    add_block_top(N_WNW_BLOCK, -2,0,-17,7, "westnorthwest");
    left_x--;
    right_x--;
    add_block_left(block, -9, 3,-9,3, "westnorthwest");
    break;
  case "northwest":
    report("Adding ese_se block to top");
    add_block_top(NW_WNW_BLOCK, -6,2,-21,9, "westnorthwest");
    add_block_left(block, -9,3,-9,3, "westnorthwest");     break;
  case "northnorthwest":
    report("Adding ese_ssw block to top");
    add_block_top(ESE_SSE_BLOCK, -1, 0,-16, 7, "westnorthwest");
    add_block_left(block, -9,3,-9,3, "westnorthwest");     break;
  case "westnorthwest":
    report("adding ese_block to left twice");
    add_block_left(ESE_BLOCK, -9, 3,-9,3, "westnorthwest");
//    left_x--;
//    right_x--;
    add_block_left(block, -9, 3,-9,3, "westnorthwest");
    break;
  case "west":
    report("adding ese_e_block to left");
    add_block_left(ESE_E_BLOCK, -15,4,-15,4, "westnorthwest");
    add_block_left(block, -9, 3,-9,3, "westnorthwest");
    break;
  case "westsouthwest":
    report("Adding ese_ene block to right");
    left_y-=3;
    right_y-=3;
    left_x--;
    right_x--;
    add_block_left(ESE_ENE_BLOCK,-15,2,-15,2, "westnorthwest");
    add_block_left(block, -9, 3,-9,3, "westnorthwest");
    left_y++;
    right_y++;
    break;
  case "southwest":
    report("Adding ese_ne block to bottom");
    add_block_bottom(ESE_NE_BLOCK, -23,-9,-8,-2, "westnorthwest");
//    left_y--;
//    right_y--;
    left_x--;
    right_x--;
    add_block_left(block, -10, 2,-10,2, "westnorthwest");
    left_y++;
    right_y++;
    break;
  case "southsouthwest":
    report("Adding ese_nne block to right");
    left_y++;
    right_y++;
    add_block_bottom(ESE_NNE_BLOCK, -20,-10,-5,-3, "westnorthwest");
    left_y--;
    right_y--;
    left_x--;
    right_x--;
    add_block_left(block, -9, 3,-9,3, "westnorthwest");
    left_x++;
    right_x++;
    left_y++;
    right_y++;
    break;
  }
  previous_direction = "westnorthwest";
  return 1;
}

int add_northwest_block(){
  string * block;
  int pos, sprite_x, ob_x;
  block = SE_BLOCK;
  if (build_progress == current_progress)
  {
    pos = 0;
    sprite_x = 9+ query_x_correction(current_direction, "northwest")+ current_position*2;
    report("Y correction: " + query_y_correction(current_direction, "northwest"));
    if (query_y_correction(current_direction, "northwest")!=0)  pos -= query_y_correction(current_direction, "northwest");
    block = add_sprite_to_block(get_boat(current_direction), block, sprite_x, pos);
    if (sizeof(block)<1) report("%^B_GREEN%^Size of block is <1 in add_eastnortheast_block");
  }


  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    ob_x = obstacle_placements[build_progress]*2 + 1;
//    if (ob_x<2) ob_x = 0;
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "NW"), block, ob_x, 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");



  if(sizeof(display)<1)
  {
    display = SE_BLOCK;
    left_x = 0;
    right_x = 15;
    left_y = 6;
    right_y = 6;
    left_edge = 0;
    right_edge = 23;
    top_edge = 5;
 //   block  = add_sprite_to_block(get_sprite(obstacles[build_progress]), block, obstacle_placements[build_progress], 0);
    bottom_edge = 0;
    trim_display();
    previous_direction = "northwest";
    left_x--;
    right_x--;
    add_block_top(block, -9,5,-9,5, "northwest");
    return 1;
  }
  switch(previous_direction)
  {
  case "southwest":
    report("Adding se_ne block to bottom");
    add_block_bottom(SE_NE_BLOCK, -35,-7,-5,-7, "northwest");
    left_y += 7;
    right_y += 7;
    break;
  case "westnorthwest":
    report("Adding SE_ESE_BLOCK to left");
    add_block_left(SE_ESE_BLOCK,-19,9,-4,2, "northwest");
    left_x--;
    right_x--;
    add_block_top(block, -9,5,-9,5, "northwest");
    break;
  case "west":
    report("adding se_e_block to left");
    add_block_left(SE_E_BLOCK, -18,9,-3,2, "northwest");
    left_x --;
    right_x--;
    add_block_top(block, -9,5,-9,5, "northwest");
    break;
  case "westsouthwest":
    report("Adding se_ene block to left");
    left_y-=1;
    right_y-=1;
    add_block_left(SE_ENE_BLOCK, -18,8,-3,1, "northwest");
    left_x--;
    right_x--;
    add_block_top(block, -9,5,-9,5, "northwest");
    break;
  case "northnortheast":
    report("Adding nne_nw block to top");
    left_x--;
    right_x--;
    add_block_top(NNE_NW_BLOCK,-4,6,-4,6, "northwest");
    add_block_top(block, -9,5,-9,5, "northwest");
    break;
  case "northwest":
    report("Adding nw block to top twice");
    add_block_top(SE_BLOCK, -10,5,-10,5, "northwest");
    add_block_top(block, -10,5,-10,5, "northwest");
    break;
  case "northnorthwest":
    report("Adding se_sse block to top");
    add_block_top(SE_SSE_BLOCK,-7,5,-7,5, "northwest");
    left_x--;
    right_x--;
    add_block_top(block, -9,5,-9,5, "northwest");
    break;
  case "none":
  case "north":
    report("Adding se_s block to top");
    add_block_top(SE_S_BLOCK,-6,5,-6,5, "northwest");
    left_x--;
    right_x--;
    report("%^B_MAGENTA%^%^BOLD%^%^YELLOW%^Previous Direction: " + previous_direction);
    previous_direction = "north_northwest";
    add_block_top(block, -9,5,-9,5, "northwest");
    left_y++;
    right_y++;
    break;
  case "northeast":
    report("Adding NE_NW block to top");
    add_block_top(NE_NW_BLOCK,-1,6,-1,6, "northwest");
    add_block_top(block, -9,5,-9,5, "northwest");
    break;
  }
  previous_direction = "northwest";
  return 1;
}

int add_northnorthwest_block(){
  string * block;
  int pos;
  block = SSE_BLOCK;
  if (build_progress == current_progress)
  {
    if (current_position <1) pos = 0;
    else pos = current_position *2;
    pos +=2;
    pos += query_x_correction(current_direction, "northnorthwest");
    block = add_sprite_to_block(get_boat(current_direction), block, pos, 0);
  }

  if (sizeof(obstacles) > build_progress && obstacles[build_progress] != "none")
  {
    report("%^B_RED%^%^BOLD%^%^CYAN%^THERE IS AN OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");
    block  = add_sprite_to_block(get_sprite(obstacles[build_progress], "NNW"), block, (obstacle_placements[build_progress]*2)+1, 0, obstacles[build_progress]);
  } else report("%^B_GREEN%^%^BOLD%^%^RED%^THERE IS NO OBSTACLE AT POINT " + build_progress + ". THE OBSTACLE IS: " + "unknown");

  if(sizeof(display)<1)
  {
    display = SSE_BLOCK;
    left_x = 0;
    right_x = 15;
    left_y = 6;
    right_y = 6;
    left_edge = 0;
    right_edge = 21;
    top_edge = 5;
    bottom_edge = 0;
    trim_display();
    previous_direction = "northnorthwest";
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    return 1;
  }
  switch(previous_direction)
  {
  case "eastnortheast":
    report("Adding ene_nnw block to right");
    add_block_right(ENE_NNW_BLOCK, 1,4,15,11, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  case "none":
  case "north":
    report("Adding n_nnw block to top");
    add_block_top(N_NNW_BLOCK, -2,5,-2,5, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  case "northeast":
    report("Adding ne_nnw block to top");
    add_block_top(NE_NNW_BLOCK, 1,7,1,7, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  case "northwest":
    report("Adding sse_se block to top");
    add_block_top(SSE_SE_BLOCK, -8,5,-8,5, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  case "northnorthwest":
    report("Adding sse block to top twice");
    add_block_top(SSE_BLOCK, -5,5,-5,5, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  case "northnortheast":
    report("Adding sse_ssw block to top");
    add_block_top(SSE_SSW_BLOCK, -1,5,-1,5, "northnorthwest");
    left_y++;
    right_y++;
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    left_y++;
    right_y++;
    break;
  case "west":
    report("Adding sse_e block to left");
    add_block_left(SSE_E_BLOCK, -17,8,-2,1, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  case "westsouthwest":
    report("Adding sse_ene block to left");
    add_block_left(SSE_ENE_BLOCK, -18,-1,-3,-8, "northnorthwest");
    left_y+=9;
    right_y+=9;
    left_x-=4;
    right_x-=4;
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    left_x+=3;
    right_x+=3;
    break;
  case "westnorthwest":
    report("Adding sse_ese block to top");
    add_block_left(SSE_ESE_BLOCK, -22,9,-7,2, "northnorthwest");
    add_block_top(block, -5,5,-5,5, "northnorthwest");
    break;
  }
  previous_direction = "northnorthwest";
  return 1;
}

string query_previous_direction(){
  return previous_direction;
}

int show_block(string blockname){
  int * map;
  switch(blockname){
  case "n":
    map = N_BLOCK;
    break;
  case "nne":
    map = NNE_BLOCK;
    break;
  case "ne":
    map = NE_BLOCK;
    break;
  case "ene":
    map = ENE_BLOCK;
    break;
  case "e":
    map = E_BLOCK;
    break;
  case "ese":
    map = ESE_BLOCK;
    break;
  case "se":
    map = SE_BLOCK;
    break;
  case "sse":
    map = SSE_BLOCK;
    break;
  case "n_w":
    map = N_W_BLOCK;
    break;
  case "n_wnw":
    map = N_WNW_BLOCK;
    break;
  case "n_nw":
    map = N_NW_BLOCK;
    break;
  case "n_nnw":
    map = N_NNW_BLOCK;
    break;
  case "n_nne":
    map = N_NNE_BLOCK;
    break;
  case "n_ne":
    map = N_NE_BLOCK;
    break;
  case "n_ene":
    map = N_ENE_BLOCK;
    break;
  case "n_e":
    map = N_E_BLOCK;
    break;
  case "nne_wnw":
    map = NNE_WNW_BLOCK;
    break;
  case "nne_nw":
    map = NNE_NW_BLOCK;
    break;
  case "nne_nnw":
    map = NNE_NNW_BLOCK;
    break;
  case "nne_n":
    map = NNE_N_BLOCK;
    break;
  case "nne_ne":
    map = NNE_NE_BLOCK;
    break;
  case "nne_ene":
    map = NNE_ENE_BLOCK;
    break;
  }
  show_my_block(TP, map);
}

void report(string str){
//  "/daemon/reporter_d.c"->report("lujke", str);
}

string * query_display(){
  return display;
}

void show_whole_display(object who){
  string count_line;
  int i, count;
  if (sizeof(display)<1){
    tell_object(who, "No display");
  }
  show_map(who, display);
//  count = strlen(display[0]);
//  count_line = "  ";
//  for (i=0;i<count;i++)
//  {
//    if (i/10<1)
//    {
//      count_line += " ";
//    } else {
//      count_line += i/10;
//    }
//  }
//  tell_object(TP, count_line);
//  count_line = "";
//  for (i=0;i<count;i++)
//  {
//    count_line += i%10;
//  }
//  tell_object(TP, count_line);
//  tell_object(TP, "" + left_edge);
}

int query_left_x(){
  return left_x;
}

int query_right_x(){
  return right_x;
}

int query_left_edge(){
  return left_edge;
}

int query_right_edge(){
  return right_edge;
}

int query_left_y(){
  return left_y;
}

int query_right_y(){
  return right_y;
}

int trim_display(){
  int res;
  res = 1;
  while(res == 1) res = trim_top();
  res = 1;
  while(res == 1) res = trim_bottom();
  res = 1;
  while(res == 1) res = trim_left();
  res = 1;
  while(res == 1) res = trim_right();
  return 1;
}

int trim_top(){
  string line;
  int i, siz;
  siz = sizeof(display);
  if (siz<1) return 0;
  line = display[0];
  for (i=0;i<strlen(line);i++)
  {
    if (line[i..i]!= " ")
    {
      return 0;
    }
  }
  display = display[1..siz-1];
  top_edge --;
  return 1;
}

int trim_bottom(){
  string line;
  int i, siz;
  siz = sizeof(display);
  if (siz<1) return 0;
  line = display[siz-1];
  for (i=0;i<strlen(line);i++)
  {
    if (line[i..i]!= " ")
    {
      return 0;
    }
  }
  display = display[0..siz-2];
  bottom_edge++;
  return 1;
}

int trim_left(){
  int i, siz;
  string line;
  siz = sizeof(display);
  if (siz < 1) return 0;
  for (i=0;i<sizeof(display);i++)
  {
    line = display[i];
    if (line[0..0] != " ") return 0;
  }
  for (i=0;i<sizeof(display);i++)
  {
    line = display[i];
    line = line[1..sizeof(line)-1];
    display[i] = line;
  }
  left_edge ++;
  return 1;
}

int trim_right(){
  int i, siz;
  string line;
  siz = sizeof(display);
  if (siz < 1) return 0;
  for (i=0;i<sizeof(display);i++)
  {
    line = display[i];
    if (line[strlen(line)-1..strlen(line)-1] != " ") return 0;
  }
  for (i=0;i<sizeof(display);i++)
  {
    line = display[i];
    line = line[0..sizeof(line)-2];
    display[i] = line;
  }
  right_edge--;
  return 1;
}

void adjust_edges(){
  if (left_y>top_edge) top_edge = left_y;
  if (right_y>top_edge) top_edge = right_y;
  if (left_y<bottom_edge) bottom_edge = left_y;
  if (right_y<bottom_edge) bottom_edge = right_y;
  if (left_x>right_edge) right_edge = left_x;
  if (right_x>right_edge) right_edge = right_x;
  if (left_x<left_edge) left_edge = left_x;
  if (right_x<left_edge) left_edge = right_x;
}

void adjust_width(int left_adjust_x, int right_adjust_x){
  int new_left_x, new_right_x;
  new_left_x = left_x + left_adjust_x;
  new_right_x = right_x + right_adjust_x;
  report ("Adjusting width left. left_x: " + left_x + "  left_adjust_x: " + left_adjust_x + " new_left_x: " + new_left_x + "  right_x: " + right_x +" right_adjust_x: " + right_adjust_x + " new_right_x: " + new_right_x + " left_edge: " + left_edge + "  right_edge: " + right_edge);
  if (new_left_x < left_edge)
  {
    add_width_left( (new_left_x * -1) - (left_edge * -1));
  }
  if (new_right_x < left_edge)
  {
    add_width_left((new_right_x * -1) - (left_edge * -1));
  }
  if (new_left_x > right_edge)
  {
    add_width_right(new_left_x - right_edge);
  }
  if (new_right_x > right_edge)
  {
    add_width_right(new_right_x - right_edge);
  }
}

void add_width_left(int how_many){
  int i, count, j;
  string addition;
  count = sizeof(display);
  if (count<1 || how_many<1) return;
  addition = "";
  for(j=0;j<how_many;j++)
  {
    addition += " ";
  }
  for (i=0;i<count;i++)
  {
    display[i] = addition + display[i];
  }
  left_edge -= how_many;
}

void add_width_right(int how_many){
  int i, count, j;
  string addition;
  count = sizeof(display);
  if (count<1||how_many<1) return;
  addition = "";
  for(j=0;j<how_many;j++)
  {
    addition += " ";
  }
  for (i=0;i<count;i++)
  {
    display[i] = display[i] + addition;
  }
  right_edge += how_many;
}

varargs void adjust_height(int left_adjust_y, int right_adjust_y, int blocksize){
  int new_left_y, new_right_y, how_many, temp_bottom, temp_top;
  new_left_y = left_y + left_adjust_y;
  new_right_y = right_y + right_adjust_y;
  report("Adjusting height. left_y: " + left_y + " Right_y: " + right_y + " left_adjust_y: " + left_adjust_y + " right_adjust_y: " + right_adjust_y + " Top edge: " + top_edge + " Bottom edge: " + bottom_edge);
  temp_bottom = left_y;
  if (right_y < temp_bottom) temp_bottom = right_y;
  if (new_left_y<temp_bottom) temp_bottom = new_left_y;
  if (new_right_y<temp_bottom) temp_bottom = new_right_y;
  temp_bottom += blocksize;
  if (new_left_y<new_right_y)
  {
    if (new_left_y <= bottom_edge +1)
    {
      how_many = bottom_edge - new_left_y +1;
      report("%^BOLD%^%^RED%^ADJUST HEIGHT: Adding " + how_many + " lines to bottom");
      add_height_bottom(how_many);
    }
  } else
  {
    if (new_right_y <= bottom_edge +1)
    {
      how_many = bottom_edge - new_right_y +1;
      report("%^BOLD%^%^RED%^ADJUST HEIGHT: Adding " + how_many + " lines to bottom ");
      add_height_bottom(how_many);
    } else
    {
      report ("%^BOLD%^%^RED%^ADJUST_HEIGHT: No need to add any lines to bottom after initial check");
    }
  }
  if (temp_bottom<bottom_edge)
  {
      how_many = bottom_edge - temp_bottom +1;
      report("%^BOLD%^%^MAGENTA%^ADJUST HEIGHT SECONDARY CHECK: Adding " + how_many + " lines to bottom ");
      add_height_bottom(how_many);
  }
  if (new_left_y > top_edge -1)
  {
    how_many = new_left_y - top_edge+1;
      report("%^BOLD%^%^MAGENTA%^ADJUST HEIGHT: Adding " + how_many + " lines to top ");
    add_height_top(new_left_y - top_edge);
  }
  if (new_right_y > top_edge-1)
  {
    how_many = new_right_y - top_edge +1;
    report("%^BOLD%^%^MAGENTA%^ADJUST HEIGHT: Adding " + how_many + " lines to top ");
    add_height_top(new_right_y - top_edge);
  }
  temp_top = temp_bottom + blocksize+1;
  if (temp_top > top_edge)
  {
    add_height_top(temp_top - top_edge);
  }
  report("Height adjusted. New top edge: " + top_edge + " New bottom edge: " + bottom_edge);
}



add_height_top(int how_many){
  string line;
  int i, count;
  if (sizeof(display)<1) return;
  count = strlen(display[0]);

  line  = "";
  for (i=0;i<count;i++)
  {
    line += " ";
  }
  for (i=0;i<how_many;i++)
  {
    display = ({line}) + display;
  }
  top_edge += how_many;
}

add_height_bottom(int how_many){
  string line;
  int i, count;
  if (sizeof(display)<1) return;
  report("Adding " + how_many + " lines to the bottom edge");
  count = strlen(display[0]);
  line  = "";
  for (i=0;i<count;i++)
  {
    line += " ";
  }
  for (i=0;i<how_many;i++)
  {
    display =  display + ({line});
  }
//  left_y+=how_many;
//  right_y+= how_many;
  bottom_edge -= how_many;
}

varargs int add_block_top(string * block, left_adjust_x, left_adjust_y, right_adjust_x, right_adjust_y, string direction, left_point_adjust, right_point_adjust){
  int width, height, i, j, full_width, left_placement, top_point, bottom_point, x, y,leftest_x, rightest_x;
  string line;
  height = sizeof(block);
  report("%^BOLD%^%^YELLOW%^Add block top 1: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^1) Left edge: " + left_edge);
  if (height >0)
  {
    width = strlen(block[0]);
  }
  if (sizeof(display)<1){
    report("starting with a new block");
    display = block;
    left_x = query_initial_left_x(direction);
    left_y = query_initial_left_y(direction);
    right_x = query_initial_right_x(direction);
    right_y = query_initial_right_y(direction);
    left_edge = 0;
    right_edge = width-1;
    report("%^BOLD%^%^YELLOW%^Add block top 1a: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
    return;
  }
  report("%^BOLD%^%^YELLOW%^Add block top 2: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^2) Left edge: " + left_edge);

//  report ("display before adjusting width:");
//  show_whole_display(find_player("lujke"));
  adjust_width(left_adjust_x, right_adjust_x);
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^3) Left edge: " + left_edge);

//  report ("display AFTER adjusting width:");
//  show_whole_display(find_player("lujke"));
  adjust_edges();
  if(left_x < right_x)
  {
    x = left_x - left_edge;
  } else
  {
    x = right_x - left_edge;
  }
  if (left_y<right_y)
  {
    y = left_y - bottom_edge;
  } else
  {
    y = right_y - bottom_edge;
  }

////
  leftest_x = left_x;
  if (right_x < leftest_x) leftest_x = right_x;
  if (left_x + left_adjust_x < leftest_x) leftest_x = left_x + left_adjust_x;
  if (right_x + right_adjust_x < leftest_x) leftest_x = right_x + right_adjust_x;
  if (left_point_adjust<0) leftest_x+= left_point_adjust;
  x = leftest_x;
  x-= left_edge;
  rightest_x = left_x;
  if (right_x > rightest_x) rightest_x = right_x;
  if (left_x + left_adjust_x > rightest_x) rightest_x = left_x + left_adjust_x;
  if (right_x + right_adjust_x > rightest_x) rightest_x = right_x + right_adjust_x;
  if (right_point_adjust>0) rightest_x += right_point_adjust;
  x= leftest_x;
////
  report("%^BOLD%^%^YELLOW%^Add block top 3: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^4) Left edge: " + left_edge);
  if ( left_y<top_edge || right_y <top_edge )
  {
    report("inserting block into existing display");
    if (top_point > top_edge)
    {
      adjust_height(left_adjust_y, right_adjust_y, sizeof(block));
    }

    top_point = calculate_top_point (left_adjust_y, right_adjust_y, sizeof(block), sizeof(display));
    insert_block(block, x, top_point, direction);
  } else
  {
    report("adding block on top of existing display");
    full_width = strlen(display[0]);
//    if (left_x<right_x);
//      left_placement = left_x - left_edge;
//      if (left_adjust_x < 0) left_placement += left_adjust_x;
//    } else {
//      left_placement = right_x - left_edge;
//      left_placement = right_x - left_edge;
//      if (right_adjust_x < 0) left_placement += right_adjust_x;
//    }
    left_placement = x-left_edge;
    report("%^BOLD%^%^YELLOW%^Add block top 4: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^5) Left edge: " + left_edge);

    for (i=height-1;i>=0;i--)
    {
      line  = "";
      if (left_placement >0)
      {
        for (j=0;j<left_placement;j++)
        {
          line += " ";
        }
      }
      report("Trying to add block[i] to line. i: " + i + " size of block: " + sizeof(block));
      line += block[i];
      if (sizeof(display)>0)
      {
        while (strlen(line)<strlen(display[0]))
        {
          line += " ";
        }
      }
      report("Attempting to add line. i: "+ i );
      display =  ({ line })+ display;
      report("Line added");
    }
    adjust_width(left_adjust_x, right_adjust_x);
  }
  report("%^BOLD%^%^YELLOW%^Add block top 5: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^6) Left edge: " + left_edge);
  left_x += left_adjust_x;
  left_y += left_adjust_y;
  right_x += right_adjust_x;
  right_y += right_adjust_y;
  report("%^BOLD%^%^YELLOW%^Add block top 6: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  adjust_edges();
  report("Block added on top. left_x: " + left_x + "  right_x: " + right_x + "  left_y: " + left_y + "  right_y: " + right_y);
  trim_display();
  report("%^B_ORANGE%^%^BOLD%^%^WHITE%^7) Left edge: " + left_edge);

}

varargs int add_block_bottom(string * block, left_adjust_x, left_adjust_y,
right_adjust_x, right_adjust_y, string direction, int full_height, int top_point_adjust, int bottom_point_adjust, int right_point_adjust, int left_point_adjust){
  int width, height, i, j, full_width, left_placement, top_point, bottom_point, x, y,lower_left, lower_right, upper_left, upper_right,
leftest_x, rightest_x, bottom_left, bottom_right, top_left, top_right, temp_bottom, temp_top;
  string line;
  report("%^BOLD%^%^CYAN%^Add_block_bottom: left_adjust_x: " + left_adjust_x +" left_adjust_y: " + left_adjust_y +" right_adjust_x: " + right_adjust_x +" right_adjust_y: " + right_adjust_y +" direction: " + direction +" ");
  report("%^BOLD%^%^RED%^Starting coordinates: Left_x: " + left_x + " Left_y: " + left_y + " Right_x: " + right_x + " Right_y: " + right_y);
  height = sizeof(block);
  if (height >0)
  {
    width = strlen(block[0]);
  }
  if (sizeof(display)<1){
    report("starting with a new block");
    display = block;
    left_x = query_initial_left_x(direction);
    left_y = query_initial_left_y(direction);
    right_x = query_initial_right_x(direction);
    right_y = query_initial_right_y(direction);
    adjust_width(0, 0);
    adjust_edges();
    return 1;
  }
  x = left_x;
  if (left_adjust_x<1) x += left_adjust_x;
  if (right_x<x) x = right_x;
  if (right_x + right_adjust_x < x) x = right_x + right_adjust_x;
  report("%^BOLD%^%^MAGENTA%^About to adjust width. Current width: " + strlen(display[0]) + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report ("%^B_BLUE%^X 1: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  adjust_width(left_adjust_x + left_point_adjust, right_adjust_x+ right_point_adjust);
  report ("%^B_BLUE%^X 2: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  report("%^BOLD%^%^CYAN%^ABOUT TO ADJUST EDGES. Left edge/left x/left_adjust x: " + left_edge + "/"+ left_x +"/" + left_adjust_x + "  right_edge/right x/right_adjust_x: " + right_edge + "/" + right_x + "/" + right_adjust_x);
  adjust_edges();
  report("%^BOLD%^%^CYAN^EDGES ADJUSTED. Left edge/left x: " + left_edge + "/"+ left_x + "  right_edge/right x: " + right_edge + "/" + right_x );
  report ("%^B_BLUE%^X 3: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  if (left_y<right_y)
  {
    y = left_y - bottom_edge;
  } else
  {
    y = right_y - bottom_edge;
  }
  report ("%^B_BLUE%^X 4: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  leftest_x = left_x;
  if (right_x < leftest_x) leftest_x = right_x;
  if (left_x + left_adjust_x < leftest_x) leftest_x = left_x + left_adjust_x;
  if (right_x + right_adjust_x < leftest_x) leftest_x = right_x + right_adjust_x;
  if (left_point_adjust<0) leftest_x+= left_point_adjust;
  rightest_x = left_x;
  if (right_x > rightest_x) rightest_x = right_x;
  if (left_x + left_adjust_x > rightest_x) rightest_x = left_x + left_adjust_x;
  if (right_x + right_adjust_x > rightest_x) rightest_x = right_x + right_adjust_x;
  if (right_point_adjust>0) rightest_x += right_point_adjust;
    adjust_width(leftest_x - left_x, rightest_x - right_x);
  if (left_adjust_y<0)
  {
    top_left = left_y + left_adjust_y;
  } else
  {
    top_left = left_y;
  }
  if (right_adjust_y<0)
  {
    top_right = right_y + right_adjust_y;
  } else
  {
    top_right = right_y;
  }
  report ("%^B_BLUE%^X 5: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  report("%^BOLD%^%^MAGENTA%^Left edge: %^BOLD%^%^BLUE%^" + left_edge + "%^BOLD%^%^MAGENTA%^Leftest x: %^BLUE%^" + leftest_x + " %^BOLD%^%^MAGENTA%^Right edge: %^YELLOW%^" + right_edge + "%^BOLD%^%^MAGENTA%^Rightest x: %^YELLOW%^" + rightest_x);
  if (leftest_x < left_edge) add_width_left(left_x - leftest_x);
  report ("%^B_BLUE%^X 5i: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  if (rightest_x > right_edge) add_width_right(rightest_x - right_edge);
  report ("%^B_BLUE%^X 5ii: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  full_height = sizeof(display);
  temp_top = calculate_top_point(left_adjust_y, right_adjust_y, sizeof(block), full_height);
  report("%^BOLD%^%^YELLOW%^temp_top: "+ temp_top + " bottom_edge: " + bottom_edge);
  if ( temp_top >= bottom_edge)
  {
    report("Add_block_bottom: inserting block into existing display");
    report("%^B_RED%^%^BOLD%^%^BLACK%^Add_block_bottom: first line of existing display: \n" + display[0]);
//    if(left_x < right_x)
//    {
//      x = left_x;
//    } else
//    {
//      x = right_x;
//    }
//    x-= left_edge;
//    if (left_x + left_adjust_x < x) x = left_x + left_adjust_x ;
//    if (right_x + right_adjust_x < x) x = right_x + right_adjust_x ;
    report("%^BOLD%^%^YELLOW%^ADD BLOCK BOTTOM: ABOUT TO ADJUST HEIGHT.");
    adjust_height(left_adjust_y, right_adjust_y, sizeof(block));
    report("%^GREEN%^ADD BLOCK BOTTOM: HEIGHT ADJUSTED. %^WHITE%^New size of display: " + sizeof(display) );
    top_point = calculate_top_point(left_adjust_y, right_adjust_y, sizeof(block), sizeof(display) );
    report ("Initial top_point: " + top_point);
    top_point -= top_point_adjust;
    top_point -= bottom_point_adjust;
    report ("Adjusted top_point: " + top_point);
  report ("%^B_BLUE%^X 5a: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);

    insert_block(block, x, top_point, direction);
  } else
  {
    report("adding block under existing display");
    full_width = strlen(display[0]);
    left_placement = x;
    report ("%^B_BLUE%^X 6: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
    report ("%^BOLD%^%^YELLOW%^Insert block bottom. Left placement =" + left_placement);
    for (i=height;i>0;i--)
    {
      line  = "";
      if (left_placement >0)
      {
        for (j=0;j< left_placement;j++)
        {
          line += " ";
        }
      }
      line += block[sizeof(block)-i];
      report("%^BOLD%^%^YELLOW%^Add_block_bottom. Adding line " + i + " Block size is: " + sizeof(block));
      if (left_placement + strlen(block[sizeof(block)-i]) < full_width)
      {
        for (j=left_placement + strlen(block[sizeof(block)-i]); j<full_width;j++)
        {
          line += " ";
        }
      }
      report("%^BOLD%^%^MAGENTA%^Add_block_bottom. Line " + i + " added. Block size is: " + sizeof(block));
      if (sizeof(display)>0)
      {
        while (strlen(line)<strlen(display[0]))
        {
          line += " ";
        }
      }
      report("%^B_RED%^Adding line number %^RESET%^%^BOLD%^%^CYAN%^" +i + "%^RESET%^%^B_RED%^ under display.");
      display =  display + ({line});
    }
//    adjust_width(left_adjust_x, left_adjust_y);
  report ("%^B_BLUE%^X 7: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);

    trim_display();
  }
  report ("%^B_BLUE%^X 8: " + x + " width: " + strlen(display[0]) + " left edge: " + left_edge);
  left_x += left_adjust_x;
  left_y += left_adjust_y;
  right_x += right_adjust_x;
  right_y += right_adjust_y;
  adjust_edges();
  report ("%^B_BLUE%^X 8: \n%^RESET%^" + x);

  report("%^BOLD%^%^BLUE%^New coordinates: Left_x: " + left_x + " Left_y: " + left_y + " Right_x: " + right_x + " Right_y: " + right_y);
  trim_display();
}


string query_coords(){
  string result;
  result = "left_x: " + left_x + "left_y: " + left_y + " right_x: " + right_x + " right_y: " + right_y + ".";
  return result;
}

int calculate_bottom_point(int left_adjust_y, int right_adjust_y){
  int bottom_left, bottom_right, bottom_point;
  report ("Calculating bottom point. left_y: " + left_y  + " left_adjust_y: " + left_adjust_y + " right_y: "+ right_y + " right_adjust_y: " + right_adjust_y);
  if (left_adjust_y<0)
  {
    bottom_left = left_y + left_adjust_y;
  } else
  {
    bottom_left = left_y;
  }
  if (right_adjust_y<0)
  {
    bottom_right = right_y + right_adjust_y;
  } else
  {
    bottom_right = right_y;
  }
  if (bottom_left < bottom_right)
  {
    bottom_point = bottom_left;
  } else
  {
    bottom_point = bottom_right;
  }
  report("New bottom point: " + bottom_point);
  return bottom_point;
}

varargs int calculate_top_point(int left_adjust_y, int right_adjust_y, int blocksize, int full_height){
  int bottom_placement, top_placement;
  report ("%^BOLD%^%^CYAN%^Calculating top point. left_y: " + left_y  + " left_adjust_y: " + left_adjust_y + " right_y: "+ right_y + " right_adjust_y: " + right_adjust_y + "  full height: " + full_height + " blocksize: " + blocksize + " bottom edge: " + bottom_edge);
    if (left_adjust_y <0 || right_adjust_y<0)
    {
      report("%^BOLD%^%^BLUE%^1");
      if (left_y + left_adjust_y < right_y + right_adjust_y)
      {
        report("%^BOLD%^%^BLUE%^2");
        bottom_placement = full_height- (left_y + left_adjust_y) +1;
      } else
      {
        report("%^BOLD%^%^BLUE%^3");
        bottom_placement = full_height- (right_y + right_adjust_y) +1;
      }
    } else
    {
      if (left_y<right_y)
      {
        report("%^BOLD%^%^BLUE%^4");
        bottom_placement = full_height - left_y +1 ;
      } else
      {
        report("%^BOLD%^%^BLUE%^5");
        bottom_placement = full_height - right_y +1;
      }
    }
    bottom_placement = bottom_placement + bottom_edge;
    top_placement = bottom_placement - blocksize;
    report("Top placement: " + top_placement + " bottom placement: " + bottom_placement);
    return top_placement;
}


int query_initial_left_x(string direction){
  switch(direction){
  case "north":
  case "northnortheast":
  case "northeast":
  case "eastnortheast":
  case "east":
  case "eastsoutheast":
    return 0;
  case "southeast":
  case "southsoutheast":
  case "south":
  case "southsouthwest":
  case "southwest":
    return 15;
  case "westsouthwest":
  case "westnorthwest":
    return 9;
  case "west":
    return 8;
  case "northwest":
    return 22;
  case "northnorthwest":
    return ;
  }
}

int query_initial_right_x(string direction){
  switch(direction){
  case "north":
    return 15;
  case "south":
    return 15;
  case "east":
    return 14;
  case "west":
    return 14;
  }
}

int query_initial_left_y(string direction){
  switch(direction){
  case "north":
    return 4;
  case "south":
    return -4;
  case "east":
    return 7;
  case "west":
    return 0;
  }
}

int query_initial_right_y(string direction){
  switch(direction){
  case "north":
    return 4;
  case "south":
    return -4;
  case "east":
    return 0;
  case "west":
    return 7;
  }
}


int add_block_right(string * block, left_adjust_x, left_adjust_y, right_adjust_x, right_adjust_y, string direction){
  int width, height, i, j, full_height, bottom_placement, top_placement, x, y, flag;
  string line, tmp, blockline;
  report("%^BOLD%^%^YELLOW%^Add block right 1: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  height = sizeof(block);
  if (height >0)
  {
    width = strlen(block[0]);
  } else
  {
    report ("Add_block_right error: block is not valid");
    return 0;
  }
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^About to adjust height. Current top edge: " + top_edge + " Current bottom edge: " + bottom_edge);
  adjust_height(left_adjust_y, right_adjust_y, sizeof(block));
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^Finished adjusting height. New edge: " + top_edge + " New bottom edge: " + bottom_edge);
  if (sizeof(display)<1)
  {
    report("starting with a new block");
    display = block;
    left_x = query_initial_left_x(direction);
    left_y = query_initial_left_y(direction);
    right_x = query_initial_right_x(direction);
    right_y = query_initial_right_y(direction);
    adjust_edges();
    return;
  }
  full_height = sizeof(display);
  report("%^BOLD%^%^YELLOW%^Add block right 2: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x+ " Right Edge: " + right_edge);
  if(left_x < right_x)
  {
    x = left_x;
  } else
  {
    x = right_x;
  }
  if (left_y<right_y)
  {
//    y = left_y;
    report("left_y: " + left_y + "bottom edge: " + bottom_edge);
    y = left_y - bottom_edge;
    report("y: " + y);
  } else
  {
//    y = right_y;
    report("right_y: " + right_y + "bottom edge: " + bottom_edge);
    y = right_y - bottom_edge;
    report("y: " + y);
  }
  report("%^B_GREEN%^Calculating new top position (y)");

  y = calculate_top_point(left_adjust_y, right_adjust_y, sizeof(block), full_height);
   report("y: " + y);
//  y = sizeof(display) + bottom_edge - y;
//   report("Actual y: " + y);
  flag = 0;
  if ( left_x < right_edge) flag = 1;
  if ( right_x < right_edge) flag = 1;
  if ( flag ==1)
  {
    report ("FLAG == 1");
    if (left_x < right_edge)
    {
      report ( "%^BOLD%^%^CYAN%^left_x (" + left_x + ") < right_edge (" + right_edge + ")");
    }
    if (right_x < right_edge)
    {
      report ( "%^BOLD%^%^YELLOW%^right_x (" + right_x + ") < right_edge (" + right_edge + ")");
    }
    report("%^CYAN%^inserting block into existing display. Left_x: " + left_x + " Right_x: " + right_x + " Right_edge: " + right_edge);
//    insert_block(block, x-left_edge, y-1, direction);
    insert_block(block, x, y, direction);
    switch(direction){
    case "east":
      left_x --;
      right_x --;
      break;
    }
  } else
  {
    report("adding block to right of existing display. Left_y: " + left_y + " Right_y: " + right_y + " Left_adjust_y: " + left_adjust_y + " Right_adjust_y: " + right_adjust_y + " Right Edge: " + right_edge);

    full_height = sizeof(display);

    if (left_adjust_y <0 || right_adjust_y<0)
    {
      if (left_y + left_adjust_y < right_y + right_adjust_y)
      {
        bottom_placement = full_height - left_y - left_adjust_y;
      } else
      {
        bottom_placement = full_height - right_y - right_adjust_y;
      }
    } else
    {
      if (left_y<right_y)
      {
        bottom_placement = left_y;
      } else
      {
        bottom_placement = right_y;
      }
    }
    top_placement = calculate_top_point(left_adjust_y, right_adjust_y, sizeof(block), full_height);
    bottom_placement = top_placement + sizeof(block);
//Make blank line of the right width
    line = "";
    for (i=0;i<strlen(block[0]);i++)
    {
      line += " ";
    }
    report("%^BOLD%^%^YELLOW%^Add block right 4: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);

    report("Add_block_right: Placements set. top_placement: " + top_placement +  " bottom_placement: " + bottom_placement + "full_height: " + full_height);
    j = 0;
    for (i=0;i<full_height;i++)
    {
//      if ((top_placement<bottom_placement && (i < top_placement || i > bottom_placement)) ||(top_placement>bottom_placement && (i < bottom_placement || i > top_placement)))

      if ((top_placement<bottom_placement && (i < top_placement || i >= bottom_placement)) ||(top_placement>bottom_placement && (i <= bottom_placement || i > top_placement)))

      {
        report ("i (" + i + ") is not within placement range. Adding blank line");
        tmp = "";
        tmp = tmp + line;
        display[i] = display[i] + tmp;
        continue;
      }
      report("Calculating j. i = " + i + " bottom_placement = " + bottom_placement + " bottom_edge = " + bottom_edge);
      report ("j= " + j);
      tmp = "";
      tmp = tmp + display[i];
      display[i] = tmp + block[j]; // + " j =  " + j;
      j ++;
    }
  }
  report("%^BOLD%^%^YELLOW%^Add block right 5: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  left_x += left_adjust_x;
  left_y += left_adjust_y;
  right_x += right_adjust_x;
  right_y += right_adjust_y;
  adjust_edges();
  switch(direction){
  case "south":
  case "southwest":
  case "southeast":
    left_y++;
    right_y++;
    break;
  }

  report("Block added to right. left_x: " + left_x + "  right_x: " + right_x + "  left_y: " + left_y + "  right_y: " + right_y);
  trim_display();
}


int query_bottom_edge(){
  return bottom_edge;
}

int query_top_edge(){
  return top_edge;
}

int add_block_left(string * block, left_adjust_x, left_adjust_y, right_adjust_x, right_adjust_y, string direction){
  int width, height, i, j, full_height, bottom_placement, top_placement, x, y;
  string line, tmp, blockline;
  report("%^BOLD%^%^YELLOW%^Add block left 1: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^1) Left edge: " + left_edge);
  height = sizeof(block);
  if (height >0)
  {
    width = strlen(block[0]);
  } else
  {
    report ("Add_block_left error: block is not valid");
    return 0;
  }
  adjust_height(left_adjust_y, right_adjust_y, sizeof(block));
  full_height = sizeof(display);
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^2) Left edge: " + left_edge);

  if (sizeof(display)<1)
  {
    report("starting with a new block");
    display = block;
    left_x = query_initial_left_x(direction);
    left_y = query_initial_left_y(direction);
    right_x = query_initial_right_x(direction);
    right_y = query_initial_right_y(direction);
    adjust_edges();
    return;
  }
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^3) Left edge: " + left_edge);
  report("%^BOLD%^%^YELLOW%^Add block left 2: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  x = left_x;
  if (left_adjust_x<0) x+= left_adjust_x;
  if (right_x<x) x = right_x;
  if (right_x+right_adjust_x<x) x = right_x+right_adjust_x;
  y = calculate_top_point(left_adjust_y, right_adjust_y, sizeof(block), full_height);
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^4) Left edge: " + left_edge);
  if ( left_x >left_edge || right_x  > left_edge )
  {
    if (left_x<left_edge)
    {
      add_width_left(left_edge-left_x);
    }
    if (right_x<left_edge)
    {
      add_width_left(left_edge-right_x);
    }
    if (left_x+ left_adjust_x< left_edge)
    {
      add_width_left(left_edge- left_adjust_x-left_x);
    }
    if (right_x+ right_adjust_x< right_edge)
    {
      add_width_left(left_edge - right_adjust_x-right_x);
    }
    if (x<left_edge) add_width_left(left_edge - x);
    report("%^B_CYAN%^%^BOLD%^%^WHITE%^4a) Left edge: " + left_edge);

    report("inserting block into existing display. Left_x: " + left_x + " Right_x: " + right_x + " Right_edge: " + right_edge);
    blockline = block[0];
    report("%^B_CYAN%^%^BOLD%^%^WHITE%^4b) Left edge: " + left_edge);
 //   insert_block(block, x - strlen(blockline)+1, y-1, direction);
    insert_block(block, x, y-1, direction);
    report("%^B_CYAN%^%^BOLD%^%^WHITE%^4c) Left edge: " + left_edge);
  } else
  {
    report("adding block to left of existing display. Left_y: " + left_y + " Right_y: " + right_y + " Left_adjust_y: " + left_adjust_y + " Right_adjust_y: " + right_adjust_y);
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^5) Left edge: " + left_edge);
    full_height = sizeof(display);
    top_placement = calculate_top_point(left_adjust_y, right_adjust_y, sizeof(block), full_height);
    report("%^BOLD%^%^MAGENTA%^Switching on direction. Direction: " + direction + " Previous direction: " + previous_direction + " top_placement: " + top_placement);
    report("%^BOLD%^%^YELLO%^Finished switching on direction. Direction: " + direction + " Previous direction: " + previous_direction + " top_placement: " + top_placement);
    bottom_placement = top_placement + sizeof(block);

  report("%^B_CYAN%^%^BOLD%^%^WHITE%^6) Left edge: " + left_edge);
  report("Add_block_left: %^BOLD%^%^GREEN%^CHECKING WHETHER I NEED TO ADD HEIGHT TO BOTTOM! y:" + y + " sizeof(display): "+sizeof(display));
  if(y + sizeof(block)>sizeof(display)-1)
  {
    add_height_bottom(y-sizeof(display) +1 + sizeof(block));
    report("%^B_ORANGE%^Height added to bottom: " + (y-sizeof(display) +1 + sizeof(block)));
  }
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^7) Left edge: " + left_edge);

//Make blank line of the right width
    line = "";
    for (i=0;i<strlen(block[0]);i++)
    {
      line += " ";
    }
    report("%^BOLD%^%^YELLOW%^Add block left 4: left_x: " + left_x + " right_x: " + right_x + " left_adjust_x: " + left_adjust_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^8) Left edge: " + left_edge);
    report("Add_block_left: Placements set. top_placement: " + top_placement +  " bottom_placement: " + bottom_placement);
    j = 0;
    for (i=0;i<full_height;i++)
    {
      if ((top_placement<bottom_placement && (i < top_placement || i >= bottom_placement)) ||(top_placement>bottom_placement && (i <= bottom_placement || i > top_placement)))
      {
        report ("i (" + i + ") is not within placement range. Adding blank line");
        tmp = "";
//        tmp = tmp + i;
        tmp = tmp + line;
//        if (i<10) tmp = tmp + " ";
        display[i] = tmp + display[i];
        continue;
      }
      report("Calculating j. i = " + i + " bottom_placement = " + bottom_placement + " bottom_edge = " + bottom_edge);
      report ("j= " + j);
      tmp = "";
//      tmp = tmp + i;
//      if (i<10) tmp = tmp + " ";
      tmp = tmp + block[j];
      report("%^BOLD%^%^CYAN%^block[j]: %^WHITE%^'" + block[j] + "'%^YELLOW%^  tmp: %^WHITE%^'" + tmp + "'");
      display[i] = tmp + display[i]; // + " j =  " + j;
      j ++;
    }
  }
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^9) Left edge: " + left_edge);

  left_x += left_adjust_x;
  left_y += left_adjust_y;
  right_x += right_adjust_x;
  right_y += right_adjust_y;
  adjust_edges();
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^9a) Left edge: " + left_edge);
  trim_display();
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^9b) Left edge: " + left_edge);
  switch(direction)
  {
  case "west":
    switch(previous_direction)
    {
    case "west":
    case "northwest":
    case "southwest":
    case "westsouthwest":
    case "westnorthwest":
      break;
    }
    break;
  case "south":
  case "southwest":
  case "southeast":
    left_y++;
    right_y++;
    break;
  }
  report("Block added to left. left_x: " + left_x + "  right_x: " + right_x + "  left_y: " + left_y + "  right_y: " + right_y);
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^10) Left edge: " + left_edge);
  trim_display();
  report("%^B_CYAN%^%^BOLD%^%^WHITE%^11) Left edge: " + left_edge);

}


int query_left_adjust_x(string direction){
  switch(direction)
  {
    case "north":
    switch(previous_direction)
    {
      case "east":
        return 1;
        break;
      case "northeast":
      case "north":
      case "northwest":
        return 0;
        break;
      case "west":
        return -16;
        break;
    }
    case "northeast":
    switch(previous_direction)
    {
      case "southeast":
        return 3;
        break;
      case "east":
        return 4;
        break;
      case "northeast":
        return 7;
      case "north":
      case "northwest":
        return 7;
        break;
    }
    case "east":
    switch(previous_direction)
    {
      case "north":
      case "northeast":
        return 20;
        break;
      case "east":
        return 14;
        break;
      case "southeast":
        return 18;
        break;
      case "south":
        return 21;
        break;
    }
    case "southeast":
    switch(previous_direction)
    {
      case "northeast":
        return 29;
        break;
      case "east":
        return 19;
        break;
      case "southeast":
      case "south":
      case "southwest":
        return 0;
        break;
    }
    case "south":
    switch(previous_direction)
    {
      case "east":
        return 1;
        break;
      case "southeast":
      case "south":
      case "southwest":
        return 0;
        break;
      case "west":
        return -1;
        break;
    }
    case "southwest":
    switch(previous_direction)
    {
      case "northwest":
        return -3;
        break;
      case "west":
        return -4;
        break;
      case "southwest":
      case "south":
      case "southeast":
        return -7;
        break;
    }
    case "west":
    switch(previous_direction)
    {
      case "north":
      case "northwest":
        return -4;
        break;
      case "west":
        return -14;
        break;
      case "southwest":
      case "south":
        return -20;
        break;
    }
    case "northwest":
    switch(previous_direction)
    {
      case "northeast":
      case "north":
      case "northwest":
        return -7;
        break;
      case "west":
        return -18;
        break;
      case "southwest":
        return -30;
        break;
    }
      break;
  }
}

int query_right_adjust_x(string direction){
  switch(direction)
  {
    case "north":
    switch(previous_direction)
    {
      case "east":
        return 16;
        break;
      case "northeast":
      case "north":
      case "northwest":
        return 0;
        break;
      case "west":
        return -1;
        break;
    }
    case "northeast":
    switch(previous_direction)
    {
      case "east":
        return 19;
        break;
      case "northeast":
      case "north":
      case "northwest":
        return 7;
        break;
      case "southeast":
        return 29;
        break;
    }
    case "east":
    switch(previous_direction)
    {
      case "east":
        return 14;
        break;
      case "northeast":
      case "north":
      case "southeast":
        return 4;
        break;
      case "south":
        return 7;
        break;
    }
    case "southeast":
    switch(previous_direction)
    {
      case "east":
        return 4;
        break;
      case "northeast":
        return 3;
        break;
      case "south":
      case "southeast":
      case "southwest":
        return 7;
        break;
    }
    case "south":
    switch(previous_direction)
    {
      case "east":
        return 16;
        break;
      case "southeast":
      case "south":
      case "southwest":
        return 0;
        break;
      case "west":
        return -16;
        break;
    }
    case "southwest":
    switch(previous_direction)
    {
      case "northwest":
        return -30;
        break;
      case "southeast":
      case "south":
      case "southwest":
        return -7;
        break;
      case "west":
        return -18;
        break;
    }
    case "west":
    switch(previous_direction)
    {
      case "northwest":
      case "north":
        return -20;
        break;
      case "west":
        return -14;
        break;
      case "southwest":
      case "south":
        return -5;
        break;
    }
    case "northwest":
    switch(previous_direction)
    {
      case "northeast":
      case "north":
      case "northwest":
        return -7;
        break;
      case "west":
        return -4;
        break;
      case "southwest":
        return -3;
        break;
    }
  break;
  }
}

void insert_block(string * block, int x, int y, string direction){
  int i, j, count1, count2, full_height, line_no, lower_x, adjustment, temp_y, left_adjust_x, right_adjust_x, block_x, height_added;
  string line, newline;
  report ("%^BOLD%^%^YELLOW%^Inserting a block. x = " + x +" y = " + y);
  count1 = sizeof (display);
  if (count1<1) return;
  if (sizeof(block)<1) return ({});
  count2 = strlen(block[0]);
  full_height = sizeof(display);
  adjustment = 0;
  switch(direction)
  {

  case "eastnortheast":
    switch(previous_direction)
    {
    case "northnorthwest":
      adjustment = -1;
      break;
    }
    break;
  case "west":
    switch(previous_direction)
    {
    case "north":
      adjustment = -1;
      x--;
      left_x--;
      right_x--;
      break;
    case "west":
      adjustment = -1;
      break;
    }
    break;
  case "westnorthwest":
    switch(previous_direction)
    {
    case "north":
      adjustment = -1;
      break;
    }
    break;
  case "northwest":
    switch(previous_direction)
    {
    case "north_northwest":
      report("%^B_ORANGE%^%^BOLD%^%^YELLOW%^Previous Direction: " + previous_direction);
      adjustment = 1;
      break;
    }
    break;
  }
  height_added = 0;
  y -= adjustment;
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 1: x: " + x + "%^B_GREEN%^%^BOLD%^%^WHITE%^Sizeof display: " + sizeof(display));
  report("%^BOLD%^%^MAGENTA%^ABOUT TO CHECK WHETHER MORE SPACE IS NEEDED TO THE RIGHT");
  if (x- left_edge + strlen(block[0] ) > strlen(display[0]))
  {
    report("%^BOLD%^%^WHITE%^Adding width to the right. x:" + x + " left edge: " + left_edge + " strlen(block[0]): " + strlen(block[0]) + " strlen(display[0]): " + strlen(display[0]));
    add_width_right(x - left_edge + strlen(block[0]) - strlen(display[0]));
    report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 1a: x: " + x);
  } else
  {
    report("%^BOLD%^%^BLACK%^No need to add width to the right. x:" + x + " strlen(block[0]): " + strlen(block[0]) + " strlen(display[0]): " + strlen(display[0]) + " left_x: " + left_x + " right_x: " + right_x);
  }
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 2: x: " + x );
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 2) Sizeof display: " + sizeof(display));
//  left_adjust_x = query_left_adjust_x(direction);
//  right_adjust_x = query_right_adjust_x(direction);

  report("%^BOLD%^%^MAGENTA%^ABOUT TO CHECK WHETHER MORE SPACE IS NEEDED TO THE LEFT");
  report("%^BOLD%^%^CYAN%^left_x: " + left_x + " left_adjust_x: " + left_adjust_x + " right_x: " + right_x + " right_adjust_x: " + right_adjust_x);
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 3: x: " + x);
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 3) Sizeof display: " + sizeof(display));
  if (x < left_edge)
  {
    report("%^BOLD%^%^WHITE%^Adding width to the left. x:" + x + " left_edge: " + left_edge );
    add_width_left((x-left_edge));
  } else
  {
    report("%^BOLD%^%^BLACK%^No need to add width to the left. x:" + x + " left_edge: " + left_edge );
  }
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 4: x: " + x);
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 4) Sizeof display: " + sizeof(display));
  if (full_height<1) return;

  full_height = sizeof(display);
//  report ("Adjusting x to compensate for left_edge value of: " + left_edge + " Original value of x: " + x + " New value of x: "+ (x - left_edge) );
//  x -= left_edge;
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 5: x: " + x);
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 5) Sizeof display: " + sizeof(display));
  report ("%^BOLD%^%^GREEN%^About to cycle through block. Starting y: "+ y +" Bottom edge: " + bottom_edge);
//  if (y<0)
//  {
//    add_height_top(0-y);
//  }
  report("%^BOLD%^%^GREEN%^CHECKING WHETHER I NEED TO ADD HEIGHT TO BOTTOM! y:" + y + " sizeof(display): "+sizeof(display));
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 6: x: " + x);
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 6) Sizeof display: " + sizeof(display));
  if(y + sizeof(block)>sizeof(display)-1)
  {
    height_added = y-sizeof(display)+1+sizeof(block);
    add_height_bottom(y-sizeof(display) +1 + sizeof(block));
    report("%^B_ORANGE%^Height added to bottom: " + (y-sizeof(display) +1 + sizeof(block)));
    report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 6a) Sizeof display: " + sizeof(display));
  }
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 7: x: " + x + " %^BOLD%^%^YELLOW%^Y: " + y);
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 7) Sizeof display: " + sizeof(display));
  report("%^BOLD%^%^CYAN%^CHECKING WHETHER I NEED TO ADD HEIGHT TO TOP! y:" + y + " %^B_GREEN%^%^BOLD%^%^WHITE%^sizeof(display): "+sizeof(display));
  if(y<0)
  {
    height_added = 0-y;
    add_height_top(0-y);
    report("%^B_ORANGE%^Height added to top: " + (0-y));
    report("%^B_GREEN%^%^BOLD%^%^WHITE%^New size of display: " + sizeof(display));
    y=0;
  }
  x-=left_edge;
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 8: x: " + x + " %^BOLD%^%^YELLOW%^Y: " + y);
  report( " %^B_GREEN%^%^BOLD%^%^WHITE%^Insert_block 8) Sizeof display: " + sizeof(display));
  for (i=y;i<y + sizeof(block);i++)
  {
    line_no = i;
    report ("INSERT_BLOCK: Inserting line. Line no: " + line_no + " i = " + i + " bottom_edge: " + bottom_edge + "sizeof(block): " + sizeof(block) + " sizeof(display) = " + sizeof(display));
    line = "";
    report ("%^BOLD%^%^YELLOW%^Insert_block. Adding line. i = " + i + " line_no = " + line_no + " Size of display: " + sizeof(display));
    line += display[line_no];
    report ("%^BOLD%^%^GREEN%^Line successfully added");
    report ("i = " + i + " line_no = " + line_no);
    report ("Inserting block at line_no " + line_no + " x = " + x);
    report ("Block line to be inserted: " + block[i-y]);
    count2 = strlen(line);
    if (left_x<right_x)
    {
      lower_x = left_x;
    } else
    {
      lower_x = right_x;
    }
    if (left_x + left_adjust_x < lower_x)  lower_x = left_x + left_adjust_x;
    if (right_x + right_adjust_x < lower_x)  lower_x = right_x + right_adjust_x;

    report("%^BOLD%^%^GREEN%^About to insert block. x: " + x + " left edge: " + left_edge);
    for (j=x;j<x+strlen(block[0]);j++)
    {
      report ("%^BOLD%^%^RED%^x = " + x + "  j = " + j + "  Checking for a blank space");
      if (line[j..j] == " ")
      {
         block_x = j-x;
        report ("%^BOLD%^%^MAGENTA%^Block number to replace: " + (i-y) + " j: " + j +" Start of range: " + (j-lower_x+left_edge) + " End of range: " + (j-lower_x+left_edge) + " j: " + j + " x: " + x + " left_edge: " + left_edge + " block_x: " + block_x );
//        report ("%^BOLD%^%^CYAN%^line[j]: " + line[j]);
//        if (stringp(block[i-y][block_x]) && strlen(block[i-y][block_x])>0)
//        {
          report ("block[i-y]: " + block[i-y]);
          report ("block[i-y][block_x]: " + block[i-y][block_x]);
          line[j] = block[i-y][block_x];
//        } else {
          report ("%^BOLD%^%^YELLOW%^x = " + x + "  j = " + j + "  Adjusted line");
//        }
      }else
      {
        report ("Not a blank space. Character found: " + line[j..j] + "  j = : " + j + " line no: " + line_no + " i: " + i) ;
      }

    }
    report("About to replace a line. i =  " + i);
    display[line_no] = line;
  }
  report("%^B_MAGENTA%^%^BOLD%^%^WHITE%^Insert_block 10: x: " + x);
  report ("%^BOLD%^%^MAGENTA%^Insert_block: Adjusting x & y. Left_x: " + left_x + " Right_x: " + right_x + "Left_adjust_x: " + left_adjust_x + " Right_adjust_x: " + right_adjust_x);
}

string substitute_character(string ch){
  string * substitutables;
  substitutables = keys(SUBSTITUTIONS);
  if (member_array (ch, substitutables)!=-1)
  {
    return SUBSTITUTIONS[ch];
  }
  return ch;
}


varargs string * add_sprite_to_block(string * sprite, string * block, int x, int y, spritename){
  int height, width, sprite_height, sprite_width;
  string line, ch, newline, *newblock;
  int i, j;
  height = sizeof(block);
  if (height <1) return ({});
  width = strlen(block[0]);
  if (width<1) return ({});
  sprite_height = sizeof(sprite);
  if (stringp(spritename) && sizeof(path)>build_progress)
  {
    // special_report("Build_progress: " + build_progress + " Direction: " + path[build_progress]+ " Pre-correction: x " + x + " y " + y);
    if (stringp(spritename))
    {
      // special_report("Sprite name: " + spritename);
    } else
    {
      // special_report("Sprite name is not a valid string. BOO!");
    }
    x += query_sprite_x_correction(spritename, path[build_progress]);
    y += query_sprite_y_correction(spritename, path[build_progress]);
    // special_report("Post-correction: x " + x + " y " + y);
  } else {
    if (!stringp(spritename))
    {
      // special_report("No sprite name found");
      if (sizeof(obstacles)> build_progress){
        // special_report("Obstacles[build_progress] = " + obstacles[build_progress]);
      }
    } else
    {
      // special_report("Sprite  name: " + spritename);
    }
    if (sizeof(path)>build_progress)
    {
      // special_report("direction: " + path[build_progress]);
    } else
    {
      // special_report("sizeof path: " + sizeof(path) + " build progress: " + build_progress);
    }
  }
  if (sprite_height <1)
  {
    report("sprite is size zero");
    return ({});
  }
  sprite_width = strlen(sprite[0]);
  if (sprite_width<1)
  {
    report("sprite is width zero");
    return ({});
  }
  if (x > width)
  {
    report("x >width. x: " + x + " width: " + width);
    return ({});
  }

  if (y>height)
  {
    report("y > height. y: " + y + " width: " + width);
    return ({});
  }
  newblock = ({});
  if (y>0) newblock = block[0..y-1];
  report("Adding lines to new block. y: " + y + " Size of new block: " + sizeof(newblock) + " height: " + height + " sizeof sprite: " + sizeof(sprite) + " x: " + x + " width: " + width);
  for (i = y; i<y+ sprite_height && i<height;i++){
    report("Adding a line. i: " + i);
    if (i<0) continue;
    line = block[i];
    newline = "";
    if (x>0)
    {
      newline = line[0..x-1];
    }
    for (j=x; j<strlen(line) && j<x + sprite_width; j++)
    {
      if (j<0) continue;
      ch = sprite[i-y][j-x..j-x];
//      report("Character to be substitued:" + ch);
//      ch = substitute_character(ch);
//      report("Substitute:" + ch);
      if(ch != " ") newline += ch;
      else newline += line[j..j];
    }
    if (j<=width -1) newline += line[j..width-1];
    newblock += ({newline});
  }
  if (y+ sprite_height<=height-1) newblock += block[y+sprite_height..height-1];
  return newblock;
}
