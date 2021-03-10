#include <std.h>
#include "../tecqumin.h"
#define STRAIGHT 0
#define SLIGHT_LEFT -1
#define LEFT -2
#define HARD_LEFT -3
#define SLIGHT_RIGHT 1
#define RIGHT 2
#define HARD_RIGHT 3
#define OBS_INTERVAL 5
#define PATHFINDER "/daemon/pathfinder_d.c"
#define CANOE_D "/d/atoyatl/canoe_d"

inherit ROOM;

// This room is designed to give players a white water ride in a canoe.
// It's all controlled by a separate paddle object (../obj/paddle.c)
// That the players can use to control the vessel

int direction;   // the direction the boat is pointing in
                 // from 0 - 15
                 // 0 = north 1 = nne 2 = ne... 15 = nnw
int river_flow;  // the direction the river is flowing in
                 // numbers as above
int river_speed; // the speed the river is flowing at
int boat_speed; // the speed the boat is travelling at, relative
                 // to the river
int river_length; // the length of the river
int progress;     // the boat's progress down the river
int position;     // the boats position between the banks
                  // 0 = beside left bank 8 = beside right bank
int hull_points;  // current condition of the boat
int max_hull_points;  // maximum condition of the boat
int capsized;     // just a flag, to remember if the canoe has capsized
int paused;       //just a flag, to track whether the boat is paused
int pause_count;  //
int * path; //An array of the path of the river
int * speed; // An array of the speed of the river
string * obstructions;
int * obstruction_placements;
int last_paddle;
int launched;
// string log; string used in debugging process - removed until needed

object * query_path();
object * query_speed();
int change_dir(int dir);
int change_speed (int spd);
int apply_lateral_travel();
int query_relative_direction();
void travel();
void launch(object ob);
void capsize();
void show_direction(int relative_direction);

void create(){
  ::create();
  set_property("indoors", 0);
  set_property("light", 2);
  set_short("A small canoe");
  set_long( (:TO, "long_desc":) );
  set_terrain(WOOD_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_smell("default","The whiff of the white water wafts by");
  set_listen("default","The roaring of the river rolls in your ears");
  set_exits( ([ "out" : ROOMS + "canoe_entry" ]) );
  setup_river();
}


void setup_river(){
  int i, j, bend;
  paused = 0;
  pause_count = 0;
  set_items( ([

  ]) );
  //log = "";
  path = ({0});
  speed = ({});
  direction = 0;
  river_speed = random (5)+1;
  progress = 0;
  capsized = 0;
  river_length = 13 + random (6);
  for (i=1;i<river_length;i++){
    river_speed += random (3)-1;
    if (river_speed>5){
      river_speed = 5;
    }
    if (river_speed <1) {river_speed = 1; }

//    path += ({direction});  //////////
//    path += ({direction});  //////////
//    path += ({direction});  //////////
    speed += ({river_speed});
    speed += ({river_speed});
//    speed += ({river_speed});


    bend = random(7)-3;
    switch (bend){
    case STRAIGHT:
      path += ({direction});
      path += ({direction});
//      path += ({direction});
      break;
    case SLIGHT_RIGHT:
      path += ({direction});
      direction ++;
      if (direction>15){
        direction = 0;
      }
      path += ({direction});
      path += ({direction});
      break;
    case RIGHT:
      path += ({direction});
      direction +=2;
      if (direction>15){
        direction -= 16;
      }
      path += ({direction});
      direction ++;
      if (direction>15){
        direction -= 16;
      }
      path += ({direction});
      break;
    case HARD_RIGHT:
      direction +=3;
      if (direction>15){
        direction -= 16;
      }
      path += ({direction});
//      direction ++;
//      if (direction>15){
//        direction = 0;
//      }
      path += ({direction});
//      direction ++;
//      if (direction>15){
//        direction = 0;
//      }
//      path += ({direction});
      break;
    case SLIGHT_LEFT:
//      path += ({direction});
      direction --;
      if (direction<0){
        direction += 16;
      }
      path += ({direction});
      path += ({direction});
      break;
    case LEFT:
      path += ({direction});
      direction -=2;
      if (direction<0){
        direction += 16;
      }
      path += ({direction});
      direction --;
      if (direction<0){
        direction += 16;
      }
//      path += ({direction});
      break;
    case HARD_LEFT:
      direction -=3;
      if (direction<0){
        direction += 16;
      }
      path += ({direction});
//      direction --;
//      if (direction<0){
//        direction = 15;
//      }
      path += ({direction});
//      direction --;
//      if (direction<0){
//        direction = 15;
//      }
//      path += ({direction});
      break;
    }
  }
  river_length = sizeof(path);
  obstructions = ({});
  obstruction_placements = ({});
  generate_obstructions();
  path += ({direction, direction, direction, direction, direction, direction});
  speed += ({river_speed, river_speed,river_speed});
  obstructions += ({"none", "none", "is an island "});
  obstruction_placements += ({3, 3, 3});
  path += ({direction, direction, direction, direction, direction, direction, direction});
  speed += ({2,2,3,3,4,5, 5});
  obstructions += ({"none", "none","none", "none","none", "is a waterfall "});
  obstruction_placements += ({3, 3, 3,3,3,3});
  river_length = sizeof(path);
  check_island_placement();
  last_paddle = 0;
  launched = 0;
  progress = 0;
  position = 0;
  direction = 0;
}


void init(){
  ::init();
  add_action("pause", "pause");
  add_action("resume", "resume");
}

void generate_obstructions(){
  int i;
  obstructions = ({});
  for (i=0;i<river_length;i++){
    if (i>0 && !random(OBS_INTERVAL)){
      switch (random(4)){
      case 0:
        obstructions+= ({"a rock "});
        break;
      case 1:
        obstructions+= ({"a weir "});
        break;
     case 2:
        obstructions+= ({"a log "});
        break;
      case 4:
        obstructions+= ({"a rock "});
        break;
      case 5:
        obstructions+= ({"a sandbar "});
        break;
      }
      obstruction_placements += ({random(7)});
    }else{
      obstructions += ({"none"});
      obstruction_placements +=({0});
    }
  }
  while(sizeof(obstructions)>sizeof(obstruction_placements))
  {
    obstruction_placements += ({random(5)});
  }
  while(sizeof(obstruction_placements)>sizeof(obstructions))
  {
     obstructions += ({"none"});
  }
}

void check_island_placement(){
  string ob;
  int pos, i;
  for (i=0;i<sizeof(obstructions); i++)
  {
    if (obstructions[i] == "is an island ")
    {
      while (sizeof(obstruction_placements)<=i)
      {
        obstruction_placements += ({3});
      }
      obstruction_placements[i] = 3;
    }
  }
}

void set_obstruction(int progress, int position, int type){
  string obs;
  switch(type)
  {
  case 0:
    obs = "a rock ";
    break;
  case 1:
    obs = "a weir ";
    break;
  case 2:
    obs = "a log ";
    break;
  case 4:
    obs = "a rock ";
    break;
  case 5:
    obs = "a sandbar ";
    break;
  case 6:
    obs = "is an island ";
    break;
  case 7:
    obs = "is a waterfall ";
    break;
  default:
    obs = "none";
    break;
  }
  obstructions[progress] = obs;
  obstruction_placements[progress] = position;
  tell_object(TP, "Obstruction: " + obs + " placed at progress: " + progress + ", position: " + position);
}

int query_paused(){
  return paused;
}

void set_paused(int p){
  paused = p;
}

int pause(string str){
  if (paused % 2 ==1)
  {
    tell_room(TO, "The canoe ride is already paused");
    return 1;
  }
  if (paused >3 && !TP->query_true_invis())
  {
    tell_room(TO, "The canoe ride has already been paused twice. You're going to have to try to ride it out!");
    return 1;
  }
  if (TP->query_true_invis())
  {
    tell_room(TO, "The canoe ride has been paused by an imm. It will only restart with the command <resume>");
    paused ++;
    pause_count = 21;
    return 1;
  }
  tell_room(TO, "The canoe ride has been paused!");
  paused ++;
  return 1;
}

int resume(string str){
  if (paused % 2 ==0)
  {
    tell_room(TO, "The canoe ride isn't paused");
    return 1;
  }
  if (paused >3 && paused <20 && !TP->query_true_invis())
  {
    tell_room(TO, "The canoe has already been paused twice on this run. Now you'll just have to ride it out!");
    return 1;
  }
  tell_room(TO, "The canoe ride resumes!");
  paused ++;
  pause_count = 0;
  return 1;
}

int query_position(){
  return position;
}

void set_position(int p){
  position = p;
}

varargs void show_river(object who){
  if (!objectp(who)) who = TP;
  CANOE_D->load_path(TO);
  CANOE_D->set_current_position(position);
  CANOE_D->set_current_progress(progress);
  CANOE_D->set_current_direction(direction);
  CANOE_D->set_obstacles(obstructions);
  CANOE_D->set_obstacle_placements(obstruction_placements);
  CANOE_D->show_river(who);
//  CANOE_D->build_map_section(progress, 4, who);
//  CANOE_D->show_whole_display(who);
}

string * query_obstructions(){
  return obstructions;
}

int query_progress(){
  return progress;
}

object * query_path(){
  return path;
}

object * query_speed(){
  return speed;
}

void reset(){
  int flag, i, count;
  object * critters, paddle;
  ::reset();
  critters = all_living(TO);
  count = sizeof(critters);
  flag = 0;
  if (count>0)
  {
    for (i=0;i<count;i++)
    {
      if (userp(critters[i]) && !critters[i]->query_true_invis())
      {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0)
  {
    if (!present("paddle", TO))
    {
      paddle = new (OBJ + "paddle");
      paddle->move(TO);
    }
  }
  if (flag ==0 && launched <2)
  {
    setup_river();
  }
}

query_launched(){
  return launched;
}

varargs int * get_path_between_points(int start_point, int end_point){
  int i, * result, line;
  if (sizeof(path)<1) return ({"There is no river. Path has not been prepared"});
  if (!intp(start_point) || start_point<0) start_point = 0;
  if (!intp(end_point) || end_point>sizeof(path)-1) end_point = sizeof(path)-1;
  result = ({});
  for (i = start_point;i<end_point;i++)
  {
    line = path[i];
    result += ({line});
  }
  return result;
}

varargs string * draw_river(int start_point, int end_point){
  string line, * result;
  int i, p, * temp_path;
  if (sizeof(path)<1) return ({"There is no river. Path has not been prepared"});
  if (!intp(start_point) || start_point<0) start_point = 0;
  if (!intp(end_point) || end_point > sizeof(path)-1)
  {
    end_point = sizeof(path)-1;
  }
  result = ({});
  temp_path = get_path_between_points(start_point, end_point);
  "/d/atoyatl/canoe_d"->set_path(temp_path);
  "/d/atoyatl/canoe_d"->build_map();
  result = "/d/atoyatl/canoe_d"->query_display();
  return result;
}

string get_river_position(int pos){
  switch (pos){
  case 0:
    return "right beside the left bank";
    break;
  case 1:
    return "close to the left bank";
    break;
  case 2:
    return "slightly to the left of the centre of the river";
    break;
  case 3:
    return "in the middle of the river";
    break;
  case 4:
    return "slightly to the right of the centre of the river";
    break;
  case 5:
    return "close to the right bank";
    break;
  case 6:
    return "right beside the right bank";
    break;
  }
}

string get_ob_position(int ob_dist){
  int placement;
  if (ob_dist>sizeof(obstruction_placements)){
    return "The obstruction seems to be placed beyond"
          +" the end of the map. Very strange. The"
          +" map does not go as far as position "
          + ob_dist;
  }
  placement =  obstruction_placements[ob_dist];
  return get_river_position(placement);
}

string get_dist_string(int distance){
  switch (distance){
  case 1:
    return "ten yards";
  case 2:
    return "twenty yards";
  case 3:
    return "thirty yards";
  case 4:
    return "forty yards";
  case 5:
    return "fifty yards";
  case 6:
    return "sixty yards";
  case 7:
    return "seventy yards";
  case 8:
    return "eighty yards";
  case 9:
    return "ninety yards";
  default:
    return "a long way";
  }
}

mapping query_bends(){
  int i, j, prev_dir, bend_counter, dog_leg;
  mapping result;
  result = ([]);
  prev_dir = 0;
  dog_leg = 0;

  if (progress<sizeof(path)-1){
    prev_dir = path[progress];
  }else {
    return ([1:"There was an error in the listing for the bends"]);
  }
  for (i=progress+1;i<progress+10;i++){
  //  log += "Looping, checking for next bend at point " + i + "\n";
    bend_counter = 0;
    dog_leg = 0;
    if (i >= river_length - 1){
      result += ([ i: "The river empties into a small lake "]);
      return result;
    }
/*    if (prev_dir ==path[i]){
      result += "The river carries straight on "
              + get_dist_string(i-progress) +" ahead.";
    }
*/

    // Add in the text for a right turn
    if ((!(prev_dir==0&&path[i]==15) &&prev_dir < path[i] )
                     ||(prev_dir==15 && path[i]==0)){
 //     log += "Found a right turn at point " + i
 //            + ". prev_dir = " + prev_dir + ", path[i] = " + path[i];
      bend_counter ++;
      prev_dir = path[i];
      for (j=i+1;j<i + 3;j++){
  //      log += "Looping to check how the bend goes. j = " + j +"\n";
        if (j>=sizeof(path)-1){
   //       log += "the river ends at point " + j;
          result += ([i:"The river bends to the right then empties into"
                       +" a small lake "]);
          return result;
        }
        if ((!(prev_dir==0&&path[j]==15) && prev_dir < path[j])
                     ||(prev_dir==15 && path[j]==0)){
   //       log += "Found a right turn at point " + j
   //          + ". prev_dir = " + prev_dir + ", path[j] = " + path[j];
          bend_counter++;
        }
        if ((!(prev_dir==15 && path[j]==0) && prev_dir > path[j])
                     ||(prev_dir==0 && path[j]==15)){
  //        log += "Found a left turn (dogleg) at point " + j
  //         + ". prev_dir = " + prev_dir + ", path[j] = " +path[j]+"\n";
          result += ([i:"The river bends right and then left "]);
          dog_leg = 1;
          prev_dir = path[j];
          j++;
          break;
        }
        prev_dir = path[j];
      }
      if (dog_leg==0){
 //     log += "No dogleg found. bend_counter = " + bend_counter + "\n";
        switch (bend_counter){
        case 1:
          result += ([i:"The river bends slightly to the right "]);
          break;
        case 2:
          result += ([i:"The river bends to the right "]);
          break;
        case 3:
          result += ([i:"The river bends sharply to the right "]);
          break;
        default:
          result += ([i:"We thought you were turning to the right, but"
                       +" there was an error with your bend counter "]);
        }
      }
      i=j-1;
    }
    // Add in the text for a left turn
    if ((!(prev_dir== 15 && path[i]==0)&&prev_dir>path[i] )
                  ||(prev_dir==0 && path[i]==15)){
  //    log += "Found a left turn at point " + i
  //           + ". prev_dir = " + prev_dir + ", path[i] = " + path[i];

      bend_counter --;
      prev_dir = path[i];
      for (j=i+1;j<i+3;j++){
//        log += "Looping to check how the bend goes. j = " + j +"\n";
        if (j>=sizeof(path)-1){
//          log += "end of the river found at point " +j + "\n";
          result += ([i:"The river bends to the left then empties into a"
                   +" small lake "]);
          return result;
        }
        if ((!(prev_dir==15 && path[i]==0)&& prev_dir > path[j])
                  ||(prev_dir==0 && path[j]==15)){
 //         log += "Found a left turn at point " + j
 //            + ". prev_dir = " + prev_dir + ", path[j] = " + path[j];
          bend_counter--;
        }
        if ((!(prev_dir==0&& path[j]==15)&&prev_dir < path[j])
                  ||(prev_dir==15 && path[j]==0)){
 //         log += "Found a right turn (dogleg) at point " + j
 //            + ". prev_dir = " + prev_dir + ", path[j] = " + path[j];

          result += ([i:"The river bends left and then right "]);
          dog_leg = 1;
          prev_dir = path[j];
          j++;
          break;
        }
        prev_dir = path[j];
      }
      if (dog_leg==0){
 //     log += "No dogleg found. bend_counter = " + bend_counter + "/n";
        switch (bend_counter){
        case -1:
          result += ([i:"The river bends slightly to the left "]);
          break;
        case -2:
          result += ([i:"The river bends to the left "]);
          break;
        case -3:
          result += ([i:"The river bends sharply to the left "]);
          break;
        default:
          result+=([i:"We thought you were turning left, but there was an"
                 +" error with your bend counter "]);
        }
      }
      i=j-1;
    }

  }
  return result;
}
string bends_description(){
  int i;
  string result;
  mapping bends;
  result = "";
  bends = query_bends();
  for (i=1;i<11;i++){
    if (progress+i>=sizeof(bends)){
      break;
    }
    if (bends[progress+i]!=0){
      result += bends[progress+i];
      if (obstructions[progress+i]!="none"){
        result += "and there " + obstructions[progress+i]
               + get_ob_position(progress+i)+ " " ;
      }
      result += get_dist_string(i) + " ahead.\n";
    }
  }
  return result;
}

string obs_description(){
  int i;
  string result;
  result = "";
  obstructions = query_obstructions();

  for (i=1;i<11;i++){
    if (progress+i>=sizeof(path)){
      break;
    }
    if (progress + i>=sizeof(obstructions)){
      break;
    }
    if (obstructions[progress+i]!="none"){
      result += "There is "+ obstructions[progress+i]
              + get_ob_position(progress+i)+ " ";
      result += get_dist_string(i) + " ahead.\n";
    }
  }
  return result;
}

string long_desc(){
  string result, * obstructions;
  mapping bends;
  int i;
  if (capsized ==2){
    tell_object(TP, "The canoe has been capsized! You"
           +" end up in the river!");
    TP->move(ROOM + "river");
//    TP->force_me("look");
    return "";
  }
  show_river(TP);
  result = "You are in a small, pointed water craft. It comes complete"
          +" with a paddle and is just about wide enough to kneel down"
          +" in.\n";
  result += bends_description();
  result += obs_description();
  if (query_exit("out")==ROOMS + "river_beach")
  {
    result += "The canoe is pulled up on the beach"
      +" of a secret island in the middle"
      +" of the river";
  }
    return result;
}

int query_boat_speed(){
  return boat_speed;
}

string speed_change_description(int travel_speed){
  if (!intp(travel_speed) || progress>sizeof(speed)-1) return "";
  switch (travel_speed){
  case 0:
    break;
  case -5..-1:
    switch(speed[progress] - speed[progress+1]){
    case 0:
      return "";
      break;
    case 1..4:
      return "The river runs faster here";
      break;
    case -4..-1:
      return "The water flows more slowly here";
    }
  case 1..5:
    if (!intp(speed[progress]) || !intp(speed[progress-1])) break;
    switch(speed[progress] - speed[progress-1]){
    case 0:
      return "";
      break;
    case 1..4:
      return "The river runs faster here";
      break;
    case -4..-1:
      return "The water flows more slowly here";
    }
  }
  return "";
}

int change_speed (int spd){
  if (spd>1 || spd <-1){
    return -10;
  }
  boat_speed += spd;
  if (boat_speed>2){
    boat_speed = 2;
  }
  if (boat_speed < -2){
    boat_speed = -2;
  }
  return boat_speed;
}

void capsize(){
  object * occupants, river;
  int i, bank_num;
  bank_num = (progress / (river_length+1))*4;
  bank_num ++;
  river = find_object_or_load(JUNG_ROOM + "river" + bank_num );
  if (!objectp(river)){
    tell_room(TO, "Error with the river you were falling into ('" +
              JUNG_ROOM + "river" + bank_num + ".c" + "'). Please"+
              " tell a Wiz, and/or bug this room.");
    return;
  }
  occupants = PATHFINDER->all_living_present(TO);
  if (sizeof(occupants)>0){
    for(i=0;i<sizeof(occupants);i++){
      if (!occupants[i]->query_true_invis()){
        tell_room(TO, (string)occupants[i]->QCN + " falls into the river!",
          occupants[i]);
      }
      tell_object(occupants[i], "You fall into the river with a "
                                +"splash!");
      occupants[i]->move(river);
    }
  }
  capsized = 2;
}


int query_lat_dist(int relative_direction, int speed){
  switch (relative_direction){
  case 0: // deliberately allowing this to fall through to the next line
  case 8:
    return 0;
    break;
  case 1:
    switch (speed){
    case 0..2:
      return 1;
    case -1..-2:
      return -1;
    }
    break;
  case 2..6:
    switch (speed){
    case 0..2:
      return 1;
    case -1..-2:
      return -1;
    }
    break;
  case 7:
    switch (speed){
    case 0..2:
      return 1;
    case -1..-2:
      return -1;
    }
    break;
  case 9:
    switch (speed){
    case 0..2:
      return -1;
    case -1..-2:
      return 1;
    }
    break;
  case 10..11:
    return boat_speed*-1;
    break;
  case 12:
    switch (speed){
    case 0..2:
       return -1;
    case -1..-2:
      return 1;
    }
    break;
  case 13..14:
    return boat_speed*-1;
  case 15:
    switch (speed){
    case 0..2:
       return -1;
    case -1..-2:
      return 1;
    }
    break;
  }
}

void hit_obstruction(string obstruction){  //blah
  object * critters, critter;
  critters = all_living(TO);
  foreach(critter in critters)
  {
    critter->force_me("look");
  }
  if (obstruction == "is an island " || obstruction == "is a waterfall ") return;
  tell_room(TO, "%^BOLD%^%^CYAN%^The canoe hits  %^RESET%^" + obstruction
               + "%^BOLD%^%^CYAN%^. You"
               +" capsize and end up in the "
               +"%^BOLD%^%^BLUE%^river%^CYAN%^!");

  capsize();
}

int apply_lateral_travel(){
  int relative_direction, lat_dist, ob_position;
  string obstruction;
  relative_direction = query_relative_direction();
//  tell_room(TO, "relative direction is: " + relative_direction);

  lat_dist = query_lat_dist(relative_direction, boat_speed);
  position += lat_dist;

  switch (lat_dist){
  case 0:
    tell_room(TO, "The canoe continues straight down the river");
    break;
  case 1:
    tell_room(TO, "The canoe moves toward the right hand bank");
    break;
  case 2:
    tell_room(TO, "The canoe slews wildly toward the right hand bank!");
    break;
  case -1:
    tell_room(TO, "The canoe moves toward the left hand bank");
    break;
  case -2:
    tell_room(TO, "The canoe slews wildly toward the left hand bank!");
    break;
  }
//Check for obstruction
  obstruction = obstructions[progress];
  if (obstruction != "none" && obstruction != "is an island " &&
      obstruction != "is a waterfall " ){
    special_report("%^B_WHITE%^%^BOLD%^%^BLACK%^There is NOT a waterfall or an ISLAND!");
    ob_position = obstruction_placements[progress];
    if (ob_position< position && ob_position < position - lat_dist){
      tell_room(TO, obstruction + " passes by to your left.");
    } else {
      if (ob_position> position && ob_position > position - lat_dist){
        tell_room(TO, obstruction + " passes by to your right.");
      } else {
        hit_obstruction(obstruction);
        return;
      }
    }
  } else
  {
    special_report("%^B_CYAN%^%^BOLD%^%^WHITE%^There might be a waterfall or an ISLAND!");
    if (obstruction == "is a waterfall " )
    {
  //    waterfall();
      return;
    }
    if (obstruction == "is an island " )
    {
   //   arrive();
      return;
    }
  }
//tell_room(TO, "Current position is: " + position);
  return position;
}

void special_report(string str){
  /* "/daemon/reporter_d"->report("lujke", str); */
}

int query_relative_direction(){
  int relative_direction;
  relative_direction = direction - river_flow;
  if (relative_direction<0){
    relative_direction += 16;
  }
  return relative_direction;
}

void arrive(){
  object * critters, crit;
  critters = all_living(TO);
  if (sizeof(critters)<1) return;
  foreach(crit in critters)
  {
    "/daemon/pic_shower_d"->showpic("islandbeach");
  }
  launched = 2;
  remove_exit("out");
  set_exits( ([ "out" : ROOMS + "river_beach" ]) );
}

void waterfall(){
  object mazeroom;
  if(position<3){position ++;}
  if (position >3) {position --;}
  mazeroom = find_object_or_load(JUNG_ROOM7 + "j_maze0");
  mazeroom->initiate_maze_room(mazeroom, "/d/atoyatl/tecqumin/jungleg/rooms/", 0);
  call_out("waterfall1a", 1);
}

void waterfall1a(){
  tell_room(TO, "The canoe is caught by a strong current and"
               +" pulled to the centre"
               +" of the river. You can hear an ominous rumble.");
}

void waterfall2(){
  if(position<3){position ++;}
  if (position >3) {position --;}
  call_out("waterfall2a", 1);
}

void waterfall2a(){
  tell_room(TO, "The canoe accelerates forward to the centre of"
               +" the river, as the increasingly strong current pulls it"
               +" swiftly toward the rumbling sound that is getting"
             +" louder and louder.");
}

void waterfall3(){
  if(position<3){position ++;}
  if (position >3) {position --;}
  call_out("waterfall3a", 1);
}

void waterfall3a(){
  tell_room(TO, "The RUMBLING sound is near"
               +" deafening now, as the canoe is pulled directly toward"
               +" the oncoming water"
               +"fall!");
 call_out("waterfall4", 3);
}

void waterfall4(){
  object * critters, crit;
  critters = all_living(TO);
  if (sizeof(critters)<1) return;
  foreach (crit in critters)
  {
    "/daemon/pic_shower_d"->showpic("waterfall2", crit);
  }
  call_out("waterfall4a", 2);
}


void waterfall4a(){
  object * critters, crit;
  critters = all_living(TO);
  if (sizeof(critters)<1) return;
  foreach (crit in critters)
  {
    "/daemon/pic_shower_d"->showpic("waterfall3", crit);
  }
  call_out("waterfall5", 3);
}

void waterfall5(){
  object * critters, crit;
  critters = all_living(TO);
  if (sizeof(critters)<1) return;
  foreach (crit in critters)
  {
    "/daemon/pic_shower_d"->showpic("canoefall", crit);
  }
  call_out("waterfall6", 2);
}

void waterfall6(){
  object * critters, crit;
  critters = all_living(TO);
  if (sizeof(critters)<1) return;
  foreach (crit in critters)
  {
    "/daemon/pic_shower_d"->showpic("canoefall2", crit);
  }
  call_out("waterfall7", 2);
}

void waterfall7(){
  tell_room(TO, " \n\n\n\n\n\n\n\n\n\n\nYou hit the water like a sack of kobolds dropped from the top of the Crystal Tower");
  call_out("waterfall8", 3);
}


void waterfall8(){
  tell_room(TO, "\n\n\n\n\n\n\n\After a brief struggle for life and breath, you "
               +"drown.");
  call_out("waterfall19", 2);
}

void waterfall19(){
  object * critters;
  int i, num;
  tell_room(TO, "Oh wait, no. After a brief struggle for life and"
               +" breath, you surface and manage to swim to the shore.");
  critters = all_living(TO);
  num = sizeof(critters);
  if (num>0){
    for (i=0;i<num;i++){
      critters[i]->move(JUNG_ROOM7 + "riverbank.c");
    }
  }
  call_out("waterfall10",2, critters);
}

void waterfall10(object * critters){
  object crit;
  if (sizeof(critters)<1) return;
  foreach (crit in critters)
  {
    crit->force_me("look");
  }
}

void show_position(int pos){
  string message;
  message = "The boat is ";
  message = message + get_river_position(pos);
  message += ".";
  tell_room(TO, message);
}

string get_speed_message(){
  string b_speed, r_speed;
  r_speed = "%^BOLD%^%^BLUE%^";
  if (sizeof(speed)>progress)
  {
    river_speed = speed[progress];
  } else
  {
    river_speed = random(5)+1;
  }
  if (intp(river_speed)){
  switch(river_speed)
  {
    case 1:
      r_speed += "The river's flow is barely perceptible";
      break;
    case 2:
      r_speed += "The river meanders slowly along";
      break;
    case 3:
      r_speed += "The river flows at a steady pace";
      break;
    case 4:
      r_speed += "The river flows swiftly";
      break;
    case 5:
      r_speed+= "White horses break here and there as the river rushes and tumbles at great speed";
      break;
    }
  } else
  {
    r_speed = "Oh NO! The river speed is an array!";
  }
  switch(boat_speed)
  {
  case -2:
    b_speed = "Backpaddling has slowed the canoe as much as possible from the flow of the river";
    break;
  case -1:
    b_speed = "Backpaddling has slowed the canoe down from the flow of the river";
    break;
  case 0:
    b_speed = "The canoe is keeping pace with the flow of the river";
    break;
  case 1:
    b_speed = "The canoe is going a little faster than the river";
    break;
  case 2:
    b_speed = "The canoe is going as fast as possible ahead of the current of the river";
    break;
  }
  return "%^BOLD%^%^BLUE%^"+ r_speed + "  %^BOLD%^%^RED%^"+b_speed;
}

void report(string str){
//  "/daemon/reporter_d"->report("lujke", str);
}

void travel(){
  int j, x, delay, countdown;
  int travel_speed;
  int relative_direction;
  string obname;
  int obpos;
  object* kritters, kritter;
  if (launched ==3) return;
  if (capsized == 2) return;
  if (paused % 2 ==1){
    report ("PAUSED");
    if (pause_count ==10)
    {
      tell_room(TO, "Pause duration completed. Resuming journey");
      paused = 0;
      pause_count = 0;
      call_out("travel", 3);
      return;
    }
    countdown = 10- pause_count;
    tell_room(TO, "%^BOLD%^%^WHITE%^The canoe ride is PAUSED. Countdown to restart: %^BOLD%^%^YELLOW%^" + countdown);
    tell_room(TO, "To restart ahead of countdown, type <resume>");
    if (pause_count <20) pause_count ++;
    call_out("travel", 8);
    return;
  }
  if (sizeof(speed) > progress)
  {
    river_speed = speed[progress];
  } else
  {
    river_speed = random(4)+1;
  }
  river_length = sizeof(path);
  kritters = all_living(TO);
  if (sizeof(kritters)<1){
    return;
  }
// work out how far the boat will travel down the river this round

  relative_direction = query_relative_direction();
  travel_speed = river_speed;
  if (!intp(travel_speed)) travel_speed = 2 + random(3);
  if (relative_direction ==12 ||relative_direction ==4){
    if (river_speed>=3){
      tell_room(TO, "%^BOLD%^%^BLUE%^The %^CYAN%^sw%^WHITE%^i%^CYAN%^ft"
        +" %^BLUE%^flowing w%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^t%^WHITE%^e%^BLUE%^r"
        +" roars over the %^RED%^ca%^YELLOW%^noe%^BLUE%^ as it turns"
        +" side on to the %^CYAN%^stream%^BLUE%^. %^WHITE%^You capsize!");
      capsize();
      foreach(kritter in kritters)
      {
        kritter->force_me("look");
      }
      return;
    }
  }
  switch (relative_direction){
  case 0..2:
    if (!intp(travel_speed) || !intp(boat_speed)) break;
    travel_speed += boat_speed;
    break;
  case 3..5:
    if (!intp(travel_speed) || !intp(boat_speed)) break;
    switch (boat_speed){
    case -1..-2:
      travel_speed -=1;
      break;
    case 1..2:
      travel_speed +=1;
      break;
    }
    break;
  case 11..13:
    if (!intp(travel_speed) || !intp(boat_speed)) break;
    switch (boat_speed){
    case -1..-2:
      travel_speed -=1;
      break;
    case 1..2:
      travel_speed +=1;
      break;
    }
    break;
  case 14..15:
    if (!intp(travel_speed) || !intp(boat_speed)) break;
    travel_speed += boat_speed;
    break;
  default:
    if (!intp(travel_speed) || !intp(boat_speed)) break;
    travel_speed -= boat_speed;
    break;
  }

  // apply the boat's progress during the round
  if (!intp(river_speed) || !intp(boat_speed))
  {
    river_speed = random(4) +1;
    boat_speed = 0;
  }

  if (boat_speed + river_speed>0){
    progress ++;
  }
  if (boat_speed + river_speed<0){
    progress --;
  }

  if (progress == river_length-10 && position >1 && position < 5){
    arrive();
    launched = 2;


    return;
  }
  if (progress == river_length-2){
    waterfall();
  }
  if (progress == river_length-6){
    waterfall2();
  }  if (progress == river_length-5){
    waterfall3();
    return;
  }
  if (river_flow > path[progress]||(river_flow == 0 && path[progress]==15)){
    tell_room(TO, "The river bends to the left");
  }
  if (river_flow<path[progress]||(river_flow == 15 &&path[progress]==0)){
    tell_room(TO, "The river bends to the right");
  }
  if (sizeof(path)>progress)   river_flow = path[progress];
  if (sizeof(speed)>progress) river_speed = speed[progress];
  relative_direction = query_relative_direction();

//  tell_room(TO, "about to apply lateral travel");

  apply_lateral_travel();
  if (capsized ==2) return;
//  tell_room(TO, "Finished applying lateral travel. You really should have heard something then.");
  if (sizeof(obstructions)>progress)
  {
    obname = obstructions[progress];
    if (sizeof(obstruction_placements)>progress)
    {
      obpos = obstruction_placements[progress];
    }
    if (intp(obpos) && obpos == position && stringp(obname) && obname != "none")
    {
      hit_obstruction(obname);
    }
  }

  if (position>6){
    tell_room(TO, "%^BOLD%^%^YELLOW%^The canoe %^RED%^crashes%^YELLOW%^ on the right bank of the river!");
    capsized = 2;
    if (sizeof(kritters)>0){
      for (j=0;j<sizeof(kritters);j++){
        if (objectp(kritters[j])){
          tell_object(kritters[j], "You tumble out of the canoe and"
                                  +" into the river!");
          x = (progress / (river_length+1))*4;
          x++;
          kritters[j]->move_player(JUNG_ROOM + "river" + x);
        }
      }
    }
    return;
  }
  if (position<0){
    tell_room(TO, "%^BOLD%^%^YELLOW%^The canoe %^RED%^crashes %^YELLOW%^on the left bank of the river!");
    capsized = 2;
    if (sizeof(kritters)>0){
      x = (progress / (river_length+1))*4;
      x++;
      for (j=0;j<sizeof(kritters);j++){
        if (objectp(kritters[j])){
          tell_object(kritters[j], "You tumble out of the canoe and"
                                  +" into the river!");
          kritters[j]->move_player(JUNG_ROOM + "river" + x);
        }
      }
    }
    return;
  }
  if (travel_speed == 0){
    travel_speed = 1;
  }

// Send a message if the boat is near either bank

  switch(position){
  case 0:
    tell_room(TO,"Careful! The boat is right alongside the"
                +" left bank of the river!");
    break;
  case 1:
    tell_room(TO,"Watch it! You're getting close to the"
                +" left bank of the river!");
    break;
  case 5:
    tell_room(TO,"Watch it! You're getting close to the"
                +" right bank of the river!");
    break;
  case 6:
    tell_room(TO,"Careful! The boat is right alongside the"
                +" right bank of the river!");
    break;
  }
  show_river(kritters[j]);
  if (sizeof(kritters)>1){
    for(j =1; j<sizeof(kritters);j++)
    {
      CANOE_D->show_whole_display(kritters[j]);
    }
  }
//Send a message about the boat's position on the river
  show_position(position);

// Send a message about the direction the boat is facing on the river
  show_direction(relative_direction);
  tell_room(TO, ""+bends_description());
  tell_room(TO, ""+obs_description());
  tell_room(TO, "%^BOLD%^" + speed_change_description(travel_speed));
//  tell_room(TO, "Progress: " + progress + " Position: " + position);
  tell_room(TP, get_speed_message());


  if (boat_speed > 0){
    boat_speed --;
  }
  if (boat_speed<0){
    boat_speed ++;
  }
  if (!intp(travel_speed) || travel_speed ==0){
    travel_speed = 0;
    tell_room(TO, "You are not moving relative to the bank. You need to paddle some!");
    call_out("travel", 2);
    return;
  }
  if (travel_speed<0){
    tell_room(TO, "You are going backward relative to the bank. Perhaps you want to paddle forwards?");
  }
  delay = 12/travel_speed;
  if (travel_speed <0) {
    delay = delay *-1;
  }
  if (delay <2 && delay >=1){
    tell_room(TO, "You are going too fast. SLOW DOWN!");
  }
  if (delay<1){
    tell_room(TO, "You lose control of the canoe as it hurtles down the river."
               +" The nose dips under the surface and you CAPSIZE!");
    capsize();
    return;
  }
//  delay ++;
  call_out("travel", delay);
}

void show_direction(int relative_direction){
  switch(relative_direction){
  case 0:
    tell_room(TO,"The canoe is pointing straight forward down the river");
    break;
  case 1:
    tell_room(TO,"The canoe is pointing forward, angling slightly toward"
                +" the right hand bank of the river");
    break;
  case 2:
    tell_room(TO,"The canoe is pointing forward, diagonally toward the"
                +" right hand bank of the river");
    break;
  case 3:
    tell_room(TO,"The canoe is pointing forward, but angling sharply toward the right hand bank of the river");
    break;
  case 4:
    tell_room(TO,"The canoe is side on to the current, heading toward the right hand bank of the river");
    break;
  case 5:
    tell_room(TO,"The canoe is pointing toward the right hand bank of the river, angling slightly upstream");
    break;
  case 6:
    tell_room(TO,"The canoe is pointing diagonally upstream toward the right hand bank of the river");
    break;
  case 7:
    tell_room(TO,"The canoe is pointing upstream, angling slightly toward the right hand bank of the river");
    break;
  case 8:
    tell_room(TO,"The canoe is pointing directly upstream");
    break;
  case 9:
    tell_room(TO,"The canoe is pointing upstream, angling slightly toward the left hand bank of the river");
    break;
  case 10:
    tell_room(TO,"The canoe is pointing diagonally upstream toward the left hand bank of the river");
    break;
  case 11:
    tell_room(TO,"The canoe is pointing toward the left hand bank of the river, angling slightly upstream");
    break;
  case 12:
    tell_room(TO,"The canoe is side on to the current, heading toward the left hand bank of the river");
    break;
  case 13:
    tell_room(TO,"The canoe is pointing forward, angling sharply toward the left hand bank of the river");
    break;
  case 14:
    tell_room(TO,"The canoe is pointing diagonally forward toward the left hand bank of the river");
    break;
  case 15:
    tell_room(TO,"The canoe is pointing forward, angling slightly toward the left hand bank of the river");
    break;

  }
}


void paddle_left(){
  boat_speed+=1;
  direction +=1;
  if (boat_speed >2){
    boat_speed = 2;
  }
  if (direction>15){
    direction = 0;
  }
  tell_room(TO, "The nose of the canoe turns to the right");
  show_direction(query_relative_direction());
  show_river(TP);
//  tell_room(TO, "new direction is: "
//                          + direction);
//  tell_room(TO, "new relative direction is: "
//                          + query_relative_direction());
  if (find_call_out("travel") == -1) call_out("travel", 2);
  tell_room(TO, get_speed_message());
}

void paddle_right(){
  boat_speed+=1;
  direction -=1;

  if (boat_speed >2){
    boat_speed = 2;
  }
  if (direction<0){
    direction = 15;
  }
  tell_room(TO, "The nose of the canoe turns to the left");
  show_direction(query_relative_direction());
  show_river(TP);
//  tell_room(TO, "new direction is: "
//                          + direction);
//  tell_room(TO, "new relative direction is: "
//                          + query_relative_direction());
  if (find_call_out("travel") == -1) call_out("travel", 2);
  tell_room(TO, get_speed_message());
}


void back_paddle_left(){
  boat_speed-=1;
  direction -=1;
  if (boat_speed <-2){
    boat_speed = -2;
  }
  if (direction<0){
    direction = 15;
  }
  tell_room(TO, "The nose of the canoe turns to the left");
  show_direction(query_relative_direction());
  show_river(TP);
//  tell_room(TO, "new direction is: "
//                          + direction);
//  tell_room(TO, "new relative direction is: "
//                          + query_relative_direction());
  if (find_call_out("travel") == -1) call_out("travel", 2);
  tell_room(TO, get_speed_message());
}

int get_direction(){
  return direction;
}

void set_direction(int dir){
  direction = dir;
}

void back_paddle_right(){
  boat_speed-=1;
  direction +=1;

  if (boat_speed <-2){
    boat_speed = -2;
  }
  if (direction>15){
    direction = 0;
  }
  tell_room(TO, "The nose of the canoe turns to the right");
  show_direction(query_relative_direction());
  show_river(TP);
//  tell_room(TO, "new direction is: "
//                          + direction);
//  tell_room(TO, "new relative direction is: "
//                          + query_relative_direction());
  if (find_call_out("travel") == -1) call_out("travel", 2);
  tell_room(TO, get_speed_message());
}

void set_progress(int p){
  progress = p;
}

void launch(object ob){
  if (!objectp(ob)){
    return;
  }
  if (progress>=sizeof(path)){
    progress = 0;
  }
  if (query_exit("out")==ROOMS + "river"){
    tell_object(ob, "The canoe is already launched, isn't it? If not, please make a bug report");
    return;
  }
  if (query_exit("out")!=ROOMS + "river_beach"){
    progress = 0;
    direction = 0;
  }
  tell_object(ob, "Using your paddle, you push off from the"
                 +" bank");
  tell_room(TO, "Using " + (string)ob->QP + " paddle, "
              + (string) ob->QCN + " pushes off from the bank", ob);
  tell_room(TO,"The canoe moves off to the centre of the river");
  position = 4;
  remove_exit("out");
  set_exits( ([ "out" : ROOMS + "river" ]) );
  call_out("travel",2);
  launched = 1;
  show_river(ob);
}
