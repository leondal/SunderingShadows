/* by Styx - 3/31/02 for Shadow, converting to a /std/ inheritable 08/2005
* features - some are on the jail guard (attacking on picking or
*    unlocking as well as code for accepting a prisoner)
* - this room removes a prisoner's name from the array on them entering the main room
*  fines/bounties get removed (via user.c per Ares/Grendel) if a city guard kills them
*/

/* ****** notes to be zapped later when finished **************
>> move the wanted list from the Shadow guard file and Tonovi to SAVE_D ? <<<<<
>> let them collect fines too?
>> need to check the remove name function for jailers that are & aren't hms

recognize by number
add aliases by number
list of reasons for bounties & fines
let avatars or immortals get a log by area by type of event (to confirm bounties, etc.)

finish jailers and others putting people in jail and paying bounties, etc.

add alias of testflunkytestaliases for testflunky wanted (should have been wanted testflunky)
   didn't work but no error message

list wanted gets a message of no bounties in that location, don't need ?
>>*******************  end of the notes to be zapped ***************** */

#include <std.h>
#include <daemons.h>

#define MAXBOUNTY 50000000

inherit VAULT;

void set_jail_location(string loc);  	// generally city
void set_cell(string filename);		// for the cell file

int __DoJail(string str);
int __ToCell(object jailwho, object jailby, string alias);
int __DoLists(string str);
int check_released(object who, string where, object here);
int __Pardon(string str);
int __RemoveName(string str);
int __PayFine(string str);
int __Clean(string str);
int __Help(string str);
int __AddLoc(string str);

string JailLoc, CellFile;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no teleport",1);
   set_property("no phase",1);  // to keep the psion phase from letting them bypass the door
   set_indoors(1);
   set_property("no sticks",1);
   set_name("Inheritable jail");
   set_short("The inheritable jail office");
   set_long("This is the inherit for the jail system - no one should be in here." );
   set_listen("default","You can hear rats scurrying around and prisoners shuffling about.");
   set_smell("default","The stench of unwashed bodies emanates from the cells.");
}

void init() {
   ::init();
   add_action("__Help", "help");
   add_action("__DoLists", "list");
   add_action("__Pardon", "pardon");
   add_action("__AddName","add");
   add_action("__DoJail", "jail");
   add_action("__PayFine", "pay");
   if(userp(TP))
      check_released(TP, JailLoc, TO);
   if(wizardp(TP)) {
      add_action("__Clean", "clean");
      add_action("__AddLoc", "addnew");
   }
}

void set_jail_location(string loc) { JailLoc = loc; }
void set_cell(string filename) { CellFile = filename; }

int query_jail_location() {  return JailLoc; }
int query_cell() {  return CellFile; }

int __DoJail(string str) {
   int i, count;
   string *jailers, who;
   object jailwho, jailer;
   object *here = ({});
   if(!str) return notify_fail("Jail whom?\n");
   if((who = (string)TP->realName(str)) == "")
  	return notify_fail("You don't seem to know anyone named "
	   +capitalize(str)+".\n");
   if(!jailwho = present(capitalize(str), TO))
  	return notify_fail(capitalize(str)+" doesn't seem to be here.\n");
   if(!jailwho->query_bound() && !jailwho->query_unconscious())
       return notify_fail("You have to have them bound or "
         "unconscious to be jailed.\n");
   if(!present("jailer")) {
      here = all_inventory(TO);
      count = sizeof(here);
      jailers = AREALISTS_D->query_jailer_names(JailLoc);
      if(sizeof(jailers) > 0) {
        for(i=0; i<count; i++) {
	  if(!living(here[i]))
	    continue;
	  if(here[i]->query_true_invis())
	    continue;
	  if(member_array(here[i]->query_name(), jailers) != -1) {
	    jailer = here[i];
	    break;
	  }
        }
      }
      if(!objectp(jailer))
	return notify_fail("There must be a jailer or authorized official present "
	   "to put a prisoner into a cell.\n");
   }
   __ToCell(jailwho, TP, str);
   return 1;
}

// This is separate so the guards can use it.
int __ToCell(object jailwho, object jailby, string alias) {
   object Jailer;
   int bounty;
   if(jailwho->query_property("draggee")) {
	write("You need to drop the prisoner to jail them.\n");
	return 1;
   }
   jailwho->move(CellFile);
   jailwho->set("jailed_age",(int)jailwho->query_age());
   jailwho->set("jailed_time", time());
   if(jailby->is_player()) {
	AREALISTS_D->add_prisoner(alias,JailLoc,jailby);
   } else {
	AREALISTS_D->add_prisoner(jailwho,JailLoc,jailby);
   }
   bounty = AREALISTS_D->query_bounty_amount(jailwho,JailLoc,TO);
   if(bounty && userp(jailby)) {
	log_file("player/city_jails", "Bounties - "+JailLoc+":  "+jailby->QCN+" was paid a "
	   +bounty+" bounty for "+jailwho->QCN+" on "+ctime(time())+".\n");
   	jailby->add_money("gold", bounty);
   	jailby->force_me("save");
    	tell_room(TO,"The jailer hands a pouch full of gold to "+jailby->QCN+
	   " with a smirk.",jailby);
	tell_object(jailby,"The jailer slips you a pouch full of "+bounty+
	   " gold with a smirk.");
   }
   AREALISTS_D->remove_bounty(jailwho, JailLoc, TO);
   log_file("player/city_jails", "Prisoners - "+JailLoc+":  "+jailwho->QCN+
	" was put into jail on "+ctime(time())+".\n");
   "/cmds/avatar/_note.c"->cmd_note("ckpt "+jailwho->query_name()+
	" was put into the %^RED%^"+JailLoc+" jail.");
   if(Jailer = present("jailer")) {
	Jailer->__Jail(jailwho);
        return 1;
   } else {
      tell_room(TO,jailby->QCN+" peers through the grating in the door "
      	"and pulls a lever.  You hear something click inside the cell as "
	+jailby->QS+" quickly shoves "+jailwho->QCN+" inside.", ({jailby, jailwho}));
      tell_room(CellFile,jailby->QCN+" peers through the grating in the door "
      	"and pulls a lever.  You hear something click inside the cell as "
	+jailby->QS+" quickly shoves "+jailwho->QCN+" inside.", ({jailby, jailwho}));
      tell_object(jailwho,jailby->QCN+" peers through the grating in the door "
       "and pulls a lever.  You hear something click inside the cell "
       "before the door opens and you are quickly shoved inside.\n");
      tell_object(jailby, "You peer through the grating in the door "
      	"and pull a lever.  You hear something click inside the cell and "
	"quickly shove "+jailwho->QCN+" inside when the door opens.");
      tell_room(TO,"%^ORANGE%^The cell door shuts quickly with an ominous thud.");
      tell_room(CellFile,"%^ORANGE%^The cell door shuts quickly with an ominous thud.");
      jailwho->force_me("look");
   }
   return 1;
}

int __PayFine(string str) {
   int fine;

   if(!str || str != "fine")
      return notify_fail("Try <pay fine>.\n");
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!fine = AREALISTS_D->query_fine_amount(TP, JailLoc, TO))
      return notify_fail("You apparently do not have a fine here.\n");
   if(fine < 0)
      return notify_fail("The fine seems to be negative, please contact a wiz.\n");
   if((int)TP->query_gold_equiv() < fine) {
      write("You need "+fine+" gold to pay your fine.");
      tell_room(TO, TPQCN+" seems to be fishing through "+TPQP+" pockets for "
	"money and checks the list of fines again.", TP);
      return 1;
   }

   TP->add_money("gold", -fine);
   TP->force_me("save");
   AREALISTS_D->remove_fine(TP, JailLoc, TO);
   log_file("player/city_jails", "Fines - "+JailLoc+":  "+TP->query_true_name()+" paid "
	"a fine of "+fine+" on "+ctime(time())+".\n");
   write("You slip the pouch full of "+fine+" gold coins successfully into "
	"the proper slot and hear the jingle as they are counted and "
	"recorded.");
   tell_room(ETP,TPQCN+" slips a pouch full of coins into a slot and you "
	"hear them clink and jingle as they are counted and put away.",TP);
   return 1;
}

int __Pardon(string str) {
   string *jailers, *wanted;
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   if(!avatarp(TP) && member_array(TPQN,jailers) == -1)
	return notify_fail("Sorry but you apparently aren't authorized.\n");
   if(!str)
	return notify_fail("Pardon who?\n");
   str = lower_case(str);
   AREALISTS_D->remove_wanted(str, JailLoc, TP);
   tell_object(TP,"Please do <list wanted> to confirm you were successful.");
   log_file("player/city_jails", "Pardon - "+JailLoc+":  "+TP->query_true_name()+" pardoned "
	+capitalize(str)+" from the wanted list on "+ctime(time())+".\n");
   return 1;
}

int __RemoveName(string str) {
   string *jailers, syntax_msg, name, list, realname;
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   syntax_msg = "Please try <list remove [name] from [jailers|prisoners"
	"|wanted|bounties|fines|banned] >";
   if(!avatarp(TP) && member_array(TPQN,jailers) == -1)
	return notify_fail("Sorry but you apparently aren't authorized.\n");
   if(!str)
      return notify_fail("Please specify a name to remove.\n");
   str = lower_case(str);
   if(sscanf(str, "%s from %s", name, list) != 2) {
	write(syntax_msg);
	return 0;
   }
   realname = (string)TP->realName(name);
   if(!avatarp(TP) && realname == "")
      return notify_fail("Sorry, but you apparently don't know "
	   "anyone named "+capitalize(name)+".\n");
   if(realname == "")  realname = str;
   switch(list) {
      case "jailers" :
	if(member_array(name,jailers) == -1) {
	   write( capitalize(name)+" isn't an authorized "
		+JailLoc+" jailer to be removed.\n");
	   return 0;
        }
	AREALISTS_D->remove_jailer(name, JailLoc, TP);
	tell_object(TP, capitalize(name)+" is no longer an authorized "
		"jailer for "+JailLoc+".");
   	"/cmds/avatar/_note.c"->cmd_note("add "+realname+" was %^BOLD%^removed "
         	"from the list of jailers for the "+JailLoc+" jail.%^RESET%^");
	log_file("player/city_jails", "Jailers - "+JailLoc+":  "+TP->query_true_name()+" removed "
		+capitalize(realname)+" from the jailers list on "+ctime(time())+".\n");
        break;
      case "prisoners" :
	AREALISTS_D->remove_prisoner(name, JailLoc, TP);
   	log_file("player/city_jails", "Prisoners - "+JailLoc+":  "+TP->query_true_name()+" removed "
	    +capitalize(name)+" from the prisoners list on "+ctime(time())+".\n");
	write("You have removed "+capitalize(name)+" from the "+JailLoc+
	    " prisoners list.");
	break;
      case "wanted" :
	AREALISTS_D->remove_wanted(name, JailLoc, TP);
   	log_file("player/city_jails", "Wanted - "+JailLoc+":  "+TP->query_true_name()+" removed "
	    +capitalize(name)+" from the wanted list on "+ctime(time())+".\n");
	write("You have removed "+capitalize(name)+" from the "+JailLoc+" wanted list.");
	write("Please do <list wanted> to confirm you were successful.");
	break;
      case "banned" :
	AREALISTS_D->remove_banned(name, JailLoc, TP);
   	log_file("player/city_jails", "Banned - "+JailLoc+":  "+TP->query_true_name()+" removed "
	    +capitalize(name)+" from the banned list on "+ctime(time())+".\n");
	write("You have removed "+capitalize(name)+" from the "+JailLoc+" banned list.");
	write("Please do <list banned> to confirm you were successful.");
	break;
      case "fines" :
	AREALISTS_D->remove_fine(name, JailLoc, TP);
   	log_file("player/city_jails", "Fines - "+JailLoc+":  "+TP->query_true_name()+" removed the "
	    "fine on "+capitalize(name)+" on "+ctime(time())+".\n");
	write("Please do <list fines> to confirm you were successful.");
	break;
      case "bounties" :
	AREALISTS_D->remove_bounty(name, JailLoc, TP);
   	log_file("player/city_jails", "Bounties - "+JailLoc+":  "+TP->query_true_name()+" removed the "
	    "bounty on "+capitalize(name)+" on "+ctime(time())+".\n");
	write("You have removed the bounty for "+capitalize(name)+" in "+JailLoc+".");
	write("Please do <list wanted> to confirm you were successful.");
	break;
      default:
	write(syntax_msg);
   }
   return 1;
}

int check_released(object who, string where, object here) {
   if(AREALISTS_D->is_prisoner(who, where, here)) {
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+
          " is %^RED%^out of the "+JailLoc+" jail.%^RESET%^");
      AREALISTS_D->remove_prisoner(who, where, here);
      log_file("player/city_jails", "Prisoners - "+JailLoc+":  "+who->QCN+" is "
	"out of the "+JailLoc+" jail on "+ctime(time())+".\n");
      return 1;
   }
   return 0;
}

int __AddName(string str) {
   string *jailers = ({});
   string name, which, newalias, type, syntax_msg, realname;
   int amount, currBounty;
   syntax_msg = "Try < add [name] to [jailers|wanted] >,\n"
	"    < add [fine|bounty] of [amount] for [name] >,\n"
	"or  < add alias of [aliasname] for [prisoner|wanted|jailers|banned] [name] >\n";
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   if(!str)
      return notify_fail(syntax_msg);

   if(sscanf(str, "%s to %s", name, which) != 2  &&
     sscanf(str, "%s of %d for %s", which, amount, name) != 3 &&
     sscanf(str, "alias of %s for %s %s", newalias, type, name) != 3 )
        return notify_fail(syntax_msg);

   name = lower_case(name);
   if(!avatarp(TP) && (string)TP->realName(name) == "")
      return notify_fail("Sorry, but you apparently don't know "
		"anyone named "+capitalize(name)+".\n");
   if(!avatarp(TP) && !AREALISTS_D->is_jailer(TP, JailLoc, TO)) {
      if(which != "alias")
	return notify_fail("Sorry but you apparently aren't authorized.\n");
   }
   switch(which) {
      case "alias" :
	if(type == "wanted")
	   AREALISTS_D->add_wanted_alias(name, newalias, JailLoc, TP);
	if(type == "prisoner")
	   AREALISTS_D->add_prisoner_alias(name, newalias, JailLoc, TP);
	if(type == "fine")
	   AREALISTS_D->add_fine_alias(name, newalias, JailLoc, TP);
	if(type == "bounty")
	   AREALISTS_D->add_bounty_alias(name, newalias, JailLoc, TP);
	if(type == "jailers")
	   AREALISTS_D->add_jailer_alias(name, newalias, JailLoc, TP);
	if(type == "banned")
	   AREALISTS_D->add_banned_alias(name, newalias, JailLoc, TP);
   	log_file("player/city_jails", "Aliases - "+JailLoc+":  "+TP->query_true_name()+" added "
	    +capitalize(newalias)+" for the "+type+" alias list for "
	    +capitalize(name)+" on "+ctime(time())+".\n");
	break;
      case "jailers" :
        if(AREALISTS_D->is_jailer(name, JailLoc, TP))
          return notify_fail("You don't need to add them, they were "
		"already authorized.\n");
        AREALISTS_D->add_jailer(name, JailLoc, TP);
	realname = (string)TP->realName(name);
        tell_object(TP,"You have added "+name+" to be an authorized jailer "
	    "for the "+JailLoc+" jail.");
        if(realname == "")  realname = name;  // fix for not having them recognized
        "/cmds/avatar/_note.c"->cmd_note("add "+realname+" was added to the "
            "%^BOLD%^the list of "+JailLoc+" jailers.");
   	log_file("player/city_jails", "Jailers - "+JailLoc+":  "+TP->query_true_name()+" added "
	    +capitalize(realname)+" as an authorized jailer on "+ctime(time())+".\n");
        break;
      case "wanted" :
	AREALISTS_D->add_wanted(name, JailLoc, TP);
   	log_file("player/city_jails", "Wanted - "+JailLoc+":  "+TP->query_true_name()+" added "
	    +capitalize(name)+" to the wanted list on "+ctime(time())+".\n");
	write("You have added "+capitalize(name)+" to the "+JailLoc+" wanted list.");
        break;
      case "banned" :
	AREALISTS_D->add_banned(name, JailLoc, TP);
   	log_file("player/city_jails", "Banned - "+JailLoc+":  "+TP->query_true_name()+" added "
	    +capitalize(name)+" to the banned list on "+ctime(time())+".\n");
	write("You have added "+capitalize(name)+" to the "+JailLoc+" banned list.");
        break;
      case "fine" :
	AREALISTS_D->add_fine(name, JailLoc, amount, TP);
   	log_file("player/city_jails", "Fines - "+JailLoc+":  "+TP->query_true_name()+" added "
	    "a fine of "+amount+" for "+capitalize(name)+" on "+ctime(time())+".\n");
	break;
      case "bounty":
        currBounty = AREALISTS_D->query_bounty_amount(name,JailLoc,TO);
        if(amount < 0)
      	   return notify_fail("The amount must be positive.\n");
 	if((amount + currBounty) > MAXBOUNTY)
	   return notify_fail("Please limit bounties to "+MAXBOUNTY+".\n");
	if(!avatarp(TP)) {
          if((int)TP->query_gold_equiv() < amount)
		return notify_fail("You need "+amount+" gold to put up for the bounty.\n");
	   TP->add_money("gold", -amount);
	   TP->force_me("save");
	   log_file("player/city_jails", "Bounties - "+JailLoc+":  "+TP->query_true_name()+" funded a "
		"bounty of "+amount+" on "+capitalize(name)+" on "
		+ctime(time())+".\n");
   	   write("You slip the pouch full of "+amount+" gold coins into "
		"the proper slot and hear the jingle as they are counted and "
		"recorded.");
	   tell_room(TO,TPQCN+" slips a pouch full of coins into a slot and "
		"you hear them clink and jingle as they are counted and put "
		"away.",TP);
	}
        if(currBounty > 0)
	   write("You are adding the bounty of "+amount+" to the current bounty "
	      "of "+currBounty+" for a new total of "+(amount + currBounty)+".");
	AREALISTS_D->add_bounty(name, JailLoc, amount+currBounty, TP);
   	log_file("player/city_jails", "Bounties - "+JailLoc+":  "+TP->query_true_name()+" added "
	    "a bounty of "+amount+" for "+capitalize(name)+" on "+ctime(time())+".\n");
	break;
     default : write(syntax_msg);
   }
   return 1;
}

int __DoLists(string str) {
   int i,j, num, count, amount;
   string *jailers, *lnames, *akalist, displaylist, lookslike, remove;
   mapping fines;
   if(!str)
	return __Help("jail");
   if(sscanf(str, "remove %s", remove) != 0) {
	__RemoveName(remove);
	return 1;
   }
   switch(str) {
     case "prisoners":
	if(!sizeof(lnames = AREALISTS_D->query_prisoner_names(JailLoc)))
	   return notify_fail("There are currently no prisoners for "+JailLoc+"\n");
	write("%^BOLD%^The following alleged criminals have been detained "
        	"and are being held until further notice.");
	count = sizeof(lnames);

	write("%^BOLD%^%^BLUE%^Names known as and brief description");
	displaylist = "%^BOLD%^%^BLUE%^------------------------------------\n";
     	for(i=0; i<count; i++) {
	   akalist = AREALISTS_D->query_prisoner_aliases(lnames[i], JailLoc, TO);
	   displaylist += "%^YELLOW%^ "+(i+1)+".  Reported known as:  %^BLUE%^";
	   num = sizeof(akalist);
	   for(j=0; j<num; j++) {
	      if(j > 0)
		displaylist += ", "+capitalize(akalist[j]);
	      else displaylist += capitalize(akalist[j]);
	   }
	   if(avatarp(TP))
		displaylist+= "    %^RESET%^(Immortal eyes only) Real name:  "
		    +capitalize(lnames[i])+"\n";
	   lookslike = AREALISTS_D->query_prisoner_adjective(lnames[i], JailLoc, TO);
	   displaylist += "     %^YELLOW%^Described as:  %^RESET%^"+lookslike+"\n\n";
        if  (i % 5 == 0) { // Print out every 5 regardless... Buffer overflows otherwise.
              write(displaylist);
              displaylist="";
          }
	}
	write(displaylist);
	break;

     case "jailers":
	lnames = AREALISTS_D->query_jailer_names(JailLoc);
	if(!count = sizeof(lnames))
	   return notify_fail("There do not appear to be any authorized "
		"officials at present.\n");
	write("The authorized officials for the %^BOLD%^%^CYAN%^"+JailLoc+
		" jail include:%^RESET%^");

	write("%^BOLD%^%^BLUE%^Known as and brief description");
	displaylist = "%^BOLD%^%^BLUE%^------------------------------\n";
     	for(i=0; i<count; i++) {
	   akalist = AREALISTS_D->query_jailer_aliases(lnames[i], JailLoc, TO);
	   displaylist += "%^YELLOW%^ "+(i+1)+".  Known as:  %^BLUE%^";
	   num = sizeof(akalist);
	   for(j=0; j<num; j++) {
	      if(j > 0)
		displaylist += ", "+capitalize(akalist[j]);
	      else displaylist += capitalize(akalist[j]);
	   }
	   if(avatarp(TP))
		displaylist+= "    %^RESET%^(Immortal eyes only) Real name:  "
		    +capitalize(lnames[i])+"\n";
	   lookslike = AREALISTS_D->query_jailer_adjective(lnames[i], JailLoc, TO);
	   displaylist += "     %^YELLOW%^Described as:  %^RESET%^"+lookslike+"\n\n";
         if (i % 5 == 0) { // Print out every 5 regardless... Buffer overflows otherwise.
              write(displaylist);
              displaylist="";
          }
	}
	write(displaylist);
	break;
     case "wanted":
        displaylist = "%^BOLD%^%^BLUE%^Names known as and brief description\n"
		      "%^BOLD%^%^BLUE%^------------------------------------\n";
	if(!sizeof(lnames = AREALISTS_D->query_wanted_names(JailLoc)))
	   return notify_fail("There is currently no wanted list for "+JailLoc+"\n");
	write("%^BOLD%^The following wanted for crimes or questioning by "+JailLoc+
	   " officials.");
	count = sizeof(lnames);
     	for(i=0; i<count; i++) {
	   akalist = AREALISTS_D->query_wanted_aliases(lnames[i], JailLoc, TO);
	   displaylist += "\n%^YELLOW%^ "+(i+1)+".  Reported known as:  %^BLUE%^";
	   num = sizeof(akalist);
	   for(j=0; j<num; j++) {
	      if(j > 0)
		displaylist += ", "+capitalize(akalist[j]);
	      else displaylist += capitalize(akalist[j]);
	   }
	   if(avatarp(TP))
		displaylist+= "    %^RESET%^(Immortal eyes only) Real name:  "
		    +capitalize(lnames[i])+"\n";
	   lookslike = AREALISTS_D->query_wanted_adjective(lnames[i], JailLoc, TO);
	   displaylist += "     %^YELLOW%^Described as:  %^RESET%^"+lookslike+"\n";
	   if(amount = AREALISTS_D->query_bounty_amount(lnames[i],JailLoc,TO))
		displaylist += sprintf("%%^BOLD%%^%%^MAGENTA%%^%-15s %%^YELLOW%%^%10d",
	   	   "          Bounty:  ", amount )+" gold\n";
         if (i % 5 == 0) { // Print out every 5 regardless... Buffer overflows otherwise.
              write(displaylist);
              displaylist="";
          }
	}
	write(displaylist);
	break;
     case "fines" :
	if(!fines = AREALISTS_D->query_fines(JailLoc))
	   return notify_fail("There are currently no fines listed for "
		+JailLoc+"\n");
	lnames = keys(fines);
	displaylist = ("%^BOLD%^The following fines have been levied by "+JailLoc+
		" officials.\n");
        displaylist += ("%^BOLD%^%^BLUE%^Names known as and fine amount\n"
	                "%^BOLD%^%^BLUE%^------------------------------\n");
	count = sizeof(lnames);
     	for(i=0; i<count; i++) {
	   akalist = AREALISTS_D->query_fine_aliases(lnames[i], JailLoc, TO);
	   displaylist += "%^YELLOW%^ "+(i+1)+".  Reported known as:  %^BLUE%^";
	   num = sizeof(akalist);
	   for(j=0; j<num; j++) {
	      if(j > 0)
		displaylist += ", "+capitalize(akalist[j]);
	      else displaylist += capitalize(akalist[j]);
	   }
	   if(avatarp(TP))
		displaylist+= "    %^RESET%^(Immortal eyes only) Real name:  "
		    +capitalize(lnames[i])+"\n";
	   lookslike = AREALISTS_D->query_fine_adjective(lnames[i], JailLoc, TO);
	   displaylist += "\n     %^YELLOW%^Described as:  %^RESET%^"+lookslike+"\n";
	   if(amount = AREALISTS_D->query_fine_amount(lnames[i], JailLoc, TO))
		displaylist += sprintf("%%^BOLD%%^%%^MAGENTA%%^%-15s %%^YELLOW%%^%10d",
	   	   "          Fine:  ", amount )+" gold\n";
         if (i % 5 == 0) { // Print out every 5 regardless... Buffer overflows otherwise.
              write(displaylist);
              displaylist="";
          }
	}
	write(displaylist);
	break;
     case "banned":
	if(!sizeof(lnames = AREALISTS_D->query_banned_names(JailLoc)))
	   return notify_fail("There isn't currently anyone banned by "+JailLoc+"\n");
	write("%^BOLD%^The following have been banned from "+JailLoc+".");
	count = sizeof(lnames);

	write("%^BOLD%^%^BLUE%^Names known as and brief description");
	displaylist = "%^BOLD%^%^BLUE%^------------------------------------\n";
     	for(i=0; i<count; i++) {
	   akalist = AREALISTS_D->query_banned_aliases(lnames[i], JailLoc, TO);
	   displaylist += "%^YELLOW%^ "+(i+1)+".  Reported known as:  %^BLUE%^";
	   num = sizeof(akalist);
	   for(j=0; j<num; j++) {
	      if(j > 0)
		displaylist += ", "+capitalize(akalist[j]);
	      else displaylist += capitalize(akalist[j]);
	   }
	   if(avatarp(TP))
		displaylist+= "    %^RESET%^(Immortal eyes only) Real name:  "
		    +capitalize(lnames[i])+"\n";
	   lookslike = AREALISTS_D->query_banned_adjective(lnames[i], JailLoc, TO);
	   displaylist += "     %^YELLOW%^Described as:  %^RESET%^"+lookslike+"\n\n";
         if (i % 5 == 0) { // Print out every 5 regardless... Buffer overflows otherwise.
              write(displaylist);
              displaylist="";
          }
	}
	write(displaylist);
	break;

     default:
        write("Try <list [prisoners|jailers|wanted|fines|banned] >\n");
   }
   return 1;
}

int __Clean(string str) {
   if(!wizardp(TP))
	return 0;
   if(!str)
	return notify_fail("Clean which?\n");
   switch(str) {
      case "prisoners" :
	AREALISTS_D->clean_prisoners();		break;
      case "wanted" :
	AREALISTS_D->clean_wanted();		break;
      case "jailers" :
	AREALISTS_D->clean_jailers();		break;
      case "bounties" :
	AREALISTS_D->clean_bounties();		break;
      case "fines" :
	AREALISTS_D->clean_fines();		break;
       case "banned" :
	AREALISTS_D->clean_banned();		break;
     case "all" :
	write("Note:  this may cause noticeable lag!");
	AREALISTS_D->clean_criminals();
	break;
   }
   return 1;
}

int __AddLoc(string str) {
   if(!wizardp(TP))
	return 0;
   if(!str)
	return notify_fail("Please specify a location to add.\n");
   AREALISTS_D->add_valid_location(capitalize(str));
   return 1;
}


int __Help(string str) {
  if(str == "jail" || str == "commands" || str == "jail commands" || str == "shop") {
     write("%^CYAN%^Commands available (some restricted according to authorization) are:\n\n"
	"   < list [jailers|wanted|prisoners|fines|banned] >\n"
        "   < pay fine >\n"
	"   < add alias of [aliasname] for [prisoner|wanted|jailers|banned] [name] >\n"
	"   < jail [name] > if a jailer is present & the prisoner is bound\n\n"
	"%^BOLD%^%^BLUE%^Note about the <jail> ability:  %^RED%^<pkmail>%^BLUE%^"
	" is, of course, required if you have captured someone.  Please "
	"include mention that you jailed them and where.  If they were not "
	"already wanted, be specific about your reasons.  Also, be "
	"sure to log in as regularly as possible until they are released "
	"to follow through with the RP, including going to the jail and "
	"checking in, taunting, or whatever is appropriate RP for your "
	"character.\n  You also need to mud mail the listed officials with the "
	"IC reason you would have given the guard or them when you turned the "
	"person over to be jailed.\n"
     );
     if(avatarp(TP) || AREALISTS_D->is_jailer(TP, JailLoc, TO )) {
       write("%^BOLD%^Officials and immortals only:%^RESET%^%^CYAN%^\n"
	"   < list remove [name] from [jailers|wanted|prisoners|fines|banned] >\n"
	"(%^RESET%^Note:  If a wanted person is a prisoner, leave them on "
	"the wanted list until their jail time is up unless you want them "
	"to get released several hours earlier.  The timed release will "
	"remove them from the wanted list.)%^CYAN%^\n"
	"   < add [name] to [jailers|wanted|banned] >\n"
	"   < add [fine|bounty] of [amount] for [name] >\n"
	"   < request key > if the jailer is present and has one\n"
	"   < pardon [name] > from the wanted list\n\n"
	"%^RESET%^Note:  Adding a bounty directly will require putting up the funds "
	"yourself.  However, you may request an immortal add it for you.  If "
	"none is available, you may use avatarmail or try to contact one later "
	"to be reimbursed.\n"
       );
     }
     if(avatarp(TP)) {
	write("%^BOLD%^%^BLUE%^Immortals adding names will have them show up "
	  "as 'Unknown' to avoid putting real names out there that shouldn't "
	  "be.  So, you will need to add an alias for the name(s) you know "
	  "the person goes by even if it's their real name.\n");
     }
     if(wizardp(TP)) {
	write("%^BOLD%^%^GREEN%^Wizards only:%^RESET%^\n"
	  "Clean up functions may need run periodically to purge out names "
	  "of those who have been rid.  Those functions can be run with the "
	  "following function:%^CYAN%^\n"
	  "  <clean [wanted|prisoners|jailers|bounties|fines|banned] >%^RESET%^\n"
	  "You can also < clean all > but that may cause lag and should be done "
	  "with caution.%^CYAN%^\n"
	  "  <addnew [location]> %^RESET%^To add a new jail location (i.e. Tabor).\n"
	  "%^YELLOW%^NOTE:  Most activities are logged to /log/ICjails.%^RESET%^"
	);
     }
     return 1;
  }
  return 0;
}
