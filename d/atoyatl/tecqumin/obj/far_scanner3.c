#include <std.h>
inherit OBJECT;


void create(){
  ::create();
  set_name("xxxscannerxxx");
  set_id(({"scanner"}));
  set_long("");
  set_short("");
}

object far_present(object startroom, string item_name, int distance){
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
      exits = rooms[j]->query_exits(); 
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
  object * items, player;
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
  player = find_player(item_name);
  if (objectp(player) && present (player, room)){ 
    items += ({player});
  }
  return items;
}

object * all_living_present(object room){
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
      exits = rooms[j]->query_exits(); 
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
// If flag is set to 1, returns the shortest available path (this is more 
// processor intensive). Otherwise, returns the first available path
  int i, exitno;
  string * exits, *tempexits, *temppath;
  object room, temproom, holder;
  room = startroom;
  holder = ETO;
  if (!objectp(holder)){return ({});}
  if (depth <0){ return ({});}
  if (!objectp(startroom)||!objectp(endroom)){return ({});}
  exits = startroom->query_exits();
  if (sizeof(exits)<1){
    return ({});
  }
  for (i=0;i<sizeof(exits);i++){
    if (file_exists(room->query_exit(exits[i])+".c")){
      temproom = find_object_or_load(room->query_exit(exits[i]));
      if (objectp(temproom)){
        if (temproom == endroom){
//        tell_object(holder, "It's the end room!");
          if (flag == 1){
            if (sizeof(finalpath)<1 ||sizeof(finalpath)>(sizeof(path)+1)){
              path += exits[i..i];
              finalpath = path;
            }else{
//            tell_object(holder, "this path is longer than the existing"
//                               +" final path. Leaving the existing"
//                               +" final path intact.");
            } 
          }else{
//          tell_object(holder, "don't care if it's the shortest path or"
//                             +" not. Using this path regardless!");
            return path + exits[i..i];
          }
        }else{
          if (member_array(temproom, rooms, 0)==-1){
//         tell_object(holder, "It's not the end room, but let's check to"
//                             +" see if it leads to it...\n");
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
//              tell_object(holder, "this lookse like a better path."
//                                +" replacing final path");
              }
            }
          }else{
//          tell_object(holder, "Already checked that room!\n");
          }
        }
      }
    }
  }
//  tell_object(holder,"Finished checking all exits for "
//                     +temproom->query_short());
  return finalpath;
} 

object find_waystation(object startroom, string destination,int distance){
  // returns the nearest room with a 'waystation' setting.
  // If the current room has a waystation setting, returns the nearest 
  // room with a waystation setting less than the current room's 
  // waystation setting

  object *rooms, temproom, dest_room, debugger;
  string * exits, exitname;
  int i,j,k,roomcount, prevcount, runningcount, station_num, targ_num;
 
  if (!objectp(startroom)){
    return 0;
  }
  rooms= allocate(8000);
  roomcount = 0;
  prevcount =0;
  runningcount = 0;
  debugger = find_player("lujke");
//  startroom = EETO;
  dest_room = find_object_or_load(destination);
  if (!objectp(dest_room)){
    tell_object(ETO, "Invalid destination");
    return 0;
  }

 // check if the current room contains a waystation
  station_num = "/realms/lujke/daemons/destinations_d.c"->query_waystation(destination,file_name(startroom));
  tell_object(debugger, "The waystation number of this room is: " 
                    + station_num);

  if (station_num==1){
    tell_object(debugger, "This room is the destination!");
    return startroom;
  }
  targ_num = station_num -1;
  if (distance <1){
    tell_object(debugger, "Distance is less than 1 - ending execution");
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
    tell_object(debugger, "About to check through all the rooms added in the"
                     +" last iteration. Prevcount is: " + prevcount 
                     + " Roomcount is: " + roomcount);
                                       
    for (j=prevcount;j<roomcount;j++){
        // cycle through each room that was added to the list on the last
        // iteration
 //     tell_object(debugger, "Checking next room");

      if (objectp(rooms[j])){
 //       tell_object(debugger, "The room exists!");
       
        exits = rooms[j]->query_exits(); 
        for (k=0;k<sizeof(exits);k++){
          //go through all the rooms that each room is linked to
          exitname = exits[k];
          if(file_exists(rooms[j]->query_exit(exitname)+".c")){
           temproom = find_object_or_load(rooms[j]->query_exit(exitname));
          // check each room. If it is valid and not already on the list,
          // add it to the list.
            if (objectp(temproom)){
   //            tell_object(debugger, "The room exists");
              if (member_array(temproom, rooms, 0)==-1){ 
                 // If this is a new room, check to see if it has a
                 // waystation number for the destination being checked
                 // - and whether it is the number sought.
                 station_num = "/realms/lujke/daemons/destinations_d.c"->query_waystation(destination, file_name(temproom));
                 if (station_num > 0 ){
                   tell_object(debugger, file_name(temproom) + " This room appears to have a"
                                    +" waystation setting");

                   if (targ_num < 0){
                     tell_object(debugger,file_name(temproom) + " Any waystation will do - let's"
                                      +" stop here!");
                     return temproom;
                   }
                   if (station_num<=targ_num){
                     tell_object(debugger,file_name(temproom) +
                                       " This waystation has an equal or"
                                      +" lower number than the target we"
                                      +" are looking for.");
                     return temproom;
                   } else{
                     tell_object(debugger, file_name(temproom) 
                                      +" This waystation number is higher"
                                      +" than the one we are looking for"
                                      +" - let's not bother with it.");
                   }
                 } else{
                   tell_object(debugger, file_name(temproom) 
                                    +" This room does not have a"
                                    +" waystation number greater than 0");
                 }
               rooms[runningcount]= temproom;
               runningcount++;
              }
            } else {
 //              tell_object(debugger, "The room does not exist");
            }
          }else{
            tell_object(debugger, "Can't find the file named: " 
                             + rooms[j]->query_exit(exitname));
          }
        }
//        tell_object(debugger, "Finished checking exits");
      }else{
//        tell_object(debugger, "The room is not valid!");

      }
    }
    tell_object(debugger, "Finished this iteration");
    prevcount = roomcount;
    roomcount = runningcount;
  }
  tell_object(debugger, "Finished iterating. Haven't found any suitable"
                   +" waystation rooms");

  return 0;
}
