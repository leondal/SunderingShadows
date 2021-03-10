// made by Kayla of ShadowGate 9/24/94
// colorized by Melnmarn@ShadowGate & Ted Turner 03/05/95
// Revamped and updated by TRISTAN 03/29/09 
// updated by Ares to take out all the random rolling until Circe finishes point buy
// complete revision to allow pointbuy, all stats based on 6min, 18max, 92pt overall cap. -N, 10/10.
#include <std.h>
#include <daemons.h>
#include <rooms.h>
#define STATS ({"strength","wisdom","intelligence","dexterity","constitution","charisma"})
#include "ansi.h"

inherit ROOM;

#define MAXPOINTS 56 // 92 total points minus 36 starting points (6 per stat). -N, 10/10.
#define CLS ESC+"[H"+ESC+"[2J"

void okdone();
void upstats();
int bonus, donedone;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport", 1);
   set_short("The Setting Room");
   set_long("%^BOLD%^%^WHITE%^You are standing in a small room with white walls and a tiled ceramic floor.  On the wall "
"there is a list of instructions that read:\n"
"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"%^CYAN%^Step 1.  %^YELLOW%^Thou shalt <add> your bonus points to statistics. Eg/ <add 3 to dexterity>\n"
"%^CYAN%^Step 2.  %^YELLOW%^Thou shalt type <done> when you have added all your stats and not before. Or, thou shalt <reset> "
"if thou wisheth to start again.\n"
"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"%^WHITE%^  Shouldst thou need to read these intructions again, thou shalt type <look> and thou willt be informed.\n");
}

void init() {
   ::init();
   if(avatarp(TP)) return;
   TP->set_stats("strength",6);
   TP->set_stats("dexterity",6);
   TP->set_stats("constitution",6);
   TP->set_stats("charisma",6);
   TP->set_stats("wisdom",6);
   TP->set_stats("intelligence",6);
   TP->set_stats("exceptional_strength",-1);
   TP->force_me("look");

   add_action("reroll","reset");
   add_action("okdone","done");
   upstats();
}

int reroll() {
   donedone=0;
   bonus = 0;
   init();
   return 1;
}

int okdone() {
   TP->set("new_class_type",1);
   TP->set("new_hp_rolled_two",1);
   TP->set("new_stat_type2",1);
   TP->move(new("/d/shadowgate/race_set"));
   return 1;
}

int add_stat(string str) {
   int amount;
   string stat;

   if(donedone) return 0;
   if(!str) {
      write("%^BOLD%^%^YELLOW%^ Syntax: add # to stat");
      if(bonus == 0) write("%^BOLD%^%^WHITE%^You are finished. Please type %^MAGENTA%^done%^WHITE%^ to continue or "
"%^MAGENTA%^reset%^WHITE%^ to start again.%^RESET%^");
      else write("%^YELLOW%^You have "+bonus+" left to add.%^RESET%^");
      write("");
      write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
      write("%^BOLD%^%^MAGENTA%^    Current scores   %^RESET%^");
      write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
      write("%^BOLD%^%^BLUE%^ strength     --- "+TP->query_stats("strength"));
      write("%^BOLD%^%^BLUE%^ intelligence --- "+TP->query_stats("intelligence"));
      write("%^BOLD%^%^BLUE%^ dexterity    --- "+TP->query_stats("dexterity"));
      write("%^BOLD%^%^BLUE%^ constitution --- "+TP->query_stats("constitution"));
      write("%^BOLD%^%^BLUE%^ wisdom       --- "+TP->query_stats("wisdom"));
      write("%^BOLD%^%^BLUE%^ charisma     --- "+TP->query_stats("charisma"));
      return 1;
   }
   if(sscanf(str,"%d to %s",amount,stat)!= 2) {
      write("%^BOLD%^%^YELLOW%^Syntax: add # to stat");
      return 1;
   }
   if(amount > bonus) {
      write("%^BOLD%^%^RED%^ You have only "+bonus+" points left to apply.");
      return 1;
   }
   if(stat == "str") stat = "strength";
   if(stat == "int") stat = "intelligence";
   if(stat == "dex") stat = "dexterity";
   if(stat == "con") stat = "constitution";
   if(stat == "cha") stat = "charisma";
   if(stat == "wis") stat = "wisdom";
   if(member_array(stat, STATS) == -1) {
      write("%^BOLD%^%^CYAN%^Try a stat that you have.");
      return 1;
   }
   if((int)TP->query_stats(stat)+amount > 18 ) {
      write("%^BOLD%^%^RED%^That score will exceed 18. %^WHITE%^ Please reenter.");
      return 1;
   }
   if(amount < 0) {
      write("%^BOLD%^%^GREEN%^You cannot subtract points. Please %^WHITE%^reset%^GREEN%^ if you need to start again.");
      return 1;
   }

   TP->set_stats(stat, ((int)TP->query_stats(stat)+amount));
   bonus -= amount;

   if(bonus == 0) write("%^BOLD%^%^WHITE%^You are finished. Please type %^MAGENTA%^done%^WHITE%^ to continue or "
"%^MAGENTA%^reset%^WHITE%^ to start again.%^RESET%^");
   else write("%^YELLOW%^You have "+bonus+" left to add.%^RESET%^");
   write("");
   write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   write("%^BOLD%^%^MAGENTA%^    Current scores   %^RESET%^");
   write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   write("%^BOLD%^%^BLUE%^ strength     --- "+TP->query_stats("strength"));
   write("%^BOLD%^%^BLUE%^ intelligence --- "+TP->query_stats("intelligence"));
   write("%^BOLD%^%^BLUE%^ dexterity    --- "+TP->query_stats("dexterity"));
   write("%^BOLD%^%^BLUE%^ constitution --- "+TP->query_stats("constitution"));
   write("%^BOLD%^%^BLUE%^ wisdom       --- "+TP->query_stats("wisdom"));
   write("%^BOLD%^%^BLUE%^ charisma     --- "+TP->query_stats("charisma"));
   return 1;
}

void upstats() 
{
    object desc;
   TP->new_body();
   bonus = 56; //92 - 36 starting stats

   TP->convert_relationships();

   if(objectp(to_object("/daemon/description_d")))
   if(desc = new("/daemon/description_d"))
   {
       desc->new_description_profile(TP);
       destruct(desc);
   }

   write("%^BOLD%^%^YELLOW%^You are given an extra "+bonus+" points to boost your starting scores.%^RESET%^");
   write("%^BOLD%^%^CYAN%^Each score must be at least %^BLUE%^6%^CYAN%^ and at most %^BLUE%^18.%^RESET%^");
   write("%^BOLD%^%^WHITE%^Syntax example: add %^RESET%^ 2 to strength");
   write("%^BOLD%^%^WHITE%^This will make you strength 2 points higher.");
   write("%^BOLD%^%^WHITE%^Type %^YELLOW%^done%^BOLD%^%^WHITE%^ when finished.");
   write("");
   write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   write("%^BOLD%^%^MAGENTA%^    Current scores   %^RESET%^");
   write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   write("%^BOLD%^%^BLUE%^ strength     --- "+TP->query_stats("strength"));
   write("%^BOLD%^%^BLUE%^ intelligence --- "+TP->query_stats("intelligence"));
   write("%^BOLD%^%^BLUE%^ dexterity    --- "+TP->query_stats("dexterity"));
   write("%^BOLD%^%^BLUE%^ constitution --- "+TP->query_stats("constitution"));
   write("%^BOLD%^%^BLUE%^ wisdom       --- "+TP->query_stats("wisdom"));
   write("%^BOLD%^%^BLUE%^ charisma     --- "+TP->query_stats("charisma"));
   add_action("add_stat","add");
}