#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int mycharge;

void create() {
   ::create();
   set_name("platinum amulet");
   set_id(({"amulet","platinum amulet","amulet wrought of platinum","talisman","talisman of vocal clarity"}));
   set_short("%^BOLD%^%^WHITE%^Talisman of V%^CYAN%^o%^WHITE%^cal Clar%^GREEN%^i%^WHITE%^ty%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^an amulet wrought of pla%^CYAN%^t%^WHITE%^inum%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This simple amulet has been wrought from brilliant "
"%^CYAN%^plat%^WHITE%^in%^CYAN%^um %^WHITE%^metal, wrought finely by only the most skilled "
"of crafters.  It forms a simple %^GREEN%^diamond %^WHITE%^shape, patterned around the "
"outer edge with %^RESET%^c%^BOLD%^%^BLACK%^ri%^RESET%^m%^BOLD%^%^BLACK%^pe%^RESET%^d "
"%^BOLD%^%^WHITE%^folds.  This is the only decoration to its %^YELLOW%^glossy %^WHITE%^"
"metallic surface, leaving it simple but elegant in appearance.  A short %^BLUE%^"
"ins%^CYAN%^cr%^BLUE%^ipt%^CYAN%^io%^BLUE%^n %^WHITE%^is etched upon the "
"underside.%^RESET%^\n");
   set_lore("Such amulets as these are often used by spellcrafters to imbue with magical "
"effects, due to their quality of workmanship. Only superior metals such as mithril and "
"platinum are used, as lesser metals tend not to retain their arcane properties over long "
"spans of time. Each amulet is marked with runes to distinguish their purpose, as they are "
"usually crafted for lay users rather than wizards.");
   set_property("lore difficulty",12);
   set("read","%^BOLD%^%^WHITE%^-speak the %^YELLOW%^tongues%^WHITE%^ of others-%^RESET%^");
   set_language("wizish");
   set_limbs(({"neck"}));
   set_weight(2);
   set_value(0);
   set_size(-1);
   set_ac(0);
   set_type("ring");
   mycharge = roll_dice(2,3);
   set_property("no disenchant",1);
}

void init() {
   ::init();
   add_action("speechez","tongues");
}

int speechez(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the amulet.");
     return 1;
   }
   if(str) {
     tell_object(TP, "Just 'tongues' will work.");
     return 1;
   }
   if(!mycharge) {
     tell_object(TP,"You've already used up the power the amulet had.");
     return 1;
   }
   mycharge--;
   new("/cmds/spells/t/_tongues")->use_spell(TP,TP,25,100,"mage");
   return 1;
}