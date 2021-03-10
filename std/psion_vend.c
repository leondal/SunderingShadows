//Added a check for move ok to stop items being lost in the void.  Circe
#include <std.h>
#include <money.h>
#include <daemons.h>
#include <move.h>

#define LINE "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"

inherit NPC;

int crystal_price;

void create(){
   ::create();
}

void init(){
   ::init();
   add_action("__Buy", "buy");
   add_action("__List", "list");
   add_action("__Help", "help");
   add_action("__Sell","sell");
}

int __Buy(mixed str){
   object ob, newcrys, newbag;
   int pgold,cost, success;
   string response;
   response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";

   if(!str) return notify_fail("Syntax: buy <itemname> or <itemnumber>\n");
   crystal_price = (int)TP->query_highest_level() * 200;
   if(crystal_price > 5000) crystal_price = 5000;
   if(!TP->is_class("psion") && !TP->is_class("psywarrior")){
	tell_room(ETO, response+"I'm sorry, but I will not sell to "+
         "someone without psionic abilities.");
      return 1;
   }
   if(member_array(str,({"crystal","psicrystal"})) != -1){
      if(!TP->query_funds("gold",crystal_price)){
	   tell_room(ETO, response+"You do not have enough money to buy "+
            "a psicrystal.  It will cost you "+crystal_price+" gold.");
         return 1;
      }
      tell_room(ETO,response+"Here you are then...one psicrystal.");
      TP->use_funds("gold",crystal_price);
      newcrys = new("/d/magic/psicrystal"); 
      if (newcrys->move(TP) != MOVE_OK){ 
         newcrys->move(ETP);
         tell_room(ETO, response+"I'll just place the crystal in front "+
            "of you as you don't seem able to carry it.");
      }
      return 1;
   }
   if(member_array(str,({"pouch","components pouch","crystal pouch","crystals pouch"})) != -1){
      if(!TP->query_funds("gold",10)){
         tell_room(ETO, response+"You do not have enough gold for a "+
            "new crystals pouch.");
         return 1;
      }
      TP->use_funds("gold",10);
	tell_room(ETO, response+"Here is your new crystals pouch.");
      newbag = new("/d/magic/psi_comp_bag"); 
      if (newbag->move(TP) != MOVE_OK){ 
         newbag->move(ETP);
         tell_room(ETO, response+"It seems your hands are full.  I'll "+
            "just put this on the floor for you.");
      }
      return 1;
   }
   return 1;
}

int __List(string str){
   if(str) return notify_fail("Simply try <list>.\n");
   crystal_price = (int)TP->query_highest_level() * 200;
   if(crystal_price > 5000) crystal_price = 5000;
   write(
"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
"   %^CYAN%^Psicrystal               %^YELLOW%^"+crystal_price+" gold%^RESET%^\n"
"   %^CYAN%^Crystals Pouch           %^YELLOW%^10 gold%^RESET%^\n"
"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
);
   return 1;
}

int __Help(string nothing){
   if(nothing != "store" && nothing != "shop") return 0;
   write(
"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
"                       %^BOLD%^%^WHITE%^Psionics Store Help\n"
"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
"    %^CYAN%^There are 3 commands in the psionics store. The shopkeeper\n"
"    understands 'help', 'buy', and 'list'.\n"
"    syntax: 'list'\n"
"        The list command will list all items available in this shop.\n"
"    syntax: 'buy <item name>','buy crystal','buy pouch'\n"
"        This will let you buy a new psicrystal or a pouch to hold your\n"
"        crystals.\n"
"    syntax: 'help store'\n"
"        Displays this text.\n"
"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
);
   return 1;
}