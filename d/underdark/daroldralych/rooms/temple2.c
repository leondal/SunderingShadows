#include <std.h>
#include "../defs.h"
#define FUNDS "/daemon/templefunds_d.c"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("A small, ornate shrine");
   set_short("%^MAGENTA%^A small, ornate shrine%^RESET%^");
   set_long("%^MAGENTA%^A small, ornate shrine%^RESET%^\n"
"%^BOLD%^%^BLACK%^This sidechamber has been somewhat separated from the rest of the temple, and is decorated in quite a "
"distinctly different style to the building itself.  The walls, roof and floor are of %^RESET%^%^BLUE%^glo%^BOLD%^s"
"%^RESET%^%^BLUE%^sy %^BOLD%^%^BLACK%^black obsidian, with the unmarred hue of a starless midnight sky.  The fine "
"tapestries and silks are missing from this section of the temple, as is the fine carpet underfoot.  Instead, the only "
"items of intereset here are a series of stone pedestals, each of which supports a martial weapon.  Some are stained with "
"%^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^while others are notched from heavy impact.  At the end of the room stands an "
"austere zurkhwood altar, draped with a single cloth of %^RESET%^%^RED%^deep c%^BOLD%^r%^RESET%^%^RED%^imson%^BOLD%^"
"%^BLACK%^.  Upon it is depicted a %^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k ga%^BOLD%^%^BLACK%^unt%^RESET%^let%^BOLD%^"
"%^BLACK%^, tightly clenched around scattered rays of %^RESET%^%^GREEN%^em%^BOLD%^e%^YELLOW%^r%^RESET%^%^GREEN%^a%^CYAN%^l"
"%^GREEN%^d %^BOLD%^%^BLACK%^light, and imposed over a crossed sword and mace.  Atop the altar is a small obsidian box"
".%^RESET%^\n");
   set_smell("default","%^ORANGE%^The heady, %^MAGENTA%^in%^CYAN%^to%^MAGENTA%^xica%^BOLD%^t%^RESET%^%^MAGENTA%^ing "
"%^ORANGE%^aroma of incense fills the air.");
   set_listen("default","%^CYAN%^P%^GREEN%^ra%^CYAN%^y%^GREEN%^er%^CYAN%^s %^GREEN%^of the faithful surround you with a "
"dull %^ORANGE%^mur%^YELLOW%^m%^RESET%^%^ORANGE%^ur %^GREEN%^of sound.");

   set_items(([
     ({"walls","roof","floor"}):"%^BOLD%^%^BLACK%^The walls, roof and floor are all carved from %^RESET%^%^BLUE%^glo"
"%^BOLD%^s%^RESET%^%^BLUE%^sy %^BOLD%^%^BLACK%^black obsidian, much as the rest of this building is.  This room is far "
"more %^RESET%^%^CYAN%^austere %^BOLD%^%^BLACK%^than the rest of the temple, however, completely lacking the fine "
"tapestries and soft carpet found elsewhere.%^RESET%^",
     ({"altar","zurkhwood altar"}):"%^BOLD%^%^BLACK%^The zurkhwood altar at the far end of the room is simple and stocky "
"in design, with no elegance or tracery to lighten its shape.  A single %^RESET%^%^RED%^c%^BOLD%^r%^RESET%^%^RED%^imson"
"%^BOLD%^%^BLACK%^ cloth is draped across it, upon which is displayed a slightly unusual symbol of the B%^GREEN%^l"
"%^BLACK%^ack Ha%^RED%^n%^BLACK%^d.%^RESET%^",
     ({"gauntlet","black gauntlet","cloth"}):"%^BOLD%^%^BLACK%^Across the altar is draped a single cloth of %^RESET%^"
"%^RED%^deep c%^BOLD%^r%^RESET%^%^RED%^imson%^BOLD%^%^BLACK%^, upon which is depicted a %^RESET%^bl%^BOLD%^%^BLACK%^ac"
"%^RESET%^k ga%^BOLD%^%^BLACK%^unt%^RESET%^let%^BOLD%^%^BLACK%^, tightly clenched around scattered rays of %^RESET%^"
"%^GREEN%^em%^BOLD%^e%^YELLOW%^r%^RESET%^%^GREEN%^a%^CYAN%^l%^GREEN%^d %^BOLD%^%^BLACK%^light, and imposed over a crossed "
"sword and mace.%^RESET%^",
     ({"pedestals","stone pedestals","weapon","weapons","martial weapons"}):"%^BOLD%^%^BLACK%^A series of stone pedestals "
"encircle the room itself, leading towards the altar.  Each displays a single martial weapon, ranging from sp%^RESET%^ik"
"%^BOLD%^%^BLACK%^ed gauntlets and maces through to narrow swords and serrated daggers.  Some are %^RESET%^%^RED%^bl"
"%^BOLD%^o%^RESET%^%^RED%^odst%^MAGENTA%^ai%^RED%^ned%^BOLD%^%^BLACK%^, while others are notched and scratched from prior "
"use.  All, however, are crafted for a similar level of brutality and viciousness in combat.%^RESET%^",
     ({"box","donation box","small box"}):"%^BOLD%^%^BLACK%^A carved box of obsidian rests atop the altar.  It awaits "
"worshippers to %^RESET%^donate%^BOLD%^%^BLACK%^ items.%^RESET%^",
   ]));
   set_exits(([
     "west":ROOMS"temple1",
   ]));
}

void reset(){
   ::reset();
   //echoes here
}

void init() {
    ::init();
    add_action("donate", "donate");
}

int donate(string str) {
   string type;
   int x, amount, amt2;
   object what;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) {
      notify_fail("Correct syntax: <donate [amount] [type]> or <donate [item]>\n");
      return 0;
   }
   if(TP->query_property("dominated")) return notify_fail("The god senses your true feelings and does not "
"accept your donation.\n");
   if(what = present(str, TP)) {
      amount = (int)what->query_value();
      type = what->query_cointype();
      if(!amount || !type) {
         write("That "+str+" is apparently worthless.");
         return 1;
      }
      if(what->query_worn()) {
        write("Please remove that before donating it.");
        return 1;
      }
      if(what->query_wielded()) {
        write("Please unwield that before donating it.");
        return 1;
      }
      tell_room(TO, TPQCN+" donates "+(string)what->query_short()+" to the temple.",TP);
      tell_object(TP, "You donate "+(string)what->query_short()+" to the temple.");
      what->remove();
      if(what) destruct(what);
      FUNDS->add_temple_gold(base_name(TO), amount, type, TP, "bane", 1);
      return 1;
   }
   if(sscanf(str, "%d %s", amount, type) != 2) {
      notify_fail("Please try either <donate [amount] [type]> or <donate [item]>\n");
      return 0;
   }
   if((int)TP->query_money(type) < amount) {
      notify_fail("You check your pockets and realize you do not have that many "+type+"!\n");
      return 0;
   }
   if(amount < 0) {
      notify_fail("No, you can't do that and yes, we're watching!\n");
      return 0;
   }
   FUNDS->add_temple_gold(base_name(TO), amount, type, TP, "bane");
   tell_object(TP,"You slip the "+amount+" "+type+" coins into the donation box.");
   tell_room(ETP,TPQCN+" donates some "+type+" coins to the temple's donation box.",TP);
   return 1;
}
