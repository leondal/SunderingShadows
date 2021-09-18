#define MAPPER "/daemon/map_maker_d.c"
varargs int cmd_map(string str) {
  string verb, name, *mapnames, result, mapname, title, note, verb2, plain_title, * roomnames, * titles, title1, title2, startroom, endroom, * route,
line, temp;
  mapping maps;
  int num, i, count, j, width, flag;
//  report("Running command map, with string " + str);
  if (!stringp(str))
  {
    TP->force_me("map");
    return 1; 
  }
  num = sscanf(str, "%s %s", verb, name);
  if (num< 2) verb = str;
  switch(verb)
  {
  case "note":
    if (!stringp(name)) return help();
    num = sscanf(name, "%s %s", verb2, name);
    if (num<2) return help();
    switch(verb2)
    {
    case "add":
      mapname = MAPPER->query_current_map(TPQN);
      if (mapname == "none") 
      {
        tell_object(TP, "You don't have a map currently loaded that you could add a note to");
        return 1;
      }
      if (MAPPER->load_map(TPQN, mapname)!=1)
      {
        tell_object(TP, "You weren't able to add a note due to a problem with your current"
          +" map. Make sure you have one loaded that you can view, and try again");
        return 1;
      }
      if (!objectp(ETP) || !MAPPER->contains_room(base_name(ETP)))
      {
        tell_object(TP, "%^RESET%^You can't add a note about this room to your"
          +" current map, because this room is not included in your"
          +" current map. Please load or create a map that contains"
          +" this room, and try again. (Hint: you can only add a note"
          +" when the map you are viewing contains a bright green"
          +" %^BOLD%^%^GREEN%^X%^RESET%^)");
        return 1;
      }
      num = sscanf(name, "%s %s", title, note);
      if (num<2) return help();
      plain_title = strip_colors(title);
      if (strlen(plain_title)>2) 
      {
        tell_object(TP, "%^RESET%^The title of your note must be 2 characters or less (e.g. 'N1'). It can contain colour codes, though. You
entered: " + title);
        return 1;
      } 
      if (strlen(plain_title)==1)
      {
        title = title + " ";
        plain_title = plain_title + " ";
      }
      titles = MAPPER->query_all_note_titles(TPQN);
      count = sizeof(titles);
      if (count>1)
      {
        for (i=0;i<count;i++)
        { 
          if(strip_colors(titles[i]) == plain_title)
          {
            tell_object (TP, "%^RESET%^This map already has a note with the title "
              + titles[i] + "%^RESET%^. I'm afraid it will get too confusing"
              +" if you add another one so similar");
            return 1; 
          }
        }
      }
      num = MAPPER->add_notation(TPQN, title, note);
      if (num < 1)
      {
        tell_object("%^RESET%^Sorry, there was a problem adding your note. Most likely,"
          +" you don't have a map currently loaded that you can view. Please"
          +" load or create one, and try again");
        return 1;
      }
      tell_object(TP, "%^RESET%^You carefully mark your map at this point,"
        +" with the notation " + title );
      if (stringp(note)) tell_object(TP, "On the back, you write a reminder"
        +" to yourself: " + note);
      return 1;
      break;
    case "read":
      mapname = MAPPER->query_current_map(TPQN);
      if (mapname == "none") 
      {
        tell_object(TP, "%^RESET%^You don't have a map currently loaded that you could read a note from");
        return 1;
      }
      if (MAPPER->load_map(TPQN, mapname)!=1)
      {
        tell_object(TP, "%^RESET%^You weren't able to read a note due to a problem with your current"
          +" map. Make sure you have one loaded that you can view, and try again");
        return 1;
      }
      title = name;
      plain_title = strip_colors(title);
      if (strlen(plain_title)>2) 
      {
        tell_object(TP, "%^RESET%^The title of your notes will be 2 characters or less (e.g. 'N1')");
        return 1;
      } 
      if (strlen(plain_title)==1)
      {
        title = title + " ";
      }
      note = MAPPER->query_note(title);
      if (note == "No note with that title")
      {
        tell_object(TP, "%^RESET%^%^ORANGE%^Consulting your notes, you cannot find anything under the title%^RESET%^ " + title);
        return 1;
      }
      tell_object(TP, "%^RESET%^%^ORANGE%^Consulting your notes, you see that the record you have"
        +" made beside the marking " + title + " reads: \n" + note);
      return 1;
      break;
    case "remove":
      mapname = MAPPER->query_current_map(TPQN);
      if (mapname == "none") 
      {
        tell_object(TP, "%^RESET%^You don't have a map currently loaded that you could remove a note from");
        return 1;
      }
      if (MAPPER->load_map(TPQN, mapname)!=1) 
      {
        tell_object(TP, "%^RESET%^You weren't able to remove a note due to a problem with your current"
          +" map. Make sure you have one loaded that you can view, and try again");
        return 1;
      }
      title = name;
      plain_title = strip_colors(title);
      if (strlen(plain_title)>2) 
      {
        tell_object(TP, "%^RESET%^The title of your notes will be 2 characters or less (e.g. 'N1')");
        return 1;
      } 
      if (strlen(plain_title)==1)
      {
        title = title + " ";
      }
      note = MAPPER->query_note(title);
      if (note == "There does not seem to be a note to go with that title")
      {
        tell_object("%^RESET%^There is no note with the title " + title + " for you to remove from the map");
        return 1;
      }
      tell_object(TP, "%^RESET%^You remove a note with the title "+ title + " from your map. It previously read: " + note);
      MAPPER->remove_note(TPQN, plain_title);
      return 1;
      break;
    default:
      return help();
    }
  case "route":
    MAPPER->load_current_map(TPQN);
    num = sscanf(name, "from %s to %s", title1, title2);
    if (num ==2)
    {
      startroom = MAPPER->query_room_with_note(title1);
      endroom = MAPPER->query_room_with_note(title2);
      if (startroom == "none")
      {
        tell_object(TP, "Your current map does not have a note with the title " + title1);
        return 1;
      }     
      if (endroom == "none")
      {
        tell_object(TP, "Your current map does not have a note with the title " + title2);
        return 1;
      }     
    }else { 
      num = sscanf(name, "to %s", title1);
      if (num == 0)
      {
        tell_object(TP, "Syntax is either: 'map route from [T1] to [T2]' OR: 'map route to [T1]'");
        return 1;
      }
      endroom = MAPPER->query_room_with_note(title1);
      if (endroom == "none")
      {
        tell_object(TP, "Your current map does not have a note with the title " + title1);
        return 1;
      }
      startroom = base_name(ETP);
    }
    route = MAPPER->map_route("lujke", startroom, endroom);
    if(sizeof(route)<1)
    {
      tell_object(TP, "There does not seem to be a viable route between those marks on your map");
      report("startroom: " + startroom + ", endroom: " + endroom);
    }
    result = "You can get there from here by going ";
    count = sizeof(route);
    for (i=0;i<count;i++)
    {
      if (count>1 && i==count-1) result += " and ";
      result += route[i];
      if (i<count-1) result += ", ";
    }
    tell_object(TP, result);
    return 1;
    break;
  case "view":
    mapname = MAPPER->query_current_map(TP->query_name());
     if (mapname == "none")
    {
      tell_object(TP, "%^RESET%^You don't have a map currently loaded. You can use"
        +" 'map list' to see the list of your available maps, and 'map load"
        +" <name>' to load a map.");
      return 1;
    }
    MAPPER->load_map(TPQN, mapname);
    tell_object(TP, "%^ORANGE%^Showing map: %^GREEN%^" + mapname); 
    tell_object(TP, MAPPER->show_basic_map(TP));
    break;
  case "key":
    mapname = MAPPER->query_current_map(TP->query_name());
     if (mapname == "none")
    {
      tell_object(TP, "%^RESET%^You don't have a map currently loaded. You can use"
        +" 'map list' to see the list of your available maps, and 'map load"
        +" <name>' to load a map.");
      return 1;
    }
    MAPPER->load_map(TPQN, mapname);
    tell_object(TP, "%^ORANGE%^Showing map: %^GREEN%^" + mapname); 
    
    tell_object(TP, MAPPER->show_basic_map(TP));
    tell_object(TP, MAPPER->show_key(TP));
    break;
  case "report":
    if (avatarp(TP))
    {
      if (stringp(name) && name == "off") 
      {
        if (MAPPER->query_reporting()==TP->query_name())
        {
          MAPPER->stop_reporting();
          tell_object(TP, "The mapper daemon will no longer send you bug reports");
          return 1;
        } else 
        {
          tell_object(TP, "The mapper daemon is not sending you bug reports");
          return 1;         
        }        
      } else 
      {
        MAPPER->start_reporting(TP->query_name());
        tell_object(TP, "The mapper will start sending you bug reports");
        break;
      }
    }
  case "expand":
    if (stringp(name) && name == "off") 
    {
      if (TP->query_property("map_expanding")==1)
      {
        TP->remove_property("map_expanding");
        tell_object(TP, "You will no longer expand your map if you meet any conflicts");
        return 1;
      } else 
      {
        tell_object(TP, "You are not expanding your map to deal with any conflicts");
        return 1;
      }        
    } else 
    {
      if (TP->query_property("map_expanding")==1)
      {
        tell_object(TP, "You have already decided to expand your map to deal with any clashes you come across");
        return 1;
      }
      tell_object(TP, "You decide to expand your map to deal with any clashes you come across");
      TP->set_property("map_expanding", 1);
      return 1;         
    }
    break;
  case "start":
    if (TP->query_property("automapping")==1)
    {
      tell_object(TP, "You are already mapping your progress");  
      return 1;
    }
    TP->remove_property("automapping");
    TP->set_property("automapping", 1);
    tell_object(TP, "%^RESET%^You %^BOLD%^%^GREEN%^start%^RESET%^ mapping your progress");
    break;
  case "stop":
    TP->remove_property("automapping"); 
    tell_object(TP, "%^RESET%^You %^RED%^stop%^RESET%^ mapping your progress");
    break;
  case "clear":
    MAPPER->start_new_map(TP);
    tell_object(TP, "You start fresh with a new map");
    break;
  case "save":
    if (num<2)
    {
      write ("Syntax is: 'map save <name>', where <name> is what you want to call your map.");
      return 1;
    }
    if (interact(TP->query_name(), name))
    { 
      write ("Sorry, you can't include your name in your map names");
      return 1;
    }
    if (strlen(name)>12)
    {
      write ("Sorry, your map names can't have more than 12 characters");
      return 1;
    }
    num = sscanf(name, "%s %s", verb, temp);
    if (num>1)
    {
      write ("Sorry, your map names can't contain spaces");
      return 1;      
    }
    // PUT IN CODE TO LOAD THE CURRENT MAP FIRST
    MAPPER->save_map(TP->query_name(), name);
    MAPPER->SAVE();
    tell_object(TP, "Map saved as: " + name );
    break;
  case "load":
    if (num<2)
    {
      write ("Syntax is: 'map load <name>', where <name> is the name of"
        +" one of your saved maps (use 'map list' to see the list of"
        +" maps you have saved.");
      return 1;
    }
    MAPPER->load_map(TP->query_name(), name);
    //PUT IN CODE TO CHECK FOR SUCCESSFUL LOADING
    tell_object(TP, "Map: " + name + " loaded");
    break;
  case "remove":
    if (num<2)
    {
      write ("Syntax is: 'map remove <name>', where <name> is the name"
        +" of one of your saved maps that you want to remove (use 'map"
        +" list' to see the list of maps you have saved.");
      return 1;
    }
    if (MAPPER->remove_map(TP->query_name(), name) == 0)
    {
      tell_object(TP, "You do not have a saved map with the name: " + name);
      return 1;
    }
    tell_object(TP, "Map: " + name + " removed");
    return 1;
    break;
  case "list":
    maps = MAPPER->query_maps(TP->query_name());
    if (!mapp(maps) || sizeof(maps)<1)
    {
      tell_object(TP, "You do not have any saved maps to list");
      return 1;
    }    
    result = "";
    line = "";
    mapnames = keys(maps);
    width = atoi(TP->getenv("SCREEN"));
    if (width == 0) width = 75;
    count = sizeof(mapnames);
    for (i=0;i<count;i++)
    {
      num = strlen(mapnames[i]);
      if (strlen(line) + num + 1 > width)
      {
        result += line + "\n";
        line = "";
      }
      line += " " + mapnames[i];
      if (num%8>0)
      {
        for (j=0;j<8-num%8;j++)
        {
          line += " ";
        }
      }


/*
      num = strlen(mapnames[i]);
      if (num>8)
      {
        result += mapnames[i][0..7] + "  ";
      } else {
        result += mapnames[i];
        if (num<8) for (j=num;j<9;j++) result += " ";
      }
      if (strlen(result)/width < (strlen(result)+10)/width)
      {
        result += "\n";
      }
*/
    }
    result += line;
    result = "%^ORANGE%^Maps saved for " + TP->query_name() + ":\n\n"+ result;
    tell_object(TP, result);
    break;
  case "check":
    if (TP->query_property("automapping") ==1)
    {
      tell_object(TP, "You %^BOLD%^%^GREEN%^are%^RESET%^ currently mapping your progress."
        +"\nType 'map stop' to stop.");
      return 1;
    }
    tell_object(TP, "You are %^RED%^not%^RESET%^ currently mapping your progress"
      +"\nType 'map start' to begin mapping.");
    return 1;
    break;
  default:
    help();
    return 1;
  }
  return 1;
}

varargs string * map_route(object who, object dest, object start){
  string * route, *path;
  object * rooms, waystation;
  rooms = ({});
  route = ({});
  path = ({});
  if (!objectp(who)) return ({});
  if (!objectp(dest)) return ({});
  if (!objectp(start))
  {
    if (!objectp(environment(who))) return ({});
    start = environment(who);
  }
  waystation = "/daemon/pathfinder_d"->find_waystation(start, base_name(dest), 5);
  if (!objectp(waystation)){
    MAPPER->report("About to generate waystations");
    "/daemon/destinations_d"->generate_waystations(base_name(dest), 5, 4, rooms);
  }
  waystation = "/daemon/pathfinder_d"->find_waystation(start, base_name(dest), 5);
  if (!objectp(waystation)) return ({});
  route = "/daemon/pathfinder_d.c"->findpath (start, waystation, path, route, rooms, 5, 1);
  return route;
}

void report(string str){
  "/daemon/reporter_d"->report("lujke", str);
}

void help() 
{
   write(
    "Syntax: <map view>           - displays your current map\n"
    "        <map key>            - displays your current map with an explanatory\n"
    "                               key\n"
    "        <map start>          - starts the process of mapping your movements\n"
    "        <map stop>           - stops mapping your movements\n"
    "        <map clear>          - clears your current map\n"
    "        <map save [name]>    - saves your current map with the specified name\n"
    "        <map load [name]>    - loads a map with the specified name\n"
    "        <map remove [name]>  - removes the names map from your saved maps\n"
    "        <map list>           - lists your saved maps\n"
    "        <map check>          - Tells you whether or not your mapper is\n"
    "                               running\n"
    "<map note add [title][note]> - Adds a note to your map under the given\n"
    "                               title (Titles must be short - 1 or 2\n"
    "                               characters\n"
    "   <map note remove [title]> - Removes the note with the given title from\n"
    "                               your map\n"
    "     <map note read [title]> - Reads the note with the given title\n"
    "      <map route to [title]> - Gives directions from your current position\n"
    "                               to one of the notes on your map.\n"                           
    " <map route from [title] to [title]> - Gives directions from one of the\n"
    "                               notes on your map to another\n"
    "         <map expand>         - Allows the map to expand itself if it\n"
    "                                encounters any clashes\n"
    "     <map expand off>         - Stops the map expanding itself if it\n"
    "                                encounters any clashes\n"
  );
 
  if (avatarp(TP)) write(
    "        <map report>        - Makes the map daemon send you debugging\n"
    "                              reports\n"
    "        <map report off>    - Stops the map daemon sending you reports\n");
  write(
    "\nThese commands operate the mud's auto-mapper. \n"
    "When you <start> the mapper, it will begin adding each room that you move\n"
    "into to your map. If you are in a room that is not included in your\n"
    "current map, it will load the first map it finds that contains the room,\n"
    "or start a new map if it does not find an existing one. \n" 
    "The number of maps you can save is affected by your intelligence score.\n"
    "Note: if you log out or are disconnected, you may need to restart your\n"
    +" mapper.\n"
    "You can use <map check> to check whether your mapper is currently running.\n"
    "You can use the <map note> commands to add notes to specific points on your\n"
    "map, the <map route> commands to plot a route from one point on the map to\n"
    "another (uses your current location as a default starting point), and\n"
    +"<map expand> to control how your map responds when it encounters an\n"
    +" existing room mapped to the location you are moving into. By default,\n"
    +"you will just stop mapping, but if you set it to expand, the map will\n"
    +"stretch in order to accomodate the extra rooms. It may take some\n"
    +"experimenting to work out how best to use this feature, which can be"
    +"considered 'alpha' at best."
  );

}
