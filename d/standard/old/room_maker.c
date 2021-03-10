//  The KLF Room maker
//  by Kriton@Emerald MUD
//  Version 1.0
//  Written 7 September 1994

#include <std.h>
#include <ansi.h>

#define MASTER "/adm/obj/master"
#define CLS ESC+"[H"+ESC+"[2J"
#define TERM (string)this_player()->getenv("TERM")
#define OK_TERMS ({ "xterm", "ansi", "ansi-status" })
#define PROMPT "] "
#define TP  this_player()

inherit OBJECT;

mapping __roominfo;
string long, exitx, itemx, objectx, soundx, smellx;

void menu();
void menu2();
void print_query(string subj);

void create()    {
  ::create();
  seteuid(getuid());
  set_name("room builder");
  set_short("KLF Room Maker");
  set_id(({"maker","room maker","roommaker","klf room maker"}));
  set_long(
@TEXT
   This item was created by the KLF labs to help wizards create 
functioning rooms in a quick, effective manor.  For more information
type <help roommaker>.
TEXT
  );
  set_weight(0);
  set_value(0);
  __roominfo = ([  ]);
}
 
void init()    {
  ::init();
  if(!wizardp(this_player())) return;
  add_action("__make","makeroom");
  add_action("__edit","editroom");
}

void load_defaults()    {
  __roominfo["exits"] = ([  ]);
  __roominfo["items"] = ([  ]);
  __roominfo["short"] = "A KLF Generated Room";
  __roominfo["long"] = "A room made by KLF's Room Generator version 1.0\n";
  __roominfo["light"] = 2;
  __roominfo["indoors"] = 1;
  __roominfo["objects"] = ([  ]);
  __roominfo["smells"] = ([  ]);
  __roominfo["sounds"] = ([  ]);
  __roominfo["invis exits"] = ({  });
} 

// **** add_action()'s **** //

int __make(string str)    {
  string path, filename, temp, file;
  if(!str)    {
    notify_fail("Please specify the filename of the room to be created.\n");
    return 0;
  }
  path = this_player()->get_path();
  file = str;
  filename = resolv_path(path,file);
  if(sscanf(filename,"%s.c",temp) != 1) filename += ".c";
  if(!MASTER->valid_write(filename,this_player(),"__make"))    {
    notify_fail("KLF: Permission Denied.\n");
    return 0;
  }
  if(str != "-r")    {
    __roominfo = ([  ]);
    __roominfo["filename"] = filename;
    load_defaults();
  }
  menu();
  return 1;
}

// **** menu(), and other input functions **** //

void pause2(string str)    {   menu();   }

void pause()    {
  message("prompt","Press <enter> to continue...",this_player());
  input_to("pause2");
}

void input_long()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter your long description below: (\"**\" or \".\" to quit)");
  message("prompt",PROMPT,this_player());
  long = "";
  input_to("enter_long");
}

enter_long(string str)    {
  if(str != "**" && str != ".")    {
    long += str + "\n";
    message("prompt",PROMPT,this_player());
    input_to("enter_long");   
  }  else  {
    __roominfo["long"] = long;
    menu();
  }
}

void input_short()   {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    message("prompt","\nEnter short description> ",this_player());
  input_to("enter_short");
}

void enter_short(string str)   {
  if(!str) input_short();
    else  {
      __roominfo["short"] = str;
      menu();
    }
}

void input_exits()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter the exits below: \n"+
        "(\"**\" or \".\" in the first field will quit this process)\n"+
        "Format: exits id followed by a second input of the pathname.");
  message("prompt","\nExit ID: ",this_player());
  input_to("enter_exit_id");
}

void enter_exit_id(string str)   {
  if(!str)    {
    write("\nInvalid exit ID.");
    message("prompt","\nExit ID: ",this_player());
    input_to("enter_exit_id");
    return;
  }
  if(str != "**" && str != ".")    {
    exitx = str;
    message("prompt","\nExits to (pathname): ",this_player());
    input_to("enter_exit_fl");
  } else menu();
}

void enter_exit_fl(string str)    {
  if(!str)    {
    write("\nInvalid pathname.");
    message("prompt","\nExits to (pathname): ",this_player());
    input_to("enter_exit_fl");
    return;
  }
  __roominfo["exits"][exitx] = str;
  message("prompt","\nExit ID: ",this_player());
  input_to("enter_exit_id");
}
    
void input_items()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("Enter the descriptions of items that appear in the room below:\n"+
        "(\"**\" or \".\" in the first field will quit)");
  message("prompt","\nItem ID: ",this_player());
  input_to("enter_item_id");
}

void enter_item_id(string str)    {
  if(!str)    {
    write("\nInvalid Item ID.");
    message("prompt","\nItem ID: ",this_player());
    input_to("enter_item_id");  
    return;
  }
  if(str != "**" && str != ".")   {
    itemx = str;
    message("prompt","Item Descrition: ",this_player());
    input_to("enter_item_description");
  }  else menu();
}

void enter_item_description(string str)   {
  if(!str)    {
    write("\nInvalid Description.");
    message("prompt","\nItem Descrition: ",this_player());
    input_to("enter_item_description");
    return;
  }  else  {
    __roominfo["items"][itemx] = str;
    message("prompt","\nEnter Item ID: ",this_player());
    input_to("enter_item_id");
  }
}  

void input_light()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter a light value in the space below.\n"+
        "Valid light values range from 5 to -5 (magical darkness)");
  message("prompt","\nLight> ",this_player());
  input_to("enter_light");
}

void enter_light(string str)    {
  int light;
  if(!str || sscanf(str,"%d",light) != 1)   {
    write("\nInvalid choice.");
    message("prompt","\nLight> ",this_player());
    input_to("enter_light");
    return;
  }
  sscanf(str,"%d",light);
  if(light > 5 || light < -5)    {
    write("\nLight value is out of range.");
    message("prompt","\nLight> ",this_player());
    input_to("enter_light");
    return;
  }  else   {
    __roominfo["light"] = light;
    menu();
  }
}

void input_indoors()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("\nPlease enter whether this room is indoors or outdoors.\n"+
        "(1 == indoors and 0 == outdoors)");
  message("prompt","\nIndoors> ",this_player());
  input_to("enter_indoors");
}

void enter_indoors(strinay(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter a light value in the space below.\n"+
        "Valid light values range from 5 to -5 (magical darkness)");
  message("prompt","\nLight> ",this_player());
  input_to("enter_light");
}

void enter_light(string str)    {
  int light;
  if(!str || sscanf(str,"%d",light) != 1)   {
    write("\nInvalid choice.");
    message("prompt","\nLight> ",this_player());
    input_to("enter_light");
    return;
  }
  sscanf(str,"%d",light);
  if(light > 5 || light < -5)    {
    write("\nLight value is out of range.");
    message("prompt","\nLight> ",this_player());
    input_to("enter_light");
    return;
  }  else   {
    __roominfo["light"] = light;
    menu();
  }
}

void input_indoors()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("\nPlease enter whether this room is indoors or outdoors.\n"+
        "(1 == indoors and 0 == outdoors)");
  message("prompt","\nIndoors> ",this_player());
  input_to("enter_indoors");
}

void enter_indoors(string str)   {
  int numb;
  if(!str || sscanf(str,"%d",numb) != 1)    {
    write("Invalid Choice.");
    message("prompt","\nIndoors> ",this_player());
    input_to("enter_indoors");
    return;
  }
  sscanf(str,"%d",numb);
  if(numb != 1 && numb != 0)    {
    write("\nRoom must be either 1 for indoors or 0 for outdoors.");
    message("prompt","\nIndoors> ",this_player());
    input_to("enter_indoors");
  }  else  {
    __roominfo["indoors"] = numb;
    menu();
  }
}      

void abort()   {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("\nEdit aborted.");
}

string fill_mapping(string str)    {
  int i;
  string temp, *klf;
  temp = "";
  klf = keys(__roominfo[str]);
  for(i=0;i<sizeof(klf);i++)    {
    temp += "\"" + klf[i] + "\":" + "\"";
    temp += __roominfo[str][klf[i]] + "\",\n";
  }
  return temp;
}

string fill_invis_exits()    {
  string temp, *exits;
  int i;
  exits = __roominfo["invis exits"];
  temp = "  set_invis_exits(({";
  for(i=0;i<sizeof(exits);i++)
    temp += "\""+exits[i]+"\",";
  temp += "}));\n";
  return temp;
}

string fill_senses(string str)    {
  string temp, *tmp, sense;
  int i;
  if(str == "smells") sense = "smell";
    else sense = "listen";
  tmp = keys(__roominfo[str]);
  temp = "";
  for(i=0;i<sizeof(tmp);i++)    {
    temp += "  set_"+sense+"(\""+tmp[i]+"\",";
    temp += "\""+__roominfo[str][tmp[i]]+"\");\n";
  }
  return temp;
}

string fill_objects()   {
  string temp, *tmp;
  int i;
  temp = "\n\nvoid reset()   {\n";
  tmp = keys(__roominfo["objects"]);
  for(i=0;i<sizeof(tmp);i++)   {
    temp += "  if(!present(\""+__roominfo["objects"][tmp[i]]+"\"))\n";
    temp += "    new(\""+tmp[i]+"\")->move(this_object());\n";
  }
  temp += "}\n";
  return temp;
}  

void save_and_quit()    {
  int x;
  string file;
  if(file_size(__roominfo["filename"]) > 0) 
    rm(__roominfo["filename"]);
  file="//  Room created using KLF generator by Kriton\n"+
  "//  Created "+ctime(time())+" by "+(string)TP->query_name()+"\n\n"+
  "inherit \"std/room\";\n\n"+
  "void create() +"\",";
  temp += "}));\n";
  return temp;
}

string fill_senses(string str)    {
  string temp, *tmp, sense;
  int i;
  if(str == "smells") sense = "smell";
    else sense = "listen";
  tmp = keys(__roominfo[str]);
  temp = "";
  for(i=0;i<sizeof(tmp);i++)    {
    temp += "  set_"+sense+"(\""+tmp[i]+"\",";
    temp += "\""+__roominfo[str][tmp[i]]+"\");\n";
  }
  return temp;
}

string fill_objects()   {
  string temp, *tmp;
  int i;
  temp = "\n\nvoid reset()   {\n";
  tmp = keys(__roominfo["objects"]);
  for(i=0;i<sizeof(tmp);i++)   {
    temp += "  if(!present(\""+__roominfo["objects"][tmp[i]]+"\"))\n";
    temp += "    new(\""+tmp[i]+"\")->move(this_object());\n";
  }
  temp += "}\n";
  return temp;
}  

void save_and_quit()    {
  int x;
  string file;
  if(file_size(__roominfo["filename"]) > 0) 
    rm(__roominfo["filename"]);
  file="//  Room created using KLF generator by Kriton\n"+
  "//  Created "+ctime(time())+" by "+(string)TP->query_name()+"\n\n"+
  "inherit \"std/room\";\n\n"+
  "void create()   {\n"+
  "  ::create();\n"+
  "  set_short(\""+__roominfo["short"]+"\");\n"+
  "  set_property(\"indoors\","+__roominfo["indoors"]+");\n"+
  "  set_property(\"light\","+__roominfo["light"]+");\n"+
  "  set_long(\n"+
  "@TEXT\n"+
  __roominfo["long"]+
  "TEXT\n"+
  "  ); \n"+
  "  set_exits(([\n"+
  fill_mapping("exits")+
  "  ]));\n"+
  "  set_items(([\n"+
  fill_mapping("items")+
  "  ]));\n";
  if(sizeof(__roominfo["invis exits"]) != 0)
    file += fill_invis_exits();
  if(sizeof(keys(__roominfo["smells"])) != 0)
    file += fill_senses("smells");
  if(sizeof(keys(__roominfo["sounds"])) != 0)
    file += fill_senses("sounds");
  file += " }\n";
  if(sizeof(keys(__roominfo["objects"])) != 0)
    file += fill_objects();
  x = write_file(__roominfo["filename"],file);
  if(x==0) write("Failed to write file "+__roominfo["filename"]+".");
    else write("File "+__roominfo["filename"]+" saved.");
  __roominfo = ([  ]);
  return;
}

void menu()     {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("%^GREEN%^%^BOLD%^"+
  "                         KLF Room builder v 1.0 %^RESET%^");
  write("\nCurrently editing: "+__roominfo["filename"]);
  write("\n"+
  "  1)  Query Long           2)  Query Short\n"+
  "  3)  Query Exits          4)  Query Items\n"+
  "  5)  Query Light          6)  Query Indoors\n"+
  "  7)  Set Long             8)  Set Short\n"+
  "  9)  Set Exits            10) Set Items\n"+
  "  11) Set Light            12) Set Indoors\n"+
  "  13) Extra Options        14) Quit/Abort Edit\n"+
  "          15) Write to file/Save");
  message("prompt","\nKLF>> ",this_player());
  input_to("enter_selection");
}

void enter_selection(string str)    {
  int choice;
  if(!str || sscanf(str,"%d",choice) != 1)    {
    menu();
    return;
  }
  sscanf(str,"%d",choice);
  switch(choice)    {
    case 1: print_query("long"); break;
    case 2: print_query("short"); break;
    case 3: print_query("exits"); break;
    case 4: print_query("items"); break;
    case 5: print_query("light"); break;
    case 6: print_query("indoors"); break;
    case 7: input_long(); break;
    case 8: input_short(); break;
    case 9: input_exits(); break;
    case 10: input_items(); break;
    case 11: input_light(); break;
    case 12: input_indoors(); break;
    case 13: menu2(); break;
    case 14: abort(); break;
    case 15: save_and_quit(); break;
    default: write("\nInvalid Selection."); 
  }
}

void menu2()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("%^GREEN%^%^BOLD%^"+
  "                         KLF Room builder v 1.0%^RESET%^\n");
  write("Currently editing: "+__roominfo["filename"]+"\n");
  write(
  "  1)  Add object to room         2)  Add smell to room\n"+
  "  3)  Add listen/sound to room   4)  Add invisible exit\n"+
  "  5)  Query invisible exits      6)  Query objects\n"+
  "  7)  Query smells               8)  Query sounds\n"+
  "  9)  Return to main menu        10) Abort edit\n");
  message("prompt","KLF>> ",this_player());
  input_to("selection");
}

void input_objects()   {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("In the space below you may enter the pathname of an object \n"+
        "you would like to see put it in the room upon resets.\n"+
        "(Type \"**\" or \".\" to quit this process)\n");
  message("prompt","Pathname> ",this_player());
  input_to("enter_objects");
}

void enter_objects(string str)    {
  string temp, file;
  if(!str)  {  input_objects();  return;   }
  if(str != "**" && str != ".")   {
    objectx = str;
    write("Please give one ID that this item will respond to.");
    write("("+objectx+")");
    message("prompt","\nID> ",this_player());
    input_to("enter_object_id");
    return;
  }  else menu2();
}

void enter_object_id(string str)    {
  if(!str)   {
    write("Please give one ID that this item will respond to.");
    write("("+objectx+")");
    message("prompt","\nID> ",this_player());
    input_to("enter_object_id");
    return;
  }
  __roominfo["objects"][objectx] = str;
  input_objects();
}

void input_smells()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("Please enter a smell ID, this will be followed by a prompt\n"+
        "for the description of the smell. (\"**\" or \".\" to quit)\n");
  message("prompt","ID> ",this_player());
  input_to("enter_smell_id");
}

void enter_smell_id(string str)   {
  if(!str)  {  input_smells();  return;  }
  if(str != "**" && str != ".")    {
    smellx = str;
    write("Please enter what "+str+" smells like.");
    message("prompt","\nSmell: ",this_player());
    input_to("enter_smell");
    return;
  }  else menu2();
}

void enter_smell(string str)    {
  if(!str)    {
    write("Please enter what "+str+" smells like.");
    message("prompt","\nSmell: ",this_player());
    input_to("enter_smell");
    return;
  }
  __roominfo["smells"][smellx] = str;
  input_smells();
}

void input_sounds()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("Please enter a sound ID, this will be followed by a prompt\n"+
        "for the description of the sound. (\"**\" or \".\" to quit)\n");
  message("prompt","ID> ",this_player());
  input_to("enter_sound_id");
}
 
void enter_sound_id(string str)   {
  if(!str)  {  input_sounds();  return;  }
  if(str != "**" && str != ".")    {
    soundx = str;
    write("Please enter what "+str+" sounds like.");
    message("prompt","\nSounds: ",this_player());
    input_to("enter_sound");
    return;
  } else menu2();
}

void enter_sound(string str)    {  
  if(!str)    {
    write("Please enter what "+str+" sounds like.");
    message("prompt","\nSound: ",this_player());
    input_to("enter_sound");
    return;
  }
  __roominfo["sounds"][soundx] = str;
  input_sounds();
}

void input_invis_exits()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("Please enter the ID of an exit you want invisible.");
  write("(\"**\" or \".\" to quit)"); 
  message("prompt","Invis exit> ",this_player());
  input_to("enter_invis_exit");
}

void enter_invis_exit(string str)    {
  if(!str)  {  input_invis_exits();  return;  }
  if(str != "**" && str != ".")    {
    __roominfo["invis exits"] += ({ str });
    input_invis_exits();
  }  else menu2();
}

void selection(string str)   {
  int number;
  if(!str || sscanf(str,"%d",number) != 1)   {
    menu2();
    return;
  }
  sscanf(str,"%d",number);
  switch(number)    {
    case 1: input_objects(); break;
    case 2: input_smells(); break;
    case 3: input_sounds(); break;
    case 4: input_invis_exits(); break;
    case 5: print_query("invis exits"); break;
    case 6: print_query("objects"); break;
    case 7: print_query("smells"); break;
    case 8: print_query("sounds"); break;
    case 9: menu(); break;
    case 10: abort();
    default: menu2();
  }
}
 
void print_query(string subj)     {
  string *klf, mess;
  int i;
  
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    
  write("Query "+subj+"...");
  
  if(subj == "invis exits")   {
    klf = __roominfo["invis exits"];
    if(!klf || sizeof(klf) == 0)    {
       write("There are no invisible exits defined.");
    }  else  {
      mess = klf[0];
      for(i=0;i<sizeof(klf);i++) mess += ", "+klf[i];
      write(mess);
    }
    message("prompt","\nPress <ENTER> to continue: ",this_player());
    input_to("pause2");  
    return;
  }
  if(subj == "exits" || subj == "items" ||
     subj == "smells" || subj == "objects" || subj == "sounds")     {
    klf = (keys(__roominfo[subj]));
    mess = "";
    for(i=0;i<sizeof(klf);i++)    {
      mess += klf[i] + ":" + __roominfo[subj][klf[i]] + "\n";
    }
  }  else mess = __roominfo[subj];
  write("\n"+mess);
  message("prompt","Press <ENTER> to continue: ",this_player());
  input_to("pause2");
}
  

string query_auto_load()   {
    return base_name(this_object())+":";
}

void help()    {
  write(
@TEXT
%^GREEN%^%^BOLD%^KLF Room Generator v 1.0%^RESET%^"

Current Commands:
-----------------
makeroom <filename>:  This command will allow you to generate room
                      code with an easy to use menu system.  Use
                      the -r option to restore data lost after link-
                      death ( makeroom -r <filename> ).

This generator will accept the use of macros such as ~, here, etc,.
It is not as picky with names as other generators are.
TEXT
  );
}
