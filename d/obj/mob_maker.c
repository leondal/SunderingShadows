//  KLF Monster Maker
//    Version 1.0
//    By Kriton@Orion II
//    Written 16 August 1994

#include <std.h>

#define PROMPT "Select ==> "
#define EDIT_PROMPT "] "
#define MASTER "/adm/obj/master"
#define MONSTER_BODIES  "/adm/db/mon_races"

inherit OBJECT;

mapping __monster;
string long;

void menu();
int write_to_file();
void load_monster(string mon_path);

void init()    {
  ::init();
  add_action("edit_monster","edit");
  add_action("make_monster","make");
}

void create()    {
  ::create();
  set_name("monster maker");
  set_short("KLF Monster Maker");
  set_id(({"maker","monster maker","klf maker"}));
  set_long(
@TEXT
   This is the KLF Monster Maker for wizards that like coding to be easy.
Type <help maker> for details.
TEXT
  );
  set_weight(0);
  set_value(0);
  __monster = ([  ]);
}

void load_defaults()    {
  __monster["race"] = "human";
  __monster["level"] = 1;
  __monster["body type"] = "human";
  __monster["long"] = "a monster created by KLF.";
  __monster["short"] = "a KLF monster";
  __monster["ids"] = ({ "monster", "klf monster" });
  __monster["name"] = "generic";
  __monster["gender"] = "neutar";
}

int make_monster(string str)    {
  string path, temp;
  if(!str)    {
    notify_fail("KLF: Missing arguement to monster maker.\n");
    return 0;
  }
  path = this_player()->get_path();
  if(!path) path = "/wizards/"+(string)this_player()->query_name()+"/";
  if(sscanf(str,"%s.c",temp) != 1) path += "/"+str + ".c";
    else path += "/" + str;
  if(!MASTER->valid_write(path,this_player()))    {
    notify_fail("KLF: Permission Denied.\n");
    return 0;
  }
  if(file_size(path) > 0)    {
    notify_fail("KLF: File "+path+" already exists.\n");
    return 0;
  }
  if(file_size(path) != -1)    {
    notify_fail("KLF: Unable to create file.\n");
    return 0;
  }
  __monster = ([  ]);
  __monster["file name"] = path;
  load_defaults();
  menu();
  return 1;
}

int edit_monster(string str)    {
  string path, temp;
  if(!str)   {
    notify_fail("KLF: Missing arguement to monster maker.\n");
    return 0;
  }
  path = this_player()->get_path();
  if(sscanf(str,"%s.c",temp) != 1) path += "/" + str + ".c";
    else path += "/" + str;
  if(!MASTER->valid_read(path,this_player()))   {
    notify_fail("KLF: Permission Denied.\n");
    return 0;
  }
  if(file_size(path) < 0)    {
    switch(file_size(path))    {
      case -2: notify_fail("KLF: "+path+" is a directory.\n"); break;
      case -1: notify_fail("KLF: "+path+" does not exist.\n"); break;
      default: notify_fail("KLF: Error, could not load file "+path+"\n");
    }
    return 0;
  } 
  __monster = ([  ]);
  __monster["file name"] = path;
  load_monster(path);
  menu();
  return 1;
}  

void load_monster(string mon_path)    {
  string *lines;
  object test;
  
  test = new(mon_path);
  
  if(!test)    {
    write("KLF: Could not restore "+mon_path);
    write("KLF: Using defaults");
    load_defaults();
    return;
  }
  __monster["ids"] = (string *)test->query_id();
  __monster["short"] = (string)test->query_short();
  __monster["long"] = (string)test->query("long");
  __monster["name"] = (string)test->query_name();
  __monster["race"] = (string)test->query("race");
  __monster["body type"] = (string)test->query_body_type();
  __monster["level"] = (int)test->query_level();
  __monster["gender"] = (string)test->query_gender();
}

void pause(string str)   {   menu();   }

void do_query(string str)    {
  string what,*temp;
  int i;
  if(str != "ids")  {
    what = __monster[str];
    if(!what) what = "Undefined";
  } else {
    temp = __monster["ids"];
    if(!temp || sizeof(temp) == 0) what = "Undefined";
      else {
        what = temp[0];
        for(i=0;i<sizeof(temp);i++) what += ", "+temp[i];
      }
  }
  write("\n"+str+":\n"+what+"\n");
  message("prompt","\nPress <ENTER> to continue.",this_player());
  input_to("pause");
}

void do_long()    {
  write("\nEnter long description (use \"**\" or \".\" to quit):");
  message("prompt",EDIT_PROMPT,this_player());
  long = "";
  input_to("enter_long");
}

void enter_long(string str)    {
  if(str != "." && str != "**")    {
    long += str + "\n";
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_long");
  } else {
    __monster["long"] = long;
    menu();
  }
}

void do_short()    {
  message("prompt","\nEnter short description: ",this_player());
  input_to("enter_short");
}

void enter_short(string str)    {
  if(!str || strlen(str) < 2) do_short();
    else  {
      __monster["short"] = str;
      menu();
    }
}

void do_ids()    {
  write("\nEnter monster IDs below (\"**\" or \".\" to quit):");
  message("prompt",EDIT_PROMPT,this_player());
  __monster["ids"] = ({  });
  input_to("enter_ids");
}

void enter_ids(string str)    {
  if(str != "**" && str != ".")    {
    __monster["ids"] += ({ str });
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_ids");
    return;
  }
  if(sizeof(__monster["ids"]) < 1)   {
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_ids");
  }
  menu();  
}
    
void do_level()    {
  message("prompt","\nEnter monster level: ",this_player());
  input_to("enter_level");
}

void enter_level(string str)   {
  int lev;
  if(!str || sscanf(str,"%d",lev) != 1) do_level();
    else  {
      sscanf(str,"%d",lev);
      __monster["level"] = lev;
      menu();
    }
}

void do_name()    {
  message("prompt","\nEnter monster name: ",this_player());
  input_to("enter_name");
}

void enter_name(string str)    {
  if(!str) do_name();
    else  {
      __monster["name"] = str;
      menu();
    }
}

void do_body_type()    {
  message("prompt","\nEnter body type (\"?\" for list): ",this_player());
  input_to("enter_body");
}

string *body_types()    {
  string temp, *bodies;
  int i;
  temp = "";
  bodies = get_dir("/adm/db/mon_races/*");
  if(!bodies || sizeof(bodies) == 0) bodies = ({ "human" });
  if(bodies && member_array(".",bodies) != -1) bodies -= ({ "." });
  return bodies;
}

void enter_body(string str)    {
  if(!str) {  do_body_type();  return;   }
  if(str == "?")    {
    message("edit","\nDefined body types:",this_playerter level: ",this_player());
  input_to("enter_level");
}

void enter_level(string str)   {
  int lev;
  if(!str || sscanf(str,"%d",lev) != 1) do_level();
    else  {
      sscanf(str,"%d",lev);
      __monster["level"] = lev;
      menu();
    }
}

void do_name()    {
  message("prompt","\nEnter monster name: ",this_player());
  input_to("enter_name");
}

void enter_name(string str)    {
  if(!str) do_name();
    else  {
      __monster["name"] = str;
      menu();
    }
}

void do_body_type()    {
  message("prompt","\nEnter body type (\"?\" for list): ",this_player());
  input_to("enter_body");
}

string *body_types()    {
  string temp, *bodies;
  int i;
  temp = "";
  bodies = get_dir("/adm/db/mon_races/*");
  if(!bodies || sizeof(bodies) == 0) bodies = ({ "human" });
  if(bodies && member_array(".",bodies) != -1) bodies -= ({ "." });
  return bodies;
}

void enter_body(string str)    {
  if(!str) {  do_body_type();  return;   }
  if(str == "?")    {
    message("edit","\nDefined body types:",this_player());
    message("edit",format_page(body_types(),3),this_player());
    do_body_type();
    return;
  }
  if(member_array(str,body_types()) == -1)    {
    message("edit","\nNot a valid body type.",this_player());
    do_body_type();
    return;
  }
  __monster["body type"] = str;
  menu();
}

void do_race()    {
  message("prompt","Enter monster race: ",this_player());
  input_to("enter_race");
}

void enter_race(string str)    {
  if(!str)   {   do_race();  return;   }
  __monster["race"] = str;
  menu();
}

void do_gender()    {
  message("prompt","\nEnter monster gender[m/f/n]: ",this_player());
  input_to("enter_gender");
}

void enter_gender(string str)    {
  if(str != "m" && str != "f" && str != "n")   {
    do_gender();
    return;
  }
  switch(str)    {
    case "f":  __monster["gender"] = "female";  break;
    case "n":  __monster["gender"] = "neutar";  break;
    default:   __monster["gender"] = "male";
  }
  menu();
}

void menu()    {
  write("\nKLF Monster Making Menu: (loaded: "+__monster["file name"]+")\n\n"+
  "  1) Query Long               2) Query Short\n"+
  "  3) Query Ids                4) Query Level\n"+
  "  5) Query Name               6) Query Body Type\n"+
  "  7) Query Race               8) Set Long\n"+
  "  9) Set Short               10) Set Ids\n"+
  " 11) Set Level               12) Set Name\n"+
  " 13) Set Body Type           14) Set Race\n"+
  " 15) Query Gender            16) Set Gender\n"+
  " 17) Quit                    18) Save to file\n");
  message("prompt",PROMPT,this_player());
  input_to("menu_input");
}

void menu_input(string str)    {
  int choice;
  if(!str || sscanf(str,"%d",choice) != 1)   {
    write("\nInvalid Choice.\n");
    menu();
    return;
  }
  sscanf(str,"%d",choice);
    switch(choice)    {
      case 1: do_query("long"); break;
      case 2: do_query("short"); break;
      case 3: do_query("ids"); break;
      case 4: do_query("level"); break;
      case 5: do_query("name"); break;
      case 6: do_query("body type"); break;
      case 7: do_query("racee name"]+")\n\n"+
  "  1) Query Long               2) Query Short\n"+
  "  3) Query Ids                4) Query Level\n"+
  "  5) Query Name               6) Query Body Type\n"+
  "  7) Query Race               8) Set Long\n"+
  "  9) Set Short               10) Set Ids\n"+
  " 11) Set Level               12) Set Name\n"+
  " 13) Set Body Type           14) Set Race\n"+
  " 15) Query Gender            16) Set Gender\n"+
  " 17) Quit                    18) Save to file\n");
  message("prompt",PROMPT,this_player());
  input_to("menu_input");
}

void menu_input(string str)    {
  int choice;
  if(!str || sscanf(str,"%d",choice) != 1)   {
    write("\nInvalid Choice.\n");
    menu();
    return;
  }
  sscanf(str,"%d",choice);
    switch(choice)    {
      case 1: do_query("long"); break;
      case 2: do_query("short"); break;
      case 3: do_query("ids"); break;
      case 4: do_query("level"); break;
      case 5: do_query("name"); break;
      case 6: do_query("body type"); break;
      case 7: do_query("race"); break;
      case 8: do_long(); break;
      case 9: do_short(); break;
      case 10: do_ids(); break;
      case 11: do_level(); break;
      case 12: do_name(); break;
      case 13: do_body_type(); break;
      case 14: do_race(); break;
      case 15: do_query("gender"); break;
      case 16: do_gender(); break;
      case 17:
        write("\nEdit aborted.");
        __monster = ([  ]);
        return;
        break;
      case 18:
        if(write_to_file() != 1)
          write("\nKLF: Error while writing to file "+__monster["file name"]);
            else write("\nMonster written to file.");
        __monster = ([  ]);
        return;
        break;
      default: 
        write("Invalid choice.");
        menu();
    }
}
  
string return_ids()    {
  string temp, *ids;
  int i;
  temp = "";
  ids = __monster["ids"];
  if(!ids || sizeof(ids) < 1) return "\"monster\"";
  for(i=0;i<sizeof(ids);i++) temp += "\""+ids[i]+"\",";
  return temp;
}
  
int write_to_file()    {
  if(file_size(__monster["file name"]) > 0) rm(__monster["file name"]);
  write_file(__monster["file name"],
  "//  Created by KLF Monster Maker "+ctime(time())+"\n"+
  "//  Monster by "+this_player()->query_name()+"\n\n"+
  "inherit \"std/monster\";\n\n"+
  "void create()    {\n"+
  "  ::create();\n"+
  "  set_name(\""+__monster["name"]+"\");\n"+
  "  set_short(\""+__monster["short"]+"\");\n"+
  "  set_id(({"+return_ids()+"}));\n"+
  "  set_long(\n"+
  "@TEXT\n"+
    __monster["long"]+
  "TEXT\n"+
  ");\n"+
  "  set_body_type(\""+__monster["body type"]+"\");\n"+
  "  set(\"race\",\""+__monster["race"]+"\");\n"+
  "  set_level("+__monster["level"]+");\n"+
  "  set_gender(\""+__monster["gender"]+"\");\n"+
  "}\n");
  call_other("/cmds/system/_update","cmd_update",__monster["file name"]);
  return 1;
}        

void help()    {
  write(
@TEXT
Commands for KLF Monster Maker Version 1.0:

make <monster>      : Creates a monster with file name <monster>
edit <monster>      : Edits a monster with file name <monster>

Please do NOT enter full path names as the monster name, it will
use your current directory as the destination.  NOTE: Editing existing
monsters that were NOT generated by this device may result in loss
of extra code within the original file.

(Send problems or comments to Kriton@Orion II).
TEXT
  );
}