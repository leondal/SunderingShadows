/* As I recall - created by Grendel, ckpt added by Garrett based on Obsidian's
     special/personal noting method/function
  Garrett changed the save so it can handle more players and list more efficiently
  Styx worked on (and got Garrett to help/do) setting several "events" such as
     trainers, quest completions, etc. to ckpt automatically
  Colors added to ckpt per Grendel's suggestion (and history above) - Styx 7/2002
  Latest command added by Circe thanks to help from Grendel and Tristan 1/25/04
*/

#include <std.h>

#define TREESAVE "/daemon/treesave_d.c"
#define MINLEN 60
#define HRLEN 3600
#define DAYLEN 86400

inherit DAEMON;


string format_checkpoint(string who, string comment);
string format_notes(string *notes);
string format_latest_notes(string *notes);

void help( );

int cmd_pcnote(string str){
  string *notes;
  string tmp, nme, nte, type;
  int num;

  if(!str) {
    help();
    return notify_fail("Incorrect syntax.  Try reading <help pcnote>.\n");
  }
  if (avatarp(TP)) {
    if(str == "who"){
      notes = TREESAVE->query_array_keys("pcnotes");

      if (!sizeof(notes)) {
        write("Nothing to report.");
        return 1;
      }
      //sort(notes);
      tell_object(TP,"Notes for users who no longer exist are %^RED%^red%^RESET%^.");
      tmp = "";
      if (user_exists(notes[0]))
	tmp += capitalize(notes[0]);
      //message("system",capitalize(notes[0]),TP);
      else
	tmp += "%^RED%^"+ capitalize(notes[0])+"%^RESET%^";
      //message("system","%^RED%^"+ capitalize(notes[0])+"%^RESET%^",TP);

      for(num=1;num<sizeof(notes);num++){
	if (!(num % 7)) {
	  tell_object(TP,tmp);
	  tmp = "";
	} else {
          tmp += ", ";
	}
	if (user_exists(notes[num]))
	  tmp += capitalize(notes[num]);
	//message("system",capitalize(notes[num]),TP);
	else
	  tmp += "%^RED%^"+ capitalize(notes[num])+"%^RESET%^";
	//message("system",", "%^RED%^"+ capitalize(notes[num])+"%^RESET%^",TP);
      }
      tmp += ".";
      write(tmp);
      //  tell_object(TP, tmp+".");
      //  write(format_page(explode(tmp,","),3));
      return 1;
    }
    if(str == "clean"){
      if(!wizardp(TP)) return notify_fail("For wizzes only.\n");
      notes = TREESAVE->query_array_keys("pcnotes");
      for(num=0;num<sizeof(notes);num++){
        if(!user_exists(notes[num])){
          TREESAVE->remove_key_from_array("pcnotes",notes[num]);
          tell_object(TP, capitalize(notes[num])+" has been cleared.");
        }
      }
      tell_object(TP, "Done.");
      return 1;
    }
    if(sscanf(str, "%s %s", type, tmp) != 2) {
      help();
      return notify_fail("Incorrect syntax.\n");
    }
    if(type != "add" && type != "view" && type != "clear" && type != "rem" && type != "ckpt" && type != "latest") {
      help();
      return notify_fail("Incorrect syntax.\n");
    }
    switch(type){
    case "ckpt":
      if((sscanf(tmp, "%s %s", nme, nte) != 2)
	 && (sscanf(tmp,"%s",nme) != 1)) {
	help();
	return notify_fail("Incorrect Syntax.\n");
      }
      if (!stringp(nte)) nte = "";
      if (!stringp(nme)) nme = tmp;
      nme = lower_case(nme);
      if (!user_exists(nme)) notify_fail ("ERROR: This player doesn't seem to exist...\n");
      if (!objectp(find_player(nme)))
	return notify_fail ("ERROR: Player must be online!\n");
      if (avatarp(find_player(nme)))
	return notify_fail("You want to checkpoint them?\n");
      nte = format_checkpoint(nme,nte);
      if (objectp(TP)) {
        nte = capitalize(TP->query_name()) + ", " + ctime(time()) + " - %^BOLD%^%^BLUE%^SG time: %^GREEN%^"+hour(time())+":"+(minutes(time()) > 9?minutes(time()):"0"+minutes(time()))+" "+day(time())+", "+date(time())+" "+month(time())+", "+year(time())+" SG%^RESET%^ - " + nte;
      } else {
        nte = "{"+capitalize(getuid()) + "}, " + ctime(time()) + " - " + nte;
      }
      TREESAVE->add_value_to_array("pcnotes",nme, nte);
      if (objectp(TP) && avatarp(TP))
        tell_object(TP, "Checkpoint added.");
      return 1;
      break;

    case "add":
      if(sscanf(tmp, "%s %s", nme, nte) != 2) {
	help();
	return notify_fail("Incorrect Syntax.\n");
      }
      nme = lower_case(nme);
      if (!user_exists(nme)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
      nte = capitalize(TP->query_name()) + ", " + ctime(time()) + " - %^BOLD%^%^BLUE%^SG time: %^GREEN%^"+hour(time())+":"+(minutes(time()) > 9?minutes(time()):"0"+minutes(time()))+" "+day(time())+", "+date(time())+" "+month(time())+", "+year(time())+" SG%^RESET%^ - " + nte;
      TREESAVE->add_value_to_array("pcnotes",nme, nte);
      tell_object(TP, "Note added.");
      return 1;
      break;

    case "view":
      tmp = lower_case(tmp);
      if (!user_exists(tmp)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
      notes = TREESAVE->query_array("pcnotes",tmp);
      if(!notes || notes == ({}))
	return notify_fail("There are no notes for "+tmp+"\n");
      TP->more(format_notes(notes));
      return 1;
      break;

    case "latest":
      tmp = lower_case(tmp);
      if (!user_exists(tmp)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
      notes = TREESAVE->query_array("pcnotes",tmp);
      if(!notes || notes == ({}))
	return notify_fail("There are no notes for "+tmp+"\n");
      TP->more(format_latest_notes(notes));
      return 1;
      break;

    case "clear":
      if(!wizardp(TP)) return notify_fail("For wizzes only.\n");
      tmp = lower_case(tmp);
      TREESAVE->remove_key_from_array("pcnotes",tmp);
      tell_object(TP, "Notes removed for "+tmp+".");
      return 1;
      break;

    case "rem":
      if(sscanf(tmp, "%s %d", nme, num) == 2) {
	nme = lower_case(nme);
	if (!user_exists(nme)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
	if (TREESAVE->remove_value_from_array("pcnotes",nme, num))
	  tell_object(TP, "Note removed.");
	else tell_object(TP, "No notes found or notes out of range?");
	return 1;
      } else if (sscanf(tmp, "%s", nme) == 1) {
	nme = lower_case(nme);
	//TREESAVE->interactive_remove_value_from_array("pcnotes",nme);
	// the interactive function returns success or fail.
	write("Interactive stuff disabled for now. Sorry...");
	return 1;
      } else {
          help();
	  return notify_fail("Incorrect Syntax.\n");
	}
        break;
    }
    return 1;
  } else /* !avatarp() */ {
    if (str == "view") {
      tmp = lower_case(TPQN);
      if (!user_exists(tmp)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
      notes = TREESAVE->query_array("pcnotes",tmp);
      if(!notes || notes == ({}))
	return notify_fail("There are no notes for "+tmp+"\n");
      TP->more(format_notes(notes));
      return 1;
    }

    if (str == "latest") {
      tmp = lower_case(TPQN);
      if (!user_exists(tmp)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
      notes = TREESAVE->query_array("pcnotes",tmp);
      if(!notes || notes == ({}))
	return notify_fail("There are no notes for "+tmp+"\n");
      TP->more(format_latest_notes(notes));
      return 1;
    }

    if(sscanf(str, "%s %s", type, tmp) != 2) {
      help();
      return notify_fail("Incorrect Syntax.\n");
    }
    switch(type) {
    case "add":
      nme = lower_case(TPQN);
      if (!user_exists(nme)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
      nte = capitalize(TP->query_name()) + ", " + ctime(time()) + " - " + tmp;
      TREESAVE->add_value_to_array("pcnotes",nme, nte);
      tell_object(TP, "Note recorded");
      return 1;
      break;

    case "rem":
      if(sscanf(tmp, "%d", num) == 1) {
	nme = lower_case(TPQN);
	if (!user_exists(nme)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
	if (TREESAVE->remove_value_from_array("pcnotes",nme, num))
	  tell_object(TP, "Note removed.");
	else
	  tell_object(TP, "No notes found or notes out of range?");
	return 1;

      } else {
	help();
	return notify_fail("Incorrect Syntax.\n");
      }
      break;
    default:
      	help();
	return notify_fail("Incorrect Syntax.\n");
	break;
    }
    write("End of switch problem. Tell garrett");
    return 1;
  }
}

void help(){
    write(
"
%^CYAN%^NAME%^RESET%^

pcnote - manage notes about character

%^CYAN%^SYNOPSIS%^RESET%^

Players:

pcnote add %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^
pcnote view
pcnote latest
pcnote rem %^ORANGE%^%^ULINE%^NUMBER%^RESET%^

Avatars:

pcnote add %^ORANGE%^%^ULINE%^NAME%^RESET%^ %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^
pcnote view %^ORANGE%^%^ULINE%^NAME%^RESET%^
pcnote latest %^ORANGE%^%^ULINE%^NAME%^RESET%^
pcnote clear %^ORANGE%^%^ULINE%^NAME%^RESET%^
pcnote rem %^ORANGE%^%^ULINE%^NAME%^RESET%^ %^ORANGE%^%^ULINE%^NUMBER%^RESET%^
pcnote who

%^CYAN%^DESCRIPTION%^RESET%^

Pcnotes (player character notes) is a tool you can use to save notes. Some of these notes might be used by avatars.

Here you can point your past, personal preferences or other useful information you think you youself or avatars might need in interractions with you. Or you can store information you yourself as a player find useful, such as naval locations or names of important npcs.

%^CYAN%^SEE ALSO%^RESET%^

help, score, stats, who, discern, note
"
);

}


string format_checkpoint(string who, string comment) {
  object ob;
  int num,max, expholder, totage, temp, days, hours, min, sec;

  string classstring,levelstring, exptonext, *classes, holder;

  ob=find_player(who);
  max = sizeof(classes = ob->query_classes());
  classstring = "Class: "+capitalize(classes[0]);
  levelstring = "Level: "+ob->query_class_level(classes[0]);
  expholder = "/adm/daemon/advance_d"->get_exp(ob->query_class_level(classes[0])+1,classes[0], ob);
  expholder -= ((int)ob->query_exp()/sizeof(classes));
  exptonext = "Exp to Next: " + expholder;
  for(num=1;num<max;num++){
    classstring += "/"+capitalize(classes[num]);
    levelstring += "/"+ob->query_class_level(classes[num]);
    expholder = "/adm/daemon/advance_d"->get_exp(ob->query_class_level(classes[num])+1,classes[num], ob);
    expholder -= ((int)ob->query_exp()/sizeof(classes));
    exptonext += "/"+expholder;

  }
  holder = classstring+", %^BOLD%^%^GREEN%^"+levelstring+"%^RESET%^, "+exptonext;
  holder += ", %^BOLD%^%^MAGENTA%^Exp.: " + ob->query_exp()+"%^RESET%^";
  holder += ", %^GREEN%^Exp. in NWPs:  "+(int)ob->query_total_nwp_exp()+"%^RESET%^";

  totage = ob->query_age();
  days = totage/DAYLEN;
  temp = totage%DAYLEN;
  hours = temp/HRLEN;
  temp = temp%HRLEN;
  min = temp/MINLEN;
  sec = temp%MINLEN;

  holder += ", %^BOLD%^%^WHITE%^Age: "  +days+ " days, %^RESET%^"
     +hours+":"+min+"."+sec+" old.";
  if (stringp(comment) && (comment != "")) holder += "  Comment: ";
  return holder + comment;
}

string *format_notes(string *notes){
    string num, *tmp, nd;
    int x;

   tmp = allocate(sizeof(notes));
    for(x=0;x<sizeof(notes);x++)
//   tmp[x] = arrange_string(""+(x+1)+"", 3) + ": " + notes[x] + "\n" ;
    tmp[x] = arrange_string(""+(x+1)+"", 3) + ": " + notes[x] ;
    return tmp;

}

string *format_latest_notes(string *notes){
    string num, *tmp, nd;
    int x,i;

   i = sizeof(notes)-5;
   if(i < 0){
      i = 0;
   }
    tmp = ({});
    for(x=i;x<sizeof(notes);x++)
{
        tmp += ({arrange_string(""+(x+1)+"", 3) + ": " + notes[x]});
}
    return tmp;

}
