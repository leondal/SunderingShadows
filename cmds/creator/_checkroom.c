int cmd_checkroom(string path) {
  string * files, * broken_rooms, no_exit_rooms, dest_name, * temp_exits, * temp_rooms, roomname, return_roomname, return_dir, * return_exits;
  mapping rooms, exits, broken_exits;
  object room, dest_room;
  int i,j, count, count2, result;
  broken_rooms = ({});
  no_exit_rooms = ({});
  rooms = ([]);
  exits = ([]);
  broken_exits = ([]);
  if (path[sizeof(path)-1..sizeof(path)-1] != "/")
  {
    path = path + "/";
  } 
  files = get_dir(path + "*.c");
  count = sizeof(files);
  if (count < 1)
  {
    return notify_fail("No files in that directory. Remember that you must specify a path including a final '/', such as '/realms/lujke/'");
  }
  report ("Number of rooms found: " + count);
  for (i=0;i<count;i++)
  {
    report ("Checking room " + i);
    roomname = path+files[i]; 
    if (catch(roomname->short_desc()))
    {
        broken_rooms += ({files[i]});
        continue;
    }
    room = find_object_or_load(path+files[i]);
    if (!room->is_room())
    {
      continue;
    }
    exits = room->query_exits();
    count2 = sizeof(exits);
    report ("Number of exits found: " + count2);
    if (count2 <1)
    {
      no_exit_rooms += ({files[i]});
      continue;
    }
    for (j=0;j<count2;j++)
    {
      report ("Checking exit: " + j);
      dest_name = room->query_exit(exits[j]);
      if (!interact(".c", dest_name))
      {
        dest_name = dest_name + ".c";
      }
      if (!file_exists(dest_name)  ) // || catch(dest_name)->query_short()  !stringp(dest_name) ||    || catch(find_object_or_load(dest_name))
      {
        temp_exits = ({});
        temp_rooms = keys(broken_exits);
        if (sizeof(temp_rooms)>0 && member_array(dest_name, temp_rooms)!= -1)
        {
          temp_exits = ({broken_exits[base_name(room)]});
        }
        temp_exits += ({ exits[j] +": file: " + dest_name + " doesn't exist" });
        broken_exits[base_name(room)] = temp_exits;
        continue;
      }
      dest_room = find_object_or_load(dest_name);
      if ( !objectp(dest_room))
      {
        temp_exits = ({});
        temp_rooms = keys(broken_exits);
        if (sizeof(temp_rooms)>0 && member_array(base_name(room), temp_rooms)!= -1)
        {
          temp_exits = broken_exits[base_name(room)];
        }
        temp_exits += ({exits[j] +": " + dest_name + " was not a valid object"});
        broken_exits[base_name(room)] = temp_exits;
        continue;
      }
      return_exits = dest_room->query_exits();
      if ( sizeof(return_exits)<1)
      {
        temp_exits = ({});
        temp_rooms = keys(rooms);
        if (sizeof(temp_rooms)>0 && member_array(base_name(room), temp_rooms)!= -1)
        {
          temp_exits = rooms[base_name(room)];
        }
        temp_exits += ({exits[j] + ": " + dest_name + " doesn't have any exits, so there's no return exit"});
        rooms[base_name(room)] = temp_exits;
        continue;
      }
      return_dir = reverse_direction(exits[j]);
      return_roomname = dest_room->query_exit(return_dir);
      if (return_roomname != base_name(room))
      {
        temp_exits = ({});
        temp_rooms = keys(rooms);
        if (sizeof(temp_rooms)>0 && member_array(base_name(room), temp_rooms)!= -1)
        {
          temp_exits = rooms[base_name(room)];
        }
        temp_exits += ({exits[j]});
        rooms[base_name(room)] = temp_exits;
        continue;
      }
    }
  }
  count = sizeof(broken_rooms);
  if (count>0)
  {
    tell_object(TP, "%^BOLD%^%^YELLOW%^The following rooms are broken:");
    for (i=0;i<count;i++){
      tell_object(TP, "%^ORANGE%^Room: %^RESET%^" + broken_rooms[i]);
    }
  } else 
  {
    tell_object(TP, "%^BOLD%^%^GREEN%^You have no broken rooms. Congratulations!");
    tell_object(TP, "%^RESET%^%^MAGENTA%^Someone speaks in laconic draconic: %^B_GREEN%^%^BOLD%^%^GREEN%^ Now try writing something more complicated. Come on! Push yourself!%^YELLOW%^(%^BLUE%^Lujke%^YELLOW%^)");
  }
  count = sizeof(broken_exits);
  if (count > 0)
  {
    tell_object(TP, "%^BOLD%^%^CYAN%^The following rooms have broken exits:");
    temp_rooms = keys(broken_exits);
    for (i=0;i<count;i++)
    {
      tell_object(TP, " %^RESET%^%^CYAN%^Room: %^RESET%^" + temp_rooms[i]);
      temp_exits = broken_exits[temp_rooms[i]];
      count2 = sizeof(temp_exits);
      if (count2<1)
      {
        tell_object(TP, "%^RESET%^%^CYAN%^No exits broken after all. My mistake");
      } else 
      {
        for (j=0;j<count2;j++)
        {
          tell_object(TP, temp_exits[j]);
        }
      }
    }
  } else 
  {
    tell_object(TP, "%^BOLD%^%^GREEN%^No rooms have broken exits. Congratulations!");
  }
  count = sizeof(rooms);
//  report ("Number of rooms found: " + count);
  if (count > 0)
  {
    tell_object(TP, "%^BOLD%^%^MAGENTA%^The following rooms have exits that are one way:");
    temp_rooms = keys(rooms);
    for (i=0;i<count;i++)
    {
//      report ("checking room: " + i);
      tell_object(TP, "%^MAGENTA%^Room:%^RESET%^ " + temp_rooms[i]);
      temp_exits = rooms[temp_rooms[i]];
      count2 = sizeof(temp_exits);
//      report ("Number of EXITS found: " + count2);
      if (count2<1)
      {
        tell_object(TP, "%^RESET%^%^MAGENTA%^No one-way exits after all. My mistake");
      } else
      {
        for (j=0;j<count2;j++)
        {
          tell_object(TP, "%^GREEN%^Exit: %^RESET%^: " + temp_exits[j]);
        }
      }
    }
  } else 
  {
    tell_object(TP, "No rooms have broken exits. Congratulations!");
  } 
  return 1;
}

void report(string str){
//  "/daemon/reporter_d"->report("lujke", str);
}

string reverse_direction(string dir){
  string result;
  result = "none";
  switch(dir){
  case "north":
    result = "south";
    break;
  case "northeast":
    result = "southwest";
    break;
  case "east":
    result = "west";
    break;
  case "southeast":
    result = "northwest";
    break;
  case "south":
    result = "north";
    break;
  case "southwest":
    result = "northeast";
    break;
  case "west":
    result = "east";
    break;
  case "northwest":
    result = "southeast";
    break;
  case "up":
    result = "down";
    break;
  case "down":
    result = "up";
    break;
  case "in":
    result = "out";
    break;
  case "out":
    result = "in";
    break;
  case "climb":
    result = "descend";
    break;
  case "descend":
    result = "climb";
    break;
  case "forward":
    result = "backward";
    break;
  case "backward":
    result = "forward";
    break;
  case "right":
    result = "left";
    break;
  case "left":
    result = "right";
    break;
  }
  return result;
}

int try_load(string file){
  return 1;
// return catch{ find_object_or_load(file);};
}

void help() 
{
   write(
    "Syntax: <checkroom [path] >"
    "Checks all the rooms in the given directory, and returns lists of:"
    "  - rooms that don't load"
    "  - exits that don't work"
    "  - exits that are one-way only"
 
  );

}
