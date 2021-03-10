#include <std.h>

#define GUILDSD "/daemon/guild_d.c"

void init() {
    add_action("types", "check");
    add_action("our_troopers", "list");
    add_action("buy_em", "hire");
    add_action("read", "read");

}

int types(string str) {
    string *files;
    int numfiles, i, cash, len;
    string short, dir, file1, guild;
    string info;

    len = 40;

    guild = (string)TP->query_guild();
    if(!guild) return notify_fail("You must be part of a guild.");
    switch (guild) {
    case "Iron Fist":
	dir = "/d/guilds/fist/troopers/";
	break;
case "Legion of Lost Soul":
dir = "/d/guilds/pack/troopers/";
	break;
case "Crimson Hand":
	dir = "/d/guilds/pack/troopers/";
	break;
    case "Order of the Metallic Dragon":
	dir = "/d/guilds/order/troopers/";
	break;
    default:
	tell_player(TP, "ERROR - Please contact WIZ (I suggest Grendel.  He rocks)\n");
	break;
    }

    files = get_dir(dir);
    numfiles = sizeof(files);
    if(!numfiles) return notify_fail("Your guild doesn't have any troopers.  This means you need to talk to a wiz.");

    tell_player(TP, "The following are the different troopers you can hire for your guild.\n\n");

    info = "";
    for(i=0;i<numfiles;i++) {
	if( i > 9 ) len = 39;
	file1 = dir+files[i];
	if(!(file1->query_short())) {
	    file1->set_invis();
	    short = file1->query_short();
	    file1->set_invis();
	} else {
	    short = file1->query_short();
	}
	cash = file1->query_cost();
	short = arrange_string(short, len);
	short += " ";
	info += i+") "+short+" "+cash+" gold\n";
    }
    TP->more(explode(info,"\n"));

    return 1;
}

int our_troopers() {
    string guild;
    string short;
    string *files;
    int numfiles;
    int i;
    int cash;

    guild = (string)TP->query_guild();
    if(!guild) return notify_fail("You aren't in a guild.\n");
    files = GUILDSD->query_troopers(guild);
    numfiles = sizeof(files);
    if(!numfiles) return notify_fail("Your guild has no troopers.\n");

    tell_player(TP, "These are the following troopers for your guild.\n\n");
    tell_player(TP, "Your guild has "+numfiles+" troopers.\n\n");
    for (i=0;i<numfiles;i++) {
	if(!(files[i]->query_short())) {
	    files[i]->set_invis();
	    short = files[i]->query_short();
	    files[i]->set_invis();
	} else {
	    short = files[i]->query_short();
	}
	cash = files[i]->query_cost();
	cash = cash * 35 / 100;
	short = arrange_string(short, 40);
	short += " ";
	tell_player(TP, i+") "+short+" \n");
    }
    return 1;
}

int buy_em(string str) {
    string guild;
    int size;
    string *files;
    int num;
    string dir;
    string short;
    string file1;
    int funds, cost;

    guild = (string)TP->query_guild();
    switch (guild) {
    case "Iron Fist":
	dir = "/d/guilds/fist/troopers/";
	break;
case "Legion of Lost Soul":
dir = "/d/guilds/pack/troopers/";
	break;
case "Crimson Hand":
	dir = "/d/guilds/pack/troopers/";
	break;
    case "Order of the Metallic Dragon":
	dir = "/d/guilds/order/troopers/";
	break;
    default:
	tell_player(TP, "You have to be in a guild.\n");
	break;
    }

    files = get_dir(dir);
    size = sizeof(files);
    if(!size) return notify_fail("Your guild has no troopers to purchase.  Talk to a wiz.\n");

    if(sscanf(str,"trooper %d", num) != 1) return notify_fail("Incorrect syntax.\n");
    if( (num < 0) || (num > (size-1)) ) return notify_fail("That trooper is not available.\n");
    file1 = dir+files[num];
    if(!(file1->query_short())) {
	file1->set_invis();
	short = file1->query_short();
	file1->set_invis();
    } else {
	short = file1->query_short();
    }
    funds = GUILDSD->query_guild_account(guild);
    cost = file1->query_cost();
    if(cost > funds) {
	tell_player(TP, "Your guild doesn't have the money to hire that trooper.\n");
	return 1;
    }
    GUILDSD->add_guild_gold(guild, -cost);
    tell_player(TP, "You bought trooper "+num+", by the name of "+short+" for "+cost+" gold.\n");
    GUILDSD->add_trooper(guild, file1);

    return 1;
}


int read(string str) {
    if(!str) return notify_fail("read what?");
    if(str != "sign") return notify_fail("That is not here");

    tell_room(ETP, TPQCN+" reads the sign on the wall.", TP);
    tell_object(TP, "These are the commands available in this room :");
    tell_object(TP, "   check : Lists the types of troopers your guild may hire.");
    tell_object(TP, "   list : Lists the troopers currently employed by your guild.");
    tell_object(TP, "   hire trooper # : Hires a trooper for your guild.  The number is the");
    tell_object(TP, "      number to the left of the trooper on the 'check' command.");
    return 1;
}
