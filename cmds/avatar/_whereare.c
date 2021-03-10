// People-by-room lister for avatars and above.
// Based on GrendelCode[tm]
// Coded on 01-13-2001.
// Bug fixes on and about 01-14-2001.
// Intended to show people by rooms.
// I don't sort the rooms, I think that'd be too much a pain.
// I did my best with formatting.
// I'm thinking on how to make it kind to people who use
//   umpteenmillion daggers and snakes, but I don't have a
//   clear grip on how to do that.
// garrett

#define ALL_MY_COLORS ({ "%^BLUE%^", "%^B_BLUE%^", "%^CYAN%^", "%^B_CYAN%^", "%^GREEN%^", "%^B_GREEN%^", "%^RED%^", "%^B_RED%^", "%^ORANGE%^", "%^YELLOW%^", "%^B_ORANGE%^", "%^MAGENTA%^", "%^B_MAGENTA%^", "%^WHITE%^", "%^B_WHITE%^", "%^BLACK%^", "%^B_BLACK%^", "%^BOLD%^", "%^ULINE%^", "%^RESET%^" })
#include <std.h>


string * colors=ALL_MY_COLORS;
string filter_colors(string str) {
  string tmp;
   int i,sizeof_array;
//  while (sscanf(str, "%*s%%^%s%%^%*s", tmp) > 2)
//    str = replace_string(str, "%^"+tmp+"%^", "");
    for(i=0, sizeof_array=sizeof(colors),tmp=colors[i];i<sizeof_array;i++)
        str=replace_string(str,tmp,"");

   for(i=0, sizeof_array=sizeof(colors),tmp=colors[i];i<sizeof_array;i++)
        str=replace_string(str,lower_case(tmp),"");
  return str;
}

string my_strip_colors(string str)
{
    string ret;
    mapping Uncolor = ([ "RESET" : "", "BOLD" : "", "ULINE" : "", "FLASH" : "", "BLACK" : "", "RED" : "",
                         "BLUE" : "", "CYAN" : "", "MAGENTA" : "", "ORANGE" : "", "YELLOW" : "",
                         "GREEN" : "", "WHITE" : "", "BLACK" : "", "B_RED" : "", "B_ORANGE" : "",
                         "B_YELLOW" : "", "B_BLACK" : "", "B_CYAN" : "", "B_WHITE" : "", "B_GREEN" : "",
                         "B_MAGENTA" : "", "STATUS" : "", "WINDOW" : "", "INITTERM" : "", "B_BLUE" : "",
                         "ENDTERM" : ""]);
    ret = terminal_colour(str, Uncolor);
    return ret;
}
int cmd_whereare(string arguments) {
  object *peo, *players, *reported, ob;
  string loc, str, name, temp, *targetnames;
  mapping map;
  int iter, column, maxscreensize, numcols, pass, snakes, undeads;
  
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
//    str = filter_colors(replace_string(str,"\n",""));
    str = my_strip_colors(str);
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
      str += "%^GREEN%^" + loc;
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
	  loc = "%^BOLD%^%^BLUE%^Hm  ";
	} else if (newbiep(ob)) {
	  if (pass!=3)
	    continue;
	  loc = "%^BOLD%^%^CYAN%^Nb  ";
	} else if (userp(ob)) {
	  if (pass!=2)
	    continue;
	  loc = "%^BOLD%^%^GREEN%^Pl  ";
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

int help(){
  write(@gArReTt
Syntax:  whereare

A players-grouped-by room search.

Intentionally shows ALL living things along with a player.
The list goes in this order:
  Avatar
  High Mortal
  Player
  Newbie
  NPC
  Glory Hunter
  Mount
  Elemental / Summoned Monsters (Other than Snakes and Undead) / Monsters
  (Summary list of snakes, if any, then Summary list of Undead, again, if any.)
Monsters do NOT have any designation. Summoned Snakes are counted in summary at the end of the room listing.
Formatting works best if setenv SCREEN 80 is issued, as it was already enough of a beast to mangle as it was.
-------
garrett
gArReTt
);
  return 1;
}

