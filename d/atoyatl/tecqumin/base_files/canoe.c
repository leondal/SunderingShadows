#include <std.h>
#include "../tecqumin.h"
#define STRAIGHT 0
#define SLIGHT_LEFT -1
#define LEFT -2
#define HARD_LEFT -3
#define SLIGHT_RIGHT 1
#define RIGHT 2
#define HARD_RIGHT 3
#define OBS_INTERVAL 10
#define PATHFINDER "/daemon/pathfinder_d.c"

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
  int i, j, bend;
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
    speed += ({river_speed});


    bend = random(9)-4;
    switch (bend){
    case STRAIGHT:
      path += ({direction});
      path += ({direction});
      path += ({direction});
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
      direction ++;
      if (direction>15){
        direction = 0;
      }
      path += ({direction});
      direction ++;
      if (direction>15){
        direction = 0;
      }
      path += ({direction});
      break;
    case HARD_RIGHT:
      direction ++;
      if (direction>15){
        direction = 0;
      }
      path += ({direction});
      direction ++;
      if (direction>15){
        direction = 0;
      }
      path += ({direction});
      direction ++;
      if (direction>15){
        direction = 0;
      }
      path += ({direction});
      break;
    case SLIGHT_LEFT:
      path += ({direction});
      direction --;
      if (direction<0){
        direction = 15;
      }
      path += ({direction});
      path += ({direction});
      break;
    case LEFT:
      path += ({direction});
      direction --;
      if (direction<0){
        direction = 15;
      }
      path += ({direction});
      direction --;
      if (direction<0){
        direction = 15;
      }
      path += ({direction});
      break;
    case HARD_LEFT:
      direction --;
      if (direction<0){
        direction = 15;
      }
      path += ({direction});
      direction --;
      if (direction<0){
        direction = 15;
      }
      path += ({direction});
      direction --;
      if (direction<0){
        direction = 15;
      }
      path += ({direction});
      break;
    }
  }
  river_length = sizeof(path);
  obstructions = ({});
  obstruction_placements = ({});
  for (i=0;i<river_length;i++){
    if (!random(OBS_INTERVAL)){
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
      obstruction_placements += ({random(9)});
    }else{
      obstructions += ({"none"});
      obstruction_placements +=({0});
    }
  }
  path += ({direction, direction, direction});
  speed += ({speed, speed, speed});
  obstructions += ({"none", "none", "is an island "});
  obstruction_placements += ({4, 4, 4});
  path += ({direction, direction, direction, direction});
  speed += ({2,2,3});
  obstructions += ({"none", "none", "is a waterfall "});
  obstruction_placements += ({4, 4, 4});
  river_length = sizeof(path);
  last_paddle = 0;
  launched = 0;
}

string * query_obstructions(){
  return obstructions;
}
/*
string query_log(){
  return log;
} */

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
    launched = 0;
    paddle = new (OBJ + "paddle");
    paddle->move(TO);
  }
}

query_launched(){
  return launched;
}

string get_river_position(int pos){
  switch (pos){
  case 0:
    return "right beside the left bank";
    break;
  case 1..2:
    return "close to the left bank";
    break;
  case 3: 
    return "slightly to the left of the centre of the river";
    break;
  case 4:
    return "in the middle of the river";
    break;
  case 5:
    return "slightly to the right of the centre of the river";
    break;
  case 6..7:
    return "close to the right bank";
    break;
  case 8:
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
/*
void advance(){
  progress ++;
}

void retreat(){
  progress --;
}*/

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
  if (capsized ==1){
    tell_object(TP, "%^BOLD%^%^CYAN%^The canoe has been capsized! You"
           +" end up in the %^BLUE%^river%^RESET%^%^BOLD%^%^CYAN%^!");
    TP->move(ROOM + "river");
    TP->force_me("look");
    return "";
  }
  result = "You are in a small, pointed water craft. It comes complete"
          +" with a paddle and is just about wide enough to kneel down"
          +" in.\n";
  result += bends_description();
  result += obs_description();
    return result;
}

string speed_change_description(int travel_speed){
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
    tell_room(TO, "Error with the river you were falling into ('" + JUNG_ROOM + "river" + bank_num + ".c" + "'). Please tell a Wiz, and/or bug this room.");    
    return;
  }
  occupants = PATHFINDER->all_living_present(TO);
  if (sizeof(occupants)>0){
    for(i=0;i<sizeof(occupants);i++){
      if (!occupants[i]->query_true_invis()){
        tell_room(TO, (string)occupants[i]->QCN + " falls into the river!", occupants[i]);
      }
      tell_object(occupants[i], "%^BOLD%^%^BLUE%^You fall into the river with a %^BOLD%^"
                                +"%^CYAN%^splash%^BLUE%^!%^RESET%^");
      occupants[i]->move(river);
    }
  }
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

void hit_obstruction(string obstruction){
  tell_room(TO, "The canoe hits  " + obstruction + ". You%^BOLD%^"
               +"%^CYAN%^ capsizes%^RESET%^ and end up in the %^BOLD%^"
               +"%^BLUE%^river%^RESET%^!");
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
  case -1:
    tell_room(TO, "The canoe moves toward the left hand bank");
    break;
  case -2:
    tell_room(TO, "The canoe slews wildly toward the left hand bank!");
    break;
  }
//Check for obstruction
  obstruction = obstructions[progress];
  if (obstruction != "none" && obstruction != "is an island " && obstruction != "is a waterfall " ){
    ob_position = obstruction_placements[progress];
    if (ob_position< position && ob_position < position - lat_dist){
      tell_room(TO, obstruction + " passes by to your left.");
    } else {
      if (ob_position> position && ob_position > position - lat_dist){
        tell_room(TO, obstruction + " passes by to your right.");
      } else {
        hit_obstruction(obstruction);
      }
    }
  }
//tell_room(TO, "%^BOLD%^%^CYAN%^Current position is: " + position);
  return position;
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
  tell_room(TO, "%^ORANGE%^With a loud CRUNCH, the canoe grounds"
               +" itself on an island in the middle of the stream."
               +" Outside, you can see a %^BOLD%^%^YELLOW%^sandy beach.");
  remove_exit("out");
  set_exits( ([ "out" : ROOMS + "river_beach" ]) );
}

void waterfall(){
  tell_room(TO, "%^BLUE%^The canoe is caught by a strong current and"
               +" pulled to the %^BOLD%^%^CYAN%^centre%^RESET%^"
               +"%^BLUE%^ of the river. You can hear an ominous rumble.");
  if(position<4){position ++;}
  if (position >4) {position --;}
  call_out("waterfall2", 2);
}

void waterfall2(){
  tell_room(TO, "%^BLUE%^The canoe accelerates forward in the centre of"
               +" the river, as the increasingly strong current pulls it"
               +" swiftly toward the rumbling sound that is getting"
             +"%^ORANGE%^ louder%^BLUE%^ and %^ORANGE%^louder%^BLUE%^.");
  call_out("waterfall3", 3);
}

void waterfall3(){
  tell_room(TO, "%^BLUE%^The %^ORANGE%^RUMBLING %^BLUE%^sound is near"
               +" deafening now, as the canoe is pulled directly toward"
               +" the oncoming %^BOLD%^%^WHITE%^w%^CYAN%^a%^WHITE%^ter"
               +"%^BLUE%^f%^WHITE%^all%^BLUE%^!");
  call_out("waterfall4", 3);
}

void waterfall4(){
  tell_room(TO, "%^ORANGE%^With a terrifying inevitability, the canoe"
              +" tips over the edge of the %^BOLD%^%^WHITE%^w%^CYAN%^a"
              +"%^WHITE%^terf%^BLUE%^a%^WHITE%^ll%^RESET%^%^ORANGE%^");
  call_out("waterfall5", 1);
}

void waterfall5(){
  tell_room(TO, "%^BOLD%^%^WHITE%^You plunge DOWN");
  call_out("waterfall6", 1);
}

void waterfall6(){
  tell_room(TO, "%^BOLD%^%^WHITE%^                   DOWN");
  call_out("waterfall7", 1);
}

void waterfall7(){
  tell_room(TO, "%^BOLD%^%^WHITE%^                         and"
                +" further DOWN");
  call_out("waterfall8", 1);
}

void waterfall8(){
  tell_room(TO, "%^BOLD%^%^CYAN%^...and land in the water.");
  call_out("waterfall9", 2);
}

void waterfall9(){
  tell_room(TO, "After a brief struggle for life and breath, you %^BLUE%^"
               +"drown%^RESET%^.");
  call_out("waterfall10", 1);
}

void waterfall10(){
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
}

void show_position(int pos){
  string message;
  message = "%^CYAN%^The boat is ";
  message = message + get_river_position(pos);
  message += ".";
  tell_room(TO, message);
}

void travel(){
  int j, x, delay;
  int travel_speed;
  int relative_direction;
  object* kritters;

  river_length = sizeof(path);
  kritters = all_living(TO);
  if (sizeof(kritters)<1){
    return;
  }
// work out how far the boat will travel down the river this round

  relative_direction = query_relative_direction();
  travel_speed = river_speed;
  if (relative_direction ==12 ||relative_direction ==4){
    if (river_speed>=3){
      tell_room(TO, "%^BOLD%^%^CYAN%^The swift flowing water roars over"
         +" the canoe as it turns side on to the stream. You capsize!");
      capsize();
      return;
    }
  }
  switch (relative_direction){
  case 0..2:
    travel_speed += boat_speed;
    break;
  case 3..5:
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
    travel_speed += boat_speed;
    break;
  default:
    travel_speed -= boat_speed;
    break;
  }  

  // apply the boat's progress during the round
  
  if (boat_speed + river_speed>0){
    progress ++;
  } 
  if (boat_speed + river_speed<0){
    progress --;
  } 
  
  if (progress == river_length-4 && position >2 && position < 6){
    arrive();
    return;
  }
  if (progress >= river_length-1){
    waterfall();
    return;
  }
  if (river_flow > path[progress]||(river_flow == 0 && path[progress]==15)){
    tell_room(TO, "%^BOLD%^%^BLUE%^The river bends to the %^WHITE%^left");
  }
  if (river_flow<path[progress]||(river_flow == 15 &&path[progress]==0)){
    tell_room(TO, "%^BOLD%^%^RED%^The river bends to the %^WHITE%^right");
  }
  river_flow = path[progress];
  river_speed = speed[progress];
  relative_direction = query_relative_direction();

//  tell_room(TO, "about to apply lateral travel");

  apply_lateral_travel();

//  tell_room(TO, "Finished applying lateral travel. You really should have heard something then.");

  if (position>8){
    tell_room(TO, "The canoe crashes on the right bank of the river!");
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
    tell_room(TO, "The canoe crashes on the left bank of the river!");
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
    tell_room(TO,"%^BOLD%^%^RED%^Careful! The boat is right alongside the"
                +" %^WHITE%^left%^RED%^ bank of the river!");
    break;
  case 1:
    tell_room(TO,"%^RED%^Watch it! You're getting close to the"
                +" %^RESET%^left%^RED%^ bank of the river!");
    break;
  case 6:
    tell_room(TO,"%^RED%^Watch it! You're getting close to the"
                +" %^RESET%^right%^RED%^ bank of the river!");
    break;
  case 8:
    tell_room(TO,"%^BOLD%^%^RED%^Careful! The boat is right alongside the"
                +" %^WHITE%^right%^RED%^ bank of the river!");
    break;
  }

//Send a message about the boat's position on the river
  show_position(position);

// Send a message about the direction the boat is facing on the river
  show_direction(relative_direction);
  tell_room(TO, "%^ORANGE%^"+bends_description());
  tell_room(TO, "%^ORANGE%^"+obs_description());
  tell_room(TO, "BOLD%^%^WHITE%^" + speed_change_description(travel_speed));
  tell_room(TO, "%^YELLOW%^Progress: " + progress + "%^CYAN%^ Position: " + position);

  if (boat_speed > 0){
    boat_speed --;
  }
  if (boat_speed<0){
    boat_speed ++;
  }
  if (travel_speed ==0){
    tell_room(TO, "%^BOLD%^%^BLUE%^You are not moving relative to the bank. You need to paddle some!");
    call_out("travel", 2);
    return;
  }
  if (travel_speed<0){
    tell_room(TO, "%^BOLD%^%^CYAN%^You are going backward relative to the bank. Perhaps you want to paddle forwards?");
  }
  delay = 12/travel_speed;
  if (travel_speed <0) {
    delay = delay *-1; 
  }
  if (delay <2 && delay >=1){
    tell_room(TO, "%^BOLD%^%^YELLOW%^You are going too fast. %^BOLD%^%^RED%^SLOW DOWN!%^RESET%^"); 
  }
  if (delay<1){
    tell_room(TO, "%^BOLD%^%^RED%^You lose control of the canoe as it hurtles down the river."
               +" The nose dips under the surface and you %^BOLD%^%^CYAN%^CAPSIZE%^BOLD%^%^RED%^!");
    capsize();
    return;
  }
  call_out("travel", delay);
}

void show_direction(int relative_direction){
  switch(relative_direction){
  case 0:
    tell_room(TO,"%^MAGENTA%^The canoe is pointing straight forward down the river");
    break;
  case 1:
    tell_room(TO,"%^RED%^The canoe is pointing forward, angling slightly toward"
                +" the right hand bank of the river");
    break;
  case 2:
    tell_room(TO,"%^RED%^The canoe is pointing forward, diagonally toward the"
                +" right hand bank of the river");
    break;
  case 3:
    tell_room(TO,"%^BOLD%^%^RED%^The canoe is pointing forward, but angling sharply toward the right hand bank of the river");
    break;
  case 4:
    tell_room(TO,"%^BOLD%^%^RED%^The canoe is side on to the current, heading toward the right hand bank of the river");
    break;
  case 5:
    tell_room(TO,"%^BOLD%^%^RED%^The canoe is pointing toward the right hand bank of the river, angling slightly upstream");
    break;
  case 6:
    tell_room(TO,"%^RED%^The canoe is pointing diagonally upstream toward the right hand bank of the river");
    break;
  case 7:
    tell_room(TO,"%^RED%^The canoe is pointing upstream, angling slightly toward the right hand bank of the river");
    break;
  case 8:
    tell_room(TO,"%^MAGENTA%^The canoe is pointing directly upstream");
    break;
  case 9:
    tell_room(TO,"%^BLUE%^The canoe is pointing upstream, angling slightly toward the left hand bank of the river");
    break;
  case 10:
    tell_room(TO,"%^BLUE%^The canoe is pointing diagonally upstream toward the left hand bank of the river");
    break;
  case 11:
    tell_room(TO,"%^BOLD%^%^BLUE%^The canoe is pointing toward the left hand bank of the river, angling slightly upstream");
    break;
  case 12:
    tell_room(TO,"%^BOLD%^%^BLUE%^The canoe is side on to the current, heading toward the left hand bank of the river");
    break;
  case 13:
    tell_room(TO,"%^BOLD%^%^BLUE%^The canoe is pointing forward, angling sharply toward the left hand bank of the river");
    break;
  case 14:
    tell_room(TO,"%^BLUE%^The canoe is pointing diagonally forward toward the left hand bank of the river");
    break;
  case 15:
    tell_room(TO,"%^BLUE%^The canoe is pointing forward, angling slightly toward the left hand bank of the river");
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

//  tell_room(TO, "%^BLUE%^new direction is:%^BOLD%^%^BLACK%^ " 
//                          + direction);
//  tell_room(TO, "%^RED%^new relative direction is:%^BOLD%^%^BLACK%^ " 
//                          + query_relative_direction());

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

//  tell_room(TO, "%^BLUE%^new direction is:%^BOLD%^%^BLACK%^ " 
//                          + direction);
//  tell_room(TO, "%^RED%^new relative direction is:%^BOLD%^%^BLACK%^ " 
//                          + query_relative_direction());
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

//  tell_room(TO, "%^BLUE%^new direction is:%^BOLD%^%^BLACK%^ " 
//                          + direction);
//  tell_room(TO, "%^RED%^new relative direction is:%^BOLD%^%^BLACK%^ " 
//                          + query_relative_direction());
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
//  tell_room(TO, "%^BLUE%^new direction is:%^BOLD%^%^BLACK%^ " 
//                          + direction);
//  tell_room(TO, "%^RED%^new relative direction is:%^BOLD%^%^BLACK%^ " 
//                          + query_relative_direction());
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
  tell_object(ob, "%^BLUE%^Using your paddle, you push off from the"
                 +" bank");
  tell_room(TO, "%^BLUE%^Using " + (string)ob->QP + " paddle, " 
              + (string) ob->QCN + " pushes off from the bank", ob);
  tell_room(TO,"%^BLUE%^The canoe moves off to the centre of the river");
  position = 4;
  remove_exit("out");
  set_exits( ([ "out" : ROOMS + "river" ]) ); 
  progress = 0;
  direction = 0;
  call_out("travel",2);
  launched = 1;
}

