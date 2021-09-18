#include "/daemon/rumours/sources.h"
#define RUMOURS_D "/daemon/rumours_d.c"


string subj;
int num;

void help() 
{
   write(
//  "123456789012345678901234567890123456789012345678901234567890123456789012345" 
    "Syntax: <gossip> -  Opens an editor from which you can make choices about"
   +"\n                    finding out about rumours, or starting some new ones\n"
   +"\nOptions available in the editor are: "
   + list_commands("short")                 
  );
  write(
    "\n%^BOLD%^%^YELLOW%^Note: %^RESET%^%^RED%^Starting a background rumour about yourself may be considered an OOC action, to help establish the known history of your character. However, starting a rumour about someone else, or digging for information about them are definitely IC actions. There is some chance of word getting out about what you've been up to."
    +"\nYou can start as many background rumours for your character as you like. However, you will be limited in how many rumours you can start or circulate using the 'start rumour' and 'circulate rumour' options, depending on your influence. Once you have exhausted all your gossipping potential, you'll have to wait a while before starting or circulating more.");
}

varargs cmd_gossip(string str){
    tell_object(TP, list_commands());
/////////////////////////////////////////////////////////////////
//   REMOVE THIS SECTION TO IMPLEMENT THE COMMAND FOR PLAYERS  //
//                                                             //
//    if (!avatarp(TP) && !TP->query_true_invis() && TPQN != "noob") //
//    {                                                          //
//       tell_object(TP, "NOTE: "                                // 
//       +"%^BOLD%^%^YELLOW%^The gossip command is not yet"      //
//       +" available to players, but we hope it will be soon."  //
//       +" Do get your character rumours ready to go, for when" //
//       +" it is available. %^BOLD%^%^GREEN%^Lujke, Jan 2018"); //
//       return;                                                 //
//    }                                                          //
/////////////////////////////////////////////////////////////////
//    
    input_to("enter_editor", 0);
    return 1;
 }

void report(string str){
  //"/daemon/reporter_d.c"->report("lujke", str); not there anymore -H
  "/d/atoyatl/reporter_d.c"->report("lujke", str);
}

varargs string list_commands(string str){
  string result;
  if (!stringp(str) || str != "short")
  {
    result = "%^BOLD%^%^RED%^Here's a list of commands you can use,"
      +"\n%^RESET%^%^ORANGE%^OR%^BOLD%^%^RED%^ enter anything else to exit%^RESET%^";
  } else 
  {
    result = "";
  }
  result += "\n%^ORANGE%^            gossip at random%^RESET%^ - listen out for random rumours"
      +"\n                               from around the Realms"
      +"\n%^ORANGE%^          dig dirt on [%^RESET%^name%^ORANGE%^]%^RESET%^ - ask around after rumours"
      +"\n                               about the named person"
      +"\n%^ORANGE%^                start rumour%^RESET%^ - start a rumour about"
      +"\n                               yourself or someone you know"
      +"\n%^ORANGE%^                  background%^RESET%^ - create a rumour about your character that"
      +"\n                               will form part of the background information"
      +"\n                               that might be generally discoverable about"
      +"\n                               them"
      +"\n%^ORANGE%^              recall rumours%^RESET%^ - lists all the people you"
      +"\n                               have heard a rumour about"
      +"\n%^ORANGE%^ recall rumours about [%^RESET%^name%^ORANGE%^]%^RESET%^ - lists all the rumours you"
      +"\n                               have heard about the named"
      +"\n                               person"
      +"\n%^ORANGE%^recall rumour # about [%^RESET%^name%^ORANGE%^]%^RESET%^ - gives all the details you"
      +"\n                               have heard about the rumour"
      +"\n                               in question"
      +"\n%^ORANGE%^dig further into rumour # about [name]%^RESET%^ - seek out more details"
      +"\n                               about a rumour you have"
      +"\n                               already heard about"
      +"\n                               someone"
      +"\n%^ORANGE%^                   circulate%^RESET%^ - circulate a rumour that"
      +"\n                               you have heard about someone" 
      +"\n%^ORANGE%^                       quash%^RESET%^ - try to quash a rumour that"
      +"\n                               you have heard about someone" 
      +"\n                               (This is harder than spreading"
      +"\n                               a rumour around, and could"
      +"\n                               backfire)"
      +"\n%^ORANGE%^                       check%^RESET%^ - check what sort of rumours"
      +"\n                               might be available in the place you are in,"
      +"\n                               and whether you are currently engaged in any"
      +"\n                               gossip";
  if (avatarp(TP)||TP->query_true_invis()){
    result +="\n%^BOLD%^%^WHITE%^Your additional Imm commands:\n"
     +"     <remove rumour # for [name]> - deletes the rumour in question"
   +"\n                                    completely. For judicious use, to"
   +"\n                                    prevent the rumour system being abused"
   +"\n      <plant rumour about [name]> - creates a rumour about the person in"
   +"\n                                    question, but also allows you to"
   +"\n                                    specify someone else as instigator of"
   +"\n                                    the rumour. Handy for putting in some"
   +"\n                                    consequences when PCs are blabbing"
   +"\n                                    about secret stuff in public locations,"
   +"\n                                    for example."
   +"\n       <list rumours about [name] - Lists all the rumours in circulation"
   +"\n                                    the named person."
   +"\n      <edit rumour # about [name] - Puts you into an editor where you can"
   +"\n                                    choose to change various aspects of"
   +"\n                                    the rumour specified";
   
  }
  return result;
}


string list_heard_rumour_subjects(string hearer){
  mapping rumours, subject_rumours;
  int * nums, num, width, linelen, sublen, remainder, i;
  string * subjects, subject, result, line;
  report("list_heard_rumour_subjects: %^CYAN%^Starting");
  rumours = RUMOURS_D->query_heard_rumours(hearer);
  if (!mapp(rumours) || sizeof(rumours)<1) return "%^BOLD%^%^WHITE%^Sorry, you have not heard any rumours yet.\n\n%^RESET%^%^ORANGE%^How sad. \n%^RESET%^Don't you talk to people? \n\n%^BOLD%^%^WHITE%^Check 'help gossip' for more on how to go about hearing some juicy tidbits of information.";
  subjects = keys(rumours);
//  report("Setting up result");
  result = "%^RESET%^%^ORANGE%^You have heard rumours about the following subjects:\n";
  line  = ""; 
  width = atoi(TP->getenv("SCREEN"));
  if (width <15) width = 70;
//  report ("Checking subjects");
  foreach(subject in subjects)
  {
//    report("Subject: " + subject);
    sublen = strlen(subject);
    linelen = strlen(line);
    if (linelen + sublen>width)
    {
      result += line + "\n";
      line = "";
    }
//    report("Adding subject to line");
    line += capitalize(subject);
    if (width > sublen + linelen + 6)
    {
      remainder = sublen % 6;
      if (remainder > 0)
      {
        for (i = remainder; i<6;i++) line += " ";
      } 
      line += "  ";
    } else {
      result +=line + "\n";
      line = "";
    }
  }
  result += line;
  return result;
} 

mixed * get_random_rumour(){
  mixed * rumour;
  string surface;
  rumour = RUMOURS_D->get_rumour();
  return rumour;
}

int get_random_source_number(){
  return random(sizeof(SOURCES));
}

string get_source(int num){
  int num_sources;
  num_sources = sizeof(SOURCES);
  if (num >= num_sources) return "";
  return SOURCES[num];
}

varargs void confirm_unknown(string str, string name, string inst){
  if (lower_case(str) == "yes")
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, going ahead with the name %^RESET%^%^CYAN%^" + capitalize(name) + "%^BOLD%^%^WHITE%^." 
   +"\n%^BOLD%^%^WHITE%^Now, where would someone be most likely to hear the rumour you are starting?"
   +"\n%^ORANGE%^Options are:"
   +"\n%^BOLD%^%^WHITE%^City   %^RESET%^-%^ORANGE%^ Rumours circulating in human, elf and dwarf cities"
   +"\n%^GREEN%^Wild   %^RESET%^-%^ORANGE%^ Rumours circulating among the people of the wilds - rangers, druids, barbarians and the like"
   +"\n%^ORANGE%^B%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^a%^GREEN%^s%^ORANGE%^t  %^RESET%^-%^ORANGE%^ Rumours circulating among the beast races of the Realms"
   +"\n%^RESET%^Or enter 'Q' to quit");
    input_to("rumour_type", 0, name, inst);
    return;
  }
  tell_object(TP, "%^ORANGE%^Very well, what is the name you would like the rumour to be about instead?");
  input_to("start_rumour", 0, inst);
}

varargs void start_rumour(string str, string inst){
  mapping rels;
  string name, myname, * nick_options, nick_option;
  mixed * nicks, nick ;
  int flag;
  if (!RUMOURS_D->can_gossip(TP->query_name()) )
  {
    if (avatarp(TP) || TP->query_true_invis())
    {
      tell_object("As an Imm, you can gossip as much as you want. Otherwise, you'd be out of tries about now");
    } else
    {  
      tell_object(TP, "You have exhausted your gossipping contacts for the time being. Try again later.");
      return;
    }
  }
  if (str == "me" || str == "myself")
  {
    myname = TP->query_name();
    if (TP->isKnown(myname))
    {
      str = TP->knownAs(myname);
      tell_object(TP, "%^CYAN%^Okay, you're starting a rumour about yourself");
    } else 
    {
      tell_object(TP, "You haven't recognized yourself yet. You'll need to do that before you can start a rumour about yourself");
      return;
    }
  }

  if(!Does_x_know_y(TP, str)) 
  {
    if (avatarp(TP) || TP->query_true_invs())
    {
      tell_object(TP, "%^CYAN%^You don't know anyone by that name. Are you SURE you want to go ahead? Enter 'yes' to proceed or anything else to try again"); 
      input_to("confirm_unknown", 0, str, inst);  
    }
    tell_object(TP, "%^CYAN%^You don't know anyone by that name");
    return;
  }
  name = str;
  tell_object(TP, "%^BOLD%^%^WHITE%^Where would someone be most likely to hear the rumour you are starting?"
   +"\n%^ORANGE%^Options are:"
   +"\n%^BOLD%^%^WHITE%^City   %^RESET%^-%^ORANGE%^ Rumours circulating in human, elf and dwarf cities"
   +"\n%^GREEN%^Wild   %^RESET%^-%^ORANGE%^ Rumours circulating among the people of the wilds - rangers, druids, barbarians and the like"
   +"\n%^ORANGE%^B%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^a%^GREEN%^s%^ORANGE%^t  %^RESET%^-%^ORANGE%^ Rumours circulating among the beast races of the Realms"
   +"\n%^RESET%^Or enter 'Q' to quit");
  input_to("rumour_type", 0, name, inst);
}

varargs void rumour_type(string str, string name, string inst){
  int type;
  string location;
  if (!stringp(str))
  {
    tell_object(TP, "No rumour type entered. Defaulting to CITY - you will get a chance to amend this before you finalise the rumour");
    type = CITY_SOURCE;
    input_to("surface_rumour", 0, name, type, inst);
    return;
  }
  switch(lower_case(str))
  {
  case "city":
    tell_object(TP, "%^ORANGE%^Okay, it's going to be a city rumour");
    type = CITY_SOURCE;
    location = "in the %^ORANGE%^city%^RESET%^";
    break;
  case "wild":
    tell_object(TP, "%^ORANGE%^Okay, it's going to be a rumour passing among the wild folk");
    type = WILD_SOURCE;
    location = "among the people of the %^GREEN%^Wild%^RESET%^";
    break;
  case "beast":
    tell_object(TP, "%^ORANGE%^Okay, it's going to be a rumour passing among the beast races");
    type = BEAST_SOURCE;
    location = "among the %^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^e%^MAGENTA%^a%^GREEN%^s%^BOLD%^%^BLACK%^t%^RESET%^ races";
    break;
  case "q":
    tell_object(TP, "%^ORANGE%^Abandoning rumour");
    return;
  default:
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, that's not an available option. Please try again to specify the type of rumour you want to start"
   +"\n%^ORANGE%^Options are:"
   +"\n%^BOLD%^%^WHITE%^City   %^RESET%^-%^ORANGE%^ Rumours circulating in human, elf and dwarf cities"
   +"\n%^GREEN%^Wild   %^RESET%^-%^ORANGE%^ Rumours circulating among the people of the wilds - rangers, druids, barbarians and the like"
   +"\n%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^e%^MAGENTA%^a%^GREEN%^s%^BOLD%^%^BLACK%^t  %^RESET%^-%^ORANGE%^ Rumours circulating among the beast races of the Realms"
   +"\n%^RESET%^Or enter 'Q' to quit");
    location = "in the %^ORANGE%^city%^RESET%^";
    input_to("rumour_type", 0, name, inst);
    return;
    break;
  }

  tell_object(TP, "What rumour about " + name + " would you like to start " + location + "?\n"
   +"%^RESET%^%^CYAN%^Note: your rumour can have a maximum of 300 characters"
   +" (excluding colour codes) - about 50 words."
   +"\n%^RESET%^Or enter 'Q' to quit");
  report ("About to do surface rumour. Type = " + type);
  input_to("surface_rumour", 0, name, type, inst);
}

string get_location_name(int type){
  string location;
  switch(type){
  case CITY_SOURCE:
    location = "in the %^ORANGE%^city%^RESET%^";
    break;
  case WILD_SOURCE:
    location = "among the people of the %^GREEN%^Wild%^RESET%^";
    break;
  case BEAST_SOURCE:
    location = "among the %^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^e%^MAGENTA%^a%^GREEN%^s%^BOLD%^%^BLACK%^t%^RESET%^ races";
    break;
  }
  return location;

}

varargs void surface_rumour(string str, string name, int type, string inst){
  string plainstr;
  report("surface rumour: type = " + type);
  plainstr = strip_colors(str);
  if (lower_case(plainstr) == "q")
  {
    tell_object(TP, "%^ORANGE%^Rumour edit abandoned");
    return;
  }
  if (strlen(plainstr)>300)
  {
    tell_object(TP, "Sorry, that rumour is too long. Try again, keeping it to 300 characters or fewer");
    input_to("surface_rumour", 0, name, type, inst);
    return;
  }
  if (strlen(plainstr)<1){
    tell_object(TP, "%^BOLD%^%^WHITE%^There needs to be some content to a rumour, to make it worth gossipping about. Try again, or enter 'q' to abandon this rumour");
    input_to("surface_rumour",0,name, type);
    return;
  }
  tell_object(TP, "%^BOLD%^%^WHITE%^Got it.\n%^BOLD%^%^WHITE%^Is there any more detail someone might find out with a little more digging? You can enter another 600 characters or so, if the rumour needs fleshing out, or hit <enter> to skip");
  input_to("detailed_rumour", 0, name, type, str, inst);
}

varargs void detailed_rumour(string str, string name, int type, string surface, string inst){
  string plainstr;
  report("detailed rumour: type = " + type);
  if (!stringp(str) || strlen(str)<1)
  {
    str = "";
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, so there's no further general details about this rumour. Are there any %^RED%^secret%^WHITE%^ details that could be discovered with serious investigation?\nYou can enter another 600 characters or so, if there are secrets to discover, or hit <enter> to skip");
    input_to("secret_info", 0, name, type, surface, str, inst);
    return;
  }
  plainstr = strip_colors(str);
  if (lower_case(plainstr) == "q"){
    tell_object(TP, "%^ORANGE%^Rumour edit abandoned");
    return;
  } 
  if (strlen(plainstr)>600)
  {
    tell_object(TP, "Sorry, that detailed information must have too much detail. Try again, keeping it to 600 characters or fewer");
    input_to("detailed_rumour", 0, name, surface, inst);
    return;
  }
  tell_object(TP, "%^BOLD%^%^WHITE%^Got it.\n%^BOLD%^%^WHITE%^Are there any %^RED%^secret%^WHITE%^ details that could be discovered with serious investigation?\nYou can enter another 600 characters or so, if there are secrets to discover, or hit <enter> to skip");
  input_to("secret_info", 0, name, type, surface, str, inst);
  return;

}

varargs void secret_info(string str, name, int type, surface, detail, inst ){
  string secret;
  report("secret rumour: type = " + type);
  if (!stringp(str) || strlen(str)<1)
  {
    secret = "";
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, so there are no secrets to be found about this rumour at the moment. Now let's finalise the details");
  } else 
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, got the secret information. Now let's finalise the details");
    secret = str;
  } 
  call_out("confirm_rumour", 1, name, type, surface, detail, secret, TP, inst);  
  return;
}

varargs void confirm_rumour(string name, int type, string surface, string detail, string secret, object ob, inst){
  string location;
  report("confirm rumour: type = " + type);
  location = get_location_name(type);
  if (!objectp(ob)) return;
  tell_object(ob, "%^BOLD%^%^WHITE%^Please confirm the details of the rumour you wish to start");
  tell_object(ob, "\n%^ORANGE%^Subject name:%^RESET%^ " + name );
  tell_object(ob, "Rumour circulating: " + location);
  tell_object(ob, "\n%^ORANGE%^Surface details of rumour: %^RESET%^");
  tell_object(ob, surface);
  tell_object(ob, "\n%^ORANGE%^Deeper details of rumour: %^RESET%^");
  tell_object(ob, detail);
  tell_object(ob, "\n%^ORANGE%^Secret details of rumour (these will be hard to find out)");
  tell_object(ob, secret);
  tell_object(ob, "\n%^BOLD%^%^WHITE%^Are these details correct? Enter 'Yes' to go ahead and start the rumour, or use one of the following commands:");
  tell_object(ob, "%^CYAN%^Amend subject name");
  tell_object(ob, "%^CYAN%^Amend rumour type%^RESET%^ (Selects between city, wild or beast-race rumours)");
  tell_object(ob, "%^CYAN%^Amend surface details");
  tell_object(ob, "%^CYAN%^Amend deeper details");
  tell_object(ob, "%^CYAN%^Amend secret details");
  tell_object(ob, "%^CYAN%^Amend traction");
  tell_object(ob, "%^CYAN%^OR 'Q' to abort the rumour altogether");
  input_to("final_confirmation", 0, name, type, surface, detail, secret, ob, inst);
}

int calculate_traction(int type, object ob){
  int racetype, traction;
  if (!objectp(ob)) return 0;
  switch(lower_case(ob->query_race()))
  {
    case "beastman":
    case "firbolg":
    case "half-elf":
    case "halfling":
    case "human":
    case "centaur":
    case "voadkyn":
    case "wemic":
    case "gnome":
      racetype = 1;
      break;
    case "half-orc":
      switch (ob->query("subrace"))
      {
      case "gray orc":
      case "mountain orc":
      case "orog":
      case "tanarukk":
        racetype = 2;
        break;
      default:
        racetype = 1;
        break;
      }
      break;
    case "elf":
      switch (ob->query("subrace"))
      {
      case "fey'ri":
        racetype = 2;
        break;
      default:
        racetype = 1;
        break;
      }
      break;
    case "dwarf":
      switch (ob->query("subrace"))
      {
      case "gray dwarf":
        racetype = 2;
        break;
      default:
        racetype = 1;
        break;
      }
      break;
    case "half-drow": 
    case "bugbear":
    case "drow":
    case "gnoll":
    case "goblin":
    case "half-ogre":
    case "hobgoblin":
    case "kobold":
    case "minotaur":
    case "orc":
    case "ogre":
    case "ogre-mage":
    case "yuan-ti":
      racetype = 2;
      break;
  }
  switch(type)
  {
  case CITY_SOURCE:
    if (racetype ==1)
    {
      traction = ob->query_skill("influence") *2;
    } else
    {
      traction = ob->query_skill("influence")/5;
    }
    break;
  case WILD_SOURCE:
    if (racetype ==1)
    {
      traction = ob->query_skill("influence") *2;
    } else
    {
      traction = ob->query_skill("influence")/5;
    }
    break;
  case BEAST_SOURCE:
    if (racetype ==2)
    {
      traction = ob->query_skill("influence") *2;
    } else
    {
      traction = ob->query_skill("influence")/5;
    }
    break;
  }
  return traction;
}

void final_confirmation(string str,string name, int type, string surface, string detail, string secret, object ob, string inst){
  string tn, instigator, * altnames, altname;
  int traction, flag, rn;
  mixed truename, * truenames;
  mapping rels;
  if (!objectp (ob)) return;
  if (stringp(inst) && inst !="") instigator = inst; else instigator = ob->query_name();
  traction = calculate_traction(type, ob);
  switch(lower_case(str))
  {
  case "yes":
    tn = "no-one";
    rels = ob->getRelationships();
    truenames = keys(rels);
    flag = 0;
    foreach(truename in truenames)
    {
      if (mapp(truename)){
        altnames = values(truename);
        foreach(altname in altnames)
        {
          if (ob->knownAs(altname)==name)
          {
            tn = altname;
            flag = 1;
            break;
          }
          if (flag == 1) break;
        }
      }
      if (stringp(truename)){
        if (ob->knownAs(truename)==name)
        {
          tn = truename;
          break;
        }
      }
    }
    rn = RUMOURS_D->add_rumour(name, tn, ({instigator, instigator, instigator}), surface, detail, secret, type, traction, ob->query_short());
    RUMOURS_D->hear_rumour(ob->query_true_name(), RUMOURS_D->query_rumour( name, rn), SECRET_LVL);
    tell_object(ob, "%^ORANGE%^Very good, your rumour has been started. Let's see if it gets any traction");
    if (RUMOURS_D->can_gossip(TPQN, TP->query_skill("influence")) && instigator != "background") RUMOURS_D->add_gossip_time(instigator);
    break;
  case "amend subject name":
    tell_object(ob, "%^BOLD%^%^WHITE%^Very well, what is the name you wish this rumour to be attached to?");
    input_to("amend_name", 0, type, surface, detail, secret, ob); 
    break;
  case "amend rumour type":
    tell_object(ob, "%^BOLD%^%^WHITE%^Very well, where do you want to start this rumour circulating?"
   +"\n%^ORANGE%^Options are:"
   +"\n%^BOLD%^%^WHITE%^City   %^RESET%^-%^ORANGE%^ Rumours circulating in human, elf and dwarf cities"
   +"\n%^GREEN%^Wild   %^RESET%^-%^ORANGE%^ Rumours circulating among the people of the wilds - rangers, druids, barbarians and the like"
   +"\n%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^e%^MAGENTA%^a%^GREEN%^s%^BOLD%^%^BLACK%^t  %^RESET%^-%^ORANGE%^ Rumours circulating among the beast races of the Realms");
    input_to("amend_type", 0, name, surface, detail, secret, ob); 
    break;
  case "amend traction":
    tell_object("%^BOLD%^%^WHITE%^Very well, what would you like the new traction score to be?");
    input_to("amend_type", 0, name, type, surface, detail, secret, ob);
    break;
  case "amend surface details":
    tell_object(ob, "%^BOLD%^%^WHITE%^Very well, please re-enter the surface details of the rumour");
    input_to("amend_surface", 0, name, type, detail, secret, ob); 
    break;
  case "amend deeper details":
    tell_object(ob, "%^BOLD%^%^WHITE%^Very well, please re-enter the deeper details of the rumour");
    input_to("amend_detail", 0, name, type, surface, secret, ob); 
    break;
  case "amend secret details":
    tell_object(ob, "%^BOLD%^%^WHITE%^Very well, please re-enter the secret details of the rumour");
    input_to("amend_secret", 0, name, type, surface, detail, ob); 
    break;
  case "q":    
    break;
  default:
    tell_object(TP, "I'm sorry, that was not one of your options.");
    confirm_rumour(name, type, surface, detail, secret, ob, inst); 
    break; 
  }
  return;
}

int Does_x_know_y(object x, string y){
  mapping rels;
  string * nick_options, nick_option;
  mixed * nicks, nick ;
  int flag;
  nicks = ({});
  rels = x->getRelationships();
  if (mapp(rels) && sizeof(rels)>0)
  {
    nicks = values(rels);
  }
  if (sizeof(nicks)<1)
  {
    return 0;
  } else 
  {
    flag = 0;
    foreach(nick in nicks)
    {
      if (stringp(nick) && nick == y)
      {
        flag = 1; 
        break;
      }
      if (mapp(nick) && sizeof(nick)>0)
      {
        nick_options = values(nick);
        foreach(nick_option in nick_options)
        {
          if (nick_option == y)
          {
            flag = 1; 
            break;
          }
        }
      }
    }
    return flag;
  }
  
}

void amend_name(string str, int type, string surface, string detail, string secret, object ob){
  mapping rels;
  string * nicks;
  if (!objectp(ob)) return;
  if (!stringp(str) || strlen(str)<1)
  {
    tell_object(ob, "%^BOLD%^%^Please enter the name you want to use - or 'Q' if you want to abandon the rumour you were writing completely");
    input_to("amend_name", 0, surface, detail, secret, ob);
    return;
  } 
  if (lower_case(str)== "q")
  {
    tell_object(ob, "%^ORANGE%^Rumour abandoned. Feel free to start over");
    return;
  } 
  nicks = ({});
  rels = TP->getRelationships();
  if (mapp(rels) && sizeof(rels)>0)
  {
    nicks = values(rels);
  }
  if (sizeof(nicks)<1 || member_array(str, nicks)==-1)
  {
    tell_object(TP, "%^CYAN%^You don't know anyone by that name. Please try again");
    tell_object(ob, "%^BOLD%^%^WHITE%^What is the name you wish this rumour to be attached to?");
    input_to("amend_name", 0, surface, detail, secret, ob); 
    return;
  }
  tell_object(ob, "%^BOLD%^%^WHITE%^Amending name to " + str);
  call_out("confirm_rumour",1, str, type, surface, detail, secret, ob);
}

void amend_type(string str, string name, string surface, string detail, string secret, object ob){
  int type;
  if (!objectp(ob)) return;
  if (!stringp(str) || strlen(str)<1)
  {
    tell_object(ob, "%^BOLD%^%^WHITE%^Please enter the type of rumour you want to start."
   +"\n%^ORANGE%^Options are:"
   +"\n%^BOLD%^%^WHITE%^City   %^RESET%^-%^ORANGE%^ Rumours circulating in human, elf and dwarf cities"
   +"\n%^GREEN%^Wild   %^RESET%^-%^ORANGE%^ Rumours circulating among the people of the wilds - rangers, druids, barbarians and the like"
   +"\n%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^e%^MAGENTA%^a%^GREEN%^s%^BOLD%^%^BLACK%^t  %^RESET%^-%^ORANGE%^ Rumours circulating among the beast races of the Realms");
    input_to("amend_type", 0, name, surface, detail, secret, ob);
    return;
  } 
  if (lower_case(str)== "q")
  {
    tell_object(ob, "%^ORANGE%^Rumour abandoned. Feel free to start over");
    return;
  } 
  switch(lower_case(str))
  {
  case "city":
    tell_object(ob, "%^ORANGE%^Okay, it's going to be a city rumour");
    type = CITY_SOURCE;
    break;
  case "wild":
    tell_object(ob, "%^ORANGE%^Okay, it's going to be a rumour passing among the wild folk");
    type = WILD_SOURCE;
    break;
  case "beast":
    tell_object(ob, "%^ORANGE%^Okay, it's going to be a rumour passing among the beast races");
    type = BEAST_SOURCE;
    break;
  default:
    tell_object(ob, "%^ORANGE%^I didn't understand that. Defaulting to a city rumour");
    type = CITY_SOURCE;
    break;
  }
  call_out("confirm_rumour",1, name, type, surface, detail, secret, ob);
}


void amend_surface(string str, string name, int type, string detail, string secret, object ob){
  string plainstr;
  if (!objectp(ob)) return;
  if (!stringp(str) || strlen(str)<1)
  {
    tell_object(ob, "%^BOLD%^%^WHITE%^Please enter the basic details of the rumour you want to start about " + name + " - or 'Q' if you want to abandon the rumour you were writing completely");
    input_to("amend_surface", 0, name, detail, secret, ob);
    return;
  } 
  if (lower_case(str)== "q")
  {
    tell_object(ob, "%^ORANGE%^Rumour abandoned. Feel free to start over");
    return;
  } 
  plainstr = strip_colors(str);
  if (strlen(plainstr)>300)
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, that's too much information. Please try again, using 300 characters or fewer");
    input_to("amend_surface", 0, name, detail, secret, ob);
    return;
  }
  tell_object(ob, "%^BOLD%^%^WHITE%^Got it. Amending the surface details of the rumour");
  call_out("confirm_rumour",1, name, type, str, detail, secret, ob);
}

void amend_detail(string str, string name, int type, string surface, string secret, object ob){
  string plainstr;
  if (!objectp(ob)) return;
  if (!stringp(str) || strlen(str)<1)
  {
    tell_object(ob, "%^BOLD%^%^WHITE%^Got it. No further details about the rumour available at this time.");
    call_out("confirm_rumour",1, name, type, surface, str, secret, ob);
    return;
  } 
  if (lower_case(str)== "q")
  {
    tell_object(ob, "%^ORANGE%^Rumour abandoned. Feel free to start over");
    return;
  } 
  plainstr = strip_colors(str);
  if (strlen(plainstr)>600)
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, that's too much information, even for the deeper details of the rumour. Please try again, using 600 characters or fewer");
    input_to("amend_detail", 0, name, surface, secret, ob);
    return;
  }
  tell_object(ob, "%^BOLD%^%^WHITE%^Got it. Amending the deeper details of the rumour");
  call_out("confirm_rumour",1, name, type, surface, str, secret, ob);
}

void amend_secret(string str, string name, int type, string surface, string detail, object ob){
  string plainstr;
  if (!objectp(ob)) return;
  if (!stringp(str) || strlen(str)<1)
  {
    tell_object(ob, "%^BOLD%^%^WHITE%^Got it. No secret information about the rumour available at this time.");
    call_out("confirm_rumour",1, name, type, surface, detail, str, ob);
    return;
  } 
  if (lower_case(str)== "q")
  {
    tell_object(ob, "%^ORANGE%^Rumour abandoned. Feel free to start over");
    return;
  } 
  plainstr = strip_colors(str);
  if (strlen(plainstr)>600)
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, that's too much information, even for the secret details of the rumour. Please try again, using 600 characters or fewer");
    input_to("amend_secret", 0, name, type, surface, detail, ob);
    return;
  }
  tell_object(ob, "%^BOLD%^%^WHITE%^Got it. Amending the secret information about this rumour");
  call_out("confirm_rumour",1, name, type, surface, detail, str, ob);
}


void enter_editor(string str){
  string word1, rest, name, list, response, rum_type, tracing, investigating, source_type, result;
  int num, rumour_no, room_type, gossipping;
  mixed * rum;
  num = sscanf(str, "%s %s", word1, rest);
  if (num<2) { 
    rest = "";
    word1 = str;
  }
  report("Entering editor. str = " + str + " word1 = " + word1);
  switch(lower_case(word1)){
  case "q":
    tell_object(TP, "%^ORANGE%^OK, exiting gossip commands");
    return;
  case "remove":
    if (!avatarp(TP)){
      break;
    }
    num = sscanf(rest, "rumour %d for %s", rumour_no, name);
    if (num <2)
    {
      num = sscanf(rest, "rumor %d for %s", rumour_no, name);
      if (num <2) 
      {
        num = sscanf(rest, "rumor %d about %s", rumour_no, name);
        if (num <2) 
        {
          tell_object(TP, "%^BOLD%^%^WHITE%^I didn't understand that. The syntax to remove a rumour is: %^RESET%^'remove rumour # for [name]'");
          return;
        }
      }
    }
    num = RUMOURS_D->remove_rumour(name, rumour_no);
    switch(num)
    {
    case -2:
    case -1: //deliberately falling through
      tell_object("Sorry, there do not seem to be any rumours for " + name);
      return;
      break;
    case 1:
      tell_object(TP, "Rumour successfully removed");
      return;
      break;
    }
    break;
  case "plant":
    if (!avatarp(TP) && !TP->query_true_invis()) break;
    tell_object(TP, "%^BOLD%^%^WHITE%^Ooh sneaky - who would you like this rumour to seem to have been started by?");
    input_to("plant_rumour",0);        
    return;
    break;
  case "background":
    report("Background check. Checking whether TP knows themselves");
    if (!TP->isKnown(TPQN)) 
    {
      tell_object(TP, "Sorry, you have not yet recognized yourself. As rumours"
        +" about yourself work on the name you have recognized yourself by,"
        +" you'll have to do that first. ");
      return;
    }
    name = TP->knownAs(TPQN);
    report("TP Does indeed know themselves, as " + name);
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, let's get started with a%^RESET%^%^ORANGE%^"
      +" background%^BOLD%^%^WHITE%^ rumour for your character. Since you have"
      +" recognized yourself as %^RESET%^" + capitalize(name) + "%^BOLD%^%^WHITE%^,"
      +" that is the name this rumour will be attributed to."
    +"\n%^BOLD%^%^WHITE%^Now, where would someone be most likely to hear about this bit of your"
    +" background?"
    +"\n%^BOLD%^%^WHITE%^City   %^RESET%^-%^ORANGE%^ In human, elf and dwarf cities"
    +"\n%^GREEN%^Wild   %^RESET%^-%^ORANGE%^ Among the people of the wilds - rangers, druids, barbarians and the like" 
    +"\n%^ORANGE%^B%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^a%^GREEN%^s%^ORANGE%^t  %^RESET%^-%^ORANGE%^ Among the beast races of the Realms"
    +"\n%^RESET%^Or enter 'Q' to quit");
    input_to("rumour_type", 0, name, "background");
    return;
    break;
  case "check":
    room_type = RUMOURS_D->check_room_source_type(ETP);
    switch (room_type)
    {
    case CITY_SOURCE:
      source_type = "rumours circulating in the %^ORANGE%^cities%^RESET%^ of %^MAGENTA%^humans%^RESET%^ and their allies";
      break;
    case WILD_SOURCE:
      source_type = "rumours circulating among the %^BOLD%^%^GREEN%^w%^RESET%^%^GREEN%^i%^BOLD%^ld%^RESET%^%^GREEN%^ folk";
      break;
    case BEAST_SOURCE:
      source_type = "rumours circulating among the %^BOLD%^%^BLACK%^b%^RESET%^%^MAGENTA%^e%^BLUE%^a%^BOLD%^%^BLACK%^st races";
      break;
    default:
      source_type = "none";
    }
    if (source_type == "none") 
    {
      result = "You think you are unlikely to come across rumours of any type in this place.";
    } else
    {
      result = "You think that this is the sort of place you might come across " + source_type;
    }
    if (TP->query_property("tracing"))
    {
      tracing = TP->query_property("tracing");
      num = sscanf(tracing, "%s_%d", word1, rumour_no);
      result += "\nYou are currently trying to find out who might have started rumour number " + rumour_no + " about " + capitalize(word1);
    }
    if (TP->query_property("investigating"))
    {
      investigating = TP->query_property("investigating");
      num = sscanf(investigating, "%s_%d", word1, rumour_no);
      if (num ==2)
      {
        result += "\nYou are currently trying to find out more detail about rumour number " + rumour_no + " about " + capitalize(word1);
      } else
      {
        result += "\nYou are currently trying to dig up some gossip about " + capitalize(investigating);
      } 
    }
    if (!TP->query_property("investigating") && !TP->query_property("tracing"))
    {
      if (TP->query_property("gossipping"))
      {
        result += "\nYou are currently gossipping at random";
      } else
      {    
        report("Query_property('gossipping') is not valid");  
        result += "\nYou are not currently gossipping";
      }
    }
    tell_object(TP, result);
    return 1;
    break;
  case "edit":
    if (!avatarp(TP) && !TP->query_true_invis()) break;
    num = sscanf(rest, "rumour %d about %s", rumour_no, name);
    if (num !=2)
    {
      num = sscanf(rest, "rumor %d about %s", rumour_no, name);
      if (num !=2)
      {
        tell_object(TP, "%^BOLD%^%^WHITE%^Which rumour do you want to edit? %^RESET%^Syntax is: %^CYAN%^'edit rumour # about [name]'");
        input_to("enter_editor", 0);
      }
    }
    rum = RUMOURS_D->query_rumour(name, rumour_no);
    if (!arrayp(rum) || sizeof(rum)<1)
    {
      tell_object(TP, "Sorry, unable to retrieve rumour number " + rumour_no + " about " + capitalize(name) + ". Please use the list command to check you have used the right number. If you are sure you have, please make a bug report, reminding Lujke about the importance of mental stability in a genius");
      return;
    } 
    display_rumour(TP, rum);
    tell_object(TP, "%^WHITE%^Which bit of the rumour would you like to edit? Options are:\n");
    tell_object(TP, "%^RESET%^Subject         True name(of subject)  Rumour type (City, wild or beast)\n"
                   +"Instigator(s)   Traction               Date\n"             
                   +"Surface         Detail                 Secret");
    input_to ("edit_rumour", 0, rum);
    return;
    break;
  case "gossip":
    if (rest != "at random")
    {
      tell_object(TP, "I didn't understand that. Try again - perhaps you meant 'gossip at random'?");
      input_to("enter_editor", 0);
      return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////Remove this section to make gossip completely live for players /////////////////////
//                                                                                                    //
//    if (!avatarp(TP) && !TP->query_true_invis())                                                    //
//    {                                                                                               //
//      tell_object(TP, "%^BOLD%^%^CYAN%^Sorry, that gossip function is not open for players yet\n"   //
//                     +"At the moment, you can only use 'start rumour' and 'background' to \n"       // 
//                     +"set rumours up. You won't be able to find any out until there are enough"    //
//                     +"recorded to make the system viable");                                        //
//      return;                                                                                       //
//    }                                                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
    room_type = RUMOURS_D->check_room_source_type(ETP);
    switch(room_type)
    {
    case CITY_SOURCE:
      rum_type = "circulating in the cities of humans and their allies";
      break;
    case WILD_SOURCE:
      rum_type = "circulating amongst the wild folk";
      break;
    case BEAST_SOURCE:
      rum_type = "circulating among the beast races of the realms";
      break;
    case -1:
      tell_object(TP, "Unfortunately, this does not seem like the sort of place you are likely to pick up any rumours");
      return;
      break;
    }
    tell_object (TP, "You set about gossipping and casually hearing what stories are " + rum_type);
    if (TP->query_property("tracing")) TP->remove_property("tracing");
    if (TP->query_property("investigating")) TP->remove_property("investigating");
    if (TP->query_property("gossipping")) TP->remove_property("gossipping");
    TP->set_property("gossipping", room_type);
    return; 
    break;
  case "start":
    tell_object(TP, "%^BOLD%^%^WHITE%^Who are you starting a rumour about? Give"
      +" a name you have recognized"
      +" someone by, or 'myself' if the rumour is about you.%^RESET%^\nNote: if you"
      +" are starting the rumour about yourself, it will be set for the name you"
      +" have recognized yourself by");
    input_to("start_rumour",0);        
    return;
    break;
  case "recall":
    if (rest == "rumours")
    {
      RUMOURS_D->recall_rumours(TP);
      return;
    }
    num = sscanf(rest, "rumours about %s", name);
    if (num <1) 
    {
      num = sscanf(rest, "rumors about %s", name);
      if (num <1){
        num = sscanf(rest, "rumour %d about %s", rumour_no, name);  
        if (num == 2){
          recall_rumour_about(name, rumour_no, TP->query_true_name());
          return;
        }  else 
        {
          num = sscanf(rest, "rumor %d about %s", rumour_no, name);  
          if (num == 2){
            recall_rumour_about(name, rumour_no, TP->query_true_name());
            return;
          }
        }
      } else
      {
        recall_rumours_about(name);
        return;
      }
    } else {
      recall_rumours_about(name);
      return;
      break;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^What do you want to recall? %^RESET%^%^ORANGE%^Options are:\n"
                   +"  'recall rumours about [name]'   - lists all the rumours you've heard about that person\n"
                   +"  'recall rumour # about [name'   - gives the full details of a particular rumour\n\n"
                   +"OR type 'Q' to quit");
    input_to("enter_editor", 0);
    return;
    break;
  case "list":
    report("Case: list");
    if (rest == "rumour subjects" || rest == "rumor subjects")
    {
      report("Trying to list heard rumour subjects");
      list = list_heard_rumour_subjects(TPQN);
      tell_object(TP, list);
      return; 
      break;
    }
    if (!avatarp(TP) && !TP->query_true_invis())
    {
      report("Someone not an avatar is trying to list all the rumours. Naughty!");
      break;
    }
    num = sscanf(rest, "rumours about %s", name);
    if (num <1)
    {
      num = sscanf(rest, "rumors about %s", name);    
      if (num <1){
        response = "%^BOLD%^%^WHITE%^What are you trying to list? Options are:\n"
                    +"               'list rumour subjects'\n";
        if (avatarp(TP) || TP->query_true_invis())
        {
          response += "%^ORANGE%^Avatar option: %^RESET%^'list rumours about [name]'\n";
        }
        response += "Or type 'q' to quit";
        tell_object(TP, response);
        input_to("enter_editor", 0); 
        return;
        break;
      }
    }
    report("Generating list of rumours about " + name);
    response = list_rumours_about(name);
    tell_object(TP, response); 
    return;
    break;


  case "trace":
    if (!stringp(rest) || strlen(rest)<1)
    {
      tell_object(TP, "Trace what?");
      tell_object(TP, list_commands());
      return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////Remove this section to make gossip completely live for players /////////////////////
//                                                                                                    //
//    if (!avatarp(TP) && !TP->query_true_invis())                                                    //
//    {                                                                                               //
//      tell_object(TP, "%^BOLD%^%^CYAN%^Sorry, that gossip function is not open for players yet\n"   //
//                     +"At the moment, you can only use 'start rumour' and 'background' to \n"       // 
//                     +"set rumours up. You won't be able to find any out until there are enough"    //
//                     +"recorded to make the system viable");                                        //
//      return;                                                                                       //
//    }                                                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
    num = sscanf(rest, "rumour %d about %s", rumour_no, name);
    if (num ==2)
    {
      trace_rumour(name, rumour_no, TP);
      return;
      break;
    } else {
      num = sscanf(rest, "rumor %d about %s", rumour_no, name);
      if (num ==2)
      {
        trace_rumour(name, rumour_no, TP);
        return;
        break;
      }
    }


  case "dig":
    if (!stringp(rest) || strlen(rest)<1)
    {
      tell_object(TP, "Dig what?");
      tell_object(TP, list_commands());
      return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////Remove this section to make gossip completely live for players /////////////////////
//                                                                                                    //
//    if (!avatarp(TP) && !TP->query_true_invis())                                                    //
//    {                                                                                               //
//      tell_object(TP, "%^BOLD%^%^CYAN%^Sorry, that gossip function is not open for players yet\n"   //
//                     +"At the moment, you can only use 'start rumour' and 'background' to \n"       // 
//                     +"set rumours up. You won't be able to find any out until there are enough"    //
//                     +"recorded to make the system viable");                                        //
//      return;                                                                                       //
//    }                                                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
    num = sscanf(rest, "further into rumour %d about %s", rumour_no, name);
    if (num ==2)
    {
      dig_further_into(rumour_no, name, TP);
      return;
      break;
    } else {
      num = sscanf(rest, "further into rumor %d about %s", rumour_no, name);
      if (num ==2)
      {
        dig_further_into(rumour_no, name, TP);
        return;
        break;
      }
    }
    num = sscanf(rest, "dirt on %s", name);
    if (num < 1) 
    {
      tell_object(TP, "Dig what?");
      cmd_gossip();
      input_to("enter_editor",0);
      return;
    }
    dig_dirt_on(name, TP);
    return;
    break;


  case "circulate":
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////Remove this section to make gossip completely live for players /////////////////////
//                                                                                                    //
//    if (!avatarp(TP) && !TP->query_true_invis())                                                    //
//    {                                                                                               //
//      tell_object(TP, "%^BOLD%^%^CYAN%^Sorry, that gossip function is not open for players yet\n"   //
//                     +"At the moment, you can only use 'start rumour' and 'background' to \n"       // 
//                     +"set rumours up. You won't be able to find any out until there are enough"    //
//                     +"recorded to make the system viable");                                        //
//      return;                                                                                       //
//    }                                                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
    num  = sscanf(rest, "rumour %d about %s", rumour_no, name);
    if (num ==2)
    {
      if (!RUMOURS_D->can_gossip(TPQN, TP->query_skill("influence")))
      {
        if (avatarp(TP) || TP->query_tue_invis())
        {
          tell_object(TP, "As an imm, you can circulate as many rumours as you want. Otherwise you'd be out of tries by now");
        } else 
        {
          tell_object("You've done all the muck spreading you can manage with your level of influence for the moment. Try again later");
          return;
        }
      }
      circulate_rumour(rumour_no, name, TP);
      return;
    } else 
    {
      tell_object(TP, "%^BOLD%^%^WHITE%^Which rumour do you want to circulate?\n%^RESET%^%^ORANGE%^Syntax is: %^RESET%^'circulate rumour # about [name]'");
      input_to("enter_editor", 0);
      return;
    }
    break;
  case "quash":
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////Remove this section to make gossip completely live for players /////////////////////
//                                                                                                    //
//    if (!avatarp(TP) && !TP->query_true_invis())                                                    //
//    {                                                                                               //
//      tell_object(TP, "%^BOLD%^%^CYAN%^Sorry, that gossip function is not open for players yet\n"   //
//                     +"At the moment, you can only use 'start rumour' and 'background' to \n"       // 
//                     +"set rumours up. You won't be able to find any out until there are enough"    //
//                     +"recorded to make the system viable");                                        //
//      return;                                                                                       //
//    }                                                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
    num  = sscanf(rest, "rumour %d about %s", rumour_no, name);
    if (num ==2)
    {
      if (!RUMOURS_D->can_gossip(TPQN, TP->query_skill("influence")))
      {
        if (avatarp(TP) || TP->query_tue_invis())
        {
          tell_object(TP, "As an imm, you can quash as many rumours as you want. Otherwise you'd be out of tries by now");
        } else 
        {
          tell_object("You've done all the intervening in gossip you can manage with your level of influence for the moment. Try again later");
          return;
        }
      }
      quash_rumour(rumour_no, name, TP);
      return;
    } else 
    {
      tell_object(TP, "%^BOLD%^%^WHITE%^Which rumour do you want to quash?\n%^RESET%^%^ORANGE%^Syntax is: %^RESET%^'quash rumour # about [name]'");
      input_to("enter_editor", 0);
      return;
    }
    break;
  }
  tell_object(TP, "I'm sorry, that's not one of your options for gossipping. Please try again. See 'help gossip' for available commands");
  return;
}

void display_rumour(object ob, mixed * rum){
  string subject, source_type, surface, detail, secret, * insts, inst, true_name, instigators, date_string;
  int traction, rumour_no, when;
  subject = rum[RUMOUR_SUBJECT];
  when = rum[TIME];
  true_name = rum[TRUENAME];
  insts = rum[INSTIGATOR];
  rumour_no = rum[RUMOUR_NUMBER];
  traction = rum[TRACTION];
  surface = rum[SURFACE];
  detail = rum[DETAIL];
  secret = rum[SECRET];
  instigators = "";
  foreach(inst in insts){
    instigators += inst + ", ";
  }
  if (strlen(instigators) > 2) instigators = instigators[0..strlen(instigators)-3];
  switch(rum[SOURCE_TYPE])
  {
  case CITY_SOURCE:
    source_type = "%^BOLD%^%^WHITE%^City%^RESET%^";  
    break;
  case WILD_SOURCE:
    source_type = "%^RESET%^%^GREEN%^W%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ld%^RESET%^";
    break;
  case BEAST_SOURCE:
    source_type = "%^RESET%^%^MAGENTA%^B%^BLUE%^e%^ORANGE%^a%^MAGENTA%^st%^RESET%^";
    break;
  }  
 
  date_string = "%^BOLD%^%^RED%^" + hour(when)+"%^RESET%^:%^BOLD%^%^RED%^"+(minutes(when)/10);
  date_string +=(minutes(when)%10) +" %^BOLD%^%^BLUE%^"+day(when)+", ";
  date_string += date(when)+" "+month(when)+"%^RESET%^, %^BOLD%^%^GREEN%^"+year(when)+" SG%^RESET%^";
  tell_object(ob, "%^RESET%^%^CYAN%^Subject: %^RESET%^" + capitalize(subject) + "   %^CYAN%^Rumour Number: %^RESET%^" + rumour_no + "   %^CYAN%^Subject's true name: %^RESET%^" + capitalize(true_name) );
  tell_object(ob, "%^RESET%^%^CYAN%^Rumour type: %^RESET%^" + source_type + "    %^CYAN%^Traction score: %^RESET%^"+ traction + "\n%^CYAN%^When created: %^RESET%^" + date_string);
  tell_object(ob,  "%^RESET%^%^CYAN%^Rumour instigators: %^RESET%^" + instigators + "\n\n"); 
  tell_object(ob, "%^RESET%^%^CYAN%^Surface level of rumour:%^RESET%^\n" + surface + "\n\n"); 
  tell_object(ob, "%^RESET%^%^CYAN%^Further details of rumour:%^RESET%^\n" + detail + "\n\n");
  tell_object(ob, "%^RESET%^%^CYAN%^Secret information about rumour:%^RESET%^\n" + secret + "\n\n");
}

varargs void edit_rumour2(string str, mixed * rum, string aspect_changed, string previous_subject){
  int ASPECT, trac;
  mixed what;
  what = str;
  report("edit_rumour2 aspect_changed: " + aspect_changed);
  switch(aspect_changed)
  {
  case "subject":
    ASPECT = RUMOUR_SUBJECT;
    break;
  case "true name":
    ASPECT = TRUENAME;
    break;
  case "rumour type":
  case "rumor type":
    ASPECT = SOURCE_TYPE;
    switch(lower_case(str))
    {
    case "city":
      what = CITY_SOURCE;
      break;
    case "wild":
      what = WILD_SOURCE;
      break;
    case "beast":
      what = BEAST_SOURCE;
      break;
    }
    break;
  case "instigator":
  case "instigators":
    ASPECT = INSTIGATOR;
    what = explode(str, " ");
    return;
    break;
  case "traction":
    ASPECT = TRACTION;
    report("amending traction.str:'" + str +"'");
    trac = atoi(str);
    break;
  case "date":
    ASPECT = TIME;
    what = rum[TIME] + atoi(str)*24000;
    break;
  case "surface":
    ASPECT = SURFACE;
    break;
  case "detail":
    ASPECT = DETAIL;
    break;
  case "secret":
    ASPECT = SECRET;
    break;
  }
  if (ASPECT == TRACTION)
  {
    report ("%^BOLD%^%^GREEN%^Setting rumour[" + ASPECT + "] to " + trac);
    rum[ASPECT] = trac;
  } else
  {
    report ("%^BOLD%^%^MAGENTA%^ASPECT: " + ASPECT + " TRACTION: " + TRACTION);
    rum[ASPECT] = what;
  }
  RUMOURS_D->save_rumour(rum);
  tell_object(TP, "%^BOLD%^%^WHITE%^Okay, the rumour now looks like this:");
  display_rumour(TP, rum);
  tell_object(TP, "%^WHITE%^Do you want to edit another part of the rumour? Options are:\n");
  tell_object(TP, "%^RESET%^Subject         True name(of subject)  Rumour type (City, wild or beast)\n"
                   +"Instigator(s)   Traction               Date\n"             
                   +"Surface         Detail                 Secret\n"
                   +"%^BOLD%^%^WHITE%^Or type anything else to exit");
  input_to ("edit_rumour", 0, rum, previous_subject);
}


varargs void edit_rumour(string str, mixed * rum, string previous_subject){
  switch(lower_case(str))
  {
  case "subject":
    if(stringp(previous_subject) && strlen(previous_subject)>0 && previous_subject != rum[RUMOUR_SUBJECT])
    {
      tell_object(TP, "You have already amended the subject to " + rum[RUMOUR_SUBJECT] + ". Changing it again will confuse the editor. Please finish this edit, then use the edit rumour command again using the new subject name if you want to change it again.");
      break;
    } 
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, who would you like the new subject of the rumour to be? - This should be the name that the person starting the rumour knows them by");
    input_to("edit_rumour2",0,rum, str, rum[RUMOUR_SUBJECT]);
    return;
    break;
  case "true name":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, who would you like the new truename of the subject of the rumour to be? - This is the actual character name, the one they log in with");
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  case "rumour type":
  case "rumor type":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, what sort of rumour would you like this to be? - City, Wild or Beast");
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  case "instigator":
  case "instigators":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, who would you to appear to have started the rumour? You can enter one name, or several separated by spaces ('lujke kassius nienne octothorpe')");
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  case "traction":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, what would you like the new traction score of the rumour to be? (current score is " + rum[TRACTION] +")");
    input_to("edit_rumour2",0,rum, lower_case(str), previous_subject);
    return;
    break;
  case "date":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, how many days would you like to adjust the rumour start date by? (Enter a positive integer to bring the date forward, or a negative to push it back");
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  case "surface":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, who would you like the %^RESET%^%^ORANGE%^surface%^BOLD%^%^WHITE%^ level of the rumour to be? It currently reads: \n" + rum[SURFACE]);
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  case "detail":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, who would you like the %^BLUE%^%^detailed%^WHITE%^ information of the rumour to be? It currently reads: \n" + rum[DETAIL]);
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  case "secret":
    tell_object(TP, "%^BOLD%^%^WHITE%^Okay, who would you like the %^CYAN%^secret%^WHITE%^ level of the rumour to be? It currently reads: \n" + rum[SECRET]);
    input_to("edit_rumour2",0,rum, str, previous_subject);
    return;
    break;
  default:
    if (!stringp(str) || strlen(str)<1) str = "That";
    tell_object(TP, str + " is not a valid aspect of the rumour. Exiting editor");
    if(stringp(previous_subject) && strlen(previous_subject)>0 && previous_subject != rum[RUMOUR_SUBJECT]) 
    {
      report("subject has changed. Getting rid of previous rumour. Rumour name: " + previous_subject + " Rumour number: " + rum[RUMOUR_NUMBER]);
      RUMOURS_D->remove_rumour(previous_subject, rum[RUMOUR_NUMBER]);
    } else {
      report("exiting editor. Rumour subject has not changed");
    }
    return;
  } 
}

void plant_rumour(string str){
  if (!stringp(str))
  {
    tell_object(TP, "%^ORANGE%^No really, who would you like the rumour to seem to have been started by?");
    input_to("plant_rumour", 0);
  }
  tell_object(TP, "%^BOLD%^%^WHITE%^Okay, so it will seem like %^RESET%^%^ORANGE%^"+ capitalize(str) + " %^BOLD%^%^WHITE%^started this rumour. Who will the rumour be about?");
  input_to("start_rumour", 0, str);
}

void circulate_rumour(int num, string name, object ob){
  report ("About to circulate rumour. Num: " + num + " name: " + name + " Circulator: " + ob->QCN);
  RUMOURS_D->circulate_rumour(num, name, ob);
}

void quash_rumour(int num, string name, object ob){
  report ("About to quash rumour. Num: " + num + " name: " + name + " Circulator: " + ob->QCN);
  RUMOURS_D->quash_rumour(num, name, ob);
}


void dig_further_into(int rumour_no, string name, object ob){
  string investigation_target, * subjects;
  int nums;
  mapping my_rumours, my_rumours_about_subject;
  my_rumours = RUMOURS_D->query_heard_rumours(ob->query_name());
  if (!mapp(my_rumours) || sizeof(my_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours, so there's nothing for you to dig any further into. You need to get out and listen to some basic gossip first");
    return;
  }
  subjects = keys(my_rumours);
  if (member_array(name, subjects)==-1)
  {
    tell_object(ob, "You haven't heard any rumours about " + capitalize(name) + ", so there's nothing for you to dig any further into. Wait until you've started to hear things about them.");
    return;
  }
  my_rumours_about_subject = my_rumours[name];
  if (!mapp(my_rumours_about_subject) || sizeof(my_rumours_about_subject)<1)
  {
    tell_object(ob, "You haven't heard any rumours about " + capitalize(name) + ", so there's nothing for you to dig any further into. Wait until you've started to hear things about them.");
    return;    
  }
  nums = keys(my_rumours_about_subject);
  if (sizeof(nums)<1 || member_array(rumour_no, nums)==-1)
  {
    tell_object(ob, "You haven't heard a rumour numbered " + rumour_no + " in relation to " + capitalize(name) + ", so you can't dig further into it. Check your list of heard rumours about them for a valid number, and try again."); 
    return;
  }
  investigation_target = name + "_" + rumour_no;
  tell_object(ob, "%^CYAN%^You set about investigating more information about rumour " + rumour_no + " in relation to %^BOLD%^%^WHITE%^" + capitalize(name));
  if (ob->query_property("tracing")) ob->remove_property("tracing");
  if (ob->query_property("investigating")) ob->remove_property("investigating");
  if (ob->query_property("gossipping")) ob->remove_property("gossipping");
  ob->remove_property("gossipping");
  ob->set_property("investigating", investigation_target);
  ob->set_property("gossipping",investigation_target);
 
} 

string list_rumours_about(string subject){
  string result, surface, line, col;
  mapping rums, rum;
  int * nums, num, i, type, count;
  rums = RUMOURS_D->query_rumours(subject);
  if (!mapp(rums) || sizeof(rums)<1) return "There are no rumours in circulation about anyone called " + subject;
  result = "";                                                                  
  nums = keys(rums);
  foreach(num in nums)
  {
    rum = RUMOURS_D->query_rumour(subject, num);
    count = sizeof(rum);
    if (count>0) 
    {
      report("Loaded a rumour. Elements are: ");
      for (i=0;i<count;i++){
        if (stringp(rum[i])){
          report("Element " +  i + ": " + rum[i]);
        } else 
        {
          report("element " + i + " is not a string");
        }
      }
    } else {
      report("%^BOLD%^%^CYAN%^Rumour loaded is not valid");
    }
    type = rum[SOURCE_TYPE];
    switch(type)
    {
    case CITY_SOURCE:
      col = "%^BOLD%^%^WHITE%^";
      break;
    case WILD_SOURCE:
      col = "%^RESET%^%^GREEN%^";
      break;
    case BEAST_SOURCE:
      col = "%^RESET%^%^MAGENTA%^";
      break;
    }
    line  = col;
    line += num;
    if (num<1000) line += " ";
    if (num<100) line += " ";
    if (num<10) line += " ";
    line += "       ";
    surface = rum[SURFACE];
    if (strlen(surface) >29)
    {
      line += surface[0..28]; 
    } else
    {
      line += surface;
      num = 29 - strlen(surface);
      for(i=0;i<num;i++)
      {
        line += " ";
      }
    }
    line += "     ";
    if (strlen(rum[DETAIL])>0)
    {
      line += "Y";
    } else 
    {
      line += " ";
    }
    line += "              ";
    if (strlen(rum[SECRET])>0)
    {
      line += "Y";
    } else 
    {
      line += " ";
    }
    line += "        ";
    switch(type)
    {
      case CITY_SOURCE:
        line += "%^BOLD%^%^WHITE%^City";
        break;
      case WILD_SOURCE:
        line += "%^BOLD%^%^GREEN%^Wild";
        break;
      case BEAST_SOURCE:
        line += "%^MAGENTA%^Beast";
        break;
    }
    line += "%^RESET%^\n";
    if (strlen(surface) >29)
    {
      line += col + "           ";
      if (strlen(surface)>58)
      {
        line += surface[29..57];
      } else {
//        line += surface;
      }
      if (strlen(surface)<59) line += "\n";
    }
    line += "%^RESET%^\n";
    if (strlen(surface) >58)
    {
      line += col + "           ";
      if (strlen(surface)>87)
      {
        line += surface[58..86];
      } else {
 //       line += surface;
      }
      line += "\n";
    }
    result = line + result;
  }
  result = "%^ORANGE%^Rumours currently in circulation about %^BOLD%^%^WHITE%^" + capitalize(subject) + "%^RESET%^%^ORANGE%^:\n"
    +"Rumour no  Surface details               Further info? Secret info?  Type\n" + result;
  return result;
}

varargs void recall_rumours_about(string name, string recaller){
  mapping heard_rums, rums;
  mixed * heard_rumour, * rumour;
  string * recallers, * subjects, result, surface;
  int * nums, num, lvl, width, rumour_num;
  width = atoi(TP->getenv("SCREEN"));
  if (width<15) width = 70; 
  if (!stringp(recaller)) recaller = TPQN;
  heard_rums = RUMOURS_D->get_my_heard_rumours(recaller);
  if(!mapp(heard_rums) || sizeof(heard_rums)<1){
    report(recaller + "'s list of heard rumours is empty");
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours. Get out there and talk to some people. See 'help gossip' for information about how to stumble across rumours.");
    return;
  }
  subjects = keys(heard_rums);
  if (member_array(name, subjects)==-1){
    report (recaller + "'s list of heard rumours does not include any about " + name);
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours about " + name + ". See 'help gossip' for information about how to dig dirt on a particular person, if you want to find out more about them");
    return;
  }
  rums = heard_rums[name];
  if (!mapp(rums) || sizeof(rums) < 1){
    report (recaller + "'s list of heard rumours about " + name + " is empty");
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours about " + name + ". See 'help gossip' for information about how to dig dirt on a particular person, if you want to find out more about them");
    return;
  }
  nums = keys(rums);
  result = "%^ORANGE%^You know the following rumours about %^RESET%^" +name + "%^ORANGE%^:\n\n"
          +"%^ORANGE%^Rumour no      Details\n"; 
                        
  foreach(num in nums)
  {
    heard_rumour = rums[num];
    report("Checking heard rumour number " + num + " sizeof heard rumour: " + sizeof(heard_rumour));
    rumour = RUMOURS_D->query_rumour(name, heard_rumour[1]);
    surface = rumour[SURFACE]; 
    report("Rumour surface: " + surface);
    result += "" + num;
    if (num>100) result += " ";
    if (num<10) result += " ";
    if (strlen(surface) <= width-16)
    {
      result += "            " + surface +"\n"; 
    } else {
      result += "            " + surface[0..width - 18] + "...\n";
    }
  }
  tell_object(TP, result);
}

varargs void recall_rumour_about(string name, int no, string recaller){
  mapping heard_rums, rums;
  mixed * rum, * heard_rumour;
  string * recallers, * subjects, result, detail;
  int * nums, lvl, rumour_num;
  if (!stringp(recaller)) recaller = TP->query_true_name();
  report ("Trying to recall rumour number " + no +" about " + name + ", as recalled by " + recaller);
  heard_rums = RUMOURS_D->get_my_heard_rumours(recaller);
  if(!mapp(heard_rums) || sizeof(heard_rums)<1){
    report(recaller + "'s list of heard rumours is empty");
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours. Get out there and talk to some people. See 'help gossip' for information about how to stumble across rumours.");
    return;
  }
  report ("Got some heard rumours");
  subjects = keys(heard_rums);
  if (member_array(lower_case(name), subjects)==-1){
    report (recaller + "'s list of heard rumours does not include any about " + name);
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours about " + name + ". See 'help gossip' for information about how to dig dirt on a particular person, if you want to find out more about them");
    return;
  }
  rums = heard_rums[name];
  if (!mapp(rums) || sizeof(rums)<1)
  {
    report("%^BOLD%^%^CYAN%^Error 1 in void recall_rumour. Name used for recaller: " + recaller + "Name used for subject: " + name);
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours about " + name + ". See 'help gossip' for information about how to dig dirt on a particular person, if you want to find out more about them");
    return;
  }
  nums = keys(rums);
  if (sizeof(nums)<1)
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you can't recall hearing any rumours about " + name + ". See 'help gossip' for information about how to dig dirt on a particular person, if you want to find out more about them");
    return;
  }
  report ("Got some heard rumours about " + name);
  if (member_array(no, nums)==-1)
  {
    tell_object(TP, "%^BOLD%^%^WHITE%^Sorry, you haven't heard a rumour number " + no + " about " + name + ". Try typing 'gossip' then 'recall rumours about " + name + "' to see a list of the rumours you have heard about them.");
  }
  heard_rumour = rums[no];
  rum = RUMOURS_D->query_rumour(name, heard_rumour[1]);
  if (sizeof(rum)<1)
  {
    tell_object(TP, "Sorry, your memory is a bit fuzzy and you can't recall rumour number " + num + " about " + name + ". It might be worth making a bug report, in case something is going wrong with the rumour system, despite Lujke's very stable genius-ness");
    return;
  }
  result = "";
  lvl = heard_rumour[2];
  report ("Found a rumour. Rumour lvl heard is: " + lvl);
  switch(lvl)
  {
  case 3:
    result = "\n%^RESET%^%^ORANGE%^You have also discovered some interesting, secretive and hard to come across information, suggesting that:\n%^RESET%^" + rum[SECRET];
  case 2: //deliberately falling through;
    detail = rum[DETAIL];
    if (stringp(detail) && detail != ""){       
      result = "\n%^RESET%^%^ORANGE%^Further gossip has reached your ears that\n%^RESET%^" + rum[DETAIL] + "\n" + result;
    }
  case 1: //deliberately falling through
    result = "%^RESET%^%^ORANGE%^You have heard that:\n%^RESET%^" + rum[SURFACE] + "\n" + result + "\n";     
  } 
  tell_object(TP, result);
}

void dig_dirt_on(string name, object ob){
  int s_type;
  object room;
  string message;
  if (!objectp(ob)) return;
  room = environment(ob);
  if (!objectp(room))
  {
    tell_object(ob, "Error with the gossip command - you are not in a valid room. Please make a bug report");
    return;
  }
  s_type = RUMOURS_D->check_room_source_type(room);
  switch(s_type)
  {
  case CITY_SOURCE:
    message = "%^BOLD%^%^WHITE%^You set your ear to the %^RESET%^%^ORANGE%^rumour mill %^BOLD%^%^WHITE%^ to see if you can dig up any %^BOLD%^%^BLACK%^dirt%^WHITE%^ on ";
    break;
  case WILD_SOURCE:
    message = "%^BOLD%^%^GREEN%^You set your ear to the %^BOLD%^%^WHITE%^%^winds %^BOLD%^%^GREEN%^and check with the peoples of the %^RESET%^%^GREEN%^wild places%^BOLD%^%^GREEN%^to see if you can dig up any %^BOLD%^%^BLACK%^dirt%^GREEN%^ on ";
    break;
  case BEAST_SOURCE:
    message = "%^MAGENTA%^You set your ear to the %^RESET%^%^ORANGE%^rumour mill %^MAGENTA%^%^to see if you can dig up any %^BOLD%^%^BLACK%^dirt%^RESET%^%^MAGENTA%^ on ";
    break;
  default:
    tell_object(ob, "This is not a place where you'll have much luck picking up rumours. Try in urban areas, or in the wilds");
    return;
    break;
  }
  tell_object(ob, message + capitalize(name));
  if (ob->query_property("tracing")) ob->remove_property("tracing");
  if (ob->query_property("investigating")) ob->remove_property("investigating");
  if (ob->query_property("gossipping")) ob->remove_property("gossipping");
  ob->set_property("investigating",lower_case(name));
  ob->set_property("gossipping", s_type);
}

void trace_rumour(string name, int num, object ob){
  int s_type, * nums, rumour_num, rum_type;
  object room;
  string message, * subjects;
  mixed * heard_rum, rum;
  mapping my_heard_rumours, rumours_about_subject;
  if (!objectp(ob)) return;
  room = environment(ob);
  my_heard_rumours = RUMOURS_D->query_heard_rumours(ob->query_true_name());
  if (!mapp(my_heard_rumours) ||sizeof(my_heard_rumours)<1)
  {
    tell_object(ob, "You have not heard any rumours yet, so there's nothing for you to try to trace the source of");
    return;
  }
  subjects = keys(my_heard_rumours);
  if (member_array(name, subjects) == -1)
  {
    tell_object(ob, "You have not heard any rumours about " + capitalize(name) + ", so there's nothing for you to try to trace the source of");
    return;
  }
  rumours_about_subject = my_heard_rumours[name];
  if (!mapp(rumours_about_subject) ||sizeof(rumours_about_subject)<1)
  {
    tell_object(ob, "You have not heard any rumours about " + capitalize(name) + ", so there's nothing for you to try to trace the source of");
    return;
  }
  nums = keys(rumours_about_subject);
  if (member_array(num, nums) ==-1)
  {
    tell_object(ob, "You have not heard a rumour number " + num + " about " + capitalize(name) + ", so there's nothing for you to try to trace the source of");
    return;
  }  
  if (!objectp(room))
  {
    tell_object(ob, "Error with the gossip command - you are not in a valid room. Please make a bug report");
    return;
  }
  s_type = RUMOURS_D->check_room_source_type(room);
  heard_rum = rumours_about_subject[num];
  rum = RUMOURS_D->query_rumour(name, heard_rum[1]);
  if (sizeof(rum)<1)
  {
    tell_object(ob, "Sorry, there was an error finding the rumour that you are trying to trace. Please make a bug report");
    return;
  } 
  rum_type = rum[SOURCE_TYPE];
  if (rum_type != s_type)
  {
    report_wrong_type(s_type, rum_type, ob);
    return;
  }
  switch(s_type)
  {
  case CITY_SOURCE:
    message = "%^BOLD%^%^WHITE%^You set about the task of asking around to try to trace the source of the rumour ";
    break;
  case WILD_SOURCE:
    message = "%^BOLD%^%^GREEN%^You use your connections in the wild to try to track the rumour back to its source ";
    break;
  case BEAST_SOURCE:
    message = "%^MAGENTA%^You set about the task of tracing the source of the rumour ";
    break;
  default:
    tell_object(ob, "This is not a place where you'll have much luck picking up rumours. Try in urban areas, or in the wilds");
    return;
    break;
  }
  tell_object(ob, message);
  if (ob->query_property("tracing")) ob->remove_property("tracing");
  if (ob->query_property("investigating")) ob->remove_property("investigating");
  if (ob->query_property("gossipping")) ob->remove_property("gossipping");
  ob->set_property("tracing",lower_case(name) + "_" + num);
  ob->set_property("gossipping", s_type);
}

report_wrong_type(int s_type, int rum_type, ob){
  switch(rum_type)
  {
  case CITY_SOURCE: 
    tell_object(ob, "%^BOLD%^%^WHITE%^This rumour seems to have originated among the %^RESET%^city folk%^BOLD%^%^WHITE%^ of humans and their allies. If you want to trace its source, you'll have to check there");
    break;
  case BEAST_SOURCE:
    tell_object(ob, "%^BOLD%^%^WHITE%^This rumour seems to have originated among the %^RESET%^%^MAGENTA%^beast races%^BOLD%^%^WHITE%^ of the realms. To trace its source, you'll probably have to check in one of their cities");
    break;
  case WILD_SOURCE:
    tell_object(ob, "%^GREEN%^This rumour seems to have originated among the %^BOLD%^%^GREEN%^wild folk%^RESET%^%^GREEN%^ of the realms. To trace its source, you'll probably have to check in one of their cities");
    break;
  }
}
