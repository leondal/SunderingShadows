#include <std.h>
inherit OBJECT;


void create(){
  ::create();
  set_name("scanner");
  set_id("scanner");
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
    prevcount = roomcount;
    roomcount = runningcount;
  }
}

object* all_present(string item_name, object room){
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
  if (depth <0){tell_object(holder, "Run out of depth!\n"); return ({});}
  if (!objectp(startroom)||!objectp(endroom)){return ({});}
  exits = startroom->query_exits();
  if (sizeof(exits)<1){
    return ({});
  }
  for (i=0;i<sizeof(exits);i++){
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
//        tell_object(holder, "It's not the end room, but let's check to"
//                             +" see if it leads to it...\n");
          temppath = findpath(temproom, endroom, path + exits[i..i], finalpath, rooms + ({startroom}), depth-1, flag);
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
//  tell_object(holder,"Finished checking all exits for "
//                     +temproom->query_short());
  return finalpath;
} 
