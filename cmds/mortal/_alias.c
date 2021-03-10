// alias command
#include <std.h>

inherit DAEMON;

void alias_reset();
int sort(string one,string two);

varargs int cmd_alias (string str, int first)
{
    int i, sl;
    int index;
    string verb,cmd,*elements,melnmarn;
    object act_ob;
    mapping alias;

    if(!objectp(PO) || !interactive(PO)) { return 0; }

    act_ob = PO;


    if(str == "-clear")
    {
        act_ob->clear_aliases();
        return 1;
    }

    if(str == "-reset")
    {
        alias_reset();
        return 1;
    }

    alias = (mapping)act_ob->query_aliases();

    if(!str)
    {
        if (!mapp(alias))
        {
            if(pointerp(alias)) write("Your alias mapping is a pointer!");
            if(intp(alias)) write("Your alias mapping is an integer!");
            if(stringp(alias)) write ("Your alias mapping is a string!");
            if(alias == 0) write ("Your alias mapping is 0!");
            notify_fail("You have some bad aliases, dude!");
            return 0;
	    }

        elements = keys(alias);
        if(!elements || !sizeof(elements))
        {
	        write("No aliases defined.");
	        return 1;
	    }

        elements = sort_array(elements,"sort");

        melnmarn = "";
        for(i = 0; i < sizeof(elements); i++)
        {
	        melnmarn += sprintf("%%^YELLOW%%^%-10s %%^RESET%%^%%^CYAN%%^%-50s \n",elements[i],alias[elements[i]]);
	    }

        act_ob->more(explode(melnmarn,"\n"));
        return 1;
    }

    if(sscanf(str,"%s %s",verb,cmd) == 2)
    {
        // added pray to prevent screwing up praying in churches *Styx* 11/20/03, last change 7/98
        if(verb=="alias" || verb == "pray")
        {
            notify_fail ("Sorry, we can't allow you to alias 'alias' or 'pray'.\n");
            return 0;
        }
        if(!first)
        {
            if (!alias[verb])
            {
                write("Alias: "+verb+" ("+cmd+") added.");
            }
            else
            {
                write("Alias: "+verb+" ("+cmd+") altered.");
            }
        }

        act_ob->add_alias(verb,cmd);
        return 1;
    }

    if(!alias[str])
    {
        write("The alias "+str+" wasn't found.");
        return 1;
    }

    printf("%-15s%s\n",str,alias[str]);
    return 1;
}

int sort(string one,string two) { return strcmp(one,two); }

varargs void alias_reset()
{
    if (!interactive(previous_object())) { return; }
    cmd_alias("exa look $*",1);
    cmd_alias("i inventory",1);
    cmd_alias("l look $*",1);
    cmd_alias("$' say $*",1);
    cmd_alias("$\" say $*",1);
    cmd_alias("bio biography $*",1);
    cmd_alias("$: emote $*",1);
    cmd_alias("e east");
    cmd_alias("w west");
    cmd_alias("n north");
    cmd_alias("s south");
    cmd_alias("u up");
    cmd_alias("d down");
    cmd_alias("ne northeast");
    cmd_alias("nw northwest");
    cmd_alias("sw southwest");
    cmd_alias("se southeast");
}


int help()
{
  write("
%^CYAN%^NAME%^RESET%^

alias - define server-side command aliases

%^CYAN%^SYNOPSIS%^RESET%^

alias
alias %^ORANGE%^%^ULINE%^ALIAS%^RESET%^ [%^ORANGE%^%^ULINE%^COMMAND%^RESET%^]
alias -reset
alias -clear
unalias %^ORANGE%^%^ULINE%^ALIAS%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Alias defines short substitution for any entered command.

You can enter substitution variables:

 $N    Where N is the number will substitute Nth argument of alias into the command.
 $*    Substitutes all alias arguments into the command.

Without argument, alias will list all defined aliases.

There are two options:

 -reset    Will reset aliases to default.
 -clear    Will completely empty your aliases.

Prefixing the alias verb with a $ allows you to set up a verb that does not require a space after it.

To remove an %^ORANGE%^%^ULINE%^ALIAS%^RESET%^ use %^ORANGE%^<unalias %^ORANGE%^%^ULINE%^ALIAS%^RESET%^%^ORANGE%^>%^RESET%^.

%^CYAN%^EXAMPLES%^RESET%^

%^ORANGE%^<alias greet kill>%^RESET%^

    Each time you use <greet TARGET> server will perform the same action as if you have typed <kill TARGET>

%^ORANGE%^<alias lsack look sack $1>%^RESET%^

    Command <lsack 2> will be substituted on the server to <look sack 2>

%^ORANGE%^<alias $' say \" $* \">%^RESET%^

    Now if you type %^ORANGE%^<'Hello!>%^RESET%^ server will substitute it with %^ORANGE%^<say \" Hello! \">%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^

unalias, nickname, unnickname, history, last

");
	return 1;
}
