
//guilds_d.c

#include <std.h>
#include <security.h>

#define SAVE_FILE "/daemon/save/guilds"

inherit DAEMON;

string *guilds;
mapping gAccounts, troopers, defenders;
mapping controledRooms;

void SAVE();
string *query_guild_shorts(string guild);
void add_money();

void create(){
	::create();
	
	guilds = ({});
	seteuid(UID_DAEMONSAVE);
	restore_object(SAVE_FILE);
	seteuid(getuid());
	add_money();
}

void add_guild(string str){
	guilds += ({str});
	
	guilds = distinct_array(guilds);
	SAVE();
}

string *query_guild_names(){ return guilds;}

void remove_guild(string str){
	if(member_array(str, guilds) != -1){
		guilds -= ({str});
	}
	SAVE();
}

string *query_guild_shorts(string guild){
	
   return ({});
	switch (guild){
		case "Fallen Angel":
			return ({"angels"});
			break;
		case "Legion of Lost Soul":
			return ({"legion"});
			break;
		case "Shadows of Fate":
			return ({"pack"});
			break;
		case "all":
                        return ({"order","angels","legion","pack","rider","fist", "illuminati"});
			break;
                case "Order of the Metallic Dragon":
			return ({"order"});
			break;
		case "Rider":
			return ({"rider"});
			break;
		case "Iron Fist":
			return ({"fist"});
			break;
        case "Illuminati":
             return ({"illuminati"});
             break;
		default: return ({});
		}
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
}

void add_trooper(string guild, string file){
   if(!troopers) troopers = ([]);
   if(!troopers[guild]) troopers[guild] = ({});
   troopers[guild] += ({file});
   SAVE();
}

void remove_trooper(string guild, string file){
   int a;
   if(!troopers) troopers = ([]);
   if(!troopers[guild]) troopers[guild] = ({});
   if((a = member_array(file, troopers[guild])) != -1){
      troopers[guild][a] = 0;
      troopers[guild] -= ({0});
   }
   SAVE();

}
string * query_troopers(string guild){
   if(!troopers) troopers = ([]);
   if(!troopers[guild]) troopers[guild] = ({});
   return troopers[guild];
}

mapping query_all_troopers(){
   return troopers;
}

int query_guild_account(string guild){
   if(!gAccounts) gAccounts = ([]);
   if(!gAccounts[guild]) gAccounts[guild] = 0;
   return gAccounts[guild];

}

void add_guild_gold(string guild, int amount){
   if(!gAccounts) gAccounts = ([]);
   if(!gAccounts[guild]) gAccounts[guild] = 0;
   gAccounts[guild]+= amount;
   SAVE();
}

mapping query_control(string file){
   if(!controledRooms) controledRooms = ([]);
   if(!controledRooms[file]) controledRooms[file] = ([]);
   return controledRooms[file];
}

void set_controled_room(string file, string guild){
   if(!controledRooms) controledRooms = ([]);
   if(!controledRooms[file]) controledRooms[file] = ([]);
   controledRooms[file]["guild"]=guild;
   controledRooms[file]["guards"] = ({});
   SAVE();
}

int add_guard(string file,string gfile,string guild){
   if(!controledRooms) controledRooms = ([]);
   if(!controledRooms[file]) controledRooms[file] = ([]);
   if(!controledRooms[file]["guild"] || controledRooms[file]["guild"] != guild)
      return 0;
   controledRooms[file]["guards"] += ({gfile});

   SAVE();
   return 1;
}


int remove_guard(string file,string gfile,string guild){
   int a;
   if(!controledRooms) controledRooms = ([]);
   if(!controledRooms[file]) controledRooms[file] = ([]);
   if(!controledRooms[file]["guild"] || controledRooms[file]["guild"] != guild)
      return 0;
   if((a = member_array(gfile,controledRooms[file]["guards"])) != -1){
      controledRooms[file]["guards"][a] = 0;
      controledRooms[file]["guards"] -= ({0});
   }

   SAVE();
   return 1;
}
string query_control_guild(string file){
   if(!controledRooms) controledRooms = ([]);
   if(!controledRooms[file]) controledRooms[file] = ([]);
   if(!controledRooms[file]["guild"]) controledRooms[file]["guild"] = 0;
   return controledRooms[file]["guild"];
}

string * query_guards(string file){
   if(!controledRooms) controledRooms = ([]);
   if(!controledRooms[file]) controledRooms[file] = ([]);
   if(!controledRooms[file]["guards"]) controledRooms[file]["guards"] = ({});
   return controledRooms[file]["guards"];
}

int clean_up(){return 1;}

void add_money(){
   string * rooms;
   int i,j,k;
   if(!controledRooms) return;

   rooms = keys(controledRooms);

   j = sizeof(rooms);
   for (i=0;i<j;i++) {
      if(!controledRooms[rooms[i]]["guild"])
	 continue;
      if(!find_object_or_load(rooms[i])) continue;
      catch(add_guild_gold(controledRooms[rooms[i]]["guilds"],(int)rooms[i]->query_value()));

   }

}

void add_defend(string guild, string file){
   if(!defenders) defenders = ([]);
   if(!defenders[guild]) defenders[guild] = ({});
   defenders[guild] += ({file});
   SAVE();
}

void remove_defender(string guild, string file){
   int a;
   if(!defenders) defenders = ([]);
   if(!defenders[guild]) defenders[guild] = ({});
   if((a = member_array(file, defenders[guild])) != -1){
      defenders[guild][a] = 0;
      defenders[guild] -= ({0});
   }

   SAVE();

}
string * query_defenders(string guild){
   if(!defenders) defenders = ([]);
   if(!defenders[guild]) defenders[guild] = ({});
   return defenders[guild];
}

mapping query_all_defenders(){
   return defenders;
}
