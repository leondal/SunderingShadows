//updated by Circe 8/4/19 to current code
#include <std.h>
#include <daemons.h>
#define WAIT_TIME 14400

inherit "/d/common/obj/armour/bracers";
int used_time, modifier;

void create(){
    ::create();
    set_name("%^RESET%^%^RED%^I%^BOLD%^r%^RESET%^%^ORANGE%^i%^YELLOW%^d%^GREEN%^e%^RESET%^%^GREEN%^s%^CYAN%^c%^BOLD%^e%^BLUE%^n%^RESET%^%^BLUE%^t %^MAGENTA%^B%^BOLD%^r%^RESET%^%^RED%^a%^BOLD%^c%^RESET%^%^ORANGE%^e%^YELLOW%^r%^GREEN%^s%^RESET%^");
    set_id(({ "bracers", "bracer", "iridescent bracers","iridescent bracer","crystal bracer","crystal bracers"}));
    set_short("%^RESET%^%^RED%^I%^BOLD%^r%^RESET%^%^ORANGE%^i%^YELLOW%^d%^GREEN%^e%^RESET%^%^GREEN%^s%^CYAN%^c%^BOLD%^e%^BLUE%^n%^RESET%^%^BLUE%^t %^MAGENTA%^B%^BOLD%^r%^RESET%^%^RED%^a%^BOLD%^c%^RESET%^%^ORANGE%^e%^YELLOW%^r%^GREEN%^s%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A pair of %^RESET%^%^RED%^i%^BOLD%^r%^RESET%^%^ORANGE%^i%^YELLOW%^d%^GREEN%^e%^RESET%^%^GREEN%^s%^CYAN%^c%^BLUE%^e%^RESET%^%^MAGENTA%^n%^BOLD%^t%^WHITE%^ crystal bracers%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Twin looping spirals crafted from %^CYAN%^crystal%^WHITE%^ make up the body of these bracers.  The winding spirals are made in a fashion where they encircle each forearm four times before tapering off to blunt ends.  The inside of the bracers are %^MAGENTA%^polished%^WHITE%^ smooth for comfort. Multiple %^YELLOW%^facets%^WHITE%^ have been cut into the spirals, causing the %^CYAN%^crystals%^WHITE%^ to catch the light and create %^RESET%^%^RED%^i%^BOLD%^r%^RESET%^%^ORANGE%^i%^YELLOW%^d%^GREEN%^e%^RESET%^%^GREEN%^s%^CYAN%^c%^BLUE%^e%^MAGENTA%^n%^BOLD%^t%^WHITE%^ bands of color.  Some of the facets even serve as prisms, creating bands of %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^CYAN%^m%^BLUE%^a%^BOLD%^t%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ colors to fall all around.  There is a delicate grace to these wondrous bracers.%^RESET%^\n");
    set_lore("Little is known about these mysterious bracers.  Their craftsmanship might suggest elven, but there is a strange alien nature to the bracers that suggests otherwise.  Some speculate that the bracers might be the work of the githyanki, yellow-skinned natives of the astral plane, or githzerai, the mortal enemies of the githyanki.  It is said that the githyanki and githzerai are able to achieve with their minds feats that would leave a wizard in shock.  The bracers seem to demonstrate some faint psionic powers, an ability to animate crystals for protection.  To animate the crystals, one must simply %^BOLD%^%^CYAN%^summon crystals%^RESET%^, and they will come.  This power is exhausting to the bracers and requires time to recharge before it can be used again.");
    set_property("lore",14);
    set_value(7000);
    set_property("enchantment",3);
    set_item_bonus("sight bonus",5);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}

void init(){
    ::init();
    if(living(ETO)) {
        add_action("make_em","summon");
    }
}

int make_em(string str){
	if (ETO->query_bound() || EETO->query_unconscious() || EETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
        return 0;
    }
    if(!str) return notify_fail("Summon what?\n");
    if(!TO->query_worn()) return notify_fail("The bracers fail to respond.\n");
    if(WAIT_TIME > (time() - used_time)) return notify_fail("The bracers fail to respond.\n");
    if(str == "crystal" || str == "crystals"){
        used_time = time();
        ETO->force_me("emote focuses on "+ETO->QP+" bracers with an intense concentration.");
       new("/cmds/spells/c/_call_crystals.c")->use_spell(ETO,0,20,100,"psion");
	  return 1;
    }
    return notify_fail("The bracers fail to respond.\n");
}

int wear_func(){
    if(::check() != 1) {
        return 0;
    }
     if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
    if((int)ETO->query_lowest_level() < 20) {
        write("The magic of the bracers refuses you!");
        return 0;
    }
    if(!ETO->query_invis()) {        
        tell_room(EETO,"%^BOLD%^"+ETOQCN+" loops the crystal bracers"+
		" around "+ETO->QP+" forearms.\nBands of %^RED%^c%^RESET%^"+
		"%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^BLUE%^r%^WHITE%^ dance about "+ETOQCN+".",ETO);
    }
	tell_object(ETO,"%^BOLD%^You loop the bracers around your forearms,"+
		" feeling the smoothness of the crystal against your skin."+
		"\nBands of %^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o"+
		"%^BLUE%^r%^WHITE%^ dance about you.",EETO);
    return 1;
}

int remove_func(){
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^BOLD%^"+ETOQCN+" twists the crystal bracers off"+
		" of "+ETO->QP+" forearms.",ETO);
    }
        
    tell_object(ETO,"%^BOLD%^You start to twist the bracers off of your arms.%^RESET%^",EETO);
	return 1;
}

void set_used_time(int x) {
    used_time = x;
}
