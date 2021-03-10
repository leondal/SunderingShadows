//wemote.c
//checkpoint to notes file added by *Styx*  8/2002

#include <std.h>

inherit DAEMON;

int cmd_wemote(string str){
   string who, action, reason;
   object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   if(!str || str == ""){
      return notify_fail("wemote <add | remove> <who> <reason>\n");
   }

   if(sscanf(str,"%s %s %s", action, who, reason) != 3){

      return notify_fail("wemote <add | remove> <who> <reason>\n"
        "This will make a checkpoint note with the reason given.");
   }

   if(!(ob = find_player(who))){
      return notify_fail("That player is not online or else you put the "
         "name in the wrong spot.\n"
         "Proper syntax is - wemote <add | remove> <who> <reason>\n");
   }

   if(action == "remove"){
      ob->set("emote loss",1);
      tell_object(ob,"You have lost the right to use your emotes.");
      tell_object(TP,"You have taken "+capitalize(who)+"'s right to use emotes.");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" %^BOLD%^%^RED%^"
          "emotes were removed%^RESET%^ for reason:  "+reason+".");
      return 1;
   }
   if(action == "add"){
      ob->set("emote loss",0);
      tell_object(ob,"You have regained the right to use your emotes.");
      tell_object(TP,"You have returned "+capitalize(who)+"'s right to use emotes.");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" %^BOLD%^%^RED%^"
          "emotes were restored%^RESET%^ for reason:  "+reason+".");
      return 1;
   }

   return notify_fail("You must specify to remove or add the emote ability.");
}

void help(){
write(
"wemote add <name> <reason> returns emotes.\n"
"wemote remove <name> <reason> takes away emotes.\n"
"<reason> is logged to their notes file in a checkpoint\n"

);
}
