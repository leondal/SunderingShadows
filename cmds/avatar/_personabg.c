#include <std.h>
#include <objects.h>

inherit DAEMON;

int cmd_personabg(string str){
    object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!avatarp(TP)) return 0;
    if((string)TP->query_name() == (string)TP->query_vis_name()) return notify_fail("You MUST be using a persona.\n");
    ob = new("/cmds/avatar/perbackobj");
    ob->move(this_player());
    return 1;
}

void help() {
    write("Allows you to change or set the background OF YOUR CURRENT PERSONA.  Do NOT use this command if not in a persona.");
}
