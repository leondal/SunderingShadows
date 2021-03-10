#include <std.h>
#include <daemons.h>
#include <move.h>
#include "/daemon/nwps_d.h"

inherit DAEMON;
int help(){
    write(
@SAIDE
Usage:  makescroll <type> <spell>

This will make a scroll of <type> and <spell> you specify.
Valid arguments for type are "safe" or "normal", 

Safe scrolls will not crumble/explode BUT they cannot
be transcribed.  Safe scrolls are IG for newbies 
ONLY.

Normal scrolls WILL crumble/explode and can be 
transcribed.

SAIDE
    );
    return 1;
} 

int cmd_makescroll(string str){
  object ob,testspell;
  string spell, type, cspell;
  if (!str) {
   help();
   return 1;
  }
  if(sscanf(str,"%s %s",type, spell) == 2) {
    if(type == "safe") { 
      ob = new("/d/magic/safe_scroll");
    }
    if(type == "normal") {
      ob = new("/d/magic/scroll");
    }

    if(!objectp(ob)) {
      tell_object(TP,"%^RED%^ERROR%^RESET%^:  Valid types are "+
      "%^CYAN%^<safe>%^RESET%^ or %^RED%^<normal>%^RESET%^");
      return 1;
    }
//Updated to draw from the correct directories. Was still pulling from /cmds/wizard ~Circe~ 3/24/16
    cspell = lower_case(spell);
    cspell = replace_string(cspell," ","_");
    cspell = "/cmds/spells/"+cspell[0..0]+"/_"+cspell;
    if(!file_exists(cspell+".c")) {
      tell_object(TP,"%^RED%^ERROR%^RESET%^: "+spell+
      " is not a valid mage spell.");
      ob->remove();
      return 1;
    }
      testspell = new(cspell+".c");
      if(!testspell->query_spell_level("mage")){
         tell_object(TP,"That is not a valid mage spell!");
         return 1;
      }
   
    ob->set_spell_name(spell);
    if(ob->move(TP) != MOVE_OK) {
      tell_object(TP,"%^RED%^ERROR%^RESET%^:  Moving "+type+
      " scroll of "+spell+" to room instead.");
      ob->move(ETP);
      return 1;
    }
      tell_object(TP,"You have created a "+type+ 
      " scroll of "+spell);
      return 1;
 }
  help();
  return 1;
}


