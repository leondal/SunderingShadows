/////////////////////////////////////////////////////
//  Armour Maker
//  Coder: Tinks@Circle
/////////////////////////////////////////////////////

#include <std.h>
#include <ansi.h>
#include <security.h>
#include "/cmds/creator/make/makeobj.h"
#include "/cmds/creator/make/m_armour.h"

#define VERSION "v1.0"

#define PROMPT "=> "
#define M_PROMPT "Select ==> "
#define EDIT_PROMPT "] "
#define MASTER "/adm/obj/master"
#define MONSTER_BODIES  "/adm/db/mon_races"
#define CLS ESC+"[H"+ESC+"[2J"
#define TERM (string)this_player()->getenv("TERM")
#define OK_TERMS ({ "xterm", "ansi", "ansi-status" })
#define TP  this_player()

inherit OBJECT;

mapping __armour;
string *__dids;
string long;

void menu();
int write_to_file();
void print_query(string subj);     
void load_armour(string mon_path);

void load_defaults()    {
  __dids=({});
  __armour["long"] = "an Armour created by Tinks.";
  __armour["short"] = "An Armour Maker";
  __armour["ids"] = ({ "armour", "tinks armour" });
  __armour["name"] = "armour";
  __armour["weight"] = 0;
  __armour["remove"] = " ";
  __armour["wear"] = " ";
  __armour["value"] = 0;
  __armour["poison"] = 0;
  __armour["bodyprotecte"] = ([ ]);
  __armour["type"] = ([ ]);
}

/////////////////////////////////////////////////////////////////////////
int start_up(string filename){

  seteuid(UID_CRESAVE);
  __armour=([]);
  __armour["filename"] = filename;
  load_defaults();
  menu();
  return 1;
}

/////////////////////////////////////////////////////////////////////////
void pause2(string str) {
    menu();
}

void pause()    {
  message("prompt","Press <enter> to continue...",this_player());
  input_to("pause2");
}

/////////////////////////////////////////////////////////////////////////
void input_long() {

    if(member_array(TERM,OK_TERMS) != -1) write(CLS);
       write("Please enter your long description below: (\"**\" or \".\" to quit)");
    message("prompt",PROMPT,this_player());
    long = "";
    input_to("enter_long");
}

enter_long(string str) {

  if(str != "**" && str != ".")    {
     long += str + "\n";
     message("prompt",PROMPT,this_player());
     input_to("enter_long");
  }  else  {
     __armour["long"] = long;
     menu();
  }
}

/////////////////////////////////////////////////////////////////////////
void input_short()   {

   if(member_array(TERM,OK_TERMS) != -1) write(CLS);
       message("prompt","\nEnter short description> ",this_player());
   input_to("enter_short");
}

void enter_short(string str)   {
  if(!str) input_short();
    else  {
      __armour["short"] = str;
      menu();
    }
}
/////////////////////////////////////////////////////////////////////////
void input_wear()   {

   if(member_array(TERM,OK_TERMS) != -1) write(CLS);
       message("prompt","\nEnter short description> ",this_player());
   input_to("enter_wear");
}

void enter_wear(string str)   {
  if(!str) input_short();
    else  {
      __armour["wear"] = str;
      menu();
    }
}
/////////////////////////////////////////////////////////////////////////
void input_remove()   {

   if(member_array(TERM,OK_TERMS) != -1) write(CLS);
       message("prompt","\nEnter short description> ",this_player());
   input_to("enter_remove");
}

void enter_remove(string str)   {
  if(!str) input_remove();
    else  {
      __armour["remove"] = str;
      menu();
    }
}

/////////////////////////////////////////////////////////////////////////
void input_name()   {

   if(member_array(TERM,OK_TERMS) != -1) write(CLS);
       message("prompt","\nEnter name> ",this_player());
   input_to("enter_name");
}

void enter_name(string str)   {
  if(!str) input_short();
    else  {
      __armour["name"] = str;
      menu();
    }
}

/////////////////////////////////////////////////////////////////////////
void input_ids()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("\nEnter Armour IDs below (\"**\" or \".\" to quit):");
  message("prompt",EDIT_PROMPT,this_player());
  __armour["ids"] = ({  });
  input_to("enter_ids");
}

void enter_ids(string str)    {
  if(str != "**" && str != ".")    {
    __armour["ids"] += ({ str });
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_ids");
    return;
  }
  if(sizeof(__armour["ids"]) < 1)   {
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_ids");
  }
  menu();
}

/////////////////////////////////////////////////////////////////////////
void input_limbs()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("\nEnter limbs below (\"**\" or \".\" to quit):");
  message("prompt",EDIT_PROMPT,this_player());
  __armour["limbs"] = ({  });
  input_to("enter_limbs");
}

void enter_limbs(string str)    {
  if(str != "**" && str != ".")    {
    __armour["limbs"] += ({ str });
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_limbs");
    return;
  }
  if(sizeof(__armour["limbs"]) < 1)   {
    message("prompt",EDIT_PROMPT,this_player());
    input_to("enter_limbs");
  }
  menu();
}

/////////////////////////////////////////////////////////////////////////
void input_value()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter a value in the space below.\n"+
        "Valid values is positive number which stands for the cost");
  message("prompt","\nValue> ",this_player());
  input_to("enter_value");
}

void enter_value(string str)    {
  int value;
  if(!str || sscanf(str,"%d",value) != 1)   {
    write("\nInvalid choice.");
    message("prompt","\nValue> ",this_player());
    input_to("enter_value");
    return;
  }
  sscanf(str,"%d",value);
  if(value > 10000 || value < 0)    {
    write("\nValue is out of range.");
    message("prompt","\nValue> ",this_player());
    input_to("enter_value");
    return;
  }  else   {
    __armour["value"] = value;
    menu();
  }
}


/////////////////////////////////////////////////////////////////////////
void input_ac()    {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter a value in the space below.\n"+
         "AC value is a positive number which stands for the cost");
  message("ac","\nAC> ",this_player());
  input_to("enter_ac");
}

void enter_ac(string str)    {
  int ac;
  if(!str || sscanf(str,"%d",ac) != 1)   {
    write("\nInvalid choice.");
    message("prompt","\nAC> ",this_player());
    input_to("enter_ac");
    return;
  }
  sscanf(str,"%d",ac);
  if(ac > 10000 || ac < 0)    {
    write("\nAC value is out of range.");
    message("prompt","\nAC> ",this_player());
    input_to("enter_ac");
    return;
  }  else   {
    __armour["ac"] = ac;
    menu();
  }
}

/////////////////////////////////////////////////////////////////////////
void input_weight() {
  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
    write("Please enter a weight value in the space below.\n"+
        "Valid weight is a number greater than 0");
  message("prompt","\nWeightt> ",this_player());
  input_to("enter_weight");
}

void enter_weight(string str)    {
  int weight;
  if(!str || sscanf(str,"%d",weight) != 1)   {
    write("\nInvalid choice.");
    message("prompt","\nWeight> ",this_player());
    input_to("enter_weight");
    return;
  }
  sscanf(str,"%d",weight);
  if(weight > 500000 || weight < 0)    {
    write("\nWeight value is out of range.");
    message("prompt","\nWeight> ",this_player());
    input_to("enter_weight");
    return;
  }  else   {
    __armour["weight"] = weight;
    menu();
  }
}

/////////////////////////////////////////////////////////////////////////


string return_ids()    {
  string temp, *ids;
  int i;
  temp = "";
  ids = __armour["ids"];
  if(!ids || sizeof(ids) < 1) return "\"armour\"";
  for(i=0;i<sizeof(ids);i++) temp += "\""+ids[i]+"\",";
  return temp;
}
string return_limbs()    {
  string temp, *limbs;
  int i;
  temp = "";
  limbs = __armour["limbs"];
  if(!limbs || sizeof(limbs) < 1) return "\" \"";
  for(i=0;i<sizeof(limbs);i++) temp += "\""+limbs[i]+"\",";
  return temp;
}

/////////////////////////////////////////////////////////////////
//
// DONE AND SAVE MEMORY TO FILE
//
/////////////////////////////////////////////////////////////////
int write_to_file()    {
  int x;
  string file;

  file="//  Armour created using Tinks generator \n"+
  "//  Created "+ctime(time())+" by "+(string)TP->query_name()+"\n\n"+
  "#include <std.h>\n"+
  "inherit ARMOUR;\n\n"+
  "void create()   {\n"+
  "  ::create();\n"+
  "  set_short(\""+__armour["short"]+"\");\n"+
  "  set_id(({"+return_ids()+"}));\n"+
  "  set_wear(\""+__armour["wear"]+"\");\n"+
  "  set_remove(\""+__armour["remove"]+"\");\n"+
  "  set_value("+__armour["value"]+");\n"+
  "  set_weight("+__armour["weight"]+");\n"+
  "  set_limbs(({"+return_limbs()+"}));\n"+
  "  set_long(\n"+
  "@TEXT\n"+
  __armour["long"]+
  "TEXT\n"+
  "  ); \n"+
  " }\n";
  x = write_file(__armour["filename"],file);
  return x;
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
/////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////
void menu() {

  if(member_array(TERM,OK_TERMS) != -1) write(CLS);

  write("%^GREEN%^%^BOLD%^"+
  "             Armour builder "+VERSION+"%^RESET%^");
  write("\nCurrently editing: "+__armour["filename"]);
  write(" Use <set>,<see>,<help> for the following words\n\n"
    +did("set name")            +"name         \n"
    +did("set short")           +"short        \n"
    +did("set long")            +"long         \n"
    +did("set ids")             +"ids          \n"
    +did("set wear")            +"wear         \n"
    +did("set remove")          +"remove       \n"
    +did("set ac")              +"ac           \n"
    +did("set value")            +"value        \n"
    +did("set weight")           +"weight       \n"
    +did("set limbs")            +"limbs        \n\n"
  "%^WHITE%^%^BOLD%^"
  "  help         "
  "  abort        "
  "  save         \n"
  "%^RESET%^"
  );

  message("prompt",M_PROMPT,this_player());
  input_to("enter_selection");
}

void enter_selection(string str) {

  if(!str)   {
    write("\nInvalid Choice.\n");
    menu();
    return;
  }

  switch(str)    {

      case  "help"          : display_txt(HELP_TXT);
                              input_to("pause");
                              break;
      /*******************************************************/
      case  "set name"      : input_name();
                              set_did(str);
                              break;
      case  "see name"      : print_query("name"); break;
      case  "help name"     : display_txt(TXTPATH+NAME_FILE); break;
      /*******************************************************/
      case  "set short"      : input_short();
                              set_did(str);
                              break;
      case  "see short"      : print_query("short"); break;
      case  "help short"     : display_txt(TXTPATH+SHORT_FILE); break;
      /*******************************************************/
      case  "set long"      : input_long();
                              set_did(str);
                              break;
      case  "see long"      : print_query("long"); break;
      case  "help long"     : display_txt(TXTPATH+LONG_FILE); break;
       /*******************************************************/
      case  "set ids"      : input_ids();
                              set_did(str);
                              break;
      case  "see ids"      : print_query("ids"); break;
      case  "help ids"     : display_txt(TXTPATH+IDS_FILE); break;
      /*******************************************************/
      case  "set wear"      : input_wear();
                              set_did(str);
                              break;
      case  "see wear"      : print_query("wear"); break;
      case  "help wear"     : display_txt(TXTPATH+WEAR_FILE); break;
      /*******************************************************/
      case  "set remove"      : input_remove();
                              set_did(str);
                              break;
      case  "see remove"      : print_query("remove"); break;
      case  "help remove"     : display_txt(TXTPATH+REMOVE_FILE); break;
      /*******************************************************/
      case  "set ac"      : input_ac();
                              set_did(str);
                              break;
      case  "see ac"      : print_query("ac"); break;
      case  "help ac"     : display_txt(TXTPATH+AC_FILE); break;
      /*******************************************************/
      case  "set value"      : input_value();
                              set_did(str);
                              break;
      case  "see value"      : print_query("value"); break;
      case  "help value"     : display_txt(TXTPATH+VALUE_FILE); break;
      /*******************************************************/
      case  "set weight"      : input_weight();
                              set_did(str);
                              break;
      case  "see weight"      : print_query("weight"); break;
      case  "help weight"     : display_txt(TXTPATH+WEIGHT_FILE); break;
      /*******************************************************/
      case  "set limbs"      : input_limbs();
                              set_did(str);
                              break;
      case  "see limbs"      : print_query("limbs"); break;
      case  "help limbs"     : display_txt(TXTPATH+LIMBS_FILE); break;
      /*******************************************************/

      case  "exit" :
      case  "quit" :
      case  "abort":
        write("\nEdit aborted.");
        __armour = ([  ]);
        destruct(this_object());
        return;
        break;

      case "save":
      case "done":
        if(write_to_file() != 1)
          write("\nERROR: Error while writing to file "+__armour["filename"]);
            else write("\nArmour written to file.");
        __armour = ([  ]);
        destruct(this_object());
        return;
        break;


      default:
        write("Invalid choice.");
        menu();
    }
}



void print_query(string subj)     {
  string what,*temp;
  int i;

  if(member_array(TERM,OK_TERMS) != -1) write(CLS);
  write("Query "+subj+"...");
  if((subj != "ids")&&(subj != "limbs"))  {
    what = __armour[subj];
    if(!what) what = "Undefined";
  } else if (subj == "ids"){
    temp = __armour["ids"];
    if(!temp || sizeof(temp) == 0) what = "Undefined";
      else {
        what = temp[0];
        for(i=0;i<sizeof(temp);i++) what += ", "+temp[i];
      }
  } else {

    temp = __armour["limbs"];
    if(!temp || sizeof(temp) == 0) what = "Undefined";
      else {
        what = temp[0];
        for(i=0;i<sizeof(temp);i++) what += ", "+temp[i];
    }
  }
  write("\n"+subj+":\n"+what+"\n");


  message("prompt","Press <ENTER> to continue: ",this_player());
  input_to("pause2");

}

string query_auto_load()   {
    return base_name(this_object())+":";
}



