#include <std.h>
inherit OBJECT;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void create(){
  ::create();
  set_name("magical acorn");
  set_id(({"acorn","magical acorn"}));
  
  set_short("%^RESET%^%^GREEN%^m%^WHITE%^a%^ORANGE%^g%^GREEN%^i"+
"c%^ORANGE%^a%^GREEN%^l %^ORANGE%^a%^GREEN%^c%^WHITE%^o%^GREEN%^"+
"rn%^RESET%^");
  set_obvious_short("%^ORANGE%^an acorn%^RESET%^");
  set_long("\n"+
"%^YELLOW%^                           MM%^RESET%^\n"+
"%^YELLOW%^                        MMM MMM%^RESET%^\n"+
"%^YELLOW%^                     MMMM    MMM%^RESET%^\n"+ 
"%^YELLOW%^                  MMMM         MMM%^RESET%^\n"+ 
"%^YELLOW%^               MMM               MMM%^RESET%^\n"+
"%^YELLOW%^             MM                     MM%^RESET%^\n"+
"%^YELLOW%^           MMM                       MM%^RESET%^\n"+
"%^YELLOW%^          MMM                         MM%^RESET%^\n"+
"%^YELLOW%^         MMM                           MM%^RESET%^\n"+
"%^YELLOW%^       MM%^RESET%^                      %^MAGENTA%^|"+
"%^RESET%^%^YELLOW%^        MM%^RESET%^\n"+
"%^YELLOW%^      MM%^RESET%^                     %^MAGENTA%^\\ |"+
" /%^RESET%^%^YELLOW%^       MM%^RESET%^\n"+
"%^YELLOW%^      MM%^RESET%^                %^MAGENTA%^--%^CYAN%^"+
"TRAVEL HOME%^MAGENTA%^--%^RESET%^%^YELLOW%^  MM%^RESET%^\n"+
"%^YELLOW%^     MMM%^RESET%^                     %^MAGENTA%^/ | "+
"\\%^RESET%^%^YELLOW%^       MM%^RESET%^\n"+
"%^RESET%^%^ORANGE%^   MMMMM                       %^MAGENTA%^|"+
"%^RESET%^%^YELLOW%^         MM%^RESET%^\n"+
"%^RESET%^%^ORANGE%^   M   MM                                "+
"%^RESET%^%^YELLOW%^MM%^RESET%^\n"+
"%^RESET%^%^ORANGE%^   MMMM MMM                             "+
"%^RESET%^%^YELLOW%^MM%^RESET%^\n"+
"%^RESET%^%^ORANGE%^   M  M M  MMMM                         "+
"%^RESET%^%^YELLOW%^MM%^RESET%^\n"+
"%^RESET%^%^ORANGE%^   MMM   M  MMMMMMMM                MMM  MM"+
"%^RESET%^\n"+
"%^RESET%^%^ORANGE%^   M  MM MMM  M  MM MMMMMMMMMMM   MMM   MMM"+
"%^RESET%^\n"+
"%^RESET%^%^ORANGE%^      MM  M  MMM   MMMMM MMM  M   M MMM MMM"+
"%^RESET%^\n"+
"%^RESET%^%^ORANGE%^         MMMM MM  MM  MMMMMM  MMM MMMMMM"+
"%^RESET%^\n"+
"%^RESET%^%^ORANGE%^           MMMMM  M   MMM  MMM  MMMMMM"+
"%^RESET%^\n"+
"%^RESET%^%^ORANGE%^               MMMM MMMM MMMM MMMMMM"+
"%^RESET%^\n"+
"%^RESET%^%^GREEN%^             MM  MMM M  %^ORANGE%^MMMMMMMMM"+
"%^RESET%^\n"+
"%^RESET%^%^GREEN%^            MM  MMM%^RESET%^\n"+
"%^RESET%^%^GREEN%^          MMM  MMM%^RESET%^\n"+
"%^RESET%^%^GREEN%^         MMM MMM%^RESET%^\n"+
"%^RESET%^%^GREEN%^          MM MM%^RESET%^\n"+
"%^RESET%^%^GREEN%^           MMM%^RESET%^\n"+
"");

}

void init(){
  ::init();
  add_action("eat_acorn","eat");
  add_action("go_home","travel");
}

int eat_acorn(string str){
  if(str=="acorn"){ 
    tell_object(TP,"%^ORANGE%^You don't want to eat that!  "+
"It might be poisonous!%^RESET%^");
  return 1;
  }
return 0;
}

int tracker;

int go_home(string str){
  if(TP->query_bound() || TP->query_unconscious()){
    TP->set_paralyzed_message("info",TP);
  return 1;
  }

  if(!str){
    notify_fail("%^ORANGE%^Where do you wish to go?%^RESET%^");
  return 1;
  }

  if(str != "home"){
    notify_fail("%^ORANGE%^You can only go %^GREEN%^home%^ORANGE%^ "+
"using the magic of the acorn!%^RESET%^");
  return 1;
  }

  if(tracker > time()){
    tell_object(TP,"%^ORANGE%^The acorn's magic hasn't revived "+
"enough to aid you.  Maybe later.%^RESET%^");
  return 1;
  }

  tracker=time()+3600;
    if(str=="home"){
      if(TP->query_highest_level()>=7){
      tell_object(TP,"%^ORANGE%^The strength of your will is too "+
"powerful for the magic of the acorn.  You will no longer be able "+
"to use its magic.%^RESET%^");
      return 1;
      }

      if(TP->query_highest_level()<=6){
        tell_object(TP,"%^GREEN%^You hold the acorn aloft and think "+
"of home.\n%^GREEN%^The world shifts before you and suddenly you "+
"find yourself standing in a garden near your current home.%^RESET%^");

        tell_room(ETP,"%^GREEN%^"+TP->QCN+" holds a small acorn aloft "+
"and suddenly vanishes from sight!%^RESET%^",TP);
        TP->move("/d/newbie/rooms/town/park2");
      return 1;
      }
    }
}


