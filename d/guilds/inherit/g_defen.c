#include <std.h>

#define GUILDSD "/daemon/guild_d.c"
string ghere;
string query_owner();

void init() {
    add_action("types", "check");
    add_action("our_troopers", "list");
    add_action("buy_em", "hire");
    add_action("take", "take");
    add_action("read", "read");
    if(!interactive(TP)) return;
   //if( !avatarp(TP) && (GUILDSD->query_control_guild(base_name(ETP))) && ((string)TP->query_guild() != query_owner()) && (member_array(query_owner(),TP->query_guild()) == -1)) {
   //tell_object(TP, "%^BOLD%^Halt!  Who goes there! \n  %^RESET%^The guards grab you and throw you out into the cold.");
   //ghere = base_name(TP->query_last_location());
   //if(!ghere){
   //TP->move("/d/shadowgate/adv_main");
    //} else {
   //TP->move(ghere);
   //}

   //}


}

int types(string str) {
    string *files;
    int numfiles, i, cash, len;
    string short, dir, file1, guild;
    string info;

    if(str) return 0;
    len = 40;

    guild = (string)TP->query_guild();
    if(!guild) return notify_fail("You must be part of a guild.");
    switch (guild) {
    case "Iron Fist":
	dir = "/d/guilds/fist/defenders/";
	break;
    case "Legion of Lost Soul":
	dir = "/d/guilds/angels/defenders/";
	break;
     case "Crimson Hand":
	dir = "/d/guilds/pack/defenders/";
	break;
    case "Order of the Metallic Dragon":
	dir = "/d/guilds/order/defenders/";
	break;
    default:
	tell_player(TP, "ERROR - Please contact WIZ (I suggest Grendel.  He rocks)\n");
	break;
    }

    files = get_dir(dir);
    numfiles = sizeof(files);
    if(!numfiles) return notify_fail("Your guild doesn't have any defenders.  This means you need to talk to a wiz.");

    tell_object(TP, "The following are the different defenders you can hire for your guild.\n\n");

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
	/*
		tell_object(TP, i+") "+short+" "+cash+" gold");
	*/
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
    string info;

    guild = (string)TP->query_guild();
    if(!guild) return notify_fail("You aren't in a guild.\n");
    files = GUILDSD->query_defenders(guild);
    numfiles = sizeof(files);
    if(!numfiles) return notify_fail("Your guild has no defenders.\n");

    info = "";
    tell_object(TP, "These are the following defenders for your guild.\n\n");
    tell_player(TP, "Your guild has "+numfiles+" defenders.\n\n");
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
	//   tell_object(TP, i+") "+short+" ");
	info += i+") "+short+" \n";
		}
	TP->more(explode(info, "\n"));
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
		    dir = "/d/guilds/fist/defenders/";
		    break;
case "Legion of Lost Soul":
dir = "/d/guilds/angels/defenders/";
		    break;
case "Crimson Hand":
		    dir = "/d/guilds/pack/defenders/";
		    break;
		case "Order of the Metallic Dragon":
		    dir = "/d/guilds/order/defenders/";
		    break;
		default:
		    tell_player(TP, "You have to be in a guild.\n");
		    break;
		}

		files = get_dir(dir);
		size = sizeof(files);
		if(!size) return notify_fail("Your guild has no defenders to purchase.  Talk to a wiz.\n");

		if(sscanf(str,"defender %d", num) != 1) return notify_fail("Incorrect syntax.\n");
		if( (num < 0) || (num > (size-1)) ) return notify_fail("That defender is not available.\n");
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
		    tell_player(TP, "Your guild doesn't have the money to hire that defender.\n");
		    return 1;
		}
		GUILDSD->add_guild_gold(guild, -cost);
		tell_player(TP, "You bought defender "+num+", by the name of "+short+" for "+cost+" gold.\n");
		GUILDSD->add_defend(guild, file1);

		return 1;
	    }

int take(string str) {
string myguild;
string herefile;

if(!userp(TP)) return notify_fail("You can't do that, you're not a real person!");
if(!str) return notify_fail("Take what?");
if(str != "room") return notify_fail("Take what?");

myguild = (string)TP->query_guild();
herefile = base_name(ETP);
GUILDSD->set_controled_room(herefile, myguild);
tell_object(TP, "%^BOLD%^%^RED%^Your guild now controls this room.");
return 1;
}

string query_owner() { return GUILDSD->query_control_guild(base_name(ETP)); }

int read(string str) {
if(!str) return notify_fail("read what?");
if(str != "sign") return notify_fail("That is not here");

tell_room(ETP, TPQCN+" reads the sign on the wall.", TP);
tell_object(TP, "These are the commands available in this room :");
tell_object(TP, "   take room : claims this room as the property of your guild.");
tell_object(TP, "   check : Lists the defenders your guild can purchase here.");
tell_object(TP, "   list : Lists the defenders currently working for your guild.");
tell_object(TP, "   hire defender # : Hires a defender for your guild.  The number is the");
tell_object(TP, "      number to the left of the defender on the 'check' command.");
return 1;
}
