// trap.c
//originally coded by Tristan - recoded by Saide to support 
//new trap lib code
//basic concept - detect/find roll against the dc of the trap
//if you fail at this - you aren't able to even know there is a trap
//so you cannot by default, try to recover or remove it 
//remove is dc + 5
//recover is dc + 10
//failure in either case = trap triggered 
//Updated by ~Circe~ 3/20/13 to work with Detect Snares and 
//Pits/Detect Traps. These spells grant the property "detecting_snares".

#include <std.h>
#include <daemons.h>
#include <move.h>

#define FFAILURE "%^BOLD%^You don't seem to find any traps on the "+obj+"."
#define RFFAILURE "%^BOLD%^"+TPQCN+" doesn't seem to find any traps on the "+obj+"."

#define VDOORACTS ({"open", "close"})
#define VLOCKACTS ({"pick", "unlock"})

inherit DAEMON;

int help();
int find_action(string input);
int remove_recover_action(string input, string Atype);
int detect_action(string input);
int reveal_action(string str);
int set_action(string str);

int cmd_trap(string str)
{
    	string action, junk;

    	if(!str)
	{
      	return help();
    	}

    	if( sscanf(str, "%s %s", action, junk) != 2) 
	{
      	return help();
    	}

    	switch(action) 
	{
		case "detect":
			return detect_action(junk);
			break;
    		case "find":
        		return find_action(junk);
        		break;
		case "remove": case "disarm":
        		return remove_recover_action(junk, "remove");
        		break;
		case "recover":
			return remove_recover_action(junk, "recover");
			break;
		case "reveal":
			return reveal_action(junk);
			break;
		case "set":
			return set_action(junk);
			break;
		default:
        	return help();
    	}
}

int reveal_action(string input)
{
	int TargSkill, x, *DCS = ({}), i, flag, failSkill;
	string targ, targ_type, *MyTraps = ({}), who, *VTRIGS = ({}), *TK;
	string MyParty, *rexits, *TrapKeys, tmp, my_msg, TN, TCN;
	object *MyTargs = ({}), theObj, MyTarg;
	mapping TrapInfo, Dmap;	
	if(!objectp(TP)) return 0;
	if(!stringp(input)) 
	{
		return help();
	}
	
	if(sscanf(input, "on %s to %s", targ, who) != 2)
	{
		tell_object(TP, "trap reveal on <object> to <who>\n"
				    "trap reveal on <object> to party\n");
		return 1;
	}
	if(who == "party")
	{
		if(!stringp(MyParty = TP->query_party()))
		{
			tell_object(TP, "You are not in any party.");
			return 1;
		}
		MyTargs = PARTY_D->query_party_members(MyParty);
		if(!sizeof(MyTargs)) 
		{
			tell_object(TP, "There are no members in your party.");
			return 1;
		}
		MyTargs = distinct_array(MyTargs);
		MyTargs -= ({TP});
		if(!sizeof(MyTargs)) 
		{
			tell_object(TP, "You are the only member of your party.");
			return 1;
		}
	}

	if(who != "party")
	{
		if(!objectp(MyTarg = present(who, ETP)))
		{
			tell_object(TP, "There is no "+who+" person here.");
			return 1;
		}

		if(!living(MyTarg)) 
		{
			tell_object(TP, capitalize(who)+" is not a living "+
			"creature and would have no way of understanding what you "+
			"mean.");
			return 1;
		}
		if(MyTarg == TP) 
		{
			tell_object(TP, "You already know how to avoid traps "+
			"you have set!");
			return 1;
		}
		MyTargs += ({MyTarg});
	}

	if(!objectp(theObj = present(targ, TP))) 
	{
		if(!objectp(theObj = present(targ, ETP)))
		{
			theObj = ETP;
		}
	}

	if(theObj != ETP)
	{
		if(!living(theObj)) targ_type = "object";
	}

	if(theObj == ETP)
	{
		if(theObj->is_vault()) 
		{
			Dmap = ETP->query_doors_map();
			if(member_array(targ, keys(Dmap)) != -1) 
			{
				targ_type = "door";
			}
		}
		if(!targ_type)
		{
			rexits = ETP->query_exits();
			if(member_array(targ, rexits) != -1) targ_type = "exit";
		}
	}	

	if(!targ_type)
	{
		tell_object(TP, "That is not a valid target that you could have "+
		"set traps on.");
		return 1;
	}
	TrapInfo = theObj->query_trap_data();
	TrapKeys = keys(TrapInfo);
	if(!sizeof(TrapInfo) || !mapp(TrapInfo)) 
	{
		tell_object(TP, "You cannot find any traps that you have "+
		"set on that object to reveal.");
		return 1;
	}

	switch(targ_type)
	{
		case "object":
			for(x = 0;x < sizeof(TrapKeys);x++)
			{
				if(!TrapInfo[TrapKeys[x]]) continue;
				if(TrapInfo[TrapKeys[x]]["set by"] != TPQN) continue;
				MyTraps += ({TrapKeys[x]});
				VTRIGS += ({TrapKeys[x] +" the " + targ});
				DCS += ({TrapInfo[TrapKeys[x]]["dc"]});
				continue;
			}		
			break;
		case "exit":
			if(TrapInfo[targ])
			{
				if(TrapInfo[targ]["set by"] == TPQN) 
				{
					MyTraps += ({targ});
					VTRIGS += ({"use the "+targ+" exit"});
					DCS += ({TrapInfo[targ]["dc"]});
				}
			}
			break;
		case "door":
			for(x = 0;x < sizeof(TrapKeys);x++)
			{
				if(TrapInfo[TrapKeys[x]]["set by"] != TPQN) continue;
				if(strsrch(TrapKeys[x], targ) == -1) continue;
				MyTraps += ({TrapKeys[x]});
				TK = explode(TrapKeys[x], " ");
				TK -= explode(targ, " ");
				VTRIGS += ({TK[0] + " the "+implode(TK[1..(sizeof(TK)-1)], " ") + 
				" on "+targ});
				DCS += ({TrapInfo[TrapKeys[x]]["dc"]});
				continue;
			}
			break;
		default:
			break;
	}

	if(!sizeof(MyTraps)) 
	{
		tell_object(TP, "You havent set any traps on "+targ+" that you can "+
		"reveal information about.");
		return 1;
	}

	if(targ_type == "exit") targ = targ + " exit";
	if(who == "party")
	{
		my_msg = "%^BOLD%^%^WHITE%^You try to reveal the triggers of your "+
		"traps on the "+targ+" and how to avoid them to your party members.%^RESET%^";
	}
	else 
	{
		my_msg = "%^BOLD%^%^WHITE%^You try to reveal the triggers of your "+
		"traps on the "+targ+" and how to avoid them to "+MyTarg->QCN+".%^RESET%^";
	}

	tell_object(TP, my_msg);

	for(x = 0;x < sizeof(MyTargs);x++)
	{
		if(!objectp(MyTargs[x])) continue;
		if(!present(MyTargs[x], ETP)) continue;
		tell_object(MyTargs[x], TPQCN + " seems to be trying to "+
		"reveal something of importance to you about the "+
		targ+".");
		TargSkill = MyTargs[x]->query_skill("dungeoneering");
		if(sizeof(MyTargs[x]->query_armour("torso"))) 
		{
			TargSkill += MyTargs[x]->skill_armor_mod(MyTargs[x]->query_armour("torso"));
		}
		flag = 0;
		TN = MyTargs[x]->query_name();
		TCN = MyTargs[x]->QCN;
		for(i = 0;i < sizeof(MyTraps);i++)
		{
			if(i > sizeof(VTRIGS) || i > sizeof(DCS)) continue;
			tell_object(MyTargs[x], TPQCN + " reveals to you a "+
			"trap on the "+targ+".");
			if((failSkill = (int)theObj->query_failed_know(MyTraps[i], TN))) 
			{
				if(TargSkill <= failSkill) continue;
			}
			if(TargSkill + roll_dice(1, 20) >= (DCS[i]/2)) 
			{			
				tell_object(MyTargs[x], TPQCN+"%^BOLD%^%^WHITE%^ shows "+
				"you that the trap will be triggered when you %^BOLD%^"+
				"%^RED%^"+VTRIGS[i]+"%^BOLD%^%^WHITE%^ and shows you "+
				"exactly how to avoid it.%^RESET%^");
				flag++;
				theObj->add_known_to(MyTraps[i], "player", TN);
				theObj->remove_failed_know(MyTraps[i], TN);
				continue;
			}
			theObj->add_failed_know(MyTraps[i], TN, TargSkill);
			tell_object(MyTargs[x], "%^BLUE%^...but you cant "+
			"quite understand what "+
			TPQS + " means about triggering or avoiding it.%^RESET%^");
			continue;
		}
		if(flag >= sizeof(MyTraps))
		{
			tell_object(TP, TCN+ "%^BOLD%^%^CYAN%^ seems to "+
			"have full knowledge of your traps on "+targ+" now.%^RESET%^");
			continue;
		}
		if(flag > 0)
		{
			tell_object(TP, TCN +"%^BOLD%^%^GREEN%^ seems to "+
			"have some knowledge of your traps on "+targ+" now.%^RESET%^");
			continue;
		}
		else 
		{
			tell_object(TP, TCN+"%^BOLD%^%^RED%^ doesn't seem "+
			"to have understood you at all about your traps on "+targ+".");
			continue;
		}
		continue;
	}
	return 1;		
}


int set_action(string input)
{
	string targ, trigger, trapkit, targ_type, *door_locks, *rexits, tmp;
	string *VTRIG = ({}), tstr, ThisTrap, *ttriggers, trap_type, trap_lvl;
	object MyTrapKit, MyTarg;
	int MySkill, x;
	mapping Dmap, TrapInfo;
	
	if(!objectp(TP)) return 0;
	if(!stringp(input))
	{
		return help();
	}

	if(sscanf(input, "%s on %s with %s", trapkit, targ, trigger) != 3)
	{
		if(sscanf(input, "%s on %s", trapkit, targ) != 2)
		{
			tell_object(TP, "trap set <trap kit> on <object>\n"+
			"trap set KIT on OBJECT with ACTION\n"+
			"trap set KIT on OBJECT with triggers");
			return 1;
		}
	}

	if(!objectp(MyTrapKit = present(trapkit, TP)))
	{
		tell_object(TP, "You have no "+trapkit+".");
		return 1;
	}

	if(!MyTrapKit->id("playersettabletrapkit"))
	{
		tell_object(TP, trapkit + " is not a valid trap kit.");
		return 1;
	}

	if(!objectp(MyTarg = present(targ, TP)))
	{
		if(!objectp(MyTarg = present(targ, ETP)))
		{
			MyTarg = ETP;
		}
	}

	if(MyTarg != ETP) 
	{
		if(!living(MyTarg)) targ_type = "object";
	}
	else
	{
		if(ETP->is_vault())
		{
			Dmap = ETP->query_doors_map();
			if(member_array(targ, keys(Dmap)) != -1) 
			{
				targ_type = "door";
				door_locks = ETP->getLocks(targ);
			}
		}
		if(!targ_type)
		{
			rexits = ETP->query_exits();
			if(member_array(targ, rexits) != -1) targ_type = "exit";
		}
	}

	if(!targ_type)
	{
		tell_object(TP, targ+ " is not a valid target to set a trap on.");
		return 1;
	}
	MySkill = TP->query_skill("dungeoneering");
	if(sizeof(TP->query_armour("torso"))) 
	{
		MySkill += TP->skill_armor_mod(TP->query_armour("torso"));
	}
	if(MySkill < 15) 
	{
		tell_object(TP, "You must have at least 15 points "+
		"in dungeoneering before you are able to "+
		"set your own traps.");
		return 1;
	}
	
	switch(targ_type) 
	{
		case "exit":
			VTRIG += ({targ});
			break;
		case "object":
			if(MyTarg->is_container() && MyTarg->query_possible_to_close()) 
			{
				VTRIG += ({"open", "close"});
				if(MyTarg->query_lock_data() && MyTarg->query_lock_data("key"))
				{
					VTRIG += ({"pick", "unlock"});
				}
			}
			break;
		case "door":
			VTRIG += ({"open", "close"});
			for(x = 0;x < sizeof(door_locks);x++)
			{
				VTRIG += ({"unlock "+door_locks[x]});
				if(Dmap[targ][door_locks[x]]["key"] != 0)
					VTRIG += ({"pick "+door_locks[x]});
				continue;
			}
	}			
	if(trigger == "triggers" || trigger == "trigger")
	{
		if(!sizeof(VTRIG)) 
		{
			tell_object(TP, "You find no viable method to rig a trap on "+
						targ+".");
			return 1;
		}
		tmp = "%^BOLD%^%^WHITE%^Valid syntaxes to rig a trap on the "+targ;
		tstr = "trap set <"+trapkit+"> on <"+targ+">";
		if(targ_type == "exit")
		{
			tmp += " exit :\n";
			tmp += tstr;
		}
		else
		{
			tmp += ":\n";
			for(x = 0; x < sizeof(VTRIG);x++)
			{
				tmp += tstr + " | " + VTRIG[x] +"\n";
			}
		}
		tell_object(TP, tmp);
		return 1;
	}
	if(!trigger && targ_type != "exit")
	{
		tell_object(TP, "You must specify which trigger for "+targ+
		" you want to activate your trap.");
		return 1;
	}
	if(targ_type == "exit") trigger = targ;
	if(member_array(trigger, VTRIG) == -1)
	{
		tell_object(TP, trigger + " is not a valid trap trigger action "+
		"for the "+targ+".");
		return 1;
	}
	if(targ_type == "exit" || targ_type == "object") ThisTrap = trigger;
	else
	{
		ttriggers = explode(trigger, " ");
		if(sizeof(ttriggers) == 1)
		{
			ThisTrap = trigger + " "+targ;
		}
		else
		{
			ThisTrap = ttriggers[0] + " " + targ + " "+
			implode(ttriggers[1..sizeof(ttriggers)], " ");
		}
	}
	TrapInfo = MyTarg->query_trap_data();
	//should they try to trap something that is already trapped - then 
	//make both traps go off - a way to get around the whole 
	//using set to determine if something is trapped or not - Saide
	if(undefinedp(TrapInfo)) 
	{
		tell_object(TP, "You are unable to set a trap on the "+
		targ+".");
		return 1;
	}
	TP->set_paralyzed(10, "%^BOLD%^%^RED%^You are busy setting a trap.%^RESET%^");
	if(targ_type == "exit") targ = targ + " exit";
	if(TrapInfo[ThisTrap]) 
	{
		tell_object(TP, "%^BOLD%^%^BLACK%^You go about setting the trap "+
		"on the "+targ+" and are overcome with a sudden sense of dread as "+
		"something goes horribly awry!%^RESET%^");
		tell_room(ETP, TPQCN + "%^BOLD%^%^BLACK%^ does something to "+
		targ+" and then suddenly looks shocked as something goes horribly "+
		"wrong!%^RESET%^", TP);
		MyTarg->execute_trap(ThisTrap, TP, 1);
		MyTrapKit->trap_activated(TP);
		MyTrapKit->remove();
		return 1;
	}
	tell_object(TP, "%^BOLD%^%^WHITE%^You go about setting the trap "+
	"on the "+targ+".%^RESET%^");
	if(!TP->query_invis()) 
	{
		tell_room(ETP, TPQCN+"%^BOLD%^%^WHITE%^ seems to be doing something to "+
		"the "+targ+".%^RESET%^", TP);
	}

	if((MySkill + roll_dice(1, 20)) >= ((int)MyTrapKit->query_dc() + 10))
	{
		tell_object(TP, "%^BOLD%^%^WHITE%^You successfully set "+
		MyTrapKit->query_short() + " on the "+targ+".");
		trap_type = MyTrapKit->query_my_trap_name();
		trap_lvl = MyTrapKit->query_trap_level();
		MyTarg->set_trapped(({ThisTrap}), ({trap_lvl}), ({trap_type}), 1);
		MyTarg->add_passed_check(ThisTrap, TPQN);
		MyTarg->set_trap_set_by(ThisTrap, TPQN, MyTrapKit->query_dc());
		MyTarg->add_known_to(ThisTrap, "player", TPQN);
		MyTrapKit->remove();
		return 1;
	}
	if(!TP->query_true_invis())
	{
		tell_room(ETP, TPQCN +"%^BOLD%^%^RED%^ cries out in shock as "+
		"something goes awry!%^RESET%^", TP);
	}
	tell_object(TP, "%^BOLD%^%^RED%^You fail in your attempt and "+
	MyTrapKit->query_short()+ " backfires on you!%^RESET%^");
	MyTrapKit->trap_activated(TP);
	MyTrapKit->remove();
	return 1;
		
}

int detect_action(string input)
{
	int MySkill;
	if(!stringp(input)) 
	{
		return help();
	}
	input = lower_case(input);
	if(input != "on" && input != "off") 
	{
		return help();
	}
	MySkill = TP->query_skill("dungeoneering");
//Below bonus info added by ~Circe~ 3/20/13 to accomodate trap detection spells.
      if(TP->query_property("detecting_snares")){
         if(objectp(TP->query_property("detecting_snares"))){
            MySkill += (int)TP->query_property("detecting_snares")->query_bonus();
         }
      }
	if(sizeof(TP->query_armour("torso"))) 
	{
		MySkill += TP->skill_armor_mod(TP->query_armour("torso"));
	}
	if(MySkill < 15) 
	{
		tell_object(TP, "You must have at least 15 points "+
		"in dungeoneering before you are able to "+
		"auto detect traps.");
		return 1;
	}

	if(input == "on")
	{
		if(TP->query("is_auto_detecting_traps")) 
		{
			tell_object(TP, "You are already auto detecting traps.");
			return 1;
		}
		TP->set("is_auto_detecting_traps", 1);
		tell_object(TP, "%^BOLD%^%^WHITE%^You are now attempting to "+
		"auto detect traps.  Please note that if a door or exit is "+
		"trapped it will show up in %^BOLD%^%^RED%^bold red"+
		"%^BOLD%^%^WHITE%^ instead of the standard "+
		"%^BOLD%^%^CYAN%^cyan%^BOLD%^%^WHITE%^.%^RESET%^");
		return 1;
	}

	if(input == "off")
	{
		if(!TP->query("is_auto_detecting_traps")) 
		{
			tell_object(TP, "You are not currently auto detecting traps.");
			return 1;
		}
		TP->delete("is_auto_detecting_traps");
		tell_object(TP, "%^BOLD%^%^WHITE%^You are no longer attempting "+
		"to auto detect traps.%^RESET%^");
		return 1;
	}
	return help();
}

int find_action(string input)
{
	string obj, MyType, *TrapKeys, MN, DTs = ({}), *Rexits, t_type;
	object theObj, *inven;
	int x, MySkill, i;
	string *TK, tmp, *DMap, TDoor;
	mapping TrapInfo; //to determine, if the room around them is a vault, if 
					//they are trying to target a door 

	if(sscanf(input, "on %s", obj) != 1)
	{
		tell_object(TP, "trap find on <object>\n");
		return 1;
	}
	
	inven = all_inventory(TP);

    	for(x = 0;x< sizeof(inven);x++) 
	{
      	if(inven[x]->id(obj)) 
		{
            	theObj = inven[x];
			MyType = "object";
            	break;
        	}
    	}

	if(!objectp(theObj)) 
	{
		inven = all_inventory(ETP);
	 	for(x = 0;x< sizeof(inven);x++) 
		{
			if(inven[x]->id(obj)) 
			{
            		theObj = inven[x];
				MyType = "object";
            		break;
        		}
		}
	}	

    	if(!objectp(theObj)) 
	{
      	theObj = ETP;
		MyType = "room";
		if(theObj->is_vault()) 
		{
			DMap = keys(theObj->query_doors_map());
			if(member_array(obj, DMap) != -1)
			{
				t_type = "door";
			}
		}
		Rexits = theObj->query_exits();	
		if(sizeof(Rexits))
		{
			if(member_array(obj, Rexits) != -1)
			{
				t_type = "exit";
			}
		}	
		if(!t_type) t_type = "misc";
    	}

	MN = TPQN;
	TrapInfo = theObj->query_trap_data();
	if(!sizeof(TrapInfo)) 
	{
		write(FFAILURE);
        	tell_room(ETP,RFFAILURE,TP);
        	return 1;
	}
	TrapKeys = keys(TrapInfo);
	MySkill = TP->query_skill("dungeoneering");
//Below bonus info added by ~Circe~ 3/20/13 to accomodate trap detection spells.
      if(TP->query_property("detecting_snares")){
         if(objectp(TP->query_property("detecting_snares"))){
            MySkill += (int)TP->query_property("detecting_snares")->query_bonus();
         }
      }
	if(sizeof(TP->query_armour("torso"))) 
	{
		MySkill += TP->skill_armor_mod(TP->query_armour("torso"));
	}
	switch(MyType)
	{
		case "object":
			for(x = 0;x < sizeof(TrapKeys);x++)
			{
				if(TrapInfo[TrapKeys[x]]["trap state"] != 1) continue;
				if(member_array(MN, keys(TrapInfo[TrapKeys[x]]["failed_check"])) != -1)
					if(TrapInfo[TrapKeys[x]]["failed_check"][MN] >= MySkill)
 						continue;
				if(member_array(MN, TrapInfo[TrapKeys[x]]["passed_check"]) != -1
				|| (MySkill + roll_dice(1, 20)) >= TrapInfo[TrapKeys[x]]["dc"])
				{
					theObj->add_passed_check(TrapKeys[x], MN);
					DTs += ({TrapKeys[x]});
					continue;
				}
				else
				{
					theObj->add_failed_check(TrapKeys[x], MN, MySkill);
					continue;
				}
				continue;
			}		
			break;
		case "room":
			for(x = 0; x < sizeof(TrapKeys);x++)
			{
				if(TrapInfo[TrapKeys[x]]["trap state"] != 1) continue;
				if(member_array(MN, keys(TrapInfo[TrapKeys[x]]["failed_check"])) != -1)
					if(TrapInfo[TrapKeys[x]]["failed_check"][MN] >= MySkill)
						continue;
				if(member_array(MN, TrapInfo[TrapKeys[x]]["passed_check"]) != -1 ||
				(MySkill + roll_dice(1, 20)) >= TrapInfo[TrapKeys[x]]["dc"])
				{			
					theObj->add_passed_check(TrapKeys[x], MN);	
					if(t_type == "door")
					{
						i = member_array(TrapKeys[x], VDOORACTS);
						if(i != -1)
						{
							DTs += ({VDOORACTS[i] +" the "+obj});		
							continue;
						}
						i = member_array(TrapKeys[x], VLOCKACTS);
						if(i != -1)
						{
							DTs += ({VLOCKACTS[i] +" any lock on the "+obj});
							continue;
						}
						TK = explode(TrapKeys[x], " ");
						if(member_array(TK[0], VDOORACTS) == -1 &&
						member_array(TK[0], VLOCKACTS) == -1) continue;
						if(strsrch(TrapKeys[x], obj) == -1) continue;
						TK -= explode(obj, " ");
						if(sizeof(TK) > 1) 
						{
							DTs += ({TK[0] + " the "+ 
							implode(TK[1..(sizeof(TK)-1)], " ") +
							" on the "+obj});
							continue;
						}
						DTs += ({TK[0] + " the "+ obj});
						continue;
					}
					if(t_type == "exit")
					{
						if(member_array(TrapKeys[x], Rexits) != -1 && 
						TrapKeys[x] == obj)
						{
							DTs += ({"use the "+TrapKeys[x] + " exit"});
							continue;
						}
						continue;
					}
					if(t_type == "misc")
					{
						if(strsrch(TrapKeys[x], obj) != -1)
						{
							TK = explode(TrapKeys[x], " ");
							TK -= explode(obj, " ");
							DTs += ({implode(TK, " ") + " the " + obj});
							continue;
						}
						continue;
					}
					else
					{
						continue;
						/*i = member_array(TrapKeys[x], VDOORACTS);
						if(i != -1)
						{
							DTs += ({VDOORACTS[i] +" any door"});		
							continue;
						}
						i = member_array(TrapKeys[x], VLOCKACTS);
						if(i != -1)
						{
							DTs += ({VLOCKACTS[i] +" any lock on any door"});
							continue;
						}
						if(member_array(TrapKeys[x], Rexits) != -1)
						{
							DTs += ({"use the "+TrapKeys[x]+" exit"});
							continue;
						}
						for(i = 0;i < sizeof(DMap);i++)
						{
							if(strsrch(TrapKeys[x], DMap[i]) != -1) 
							{
								TDoor = DMap[i];
								break;
							}
							continue;
						}
						if(!stringp(TDoor)) continue;
						TK = explode(TrapKeys[x], " ");
						TK -= explode(TDoor, " ");
						if(sizeof(TK) > 1) 
						{
							DTs += ({TK[0] + " the "+ 
							implode(TK[1..(sizeof(TK)-1)], " ") +
							" on the "+TDoor});
							continue;
						}
						DTs += ({TK[0] + " the "+ TDoor});*/
					}
				}
				else
				{
					theObj->add_failed_check(TrapKeys[x], MN, MySkill);
					continue;
				}
				continue;
			}
			break;					
	}

	if(!sizeof(DTs)) 
	{
		write(FFAILURE);
		tell_room(ETP,RFFAILURE,TP);
		return 1;
	}	

	if(MyType != "room")
	{
		tmp = " the "+obj+".";
	}
	else tmp = ".";

	if(sizeof(DTs) == 1)
	{
		tell_object(TP, "%^BOLD%^There appears to be 1 trap "+
		"on the "+obj+".  It is rigged to trigger when you %^BOLD%^"+
		"%^RED%^"+DTs[0]+"%^RESET%^%^BOLD%^"+tmp);
		tell_room(ETP, TPQCN +"%^RESET%^%^BOLD%^ seems to find "+
		"something on the "+obj+".%^RESET%^", TP);
		return 1;
	}
	else 
	{	tell_object(TP, "%^BOLD%^There appear to be "+sizeof(DTs)+
		" traps on the "+obj+".%^RESET%^");
		for(x = 0;x < sizeof(DTs);x++)
		{
			tell_object(TP, "%^BOLD%^One is rigged to trigger when "+
			"you %^BOLD%^%^RED%^"+DTs[x]+"%^RESET%^%^BOLD%^"+tmp);
		}
		tell_room(ETP, TPQCN +"%^RESET%^%^BOLD%^ seems to find "+
		"something on the "+obj+".%^RESET%^", TP);
		return 1;
	}
	return 1;
}
				


int remove_recover_action(string input, string Atype)
{
	object *inven, theObj, TrapObj;
	string obj, ThisTrap, t_type, *Rexits, *DMap, MN, *TrapKeys, tmp, MyTrap;
	int x, MySkill, DC;
	mapping TrapInfo;

	if(sscanf(input, "on %s", obj) != 1)
	{
		if(Atype == "remove")		
		{
			tell_object(TP, "trap remove on <object>\n");
			tell_object(TP, "trap disarm on <object>");
		}
		if(Atype == "recover")
			tell_object(TP, "trap recover on <object>");
		return 1;
	}
	inven = all_inventory(TP);

	for(x = 0;x < sizeof(inven);x++)
	{
		if(inven[x]->id(obj)) 
		{
			t_type = "object";
			theObj = inven[x];
			break;
		}
	}

	if(!objectp(theObj)) 
	{
		inven = all_inventory(ETP);
		for(x = 0;x < sizeof(inven);x++)
		{
			if(inven[x]->id(obj)) 
			{
				t_type = "object";
				theObj = inven[x];
				break;
			}
		}
	}

	if(!objectp(theObj)) 
	{
		theObj = ETP;
		if(theObj->is_vault()) 
		{
			DMap = keys(theObj->query_doors_map());
			if(member_array(obj, DMap) != -1)
			{
				t_type = "door";
			}
		}
		Rexits = theObj->query_exits();	
		if(sizeof(Rexits))
		{
			if(member_array(obj, Rexits) != -1)
			{
				t_type = "exit";
			}
		}
		if(!t_type) t_type = "misc";
	}	

	MN = TPQN;
	TrapInfo = theObj->query_trap_data();

	if(!sizeof(TrapInfo)) 
	{
		write(FFAILURE);
        	tell_room(ETP,RFFAILURE,TP);
        	return 1;
	}

	MySkill = TP->query_skill("dungeoneering");

	if(sizeof(TP->query_armour("torso"))) 
	{
		MySkill += TP->skill_armor_mod(TP->query_armour("torso"));
	}
	TrapKeys = keys(TrapInfo);
	
	switch(t_type)
	{
		case "object":
			for(x = 0;x < sizeof(TrapKeys);x++)
			{
				if(TrapInfo[TrapKeys[x]]["trap state"] != 1) continue;
				if(TrapInfo[TrapKeys[x]]["set by"] == TPQN) 
				{
					MyTrap = TrapKeys[x];
					continue;
				}
				if(member_array(MN, keys(TrapInfo[TrapKeys[x]]["failed_check"])) != -1) 
					if(TrapInfo[TrapKeys[x]]["failed_check"][MN] >= MySkill)
						continue;
				if(member_array(MN, TrapInfo[TrapKeys[x]]["passed_check"]) != -1 ||
				(MySkill + roll_dice(1, 20)) >= TrapInfo[TrapKeys[x]]["dc"]) 
				{
					theObj->add_passed_check(TrapKeys[x], MN);
					ThisTrap = TrapKeys[x];
					break;
				}
				else 
				{
					theObj->add_failed_check(TrapKeys[x], MN, MySkill);
					continue;
				}
			}
			break;
		case "misc": 
			for(x = 0;x < sizeof(TrapKeys);x++)
			{
				if(TrapInfo[TrapKeys[x]]["trap state"] != 1) continue;
				if(member_array(MN, keys(TrapInfo[TrapKeys[x]]["failed_check"])) != -1) 
					if(TrapInfo[TrapKeys[x]]["failed_check"][MN] >= MySkill)
						continue;
				if(member_array(MN, TrapInfo[TrapKeys[x]]["passed_check"]) != -1 ||
				(MySkill + roll_dice(1, 20)) >= TrapInfo[TrapKeys[x]]["dc"]) 
				{
					theObj->add_passed_check(TrapKeys[x], MN);
					if(strsrch(TrapKeys[x], obj) != -1) 
					{
						if(TrapInfo[TrapKeys[x]]["set by"] == TPQN)
						{
							MyTrap = TrapKeys[x];
							continue;
						}
						ThisTrap = TrapKeys[x];
						break;
					}
					continue;
				}
				else 
				{
					theObj->add_failed_check(TrapKeys[x], MN, MySkill);
					continue;
				}
			}	
		case "exit":
			if(TrapInfo[obj]) 
			{
				if(TrapInfo[obj]["trap state"] != 1) break;
				if(member_array(MN, keys(TrapInfo[obj]["failed_check"])) != -1)
				{
					if(TrapInfo[obj]["failed_check"][MN] >= MySkill)
						break;
				}
				if(member_array(MN, TrapInfo[obj]["passed_check"]) != -1 ||
				(MySkill + roll_dice(1, 20)) >= TrapInfo[obj]["dc"])
				{
					theObj->add_passed_check(obj, MN);
					ThisTrap = obj;
					break;
				}
				else
				{
					theObj->add_failed_check(obj, MN, MySkill);
					break;
				}
			}		
			break;
		case "door": 
			for(x = 0;x < sizeof(TrapKeys);x++)
			{
				if(TrapInfo[TrapKeys[x]]["trap state"] != 1) continue;
				if(member_array(MN, keys(TrapInfo[TrapKeys[x]]["failed_check"])) != -1)
					if(TrapInfo[TrapKeys[x]]["failed_check"][MN] >= MySkill)
						continue;
				if(member_array(MN, TrapInfo[TrapKeys[x]]["passed_check"]) != -1 ||
				(MySkill + roll_dice(1, 20)) >= TrapInfo[TrapKeys[x]]["dc"])
				{
					theObj->add_passed_check(TrapKeys[x], MN);
					if(member_array(TrapKeys[x], VDOORACTS) != -1)
					{
						if(TrapInfo[TrapKeys[x]]["set by"] == TPQN)
						{
							MyTrap = TrapKeys[x];
							continue;
						}
						ThisTrap = TrapKeys[x];
						break;
					}
					if(member_array(TrapKeys[x], VLOCKACTS) != -1)
					{
						if(TrapInfo[TrapKeys[x]]["set by"] == TPQN)
						{
							MyTrap = TrapKeys[x];
							continue;
						}
						ThisTrap = TrapKeys[x];
						break;
					}
					if(strsrch(TrapKeys[x], obj) != -1) 
					{
						if(TrapInfo[TrapKeys[x]]["set by"] == TPQN)
						{
							MyTrap = TrapKeys[x];
							continue;
						}
						ThisTrap = TrapKeys[x];
						break;
					}
					continue;
				}
				else 
				{
					theObj->add_failed_check(TrapKeys[x], MN, MySkill);
					continue;
				}
				continue;
			}
			break;
		default:
			break;
	}
	if(!stringp(ThisTrap) && stringp(MyTrap)) ThisTrap = MyTrap;
	if(!stringp(ThisTrap) || !TrapInfo[ThisTrap]) 
	{
		tmp = "You find no traps on the "+obj;
		if(t_type == "exit") tmp += " exit";
		tmp += " to "+Atype+".";
		tell_object(TP, tmp);
		return 1;
	}	
	DC = TrapInfo[ThisTrap]["dc"];
	if(!TP->query_invis())
	{
		tell_room(ETP, TPQCN + " is doing something to the "+obj+".", TP);
	}
	switch(Atype)
	{
		case "remove": case "disarm":
			DC += 5;
			if((MySkill + roll_dice(1, 20)) >= DC || 
			(TrapInfo[ThisTrap]["set by"] == TPQN && roll_dice(1, 20) != 1))
			{
				tmp = "You successfully disarm a trap on the "+obj;
				if(t_type == "exit") tmp += " exit.";
				else tmp += ".";
				tell_object(TP, tmp);
				TP->force_me("sigh in relief");
				theObj->disable_trap(ThisTrap, 1);
				return 1;
			}
			break;
		case "recover":
			DC += 10;
			if(TrapInfo[ThisTrap]["trap level"] != "special")
			{
				if(file_exists(TrapInfo[ThisTrap]["trap object"]+".c"))
				{
					TrapObj = new(TrapInfo[ThisTrap]["trap object"]);
				}
			}
			else
			{
				TrapObj = TRAP_D->get_trap_object("low", "random");
			}
			if(!objectp(TrapObj))
			{
				tell_object(TP, "There is something wrong with the trap "+
				"object, please bug report this.");
				return 1;
			}
			if((MySkill + roll_dice(1, 20)) >= DC ||
			(TrapInfo[ThisTrap]["set by"] == TPQN && roll_dice(1, 20) != 1))
			{
				TrapObj->set_my_dc((DC-10));
				tmp = "You successfully recover "+TrapObj->query_short()+
				" from the "+obj;
				if(t_type == "exit") tmp += " exit.";
				else tmp += ".";
				tell_object(TP, tmp);
				TP->force_me("sigh in relief");
				if((int)TrapObj->move(TP) == MOVE_NO_ROOM)
				{
					tell_object(TP, "You cannot carry the "+TrapObj->query_short()+
					" and drop it.");
					tell_room(ETP, TPQCN +" drops "+TrapObj->query_short()+
					".", TP);
					TrapObj->move(ETP);
				}
				theObj->disable_trap(ThisTrap, 2);
				return 1;
			}
			else TrapObj->remove();
			break;
		default: 
			break;
	}
	tell_object(ETP, "You hear a mechanical click....");
	TP->force_me("curse");
	TP->force_me("save");
	theObj->execute_trap(ThisTrap, TP, 1);
	return 1;
}

int help()
{
    write("
%^CYAN%^NAME%^RESET%^

trap - deal with traps

%^CYAN%^SYNOPSIS%^RESET%^

trap detect on|off
trap find|disarm|remove|recover on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^
trap reveal on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ to %^ORANGE%^%^ULINE%^WHO%^RESET%^|party
trap set %^ORANGE%^%^ULINE%^KIT%^RESET%^ on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [with %^ORANGE%^%^ULINE%^ACTION%^RESET%^|triggers]

%^CYAN%^DESCRIPTION%^RESET%^

This command manages various trap aspects. Your dungeoneering skill is essential for various actions related to them.

%^ORANGE%^<trap detect on|off>%^RESET%^
    Will toggle your ability to auto detect traps. Trapped exits will show in %^BOLD%^%^RED%^bold red%^RESET%^ if they aren't set by you and in %^BOLD%^%^GREEN%^bold green%^RESET%^ if they are set by you or your party. Non standard traps won't be shown this way.

%^ORANGE%^<trap find on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^%^ORANGE%^>%^RESET%^
    You will attemp to find a trap place on the %^ORANGE%^%^ULINE%^OBJECT%^RESET%^.

%^ORANGE%^<trap disarm|remove on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^%^ORANGE%^>%^RESET%^
    Will attempt to disarm the first trap on the object that you specify should you be able to find one. Failure will result in the trap being triggered.

%^ORANGE%^<trap reveal on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^%^ORANGE%^ to %^ORANGE%^%^ULINE%^WHO%^RESET%^%^ORANGE%^|party>%^RESET%^
    This will attempt to reveal any traps that you've set on the object you specify, to either %^ORANGE%^%^ULINE%^WHO%^RESET%^ you specify or the members of your %^ORANGE%^%^ULINE%^PARTY%^RESET%^ should you be in one and any of them present. It is presumed that they have at least a basic understanding of dungeoneering in order to understand your instructions on avoiding your traps, otherwise it will do little good.

%^ORANGE%^<trap recover on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^%^ORANGE%^>%^RESET%^
    Will attempt to recover a trap kit from the first trap on the object you specify. This is more difficult than simply disarming a trap but will result in a usuable trap kit should you succeed. Failure will result in the trap being triggered.

%^ORANGE%^<trap set %^ORANGE%^%^ULINE%^KIT%^RESET%^%^ORANGE%^ on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^%^ORANGE%^ [with %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^|triggers]>%^RESET%^
This will attempt to set the %^ORANGE%^%^ULINE%^KIT%^RESET%^ (you must have it in your inventory) on the %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ that you specify, to be triggered when someone later performs the %^ORANGE%^%^ULINE%^ACTION%^RESET%^. %^ORANGE%^<trap set %^ORANGE%^%^ULINE%^KIT%^RESET%^%^ORANGE%^ on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^%^ORANGE%^ | triggers>%^RESET%^ will reveal to you valid syntaxes for setting your trap on the %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ you specify.

%^CYAN%^SEE ALSO%^RESET%^

search, steal, glance, dungeoneering
");
    return 1;
}

