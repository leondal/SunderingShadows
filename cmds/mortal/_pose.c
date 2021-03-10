/* added ability to pose a stance added to adjectives for RP purposes *Styx* 2/15/03
   added the ability to pose while bound for RP purposes ~Circe~ 10/3/03
*/
//added a check for invisibility before the pose tells the room -Tsera 11/1/04
#include <std.h>
#include <daemons.h>
#define CLASSES ({ "thief", "mage", "fighter", "cleric", "paladin", "antipaladin", "cavalier", "ranger", "bard", "assassin", "druid", "psion" })
#define MAXSTR 80


inherit DAEMON;

int cmd_pose(string str) {
    string myclass, oldclass,*tmp,*classes=({});
   int i;
/*   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
Taken out to allow posing while bound for RP ~Circe~ 10/3/03
*/
   if (!str) {
       if (TP->query_property("posed")) {
           write("Your pose is: " + TP->query_property("posed"));
           return 1;
       }
       return notify_fail("You need to specify how you want to pose.\n");
   }
   if (sizeof(TP->query_attackers())) {
      return notify_fail("You're too busy right now.\n");
   }

   tmp = get_dir(DIR_CLASSES+"/");
   for(i=0;i<sizeof(tmp);i++)
   {
       classes += ({ replace_string(tmp[i],".c","") });
   }
   classes += CLASSES;

   if(member_array(str, classes) != -1) {
	myclass = str;
	if(!TP->is_class(myclass))
	    return notify_fail("You cannot pose as that myclass.\n");
	oldclass = TP->query_class();
	if(oldclass == myclass)
	    return notify_fail("You are already posing as a "+myclass+"!\n");
	TP->set_posed(myclass);
	TP->setenv("TITLE",(string)ADVANCE_D->get_new_title(TP));
  	tell_object(TP,"You are now posing as a "+myclass+"!");
	tell_object(TP,"If you meant to set a pose for your adjective, don't use a class name name");
  	return 1;
   }
   if(str == "clear") {
    tell_object(TP,"Clearing pose.");//added to give the user some feedback when they clear the pose -Ares 1/3/06
	TP->remove_property("posed");
	return 1;
   }
   if(str == "show") {
// changed message for when there is no pose, which gave "...set as [0]" *Styx* 11/26/03
        if(!TP->query_property("posed")) {
	    write("You do not have a pose set.");
	    return 1;
        }
	write("Your pose is currently set as ["+TP->query_property("posed")+"].");
	return 1;
   }
   if(strlen(str) > MAXSTR)
	return notify_fail("Please be more brief, less than "+MAXSTR+" characters.  Note:  You don't have to add RESET at the end even if you use colors.\n");
   if(!TP->query_invis()){
   tell_room(ETP, "["+TPQCN+" poses "+str+"].", TP);
   }
   TP->remove_property("posed");
   TP->set_property("posed", str);
   write("Your pose is now set as ["+str+"].");
   return 1;
}

int help() {
  write(
"
%^CYAN%^NAME%^RESET%^

pose - change a pose, active class

%^CYAN%^SYNOPSIS%^RESET%^

pose %^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^
pose clear|show
pose %^ORANGE%^%^ULINE%^CLASS%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command governs two features:

First, ability to convey your relative position in the room you are in, your stance or current activity. E.g. you can set pose to 'sitting at a table', 'brewing potions', or 'loitering'. To set such pose use %^ORANGE%^<pose %^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^%^ORANGE%^>%^RESET%^ command, to clean it use %^ORANGE%^<pose clear>%^RESET%^, and to show your current pose just type %^ORANGE%^<pose>%^RESET%^ or %^ORANGE%^<pose show>%^RESET%^.

Second feature governs multiclassing, as multiclassing characters sometimes need to specify their current class, e.g. for %^ORANGE%^<master>%^RESET%^ command. To do so you can use %^ORANGE%^<pose %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

emote, emoteat, say, souls, classes, master
");

}
