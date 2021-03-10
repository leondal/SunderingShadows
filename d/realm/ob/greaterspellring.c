//An attempt at a ring of spell storing
#include <std.h>
#include <daemons.h>

inherit ARMOUR;

mapping MySpells = (["spell1" : (["name" : 0, "type" : 0, "power" : 0]), 
			   "spell2" : (["name" : 0, "type" : 0, "power" : 0]),
			   "spell3" : (["name" : 0, "type" : 0, "power" : 0]), 
			   "spell4" : (["name" : 0, "type" : 0, "power" : 0]), ]);
int IsTarnished;
int IsRingFull();

void store_spell(string spell_name, string spell_type, int spell_power);
void MyType();
void SetMyType(int x);
int QueryMyType();
//One of these that's tarnished will have a rare chance 
//of totally destroying you :P - or at least hurting ALOT - Saide
void do_catastrophic_damage(object vic);


void create() 
{
    ::create();
     
    set_name("A dull dark ring");
    set_id(({"ring","dark ring","dull dark ring","spell ring",
    "ring of spell storing", "spell storing ring", "greater spell ring", 
	"greater ring of spell storing", "greater spell storing ring"}));

    set_obvious_short("%^BOLD%^%^BLACK%^A dull dark ring%^RESET%^");

    set_lore("%^BOLD%^%^BLACK%^This ring was created by a magic similiar "+
	"to the other ancient rings of spell storing - however, Ao'rus "+
	"Devar manipulated the formula, allowing more potent magic to be "+
	"stored and added more chambers to the gem which holds the "+
	"magic.  Some rumors suggest that he was angered when denied one of "+
	"these rings in his youth and eventually massacred a number of other "+
	"magi, in order to obtain one, which he promptly corrupted.  "+
	"It is also suggested that most of these that he created were nothing "+
	"more than elaborate traps, a means to easily kill those who "+
	"possessed them, should they ever use them to store magic.  "+
	"Supposedly though, you could tell the traps from the real ones "+
	"simply by noting how tarnished the ring appears.  The flawless ones "+
	"are rumored to be safer.%^RESET%^");

    set_property("lore difficulty",35);  
    set_language("gnomish");
    set_read("\n%^BOLD%^%^RED%^%^Examine my ring,\n"+
    "\t%^CYAN%^to see what magic it contains. \n%^RESET%^"+
    "%^BOLD%^%^RED%^%^Store it with energy, \n"+
    "%^BOLD%^%^RED%^Release it in times of need,\n"+
    "\t%^CYAN%^or release at a target to use its effects upon them.%^RESET%^%^RESET%^");
    set_type("ring");
    set_weight(1);
    set_limbs(({"right hand","left hand"}));

}

void init() 
{
	if (!userp(ETO)) return;
    	::init();
    	if(living(ETO)) 
	{
      	add_action("store_spells","store");
        	add_action("release","release");
        	add_action("examine","examine");
    	}
}

void heart_beat()
{
	object MyVic;
	//tell_object(find_player("saide"), "It is getting here...");
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!random(5000)) return;
	if(!userp(MyVic = ETO)) 
	{
		if(objectp(EETO)) 
		{
			if(!userp(MyVic = EETO)) 
			{
				if(objectp(environment(EETO))) 
				{
					MyVic = environment(EETO);
				}
			}
		}
	}
	
	if(userp(MyVic))
	{
		//tell_object(MyVic, "You're the victim...");
		do_catastrophic_damage(MyVic);
		return;
	}
	return;
}

void do_catastrophic_damage(object vic)
{
	object hold;
	if(!objectp(TO)) return;
	if(!objectp(vic)) return;
	if(!objectp(ETO)) return;
	if(!MySpells["spell1"]["name"] && !MySpells["spell2"]["name"] &&
	!MySpells["spell3"]["name"] && !MySpells["spell4"]["name"]) return;
	if(vic != ETO)
	{
		hold = ETO;
		tell_object(vic, "%^BOLD%^%^RED%^A sudden intense humming "+
		"erupts from your "+hold->query_name()+ "%^BOLD%^%^RED%^ "+
		"as it explodes into a massive ball of fire, which "+
		"%^BOLD%^%^BLACK%^ENGULFS%^BOLD%^%^RED%^ you!%^RESET%^");

		tell_room(environment(vic), "%^BOLD%^%^RED%^A sudden intense "+
		"humming erupts from the "+hold->query_name() + "%^BOLD%^%^RED%^ "+
		"carried by "+vic->QCN+", as it explodes into a massive "+
		"ball of fire, which %^BOLD%^%^BLACK%^ENGULFS%^BOLD%^%^RED%^ "+
		vic->QO+"%^BOLD%^%^RED%^!%^RESET%^", vic);

		vic->cause_typed_damage(vic, "torso", roll_dice(30, 20), "fire");
		if(!hold->is_room()) 
		{
			hold->remove();
		}
		TO->remove();
		return;
	}
	else
	{
		tell_object(vic, "%^BOLD%^%^RED%^A sudden intense humming "+
		"erupts from your "+TO->query_name()+ "%^BOLD%^%^RED%^ "+
		"as it explodes into a massive ball of fire, which "+
		"%^BOLD%^%^BLACK%^ENGULFS%^BOLD%^%^RED%^ you!%^RESET%^");
		
		tell_room(environment(vic), "%^BOLD%^%^RED%^A sudden intense humming "+
		"erupts from "+vic->QCN+"%^BOLD%^%^RED%^'s "+TO->query_name()+
		"%^BOLD%^%^RED%^ as it explodes into a massive ball of fire, "+
		"which %^BOLD%^%^BLACK%^ENGULFS%^BOLD%^%^RED%^ "+ETO->QO+
		"%^BOLD%^%^RED%^!%^RESET%^", vic);

		vic->cause_typed_damage(vic, "torso", roll_dice(30, 20), "fire");
		TO->remove();
		return;
	}
	return;
}
	


void SetMyType(int x) 
{ 
	IsTarnished = x; 
	MyType();
}
int QueryMyType() { return IsTarnished; }

void MyType()
{
	string MyLongDesc;
		
	MyLongDesc = "%^BOLD%^%^BLACK%^The band of this ring is made from "+
		"a very dull black metal, it seems to actually absorb any light "+
		"directed at it entirely.  It is etched with %^BOLD%^%^CYAN%^"+
		"strange runes%^BOLD%^%^BLACK%^ which slither about on the band "+
		"constantly, in snake-like patterns.  An %^BOLD%^%^WHITE%^o"+
		"%^BOLD%^%^BLACK%^bs%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^d%^BOLD%^"+
		"%^BOLD%^%^WHITE%^ia%^BOLD%^%^BLACK%^ n gem rests at the top of "+
		"the band.  It is very cloudly, but if you observe it "+
		"carefully you are able to ascertain that is it actually "+
		"divided into four chambers, each one of them filled with an "+
		"almost %^BOLD%^%^RED%^blood red%^BOLD%^%^BLACK%^ mist, which "+
		"swirls about constantly in ever changing patterns.  "+
		"A phrase has been inscribed into the underside of the band.%^RESET%^";

	if(IsTarnished == 1)
	{
		TO->set_short("%^BOLD%^%^BLACK%^A t%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLACK%^"+
		"rn%^BOLD%^%^YELLOW%^i%^BOLD%^%^BLACK%^sh%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^"+
		"d gr%^BOLD%^%^YELLOW%^ea%^BOLD%^%^BLACK%^t%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^"+
		"r ring of sp%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^ll storing%^RESET%^");
		MyLongDesc += "%^BOLD%^%^BLACK%^  The entire rings appears "+
		"%^BOLD%^%^WHITE%^tarnished"+
		"%^BOLD%^%^BLACK%^, almost to the point of rendering it worthless.  As "+
		"if it has been exposed to the elements for far too long.%^RESET%^";
		TO->set_value(1000);
		//tell_object(find_player("saide"), "It is getting here... HEART should be "+
		//"started");
		set_heart_beat(1);
	} 
	if(IsTarnished == 0)
	{
		TO->set_short("%^BOLD%^%^BLACK%^A fl%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^w"+
		"l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ss gr%^BOLD%^%^WHITE%^ea%^BOLD%^"+
		"%^BLACK%^t%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ ring of sp%^BOLD%^%^WHITE%^"+
		"e%^BOLD%^%^BLACK%^ll storing%^RESET%^");
		MyLongDesc += "%^BOLD%^%^BLACK%^  The entire ring appears "+
		"%^BOLD%^%^WHITE%^flawless%^BOLD%^%^BLACK%^, suggesting that it "+
		"would be quite valuable.%^RESET%^";
		TO->set_value(25000);
	}
	TO->set_long(MyLongDesc);		
}

int examine(string str) 
{
	string tmp;
    	if(!str) return 0;
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;
    	if(str == "ring" || str == "gem") 
	{
      	if(ETO->query_bound() || ETO->query_unconscious() 
            || ETO->query_paralyzed()) 
		{
            	ETO->send_paralyzed_message("info", ETO);
            	return 1;
        	}
        	if(!MySpells["spell1"]["name"] && 
		!MySpells["spell2"]["name"] && 
		!MySpells["spell3"]["name"] &&
		!MySpells["spell4"]["name"]) 
		{
            	tell_object(ETO,"You examine the strange "+
	            "obsidian gem and find nothing of measure.");
      	      return 1;
        	}
  
        	tell_object(ETO,"You examine the strange "+
        	"obsidian gem and realize that potent magical "+
        	"energy resides within it.\n");
     
        	tmp = "%^BOLD%^%^BLACK%^St%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^r"+
		"%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^:  %^BOLD%^"+
		"%^YELLOW%^";

        	if(MySpells["spell1"]["name"]) 
			tell_object(ETO,tmp + capitalize(MySpells["spell1"]["name"]) +
			"%^RESET%^\n");
		if(MySpells["spell2"]["name"])
	        	tell_object(ETO,tmp + capitalize(MySpells["spell2"]["name"]) +
			"%^RESET%^\n");
		if(MySpells["spell3"]["name"])
			tell_object(ETO,tmp + capitalize(MySpells["spell3"]["name"]) +
			"%^RESET%^\n");
		if(MySpells["spell4"]["name"])
			tell_object(ETO,tmp + capitalize(MySpells["spell4"]["name"]) +
			"%^RESET%^\n");		
       	return 1;
    	}
    	return 0;
}

string get_spell(string str) 
{
	if(!str) return 0;
    	str = replace_string(str," ","_");
    	return "/cmds/spells/"+str[0..0]+"/_"+str+".c";
}

void failure(object who)
{
	if(!objectp(TO)) return;
	if(!objectp(who)) return;
	tell_object(who, "%^BOLD%^%^BLACK%^The ring absorbs your spell "+
	"but does not store the power of it!%^RESET%^");
	return;
}

void do_successful_store(int len, string msg) 
{
   	tell_object(ETO,"%^RED%^You carefully concentrate on the ring "+
    	"and begin muttering incantations.%^RESET%^");
    	tell_room(EETO,ETO->QCN+"%^RED%^ focuses on "+ETO->QP+
    	" ring and begins muttering incantations.%^RESET%^",ETO);
    	ETO->set_paralyzed(len * 20,"%^RED%^You are concentrating "+
    	"on storing your spell in the ring.%^RESET%^");
	if(msg == "failure")
	{
		call_out("failure", (len*20)/2, ETO);
	}
}

int IsRingFull()
{
	if(MySpells["spell1"]["name"] == 0) return 0;
	if(MySpells["spell2"]["name"] == 0) return 0;
	if(MySpells["spell3"]["name"] == 0) return 0;
	if(MySpells["spell4"]["name"] == 0) return 0;
	return 1;
}

string WhichSpell(string spell_name)
{
	if(MySpells["spell1"]["name"] == spell_name) return "spell1";
	if(MySpells["spell2"]["name"] == spell_name) return "spell2";
	if(MySpells["spell3"]["name"] == spell_name) return "spell3";
	if(MySpells["spell4"]["name"] == spell_name) return "spell4";
	return "";
}

int store_spells(string str) 
{
	string spell, file, type, *comps;
    	mapping amcomps;
	object MyCompItem;
    	int x;
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;

    	if(!str) 
	{
        	write("What spell do you wish to store in the ring? <store spelltype spellname>.\n");
        	return 1;
   	}
    	if(sscanf(str,"%s %s",type,spell) != 2) 
	{
      	write("What spell do you wish to store in the ring? <store spelltype spellname>.\n");
        	return 1;
    	}
    	if(!ETO->is_class(type)) 
	{
      	write("You are not a "+type+"! <store spelltype spellname>\n");
        	return 1;
    	}
    	if(ETO->query_bound() || ETO->query_unconscious() 
    	|| ETO->query_paralyzed()) 
	{
      	ETO->send_paralyzed_message("info",ETO);
        	return 1;
    	}
    	if((int)ETO->query_memorized(type,spell) < 1) 
	{
      	write("You don't have the spell you are trying to "+
        	"store memorized!");
        	return 1;
    	}
    	file = replace_string(spell," ","_");
    	file = "/cmds/spells/"+file[0..0]+"/_"+file;
    	if(!file_exists(file+".c")) 
	{
      	write("You have no knowledge of such a spell.");
        	return 1;
    	}
    	if(file->query_components(type)) 
	{
      	comps = keys(file->query_components(type));
   	}
    	if(sizeof(comps)) 
	{
      	for (x = 0;x < sizeof(comps); x++) 
		{
            	switch(type) 
			{
                		case "bard":
				if(!present("bard_compx", ETO)) 
				{
					tell_object(ETO,"You lack the needed compositions for the spell!");
                    		return 1;
				}
                		if(!present("bard_compx",ETO)->query_bard_comp(comps[x])) 
				{
                    		tell_object(ETO,"You lack the needed compositions for the spell!");
                    		return 1;
               	 	}
                		break;
                		case "psion":
				if(!present("psi_compx", ETO))
				{
					tell_object(ETO,"You lack the needed compositions for the spell!");
                    		return 1;
				}
                		if(!present("psi_compx",ETO)->query_psi_comp(comps[x])) 
				{
                    		tell_object(ETO,"You lack the needed crystals for the spell!");
                    		return 1;
                		}
                		break;
                		default:
				if(!present("compx", ETO))
				{
					tell_object(ETO,"You lack the needed compositions for the spell!");
                    		return 1;
				}
                		if(!present("compx",ETO)->query_comp(comps[x])) 
				{
                    		tell_object(ETO,"You lack the needed components for the spell!");
                    		return 1;
                		}
                		break;
            	}
        	}
    	}
    	amcomps = file->query_components(type);
    	for (x = 0;x < sizeof(comps); x++) 
	{
      	if(!amcomps[comps[x]]) break;  
        	switch(type) 
		{
            	case "bard": 
				present("bard_compx", ETO)->use_bard_comp(comps[x],amcomps[comps[x]]);
            		break;
            	case "psion": 
				present("psi_compx", ETO)->use_psi_comp(comps[x],amcomps[comps[x]]);
           			break;
            	default: 
				present("compx", ETO)->use_comp(comps[x],amcomps[comps[x]]);
            		break;
        	}
    	}
    	ETO->set_memorized(type,spell,-1);
  
    	if((int)file->query_spell_level(type) > 6 || IsRingFull()) 
	{
      	do_successful_store((int)file->query_spell_level(type), "failure");
        	return 1;
    	}
  
    	do_successful_store((int)file->query_spell_level(type), "success");
	store_spell(spell, type, ((int)ETO->query_guild_level(type) / 2) + 10);    
	return 1;
}

void store_spell(string spell_name, string spell_type, int spell_power)
{
	string tmp = "";
	if(!stringp(spell_name) || !stringp(spell_type) || !intp(spell_power)) return;
	if(IsRingFull()) return;
	if(!MySpells["spell1"]["name"]) 
	{
		tmp = "spell1";
	}
	else if(!MySpells["spell2"]["name"])
	{
		tmp = "spell2";
	}
	else if(!MySpells["spell3"]["name"])
	{
		tmp = "spell3";
	}
	else if(!MySpells["spell4"]["name"])
	{
		tmp = "spell4";
	}
	if(tmp != "") 
	{
		MySpells[tmp]["name"] = spell_name;
		MySpells[tmp]["type"] = spell_type;
		MySpells[tmp]["power"] = spell_power;
	}
	return;
}

void set_spell(string thetype, string str) 
{
    	string spell, ospell;
	ospell = str;
    	str = replace_string(str," ","_");
    	spell = "/cmds/spells/"+str[0..0]+"/_"+str;
    
    	if(!file_exists(spell+".c")) 
	{
      	write("No Such Spell.");
        	return 1;
    	}
    	if(IsRingFull()) 
	{
      	write("The ring is currently full.");
        	return 1;
    	}
    	store_spell(ospell, thetype, ((int)ETO->query_guild_level(thetype) / 2) + 10);
	return 1;
}

void clear_spell(string str) 
{
    	if(!str) return;
	if(member_array(str, keys(MySpells)) == -1) return;
	MySpells[str]["name"] = 0;
	MySpells[str]["type"] = 0;
	MySpells[str]["power"] = 0;
}

int release(string str) 
{
    	string spell, targ, MySpell;
    	object vic;
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;
    	if(!TO->query_worn()) 
	{
      	write("You need to wear the ring first.");
        	return 1;
    	}
    	if(ETO->query_bound() || ETO->query_unconscious() 
	|| ETO->query_paralyzed()) 
	{
        	ETO->send_paralyzed_message("info",ETO);
        	return 1;
    	}
	if(!MySpells["spell1"]["name"] && !MySpells["spell2"]["name"] &&
	!MySpells["spell3"]["name"] && !MySpells["spell4"]["name"])
	{
      	write("The ring currently has no spells stored.");
        	return 1;
    	}
    	if(!str) 
	{
      	write("You must either <release spellname> OR <release spellname at target>");
        	return 1;
    	}

    	if(sscanf(str,"%s at %s",spell,targ) == 2) 
	{
      	if(!(vic = present(targ,EETO))) 
		{
            	return notify_fail("That's not here!\n");
        	}    
		MySpell = WhichSpell(spell);
		if(MySpell != "")
		{
            	new(get_spell(MySpells[MySpell]["name"]))->use_spell(ETO,vic,
			(int)MySpells[MySpell]["power"],100,MySpells[MySpell]["type"]);
	            ETO->set_paralyzed(3,"%^RED%^You are using the ring!%^RESET%^");
      	      clear_spell(MySpell);
            	return 1;
	      }
		if(MySpell == "")
		{
			write("No such spell currently stored.");
			return 1;
		}
     	}
	MySpell = WhichSpell(str);
    	if(MySpell != "") 
	{
      	new(get_spell(MySpells[MySpell]["name"]))->use_spell(ETO,vic,
		(int)MySpells[MySpell]["power"],100,MySpells[MySpell]["type"]);
	      ETO->set_paralyzed(3,"%^RED%^You are using the ring!%^RESET%^");
      	clear_spell(MySpell);
            return 1;
    	}
    	write("No such spell currently stored.");
    	return 1;      
}

void isMagic()
{
	::isMagic();
	return 4;
}