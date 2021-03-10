//Coded by Hades//
#include <std.h>
#include <daemons.h>
inherit OBJECT;
int uses;
void create(){
    ::create();
    set_id(({"wand","iron wand","ice wand"}));
    set_name("ice wand");
    set_short("%^RESET%^A iron %^CYAN%^blue%^RESET%^ wand");
    set_long(
        "%^CYAN%^This is a %^BLUE%^blue%^CYAN%^ iron wand.  "+
		"It is made from %^BLUE%^cold%^RESET%^ iron.%^RESET%^%^CYAN%^  "+
		"It is covered with %^BOLD%^ice%^RESET%^%^CYAN%^ but looks to "+
        "be in decent condition. There is a glass rod "+
		"attached to one end that seems to give off a %^BLUE%^cold aura%^CYAN%^.  "+  
		"It is about a foot long. There is "+
        "a tiny inscription written on a %^BLUE%^stone%^CYAN%^"+
		" near the base that can be %^BLUE%^read."
    );
    set_weight(5);
    set_value(1000);
    uses = 10;
    set("read","This is a wand of ice storm, it has the following functions:\n"
        "storm casts an ice storm in the area(1 charge)\n"+
        uses+" charges left");
}
void init(){
    ::init();
    add_action("storm","storm");
}
void storm(string str){
    object ob;
    if(ETO->query_casting()) return notify_fail("Already casting.");
    if(!query_wielded()) return notify_fail("Wield it first?\n");
    if(uses < 0) return notify_fail("The wand is out of charges.\n");
    if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",TP);
       return 1;
    }

    if(str) return notify_fail("just <storm> the area\n");
//    if(!(ob = present(str, ETP))) return notify_fail("That isn't here!\n");
//    if(!ETO->is_class("mage") && !ETO->is_class("bard")) -> bards are no longer arcane spellcasters
    if(!ETO->is_class("mage")) 
      return notify_fail("Only arcane spellcasters can use this wand.\n");
    if(ETO->is_class("mage"))
      new("/cmds/spells/i/_ice_storm")->use_spell(ETO,0,ETO->query_guild_level("mage"),100,"mage");
//    else if(ETO->is_class("bard")) new("/cmds/spells/i/_ice_storm")->use_spell(ETO,ob,ETO->query_guild_level("bard"));
    uses -= 1;
    delete("read");
    set("read","This is a wand of ice storm, it has the following functions:\n"
        "storm casts an ice storm in the area (1 charge)\n"+
        uses+" charges left");
    return 1;
}
