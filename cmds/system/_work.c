//  /bin/dev/_work.c
//  From the Nightmare mudlib
//  Debugging/Reviewing tool coded at Melvaig's request
//  By Valodin, Feb. 18, 1993

#include <std.h>

inherit DAEMON;
string temp;


/* Raw 'cd' code used here */
int cd(string str) {
    str = resolv_path((string)TP->get_path(), str);
    if (sscanf(str,"//%s",temp) == 1) str = "/"+temp;
    if(!master()->valid_read(str, TP, "work")) {
	notify_fail(str+": permission denied\n");
	return 0;
    }
    if (file_size(str) > -1) {
	notify_fail(str+": not a directory\n");
	return 0;
    }
    if (file_size(str) == -1) {
	notify_fail(str+": no such file or directory\n");
	return 0;
    }
    seteuid(getuid(previous_object()));
    TP->set_path(str);
    seteuid(getuid());
    message("system", (string)TP->get_path() + ":", TP);
    return 1;
}

int
cmd_work(string str)
{   
    object ob;
    string dirname;
    string filename;                
    string tempstr;
    int tempn;
    int i;        
    int edflag;
                              
    if (str && (sscanf(str, "!%s", str)))
       edflag = 1;
    else
       edflag = 0;
    if(!str || (str == "")) 
       ob = ETP;
    else
    {
       ob = present(str, ETP);
       if(!objectp(ob))
          ob = present(str, TP);
    }
    if(!ob)
    {
       notify_fail("Can't find the object: " + str + "\n");
       return 0;
    }          
    filename = file_name(ob);
    for(i = strlen(filename) - 1; filename[i] != '/'; i--)
      ;
    dirname = filename[0..i];
    if(!cd(dirname)) return 0;
    filename = filename[(i+1)..(strlen(filename) - 1)];
    if(sscanf(filename,"%s#%d", tempstr, tempn) == 2)
       filename = tempstr;
    if (!edflag)
       message("system", "  " + filename + ".c", TP);
    else
       ed(dirname + filename + ".c");
    return 1;
} 

int
help() {
  message("help", "Command: work\nSyntax: work [!][object]\n"
	  "This command changes your current directory to the "
	  "directory of your environement if no argument is " 
	  "given.  If an object name is given, then it " 
	  "check your current inventory and the inventory of "
	  "your room and puts you in the directory of the " 
	  "first object to match that id.  Tells you the " 
	  "filename of the object.  "
	  "If a ! is the first character in the object "
	  "argument, then it will toss you into ed.", TP);
  return 1;
}
