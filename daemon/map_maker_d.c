#include <std.h>
#include <security.h>
#define SAVE_FILE "/daemon/save/saved_maps"
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "maps_log"
inherit DAEMON;

mapping users; // ([string name: ([ string mapname: mixed * maps_locations_timings ]) ])
mixed * maps_locations_timings; // ({mapping maps, mapping locations, mapping timings, mapping clash_rooms, mapping duplicate_rooms})
mapping maps; //  ([string mapname : mixed * maps_locations_timings])
mapping location_grids; // ([ string mapname : mapping  ])
mapping timings; // ([string mapname : int time_saved])
mapping rooms;  // ([string room_name: string * exits])
mapping locations; //([ int location: string room_name ])
mapping current_maps; // ([ string username: string current_map })
mapping notations; //([string room : ({string note_name, string description}) ])
mapping waystation_records; // ([string username: mapping user_waystations ])
mapping user_waystations;// ([string mapname: mapping waystations])
mapping waystations;  // ([string roomname: int stage]);
string reporting, * clashes, * dupes;
int timing, detect_invis_exits, last_save;

int high_x();
int low_x();
int high_y();
int low_y();

mapping query_users(){
  return users;
}

mixed * query_maps_locations_timings(string user){
  return users[user];
}

mapping query_waystations(string user, string mapname){
  string * usernames, * mapnames;
  if (!mapp(waystation_records) || sizeof(waystation_records)<1) return ([]);
  usernames = keys(waystation_records);
  if (member_array(user, usernames)==-1) return ([]);
  user_waystations = waystation_records[user];
  if (!mapp(user_waystations) || sizeof(user_waystations)<1) return ([]);
  mapnames = keys(user_waystations);
  if (member_array(mapname, mapnames )== -1) return ([]);
  return user_waystations[mapname];
}

string query_current_map(string username){
  string * usernames;
  if (!mapp(current_maps) || sizeof(current_maps)<1) return "none";
  usernames = keys(current_maps);
  if (member_array(username, usernames)==-1) return "none";
  return current_maps[username];
}

int setup_waystations(string user, string mapname, string roomname){
  string * usernames, * mapnames, * roomnames, * directions, * current_rooms, * next_rooms, * checked_rooms, * waystation_names;
  int i, j, k, count, count2;
  mapping exits;
  load_map(user, mapname);
  if (!mapp(rooms) || sizeof(rooms)<1) return -1;
  next_rooms = ({roomname});
  directions = ({});
  current_rooms = ({});
  checked_rooms = ({});
  waystations = ([roomname: 1]);
  for (i=2;i<37;i++)
  {
    report ("Waystations stage " + i);
    count = sizeof(next_rooms);
    current_rooms = next_rooms;
    next_rooms = ({});
    rooms = query_rooms(user, mapname);
    report("About to run through rooms for stage" + i);
    for (j=0; j<count; j++)
    {
      report ("Room no: " + j + " is " + current_rooms[j]);
      if (member_array(current_rooms[j], checked_rooms)!=-1)
      {
        report ("%^GREEN%^Room "+ current_rooms[j] + " has already been checked");
        continue;
      }
      exits = rooms[current_rooms[j]];
      if (!mapp(exits))
      {
        report ("%^BOLD%^%^BLUE%^Room " + current_rooms[j] + " has no valid exit map");
        if (!catch(current_rooms[j]->query_short())){
          exits = generate_new_exit_map(current_rooms[j]);
 //         save_room(user, mapname, roomname, exits);
        } else
        {
          if (!stringp(current_rooms[j])) report(current_rooms[j] + "Is not a string, apparently, J = " + j);
          if (catch(current_rooms[j]->query_short())) report(current_rooms[j] + "%^BOLD%^%^YELLOW%^ Is not a valid room");
//          checked_rooms += ({current_rooms[j]});
          continue;
        }
//        checked_rooms += ({current_rooms[j]});
//        continue;
      }
      if (mapp(exits))
      {
        directions = keys(exits);
      } else
      {
        directions = ({});
      }
      count2 = sizeof(directions);
      if (count2<1)
      {
        report ("%^BOLD%^%^BLUE%^Room " + current_rooms[j] + " has less than one exit");
        checked_rooms += ({current_rooms[j]});
        continue;
      }
      for(k=0;k<count2;k++)
      {
        report ("Exit number: " + k + " is :  " + directions[k] + " leading to " + exits[directions[k]]);
        if (exits[directions[k]] != "unknown" && member_array(exits[directions[k]], checked_rooms)==-1)
        {
          report ("Adding room " + exits[directions[k]] + " to next rooms");
          next_rooms += ({exits[directions[k]]});
        } else {
          if (exits[directions[k]] == "unknown") report("NOT ADDING UNKNOWN EXIT TO NEXT ROOMS");

          if (member_array(exits[directions[k]], checked_rooms)!=-1) report("ROOM " + exits[directions[k]] + " ALREADY CHECKED. MOVING ON...");
          continue;
        }
      }
      checked_rooms += ({current_rooms[j]});
    }
    if (sizeof(next_rooms)<1){
      report("%^BOLD%^%^MAGENTA%^NO MORE ROOMS TO CHECK AFTER STAGE " + i);
      break;
    }
    report ("i%5 = " + i%5);
    count = sizeof(next_rooms);
    if(count>0 && i%3==0)
    {
      for (j = 0;j<count;j++)
      {
        report("Adding waystation for " + next_rooms[j]);
        waystations[next_rooms[j]] = i;
      }
    }
    report ("%^BOLD%^%^YELLOW%^END OF STAGE " + i);
  }
  user_waystations[mapname] = waystations;
  waystation_records[user] = user_waystations;
}

mapping query_location_grids(string user)
{
  return users[user][1];
}

mapping query_timings(string user)
{
  return users[user][2];
}
mapping query_clash_rooms(string user)
{
  return users[user][3];
}

mapping query_duplicate_rooms(string user)
{
  return users[user][4];
}


string * query_locations(string user, string mapname){
  return users[user][mapname][1];
}

string * query_timing(string user, string mapname){
  return users[user][mapname][2];
}


string * query_clashes(string user, string mapname){
  return users[user][mapname][3];
}
string * query_dupees(string user, string mapname){
  return users[user][mapname[4]];
}

mapping query_loaded_maps(){
  return maps;
}

mapping query_loaded_locations(){
  return locations;
}

int query_loaded_timing(){
  return timing;
}

string * query_loaded_clashes(){
  return clashes;
}

string * query_loaded_dupes(){
  return dupes;
}

string * query_dupes(string user){
  string mapname;
  mapname = query_current_map(user);
  if(mapname == "none") return ({});
  load_map(user, mapname);
  return dupes;
}

void create(){
    ::create();
    users = ([]);
    maps_locations_timings = ({ ([]), ([]),([]), ([]), ([]), ([]) });
    maps = ([]);
    current_maps = ([]);
    location_grids = ([]);
    timings = ([]);
    rooms = ([]);
    locations = ([]);
    clashes = ({});
    dupes = ({});
    timing = 0;
    notations = ([]);
    detect_invis_exits = 0;
    waystations = ([]);
    user_waystations = ([]);
    waystation_records = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE,1);
    seteuid(getuid());
    last_save = 0;

}

void SAVE(){
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

int remove_note(string user, string title){
  int num, t, *roomnames, i, count, roomname;
  num = load_current_map(user);
  if (num != 1) return num;
  report ("Removing note - current map successfully loaded");
  if (!mapp(notations) || sizeof(notations)<1) return 0;
  report ("Removing note - there are some notations for this map");
  roomnames = keys(notations);
  count = sizeof(roomnames);
  if (count<1) return 0;
  if (strlen(title)<2)title = title + " ";
  for (i=0;i<count;i++)
  {
    report ("checking whether " + notations[roomnames[i]][0] + " == " + title);
    if(strip_colors(notations[roomnames[i]][0]) == title)
    {
      report ("It does! Deleting note...");
      notations = m_delete(notations, roomnames[i]);
      maps = users[user];
      maps_locations_timings = ({rooms, locations, timing, clashes, dupes, notations});
      maps[current_maps[user]] = maps_locations_timings;
      users[user] = maps;
      report ("Note removed from map " + current_maps[user]);
    } else
    {
      report(strip_colors(notations[roomnames[i]][0]) + " != " + title);
    }
  }
}


mapping generate_waystations(string user, string name, string path, int stages, int spacing){
  string * this_stage_rooms, destinations, next_stage_rooms, rooms_checked;
  mapping exits, waystations;
  int i, j,k,l,m, count, count2, count3, num;
  num = load_current_map(user);
  if (num!=1) return ([]);
  //Set up first stage with starting name as only one in this_stage_rooms
  next_stage_rooms = ({path + name});

  //loop through number of stages.
  rooms_checked = ({});
  for(i=0;i<stages;i++){
    report ("%^YELLOW%^Stage: " + i);
    //At each stage: loop through rooms a number of times equal to spacing. Get exits, and destinations of exits
      //loop through destinations. If not already in list of next stage rooms, add it to list

    for (l=0;l<spacing;l++){
      this_stage_rooms = next_stage_rooms;
      next_stage_rooms = ({});
      count = sizeof(this_stage_rooms);
      if (count<1){
        break;
      }
      report ("%^BLUE%^Space: " + l);
      for (j = 0; j<count;j++){
        report("%^RESET%^Checking room: " + this_stage_rooms[j]);
        exits = rooms[this_stage_rooms[j]];
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
    for (m=0;m<count3;m++){

    }
    "/daemon/destinations_d"->add_waystation(name, name, 1);
  }
  return waystations;
}

mapping query_room_exits(string room){
  string * roomnames;
  if (!mapp(rooms) || sizeof(rooms)<1) return ([]);
  roomnames = keys(rooms);
  if (member_array(room, roomnames) == -1) return ([]);
  return rooms[room];
}




save_room(string user, string mapname, string roomname, mapping exits){
  string * usernames, * mapnames, * roomnames;
  if (!mapp(rooms))
  {
    rooms = ([]);
  }
  rooms[roomname] = exits;
  if (!arrayp(maps_locations_timings)) maps_locations_timings = ({});
  maps_locations_timings[0] = rooms;
  if (!mapp(maps)) maps = ([]);
  maps[mapname] = maps_locations_timings;
  if (!mapp(users)) users = ([]);
  users[user] = maps;
}




mapping query_maps(string user){
  string * usernames;
  if (!mapp(users) || sizeof(users)<1) return ([]);
  usernames = keys(users);
  if (member_array(user, usernames)!=-1)
  {
    return users[user];
  }
  return ([]);
}

int save_map (string user, string mapname){
  string * usernames, current_map, * mapnames;
  current_map = query_current_map(user);
  if(current_map == "none") return 0;
  load_map(user, current_map);
  if (!mapp(users) || sizeof(users)<1) users = ([]);
  usernames = keys(users);
  maps_locations_timings[0] = rooms;
  maps_locations_timings[1] = locations;
  maps_locations_timings[2] = timing;
  maps_locations_timings[3] = clashes;
  maps_locations_timings[4] = dupes;
  maps_locations_timings[5] = notations;
  if (mapp(users) && sizeof(users)>0)
  {
    usernames = keys(users);
    if (member_array(user, usernames) != -1)
    {
      maps = users[user];
    } else
    {
      maps = ([]);
    }
  } else
  {
    users = ([]);
    maps = ([]);
  }
  if (mapp(maps) && sizeof(maps)>0)
  {
    mapnames = keys(maps);
    if (member_array(current_map, mapnames)!= -1) maps = m_delete(maps, current_map);
  }
  maps[mapname] = maps_locations_timings;
  users[user] = maps;
  current_maps[user] = mapname;
}

int add_notation(string user, string title, string note){
  string * roomnames, mapname, * usernames, roomname;
  object ob;
  if (!mapp(current_maps)|| sizeof(current_maps)<1){
    report("no current map found when adding note");
    return -1;
  }
  ob = find_player(user);
  if (!objectp(ob)||!objectp(environment(ob))) return -2;
  if (!stringp(title) || !stringp(note)) return -3;
  report("User and environment okay when adding note");
  usernames = keys(current_maps);
  if (member_array(user, usernames)==-1) return -4;
  report("User has a current map when adding note");
  mapname = current_maps[user];
  load_map(user, mapname);
  if (!mapp(notations) || sizeof(notations)<1)
  {
    notations = ([]);
  }
  roomname = base_name(environment(ob));
  notations[roomname] = ({title, note});
  maps_locations_timings = ({rooms, locations, timing, clashes, dupes, notations});
  maps[mapname] = maps_locations_timings;
  users[user] = maps;
  return 1;
}

int contains_room(string roomname){
  string * roomnames;
  if (!mapp(rooms) || sizeof(rooms)<1) return 0;
  roomnames = keys(rooms);
  if (member_array(roomname, roomnames)==-1) return 0;
  return 1;
}

int has_notation(string roomname){
  string * roomnames;
  if (!mapp(notations) || sizeof(notations)<1) return 0;
  roomnames = keys(notations);
  if (member_array(roomname, roomnames)==-1) return 0;
  return 1;
}

string * query_notation(string roomname){
  string * roomnames;
  if (!mapp(notations) || sizeof(notations)<1) return ({});
  roomnames = keys(notations);
  if (member_array(roomname, roomnames)==-1) return ({});
  return notations[roomname];
}

int load_current_map(string user){
  string mapname;
  mapname = query_current_map(user);
  if (mapname == "none") return 0;
  return load_map(user, mapname);
}

string * query_rooms_with_notations(string user){
  string mapname;
  mapname = query_current_map(user);
  if (mapname == "none") return ({});
  load_map(user, mapname);
  if (!mapp(notations) || sizeof(notations)<1) return ({});
  return keys(notations);
}

string * query_all_note_titles(string user){
  string * result, roomnames;
  int i, count;
  result = ({});
  roomnames = query_rooms_with_notations(user);
  count = sizeof(roomnames);
  if (count<1) return roomnames;
  for (i=0;i<count;i++){
    result += ({notations[roomnames[i]][0]});
  }
  return result;
}

string query_note(string title){
  string * roomnames, * title_note, t;
  int i, count;
  if (!mapp(notations) || sizeof(notations)<1) return "No note with that title";
  roomnames = keys(notations);
  count = sizeof(roomnames);
  for (i=0;i<count;i++)
  {
    title_note = notations[roomnames[i]];
    if (sizeof(title_note)<2) continue;
    t = strip_colors(title_note[0]);
    if (t == title) return title_note[1];
  }
  return "There does not seem to be a note to go with that title";
}

string query_room_with_note(string title){
  string * roomnames, * title_note, t;
  int i, count;
  if (!mapp(notations) || sizeof(notations)<1) return "none";
  roomnames = keys(notations);
  count = sizeof(roomnames);
  for (i=0;i<count;i++)
  {
    title_note = notations[roomnames[i]];
    if (sizeof(title_note)<2) continue;
    t = strip_colors(title_note[0]);
    if (t == title) return roomnames[i];
  }
  return "none";
}


int load_maps(string user){
  string * usernames;
  if (!mapp(users) || sizeof(users)<1)
  {
    report("No users found in load_maps");
    users = ([]);
    maps = ([]);
    users[user] = maps;
    return 2;
  }
  usernames = keys(users);
  if (!member_array(user, usernames)==-1)
  {
    report("No maps found for user " + user + " in load_maps");
    maps = ([]);
    users[user] = maps;
    return 3;
  }
  report("maps loaded for user " + user);
  maps = users[user];
  return 1;
}

int remove_map(string user, string mapname){
  string * usernames, * mapnames;
  if (!mapp(users) || sizeof(users)<1) return 0;
  usernames = keys(users);
  if (member_array(user, usernames)==-1) return 0;
  maps = users[user];
  if (!mapp(maps) || sizeof(maps)<1) return 0;
  mapnames = keys(maps);
  if (member_array(mapname, mapnames)==-1) return 0;
  maps = m_delete(maps, mapname);
  users[user] = maps;
  return 1;
}

int load_map(string user, string mapname){
  string * usernames, mapnames;
  if (!mapp(users) || sizeof(users)<1 ) users = ([]);
  usernames = keys(users);
  report("%^BOLD%^%^CYAN%^LOADING MAP " +  mapname + " for user " + user);
  if (sizeof(usernames)>0 && member_array(user, usernames) !=-1)
  {
    report("%^BOLD%^%^CYAN%^Some maps_locations_timings identified for user " + user);
    maps = users[user];
    if (!mapp(maps) || sizeof(maps)<1 ) maps = ([]);
    user_waystations = waystation_records[user];
    mapnames = keys(maps);
    if (sizeof(mapnames)< 1 || member_array(mapname, mapnames)==-1)
    {
      report ("No map called " + mapname + " found for user " + user + ". Starting a blank one");
      rooms = ([]);
      locations = ([]);
      timing = 0;
      clashes = ({});
      dupes = ({});
      notations = ([]);
      maps_locations_timings = ({rooms, locations, timing, clashes, dupes, notations});
      maps[mapname] = maps_locations_timings;
      users[user]= maps;
      current_maps[user] = mapname;
      if (!mapp(waystation_records)) waystation_records = ([]);
      usernames = keys(waystation_records);
      if (sizeof(usernames)<1 || member_array(user, usernames)== -1)
      {
        user_waystations = ([]);
      } else
      {
        user_waystations = waystation_records[user];
      }
      waystations = ([]);
      user_waystations[mapname] = waystations;
      waystation_records[user] = user_waystations;
      report("Load map result 3");
      return 3;
    }
    maps_locations_timings = maps[mapname];
    if (sizeof(maps_locations_timings)>0)
    {
      rooms = maps_locations_timings[0];
      locations = maps_locations_timings[1];
      timing = maps_locations_timings[2];
      clashes = maps_locations_timings[3];
      dupes = maps_locations_timings[4];
      if (sizeof(maps_locations_timings)>5)
      {
        notations = maps_locations_timings[5];
      } else
      {
        notations = ([]);
      }
      if (!mapp(waystation_records) || sizeof(waystation_records)<1)
      {
        report("Load map: No waystation records found AT ALL");
        waystation_records = ([]);
        user_waystations= ([]);
        waystations = ([]);
        user_waystations[mapname] = waystations;
        waystation_records[user] = user_waystations;

      } else
      {
        usernames = keys(waystation_records);
        if (member_array(user, usernames)==-1)
        {
          report("Load map: No waystation records found FOR THIS USER: " + user);
          user_waystations = ([]);
          waystations = ([]);
          user_waystations[mapname] = waystations;
          waystation_records[user] = user_waystations;
        } else
        {
          user_waystations = waystation_records[user];
          if (!mapp(user_waystations) || sizeof(user_waystations)<1){
            report("Load map: user_waystations for this user not a valid mapping, or sized <1");
            waystations = ([]);
            user_waystations = ([]);
            user_waystations[mapname] = waystations;
          } else
          {
            mapnames = keys(user_waystations);
            if (member_array(mapname, mapnames)==-1)
            {
              report("Load map: No waystations found for this map. User: " + user + " Mapname: " + mapname);
              waystations = ([]);
              user_waystations[mapname] = waystations;
            } else
            {
              waystations = user_waystations[mapname];
              if (!mapp(waystations))
              {
                report("Load map: waystations for map: "+ mapname +" user: " + user + " are not a valid mapping");
                waystations = ([]);
                user_waystations[mapname] = waystations;
              } else
              {
                report("%^BOLD%^%^CYAN%^Load map: Waystations successfully loaded");
              }
            }
          }
        }
      }
      current_maps[user] = mapname;
      report("Load map result 1");
      return 1;
    }
    report("Load map result 5");
    return 5;
  }
  report("%^BOLD%^%^CYAN%^NO MAPS_LOCATIONS_TIMINGS identified for user " + user + ". Making some new ones");
  maps = ([]);
  rooms = ([]);
  locations = ([]);
  timing = 0;
  clashes = ({});
  dupes = ({});
  notations = ([]);
  maps_locations_timings = ({maps, locations, timing, clashes, dupes, notations});
  maps[mapname] = maps_locations_timings;
  users[user]= maps;
  current_maps[user] = mapname;
  waystations = ([]);
  user_waystations[mapname] = waystations;
  waystation_records[user] = user_waystations;
  report("Load map result 2");
  return 2;
}

void start_new_map(object who){
  string mapname, * usernames, * mapnames;
  if (!objectp(who)) return;
  if (!intp(last_save) || time()> last_save + 100) SAVE();
  mapname = get_next_map_name(who);
  if (!mapp(users) || sizeof(users)<1) users = ([]);
  usernames = keys(users);
  rooms = ([]);
  locations = ([]);
  clashes = ({});
  dupes = ({});
  timing = 0;
  notations =([]);
  detect_invis_exits = 0;
  maps_locations_timings = ({ rooms, locations, timing, clashes, dupes , notations});

  if (mapp(users) && sizeof(users)>0)
  {
    usernames = keys(users);
    if (member_array(who->query_name(), usernames)!=-1)
    {
      maps = users[who->query_name()];
    }
  }
  if (!mapp(maps)) maps = ([]);
  maps[mapname] = maps_locations_timings;
  users[who->query_name()]=maps;
  current_maps[who->query_name()] = mapname;
}

void clear_maps(string who){
  users[who] = ([]);
  current_maps[who] = "none";
}

mapping query_map(string who, string mapname){
  string * usernames;
  if (!mapp(users) || sizeof(users)<1) return ([]);
  usernames = keys(users);
  if (member_array(who, usernames) == -1) return ([]);
  return users[who][0][mapname];
}

int get_location(string roomname){
  int * locs, i, count;
  if (mapp(locations) && sizeof(locations)>0)
  {
    locs = keys(locations);
    count = sizeof(locs);
    if (count>0)
    {
      for (i=0;i<count;i++)
      {
        if (locations[locs[i]]==roomname)
        {
          report ("location number " + i + " is " + locs[i] + "which links to " + locations[locs[i]] + ", and is the same as the base name of the room");
          return locs[i];
        }
      }
    }
  }
  return -1;
}

int is_nonstandard_direction(string direction){
  switch(direction)
  {
  case "north":
  case "northeast":
  case "east":
  case "southeast":
  case "south":
  case "southwest":
  case "west":
  case "northwest":
    return 0;
  default:
    return 1;
  }
}

void add_room(object who, string direction){
  object rm, destination;
  string * mapnames, mapname, * roomnames, dest_name, * exits, return_dir, *directions, dest_mapname;
  int i, count, *locs, loc, tmp, num, existing_loc;
  mapping exit_map;
  mapnames = ({});
  if (is_nonstandard_direction(direction)) return;
  if (!objectp(who) || !objectp(environment(who)))   //Check for errors in the player or their environment
  {
    report("error in add_room with who or their environment");
    return;
  }
  rm = environment(who);
  load_maps(who->query_name());
  mapname = get_map_name( base_name(rm));
  dest_name = rm->query_exit(direction);
  dest_mapname = get_map_name(dest_name);
  if (!mapp(maps) || sizeof(maps)<1) maps = ([]);
  mapnames = keys(maps);
  if (member_array(dest_mapname, mapnames)!=-1 && dest_mapname != mapname && dest_mapname!= "none")
  {
    report("%^CYAN%^Moving onto a new map. Current map: " + mapname + " New map: " + dest_mapname);
    tell_object(who, "%^ORANGE%^You realise that you are moving into the area covered by map: " + dest_mapname +", so you pull that map out and carry on");
    load_map(who->query_name(), dest_mapname);
    return 8;
  } else {
    if (!mapp(current_maps)) current_maps = ([]);
    current_maps[who->query_name()] = mapname;
    if (mapname ==  "none")
    {
      if (sizeof(query_maps(who->query_name())) >= ((int)"/daemon/bonus_d.c"->query_stat_bonus(who, "intelligence") + 5) *3)
//      if (sizeof(query_maps(who->query_name())) >= (int)"/daemon/bonus_d.c"->query_stat_bonus(who, "intelligence") + 5)
      {
        report("Max no of maps exceeded");
        tell_object(who, "The room you are in is not on any of your existing"
          +" maps, and you have reached the maximum number of maps you are able"
          +" to keep track of. If you want to start a new map of this area,"
          +" you will have to remove one or more of your existing maps."
          +" (If you don't want to remove a map, and want to stop seeing this"
          +" message, type 'map stop')");
        return 7;
      }
      report("No map found for " + who->query_name() + " at room " + base_name(rm));
      mapname = get_next_map_name(who);
      report("Starting new map: " + mapname);
    }
    num = load_map (who->query_name(), mapname);
    report ("Map load result is : "  + num);
  }
  if (catch(dest_name->query_short())) //checking for errors in the destination room
  {
    report("error in add_room, when trying to load destination room");
    return;
  }
  destination = find_object_or_load(dest_name);
  if (destination->is_map_transition()){
    tell_object(who, "%^ORANGE%^You reach the edge of your paper and stop mapping");
    report("%^BOLD%^%^MAGENTA%^Stopped mapping at map transition");
    return 6;
  }
  report ("start room is: " + base_name(rm) + "  direction name is: " + direction + " destination room is : " + dest_name);
  existing_loc = 0;
  if (!mapp(rooms) || sizeof(rooms)<1) rooms = ([]);
  roomnames = keys(rooms);
  if (sizeof(roomnames)>0 && member_array(base_name(rm), roomnames)!=-1) //checks whether the start room is already on the map
  {
    report ("Found existing exit map for start room");
    exit_map = rooms[base_name(rm)];
  } else
  {
    report ("%^BOLD%^%^MAGENTA%^No existing exit map for start room. Making a new one");
    exit_map = generate_new_exit_map(rm);
  }
  report("Adding exit in " + direction + " direction, leading to " + dest_name);
  exit_map[direction] = dest_name;
  rooms[base_name(rm)] = exit_map; //save the updated exit map to the room
//  roomnames = keys(rooms);
  if (sizeof(roomnames)>0 && member_array(dest_name, roomnames)!=-1)
  {
    report ("destination room does have an existing exit map. Loading it.");
    exit_map = rooms[dest_name];
    existing_loc = query_location(dest_name);
  } else
  {
    report ("destination room does not yet have an exit map. Making a new one.");
    exit_map = generate_new_exit_map(dest_name);
  }

  return_dir = find_exit_direction(destination, rm);
  report ("return exit is in "+ return_dir+" direction");
  if (!mapp(exit_map) || sizeof(exit_map)<1) exit_map = ([]);
  directions = keys(exit_map);
  if (sizeof(directions)>0 && member_array(return_dir, directions)!=-1 && exit_map[return_dir]!="none" && exit_map[return_dir]!=base_name(rm))
  {
    //Add in code for recording a funky exit (when you get round to it)
    report ("%^BOLD%^%^YELLOW%^NEED TO ADD CODE FOR RECORDING %^BOLD%^%^MAGENTA%^FUNKY %^YELLOW%^EXITS");
//    report ("FOR NOW, Adding exit in " + return_dir + " direction to the exit map, leading to " + base_name(rm));
//    exit_map[return_dir] = base_name(rm);
  }
  if (return_dir != "none")
  {
    report ("Adding exit in " + return_dir + " direction to the exit map, leading to " + base_name(rm));
    exit_map[return_dir] = base_name(rm);
  }
  report ("Adding the updated exit map to the destination room, " + dest_name);
  rooms[dest_name] = exit_map;

  loc = get_location(base_name(rm));
  if (loc ==-1) loc = 500500;
  report ("setting location " + loc + " to " + base_name(rm));
  locations[loc] = base_name(rm);
  //Check for conflicts with another room in the same location, or the same room in another location
  tmp = get_location(dest_name);
  loc = get_new_location(loc, direction);
  if (tmp >-1 && tmp != loc && (sizeof(dupes)<1 || member_array(dest_name, dupes) ==-1) )
  {
    dupes += ({dest_name});
    dupes += ({dest_name+".dupe"});
    dest_name = dest_name + ".dupe";
  }
  if (mapp(locations))
  {
    locs = keys(locations);
    if (sizeof(locs)>0 && member_array(loc, locs)!=-1)
    {
      if (locations[loc]!= dest_name)
      {
        clashes += ({dest_name});
      }
    }
  }
  report ("setting location " + loc + " to " + dest_name);
  locations[loc] = dest_name;
//  if (return_dir!="none")
//  {
//    exit_map[return_dir] = base_name(rm);
//  }
//  rooms[dest_name] = exit_map;
  maps_locations_timings[0] = rooms;
  maps_locations_timings[1] = locations;
  //add in code to add the location for the new room
  maps_locations_timings[2] = timing;
  maps_locations_timings[3] = clashes;
  maps_locations_timings[4] = dupes;
  maps_locations_timings[5] = notations;
  if (!mapp(maps)) maps = ([]);
  report ("About to set map for mapname: " + mapname);
  maps[mapname] = maps_locations_timings;
  if (!mapp(users))  users = ([]);
  report ("Map set successfully!");
  users[who->query_name()] = maps;
  if (!mapp(current_maps)) current_maps = ([]);
  current_maps[who->query_name()] = mapname;
}

mapping generate_new_exit_map(string roomname){
  mapping mp;
  object room, destroom;
  int i, count;
  string * directions, * roomnames, destname, ret_dir;
  if (!stringp(roomname))
  {
    report ("%^RED%^ERROR in generate_new_exit_map - roomname passed is not a string: " + roomname);
    return ([]);
  }
  if (!mapp(rooms) || sizeof(rooms)<1) rooms = ([]);
  roomnames = keys(rooms);
  if (catch(roomname->query_short()) )return 0;
  room = find_object_or_load(roomname);
  mp = ([]);
  directions = room->query_exits();
  count = sizeof(directions);
  if (count>0)
  {
    for (i=0;i<count;i++)
    {
      destname = room->query_exit(directions[i]);
      if (member_array(destname, roomnames)==-1)
      {
        mp[directions[i]] = "unknown";
      } else
      {
        mp[directions[i]] = destname;
        if (!catch(destname->query_short())){
          destroom = find_object_or_load(destname);
          ret_dir = find_exit_direction(destroom, room);
          if (ret_dir == 0)
          {
            report ("%^BOLD%^%^MAGENTA%^GODDAM IT, this is how the 0's are getting into the map!");
            report ("Room is: " + destname + " direction is: " + ret_dir);
          }
          if (roomname == 0 )
          {
            report ("%^BOLD%^%^YELLOW%^NO NO NO, this is how the 0's are getting into the map!");
            report ("Room is: " + roomname + " direction is: " + ret_dir);
          }
          if (destname == 0 )
          {
            report ("%^BOLD%^%^RED%^NO NO NO, this is how the 0's are getting into the map!");
            report ("Room is: " + roomname + " direction is: " + ret_dir);
          }          add_exit(destname, ret_dir,roomname);
        }
      }
    }
  }
  return mp;
}

string * map_route(string user, string startroom, string destroom){
  string mapname, * waystation_names, * temppath, * path, * unknowns, dest_name;
  int i, count;
  object origin, destination;
  mapname = query_current_map(user);
  if (catch(destroom->query_short()) )
  {
    report("%^BOLD%^%^GREEN%^Problem loading the destination room in map_route");
    return ({});
  }
  destination = find_object_or_load(destroom);
  if (mapname == "none")
  {
    report("%^BOLD%^%^GREEN%^No current map found in in map_route");
    return ({});
  }
  load_map(user, mapname);
  report("%^BOLD%^%^WHITE%^About to do query_waystations_en_route from map_route");
  waystation_names = query_waystations_en_route(user, startroom, destroom);
  report("%^BOLD%^%^WHITE%^FINISHED query_waystations_en_route from map_route");
  if (!arrayp(waystation_names) || sizeof(waystation_names)<1)
  {
    report("%^BOLD%^%^GREEN%^Waystations not loaded correctly in map_route");
    return ({});
  }
  path = ({});
  unknowns = query_unknowns();
  count = sizeof(waystation_names);
  report("%^BOLD%^%^YELLOW%^About to cycle through " + sizeof(waystation_names) + " waystations");
  for(i=0;i<count;i++)
  {
    if (i<count) report("%^BOLD%^%^YELLOW%^" + i + "Startroom: " + startroom + " Waystation: " + waystation_names[i]);
    else report ("Last section. Startroom: " + startroom + " Final destination: " +destroom);
    if (i==count)
    {
      dest_name = destroom;
    } else {
      dest_name = waystation_names[i];
    }
    if (catch(dest_name->query_short()))
    {
      report("%^BOLD%^%^GREEN%^Problem loading target waystation: " + dest_name + " in map_route");
      return ({});
    }
    destination = find_object_or_load(dest_name);
    if (catch(startroom->query_short()) )
    {
      report("%^BOLD%^%^GREEN%^Problem loading waystation: " + startroom + " in map_route");
      return ({});
    }
    origin = find_object_or_load(startroom);
    report ("Attempting to find path from " + base_name(origin) + " to " + base_name(destination));
    temppath = "/daemon/pathfinder_d.c"->findpath (origin, destination, ({}), ({}),({}), 5, 1, unknowns);
    report("The path from stage 1 has " + sizeof(temppath) + " steps");
    path += temppath;
    if (i<count) startroom = waystation_names[i];
  }
  return path;
}

string * query_waystations_en_route(string user, string startroom, string destroom){
  string mapname, roomname, * result;
  object destination;
  mapname = query_current_map(user);
  if (catch(destroom->query_short()))
  {
    report("Problem loading destroom: " + destroom + " in query_waystations_en_route");
    return ({});
  }
  destination = find_object_or_load(destroom);
  if (mapname == "none"){
    report("Problem with mapname being set to none in query_waystations_en_route");
    return ({});
  }
  report("%^BOLD%^%^WHITE%^About to set up waystations for mapname: " + mapname + " and destroom: " + destroom);
  setup_waystations(user, mapname, destroom, 10, 3);
  report("%^BOLD%^%^WHITE%^Waystations set up");
  roomname = startroom;
  result = ({});
  while(roomname != destroom && roomname != "none"){
    report ("%^BOLD%^%^MAGENTA%^Trying to find a waystation from " + roomname + " to " + destroom);
    roomname = find_waystation(user, mapname, roomname, destroom);
    if (roomname!= "none")
    {
      report("Yay, found a waystation at " + roomname);
      result += ({roomname});
    } else
    {
      report("No waystation found this time. What a downer");
    }
  }
//  result = result + ({destroom});
  return result;
}

string find_waystation(string user, string mapname, string startroom, string destroom){
  string * roomnames, * directions, * checked_rooms, *current_rooms, * next_rooms, room, result, *waystation_names, rep;
  mapping exits;
  int i, j, k, count, count2, waystage, l, count3;
  report ("%^BOLD%^%^YELLOW%^find_waystation: loading map. User: " + user +  " mapname: " + mapname);
  load_map(user, mapname);
  report("%^BOLD%^%^GREEN%^Map loaded - trying to find a waystation from " + startroom + " to " + destroom);
  if (!mapp(rooms) || sizeof(rooms)<1 || !mapp(waystations) || sizeof(waystations)<1){
    report("%^BOLD%^%^BLACK%^Ending early - problem with rooms or waystations");
    if (!mapp(rooms)) report("rooms is not a valid mapping");
    if( sizeof(rooms)<1) report("sizeof( rooms)<1");
    if (!mapp(waystations)) report("Problem is that waystations are not a valid mapping");
    if (sizeof(waystations)<1) report("problem is that sizeof( waystations)<1");
    return "none";
  }
  if (!mapp(waystations) || sizeof(waystations)<1) waystations = ([]);
  waystation_names = keys(waystations);
  roomnames = keys(rooms);

  waystage = 10000;
  result = "none";
  if (member_array(startroom, waystation_names)!=-1) waystage = waystations[startroom];
  if (member_array(startroom, roomnames)==-1) return "none";
  next_rooms = ({startroom});
  checked_rooms = ({});
  l = -1;
  for (i = 0; i<5;i++)
  {
    report("%^BOLD%^%^BLUE%^find_waystation stage: " + i);
    current_rooms = next_rooms;
    next_rooms = ({});
    count2 = sizeof(current_rooms);
    if (count2<1)
    {
      report("No more rooms to check at stage " + i + ". Aborting");
      break;
    }
    for (k=0;k<count2;k++)
    {
      report("Checking room " + current_rooms[k] + " to see if it's a waystation");
      exits = rooms[current_rooms[k]];
      if (!mapp(exits) || sizeof(exits)<1){
        report ("Room " + current_rooms[k] + " appears to have no exits. Attempting to fix that");
        exits = generate_new_exit_map(current_rooms[k]);
        if (!mapp(exits)|| sizeof(exits)<1)
        {
          report("Still no joy with the exit map. Moving on");
          continue;
        } else
        {
          save_room( user, mapname, current_rooms[k], exits);
          report("That's sorted. continuing");
        }
      }
      count = sizeof(exits);
      directions = keys(exits);
      for(j=0;j<count;j++)
      {
        room = exits[directions[j]];
        if (room == "unknown" || (sizeof(checked_rooms)>0 && member_array(room, checked_rooms)!=-1)) continue;
        next_rooms += ({room});
        if(member_array(room, waystation_names)!=-1)
        {
          report("Room " + room + " is a waystation, stage: " + waystations[room] + ". Current waystage is: " + waystage);
          if( waystations[room]<=waystage) {
            report("This waystation is closer than or as close as the existing waystage. Setting result to " + room);
            result = room;
            waystage = waystations[room];
          }
        }
      }
      checked_rooms += ({current_rooms[k]});
    }
  }
  return result;
}

string * findpath(string startname, string endname){
  object startroom, endroom;
  string * result, *nogorooms, * roomnames;
  if (!mapp(rooms) || sizeof(rooms)<1) return ({});
  roomnames = keys(rooms);
  if (member_array(startname, roomnames)==-1 || member_array(endname, roomnames) ==-1) return ({});
  if (catch(startname->query_short())||catch(endname->query_short())) return ({});
  startroom = find_object_or_load(startname);
  endroom = find_object_or_load(endname);
  nogorooms = query_unknowns();
  result = "/daemon/pathfinder_d"->findpath (startroom, endroom, ({}),({}), ({}), 5, 1, nogorooms);
}

string * query_unknowns(){
  string * roomnames, *directions, * result;
  int i, count, *locs, j, count2, loc;
  object room;
  mapping my_exits;
  result = ({});
  if (!mapp(locations) || sizeof(locations)<1) locations = ([]);
  locs = keys(locations);
  roomnames = keys(rooms);
  count = sizeof(roomnames);
  if (count<1 || sizeof(locs)<1) return ({});
  for(i=0;i<count;i++)
  {
    if (roomnames[i] == "unknown") continue;
    if (catch(roomnames[i]->query_short())) continue;
    room = find_object_or_load(roomnames[i]);
    directions = room->query_exits();
    count2 = sizeof(directions);
    if (count2<1) continue;
    for(j=0;j<count2;j++)
    {
      loc = get_new_location(query_location(roomnames[i]), directions[j]);
      if (member_array(loc, locs)==-1 || locations[loc] == "unknown")
      {
        result += ({room->query_exit(directions[j]) });
      }
    }
  }
  return result;
}

void add_exit(string roomname, string direction, string destination){
  mapping exits;
  string * roomnames;
  roomnames = ({});
  if (mapp(rooms)) roomnames = keys(rooms);
  if (sizeof(roomnames)>0 && member_array(roomname, roomnames)!= -1)
  {
    exits = rooms[roomname];
  } else
  {
    exits = generate_new_exit_map(roomname);
  }
  exits[direction] = destination;
  rooms[roomname] = exits;
}

string find_exit_direction(object start_room, object end_room){
  string * directions;
  int i, count;
  if (!objectp(start_room) || !objectp(end_room))
  {
     return "none";
  }
  directions = start_room->query_exits();
  count = sizeof(directions);
  if (count<1) return "none";
  for (i=0;i<count;i++)
  {
    report ("Checking " + directions[i]+ " exit from room " + base_name(start_room));
    if (start_room->query_exit(directions[i])==base_name(end_room))
    {
      report ("We have a match - it leads to " + base_name(end_room));
      return directions[i];
    }
    report ("No match - " + start_room->query_exit(directions[i]) + " != " + base_name(end_room));
  }
  return "none";
}

string get_map_name(string roomname){  // load maps for relevant user first
  string * mapnames, * roomnames;
  mixed* rooms_locs_tims;
  int i, count;
  mapping this_map;
  if (!mapp(maps) || sizeof(maps)<1) return "none";
  mapnames = keys(maps);
  count = sizeof(mapnames);
  for (i=0;i<count;i++)
  {
    report ("Checking for room " + roomname + " in map: " + mapnames[i]);
    rooms_locs_tims = maps[mapnames[i]];
    this_map = rooms_locs_tims[0];
    if (!mapp(this_map) || sizeof(this_map)<1) continue;
    roomnames = keys(this_map);
    if (sizeof (roomnames)>0 && member_array(roomname, roomnames)!=-1)
    {
      report ("Room found!!! in map " + mapnames[i]);
      return mapnames[i];
    }
    report ("Room not found");
  }
  return "none";
}

string get_next_map_name(object who){
  string * usernames, * mapnames, nm;
  int i, count, res, num, mapnum;
  if (!objectp(who)) return "ERROR";
  report("Getting next map name for : " + who->QCN);
  if (!mapp(users) || sizeof(users)<1) users = ([]);
  usernames = keys(users);
  nm = who->query_name();
  if (sizeof(usernames)< 1 || member_array(nm, usernames) ==-1)
  {
    report("Either no users found, or no users with the name " + nm);
    return nm + "1";
  }
  maps = users[nm];
  if (!mapp(maps)) return "ERROR";
  mapnames = keys(maps);
  count = sizeof(mapnames);
  if (count<1) return nm + "1";
  res = 1;
  for (i=0;i<count;i++)
  {
    if (interact(nm, mapnames[i]))
    {
      num = sscanf(mapnames[i], nm + "%d", mapnum);
      if (num>0)
      {
        if (mapnum>= res) res = mapnum +1;
      }
    }
  }
  return nm + res;
}

int get_new_location(int start_location, string direction){
  switch (direction)
  {
    case "north":
      return start_location + 1000;
      break;
    case "northeast":
      return start_location + 1001;
      break;
    case "east":
      return start_location + 1;
      break;
    case "southeast":
      return start_location - 999;
      break;
    case "south":
      return start_location - 1000;
      break;
    case "southwest":
      return start_location - 1001;
      break;
    case "west":
      return start_location - 1;
      break;
    case "northwest":
      return start_location + 999;
      break;
  }
  return -1;
}

string show_key(object who){
  string key;
  key = "MAGENTA%^KEY%^RESET%^\n"
   + "Rm - a room\n";
  key += "Up - a room with an 'up' exit\n"
   + "Dn - a room with a 'down' exit\n"
   + "UD - a room with both 'up' and 'down' exits\n"
   + "%^BOLD%^%^GREEN%^X %^RESET%^ - You are %^BOLD%^%^GREEN%^here%^RESET%^\n"
   + "%^BOLD%^%^BLUE%^* %^RESET%^ - A room with a nonstandard exit\n"
   + "%^BOLD%^%^BLACK%^XX%^RESET%^ - a %^BOLD%^%^BLACK%^broken%^RESET%^ room. Something is wrong here\n"
   + "%^BOLD%^%^RED%^XX%^RESET%^ - a %^BOLD%^%^RED%^CLASH%^RESET%^. More than one room appears to be at this location\n"
   + "%^MAGENTA%^ # %^RESET%^- a %^MAGENTA%^DUPLICATE%^RESET%^. This room seems to appear in more than one location on your map.\n"
   + "\\ | / - exits\n"
   + "%^BOLD%^%^RED%^\\ | / - %^RESET%^broken exits\n"
   + "%^BOLD%^%^MAGENTA%^\\ | / - %^RESET%^one way exits\n";
  return key;
}

mapping query_rooms(){
  return rooms;
}

mapping query_exits(string room){
  string * rms;
  if (!mapp(rooms) || sizeof(rooms) <1) rooms = ([]);
  rms = keys (rooms);
  if (sizeof(rms) <1 || member_array(room, rms)==-1)
  {
    return ([]);
  }
  return rooms[room];
}

string query_reporting(){
  return reporting;
}

void start_reporting(string whom){
  reporting = whom;
}

void stop_reporting(){
  reporting = "none";
}

void report(string str){

}

void trim(int screen_width){
  int * locs, trim, high_x, low_x, i, count, width, x;
  if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
  locs = keys(locations);
  count = sizeof(locs);
  if (count<1) return;
  high_x = high_x();
  low_x = low_x();
  width = screen_width / 4;
  if (width < high_x - low_x)
  {
    trim = 1+ (high_x - low_x - width) / 2 ;
    for (i=0;i<count;i++)
    {
      x = locs[i] % 1000;
      if (x < low_x + trim || x > high_x - trim)
      {
        m_delete(locations, locs[i]);
      }
    }
  }
}

int low_x(){
  int x, * locs, count, i;
  count = sizeof(locations);
  if (count<1) return -1;
  if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
  locs = keys(locations);
  x = 1000;
  for (i=0;i<count;i++){
    if (locs[i]%1000<x) x = locs[i]%1000;
  }
  return x;
}

int high_x(){
  int x, * locs, count, i;
  if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
  count = sizeof(locations);
  if (count<1) return -1;
  locs = keys(locations);
  x = 0;
  for (i=0;i<count;i++){
    if (locs[i]%1000>x) x = locs[i]%1000;
  }
  return x;
}

int low_y(){
  int y, * locs, count, i;
  if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
  count = sizeof(locations);
  if (count<1) return -1;
  locs = keys(locations);
  y = 1000;
  for (i=0;i<count;i++){
    if (locs[i]/1000<y) y = locs[i]/1000;
  }
  return y;
}

int high_y(){
  int y, * locs, count, i;
  if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
  count = sizeof(locations);
  if (count<1) return -1;
  locs = keys(locations);
  y = 0;
  for (i=0;i<count;i++){
    if (locs[i]/1000>y) y = locs[i]/1000;
  }
  return y;

}

string query_exit(string room, string direction){
  string * room_names;
  int count;
  if (!mapp(rooms) || sizeof(rooms) <1) rooms = ([]);
  room_names = keys(rooms);
  count = sizeof(room_names);
  if (count<1 || member_array(room, room_names)==-1)
  {
    return "none";
  }
  return rooms[room][direction];
}

int query_location(string room){
  string * rms;
  int * locs, i, count, len;
  if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
  rms = values(locations);
  locs = keys(locations);
  len  = strlen(room);
  if (room[len - 6.. len-1] ==  ".dupe") room = room[0..len-6];
  if (sizeof(rms)<1 ||  member_array(room, rms)==-1)
  {
    if (sizeof(rms)<1)
    {
      report ("No room locations recorded yet");
    } else
    {
      report ("Room " + room + " does not have a location recorded");
    }
    return -1;
  }
  count = sizeof(locs);
  for (i=count-1 ;i >= 0;i--)
  {
    if (locations[locs[i]] == room)
    {
      return locs[i];
    }
  }
  return -1;
}

void set_location(string room, int location){
  locations[location] = room;
}

string query_room(int location){
  int * locs;
  if (!mapp(locations) || sizeof(locations)<1) locations = ([]);
  locs = keys(locations);
  if (sizeof(locs) <1 || member_array(location, locs)==-1)
  {
    return "none";
  }
  return locations[location];
}
	mapping get_rooms_at_y(int  y){
  mapping result;
  int i, count,* locs;
  count = sizeof(locations);
  if (count<1) return ([]);
  locs = keys(locations);
  result = ([]);
  for (i=0;i<count;i++)
  {
    if (locs[i]/1000 != y) continue;
    result[locs[i]%1000] = locations[locs[i]];
  }

  return result;
}


int has_invis_exit(object room){
  string * exits;
  int i, count;
  if (!objectp(room)) return 0;
  exits = rooms->query_exits();
  count = sizeof(exits);
  if (count<1) return 0;
  for (i=0;i<count;i++)
  {
    if (room->invis_exit(exits[i])) return 1;
  }
  return 0;
}

int count_nonstandard_exits(string * exits){
  int num, count, i;
  count = sizeof(exits);
  if (count<1) return 0;
  num = count;
  for (i=0;i<count;i++)
  {
    if (exits[i]=="north" || exits[i]=="northeast" ||
        exits[i]=="east" || exits[i]=="southeast" ||
        exits[i]=="south" || exits[i]=="southwest" ||
        exits[i]=="west" || exits[i]=="northwest" ||
        exits[i]=="up" || exits[i]=="down" ) num --;
  }
  return num;
}

int eastmost_location_at_y(int y){
  int * locs, i, count, result;
  result = -1;
  if (!mapp(locations) || sizeof(locations)<1) return -1;
  locs = keys(locations);
  count = sizeof(locs);
  for(i=0;i<count;i++)
  {
    if (locs[i]/1000 != y) continue;
    if (locs[i] > result) result = locs[i];
  }
  return result;
}

string show_basic_map(object who){
  int high_x, low_x, high_y, low_y, i, count, j, count2, * locs, loc, flag, screen_width, len;
  string * rooms_at_y, line, roomname, top_line, bottom_line, * hidden_exits, dest , map, uncoloured_line, bottom_nos;
  object room, dest_room;
  high_x = high_x();
  low_x = low_x();
  high_y = high_y();
  low_y = low_y();
  map = "";
  screen_width = atoi(TP->getenv("SCREEN"));
  if (screen_width > 70) screen_width = 70;
  if (screen_width<1) screen_width = 70;
  if (screen_width<10) screen_width = 10;
  trim(screen_width);
  show_key(who);
  report ("About to show lines. Low_x: " + low_x + "  high_x: " + high_x + "  low_y: " + low_y + "  high_y: " + high_y);
  for (i = high_y; i>=low_y; i --)
  {
    report ("showing line " + i);
    line = "";
    top_line = "";
    if (i==low_y) bottom_line = " ";
    if (i==low_y) bottom_nos = " ";
    rooms_at_y = get_rooms_at_y(i);
    if (sizeof(rooms_at_y)<1)
    {
      report ("No rooms found at line y=" + i);
    }
    report ("Found some rooms");
    if (!mapp(locations) || sizeof(locations) <1) locations = ([]);
    locs = keys(locations);
    report ("About to run through rooms at line " + i);
    for (j=low_x;j<=high_x;j++)
    {
      loc = (i*1000) + j;
      if (i==low_y){
        switch(j%3)
        {
        case 0:
          bottom_nos += "%^YELLOW%^";
          break;
        case 1:
          bottom_nos += "%^BOLD%^%^RED%^";
          break;
        case 2:
          bottom_nos += "%^BOLD%^%^BLUE%^";
          break;
        }
      }
      bottom_nos = bottom_nos + j;
      if (j==low_x)
      {
        if(room_above_has_exit(loc, "southwest"))
        {
          report ("%^BOLD%^%^GREEN%^Adding stripe to top line");
          top_line += "/";
        } else
        {
          top_line += " ";
        }
        line += " ";
/*
        if (i==low_y && room_above_has_exit(loc-1000, "southwest"))
        {
          report ("%^BOLD%^%^MAGENTA%^Adding stripe to bottom line");
          bottom_line += "/";
          report("1: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
        } else
        {
          if (i==low_y) bottom_line += " ";
        }
*/
      }
//      top_line += "'";
//      line += "'";
//      if (i==low_y) bottom_line += "'";
      report ("Checkiing for room at location: " + loc);
      if (member_array(loc, locs)==-1)
      {
        report ("No room found at location " + loc);
        if (room_above_has_exit(loc-1, "southeast"))
        {
          top_line += "\\";
        } else {
          top_line += " ";
        }
        if (room_above_has_exit(loc, "south"))
        {
          top_line += "|";
        } else {
          top_line += " ";
        }
        if (room_above_has_exit(loc+1, "southwest"))
        {
          top_line += "/";
        } else {
          top_line += " ";
        }
        if(room_to_left_has_exit(loc, "east"))
        {
          line += "-  ";
        } else
        {
          line += "   ";
        }
        if (i==low_y) bottom_line +="   ";
        report ("2: %^ORANGE%^Bottom line is now: '" + bottom_line + "'");
        continue;
        //blah
      } else
      {
        report ("Room found at location " + loc + ". Testing for exit weirdness");
        roomname = locations[loc];
        if (interact(".dupe", roomname)){
          len = strlen(roomname);
          roomname = roomname[0..len-6];
        }
        if (catch(roomname->query_short())){
          report ("The original room is broken");
          line += " %^BOLD%^%^BLACK%^XX%^RESET%^";
          top_line += "   ";
          if (i==low_y)
          {
            bottom_line += "   ";
            report("3: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
          }
          continue;
        }
        report ("Room "+ roomname + " seems to be safe. Loading");
        room = find_object_or_load(roomname);
        report ("Room loaded");
        if ((room->query_exit("northwest")=="/d/shadowgate/void" ||room->invis_exit("northwest")) && !room_above_has_exit(loc-1, "southeast")){
          if (room->query_exit("northwest")=="/d/shadowgate/void"){
            report ("No northwest exit from " + roomname);
          } else {
            report ("There is a northwest exit from " + roomname);
          }
          if (room->invis_exit("northwest")){
            report ("Northwest exit from " + roomname + " is invisible");
          } else {
            report ("northwest exit from " + roomname + " is VISIBLE");
          }
          top_line += " ";
        } else
        {
          report ("There is a a northwest exit from " + base_name(room));
          dest = room->query_exit("northwest");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            top_line += "%^BOLD%^%^RED%^";
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("southeast") != roomname){
              top_line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          top_line += "\\%^RESET%^";
        }
        if ((room->query_exit("north")=="/d/shadowgate/void" || room->invis_exit("north")) && !room_above_has_exit(loc, "south")){
          if (room->query_exit("north")=="/d/shadowgate/void"){
            report ("No north exit from " + base_name(room));
          }
          if (room->invis_exit("north")){
            report ("North exit from " + base_name(room) + " is invisible");
          }
          top_line += " ";
        } else
        {
          report ("There is a a north exit from " + base_name(room));
          dest = room->query_exit("north");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            top_line += "%^BOLD%^%^RED%^";
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("south") != roomname){
              top_line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          top_line += "|%^RESET%^";
        }
        if ((room->query_exit("northeast")=="/d/shadowgate/void" || room->invis_exit("northeast")) && !room_above_has_exit(loc+1, "southwest")){
          if (room->query_exit("northeast")=="/d/shadowgate/void"){
            report ("No northeast exit from " + base_name(room));
          }
          if (room->invis_exit("northeast")){
            report ("Northeast exit from " + base_name(room) + " is invisible");
          }
          top_line += " ";
        } else
        {
          report ("There is a a northeast exit from " + base_name(room));
          dest = room->query_exit("northeast");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            top_line += "%^BOLD%^%^RED%^";
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("southwest") != roomname){
              top_line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          top_line += "/%^RESET%^";
        }
        if (room->query_exit("west")=="/d/shadowgate/void" && !room_to_left_has_exit(loc, "east")  /*|| room->invis_exit("west")*/)
        {
          if (room->query_exit("west")=="/d/shadowgate/void")
          {
            report ("No west exit from " + base_name(room));
          }
          if (room->invis_exit("west"))
          {
            report ("West exit from " + base_name(room) + " is invisible");
          }
          line += " "; //only need to do this if it is at the first line
        } else
        {
          report ("There is a west exit from " + base_name(room));
          dest = room->query_exit("west");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short()))
          {
            report ("The destination room is broken");
            top_line += "%^BOLD%^%^RED%^";
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("east") != roomname)
            {
              line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          line += "-%^RESET%^";
          if(j==low_x && !room_above_has_exit(loc, "southwest"))
          {
            top_line += " ";
          }
        }
        if (objectp(environment(who)) && room == environment(who))
        {
          line += "%^BOLD%^%^GREEN%^X %^RESET%^";
          continue;
        }
        flag = 0;
        if (flag ==0 && has_notation(base_name(room)))
        {
          flag = 1;
          line += query_notation(base_name(room))[0];
        }
        if (flag == 0 && sizeof(clashes)>0 && member_array(base_name(room), clashes)!=-1)
        {
          line += "%^BOLD%^%^RED%^XX%^RESET%^";
          flag = 1;
        }
        if (flag == 0 && sizeof(dupes)>0 && member_array(base_name(room), dupes)!=-1)
        {
          if (member_array(base_name(room), dupes)<10)
          {
            line += "%^MAGENTA%^ " + member_array(base_name(room), dupes)+ "%^RESET%^";
          } else
          {
            if (member_array(base_name(room), dupes)<100)
            {
              line += "%^MAGENTA%^" + member_array(base_name(room), dupes)+ "%^RESET%^";
            } else
            {
              line += "%^MAGENTA%^ #%^RESET%^";
            }
          }
          flag = 1;
        }
        if (detect_invis_exits == 1 && has_invis_exit(room))
        {
          line += "%^ORANGE%^* %^RESET%^";
          flag = 1;
        }
        if (flag ==0 && count_nonstandard_exits(room->query_exits())>0)
        {
          line += "%^BOLD%^%^BLUE%^* %^RESET%^";
          flag = 1;
        }
        if (flag < 1 && room->query_exit("up")!="/d/shadowgate/void"  && !room->invis_exit("up") )
        {
          if (room->query_exit("down")!="/d/shadowgate/void"  && !room->invis_exit("down") )
          {
            line += "%^ORANGE%^U%^MAGENTA%^D%^RESET%^";
            flag = 1;
          } else
          {
            line += "%^ORANGE%^Up%^RESET%^";
            flag = 1;
          }
        }
        if (flag ==0 && room->query_exit("down")!="/d/shadowgate/void" && !room->invis_exit("down")  )
        {
          line += "%^MAGENTA%^Dn%^RESET%^";
          flag = 1;
        }
        if (flag ==0)
        {
          line += "Rm";
        }
      }
      line += "%^RESET%^";
      if (i == low_y)
      {
        if (room->query_exit("southwest")=="/d/shadowgate/void" || room->invis_exit("southwest")){
          if (room->query_exit("southwest")=="/d/shadowgate/void"){
            report ("No southwest exit from " + base_name(room));
          }
          if (room->invis_exit("southwest")){
            report ("Southwest exit from " + base_name(room) + " is invisible");
          }
          bottom_line += " ";
          report("4: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
        } else
        {
          report ("There is a a southwest exit from " + base_name(room));
          dest = room->query_exit("southwest");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            bottom_line += "%^BOLD%^%^RED%^";
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("northeast") != roomname){
              bottom_line += "%^BOLD%^%^MAGENTA%^";
              report("5: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
            }
          }
          bottom_line += "/%^RESET%^";
          report("6: %^ORANGE%^Bottom line is now '" + bottom_line + "'");        }
        if (room->query_exit("south")=="/d/shadowgate/void" || room->invis_exit("south")){
          if (room->query_exit("south")=="/d/shadowgate/void"){
            report ("No south exit from " + base_name(room));
          }
          if (room->invis_exit("south")){
            report ("South exit from " + base_name(room) + " is invisible");
          }
          bottom_line += " ";
          report("7: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
        } else
        {
          report ("There is a a south exit from " + base_name(room));
          dest = room->query_exit("south");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            bottom_line += "%^BOLD%^%^RED%^";
            report("8: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("north") != roomname){
              bottom_line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          report("Adding a south exit to the bottom line");
          bottom_line += "|%^RESET%^";
          report("9: %^ORANGE%^bottom line is now: '" + bottom_line + "'");
        }
        if (room->query_exit("southeast")=="/d/shadowgate/void" || room->invis_exit("southeast"))
        {
          bottom_line += " ";
          report("10: %^ORANGE%^bottom line is now: '" + bottom_line + "'");
        } else
        {
          report ("There is a a southeast exit from " + base_name(room));
          dest = room->query_exit("southeast");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            bottom_line += "%^BOLD%^%^RED%^";
            report("11: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
          } else
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("northwest") != roomname){
              bottom_line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          bottom_line += "\\%^RESET%^";
            report("12: %^ORANGE%^Bottom line is now '" + bottom_line + "'");
        }
      }
    }
    map += top_line + "\n";
    map += line + "\n";
    if (i==low_y)
    {
      report ("%^ORANGE%^Bottom line is: <" + bottom_line + ">");
      map += bottom_line + "\n";
    }
  }
  if (who->query_name() == reporting)
  {
    map += bottom_nos + "\n";
  }
  return map;
}



int room_to_left_has_exit(int this_location, string direction){
  int loc, * locs;
  string roomname, * exits, * roomnames;
  mapping exitmap;
  loc = this_location -1;
  if (!mapp(locations) || sizeof(locations)<1) return 0;
  locs = keys(locations);
  if (member_array(loc, locs)==-1) return 0;
  roomname = locations[loc];
  if (!mapp(rooms) || sizeof(rooms)<1) return 0;
  roomnames = keys(rooms);
  if (member_array(roomname, roomnames)==-1) return 0;
  exitmap = rooms[roomname];
  if (!mapp(exitmap) || sizeof(exitmap)<1) return 0;
  exits = keys(exitmap);
  if (member_array(direction, exits)==-1) return 0;
  return 1;
}

int room_to_right_has_exit(int this_location, string direction){
  int loc, * locs;
  string roomname, * exits, * roomnames;
  mapping exitmap;
  loc = this_location +1;
  if (!mapp(locations) || sizeof(locations)<1) return 0;
  locs = keys(locations);
  if (member_array(loc, locs)==-1) return 0;
  roomname = locations[loc];
  if (!mapp(rooms) || sizeof(rooms)<1) return 0;
  roomnames = keys(rooms);
  if (member_array(roomname, roomnames)==-1) return 0;
  exitmap = rooms[roomname];
  if (!mapp(exitmap) || sizeof(exitmap)<1) return 0;
  exits = keys(exitmap);
  if (member_array(direction, exits)==-1) return 0;
  return 1;
}



int room_above_has_exit(int this_location, string direction){
  int loc, * locs;
  string roomname, * exits, * roomnames;
  mapping exitmap;
  loc = this_location + 1000;
  if (!mapp(locations) || sizeof(locations)<1) return 0;
  locs = keys(locations);
  if (member_array(loc, locs)==-1) return 0;
  roomname = locations[loc];
  if (!mapp(rooms) || sizeof(rooms)<1) return 0;
  roomnames = keys(rooms);
  if (member_array(roomname, roomnames)==-1) return 0;
  exitmap = rooms[roomname];
  if (!mapp(exitmap) || sizeof(exitmap)<1) return 0;
  exits = keys(exitmap);
  if (member_array(direction, exits)==-1) return 0;
  return 1;
}
