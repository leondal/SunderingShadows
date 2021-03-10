#include <std.h>
inherit OBJECT;
int end_game(string str);
void long_desc(string str);
void start();

object who;
string long,file, edfile;

void create(){
    ::create();
    set_name(" ");
    set_short(" ");
    set_id(({"lore_edit_obj"}));
    set_property("no animate",1);
}

void init(){
  ::init();
  who = environment(TO);
  file = "/d/save/background/"+lower_case(who->query_name())+".htm";
  edfile = "/tmp/background/"+lower_case(who->query_name())+".txt";
  start();
}

void start(){
  if (file_exists(edfile)) rm (edfile);

  if (file_exists(file)) {
    //  rm(file);
    tell_object(who,"You come to continue your saga. Ah. Excellent.");
    long=read_file(file,6);

    long= "daemon/converter"->convertToInput(long);
    write_file(edfile,long);

  }
  tell_object(who,"Give a history of your character. Hit <return> after each line.");
  tell_object(who,"Type ** on a blank line when you are done.\n");
  tell_object(who,"Type ~e to enter the editor for other commands.");
  who->edit(edfile,"end_game",TO,"background");
  /*********
    long = "";
	input_to("long_desc");
    return 1;
  *******/
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

int end_game(mixed garbage){
  string str;
  if(file_size(edfile) == 0){
    tell_object(who,"No information saved");
    rm(edfile);
    rm(file);
    return 1;
  }
  str = "<HTML>\n"+"<HEAD>\n"+
    "<TITLE>"+capitalize(who->query_name())+"</TITLE>\n"+
    "</HEAD>\n"+
    "<BODY TEXT=\"#ffffff\" LINK=\"#C8C8C8\" VLINK=\"#C8C8C8\" BGCOLOR=\"#000000\"><H4><HR WIDTH=500><BLOCKQUOTE>\n";
  str += read_file(edfile);
  str = "daemon/converter"->convertFromInput(str);
  rm(file);
  write_file(file,str);
  tell_object(who,"Your background information now reads:");
  str = read_file(file,6);
  str = "daemon/converter"->convertToInput(str);
  rm(edfile);
  who->more(explode(str,"\n"));
  call_out("remove",1);
  return 1;
}

void save_me(string file){
    return ;
}
