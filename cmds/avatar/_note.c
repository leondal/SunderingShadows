/* As I recall - created by Grendel, ckpt added by Garrett based on Obsidian's
     special/personal noting method/function
  Garrett changed the save so it can handle more players and list more efficiently
  Styx worked on (and got Garrett to help/do) setting several "events" such as 
     trainers, quest completions, etc. to ckpt automatically
  Colors added to ckpt per Grendel's suggestion (and history above) - Styx 7/2002
  Latest command added by Circe thanks to help from Grendel and Tristan 1/25/04
*/

#include <std.h>
#include <money.h>
#include <bank.h>
#include <daemons.h>

#define TREESAVE "/daemon/treesave_d.c"
#define MINLEN 60
#define HRLEN 3600
#define DAYLEN 86400

inherit DAEMON;
int newnum;

string format_checkpoint(string who, string comment);
string format_notes(string *notes);
string format_latest_notes(string *notes);

void help( );
int check_permission(string name,object player);

int check_permission(string name,object player)
{
    string pos;
    if(!objectp(player)) { return 1; }
    if(!interactive(player)) { return 1; } // Possible loophole, but needed for quests to function right -Ares
    if(!stringp(name)) { return 1; }
    pos = lower_case((string)player->query_position());
    if(pos == "builder" || pos == "apprentice")
    {
        if(lower_case(name) != lower_case((string)player->query_true_name()))
        {
            tell_object(player,"You can only use this on yourself.");
            return 0;
        }
    }
    return 1;
}

int cmd_note(string str){
    string *notes, *tmpnotes;
    string tmp, nme, nte, type, let;
    int num,num2;

    if(!str) {
      help();
      return notify_fail("Incorrect syntax.  Try reading <help note>.\n");
    }
    if(sscanf(str, "%s %s %d", type, tmp, num2) == 3) {
        if(type != "latest" && type != "rem"){
          help();
          return 1;
       }
       tmp = lower_case(tmp);        
       newnum = num2;
       if(type == "latest") {
           if(!check_permission(tmp,TP)) { return 1; }
	        if (!user_exists(tmp)) write ("%^BOLD%^%^RED%^Warning: "+
                "%^RESET%^This player doesn't seem to exist...");
                notes = TREESAVE->query_array("notes",tmp);
            if(!notes || notes == ({}))
            return notify_fail("There are no notes for "+tmp+"\n");
            TP->more(format_latest_notes(notes));
            return 1;
        }
    }
    if(sscanf(str,"who %s",let) == 1) {
        notes = TREESAVE->query_array_keys("notes");
        tell_object(TP,"Notes for users who no longer exists are %^RED%^red%^RESET%^.");
        tmp = "";
        for(num = 0;num < sizeof(notes);num++) {
            if(explode(notes[num],"")[0] != lower_case(let)) {
                 continue;
            }
            if(user_exists(notes[num])) {
                tmp += capitalize(notes[num]) + ", ";                
                continue;
            }
            tmp += "%^RED%^"+ capitalize(notes[num]) + "%^RESET%^, ";
            continue;
        }
        tell_object(TP,tmp);
        return 1;
    }
    if(str == "who"){
      notes = TREESAVE->query_array_keys("notes");
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
      notes = TREESAVE->query_array_keys("notes");
      for(num=0;num<sizeof(notes);num++){
        if(!user_exists(notes[num])){
          TREESAVE->remove_key_from_array("notes",notes[num]);
          tell_object(TP, capitalize(notes[num])+" has been cleared.");
        }
      }
      tell_object(TP, "Done.");
      return 1;
    }
    
    if(str == "erase") {
        notes = TREESAVE->query_array_keys("notes");
        for(num = 0;num < sizeof(notes);num++) {
            if(!user_exists(notes[num])) {
                tmpnotes = TREESAVE->query_array("notes",notes[num]);
                if(sizeof(tmpnotes) < 5) {
                    TREESAVE->remove_key_from_array("notes",notes[num]);
                    tell_object(TP, capitalize(notes[num])+" has been cleared.");
                    continue;
                }
                continue;
            }
        }
        return 1;
    }

    if(sscanf(str, "%s %s", type, tmp) != 2) {
      help();
      return notify_fail("Incorrect syntax.\n");
    }
    if(type != "add" && type != "view" && type != "clear" && type != "rem" && type != "ckpt") {
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
    if(!check_permission(nme,TP)) { return 1; }
	nte = format_checkpoint(nme,nte);
      if (objectp(TP)) {
        nte = capitalize(TP->query_name()) + ", " + ctime(time()) + " - " + nte;
    } else {
        nte = "{"+capitalize(getuid()) + "}, " + ctime(time()) + " - " + nte;
    }
        TREESAVE->add_value_to_array("notes",nme, nte);
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
        if(!check_permission(nme,TP)) { return 1; }
	if (!user_exists(nme)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
        nte = capitalize(TP->query_name()) + ", " + ctime(time()) + " - " + nte;
        TREESAVE->add_value_to_array("notes",nme, nte);
        tell_object(TP, "Note added.");
        return 1;
        break;

      case "view":
        tmp = lower_case(tmp);
        if(!check_permission(tmp,TP)) { return 1; }
	if (!user_exists(tmp)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
        notes = TREESAVE->query_array("notes",tmp);
        if(!notes || notes == ({}))
          return notify_fail("There are no notes for "+tmp+"\n");
        TP->more(format_notes(notes));
        return 1;
        break;

      case "clear":
        if(!wizardp(TP)) return notify_fail("For wizzes only.\n");
        tmp = lower_case(tmp);
        if(!check_permission(tmp,TP)) { return 1; }
        TREESAVE->remove_key_from_array("notes",tmp);
        tell_object(TP, "Notes removed for "+tmp+".");
        return 1;
        break;

      case "rem":
        if(sscanf(tmp, "%s %d", nme, num) == 2) {
	  nme = lower_case(nme);
        if(!check_permission(nme,TP)) { return 1; }
	  if (!user_exists(nme)) write ("%^BOLD%^%^RED%^Warning: %^RESET%^This player doesn't seem to exist...");
 	  if (TREESAVE->remove_value_from_array("notes",nme, num))
	    tell_object(TP, "Note removed.");
	  else tell_object(TP, "No notes found or notes out of range?");
	  return 1;
	} else if (sscanf(tmp, "%s", nme) == 1) {
          nme = lower_case(nme);
          //TREESAVE->interactive_remove_value_from_array("notes",nme);
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

}

void help(){
write(
@HELP
Syntaxes:
  note add <name> <note>
    adds a <note> for <name>.
  note ckpt <name> <comment>
    adds a checkpoint note to <name>. A <comment> doesn't have to be added,
    but will be appended. Kudos to Obsidian for the idea and format.
  note view <name>
    Lists all the notes for <name>
  note latest <name> <number>
    Lists the last <number> notes for <name>
  note clear <name>
    deletes all the notes for <name>
    Wizzes only.
  note clean
    deletes notes for all characters who fail to exist
    Wizzes only.
  note rem <name> <number>
    deletes a single note for <name>
  note who | who <letter>
    Returns a list of everyone that has notes.
    Or returns a list of those who have notes 
    with a name starting with <letter>
  note erase
    Cleans notes for all characters who no longer 
    exist and have less than 5 notes.

HELP
);
}

int convert_coins(mapping money)
{
    int i,coins,value;
    for(i=0;i<sizeof(HARD_CURRENCIES);i++)
    {
        coins = money[HARD_CURRENCIES[i]];
        coins = coins / EXCHANGE_RATES[i];
        value += coins;
    }   
    return value;
}

string format_checkpoint(string who, string comment) {
  object ob;
  int num,max, expholder, totage, temp, days, hours, min, sec,i,j,money=0;
  mapping bankmoney,totals=([]);

  string classstring,levelstring, exptonext, *classes, holder,*accounts=({});

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

  accounts = BANK_D->query_bank_accounts(who);
  if(sizeof(accounts))
  {
      for(i=0;i<sizeof(accounts);i++)
      {
        bankmoney = (mapping)BANK_D->query_balance(who,accounts[i]);
        if(!mapp(bankmoney)) { continue; }
        for(j=0;j<sizeof(HARD_CURRENCIES);j++)
		{
           	totals[HARD_CURRENCIES[j]] = totals[HARD_CURRENCIES[j]] + bankmoney[HARD_CURRENCIES[j]];
        }
      }
      for(j=0;j<sizeof(HARD_CURRENCIES);j++)
      {
	    totals[HARD_CURRENCIES[j]] += (int)USERCALL->user_call(who,"query_money",HARD_CURRENCIES[j]);
      }
      money = convert_coins(totals);   
  }

  holder = classstring+", %^BOLD%^%^GREEN%^"+levelstring+"%^RESET%^, "+exptonext;
  holder += ", %^BOLD%^%^MAGENTA%^Exp.: " + ob->query_exp()+" (miniquest exp = "+ob->query("miniquest_exp")+")%^RESET%^";
  holder += ", %^GREEN%^Exp. in NWPs:  "+(int)ob->query_total_nwp_exp()+"%^RESET%^";
  holder += ", %^BOLD%^%^YELLOW%^Gold in coins: "+money+"%^RESET%^";


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
   i = sizeof(notes)-newnum;
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
