#include <std.h>
#include <daemons.h>
#define DEST "/daemon/destinations_d.c"

inherit DAEMON;

/*This daemon has a number of functions to help with locating nearby rooms or objects/monsters, and to find a path between rooms. Each function is essentially stand alone, and has its own explanation 
Lujke September 2005 */

object far_present(object startroom, string item_name, int distance){

/* Coded by Lujke August 2005
   far_present returns the first object that it finds which has a given id
   within a set range of a given starting room.
   It takes three arguments:
   object startroom - the room to start looking from
   string item_name - the id that you want to find
   int distance - the number of rooms distant that you want to search
*/

  object *rooms, item, temproom;
  string * exits, exitname;
  int i,j,k,roomcount, prevcount, runningcount;
  if (!objectp(startroom)){return 0;}
  rooms= allocate(8000);
  roomcount = 0;
  prevcount =0;
  runningcount = 0;
 // check if object is present in start room
  item = present(item_name, startroom);
  if (objectp(item)){
    distance = 0;
    return item;
  }
  if (distance <1){
    return item;
  } 
  //build a list of all the rooms up to <distance> rooms from startroom
  rooms[0] = startroom;
  roomcount ++;
  runningcount ++;
  for (i=0;i<distance;i++){
    if (prevcount==roomcount){ break;} // if this is true, it means
                                         // that no further rooms were
                                        // found on the last iteration
    for (j=prevcount;j<roomcount;j++){
        // cycle through each room that was added to the list on the last
        // iteration

      if (!objectp(rooms[j])){
        return item;
      }
      exits = rooms[j]->query_obvious_exits(); 
      for (k=0;k<sizeof(exits);k++){
          //go through all the rooms that each room is linked to
        exitname = exits[k];
        if(file_exists(rooms[j]->query_exit(exitname)+".c")){
          temproom = find_object_or_load(rooms[j]->query_exit(exitname));
          // check each room. If it is valid and not already on the list,
          // add it to the list.
          if (objectp(temproom)){
            if (member_array(temproom, rooms, 0)==-1){ 
               // If this is a new room, check to see if it contains the
               // item and return the item if it does
               item = present(item_name, temproom);
               if (objectp(item)){
                 return item;
               }
             rooms[runningcount]= temproom;
             runningcount++;
            }
          }
        }
      }
    }
    prevcount = roomcount;
    roomcount = runningcount;
  }
}



object* all_present(string item_name, object room){

/* Coded by Lujke August 2005
  all_present returns an array of all objects in a room which have a given 
  id. It takes two arguments:

  string item_name  -  the id that you want to search for
  object room       -  the room that you want to check (could
                         theoretically be any object, not just a room)
*/

  object * items;
  int i,j;
  items = ({});
  if (!objectp(room)){
    return items;
  }
  if (sizeof(all_inventory(room))<1){ return items; }
  for (i=0;i<sizeof(all_inventory(room));i++){
    if (objectp(all_inventory(room)[i])){
      if (all_inventory(room)[i]->id(item_name)){
        items += ({ all_inventory(room)[i] }); 
      }
    }
  }
  return items;
}

object * all_living_present(object room){

/* Coded by Lujke August 2005
  
   all_living_present takes an argument of an object (usually a room)
   and returns an array of objects, containing every living thing in the
   room's inventory.

   If there is nothing in the room, an empty array is returned.
*/

  object * creatures;
  int i,j;
  creatures = ({});
  if (!objectp(room)){
    return creatures;
  }
  if (sizeof(all_inventory(room))<1){ return creatures; }
  for (i=0;i<sizeof(all_inventory(room));i++){
    if (objectp(all_inventory(room)[i])){
      if (living(all_inventory(room)[i])==1){
        creatures += ({ all_inventory(room)[i] }); 
      }
    }
  }
  return creatures;
}

object* all_far_present(object startroom, string item_name, int distance){

/* Coded by Lujke August 2005

  all_far_present returns an array of all the objects that have a given id
  which are to be found within a set range of a given starting room/

  It takes 3 arguments:

  object startroom - the room from which to start the search
  string item_name - the id that you want to look for
  int distance - the distance you want to search for. Note that the
                 maximum distance setting is 5; any furter causes
                 recursion errors

*/


  object *rooms, *items, *tempitems,temproom;
  string * exits, exitname;
  int i,j,k,l,m,roomcount, prevcount, runningcount;
  if (!objectp(startroom)){return 0;}
  rooms= allocate(8000);
  items =  ({});
  tempitems =  ({});
  roomcount = 0;
  prevcount =0;
  runningcount = 0;
  rooms[0] = startroom;
  roomcount ++;  runningcount ++;
  if (item_name == "living"){
    items = all_living_present(startroom);
  }else{
    items = all_present(item_name, startroom);
  }
  for (i=0;i<distance;i++){
    if (prevcount==roomcount){ break;} // if this is true, it means
                                         // that no further rooms were
                                        // found on the last iteration
    for (j=prevcount;j<roomcount;j++){
        // cycle through each room that was added to the list on the last
        // iteration

      if (!objectp(rooms[j])){
        return items;
      }
      exits = rooms[j]->query_obvious_exits(); 
      for (k=0;k<sizeof(exits);k++){
          //go through all the rooms that each room is linked to
        exitname = exits[k];
        if (file_exists(rooms[j]->query_exit(exitname)+".c")){
          temproom = find_object_or_load(rooms[j]->query_exit(exitname));
          // check each room. If it is valid and not already on the list,
           // add it to the list. 
          if (objectp(temproom)){
            if (member_array(temproom, rooms, 0)==-1){ 
               // If this is a new room, add the list of its items to the 
               // existing list of items
               if (item_name=="living"){
                 tempitems = all_living_present(temproom);
                 if (sizeof(tempitems)>0){
                   items += tempitems;   
                 }
               }else{
                 tempitems = all_present(item_name, temproom);
                 if (sizeof(tempitems)>0){
                   items += tempitems;   
                 }
               }
                rooms[runningcount]= temproom;
               runningcount++;
            }
          }
        }
      }
    }
    prevcount = roomcount;
    roomcount = runningcount;
  }
  return items;
}


varargs string * findpath (object startroom, object endroom, string * path, string * finalpath, object * rooms, int depth, int flag, string * nogorooms){

/* Findpath returns a string array of directions that you would need to take to walk from one room to another.

It takes 7 arguments:
object startroom   - the room you want to start from
object endroom     - the room you want to finish at
string * path      - an array to hold the path variable as the function
                     adds to them. IMPORTANT: This MUST be initialised
                     using path  = ({}); before it is passed to the
                     function.
string * finalpath - an array to hold the final path to be returned.
                     IMPORTANT: this MUST be initialised using 
                     finalpath = ({}); before it is passed to the function
object * rooms     - an array to hold the rooms that the function has
                     already looked at (to prevent it looking at the same
                     room more than once and getting into a loop on 
                     recursions. As above, it MUST be initialised using
                     rooms = ({}); before being passed to the function
int depth          - The 'distance' over which you want to look for the
                     path. The higher the distance, the more processer
                     time will be used. CANNOT be set higher than 5, in 
                     any case, as this causes recursion errors
int flag           - If set to 1, this will cause the function to return
                     the shortest possible path between the rooms. 
                     Otherwise, the function will return the first valid
                     path it finds. This version can give a longer path,
                     but takes less processor time.
string * nogorooms - an array of base names of rooms that the path should
                     avoid. This variable is optional
*/


  int i, exitno;
  string * exits, *tempexits, *temppath;
  object room, temproom;
  room = startroom;
  
  if (depth <0){
    return ({});
  }
  if (!arrayp(nogorooms)) nogorooms = ({});
  if (!objectp(startroom)||!objectp(endroom)){return ({});}
  exits = startroom->query_obvious_exits();
  if (sizeof(exits)<1){
    return ({});
  }
  for (i=0;i<sizeof(exits);i++){
    if (member_array(room->query_exit(exits[i]), nogorooms)!=-1) continue; // skip any rooms included in the nogo list
    if (file_exists(room->query_exit(exits[i])+".c") && !catch(room->query_exit(exits[i])->query_short())){
      temproom = find_object_or_load(room->query_exit(exits[i]));
      if (objectp(temproom)){
        if (temproom == endroom){

          if (flag == 1){
            if (sizeof(finalpath)<1 ||sizeof(finalpath)>(sizeof(path)+1)){
              path += exits[i..i];
              finalpath = path;
            }else{
            } 
          }else{
            return path + exits[i..i];
          }
        }else{
          if (member_array(temproom, rooms)==-1){
            temppath = findpath(temproom, endroom, path + exits[i..i],
                        finalpath, rooms + ({startroom}), depth-1, flag, nogorooms);
            if (sizeof(finalpath)<1){
               if (sizeof(temppath)>0){
                 finalpath = temppath;
               }
            }
            if(sizeof(finalpath)>sizeof(temppath)){
              if (sizeof(temppath)>0){
                finalpath = temppath;
              }
            }
          }else{

          }
        }
      }
    }
  }

  return finalpath;
} 


varargs string * findburiedpath (object startroom, object endroom, string * path, string * finalpath, object * rooms, int depth, int flag, string * nogorooms){

/* Same as findpath, but includes buried exits.*/

  int i, exitno;
  string * exits, *tempexits, *temppath, * buried_directions, * combined_exits, temp_exit;
  object room, temproom;
  mapping buried_exits;
  report("Findburiedpath 1");
  room = startroom;

  if (flag >5) return ({"flag count exceeded"});
  if (depth <0){
    return ({});
  }
  if (!arrayp(nogorooms)) nogorooms = ({});
  if (!objectp(startroom)||!objectp(endroom)){return ({});}
  exits = startroom->query_obvious_exits();
  buried_exits = startroom->query_orig_exits();
  combined_exits = exits;
  report("Findburiedpath 2");
  if (sizeof(buried_exits)>0)
  {
    report("There are " + sizeof(buried_exits) + " buried exits");
    buried_directions = keys(buried_exits);
    combined_exits += buried_directions;
  } else report("No buried exits found");
  report("Findburiedpath 3");
  if (sizeof(combined_exits)>0)
  {
    report("About to cycle through " + sizeof(combined_exits) + " combined exits"); 
    for (i=0;i<sizeof(combined_exits);i++)
    {
      report("Combined exit " + i + " Direction: " + combined_exits[i]);
      temp_exit = find_open_or_buried_destination(room, combined_exits[i]);
      if (member_array(temp_exit, nogorooms)!=-1) continue; // skip any rooms included in the nogo list
      if (file_exists(temp_exit + ".c") && !catch(temp_exit->query_short()))
      {
        temproom = find_object_or_load(temp_exit);
        if (objectp(temproom))
        {
          report(file_name(temproom) + " is a valid room");
          if (temproom == endroom)
          {
            report("%^BOLD%^%^CYAN%^Temproom "+ file_name(temproom) + " is the endroom");  
            if (flag >0)
            {
              report("%^BOLD%^%^MAGENTA%^Flag >0. What does that mean?");
              if (sizeof(finalpath)<1 ||sizeof(finalpath)>(sizeof(path)+1))
              {
                path += exits[i..i];
                finalpath = path;
              }else{
              } 
            }else{
              report("%^BOLD%^%^MAGENTA%^Flag <1. Ending");
              return path + combined_exits[i..i];
            }
          }else{
            report("Current room: " + file_name(startroom) + " %^ORANGE%^Temproom " + file_name(temproom) + " is not the end room");
            if (member_array(temproom, rooms)==-1){
              temppath = findburiedpath(temproom, endroom, path + combined_exits[i..i],
                          finalpath, rooms + ({startroom}), depth-1, flag ++, nogorooms);
              if (sizeof(finalpath)<1){
                 if (sizeof(temppath)>0){
                   finalpath = temppath;
                 }
              }
              if(sizeof(finalpath)>sizeof(temppath)){
                if (sizeof(temppath)>0){
                  finalpath = temppath;
                }
              }
            }else{
              report("room already checked");
            }
          }
        } else report("%^BOLD%^%^RED%^temproom "+ file_name(temproom) + " is not a valid object");
      }  else
      {
        report("Either " + temp_exit + " does not exist as a file, or there is an error with query_short");
      }
    }
  } else
  {
    report("There are no combined exits");
  }
  return finalpath;
} 

string find_open_or_buried_destination(object room, string direction){
  string * exits, * buried_directions;
  mapping buried_exits;
  if (!objectp(room))
  {
    report("Find open or buried destination: room is not an object");
    return "";
  }
  exits = room->query_exits();
  buried_exits = room->query_orig_exits();

  if (mapp(buried_exits) && sizeof(buried_exits)>0) buried_directions = keys(buried_exits);
  else buried_directions = ({});
  report("Find open or buried destination: " + sizeof(exits) + " exits and " + sizeof(buried_directions) + " buried exits");
  if (member_array(direction, exits)!=-1){
//    report(direction + " is one of the normal exits, leading to: " + room->query_exit(direction));
    return room->query_exit(direction);
  }
  if (member_array(direction, buried_directions)!=-1)
  {
    report("%^BOLD%^%^YELLOW%^" + direction + " is one of the buried exits, leading to: " + buried_exits[direction]);
    return buried_exits[direction];
  }
  return "";
}

void report(string str){
//  object luj;
//  luj = find_player("lujke");
//  if (objectp(luj)){
//    tell_object(luj, "%^GREEN%^" + str);
//  }
//  "/daemon/reporter_d"->report("lujke", str);
}

varargs object find_waystation(object startroom, string destination,int distance, string * nogorooms){
  /* find_waystation returns the nearest room with a 'waystation' setting.
     If the current room has a waystation setting, returns the nearest 
     room with a waystation setting less than the current room's 
     waystation setting. This function is used to help mobs find their way
     to a given destination, which has been set up with waystations.
     (See also /daemons/destination_d.c

     find_waystation takes three arguments:
 
  object startroom   - the room you want to start from
  string destination - the filename of the final destination room, without 
                       a ".c" at the end ( ie exactly what is returned by
                       file_name(room) )
  int distance       - the number of 'steps' over which you want the code
                       to look for a waystation. CANNOT be higher than 5,
                       as this would cause recursion problems.
  */

  object *rooms, temproom, dest_room, room;
  string * exits, exitname;
  int i,j,k,roomcount, prevcount, runningcount, station_num, targ_num, track;;
 
  if (!objectp(startroom)){
    report ("Starting room didn't load");
    return 0;
  }
  if (!arrayp(nogorooms)) nogorooms = ({});
  rooms= allocate(8000);
  roomcount = 0;
  prevcount =0;
  runningcount = 0;
  track = 0;
  if (!file_exists(destination + ".c")){
    report("No such file as given destination: " + destination + ".c"); 
    notify_fail("Error - file does not exist!");
    return 0;
  }
  dest_room = find_object_or_load(destination);
  if (!objectp(dest_room)){
    report("Destination: " + destination + " is not a valid room");
    return 0;
  }

 // check if the current room contains a waystation
  station_num = DEST->query_waystation(destination,file_name(startroom));

  if (station_num==1){
    return startroom;
  }
  targ_num = station_num -1;
  if (distance <1){
    return startroom;
  } 
  //build a list of all the rooms up to <distance> rooms from startroom
  rooms[0] = startroom;
  roomcount ++;
  runningcount ++;
  for (i=0;i<distance;i++){
    report ("Checking distance stage " + i);
                               // if this is true, it means that no further
    if (prevcount==roomcount){  // rooms were found on the last iteration
      report("%^BOLD%^No further rooms found to check");
      break;
    }       
    track = 0;
    if (intp(prevcount)){
      if(intp(roomcount)){
        track = roomcount-prevcount;
      } else {
        track -= 1000;
      }
    } else {
      track -= 10;
    }
    report ("There are " + track + " rooms to check at this distance");                                   
    for (j=prevcount;j<roomcount;j++){
        // cycle through each room that was added to the list on the last
        // iteration
      room = find_object_or_load(file_name(rooms[j]));
      if (objectp(room)){
        report ("%^BOLD%^%^BLUE%^checking " + file_name(rooms[j]));
        exits = room->query_obvious_exits(); 
        if (sizeof(exits)<1){
          room->query_short();
          exits = room->query_obvious_exits(); 
        }
        report ("There are " + sizeof(exits) + " %^RESET%^%^ORANGE%^exits to check");
        for (k=0;k<sizeof(exits);k++){
          //go through all the rooms that each room is linked to
          exitname = exits[k];
          report ("Checking " + exitname + " exit of room " + base_name(room));
          if(!catch(rooms[j]->query_exit(exitname)->query_short())) {    //  old check:  file_exists(rooms[j]->query_exit(exitname)+".c"))
            temproom = find_object_or_load(rooms[j]->query_exit(exitname));
          // check each room. If it is valid and not already on the list,
          // and not on the nogolist add it to the list.
            if (member_array(rooms[j]->query_exit(exitname), nogorooms)==-1  && objectp(temproom)){
              if (member_array(temproom, rooms, 0)==-1){ 
                 // If this is a new room, check to see if it has a
                 // waystation number for the destination being checked
                 // - and whether it is the number sought.
                station_num = DEST->query_waystation(destination, file_name(temproom));
                if (station_num > 0 ){
                  if (targ_num < 0){
                    return temproom;
                  }
                  if (station_num<=targ_num){
                    // this waystation is closer than the one in the
                    // current room - use it.
                    return temproom;
                  } else { 
                    report(file_name(temproom) + " %^RESET%^is a waystation, but is not closer than the starting room");
                  }
                } else {
                  report(file_name(temproom) + " %^RESET%^is not a waystation");
                } 
                rooms[runningcount]= temproom;
                runningcount++;
              } else {
                report (file_name(temproom) + " has already been checked");
              }
            } else {
              report("%^RED%^ERROR: " + rooms[j]->query_exit(exitname) + " is not a valid room");
            } 
          } else {
              report("%^RED%^ERROR: " + rooms[j]->query_exit(exitname) + "%^MAGENTA%^ does not exist as a file");
          }
        }
      } else{
        report (file_name(rooms[j]) + "%^YELLOW%^ is not a valid room");
      }
    }
    prevcount = roomcount;
    roomcount = runningcount;
  }
  return 0;
}
