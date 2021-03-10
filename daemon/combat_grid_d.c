// combat_grid_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>
#include "/daemon/combat_grid/combat_grid.h"
#define SAVE_FILE "/daemon/save/ombat_grid" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "combat_grid_log"

inherit DAEMON;

void setup_room_icons();

mapping CRITTER_LOCATIONS; //[int x][int y][object critter]
mapping CRITTER_FACINGS; // [object critter][int facing]
mapping OBJECT_LOCATIONS; //[int x][int y][object ob]
mapping ROOM_LAYOUT; //[int x][int y][int background_code]
mapping ROOM_ICONS_SMALL; // [int i][string str] - uses defines in combat_grid.h
string reporter;

void create(){
  ::create();
  CRITTER_LOCATIONS = ([]);
  CRITTER_FACINGS = ([]);
  OBJECT_LOCATIONS = ([]);
  ROOM_LAYOUT = ([]);
  ROOM_ICONS_SMALL = ([]);
  setup_room_icons();
}

string * generate_display (object who){
  string * display, line, char;
  int x,y;
  object ob;
}

void start_reporting(string rep){
  reporter = rep;
}

void stop_reporting(){
  reporter = "";
}

void report(string str){
  if (!stringp(str) || !stringp(reporter) || str == "" || reporter == "") return;
  "/daemon/reporter_d"->report(reporter, str);
}

object * query_critters_at_location(int x, int y){
  int * xs, * ys;
  mapping x_y;
  object * occupants;
  if (!mapp(CRITTER_LOCATIONS) || sizeof(CRITTER_LOCATIONS)<1)
  {
    report("Locations not valid when checking for critters at location " + x + ", " + y);
    return ({});
  }
  xs = keys(CRITTER_LOCATIONS);
  if (member_array(x, xs)==-1)
  {
    report("No critters found at location " + x + ", " + y);
    return ({});
  }
  x_y = CRITTER_LOCATIONS[x];
  if (!mapp(x_y) || sizeof(x_y)<1)
  {
    report("x_y not valid when checking for critters at location " + x + ", " + y);
    return ({});
  }
  ys = keys(x_y);
  if (member_array(y, ys)==-1)
  {
    report("No critters found at location " + x + ", " + y);
    return ({});
  }
  occupants = CRITTER_LOCATIONS[x][y];
  return occupants;
}



int query_critter_x (object critter){
  int * xs,* ys, i, j;
  mapping x_y;
  if (!mapp(CRITTER_LOCATIONS))
  {
    report("Error in query_critter_x: CRITTER_LOCATIONS not valid");
    return -1;
  }
  xs = keys(CRITTER_LOCATIONS);
  if (sizeof(xs)<1)
  {
    report("Error in query_critter_x: sizeof(xs)<1");
    return -2;  
  }
  foreach(i in xs)
  {
    x_y = CRITTER_LOCATIONS[j];
    if (!mapp(x_y)|| sizeof(x_y)<1)
    {
      report("Error in query_critter_x: x_y not valid. i = " + i);
      continue; 
    }
    ys = keys(x_y);
    foreach(j in ys)
    {
      if (x_y[j]==critter) return i;
    }
  }
  report("Critter not found in query_critter_x");
  return -2;
}

int query_critter_y (object critter){
  int * xs,* ys, i, j;
  mapping x_y;
  if (!mapp(CRITTER_LOCATIONS))
  {
    report("Error in query_critter_x: CRITTER_LOCATIONS not valid");
    return -1;
  }
  xs = keys(CRITTER_LOCATIONS);
  if (sizeof(xs)<1)
  {
    report("Error in query_critter_x: sizeof(xs)<1");
    return -2;  
  }
  foreach(i in xs)
  {
    x_y = CRITTER_LOCATIONS[i];
    if (!mapp(x_y)|| sizeof(x_y)<1)
    {
      report("Error in query_critter_x: x_y not valid. i = " + i);
      continue; 
    }
    ys = keys(x_y);
    foreach(j in ys)
    {
      if (x_y[j]==critter) return j;
    }
  }
  report("Critter not found in query_critter_x");
  return -2;
}

int query_critter_facing(object critter){
  object * critters;
  if (!objectp(critter))
  {
    report("Error in query_critter_facing: critter is not valid");
  }
  if (!mapp(CRITTER_FACINGS) || sizeof(CRITTER_FACINGS)<1)
  {
    report ("Error in query_critter_facing: CRITTER_FACINGS is not valid");
    return -1; 
  }
  critters = keys(CRITTER_FACINGS);
  if (member_array(critter, critters) ==-1)
  {
    report("Error in query_critter_facing: critter not found");
    return -1;
  }
  return CRITTER_FACINGS[critter];
}

int set_critter_facing(object critter, int facing){
  if (!mapp(CRITTER_FACINGS)) CRITTER_FACINGS = ([]);
  CRITTER_FACINGS[critter] = facing;
  return 1;
}

int set_critter_location(object critter, int x, int y, int facing){
  object * occupants;
  if (!objectp(critter) || !intp(x) || !intp(y)) return -1;
  occupants = query_critters_at_location(x,y);
  occupants = occupants + ({critter});  
  CRITTER_LOCATIONS[x][y] = occupants;
  if (!intp(facing))
  {
    CRITTER_FACINGS[critter] = NORTH;
    return -2;
  }
  CRITTER_FACINGS[critter] = facing;
  if (facing <1 || facing >8)
  {
    report("place_critter error: facing = " + facing);
  }
  return 1;
}

object * identify_threats_to_location(int x, int y)
{
  int i, j, temp_x, temp_y, * locations, location, k;
  object * threats, * occupants;
  threats = ({});
  for (k = 1;k < 4; k++)
  {
    locations = surrounding_rooms(x, y, k);
    foreach(location in locations)
    {
      occupants = query_critters_at_location(location/1000, location % 1000);
    }
  }
}

int * surrounding_rooms(int temp_x, int temp_y, int distance){
  int * results, i, j;
  results = ({});
  for (i= temp_x - distance; i<= temp_x + distance;i++)
  {
    for (j = temp_y-distance; j<= temp_y + distance; j++)
    {
      if (i==temp_x || j==temp_y) continue;
      if (i==temp_x-distance || i==temp_x+ distance|| j==temp_y-distance || j == temp_y+distance)
      { 
        results += ({temp_x * 1000 + temp_y});
      }
    }
  }
  return results;
}

int check_reach(object ob){
  int reach, size;
  object wpn, * wpns;
  if (!objectp(ob) || !living(ob)) return -1;
  reach = ob->query_size()-1;
  wpns = ob->query_wielded();
  if (sizeof(wpns)>0)
  {
    size = 0;
    foreach(wpn in wpns)
    {
      if (size< wpn->query_size()-2)
      {
        size = wpn->query_size()-2;
      }
    }
    reach += size;
  }
  return reach;
}


void setup_room_icons(){
 ROOM_ICONS_SMALL[WALL_NS] = "|"; 
 ROOM_ICONS_SMALL[WALL_EW] = "-";
 ROOM_ICONS_SMALL[WALL_NESW] = "\\";
 ROOM_ICONS_SMALL[WALL_NWSE] = "/"; 
 ROOM_ICONS_SMALL[DOOR] = "D";
}
