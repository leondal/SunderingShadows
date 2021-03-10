// Used to save info about guards that the avatars make, so they don't have to 
// create detailed files every reboot. -Ares
#include <std.h>
#include <security.h>

inherit OBJECT;

string GUARD_NAME,GUARD_RACE,GUARD_GENDER,GUARD_SHORT,GUARD_LONG,*GUARD_IDS=({}),*GUARD_CLASS=({}),*GUARD_SPELLS=({}),*GUARD_INVENTORY=({}),*TARGETED_PLAYERS=({}),*DONT_TARGET=({});
int GUARD_SIZE,GUARD_LEVEL,GUARD_HP,GUARD_EXP,GUARD_SWARM,GUARD_AC,GUARD_ATTACKS,GUARD_DAMAGE;
int GUARD_SPELL_CHANCE,GUARD_PLATINUM,GUARD_GOLD,GUARD_SILVER,GUARD_ELECTRUM,GUARD_COPPER,GUARD_KITS,GUARD_AGGRESSIVE;
int GUARD_RESISTANCE,SMART,GUARD_STR,GUARD_CON,GUARD_DEX,GUARD_INT,GUARD_WIS,GUARD_CHA,GUARD_DROP,GUARD_TARGETING;

void create() 
{
  ::create();
  set_name("key");
  set_id( ({"key"}) );
  set_short("a small iron key");
  set_long("This is a guard key.  The information about a guard setting has been "
      "saved here.  When you have an orb in your inventory, turn key to restore.  "
      "If you have more than one key, turn key 2, etc.");
  set_weight(0);
}
	
string query_long(string str)
{
    string hold,*ids;
    ids = GUARD_IDS;
    hold = ::query_long(str)+"  Saved guard name = "+GUARD_NAME+"  "
        "Saved guard ids = "+implode(GUARD_IDS," ")+"";
    return hold;
}

int query_is_guard_key() { return 1; }

void save_guard_arrays(string data,mixed *value)
{
    if(!stringp(data))      { return; }
    if(!pointerp(value))    { return; }
    
    switch(data)
    {
    case "guard_ids":
        GUARD_IDS = value;
        break;
    case "guard_class":
        GUARD_CLASS = value;
        break;
    case "guard_spells":
        GUARD_SPELLS = value;
        break;
    case "guard_inventory":
        GUARD_INVENTORY = value;
        break;
	case "guard_targets":
		TARGETED_PLAYERS = value;
		break;
    case "dont_target":
        DONT_TARGET = value;
        break;
    default:
        break;
    }
    return;
}

void save_guard_data(string data,mixed value)
{
    if(!stringp(data)) { return;}

    switch(data)
    {
    case "guard_name":
        GUARD_NAME = (string)value;
        break;
    case "guard_race":
        GUARD_RACE = (string)value;
        break;
    case "guard_gender":
        GUARD_GENDER = (string)value;
        break;
    case "guard_short":
        GUARD_SHORT = (string)value;
        break;
    case "guard_long":
        GUARD_LONG = (string)value;
        break;
    case "guard_size":
        GUARD_SIZE = to_int(value);
        break;
    case "guard_level":
        GUARD_LEVEL = to_int(value);
        break;
    case "guard_hp":
        GUARD_HP = to_int(value);
        break;
    case "guard_exp":
        GUARD_EXP = to_int(value);
        break;
    case "guard_swarm":
        GUARD_SWARM = to_int(value);
        break;
    case "guard_ac":
        GUARD_AC = to_int(value);
        break;
    case "guard_attacks":
        GUARD_ATTACKS = to_int(value);
        break;
    case "guard_damage":
        GUARD_DAMAGE = to_int(value);
        break;
	case "guard_aggressive":
		GUARD_AGGRESSIVE = to_int(value);
		break;
    case "guard_spell_chance":
        GUARD_SPELL_CHANCE = to_int(value);
        break;
    case "guard_platinum":
        GUARD_PLATINUM = to_int(value);
        break;
    case "guard_gold":
        GUARD_GOLD = to_int(value);
        break;
    case "guard_electrum":
        GUARD_ELECTRUM = to_int(value);
        break;
    case "guard_silver":
        GUARD_SILVER = to_int(value);
        break;
    case "guard_copper":
        GUARD_COPPER = to_int(value);
        break;
    case "guard_resistance":
        GUARD_RESISTANCE = to_int(value);
        break;
    case "smart":
        SMART = to_int(value);
        break;
    case "guard_str":
        GUARD_STR = to_int(value);
        break;
    case "guard_con":
        GUARD_CON = to_int(value);
        break;
    case "guard_dex":
        GUARD_DEX = to_int(value);
        break;
    case "guard_int":
        GUARD_INT = to_int(value);
        break;
    case "guard_wis":
        GUARD_WIS = to_int(value);
        break;
    case "guard_cha":
        GUARD_CHA = to_int(value);
        break;
    case "guard_drop":
        GUARD_DROP = to_int(value);
        break;
    case "guard_targeting":
        GUARD_TARGETING = to_int(value);
        break;
	case "guard_kits":
		GUARD_KITS = to_int(value);
		break;
    default:
        break;
    }
    return;
}

mixed get_guard_data(string data)
{
    if(!stringp(data)) { return 0;}

    switch(data)
    {
    case "guard_name":          return GUARD_NAME;
    case "guard_race":          return GUARD_RACE;
    case "guard_gender":        return GUARD_GENDER; 
    case "guard_short":         return GUARD_SHORT;
    case "guard_long":          return GUARD_LONG; 
    case "guard_size":          return GUARD_SIZE; 
    case "guard_level":         return GUARD_LEVEL; 
    case "guard_hp":            return GUARD_HP; 
    case "guard_exp":           return GUARD_EXP; 
    case "guard_swarm":         return GUARD_SWARM; 
    case "guard_ac":            return GUARD_AC; 
    case "guard_attacks":       return GUARD_ATTACKS; 
    case "guard_damage":        return GUARD_DAMAGE; 
	case "guard_aggressive":    return GUARD_AGGRESSIVE;
    case "guard_spell_chance":  return GUARD_SPELL_CHANCE; 
    case "guard_platinum":      return GUARD_PLATINUM; 
    case "guard_gold":          return GUARD_GOLD; 
    case "guard_electrum":      return GUARD_ELECTRUM; 
    case "guard_silver":        return GUARD_SILVER; 
    case "guard_copper":        return GUARD_COPPER; 
    case "guard_resistance":    return GUARD_RESISTANCE; 
    case "smart":               return SMART; 
    case "guard_str":           return GUARD_STR; 
    case "guard_con":           return GUARD_CON; 
    case "guard_dex":           return GUARD_DEX; 
    case "guard_int":           return GUARD_INT; 
    case "guard_wis":           return GUARD_WIS; 
    case "guard_cha":           return GUARD_CHA; 
    case "guard_drop":          return GUARD_DROP;
    case "guard_targeting":     return GUARD_TARGETING;
	case "guard_kits":			return GUARD_KITS;
    default:                    return 0;
    }
    return 0;
}

mixed *get_guard_arrays(string data)
{
    if(!stringp(data))      { return ({}); }
    
    switch(data)
    {
    case "guard_ids":           return GUARD_IDS; 
    case "guard_class":         return GUARD_CLASS; 
    case "guard_spells":        return GUARD_SPELLS;
    case "guard_inventory":     return GUARD_INVENTORY;
	case "guard_targets":		return TARGETED_PLAYERS;
    case "dont_target":         return DONT_TARGET;
    default:                    return ({});
    }
    return ({});
}

void restore_key(string fname)
{
	seteuid(UID_ROOT);	
	restore_object(fname);
	seteuid(geteuid());
}

void key_save(string fname)
{
	seteuid(UID_ROOT);
	save_object(fname);
	seteuid(geteuid());
}