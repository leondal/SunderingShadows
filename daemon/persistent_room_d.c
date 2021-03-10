// Daemon used for an avatar room generator and possibly for presistent rooms for players that
// can last through reboot.  -Ares 03/28/08

#include <std.h>
#include <security.h>
#include <daemons.h>
#include <terrain.h>

#define INHERIT_ROOM "/cmds/avatar/avatar_room.c"
#define SAVE_FILE "/d/av_rooms/avatar_room_saves"

inherit OBJECT;

mapping AVATAR_ROOMS;
nosave mapping ROOM_INFO=([]),TRAVEL_TYPES = TRAVEL_PENALTY,CURRENT_DOOR=([]),CURRENT_LOCK=([]);
nosave string PATH,FILE,DIR,*completed_stages=({}),*completed_door_stages=({}),*completed_lock_stages=({});
nosave string *STAGES = ({ "name","indoors","light","terrain_type","travel_type","climate","short_desc","long_desc","smell","listen","search","items","exits","doors" });
nosave string DOOR_STAGES = ({ "door_id", "door_destination","door_direction","door_closed","door_open_message","door_close_message","door_description","door_knock_message","door_locks" });
nosave string LOCK_STAGES = ({ "lock_name","lock_key","lock_description","lock_difficulty","is_locked" });
nosave string *CLIMATES = ({"arctic","temperate","tropical","mountain","desert"});
nosave string *TERRAINS = TERRAIN;

void clean()
{
	ROOM_INFO = (([
				 "name"			: "",
				 "ids"			: "",
				 "indoors"		: "",
				 "light"		: "",
				 "terrain_type"	: "",
				 "travel_type"	: "",
				 "climate"		: "",
			     "short_desc"	: "",
				 "long_desc"	: "",
				 "smell"		: "",
				 "listen"		: "",
				 "search"		: "",
				 "items"		: "",
				 "exits"		: "",
				 "hidden_exits" : "",
				 "doors"        : "",
				]));
	completed_stages=({});
	completed_lock_stages = ({});
	completed_door_stages = ({});
	return;
}

void create()
{
	clean();
	AVATAR_ROOMS=([]);
	restore_object(SAVE_FILE);
	::create();
	seteuid(UID_DAEMONSAVE);
}

int check(string str)
{
	if(!stringp(str) || str == "" || str == " ") { return 0; }
	return 1;
}

int fill_stages()
{
	completed_stages = STAGES;
}

int add_stage(string stage)
{
	if(!stringp(stage) || stage == "" || stage == " ") { return 0; }
	completed_stages += ({ stage });
	return 1;
}

void set_path(string path)
{
	if(!check(path)) { return; }
	// add in a path check for temporary rooms later
	if(strsrch(path,"/d/av_rooms/") == -1) { return; }

	PATH = path;
	return;
}

void set_file(string file)
{
	if(!check(file)) { return; }
	FILE = file;
	return;
}

int terrain_check(string terrain)
{
	if(!pointerp(TERRAINS) || TERRAINS == ({}))
	{
		return notify_fail("TERRAINS not set in persistent_room_d.c, please contact a wiz.");
	}
	if(member_array(terrain,TERRAINS) == -1) { return 0; }
	return 1;
}

int travel_check(string travel)
{
	string *types = ({});
	if(!mapp(TRAVEL_TYPES) || TRAVEL_TYPES == ([]))
	{
		return notify_fail("TRAVEL_TYPES not set in persistent_room_d.c, please contact a wiz.");
	}
	types = keys(TRAVEL_TYPES);
	if(member_array(travel,types) == -1) { return 0; }
	return 1;
}

int climate_check(string climate)
{
	if(!pointerp(CLIMATES) || CLIMATES == ({}))
	{
		return notify_fail("CLIMATES not set in persistent_room_d.c, please contact a wiz.");
	}
	if(member_array(climate,CLIMATES) == -1) { return 0; }
	return 1;
}

int set_room_name(string name)
{
	if(!check(name)) { return 0; }
	ROOM_INFO["name"] = name;
	add_stage("name");
	return 1;
}

int set_room_ids(string *ids) // used for some temporary rooms that will be player camps.
{
	if(!pointerp(ids) || !sizeof(ids)) { return 0; }
	ROOM_INFO["ids"] = ids;
	return 1;
}

int set_indoors_outdoors(int num)
{
	if(!intp(num)) { return 0; }
	ROOM_INFO["indoors"] = num;
	add_stage("indoors");
	return 1;
}

int set_room_light(int num)
{
	if(!intp(num)) { return 0; }
	ROOM_INFO["light"] = num;
	add_stage("light");
	return 1;
}

int set_room_terrain(string terrain)
{
	if(!check(terrain)) { return 0; }
	if(!terrain_check(terrain)) { return 0; }
	ROOM_INFO["terrain_type"] = terrain;
	add_stage("terrain_type");
	return 1;
}

int set_room_travel(string travel)
{
	if(!check(travel)) { return 0; }
	if(!travel_check(travel)) { return 0; }
	ROOM_INFO["travel_type"] = travel;
	add_stage("travel_type");
	return 1;
}

int set_room_climate(string climate)
{
	if(!check(climate)) { return 0; }
	if(!climate_check(climate)) { return 0; }
	ROOM_INFO["climate"] = climate;
	add_stage("climate");
	return 1;
}

int set_room_short(string str)
{
	if(!check(str)) { return 0; }
	ROOM_INFO["short_desc"] = str;
	add_stage("short_desc");
	return 1;
}

int set_long_desc(string desc)
{
	if(!check(desc)) { return 0; }
	ROOM_INFO["long_desc"] = desc;
	add_stage("long_desc");
	return 1;
}

int set_room_smell(string smell)
{
	if(!check(smell)) { return 0; }
	ROOM_INFO["smell"] = smell;
	add_stage("smell");
	return 1;
}

int set_room_listen(string listen)
{
	if(!check(listen)) { return 0; }
	ROOM_INFO["listen"] = listen;
	add_stage("listen");
	return 1;
}

void set_current_door(string door)
{
	if(!stringp(door)) { return; }
	if(is_existing_door(door))
	{
		CURRENT_DOOR = ROOM_INFO["doors"][door];
	}
	else
	{
		CURRENT_DOOR["door_id"] = door;
	}
	return;
}

void set_current_lock(string lock)
{
	if(!stringp(lock)) { return; }
	CURRENT_LOCK["lock_name"] = lock;
	return;
}

void setup_current_lock(mapping lock)
{
	if(!mapp(lock)) { return; }
	CURRENT_LOCK[lock["lock_name"]] = lock;
	return;
}

int set_doors(mapping doors)
{
	if(!mapp(doors)) { return 0; }
	ROOM_INFO["doors"] = doors;
	return 1;
}

int add_hidden_exit(string exit)
{
	if(!pointerp(ROOM_INFO["hidden_exits"]))
	{
		ROOM_INFO["hidden_exits"] = ({});
	}
	if(!stringp(exit) || exit == "") { return 0; }
	ROOM_INFO["hidden_exits"] += ({ exit });
	return 1;
}

int set_room_hidden_exits(string *exits)
{
	if(!pointerp(exits)) { return 0; }
	ROOM_INFO["hidden_exits"] = exits;
	return 1;
}

int delete_hidden_exit(string exit)
{
	if(!pointerp(ROOM_INFO["hidden_exits"])) { return 0; }
	ROOM_INFO["hidden_exits"] -= ({ exit });
	return 1;
}

int delete_all_hidden()
{
	ROOM_INFO["hidden_exits"] = ({});
	return 1;
}

string *query_hidden_exits()
{
	if(!pointerp(ROOM_INFO["hidden_exits"])) { return ({}); }
	return ROOM_INFO["hidden_exits"];
}


void fill_door_stages()
{
	completed_door_stages = DOOR_STAGES;
	return;
}

void fill_lock_stages()
{
	completed_lock_stages = LOCK_STAGES;
	return;
}

void clear_all_doors()
{
	ROOM_INFO["doors"] = ([]);
	return;
}

void delete_door(string door)
{
	if(!stringp(door)) { return; }
	if(!is_existing_door(door)) { return; }
	map_delete(ROOM_INFO["doors"],door);
	return;
}

void delete_lock(string door,string lock)
{
	mapping locks=([]);
	if(!stringp(door) || !stringp(lock)) { return; }
	if(!is_existing_lock(door,lock)) { return; }
	locks = ROOM_INFO["doors"]["door_locks"];
	map_delete(locks,lock);
	return;
}

void clear_all_locks(string door)
{
	mapping door_info = ([]);
	if(!stringp(door)) { return; }
	if(!is_existing_door(door)) { return; }
	if(!mapp(ROOM_INFO["doors"])) { return; }
	door_info = ROOM_INFO["doors"];
	door_info[door]["door_locks"] = ([]);
	return;
}

int clear_current_door(string door)
{
	if(!stringp(door)) { return 0; }
	if(door != CURRENT_DOOR["door_id"]) { return 0; }
	CURRENT_DOOR = ([]);
	completed_door_stages = ({});
	return 1;
}

int clear_current_lock(string door,string lock)
{
	if(!stringp(door) || !stringp(lock)) { return 0; }
	if(door != CURRENT_DOOR["door_id"]) { return 0; }
	if(lock != CURRENT_LOCK["lock_name"]) { return 0; }
	CURRENT_LOCK = ([]);
	completed_lock_stages = ({});
	return 1;
}

int is_existing_door(string door)
{
	string *doors=({});
	if(!stringp(door)) { return 0; }
	if(!mapp(ROOM_INFO["doors"])) { return 0; }
	doors = keys(ROOM_INFO["doors"]);
	if(member_array(door,doors) == -1) { return 0; }
	return 1;
}

int is_existing_lock(string door,string lock)
{
	mapping door_info=([]);
	if(!stringp(door) || !stringp(lock)) { return 0; }
	if(!is_existing_door(door)) { return 0; }
	door_info = ROOM_INFO["doors"];
	if(!mapp(door_info[door][lock])) { return 0; }
	return 1;
}

int is_current_door(string door)
{
	if(!stringp(door)) { return 0; }
	if(door == CURRENT_DOOR["door_id"]) { return 1; }
	return 0;
}

int is_current_lock(string lock)
{
	if(!stringp(lock)) { return 0; }
	if(lock == CURRENT_LOCK["lock_name"]) { return 1; }
	return 0;
}

int set_door_data(string door,string type,string data)
{
	if(!stringp(door) || !stringp(type) || !stringp(data)) { return 0; }
	if(!is_current_door(door)) { return 0; }
	if(member_array(type,DOOR_STAGES) == -1) { return 0; }
	if(type == "door_closed") { CURRENT_DOOR[type] = to_int(data); }
	else { CURRENT_DOOR[type] = data; }
	if(type == "door_locks" && data == "")
	{
		CURRENT_DOOR["door_locks"] = ([]);
	}
	completed_door_stages += ({ type });
	return 1;
}

int set_lock_data(string door,string lock,string type,string data)
{
	if(!stringp(door) || !stringp(lock) || !stringp(type) || !stringp(data)) { return 0; }
	if(!is_current_lock(lock)) { return 0; }
	if(!is_current_door(door)) { return 0; }
	if(member_array(type,LOCK_STAGES) == -1) { return 0; }
	if(type == "lock_difficulty" || type == "is_locked") { CURRENT_LOCK[type] = to_int(data); }
	else { CURRENT_LOCK[type] = data; }
	completed_lock_stages += ({ type });
	return 1;
}

void add_lock(string door,string lock)
{
	mapping door_info=([]);
	if(!stringp(door) || !stringp(lock)) { return; }
	if(!is_current_door(door)) { return; }
	if(!is_current_lock(lock)) { return; }
	if(!mapp(CURRENT_DOOR)) { return; }
	door_info = CURRENT_DOOR;
	if(!mapp(door_info["door_locks"]))
	{
		door_info["door_locks"] = ([]);
	}
	door_info["door_locks"] += ([ CURRENT_LOCK["lock_name"] : CURRENT_LOCK, ]);
	CURRENT_LOCK = ([]);
	completed_door_stages += ({ "door_locks" });
	completed_lock_stages = ({});
	return;
}

int complete_lock(string door,string lock)
{
	int i;
	if(!stringp(door) || !stringp(lock)) { return 0; }
	if(!is_current_lock(lock)) { return 0; }
	if(!is_current_door(door)) { return 0; }
	for(i=0;i<sizeof(LOCK_STAGES);i++)
	{
		if(member_array(LOCK_STAGES[i],completed_lock_stages) == -1)
		{
			return 0;
		}
	}
	add_lock(door,lock);
	return 1;
}

void add_door(string door)
{
	if(!stringp(door)) { return; }
	if(!is_current_door(door)) { return; }
	if(!mapp(ROOM_INFO["doors"])) { ROOM_INFO["doors"] = ([]); }
	ROOM_INFO["doors"] += ([ CURRENT_DOOR["door_id"] : CURRENT_DOOR, ]);
	add_stage("doors");
	CURRENT_DOOR = ([]);
	completed_door_stages = ({});
	return;
}

int complete_door(string door)
{
	int i;
	if(!stringp(door)) { return 0; }
	if(!is_current_door(door)) { return 0; }
	for(i=0;i<sizeof(DOOR_STAGES);i++)
	{
		if(member_array(DOOR_STAGES[i],completed_door_stages) == -1)
		{
			return 0;
		}
	}
	add_door(door);
	return 1;
}

mapping query_doors()
{
	if(!mapp(ROOM_INFO["doors"])) { return ([]); }
	return ROOM_INFO["doors"];
}

mapping query_locks(string door)
{
	mapping doors=([]),locks=([]);
	if(!stringp(door)) { return ([]); }
	if(!is_existing_door(door)) { return ([]); }
	doors = ROOM_INFO["doors"];
	if(!mapp(doors)) { return ([]); }
	locks = doors["door_locks"];
	if(!mapp(locks)) { return ([]); }
	return locks;
}

mapping query_door(string door)
{
	mapping doors=([]),the_door=([]);
	if(!stringp(door)) { return ([]); }
	if(!is_existing_door(door)) { return ([]); }
	doors = ROOM_INFO["doors"];
	the_door = doors["door"];
	if(!mapp(the_door)) { return ([]); }
	return the_door;
}

mapping query_lock(string door,string lock)
{
	mapping doors=([]),the_door=([]),locks=([]),the_lock=([]);
	if(!stringp(door) || stringp(lock)) { return ([]); }
	if(!is_existing_door(door)) { return ([]); }
	if(!is_existing_lock(door,lock)) { return ([]); }
	doors = ROOM_INFO["doors"];
	if(!mapp(doors)) { return ([]); }
	the_door = doors[door];
	if(!mapp(the_door)) { return ([]); }
	locks = the_door["door_locks"];
	if(!mapp(locks)) { return ([]); }
	the_lock = locks["lock_name"];
	if(!mapp(the_lock)) { return ([]); }
	return the_lock;
}

string *query_completed_door_stages()
{
	return completed_door_stages;
}

string *query_completed_lock_stages()
{
	return completed_lock_stages;
}

string *query_door_stages()
{
	return DOOR_STAGES;
}

string *query_lock_stages()
{
	return LOCK_STAGES;
}

void setup_new_door(string door)
{
	if(!stringp(door)) { return; }
	if(is_existing_door(door)) { return; }
	CURRENT_DOOR = ([ "door_id"            : door,
                      "door_destination"   : "",
					  "door_direction"     : "",
					  "door_key"           : "",
					  "door_closed"        : 0,
					  "door_locked"        : 0,
					  "door_close_message" : "",
					  "door_open_message"  : "",
					  "door_description"   : "",
					  "door_knock_message" : "",
					  "door_locks"         : ([]),
					]);
	set_current_door(door);
	return;
}

void setup_new_lock(string door,string lock)
{
	if(!stringp(door) || !stringp(lock)) { return; }
	if(!is_current_door(door)) { return; }
	if(is_existing_lock(door,lock)) { return; }
	CURRENT_LOCK[lock] = ([ "lock_name"			: lock,
							"lock_key"			: "",
							"lock_description"	: "",
							"door_id"			: door,
							"lock_difficulty"	: 0,
							"is_locked"			: 0,
						]);
	set_current_lock(lock);
	return;
}

int set_room_searches(mapping searches)
{
	if(!mapp(searches)) { return 0; }
	ROOM_INFO["search"] = searches;
	add_stage("search");
	return 1;
}

int set_room_items(mapping items)
{
	if(!mapp(items)) { return 0; }
	ROOM_INFO["items"] = items;
	add_stage("items");
	return 1;
}

int set_room_exits(mapping exits)
{
	if(!mapp(exits)) { return 0; }
	ROOM_INFO["exits"] = exits;
	add_stage("exits");
	return 1;
}

int set_room_doors(mapping doors)
{
	if(!mapp(doors)) { return 0; }
	ROOM_INFO["doors"] = doors;
	add_stage("doors");
	return 1;
}

mapping query_room_info()
{
	if(mapp(ROOM_INFO)) { return ROOM_INFO; }
	return ([]);
}

void clean_room_info()
{
	ROOM_INFO = ([]);
	return;
}

void set_room_info(mapping map)
{
	if(mapp(map) && map != ([]))
	{
		ROOM_INFO = map;
	}
	return;
}

mixed query_room_data(string data)
{
	return ROOM_INFO[data];
}

string query_save_path()
{
	return PATH;
}

string query_file_name()
{
	return FILE;
}

string *stage_check()
{
	string *incomplete=({});
	int i;
	if(!pointerp(completed_stages) || completed_stages == ({})) { return STAGES; }
	for(i=0;i<sizeof(STAGES);i++)
	{
		if(member_array(STAGES[i],completed_stages) == -1)
		{
			incomplete += ({ STAGES[i] });
		}
	}
	if(pointerp(incomplete) && incomplete != ({})) { return incomplete; }
	return ({});
}

string *query_stages()
{
	return STAGES;
}

string *query_climates()
{
	return CLIMATES;
}

string *query_terrains()
{
	return TERRAINS;
}

mapping query_travel_types()
{
	return TRAVEL_TYPES;
}

int query_complete()
{
	string *stages=({});
	stages = stage_check();
	if(sizeof(stages)) { return 0; }
	return 1;
}

mapping retrieve_room_info(string file)
{
	mapping info = ([]);

	if(!check(file)) { return ([]); }
	if(!file_exists(file)) { return ([]); }

	info = AVATAR_ROOMS[file];
	if(!mapp(info)) { write("%^B_RED%^%^CYAN%^Invalid mapping, restoration failed.%^RESET%^"); }
	return info;
}

void delete_room_from_map(string file)
{
	if(!file_exists(file)) { return; }
	map_delete(AVATAR_ROOMS,file);
	save_object(SAVE_FILE);
	return;
}

int SAVE()
{
	mapping info = ([]),door=([]),locks=([]),lock=([]);
	string *arr=({}),*desc_sections=({}),long_desc,*temp=({});
	mixed *items=({});
	int i,j,num,hops,extra;

	if(!query_complete())
	{
		arr = stage_check();
		write("You must complete the room first.");
		write("You have the following things unfinished: "+implode(arr,",")+"");
	}

	long_desc = ROOM_INFO["long_desc"];
	num = strlen(long_desc);
	if(num > 200)
	{
		hops = num/200;
		extra = num%200;
		for(i=0;i<hops;i++)
		{
			desc_sections += ({ long_desc[(i*200)..((i*200)+199)] });
		}
		if(extra)
		{
			desc_sections += ({ long_desc[(hops*200)..num] });
		}
	}

	DIR = PATH + FILE+".c";

	AVATAR_ROOMS[DIR] = ROOM_INFO;
	save_object(SAVE_FILE);

	write("%^B_RED%^%^CYAN%^writing to file "+DIR+"%^RESET%^");

	write_file(DIR,"// File created with /daemon/persistent_room_d.c\n");
	write_file(DIR,"#include <std.h>\n\n");

	write_file(DIR,"inherit \""+INHERIT_ROOM+"\";\n\n");

	write_file(DIR,"void create()\n");
	write_file(DIR,"{\n");
	write_file(DIR,"    ::create();\n");
	write_file(DIR,"    set_name(\""+ROOM_INFO["name"]+"\");\n");

	if(pointerp(ROOM_INFO["ids"]) && sizeof(ROOM_INFO["ids"]))
	{
		write_file(DIR,"    set_id("+identify(ROOM_INFO["ids"])+");\n");
	}

	write_file(DIR,"    set_property(\"indoors\","+ROOM_INFO["indoors"]+");\n");
	write_file(DIR,"    set_property(\"light\","+ROOM_INFO["light"]+");\n");
	write_file(DIR,"    set_property(\"no teleport\",1);\n");
	write_file(DIR,"    set_terrain(\""+ROOM_INFO["terrain_type"]+"\");\n");
	write_file(DIR,"    set_travel(\""+ROOM_INFO["travel_type"]+"\");\n");
	write_file(DIR,"    set_climate(\""+ROOM_INFO["climate"]+"\");\n\n");
	write_file(DIR,"    set_short(\""+ROOM_INFO["short_desc"]+"\");\n\n");

	if(pointerp(desc_sections) && desc_sections != ({}))
	{
		write_file(DIR,"    set_long(\""+desc_sections[0]+"\"\n");
		for(i=1;i<sizeof(desc_sections);i++) //i = 1 intentionally
		{
			write_file(DIR,"\t\""+desc_sections[i]+"\"\n");
		}
		write_file(DIR,"\t);\n\n");
	}
	else
	{
		write_file(DIR,"    set_long(\""+ROOM_INFO["long_desc"]+"\");\n\n");
	}

	write_file(DIR,"    set_smell(\"default\",\"\n"+ROOM_INFO["smell"]+"\");\n");
	write_file(DIR,"    set_listen(\"default\",\""+ROOM_INFO["listen"]+"\");\n\n");

	if(mapp(ROOM_INFO["search"]) && ROOM_INFO["search"] != ([]))
	{
		info = ROOM_INFO["search"];
		arr = keys(info);
		if(sizeof(arr))
		{
			for(i=0;i<sizeof(arr);i++)
			{
				write_file(DIR,"    set_search(\""+arr[i]+"\",\""+info[arr[i]]+"\");\n");
			}
		}
	}

	if(mapp(ROOM_INFO["items"]) && ROOM_INFO["items"] != ([]))
	{
		info = ROOM_INFO["items"];
		items = keys(info);
		{
			if(sizeof(items))
			{
				write_file(DIR,"    \nset_items(([ \n");
				for(i=0;i<sizeof(items);i++)
				{
					if(pointerp(items[i]))
					{
						write_file(DIR,"\t"+identify(items[i])+" : \""+info[items[i]]+"\",\n");
					}
					else
					{
						write_file(DIR,"\t\""+items[i]+"\" : \""+info[items[i]]+"\",\n");
					}
				}
				write_file(DIR,"\t]));\n");
			}
		}
	}

	if(mapp(ROOM_INFO["exits"]) && ROOM_INFO["exits"] != ([]))
	{
		info = ROOM_INFO["exits"];
		arr = keys(info);

		if(sizeof(arr))
		{
			write_file(DIR,"\n    set_exits(([ \n");
			for(i=0;i<sizeof(arr);i++)
			{
				write_file(DIR,"\t\t\""+arr[i]+"\" : \""+info[arr[i]]+"\",\n");
			}
			write_file(DIR,"\t]));\n\n");
		}
	}

	if(pointerp(ROOM_INFO["hidden_exits"]) && sizeof(ROOM_INFO["hidden_exits"]))
	{
		write_file(DIR,"\n\n    set_invis_exits("+identify(ROOM_INFO["hidden_exits"])+");\n\n");
	}

	if(mapp(ROOM_INFO["doors"]) && ROOM_INFO["doors"] != ([]))
	{
		info = ROOM_INFO["doors"];
		arr = keys(info);
		if(sizeof(arr))
		{
			for(i=0;i<sizeof(arr);i++)
			{
				door = info[arr[i]];
				locks = door["door_locks"];

				if(mapp(locks)) { temp = keys(locks); }
				if(pointerp(temp) && sizeof(temp))
				{
					write_file(DIR,"    set_door(\""+door["door_id"]+"\",\""+door["door_destination"]+"\",\""+door["door_direction"]+"\",\""+locks[temp[0]]["lock_key"]+"\",\""+temp[0]+"\");\n");

					for(j=0;j<sizeof(temp);j++)
					{
						lock = locks[temp[j]];

						write_file(DIR,"    add_lock(\""+door["door_id"]+"\",\""+lock["lock_key"]+"\",\""+lock["lock_name"]+"\",\""+lock["lock_description"]+"\");\n");
						write_file(DIR,"    set_locked(\""+door["door_id"]+"\","+lock["is_locked"]+",\""+lock["lock_name"]+"\");\n");
						if(lock["lock_difficulty"])
						{
							write_file(DIR,"    lock_difficulty(\""+door["door_id"]+"\","+lock["lock_difficulty"]+",\""+lock["lock_name"]+"\");\n");
						}
					}
				}
				else
				{
					write_file(DIR,"    set_door(\""+door["door_id"]+"\",\""+door["door_destination"]+"\",\""+door["door_direction"]+"\");\n");
				}

				if(door["door_closed"])
				{
					write_file(DIR,"    set_open(\""+door["door_id"]+"\",0);\n");
				}
				if(door["door_knock_message"])
				{
					write_file(DIR,"    set_string(\""+door["door_id"]+"\",""\"knock\",\""+door["door_knock_message"]+"\");\n");
				}
				if(door["door_open_message"])
				{
					write_file(DIR,"    set_string(\""+door["door_id"]+"\",""\"open\",\""+door["door_open_message"]+"\");\n");
				}
				if(door["door_close_message"])
				{
					write_file(DIR,"    set_string(\""+door["door_id"]+"\",""\"close\",\""+door["door_close_message"]+"\");\n");
				}
				if(door["door_description"])
				{
					write_file(DIR,"    set_door_description(\""+door["door_id"]+"\",\""+door["door_description"]+"\");\n");
				}
			}
		}
	}

	write_file(DIR,"}");

	write("%^B_RED%^%^CYAN%^Finishing..  file created "+DIR+".%^RESET%^");
	return 1;
}
