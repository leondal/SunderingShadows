//Updated to automatically grant AP status at conclusion of quest - Octothorpe 4/17/10
#include <std.h>
#include <daemons.h>
#include <security.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a table");
	set_id(({"table","Table","a table","stone table","large stone table"}));
	set_short("%^RESET%^%^CYAN%^a large stone table%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This table looks like it has been here a very long time, its %^BLUE%^stone %^CYAN%^surface pitted and cracked.  It looks immensely %^RED%^heavy%^CYAN%^, far too "
"much so to lift or move from its place in the centre of the room.  There are three deep, long grooves in its surface, in which you could %^ORANGE%^place %^CYAN%^something.%^RESET%^");
	set_weight(99999);
}

void init(){
	::init();
	add_action("finish_quest","place");
}

int finish_quest(string str){
  string which;
  int succeed;
  object ob;

  if(!str){
  	tell_object(TP,"Place what where?");
  	return 1;
  }
  if(str!="sword on table"){
  	tell_object(TP,"Try place <object> on <thing>");
  	return 1;
  }
  if(member_array("Quest for the Swords",TP->query_quests())!=-1){
    tell_object(TP,"%^BOLD%^%^RED%^You have already finished the quest, "+TPQCN+"! You should not be here!");
    TP->move_player("/d/shadow/virtual/sea/hmquest.dock.c");
    return 1;
  }

  which = (string)TP->query("which_hm_quest");
  switch (which) {
    case "destiny":
      if(!ob=present("hm_quest_destiny",TP)){
        if(present("hm_quest_glyphs",TP)){
          tell_object(TP,"%^BOLD%^%^MAGENTA%^You must assemble the sword, "+TPQCN+"!");
          succeed = 0;
        }
        else{
          tell_object(TP,"%^YELLOW%^You do not have the sword you were sent for, "+TPQCN+"!");
          succeed = 0;
        }
      }
      else{
        tell_room(environment(TP),"%^BOLD%^%^YELLOW%^There is a bright %^WHITE%^flash %^YELLOW%^of light as "+TPQCN+" places a sword on the table!",TP);
        tell_object(TP,"%^BOLD%^%^YELLOW%^There is a bright %^WHITE%^flash %^YELLOW%^of light as the sword touches the table!\n");
        tell_object(TP,"%^BOLD%^%^RED%^Thank you for returning the %^BLUE%^Sword of Destiny %^RED%^to its rightful place, "+TPQCN+"!");
        succeed = 1;
      }
      break;
    case "ages":
      if(!ob=present("hm_quest_ages",TP)){
          if(present("hm_quest_runes",TP)){
          tell_object(TP,"%^BOLD%^%^MAGENTA%^You must assemble the sword,"+TPQCN+"!");
          succeed = 0;
        }
        else{
          tell_object(TP,"%^YELLOW%^You do not have the sword you were sent for, "+TPQCN+"!");
          succeed = 0;
        }
      }
      else{
        tell_room(environment(TP),"%^BOLD%^%^YELLOW%^There is a bright %^WHITE%^flash %^YELLOW%^of light as "+TPQCN+" places a sword on the table!",TP);
          tell_object(TP,"%^BOLD%^%^YELLOW%^There is a bright %^WHITE%^flash%^YELLOW%^ of light as the sword touches the table!\n");
        tell_object(TP,"%^BOLD%^%^RED%^Thank you for returning the %^BLUE%^Sword of the Ages %^RED%^to its rightful place, "+TPQCN+"!");
        succeed = 1;
      }
      break;
    case "fate":
      if(!ob=present("hm_quest_fate",TP)){
        if(present("hm_quest_symbols",TP)){
          tell_object(TP,"%^BOLD%^%^MAGENTA%^You must assemble the sword,"+TPQCN+"!");
          succeed = 0;
        }
        else{
          tell_object(TP,"%^YELLOW%^You do not have the sword you were sent for, "+TPQCN+"!");
          succeed = 0;
        }
      }
      else{
        tell_room(environment(TP),"%^BOLD%^%^YELLOW%^There is a bright %^WHITE%^flash %^YELLOW%^of light as "+TPQCN+" places a sword on the table!",TP);
        tell_object(TP,"%^BOLD%^%^YELLOW%^There is a bright %^WHITE%^flash%^YELLOW%^ of light as the sword touches the table!\n");
        tell_object(TP,"%^BOLD%^%^RED%^Thank you for returning the %^BLUE%^Sword of Fate %^RED%^to its rightful place, "+TPQCN+"!");
        succeed = 1;
      }
      break;
    default: break;
  }
  if(succeed){
    ob->remove();
    tell_room(environment(TP),"%^BOLD%^%^GREEN%^You see that "+TPQCN+" has completed the Quest for the Swords!\n",TP);
    tell_object(TP,"%^BOLD%^%^GREEN%^\n\nCongratulations, you have completed the Quest for the Swords!\n");
    //tell_object(TP,"%^BOLD%^%^RED%^You now have Advanced Player status.\n");
    TP->set_quest("Quest for the Swords");
    TP->set_hm_quest(1);
    TP->fix_exp(2000000,TP);
    /*if(TP->query("no pk")) {
      TP->delete("no pk");
      tell_object(TP,"\n\n%^BOLD%^%^BLUE%^As a highlevel player, your PK immunity is now dropped for you. Good luck!%^RESET%^");
      message("info","%^YELLOW%^"+capitalize(TP->query_name())+"'s %^MAGENTA%^PK immunity %^YELLOW%^has just been removed.%^RESET%^\n",users());
    }*/
    //seteuid(UID_ADVANCE);
    //seteuid(getuid());
    //log_file("advplayer", TP->query_name()+" became AP: "+ctime(time())+" by completing the Quest for the Swords.\n");
    return 1;
  }
  else{
    tell_object(TP,"%^BOLD%^Please try again when you have the correct sword.");
    return 1;
  }
}
