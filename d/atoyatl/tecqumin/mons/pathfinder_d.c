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


string * findpath (object startroom, object endroom, string * path, string * finalpath, object * rooms, int depth, int flag){

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
*/


  int i, exitno;
  string * exits, *tempexits, *temppath;
  object room, temproom;
  room = startroom;

  if (depth <0){
    return ({});
  }

  if (!objectp(startroom)||!objectp(endroom)){return ({});}
  exits = startroom->query_obvious_exits();
  if (sizeof(exits)<1){
    return ({});
  }
  for (i=0;i<sizeof(exits);i++){
    if (file_exists(room->query_exit(exits[i])+".c")){
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
          if (member_array(temproom, rooms, 0)==-1){
            temppath = findpath(temproom, endroom, path + exits[i..i],
                        finalpath, rooms + ({startroom}), depth-1, flag);
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

object find_waystation(object startroom, string destination,int distance){
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

  object *rooms, temproom, dest_room;
  string * exits, exitname;
  int i,j,k,roomcount, prevcount, runningcount, station_num, targ_num;
 
  if (!objectp(startroom)){
    return 0;
  }
  rooms= allocate(8000);
  roomcount = 0;
  prevcount =0;
  runningcount = 0;

  if (!file_exists(destination + ".c")){
    notify_fail("Error - file does not exist!");
    return 0;
  }
  dest_room = find_object_or_load(destination);
  if (!objectp(dest_room)){
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
  for (i=0;i<distance;i++){   // if this is true, it means that no further
    if (prevcount==roomcount){  // rooms were found on the last iteration
      break;
    }                                          
    for (j=prevcount;j<roomcount;j++){
        // cycle through each room that was added to the list on the last
        // iteration

      if (objectp(rooms[j])){
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
                   } 
                 } 
               rooms[runningcount]= temproom;
               runningcount++;
              }
            } 
          }
        }
      }
    }
    prevcount = roomcount;
    roomcount = runningcount;
  }
  return 0;
}

