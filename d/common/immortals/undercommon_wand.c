#include <std.h>
#include <langs.h>
inherit OBJECT;

create(){
  ::create();
  set_name("undercommon wand");
  set_id(({"wand","magic wand","magical wand","wand for undercommon","undercommon wand"}));
  set_short("A magical wand for undercommon");
  set_long("This is a happy wand to let people try to roll for undercommon.  "
"Note that it will only work on the following races: human, dwarf, gnome.  "
"Please warn the player that it will randomly revoke one of their optional languages if they "
"successfully roll for undercommon; this is a risk they will need to take, and is not reversable.  "
"Any half-ogre or half-drow characters will need to consult a wiz to roll a chance at undercommon.  "
"Please use <trylang playername> to give them their reroll chance; this will only work once per player.");
  set_weight(0);
  set_value(0);
}

void init(){
  ::init();
  add_action("wave_wand", "trylang");
}

int wave_wand(string str){
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