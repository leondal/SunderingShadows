// Command to rid inactive players

#include <std.h>
#include <security.h>
#include <daemons.h>
#include "/adm/include/dontrid.h" // contains the EXCLUDE array of player names to be skipped
inherit DAEMON;

#define GREPFILE "/adm/save/users/temp.txt"
#define USERDIR "/adm/save/users/"
#define ALPHA ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"})

string *toberid;

void make_list(string pattern, string dir);
void grep(string str);
void do_rid();
int help();

int cmd_purge(string str){
   string when, dirs, thedir;
   int i;
   
   seteuid(UID_ROOT);
   if(!str) return help();
   if(sscanf(str, "%s %s", when, dirs) != 2) return help();
   if(dirs != "all" && member_array(dirs,ALPHA) == -1) return help();
   if(!EXCLUDE) return notify_fail("WARNING: Exclude file is missing. Purge will not run.");
   toberid = ({});
   if(dirs == "all")
      for(i=0;i<sizeof(ALPHA);i++){
         thedir = USERDIR + ALPHA[i];
         make_list(when, thedir);
      }
   else{
      thedir = USERDIR + dirs;
      make_list(when, thedir);
   }
   do_rid();
   return 1;
}

void make_list(string pattern, string dir){
   string str, line, name;
   int i, j, k;
   
   str = "real_last_on "+ dir + "/*.o > "+GREPFILE;
   grep(str);
   if(file_size(GREPFILE) > -1){
      i = 1;
      while(line = read_file(GREPFILE,i,1)){
         if(line == "" || line == 0) break;
         j = strsrch(line,".o:");
         if(j != -1){
            k = strsrch(line,"/",-1);
            name = line[k+1..j-1];
            i++;
            line = read_file(GREPFILE,i,1);
            if(strsrch(line,pattern) != -1)
               if(member_array(name,EXCLUDE) == -1){ 
                  if (! USERCALL->user_call(name,"is_avatar") )

                  toberid += ({name});
               }
            i+=2;
         }
      }
   }
   rm(GREPFILE);
}

void grep(string str) {
    mapping borg;
    string *lines, *files;
    string output, exp, file, tmp;
    mixed x;
    int i, max;

    if(sscanf(str, "%s > %s", tmp, output) == 2) {
        if(output[0] != '/')
          output = (string)previous_object()->get_path()+"/"+output;
        str = tmp;
    }
    else output = 0;
    if(sscanf(str, "'%s' %s", exp, file) != 2 && sscanf(str, "%s %s", exp, file) != 2) return 0;
    if(!(max = sizeof(files = (string *)previous_object()->wild_card(file)))) { 
        message("system", "File not found.", this_player());
        return;
    }
    for(i=0, borg = ([]); i<max; i++) {
        x = catch(borg[files[i]] = regexp(explode(read_file(files[i]), "\n"), exp));
        if(x) write(""+files[i]);
        if(!sizeof(borg[files[i]])) map_delete(borg, files[i]);
    }
    if(!(max = sizeof(files = keys(borg)))) str = "No matches found.\n";
    else {
        for(i=0, str = ""; i<max; i++)
          str += sprintf("%s:\n%s\n\n", files[i], implode(borg[files[i]],"\n"));
    }
    write_file(output, str);
    return;
}

void do_rid(){
   int i;
   string name;
   object ridob;
   
   for(i=0;i<sizeof(toberid);i++){
      name = toberid[i];
      ridob = new("/cmds/adm/_rid");
      ridob->cmd_rid(name);
   }
   write("Purged "+sizeof(toberid)+" players.");
  log_file("purge",format_page(toberid,4)+"\n\n");

}

int help(){
   write(
@HELP
   Usage: purge <when> <directory || all>

   Purge is used to rid inactive characters. See /adm/include/dontrid.h
   for the characters that will not be deleted. 
   
   <when> is a string to search for in the real_last_on date in the p.o file.
          Any p.o file containing this will be rid.
          Ex: 1999 or Jan
          Note: real_last_on looks like this: Mon Feb 21 21:38:15 2000
          
   <directory> specifies which file directories to search through (a-z).
          Note: Please use lowercase letters.
   
   <all> will search through the full list of p.o files. 

HELP
   );
   return 1;      
}
