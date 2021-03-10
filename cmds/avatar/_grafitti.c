/* 
Grafitti command to make changes to long, short, day long, night long....


*/

#include <std.h>
#include <daemons.h>

#define TEMPFILE "/tmp/grafitti/"+TPQN

inherit DAEMON;

void help( );

void check_state(object targ) {
  if (!objectp(targ))
    return notify_fail("Not a good environment!\n");
  if (targ->query_storage())
    write("Warning! Room saves, so room will probably always save grafitti!");
  return 1;

}

int cmd_grafitti(string str) {
  string cmd, what1, what2, text, old_shit;
    int num;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!check_state(ETP))
      return 0;

    if(!str) {
      help();
      return 1;
    }
    
    if(str == "save"){
      // Save here.
      ETP->save_grafitti();
      write("Saved. Further updates will be saved.");
      return 1;
    }
    if (str == "nosave") {
      ETP->nosave_grafitti();
      write("Saving removed and file will revert on room unloading");
      return 1;
    }
    if(str == "clean") {
      ETP->clean_grafitti();
      write("Room cleaned up. Saves removed.");
      return 1;
    }
    if(sscanf(str, "%s %s", cmd, text) != 2) {
      help();
      return notify_fail("Incorrect syntax.\n");
    }
    if((sscanf(text, "%s %s", what1, what2) != 2)
       && (sscanf(text,"%s",what1) != 1)) {
      help();
      return notify_fail("Incorrect Syntax.\n");
    }
    switch(what1) {
    case "night_long":
    case "day_long":
      what1=replace_string(what1,"_"," ");
      break;
    case "short":
    case "long":
      break;
    default:
      return notify_fail("Bad change: "+what1+".\n");
      break;
    }

    switch(cmd){
    case "set":
      ETP->set_grafitti(what1, what2);
      break;	
    case "edit":
      ETP->set("_nograph",1);
    case "reedit":
    rm(TEMPFILE);
      switch(what1) {
      case "long":
	old_shit=ETP->query_long();
	break;
      case "short":
	old_shit=ETP->query_short();
	break;
      case "night long":
      if(!ETP->query("night long"))
          old_shit=ETP->query_long();
      else
	old_shit=ETP->query("night long");
	break;
      case "day long":
      if(!ETP->query("day long"))
          old_shit=ETP->query_long();
      else
	old_shit=ETP->query("day long");
	break;
      }
      ETP->delete("_nograph");
      // Not sure how to throw someone into an editor here.
   write_file(TEMPFILE,old_shit);
      TP->edit(TEMPFILE,"fileset_grafitti", find_object_or_load(GRAFITTI_D), what1);
      return 1;;
      break;
    case "clear":
    case "remove":
      ETP->remove_grafitti(what1);
      break;
    default:
      return notify_fail("Bad command: "+cmd+".\n");

    }
return 1;


}

void help(){
write(
@HELP
Syntaxes:
<grafitti> gives you this help (and information about the room, sometimes)

grafitti save: Makes the room's grafitti save.
grafitti nosave: Removes the saved data. Room reverts on unload/cleanup/ At
  most a boot away.

grafitti clean: Reverts the room and removes saved information.

grafitti set <what> <new...>: Redoes <what> to be <new......>
grafitti edit <what>: Throws you into an editor/buffer to edit the
    room, using the original description.
grafitti reedit <what>: Throws you into an editor/buffer to edit the
    room, using the modified description.
grafitti remove <what>: Resets <what> back to original room stuff.
grafitti clear <what>   Also resets <what>.


HELP
);

write (@HELP2
What can be:
  short: room short description. Seen in brief movement.
  night_long: long description seen at night.
  day_long: long description seen during the day.
  long: long description seen if night_long or day_long aren't set.

HELP2
);
}
