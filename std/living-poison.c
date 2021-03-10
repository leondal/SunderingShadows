//Poison as they should be - Saide
#include <std.h>
#include <daemons.h>

mapping PoisonEffects;

//Applies the poison effect to the targ
void ApplyPoison(object targ, object poison, object poisoner);

//Should process the primary and secondary
//poison effects
void ProcessPoisons();
void RemovePoisonByKey(int PoisonKey);
void ClearAllPoisons();

void ApplyPoison(object targ, mixed poison, object poisoner)
{
	int Duration, Count, AllowsSave, WhichSave, IsPlayer, DC, *y, flag;
	string PoisonApplier, PoisonName, ApplyType;	
	mixed WhoDoneIt;
	object PoisonerOb; //Object responsible for applying the poison
				 //can be an actual poison "object" or filename 
				 //if it is a filename will attempt to load the file
				 //and get the relevant info from that file
	if(!objectp(targ)) return;

	if(!objectp(poisoner)) return;
	
	if(poisoner->is_player()) 
	{
		PoisonApplier = poisoner->query_name();
		IsPlayer = 1;
	}
	else 
	{
		PoisonApplier = base_name(poisoner);
		IsPlayer = 0;
	}

	if(living(poisoner)) 
	{
		ApplyType = "injury";
	}
	else if(poisoner->is_food() || poisoner->is_drink()) 
	{
		ApplyType = "ingested";
	}
	else ApplyType = "contact";

	if(!mapp(PoisonEffects))
	{
		PoisonEffects = ([]);
	}

	if(!objectp(poison)) 
	{
		PoisonerOb = find_object_or_load(poison);
	}
	else PoisonerOb = poison;
	
	//If it is still not a valid Object at this point then let us try to 
	//retrieve one from the Poison Daemon
	if(!objectp(PoisonerOb)) 
	{
		PoisonerOb = POISON_D->QueryPoisonObject(poison, ApplyType);
		if(!objectp(PoisonerOb)) return;
	}
	//How long this poison stays on a person
	//Have it count down to zero
	Duration = PoisonerOb->query_duration();

	//Length between primary and secondary 
	//poison effects or subsequent effects 
	Count = PoisonerOb->query_delay(1);	
	
	//Does this allow a saving throw? 
	AllowsSave = (int)PoisonerOb->query_save_allowed(1);
	
	WhichSave = (string)PoisonerOb->query_saving_throw(1);
	
	PoisonName = (string)PoisonerOb->query_poison_name();

	if(!IsPlayer && living(poisoner)) 
	{
		DC = 10 + ((int)poisoner->query_level()/2);
	}
	else
	{
		DC = (int)PoisonerOb->query_poison_dc(1);
		//DC+= //any player mods - Saide
	}
	flag = 0;
	if(!flag) 
	{
		WhoDoneIt = poisoner->QCN;
		if(!WhoDoneIt || !stringp(WhoDoneIt)) WhoDoneIt = "something";
		tell_object(targ, "%^BOLD%^%^GREEN%^You have been "+
		"poisoned by "+WhoDoneIt+"!%^RESET%^");	
	}
	if(flag) 
	{
		tell_object(targ, poisoner->QCN+"%^BOLD%^%^GREEN%^ "+
		"has poisoned you with "+PoisonName+" poison!%^RESET%^");
	}

	//basically what I am thinking is keeping track of poison by 
	//it's name - if you get poisoned twice by the same poison it 
	//resets the duration and the effect state, but keeps the 
	//actual poison effects and just adds to them
	if(!PoisonEffects[PoisonName]) 
	{
		PoisonEffects[PoisonName] = (["PoisonApplier" : PoisonApplier, 
		"ObjectThatPoisons" : base_name(PoisonerOb), "Duration" : Duration,
		"Count" : Count, "AllowsSave" : AllowsSave, "WhichSave" : WhichSave, 
		"Effects" : ([]), "DC" : DC, "WhichEffect" : 1, "PoisonName" : PoisonName, 
		"SaveFails" : 0 ]);	
	}
	else
	{
		PoisonEffects[PoisonName]["PoisonApplier"] = PoisonApplier;
		PoisonEffects[PoisonName]["ObjectThatPoisons"] = base_name(PoisonerOb);
		PoisonEffects[PoisonName]["Duration"] = Duration,
		PoisonEffects[PoisonName]["Count"] = Count;
		PoisonEffects[PoisonName]["WhichEffect"] = 1;
		PoisonEffects[PoisonName]["SaveFails"] = 0;
		PoisonEffects[PoisonName]["DC"] = DC;
	}
	PoisonerOb->remove();
	//destruct(PoisonerOb);
}

void RemovePoisonByKey(int PoisonKey)
{
	if(!mapp(PoisonEffects)) 
	{
		PoisonEffects = ([]);
	}
	map_delete(PoisonEffects, PoisonKey);
}

void ProcessPoisons()
{
	int x, WhichEffect, Count, Duration, EffectAmt, flag = 0, DC, sf;
	int CurPoison;
	object PoisonerOb;
	string PoisonFile, EffectType, PoisonName, *pnames;
	if(!mapp(PoisonEffects))
	{
		PoisonEffects = ([]);
	}
	if(!sizeof(keys(PoisonEffects))) 
	{
		return;
	}	
	pnames = keys(PoisonEffects);
	for(x = 0;x < sizeof(pnames);x++)
	{
		CurPoison = pnames[x];
		flag = 0;
		if(undefinedp(PoisonEffects[CurPoison])) continue;

		PoisonFile = PoisonEffects[CurPoison]["ObjectThatPoisons"];
		
		if(!objectp(PoisonerOb = POISON_D->QueryPoisonObject(PoisonFile))) 
		{
			RemovePoisonByKey(CurPoison);
			continue;
		}				
		
		Count = PoisonEffects[CurPoison]["Count"];
		Duration = PoisonEffects[CurPoison]["Duration"];

		WhichEffect = PoisonEffects[CurPoison]["WhichEffect"];
	
		Duration--;

		if(Count > 0)
		{
			Count--;
			PoisonEffects[CurPoison]["Count"] = Count;
			PoisonEffects[CurPoison]["Duration"] = Duration;
			PoisonerOb->remove();			
			//destruct(PoisonerOb);
			continue;
		}
		Count = (int)PoisonerOb->query_delay(WhichEffect+1);

		PoisonEffects[CurPoison]["Count"] = Count;
	
		if(Duration <= 0) 
		{
			if(!PoisonerOb->end_effect(TO)) 
			{
				PoisonName = PoisonEffects[x+1]["Poison Name"];
				tell_object(TO, "%^BOLD%^%^GREEN%^You "+
				"feel the effects of the "+PoisonName+" wear"+
				"off!%^RESET%^");
			}				
			RemovePoisonByKey(CurPoison);
			PoisonerOb->remove();
			//destruct(PoisonerOb);
			continue;
		}

		sf += PoisonEffects[CurPoison]["SaveFails"];

		if((WhichEffect > (int)PoisonerOb->query_number_of_effects() &&
		(int)PoisonerOb->query_number_of_effects() != -1)) 
		{
			PoisonerOb->remove();
			if(!sf)
			{
				RemovePoisonByKey(CurPoison);
			}
			//destruct(PoisonerOb);
			continue;
		}

		EffectType = (string)PoisonerOb->query_effect_type(WhichEffect);
		//EffectAmt = (int)PoisonerOb->query_effect_amount(WhichEffect);

		DC = (int)PoisonerOb->query_poison_dc(WhichEffect);
		if(DC < PoisonEffects[CurPoison]["DC"])
		{
			DC = PoisonEffects[CurPoison]["DC"];
		}

		EffectAmt = (int)PoisonerOb->ProcessEffect(TO, WhichEffect, DC);
		if(EffectAmt) sf++;

		if(PoisonEffects[CurPoison]["Effects"][EffectType]) 
		{	
			PoisonEffects[CurPoison]["Effects"][EffectType] += EffectAmt;
		}
		else
		{
			PoisonEffects[CurPoison]["Effects"][EffectType] = EffectAmt;
		}

		WhichEffect++;
		PoisonEffects[CurPoison]["WhichEffect"] = WhichEffect;
		PoisonEffects[CurPoison]["SaveFails"] = sf;
		PoisonerOb->remove();
		//destruct(PoisonerOb);
		continue;	
	}
}

void ClearAllPoisons() 
{
	PoisonEffects = ([]);
}

int is_poisoned()
{
	if(!mapp(PoisonEffects)) return 0;
	return sizeof(keys(PoisonEffects));
}

int query_poison_effect(string EffectType)
{
	int x, mod = 0;
	string *pnames;
	if(!mapp(PoisonEffects)) 
	{
		PoisonEffects = ([]);
		return 0;
	}
	if(!sizeof(keys(PoisonEffects))) return 0;

	EffectType = POISON_D->query_poison_effect_type(EffectType);

	pnames = keys(PoisonEffects);
	for(x; x < sizeof(pnames);x++)
	{
		if(PoisonEffects[pnames[x]]["Effects"][EffectType])
		{
			mod += PoisonEffects[pnames[x]]["Effects"][EffectType];
			continue;
		}
	}
	return (mod*-1);
} 

void QueryPoisons()
{
	return PoisonEffects;
}