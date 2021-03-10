#include <std.h>
#include "../defs.h"
#define FUNDS "/daemon/templefunds_d.c"
inherit "/std/church";

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("The ceremonial altar chamber");
   set_short("%^MAGENTA%^The ceremonial altar chamber%^RESET%^");
   set_long("%^MAGENTA%^The ceremonial altar chamber%^RESET%^\n"
"%^BOLD%^%^BLACK%^At the entrance to this grand room is a carved box, set upon a small table.  Just beyond it lies the "
"first of many rings of seating, split by two rows of stairs, that lead down in concentric circles to a raised dais in "
"the centre of the room.  Impressive enough for use in the holiest of rituals, the great central altar upon the dais is "
"of a perfect %^RESET%^%^BLUE%^mi%^BOLD%^r%^RESET%^%^BLUE%^ror %^BOLD%^%^BLACK%^surface, and covered in ornate carvings "
"of %^RESET%^%^WHITE%^wr%^BOLD%^%^BLACK%^a%^RESET%^ith%^BOLD%^%^BLACK%^li%^RESET%^ke spi%^BOLD%^%^BLACK%^d%^RESET%^ers"
"%^BOLD%^%^BLACK%^ over which living arachnids crawl unchecked.  Slender archways run up the curved walls to the roof, "
"to meet in the middle behind a massive carved figure that looms above the room's onlookers.  It takes the form of a drow "
"woman of %^RESET%^%^CYAN%^st%^BOLD%^u%^RESET%^%^CYAN%^nni%^GREEN%^ng%^CYAN%^ly %^BOLD%^%^BLACK%^fair aspect, completely "
"unclothed to the waist except for a tangled layer of spiderwebs.  From there, however, her torso spreads into the thorax "
"of a giant %^RESET%^%^RED%^sp%^ORANGE%^id%^RED%^er%^BOLD%^%^BLACK%^, legs splayed as if to cling to the stone of the "
"roof above.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The heady, %^MAGENTA%^in%^CYAN%^to%^MAGENTA%^xica%^BOLD%^t%^RESET%^%^MAGENTA%^ing "
"%^ORANGE%^aroma of incense fills the air.");
   set_listen("default","%^CYAN%^P%^GREEN%^ra%^CYAN%^y%^GREEN%^er%^CYAN%^s %^GREEN%^of the faithful surround you with a "
"dull %^ORANGE%^mur%^YELLOW%^m%^RESET%^%^ORANGE%^ur %^GREEN%^of sound.");

   set_items(([
     "sign":"%^BOLD%^%^BLACK%^A sign written in %^RESET%^%^WHITE%^stylized calligraphy %^BOLD%^%^BLACK%^has been tacked "
"to the wall.  You should %^RESET%^%^WHITE%^read %^BOLD%^%^BLACK%^it.%^RESET%^",
     "altar":"%^BOLD%^%^BLACK%^The altar is a massive block of obsidian, polished to a perfect %^RESET%^%^BLUE%^mi"
"%^BOLD%^r%^RESET%^%^BLUE%^ror %^BOLD%^%^BLACK%^surface, large enough to easily fit two humans lying side by side.  It is "
"covered in ornate carvings of %^RESET%^%^WHITE%^wr%^BOLD%^%^BLACK%^a%^RESET%^ith%^BOLD%^%^BLACK%^li%^RESET%^ke spi"
"%^BOLD%^%^BLACK%^d%^RESET%^ers%^BOLD%^%^BLACK%^, which have been decorated with carefully placed shards of%^RESET%^"
"%^MAGENTA%^ gli%^WHITE%^t%^MAGENTA%^teri%^WHITE%^n%^MAGENTA%^g amet%^WHITE%^h%^MAGENTA%^yst%^BOLD%^%^BLACK%^.  Living "
"spiders crawl freely across the altar itself, and along the walls and floor unchecked.%^RESET%^",
     ({"walls","floor","roof"}):"%^BOLD%^%^BLACK%^The entire room around you has been shaped from solid obsidian, with "
"delicate archways running up the walls to meet above your head in a large, ovoid outline of stone.%^RESET%^",
     ({"arches","archways","great archways"}):"%^BOLD%^%^BLACK%^Slender archways run up the walls at intervals around the "
"room, meeting together at the statue upon the centre of the roof above.  Unlike the prior chamber, no patterning marks "
"their surfaces, perhaps so as not to detract from the magnificence of the altar and the looming figure above.%^RESET%^",
     ({"stairs","lines of stairs","steps"}):"%^BOLD%^%^BLACK%^Two matching lines of obsidian stairs carve paths through "
"the rings of seating, allowing access to the rows lower down.%^RESET%^",
     ({"seating","rings of seating","seats","rings of seats"}):"%^BOLD%^%^BLACK%^Lines of seating, carved from flawless "
"o%^RESET%^bs%^BOLD%^%^BLACK%^id%^RESET%^ia%^BOLD%^%^BLACK%^n stone, run around the room in concentric rings down toward "
"the centre.%^RESET%^",
     ({"figure","drow figure","carving","spider","carved figure"}):"%^BOLD%^%^BLACK%^Faint %^RESET%^%^MAGENTA%^fae"
"%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BOLD%^%^BLACK%^ outlines the carved figure upon the roof above you, of a %^RESET%^"
"%^CYAN%^st%^BOLD%^u%^RESET%^%^CYAN%^nni%^GREEN%^ng%^CYAN%^ly %^BOLD%^%^BLACK%^fair drow female.  Only criss-crossed "
"layers of spiderweb cover her otherwise naked figure to the waist, at which point a the thorax of a giant spider grows "
"to spread its spindly black legs across the roof.  Her face is contorted into a look of sheer %^RESET%^%^RED%^mal%^BOLD%^"
"e%^RESET%^%^RED%^vola%^BOLD%^n%^RESET%^%^RED%^ce%^BOLD%^%^BLACK%^, marring the woman's otherwise beautiful features"
".%^RESET%^",
     ({"box","donation box","carved box","obsidian box","table","small table"}):"%^BOLD%^%^BLACK%^A carved box of "
"obsidian rests upon a small table at the entrance to this grand room.  It awaits worshippers to %^RESET%^donate%^BOLD%^"
"%^BLACK%^ items.%^RESET%^",
   ]));
   set_exits(([
     "south":ROOMS"temple1",
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
      FUNDS->add_temple_gold(base_name(TO), amount, type, TP, "shar", 1);
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
   FUNDS->add_temple_gold(base_name(TO), amount, type, TP, "shar");
   tell_object(TP,"You slip the "+amount+" "+type+" coins into the donation box.");
   tell_room(ETP,TPQCN+" donates some "+type+" coins to the temple's donation box.",TP);
   return 1;
}
