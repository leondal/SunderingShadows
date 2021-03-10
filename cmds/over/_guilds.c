#include <std.h>
#include "/realms/grendel/grendel.h"

int cmd_guilds(string str){
    object *persons, ob;
    mapping map;
    string *names, name, guild, stuff;
    int i, num, align, tmp, level;
    stuff = "";
    persons = users();
    num = sizeof(persons);
     names = ({});
    map = ([]);

    for(i=0;i<num;i++){
     if(persons[i]->query_invis() && persons[i]->query_level() > TP->query_level()) continue;
	name = persons[i]->query_true_name();
	if(name) { name = capitalize(name); }
	if(!name) { name = "%^BOLD%^%^CYAN%^NONE%^RESET%^"; }
	name = arrange_string(name, 12);
    names += ({name});
	map[name] = persons[i];
    }

    sort(names);
    for(i=0;i<sizeof(names);i++){
	name = names[i];
	ob = map[names[i]];
   if((string *)ob->query_guild() == ({})){
	    guild = "%^BOLD%^%^RED%^NONE";
	    tmp = 0;
	} else {
      guild = ob->query_guild_string();
	    tmp = 1;
	}

	level = ob->query_level();
	align = ob->query_alignment();

	if(str == "out" && !tmp)
	    stuff += "%^BOLD%^"+name+" -->  "+guild+" %^BOLD%^%^GREEN%^Level: %^RESET%^"+level+"  %^MAGENTA%^Alignment: "+align+".%^RESET%^\n";
	if(str == "in" && tmp)
	    stuff += "%^BOLD%^"+name+" -->  "+guild+"%^RESET%^\n";
    if(!str) stuff += "%^BOLD%^"+name+" -->  %^BOLD%^%^MAGENTA%^Align:%^RESET%^ "+align_abbrev(align)+"  %^BOLD%^%^GREEN%^Level: %^RESET%^"+arrange_string(level,5)+"  %^BOLD%^"+guild+"\n";
    }

    return (int)this_player()->more(explode(stuff, "\n"));
}
