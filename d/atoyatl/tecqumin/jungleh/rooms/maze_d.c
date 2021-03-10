
// Lujke's new maze daemon.
//
//Variables:
//
//saved_mazes - a mapping of r+paths : maze_rooms
//maze_rooms - a mapping of rooms : exits
//exits - a mapping of exit directions: room names (base_name(room))
//
//saved_locations - a mapping or r_paths : locations
//locations - a mapping of location numbers : room names (location number = y * 1000 + x  bottom left: southwest   top right: northeast
//
//rpath - the string of the path for the current maze being worked on
//
//Functions:
//
//add_room(int location_number, mapping exits) - adds the room to the locations mapping, and adds the exit mapping to the maze_rooms for the next room name
//add_section() - add a new section to the current maze
//
//build_main_section - builds the main route through the maze, adding sections as appropriate
//add_side+path  - adds a side path, starting from a random existing room in the maze


#include <std.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
inherit DAEMON;

mapping saved_mazes, saved_locations, maze_rooms, exits, locations,
timings, maze_names,
north_locations, east_locations, south_locations, west_locations,
special_rooms, saved_rivers;
string r_path, r_name;
int maze_size, max_room_number, current_room, next_room;

void create(){
  ::create();
  saved_rivers = ([]);
  saved_mazes = ([]);
  saved_locations = ([]);
  maze_rooms = ([]);
  exits = ([]);
  maze_names = ([]);
  locations = ([]);
  timings = ([]);
  r_path = "blank";
  r_name = "blank";
  maze_size = 0;
  max_room_number = 0;
  current_room = 0;
  north_locations = ([]);
  east_locations = ([]);
  south_locations = ([]);
  west_locations = ([]);
  special_rooms = ([]);
}

mapping query_rivers(){
  return saved_rivers;
}

string * query_river(string path){
  string * ks;
  ks = keys(saved_rivers);
  if (member_array(path, ks)==-1){
    return ([]);
  }
  return saved_rivers[path];
}

string * right_locations(string path){
  string * ks;
  int * result, *locs_at_y, *all_locs, i, count, j, right_loc_at_y, max_y, x, y, right_x, all_ys;
  mapping locations;
  ks = keys(saved_locations);
  count = sizeof(ks);
  if (count <1 || member_array(path, ks)==-1){
    return ({});
  }
  locations = saved_locations[path];
  all_locs = keys(locations);
  locations = ([]);
  count = sizeof(all_locs);
  for (i=0;i<count;i++){
    x = all_locs[i]%1000;
    y = all_locs[i]/1000;
    all_ys = keys(locations);
    if (sizeof(locations)<1 || member_array(y, all_ys)==-1){
      locations[y] = all_locs[i];
      continue;
    }
    right_x =locations[y]%1000;
    if (x>right_x){
      locations[y] = all_locs[i];
    }
  }
  result = values(locations);
  return result;
}


string * left_locations(string path){
  string * ks;
  int * result, *locs_at_y, *all_locs, i, count, j, left_loc_at_y, max_y, x, y, left_x, all_ys;
  mapping locations;
  ks = keys(saved_locations);
  count = sizeof(ks);
  if (count <1 || member_array(path, ks)==-1){
    return ({});
  }
  locations = saved_locations[path];
  all_locs = keys(locations);
  locations = ([]);
  count = sizeof(all_locs);
  for (i=0;i<count;i++){
    x = all_locs[i]%1000;
    y = all_locs[i]/1000;
    all_ys = keys(locations);
    if (sizeof(locations)<1 || member_array(y, all_ys)==-1){
      locations[y] = all_locs[i];
      continue;
    }
    left_x =locations[y]%1000;
    if (x<left_x){
      locations[y] = all_locs[i];
    }
  }
  result = values(locations);
  return result;
}

mapping generate_waystations(string path, string name, int stages, int
spacing){
  string * this_stage_rooms, destinations, next_stage_rooms, rooms_checked;

  mapping exits, waystations;
  int i, j,k,l,m, count, count2, count3;
  
  //Set up first stage with starting name as only one in this_stage_rooms
  next_stage_rooms = ({name});

  //loop through number of stages.
  rooms_checked = ({});
  for(i=0;i<stages;i++){
    report ("Stage: " + i);
    //At each stage: loop through rooms a number of times equal to spacing. Get exits, and destinations of exits
      //loop through destinations. If not already in list of next stage rooms, add it to list
    for (l=0;l<spacing;l++){
      this_stage_rooms = next_stage_rooms;
      next_stage_rooms = ({});
      count = sizeof(this_stage_rooms);
      if (count<1){
        break;
      }
      report ("Space: " + l);
      for (j = 0; j<count;j++){
        report("Checking room: " + this_stage_rooms[j]);
        exits = query_room_exits(path, this_stage_rooms[j]);
        count2 = sizeof(exits);
        if (count2<1){
          report("Room has no exits");
          continue;
        }
        destinations = values(exits);
        for (k=0;k<count2;k++){
          if (member_array(destinations[k], rooms_checked)!=-1){
            continue;
          }
          next_stage_rooms += ({destinations[k]});
          rooms_checked += ({destinations[k]});
        }
      }      
    }
    //Once list of next stage rooms is complete, 
    //loop through next stage rooms. Check for each one whether there is a waystation already in place within spacing stages
    //If not, add waystation to that room
    waystations = ([]);
    count3 = sizeof(next_stage_rooms);
    if (count3<1){
      report ("No rooms found at this stage. Returning");
      return waystations;
    }
    "/daemon/destinations_d"->add_waystation(path+name, path+name, 1);
    for (m=0;m<count3;m++){
      if(find_waystation(path, next_stage_rooms[m], path+name, spacing-1)){
        report ("Waystation found within range of " + next_stage_rooms[m] + "Not adding waystation here.");
        continue;
      } else {
        waystations[path+next_stage_rooms[m]] = i+1;
        report("Adding waystation to " + next_stage_rooms[m]);
        "/daemon/destinations_d"->add_waystation(path+name, path+next_stage_rooms[m], i+2);
      }
    }
    "/daemon/destinations_d"->add_waystation(path+name, path+name, 1);
  } 
} 

string get_middle_room(string path){
  int * locations, x, y, end_x_loc, end_y_loc, mid_x, mid_y,i, count, x_dist, y_dist, lowest_dist, combined_dist, mid_loc;
  locations = keys(saved_locations[path]);
  count = sizeof(locations);
  end_x_loc = 0;
  end_y_loc = 0;
  for(i=0;i<count;i++){
    if (locations[i]/1000 > end_y_loc / 1000){
      end_y_loc = locations[i];
    }
    if (locations[i]%1000 > end_x_loc % 1000){
      end_x_loc = locations[i];
    }
  }
  mid_x = (end_x_loc%1000)/2;
  mid_y = (end_y_loc/1000)/2;
  lowest_dist = 1000;
  for (i=0;i<count;i++){
    if (locations[i]/1000 > mid_y){
      y_dist = locations[i]/1000 - mid_y;
    } else {
      y_dist =  mid_y - locations[i]/1000;
    }
    if (locations[i]%1000 > mid_x){
      x_dist = locations[i]%1000 - mid_x;
    } else {
      x_dist =  mid_x - locations[i]%1000;
    }
    combined_dist = x_dist + y_dist;
    if (combined_dist <lowest_dist){
      mid_loc = locations[i];
      lowest_dist = combined_dist;
    }
  }
  return query_room(path, mid_loc);
}

int find_waystation(string path, string name, string destination, int
distance){
  mapping exits;
  string * rooms_checked, * current_rooms, * next_rooms, * destinations;
  int i, j, k, count, count2;
  current_rooms = ({});
  rooms_checked = ({});
  next_rooms = ({name});
  report ("Finding waystation.");
  for (i=0;i<distance;i++){
    if (sizeof(next_rooms == 0)){
      return 0;
    }
    current_rooms = next_rooms;
    next_rooms = ({});
    count = sizeof(current_rooms);
    for(j=0;j<count;j++){
      exits = query_room_exits(path, current_rooms[j]);
      report ("checking exits for room: "+ current_rooms[j]);
      count2 = sizeof(exits);
      if (count2 < 1){
//        report ("no exits");
        continue;
      }
      destinations = values(exits);
      for (k=0;k<count2;k++){
        if (member_array(destinations[k], rooms_checked)!=-1){
//          report("Already checked " + destinations[k]);
          continue;
        }
        report ("Checking for waystation to " + destination + " in room " + path + destinations[k]); 
        if ("/daemon/destinations_d"->query_waystation(path + destination, path + destinations[k])>0){
          report ("Waystation found");
          return 1;
        }
        report ("Waystation not found");        
        rooms_checked += ({destinations[k]});
        next_rooms += ({destinations[k]});
      }
    }
  }
  return 0;
}


void set_river_entry(string path, string name, string direction){
  mapping river;
  string * ks, * directions;
  ks = keys (saved_rivers);
  if (sizeof(ks)<1 ||member_array(path, ks)==-1){
    river = ([]);
  } else {
    river = saved_rivers[path];
  }
  ks = keys(river);
  if (sizeof(ks)<1 ||member_array(name, ks)==-1){
    directions = ({"none", "none"});
  } else {
    directions = river[name];
  }
  directions = ({direction}) + ({directions[1]});
  river[name] = directions;
  saved_rivers[path] = river;
}

void set_river_exit(string path, string name, string direction){
  mapping river;
  string * ks, * directions;
  ks = keys (saved_rivers);
  if (sizeof(ks)<1||member_array(path, ks)==-1){
    river = ([]);
  } else {
    river = saved_rivers[path];
  }
  ks = keys(river);
  if (sizeof(ks)<1||member_array(name, ks)==-1){
    directions = ({"none"});
  } else {
    directions = river[name];
  }
  directions = ({directions[0]}) + ({direction});
  river[name] = directions;
  saved_rivers[path] = river;
}

string query_river_entry(string path, string name){
  mapping river;
  string * ks, * directions;
  ks = keys (saved_rivers);
  if (sizeof(ks)<1 ||member_array(path, ks)==-1){
    return "none";
  } else {
    river = saved_rivers[path];
  }
  ks = keys(river);
  if (sizeof(ks)<1 ||member_array(name, ks)==-1){
    return "none";
  } else {
    directions = river[name];
  }
  if (sizeof(directions)<1){
    return "none";
  }
  return directions[0];
}

string query_river_exit(string path, string name){
  mapping river;
  string * ks, * directions;
  ks = keys (saved_rivers);
  if (sizeof(ks)<1 ||member_array(path, ks)==-1){
    return "none";
  } else {
    river = saved_rivers[path];
  }
  ks = keys(river);
  if (sizeof(ks)<1 ||member_array(name, ks)==-1){
    return "none";
  } else {
    directions = river[name];
  }
  if (sizeof(directions)<2){
    return "none";
  }
  return directions[1];
}


void set_saved_locations(mapping locs){
  saved_locations = locs;
}

void add_saved_locations(string path, mapping locs){
  saved_locations[path] = locs;
}

void add_location(string path, int location, string room){
  string * ks;
  if (sizeof(saved_locations)<1){
    saved_locations = ([]);
    ks = ({});
  } else {
    ks = keys(saved_locations);
  }
  if (sizeof(ks)< 1 || member_array(path, ks) ==-1){
    locations = ([]);
  } else {
    locations = saved_locations[path];
  }
  locations[location] = room;
  saved_locations[path] = locations;
}

mapping query_saved_locations(string path){
  return saved_locations[path];
}

mapping query_all_locations(){
  return saved_locations;
}

int add_special_room(string path, string name){
  string * spec_rooms, ks, room_name;
  int loc, r, i;
  mapping rooms;
  ks = keys(special_rooms);
  if (sizeof(ks) > 0 && member_array(path, ks)!=-1){
    spec_rooms = special_rooms[path];
  } else {
    spec_rooms = ({});
  }  
  if (member_array(name, spec_rooms)==-1){
    spec_rooms += ({name});
    special_rooms[path] = spec_rooms;
  }
  loc = query_location(path, name);
  if (loc == -1){
    rooms = saved_locations[path];
    ks = keys(rooms);
    if (sizeof(ks)<1){ 
      return -1;
    }
    r = random(sizeof(ks));
    room_name = rooms[ks[r]];
    if(member_array(room_name, spec_rooms)!= -1 ||
       room_name == query_room(path, north_locations[path]) ||
       room_name == query_room(path, east_locations[path]) ||
       room_name == query_room(path, south_locations[path]) ||
       room_name == query_room(path, west_locations[path]) 
                                                               ){
      i=0;
      while((member_array(room_name, spec_rooms)!= -1 ||
        room_name == query_room(path, north_locations[path]) ||
        room_name == query_room(path, east_locations[path]) ||
        room_name == query_room(path, south_locations[path]) ||
        room_name == query_room(path, west_locations[path] ))
        && i<sizeof(spec_rooms)
                                                             ){
        r++;
        if (r>sizeof(spec_rooms)){
          r++;
        }
        room_name = ks[r];
      }
    }
    if(member_array(room_name, spec_rooms)!= -1 ||
       room_name == query_room(path, north_locations[path]) ||
       room_name == query_room(path, east_locations[path]) ||
       room_name == query_room(path, south_locations[path]) ||
       room_name == query_room(path, west_locations[path]) 
                                                               ){
      return -1;
    }
  }
  report ("Replacing room. Path: " + path + " room_name: " + room_name + "name: " + name);
  replace_room(path, room_name, name);
  return 1; 
}

mapping query_room_exits(string path, string room_name){
  string * ks;
  mapping maze, room;
  ks = keys (saved_mazes);
  if (sizeof(ks)<1 ){
    report ("No mazes exist");
    return ([]);
  }
  if (member_array(path, ks)==-1){
    report ("That maze (" + path + ") does not exist");
    return ([]);
  }
  maze = saved_mazes[path];
  ks = keys(maze);
  if (sizeof(ks)<1 || member_array(room_name, ks)==-1){
//    report ("No saved exits found for room " + room_name + " in the maze for " + path);
    return ([]);
  }
  room = maze[room_name];
  return room;
}

string query_exit(string path, string room_name, string direction){
  mapping exits;
  string * ks;
  exits = query_room_exits(path, room_name);
  if (sizeof(exits)<1){
    return "none";
  }
  ks = keys(exits);
  if (member_array(direction, ks)==-1){
    return "none";
  }
  return exits[direction];
}

mapping query_maze(string path){
  string * ks;
  ks = keys(saved_mazes);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    report ("No maze found for path " + path);
    return ([]);
  }
  return saved_mazes[path];
}

string query_room(string path, int location){
  string * ks;
  int * locs;
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){ return "none"; }
  locations = saved_locations[path];
  locs = keys(locations);
  if (member_array(location, locs)==-1){ return "none"; }
  return locations[location];
}

int query_location(string path, string room_name){
  string * ks;
  int * locs, i, count;
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){ return -1; }
  locations = saved_locations[path];
  locs = keys(locations);
  count = sizeof(locs);
  if (count<1){ return -1; }
  for (i=0;i<count;i++){
    if (locations[locs[i]] == room_name){
      return locs[i];
    }
  }
  return -1;
}

int find_location(int start_loc, string direction){
  switch(direction){
  case "north":
    return start_loc + 1000;
    break;
  case "northeast":
    return start_loc + 1001;
    break;
  case "east":
    return start_loc + 1;
    break;
  case "southeast":
    return start_loc -999;
    break;
  case "south":
    return start_loc - 1000;
    break;
  case "southwest":
    return start_loc - 1001;
    break;
  case "west":
    return start_loc - 1;
    break;
  case "northwest":
    return start_loc + 999;
    break;
  }
}

string ninety_degrees(string direction){
  switch(direction){
  case "north":
    return "east";
    break;
  case "northeast":
    return "southeast";
    break;
  case "east":
    return "south";
    break;
  case "southeast":
    return "southwest";
    break;
  case "south":
    return "west";
    break;
  case "southwest":
    return "northwest";
    break;
  case "west":
    return "north";
    break;
  case "northwest":
    return "northeast";
    break;
  }
}

string two_seventy_degrees(string direction){
  switch(direction){
  case "north":
    return "west";
    break;
  case "northeast":
    return "northwest";
    break;
  case "east":
    return "north";
    break;
  case "southeast":
    return "northeast";
    break;
  case "south":
    return "east";
    break;
  case "southwest":
    return "southeast";
    break;
  case "west":
    return "south";
    break;
  case "northwest":
    return "southwest";
    break;
  }
}

string reverse_direction(string direction){
  switch(direction){
  case "north":
    return "south";
    break;
  case "northeast":
    return "southwest";
    break;
  case "east":
    return "west";
    break;
  case "southeast":
    return "northwest";
    break;
  case "south":
    return "north";
    break;
  case "southwest":
    return "northeast";
    break;
  case "west":
    return "east";
    break;
  case "northwest":
    return "southeast";
    break;
  }
}

int replace_room(string path, string original_room, string new_room){
  int location, i, count;
  mapping exits, maze, locations;
  string * dirs, ks;
  report("Replacing room: " + original_room + " with room: " + new_room +  "  PATH: " + path); 
  location = query_location(path, original_room);
  if (location == -1){ 
    report("No location found for: " + path + original_room);
    return -1; 
  } else 
  {
    report("%^MAGENTA%^Location found for: " + path + original_room + ": " + location);
  }
  exits = query_room_exits(path, original_room);
  dirs = keys(exits);
  count = sizeof(dirs);
  if (count<1){
    report ("Room " + path + original_room+ " has no exits to replace"); 
    return -1; //No exits to replace
  } else 
  {
    report ("Room " + path + original_room+ " has %^BOLD%^%^RED%^" + count + "%^RESET%^ exits to replace"); 
  }
  saved_locations[path][location] = new_room;
  for (i=0;i<count;i++){
    report("Adding exit " + i);
    add_exit(path, new_room, dirs[i], 1);
    report("Exit added");
  }
  maze = saved_mazes[path];
  ks = keys(maze);
  if (member_array(original_room, ks)!=-1){
    report (original_room + " removed from saved maze: " + path);
    map_delete(maze, original_room);
    saved_mazes[path] = maze;
  } else 
  {
    report("Original room was not part of the maze. Bah!");
  }
  locations = saved_locations[path];
  ks = keys(locations);
  if (member_array(original_room, ks)!=-1){
    report (original_room + " removed from saved locations for " + path);
    map_delete(locations, original_room);
    saved_locations[path] = locations;
  } else 
  {
    report ("Original room seems not to have had a location");
  }
  report("%^GREEN%^Finished replacing room");
}

varargs int add_exit(string path, string room_name, string direction, int
overwrite){
  string end_room, *ks, destination_room;
  int start_location, end_location;
//Add the location recording
  report ("Adding exit. Path: " + path + " Room name: " + room_name + "Direction: " + direction);
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){
    report ("No current locations for path " + path);
    locations = ([]);
    saved_locations[path] = locations;
  }
  if (!intp(overwrite)){
    report ("NOT Overwriting " + direction + " for room " + room_name);
    overwrite = 0;
  }
  locations = saved_locations[path];
  start_location = query_location(path, room_name);
  if (start_location<0){
    report ("No location recorded for path " + path + " and name " + room_name);
    report ("Aborting");
    return -1;
  }
  end_location = find_location(start_location, direction);
  if (end_location < 0){
    report ("No end location found");
    report ("Aborting");
    return -1;
  } 
  if (end_location/1000 >maze_size || end_location % 1000 > maze_size){
    report ("Location is off the map. Aborting");
    return -1;
  }
  destination_room = query_room(path, end_location);
  if (destination_room == "none"){
    if (current_room > max_room_number) {
      report ("No more rooms remaining. Aborting");
      return -1;
    }
    current_room ++;
    destination_room = r_name + current_room;
    next_room = current_room;
  } else {
    next_room = atoi(query_room(path, end_location)[strlen(r_name)..strlen(query_room(path, end_location))-1]);
    report ("Calculated next room: " + next_room);
  }
  saved_locations[path][end_location] = destination_room;
//Add the exit to the start room
  ks = keys(saved_mazes);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    saved_mazes[path] = ([]);
  }
  maze_rooms = saved_mazes[path];
  ks  = keys (maze_rooms);
  if (sizeof(ks)<1 || member_array(room_name, ks ) == -1){
    maze_rooms[room_name] = ([]);
  }  
  exits = maze_rooms[room_name];
  ks = keys(exits);
  if (sizeof(ks)>0 && member_array(direction, ks)!= -1){
    // This would mean the exit already leads somewhere
    report ("Existing exit found");
    if (overwrite !=1){
      report("NOT OVERWRITING");
      return -1; 
    }
    report ("OVERWRITING EXIT - " + direction + " For room " + room_name);
  }
  exits[direction] = destination_room;
  maze_rooms[room_name] = exits;
  saved_mazes[path] = maze_rooms;
//Add return exit to the destination room
  direction = reverse_direction(direction);
  ks = keys(saved_mazes);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    saved_mazes[path] = ([]);
  }
  maze_rooms = saved_mazes[path];
  ks  = keys (maze_rooms);
  if (sizeof(ks)<1 || member_array(destination_room, ks ) == -1){
    maze_rooms[destination_room] = ([]);
  }  
  exits = maze_rooms[destination_room];
  ks = keys(exits);
  if (sizeof(ks)>0 && member_array(direction, ks)!= -1){
    report ("Return exit already exists");
    report ("Existing exit found");
    if (overwrite !=1){
      report("NOT OVERWRITING");
      return -1; 
    }
    report ("OVERWRITING EXIT - " + direction + " For room " + room_name);
  }
  exits[direction] = room_name;
  maze_rooms[destination_room] = exits;
  saved_mazes[path] = maze_rooms;
}


void clear_maze(string path){
  saved_mazes[path] = ([]);
  saved_locations[path] = ([]);
  timings[path] =0;
  north_locations[path] = -1;
  east_locations[path] = -1;
  south_locations[path] = -1;
  west_locations[path] = -1;
  maze_names[path] = "none";
}

int build_maze(string path, string name, int size, int max_rooms){
  int i, j, k, start_location, reverse_path_start;
  string * ks, section, direction, first_direction, directions;
  ks = keys(saved_mazes);
  timings[path] = time();
  if (member_array(path, ks) != -1){
    clear_maze(path);
  }
  maze_names[path] = name;
  current_room = 0;
  r_path = path;
  r_name = name;
  maze_size = size;
  max_room_number = max_rooms;
  start_location = (size/2*1000) + (size/2);
  report ("Building maze. Start location: " + start_location + "\n"
         +"r_path: " + r_path + "   r_name: " + r_name + "\n"
         +"maze size: " + maze_size + "   max room numbers: " + max_room_number); 
  add_location(r_path, start_location, r_name+current_room);
  //make one main path
  if (sizeof(section)>0){
    direction = section[sizeof(section)-1];
  } else {
    directions = ({"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest"});
    direction = directions[random(sizeof(directions))];
    first_direction = direction;
  }
  //Add a few sections in the first direction
  for (i=0;i<maze_size/4;i++){
    if (current_room > max_room_number){
      break;
    }
    section = get_section(direction);
    for(j=0;j<sizeof(section);j++){
      add_exit(r_path, r_name + current_room, section[j]);
    } 
    direction = section[sizeof(section)-1];
  }
  //Add a few sections in the opposite direction
  report ("Setting reverse section from room " + current_room);
  direction = reverse_direction(first_direction);
  for (i=0;i<maze_size/4;i++){
    if (current_room > max_room_number){
      break;
    }
    section = get_section(direction);
    next_room = 0;
    reverse_path_start = current_room;
    for(j=0;j<sizeof(section);j++){
      add_exit(r_path, r_name + next_room, section[j]);
    } 
    direction = section[sizeof(section)-1];
  }
  //add some sections at ninety degrees
  direction = ninety_degrees(first_direction);
  for (i=0;i<maze_size/4;i++){
    if (current_room > max_room_number){
      break;
    }
    section = get_section(direction);
    next_room = reverse_path_start / 2;
    for(j=0;j<sizeof(section);j++){
      add_exit(r_path, r_name + next_room, section[j]);
    } 
    direction = section[sizeof(section)-1];
  } 
  //add some sections at two seventy degrees
  direction = two_seventy_degrees(first_direction);
  for (i=0;i<maze_size/4;i++){
    if (current_room > max_room_number){
      break;
    }
    section = get_section(direction);
    next_room =  reverse_path_start + (current_room-reverse_path_start)/2;
    for(j=0;j<sizeof(section);j++){
      add_exit(r_path, r_name + next_room, section[j]);
    } 
    direction = section[sizeof(section)-1];
  } 
  align_map(path);
  setup_exit_locations(path);
  timings[path] = time();
  report ("about to setup special rooms");
  setup_special_rooms(path, name);
}

void setup_special_rooms(string path, string name){
  string * rooms;
  object room;
  int i, count;
  report("Setting up special rooms");
  room = find_object_or_load(path + name + "0");
  if (!objectp(room)){
    report ("Unable to load base room to find special rooms. Path: " + path + "  Name : " + name);
    return;
  }
  rooms = room->query_spec_rooms();
  count = sizeof(rooms);
  if (count<1){
    report("No special rooms found");
    return;
  }
  for (i=0;i<count;i++){
    report("Adding special room: " + path + rooms[i]);
    add_special_room(path, rooms[i]);
  }
}

mapping get_rooms_at_y(string path, string name, int y){
  mapping maze, result, locations;
  string * ks, room_name;
  int i, count, x, * location_nos, room_no, location_no;
  result  = ([]);
  ks = keys(saved_mazes);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    return ([]);
  }
  ks = keys(saved_locations);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    return ([]);
  }
  maze = saved_mazes[path];
  locations = saved_locations[path];
  if (sizeof(maze)< 1){
    return ([]);
  }
  locations = saved_locations[path];
  if (sizeof(locations)< 1){
    return ([]);
  }
  location_nos = keys(locations);
  count = sizeof(location_nos);
  for (i=0;i<count;i++){
    location_no = location_nos[i];
    if (location_no/1000 == y){
      x = location_no%1000;
      room_name = locations[location_no];
      if (interact(name, room_name)){
        room_name = room_name[strlen(name)..strlen(room_name)-1];
        if (strlen(room_name)<2){
          room_name = "0" + room_name;
        }
      } else {
        room_name = room_name[strlen(room_name)-2..strlen(room_name)-1];
      } 
      result[x] = room_name;
    }
  }
  return result;
}

void show_map(object ob, string path){
  mapping maze, rooms_at_y;
  string * ks, name, line;
  int i, j, * xs, low_x, high_x, low_y, high_y, k;
  if (!objectp(ob)){return;}
  if (sizeof(saved_mazes)<1){
    tell_object(ob, "There are no saved mazes" );
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    tell_object(ob, "There is no saved maze with the path " + path);
  }
  maze = saved_mazes[path];
  name = maze_names[path];
  low_x = west_limit(path);
  high_x = east_limit(path);
  low_y = south_limit(path);
  high_y = north_limit(path);
  for (i=high_y+1;i>=low_y-1;i--){
    rooms_at_y = get_rooms_at_y(path, name, i);
    if (sizeof(rooms_at_y)<1){
      continue;
    }
    for (k=0;k<sizeof(rooms_at_y);k++){
      report("rooms_at_y[" + k + "] = " + rooms_at_y[k]); 
    }
    line = "";
    for (j=low_x-1;j<high_x+1;j++){
      if (sizeof(rooms_at_y)<1){
        line += "  ";
        continue;
      }
      xs = keys(rooms_at_y);
      if(i*1000+j == north_locations[path] ||
         i*1000+j == east_locations[path]  ||
         i*1000+j == south_locations[path] ||
         i*1000+j == west_locations[path]  ){
        line += "";
      }
      if (member_array(j, xs)==-1){
        line += "  "; 
        continue;
      } else {
        line += rooms_at_y[j];
      }
      if(i*1000+j == north_locations[path] ||
         i*1000+j == east_locations[path]  ||
         i*1000+j == south_locations[path] ||
         i*1000+j == west_locations[path]  ){
        line += "";
      }
    }
    line +=i;
    tell_object(ob, line);
  }
}

int query_timing(string path){
  return timings[path];
}

void show_waystations_map(object ob, string path, string destination){
  mapping maze, rooms_at_y;
  string * ks, name, line, top_line, room_name, full_name;
  int i, j, * xs, low_x, high_x, low_y, high_y, loc, k;
  if (!objectp(ob)){return;}
  if (sizeof(saved_mazes)<1){
    tell_object(ob, "There are no saved mazes" );
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    tell_object(ob, "There is no saved maze with the path " + path);
  }
  maze = saved_mazes[path];
  name = maze_names[path];
  low_x = west_limit(path);
  high_x = east_limit(path);
  low_y = south_limit(path);
  high_y = north_limit(path);
  for (i=high_y+1;i>=low_y-1;i--){
    rooms_at_y = get_rooms_at_y(path, name, i);
    if (sizeof(rooms_at_y)<1){
      continue;
    }
    top_line = "";
    line = "";
    for (j=low_x-1;j<high_x+1;j++){
      if (sizeof(rooms_at_y)<1){
        line += "  ";
        continue;
      }
//      for (k=0;k<sizeof(rooms_at_y);k++){
//        report("rooms_at_y[" + k + "] = " + rooms_at_y[k]);
//      }
      xs = keys(rooms_at_y);
      if(i*1000+j == north_locations[path] ||
         i*1000+j == east_locations[path]  ||
         i*1000+j == south_locations[path] ||
         i*1000+j == west_locations[path]  ){
        line += "";
      }
      if (member_array(j, xs)==-1){
        line += "   ";
        top_line += "   ";
        continue;
      } else {
        room_name = query_room(path, (i*1000) + j);
        if (interact(name, room_name)){
          room_name = name + atoi(rooms_at_y[j]);
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path +room_name)==1){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path +room_name)==2){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path +room_name)==3){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path +room_name)==4){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path +room_name)==5){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path +room_name)==6){
          line += "";
        }
//        if (query_exit(path, name + rooms_at_y[j], "northwest")!="none"){
        if (query_exit(path, room_name, "northwest")!="none"){
          top_line += "\\";
        } else {
          top_line += " ";
        }
//        if (query_exit(path, name + rooms_at_y[j], "north")!="none"){
        if (query_exit(path, room_name, "north")!="none"){
          top_line += "|";
        } else {
          top_line += " ";
        }
//        if (query_exit(path, name + rooms_at_y[j], "northeast")!="none"){
        if (query_exit(path, room_name, "northeast")!="none"){
          top_line += "/";
        } else {
          top_line += " ";
        }
//        if (query_exit(path, name + rooms_at_y[j], "west")!="none"){
        if (query_exit(path, room_name, "west")!="none"){
          line += "-";
        } else {
          line += " ";
        }
        if (atoi(rooms_at_y[j])>99){
          line += "";
        }
        loc = (i*1000) + j;
        full_name = query_room(path, loc);
//        report ("Location: " + loc + "  Fullname: " + full_name);
        if (interact("leftbank", full_name)){
          line += "";
        }
        if (interact("rightbank", full_name)){
          line += "";
        }
        if (atoi(rooms_at_y[j])>99){
          line += ""+rooms_at_y[j][1..2]+"";
        } else {
          line += rooms_at_y[j][0..1];
        }
        if (interact("leftbank", full_name) || interact("rightbank", full_name) ){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(destination, path + room_name)>0){
          line += "";
        }
      }
      if(i*1000+j == north_locations[path] ||
         i*1000+j == east_locations[path]  ||
         i*1000+j == south_locations[path] ||
         i*1000+j == west_locations[path]  ){
        line += "";
      }


    }
    line +=i;
    tell_object(ob, top_line);
    tell_object(ob, line);
  }
}


void show_extended_map(object ob, string path){
  mapping maze, rooms_at_y;
  string * ks, name, line, top_line, room_name, full_name;
  int i, j, * xs, low_x, high_x, low_y, high_y, loc, k;
  if (!objectp(ob)){return;}
  if (sizeof(saved_mazes)<1){
    tell_object(ob, "There are no saved mazes" );
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    tell_object(ob, "There is no saved maze with the path " + path);
  }
  maze = saved_mazes[path];
  name = maze_names[path];
  low_x = west_limit(path);
  high_x = east_limit(path);
  low_y = south_limit(path);
  high_y = north_limit(path);
  for (i=high_y+1;i>=low_y-1;i--){
    rooms_at_y = get_rooms_at_y(path, name, i);
    if (sizeof(rooms_at_y)<1){
      continue;
    }
    top_line = "";
    line = "";
    for (j=low_x-1;j<high_x+1;j++){
      if (sizeof(rooms_at_y)<1){
        line += "  ";
        continue;
      }
//      for (k=0;k<sizeof(rooms_at_y);k++){
//        report("rooms_at_y[" + k + "] = " + rooms_at_y[k]);
//      }
      xs = keys(rooms_at_y);
      if(i*1000+j == north_locations[path] ||
         i*1000+j == east_locations[path]  ||
         i*1000+j == south_locations[path] ||
         i*1000+j == west_locations[path]  ){
        line += "";
      }
      if (member_array(j, xs)==-1){
        line += "   ";
        top_line += "   ";
        continue;
      } else {
        room_name = query_room(path, (i*1000) + j);
        if (interact(name, room_name)){
          room_name = name + atoi(rooms_at_y[j]);
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==1){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==2){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==3){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==4){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==5){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==6){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path +room_name)==6){
          line += "";
        }
//        if (query_exit(path, name + rooms_at_y[j], "northwest")!="none"){
        if (query_exit(path, room_name, "northwest")!="none"){
          top_line += "\\";
        } else {
          top_line += " ";
        }
//        if (query_exit(path, name + rooms_at_y[j], "north")!="none"){
        if (query_exit(path, room_name, "north")!="none"){
          top_line += "|";
        } else {
          top_line += " ";
        }
//        if (query_exit(path, name + rooms_at_y[j], "northeast")!="none"){
        if (query_exit(path, room_name, "northeast")!="none"){
          top_line += "/";
        } else {
          top_line += " ";
        }
//        if (query_exit(path, name + rooms_at_y[j], "west")!="none"){
        if (query_exit(path, room_name, "west")!="none"){
          line += "-";
        } else {
          line += " ";
        }
        if (atoi(rooms_at_y[j])>99){
          line += "";
        }
        loc = (i*1000) + j;
        full_name = query_room(path, loc);
//        report ("Location: " + loc + "  Fullname: " + full_name);
        if (interact("leftbank", full_name)){
          line += "";
        }
        if (interact("rightbank", full_name)){
          line += "";
        }
        if (atoi(rooms_at_y[j])>99){
          line += ""+rooms_at_y[j][1..2]+"";
        } else {
          line += rooms_at_y[j][0..1];
        }
        if (interact("leftbank", full_name) || interact("rightbank", full_name) ){
          line += "";
        }
        if ("/daemon/destinations_d"->query_waystation(JUNG_ROOM5 + "j_link4a", path + room_name)>0){
          line += "";
        }
      }
      if(i*1000+j == north_locations[path] ||
         i*1000+j == east_locations[path]  ||
         i*1000+j == south_locations[path] ||
         i*1000+j == west_locations[path]  ){
        line += "";
      }
    }
    line +=i;
    tell_object(ob, top_line);
    tell_object(ob, line);
  }
}

int query_north_location(string path){
  string * ks;
  ks = keys(north_locations);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    return -1;
  }
  return north_locations[path];
}
int query_east_location(string path){
  string * ks;
  ks = keys(east_locations);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    return -1;
  }
  return east_locations[path];
}

int query_south_location(string path){
  string * ks;
  ks = keys(south_locations);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    return -1;
  }
  return south_locations[path];
}

int query_west_location(string path){
  string * ks;
  ks = keys(west_locations);
  if (sizeof(ks)<1 || member_array(path, ks)==-1){
    return -1;
  }
  return west_locations[path];
}

mapping query_north_locations(){
  return north_locations;
}

int place_north_exit(string path, string room_name){
  string original_room;
//  report ("Placing north exit at location: " + north_locations[path]);
  original_room = query_room(path, north_locations[path]);
  replace_room(path, original_room, room_name); 
}

int place_east_exit(string path, string room_name){
  string original_room;
  original_room = query_room(path, east_locations[path]);
  replace_room(path, original_room, room_name); 
}
int place_south_exit(string path, string room_name){
  string original_room;
  original_room = query_room(path, south_locations[path]);
  replace_room(path, original_room, room_name); 
}
int place_west_exit(string path, string room_name){
  string original_room;
  original_room = query_room(path, west_locations[path]);
  replace_room(path, original_room, room_name); 
}

varargs string * get_section(string direction){
  string * sections, * section, * directions; 
  int dir_number, r;
  directions = ({"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest"});
  if (!stringp(direction)){
    direction = directions[random(sizeof(directions))];
    report ("No direction received. Direction chosen at random: " + direction);
  }
  dir_number = member_array(direction, directions);
  if ( dir_number ==-1){
    dir_number = random(sizeof(directions));
  }
  report ("Old direction: " + direction);

  //choose a new direction for the section. Further deviations from current direction are less likely.
  r = random(3) + random(3) + random(3) + random(3) -4;
  dir_number += r;
  while (dir_number>7){
    dir_number -= 8;
  }
  while (dir_number<0){
    dir_number += 8;
  }
  direction = directions[dir_number];
  report ("new direction: " + direction);
  switch (direction){
  case "north":
     sections = ({ 
    ({"north", "north", "north", "north" }),
    ({"north", "east", "north" , "north"}), 
    ({"north", "west", "north", "north" }),
    ({"north", "north", "east", "east" , "north"}),
    ({"north", "north", "west", "west" , "north"}),
//    ({"north", "north", "east", "south", "south", "east" }),
    ({"north", "northeast", "northeast", "northwest", "northwest", "north" }),
    ({"north", "northwest", "northwest", "northeast", "northeast", "north" }),
    ({"north", "southwest", "northwest" , "north"}),
    ({"north", "southeast", "northeast" , "north"}),
    ({"north", "southwest", "southwest", "northwest", "northwest", "north" }),
    ({"north", "southeast", "southeast", "northeast", "northeast", "north" })
      });
    break;
  case "northeast": 
    sections = ({
    ({"northeast", "northeast", "northeast", "northeast" }),
    ({"northeast", "northwest", "northeast" , "northeast" }),
    ({"northeast", "southeast", "northeast" , "northeast"}),
    ({"northeast", "northeast", "northwest", "northwest" , "northeast"}),
    ({"northeast", "northeast", "southeast", "southeast" , "northeast"}),
//    ({"northeast", "northeast", "northwest", "southwest", "southwest" }),
    ({"northeast", "east", "east", "north", "north", "northeast" }),
    ({"northeast", "west", "west", "east", "east", "northeast" }),
    ({"northeast", "south", "north" , "northeast"}),
    ({"northeast", "west", "east", "northeast" }),
    ({"northeast", "south", "south", "north", "north", "northeast" }),
    ({"northeast", "west", "west", "east", "east", "northeast" })
     });
    break;
  case "east":
    sections = ({
    ({"east", "east", "east", "east"}),
    ({"east", "south", "east", "east" }),
    ({"east", "north", "east" , "east"}),
    ({"east", "east", "south", "south", "east" }),
    ({"east", "east", "north", "north" , "east", "east" }),
//    ({"east", "east", "south", "west", "west" }),
    ({"east", "southeast", "southeast", "northeast", "northeast", "east" }),
    ({"east", "southwest", "southwest", "southeast", "southeast", "east" }),
    ({"east", "northwest", "northeast" , "east"}),
    ({"east", "southwest", "southeast", "east" }),
    ({"east", "northwest", "northwest", "northeast", "northeast", "east" }),
    ({"east", "southwest", "southwest", "southeast", "southeast", "east" })
    });
  case "southeast":
    sections = ({
    ({"southeast", "southeast", "southeast", "southeast" }),
    ({"southeast", "northeast", "southeast", "southeast" }),
    ({"southeast", "southwest", "southeast", "southeast" }),
    ({"southeast", "southeast", "northeast", "northeast", "southeast" }),
    ({"southeast", "southeast", "southwest", "southwest", "southeast" }),
 //   ({"southeast", "southeast", "northeast", "northwest", "northwest" }),
    ({"southeast", "south", "south", "east", "east", "southeast" }),
    ({"southeast", "north", "north", "south", "south", "southeast" }),
    ({"southeast", "west", "east", "southeast" }),
    ({"southeast", "north", "south", "southeast" }),
    ({"southeast", "west", "west", "east", "east", "southeast" }),
    ({"southeast", "north", "north", "south", "south", "southeast" })
    });
    break;
  case "south":
    sections = ({
    ({"south", "south", "south", "south" }),
    ({"south", "east", "south", "south" }),
    ({"south", "west", "south", "south" }),
    ({"south", "south", "east", "east", "south" }),
    ({"south", "south", "west", "west", "south" }),
//    ({"south", "south", "east", "north", "north" }),
    ({"south", "southeast", "southeast", "southwest", "southwest", "south" }),
    ({"south", "northeast", "northeast", "southeast", "southeast", "south" }),
    ({"south", "northwest", "southwest", "south" }),
    ({"south", "northeast", "southeast", "south" }),
    ({"south", "northwest", "northwest", "southwest", "southwest", "south" }),
    ({"south", "northeast", "northeast", "southeast", "southeast", "south" })
    });
    break;
  case "southwest":
    sections = ({
    ({"southwest", "southwest", "southwest", "southwest" }),
    ({"southwest", "southeast", "southwest", "southwest" }),
    ({"southwest", "northwest", "southwest", "southwest" }),
    ({"southwest", "southwest", "southeast", "southeast", "southwest" }),
    ({"southwest", "southwest", "northwest", "northwest", "southwest" }),
//    ({"southwest", "southwest", "southeast", "northeast", "northeast" }),
    ({"southwest", "south", "south", "west", "west", "southwest" }),
    ({"southwest", "east", "east", "south", "south", "southwest" }),
    ({"southwest", "north", "west", "southwest" }),
    ({"southwest", "east", "south", "southwest" }),
    ({"southwest", "north", "north", "west", "west", "southwest" }),
    ({"southwest", "east", "east", "south", "south", "southwest" })
    });
    break;
  case "west": 
    sections = ({
    ({"west", "west", "west", "west" }),
    ({"west", "south", "west", "west" }),
    ({"west", "north", "west", "west" }),
    ({"west", "west", "south", "south", "west" }),
    ({"west", "west", "north", "north", "west" }),
  //  ({"west", "west", "south", "east", "east" }),
    ({"west", "southwest", "southwest", "northwest", "northwest", "west" }),
    ({"west", "southeast", "southeast", "southwest", "southwest", "west" }),
    ({"west", "northeast", "northwest", "west" }),
    ({"west", "southeast", "southwest", "west" }),
    ({"west", "northeast", "northeast", "northwest", "northwest", "west" }),
    ({"west", "southeast", "southeast", "southwest", "southwest", "west" })
    });
    break;
  case "northwest":
    sections = ({
    ({"northwest", "northwest", "northwest", "northwest" }),
    ({"northwest", "southwest", "northwest", "northwest" }),
    ({"northwest", "northeast", "northwest" , "northwest"}),
    ({"northwest", "northwest", "southwest", "southwest", "northwest" }),
    ({"northwest", "northwest", "northeast", "northeast", "northwest" }),
//    ({"northwest", "northwest", "southwest", "southeast", "southeast" }),
    ({"northwest", "west", "west", "west", "west", "northwest" }),
    ({"northwest", "south", "south", "west", "west", "northwest" }),
    ({"northwest", "east", "west", "northwest" }),
    ({"northwest", "south", "west", "northwest" }),
    ({"northwest", "east", "east", "west", "west", "northwest" }),
    ({"northwest", "south", "south", "west", "west", "northwest" })
    });
    break;
  }
  section = sections[random(sizeof(sections))];
  return section;
}

mapping query_locations(string path){
  string * ks;
  int count;
  ks = keys(saved_locations);
  count = sizeof (ks);
  if (count <1 || member_array(path, ks)==-1){
    report("No locations for " + path );
    return ([]);
  }
  return saved_locations[path];
}

void align_map(string path){
  int * locs, count, i, min_x, min_y, x, y, loc;
  string * ks;
  mapping locations, new_locations;
  locs =  westmost_locations(path, 1);
  if(sizeof(locs)<1){
    report("No west locations to align");
    return;
  }
  min_x = locs[0] %1000;
  report ("Min x: " + min_x);
  locs =  southmost_locations(path, 1);
  if(sizeof(locs)<1){
    report("No south locations to align");
    return;
  }
  min_y = locs[0] /1000;
  report ("Min y: " + min_y);
  ks = keys(saved_locations);
  count = sizeof (ks);
  if (count <1 || member_array(path, ks)==-1){
    report("No locations for " + path + " to align");
    return;
  }
  locations = saved_locations[path];
  locs = keys(locations);
  count = sizeof(locs);
  if (count <1){
    report("Fewer than 1 location for " + path + " to align");
    return;
  }
  new_locations = ([]);
  for(i=0;i<count;i++){
    report("Original location: " + locs[i]);
    x = locs[i]%1000;
    y = locs[i]/1000;
    x -= min_x;
    y -= min_y;
    loc = (y * 1000) + x;
    report("New location: " + loc);
    new_locations[loc] = locations[locs[i]];
  }
  saved_locations[path] = new_locations;
}

varargs int * eastmost_locations(string path, int num_results){
  string * ks;
  mapping maze, locations;
  int * location_nos, x, i, count, j, * result, *start_result, * end_result, num;
  if (num_results < 1){
    num_results = 1;
  }
  result = ({});
  if (sizeof(saved_mazes)<1){
    return ({});
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    return ({});
  }
  maze = saved_mazes[path];
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){;
    return ({});
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(location_nos);
//  report ("Starting to check through " + count + " locations");
  for (i=0;i<count;i++){
    if (i<num_results){
      result += ({location_nos[i]});
      continue;
    }
    x = location_nos[i]%1000;
//    report ("location number: " + location_nos[i] + "  x value: " + x);
    if (sizeof(result)<1){
//      report ("This is the first result. Adding and continuing");
      result = ({location_nos[i]});
      continue;
    }
//    report ("cycling through results to see if this is a eastmost location");
    num = sizeof(result);
    for (j= 0;j<num;j++){
      if (x>result[j]%1000){
//        report ("" + x + " is bigger than x value of " + result[j]);
        if (j==0){
//          report ("adding " + location_nos[i] + " at start of results");
          result = ({location_nos[i]}) + result;
          break;
        } else {
//          report ("adding " + location_nos[i] + " in middle of results");
          start_result = result [0..j-1];
          end_result = ({});
          if (sizeof(result)>j-1){
            end_result = result[j..sizeof(result)-1];
          }
          result = start_result + ({location_nos[i]})+ end_result;
          break;
        }
      }
    }
  }
  result = result[0..num_results-1];
  return result;
}

varargs void show_exit_locations(object ob, string path){
  if (!objectp(ob)){
    ob = TP;
  }
  tell_object(ob, "North exit: " + north_locations[path]);
  tell_object(ob, "East exit: " + east_locations[path]);
  tell_object(ob, "South exit: " + south_locations[path]);
  tell_object(ob, "West exit: " + west_locations[path]);
}
void setup_exit_locations(string path){
  int * locations, i, count;
  north_locations[path] = northmost_locations(path, 1)[0];
  east_locations[path] = eastmost_locations(path, 1)[0];
  south_locations[path] = southmost_locations(path, 1)[0];
  west_locations[path] = westmost_locations(path, 1)[0];
  if (north_locations[path] == east_locations[path]  || north_locations[path] == west_locations[path]){
    locations = northmost_locations(path, 3);
    if (sizeof(locations)<1){
      report("No northmost locations found!");
      return;
    }
    for (i = 0;i<sizeof(locations);i++){
      if (locations[i]!= east_locations[path] && locations[i]!=west_locations[path]){
        north_locations[path] = locations[i];
        break;
      }
    }
  }
  if (south_locations[path] == east_locations[path]  || south_locations[path] == west_locations[path]){
    locations = southmost_locations(path, 3);
    if (sizeof(locations)<1){
      report("No southmost locations found!");
      return;
    }
    for (i = 0;i<sizeof(locations);i++){
      if (locations[i]!= east_locations[path] && locations[i]!=west_locations[path]){
        south_locations[path] = locations[i];
        break;
      }
    }
  }
}



varargs int * westmost_locations(string path, int num_results){
  string * ks;
  mapping maze, locations;
  int * location_nos, x, i, count, j, * result, *start_result, * end_result, num;
  if (num_results < 1){
    num_results = 1;
  }
  result = ({});
  if (sizeof(saved_mazes)<1){
    return ({});
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    return ({});
  }
  maze = saved_mazes[path];
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){;
    return ({});
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(location_nos);
//  report ("Starting to check through " + count + " locations");
  for (i=0;i<count;i++){
    if (i<num_results){
      result += ({location_nos[i]});
      continue;
    }
    x = location_nos[i]%1000;
//    report ("location number: " + location_nos[i] + "  x value: " + x);
    if (sizeof(result)<1){
//      report ("This is the first result. Adding and continuing");
      result = ({location_nos[i]});
      continue;
    }
//    report ("cycling through results to see if this is a eastmost location");
    num = sizeof(result);
    for (j= 0;j<num;j++){
      if (x<result[j]%1000){
//        report ("" + x + " is bigger than x value of " + result[j]);
        if (j==0){
//          report ("adding " + location_nos[i] + " at start of results");
          result = ({location_nos[i]}) + result;
          break;
        } else {
//          report ("adding " + location_nos[i] + " in middle of results");
          start_result = result [0..j-1];
          end_result = ({});
          if (sizeof(result)>j-1){
            end_result = result[j..sizeof(result)-1];
          }
          result = start_result + ({location_nos[i]})+ end_result;
          break;
        }
      }
    }
  }
  result = result[0..num_results-1];
  return result;
}


varargs int * northmost_locations(string path, int num_results){
  string * ks;
  mapping maze, locations;
  int * location_nos, y, i, count, j, * result, *start_result, * end_result, num;
  if (num_results < 1){
    num_results = 1;
  }
  result = ({});
  if (sizeof(saved_mazes)<1){
    return ({});
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    return ({});
  }
  maze = saved_mazes[path];
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){;
    return ({});
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(location_nos);
//  report ("Starting to check through " + count + " locations");
  for (i=0;i<count;i++){
    if (i<num_results){
      result += ({location_nos[i]});
      continue;
    }
    y = location_nos[i]/1000;
//    report ("location number: " + location_nos[i] + "  y value: " + y);
    if (sizeof(result)<1){
//      report ("This is the first result. Adding and continuing");
      result = ({location_nos[i]});
      continue;
    }
//    report ("cycling through results to see if this is a northmost location");
    num = sizeof(result);
    for (j= 0;j<num;j++){
      if (y>result[j]/1000){
//        report ("" + y + " is bigger than y value of " + result[j]);
        if (j==0){
//          report ("adding " + location_nos[i] + " at start of results");
          result = ({location_nos[i]}) + result;
          break;
        } else {
//          report ("adding " + location_nos[i] + " in middle of results");
          start_result = result [0..j-1];
          end_result = ({});
          if (sizeof(result)>j-1){
            end_result = result[j..sizeof(result)-1];
          }
          result = start_result + ({location_nos[i]})+ end_result;
          break;
        }
      }
    }
  }
  result = result[0..num_results-1];
  return result;
}

mapping query_saved_mazes(){
  return saved_mazes;
}

varargs int * southmost_locations(string path, int num_results){
  string * ks;
  mapping maze, locations;
  int * location_nos, y, i, count, j, * result, *start_result, * end_result, num;
  if (num_results < 1){
    num_results = 1;
  }
  result = ({});
  if (sizeof(saved_mazes)<1){
    return ({});
  }
  ks = keys(saved_mazes);
  if (member_array(path, ks)==-1){
    return ({});
  }
  maze = saved_mazes[path];
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){;
    return ({});
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(location_nos);
//  report ("Starting to check through " + count + " locations");
  for (i=0;i<count;i++){
    if (i<num_results){
      result += ({location_nos[i]});
      continue;
    }
    y = location_nos[i]/1000;
//    report ("location number: " + location_nos[i] + "  y value: " + y);
    if (sizeof(result)<1){
//      report ("This is the first result. Adding and continuing");
      result = ({location_nos[i]});
      continue;
    }
//    report ("cycling through results to see if this is a southmost location");
    num = sizeof(result);
    for (j= 0;j<num;j++){
      if (y<result[j]/1000){
//        report ("" + y + " is smaller than y value of " + result[j]);
        if (j==0){
//          report ("adding " + location_nos[i] + " at start of results");
          result = ({location_nos[i]}) + result;
          break;
        } else {
//          report ("adding " + location_nos[i] + " in middle of results");
          start_result = result [0..j-1];
          end_result = ({});
          if (sizeof(result)>j-1){
            end_result = result[j..sizeof(result)-1];
          }
          result = start_result + ({location_nos[i]})+ end_result;
          break;
        }
      }
    }
  }
  result = result[0..num_results-1];
  return result;
}

int north_limit(string path){
  mapping locations;
  string * ks;
  int * location_nos, x, result, i, count;
  if (sizeof(saved_locations)<1){
    return -1;
  }
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){
    return -1;
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(locations);
  result = 0;
  for (i = 0;i<count;i++){
    x = location_nos[i]/1000;
    if (x>result){
      result = x;
    }
  }
  return result;
}

int south_limit(string path){
  mapping locations;
  string * ks;
  int * location_nos, x, result, i, count;
  if (sizeof(saved_locations)<1){
    return -1;
  }
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){
    return -1;
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(locations);
  result = 1000;
  for (i = 0;i<count;i++){
    x = location_nos[i]/1000;
    if (x<result){
      result = x;
    }
  }
  return result;
}


int east_limit(string path){
  mapping locations;
  string * ks;
  int * location_nos, x, result, i, count;
  if (sizeof(saved_locations)<1){
    return -1;
  }
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){
    return -1;
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(locations);
  result = 0;
  for (i = 0;i<count;i++){
    x = location_nos[i]%1000;
    if (x>result){
      result = x;
    }
  }
  return result;
}

int west_limit(string path){
  mapping locations;
  string * ks;
  int * location_nos, x, result, i, count;
  if (sizeof(saved_locations)<1){
    return -1;
  }
  ks = keys(saved_locations);
  if (member_array(path, ks)==-1){
    return -1;
  }
  locations = saved_locations[path];
  location_nos = keys(locations);
  count = sizeof(locations);
  result = 1000;
  for (i = 0;i<count;i++){
    x = location_nos[i]%1000;
    if (x<result){
      result = x;
    }
  }
  return result;
}

int midmost_north_room(string path){
  int i, count,* rooms, map_midpoint, * east_locations, east_limit, mid_east, result, x, new_x, dist_from_middle, new_dist_from_middle;
  rooms = northmost_locations(path, 5);
  east_locations = eastmost_locations(path, 5);
  mid_east = (east_limit(path) + west_limit(path))/2;
  report ("Mid east: " + mid_east);
  count = sizeof(rooms);
  result = 0;
  dist_from_middle = mid_east;
  for (i=0;i<count;i++){
    new_x = rooms[i]%1000;
    if (new_x >=mid_east){
      new_dist_from_middle = new_x - mid_east;
    } else {
      new_dist_from_middle = mid_east - new_x;
    }
    if (new_dist_from_middle < dist_from_middle){
      result = rooms[i];
      dist_from_middle = new_dist_from_middle;
    }
  }
  return result;
}

int midmost_south_room(string path){
  int i, count,* rooms, map_midpoint, * east_locations, east_limit, mid_east, result, x, new_x, dist_from_middle, new_dist_from_middle;
  rooms = southmost_locations(path, 5);
  east_locations = eastmost_locations(path, 5);
  mid_east = (east_limit(path) + west_limit(path))/2;
  report ("Mid east: " + mid_east);
  count = sizeof(rooms);
  result = 0;
  dist_from_middle = mid_east;
  for (i=0;i<count;i++){
    new_x = rooms[i]%1000;
    if (new_x >=mid_east){
      new_dist_from_middle = new_x - mid_east;
    } else {
      new_dist_from_middle = mid_east - new_x;
    }
    if (new_dist_from_middle < dist_from_middle){
      result = rooms[i];
      dist_from_middle = new_dist_from_middle;
    }
  }
  return result;
}

int midmost_east_room(string path){
  int i, count,* rooms, map_midpoint, * east_locations, north_limit, mid_north, result, y, new_y, dist_from_middle, new_dist_from_middle;
  rooms = northmost_locations(path, 5);
  east_locations = eastmost_locations(path, 5);
  mid_north = (north_limit(path) + south_limit(path))/2;
  report ("Mid north: " + mid_north);
  count = sizeof(rooms);
  result = 0;
  dist_from_middle = mid_north;
  for (i=0;i<count;i++){
    new_y = rooms[i]%1000;
    if (new_y >=mid_north){
      new_dist_from_middle = new_y - mid_north;
    } else {
      new_dist_from_middle = mid_north - new_y;
    }
    if (new_dist_from_middle < dist_from_middle){
      result = rooms[i];
      dist_from_middle = new_dist_from_middle;
    }
  }
  return result;
}

int midmost_west_room(string path){
  int i, count,* rooms, map_midpoint, * east_locations, north_limit, mid_north, result, y, new_y, dist_from_middle, new_dist_from_middle;
  rooms = northmost_locations(path, 5);
  east_locations = eastmost_locations(path, 5);
  mid_north = (north_limit(path) + south_limit(path))/2;
  report ("Mid north: " + mid_north);
  count = sizeof(rooms);
  result = 0;
  dist_from_middle = mid_north;
  for (i=0;i<count;i++){
    new_y = rooms[i]%1000;
    if (new_y >=mid_north){
      new_dist_from_middle = new_y - mid_north;
    } else {
      new_dist_from_middle = mid_north - new_y;
    }
    if (new_dist_from_middle < dist_from_middle){
      result = rooms[i];
      dist_from_middle = new_dist_from_middle;
    }
  }
  return result;
}

void report(string str){
  object ob;
  ob = find_player("lujke");
  if (objectp(ob)){
    tell_object(ob, "" + str);
  }
}
