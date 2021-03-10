//checkpoint to notes file added by *Styx*  8/2002

#include <std.h>
#include <security.h>
#include <dieties.h>

#define NORM_CHANNELS ({"cleric","fighter","ranger","mage","paladin", "antipaladin","thief", "bard","assassin","druid","cavalier", "hm", "newbie", "inform", "shout"})

inherit DAEMON;

int cmd_channel(string str) {

	object ob;
	string opt, who, channel, reason;
   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   
   // Letting builders and apprentices create a line to talk with their testers
   
	if(!wizardp(TP))  return 0;
	if(!str) return 0;

	if(sscanf(str, "%s %s %s %s",opt,who,channel,reason) !=4) 
          return notify_fail("Syntax: <channel [add|remove] [player] [channel] [reason]>\n");


   if(posxxx == "builder" || posxxx == "apprentice")
   {
	   object *imms=({});
	   int i;

	   imms = children("/std/user.c");
	   if(sizeof(imms))
	   {
		   for(i=0;i<sizeof(imms);i++)
		   {
			   if(!objectp(imms[i])) { continue; }
			   if(!wizardp(imms[i])) { continue; }
			   if(imms[i] == TP) { continue; }

			   if(opt == "remove")
			   {
					tell_object(imms[i],"%^B_BLUE%^%^WHITE%^"+capitalize(TP->query_true_name())+" "
						"removes "+who+" from the "+channel+" line.");
			   }
			   else
			   {
					tell_object(imms[i],"%^B_BLUE%^%^WHITE%^"+capitalize(TP->query_true_name())+" "
						"adds "+who+" to the "+channel+" line.");
			   }
		   }

		   if(opt == "remove")
		   {
			   tell_object(TP,"%^BOLD%^%^WHITE%^You remove "+who+" from the "+channel+" line.");
		   }
		   else
		   {
			   tell_object(TP,"%^B_BLUE%^%^WHITE%^You add "+who+" to the "+channel+" line.");
		   }
	   }
   }

	//if((string)TP->query_position() == "builder" || (string)TP->query_position() == "apprentice")
	//   return notify_fail("Sorry, you don't have access to add or restrict channels.\n");

	seteuid(UID_LOG);
	
     write_file("/log/channels",TPQN+" "+str+" "+ctime(time())+"\n");
     if(!(ob = find_player(who = lower_case(who))))
	return notify_fail("Either that player is not online or you have the name "
    	   "in the wrong order.\n");
     if(opt == "remove") {
	ob->restrict_channel(channel);
	message("system", sprintf("You restrict %s from the %s line.",capitalize(who),channel), TP);
	message("system", sprintf("You have lost your %s line.",channel),ob);
	if( (member_array(channel, NORM_CHANNELS) != -1) || (member_array(channel, keys(DIETIES)) != -1) ) {
          "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" %^BOLD%^%^RED%^"
             +channel+" line was removed%^RESET%^ for reason:  "+reason+".");
        }
	return 1;
     }
     else if(opt == "add") {
	ob->unrestrict_channel(channel);
	message("system", sprintf("You can now use the %s line.",channel),ob);
	message("system", sprintf("You allow %s to use the %s line.", capitalize(who),channel),TP);
	if( (member_array(channel, NORM_CHANNELS) != -1) || (member_array(channel, keys(DIETIES)) != -1) ) {
          "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" %^BOLD%^%^RED%^"
            +channel+" line was added/restored %^RESET%^ for reason:  "+reason+".");
        }
	return 1;
     }
     else return 0;
}

void help() 
{
  write(
    "Syntax: <channel [add|remove] [player] [channel] [reason]>\n\n"
    "Used to add and remove lines from players.\n"
    "The reason will be included in a checkpoint note on the player.\n"
    "see also:  channels\n\n"
	"Builders and Apprentices should get permission before they use \n"
	"this command to create a new channel."
  );
}
