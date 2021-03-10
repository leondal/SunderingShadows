//Coded by Bane//
#include <std.h>
#include <daemons.h>
#define MAXUSE 30
inherit OBJECT;
int uses;
void create(){
    ::create();
    set_id(({"wand","ivory wand","wand of conjuration"}));
    set_name("wand of conjuration");
    set_short("An ivory wand");
    set_long(
	"This is a splintered ivory wand.  It is polished very nicely "+
	"and is about a foot long.  There is an inscription on it."
    );
    set_weight(5);
    set_value(11000);
    set_read("This is a wand of conjuration, it has the following functions:\n"
"spray <name>: casts prismatic spray at a target(7 charges)\n"
"conjure <1|2|3|4|5|6>: casts the appropriate monster summoning spell(1 charge per level)");
    uses = 0;
}
void init(){
    ::init();
    add_action("spray","spray");
    add_action("conjure","conjure");
}

void spray(string str){
    object ob;
       if (ETO->query_bound() || ETO->query_unconscious()
       || ETO->query_paralyzed()) {
       ETO->send_paralyzed_message("info",ETO);
       return 1;
    }
   if(!query_wielded()) return notify_fail("Wield it first?\n");

    if(uses > MAXUSE) return notify_fail("The wand is out of charges.\n"); 
    if(!str) return notify_fail("Spray who?\n");
    if(!(ob = present(str, EETO))) return notify_fail("That isn't here!\n");
    if(!ETO->is_class("mage")) return notify_fail("Only mages can do that.\n");
    new("/cmds/spells/p/_prismatic_spray")->use_spell(ETO,ob,14,100,"mage");
    uses += 7;
    ETO->set_paralyzed(2,"%^MAGENTA%^You are using the wand!"+
    "%^RESET%^");
    return 1;
}
void conjure(string str){
    if (ETO->query_bound() || ETO->query_unconscious()
    || ETO->query_paralyzed()) {
       ETO->send_paralyzed_message("info",ETO);
       return 1;
    }
   if(!query_wielded()) return notify_fail("Wield it first?\n");

   if(!ETO->is_class("mage") && !ETO->is_class("bard")) return notify_fail("Only mages can use that.\n");
    if(uses > MAXUSE) return notify_fail("The wand is out of charges.\n"); 
    if(!str) return notify_fail("Conjure what type?\n");
    switch(str){
	case "1":
	    new("/cmds/spells/m/_monster_summoning_i")->use_spell(ETO,ETO,12,100,"mage");
	    uses += 1;
	    break;
	case "2":
	    new("/cmds/spells/m/_monster_summoning_ii")->use_spell(ETO,ETO,12,100,"mage");
	    uses += 2;
	    break;
	case "3":
	    new("/cmds/spells/m/_monster_summoning_iii")->use_spell(ETO,ETO,12,100,"mage");
	    uses += 3;
	    break;
	case "4":
	    new("/cmds/spells/m/_monster_summoning_iv")->use_spell(ETO,ETO,12,100,"mage");
	    uses += 4;
	    break;
	case "5":
	    new("/cmds/spells/m/_monster_summoning_v")->use_spell(ETO,ETO,12,100,"mage");
	    uses += 5;
	    break;
	case "6":
	    new("/cmds/spells/m/_monster_summoning_vi")->use_spell(ETO,ETO,12,100,"mage");
	    uses += 6;
	    break;
    }
    ETO->set_paralyzed(2,"%^MAGENTA%^You are using the wand!%^RESET%^");
    return 1;
}
