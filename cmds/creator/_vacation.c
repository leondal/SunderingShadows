//	_bug.c
//	original written by Sulam 030192
//	help added by Buddha 180192
//	logging for individual creators added by Descartes 201092
//      Edit, word wrap added by Manny 100893
 
#include <std.h>
#include <dirs.h>
#include <security.h>
 
inherit DAEMON;
 
int cmd_vacation(string text);
int report(string *lines);
void end_text();
void abort();
string file;
 
 
int cmd_vacation(string text) {
    string *lines;
    string str, new_text;
    object ob;

    if(!wizardp(TP)) return 0;
    if(!text || ob = present(text,this_player()) ||
      ob = present(text, environment(this_player()))) {
        rm(DIR_TMP+"/"+geteuid(previous_object())+".vacation");
        file = file_name(ob ? ob : environment(previous_object()));
        
previous_object()->edit(DIR_TMP+"/"+geteuid(previous_object())+".vacation",
            "end_edit", this_object());
        return 1;
    }
    if(sscanf(text, "%s %s", str, new_text) == 2) {
        if(!(ob = present(str, this_player())) &&
          !(ob = present(str, environment(this_player()))))
            new_text = str+" "+new_text;
    }
    if(!ob) ob = environment(this_player());
	  file = file_name(ob);
          lines = explode(wrap(text), "\n");
          report(lines);
          return 1;
}
 
end_edit() {
  string *lines;
  string tmpfile;
    tmpfile = 
file+":\n"+read_file(DIR_TMP+"/"+geteuid(this_player())+".vacation");
    lines = explode(wrap(replace_string(tmpfile, "\n", " "), 77), "\n");
  rm("/tmp/"+this_player()->query_name()+".vacation");
  report(lines);
}
 
report(string *lines) {
  string who, *elements;
  int x;
 
  elements = explode(file, "/");
  if(elements[0] == "realms") who = elements[1];
  else if(elements[0] == "d") who = elements[1];
  else who = 0;
  
  seteuid(UID_LOG);
  log_file("vacation", "[Vacation reported: "+
   this_player()->query_cap_name()+" "+ctime(time())+"]\n");
  x = -1;
  while(++x < sizeof(lines)) {
    log_file("vacation", lines[x]+"\n");
  }
  seteuid(getuid());
  write("Vacation reported!  Hope to see you soon!\n");
  return 1;
}
 
void abort() {
  notify_fail("Vacation report aborted.\n");
  rm("/tmp/"+this_player()->query_name()+".vacation");
  return 0;
}
