//room for tax collector for the Torm crime syndicate.
//Circe 7/12/04
#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
#include <daemons.h>
#define LEVELS ({"low","medium","high"})

inherit ROOM;

int tax1;
int tax2;
int tax3;

void create()
{
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_name("A Small Office on the Boardwalk");
   set_short("A Small Office on the Boardwalk");
   set_long(
   "A Small Office on the Boardwalk.\n"
   "This office stands on the lower boardwalk looking out over the Dagger "+
   "Sea.  The office is tidy, with a simple wooden desk and chair in the "+
   "southern part of the room, leaving enough space for sailors to travel "+
   "between the two doors.  A locked cabinet stands in the southwestern "+
   "corner, and numerous papers and folios are on the desk.  It seems that "+
   "all business must pass through this office, day or night.  A ladder just "+
   "outside the western door leads to the upper boardwalk.  The office "+
   "opens up to the east, and through the far doorway, you can see the "+
   "Dagger Sea.  A %^YELLOW%^small sign %^RESET%^"+
   "is posted on the wall behind the desk for you to read."
  );
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","The waves of the sea wash against the docks.");
  set_items(([
  ({"sea","dagger sea","Dagger Sea"}) : "%^BLUE%^The vast Dagger Sea"+
  " stretches far out into the distance. It is a dark blue and you can hear"+
  " the waves breaking against the city walls and docks.%^RESET%^",
  "fog" : "A light layer of fog covers the entire bay, spilling off"+
  " from the ocean into the city streets. During the early years of"+
  " the city, it was probably a wonderful protection against pirates"+
  " and others who might normally want to attack at night, for the"+
  " fog hides all the dangerous rocks, and most ships trying to dock"+
  " would be smashed to pieces. Now it simply limits trade to the"+
  " daytime hours, and probably brings in a lot of business for the"+
  " inns in the city, with everyone forced to stay here at night.",
  "spires" : "To the west you can see Torm's spires stretching into the sky.",
  "ships" : "There are many wooden ships around, all of them appear fairly"+
  " sturdy, though there are several different styles from various distant"+
  " lands. This is obviously a bustling sea port that draws business from"+
  " many places.",
  ({"birds","small birds"}) : "There are several small birds about, either"+
  " dozing or trying to get a bit of food that a sailor might have left behind.",
  ({"desk","wooden desk","chair"}) : "The wooden desk and chair are well-"+
  "made, if small.  The desk has been covered with writing implements, "+
  "ink, and papers that contain columns of numbers and names.",
  ({"papers","folios","ink","implements"}) : "Many of the papers are "+
  "in closed folios, but what you can see seems to be columns of "+
  "numbers and names, though they make little sense.  They are obviously "+
  "records of some kind.  A large ink pot with several quills rests on "+
  "the desk, just waiting to be used for another entry.",
  ({"cabinet","wooden cabinet","storage cabinet","locked cabinet"}) : "This "+
  "large wooden cabinet has several iron locks built into it, as well as "+
  "being chained.  There is no hint as to what might be inside.",
  ({"sign","small sign"}) : ({"This is a small sign painted with blue "+
  "letters that you could read.",(:TO,"read_sign":),"common"})
  ]));
  set_exits(([
     "up" : TCITY+"c70",
     "east" : TCITY+"dock_taxes"
  ]));
  set_pre_exit_functions(({"east"}),({"Pay_taxes"}));
}

void reset(){
   ::reset();
   if(!present("torm guard")){
      new(MON+"guard4")->move(TO);
   }
   if(!present("torm tax collector")){
      new(MON+"tax_collector")->move(TO);
   }
}

void init(){
   ::init();
   add_action("add_em","add");
   add_action("remove_em","remove");
   add_action("query_em","query");
   add_action("check_em","check");
   add_action("pay_em","pay");
}

void read_sign(){
   write(
@CIRCE
%^BOLD%^%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       %^BLUE%^Torm Tax Collector's Office

%^WHITE%^Here, taxes are collected for the city of 
Torm.  You may wish to <check status> to 
see whether or not you will be charged taxes.
If you owe taxes, you will need to <pay taxes>
before you can pass.
%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^
CIRCE
   );
   if(avatarp(TP)){
   write(
@CIRCE
Here, you may 
   <add player taxlevel>
      The tax levels are low, medium, and high, 
      charging 100, 300, and 700 gold respectively.
   <remove player>
      This will remove the player's name from the tax lists.
   <query player> of <query all>
      This will tell you if a player is being taxed and at 
      what level.  Query all returns all taxed players.
   <check killers>
      This will tell you which players have attacked the 
      tax collectors and when.
   <check cheaters>
      This will tell you which players have snuck past the 
      tax collectors and when.
%^RED%^Note%^RESET%^: Be sure to query a player and remove them 
if they are already being taxed before adding a new tax level or
you run the risk of them being taxed multiple times or causing bugs.
CIRCE
   );
   }
}

int pay_em(string str){
   string taxname;
   tax1 = SAVE_D->query_array("Torm_taxes_low");
   tax2 = SAVE_D->query_array("Torm_taxes_med");
   tax3 = SAVE_D->query_array("Torm_taxes_high");
   if(!str){
      tell_object(TP,"You may <pay taxes> here to pass through.");
      return 1;
   }
   if(str == "taxes"){
      if(!present("torm tax collector")){
         tell_object(TP,"There is not tax collector here!  It must "+
            "be your lucky day.");
         return 1;
      }
   if(member_array(TPQN, tax1) != -1) {
      if(present("torm tax collector")){
         taxname = present("torm tax collector")->QCN;
         if(!TP->query_funds("gold",100)){
            tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Hold "+
            "right there, "+TPQCN+".  It says here you owe taxes in "+
            "the amount of 100 gold.  You will have to return with "+
            "the funds to pay it before I can let you pass.");
            return 0;
         }
         tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Thank "+
            "you for your contribution, "+TPQCN+".  It will be put "+
            "to good use.");
         tell_room(TO,""+taxname+" collects some money from "+TPQCN+" "+
            "and locks it quickly away in the cabinet.");
         if(present("torm guard")){
            tell_object(TO,"The guard steps out of the way and lets "+
               ""+TPQCN+" pass.");
         }
         TP->set_property("paid taxes",1);
         TP->use_funds("gold",100);
         return 1;
      }
      return 1;
   }
   if(member_array(TPQN, tax2) != -1) {
      if(present("torm tax collector")){
         taxname = present("torm tax collector")->QCN;
         if(!TP->query_funds("gold",300)){
            tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Hold "+
            "right there, "+TPQCN+".  It says here you owe taxes in "+
            "the amount of 300 gold.  You will have to return with "+
            "the funds to pay it before I can let you pass.");
            return 0;
         }
         tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Thank "+
            "you for your contribution, "+TPQCN+".  It will be put "+
            "to good use.");
         tell_room(TO,""+taxname+" collects some money from "+TPQCN+" "+
            "and locks it quickly away in the cabinet.");
         if(present("torm guard")){
            tell_object(TO,"The guard steps out of the way and lets "+
               ""+TPQCN+" pass.");
         }
         TP->set_property("paid taxes",1);
         TP->use_funds("gold",300);
         return 1;
      }
      return 1;
   }
   if(member_array(TPQN, tax3) != -1) {
      if(present("torm tax collector")){
         taxname = present("torm tax collector")->QCN;
         if(!TP->query_funds("gold",700)){
            tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Hold "+
            "right there, "+TPQCN+".  It says here you owe taxes in "+
            "the amount of 700 gold.  You will have to return with "+
            "the funds to pay it before I can let you pass.");
            return 0;
         }
         tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Thank "+
            "you for your contribution, "+TPQCN+".  It will be put "+
            "to good use.");
         tell_room(TO,""+taxname+" collects some money from "+TPQCN+" "+
            "and locks it quickly away in the cabinet.");
         if(present("torm guard")){
            tell_object(TO,"The guard steps out of the way and lets "+
               ""+TPQCN+" pass.");
         }
         TP->set_property("paid taxes",1);
         TP->use_funds("gold",700);
         return 1;
      }
      return 1;
   }
   }
   tell_object(TP,"You may <pay taxes> here if you owe them.");
   return 1;
}

int add_em(string str){
   string player,level;
   tax1 = SAVE_D->query_array("Torm_taxes_low");
   tax2 = SAVE_D->query_array("Torm_taxes_med");
   tax3 = SAVE_D->query_array("Torm_taxes_high");
   if(!avatarp(TP)) return 0;
   if(!str){
      tell_object(TP,"Try <add playername taxlevel>");
      return 1;
   }
   if(sscanf(str,"%s %s",player,level) != 2){
      tell_object(TP,"Try <add playername taxlevel>");
      return 1;
   }
   player = lower_case(player);
   if(!user_exists(player)) {
      tell_object(TP,"%^RED%^Error: %^RESET%^"+
      "Player %^YELLOW%^"+capitalize(player)+" %^RESET%^does not exist!");
      return 1;
   }
   if(member_array(level,LEVELS) == -1){
      tell_object(TP,"That is not a valid level.  Try low, medium, or high.");
      return 1;
   }
   switch(level){
      case "low":  if(member_array(player, tax1) != -1) return notify_fail("Player "+
                      ""+capitalize(player)+" is already on the low tax list.\n");
                   SAVE_D->set_value("Torm_taxes_low", player);
                   tell_object(TP,"Player "+capitalize(player)+" added to "+
                      "the %^YELLOW%^low %^RESET%^tax list.");
                   break;
      case "medium":  if(member_array(player, tax2) != -1) return notify_fail("Player "+
                      ""+capitalize(player)+" is already on the medium tax list.\n");
                   SAVE_D->set_value("Torm_taxes_med", player);
                   tell_object(TP,"Player "+capitalize(player)+" added to the "+
                      "%^ORANGE%^medium %^RESET%^tax list.");
                   break;
      case "high":  if(member_array(player, tax2) != -1) return notify_fail("Player "+
                      ""+capitalize(player)+" is already on the high tax list.\n");
                   SAVE_D->set_value("Torm_taxes_high", player);
                   tell_object(TP,"Player "+capitalize(player)+" added to the "+
                      "%^BOLD%^%^RED%^high %^RESET%^tax list.");
                   break;
   }
   return 1;
}

int remove_em(string str){
   string player,level;
   int low,med,high;
   tax1 = SAVE_D->query_array("Torm_taxes_low");
   tax2 = SAVE_D->query_array("Torm_taxes_med");
   tax3 = SAVE_D->query_array("Torm_taxes_high");
   if(!avatarp(TP)) return 0;
   if(!str){
      tell_object(TP,"Try <remove playername>");
      return 1;
   }
   str = lower_case(str);
   if(!user_exists(str)) {
      tell_object(TP,"%^RED%^Error: %^RESET%^"+
      "Player %^YELLOW%^"+str+" %^RESET%^does not exist!");
      return 1;
   }
   if(member_array(str, tax1) != -1){
      low = 1;
   }
   if(member_array(str, tax2) != -1){
      med = 1;
   }
   if(member_array(str, tax3) != -1){
      high = 1;
   }
   if(!low && !med && !high){
      tell_object(TP,"Player "+capitalize(str)+" not found on any tax list.");
      return 1;
   }
   if(member_array(str, tax1) != -1){
      SAVE_D->remove_name_from_array("Torm_taxes_low",str);
      tell_object(TP,"Player "+capitalize(str)+" was removed from the "+
         "%^YELLOW%^low %^RESET%^tax list.");
   }
   if(member_array(str, tax2) != -1){
      SAVE_D->remove_name_from_array("Torm_taxes_med",str);
      tell_object(TP,"Player "+capitalize(str)+" was removed from the "+
         "%^ORANGE%^medium %^RESET%^tax list.");
   }
   if(member_array(str, tax3) != -1){
      SAVE_D->remove_name_from_array("Torm_taxes_high",str);
      tell_object(TP,"Player "+capitalize(str)+" was removed from the "+
         "%^BOLD%^%^RED%^high %^RESET%^tax list.");
      return 1;
   }
   return 1;
}

int query_em(string str){
   string player,level;
   int low,med,high,nolow,nomed,nohigh,i;
   string *names1; 
   string *names2;
   string *names3;
   tax1 = SAVE_D->query_array("Torm_taxes_low");
   tax2 = SAVE_D->query_array("Torm_taxes_med");
   tax3 = SAVE_D->query_array("Torm_taxes_high");
   names1 = SAVE_D->query_array("Torm_taxes_low");
   names2 = SAVE_D->query_array("Torm_taxes_med");
   names3 = SAVE_D->query_array("Torm_taxes_high");
   if(!avatarp(TP)) return 0;
   if(!str){
      tell_object(TP,"Try <query playername>");
      return 1;
   }
   if(str == "all"){
      if(!sizeof(names1)){
         tell_object(TP,"There are no players on the %^YELLOW%^low "+
            "%^RESET%^tax list.");
         nolow = 1;
      }
      if(!sizeof(names2)){
         tell_object(TP,"There are no players on the %^ORANGE%^medium "+
            "%^RESET%^tax list.");
         nomed = 1;
      }
      if(!sizeof(names3)){
         tell_object(TP,"There are no players on the %^BOLD%^%^RED%^high "+
            "%^RESET%^tax list.");
         nohigh = 1;
      }
      if(!nolow){
         tell_object(TP,"The following players are on the %^YELLOW%^low "+
            "%^RESET%^tax list.");
         for(i = 0;i < sizeof(names1);i++) {
             tell_object(TP,""+capitalize(names1[i])+"\n");
         }
      }
      if(!nomed){
         tell_object(TP,"The following players are on the %^ORANGE%^medium "+
            "%^RESET%^tax list.");
         for(i = 0;i < sizeof(names2);i++) {
             tell_object(TP,""+capitalize(names2[i])+"\n");
         }
      }
      if(!nohigh){
         tell_object(TP,"The following players are on the %^BOLD%^%^RED%^high "+
            "%^RESET%^tax list.");
         for(i = 0;i < sizeof(names3);i++) {
             tell_object(TP,""+capitalize(names3[i])+"\n");
         }
      }
      return 1;
   }
   str = lower_case(str);
   if(!user_exists(str)) {
      tell_object(TP,"%^RED%^Error: %^RESET%^"+
      "Player %^YELLOW%^"+str+" %^RESET%^does not exist!");
      return 1;
   }
   if(member_array(str, tax1) != -1){
      low = 1;
   }
   if(member_array(str, tax2) != -1){
      med = 1;
   }
   if(member_array(str, tax3) != -1){
      high = 1;
   }
   if(!low && !med && !high){
      tell_object(TP,"Player "+capitalize(str)+" not found on any tax list.");
      return 1;
   }else{
      if(low == 1) tell_object(TP,"Player "+capitalize(str)+" found on the "+
         "%^YELLOW%^low %^RESET%^tax list.");
      if(med == 1) tell_object(TP,"Player "+capitalize(str)+" found on the "+
         "%^ORANGE%^medium %^RESET%^tax list.");
      if(high == 1) tell_object(TP,"Player "+capitalize(str)+" found on the "+
         "%^BOLD%^%^RED%^high %^RESET%^tax list.");
      return 1;
   }
}

int check_em(string str){
   string player,level;
   int low,med,high;
   tax1 = SAVE_D->query_array("Torm_taxes_low");
   tax2 = SAVE_D->query_array("Torm_taxes_med");
   tax3 = SAVE_D->query_array("Torm_taxes_high");
   if(!str){
      if(avatarp(TP)){
         tell_object(TP,"Try <check killers>");
         return 1;
      }
      tell_object(TP,"Try <check status>");
      return 1;
   }
   if(str == "status"){
      if(member_array(TPQN, tax1) != -1){
         low = 1;
      }
      if(member_array(TPQN, tax2) != -1){
         med = 1;
      }
      if(member_array(TPQN, tax3) != -1){
         high = 1;
      }
      if(!low && !med && !high){
         tell_object(TP,"You are not showed as owing any taxes.");
         return 1;
      }else{
         if(low == 1) tell_object(TP,"You will be charged %^YELLOW%^100 gold "+
            "coins %^RESET%^in taxes for using this dock.");
         if(med == 1) tell_object(TP,"You will be charged %^YELLOW%^300 gold "+
            "coins %^RESET%^in taxes for using this dock.");
         if(high == 1) tell_object(TP,"You will be charged %^YELLOW%^700 gold "+
            "coins %^RESET%^in taxes for using this dock.");
         return 1;
      }
   }
   if(str == "killers"){
      if(!avatarp(TP)){
         tell_object(TP,"You cannot do that!");
         return 1;
      }
      tell_object(TP,"These are the attacks that have taken place "+
         "against the tax collectors.  It is up to you to decide if "+
         "they were witnessed and what the consequences might be.");
      if(!file_exists("/log/reports/tormdocks")){
         tell_object(TP,"It seems there have been no attacks.");
         return 1;
      }
      TP->more("/log/reports/tormdocks");
      return 1;
   }
   if(str == "cheaters"){
      if(!avatarp(TP)){
         tell_object(TP,"You cannot do that!");
         return 1;
      }
      tell_object(TP,"These are the people who have skipped out on "+
         "paying their taxes.  It is up to you to decide if "+
         "they were witnessed and what the consequences might be.");
      if(!file_exists("/log/reports/tormtaxes")){
         tell_object(TP,"It seems no one has tried to sneak by.");
         return 1;
      }
      TP->more("/log/reports/tormtaxes");
      return 1;
   }
   tell_object(TP,"You may <check status> here.");
   return 1;
}

int Pay_taxes(){
   string taxname;
   string myname = TPQN;
   string realname = capitalize(TP->query_true_name());
   tax1 = SAVE_D->query_array("Torm_taxes_low");
   tax2 = SAVE_D->query_array("Torm_taxes_med");
   tax3 = SAVE_D->query_array("Torm_taxes_high");
   if(!present("torm tax collector") && !present("torm guard")){
      if(member_array(myname, tax1) != -1){
         log_file("reports/tormtaxes",""+realname+" "+
         "didn't pay their taxes of 100 gold.  "+
         "["+ctime(time())+"].\n");
      }
      if(member_array(myname, tax2) != -1){
         log_file("reports/tormtaxes",""+realname+" "+
         "didn't pay their taxes of 300 gold.  "+
         "["+ctime(time())+"].\n");
      }
      if(member_array(myname, tax3) != -1){
         log_file("reports/tormtaxes",""+realname+" "+
         "didn't pay their taxes of 700 gold.  "+
         "["+ctime(time())+"].\n");
      }
   return 1;
   }
   if(TP->query_invis()){
      if(member_array(myname, tax1) != -1){
         log_file("reports/tormtaxes",""+realname+" "+
         "didn't pay their taxes of 100 gold.  "+
         "["+ctime(time())+"].\n");
      }
      if(member_array(myname, tax2) != -1){
         log_file("reports/tormtaxes",""+realname+" "+
         "didn't pay their taxes of 300 gold.  "+
         "["+ctime(time())+"].\n");
      }
      if(member_array(myname, tax3) != -1){
         log_file("reports/tormtaxes",""+realname+" "+
         "didn't pay their taxes of 700 gold.  "+
         "["+ctime(time())+"].\n");
      }
   return 1;
   }
   if((int)TP->query_property("paid taxes") == 1){
      TP->remove_property("paid taxes");
      return 1;
   }
   if(member_array(myname, tax1) != -1) {
      taxname = present("torm tax collector")->QCN;
      tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Hold "+
         "right there, "+TPQCN+".  It says here you owe taxes in "+
         "the amount of 100 gold.  You will have to return with "+
         "the funds to pay it before I can let you pass.");
      return 0;
   }
   if(member_array(myname, tax2) != -1) {
      taxname = present("torm tax collector")->QCN;
      tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Hold "+
         "right there, "+TPQCN+".  It says here you owe taxes in "+
         "the amount of 300 gold.  You will have to return with "+
         "the funds to pay it before I can let you pass.");
      return 0;
   }
   if(member_array(myname, tax3) != -1) {
      taxname = present("torm tax collector")->QCN;
      tell_room(TO,"%^MAGENTA%^"+taxname+" says%^RESET%^: Hold "+
         "right there, "+TPQCN+".  It says here you owe taxes in "+
         "the amount of 700 gold.  You will have to return with "+
         "the funds to pay it before I can let you pass.");
      return 0;
   }
   return 1;
}