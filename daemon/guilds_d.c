
//guilds_d.c

#include <std.h>
#include <security.h>

#define SAVE_FILE "/daemon/save/testguilds"

inherit DAEMON;

//string *guilds;
//mapping gAccounts, troopers, defenders;
//mapping controledRooms;

mapping guilds;
/*
  guilds[string] = guild name                           
  guilds[guildname]["account"] = int             //amount of gold guild has
  guilds[guildname]["short"] = string            //'nickname' of guild
  guilds[guildname]["leader"] = string           //guild leader
  guilds[guildname]["hc"] =({string})            //guild HC 
  guilds[guildname]["memberlist"] = ({string})   //listing of members
*/

void SAVE();
string *query_all_guilds();
mapping query_guild(string guildname);
int remove_guild(string guildname);
string *query_guild_shorts(string guild);
string query_guild_leader(string guildname);
string *query_guild_hc(string guildname);
string *query_guild_members(string guildname);

int set_guild_leader(string guildname, string leadname);
int set_guild_short(string guildname, string shortname);

int is_leader(string guildname, string name);
int is_hc(string guildname, string name);
int is_member(string guildname, string name);

int add_guild_hc(string guildname, string hcname);
int remove_guild_hc(string guildname, string hcname);
int set_guild_hc(string guildname, string *hc);
int add_guild_member(string guildname, string name);
int remove_guild_member(string guildname, string name);

void delete_player(string name);

int add_funds(string name, int amount);
int use_funds(string name, int amount);
int query_funds(string name);



void create() {
    ::create();

    guilds = ([ ]);
    seteuid(UID_DAEMONSAVE);
    //seteuid(getuid());
    restore_object(SAVE_FILE);
    seteuid(getuid());
}

void SAVE() {
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

//Function for wiz to set up basic information for the guild
//  fairly quickly and easily
int setup_guild(string guildname, string leadername, string shortname, string* hc){
    if(!guilds) guilds =([]);

    if(guilds[guildname]) return 0;
    if(!leadername || leadername == "") return 0;

    hc = distinct_array(hc);
    
    guilds[guildname] = ([]);
    guilds[guildname]["account"] = 0;
    guilds[guildname]["short"] = shortname;
    guilds[guildname]["leader"] = lower_case(leadername);
    guilds[guildname]["hc"] = hc;
    guilds[guildname]["memberlist"] = hc;
    guilds[guildname]["memberlist"] += ({leadername});
    SAVE();
    return 1;
}

mapping query_guilds_map(){
    return guilds;
}

string *query_all_guilds(){
    if(!guilds){
        guilds = ([]);
        return ({ });
    }                
    return keys(guilds);
}

mapping query_guild(string guildname){
    if(!guilds){
        guilds = ([]);
        return ({ });
    }
    if(!guilds[guildname]){
        guilds[guildname] = ([]);
        return ([ ]);
    }
    return guilds[guildname];

}

int remove_guild(string guildname){
    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        guilds[guildname] = ([]);
        return 0;
    }

    map_delete(guilds, guildname);
    //guilds[guildname] = ([ ]);
    SAVE();
    return 1;
}

string *query_guild_shorts(string guild){
    string *tmp, *glds;
    int i;

    if(!guilds){
        guilds = ([]);
        return ({});
    }


    if(guild == "all"){
        tmp = ({ });
        glds = query_all_guilds();

        for(i = 0;i<sizeof(glds);i++)
            tmp += ({ guilds[glds[i]]["short"] });

        tmp = distinct_array(tmp);
        return tmp;
    }

    if(!guilds[guild]) return ({ });
    return ({ guilds[guild]["short"] });

}

string query_guild_leader(string guildname){
    if(!guilds){
        guilds = ([]);
        return "";
    }
    return guilds[guildname]["leader"];
}

string *query_guild_hc(string guildname){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return ({ });
    }
    tmp = guilds[guildname]["hc"];
    tmp += ({query_guild_leader(guildname)});
    return tmp;
}

string *query_guild_members(string guildname){
    if(!guilds){
        guilds = ([]);
        return ({ });
    }
    return guilds[guildname]["memberlist"];
}


int set_guild_leader(string guildname, string leadname){
    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    guilds[guildname]["leader"] = lower_case(leadname);
    SAVE();
    return 1;
}

int set_guild_short(string guildname, string shortname){
    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    guilds[guildname]["short"] = shortname;
    SAVE();
    return 1;
}

int is_leader(string guildname, string name){
    if(!guilds){
        guilds = ([]);
        return -1;
    }
    if(!guilds[guildname]){
        return -1;
    }

    if(guilds[guildname]["leader"] == name) return 1;
    return 0;
}

int is_hc(string guildname, string name){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return -1;
    }
    if(!guilds[guildname]){
        return -1;
    }

    tmp = query_guild_hc(guildname);
    if(member_array(name, tmp) != -1) return 1;
    return 0;
}

int is_member(string guildname, string name){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return -1;
    }
    if(!guilds[guildname]){
        return -1;
    }

    tmp = guilds[guildname]["memberlist"];
    if(member_array(name, tmp) != -1) return 1;
    return 0;
}

int add_guild_hc(string guildname, string hcname){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    hcname = lower_case(hcname);
    tmp = guilds[guildname]["hc"];
    tmp += ({hcname});
    guilds[guildname]["hc"] = distinct_array( tmp );
    SAVE();
    return 1;
}

int remove_guild_hc(string guildname, string hcname){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    tmp = guilds[guildname]["hc"];
    tmp -= ({hcname});
    guilds[guildname]["hc"] = distinct_array( tmp );
    SAVE();
    return 1;
}

int set_guild_hc(string guildname, string *hc){
    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    guilds[guildname]["hc"] = distinct_array( hc );
    SAVE();
    return 1;
}

int add_guild_member(string guildname, string name){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    name = lower_case(name);
    tmp = guilds[guildname]["memberlist"];
    tmp += ({name});
    guilds[guildname]["memberlist"] = distinct_array( tmp );
    SAVE();
    return 1;
}

int remove_guild_member(string guildname, string name){
    string *tmp;

    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[guildname]){
        return 0;
    }

    if( is_leader(guildname, name) )
        return 0;

    if(is_hc(guildname, name))
        remove_guild_hc(guildname, name);

    tmp = guilds[guildname]["memberlist"];
    tmp -= ({name});
    guilds[guildname]["memberlist"] = distinct_array( tmp );

    SAVE();
    return 1;
}

void delete_player(string name){
    string *glds;
    int i;

    if(!guilds)
        guilds = ([]);

    glds = keys(guilds);
    for(i = 0;i<sizeof(glds);i++){

        //If this person is the leader, set HC[0] as leader
        if(is_leader(glds[i], name)){
            set_guild_leader(glds[i], query_guild_hc(glds[i])[0] );
            remove_guild_hc(glds[i], query_guild_hc(glds[i])[0] );
        }

        //If person is HC, remove him.
        if(is_hc(glds[i], name)){
            remove_guild_hc(glds[i], name);
        }
        
        //If he's a member, remove him
        if(is_member(glds[i], name)) {
            remove_guild_member(glds[i], name);
        }
    }
    SAVE();
    return 1;
}

int add_funds(string name, int amount){
    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[name]){
        return 0;
    }

    guilds[name]["account"] += amount;
    SAVE();
    return guilds[name]["account"];
}

int use_funds(string name, int amount){
    if(!guilds){
        guilds = ([]);
        return 0;
    }
    if(!guilds[name]){
        return 0;
    }

    if(guilds[name]["account"] < amount)
        return 0;

    guilds[name]["account"] -= amount;
    SAVE();
    return guilds[name]["account"];
}

int query_funds(string name){
        if(!guilds){
        guilds = ([]);
        return -1;
    }
    if(!guilds[name]){
        return -1;
    }
    
    return guilds[name]["account"];

}

int clean_up() {
    return 1;
}
