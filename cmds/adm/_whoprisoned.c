#include <std.h>
#include <security.h>
#define JAIL "/adm/daemon/prison_d.c"

inherit DAEMON;

int cmd_whoprisoned(string who)
{
	mixed *pair;
	string *list, *release, *tmp, *date_info, *time_info;
	string name, by, reason;
	int count;
	mapping prison_list, player_info;

	if (!archp(this_player()) ) { return 0; }
	
	count = 0;
	prison_list = JAIL->query_prison_list();

	if (who)
	{
		player_info = prison_list[who];
		if (!player_info)
		{
			write(capitalize(who)+" is not in prison.");
			return 1;
		}
		else
		{
			list = values(player_info);
			release = ctime(list[2]);
			name = capitalize(who);
			by = capitalize(list[0]);
			reason = list[1];
			write("\n"+name+" was imprisoned by "+by+" for "+reason);
			write("To be released on "+release+"\n");
			return 1;
		}
	}
	while ((pair = each(prison_list)) != ({}))
	{
		if (!count)
		{
			tmp = ({"Prisoner","By","Reason","Release date"});
			tmp += ({"----------------- ","----------------- ","----------------- ","-----------------"});
		}
		player_info = pair[1];
		list = values(player_info);
		name = capitalize(pair[0]);
		by = capitalize(list[0]);
		reason = capitalize(list[1]);
		release = ctime(list[2]);
		date_info = explode(release," ");
		time_info = explode(date_info[3],":");
		release = date_info[0]+" "+date_info[1]+" "+date_info[2]+" "+time_info[0]+":"+time_info[1];
		tmp += ({name, by, reason, release});
		count = 1;
	}
	if (!count)
	{
		write("There is no one in prison!");
	}
	else
	{
		write(format_page(tmp,4));
		write("For more information on a prisoner, do whoprisoned <name>");
	}
	return 1;
}

int help()
{
	if (!archp(this_player())) return 0;
	write ("Format: Whoprisoned <player>.\n"+
	"Either lists whether <player> is in prison, or lists all players "+
        "that are in prison if you do not give <player>.");
	return 1;
 }
