/* Cygnus@Nightmare */

#include <std.h>

inherit DAEMON;

string color(object who, int quiet, int is_wiz);


int cmd_users() {
    int i,tpwiz, userwiz, quiet;
    object *user_ob;
    string name, *user_name;

	// Command is out of the game.
	if(!avatarp(TP)) return 0;
	
    user_ob = users();
    user_name = ({ });
    tpwiz = wizardp(TP);
    for (i = 0; i < sizeof(user_ob); i++) {
        userwiz = wizardp(user_ob[i]);
        quiet = (int)user_ob[i]->query_quietness();
	if ( (!user_ob[i]->is_player() || user_ob[i]->query_invis()) ||
             ( !tpwiz && userwiz && quiet ) )
	    continue;
       name = capitalize((string)user_ob[i]->query_name());
       if(avatarp(user_ob[i])){
           if(user_ob[i]->query_disguised()) name = capitalize((string)user_ob[i]->query_vis_name());
        else name = capitalize(user_ob[i]->query_name());
    }
       	if (stringp(name))
	    user_name += ({ color(user_ob[i],quiet,userwiz)+
                            capitalize(name) });        
    }
       user_name += ({color(TP,0,0)+(string)TPQCN });
    user_name = distinct_array(user_name);
        user_name = sort_array(user_name, "sort_names");
	write(format_page(user_name, 4));
	write(sprintf("Total : %d", sizeof(user_name)));
    return 1;
}

string color(object who, int quiet, int is_wiz) {
string colour;
       colour = "%^WHITE%^";
       if (is_wiz) {
          if (quiet) { colour = "%^BOLD%^%^GREEN%^"; }
                else { colour = "%^BOLD%^%^BLUE%^";  } }
       return colour; }

int sort_names(string name1, string name2) {
    if (name1 == name2)
	return 0;
    if (name1 < name2)
	return -1;
    else
	return 1;
}

int help()
{
  write( @EndText
Syntax: users
Effect: Lists the names of player logged in. 
        A shorter and quicker version of "who"

See also: who, where
See also: say, tell, class
EndText
  );
  write("Extra : ANSI support will show immortals in %^BOLD%^%^BLUE%^BLUE." );
  if (wizardp(this_player()))
  write(
  "        Wizards who are in quietness will show up %^BOLD%^%^GREEN%^GREEN.");
  return 1;
}
