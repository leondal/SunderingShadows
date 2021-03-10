#include <std.h>
#include <daemons.h>
#define NOPICK ({"WildernessLore", "ArcaneSpellcraft", "DivineSpellcraft", "spellmastery", "eschew materials", "enchant", "scribe", "NonCombat", "Performance"})
inherit DAEMON;

//called in monster.c heartbeat once - Saide

void setup_monster_feats(object mob)
{
	mapping featsmap = ([]);
	string *myClasses, myClass, *myFeats = ({}), *tmp, myFile;
	string *BonusFeats, *myPicks = ({}), myCat, myPicked, myFavored;
	int myLev, x, y, myBonus;

	object *myGear, gear;
	if(!objectp(mob)) return;
	if(mob->query_property("spell_creature")) return;
	if(mob->id("summoned monster")) return;
	//if(sizeof(mob->query_monster_feats())) return;
	myLev = (int)mob->query_level();
	//let us keep monsters level 15 and under from having
	//feats, unless manually set, for now - Saide
	if(myLev < 15) return;
	myClasses = mob->query_classes();
	if(!sizeof(myClasses)) return;
	for(x = 0;x < sizeof(myClasses);x++)
	{
		if(file_exists("/std/class/"+myClasses[x]+".c"))
		{
			myFile = "/std/class/"+myClasses[x]+".c";
			featsmap = myFile->class_featmap();
			if(myFile->caster_class()) 
			{
				if(!random(2)) myPicks += ({"MagicAccuracy"});
				if(!random(2)) myPicks += ({"MagicDamage"});
				if(!random(2)) myPicks += ({"MagicProtection"});
			}
			else
			{
				if(!random(2)) myPicks += ({"MeleeAccuracy"});
				if(!random(2)) myPicks += ({"MeleeDamage"});
				if(!random(2)) myPicks += ({"Evasion"});
			}
			if(!mapp(featsmap)) continue;
			if(!sizeof(keys(featsmap))) continue;
			tmp = keys(featsmap);	
			myLev = mob->query_class_level(myClasses[x]);
			for(y = 0;y < sizeof(tmp); y++)
			{
				if(tmp[y] > myLev) continue;
				myFeats += featsmap[tmp[y]];
				continue;
			}
		}
		continue;
	}
	//pick some random feats based on equipment - Saide
	myLev = (int)mob->query_level();
	myBonus = (myLev/5)+1;
	myGear = mob->query_wielded();
	if(sizeof(myGear)) 
	{
		gear = myGear[0];
		if((int)gear->is_lrweapon()) 
		{
			myPicks += ({"Archery"});
			myFavored = "Archery";
		}
		else if((int)gear->is_weapon()) 
		{
			if((int)gear->query_size() > (int)mob->query_size()) 
			{
				myPicks += ({"TwoHandedWeapons"});
				myFavored = "TwoHandedWeapons";
			}
			else 
			{
				if(mob->is_wearing_type("shield")) 
				{
					myPicks += ({"WeaponAndShield"});
					myFavored = "WeaponAndShield";
				}
				else
				{
					if(sizeof(myGear) > 1) 
					{
						myPicks += ({"TwoWeapons"});
						myFavored = "TwoWeapons";
					}
				}
			}
		}
	}
	else
	{
		if(mob->is_wearing_type("shield")) 
		{
			myPicks += ({"WeaponAndShield"});
			myFavored = "WeaponAndShield";
		}
	}
	if(!random(2)) myPicks += ({"GeneralCombat"});
	if(!random(2)) myPicks += ({"MagicResistance"});
	if(!random(2)) myPicks += ({"DamageResistance"});

	featsmap += FEATS_D->get_all_feats();
	tmp = ({});
	while(myBonus--)
	{
		if(!sizeof(myPicks)) break;
		if(random(3) && stringp(myFavored)) myCat = myFavored;
		else myCat = myPicks[random(sizeof(myPicks))];	
		if(!featsmap[myCat]) continue;
		featsmap[myCat] -= NOPICK;	
		featsmap[myCat] -= myFeats;
		
		if(!sizeof(featsmap[myCat])) 
		{
			myPicks -= ({myCat});
			myBonus++;
			continue;
		}
		myPicked = featsmap[myCat][random(sizeof(featsmap[myCat]))];
		featsmap[myCat] -= ({myPicked});
		//tell_object(find_player("saide"), "myPicked = "+myPicked+", myCat = "+myCat);
		tmp += ({myPicked});
		continue;				
	}
	myFeats += tmp;
	myFeats -= NOPICK;
	if(sizeof(myFeats)) mob->set_monster_feats(myFeats);
	return;
}

//called from monster.c in set_monster_feats() 
//my intention is to build a list of feats from a monsters feats 
//that are instant/combat feats, so that when execute_monster_feat() is 
//called it only looks through those feats and chooses a relevant one to execute - Saide

void init_combat_feats(object mob)
{
	string *myFeats, *CombatFeats = ({});
	int x;
	object featOb;
	if(!objectp(mob)) return;
	
	myFeats = mob->query_monster_feats();
	if(!sizeof(myFeats)) return;

	for(x = 0;x < sizeof(myFeats);x++)
	{
		if(!stringp(myFeats[x])) continue;
		if(member_array(myFeats[x], CombatFeats) != -1) continue;
		if(objectp(featOb = new("/cmds/feats/"+myFeats[x][0..0]+"/_"+replace_string(myFeats[x], " ", "_")))) 
		{
			if((int)featOb->query_feat_type() == "instant")
			{				
				CombatFeats += ({myFeats[x]});
			}
			featOb->dest_effect();
		}
		continue;
	}
	if(sizeof(CombatFeats))	
	{
		mob->delete("CombatFeats");
		mob->set("combat_feats_enabled", 1);
		mob->set("CombatFeats", CombatFeats);
	}
	return;
}

//called from combat.c a 25% chance to be called on hits, 
//unless the monster is already using an instant feat - 
//set_property("feat chance", %percentage) allows an override
//of the default 25% chance - Saide

void execute_monster_feat(object mob, object targ)
{
	string myFeat, *CombatFeats;
	int x;
	if(!objectp(mob)) return;
	if(!objectp(targ)) return;
	if(!mob->query("combat_feats_enabled")) return;
	if(!pointerp(CombatFeats = mob->query("CombatFeats"))) return;
	myFeat = CombatFeats[random(sizeof(CombatFeats))];
	if(!stringp(myFeat)) return;
	switch(myFeat)
	{
		case "powerattack":	
			x = 5;
			if(!mob->query("powerattack_offensive")) 
			{
				while(x--)
				{	
					mob->force_me("powerattack offensive");
				}
				mob->set("powerattack_offensive", 1);
			}
			else
			{
				while(x--)
				{	
					mob->force_me("powerattack defensive");
				}
				mob->delete("powerattack_offensive");
			}
			break;
		case "shieldwall":
			if(!random(2)) mob->force_me("shieldwall offensive");
			else mob->force_me("shieldwall defensive");
			break;
		case "expertise":
			x = 5;
			if(!mob->query("expertise_defensive"))
			{
				while(x--)
				{
					mob->force_me("expertise defensive");
				}
				mob->set("expertise_defensive", 1);
			}
			else
			{
				while(x--)
				{
					mob->force_me("expertise offensive");
				}
				mob->delete("expertise_defensive");
			}
			break;
		default:
			mob->force_me(myFeat + " " + targ->query_name());
			break;
	}
	return;
}