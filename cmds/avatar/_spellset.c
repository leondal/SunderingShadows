#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help();

int cmd_spellset(string str)
{
	string type, spell, file, nspell;
   	int number;
   	object ob;

   	if (!str) return help();
   	if (sscanf (str, "%s %d %s",type, number, spell) != 3) return help();

   	file = replace_string(spell, " ","_");
   	file = "/cmds/spells/"+file[0..0]+"/_"+file+".c";
   	if (!file_exists(file)) 
	{
		return notify_fail("That spell does not seem to exist.");
	}
   	ob = new(file);
   	if(!ob->query_spell_level(type)) 
	{
		return notify_fail("That spell and class are not compatible.");
	}
	ob->remove();
	//spontanous caster support - Saide
   	if(type == "bard" || type == "sorcerer")
	{
		nspell = "level "+ MAGIC_D->query_spell_level(type, spell);
		tell_object(TP, "Converting "+spell+" to '"+nspell+ 
		"' to support spontaneous casting.  Your mind now has "+
		number+" copies of any "+nspell+" "+type+" floating "+
		"around in it.");
		TP->set_memorized(type, nspell, number);
		return 1;
	}
	else
	{
   		TP->set_memorized(type, spell, number);
   		message("info","Your mind now has "+number+
		" copies of the "+type+" variant of "+spell+" floating around in it.",TP);
	}
   return 1;
}

int help(){

   write(
@OLI
   spellset
   Usage:   spellset <class> <amount> <spell name>

   This will set the spells in your memory. Please use within reason.
OLI
      );
   return 1;
}