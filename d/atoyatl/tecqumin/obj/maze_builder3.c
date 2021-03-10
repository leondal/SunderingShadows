#include <std.h>
inherit OBJECT;

#define NORTH 0
#define NORTHEAST 1
#define EAST 2
#define SOUTHEAST 3
#define SOUTH 4
#define SOUTHWEST 5
#define WEST 6
#define NORTHWEST 7

#define STRAIGHT 0
#define BEND_RIGHT 1
#define RIGHT 2
#define SHARP_RIGHT 3
#define FULL_TURN 4
#define BEND_LEFT 5
#define LEFT 6
#define SHARP_LEFT 7
#define DOGLEG_LEFT 8
#define DOGLEG_RIGHT 9
#define DEAD_END 10
#define IN_SPIRAL_LEFT 11
#define IN_SPIRAL_RIGHT 12


string mazename, startpoint, endpoint, *special_rooms, roompath, *doornames, *doordescs, entry_room, exit_room, northexit, southexit,eastexit, westexit, northroom, southroom, eastroom, westroom;
int x, y, direction, gridsize, start_x, start_y, next_section, prev_x, northy, southy, eastx, westx, prev_y, room_number, sections_added, count, door_chance, *locations, spec_room_counter, prev_room_number;
//mapping room_map = ([]);
mapping room_map, maze_map, saved_mazes;

string query_entry_room();
string query_exit_room();
int set_exit_room(string str);
int set_entry_room(string str);
void add_special_room(object ob, object spec_room);
int place_east_exit();
int place_north_exit();
int place_south_exit();
int place_west_exit();
int place_special_rooms(object ob);
int place_special_room(object ob, object spec_room, string spec_roomname);
int convert_to_int (string str);
string query_eastroom();
string query_northroom();
string query_southroom();
string query_westroom();
int replace_room (object spec_room, string this_roomname);
int set_eastroom(string roomname);
int set_northroom(string roomname);
int set_southroom(string roomname);
int set_westroom(string roomname);
int set_side_path(object ob);
void set_special_rooms(string * rooms);
void set_roompath(string str);
string query_roompath();
void remove_special_room(string room);
void set_gridsize(int size);
int query_gridsize();
void set_start_x(int i);
void set_start_y(int i);
int query_start_x();
int query_start_y();
void set_direction(int dir);
int query_direction();
int calculate_x(int start_point, int direction);
int calculate_y(int start_point, int direction);
int calculate_location(int start, int direction);
int find_location(int start, int direction, int turn);
int add_exit(object room, string dir, string dest);
int add_room(int turn, object ob);
int add_section(int type, object ob);
int init_maze(int start_x, int start_y, string name, int size);
int build_maze(object ob);
int set_main_path(object ob);
string * query_special_rooms();
string query_direction_name(int dir);
mapping query_room_map();
void restore_maze(string name);


void create(){
      ::create();
//      eastroom = "";
//      northroom = "";
//     southroom = "";
//     westroom = "";
      room_map = ([]);
      direction = random(8);
      gridsize = 10;
      next_section = 0;
      door_chance = 20;
      count = 0;
      spec_room_counter=0;
      set_name("maze builder");
      set_id(({"builder", "maze builder", "maze"}));
      set_short("a virtual maze builder");
      set_long("a strange looking box with a few buttons on it, that" 
              +" seems to be spilling out randomly generated mazes onto"
              +" sheets of paper."); 
 
   	set_lore("It is widely rumoured that Lujke disapproves of mazes on"
              +" principle, beacuse He can never find His way round them."
              +" However, legend has it that on one momentous Sunday"
              +" morning He thought to Himself and spake thusly: 'If we"
              +" are to have mazes, and it seemeth that we are, then they"
              +" should be good mazes, that are different every time,"
              +" that the munchkin among you shall be as lost as the"
              +" newbie.' And as He spake, so it came to be. And much"
              +" rejoicing was there from the tower of the Immortals, and"
              +" much wailing and gnashing of teeth was to be heard among"
              +" those who are kin to munch.");
   	set_property("lore difficulty",31);
   	set_weight(2);
   	set_value(2);
      doornames = ({"door"});
      doordescs = ({"a standard wooden door, with a two tumbler lock"
                   +" arrangement."});
}

int add_exit(object room, string dir, string dest){
  mapping exits, all_rooms;
  string rm_name, * rm_names, * map_names, mz_name;
  int num_len, i;
  if (!objectp(room)||!stringp(dir)||!stringp(dest)){return 0;}
  room->add_exit(dest, dir);
  rm_name = file_name(room);
  num_len = 0;
  for (i=strlen(rm_name)-1;i>=0;i--){
    if (rm_name[i]=='1'||rm_name[i]=='2'||rm_name[i]=='3'||
        rm_name[i]=='4'||rm_name[i]=='5'||rm_name[i]=='6'||
        rm_name[i]=='7'||rm_name[i]=='8'||rm_name[i]=='9'||
        rm_name[i]=='0'){
      num_len ++;
    }
  }
  num_len = strlen(rm_name)-1 - num_len;
  mz_name = rm_name[0..num_len];
  if (!mapp(saved_mazes)||sizeof(saved_mazes)<1){
    saved_mazes = ([]);
    saved_mazes += ([ mz_name : ([]) ]);
  }  

  all_rooms = saved_mazes[mz_name];
  if (mapp(all_rooms)){
    rm_names = keys(all_rooms);
  } else {
    rm_names = ({});
  }
  if (member_array(rm_name, rm_names)==-1){
    all_rooms += ([rm_name : ([]) ]);
  }
  exits = all_rooms[rm_name];
  exits += ([ dir: dest ]);
  all_rooms[rm_name] = exits;
  saved_mazes[mz_name] = all_rooms;
}

mapping query_maze(string which_maze){
  return saved_mazes[which_maze];
}

mapping query_all_mazes(){
  return saved_mazes;
}

string query_exit_room(){
  return exit_room;
}
string query_entry_room(){
  return entry_room;
}
int set_entry_room(string str){
  entry_room = str;
}
int set_exit_room(string str){
  exit_room = str;
}
void set_roompath(string str){
  roompath = str;
}
string query_roompath(){
  return roompath;
}

string query_eastroom(){
  return eastroom;
}

string query_northroom(){
  return northroom;
}

string query_southroom(){
  return southroom;
}

string query_westroom(){
  return westroom;
}

void set_eastroom(string room){
  eastroom = room;
}
void set_northroom(string room){
  northroom = room;
}
void set_southroom(string room){
  southroom = room;
}
void set_westroom(string room){
  westroom = room;
}

int init_maze(int start_x,int start_y, string name, int size){
  x = start_x;
  y = start_y;
  gridsize = size;
  mazename = name;
  direction = random(8);
  northy = start_y;
  southy = start_y;
  eastx = start_x;
  westx = start_x;
  return build_maze(ETO);
  room_number = 0;
}

mapping query_room_map(){
  return room_map;
}

int build_maze(object ob){
  int i,j;
  set_main_path(ob);
  j = 1+ gridsize/5 + random( gridsize/5);
  for (i=0;i<j;i++){
    set_side_path(ob);
  }
//  tell_object(ob, "%^BOLD%^%^CYAN%^Placing exit rooms%^RESET%^");
  if (stringp(eastroom) && file_exists(eastroom)){
    place_east_exit();
//   tell_object(ob, "%^BOLD%^%^CYAN%^East exit room placed%^RESET%^");
  }
  if (stringp(northroom) && file_exists(northroom)){
    place_north_exit();
//    tell_object(ob, "%^BOLD%^%^CYAN%^North exit room placed%^RESET%^");
  }
  if (stringp(southroom) && file_exists(southroom)){
    place_south_exit();
//    tell_object(ob, "%^BOLD%^%^CYAN%^South exit room placed%^RESET%^");
  }
  if (stringp(westroom) && file_exists(westroom)){
    place_west_exit();
//    tell_object(ob, "%^BOLD%^%^CYAN%^West exit room placed%^RESET%^");
  }
//  tell_object(ob, "%^BOLD%^%^CYAN%^Placing special rooms%^RESET%^");
  place_special_rooms(ob);
  return 1;
}

void restore_maze(string name){
  int i, j;
  object room;
  string *roomnames, *exitnames, *destinations;
  mapping exits;
  if (member_array( name, keys(saved_mazes))==-1){
    return;
  }
  maze_map = saved_mazes[name];
  if (sizeof(maze_map)<1){
    return;
  }
  roomnames = keys(maze_map);
  for (i=0;i<sizeof(maze_map);i++){
    room = find_object_or_load(roomnames[i]);
    exits = maze_map[roomnames[i]];
    if (sizeof(exits)<1){continue;}
    exitnames = keys(exits);
    destinations = values(exits);
    for (j=0;j<sizeof(exits);j++){
       room->add_exit(destinations[j], exitnames[j]);
    }
  }
}

int set_main_path(object ob){
  int result, t;
  for (sections_added = 0;sections_added < (gridsize/5); 
                                        sections_added++){
    switch(random(17)){
    case 0..2:
      t = STRAIGHT;
      break;
    case 3..4:
      t = BEND_RIGHT;
      break;
    case 5..6:
      t = RIGHT;
      break;
    case 7:
      t =SHARP_RIGHT;
      break;
    case 8:
      t =  FULL_TURN;
      break;
    case 9..10:
      t = BEND_LEFT;
      break;
    case 11..12:
      t= LEFT;
      break;
    case 13:
      t = SHARP_LEFT;
      break;
    case 14:
      t = DOGLEG_LEFT;
      break;
    case 15:
      t = DOGLEG_RIGHT;
      break;
    case 16:
      t = DEAD_END;
      break;
    }
//    tell_object (ob,"Adding a type " + t+" section\n");
    result = add_section(t, ob);
    if (result<0){
      x = prev_x;
      y = prev_y;
    }
  }
}

string query_room_name(int location){
  return room_map[location];
}


int set_side_path(object ob){
  int start_point, t, i, length;
//  if (objectp(ob)) tell_object(ob, "Setting side path");
  locations = keys(room_map);
  if (sizeof(locations)<1){
//    tell_object(ob, "No locations stored. Starting from location 0");
    start_point = 0;
  }  else {
    start_point = locations[(random(sizeof(locations)))];
//    tell_object(ob, "Starting from location " + start_point);
  }
//  tell_object(ob, "Start point is " + start_point);
//  tell_object(ob, "The room at location " + start_point + " is " 
//                 + room_map[start_point]);
  x = start_point % gridsize;
  y = start_point / gridsize;
  direction = random(8);
  room_number = convert_to_int(room_map[start_point]);
  if (objectp(ob)){
//    tell_object(ob, "starting side path from room " 
//                    + room_map[start_point] + ". The room number is: " 
//                    + room_number);
  }
  length = random(gridsize/5);
  for (i=0;i<length;i++){
    switch(random(21)){
    case 0..4:
      t = STRAIGHT;
      break;
    case 5..6:
      t = BEND_RIGHT;
      break;
    case 7..8:
      t = RIGHT;
      break;
    case 9:
      t =SHARP_RIGHT;
      break;
    case 10:
      t =  FULL_TURN;
      break;
    case 11..12:
      t = BEND_LEFT;
      break;
    case 13..14:
      t= LEFT;
      break;
    case 15:
      t = SHARP_LEFT;
      break;
    case 16:
      t = DOGLEG_LEFT;
      break;
    case 17:
      t = DOGLEG_RIGHT;
      break;
    case 18:
      t = DEAD_END;
      break;
    case 19:
      t = IN_SPIRAL_LEFT;
      break;
    case 20:
      t= IN_SPIRAL_RIGHT;
      break;
    }  
   add_section (t, ob);
  }
  return 1;
}

void set_special_rooms(string * rooms){
  special_rooms = rooms;
}
void add_special_room(object ob, string room){
     special_rooms = special_rooms + ({room});
}

int place(string str){
  if (objectp(TP)){
  place_special_rooms(TP);
  }
  
}

int place_east_exit(){
  object orig_room, new_room;
  if (stringp(eastexit)&&file_exists(eastexit+".c")){
    orig_room = find_object_or_load(eastexit+".c");
  }
  new_room = find_object_or_load(eastroom);
  if (!objectp(orig_room)||!objectp(new_room)){
//    tell_object(ETO, "East exit not set!");
    return -1;
  }
  replace_room (new_room, eastexit+ ".c");
//  tell_object(ETO, "East exit set!");
}
int place_north_exit(){
  object orig_room, new_room;
  if (stringp(northexit)&&file_exists(northexit+ ".c")){
    orig_room = find_object_or_load(northexit+ ".c");
  }
  new_room = find_object_or_load(northroom);
  if (!objectp(orig_room)||!objectp(new_room)){
//    tell_object(ETO, "NORTH exit not set!");
    return -1;
  }
  replace_room (new_room, northexit+ ".c");
//  tell_object(ETO, "NORTH exit set!");
}

int place_south_exit(){
  object orig_room, new_room;
  if (stringp(southexit)&&file_exists(southexit+ ".c")){
    orig_room = find_object_or_load(southexit+ ".c");
  }
  if (stringp(southroom)&&file_exists(southroom)){
    new_room = find_object_or_load(southroom);
  }
  if (!objectp(orig_room)||!objectp(new_room)){
//    tell_object(ETO, "SOUTH exit not set!");
    return -1;
  }
  replace_room (new_room, southexit+ ".c");
//  tell_object(ETO, "SOUTH exit set!");
}
int place_west_exit(){
  object orig_room, new_room;
  if (stringp(westexit)&&file_exists(westexit+".c")){
    orig_room = find_object_or_load(westexit+ ".c");
  }
  new_room = find_object_or_load(westroom);
  if (!objectp(orig_room)||!objectp(new_room)){
//    tell_object(ETO, "West exit not set!");
    return -1;
  }
  replace_room (new_room, westexit+ ".c");
//  tell_object(ETO, "West exit set!");
}

int place_special_rooms(object ob){
  int i;
  object room;
  if (sizeof(special_rooms)<1){ 
    return -1;
  }
  for (i =0;i<sizeof(special_rooms);i++){
    room = 0;
    if (stringp(special_rooms[i]) && file_exists(special_rooms[i])){
      room = find_object_or_load(special_rooms[i]);
    }
    if (!objectp(room)){
    } else {
      place_special_room(ob, room, special_rooms[i]);
    }    
  }
}

int replace_room (object spec_room, string this_roomname){
  object orig_room, dest_room;
  string * exits, destination,ret_dest, dest_roomname;
  int num_exits, i;
  orig_room = find_object_or_load(this_roomname);
  if (!objectp(orig_room)){
    return -1;
  }
  exits = orig_room->query_exits();
  num_exits = sizeof(exits);
  if (num_exits<1){
    return 0;
  }
  for (i=0;i<num_exits;i++){
    destination = orig_room->query_exit(exits[i]);  
    add_exit(spec_room, destination, exits[i]);
//    spec_room->add_exit(destination,exits[i]);

    // check if the exit has a door - and then add the door to the 
    // special room if necessary.
    if (orig_room->query_door(exits[i])!=0){
      spec_room->set_door(orig_room->query_door(exits[i]),destination,
                                                             exits[i],0);
    }
    // set the exit in the destination room to point to the special room.
    dest_room = find_object_or_load(destination);
    if (objectp(dest_room)){
      switch(exits[i]){
      case "north":
        ret_dest = "south";
        break;
      case "northeast":
        ret_dest = "southwest";
        break;
      case "east":
        ret_dest = "west";
        break;
      case "southeast":
        ret_dest = "northwest";
        break;
      case "south":
        ret_dest = "north";
        break;
      case "southwest":
        ret_dest = "northeast";
        break;
      case "west":
        ret_dest = "east";
        break;
      case "northwest":
        ret_dest = "southeast";
        break;
      };
      dest_room->remove_exit(ret_dest);
      dest_roomname = file_name(spec_room); 
      add_exit(dest_room, dest_roomname, ret_dest);
//      dest_room->add_exit(dest_roomname,ret_dest);
      orig_room->remove_exit(exits[i]);
    }else{
      return -1;
    }
  }
}

int place_special_room(object ob, object spec_room, string spec_roomname){
  int room_place, num_exits, i,*locations, len;
  string * exits, destination, ret_dest, this_roomname;
  object std_room, dest_room;
  locations = keys(room_map);
  room_place = locations[random(sizeof(locations))];
  // check whether the room found is a standard one -
  // if not, try up to 10 times more.
  len = strlen(mazename);
  this_roomname = query_room_name(room_place);
  if (!member_array(mazename, ({this_roomname[strlen(this_roomname)-strlen(mazename)..strlen(this_roomname)]}),0)){
    if (spec_room_counter<10){
      spec_room_counter++;
      return place_special_rooms(ob);
    }
    else{
      spec_room_counter = 0;
      return -1;
    }
  }
  // if the room chosen is a standard on, replace it with a special one.

  return replace_room (spec_room, this_roomname);
}

void remove_special_room(string room){
  if (member_array(room,special_rooms) != -1)
     special_rooms = special_rooms - ({room});
}
string * query_special_rooms(){
  return special_rooms;
}
void set_gridsize(int size){
  gridsize = size;
}
int query_gridsize(){
  return gridsize;
}
void set_start_x(int i){
  start_x = i;
}
void set_start_y(int i){
  start_y = i;
}
int query_start_x(){
  return start_x;
}
int query_start_y(){
  return start_y;
}
void set_direction(int dir){
  direction = dir;
}
int query_direction(){
  return direction;
}

int calculate_x(int start_point, int direction){
  int result;
  switch(direction){
  case NORTH:
    result = start_point;
    break;
  case NORTHEAST:
    result =  start_point + 1;
    if (result>=gridsize){result = -1;}
    break;
  case NORTHWEST:
    result = start_point - 1;
    if (result<0){result = -1;}
    break;
  case EAST:
    result = start_point + 1;
    if (result>=gridsize){ result = -1; }
    break;
  case WEST:
    result = start_point -1;
    if (result<0){ result = -1; }
    break;
  case SOUTH:
    result = start_point;
    break;
  case SOUTHEAST:
    result = start_point + 1;
    if (result>=gridsize){ result = -1; }
    break;
  case SOUTHWEST:
    result = start_point -1;
    if (result<0){ result = -1; }
    break;
  default:
    result = -1;
    break;
  }
  return result;     
}

int clear_maze(){
  int i,j;
  object room;
  string * exits;
  for (i=0;i<gridsize*gridsize;i++){
    if (!file_exists(roompath+mazename+i+".c")){
      break;
    }
    room = find_object_or_load(roompath+mazename+i);
    if (objectp(room)){
      exits = room->query_exits();
      if (sizeof(exits)<1){return 1;}
      for (j=0;j<sizeof(doornames);j++){
        room->remove_door(doornames[j]);
      }
      for (j=0;j<sizeof(exits);j++){
        room->remove_exit(exits[j]);
      }
    }
  }
  room_number =0;
  x = 0;
  y=0;
  room_map = ([]);
  if (objectp(ETO)&&interactive(ETO)){
//    tell_object(ETO, "Maze cleared!");
  }
  return 1;
}

int calculate_y(int start_point, int direction){
  int result;
  switch(direction){
  case NORTH:
    result = start_point + 1;
    if (result>=gridsize){result = -1;}
    break;
  case NORTHEAST:
    result =  start_point+1;
    if (result>=gridsize){result = -1;}
    break;
  case NORTHWEST:
    result = start_point + 1;
    if (result>=gridsize){result = -1;}
    break;
  case EAST:
    result = start_point;
    break;
  case WEST:
    result = start_point;
    break;
  case SOUTH:
    result = start_point -1;
    if (result<0){ result = -1; }
    break;
  case SOUTHEAST:
    result = start_point -1;
    if (result<0){ result = -1; }
    break;
  case SOUTHWEST:
    result = start_point -1;
    if (result<0){ result = -1; }
    break;
  default:
    result = -1;
    break;
  }
  return result;     
}

int calculate_location(int start, int direction){
  int i,j;
  i = calculate_x(start%(gridsize),direction);
  j = calculate_y(start/(gridsize), direction);
  if (i<0||j<0){return -1;}
  return i + (j*gridsize);
}

int find_location(int start, int direction, int turn){
  direction = (direction + turn)%8;
  return calculate_location(start, direction);
}

string query_door_descrip(){
  return "A standard wooden door";
}

int query_lock_difficulty(){
  return 10;
}

string query_direction_name(int direction){
  switch(direction){
  case NORTH:
    return "north";
    break;
  case NORTHEAST:
    return "northeast";
    break;
  case EAST:
    return "east";
    break;
  case SOUTHEAST:
    return "southeast";
    break;
  case SOUTH:
    return "south";
    break;
  case SOUTHWEST:
    return "southwest";
    break;
  case WEST:
    return "west";
    break;
  case NORTHWEST:
    return "northwest";
    break;
  }
}

int convert_to_int (string str){
  int i,j,digit, result;
  string numstring = "";
  if (!str){return -1;}
  for (i=0;i<strlen(str);i++){
    if (str[i]== '0'||str[i]== '1'||str[i]== '2'||str[i]== '3'
        ||str[i]== '4'||str[i]== '5'||str[i]== '6'||str[i]== '7'
         ||str[i]== '8'||str[i]== '9'){
      numstring+=(str[i..i]);  // not just str[i] - as that returns a char
                               // value rather than a string
    }
  }
  if (numstring ==""){return 0;}
  result = atoi(numstring);
  return result;
}



int add_room(int turn, object ob){
  int loc,i,j,k, prev_door;
  string startname, endname, *start_exits, *end_exits;
  object startroom, endroom, sign;
  startname = roompath+mazename+room_number;
  prev_room_number = room_number;
  tell_object (ob, "Start room is: "+ startname);
  startroom = find_object_or_load(startname);
  if (!objectp(startroom)){
    if (objectp(ob)) tell_object(ob,"Start Room not valid. Nothing"
                                   +" added");
    room_number = prev_room_number;
    return -1;
  }

  loc = find_location(x+(y*gridsize),direction,turn);
  if (loc<0){
//    tell_object(ob,"The room to the " 
//                + query_direction_name((direction+turn)%8)
//                + " of room " + startname  
//                + " would be off the map. Not adding anything");
     room_number = prev_room_number;
     return -1;
  }
  if (room_map[x+(y*gridsize)]==0){  
    room_map += ([(x+(y*gridsize)):startname ]);
  }
  direction = (direction+turn)%8;
  if (room_map[loc]!=0){

    endname = room_map[loc];
    if (!stringp(endname) || !file_exists(endname)){
      room_number = prev_room_number;
      return -1;
    }
    endroom = find_object_or_load(endname);
    if (!objectp(endroom)){
      room_number = prev_room_number;
      return -1;
    }
    room_number = convert_to_int(room_map[loc]);
  } else {
    endname = roompath+mazename+(count+1);
    if (!file_exists(endname + ".c")){
//      tell_object(ob, "That filename doesn't exist (" + endname + ".c)");
      room_number - prev_room_number;
      return -1;
    }
    endroom = find_object_or_load(endname);
    if (!objectp(endroom)){
      room_number = prev_room_number;
      return -1;
    }
    count++;
    room_number = count;
  }
  if (room_map[loc]==0){
    room_map += ([ loc : endname]);
  }
  add_exit(startroom, query_direction_name(direction), endname);
  add_exit(endroom, query_direction_name((direction+4)%8), startname);

//  startroom->add_exit(endname, query_direction_name(direction));
//  endroom->add_exit(startname, query_direction_name((direction+4)%8));

// Test for adding a door to any of the room's exits
  start_exits =  startroom->query_exits();
  end_exits = endroom->query_exits();
  if (random(100)<door_chance && startroom->query_door(direction)==0){
    for (i=0;i<sizeof(doornames);i++)
    {
      prev_door = 0;
      if (sizeof(start_exits)>0){
        for (j=0;j<sizeof(start_exits);j++){
          if((string)startroom->query_door(start_exits[j])==doornames[i]){
            prev_door = 1;
          }
        }
      }
      if (sizeof(end_exits)>0){
        for (j=0;j<sizeof(end_exits);j++){
          if ((string)endroom->query_door(end_exits[j])==doornames[i]){
            prev_door = 1;
          }
        }
      }
      if (prev_door == 0){
        startroom->set_door(doornames[i], endname,
                              query_direction_name(direction),0); 
        startroom->set_door_description(doornames[i], doordescs[i]);
        startroom->set_lock_difficulty(doornames[i],
                                  query_lock_difficulty (),"lock");
        endroom->set_door(doornames[i], startname,
                    query_direction_name((direction+4)%8),0); 
        endroom->set_door_description(doornames[i], doordescs[i]);
        endroom->set_lock_difficulty(doornames[i],
                                    query_lock_difficulty(),"lock");
        break;
      }
    }
  }
  
  x= loc%gridsize;
  y = loc/gridsize;
  if (x<eastx){
    eastx = x;
    eastexit = endname;
  }
  if (x>westx){
    westx = x;
    westexit = endname;
  }
  if (y>northy){
    northy = y;
    northexit = endname;
  }
  if (y<southy){
    southy = y;
    southexit = endname;
  }
  return 1;
}



int add_section(int t, object ob){
  int result;
  switch(t){
  case STRAIGHT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case LEFT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the left");
    result = add_room(LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case RIGHT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the right");
    result = add_room(RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case BEND_LEFT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case BEND_RIGHT:
 //   if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
 //   if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
 //   if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case SHARP_LEFT:
 //   if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
 //   if (objectp(ob)) tell_object(ob, "adding room to the sharp left");
    result = add_room(SHARP_LEFT, ob);
    if (result>0)
 //   if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case SHARP_RIGHT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the sharp right");
    result = add_room(SHARP_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case DOGLEG_LEFT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case DOGLEG_RIGHT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case DEAD_END:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case IN_SPIRAL_LEFT:
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the left");
    result = add_room(LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight left");
    result = add_room(BEND_LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the left");
    result = add_room(LEFT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the left");
    result = add_room(LEFT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
  case IN_SPIRAL_RIGHT:
//    if (objectp(ob)) tell_object(ob, "adding room straight ahead");
    result = add_room(STRAIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the right");
    result = add_room(RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(BEND_RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the right");
    result = add_room(RIGHT, ob);
    if (result>0)
//    if (objectp(ob)) tell_object(ob, "adding room to the slight right");
    result = add_room(RIGHT, ob);
    if (result>0)
    return 1;
    else return -1;
    break;
   };
}
