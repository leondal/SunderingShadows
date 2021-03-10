//Innate Abilities - Saide
//Want InnateAbilities to look like 
//(["ability name" : 
//({"ability type" - spell or another type of ability
//level mod - think like 0.5 (for casting of a spell at half their level)
//uses per day - 1 for most abilities
//delay before refreshing in days - 1 will refresh at the next midnight, 2 at midnight 
//a day later 
//uses left - how many more times can they use it
//time it must be before they can use it again
//level required to use it
//class specific - checks the level of this class 
//if it's set and level required is greater than 0])
//(["mirror image" : (["type" : "spell", "casting level " : 0.5, 
//"daily uses" : 2, "delay" : 1, "uses left" : 2, "refresh time" : -1, 
//"level required" : 0, "class specific" : 0]), ])
#include "std.h"
#include "daemons.h"

//inherit LIVING;
inherit "/adm/failsafe/living_failsafe.c";

mapping InnateAbilities;

mixed query_innate_spells();
mixed query_innate_abilities();
int can_use_innate_ability(string ability);
int use_innate_ability(string ability);
int query_usable_innate_time(string ability);
void add_bonus_innate(mapping ability);
int query_innate_ability_level(mapping ability);
void remove_bonus_innate(string ability);
int query_innate_ability_uses_remaining(string ability);
int query_innate_ability_total_uses(string ability);
int query_innate_ability_level(string ability);
int query_innate_useable_time(string ability);
int meets_innate_level_requirement(string ability);

void restrict_innate_ability(string ability);
void unrestrict_innate_ability(string ability);

void reset_racial_innate() { TO->delete("racial innate"); }
void restrict_innate_ability(string ability)
{
	mixed tmp;
	if(!stringp(ability)) return;
	tmp = TO->query("restricted_innate_abilities");
	if(sizeof(tmp)) 
	{
		if(member_array(ability, tmp) != -1) return;
		tmp += ({ability});
	}
	else tmp = ({ability});
	TO->delete("restricted_innate_abilities");
	TO->set("restricted_innate_abilities", tmp);
	return;
}

void unrestrict_innate_ability(string ability)
{
	mixed tmp;
	if(!stringp(ability)) return;
	tmp = TO->query("restricted_innate_abilities");
	if(sizeof(tmp)) 
	{
		if(member_array(ability, tmp) == -1) return;
		tmp -= ({ability});
	}
	TO->delete("restricted_innate_abilities");
	if(sizeof(tmp)) 
	{
		TO->set("restricted_innate_abilities", tmp);
	}
	return;
}

void InitInnate()
{
	string MyRaceFile;
	mixed RacialInnate;
	//check_temp_innate();
	if(TO->query("test_innate_allowed")) 
	{
		//temp variable that allowed testing - moving past this now - Saide
		TO->delete("test_innate_allowed");
	}
	if((string)TO->query("racial innate") != (string)TO->query_race())
	{ 
		InnateAbilities = ([]);
		TO->set("racial innate", (string)TO->query_race());
		MyRaceFile = "/std/races/"+(string)TO->query_race()+".c";
		//tell_object(find_player("saide"), "MyRaceFile = "+MyRaceFile);
		if(file_exists(MyRaceFile))
		{
			RacialInnate = MyRaceFile->query_racial_innate(TO->query("subrace"));
			if(mapp(RacialInnate)) 
			{
				if(sizeof(keys(RacialInnate)))
				{
					InnateAbilities += RacialInnate;
				}
			}
		}
	}
	return;

}

void remove_bonus_innate(string *ability)
{
	int x;
	InitInnate();
	if(!mapp(InnateAbilities)) return;
	for(x = 0;x < sizeof(ability);x++)
	{
		if(member_array(ability[x], keys(InnateAbilities)) == -1)
		{
			continue;
		}
		if(InnateAbilities[ability[x]]["remove time"] == -1) 
		{
			map_delete(InnateAbilities, ability[x]);
			continue;
		}
		InnateAbilities[ability[x]]["temp granted"] = 2;
		continue;
	}
}

void add_bonus_innate(mapping BonusInnate)
{
	string *tmp, *tmp2, *tmp3;
	int x;
	if(!mapp(BonusInnate)) return;
	InitInnate();
	if(!mapp(InnateAbilities)) return;
	tmp = keys(BonusInnate);
	tmp2 = keys(InnateAbilities);
	tmp3 = ({});
	for(x = 0;x < sizeof(tmp);x++)
	{
		if(!mapp(BonusInnate[tmp[x]]))
		{
			tmp3 += ({tmp[x]});
			continue;
		}
		if(member_array(tmp[x], tmp2) != -1)
		{
			tmp3 += ({tmp[x]});
			continue;
		}
		BonusInnate[tmp[x]] += (["temp granted" : 1, "remove time" : -1]);
		if(!BonusInnate[tmp[x]]["type"]) 
		{
			BonusInnate[tmp[x]] += (["type" : "spell"]);
		}
		if(!BonusInnate[tmp[x]]["casting level"]) 
		{
			BonusInnate[tmp[x]] += (["casting level" : 0.5]);
		}
		if(!BonusInnate[tmp[x]]["daily uses"]) 
		{
			BonusInnate[tmp[x]] += (["daily uses" : 1]);
		}
		if(!BonusInnate[tmp[x]]["uses left"])
		{
			BonusInnate[tmp[x]] += (["uses left" : 1]);
		}
		if(!BonusInnate[tmp[x]]["refresh time"])
		{
			BonusInnate[tmp[x]] += (["refresh time" : -1]);
		}
		if(!BonusInnate[tmp[x]]["delay"])
		{
			BonusInnate[tmp[x]] += (["delay" : 1]);
		}		
		continue;
	}
	for(x = 0;x < sizeof(tmp3);x++)
	{
		map_delete(BonusInnate, tmp3[x]);
		continue;
	}
	if(!mapp(BonusInnate)) return;
	if(!sizeof(keys(BonusInnate))) return;
	InnateAbilities += BonusInnate;
}

mixed query_innate_spells()
{
	string *tmp, *tmp2;
	int x;
	InitInnate();
	if(!objectp(TO)) return 0;
	if(!mapp(InnateAbilities)) return 0;
	if(!sizeof(keys(InnateAbilities))) return 0;
	tmp2 = keys(InnateAbilities);
	tmp = ({});
	for(x = 0; x < sizeof(tmp2);x++)
	{
		if(!mapp(InnateAbilities[tmp2[x]])) continue;
		if(InnateAbilities[tmp2[x]]["type"] == "spell") 
		{
			if(InnateAbilities[tmp2[x]]["temp granted"] == 2) 
			{
				can_use_innate_ability(tmp2[x]);
				continue;
			}
			tmp += ({tmp2[x]});
			continue;
		}
		continue;
	}
	if(sizeof(tmp)) return tmp;
	return 0;			
}

int meets_innate_level_requirement(string ability)
{
	int lvl;
	mixed class_req;
	InitInnate();
	if(!mapp(InnateAbilities)) return 0;
	if(member_array(ability, keys(InnateAbilities)) == -1) return 0;
	if(!mapp(InnateAbilities[ability])) return 0;
	lvl = InnateAbilities[ability]["level required"];
	if(stringp(class_req = InnateAbilities[ability]["class specific"])) 
	{
		if(intp(lvl)) 
		{
			if(lvl) 
			{
				if((int)TO->query_class_level(class_req) < lvl) return 0;
			}
		}
	}
	else if(intp(lvl)) 
	{
		if(lvl) 
		{
			if((int)TO->query_highest_level() < lvl) return 0;
		}
	}
	return 1;
}

int can_use_innate_ability(string ability)
{
	mixed tmp;
	InitInnate();
	if(!mapp(InnateAbilities)) return 0;
	if(member_array(ability, keys(InnateAbilities)) == -1) return 0;
	if(!mapp(InnateAbilities[ability])) return 0;
	tmp = TO->query("restricted_innate_abilities");
	if(sizeof(tmp)) 
	{
		if(member_array(ability, tmp) != -1) return 0;
	}
	if(!meets_innate_level_requirement(ability)) return 0;
	if(time() >= InnateAbilities[ability]["refresh time"] 
	&& InnateAbilities[ability]["refresh time"] != -1) 
	{
		InnateAbilities[ability]["uses left"] = InnateAbilities[ability]["daily uses"];
		InnateAbilities[ability]["refresh time"] = -1;
		if(InnateAbilities[ability]["remove time"])
		{
			if(InnateAbilities[ability]["temp granted"] == 2)
			{
				map_delete(InnateAbilities, ability);
				return 0;
			}
			InnateAbilities[ability]["remove time"] = -1;
		}
		return 1;
	}
	if(InnateAbilities[ability]["uses left"] > 0 ||
	InnateAbilities[ability]["uses left"] == -1) return 1;
	return 0;
}

int query_innate_ability_uses_remaining(string ability)
{
	if(!can_use_innate_ability(ability)) return 0;
	return InnateAbilities[ability]["uses left"];
}

int query_innate_ability_total_uses(string ability)
{
	mixed tmp;
	InitInnate();
	if(!mapp(InnateAbilities)) return 0;
	if(member_array(ability, keys(InnateAbilities)) == -1) return 0;
	if(!mapp(InnateAbilities[ability])) return 0;
	tmp = TO->query("restricted_innate_abilities");
	if(sizeof(tmp)) 
	{
		if(member_array(ability, tmp) != -1) return 0;
	}
	if(!meets_innate_level_requirement(ability)) return 0;
	return InnateAbilities[ability]["daily uses"];
}

int use_innate_ability(string ability)
{
	int UsesLeft, mod, x;
	if(!can_use_innate_ability(ability)) return 0;
	UsesLeft = InnateAbilities[ability]["uses left"];
	if(UsesLeft != -1)
	{
		UsesLeft--;
		if(UsesLeft < 0) UsesLeft = 0;
	
		if(!UsesLeft) 
		{
			mod = InnateAbilities[ability]["delay"];
			x = EVENTS_D->query_midnight_time((mod-1));
			InnateAbilities[ability]["refresh time"] = x;
			if(InnateAbilities[ability]["remove time"] == -1) 
			{
				InnateAbilities[ability]["remove time"] = x;
			}
		}
		InnateAbilities[ability]["uses left"] = UsesLeft;
	}
	return 1;
}

int query_innate_ability_level(string ability)
{
	int lvl, mod;	
	string MyClass;
	if(!can_use_innate_ability(ability)) return 0;
	mod = InnateAbilities[ability]["casting level"];
	if(stringp(MyClass = InnateAbilities[ability]["class specific"])) 
	{
		lvl = (int)TO->query_class_level(MyClass) * mod;
	}
	else
	{
		lvl = (int)TO->query_highest_level() * mod;
	}
	lvl = to_int(lvl);
	if(lvl < 1) lvl = 1;
	return lvl;
}

int query_innate_useable_time(string ability)
{
	if(!query_innate_ability_total_uses(ability)) return 0;	
	return InnateAbilities[ability]["refresh time"];
}

mixed query_innate_abilities()
{
	return InnateAbilities;
}