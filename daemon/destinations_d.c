// destinations_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke, based on code plundered from Ares
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>
#define PATHFINDER "/daemon/pathfinder_d.c"
#define SAVE_FILE "/daemon/save/destinations"
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "destinations_log"

/* This daemon generates and stores 'waystation' information for named 'destinations'. The concept is that for each named 'destination', the daemon remembers a number of 'waystations', which are rooms radiating outwards from the destination, no more than 5 steps apart. For each 'waystation', the daemon also remembers how many 'stages' (sets of approximatly 5 steps) away from the final destination it is.

The waystations are used in conjunction with some new code in monster.c to allow mobs to find their way from where they are, to a named destination. Note that this only works if the mob starts from within 5 steps of a room which has a 'waystation' setting for the named destination.

To set up a room to be a destination, there are a number of options. You can manually work out all the rooms that you want to have waystations, and what stages they need to be at. (You will need to have mapped out the area in order to work this out). You can then manually add those waystation settings to your destination room in the room's create function:

#define DEST "/daemon/destinations_d.c"

void create(){
  ::create();
  ... BLAH...
  DEST->add_waystation(string <destination_room>, <destination_room>, 1);
  DEST->add_waystation(string <destination_room>, <room1>, 2);
  DEST->add_waystation(string <destination_room>, <room2>, 2);
  DEST->add_waystation(string <destination_room>, <room3>, 3);
  DEST->add_waystation(string <destination_room>, <room4>, 3);
  ... etc
}

OR, you can use the automatic waystation generator:

#define DEST "/daemon/destinations_d.c"

void create(){
  object * rooms;
  ::create();
  ... BLAH...
  DEST->generate_waystations(file_name(TO),2, 3);
  // this would generate 2 stages of waystations radiating from the
  // current room.  Each waystation would be 3 stages further away than
  // the last. NOTE: the code to generate waystations can get
  // quite processor intensive and cause lag pockets if you set
  // the 'stages' or 'spacing' too high. It's recommended to manually
  // enter the stages as above, if spacing *stages would be higher than
  // about 15.
  // However, you can use the 'generate waystations' function as a one-off
  // and make a note of which rooms it sets waystations in, to save you
  // the bother of mapping it all out. The code is not perfect though,
  // and will not necessarily set you the 'best' or shortest routes for
  // mobs to follow, so manually mapping it is still preferable.
  // Another possibility is to manually map in a few 'key' waystations
  // (eg along a main path that you want mobs to follow), and then
  // use the 'generate waystations' function to work out all the
  // more fiddly 'fill in' waystation rooms.

}
Coded by Lujke, September 2005, with daemon and SAVE code stolen from Ares
*/

inherit DAEMON;

  mapping __destinations, __timings; //__destinations holds the list of waystations
//__timings holds a list of times when the waystations for each destination were set

void save_data();


void create(){
  ::create();
  __destinations = ([]);
  __timings = ([]);
    seteuid(UID_DAEMONSAVE);
// restore_object(SAVE_FILE,1);
    seteuid(getuid());
}

void clean_up() {
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return;
}

void report(string str){

}


void add_waystation(string destination, string room, int stage){
  /* add_waytstation adds a waystation for a named room and a named
     destination. It takes three arguments:

  string destination - the filename of the destination room, without a
                       ".c" at the end, exactly as returned by
                       file_name(room)
  string room        - the filename of the room that the waystation is to
                       be added to, same format as above.
  int stage          - the 'stage' number of the waystation (ie how many
                       stages of five steps this waystation is from the
                       destination. Note that the destination room must
                       always be set to stage '1', the waystations that
                       are five 'steps' away from it are stage '2', those
                       that are ten 'steps' away are stage '3', etc.
  */

  mapping __waystations = ([]);

  if (__destinations[destination] ==0){
    __destinations += ([destination : __waystations]);
  } else{
    __waystations = __destinations[destination];
  }
  if (__waystations[room]==0){
    __waystations += ([room: stage]);
  }
  __timings[destination] = time();
  save_data();
}

void save_data(){
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

mapping query_timings(){
  if (sizeof(__timings)<1){
    return ([]);
  }
  return __timings;
}

mapping query_destinations(){
  if (sizeof(__destinations)<1){
    return ([]);
  }
  return __destinations;
}

int query_waystation(string destination, string room){
  /* returns the 'stage' number for the room named, in respect of the
     destination named. Takes two arguments:

  string destination  - the filename of the destination room, without a
                        ".c" at the end.
  string room         - the filename of the room to be queried, without a
                        ".c" at the end.
 NOTE: returns '0' if no waystation is set for this room in respect of the
 named destination   */

  mapping __waystations;
  string * dests, * stations;
  __waystations = ([]);

  if (sizeof(__destinations)<1 ){
    return 0;
  }
  dests = keys(__destinations);
  if (member_array(destination, dests)==-1){
    return 0;
  }
  __waystations = __destinations[destination];
  if (sizeof(__waystations)<1){
    return 0;
  }
  stations = keys(__waystations);
  if (member_array(room, stations)==-1){
    return 0;
  }
  return __waystations[room];
}

mapping query_waystations(string destination){
  string * dests;
  /* Returns a mapping of all waystations set for the named destination*/
  if (sizeof(__destinations)<1){
    report ("No destinations recorded");
    return ([]);
  }
  dests = keys(__destinations);
  if (sizeof(dests)<1 || member_array(destination, dests)==-1){
    report ("No destinations recorded for " + destination);
    return ([]);
  }
  return __destinations[destination];
}


varargs object * add_waystations(object * rooms, object room, string destination, int stage, int spacing, string * nogo){
  // looks for all the rooms that are a set number of steps from the
  // current room, and adds a waypoint for each of them, with the stage
  // number passed. The number of steps is set by the 'spacing' variable.
  // Note: NEVER set a stage number less than 1. 1 should be the number
  // for the final destination. All others should go higher as the
  // waystations get farther from the destination.

  object * pot_waystations, temproom, near_waystation;

  string * exits;
  int count, prevcount, i, j, k;
  report("%^CYAN%^Starting add_waystations");
  if (!nogo){
    nogo = ({});
  }
  if(!objectp(room)){
    return pot_waystations;
  }
  if (!arrayp(rooms)) rooms = ({});
  if (member_array(room, rooms)==-1){
    rooms += ({room});
  }
  pot_waystations = ({});

  exits = ({});

  prevcount = 0;
  count = 1;

  report("About to cycle through spaces");
  for (i=0;i<spacing;i++){
    report ("%^CYAN%^Stage " + i);
    if (count-prevcount<1){
    // This means that no extra rooms were added in the last iteration,
    // so the loop ceases
      report("Count: " + count + " Prevcount: " + prevcount + " Therefore ending");
      break;
    }
    report ("About to cycle through all the rooms added on the last iteration");
    //cycle through all the rooms added on the last iteration
    for (j=prevcount;j<count;j++){
      report ("j: " + j);
      exits = rooms[j]->query_exits();
      if (sizeof(exits)>0){
        report ("There are some exits in this room. Cycling through them");
        // cycle through all the exits of the current room
        for (k=0;k<sizeof(exits);k++){
          report("%^CYAN%^     K: " + k);
          //check each exit to see if it leads to a valid new room,
          // which does not already exist in the rooms array.
          if (file_exists(rooms[j]->query_exit(exits[k])+".c")){
            if (sizeof(nogo) == 0 || member_array (rooms[j]->query_exit(exits[k]), nogo) ==-1){
              if (!catch(rooms[j]->query_exit(exits[k])->query_short()))
              {
                temproom =find_object_or_load(rooms[j]->query_exit(exits[k]));
              } else
              {
                report ("Problem loading room: " + rooms[j]);
              }
              if (objectp(temproom)){
                if (member_array(temproom, rooms, 0)==-1){
                  rooms += ({temproom});
                }
              } else
              {
                report ("%^BOLD%^%^GREEN%^WEIRD%^RESET%^ Problem loading room: " + rooms[j]);
              }
            }
          }
        }
      }
    }
    prevcount = count;
    count = sizeof(rooms);
    report("Finished cycle. On to next... Prevcount: " + prevcount + " Count: " + count );
  }

  // After a number of iterations equal to the 'spacing' argument, the
  // rooms that are precisely that many steps away from
  // the starting room will be those beteeen rooms[prevcount] and room
  // [count]

  pot_waystations = rooms[prevcount..count];
  if (sizeof(pot_waystations)<1){
    report("%^BOLD%^%^RED%^Size of pot_waystations <1). Exiting add_waystations");
    save_data();
    return pot_waystations;
  }

  for (i=0;i<sizeof(pot_waystations);i++){
    temproom = pot_waystations[i];
    near_waystation =PATHFINDER->find_waystation(temproom,destination, spacing-1);
    if (!objectp(near_waystation)){
      report("Adding waystation to " + file_name(temproom));
      add_waystation(destination, file_name(temproom), stage);
    } else
     {
      report("Not adding waystation to " + file_name(temproom) + " Because it is near waystation: " + file_name(near_waystation));
    }
  }
  save_data();
  report ("%^CYAN%^Finished Add_waystations. Number of pot_waystations being returned: " + sizeof(pot_waystations));
  return pot_waystations; // returns this so that the calling function can
                          // then check through a limited number of rooms
                          // to see if they need waystations adding.
}


void clear_waystations(string destination){
  /*removes the waystations for the named destination */
  __destinations[destination] = ([]);
  __timings[destination] = 0;
  save_data();
}

void remove_destination(string destination){
  map_delete(__destinations, destination);
}

void clear_destinations(){
  /*removes all destination settings - disaster recovery ONLY! */
  __destinations = ([]);
  __timings = ([]);
  save_data();
}

varargs void generate_waystations(string destination, int stages, int spacing, string * nogo){

/*Adds in waystations for the named destination, for the number of stages named. See comments at top of file on how to use it. Note that setting 'stages' above 3 or 4 is likely to cause lag pockets */

  object dest_room,  * rooms_checked, * latest_rooms, *next_rooms;
  int i, j;
  if (!stringp(destination) || catch(destination->short_desc()))
  {
    if (catch(destination->short_desc())) report("Problem loading destination short desc");
    else report("Destination is not a string");
    return;
  }
  dest_room = find_object_or_load(destination);
  rooms_checked = ({});
  latest_rooms = ({dest_room});
  next_rooms = ({});

  if (destination ==0){
    report("Destination set to zero");
    return;
  }
  if (stages == 0){
    stages = 1;
  }
  if (spacing == 0){
    spacing =1;
  }
  if (!objectp(dest_room)){
    return;
  }
  if (!nogo){
    nogo = ({});
  }


  if (stages<1){
    report("Stages set less than zero");
    return;
  }
  report("Adding waystation for destination");
  add_waystation(destination, destination, 1); //  The destination always
                                               // has a waystation setting
                                               // of 1


  // Next add in the waystations around it, to however many stages you are
  // looking for
  report("About to addwaystations");
  for (i=0;i<stages;i++){
    report ("Stage: " + i);
    if (sizeof(latest_rooms)<1){
      report ("size of latest_rooms is less than 1. Finishing...");
      break;
    }
    for (j=0;j<sizeof(latest_rooms);j++){
      if (query_waystation(destination, file_name(latest_rooms[j]))>0){
        report("%^BOLD%^%^CYAN%^j = " + j + " About to do add_waystations");
        next_rooms += add_waystations(rooms_checked, latest_rooms[j], destination, i+2, spacing, nogo);
        report("Finished doing add_waystations");
      } else
      {
         report("%^BOLD%^%^MAGENTA%^" + file_name(latest_rooms[j]) + " IS NOT a waystation for " + destination + " continuing...");
      }
    }
    latest_rooms = next_rooms;
    next_rooms = ({});
  }
  __timings[destination] = time();
  report ("Finished cycling. About to save");
  save_data();
  report ("SAVED");
}

void generate_maze_waystations(string destination, int stages, int spacing){

//Version of generate_waystations for when the target room is part of a maze on the maze daemon.

/*Adds in waystations for the named destination, for the number of stages named. See comments at top of file on how to use it. Note that setting 'stages' above 3 or 4 is likely to cause lag pockets */

  string dest_room,  * rooms_checked, * latest_rooms, *next_rooms;
  int i, j;

  dest_room = destination;
  rooms_checked = ({});
  latest_rooms = ({dest_room});
  next_rooms = ({});


  if (destination ==0){
    return;
  }
  if (stages == 0){
    stages = 1;
  }
  if (spacing == 0){
    spacing =1;
  }

  if (!objectp(dest_room)){
    return;
  }

  if (stages<1){
    return;
  }

  add_waystation(destination, destination, 1); //  The destination always
                                               // has a waystation setting
                                               // of 1


  // Next add in the waystations around it, to however many stages you are
  // looking for
  for (i=0;i<stages;i++){
    if (sizeof(latest_rooms)<1){
      break;
    }
    for (j=0;j<sizeof(latest_rooms);j++){
      if (query_waystation(destination, latest_rooms[j])>0){
        next_rooms += add_maze_waystations(rooms_checked, latest_rooms[j], destination, i+2, spacing);
      }
    }
    latest_rooms = next_rooms;
    next_rooms = ({});
  }
  __timings[destination] = time();
  save_data();
}


int query_timing(string dest){
  string * rooms;
  rooms = keys(__timings);
  if (sizeof(rooms)<1 || member_array(dest, rooms)==-1){
    return 0;
  }
  return __timings[dest];
}

void set_waystations(string destination, mapping map){
  __destinations[destination] = map;
  __timings[destination] = time();
}
