#include <std.h>
inherit OBJECT;
int end_game(string str);
void long_desc(string str);
void start();

object who;
string long,file;

void create(){
    ::create();
    set_name(" ");
    set_short(" ");
    set_id(({"backgroundobj"}));
    set_property("no animate",1);
}

void init(){
    ::init();
    who = environment(TO);
    file = "/avatar/"+lower_case(TP->query_name())+"/"+lower_case(TP->query_vis_name())+".htm";
    start();
}

void start(){
    if(file_exists(file)) rm(file);
    tell_object(who,"Give a history of your character. Hit <return> after each line.");
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
   str = "<HTML>\n"+
    "<HEAD>\n"+
   "<TITLE>"+capitalize(who->query_name())+"</TITLE>\n"+
   "</HEAD>\n"+
    "<BODY TEXT=\"#ffffff\" LINK=\"#C8C8C8\" VLINK=\"#C8C8C8\" BGCOLOR=\"#000000\"><H4><HR WIDTH=500><BLOCKQUOTE>\n"+
   str;
     str = "daemon/converter"->convertFromInput(str);
    write_file(file,str);
    tell_object(who,"Your background information now reads:");
     str = read_file(file,6);
     str = "daemon/converter"->convertToInput(str);
     who->more(explode(str,"\n"));
	call_out("remove",1);
	return 1;
}

void save_me(string file){
    return 1;
}
