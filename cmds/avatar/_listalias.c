//listalias command - rip of alias
 
#include <std.h>
 
inherit DAEMON;
string name;
int help()
{
    write("Usage:  listalias <target>\n\n"+
    "This will give you the aliases of the <target> player "+
    "you specify as they see them.  They must be online.\n\n"+
    "Example:  listalias saide\n");
    return 1;
} 

varargs int cmd_listalias(string str) {
  int i, sl;
  int index;
  string verb,cmd,*elements,melnmarn;
  object ob;
  mapping alias;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) {
        help();
        return 1;
    }
      
    if(!(ob = find_player(str))) {
        write("No such player online.");
        return 1;
    }
    if(avatarp(ob) && ob->query_level() > TP->query_level()) {
        write("I'm afraid not.");
        return 1;
    }

    name = capitalize(ob->query_name());
    alias = (mapping) ob->query_aliases();
    if(!mapp(alias))	{

          if(pointerp(alias)) write(name + "'s alias mapping is "+
          "a pointer!");
          if(intp(alias)) write(name + "'s alias mapping is "+
          "an integer!");
          if(stringp(alias)) write (name + "'s alias mapping "+
          "is a string!");
          if(alias == 0) write (name +"'s alias mapping is 0!");
          notify_fail("ERROR: BAD ALIASES");
          return 0;
	}
    elements = keys(alias);
    if(!elements || !sizeof(elements)) {
        write("No aliases defined.");
	    return 1;
	}
      
      elements = sort_array(elements,"sort");
      melnmarn = "";
      write("%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
      write("%^BOLD%^%^GREEN%^"+name+ " has the following aliases defined: \n");
      for(i = 0; i < sizeof(elements); i++) {
	  melnmarn += sprintf("%%^YELLOW%%^%-10s %%^RESET%%^%%^CYAN%%^%-50s \n",elements[i],alias[elements[i]]);
	}
      TP->more(explode(melnmarn,"\n"));
      return 1;
  printf("%-15s%s\n",str,alias[str]);
  return 1;
}
 
