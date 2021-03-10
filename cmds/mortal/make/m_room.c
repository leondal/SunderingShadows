/*____________________________________________________________________
                             Make Room
                                by
                            Tinks@Circle
                             and Kriton
  ____________________________________________________________________*/
#include <std.h>
#include <security.h>
#include <ansi.h>
#include "/cmds/creator/make/m_room.h"


inherit OBJECT;

string *__dids;
mapping __roominfo;
int toggle;
string long, exitx, itemx, objectx, soundx, smellx;

void menu();
void print_query(string subj);


/*__________________________OBJECT INIT_______________________________*/
/*____________________________________________________________________*/
void load_defaults()    {
  __roominfo["exits"] = ([  ]);
  __roominfo["items"] = ([  ]);
  __roominfo["short"] = "A Generic Room.";
  __roominfo["long"] = "A generic looking room which should have me here.\n";
  __roominfo["light"] = 2;
  __roominfo["indoors"] = 1;
  __roominfo["objects"] = ([  ]);
  __roominfo["smells"] = ([  ]);
  __roominfo["sounds"] = ([  ]);
  __roominfo["invis exits"] = ({  });
}

// **** add_action()'s **** //

/*____________________________MAKER___________________________________*/
int start_up(string filename)    {

    seteuid(UID_CRESAVE);
    __roominfo = ([  ]);
    __roominfo["filename"] = filename;
    __dids = ({ });
    load_defaults();
  menu();
  return 1;
}

/*__________________________PAUSE_____________________________________*/
void pause2(string str) {
    menu();
}

void pause()    {

  message("prompt","Press <enter> to continue...",this_player());
  input_to("pause2");
}

/*__________________________LONG______________________________________*/
void input_long(string str) {

    if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

    switch(str){
          case "long"     :
                write("Please enter your long description below: (\"**\" or \".\" to quit)");
                break;
          case "day long" :
                write("Please enter your day long description below: (\"**\" or \".\" to quit)");
                break;
          case "night long":
                write("Please enter your night long description below: (\"**\" or \".\" to quit)");
                break;
    }

    message("prompt",PROMPT,this_player());
    long = "";
    input_to("enter_long",str);
}

enter_long(string str,string str2) {

  if(str != "**" && str != ".")    {
     long += str + "\n";
     message("prompt",PROMPT,this_player());
     input_to("enter_long",str2);
  }  else  {
     __roominfo[str2] = long;
     menu();
  }
}
/*__________________________SHORT_____________________________________*/
void input_short()   {

  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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

/*_______________________EXITS_____________________________*/
void input_exits()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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

/*___________________________ITEMS___________________________________*/
void input_items()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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

/*___________________________LIGHT_________________________________*/
void input_light()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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

/*____________________________________________________________________*/
void input_indoors()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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

/*___________________________ABORT____________________________________*/
void abort()   {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  write("\nEdit aborted file not written.");
  destruct(this_object());
}

/*________________________WRITTING SETUP______________________________*/
string fill_mapping(string str)    {
  int i;
  string temp, *guint;
  temp = "";
  guint = keys(__roominfo[str]);
  for(i=0;i<sizeof(guint);i++)    {
    temp += "\"" + guint[i] + "\":" + "\"";
    temp += __roominfo[str][guint[i]] + "\",\n";
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
string slong(string str){
  string temp;
  temp = __roominfo[str];
  if (!temp) return "\n";
  return "    set(\""+str+"\",\""+temp+"\");\n";
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

/*________________________SAVE FILE AND EXIT_________________________*/
void save_and_quit()    {
  int x;
  string file;

  if(file_size(__roominfo["filename"]) > 0)
    rm(__roominfo["filename"]);
  file=
  "//  Room created using Makeroom "+VERSION+"\n"+
  "//  Created "+ctime(time())+" by "+(string)TP->query_name()+"\n\n"+
  "#include <std.h>\n"+
  "inherit ROOM;\n\n"+
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
  slong("day long")+
  slong("night long")+
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
  destruct(this_object());
  return;
}

/*______________________OBJECTS____________________________*/
void input_objects()   {

  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  write("In the space below you may enter the pathname of an object \n"+
        "you would like to see put it in the room upon resets.\n"+
        "(Type \"**\" or \".\" to quit this process)\n");
  message("prompt","Pathname> ",this_player());
  input_to("enter_objects");
}

void enter_objects(string str)    {

  string temp, file;

  if(!str)  {
    input_objects();
    return;
  }

  if(str != "**" && str != ".")   {
    objectx = str;
    write("Please give one ID that this item will respond to.");
    write("("+objectx+")");
    message("prompt","\nID> ",this_player());
    input_to("enter_object_id");
    return;
  }  else
       menu();
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

/*___________________________SMELLS___________________________________*/
void input_smells()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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
  }  else menu();
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

/*_____________________________SOUNDS_________________________________*/
void input_sounds()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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
  } else menu();
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

/*________________________INVISIBLE EXITS_____________________________*/
void input_invis_exits()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
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
  }  else menu();
}

int display_txt(string str){
    string tmp;

    tmp="\nNo help file "+str+".\n";
    if(file_size(str)>0)
      tmp=read_file(str);
    message("system", tmp, this_player());
    write("Press enter to continue...\n");
    input_to("pause2");
    return 1;

}

void set_did(string str){
    if(member_array(str,__dids) == -1){
        __dids += ({str});
    }
}

string did(string str){
    if(member_array(str,__dids) != -1){
        return "%^YELLOW%^%^BOLD%^*%^RESET%^";
    } else
    return " ";
}

/*___________________________MENU____________________________________*/
void menu() {

  if(member_array(TERM,OK_TERMS) != -1) write(CLS);

  write("%^BLUE%^%^BOLD%^"+
  "              Room Maker "+VERSION+"%^RESET%^");
  write("\nCurrently editing: "+__roominfo["filename"]);
  write(" Use <set>,<see>,<help> for the following words\n\n"+
  did("set short")         +" short          "+
  did("set long")          +" long           "+
  did("set day long")      +" day long       \n"+
  did("set night long")    +" night long     "+
  did("set light")         +" light          "+
  did("set indoors")       +" indoors        \n"+
  did("set exits")         +" exits          "+
  did("set items")         +" items          "+
  did("set objects")       +" objects        \n"+
  did("set smells")        +" smells         "+
  did("set sounds")        +" sounds         "+
  did("set invisible exit")+" invisible exit \n\n"+

  "  abort          "+
  "  save           \n\n");
  message("prompt",M_PROMPT,this_player());
  input_to("selection");
}

void selection(string str)   {
  switch(str)    {
    case "set short"   : input_short();
                         set_did(str);
                         break;
    case "see short"   : print_query("short");break;
    case "help short"  : display_txt(TXTPATH+SHORT_FILE);break;


    case "set long"    : input_long("long");
                         set_did(str);
                         break;
    case "see long"    : print_query("long");break;
    case "help long"   : display_txt(TXTPATH+LONG_FILE);break;

    case "set day long"    : input_long("day long");
                         set_did(str);
                         break;
    case "see day long"    : print_query("day long");break;
    case "help day long"   : display_txt(TXTPATH+LONG_FILE);break;

    case "set night long"    : input_long("night long");
                         set_did(str);
                         break;
    case "see night long"    : print_query("night long");break;
    case "help night long"   : display_txt(TXTPATH+LONG_FILE);break;


    case "set light"   : input_light();
                         set_did(str);
                         break;
    case "see light"   : print_query("light");break;
    case "help light"  : display_txt(TXTPATH+LIGHT_FILE);break;


    case "set indoors" : input_indoors();
                         set_did(str);
                         break;
    case "see indoors" : print_query("indoors");break;
    case "help indoors": display_txt(TXTPATH+INDOORS_FILE);break;


    case "set exits"   : input_exits();
                         set_did(str);
                         break;
    case "see exits"   : print_query("exits");break;
    case "help exits"  : display_txt(TXTPATH+EXITS_FILE);break;


    case "set items"   : input_items();
                         set_did(str);
                         break;
    case "see items"   : print_query("items");break;
    case "help items"  : display_txt(TXTPATH+ITEMS_FILE);break;


    case "set objects" : input_objects();
                         set_did(str);
                         break;
    case "see objects" : print_query("objects");break;
    case "help objects": display_txt(TXTPATH+OBJECTS_FILE);break;


    case "set smells"  : input_smells();
                         set_did(str);
                         break;
    case "see smells"  : print_query("smells");break;
    case "help smells" : display_txt(TXTPATH+SMELLS_FILE);break;


    case "set sounds"  : input_sounds();
                         set_did(str);
                         break;
    case "see sounds"  : print_query("sounds");break;
    case "help sounds" : display_txt(TXTPATH+SOUNDS_FILE);break;

    case "set invisible exit"  : input_invis_exits();
                                 set_did(str);
                                 break;
    case "see invisible exit"  : print_query("invis exits");break;
    case "help invisible exit" : display_txt(TXTPATH+INVS_FILE);break;

    case "help" : display_txt(TXTPATH+HELP_FILE);break;
    case "done"  :
    case "save"  : save_and_quit(); break;
    case "quit"  :
    case "exit"  :
    case "abort" : abort(); break;
    default: write ("Invalid option"); menu();
  }
}

/*__________________________PRINT QUERY_______________________________*/

void print_query(string subj)     {
  string *guint, mess;
  int i;

  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  write("Query "+subj+"...");

  if(subj == "invis exits")   {

    guint = __roominfo["invis exits"];

    if(!guint || sizeof(guint) == 0)    {
       write("There are no invisible exits defined.");
    }  else  {
      mess = guint[0];
      for(i=0;i<sizeof(guint);i++) mess += ", "+guint[i];
      write(mess);
    }

    message("prompt","\nPress <ENTER> to continue: ",this_player());
    input_to("pause2");
    return;
  }

  if(subj == "exits" || subj == "items" ||
     subj == "smells" || subj == "objects" || subj == "sounds") {

    guint = (keys(__roominfo[subj]));
    mess = "";

    for(i=0;i<sizeof(guint);i++)    {
      mess += guint[i] + ":" + __roominfo[subj][guint[i]] + "\n";
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
%^BLUE%^%^BOLD%^Room Generator v 1.0%^RESET%^"
Known Coders: Tinks & Kriton

Current Commands:
-----------------
makeroom <filename> <cmd>: This command will allow you to generate room
                           code with an easy to use menu system.  Use
                           the -r option to restore data lost after
                           link death ( makeroom -r <filename> ).
CMD:
----
        -nocls : Use this to keep from have the screen clear.

This generator will accept the use of macros such as ~, here, etc,.
It is not as picky with names as other generators are.

(Please send all bugs or ideas to Tinks@Circle if using this for Circle else KLF).
TEXT
  );
}




