/*_________________________________________________________________

                          Monster Maker
                             Coded by
                           Tinks@Circle
  _________________________________________________________________*/
#include <std.h>
#include <ansi.h>
#include <security.h>
#include "/cmds/creator/make/m_monster.h"

inherit OBJECT;

int toggle;
int add;
mapping __monster;
string *__dids;
string long,objectx;

void menu();
int write_to_file();
void load_monster(string mon_path);
int display_txt(string str);

/*_____________________________DEFAULTS______________________________________*/
void load_defaults()    {


  __dids = ({ });
  __monster["race"] = "human";
  __monster["level"] = 1;
  __monster["body type"] = "human";
  __monster["long"] = "a monster created by Monster Maker set Long next time.";
  __monster["short"] = "a generic monster";
  __monster["ids"] = ({ "monster", "generic monster" });
  __monster["name"] = "generic";
  __monster["gender"] = "neutar";
  __monster["hp"] = 0;
  __monster["ini_hp"] = 0;
  __monster["ac"] = 0;
  __monster["attack"] = 0;
  __monster["xp"] = 0;
  __monster["chat"] = 0;
  __monster["emote"] = 0;
  __monster["objects"] = ([  ]);
  __monster["spells"] = ([  ]);
}

/*______________________MAIN FUNCTION TO MAKE MONSTER______________________*/

int start_up(string filename)    {

  seteuid(UID_CRESAVE);
  __monster=([]);
  __monster["file name"] = filename;
  load_defaults();
  menu();
  return 1;
}

/*____________________________EDIT MONSTER__________________________*/

int edit_monster(string str)    {
  string path, temp;

  if(!str)   {
    notify_fail("ERROR: Missing arguement to monster maker.\n");
    return 0;
  }
  path = this_player()->get_path();
  if(sscanf(str,"%s.c",temp) != 1) path += "/" + str + ".c";
    else path += "/" + str;
  if(!MASTER->valid_read(path,this_player()))   {
    notify_fail("ERROR: Permission Denied.\n");
    return 0;
  }
  if(file_size(path) < 0)    {
    switch(file_size(path))    {
      case -2: notify_fail("ERROR: "+path+" is a directory.\n"); break;
      case -1: notify_fail("ERROR: "+path+" does not exist.\n"); break;
      default: notify_fail("ERROR: Error, could not load file "+path+"\n");
    }
    return 0;
  }
  __monster = ([  ]);
  __monster["file name"] = path;
  load_monster(path);
  menu();
  return 1;
}

/*__________________________LOAD A PREV MONSTER__________________________*/

void load_monster(string mon_path)    {
  string *lines;
  object test;

  test = new(mon_path);

  if(!test)    {
    write("ERROR: Could not restore "+mon_path);
    write("ERROR: Using defaults");
    load_defaults();
    return;
  }

  __monster["ids"] = (string *)test->query_id();
  __monster["emote"] = (string *)test->query_emotes();
  __monster["short"] = (string)test->query_short();
  __monster["long"] = (string)test->query("long");
  __monster["name"] = (string)test->query_name();
  __monster["race"] = (string)test->query("race");
  __monster["body type"] = (string)test->query_body_type();
  __monster["level"] = (int)test->query_level();
  __monster["maxhp"] = (int)test->query_max_hp();
  __monster["ini_hp"] = (int)test->query_hp();
  __monster["maxsp"] = (int)test->query_max_sp();
  __monster["ini_sp"] = (int)test->query_sp();
  __monster["gender"] = (string)test->query_gender();
}

void pause(string str)   {   menu();   }

/*____________________________QUERY FUNC______________________________*/

void do_query(string str)    {
  string what,*temp;
  int i;

  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  if(str == "objects") {
       temp = (keys(__monster[str]));
       what = "";
       for(i=0;i<sizeof(temp);i++)    {
          what += temp[i] + ":" + __monster[str][temp[i]] + "\n";
       }
  }

  if (!((str == "ids")||(str=="force_me")||(str == "wlimbs")||(str == "language")||(str == "chat")||(str == "emote")||(str == "spells")))  {
    what = __monster[str];
    if(!what) what = "Undefined";
  } else {
    temp = __monster[str];
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

/*_______________________________LONG___________________________________*/

void do_long()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  write("\nEnter long description of monster(use \"**\" or \".\" to quit):");
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

/*_______________________________SHORT___________________________________*/

void do_short()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","\nEnter short description of monster: ",this_player());
  input_to("enter_short");
}

void enter_short(string str)    {
  if(!str || strlen(str) < 2) do_short();
    else  {
      __monster["short"] = str;
      menu();
    }
}

/*_______________________________IDS TYPE________________________________*/

void do_ids_type(string str)    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  switch(str){
      case "ids"      : write("\nEnter monster IDs below (\"**\" or \".\" to quit):");
                        break;
      case "language" : write("\nEnter monster Languages below (\"**\" or \".\" to quit):");
                        break;
      case "spells"   : write("\nEnter monster Spells below (\"**\" or \".\" to quit):");
                        break;
      case "wlimbs"   : write("\nEnter monster Wielding Limbs below (\"**\" or \".\" to quit):");
                        break;
      case "force_me" : write("\nEnter monster's Fored actions apon creation below (\"**\" or \".\" to quit):");
                        break; 
      default :
          write ("Error Accured Inform Tinks about it and explain how it accured.");
  }
  write("Enter one item per line.");
  message("prompt",EDIT_PROMPT,this_player());
  if (!add)
      __monster[str] = ({  });
  input_to("enter_ids_type",str);
}

void enter_ids_type(string str,string what)    {
  if(str != "**" && str != ".")    {
    __monster[what] += ({ str });
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_ids_type",what);
    return;
  }
  if(sizeof(__monster[what]) < 1)   {
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_ids_type",what);
  }
  menu();
}


/*_________________________________SET NUMBER_____________________________________*/

void do_number(string str)    {
 if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  switch (str) {

      case "ini_sp":
          message("prompt","\nEnter monster's Initial Stamina points: ",this_player());
          break;
      case "ini_hp":

          message("prompt","\nEnter monster's Initial Hit points: ",this_player());

          break;
      case "hp":
          message("prompt","\nEnter monster's Max Hit points: ",this_player());
          break;
      case "level":
          message("prompt","\nEnter monster's Level: ",this_player());
          break;
      case "ac":
          message("prompt","\nEnter monster's Overall AC: ",this_player());
          break;
      case "xp":
          message("prompt","\nEnter monster's Experience points: ",this_player());
          break;
      case "fingers":
          message("prompt","\nEnter monster's number of Fingers: ",this_player());
          break;

      case "wimpy":

          message("prompt","\nEnter monster's Wimpy percentage: ",this_player());
          break;
      case "maxsp":

          message("prompt","\nEnter monster's Maximum Stamina points: ",this_player());
          break;
      case "moving":
          message("prompt","\nEnter monster's [0] Non moving [1] Moves: ",this_player());
          break;
      case "mspeed":
          message("prompt","\nEnter monster's Moving Speed in seconds: ",this_player());
          break;
      case "spchance":
          message("prompt","\nEnter monster's Chance per second to cast a spell: ",this_player());
          break;
      default : return;
    }

  input_to("enter_number",str);
}

void enter_number(string str,string what)   {
  int num;
  if(!str || sscanf(str,"%d",num) != 1) do_number(what);
    else  {
      sscanf(str,"%d",num);
      __monster[what] = num;

      if (what == "moving"){
          if (num == 1)
              do_number("mspeed");
      }

      menu();
    }
}

/*_______________________________NAME______________________________________*/

void do_name(string str)    {

   if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  switch (str) {
      case "name":
          message("prompt","\nEnter monster's name: ",this_player());
          break;
      case "wimpyhome":
          message("prompt","\nEnter monster's first choice direction to wimpy ex. (north) (south):\n",this_player());
          break;
      case "class":
          message("prompt","\nEnter monster's Class:",this_player());
          break;
      default :
          write("ERROR: NAME FUNC PROBLEMS please notify tinks of this error and when it happened");
  }
  input_to("enter_name",str);
}

void enter_name(string str,string what)    {
  if(!str) do_name(what);
    else  {
      __monster[what] = str;
      menu();
    }
}

/*____________________________BODY TYPE____________________________________*/

void do_body_type()    {
   if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","\nEnter body type (\"?\" for list): ",this_player());
  input_to("enter_body");
}

void enter_body(string str)    {
 if(!str) { do_body_type();  return;   }
  if(str == "?")    {
    display_txt(TXTPATH+RACE_FILE);
    return;
  }
  __monster["body type"] = str;
  menu();
}

/*________________________________RACE____________________________________*/

void do_race()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","Enter monster's Race: ",this_player());
  input_to("enter_race");
}

void enter_race(string str)    {
  if(!str)   {   do_race();  return;   }
  __monster["race"] = str;
  menu();
}

/*________________________________GENDER___________________________________*/

void do_gender()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","\nEnter monster's Gender[m/f/n]: ",this_player());
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


/*______________________________ATTACK YES NO_________________________________*/

void do_att()    {
   if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","\nEnter monster's is [0]=Attackable [1]=Not Attackable: ",this_player());
  input_to("enter_att");
}

void enter_att(string str)   {
  int at;
  if(!str || sscanf(str,"%d",at) != 1) do_att();
    else  {
      sscanf(str,"%d",at);
      if  ((at > 1)||(at < 0)) do_att();
      __monster["atttack"] = at;
      menu();
    }
}



/*__________________________WHAT IS EMOTTED________________________________*/

void do_emote()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  write("\nEnter monster's Emotes below (\"**\" or \".\" to quit):");
  message("prompt",EDIT_PROMPT,this_player());
  if (!add)
      __monster["emote"] = ({  });
  input_to("enter_emote");
}

void enter_emote(string str)    {
  if(str != "**" && str != ".")    {
    __monster["emote"] += ({ str });
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_emote");
    return;
  }
  if(sizeof(__monster["emote"]) < 1)   {
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_emote");
  }
  menu();
}

/*________________________________EMOTE SPEED_____________________________*/
void do_esp()    {
   if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","\nEnter monster's Emote speed percentage per heartbeat: ",this_player());
  input_to("enter_esp");
}

void enter_esp(string str)   {
  int esp;
  if(!str || sscanf(str,"%d",esp) != 1) do_esp();
    else  {
      sscanf(str,"%d",esp);
      __monster["esp"] = esp;
      do_emote();
    }
}


/*________________________________WHAT IS CHATTED__________________________*/

void do_chat()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  write("\nEnter monster's Chats below (\"**\" or \".\" to quit):");
  message("prompt",EDIT_PROMPT,this_player());
  if (!add)
      __monster["chat"] = ({  });
  input_to("enter_chat");
}

void enter_chat(string str)    {
  if(str != "**" && str != ".")    {
    __monster["chat"] += ({ str });
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_chat");
    return;
  }
  if(sizeof(__monster["chat"]) < 1)   {
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_chat");
  }
  menu();
}


/*________________________________CHAT SPEED__________________________________*/

void do_csp()    {
   if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  message("prompt","\nEnter monster's Chats speed number is the percentage per heatbeat: ",this_player());
  input_to("enter_csp");
}

void enter_csp(string str)   {
  int csp;
  if(!str || sscanf(str,"%d",csp) != 1) do_csp();
    else  {
      sscanf(str,"%d",csp);
      __monster["csp"] = csp;
      do_chat();
    }
}

/*_____________________________OBJECT INSERTER_____________________________*/

void input_objects()   {


  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);

  write("In the space below you may enter the pathname of an object \n"+
        "you would like to see put on the monster upon clone.\n"+
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
    write("Please give one ID that this(object) item will respond to.");
    write("("+objectx+")");
    message("prompt","\nID> ",this_player());
    input_to("enter_object_id");
    return;
  }  else
  menu();
}

void enter_object_id(string str)    {
  if(!str)   {
    write("Please give one ID that this(objject) item will respond to.");
    write("("+objectx+")");
    message("prompt","\nID> ",this_player());
    input_to("enter_object_id");
    return;
  }
  __monster["objects"][objectx] = str;
  input_objects();
}



int display_txt(string str){
    string tmp;

    tmp="No help file "+str+".\n";
    if(file_size(str)>0)
      tmp = read_file(str);
    message("system", tmp, this_player());
    write("PRESS <ENTER> TO CONITNUE!");
    input_to("menu");
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
/*_________________________________MENU_____________________________________*/

void menu()    {
  if((member_array(TERM,OK_TERMS) != -1)&&(toggle)) write(CLS);
  write("%^BLUE%^%^BOLD%^"+
  "                          Monster builder "+VERSION+"%^RESET%^\n"+
  " Currently editing: "+__monster["file name"]+"\n"+
  " Use <set>,<see>,<help> for the following words\n\n"
  +did("set ids")         +" ids          "
  +did("set name")        +" name         "
  +did("set short")       +" short        "
  +did("set long")        +" long         "
  +did("set xp")          +" xp           \n"
  +did("set body")        +" body         "
  +did("set gender")      +" gender       "
  +did("set level")       +" level        "
  +did("set maxhp")       +" maxhp        "
  +did("set starthp")     +" starthp      \n"
  +did("set race")        +" race         "
  +did("set ac")          +" ac           "
  +did("set emotes")      +" emotes       "
  +did("set language")    +" language     "
  +did("set chats")       +" chats        \n"
  +did("set attacks")     +" attacks      "
  +did("set objects")     +" objects      "
  +did("set spells")      +" spells       "
  +did("set fingers")     +" fingers      "
  +did("set maxsp")       +" maxsp        \n"
  +did("set startsp")     +" startsp      "
  +did("set moving")      +" moving       "
  +did("set wimpy")       +" wimpy        "
  +did("set wimpydir")    +" wimpydir     "
  +did("set spell chance")+" spell chance \n"
  +did("set wieldlimbs")  +" wield limbs  "
  +did("set class")       +" class        "
  +did("set force_me")    +" force_me     \n\n"
  "%^WHITE%^%^BOLD%^"
  "  help         "
  "  abort        "
  "  save         \n"
  "%^RESET%^"
  );

  message("prompt",PROMPT,this_player());
  input_to("menu_input");
}

/*_______________________________MAIN MENU_________________________________*/
void menu_input(string str)    {
  string choice;
  if(!str)   {
    write("\nInvalid Choice.\n");
    menu();
    return;
  }
    add = 0;
    switch(str)    {

      case  "help"          : display_txt(HELP_TXT);
                              input_to("pause");
                              break;
      /*******************************************************/
      case  "set name"      : do_name("name");
                              set_did(str);
                              break;
      case  "see name"      : do_query("name"); break;
      case  "help name"     : display_txt(TXTPATH+NAME_FILE); break;
      /*******************************************************/
      case  "add ids"       : add = 1;
      case  "set ids"       : do_ids_type("ids");
                              set_did(str);
                              break;

      case  "see ids"       : do_query("ids"); break;
      case  "help ids"      : display_txt(TXTPATH+IDS_FILE); break;
      /*******************************************************/
      case  "set short"     : do_short();
                              set_did(str);
                              break;
      case  "see short"     : do_query("short"); break;
      case  "help short"    : display_txt(TXTPATH+SHORT_FILE); break;
      /*******************************************************/
      case  "set long"      : do_long();
                              set_did(str);
                              break;
      case  "see long"      : do_query("long"); break;
      case  "help long"     : display_txt(TXTPATH+LONG_FILE); break;
      /*******************************************************/
      case  "set body"      : do_body_type();
                              set_did(str);
                              break;
      case  "see body"      : do_query("body type"); break;
      case  "help body"     : display_txt(TXTPATH+BODY_FILE); break;
      /*******************************************************/
      case  "set race"      : do_race();
                              set_did(str);
                              break;
      case  "see race"      : do_query("race"); break;
      case  "help race"     : display_txt(TXTPATH+RACE_FILE); break;
      /*******************************************************/
      case  "set gender"    : do_gender();
                              set_did(str);
                              break;
      case  "see gender"    : do_query("gender"); break;
      case  "help gender"   : display_txt(TXTPATH+GENDER_FILE); break;
      /*******************************************************/
      case  "set level"     : do_number("level");
                              set_did(str);
                              break;
      case  "see level"     : do_query("level"); break;
      case  "help level"    : display_txt(TXTPATH+LEVEL_FILE); break;
      /*******************************************************/
      case  "set xp"        : do_number("xp");
                              set_did(str);
                              break;
      case  "see xp"        : do_query("xp"); break;
      case  "help xp"       : display_txt(TXTPATH+STARTXP_FILE); break;
      /*******************************************************/
      case  "set maxhp"     : do_number("hp");
                              set_did(str);
                              break;
      case  "see maxhp"     : do_query("hp"); break;
      case  "help maxhp"    : display_txt(TXTPATH+MAXHP_FILE); break;
      /*******************************************************/
      case  "set starthp"   : do_number("ini_hp");
                              set_did(str);
                              break;
      case  "see starthp"   : do_query("ini_hp"); break;
      case  "help starthp"  : display_txt(TXTPATH+STARTHP_FILE); break;
      /*******************************************************/
      case  "set ac"        : do_number("ac");
                              set_did(str);
                              break;
      case  "see ac"        : do_query("ac"); break;
      case  "help ac"       : display_txt(TXTPATH+AC_FILE); break;
      /*******************************************************/
      case  "add emotes"    : add = 1;
      case  "set emotes"    : do_esp();
                              set_did(str);
                              break;
      case  "see emotes"    : do_query("emote"); break;
      case  "help emotes"   : display_txt(TXTPATH+EMOTES_FILE); break;
      /*******************************************************/
      case  "add language"  : add = 1;
      case  "set language"  : do_ids_type("language");
                              set_did(str);
                              break;
      case  "see language"  : do_query("language"); break;
      case  "help language" : display_txt(TXTPATH+LANGS_FILE); break;
      /*******************************************************/
      case  "add chats"     : add = 1;
      case  "set chats"     : do_csp();
                              set_did(str);
                              break;
      case  "see chats"     : do_query("chat"); break;
      case  "help chats"    : display_txt(TXTPATH+CHATS_FILE); break;
      /*******************************************************/
      case  "set attacks"   : do_att();
                              set_did(str);
                              break;
      case  "see attacks"   : do_query("attack"); break;
      case  "help attacks"  : display_txt(TXTPATH+ATTACKS_FILE); break;
      /*******************************************************/
      case  "add objects"   : add = 1;
      case  "set objects"   : input_objects();
                              set_did(str);
                              break;
      case  "see objects"   : do_query("objects"); break;
      case  "help objects"  : display_txt(TXTPATH+OBJECTS_FILE); break;
      /*******************************************************/
      case  "add spells"    : add = 1;
      case  "set spells"    : do_ids_type("spells");
                              set_did(str);
                              break;
      case  "se: do_query("chat"); break;
      case  "help chats"    : display_txt(TXTPATH+CHATS_FILE); break;
      /*******************************************************/
      case  "set attacks"   : do_att();
                              set_did(str);
                              break;
      case  "see attacks"   : do_query("attack"); break;
      case  "help attacks"  : display_txt(TXTPATH+ATTACKS_FILE); break;
      /*******************************************************/
      case  "add objects"   : add = 1;
      case  "set objects"   : input_objects();
                              set_did(str);
                              break;
      case  "see objects"   : do_query("objects"); break;
      case  "help objects"  : display_txt(TXTPATH+OBJECTS_FILE); break;
      /*******************************************************/
      case  "add spells"    : add = 1;
      case  "set spells"    : do_ids_type("spells");
                              set_did(str);
                              break;
      case  "see spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      casee spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      casee spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      casee spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      casee spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      casee spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      casee spells"    : do_query("spells"); break;
      case  "help spells"   : display_txt(TXTPATH+SPELLS_FILE); break;
      /*******************************************************/
      case  "set fingers"   : do_number("fingers");
                              set_did(str);
                              break;
      case  "see fingers"   : do_query("fingers"); break;
      case  "help fingers"  : display_txt(TXTPATH+FINGERS_FILE); break;
      /*******************************************************/
      case  "set maxsp"     : do_number("maxsp");
                              set_did(str);
                              break;
      case  "see maxsp"     : do_query("maxsp"); break;
      case  "help maxsp"    : display_txt(TXTPATH+MAXSP_FILE); break;
      /*******************************************************/
      case  "set startsp"   : do_number("ini_sp");
                              set_did(str);
                              break;
      case  "see startsp"   : do_query("ini_sp"); break;
      case  "help startsp"  : display_txt(TXTPATH+STARTSP_FILE); break;
      /*******************************************************/
      case  "add wield limbs" : add = 1;
      case  "set wield limbs" : do_ids_type("wlimbs");
                              set_did(str);
                              break;
      case  "see wield limbs" : do_query("wlimbse"); break;
      case  "help wield limbs": display_txt(TXTPATH+WLIMBS_FILE); break;
      /*******************************************************/
      case  "set moving"    : do_number("moving");
                              set_did(str);
                              break;
      case  "see moving"    : do_query("moving"); break;
      case  "help moving"   : display_txt(TXTPATH+MOVING_FILE); break;
      /*******************************************************/
      case  "set wimpy"     : do_number("wimpy");
                              set_did(str);
                              break;
      case  "see wimpy"     : do_query("wimpy"); break;
      case  "help wimpy"    : display_txt(TXTPATH+WIMPY_FILE); break;
      /*******************************************************/
      case  "set wimpydir" : do_name("wimpyhome");
                              set_did(str);
                              break;
      case  "see wimpydir" : do_query("wimpyhome"); break;
      case  "help wimpydir"    : display_txt(TXTPATH+WIMPYDIR_FILE); break;
      /*******************************************************/
      case  "set class"     : do_name("class");
                              set_did(str);
                              break;
      case  "see class"     : do_query("class"); break;
      case  "help class"    : display_txt(TXTPATH+CLASS_FILE); break;
      /*******************************************************/
      case  "add force_me"     : add = 1;
      case  "set force_me"     : do_ids_type("force_me");
                                 set_did(str);
                                 break;
      case  "see force_me"     : do_query("force_me"); break;
      case  "help force_me"    : display_txt(TXTPATH+FORCE_FILE); break;
      /*******************************************************/
      case  "exit" :
      case  "quit" :
      case  "abort":
        write("\nEdit aborted.");
        __monster = ([  ]);
        destruct(this_object());
        return;
        break;
      case "save":
      case "done":
        if(write_to_file() != 1)
          write("\nERROR: Error while writing to file "+__monster["file name"]);
            else write("\nMonster written to file.");
        __monster = ([  ]);
        destruct(this_object());
        return;
        break;
      default:
        write("Invalid choice.");
        menu();
    }
}

/*_____________________________WRITE SETUPS_____________________________*/

/*___________________RETURN ARRAY STRING___________________*/
string return_ids() {
  string temp, *ids;
  int i;
  temp = "";
  ids = __monster["ids"];
  if(!ids || sizeof(ids) < 1) return "\"monster\"";
  for(i=0;i<sizeof(ids);i++) temp += "\""+ids[i]+"\",";
  return temp;
}

string return_string(string str) {
  string temp;

  temp = __monster[str];
  if(!temp) return "";
  switch (str){
     case "wimpydir" : return "\tset_wimpydir("+temp+");\n";
     case "class"    : return "\tset_class("+temp+");\n";
     default :
          write ("ERROR: inform tinks of this and explain what you where doin.");
    }
}

string return_ids_like(string str) {
  string temp, *which;
  int i;
  temp = "";
  which = __monster[str];
  if(!which || sizeof(which) < 1) return " ";

  for(i=0;i<sizeof(which)-1;i++) temp += "\""+which[i]+"\",";
  temp += "\""+which[i]+"\"";
  switch(str){
      case "spells" :  return  "\tset_spells(({"+temp+"}));";
      case "wlimbs" :  return  "\tset_wielding_limbs(({"+temp+"}));";
      default :
          write("ERROR report this to Tinks and explain what you were doing.");
  }

 return "";
}

string return_e(string str)    {
  string temp, *emote;
  int i;
  temp = "";
  emote = __monster[str];
  if(!emote || sizeof(emote) < 1) return " ";

  for(i=0;i<sizeof(emote)-1;i++) temp += "\""+emote[i]+"\",";
  temp += "\""+emote[i]+"\"";
  switch(str){
      case "emote" : return  "\tset_emotes("+__monster["esp"]+",({"+temp+"}),0);";
      case "chat"  : return  "\tset_emotes("+__monster["csp"]+",({"+temp+"}),0);";
      default :
          write("ERROR report this to Tinks and explain what you were doing.");
  }
}

string return_force(string str)    {
  string temp, *force;
  int i;
  temp = "";
  force = __monster[str];
  if(!force || sizeof(force) < 1) return " ";

  temp = "\n";
  for(i=0;i<sizeof(force);i++)
         temp += "\t this_player()->force_me(\""+force[i]+"\");\n";
  temp += "\n";
  return temp;
}


/*__________________________FILL OBJECTS________________________*/

string fill_objects()   {
  string temp, *tmp;
  int i;

  temp = "\n\n";
  tmp = keys(__monster["objects"]);
  for(i=0;i<sizeof(tmp);i++)   {
//    temp += "\tif(!present(\""+__monster["objects"][tmp[i]]+"\"))\n";
    temp += "\t\tnew(\""+tmp[i]+"\")->move(this_object());\n";
  }
  temp += "\n";
  return temp;
}

/*---------------------RETURN REG STRING--------------------*/
string return_number(string str)   {
    int num;

    num = __monster[str];

    if (num!=0)
        switch(str) {
            case "hp"      : return "\tset_max_hp("+num+");\n";
            case "ini_hp"  : return "\tset_hp("+num+");\n";
            case "xp"      : return "\tset_max_hp("+num+");\n";
            case "attack"  : return "\tset_property(\"no attack\");\n";
            case "ac"      : return "\tset_overall_ac("+num+");\n";
            case "level"   : return "\tset_level("+num+");\n";
            case "maxsp"   : return "\tset_max_sp("+num+");\n";
            case "ini_sp"  : return "\tset_sp("+num+");\n";
            case "fingers" : return "\tset_fingers("+num+");\n";
            case "spchance": return "\tset_spell_chance("+num+");\n";
            case "wimpy"   : return "\tset_wimpy("+num+");\n";
            case "moving"  : return "\tset_moving(1);\n   set_speed("+__monster["mspeed"]+");\n";
            default :
                write ("Program ERROR infor Tinks of what happened and how");
        }
    else
        return "";
}

/*______________________________WRITE FILE________________________________*/

int write_to_file()    {
  write_file(__monster["file name"],
  "//  Created by Monster Maker "+ctime(time())+"\n"+
  "//  Monster by "+this_player()->query_name()+"\n\n"+
  "#include <std.h>\n"+
  "inherit MONSTER;\n\n"+
  "void create()    {\n"+
  "\t::create();\n"+
  "\tset_name(\""+__monster["name"]+"\");\n"+
  "\tset_short(\""+__monster["short"]+"\");\n"+
  "\tset_id(({"+return_ids()+"}));\n"+
  return_number("hp")+
  return_number("ac")+
  return_number("attack")+
  return_number("xp")+
  return_number("level")+
  return_number("maxsp")+
  return_number("inisp")+
  return_number("fingers")+
  return_number("spchance")+
  return_number("moving")+
  return_number("wimpy")+
  return_string("wimpyhome")+
  "\tset_long(\n"+
  "@TEXT\n"+
    __monster["long"]+
  "\nTEXT\n"+
  ");\n"+
  "\tset_body_type(\""+__monster["body type"]+"\");\n"+
  "\tset(\"race\",\""+__monster["race"]+"\");\n"+
  "\tset_gender(\""+__monster["gender"]+"\");\n"+
  return_e("emote")+"\n"+
  return_e("chat")+"\n"+
  return_ids_like("spells")+"\n"+
  return_ids_like("wlimbs")+"\n"+
  fill_objects()+
  return_force("force_me")+
  "}\n"
  );


  call_other("/cmds/system/_update","cmd_update",__monster["file name"]);
  destruct(this_object());
  return 1;
}

/*______________________________HELP__________________________________*/

void help()    {
   write(
@TEXT
%^BLUE%^%^BOLD%^Monster Maker%^RESET%^

Known Coder: Tinks & Kriton

Current Commands:
-----------------
makemonster <monster> <cmd>  : Creates a monster with file name <monster>
editmonster <monster> <cmd>  : Edits a monster with file name <monster>

cmd:
-----
-nocls : Use this if you do not want the clear screen option.

Please do NOT enter full path names as the monster name, it will
use your current directory as the destination.

NOTE: Editing existing monsters that were NOT generated by this
      device may result in loss of extra code within the original file.
      Even so some things about the monster will be lost while in
      this program <help editor> for more information on it.

TEXT
  );
}
