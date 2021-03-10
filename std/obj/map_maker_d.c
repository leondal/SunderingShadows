#include <std.h>
inherit OBJECT;

mapping rooms; // ([ string filename : mapping exits ])
mapping locations; // ([ int location : string filename ])
string reporting, * out_of_bounds_rooms, working_message, start_message, end_message;
int detect_invis_exits;

void create(){
  ::create();
  set_id(({"map maker", "device", "mapper", "mapping device"}) );
  set_short("A mapping device");
  set_long("A wacky mapping device, made by that crazy Draconian Lujke");
  set_weight(1);
  setup();
  detect_invis_exits = 0;
}
 
void init(){
  ::init();
  add_action("map_me", "trace");
  add_action("report_me", "rep");
  reporting = "none";
}



void setup(){
  report ("Doing setup");
  rooms = ([]);
  locations = ([]);
  out_of_bounds_rooms = ({});
}

void start_detecting_invis(){
  detect_invis_exits = 1;
}

void stop_detecting_invis(){
  detect_invis_exits = 0;
}

mapping query_rooms(){
  return rooms;
}

mapping query_exits(string room){
  string * rms;
  rms = keys (rooms);
  if (sizeof(rms) <1 || member_array(room, rms)==-1)
  {
    return ([]);
  }
  return rooms[room];
}

void start_reporting(string whom){
  reporting = whom;
}

void stop_reporting(){
  reporting = "none";
}

void set_exits(string room, mapping exits){
  rooms[room] =  exits;
  setup_exit_locations(room);
}

int report_me(string str){
  if (!TP->query_true_invis())
  {
    return notify_fail("Only invisible imms can use this function");
  }
  if (ETO != TP)
  {
    return notify_fail("You have to be holding the mapper to set it to report");
  }
  if (reporting != TP->query_name())
  {
    reporting = TP->query_name();
    tell_object(TP, "You tell the device to start reporting");
  }  else 
  {
    reporting = "none";
    tell_object(TP, "You tell the device to stop reporting");
  }
  return 1;
}

int query_location(string room){
  string * rms;
  int * locs, i, count;
  rms = values(locations);
  locs = keys(locations);
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
  for (i=0;i<count;i++)
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
  locs = keys(locations);
  if (sizeof(locs) <1 || member_array(location, locs)==-1)
  {
    return "none";
  }
  return locations[location];
}

void report(string str){
  if (reporting == "none") return;
  "/daemon/reporter_d.c"->report(reporting, str);
}


varargs void setup_exit_locations(string room){
  int start_location, i , count, dest_loc;
  mapping exits;
  string * directions, * rms, dest_room;
  report ("Setting up locations for " + room);
  rms  = keys (rooms);
  if (sizeof(rms)<1)
  {
    report("Error - no rooms in rooms mapping when trying to setup exit locations");
    return;
  }
  if (member_array(room, rms)==-1)
  {
    report("Error - queried room ("+ room + ") is not in rooms mapping when trying to setup exit locations");
    return;
  }
  exits = rooms[room];
  directions = keys(exits);
  count = sizeof(exits);
  if (count<1)
  {
    report("No exits found for room " + room + " when trying to setup exit locations");
    return;
  }
  start_location = query_location(room);
  if (start_location == -1)
  {
    report ("Error - room " + room + " has no location when trying to setup exit locations");
    return;
  }  
  for (i=0;i<count;i++){
    dest_room = exits[directions[i]];
    dest_loc = get_new_location(start_location, directions[i]);
    if (dest_loc<1)
    {
      if (member_array(dest_room, out_of_bounds_rooms) ==-1)
      {
        out_of_bounds_rooms += ({dest_room});
      }
      continue;     
    }
    set_location(dest_room, dest_loc); 
  }
  report ("Finished setting up locations");
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

varargs string * setup_exits(string room_name, string * broken_rooms){
  int i, count;
  mapping exits;
  string * directions;
  object room;
  report ("Setting up exits for " + room_name);
  if (!arrayp(broken_rooms))
  {
    broken_rooms = ({});
  }
  if (catch(room_name->short_desc()))
  {
    report("Found broken room: " + room_name);
    broken_rooms += ({room_name});
    return broken_rooms;
  }
  room = find_object_or_load(room_name);
  directions =  room->query_exits();
  count = sizeof(directions);
  if (count<1) return broken_rooms;
  exits = ([]);
  for (i=0;i<count;i++){
    report("Setting exit : " + directions[i] + " to destination " +  room->query_exit(directions[i]));
    exits[directions[i]] = room->query_exit(directions[i]);
  }  
  rooms[room_name] = exits;
  report ("Finished setting up exits");
  return broken_rooms;
}

void map_next_step(string * next_rooms, string * mapped_rooms, string * broken_rooms, int stage, int max_stage, int delay)
{
  int i, j, count, count2;
  string * temp_next_rooms, * directions, dest_room;
  object * room;
  report ("Mapping stage " + stage);
  if (!arrayp(next_rooms)) return;
  count = sizeof(next_rooms);
  if (count<1) return;
  if (!arrayp(broken_rooms)) broken_rooms = ({});
  if (!arrayp(mapped_rooms)) mapped_rooms = ({});
  if (!intp(delay)) delay = 2;
  temp_next_rooms = ({});
  if (stringp(working_message) && userp(ETO))
  {
    tell_object(ETO, working_message);
  }
  for (i=0;i<count;i++)
  {
    if (member_array(next_rooms[i], mapped_rooms)!= -1) continue;
    broken_rooms = setup_exits(next_rooms[i], broken_rooms);
    setup_exit_locations(next_rooms[i]);
    mapped_rooms += ({next_rooms[i]});
    if (catch(next_rooms[i]->query_short()))
    {
      broken_rooms += ({broken_rooms[i]});
      continue;
    }
    room = find_object_or_load(next_rooms[i]);
    directions = room->query_exits();
    count2 = sizeof(directions);
    if (count2>0)
    {
      for (j=0;j<count2;j++)
      {
        dest_room = room->query_exit(directions[j]);

        if (member_array(dest_room, mapped_rooms)==-1 && member_array(dest_room, broken_rooms) ==-1)
        {
          temp_next_rooms += ({dest_room});
        } 
      }
    }
  }
  stage ++;
//  if (delay < stage) delay = stage;
  if (stage < max_stage)
  {
    report ("calling out stage " + stage + ", with a delay of " + delay);
    call_out("map_next_step", delay, temp_next_rooms, mapped_rooms, broken_rooms, stage, max_stage, delay);
  } else
  {
    if (userp(ETO) && stringp(end_message))
    {
      tell_object(ETO, end_message);
    }
  }
}

void set_start_message (string msg){
  start_message = msg;
}

void set_working_message(string msg){
  working_message = msg;
}

string query_start_message(){
  return start_message;
}

string query_working_message(){
  return working_message;
}

void set_end_message(string msg){
  end_message = msg;
}

string query_end_message(){
  return end_message;
}


int map_me(string str){
  string * next_rooms, * mapped_rooms, * broken_rooms;
  int stage, max_stage, delay;
  if (!objectp(ETO)){
    report ("Can't map - environment broken");
  }
  if (!objectp(EETO) || !userp(ETO)){
    return notify_fail("You have to be holding the mapper for it to work");
  }
  if (!stringp(str)) str = "0";
  max_stage = atoi(str);
  if (max_stage <1)
  {
    tell_object(TP, "Use <map #> to specify how many stages to map. Defaulting to 1 stage");
    max_stage = 1;
  }
  setup();
  next_rooms = ({base_name(EETO)});
  mapped_rooms = ({});
  broken_rooms = ({});
  report("Starting mapping from " + base_name(EETO));
  set_location(base_name(EETO), 1000500);
  if (stringp(start_message) && userp(ETO))
  {
    tell_object(ETO, start_message);
  }
  map_next_step(next_rooms, mapped_rooms, broken_rooms, 1, max_stage, 2);
  return 1;
}

mapping query_locations(){
  return locations;
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

void trim(int screen_width){
  int * locs, trim, high_x, low_x, i, count, width, x;
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
  locs = keys(locations);
  x = 1000;
  for (i=0;i<count;i++){
    if (locs[i]%1000<x) x = locs[i]%1000;
  }
  return x;
}

int high_x(){
  int x, * locs, count, i;
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
  room_names = keys(rooms);
  count = sizeof(room_names);
  if (count<1 || member_array(room, room_names)==-1)
  {
    return "none";
  }
  return rooms[room][direction];
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

string show_basic_map(object who){
  int high_x, low_x, high_y, low_y, i, count, j, count2, * locs, loc, flag, screen_width;
  string * rooms_at_y, line, roomname, top_line, * hidden_exits, dest , map;
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
  for (i = high_y; i>low_y; i --)
  {
    report ("showing line " + i);
    rooms_at_y = get_rooms_at_y(i);
    if (sizeof(rooms_at_y)<1)
    {
      report ("No rooms found at line y=" + i);
    }
    report ("Found some rooms");
    line = "";
    top_line = "";
    locs = keys(locations);
    report ("About to run through rooms at line " + i);
    for (j=low_x;j<high_x;j++)
    {
      loc = (i*1000) + j;
      report ("Checkiing for room at location: " + loc);
      if (member_array(loc, locs)==-1)
      {
        report ("No room found at location " + loc);
        line += "   ";
        top_line += "   ";
      } else
      {
        report ("Room found at location " + loc + ". Testing for exit weirdness");
        roomname = locations[loc];
        if (catch(roomname->query_short())){
          report ("The original room is broken");
          line += " %^BOLD%^%^BLACK%^XX%^RESET%^";
          top_line += "   ";
          continue;
        }
        report ("Room "+ roomname + " seems to be safe. Loading");
        room = find_object_or_load(roomname);
        report ("Room loaded");
        if (room->query_exit("northwest")=="/d/shadowgate/void" ||room->invis_exit("northwest")){
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
        if (room->query_exit("north")=="/d/shadowgate/void" || room->invis_exit("north")){
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
        if (room->query_exit("northeast")=="/d/shadowgate/void" || room->invis_exit("north")){
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
        if (room->query_exit("west")=="/d/shadowgate/void" || room->invis_exit("west")){
          if (room->query_exit("west")=="/d/shadowgate/void"){
            report ("No west exit from " + base_name(room)); 
          }
          if (room->invis_exit("west")){
            report ("West exit from " + base_name(room) + " is invisible"); 
          }
          line += " ";
        } else
        {
          report ("There is a west exit from " + base_name(room)); 
          dest = room->query_exit("west");
          report ("Testing for return exit weirdness");
          if (catch(dest->query_short())){
            report ("The destination room is broken");
            top_line += "%^BOLD%^%^RED%^";
          } else 
          {
            report ("The destination room is fine");
            dest_room = find_object_or_load(dest);
            if (dest_room->query_exit("east") != roomname){
              line += "%^BOLD%^%^MAGENTA%^";
            }
          }
          line += "-%^RESET%^";
        }
        if (objectp(EETO) && room == EETO)
        {
          line += "%^BOLD%^%^GREEN%^X %^RESET%^";
          continue;
        }
        flag = 0;
        if (detect_invis_exits == 1 && has_invis_exit(room))
        {
          line += "%^ORANGE%^* ";
          flag = 1;
        } 
        if (flag ==0 && count_nonstandard_exits(room->query_exits())>0){
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
        line += "%^RESET%^";
      }
    }
    map += top_line + "\n";
    map += line + "\n";
//    tell_object(who, top_line);
//    tell_object(who, line);
  }
  return map;
}

int has_invis_exit(object room){
  string * exits;
  int i, count;
  if (!objectp(room)) return 0;
  exits = room->query_exits();
  count = sizeof(exits);
  if (count<1) return 0;
  for (i=0;i<count;i++)
  {
    if (room->invis_exit(exits[i])) return 1;
  }
  return 0;
}

int detect_invis(string str){
  if (!TP->query_true_invis())
  {
    return notify_fail("Only invisible imms can use this function");
  }
  if (ETO != TP)
  {
    return notify_fail("You have to be holding the mapper to set it to detect invisible exits");
  }
  if(detect_invis_exits)
  {
    detect_invis_exits = 0;
    tell_object(TP, "You stop the mapper detecting invisible exits");
    return 1;
  } else 
  {
    detect_invis_exits = 1;
    tell_object(TP, "You set the mapper to detect invisible exits");
    return 1;
  }
}

string show_key(object who){
  string key;
  key = "%^MAGENTA%^KEY%^RESET%^\n"
   + "Rm - a room\n"
   + "%^BOLD%^%^GREEN%^X %^RESET%^ - You are %^BOLD%^%^GREEN%^here%^RESET%^\n";
  if (detect_invis_exits > 0){
    key += "%^ORANGE%^* %^RESET%^ - a room with one or more invisible exits\n";
  }
  key += "%^BOLD%^%^BLUE%^* %^RESET%^ - a room with one or more nonstandard exits\n" 
   + "%^ORANGE%^Up%^RESET%^ - a room with an 'up' exit\n"
   + "%^MAGENTA%^Dn%^RESET%^ - a room with a 'down' exit\n"
   + "%^ORANGE%^U%^MAGENTA%^D%^RESET%^ - a room with both 'up' and 'down' exits\n"
   + "%^BOLD%^%^BLACK%^XX%^RESET%^ - a %^BOLD%^%^BLACK%^broken%^RESET%^ room. Something is wrong here\n"
   + "\\ | / - exits\n"
   + "%^BOLD%^%^RED%^\\ | / - %^RESET%^broken exits\n"
   + "%^BOLD%^%^MAGENTA%^\\ | / - %^RESET%^one way exits\n";
  return key;
}
