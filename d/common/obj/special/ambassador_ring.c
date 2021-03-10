// to give Ambassador newbie PC's their line and abilities
//Updated by ~Circe~ 2/24/13 with a <wherenewbie> function
#include <std.h>
#include <daemons.h>

inherit "/std/armour";

void check_ok(object who);

void create() {
  ::create();
  set_property("no steal",1);
//  set_property("no offer",1);  this is more trouble than it's worth
  set_property("no animate",1);
//  set_hidden(1);               this doesn't seem to be working
//  set_property("no detect",1); nor does this, ah well
  set_name("brass ring");
  set_id(({"ring","ambassador ring", "brass ring"}));
  set_short("brass ring");
  set_long("A simple ring that looks to be made of brass." );
  set_type("ring");
  set_weight(1);
  set_value(0);
  set_limbs(({"right hand"}));
  set_wear((:TO,"wearme":));
  set_remove((:TO,"removeme":));
  set("read", "Try <review commands>." );
/* I decided this isn't the best way to do this, or maybe not anyway
  set_property("enchantment", -1);
  while (query_property("enchantment") > -1)
     set_property("enchantment", -1);
*/
}

void init() {
  if (!userp(ETO)) return;
  ::init();
  call_out("check_ok", 1, TP);
  add_action("review", "review");
  if(!avatarp(TP)){
	add_action("note", "note");
	add_action("find_em","wherenewbie");
  }
  if(avatarp(TP))
	add_action("setup", "setup");
}

void check_ok(object who) {
  if ( (!newbiep(who) && !avatarp(who)) || 
       (newbiep(who) && member_array(TPQN,SAVE_D->query_array("n_ambassador")) == -1) ) {
     log_file("ambassador", capitalize(TPQN)+" had an ambassador "
	"ring on "+ctime(time())+" & should NOT have.\n");
     tell_object(who,"The ring vanishes in a flash of light.");
     TO->remove();
     return;
  }
  TP->force_me("wear ambassador ring");
  if(!avatarp(TP))
    log_file("ambassador", capitalize(TPQN)+" has ambassador ring on "+ctime(time())+"\n");
  return;
}

int setup(string who) {
  if(!who)  
	return notify_fail("You need to specify a name.\n");
  if (!user_exists(who)) 
	return notify_fail ("This player doesn't seem to exist...\n");
  if (!objectp(find_player(who)))
	return notify_fail ("Player must be online!\n");
  if (!newbiep(find_player(who)))
        return notify_fail("They are not eligible to be an ambassador char.\n");

  "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" was set up as a newbie ambassador.");
  SAVE_D->set_value("n_ambassador", lower_case(who));
  find_player(who)->set("n_ambassador", 1);  /* can't get this to work in query to use but going to still set it in case we want it for something else later Styx */
  return 1;
}

void wearme() {
  tell_object(ETO,"%^GREEN%^The ring reminds you how special you are.");
  if (userp(ETO) && !avatarp(ETO)) ETO->unrestrict_channel("ambassador");
  return 1;
}

int drop() {
  if (!userp(ETO)) return 0;
  if (!avatarp(ETO)) {
    write("You decide to keep the ring to help further your work.");
    return 1;
  } else return ::drop();
}

void removeme() {
  tell_object(ETO,"As you remove the ring, you feel a pang of regret.");
  return 1;
}

int review(string str) {
  
  if( member_array(TPQN,SAVE_D->query_array("n_ambassador")) == -1 && !avatarp(TP))
     return 0;
  if(str == "help") {
     TP->more("/doc/help/hm/ambassador");
     return 1;
  }
  if(str == "commands") {
    if(avatarp(TP))
	write("As an immortal you may <setup [name]> to be a newbie ambassador.  "	   "This needs to be done before giving them the ring.  Please <note> "
	   "who their hm character is and remind them to <where block>.\n");
    write("Ambassador characters via the ring have the following extra abilities:\n"
	"  %^BOLD%^%^CYAN%^* %^RESET%^use of the %^BOLD%^%^CYAN%^<%^RESET%^"
      "ambassador%^BOLD%^%^CYAN%^>%^RESET%^ line, shared with immortals,\n"
      "  %^BOLD%^%^CYAN%^*%^RESET%^ ability to use %^BOLD%^%^CYAN%^<%^RESET%^wherenewbie%^BOLD%^%^CYAN%^>%^RESET%^ to see where other newbies are\n"
	"  %^BOLD%^%^CYAN%^* %^RESET%^ability to use the %^BOLD%^%^CYAN%^<%^RESET%^note%^BOLD%^%^CYAN%^> %^RESET%^command.\n"
      "    With this command, you can:\n"
      "      <note add [name] [reason]> to add a note on another newbie \n"
      "                                 or yourself\n"
      "      <note ckpt [name] [reason]> to add a note that also includes \n"
      "                                  information about class, level,\n"
      "                                  experience, etc.\n"
      "      <note view [name]> to see all notes on another newbie or yourself\n"
	"  %^BOLD%^%^CYAN%^* %^RESET%^To get an idea of what notes do, try out <note view [yourname]>\n"
	"      Feel free to test the commands on your character to see how it works.\n"
	"      %^BOLD%^Please recognize yourself so it will show your name, not adjective.\n"
	"  %^BOLD%^%^CYAN%^* %^RESET%^If you have them recognized, note should convert correctly to \n"
      "    real name but if you only know them from line questions or something, \n"
      "    that should also work.\n"
	"  %^BOLD%^%^CYAN%^* <%^RESET%^review help%^BOLD%^%^CYAN%^> %^RESET%^to review the help file regarding \n"
      "    your responsibilities/role.\n"
	"\nPlease remember that how you use this is a direct reflection on you "
	"as an HM and also know %^BOLD%^we appreciate your help%^RESET%^."
    );
    return 1;
  }
  return 0;
}

int query_size() {
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}

int note(string str) {
   string tmp, name, note, notes, type, real;
   if(sscanf(str, "%s %s", type, tmp) != 2)
      return notify_fail("Your options are <note add|ckpt [name] [reason]> or <note view [name]>\n");
 
   if(type != "add" && type != "view" && type != "ckpt")
      return notify_fail("Your options are <note add|ckpt [name] [reason]> or <note view [name]>\n");
 
   if((sscanf(tmp, "%s %s", name, note) != 2) && (sscanf(tmp,"%s",name) != 1))
      return notify_fail("You must specify a name, try <note view [name]> for example.\n");

   if (!stringp(note)) note = "";
   if (!stringp(name)) name = tmp;
   name = lower_case(name);
   real = TP->realName(name);
   if(real != "")  name = real;
   if(!user_exists(name)) 
      return notify_fail ("ERROR: This character doesn't seem to exist...\n");
   if(!objectp(find_player(name)))
      return notify_fail ("Sorry, character must be online to validate newbie status before proceeding.  If you believe you have the name correct and feel it is important to make the note now, you can contact or mail an immortal who can do it.\n");
   if(!newbiep(find_player(name)))
      return notify_fail ("Sorry, but you can only do that on newbies.\n");
   switch(type) {
      case "ckpt":
	"/cmds/avatar/_note.c"->cmd_note("ckpt "+name+" note by: %^BOLD%^"+TPQCN+" %^RESET%^"+note);
	write("Checkpoint note should have been added.");
	break;
      case "add":
	"/cmds/avatar/_note.c"->cmd_note("add "+name+" note by: %^BOLD%^"+TPQCN+" %^RESET%^"+note);
	write("Your note should have been added.");
	break;
      case "view":
        notes = "/daemon/treesave_d.c"->query_array("notes",name);
        if(!notes || notes == ({}))
          write("There are no notes for "+name+", yet anyway.\n");
	"/cmds/avatar/_note.c"->cmd_note("view "+name);
	break;
   }
   return 1;
}

string filter_colors(string str) {
  string tmp;
  while (sscanf(str, "%*s%%^%s%%^%*s", tmp) > 2)
    str = replace_string(str, "%^"+tmp+"%^", "");
  return str;
}

int find_em(string arguments) {
  object *peo, *players, *reported, ob;
  string loc, str, name, temp, *targetnames;
  mapping map;
  int iter, column, maxscreensize, numcols, pass, snakes, undeads;
  
   if(!objectp(TP)) { return 0; }

  reported = players = ({ });
  peo = users();

#ifdef 0

  if (arguments) {
    if (sizeof(arguments) > 1 )
      targetnames = explode(arguments," ");
    else
      targetnames = ({ arguments });
    for(iter=0;iter < sizeof(targetnames);iter++)
      reported += ({ find_player(targetnames[iter]) });
  }
  if (sizeof(reported)!= 0) {
    peo = reported;
    reported = ({ });
  }
#endif // 0

  for(iter = 0;iter < sizeof(peo);iter ++){
    if (!objectp(peo[iter])) continue;
    name = peo[iter]->query_name();
    if(!name) continue;
    if (wizardp(peo[iter])) continue;
    if(!newbiep(peo[iter])) continue; //only shows newbies
    players += ({ peo[iter] });
  }
  players -= ({ 0 });

  if (TP->getenv("SCREEN"))
    maxscreensize = atoi(TP->getenv("SCREEN"));
  else maxscreensize = 75;
  if (maxscreensize > 80)
     maxscreensize = 80;
  numcols = maxscreensize / 19;
  if (!numcols)
    numcols = 3;

  while (sizeof(players)) {
    if ((!str = environment(players[0])->query_short()) || (str ==""))
      str = "Unnamed Room!";
    str = filter_colors(replace_string(str,"\n",""));
    undeads = strlen(str);
    loc = "[" +file_name(environment(players[0])) + "]";
    snakes = strlen(loc);
    str = "%^BOLD%^%^CYAN%^" + str;
    if (undeads + snakes >= maxscreensize){
      str += arrange_string(" ",10);
      str += "%^BOLD%^";
      str += arrange_string(loc ,maxscreensize - (undeads + 7));
    } else {
      str += arrange_string(" ",maxscreensize - (undeads + snakes));
//      str += "%^GREEN%^" + loc;
    }
    peo=all_inventory(environment(players[0]));
    column = snakes = undeads = 0;
    for (pass=0;pass < 8; pass++)
      for (iter = 0; iter < sizeof(peo); iter ++) {
	ob=peo[iter];
	if (!objectp(ob))
	  continue;
	if (wizardp(ob))
	  continue;
	if (!living(ob))
	  continue;
	// No need to list clutter on the ground!
	if (avatarp(ob)) {
	  if (pass!=0)
	    continue;
	  loc = "%^BOLD%^%^WHITE%^Av  ";
	} else if (high_mortalp(ob)) {
	  if (pass!=1)
	    continue;
	  loc = "%^BOLD%^%^YELLOW%^Hm  ";
	} else if (newbiep(ob)) {
	  if (pass!=3)
	    continue;
	  loc = "%^BOLD%^%^CYAN%^Nb  ";
	} else if (userp(ob)) {
	  if (pass!=2)
	    continue;
	  if (ob->query("advanced_player")) loc = "%^BOLD%^%^GREEN%^Ap  ";
	  else loc = "%^BOLD%^%^BLUE%^Pl  ";
	} else if (ob->is_npc()) {
	  if (pass!=4)
	    continue;
	  loc = "%^BOLD%^%^MAGENTA%^NPC ";
	} else if ((string)ob->query_vehicle_type() == "riding animal") {
	  if (pass!=6)
	    continue;
	  loc = "%^YELLOW%^Mnt ";
	} else {
	  if ((pass==5) && ob->id("glory")) {
	    loc = "%^RESET%^%^ORANGE%^GH  ";
	  } else if ((pass == 7) && (ob->id("summoned monster"))) {
	    if (ob->id("snake")) {
	      snakes++;
	      continue;
	    } else if (ob->query_property("undead")) {
	      undeads++;
	      continue;
	    } else {
	      loc = "%^RESET%^%^ORANGE%^Sum ";
	    }
	  } else if ((pass == 7) && (ob->id("elemental")) && (ob->id("summoned monster"))) {
	    loc = "%^BOLD%^%^CYAN%^Elm ";
	  } else if ((pass == 7) && (!ob->id("glory"))){
	    loc = "    ";
	  } else continue;
	}
	name = replace_string(capitalize(ob->query_name())," ","_");
	if(ob->query_invis())
	  name = arrange_string("("+filter_colors(name)+")",15);
	else
	  name = arrange_string(name,15);
	if (column % numcols)
	  str += " ";
	else
	  str += "\n";

	if (!(++column % numcols))
	  name = replace_string(name," ","");
	str += loc + "%^BOLD%^%^RED%^"+name;

	if (userp(ob)) 
	  players -= ({ ob });
	reported += ({ ob });
      }
    // Okay. Bit of logic swap here.
    // If you're registering snakes or undead. There's a player SOMEWHERE
    // in the room that let you GET here. Therefore, you're not in the
    // first line, first column.
    if (snakes + undeads) {
      if (snakes) {
	if (column++ % numcols)
	  str += arrange_string("%^BOLD%^%^GREEN%^    "+ snakes + " snake(s).",19);
	else
	  str += "%^BOLD%^%^GREEN%^    "+ snakes + " snake(s).";
      }
      if (undeads) {
	if (column++ % numcols)
	  str += arrange_string("%^BOLD%^%^BLACK%^    "+ undeads + " undead(s).",19);
	else
	  str += "\n%^BOLD%^%^BLACK%^    "+ undeads + " undead(s).";
      }
    }
    write(str);
  }
  return 1;
}
