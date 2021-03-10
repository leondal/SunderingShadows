#include <std.h>

//Added following so it's wieldable with weapon feats Octothorpe 5/6/09
inherit "/d/common/obj/weapon/mstaff.c";
#define MAXUSES1 15
#define MAXUSES2 10

int fire;
int lightning; 

void create() {
   ::create();
   set_name("rod of wizardry");
   set_id(({"rod","rod of wizardry","rod of wizardry I"}));
   set_obvious_short("A rod");
   set_short("%^BOLD%^%^RED%^Rod of Wizardry I%^RESET%^");
   set_long(
      "%^BOLD%^%^RED%^This rod is shaped from a smooth reddish metal."+
      " It is two and a half feet long with a weight heavier than one"+
      " might expect before placing it firmly in their grasp. Along the"+
      " length of the rod three different words are written."
   );
   set_value(5000);
   set_size(1);
   set_weight(12);
   set_wield((:TO,"wieldme":));
   set_lore("Mages have long searched for a way to add to their "+
	"might in battle.  Naturally poor in the art of melee, wizards"+
	" and sorceresses have always relied on their arcane might.  "+
	"One battle mage by the name of Belarephant created a magical "+
	"rod that held some of the most common battle spells known to "+
	"mages.  If to conserve his arcane power or to use the rod"+
	" as a backup when his preperations for the day were exhausted,"+
	" no one is sure.  All they were sure of, stay far away from "+
	"Belerephant.");
   set_property("lore",12);
}

int wieldme(){
   if((TP->is_class("mage"))){
      if((int)ETO->query_highest_level() <15){
            tell_object(ETO,"%^BOLD%^%^RED%^The rod is too powerful for one such as yourself.");
            return 0;
      }
   write("%^BOLD%^%^RED%^You grip the rod firmly.");
   return 1;
   }
   write("%^BOLD%^%^RED%^You are unable to control the power of the rod!");
   return 0;
}

void init() {
   ::init();
   add_action("read_rod","read");
   add_action("magic_missile","dart");
   add_action("scorcher","fire");
   add_action("lightning_bolt","lightning");
}

int read_rod(string str) {
   if(!str) return notify_fail("Read what?");
   if(str == "rod") {
      write("%^BOLD%^%^RED%^Traced along the shaft of the rod are the words %^BOLD%^%^YELLOW%^Dart%^BOLD%^%^RED%^, %^BOLD%^%^YELLOW%^Fire%^BOLD%^%^RED%^, and %^BOLD%^%^YELLOW%^Lightning%^BOLD%^%^RED%^.");
      return 1;
   }
}

int magic_missile(string str) {
object ob;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()) return notify_fail("Wield it first?");
   if(!str) return notify_fail("You must designate a target!");
   if(!(ob = present(str, ETP))) return notify_fail("You do not see that!");
   tell_room(ETP, "%^BOLD%^%^CYAN%^"+TPQCN+" raises "+TP->query_possessive()+" rod and utters a word!",TP);
   new("/cmds/spells/m/_magic_missile")->use_spell(TP,ob,10,100,"mage");
   TP->set_paralyzed(7,"You are busy controlling the rod.");
   return 1;
}

int scorcher(string str) {
object ob;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()) return notify_fail("Wield it first?");
   if(fire < MAXUSES1) {
   if(!str) return notify_fail("You must designate a target!");
   if(!(ob = present(str, ETP))) return notify_fail("You do not see that!");
   tell_room(ETP, "%^BOLD%^%^RED%^"+TPQCN+" raises "+TP->query_possessive()+" rod and utters a word!",TP);
   new("/cmds/spells/s/_scorcher")->use_spell(TP,ob,10,100,"mage");
   TP->set_paralyzed(7,"You are busy controlling the rod.");
   fire +=1;
   return 1;
   }
   else{
      tell_object(TP, "The rod does not have enough power to do that.");
   }
   return 1;
}

int lightning_bolt(string str) {
object ob;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()) return notify_fail("Wield it first?");
   if(lightning < MAXUSES2) {
   if(!str) return notify_fail("You must designate a target!");
   if(!(ob = present(str, ETP))) return notify_fail("You do not see that!");
   tell_room(ETP, "%^BOLD%^%^YELLOW%^"+TPQCN+" raises "+TP->query_possessive()+" rod and utters a word!",TP);
   new("/cmds/spells/l/_lightning_bolt")->use_spell(TP,ob,10,100,"mage");
   TP->set_paralyzed(7,"You are busy controlling the rod.");
   lightning +=1;
   return 1;
   }
   else{
      tell_object(TP, "The rod does not have enough power to do that.");
   }
   return 1;
}

