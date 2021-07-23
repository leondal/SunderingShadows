#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int trackera, trackerb, trackerc;

void create(){
	::create();
	set_name("golden crown");
	set_id(({ "crown", "golden crown", "crown of the arcane flame" }));
	set_short("%^BOLD%^%^BLACK%^C%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^w%^BOLD%^%^BLACK%^n of the %^RESET%^%^MAGENTA%^A%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ca%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^e F%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^MAGENTA%^flame covered%^ORANGE%^ golden crown%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This golden crown is forged from a single billet of pure yellow gold.  The metal has been shaped into form by a master of the craft as all indication of tool marks and joints have been completely removed.  In the front of the golden circlet a set of five %^MAGENTA%^black opals %^ORANGE%^have been set.  The largest, worn over the brow of the head, is at least as big as a child's hand and is oval in shape.  To either side of the large opal a set of crescent opals have been set, and beside these, thin tapered opals curve around to either side of the crown.  These opals glitter with a dark %^MAGENTA%^amethyst light %^ORANGE%^that flickers and reflects the light of the arcane flames that dance along the top of the crown.  Though cool to the touch, there is a powerful energy that constantly swirls and resonates within the ever shifting swirl of %^MAGENTA%^purple flames%^ORANGE%^.%^RESET%^

AVATAR
	);
	set_weight(10);
   set_value(0);
	set_lore(
@AVATAR
The crown of the arcane flame is said to have been forged by the "Lich of Attaya".  Though little is known of his origins, it is said he surfaced within the later half of the seventh century SG.  The lich having been defeated about the same time by a young band of heroes.  The crown purportedly is imbued with arcane knowledge and magics which only several life times worth of study could reveal.  The "Lich of Attaya" had such a life time and is considered one of the most powerful creatures to have ever been found upon the accursed island.  Though, considering what else makes its home in the barrens of Attaya, the truth of this statement is up for speculation.  

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_overallStatus(220);
    set_property("no disenchant",1);
      trackera = 0;
      trackerb = 0;
      trackerc = 0;
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" places their "+query_short()+"%^RESET%^%^ORANGE%^ upon their head.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^As you don the crown of the arcane flame, knowledge fills your mind.  %^MAGENTA%^Summon%^ORANGE%^ fire to smite your enemy.  %^MAGENTA%^Conjure%^ORANGE%^ strength to dissolve their protections.  %^MAGENTA%^Invoke %^ORANGE%^the depths of the mind to ward against their coming.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" looks a little confused as they remove their "+query_short()+"%^RESET%^%^ORANGE%^.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^All the knowledge seeps from your mind as you remove your "+query_short()+"%^RESET%^%^ORANGE%^.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("fireball_fun","summon");
   add_action("dispel_fun","conjure");
   add_action("scryproof_fun","invoke");

}

int fireball_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the crown.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You should use <summon at target>.");
     return 1;
   }
   if(sscanf(str,"at %s",mytarg) == 1) {
     if(trackera > time()) {
       tell_object(TP,"The crown is still recharging that power.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     trackera = time() + 28800;
     new("/cmds/spells/f/_fireball")->use_spell(TP,present(mytarg,ETP),30,100,"mage");
     return 1;
   }
   tell_object(TP,"You should use <summon at target>.");
   return 1;
}

int dispel_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the crown.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You should use <conjure at target>.");
     return 1;
   }
   if(sscanf(str,"at %s",mytarg) == 1) {
     if(trackerb > time()) {
       tell_object(TP,"The crown is still recharging that power.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     trackerb = time() + 43200;
     new("/cmds/spells/d/_dispel_magic")->use_spell(TP,present(mytarg,ETP),30,100,"mage");
     return 1;
   }
   tell_object(TP,"You should use <conjure at target>.");
   return 1;
}

int scryproof_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the crown.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You should use <invoke at target>.");
     return 1;
   }
   if(sscanf(str,"at %s",mytarg) == 1) {
     if(trackerc > time()) {
       tell_object(TP,"The crown is still recharging that power.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     trackerc = time() + 86400;
     new("/cmds/spells/p/_protection_from_scrying")->use_spell(TP,present(mytarg,ETP),30,100,"mage");
     return 1;
   }
   tell_object(TP,"You should use <invoke at target>.");
   return 1;
}
