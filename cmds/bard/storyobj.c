#include <std.h>
inherit OBJECT;
int end_game(string str);
void long_desc(string str);
void start();

object who;
string long,file, name;

void create(){
    ::create();
    set_name(" ");
    set_short(" ");
    set_id(({"storyobj"}));
    set_property("no animate",1);
}

void init(){
    ::init();
    who = environment(TO);
    start();
}

void start(){
    tell_object(who,"Enter your story. Hit <return> after each line. Preceed each line with the command you wish to use.");
	tell_object(who,"Type ** on a blank line when you are done.\n");
    long = "";
	input_to("long_desc");
    return 1;
}

void long_desc(string str){
    if(str == "**") {
        end_game(long);
	}
	else {
        long = long+str+"\n";
        input_to("long_desc");
    } 	
}

int end_game(string str){
       if(strlen(str) == 0){
	tell_object(who,"No information saved");
        return 1;
      }
       /*
   str = "<HTML>\n"+
    "<HEAD>\n"+
   "<TITLE>"+capitalize(who->query_name())+"</TITLE>\n"+
   "</HEAD>\n"+
    "<BODY TEXT=\"#ffffff\" LINK=\"#C8C8C8\" VLINK=\"#C8C8C8\" BGCOLOR=\"#000000\"><H4><HR WIDTH=500><BLOCKQUOTE>\n"+
   str;
   */
   "daemon/recite_d"->save_story(long, name,TP);
    tell_object(who,"Your story reads:");
    who->more(file);
	 call_out("remove",1);
	 return 1;
}

void set_name(string n){
   name = n;
}

void save_me(string file){
    return 1;
}
