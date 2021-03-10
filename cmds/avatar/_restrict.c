//Changed by ~Circe~ 6/13/07 to allow for use with psionics
// /cmds/avatar/_restrict.c
// restricts a player from using cleric and mage spells
// either by spell name or by spell level
#include <std.h>
#define TS_D "/daemon/treesave_d.c"
inherit DAEMON;

int help();

int cmd_restrict(string str){
   string name, type, spell, spellfile;
   int level;
   int res_level;
   string *res_spells;
   object who;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice") {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   spell = "";
   level = -1;
   if(!str) return help();
   if((sscanf(str,"%s %s %s",name,type,spell)!=3) && (sscanf(str,"%s %s %d",name,type,level)!=3)) return help();
   sscanf(str,"%s %s %d",name,type,level);
   if(!who = find_player(name)) return notify_fail("Cannot find "+name+" to restrict.\n");
   if(!who->is_class(type)) return notify_fail(capitalize(name)+" cannot cast spells as a "+type+".\n");
   if(level > -1){
      if(type == "mage" || type == "cleric" || type == "psion" || type == "druid" || type == "sorcerer"){
         if(level > 9) return notify_fail("The highest "+type+" spell level is 9.\n");
      }
      if(type == "bard"){
         if(level > 6) return notify_fail("The highest "+type+" spell level is 6.\n");
      }
      if(type == "ranger" || type == "paladin"){
         if(level > 4) return notify_fail("The highest "+type+" spell level is 4.\n");
      }
      res_level = who->query_spell_level_restricted(type);

      if(res_level && level >= res_level)
         return notify_fail(capitalize(name)+" is already restricted to level "+res_level+" or below for "+type+" spells. <unrestrict> first if you want to raise the limit.\n");
      who->set_spell_level_restricted(type,level);
      TS_D->add_value_to_array("notes",who->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+type+" spells restricted to "+level+" or lower.");
      tell_object(TP,capitalize(name)+" is now restricted to preparing spells below level "+level+".");
      return 1;
   }
   else{
      spellfile = replace_string(spell," ","_");
      if(!file_exists("/cmds/spell/"+spell[0..0]+"/_"+spellfile+".c"))
         return notify_fail("No spell named "+spell+" exists.\n");
      else{
         who->restrict_spell(type,spell);
         TS_D->add_value_to_array("notes",who->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+type+" spell "+spell+" restricted");
         tell_object(TP,capitalize(name)+" is now restricted from preparing the "+type+" spell "+spell+".");
      }
   }
   return 1;
}


int help(){
   write(
@HELP
Syntax:    restrict <player> <class> <spellname>
        or restrict <player> <class> <level>

This command will restrict the player from using certain spells.
If a spell name is given, the player will not be able to pray for or
memorize that particular spell. (They will still be able to cast 
any that are in memory already.) If a spell level is given, the
player will not be able to pray for or memorize any spells that are
at or above that level. Remember that sorcerers/bards do not prepare 
specific spells, so they can only be restricted effectively by level.

EX. <restrict fred cleric 5> means that fred can only pray for spells
        that are below level 5 (levels 1-4 only).
    <restrict fred mage finger of death> means that fred can not memorize
        the spell finger of death

HELP
   );
   return 1;
}
