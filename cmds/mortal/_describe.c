//      /bin/user/_describe.c
//      from the Nightmare mudlib
//      User command for adding a description
//      created by Descartes of Borg 25 Nov 1992

#include <std.h>
#include <daemons.h>

inherit DAEMON;

object me;

int cmd_describe(string str) 
{
    object desc;

    desc = new(DESC_D);
    
    if (!interactive(TP)) 
    {
        if(!str) { }
        else 
        {
            this_player()->set_long(TP->query_cap_name()+" "+str);
        }
    }
    else
    {    
        if(!str) 
        {
		if(TP->query_description() == 0)
		{
			write("You currently have no description set.  Please "+
			"enter one as soon as possible.\n");
			return 1;
		}
		write("Your current description is: \n"+
		capitalize(TP->query_name()) + " " + TP->query_description() + "\n");
		return 1;
        }
	  
        if(str == "-remove" || str == "-Remove")
	    {
		    TP->set_description(0);
		    write("You clear your description.  Please remember to enter "+
		        "another as soon as possible.\n");
		    return 1;
	    }
        
        else 
        {
            this_player()->set_description(str);
            desc->set_profile_stuff(str,"description",TP);
          write("Your description now reads:
            "+capitalize(this_player()->query_name())+" "+str+"\n");
        }
    }
    return 1;
}

void help() {
  write("
%^CYAN%^NAME%^RESET%^

describe - describe yourself

%^CYAN%^SYNOPSIS%^RESET%^

describe %^ORANGE%^%^ULINE%^TEXT%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command adds a description to you others will be able to see when they look at you.

To check how your look now, you can look at yourself by name, %^ORANGE%^<look %^ORANGE%^%^ULINE%^YOURNAME%^RESET%^%^ORANGE%^>%^RESET%^.

Keep in mind that a description and adjectives are the means by which you describe your physical appearance to people. Stick to the facts, and do not add opinions. If you were to walk up to me in the street, you would not be able to tell if I was strong or evil or good. If you want people to come to a conclusion about you, you need to describe things about yourself factually. Do not try and tell the player what they should think about you.

%^CYAN%^SEE ALSO%^RESET%^

adjective, chfn, passwd, background, look, recognize

");
}
