#include <std.h>
#define EFFECTS_DIR "/d/common/mons/death_effects/"

inherit DAEMON;
mapping AllEffects;

void BuildEffectsList();

void create()
{
	::create();
	AllEffects = ([]);
	BuildEffectsList();
}

void RebuildEffectsList()
{
	AllEffects = ([]);
	BuildEffectsList();
}

void BuildEffectsList()
{
	object tmp;
	string *effectFiles, tmpType, tmpLevelRange;
	int x, oo;
	effectFiles = get_dir(EFFECTS_DIR+"*.c");
	if(!sizeof(effectFiles)) return;
	for(x = 0;x < sizeof(effectFiles);x++)
	{
		tmp = new(EFFECTS_DIR+effectFiles[x]);
		if(!objectp(tmp)) continue;
		tmpType = tmp->query_effect_type();
		tmpLevelRange = tmp->query_level_range();
		oo = tmp->query_environment_required();
		if(!stringp(tmpLevelRange)) tmpLevelRange = "NIL";
		if(tmpType == "base") 
		{
			tmp->remove();
			continue;
		}
		if(!AllEffects[tmpType]) 
		{
			AllEffects[tmpType] = ({ (["file" : EFFECTS_DIR+effectFiles[x], 
			"lvl range" : tmpLevelRange, "environment required" : oo ]) });
		}
		else 
		{
			AllEffects[tmpType] += ({ (["file" : EFFECTS_DIR+effectFiles[x],
			"lvl range" : tmpLevelRange, "environment required" : oo ]) }); 
		}
		tmp->remove();
		continue;
	}
	return;
}

mixed ValidEffectTypes()
{
	if(!mapp(AllEffects)) return 0;
	if(!sizeof(AllEffects)) return 0;
	return keys(AllEffects);
}

mixed query_all_effect_types()
{
	return AllEffects;
}

//where is the room where the death effect will be
//spawned, MyTarg should be the name or short 
//description of the object spawning the effect 
//MyLevel will be the level of the effect - this 
//way we can have effects that scale to 
//a certain level range - effects are going to be
//actual objects that cause damage or some other
//effect so that the daemon will simply
//clone one of these objects, move it to 
//"where", set up its level, and start 
//it
//Type is the category of death effect that it will pick from 

void get_death_effect(object Mob)
{
	object where, spawnEffect;
	string MyTarg, effectKeys;
	int MyLevel, effectNum, flag, ranEffect, envT;
	string *MyTypes, Type, *effectLvlRange;

	if(!objectp(Mob)) return;
	
	where = environment(Mob);
	if(!objectp(where)) return;
	
	MyTarg = Mob->query_name();
	if(!stringp(MyTarg)) return;
	
	MyLevel = Mob->query_level();

	envT = where->query_property("indoors");
	if(!intp(MyLevel)) return;

	if(!Mob->query_property("death effects")) return;

	if(stringp(Mob->query_property("death effects")))
	{
		MyTypes = ({Mob->query_property("death effects")});
	}

	if(pointerp(Mob->query_property("death effects")))
	{
		MyTypes = Mob->query_property("death effects");
	}

	if(!sizeof(MyTypes)) return;		
	Type = MyTypes[random(sizeof(MyTypes))];

	//is the death effect specifying a particular file?  
	//if yes, then load that file - or load 
	//a randomly picked file from that list - Saide

	if(file_exists(Type + ".c") || file_exists(Type)) 
	{
			spawnEffect = new(Type);
			if(!objectp(spawnEffect)) return;
			spawnEffect->adjust_level(MyLevel);
			spawnEffect->set_effectOrigin(Mob);
			//spawnEffect->move(where);
			spawnEffect->startEffect(where);	
			return;		
	}

	if(!stringp(Type)) Type = "any";
	if(!mapp(AllEffects)) return;
	if(!sizeof(AllEffects)) 
	{
		log_file("death_effects", MyTarg + " ( "+
		base_name(Mob) + " ) failed to load a death "+
		"effect of Type "+Type+" -  There are no valid Effects loaded "+
		"in the daemon.\n  ");
		return;
	}
	if(!AllEffects[Type]) 
	{
		Type = "any";
	}
	if(Type == "any") ranEffect = 1;
	effectKeys = keys(AllEffects);
	while(!objectp(spawnEffect) && flag < 3)
	{
		if(ranEffect) 
		{
			Type = effectKeys[random(sizeof(effectKeys))];			
		}
		effectNum = random(sizeof(AllEffects[Type]));

		if(envT != AllEffects[Type][effectNum]["environment required"] &&
		AllEffects[Type][effectNum]["environment required"] != -1) 
		{
			flag++;
			continue;
		}

		if(AllEffects[Type][effectNum]["lvl range"] != "NIL")
		{
			effectLvlRange = explode(AllEffects[Type][effectNum]["lvl range"], ", ");
			if(!sizeof(effectLvlRange)) 
			{
				flag++;
				continue;
			}
			if(MyLevel < to_int(effectLvlRange[0]) ||
			MyLevel > to_int(effectLvlRange[1]))
			{
				flag++;
				continue;
			}
		}
		if(!file_exists(AllEffects[Type][effectNum]["file"])) 
		{
			flag++;
			continue;
		}
		if(!objectp(spawnEffect = new(AllEffects[Type][effectNum]["file"])))
		{
			flag++;
			continue;
		}
		if(objectp(spawnEffect)) break;
	}
	if(!objectp(spawnEffect)) 
	{
		log_file("death_effects", MyTarg + " ( "+
		base_name(Mob) + " ) failed to load a death "+
		"effect of Type "+Type+"  spawnEffect was not an Object. \n");
		return;
	}
	spawnEffect->adjust_level(MyLevel);
	spawnEffect->set_effectOrigin(Mob);
	//spawnEffect->move(where);
	spawnEffect->startEffect(where);
	return;
}
