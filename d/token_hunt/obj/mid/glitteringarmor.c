#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";

void create(){
        ::create();
        set_name("sheet of ice");
        set_id(({ "armor", "breast plate", "breastplate", "glittering carapace",
"carapace", "sheet", "ice sheet" }));
        set_short("%^BOLD%^%^CYAN%^G%^WHITE%^l%^BLUE%^i%^CYAN%^tte%^WHITE%^r%^BLUE%^i%^CYAN%^ng C%^WHITE%^a%^BLUE%^r%^CYAN%^ap%^WHITE%^a%^BLUE%^c%^CYAN%^e%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^a sheet of ice%^RESET%^");
        set_long("%^BOLD%^%^CYAN%^At first look, this sheet of ice appears "+
           "to be a misshapen giant's bowl.  Small spikes, rimmed in frost, "+
           "adorn one side, providing a means to keep the bowl upright, "+
           "while the inside is smooth and polished to a %^WHITE%^g%^CYAN%^l"+
           "%^BLUE%^i%^WHITE%^tte%^CYAN%^r%^BLUE%^i%^WHITE%^ng %^CYAN%^"+
           "sheen.  Around the edge, peculiar %^BLACK%^d%^WHITE%^i%^BLACK%^"+
           "vo%^RESET%^t%^BOLD%^%^BLACK%^s %^CYAN%^mar the half-oval shaped "+
           "rim, their indentations as smooth as the interior.  On closer "+
           "inspection, you realize that this is actually a breastplate "+
           "fashioned from %^WHITE%^i%^CYAN%^c%^WHITE%^e%^CYAN%^.  The divots"+
       " are where the arms and head go, while the half-oval design "+
           "allows it to fit comfortably over the body.  Providing you can "+
           "find a way to protect yourself from the cold, that is.%^RESET%^");
   set_value(0);
        set_lore("The Gelugon, sometimes called ice devils, are fierce and "+
           "horrible warriors feared by many.  Their weapons and armor are "+
           "made of such cold ice that any contact with them can result in "+
           "near fatal frostbite or worse.  Despite this, some are brave "+
           "enough to fight such creatures, slaughtering them wherever "+
           "they're found.  Such adventurers often report back that when "+
           "the Gelugon's have melted, that their armor and weapons are "+
           "left behind.  Bringing sheets of curved ice and spears of pure "+
           "ice back as proof of their success.  A few researchers have "+
           "suggested that these armors and weapons are in fact the "+
           "exoskeletons of the creatures due to their horrific appearance.");
        set_property("lore difficulty",20);
        set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("damage resistance",1);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set_struck((:TO,"strike_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_func(){
        tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" begins to shiver "+
          "uncontrollably.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^BLUE%^You will the frost to expand and form a lattice "+
		  "work of straps across your back, even as you begin to shiver uncontrollably"+
		  " from the nearness of so much ice.%^RESET%^");
        return 1;
}

int remove_func(){
        tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" looks incredibly cold.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^BLUE%^Nearly frozen through and through, you"+
		" will the frost to unbuckle and pull the ice sheet away, exposing patches "+
		"of frostbite here and there.%^RESET%^");
        return 1;
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 200){
        tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+who->QCN+" staggers "+
		"back as a spray of ice and frost from "+ETOQCN+"'s armor showers them in"+
        " cold!%^RESET%^",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLUE%^A spray of freezing cold frost flies up"+
		" into "+who->QCN+"'s face as their weapon makes contact.  Their scream alerts "+
		"you to just how cold a blast it must have been!%^RESET%^");
        tell_object(who,"%^BOLD%^%^BLUE%^Your blow lands upon "+ETOQCN+" causing ice "+
		"crystals from their armor to explode outward and freeze to your exposed skin."+
		"  The chill is mindnumbing!%^RESET%^");
       who->set_paralyzed(roll_dice(2,3));
return damage;  }
}

int is_metal() { return 0; } // for druids
