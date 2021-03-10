// Avatar Universal Remote Control: condensing the many wands we have floating around.
// Thanks to Tristan, Garrett, Styx and Lujke for writing the original items merged here!
// Nienne, 02/08.
#include <std.h>
#include <langs.h>
#include <daemons.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("remote control");
   set_id(({"remote","control","remote control","shiney remote control","compx","psi_compx","climbing tool"}));
   set_short("%^BOLD%^%^WHITE%^A very shiney remote control");
   set_long("%^BOLD%^%^WHITE%^Welcome to the shiney new %^CYAN%^Avatar %^GREEN%^Universal %^YELLOW%^Remote "
"%^MAGENTA%^Control%^WHITE%^! Sick of filling your pockets with wands and sticks and devices? Can't remember "
"which button to push? No problem! With the new remote control you can have all your commands in the one handy "
"pocket-sized device. %^YELLOW%^Instructions %^WHITE%^are on a label on the back.%^RESET%^");
  set_read("%^BOLD%^%^RED%^ How to use -\n"
"%^YELLOW%^<here>%^WHITE%^ returns the filename of the room you are in.\n"
"%^YELLOW%^<agemod playername number>%^WHITE%^ will give the player an age modifier, number can be positive or negative.\n"
"%^YELLOW%^<setprop tpward/magicward/scryward>%^WHITE%^ to teleport, spell, or scry-proof a room.\n"
"%^YELLOW%^<remprop tpward/magicward/scryward>%^WHITE%^ to un-teleport, un-spell, or unscry-proof a room.\n"
"%^YELLOW%^<use wand on playername>%^WHITE%^ to clone their inventory on the ground with you (caution, don't use anywhere players might wander in).\n"
"%^YELLOW%^<clearprof playername profname>%^WHITE%^ to remove a redundant proficiency from the player. You may need to use fixprofs following this.\n"
"%^YELLOW%^<trylang playername>%^WHITE%^ to give a player a reroll chance for undercommon. One use only, select races only.\n"
"%^YELLOW%^<oldgrant playername amount>%^WHITE%^ grant players an amount of exp.\n"
"%^YELLOW%^<nwpbonus playername amount to nwpname>%^WHITE%^ grant players an amount of exp to an nwp.\n"
"%^YELLOW%^<deed playername deed>%^WHITE%^ add a deed to the list of accomplishments on a player. Usually good to test on yourself first.\n"
"%^YELLOW%^<pkflag playername on/off>%^WHITE%^ to add or remove a PKflag from a player.\n"
"%^YELLOW%^<dtflag playername on/off>%^WHITE%^ to add or remove a (downtime) PKflag from a player.\n"
"%^YELLOW%^<dflag playername off>%^WHITE%^ to remove a Dflag from a player.\n"
"%^YELLOW%^<lift (item) from (location)>%^WHITE%^ to steal item ('here' from floor).\n"
"%^YELLOW%^<setvalue item value cointype>%^WHITE%^ to change the price of an item.\n"
"%^YELLOW%^<convert 'persona'>%^WHITE%^ where persona is the name of the persona, will convert to the new class type.\n"
"%^YELLOW%^<force_forsake 'player' 'reason'>%^WHITE%^ this will force a player to leave their god without needing to be in their temple and without a timer before they can follow another one\n"
"%^YELLOW%^<fixfeats playername>%^WHITE%^ This will refund all of a player's feats and allow them to reassign for free. Do NOT use this unless the player has suffered buggy feats. Coded in response to the great spellcaster update bug of Sept 2015.%^RESET%^\n"
"%^YELLOW%^<addfeats <name> <number> %^WHITE%^This will add free feats to a player. Do NOT use this unless the player has suffered buggy feats. Coded in response to the great spellcaster update bug of Sept 2015.%^RESET%^\n");

  set_weight(0);
    set_limbs( ({ "right arm" }) );
    set_type("ring");
  set_value(0);
}

void init()
{
   ::init();
   if(objectp(ETO)) { if(!avatarp(ETO)) { TO->remove(); } };
   	add_action("wave_wand", "use");
   	add_action("setprop","setprop");
   	add_action("remprop","remprop");
   	add_action("files","here");
   	add_action("exp","oldgrant");
   	add_action("do_mark_deed","deed");
   	add_action("nwp_bonus","nwpbonus");
   	add_action("pk_flag", "pkflag");
   	add_action("dt_flag", "dtflag");
  	add_action("d_flag", "dflag");
  	add_action("lang_fun", "trylang");
  	add_action("clear_prof", "clearprof");
   	add_action("snag_stuff","lift");
   	add_action("set_the_value","setvalue");
  	add_action("convert","convert");
   	add_action("force_forsake","force_forsake");
	add_action("langs_set", "tongues");
    add_action("fix_em","fixfeats");
    add_action("add_em","addfeats");
    add_action("age_mod", "agemod");
}

int age_mod(string str)
{
    int modifier, cur_mod;
    object target;
    string pname;
    if(!stringp(str))
    {
        tell_object(ETO, "Try <agemod player number>");
        return 1;
    }
    if(sscanf(str, "%s %d", pname, modifier) != 2)
    {
        tell_object(ETO, "Try <agemod player number>");
        return 1;
    }
    if(!intp(modifier))
    {
        tell_object(ETO, "Try <agemod player number>");
        return 1;
    }
    target = find_player(pname);
    if(!objectp(target))
    {
        tell_object(ETO, "You are unable to find "+pname+" online.");
        return 1;
    }
    cur_mod = (int)target->query("age_modifier");
    if(intp(cur_mod))
    {
        tell_object(ETO, "Attempting to modify "+pname+"'s age by "+modifier+". They "+
        "currently have an age modifier of "+cur_mod+". "+modifier+" will be added to it.");
    }
    modifier += cur_mod;
    target->delete("age_modifier");
    target->set("age_modifier", modifier);
    tell_object(target, "%^BOLD%^%^WHITE%^Your age has been modified by "+ETO->query_name()+". If you believe "+
    "this was done in an abusive manner, please <mail law> and notify them of what happened.");
    tell_object(ETO, pname+"'s age has been modified by "+modifier+".");
    return 1;
}


int wave_wand(string str){
  string player_name, filename, obname, junk;
  object holder, target, room, * inv, *cont_inv, ob, new_ob, new_content, *critters;
  int i, j;
  holder = ETO;
  room = EETO;
  critters = all_living(EETO);
  if (sizeof(critters)>1){
    for (i=0;i<sizeof(critters);i++){
      if (interactive(critters[i]) && !critters[i]->query_true_invis() ){
        tell_object(TP, "You can't use this wand in a room where there are players, or even visible"
                       +" avatars. It dumps a copy of someone's whole inventory on the ground, so care"
                       +" is needed.");
        return 1;
      }
    }
  }
  if (sscanf(str, "wand on %s", player_name)<1){
    tell_object(holder, "Try 'use wand on <player>'");
    return 1;
  }
  if (!objectp(holder)||!objectp(room)){
    return 0;
  }
  target = find_player(player_name);
  if (!objectp(target)){
    tell_object(holder, str + " is not around at the moment");
    return 1;
  }
  if (!holder->query_true_invis()){
    tell_object(holder, "Don't be hasty! Only invisible immortals may use"
                       +" this wand.");
  }
  inv = all_inventory(target);
  if (sizeof(inv)>0){
    for (i=0;i<sizeof(inv);i++){
       ob = inv[i];
       obname = file_name(ob);
       sscanf(obname, "%s#%s", filename, junk);
//       filename+=".c"
       new_ob = new(filename);
       new_ob->move(room);
       cont_inv = all_inventory(ob);
       if (sizeof(cont_inv)>0){
         for (j=0;j<sizeof(cont_inv);j++){
           if (objectp(cont_inv[j])){
             obname = file_name(cont_inv[j]);
             sscanf(obname, "%s#%s", filename, junk);
//             filename+=".c"
             new_content = new(filename);
             new_content->move(new_ob);
           }
         }
       }
    }
  }
  tell_object(holder, player_name + "'s inventory cloned. Have fun with"
                                   +" it!");
  return 1;
}

int langs_set(string str)
{
	int i, num;
    string what;
    object ob;
	if(!str || str == ETO) str = TP->query_name();
	if(stringp(str))
	{
		if(!objectp(ob = find_player(str)))
		{
			tell_object(ETO, "No such player online.");
			return 1;
		}
		if(!avatarp(ob))
		{
			tell_object(ETO, "That player is not an avatar, not happening....");
			return 1;
		}

		for (i =0;i<sizeof(ALL_LANGS);i++)
		{
			ob->set_lang(ALL_LANGS[i],100);
		}
		tell_object(TP, "All Languages for "+ob->QCN+" set to 100");
		tell_object(ob, "All languages now set to 100");
		return 1;
	}
	else {
		write("You cannot do that!");
		return 1;
	}

}

int setprop(string str)
{
    object myroom;
    if(!avatarp(TP))
    {
        tell_object(TP,"Bad player. Bunnies dispatching now for stabbits.");
        TO->remove();
        return 1;
    }
    if(!str)
    {
        tell_object(TP,"Your arguments are <setprop tpward>, <setprop magicward>, or <setprop scryward>.");
        return 1;
    }
    if(str != "tpward" && str != "magicward" && str != "scryward")
    {
        tell_object(TP,"Your arguments are <setprop tpward>, <setprop magicward>, or <setprop scryward>.");
        return 1;
    }
    myroom = ETP;
    if(!objectp(myroom)) return 0;
    if(str == "tpward")
    {
        if((int)myroom->query_property("no teleport"))
        {
            tell_object(TP,"This room is already teleport proofed.");
            return 1;
        }
        tell_object(TP,"You have just set this room to no-teleport. You can <remprop tpward> to revoke it.");
        myroom->set_property("no teleport",1);
        return 1;
    }
    if(str == "scryward")
    {
        if((int)myroom->query_property("no scry"))
        {
            tell_object(ETO, "This room is already scry proof.");
            return 1;
        }
        tell_object(TP, "You have just set this room to no-scry. You can <remprop scryward> to revoke it.");
        myroom->set_property("no scry", 1);
        return 1;
    }
    if((int)myroom->query_property("no magic"))
    {
        tell_object(TP,"This room is already magic proofed.");
        return 1;
    }
    tell_object(TP,"You have just set this room to no-magic. You can <remprop magicward> to revoke it.");
    myroom->set_property("no magic",1);
    return 1;
}

int remprop(string str)
{
    object myroom;
    if(!avatarp(TP))
    {
        tell_object(TP,"Bad player. Bunnies dispatching now for stabbits.");
        TO->remove();
        return 1;
    }
    if(!str)
    {
        tell_object(TP,"Your arguments are <remprop tpward>, <remprop magicward>, or <remprop scryward>.");
        return 1;
    }
    if(str != "tpward" && str != "magicward" && str != "scryward")
    {
        tell_object(TP,"Your arguments are <remprop tpward>, <remprop magicward>, or <remprop scryward>.");
        return 1;
    }
    myroom = ETP;
    if(!objectp(myroom)) return 0;
    if(str == "tpward")
    {
        if(!(int)myroom->query_property("no teleport"))
        {
            tell_object(TP,"This room is not teleport proofed.");
            return 1;
        }
        tell_object(TP,"You have just revoked no-teleport on this room. You can <setprop tpward> to restore it.");
        myroom->remove_property("no teleport",1);
        return 1;
    }
    if(str == "scryward")
    {
        if(!(int)myroom->query_property("no scry"))
        {
            tell_object(ETO, "This room is not scry proof.");
            return 1;
        }
        tell_object(ETO, "You have just revoked no-scry on this room. You can <setprop scryward> to restore it.");
        myroom->remove_property("no scry");
        return 1;
    }
    if(!(int)myroom->query_property("no magic"))
    {
        tell_object(TP,"This room is not magic proofed.");
        return 1;
    }
    tell_object(TP,"You have just revoked no-magic on this room. You can <setprop magicward> to restore it.");
    myroom->remove_property("no magic",1);
    return 1;
}

int files(string str){
  string name;
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  write("%^BOLD%^The file name of this room is:");
  name = base_name(ETP);
  write(""+name);
  return 1;
}

int exp(string str){
  string name;
  int amount;
  object targplay;
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  if (!str) return notify_fail("grant <name> <amount>\n");
  if(sscanf(str,"%s %d",name, amount) != 2) return notify_fail("grant name amount\n");
  name=lower_case(name);

  if (objectp(targplay=find_player(name)) && interactive(targplay)) {
    targplay->set_property("ignore tax",1);
    targplay->fix_exp(amount,TP);
    targplay->resetLevelForExp(0);
    targplay->remove_property("ignore tax");
    write("Player "+name+" granted "+amount+" exp");
  } else {
    write("Player "+name+" is invalid or not interactive.");
  }
  return 1;
}

int fix_em(string str){
  string name;
  int feats;
  object targplay;
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  if(!wizardp(ETO)){
     tell_object(ETO,"That action is not available.");
     return 1;
  }
  if (!str) return notify_fail("fixfeats <name>\n");
  if(sscanf(str,"%s",name) != 1) return notify_fail("fixfeats <name>\n");
  name=lower_case(name);

  if (objectp(targplay=find_player(name)) && interactive(targplay)) {
    feats = (int)targplay->query_other_feats_gained();
    feats += (int)TO->query("free_feats");
    targplay->clear_feats();
    targplay->set("free_feats",feats);
    write("Feats fixed for "+capitalize(name)+".");
    tell_object(targplay,"Your feats have been reset. Please use <feats fix> before setting them again.");
    targplay->set("class_feats_reset2",1);
  } else {
    write("Player "+name+" is invalid or not interactive.");
  }
  return 1;
}

int add_em(string str,int x){
  string name;
  int feats;
  object targplay;
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  if(!wizardp(ETO)){
     tell_object(ETO,"That action is not available.");
     return 1;
  }
  if (!str) return notify_fail("addfeats <name> <number>\n");
  if(sscanf(str,"%s %d",name,feats) != 2) return notify_fail("addfeats <name> <number>\n");
  name=lower_case(name);

  if (objectp(targplay=find_player(name)) && interactive(targplay)) {
    targplay->set("free_feats",feats);
    write("You have given "+capitalize(name)+" "+feats+" feat(s).");
    tell_object(targplay,"You have been given "+feats+" free feats.");
  } else {
    write("Player "+name+" is invalid or not interactive.");
  }
  return 1;
}

int nwp_bonus(string str) {
  string targplay, nwp;
  int bonus, old_bonus;
  object ob;

  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  if (3 != sscanf(str,"%s %d to %s",targplay, bonus,nwp)) {
    return notify_fail("nwpbonus <player> <bonus> <nwpname>\n");
  } else {
    if (!objectp(ob=find_player(targplay))) {
      return notify_fail("Player `"+targplay+"' not found.");
    } else {
      if (!ob->has_nwp(nwp)) {
	return notify_fail("They don't have that NWP!");
      } else {
	old_bonus=ob->query_nwp_bonus(nwp);
	ob->set_nwp_bonus(nwp,bonus);
	write(targplay+" granted "+bonus+" NWPXP in "+nwp+
	      ". (Was at "+old_bonus+".)");
	return 1;
      }
    }
  }
}

int do_mark_deed(string str)
{
  string name, deed;
  object targplay;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  } // Added security!!! A must have. :)
  if (!str) return notify_fail("deed <name> <important_deed>\n");
  if (sscanf(str,"%s %s",name, deed) != 2) return notify_fail("deed <name> <important_deed>\n");
   name=lower_case(name);
  if (objectp(targplay = find_player(name)) && interactive(targplay))  {
   tell_object(targplay,"You have accomplished "+deed+"!");
   write("Player "+name+" noted for accomplishing "+deed+"!");
   return targplay->set_mini_quest("Achieved: "+deed,1,"Achieved: "+deed);
   } else {
   return notify_fail("Player "+ name +" not found or not interactive.\n");
   }
}

int pk_flag(string str) {
  string name, which;
  object targplay;
  int dt;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  } // Added security!!! A must have. :)
  if (!str)
	return notify_fail("syntax is <pkflag [name] on> or <pkflag [name] off>\n");
  if (sscanf(str,"%s %s",name, which) != 2)
	return notify_fail("syntax is <pkflag [name] on> or <pkflag [name] off>\n");
  if(which != "on" && which != "off")
  if (sscanf(str,"%s %s",name, which) != 2)
	return notify_fail("syntax is <pkflag [name] on> or <pkflag [name] off>\n");
  name=lower_case(name);
  if (objectp(targplay = find_player(name)) && interactive(targplay))  {
     if (dt=targplay->query_down_time())
        write("%^BOLD%^%^RED%^WARNING:%^WHITE%^ Player has a downtime set");
     tell_object(targplay,"Your PK status flag has been changed to "+which+".");
     write("You have changed "+name+"'s PK status flag to "+which+".");
     switch(which) {
     case "on":  targplay->set("no pk", 1);  break;
     case "off":  targplay->delete("no pk");  break;
	default:  write("Something didn't work right, please try again.");
     }
   } else {
     return notify_fail("Player "+ name +" not found or not interactive.\n");
   }
}

int dt_flag(string str) {
  string name, which;
  object targplay;
  int dt;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  } // Added security!!! A must have. :)
  if (!str)
	return notify_fail("syntax is <dtflag [name] on> , <dtflag [name] off> or <dtflag [name] ask>\n");
  if (sscanf(str,"%s %s",name, which) != 2)
	return notify_fail("syntax is <dtflag [name] on> , <dtflag [name] off> or <dtflag [name] ask>\n");
  if(member_array(which, ({"on","off","ask","query","time"}) ) == -1 )
   if (sscanf(str,"%s %s",name, which) != 2)
	return notify_fail("syntax is <dtflag [name] on> , <dtflag [name] off> or <dtflag [name] ask>\n");
  name=lower_case(name);
  if (objectp(targplay = find_player(name)) && interactive(targplay))  {
//     tell_object(targplay,"Your PK status flag has been changed to "+which+".");
//     write("You have changed "+name+"'s PK status flag to "+which+".");
     switch(which) {
	case "on":
  //     tell_object(targplay,"Your PK status flag has been changed to "+which+".");
         write("You have changed "+name+"'s PK downtime flag to "+which+".");
         targplay->set_down_time(dt=time()+_TWO_WEEKS_IN_SECONDS_);
         write("Their downtime flag is set to clear at: "+ctime(dt)+".");
         break;
	case "off":
  //     tell_object(targplay,"Your PK status flag has been changed to "+which+".");
         write("You have changed "+name+"'s PK downtime flag to "+which+".");
         targplay->remove_down_time();  break;
        case "ask":
	case "query":
	if (!dt=targplay->query_down_time()) {
	   write("They don't have a PK flag because of downtime...");
   	   break;
	} else {
	   write("Their downtime flag is set to clear at: "+ctime(dt)+".");
           break;
        }
	default:  write("Something didn't work right, please try again.");
     }
   } else {
     return notify_fail("Player "+ name +" not found or not interactive.\n");
   }
}

int d_flag(string str) {
  string name, which;
  object targplay;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  } // Added security!!! A must have. :)
  if (!str)
	return notify_fail("syntax is <dflag [name] off>\n");
  if (sscanf(str,"%s %s",name, which) != 2)
	return notify_fail("syntax is <dflag [name] off>\n");
  if(which != "on")
  if (sscanf(str,"%s %s",name, which) != 2)
	return notify_fail("syntax is <dflag [name] off>\n");
  name=lower_case(name);
  if (objectp(targplay = find_player(name)) && interactive(targplay))  {
     tell_object(targplay,"Your D status flag has been switched off.");
     write("You have switched "+name+"'s D status flag off.");
     targplay->set_death_age(0);
   } else {
     return notify_fail("Player "+ name +" not found or not interactive.\n");
   }
}

int lang_fun(string str){
  int totalallowed, raceallowed, success, i, j;
  string myrace, *skillslist, currentlang;
  object myplayer;
  mapping skills;

  if(!find_player(str)) {
    tell_object(TP,"No such player online.");
    return 1;
  }
  myplayer = find_player(str);
  myrace = (string)myplayer->query_race();
  if(myrace != "dwarf" && myrace != "gnome" && myrace != "human") {
    tell_object(TP,"This player's race is not appropriate for chance rolls at undercommon.");
    return 1;
  }
  if((int)myplayer->query_stats("intelligence") < 12) {
    tell_object(TP,"This player does not have sufficient intelligence to have rolled undercommon by default.");
    return 1;
  }
  if((int)myplayer->query("rolled_for_undercommon")) {
    tell_object(TP,"This player has already rolled for a chance at undercommon.");
    return 1;
  }

  switch((int)myplayer->query_stats("intelligence")) {
    case 14..15: totalallowed = 2; break;
    case 16: totalallowed = 3; break;
    case 17: totalallowed = 4; break;
    case 18: totalallowed = 5; break;
    case 19: totalallowed = 5; break;
    case 20: totalallowed = 6; break;
    case 21: totalallowed = 6; break;
    case 22: totalallowed = 7; break;
    case 23: totalallowed = 8; break;
    case 24: totalallowed = 9; break;
    case 25: totalallowed = 10; break;
    default: totalallowed = 0; break;
  }

  switch(myrace) {
    case "human": raceallowed = 6; break;
    case "dwarf": raceallowed = 5; break;
    case "gnome": raceallowed = 4; break;
  }
  for(i==0;i<totalallowed;i++) {
    if(!random(raceallowed)) success = 1;
  }

  if(!success) {
    tell_object(TP,"Unfortunately this player has failed their roll for undercommon.");
    tell_object(myplayer,"Unfortunately you have failed your roll for undercommon.");
    myplayer->set("rolled_for_undercommon",1);
    return 1;
  }

  skills = myplayer->query_all_langs();
  skillslist = keys(skills);
  j = sizeof(skillslist);

  currentlang = "blar";
  while(currentlang == "blar" || currentlang == LANGS[myrace][0]) {
    i = random(j);
    currentlang = skillslist[i];
  }
  tell_object(TP,"This player has successfully rolled for undercommon. It will be substituted for "
+currentlang+".");
  tell_object(myplayer,"Congratulations, you have successfully rolled for undercommon. It will be substituted "
"for "+currentlang+".");
  myplayer->remove_lang(currentlang);
  myplayer->set_lang("undercommon",(random((int)myplayer->query_stats("intelligence")) +5)*4);
  myplayer->set("rolled_for_undercommon",1);
  return 1;
}

int clear_prof(string str){
//  clears the named player's prof and skill settings in the named prof
//  should also return any profs previously applied to the named prof to
// their stock of unused profs
// In this file, 'skill refers to the player's skill with a weapon type,
// while prof refers to the number of profs applied in it. So, a character
// with 100(2) in medium blades would be said to have a skill of 100 and
// a prof of 2 in medium blades.

  object pc;
  mapping skilllist, proflist;
  string profname, charname, * skillnames, skillname;
  int i, j, prof, skill;
  if (!objectp(ETO)){return 0;}
// initialise the mappings and arrays used
  skilllist = ([]);
  proflist = ([]);
  skillnames = ({});

//separate the two parts of the string to be used

  sscanf(str, "%s %s", charname, profname);
  tell_object(ETO, "Trying to remove the " + profname + " prof from "
                  + charname);
  pc = find_player(charname);
  if (!objectp(pc)){return 1;}

//set skilllist to a mapping of the skillnames(strings):skilllevels (ints)
  skilllist = pc->query_skills();
  if (sizeof(skilllist)<1){
    tell_object(ETO, charname + " does not appear to have any skills!");
    return 1;
  }

// set skillnames to an array of the names of the weapon types the player
// has some skills or profs in
  skillnames = keys(skilllist);

// cycle through the list of skillnames and record the player's current
// prof in each one in the proflist mapping

  for (i=0;i<sizeof(skillnames);i++){
    skillname = skillnames[i];
    proflist[skillname]=pc->query_profs(skillname);
    tell_object(ETO, "Current skill in " + skillname + " is "
    + proflist[skillname]);
  }
// reset the player's profs
  pc->reset_profs();


// re-apply all profs, except the one you are removing
  for (i=0;i<sizeof(skillnames);i++){
    // check to make sure the next prof on the list is not the one you are
    // removing
    skillname = skillnames[i];
    if (skillname!=profname){
      // then re-apply the correct number of profs. Used a loop because I
      // couldn't find a way to apply more than one prof at a time
      prof = proflist[skillname];
      if (prof>0){
        tell_object(ETO, "Reapplying " + prof + " proficiencies to "
                        + skillname + ".");
        for (j=0;j<prof;j++){
          pc->use_prof(skillname);
        }
      }
    }
  }
//Finally, delete the skill for the proftype you are removing
  tell_object(ETO, "\nDeleting skill for " + profname + ".");
  pc->delete_skill(profname);
  tell_object(ETO, "Process finished. Prof removed");
  return 1;
}

int snag_stuff(string str) {
  string item, where;
  object theplayer;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  }
  if (!str)
    return notify_fail("Syntax is <lift (item) from (location)>\n");
  if (sscanf(str,"%s from %s",item, where) != 2)
    return notify_fail("Syntax is <lift (item) from (location)>\n");
  if(where == "here") { // pick up from ground
    if(present(item,ETP)) {
      if((int)present(item,ETP)->move(TP) != 0)
        return notify_fail("Soz, cannot carry that item.\n");
      else {
        present(item,ETP)->move(TP);
        tell_object(TP,"Has ninja'd "+item->query_name()+" from ground.");
        return 1;
      }
    }
    return notify_fail("There's no such item here sorry.\n");
  }
  if(!find_player(where))
    return notify_fail("Cannot find that player.\n");
  theplayer = find_player(where);
  if(wizardp(theplayer))
    return notify_fail("Naughty, no stealin from wiz.\n");

  if(present(item,theplayer)) {
    if((int)present(item,theplayer)->move(TP) != 0)
      return notify_fail("Soz, cannot carry that item.\n");
    else
    {
        if(present(item,ETP))
        {
            present(item,ETP)->move(TP);
            tell_object(TP,"Has ninja'd "+item->query_name()+" from "+where+".");
            return 1;
        }
    }
  }
  return notify_fail("Player does not have that item soz.\n");
}

int set_the_value(string str) {
   int price;
   string type, item;
   object ob;
   if(sscanf(str,"%s %d %s", item, price, type) != 3) return notify_fail("Syntax: <setvalue item price cointype>");
   ob = present(item,TP);
   if(!ob) return notify_fail("There is no "+item+" here.\n");
   ob->set("value",price);
   ob->set_cointype(type);
   tell_object(TP,"You have now set "+ob->query_name()+" to the value of "+price+" "+type+".");
   return 1;
}

int convert(string str)
{
    object *per;
    if(!stringp(str))
    {
        tell_object(TP,"Syntax: convert <name>");
        return 1;
    }

    if(!objectp(per=find_player(str)))
    {
        tell_object(TP,"Can't find a persona named "+str+"");
        return 1;
    }

    if(!avatarp(per))
    {
        tell_object(TP,"You can only convert avatar personas to the new class type.");
        return 1;
    }

    per->set("new_class_type",1);
    tell_object(TP,"%^RESET%^Persona %^RED%^"+str+"%^RESET%^ converted to the new class type, "
        "please remember to save and remember that class levels stack things like thaco and "
        "caster level.");
    return 1;
}


int is_immortal(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!avatarp(ob)) { return 0; }
    return 1;
}

int force_forsake(string str)
{
    string *info,name,deity;
    object player,symbol,*imms;
    int i;

    if(!stringp(str) || str == "" || str == " ")
    {
        tell_object(TP,"force_forsake <player> <reason>");
        return 1;
    }
    info = explode(str," ");

    if(!objectp(find_player(lower_case(info[0]))))
    {
        tell_object(TP,"Can't find a player named "+lower_case(info[0])+"");
        return 1;
    }

    player = find_player(info[0]);
    deity = (string)player->query_diety();

    if(!deity || deity == "" || deity == " ")
    {
        tell_object(TP,""+player->QCN+" does not follow a god.");
        return 1;
    }

    imms = children("/std/user.c");
    imms = filter_array(imms,"is_immortal",TO);

    for(i=0;i<sizeof(imms);i++)
    {
        if(!objectp(imms[i])) { continue; }
        tell_object(imms[i],"%^RESET%^%^BOLD%^"+capitalize(player->query_true_name())+" was forced to forsake "
            ""+deity+" by "+capitalize(TP->query_true_name())+".");
    }

    name = (string)player->query_true_name();
    str = implode(info," ");
    str = replace_string(str,name,"",1);

    "/cmds/avatar/_note.c"->cmd_note("ckpt "+name+" was forced to forsake "+deity+" by "
        ""+TP->query_true_name()+" because of :"+str+"");

    ADVANCE_D->deity_news(deity,player->QCN+" has been forced to forsake "
        ""+capitalize(deity)+" as "+player->QP+" diety!");

    log_file("player/god_change", player->QCN+" was forced to leave "+capitalize(deity)+" by "+TP->query_true_name()+": "+ctime(time())+"\n");

    tell_object(player,""+capitalize(deity)+" will no longer have you as a follower!");
    tell_object(player,"A bolt of energy streaks toward you from above, exacting "+capitalize(deity)+"'s revenge.");

    player->set_diety(0);
    player->set_sphere(0);
    player->set_divine_domain(({}));
    player->forget_all_cl_spells();

    if(objectp(symbol = present("symbol",player))) symbol->remove();
    player->update_channels();

    if(!avatarp(player)) { player->general_exp_adjust_perc(-15); }

    player->resetLevelForExp(0);
    return 1;
}
