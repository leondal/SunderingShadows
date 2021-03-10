#include <std.h>
#include "../defs.h"
inherit "/std/vendor_pstore";

#define MAX_ITEMS 50

void create() {
   ::create();
   set_name("Dirzstral");
   set_id(({"shop clerk","mail clerk","clerk","message keeper","message-keeper","dirzstral","Dirzstral"}));
   set_short("%^RESET%^%^BLUE%^Dirzstral Phaeraan, the message-keeper%^RESET%^");
   set_long("%^BLUE%^Behind the counter stands this youthful looking drow woman.  Her hair is cropped in a "
"simple shoulder-length style, pulled back from her face on one side with a single %^BOLD%^%^BLACK%^onyx comb"
"%^RESET%^%^BLUE%^.  While her eyes show an obvious intelligence within their %^BOLD%^%^BLACK%^dark depths"
"%^RESET%^%^BLUE%^, it seems at times that her mind is on other things than the shop she is supposed to be "
"minding.%^RESET%^");
   set_gender("female");
   set_race("drow");
   set_body_type("human");
   set("aggressive",0);
   set_hd(18,2);
   set_level(18);
   set_class("mage");
   set_mlevel("mage", 18);
   set_guild_level("mage",18);
   set_alignment(9);
   add_money("gold", random(500));
   set_mob_magic_resistance("average");
   set_overall_ac(5);
   set_stats("strength",18);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_exp(300);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_shop(ROOMS+"poffice");
   set_property("no bow",1);
}

void leave_letter(object cust, int step) {
   switch(step) {
     case 0:
      tell_room(ETO, cust->QCN+" hands the clerk a letter.", cust);
      tell_room(ETO, "%^GREEN%^Dirzstral takes both the money and paper.  With a snap of her fingers, both "
"the paper and the pouch of coins vanish.  The paper reappears instantaneously, filed in a tidy spot upon "
"the shelves behind the counter, though where the money went remains a mystery.%^RESET%^\n");
      delivering = 0;
     break;
     default:  break;
   }
}

void pickup_actions(object cust, object *what, int step) {
   int num;
   switch(step) {
     case 0:
	tell_room(ETO, "%^GREEN%^Dirzstral watches in silence as "+cust->QCN+" signs the log book.\n", cust);
	tell_object(cust, "%^GREEN%^Dirzstral silently watches as you sign your name.\n");
	call_out("pickup_actions", 2, cust, what, 1);
	break;
     case 1:
	tell_room(ETO, "%^GREEN%^She checks the name, and then turns to look at the shelves on the wall "
"behind her, her eyes scanning the pages filed there.\n");
	call_out("pickup_actions", 2, cust, what, 2);
	break;
     case 2:
    	num = sizeof(what);
    	if(num == 1) {
          tell_room(ETO,"%^GREEN%^Dirzstral nods and snaps her fingers once, and a sheet of paper appears "
"on the counter before you.  She takes it up and hands it to "+cust->QCN+".\n%^RESET%^", cust);
          tell_object(cust,"%^GREEN%^Dirzstral nods and snaps her fingers once, and a sheet of paper "
"appears on the counter before you.  She takes it up and hands it to you.\n%^RESET%^");
    	} else {
          tell_room(ETO,"%^GREEN%^Dirzstral nods and snaps her fingers once, and several sheets of paper appear "
"on the counter before her in a neat stack.  She takes them up and hands them to "+cust->QCN+".\n%^RESET%^", cust);
          tell_object(cust,"%^GREEN%^Dirzstral nods and snaps her fingers once, and "+num+" sheets of paper appear "
"on the counter before her in a neat stack.  She takes them up and hands them to you.\n%^RESET%^");
    	}   
      del_letter(cust, what);
	break;
      default:  break;
   }
}