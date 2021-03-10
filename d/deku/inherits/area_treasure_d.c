#include <std.h>
#include <daemons.h>
#include <security.h>
#include <money.h>

inherit DAEMON;
#define AREA_TREASURE "/d/save/area_treasure/"

int total_treasure_value = 100000;
int max_mon_treasure = 4000;
int use_eq_value = 0;
int value_used = 0;
int exp_used = 0;
int use_exp_daemon = 0;
int max_area_exp = 350000;
int max_monster_exp = 5000;

mapping monsters_list = ([]);

void SAVE(string file);
void RESTORE(string file);
varargs init_treasure_for_area(string file, int max_treasure,
int max_mon_treasure, int use_eq, object mon);

int set_max_monster_treasure(int x, string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	if(!x) return max_mon_treasure;
	max_mon_treasure = x;
	SAVE(AREA_TREASURE+file);
	return max_mon_treasure;
}

int query_max_monster_treasure(string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0; 
	RESTORE(AREA_TREASURE+file);
	return max_mon_treasure;
}

int set_total_treasure_value(int x, string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	if(!x) return total_treasure_value;
	total_treasure_value = x;
	SAVE(AREA_TREASURE+file);
	return total_treasure_value;
}

int query_total_treasure_value(string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	return total_treasure_value;
}

void recalculate_monster_count(string file)
{
	int x;
	string *tmp;
	string *remove_mobs = ({});
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return;
	RESTORE(AREA_TREASURE+file);
	tmp = keys(monsters_list);
	for(x = 0;x < sizeof(tmp);x++)
	{
		if(!find_object(tmp[x]))
		{
			remove_mobs += ({tmp[x]});
		}
	}
	//tell_object(find_player("saide"), identify(remove_mobs));
	for(x = 0;x < sizeof(remove_mobs);x++)
	{
		map_delete(monsters_list,remove_mobs[x]);
	}
	//tell_object(find_player("saide"), identify(monsters_list));
	SAVE(AREA_TREASURE+file);
	return;
}

//Pure test function to see
//how the recalcuation of mobs is working - Saide
void summon_all_mobs(string file)
{
	int x;
	string *tmp;
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return;
	RESTORE(AREA_TREASURE+file);
	tmp = keys(monsters_list);
	for(x = 0;x < sizeof(tmp);x++)
	{
		if(!find_object(tmp[x])) continue;
		find_object(tmp[x])->move("/realms/saide/workroom");
	}
}

int get_monster_count(string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	recalculate_monster_count(file);
	RESTORE(AREA_TREASURE+file);
	return sizeof(keys(monsters_list));
}
	
int set_use_eq_value(int x, string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	if(!x) return use_eq_value;
	use_eq_value = x;
	SAVE(AREA_TREASURE+file);
	return use_eq_value;
}

int query_use_eq_value(string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	return use_eq_value;
}	

//Stole directly from ares /cmds/avatar/_note.c 
//Saide - 8/28/07

int convert_coins(mapping money)
{
    int i,coins,value;
    for(i=0;i<sizeof(HARD_CURRENCIES);i++)
    {
        coins = money[HARD_CURRENCIES[i]];
        coins = coins / EXCHANGE_RATES[i];
        value += coins;
    }   
    return value;
}

void recalculate_area_value(string file)
{
	int x, val, y, tmp = 0, val_left, val_add, tmp_max;
	mapping moneys = ([]); 
	string *currs, *tmpa = ({0, 0});
	object *minven = ({});
	object mon;
	string *mon_names;
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return;
	recalculate_monster_count(file);
	RESTORE(AREA_TREASURE+file);
	//Assign money - is equipment value used or not?
	//Saide
	//tell_object(find_player("saide"), "It is getting here also..");
	value_used = 0;
	exp_used = 0;
	mon_names = keys(monsters_list);
	for(x = 0;x < sizeof(mon_names);x++)
	{
		if(!mon = find_object(mon_names[x])) continue;
		if(use_exp_daemon)
		{
			mon->set_exp(1 + random(10));
		}
		currs = mon->query_currencies();
		moneys = ([]);
		for(y = 0; y < sizeof(currs);y++)
		{
			moneys += ([currs[y] : 
			mon->query_money(currs[y])]);
			mon->add_money(currs[y], 
			(0-to_int(mon->query_money(currs[y]))));	
		}	
	}
	for(x = 0;x < sizeof(mon_names);x++)
	{
		if(!mon = find_object(mon_names[x])) continue;
		tmpa = ({0, 0});
		//tell_object(find_player("saide"), "gets to the second loop..");
		if(use_eq_value)
		{
			minven = all_inventory(mon);
			tmp = 0;
			for(y = 0;y < sizeof(minven);y++)
			{
				tmp += to_int(minven[y]->query_value());
				value_used += tmp;	
			}
		}
		if(value_used < total_treasure_value)
		{
			val_left = total_treasure_value - value_used;
			if(val_left > 0) 
			{
				if(val_left < max_mon_treasure) 
				{
					tmp_max = val_left;
				}
				else
				{
					tmp_max = max_mon_treasure;
				}
				val_add = tmp_max / 4 + (random(tmp_max/4) * 3);
				val_add = val_add / (sizeof(monsters_list) / 20 + 1);
				mon->add_money("gold", val_add);	
				tmpa[0] = val_add + tmp;
				value_used += val_add;
			}
		}
		if(exp_used < max_area_exp && use_exp_daemon)
		{
			val_left = max_area_exp - exp_used;
			if(val_left > 0)
			{
				if(val_left < max_monster_exp) 
				{
					tmp_max = val_left;
				}
				else
				{
					tmp_max = max_monster_exp;
				}
				val_add = tmp_max / 2 + (random(tmp_max/2));
				val_add = val_add / (sizeof(monsters_list) / 40 + 1);
				mon->set_exp(val_add);
				tmpa[1] = val_add;
				//tell_object(find_player("saide"), identify(tmpa));
				exp_used += val_add;
			}
		}			
		monsters_list[mon_names[x]] = tmpa;
	}

	SAVE(AREA_TREASURE+file);
	return;	
		
}


void register_monster(object mon, string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return;
	if(!objectp(mon)) return;
	RESTORE(AREA_TREASURE+file);
	//tell_object(find_player("saide"), "it is getting here too...");
	if(sizeof(keys(monsters_list))) 
	{
		if(member_array(file_name(mon), keys(monsters_list)) != -1)
		{
			return;
		}
	}
	monsters_list += ([file_name(mon) : ({0, 0})]);
	SAVE(AREA_TREASURE+file);
	recalculate_area_value(file);
	return;
}

int set_max_monster_exp(int exp, string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	if(!exp || exp < 0)
	{
		return max_monster_exp;
	}
	max_monster_exp = exp;
	SAVE(AREA_TREASURE+file);
	return exp;
}

int query_max_monster_exp(string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	return max_monster_exp;
}

int set_max_area_exp(int exp, string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	if(!exp || exp < 0)
	{
		exp = max_area_exp;
	}
	max_area_exp = exp;
	SAVE(AREA_TREASURE+file);
	return exp;
}

int query_max_area_exp(string file)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	return max_area_exp;
}

int set_use_exp_daemon(int val, string file, int x, int y)
{
	if(!file || !file_exists(AREA_TREASURE+file+".o")) return 0;
	RESTORE(AREA_TREASURE+file);
	if(!val) return use_exp_daemon;
	use_exp_daemon = val;
	//tell_object(find_player("saide"), "%^BOLD%^%^RED%^"+
	//"use_exp_daemon variable = "+use_exp_daemon);
	SAVE(AREA_TREASURE+file);
	set_max_monster_exp(x, file);
	set_max_area_exp(y, file);
	return use_exp_daemon;
}

varargs init_treasure_for_area(string file, int max_treasure,
int max_mon_treasure, int use_eq, object mon, int max_mon_exp,
int max_exp)
{
	int flag = 0;
	return;
	if(!file || !objectp(mon)) return;
	if(!file_exists(AREA_TREASURE+file+".o"))
	{
		SAVE(AREA_TREASURE+file);
		flag = 1;
	}
	if(max_treasure && max_treasure > 0 && flag)
	{
		set_total_treasure_value(max_treasure, file);
	}
	if(max_mon_treasure && max_mon_treasure > 0 && flag)
	{
		set_max_monster_treasure(max_mon_treasure, file);
	}
	if(flag && use_eq >= 0)
	{
		set_use_eq_value(use_eq, file);
	}
	if(max_mon_exp > 0 && flag)
	{
		set_use_exp_daemon(1, file, max_mon_exp, max_exp);
	}
	//tell_object(find_player("saide"), "IT GETS HERE DUMMY!");
	register_monster(mon, file);
}

void SAVE(string file)
{
    	seteuid(UID_DAEMONSAVE);
   	save_object(file);
    	return;
}

void RESTORE(string file)
{
	seteuid(UID_DAEMONSAVE);
    	restore_object(file);
    	return;
}	


