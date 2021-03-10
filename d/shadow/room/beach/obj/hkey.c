//  Created by Ignatius, Demonforce, and Zeek.
//  Recoded December 1, 1995
//  Beach Front Estates Caller

#include <std.h>  
#include </d/shadow/room/beach/obj/hkeycall.h>
inherit OBJECT;

int muffs   ; //Tells whether a player has channel earmuffs on.

create() {
  ::create();
  set_name( "house key" );
  set_short( 0 );
  set("long",
    "This "
    "is a "
    "house "
    "key. \n"
    " \n"+
    Tn+" is a member in good standing of the Antioch Project.\n"
    " \n"
    "In smaller letters, you read:\n"
    "Brought to you by the Bishop of Antioch.  We all adore Ignatius.\n"
    "Type: \"help amulet\" to see how the amulet works.\n"
    );
  set("id", ({
    "hkey@beachhomes"
    }) );
}
 
void init() {
  add_action( "help_fun", "help" );
   add_action( "wiz_talk", "beach" );
  add_action( "emoting", "beachemote" );
  add_action( "muffs", "silence" );
} 
 

void init_arg(mixed *arr) {
  muffs = arr[ 0 ];
}

int help_fun(string str) {
  if ( str == "key" ) { 
  message("info",
"\n%^CYAN%^The owners of houses in Beach Front can use; \n"
   "OPTION               ACTION \n"
   "------               ------\n"
   "help amulet            Displays commands.\n"
   "beach <message>        Allows talk to other home owners.\n"
   "beachemote <emote>     Emotes to other home owners.\n"
   "silence                Lets you turn the line on and off.\n"
               , this_player() );
  return( 1 );
  }
  else
    return( 0 );
}
 
 
string extra_look() {
  return ( environment(this_object())->query_cap_name()+
          " is a home onwer in the Beach Front Estate.\n" );
}
 
int wiz_talk(string str) {
  object *imms, ply;
  int count;
  string title, tmp;
  
  imms = users();
  
title = "%^BOLD%^<%^RESET%^%^CYAN%^Beach%^RESET%^%^BOLD%^>";
  
  if ( str == 0 ) str = "mutters to"+HIM+"self.";
  if(present("hkey@beachhomes", this_player())->query_muffs() ){
    message("info","You may say something, but you may not "
                   "get an answer from anyone if you have silence  "
                   "turned on.\n",
                   TP );
  }
tmp = capitalize(geteuid(this_player()))+" %^BOLD%^<%^RESET%^"+title+"%^BOLD%^> "+str;
  for (count=0;count<sizeof( imms );count++) {
    ply = present( "hkey@beachhomes", imms[ count ] ); 
    
    if ( ply && !present("hkey@beachhomes", imms[count])->query_muffs() ) {
      ply->add_history(tmp);
      message("anti", tmp, imms[count]);
      }
    }
  
  return( 1 );
}
 
int emoting(string str) {
  object *imms, ply;
  int count;
  string title, tmp;
  
  imms = users();
  
  if ( str == 0 ) str = "moves around a little.";

title = "%^BOLD%^<%^RESET%^%^CYAN%^Beach%^RESET%^%^BOLD%^>";
  
  
  if ( str == 0 ) str = "is quiet.";
  if(present("hkey@beachhomes", this_player())->query_muffs() ){
    message("info","You can do your emoting on the line, but "
                   "none may react if you have silencer "
                   "turned on.\n",
                   TP );
  }
 
tmp = "%^BOLD%^<%^RESET%^"+title+"%^BOLD%^> "+capitalize(geteuid(this_player()))+" "+str;
  for (count=0;count<sizeof( imms );count++) {
    ply = present( "hkey@beachhomes", imms[ count ] ); 
    
    if ( ply && !present("hkey@beachhomes",imms[count])->query_muffs() ) {
      ply->add_history(tmp);
      message("anti", tmp, imms[count]);
      }
    }
  
  return( 1 );
}

string visibility(object target) {
  if(target->query_invis()) return " (invis)";
  else return "";
}

int value(string str) {
  int val,count;
  val=0;
  
  for (count=0;count<strlen(str); count++) {
    val=val*10+str[count]-48;
    }
  return val;
}
 
int muffs() {
if(muffs==1) { muffs--;
  message("info","You turn the Beach line off.", 
           this_player()); }
else { muffs++;
  message("info","You turn the Beach line on.", 
           this_player()); }
return(1);
}
 
string query_muffstr() {
  if(muffs==1) return "- ";
  else return "+ ";
}
 
int query_muffs() { return muffs; }














