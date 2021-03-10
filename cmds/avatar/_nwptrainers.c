//Coded by Saide to allow avatars/immortals to see the list of currently loaded
//nwp trainers in the game.  3/18/2007

#include <std.h>
#include "/daemon/nwps_d.h"
#define NWP_D "/daemon/nwps_d"

inherit DAEMON;


int cmd_nwptrainers(string str){
	string *vnwps, *npcnwps, tmp;
	mapping trainers = ([ ]);
	int x, i, z;
	object *livs;
	livs = livings();
	if(!str) 
	{
		vnwps = keys(NWPS_MAP);
	}
	if(str)
	{
		if(member_array(str, keys(NWPS_MAP)) == -1)
		{
			return notify_fail("There is no such nwp.\n");
		}
		vnwps = ({str});
	}
	//vnwps = sort_array(vnwps);
	for(x = 0;x < sizeof(vnwps);x++)
	{
		trainers += ([ vnwps[x] : ({}) ]);
	}
	for(x = 0;x < sizeof(livs);x++)
	{
		if(!livs[x]->is_npc()) continue;
		if(livs[x]->is_npc())
		{
			npcnwps = livs[x]->query_nwps();
			for(i = 0;i < sizeof(npcnwps);i++)
			{
				if(livs[x]->query_nwp(npcnwps[i]) < 1) continue;
				if(objectp(environment(livs[x]))) 
				{
					if(member_array(npcnwps[i], vnwps) != -1) 
					{
						trainers[npcnwps[i]] += ({livs[x]->query_short(),
						base_name(livs[x]),
						environment(livs[x])->query_short(), 
						base_name(environment(livs[x]))});
					}
				}	
			}
		}

	}
	vnwps = keys(trainers);
	tmp = "%^BLUE%^Trainer\n%^CYAN%^Location\n";
	for(x = 0;x < sizeof(vnwps);x++)
	{
		tmp += "%^BOLD%^%^GREEN%^Nwp : " + capitalize(vnwps[x]) + "%^RESET%^\n";
		i = 0;
		z = 1;
		while(i < sizeof(trainers[vnwps[x]]))
		{
			tmp += z +":%^BLUE%^" + trainers[vnwps[x]][i] + "%^RESET%^\n";
			if(wizardp(TP))
			{
				tmp += "\t" + trainers[vnwps[x]][i+1] + "\n";
			}
			tmp += "\t" + trainers[vnwps[x]][i+2] + "\n";
			if(wizardp(TP)) 
			{
				tmp += "\t%^RED%^" + trainers[vnwps[x]][i+3];
			}
			tmp += "%^RESET%^\n";
			i += 4;
			z++;
		}
	}
	TP->more(explode(tmp,"\n"));
   	return 1;
}

int help(){
	int x;
	write("Syntax : <nwptrainers> || <nwptrainers> <nwp>\n\n"+
	"This command will list for you the currently loaded nwps trainers and the short description "+
	"of the room they are in.  For wizzes it will also show the filename of the npc and the "+
	"room they are in.  If you type only <nwptrainers> if will list all of the trainers for all "+
	"of the currently loaded nwp trainers in the game.  If you type <nwptrainers> <nwp> if will "+
	"only list the loaded trainers for the specified <nwp>.  The following is a list of "+	
	"valid nwps.\n");
	for(x = 0;x < sizeof(keys(NWPS_MAP));x++)
	{
		write("\t"+keys(NWPS_MAP)[x]);
	}

    return 1;
}
