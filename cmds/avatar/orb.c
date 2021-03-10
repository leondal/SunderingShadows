//wiz_mon.c
// added the ability for avatars to create a generic guard with any statistics and spells
// that they want.  Should be useful for creating plot monsters too -Ares 4/4/06
#include <std.h>
#include <move.h>
#include <security.h>
#define VALID_CLASSES   ({ "fighter","mage","thief","bard","paladin","ranger","cavalier","antipaladin","cleric","assassin","psion","druid" })

#define GUARD_FILE "/cmds/avatar/generic_guard"
#define KEY_FILE "/cmds/avatar/guard_key"

inherit "std/Object.c";

int in_use;
object player, monster;

varargs int chantcast(string str, int flag);
void mon_look();

// new globals needed for guard armies

mapping GUARD_INFO=([]);
string *guard_stages = ({ "ids","name","race","gender","size","stats","classes","level","hitpoints","armorclass","attacks","damage","aggressive","swarm","exp","money","spells","targets","spellchance","resistance","dropchance","smart","long","short","allies"});
string *completed_stages = ({});

int new_guard_func(string str);


object *GUARD_ARRAY=({});
string GUARD_NAME,GUARD_RACE,GUARD_GENDER,GUARD_SHORT,GUARD_LONG,*GUARD_IDS=({"guard"}),*GUARD_CLASS=({}),*GUARD_SPELLS=({}),*GUARD_INVENTORY=({}),*TARGETED_PLAYERS=({}),*DONT_TARGET=({});
int GUARD_SIZE,GUARD_LEVEL,GUARD_HP,GUARD_EXP,GUARD_SWARM,GUARD_AC,GUARD_ATTACKS,GUARD_DAMAGE;
int GUARD_SPELL_CHANCE,GUARD_PLATINUM,GUARD_GOLD,GUARD_SILVER,GUARD_ELECTRUM,GUARD_COPPER,GUARD_AGGRESSIVE,GUARD_KITS;
int GUARD_RESISTANCE,SMART,GUARD_STR,GUARD_CON,GUARD_DEX,GUARD_INT,GUARD_WIS,GUARD_CHA,GUARD_DROP,GUARD_TARGETING;
// function prototypes
void make_guard(object ob,object player);
int guard_func(string str);
void set_guard_money(int num,string type);
void set_guard_stat(int num,string stat);
void remove_guard_class(string str);
void set_guard_stuff(mixed what,string str);
void add_guard_stuff(string str,string what);
void set_guard_spells(string str);
int display();
int bring_guards(string str);
int command_guards(string str);
void save_guard();
void remove_guards();
// ***********************************

string strip_colors(string sh)
{
    string output = "", *list = ({});
   	string *words = ({});
    int i;
	if(!sh)
	{
		return output;
	}
	words = explode(sh, "%^");

	list +=({"RED", "YELLOW", "BLUE",
	"GREEN", "MAGENTA", "ORANGE", "CYAN", "BLACK", "WHITE"});

	list += ({ "B_RED", "B_YELLOW", "B_BLUE", "B_GREEN",
	"B_MAGENTA", "B_ORANGE", "B_CYAN", "B_BLACK", "B_WHITE"});

	list += ({"BOLD", "FLASH", "RESET"});

    	for(i = 0;i < sizeof(list);i++)
	{
		words = words - ({ list[i] });
	}
	output = implode(words,"");
	return output;
}

void create() {
  ::create();
  set_name("orb");
  set_id( ({"orb"}) );
  set_short("a Shiny Metal Orb");
  set_long("This is a control orb. There is writing on it.  There is a tiny "
      "key hole under the writing.");
  set_weight(10);
  in_use = 0;
}

void init() {
  ::init();
  player = TP;
  if(!avatarp(player)) {
     this_object()->remove();
   }

  add_action("read","read");
  add_action("control","control");
  add_action("command_mon","command_mon");
  add_action("move_mon","move_mon");
  add_action("peer","peer");
  add_action("remove_c","remove");
  add_action("free","free");
  add_action("destroy","destroy");
  add_action("chantcast","moncast");
  add_action("chantcast","monchant");
  add_action("save_key", "savekey");
  add_action("restore_key", "restorekey");
  add_action("guard_func","guard");
  add_action("display","display");
  add_action("bring_guards","bring");
  add_action("command_guards","command_guards");
  add_action("turn_key","turn");
  add_action("inventory_save","invent");
}

int read(string str) {
  if( str != "orb" )
    return 0;
  write("This orb is the orb of control. It is a wiz utility to control "
        "Non-Player-Characters (NPC's). There are a couple basic commands..\n"
        "control <monster>      - To make a monster a NPC character.\n"
        "command_mon <cmd>      - To make the monster do something.\n"
        "move_mon <object>      - To move the monster to a certain place.\n"
        "remove catch tell      - To remove the catch tell from the monster.\n"
        "peer into orb          - Take TOTAL control over the monster.\n"
        "free monster           - Free the monster from your control.\n"
        "bring guards           - Brings all of your guards to you.\n"
        "command_guards ric guards.\n"
        "guard save             - Saves a key in your inventory with guard info.\n"
        "inventory save <targ>  - Saves the inventory of the <targ> for next guard.\n"
        "display                - Shows the current settings for your guards.\n"
        "turn key               - Restores guard info from a key.\n"
		"moncast <spell> [(on|at) <target>]\n"
		"monchant <spell> [(on|at) <target>]\n"
        "savekey <keyname> || savekey - This saves either the specified key or all keys in your inventory\n"+
        "restorekey <avatar> key -list or restorekey <avatar> key <key name to restore> - this restores a saved key\n"+
        "                   - [BETAWARE] Casts a spell at the target.\n"
        "                   - Caster level of the creature is observed.\n"
        "destroy orb        - To destroy this object.\n" );
  return 1;
}


int destroy(string str) {
  if(str != "orb")
    return 0;
  if( in_use ) {
    if(objectp(monster))
      monster->npc_mon(0,TP);
  }
  say(player->query_cap_name() +" holds a shiny metal orb over their head, "
      "and it explodes with fragments showering all over the ground!");
  write("You hold the shiny metal orb over your head, and it explodes with "
        "fragments showering all over the ground!");
  this_object()->remove();
  return 1;
}

int control(string str) {
  if( catch( monster = get_object( str ) ) )
    return 0;
  if( in_use )  {
     write("You can't try to control something else when you are already "
           "controlling another.");
     return 1;
   }
  if (!objectp(monster)) {
    write("Hmm. Seems like a beast like that isn't there, or something whacked just happened.\n");
  return 1;
  }
  if( monster->query_is_npc() ) {
     write("This monster is already being controlled my someone.");
     return 1;
   }
  if( (int)monster->npc_mon(1, player) == 1 ) {
     write("You now have control of "+ monster->query_cap_name() +".");
	 monster->set_property("knock unconscious",1);
     in_use = 1;
     return 1;
   }
  write("Well.. Something is VERRY STRANGE here.. It didn't work...");
}


int command_mon(string str)
{
    if(!stringp(str) || str == "" || str == " ") { return 0; }
  if( !in_use )  {
     write("You have to have control of a monster before you can command it!");
     return 1;
   }
  if( !monster )  {
     write("You've lost control of the monster.");
     in_use = 0;
     return 1;
   }
/*   this is not gonna work with spell changes I don't think -H 11/26/20
  if (member_array(str, ({"cast","chant","moncast","monchant"}),1)!= -1)
    if (str != "mon")
      return chantcast(str);
      
  if(strsrch(str, "kill") != -1)*/

  switch(str)  {
   case "l"    :
   case "look" : mon_look();
     break;
   case "n"    : monster->force_NPC("north");
     mon_look();
     break;
   case "s"    : monster->force_NPC("south");
     mon_look();
     break;
   case "e"    : monster->force_NPC("east");
     mon_look();
     break;
   case "w"    : monster->force_NPC("west");
     mon_look();
     break;
   case "nw"   : monster->force_NPC("northwest");
     mon_look();
     break;
   case "sw"   : monster->force_NPC("southwest");
     mon_look();
     break;
   case "ne"   : monster->force_NPC("northeast");
     mon_look();
     break;
   case "se"   : monster->force_NPC("southeast");
     mon_look();
     break;
   case "u"    : monster->force_NPC("up");
     mon_look();
     break;
   case "d"    : monster->force_NPC("down");
     mon_look();
     break;
   case "i"    : monster->force_NPC("inventory");
     break;
   default     : monster->force_NPC(str);
   }

  return 1;
}


int move_mon(string str) {
  if(!str)
    return 0;
  if( !monster )    {
     write("You've lost control of the monster.");
     in_use = 0;
     return 1;
   }
  monster->move(environment(get_object(str)));
  return 1;
}


int free(string str) {
  if( str != "monster" )
    return 0;
  if( !in_use ) {
     write("You have to have control of a monster before you can free it!");
     return 1;
   }
  if( monster )
    monster->npc_mon(0,TP);
  in_use = 0;
  write("You release your control over the monster.");
  return 1;
}


void mon_look() {
  string tmp;
  object env;

  env = environment(monster);
  message("room_pathname", base_name(env), monster);
  message("room_description", (string)env->query_long(0), monster);
  message("room_exits", (string)env->query_long_exits(), monster);
  if( ( tmp = (string)env->describe_living_contents( ({ monster }) ) ) != "" )
    message("living_item", tmp, monster);
  if( ( tmp = (string)env->describe_item_contents( ({ }) ) ) != "" )
    message("inanimate_item", tmp, monster);
}

int peer(string str) {
  if( str != "into orb" )
    return 0;
  if( !in_use )    {
     write("You have to have control of a monster before you can control it!");
     return 1;
   }
  write("You peer into the orb, and lose contact of your body.\n"
        "To exit.. type on a blank line \"**\".\n");
  if( (int)this_player()->query_invis() == 0 )
  message("prompt",">> ",player);
  input_to("monster_total");
  return 1;
}

int monster_total(string str) {
  if(str != "**" && monster )  {
     command_mon(str);
     message("prompt",">> ",player);
     input_to("monster_total");
   }
  if( !monster )
    write("THE MONSTER HAS BEEN DESTROYED. The orb is free again.");
}

int remove_c(string str) {
  if( str != "catch tell" )
    return 0;
  if( !in_use )  {
     write("You have to have control of a monster before you can control its catch tell!");
     return 1;
  }
  monster->disable_catch_tell(1);
  write("Monster's catch_tell() function is disabled.");
  return 1;
}

void remove() {
// added checks for valid objects to stop bugs 3/17/03 *Styx*
  if(objectp(monster)) {
    if( monster && in_use) {
      in_use = 0;
      if(objectp(TP))
        monster->npc_mon(0,TP);
    }
  }
  remove_guards();
  return ::remove();
}

int save_me(string file_name) { return 1;}

varargs int chantcast(string str, int flag)
{
  object targ, *armor, mymon;
  int i,j, max;
  string str2,tmp;
  string type, spell, tar;
  if(!str)
  {
    write("Cast/Chant what on/at what?");
    return 1;
  }
  if(!sscanf(str,"%s on %s",str2,tar) && !sscanf(str, "cast %s on %s", str2, tar))
    if(!sscanf(str,"%s at %s",str2,tar) && !sscanf(str, "cast %s at %s", str2, tar))
      if(!sscanf(str,"%s to %s",str2,tar) && !sscanf(str, "cast %s to %s", str2, tar))
        str2 = str;

  spell = replace_string(str2," ","_");
  tmp = "/cmds/spells/"+spell[0..0]+"/_"+spell+".c";
  if(!file_exists(tmp))
  {
      tmp = "/cmds/"+type+"/_"+spell+".c";
      if(!file_exists(tmp))
      {
          write("Either that spell does not exist, or you do not know it!");
          return 1;
      }
  }

  if (!objectp(monster) && !flag)
  {
    write("You must <control> a monster before this command will function.");
    return 1;
  }
  if(!flag) max = 1;
  if(flag) max = sizeof(GUARD_ARRAY);

  for(i = 0;i < max;i++)
  {
      if(!flag) mymon = monster;
      else mymon = GUARD_ARRAY[i];
      if(!objectp(mymon)) continue;

      if(!pointerp(mymon->query_spells()) ||
      undefinedp(mymon->query_spells()))
      {
          write(mymon->QCN+" has no magical powers.");
          continue;
      }
      if(member_array(str2, mymon->query_spells()) == -1)
      {
          write(mymon->QCN+" can only cast the following spells \n"+
          identify(mymon->query_spells()));
          continue;
      }
      if(!tar) tar = 0;
      new(tmp)->use_spell(mymon,tar,100);
      continue;
  }
  return 1;

 // write(str);
 // write(identify(monster));

  seteuid(getuid());


  /*if (query_verb() == "cast" || query_verb() == "moncast") {
    if(((flag = (int)monster->query_guild_level("mage")) > 0)
       || ((flag = (int)monster->query_guild_level("bard")) > 0) )
      type = "wizard";
    else if(((flag = (int)monster->query_guild_level("cleric")) > 0)
            || ((flag = (int)monster->query_guild_level("druid")) > 0)
            || ((flag = (int)monster->query_guild_level("paladin")) > 0)
            || ((flag = (int)monster->query_guild_level("antipaladin")) > 0)
            || ((flag = (int)monster->query_guild_level("ranger")) > 0) )
      type = "priest";
  } else {
    if(((flag = (int)monster->query_guild_level("cleric")) > 0)
       || ((flag = (int)monster->query_guild_level("druid")) > 0))
      type = "priest";
    else if(((flag = (int)monster->query_guild_level("mage")) > 0)
	    || ((flag = (int)monster->query_guild_level("bard")) > 0) )
      type = "wizard";
  }*/



 /* tmp = "Caster level = "+ flag + "\n";
  tmp += "Mage level = "+(int)monster->query_guild_level("mage") + "\n";
  tmp += "Bard level = "+(int)monster->query_guild_level("bard") + "\n";
  tmp += "Cleric level = "+(int)monster->query_guild_level("cleric") + "\n";
  tmp += "Druid level = "+(int)monster->query_guild_level("druid") + "\n";
  write(tmp);*/


  /***********************************************************************
  // We're not checking armour.
  if(type == "wizard")
  {
    flag = 0;
    armor = TP->all_armour();
    i = sizeof(armor);
    for(j=0;j<i;j++)
    {
      if((string)armor[j]->query_type()!="clothing" && (string)armor[j]->query_type()!="bracer" && (string)armor[j]->query_type()!="ring" && !armor[j]->query_property("magicarmor"))
      {
	    if(TP->is_class("bard") &&((string)armor[j]->query_type() == "chain" || (string)armor[j]->query_type() == "leather")) continue;
	    if ((string)armor[j]->query_type() == "sheath") continue;
	    // Added for sheaths on 6/3/2001 by Garrett.
        flag = 1;
        break;
      }
    }
    if(flag)
    {
        write("You cannot cast while wearing all that armor!");
        return 1;
    }
  }
  ************************************************************************/

}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

void clear_guard()
{
	completed_stages = ({});
	return;
}

void add_stage(string stage)
{
	if(!stringp(stage)) { return; }
	if(member_array(stage,guard_stages) == -1) { return; }
	completed_stages += ({ stage });
	return;
}

int is_stat(string str)
{
	if( str == "str" || str == "dex" || str == "con" || str == "int" || str == "wis" || str == "cha") { return 1; }
	return 0;
}

void add_data(string str,object obj,string type)
{
	string *arr=({}),*arr2=({});
	int num,i;

	if(!objectp(obj)) { return; }
	if(!stringp(type)) { return; }

	write(type);

	switch(type)
	{
	case "ids":

		if(!stringp(str) || str == "" || str == " ")
		{
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		arr += ({ "guard","genericguard" });
		tell_object(obj,"Ids set to "+implode(arr,",")+"");
		GUARD_IDS = arr;
		add_stage("ids");
		new_guard_func("");
		return;

	case "name":

		if(!stringp(str) || str == "" || str == " ")
		{
			new_guard_func("");
			return;
		}
		tell_object(obj,"Name set to "+str+"");
		GUARD_NAME = str;
		add_stage("name");
		new_guard_func("");
		return;

	case "race":

		if(!stringp(str) || str == "" || str == " ")
		{
			new_guard_func("");
			return;
		}
		if(member_array(str,(string *)"/adm/daemon/race_d.c"->query_races()) == -1)
		{
			tell_object(obj,"Invalid race.");
			new_guard_func("");
			return;
		}
		tell_object(obj,"Race set to "+str+"");
		GUARD_RACE = str;
		add_stage("race");
		new_guard_func("");
		return;

	case "gender":

		if(!stringp(str) || str == "" || str == " ")
		{
			GUARD_GENDER = random(2)?"male":"female";
		}
		else
		{
			GUARD_GENDER = str;
		}
		tell_object(obj,"Gender set to "+GUARD_GENDER+"");
		add_stage("gender");
		new_guard_func("");
		return;

	case "size":

		if(!intp(to_int(str)))
		{
			new_guard_func("");
			return;
		}
		num = to_int(str);
		tell_object(obj,"Size set to "+num+"");
		GUARD_SIZE = num;
		add_stage("size");
		new_guard_func("");
		return;

	case "stats":

		if(!stringp(str) || str == "" || str == " ")
		{
			tell_object(obj,"All stats will be set to defaults");
			add_stage("stats");
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		if(sizeof(arr))
		{
			for(i=0;i<sizeof(arr);i++)
			{
				arr2 = explode(arr[i]," ");
				if(sizeof(arr2) != 2 || !is_stat(arr2[0]) || !intp(to_int(arr2[1])))
				{
					new_guard_func("");
					return;
				}
				switch(arr2[0])
				{
				case "str":
					GUARD_STR = to_int(arr2[1]);
					break;
				case "dex":
					GUARD_DEX = to_int(arr2[1]);
					break;
				case "con":
					GUARD_CON = to_int(arr2[1]);
					break;
				case "int":
					GUARD_INT = to_int(arr2[1]);
					break;
				case "wis":
					GUARD_WIS = to_int(arr2[1]);
					break;
				case "cha":
					GUARD_CHA = to_int(arr2[1]);
					break;
				}
			}
		}

		tell_object(obj,"Strength set to: "+GUARD_STR+"\n");
		tell_object(obj,"Dexterity set to: "+GUARD_DEX+"\n");
		tell_object(obj,"Constitution set to: "+GUARD_CON+"\n");
		tell_object(obj,"Intelligence set to: "+GUARD_INT+"\n");
		tell_object(obj,"Wisdom set to: "+GUARD_WIS+"\n");
		tell_object(obj,"Charisma set to: "+GUARD_CHA+"\n");

		add_stage("stats");
		new_guard_func("");
		return;

	case "classes":

		if(!stringp(str) || str == "" || str == " ")
		{
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		if(!sizeof(arr))
		{
			new_guard_func("");
			return;
		}
		for(i=0;i<sizeof(arr);i++)
		{
			if(member_array(arr[i],VALID_CLASSES) == -1)
			{
				new_guard_func("");
				return;
			}
		}
		GUARD_CLASS = arr;
		tell_object(obj,"Classes set to "+implode(GUARD_CLASS,", ")+"");
		add_stage("classes");
		new_guard_func("");
		return;

	case "level":

		num = to_int(str);
		tell_object(obj,"Level set to "+num+"");
		GUARD_LEVEL = num;
		add_stage("level");
		new_guard_func("");
		return;

	case "hitpoints":

		num = to_int(str);
		tell_object(obj,"Hitpoints set to "+num+"");
		GUARD_HP = num;
		add_stage("hitpoints");
		new_guard_func("");
		return;

	case "armorclass":

		num = to_int(str);
		tell_object(obj,"Armorclass set to "+num+"");
		GUARD_AC = num;
		add_stage("armorclass");
		new_guard_func("");
		return;

	case "attacks":

		num = to_int(str);
		tell_object(obj,"Number of attacks set to "+num+"");
		GUARD_ATTACKS = num;
		add_stage("attacks");
		new_guard_func("");
		return;

	case "damage":

		num = to_int(str);
		tell_object(obj,"Unarmed damage set to "+num+"");
		GUARD_DAMAGE = num;
		add_stage("damage");
		new_guard_func("");
		return;

	case "aggressive":

		num = to_int(str);
		tell_object(obj,"Set to attack players with a charisma below "+num+"");
		GUARD_AGGRESSIVE = num;
		add_stage("aggressive");
		new_guard_func("");
		return;

	case "swarm":

		num = to_int(str);
		tell_object(obj,"Swarm set to "+(num?"on":"off")+"");
		GUARD_SWARM = num;
		add_stage("swarm");
		new_guard_func("");
		return;

	case "exp":

		num = to_int(str);
		tell_object(obj,"Exp set to "+num+"");
		GUARD_EXP = num;
		add_stage("exp");
		new_guard_func("");
		return;

	case "money":

		if(!stringp(str) || str == "" || str == " ")
		{
			tell_object(obj,"This monster has no money.");
			add_stage("money");
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		if(!sizeof(arr))
		{
			new_guard_func("");
			return;
		}
		for(i=0;i<sizeof(arr);i++)
		{
			arr2 = explode(arr[i]," ");
			if(sizeof(arr2) != 2)
			{
				new_guard_func("");
				return;
			}
			switch(arr2[0])
			{
			case "platinum":
				tell_object(obj,""+capitalize(arr2[0])+" set to "+arr2[1]+"");
				GUARD_PLATINUM = to_int(arr2[1]);
				break;
			case "gold":
				tell_object(obj,""+capitalize(arr2[0])+" set to "+arr2[1]+"");
				GUARD_GOLD = to_int(arr2[1]);
				break;
			case "electrum":
				tell_object(obj,""+capitalize(arr2[0])+" set to "+arr2[1]+"");
				GUARD_ELECTRUM = to_int(arr2[1]);
				break;
			case "silver":
				tell_object(obj,""+capitalize(arr2[0])+" set to "+arr2[1]+"");
				GUARD_SILVER = to_int(arr2[1]);
				break;
			case "copper":
				tell_object(obj,""+capitalize(arr2[0])+" set to "+arr2[1]+"");
				GUARD_COPPER = to_int(arr2[1]);
				break;
			}
		}
		add_stage("money");
		new_guard_func("");
		return;

	case "spells":

		if(!stringp(str) || str == "" || str == " ")
		{
			tell_object(obj,"No spells for this monster.");
			add_stage("spells");
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		tell_object(obj,"Spells set to "+implode(arr,", ")+"");
		GUARD_SPELLS = arr;
		add_stage("spells");
		new_guard_func("");
		return;

	case "targets":

		if(!stringp(str) || str == "" || str == " ")
		{
			tell_object(obj,"No targets for this monster.");
			add_stage("targets");
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		tell_object(obj,"targets set to "+implode(arr,", ")+"");
		TARGETED_PLAYERS = arr;
		add_stage("targets");
		new_guard_func("");
		return;

	case "allies":

		if(!stringp(str) || str == "" || str == " ")
		{
			tell_object(obj,"No allies for this monster.");
			add_stage("allies");
			new_guard_func("");
			return;
		}
		arr = explode(str,",");
		tell_object(obj,"allies set to "+implode(arr,", ")+"");
		DONT_TARGET = arr;
		add_stage("allies");
		new_guard_func("");
		return;

	case "spellchance":

		if(!stringp(str) || str == "" || str == " ")
		{
			tell_object(obj,"This monster will not use spells.");
			add_stage("spellchance");
			new_guard_func("");
			return;
		}
		num = to_int(str);
		tell_object(obj,"This mob has a "+num+"% chance to cast spells each round.");
		GUARD_SPELL_CHANCE = num;
		add_stage("spellchance");
		new_guard_func("");
		return;

	case "resistance":

		num = to_int(str);
		tell_object(obj,"This mobs resistance set to "+num+"%");
		GUARD_RESISTANCE = num;
		add_stage("resistance");
		new_guard_func("");
		return;

	case "dropchance":

		num = to_int(str);
		tell_object(obj,"This mob has a "+num+"% chance for each piece of equipment to drop on death.");
		GUARD_DROP = num;
		add_stage("dropchance");
		new_guard_func("");
		return;

	case "smart":

		if(!stringp(str) || str == "" || str == " " || str == "0")
		{
			tell_object(obj,"No smart settings for this mob.");
			add_stage("smart");
			new_guard_func("");
			return;
		}
		num = to_int(str);
		tell_object(obj,"Smart setting is "+(num?"on":"off")+"");
		SMART = num;
		add_stage("smart");
		new_guard_func("");
		return;

	case "longdesc":

		if(!stringp(str) || str == "" || str == " ")
		{
			new_guard_func("");
			return;
		}
		tell_object(obj,"Long desc set to: \n"+str+"");
		GUARD_LONG = str;
		add_stage("long");
		new_guard_func("");
		return;

	case "shortdesc":

		if(!stringp(str) || str == "" || str == " ")
		{
			new_guard_func("");
			return;
		}
		tell_object(obj,"Short desc set to: "+str+"");
		GUARD_SHORT = str;
		add_stage("short");
		new_guard_func("");
		return;

	default:
		new_guard_func("");
		return;
	}
}

void guard_selection(string str,object obj)
{
	if(!objectp(obj)) { return; }

	switch(str)
	{
	case "1": //ids
		tell_object(obj,"Please enter the ids of this monster, seperated by a comma IE:  guard,orc,orc guard,slayer");
		input_to("add_data",obj,"ids");
		return;

	case "2": //name
		tell_object(obj,"Please enter the name of this monster.");
		input_to("add_data",obj,"name");
		return;

	case "3": //race

		tell_object(obj,"Please enter this monster's race.  Races you can pick include, but "
			"are not limited to: "+implode("/adm/daemon/race_d.c"->query_races(),",")+"");
		input_to("add_data",obj,"race");
		return;

	case "4": //gender

		tell_object(obj,"Please enter this monster's gender.  Enter a blank line to randomly "
			"choose between male and female.");
		input_to("add_data",obj,"gender");
		return;

	case "5": //size

		tell_object(obj,"Please enter the size of this monster.  1 is small, 2 is normal, 3 is large and "
			"anything bigger is giant.");
		input_to("add_data",obj,"size");
		return;

	case "6": //stats

		tell_object(obj,"Please enter the stats for this monster.  Stats are to be entered in the format:  "
			"str 10,dex 10,con 10,int 10,wis 10,cha 10  That is, abbreviation for stat, followed by the number "
			"and seperated from other stats by a comma.  Any stats not otherwise set in this way will be "
			"defaulted.");
		input_to("add_data",obj,"stats");
		return;

	case "7": //classes

		tell_object(obj,"Please enter the classes for this monster, sepeated by a comma. IE: fighter,mage");
		input_to("add_data",obj,"classes");
		return;

	case "8": //level

		tell_object(obj,"Please enter the level for this monster.  To simplify the coding, each class the "
			"monster have will be the same level so you need only enter 1 number.");
		input_to("add_data",obj,"level");
		return;

	case "9": //hitpoints

		tell_object(obj,"Please enter the maximum hitpoints for this monster.");
		input_to("add_data",obj,"hitpoints");
		return;

	case "10": //armorclass

		tell_object(obj,"Please enter the base armorclass for this monster.  This number "
			"will be adjusted upwards or downwards based on encumbrance, dexterity, and "
			"any equipment that the monster might be wearing in the end. Note that lower "
			"numbers are better");
		input_to("add_data",obj,"armorclass");
		return;

	case "11": //attacks

		tell_object(obj,"Please enter the number of attacks that this monster should have.");
		input_to("add_data",obj,"attacks");
		return;

	case "12": //damage

		tell_object(obj,"Please enter the damage that this monster's unarmed attacks should do.  "
			"Note that this only applies to unarmed attacks");
		input_to("add_data",obj,"damage");
		return;

	case "13": //aggressive

		tell_object(obj,"Please enter the aggressive level for this monster.  The monsters will "
			"attack all players that they can see with a charisma below this number.");
		input_to("add_data",obj,"aggressive");
		return;

	case "14": //swarm

		tell_object(obj,"Please enter the swarm setting for this monster.  The swarm setting determines "
			"if other monsters in the room will respond when this one is attacked.  If the swarm setting "
			"is 0, then no other monsters should join in when this one is attacked.  If the swarm "
			"setting is 1, then any other monsters in the room with a swarm setting of 1 should join "
			"in the attack.");
		input_to("add_data",obj,"swarm");
		return;

	case "15": //exp

		tell_object(obj,"Please enter the exp that the players gain from killing this mob.");
		input_to("add_data",obj,"exp");
		return;

	case "16": //money

		tell_object(obj,"Please enter the amount of money that this monster has in the format "
			"<currency> <amount>,<currency2> <amount2>  IE gold 10000,platinum 1000.  Enter a "
			"blank line for no money.");
		input_to("add_data",obj,"money");
		return;

	case "17": //spells

		tell_object(obj,"Please enter the spells for this monster seperated by a comma. IE: "
			"blink,fireball,call lightning,scorcher    Please note that the monster must have the "
			"corresponding class to use spells.  If they are not a mage, they can't use mage spells.  "
			"Enter a blank line for no spells.");
		input_to("add_data",obj,"spells");
		return;

	case "18": //targets

		tell_object(obj,"Enter any targets that this mob might have.  These players will always be attacked "
			"if the mob can detect them regardless of other aggressive settings.  The targeting can be toggled "
			"on and off.  Enter a blank line for no targets");
		input_to("add_data",obj,"targets");
		return;

	case "19": //spellchance

		tell_object(obj,"Enter the chance for spells to be case instead of melee attacks.  Note that you must "
			"have spells set and the mob must be of a class that can cast those spells before this will work.  "
			"The chance is a percentage number between 1 and 100.  IE 75 would be 75% chance to cast a spell "
			"in a round instead of using melee attacks.  100 will always cast spells every round.  Enter a blank "
			"line or 0 if this mob has no spells.");
		input_to("add_data",obj,"spellchance");
		return;

	case "20": //resistance

		tell_object(obj,"Please enter the base magic resistance for this monster.  Worn equipment might "
			"change this number.");
		input_to("add_data",obj,"resistance");
		return;

	case "21": //dropchance

		tell_object(obj,"Enter the chance for this mob to drop equipment from its inventory.  This will be the "
			"percentage chance that each piece of equipment in inventory will drop, NOT what percentage of "
			"inventory will actually drop.  Entering a 10 would be 10% for each piece to drop, and might result "
			"in several items dropping, or none at all, depending on the luck of the rolls.");
		input_to("add_data",obj,"dropchance");
		return;

	case "22": //smart

		tell_object(obj,"Enter 1 if this should be a smart mob.  Smart mobs will use their class abilities and "
			"they will also use items that you save to their inventory such as powder or nets.  They will no "
			"longer automatically generate these items, so you will need to place them into in their inventory "
			"if you want them to be used.  Entering 0 or a blank line will make this be a mundane monster.");
		input_to("add_data",obj,"smart");
		return;

	case "23": //longdesc

		tell_object(obj,"Enter the long description of the mob.");
		input_to("add_data",obj,"longdesc");
		return;

	case "24": //shortdesc

		tell_object(obj,"Enter the short description of the mob.");
		input_to("add_data",obj,"shortdesc");
		return;

	case "25": //allies

		tell_object(obj,"Enter any allies that this mob might have.  These players will never be attacked "
			"by the monsters unless they hit them with an area effect power or the player attacks them "
            "first.  Enter a blank line for no allies.  Usage: name,name2,name3,name4");
		input_to("add_data",obj,"allies");
		return;

	case "26": //clear
		tell_object(obj,"Clearing all mob information..");
		clear_guard();
		new_guard_func("");
		return;

	case "27": //exit
		return;

	default:
		return;
	}
	return;
}

int new_guard_func(string str)
{
	object obj;
	string *display = ({}),*hold=({});
	int i;

	if(!objectp(TP)) { return 1; }
	obj = TP;

	for(i=0;i<sizeof(guard_stages);i++)
	{
		if(member_array(guard_stages[i],completed_stages) == -1)
		{
			hold += ({ arrange_string("  "+arrange_string("%^RESET%^%^MAGENTA%^"+(i+1)+"%^RESET%^>%^RED%^",4)+""+capitalize(guard_stages[i])+"%^RESET%^",35) });
		}
		else
		{
			hold += ({ arrange_string("  "+arrange_string("%^RESET%^%^MAGENTA%^"+(i+1)+"%^RESET%^>%^CYAN%^",4)+""+capitalize(guard_stages[i])+"%^RESET%^",35) });
		}
	}

	for(i=0;i<sizeof(hold);i+=2)
	{
        if((sizeof(hold)-1) == i)
        {
            display += ({ hold[i] });
        }
        else
        {
		    display += ({ hold[i]+hold[i+1] });
        }
	}

	tell_object(obj,"  This is the new and improved guard maker.  The editor will guide you through the "
		"creation of the guard.  Please select one of the following:");
	tell_object(obj,""+implode(display,"\n")+"");
	tell_object(obj,arrange_string("  "+arrange_string("%^RESET%^%^MAGENTA%^26%^RESET%^>%^BOLD%^",4)+"Clear guard.%^RESET%^",35) +"  "+arrange_string("%^RESET%^%^MAGENTA%^27%^RESET%^>%^BOLD%^",4)+"Exit.%^RESET%^");
	input_to("guard_selection",obj);
	return 1;
}

void make_guard(object ob,object player)
{
    object ob2;
    int i;

    if(GUARD_NAME) { ob->set_monster_name(GUARD_NAME); }
    else ob->set_monster_name("generic guard");

    if(pointerp(GUARD_IDS)) { ob->set_id(GUARD_IDS); }
    else ob->set_id(({"guard","generic guard"}));

    if(GUARD_RACE) { ob->set_monster_race(GUARD_RACE); }
    else ob->set_monster_race("human");

    if(GUARD_GENDER) { ob->set_monster_gender(GUARD_GENDER); }
    else ob->set_monster_gender("male");

    if(GUARD_SIZE) { ob->set_monster_size(GUARD_SIZE); }
    else ob->set_monster_size(2);

    if(GUARD_SHORT) { ob->set_monster_short(GUARD_SHORT); }
    else ob->set_monster_short("a generic guard");

    if(GUARD_LONG) { ob->set_monster_long(GUARD_LONG); }
    else ob->set_monster_long("a generic guard description, it's not very impressive.");

    if(pointerp(GUARD_CLASS))
    {
		ob->set_monster_classes(GUARD_CLASS);
        for(i=0;i<sizeof(GUARD_CLASS);i++)
        {
            ob->set_monster_class(GUARD_CLASS[i]);
        }
    }
    else ob->set_monster_class("fighter");

    if(GUARD_LEVEL) { ob->set_monster_level(GUARD_LEVEL); }
    else ob->set_monster_level(10);

    if(GUARD_HP) { ob->set_monster_hp(GUARD_HP); }
    else ob->set_monster_hp(100);

    if(GUARD_EXP) { ob->set_monster_exp(GUARD_EXP); }
    else ob->set_monster_exp(1000);

    if(GUARD_SWARM) { ob->set_monster_swarm(GUARD_SWARM); }
    else ob->set_monster_swarm(0);

    if(GUARD_AC) { ob->set_monster_ac(GUARD_AC); }
    else ob->set_monster_ac(0);

    if(GUARD_STR) { ob->set_monster_stat("strength",GUARD_STR); }
    else ob->set_monster_stat("strength",10);

    if(GUARD_DEX) { ob->set_monster_stat("dexterity",GUARD_DEX); }
    else ob->set_monster_stat("dexterity",10);

    if(GUARD_CON) { ob->set_monster_stat("constitution",GUARD_CON); }
    else ob->set_monster_stat("constitution",10);

    if(GUARD_INT) { ob->set_monster_stat("intelligence",GUARD_INT); }
    else ob->set_monster_stat("intelligence",10);

    if(GUARD_WIS) { ob->set_monster_stat("wisdom",GUARD_WIS); }
    else ob->set_monster_stat("wisdom",10);

    if(GUARD_CHA) { ob->set_monster_stat("charisma",GUARD_CHA); }
    else ob->set_monster_stat("charisma",10);

    if(GUARD_ATTACKS) { ob->set_monster_attacks(GUARD_ATTACKS); }
    else ob->set_monster_attacks(2);

    if(GUARD_DAMAGE) { ob->set_monster_damage(GUARD_DAMAGE); }
    else ob->set_monster_damage(6);

	if(GUARD_AGGRESSIVE) { ob->set_monster_aggressive(GUARD_AGGRESSIVE); }

    if(pointerp(GUARD_SPELLS)) { ob->set_monster_spells(GUARD_SPELLS); }

    if(GUARD_SPELL_CHANCE) { ob->set_monster_spell_chance(GUARD_SPELL_CHANCE); }

    if(GUARD_PLATINUM) { ob->set_monster_money("platinum",GUARD_PLATINUM); }

    if(GUARD_GOLD) { ob->set_monster_money("gold",GUARD_GOLD); }

    if(GUARD_ELECTRUM) { ob->set_monster_money("electrum",GUARD_ELECTRUM); }

    if(GUARD_SILVER) { ob->set_monster_money("silver",GUARD_SILVER); }

    if(GUARD_COPPER) { ob->set_monster_money("copper",GUARD_COPPER); }

    if(GUARD_RESISTANCE) { ob->set_monster_resistance(GUARD_RESISTANCE); }

    if(SMART) { ob->set_smart(SMART); }
    if(GUARD_DROP) { ob->set_drop(GUARD_DROP); }

    if(GUARD_TARGETING) { ob->toggle_targeting(1); }

	if(TARGETED_PLAYERS) { ob->set_guard_targets(TARGETED_PLAYERS); }

    if(DONT_TARGET) { ob->set_allied_players(DONT_TARGET); }

    if(sizeof(GUARD_INVENTORY))
    {
        for(i=0;i<sizeof(GUARD_INVENTORY);i++)
        {
            ob2 = new(GUARD_INVENTORY[i]);
            ob2->set_property("monsterweapon",1);
			if(ob2->id("kitxyz"))
			{
				ob2->set_uses(GUARD_KITS);
				ob->set_property("add kits",1);
			}
            ob2->move(ob);
        }
    }

    GUARD_ARRAY += ({ ob });
    	ob->move(environment(player));
    	if((int)ob->is_weaponless() && !sizeof(ob->query_attack_limbs()) &&
	!sizeof(ob->query_wielding_limbs()))
	{
		tell_object(player, "%^BOLD%^%^RED%^This monster has no attack "+
		"limbs - do you want the code to try to add some, y/n?%^RESET%^");
		input_to("make_guard_attack_limbs", ob, player);
	}
    	return;
}


int make_guard_attack_limbs(string str, object ob, object who)
{
	string *ValidAttLimbs = ({"left hand", "right hand", "left claw", "right claw",
					  "left foreclaw", "right foreclaw"});
	string *MyActualLimbs, *MyAttLimbs = ({});
	int x;
	if(!objectp(who)) return 0;
	if(!objectp(ob)) return 0;
	if(lower_case(str[0..0]) == "y")
	{
		MyActualLimbs = ob->query_limbs();
		for(x = 0;x < sizeof(MyActualLimbs);x++)
		{
			if(member_array(MyActualLimbs[x], ValidAttLimbs) != -1)
			{
				MyAttLimbs += ({MyActualLimbs[x]});
			}
			if(sizeof(MyAttLimbs) == 2) break;
			continue;
		}
		if(!sizeof(MyAttLimbs))
		{
			tell_object(who, "No attack limbs added, found no suitable limbs.");
			return 1;
		}
		ob->set_attack_limbs(MyAttLimbs);
		tell_object(who, "Attacking attack limbs "+identify(MyAttLimbs));
		return 1;
	}
	if(lower_case(str[0..0]) == "n")
	{
		tell_object(who, "Attack no attack limbs.");
		return 1;
	}
	tell_object(player, "%^BOLD%^%^RED%^This monster has no attack "+
	"limbs - do you want the code to try to add some, y/n?%^RESET%^");
	input_to("make_guard_attack_limbs", ob, who);
	return 1;
}


int guard_func(string str)
{
    object ob;
    string *info;
    int i;

    if(!str)
    {
        ob = new(GUARD_FILE);
        make_guard(ob,TP);
        tell_object(TP,"Making guard...\n");
        return 1;
    }

    if(lower_case(str) == "help")
    {
        write("  This is the help file for the guard creation feature of the orb.  "
            "This can be used to create any type of monster, not necessiarily guards.  "
            "There are several commands to set any of a monster's attributes listed below.  "
            "<bring guards> will bring all of your guards to you.  <command_guards> will "
            "issue a command to all of them at the same time, much like command_mon works "
            "for one monster.  <guard> by itself will create a new guard in the room "
            "you are in.  You need to set all of it's attributes BEFORE you create it, and "
            "every subsequent guard will have the same attributes until you change them.  "
            "The changes will only effect newly created guards, and not guards which are "
            "already made.  If you want to control them one at a time, use the orb's "
            "control mob feature.  <inventory save> works differently in that it "
            "saves the inventory of the target you specify.  So if you inventory save "
            "guard, or inventory save styx, then it will save the inventory of that "
            "object, and the next guard you make will come standard with all of that "
            "object's inventory.  Note that properties of items are not saved, nor "
            "are items inside of containers(sacks, bags, etc).");
        write("\t"+arrange_string("guard set name",30)+"guard set race");
        write("\t"+arrange_string("guard set gender", 30)+"guard set size");
        write("\t"+arrange_string("guard set short",30)+"guard set long");
        write("\t"+arrange_string("guard set class",30)+"guard set level");
        write("\t"+arrange_string("guard set hp",30)+"guard set exp");
        write("\t"+arrange_string("guard set swarm",30)+"guard set ac");
        write("\t"+arrange_string("guard set str",30)+"guard set dex");
        write("\t"+arrange_string("guard set con",30)+"guard set int");
        write("\t"+arrange_string("guard set wis",30)+"guard set cha");
        write("\t"+arrange_string("guard set attacks",30)+"guard set damage");
        write("\t"+arrange_string("guard set spells",30)+"guard set chance");
        write("\t"+arrange_string("guard set platinum",30)+"guard set gold");
        write("\t"+arrange_string("guard set electrum",30)+"guard set silver");
        write("\t"+arrange_string("guard set copper",30)+"guard set resistance");
        write("\t"+arrange_string("guard set smart",30)+"guard set drop");
        write("");
        write("\t"+arrange_string("guard add id",30)+"guard add spell");
		write("\tguard heal");
		write("\tguard add target");
        write("\tguard targeting <on> | <off>");
        write("");
        write("\tguard remove class");
        write("");
        write("\t%^BOLD%^%^YELLOW%^guard new");
		write("\tguard save");
        write("\tguard inventory save");
        write("\tinvent save <target> where target is something with an inventory.");
        return 1;
    }

    if(lower_case(str) == "save")
    {
        save_guard();
        return 1;
    }

    info = explode(str," ");
    if(!pointerp(info)) { return 1; }

	if(lower_case(str) == "heal")
	{
		if(pointerp(GUARD_ARRAY))
		{
			tell_object(TP,"Healing "+sizeof(GUARD_ARRAY)+" mobs.");
			for(i=0;i<sizeof(GUARD_ARRAY);i++)
			{
				if(!objectp(GUARD_ARRAY[i])) { continue; }
				GUARD_ARRAY[i]->set_hp(GUARD_ARRAY[i]->query_max_hp());
			}
		}
	}


    switch(info[0])
    {

    case "set":

        if(sizeof(info) < 2) { return 1; }
        switch(info[1])
        {
        case "name":
            write("Enter the guard's name.");
            input_to("set_guard_stuff","name");
            break;
        case "race":
            write("Enter the guard's race. See <races> for valid options.");
            input_to("set_guard_stuff","race");
            break;
        case "gender":
            write("Enter the guard's gender.");
            input_to("set_guard_stuff","gender");
            break;
        case "size":
            write("Enter the guard's size.");
            input_to("set_guard_stuff","size");
            break;
        case "short":
            write("Enter the guard's short description.");
            input_to("set_guard_stuff","short");
            break;
        case "long":
            write("Enter the guard's long description.");
            input_to("set_guard_stuff","long");
            break;
        case "class":
            write("Enter the guard's class in lower case, this will be "
                "added to the ones it already has.  Use "
                "<guard remove class fighter> where fighter is the class name "
                "to remove a class.");
            input_to("set_guard_stuff","class");
            return 1;
        case "level":
            write("Enter the guard's level, this should be set after all "
                "classes are set, and will be the same for each class.");
            input_to("set_guard_stuff","level");
            break;
        case "hp":
            write("Enter the guard's max hp.");
            input_to("set_guard_stuff","hp");
            break;
        case "exp":
            write("Enter the exp the player gets for killing the guard.");
            input_to("set_guard_stuff","exp");
            break;
        case "swarm":
            write("Enter if the guard should <swarm>, or auto attack when "
                "other creatures in the room are attacked.(Use protect if "
                "you want them to protect your persona).");
            input_to("set_guard_stuff","swarm");
            break;
        case "ac":
            write("Enter the guard's base armor class.");
            input_to("set_guard_stuff","ac");
            break;
        case "str":
            write("Enter the guard's strength.");
            input_to("set_guard_stat","strength");
            break;
        case "dex":
            write("Enter the guard's dexterity.");
            input_to("set_guard_stat","dexterity");
            break;
        case "con":
            write("Enter the guard's constitution.");
            input_to("set_guard_stat","constitution");
            break;
        case "int":
            write("Enter the guard's intelligence.");
            input_to("set_guard_stat","intelligence");
            break;
        case "wis":
            write("Enter the guard's wisdom.");
            input_to("set_guard_stat","wisdom");
            break;
        case "cha":
            write("Enter the guard's charisma.");
            input_to("set_guard_stat","charisma");
            break;
        case "attacks":
            write("Enter how many attacks this guard has.");
            input_to("set_guard_stuff","attacks");
            break;
        case "damage":
            write("Enter this guard's unarmed damage.");
            input_to("set_guard_stuff","damage");
            break;
        case "spells":
            write("Enter this guard's spells one at a time, hit enter "
                "after each one, and ** or <done> when finished.");
            input_to("set_guard_spells");
            break;
        case "spell chance":
        case "chance":
            write("Enter the chance for this guard to use spells.");
            input_to("set_guard_stuff","spell chance");
            break;
        case "platinum":
            write("Enter how much platinum this guard drops when killed.  "
                "This is a random amount from 0 to the number you enter.");
            input_to("set_guard_money","platinum");
            break;
        case "gold":
            write("Enter how much gold this guard drops when killed.  "
                "This is a random amount from 0 to the number you enter.");
            input_to("set_guard_money","gold");
            break;
        case "electrum":
            write("Enter how much electrum this guard drops when killed.  "
                "This is a random amount from 0 to the number you enter.");
            input_to("set_guard_money","electrum");
            break;
        case "silver":
            write("Enter how much silver this guard drops when killed.  "
                "This is a random amount from 0 to the number you enter.");
            input_to("set_guard_money","silver");
            break;
        case "copper":
            write("Enter how much copper this guard drops when killed.  "
                "This is a random amount from 0 to the number you enter.");
            input_to("set_guard_money","copper");
            break;
        case "resistance":
            write("Enter this guard's magic resistance");
            input_to("set_guard_stuff","resistance");
            break;
        case "smart":
            write("Enter 1 if you want this guard to use smart combat.  This "
                "will have the guard use it's class abilities in battle "
                "and try to powder or net an opponent as well as lower its "
                "magic resistance if the guard is of a class that can do so.");
            input_to("set_guard_stuff","smart");
            break;
        case "drop":
            write("Enter 1 if the guard should drop its inventory when it dies.  "
                "Otherwise, it shouldn't drop anything unless you've handed it to "
                "them.");
            input_to("set_guard_stuff","drop");
            break;
        default:
            break;
        }

    case "add":

        if(sizeof(info) < 2) { return 1; }
        switch(info[1])
        {
        case "id":
            write("Enter the id to add to the guard.  This will add to "
                "the existing ids.");
            input_to("add_guard_stuff","id");
            break;
        case "spell":
            write("Enter the spell to add to the list of guard spells.  "
                "This will add to the already existing spells.");
            input_to("add_guard_stuff","spell");
            break;
		case "target":
			write("Enter the names of the players who you would like to "
				"add to the list for the guards to auto attack.");
			input_to("add_guard_stuff","target");
			break;
        default:
            break;
        }

	case "new":

		new_guard_func("");
		return 1;

    case "remove":

        if(sizeof(info) < 2) { return 1; }
        switch(info[1])
        {
        case "class":
            write("Enter the class you wish to remove");
            input_to("remove_guard_class");
            break;
		case "id":
			write("Enter the id you wish to remove");
			input_to("remove_guard_id");
			break;
		case "spell": case "spells":
			write("Enter the spell you wish to remove");
			input_to("remove_guard_spell");
			break;
        default:
            break;
        }

    case "targeting":

        if(!sizeof(info)) { return 1; }
        switch(info[1])
        {
        case "on":
            GUARD_TARGETING = 1;
            write("Targeting on.");
            if(pointerp(GUARD_ARRAY))
            {
                for(i=0;i<sizeof(GUARD_ARRAY);i++)
                {
                    if(!objectp(GUARD_ARRAY[i])) { continue; }
                    GUARD_ARRAY[i]->toggle_targeting(1);
                }
            }
            break;
        case "off":
            GUARD_TARGETING = 0;
            write("Targeting off");
            if(pointerp(GUARD_ARRAY))
            {
                for(i=0;i<sizeof(GUARD_ARRAY);i++)
                {
                    if(!objectp(GUARD_ARRAY[i])) { continue; }
                    GUARD_ARRAY[i]->toggle_targeting(0);
                }
            }
            break;
        default:
            break;
        }
    }

    return 1;
}

void set_guard_money(mixed num,string type)
{
    if(!stringp(type)) { return; }

    switch(type)
    {
    case "platinum":
        GUARD_PLATINUM = to_int(num);
        break;
    case "gold":
        GUARD_GOLD = to_int(num);
        break;
    case "electrum":
        GUARD_ELECTRUM = to_int(num);
        break;
    case "silver":
        GUARD_SILVER = to_int(num);
        break;
    case "copper":
        GUARD_COPPER = to_int(num);
        break;
    default:
        break;
    }
    return;
}

void set_guard_stat(mixed num,string stat)
{
    if(!stringp(stat)) { return; }

    switch(stat)
    {
    case "strength":
        GUARD_STR = to_int(num);
        break;
    case "dexterity":
        GUARD_DEX = to_int(num);
        break;
    case "constitution":
        GUARD_CON = to_int(num);
        break;
    case "intelligence":
        GUARD_INT = to_int(num);
        break;
    case "wisdom":
        GUARD_WIS = to_int(num);
        break;
    case "charisma":
        GUARD_CHA = to_int(num);
        break;
    default:
        break;
    }
    return;
}

void remove_guard_class(string str)
{
    if(!stringp(str)) { return; }
    GUARD_CLASS -= ({ str });
    return;
}

void remove_guard_id(string str)
{
	if(!stringp(str)) { return; }
	GUARD_IDS -= ({ str });
	return;
}

void remove_guard_spell(string str)
{
	if(!stringp(str)) { return; }
	GUARD_SPELLS -= ({ str });
	return;
}

void set_guard_stuff(mixed what,string str)
{
    if(!stringp(str)) { return; }

    switch(str)
    {
    case "name":
        GUARD_NAME = (string)what;
        break;
    case "race":
        GUARD_RACE = (string)what;
        break;
    case "gender":
        GUARD_GENDER = (string)what;
        break;
    case "short":
        GUARD_SHORT = (string)what;
        break;
    case "long":
        GUARD_LONG = (string)what;
        break;
    case "class":
        GUARD_CLASS += ({ (string)what });
        break;
    case "size":
        GUARD_SIZE = to_int(what);
        break;
    case "level":
        GUARD_LEVEL = to_int(what);
        break;
    case "hp":
        GUARD_HP = to_int(what);
        break;
    case "exp":
        GUARD_EXP = to_int(what);
        break;
    case "swarm":
        GUARD_SWARM = to_int(what);
        break;
    case "ac":
        GUARD_AC = to_int(what);
        break;
    case "attacks":
        GUARD_ATTACKS = to_int(what);
        break;
    case "damage":
        GUARD_DAMAGE = to_int(what);
        break;
    case "spell chance":
        GUARD_SPELL_CHANCE = to_int(what);
        break;
    case "resistance":
        GUARD_RESISTANCE = to_int(what);
        break;
    case "smart":
        SMART = to_int(what);
        break;
    case "drop":
        GUARD_DROP = to_int(what);
        break;
    case "targeting":
        GUARD_TARGETING = to_int(what);
        break;
    default:
        break;
    }
    return;
}

void add_guard_stuff(string str,string what)
{
    int i;
	string *tmp;

	if(!stringp(str)) { return; }
	if(!stringp(what)) { return; }

    switch(what)
    {
    case "id":
        GUARD_IDS += ({ str });
        break;
    case "spell":
        GUARD_SPELLS += ({ str });
        break;
	case "target":
		tmp = explode(str," ");
		if(!sizeof(tmp) || tmp == ({})) { return; }
		for(i=0;i<sizeof(tmp);i++)
		{
            if(tmp[i] == "") { continue; }
            if(!pointerp(TARGETED_PLAYERS)) { TARGETED_PLAYERS = ({}); }
			TARGETED_PLAYERS += ({ tmp[i] });
			write("Adding player "+tmp[i]+" to the auto attack list.");
		}
		break;
    default:
        break;
    }
    return;
}

void set_guard_spells(string str)
{
    if(!stringp(str)) { return; }

    switch(str)
    {
    case "**":
        write("Finishing...");
        break;
    case "none":
        write("Finishing...");
        break;
    case "":
        write("Finishing...");
        break;
    default:
        GUARD_SPELLS += ({ str });
        write(""+str+" added.");
        write("Enter the next spell, ** to finish.");
        input_to("set_guard_spells");
        break;
    }
    return;
}

int display()
{
    string yes_no,*names=({}),on_off;
    int i;
    yes_no = GUARD_DROP ? "yes" : "no";
    on_off = GUARD_TARGETING ? "on" : "off";

    if(pointerp(GUARD_ARRAY))
    {
        for(i=0;i<sizeof(GUARD_ARRAY);i++)
        {
            if(!objectp(GUARD_ARRAY[i])) { continue; }
            names   += ({ capitalize((string)GUARD_ARRAY[i]->query_name()) });
        }
    }

    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    if(sizeof(names))               { write("Guard Names: "+implode(names," ")+""); }
    if(pointerp(GUARD_CLASS))       { write("Current classes set to: "+implode(GUARD_CLASS,"/")+""); }
    if(stringp(GUARD_NAME))         { write("Current name set to:                   "+GUARD_NAME+""); }
    if(stringp(GUARD_RACE))         { write("Current race set to:                   "+GUARD_RACE+""); }
    if(stringp(GUARD_GENDER))       { write("Current gender set to:                 "+GUARD_GENDER+""); }
    if(intp(GUARD_HP))              { write("Current guard max hitpoints set to:    "+GUARD_HP+""); }
    if(intp(GUARD_EXP))             { write("Current guard exp set to:              "+GUARD_EXP+""); }
    if(intp(GUARD_SIZE))            { write("Current guard size set to:             "+GUARD_SIZE+""); }
    if(intp(GUARD_LEVEL))           { write("Current guard level set to:            "+GUARD_LEVEL+""); }
    if(intp(GUARD_SWARM))
    {
        if(GUARD_SWARM == 1)        { write("Current guard swarm set to:            %^CYAN%^ON%^RESET%^"); }
        else                        { write("Current guard swarm set to:            %^RED%^OFF%^RESET%^"); }
    }
    if(intp(GUARD_AC))              { write("Current guard ac set to:               "+GUARD_AC+""); }
    if(intp(GUARD_ATTACKS))         { write("Current guard attacks set to:          "+GUARD_ATTACKS+""); }
    if(intp(GUARD_DAMAGE))          { write("Current guard unarmed damage set to:   "+GUARD_DAMAGE+""); }
	if(intp(GUARD_AGGRESSIVE))      { write("Current guard aggressive set to:       "+GUARD_AGGRESSIVE+""); }
    if(intp(GUARD_RESISTANCE))      { write("Current guard magic resistance set to: "+GUARD_RESISTANCE+""); }
    if(intp(GUARD_STR))             { write("Current guard strength set to:         "+GUARD_STR+""); }
    if(intp(GUARD_DEX))             { write("Current guard dexterity set to:        "+GUARD_DEX+""); }
    if(intp(GUARD_CON))             { write("Current guard constitution set to:     "+GUARD_CON+""); }
    if(intp(GUARD_INT))             { write("Current guard intelligence set to:     "+GUARD_INT+""); }
    if(intp(GUARD_WIS))             { write("Current guard wisdom set to:           "+GUARD_WIS+""); }
    if(intp(GUARD_CHA))             { write("Current guard charisma set to:         "+GUARD_CHA+""); }
    if(intp(GUARD_SPELL_CHANCE))    { write("Current guard spell chance set to:     "+GUARD_SPELL_CHANCE+""); }
    if(intp(GUARD_PLATINUM))        { write("Platinum: random "+GUARD_PLATINUM+""); }
    if(intp(GUARD_GOLD))            { write("Gold:     random "+GUARD_GOLD+""); }
    if(intp(GUARD_ELECTRUM))        { write("Electrum: random "+GUARD_ELECTRUM+""); }
    if(intp(GUARD_SILVER))          { write("Silver:   random "+GUARD_SILVER+""); }
    if(intp(GUARD_COPPER))          { write("Copper:   random "+GUARD_COPPER+""); }
    if(intp(GUARD_DROP))            { write("Will this guard drop its inventory? "+yes_no+""); }
    if(pointerp(GUARD_IDS))         { write("Current guard ids: "+implode(GUARD_IDS," ")+""); }
    if(stringp(GUARD_SHORT))        { write("Current guard short description: "+GUARD_SHORT+""); }
    if(stringp(GUARD_LONG))         { write("Current guard long description:\n"+GUARD_LONG+""); }
                                      write("Guard targeting is currently toggled: "+on_off+"");
    if(pointerp(TARGETED_PLAYERS))  { write("Players currently targeted by the guards: \n\t"+implode(TARGETED_PLAYERS,"\n\t\t        ")+""); }
    if(pointerp(DONT_TARGET))       { write("Players currently allied with the guards: \n\t"+implode(DONT_TARGET,"\n\t\t        ")+""); }
    if(pointerp(GUARD_SPELLS))      { write("Current guard spells: \n\t"+implode(GUARD_SPELLS,"\n\t")+""); }
    if(SMART)                       { write("%^RED%^Smart combat is enabled.%^RESET%^"); }
    else                            { write("Smart combat is disabled."); }
    if(pointerp(GUARD_INVENTORY))   { write("Guard inventory: \n\t"+implode(GUARD_INVENTORY,"\n\t\t      ")+""); }
    write("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    return 1;
}

int bring_guards(string str)
{
    int i;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    if(lower_case(str) != "guards") { return 0; }
    if(!pointerp(GUARD_ARRAY)) { return 0; }
    for(i=0;i<sizeof(GUARD_ARRAY);i++)
    {
        if(!objectp(GUARD_ARRAY[i])) { continue; }
        GUARD_ARRAY[i]->move(ETP);
    }
    return 1;
}

int command_guards(string str)
{
    object targ,targ2;
    string who, *tmp;
    int i;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    if(!pointerp(GUARD_ARRAY)) { return 0; }
    if(sscanf(str,"follow %s",who) == 1) { targ = present(who,ETP); }
    if(sscanf(str,"unfollow %s",who) == 1) { targ2 = present(who,ETP); }
    tmp = explode(str, " ");
    if (member_array(tmp[0], ({"cast","chant","moncast","monchant"}) )!= -1)
    {
        tell_object(TP, "getting here....");
        tmp -= ({ tmp[0] });
        return chantcast(implode(tmp, " "), 1);
    }

    for(i=0;i<sizeof(GUARD_ARRAY);i++)
    {
        if(!objectp(GUARD_ARRAY[i])) { continue; }
        if(objectp(targ)) { targ->add_follower(GUARD_ARRAY[i]); }
        if(objectp(targ2)) { targ2->remove_follower(GUARD_ARRAY[i]); }
        GUARD_ARRAY[i]->force_me(str);
    }
    return 1;
}

void save_guard()
{
    object key;
    mapping save_data,save_arrays;
    string *info;
    int i;

    save_data = ([   "guard_name"           : GUARD_NAME,
                     "guard_race"           : GUARD_RACE,
                     "guard_gender"         : GUARD_GENDER,
                     "guard_short"          : GUARD_SHORT,
                     "guard_long"           : GUARD_LONG,
                     "guard_size"           : GUARD_SIZE,
                     "guard_level"          : GUARD_LEVEL,
                     "guard_hp"             : GUARD_HP,
                     "guard_exp"            : GUARD_EXP,
                     "guard_swarm"          : GUARD_SWARM,
                     "guard_ac"             : GUARD_AC,
                     "guard_attacks"        : GUARD_ATTACKS,
                     "guard_damage"         : GUARD_DAMAGE,
					 "guard_aggressive"     : GUARD_AGGRESSIVE,
                     "guard_spell_chance"   : GUARD_SPELL_CHANCE,
                     "guard_platinum"       : GUARD_PLATINUM,
                     "guard_gold"           : GUARD_GOLD,
                     "guard_electrum"       : GUARD_ELECTRUM,
                     "guard_silver"         : GUARD_SILVER,
                     "guard_copper"         : GUARD_COPPER,
                     "guard_resistance"     : GUARD_RESISTANCE,
                     "smart"                : SMART,
                     "guard_str"            : GUARD_STR,
                     "guard_dex"            : GUARD_DEX,
                     "guard_con"            : GUARD_CON,
                     "guard_int"            : GUARD_INT,
                     "guard_wis"            : GUARD_WIS,
                     "guard_cha"            : GUARD_CHA,
                     "guard_drop"           : GUARD_DROP,
                     "guard_targeting"      : GUARD_TARGETING, ]);


    save_arrays = ([ "guard_ids"            : GUARD_IDS,
                     "guard_class"          : GUARD_CLASS,
                     "guard_spells"         : GUARD_SPELLS,
                     "guard_inventory"      : GUARD_INVENTORY,
					 "guard_targets"		: TARGETED_PLAYERS,
                     "dont_target"          : DONT_TARGET, ]);

    key = new(KEY_FILE);

    info = keys(save_data);
    for(i=0;i<sizeof(info);i++)
    {
        key->save_guard_data(info[i],save_data[info[i]]);
    }
    info = keys(save_arrays);
    for(i=0;i<sizeof(info);i++)
    {
        key->save_guard_arrays(info[i],save_arrays[info[i]]);
    }
    key->move(TP);
    tell_object(TP,"Saving guard data...\n");
    return;
}

int turn_key(string str)
{
    object key;
    string what;
    int which;
    if(!stringp(str)) { return 0; }

    if(sscanf(str,"key %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) {}

    if(which) { key = present("key "+which+"",TP); }
    else { key = present("key",TP); }
    if(!objectp(key)) { tell_object(TP,"No key found."); return 1; }

    if(base_name(key) != KEY_FILE) { tell_object(TP,"Wrong type of key.\n"); return 1; }

    GUARD_NAME          = key->get_guard_data("guard_name");
    GUARD_RACE          = key->get_guard_data("guard_race");
    GUARD_GENDER        = key->get_guard_data("guard_gender");
    GUARD_SHORT         = key->get_guard_data("guard_short");
    GUARD_LONG          = key->get_guard_data("guard_long");
    GUARD_SIZE          = key->get_guard_data("guard_size");
    GUARD_LEVEL         = key->get_guard_data("guard_level");
    GUARD_HP            = key->get_guard_data("guard_hp");
    GUARD_EXP           = key->get_guard_data("guard_exp");
    GUARD_SWARM         = key->get_guard_data("guard_swarm");
    GUARD_AC            = key->get_guard_data("guard_ac");
    GUARD_ATTACKS       = key->get_guard_data("guard_attacks");
    GUARD_DAMAGE        = key->get_guard_data("guard_damage");
	GUARD_AGGRESSIVE    = key->get_guard_data("guard_aggressive");
    GUARD_SPELL_CHANCE  = key->get_guard_data("guard_spell_chance");
    GUARD_PLATINUM      = key->get_guard_data("guard_platinum");
    GUARD_GOLD          = key->get_guard_data("guard_gold");
    GUARD_ELECTRUM      = key->get_guard_data("guard_electrum");
    GUARD_SILVER        = key->get_guard_data("guard_silver");
    GUARD_COPPER        = key->get_guard_data("guard_copper");
    GUARD_RESISTANCE    = key->get_guard_data("guard_resistance");
    SMART               = key->get_guard_data("smart");
    GUARD_STR           = key->get_guard_data("guard_str");
    GUARD_DEX           = key->get_guard_data("guard_dex");
    GUARD_CON           = key->get_guard_data("guard_con");
    GUARD_INT           = key->get_guard_data("guard_int");
    GUARD_WIS           = key->get_guard_data("guard_wis");
    GUARD_CHA           = key->get_guard_data("guard_cha");
    GUARD_IDS           = key->get_guard_arrays("guard_ids");
    GUARD_CLASS         = key->get_guard_arrays("guard_class");
    GUARD_SPELLS        = key->get_guard_arrays("guard_spells");
    GUARD_INVENTORY     = key->get_guard_arrays("guard_inventory");
    GUARD_DROP          = key->get_guard_data("guard_drop");
    GUARD_TARGETING     = key->get_guard_data("guard_targeting");
	TARGETED_PLAYERS    = key->get_guard_arrays("guard_targets");
    DONT_TARGET         = key->get_guard_arrays("dont_target");
	GUARD_KITS          = key->get_guard_data("guard_kits");

    tell_object(TP,"You insert the key into the orb and it makes a metallic "
        "clicking sound as it turns.");
    tell_object(TP,"Restoring guard data...\n");
    return 1;
}

int inventory_save(string str)
{
    object targ,*stuff;
    string *inv=({}),*not_allowed,what,*info;
    int i,which;

    if(!stringp(str)) { return 0; }

    not_allowed = ({ "/d/common/obj/misc/ssack",
                     "/d/common/obj/misc/sack",
                     "/d/common/obj/misc/sbasket",
                     "/d/common/obj/misc/basket",
                     "/d/common/obj/misc/backpack",
                     "/d/common/obj/misc/bandoleer",
                     "/d/common/obj/misc/chest",
                     "/d/common/obj/misc/lkchest",
                     "/d/common/obj/misc/pouch",
                     "/d/common/obj/misc/schest",
                     "/d/common/obj/misc/spouch",
                     "/cmds/avatar/orb",
                     "/d/magic/obj/contingency",
                     "/d/magic/spellbook",
                     "/d/magic/obj/scompanioncaller",});

    info = explode(str," ");
    if(!pointerp(info)) { return 0; }
    if(!sizeof(info)) { return 0; }
    if(lower_case(info[0]) != "save") { return 0; }
    if(sizeof(info) == 2) { what = info[1]; }
    else if(sizeof(info) == 3) { what = info[1]; which = info[2]; }

    if(which) { targ = present(""+what+" "+which+"",ETP); }
    else { targ = present(""+what+"",ETP); }
    if(!objectp(targ)) { tell_object(TP,"Invalid target.\n"); return 1; }


    stuff = all_inventory(targ);
    if(!sizeof(stuff)) { tell_object(TP,"Target has no inventory.\n"); return 1; }
    for(i=0;i<sizeof(stuff);i++)
    {
        if(member_array(base_name(stuff[i]),not_allowed) != -1) { continue; }
		if(stuff[i]->id("kitxyz"))
		{
			GUARD_KITS += (int)stuff[i]->query_uses();
		}
        inv += ({ base_name(stuff[i]) });
    }
    GUARD_INVENTORY = inv;
    tell_object(TP,"Saving inventory...");
    return 1;
}

void remove_guards()
{
    int i;
    if(!pointerp(GUARD_ARRAY)) { return; }
    if(!sizeof(GUARD_ARRAY)) { return; }
    for(i=0;i<sizeof(GUARD_ARRAY);i++)
    {
        if(!objectp(GUARD_ARRAY[i])) { continue; }
        GUARD_ARRAY[i]->move("/d/shadowgate/void");
        GUARD_ARRAY[i]->remove();
    }
    return;
}

void save_key(string keyTarg)
{
	int x, y, z;
	object *myKeys = ({}), myKey, *inv, *deep_inv, *ddeep_inv;
	string fname, KEYDIR;
	if(!objectp(TO)) return;
	if(!objectp(TP)) return;
	if(!stringp(keyTarg)) keyTarg = "all";
	else
	{
		if(!objectp(myKey = present(keyTarg, TP)))
		{
			tell_object(TP, "You do not seem to have a "+keyTarg+ " key.");
			return 1;
		}
	}
	if(objectp(myKey)) myKeys += ({myKey});
	if(keyTarg == "all")
	{
		inv = all_inventory(TP);
		for(x = 0;x < sizeof(inv);x++)
		{
			if(inv[x]->query_is_guard_key()) myKeys += ({inv[x]});
			deep_inv = all_inventory(inv[x]);
			for(y = 0;y < sizeof(deep_inv);y++)
			{
				if(deep_inv[y]->query_is_guard_key()) myKeys += ({deep_inv[y]});
				ddeep_inv = all_inventory(deep_inv[y]);
				for(z = 0;z < sizeof(ddeep_inv);z++)
				{
					if(ddeep_inv[z]->query_is_guard_key()) myKeys += ({ddeep_inv[z]});
					continue;
				}
				continue;
			}
			continue;
		}
	}
	if(!sizeof(myKeys))
	{
		tell_object(TP, "You apparently have no guard keys...");
		return 1;
	}
	KEYDIR = "/d/avatars/"+TPQN+"/keys/";
	seteuid(UID_ROOT);
	if(!sizeof(get_dir(KEYDIR)))
	{
		mkdir(KEYDIR);
	}
	for(x = 0;x < sizeof(myKeys);x++)
	{
		fname = (string)myKeys[x]->get_guard_data("guard_name");
		tell_object(TP, "Saving key with guard name "+fname+".");
		fname = strip_colors(fname);
		fname = implode(explode(fname, " "), "_");
		myKeys[x]->key_save(KEYDIR + fname);
		continue;
	}
	seteuid(getuid());
	return 1;
}

void restore_key(string arg)
{
	int x;
	string hformat = "%^BOLD%^%^GREEN%^============================"+
	"=============================================%^RESET%^";
	string avTarg, keyName, *files, tmps, fname;
	object myKey;
	if(!objectp(TO)) return;
	if(!objectp(TP)) return;
	if(!stringp(arg))
	{
		tell_object(TP, "You need to specify a key to restore.");
		return 1;
	}

	if(sscanf(arg, "%s key %s", avTarg, keyName) != 2)
	{
		avTarg = TPQN;
		keyName = arg;
	}

	if(!get_dir("/d/avatars/"+avTarg+"/keys/"))
	{
		tell_object(TP, "It appears that "+avTarg+" has no keys saved.");
		return 1;
	}
	files = get_dir("/d/avatars/"+avTarg+"/keys/*.o");
	if(keyName == "-list" || keyName == "- list")
	{
		tmps = hformat + "\n";
		tmps += "%^BOLD%^%^CYAN%^\t\t"+capitalize(avTarg)+"'s Keys%^RESET%^\n";
		tmps += hformat +"\n";
		for(x = 0;x < sizeof(files);x++)
		{
			fname = explode(files[x], ".o")[0];
			fname = implode(explode(fname, "_"), " ");
			tmps += (x+1) + ".) "+ fname + "\n";
			continue;
		}
		TP->more(explode(tmps, "\n"));
		return 1;
	}
	else
	{
		if(keyName != "all")
		{
			fname = implode(explode(keyName, " "), "_") + ".o";
			if(member_array(fname, files) == -1)
			{
				tell_object(TP, "You can't seem to find a key named "+keyName+
				" in "+avTarg+"'s key list.");
				return 1;
			}
			else
			{
				seteuid(UID_ROOT);
				myKey = new("/cmds/avatar/guard_key");
				fname = explode(fname, ".o")[0];
				myKey->restore_key("/d/avatars/"+avTarg+"/keys/"+fname);
				tell_object(TP, "Attemping to restore "+avTarg+"'s key with the guard name "+keyName);
				myKey->move(TP);
				seteuid(geteuid());
				return 1;
			}
		}
		if(keyName == "all")
		{
			tell_object(TP, "Attemping to restore all of "+avTarg+"'s keys!");
			for(x = 0;x < sizeof(files);x++)
			{
				seteuid(UID_ROOT);
				myKey = new("/cmds/avatar/guard_key");
				fname = explode(files[x], ".o")[0];
				myKey->restore_key("/d/avatars/"+avTarg+"/keys/"+fname);
				myKey->move(TP);
				seteuid(geteuid());
				continue;
			}
			tell_object(TP, "Key restoration complete.");
			return 1;
		}
	}
	return 1;
}
