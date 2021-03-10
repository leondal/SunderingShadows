#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("beret");
    set_id(({"beret","cream beret","hawk beret","beret of the emerald hawks","cream colored beret"}));
    set_short("%^RESET%^%^ORANGE%^Beret %^RESET%^of the %^BOLD%^%^GREEN%^E%^RESET%^m%^BOLD%^%^BLACK%^e%^GREEN%^ra%^RESET%^l%^BOLD%^%^GREEN%^d H%^RESET%^a%^BOLD%^%^BLACK%^w%^GREEN%^ks%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^a %^RESET%^cream %^ORANGE%^colored beret%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A wide oval of %^RESET%^cream felt %^ORANGE%^"
"has been pressed and formed into the shape of this small beret.  Trimmed with "
"a ribbon of %^GREEN%^green silk %^ORANGE%^to keep it tight upon the head, a "
"small inner tie allows for minor adjustment of fit.  An embroidered badge of "
"stiffened felt is sewn to left side of the cap, causing the majority of the "
"material to flop to the right.  The badge is sewn in the style of a %^RESET%^"
"fisted gauntlet %^ORANGE%^holding a brace of %^GREEN%^green arrows"
"%^ORANGE%^.%^RESET%^\n");
    set_lore("The mountaineers of Delshen Hold were known for their crisp, "
"uniform style of dress and their skill at maneuvering through the wilds of "
"their mountainous homelands.  Dressed in cream and green, their favorite "
"tactic was to lay in wait above the pass till their enemy crossed through and "
"then fire down hundreds of green fletched arrows.  Because of this they were "
"often referred to as the emerald hawks.");
    set_property("lore difficulty",18);
    set_weight(2);
    set_value(500);
    set_type("clothing");
    set_limbs(({"head"}));
    set_size(1);
    set_property("enchantment",2);
    while (query_property("enchantment") != 2) {
      remove_property("enchantment");
      set_property("enchantment",2);
    }
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_heart_beat(1);
}

int wear_func(){
    object *armor;
    int i,FLAG;
    FLAG = 0;
    if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"The hat sits all wrong, and then falls off.");
      return 0;
    }
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+" sets "+ETO->QP+" beret atop "
+ETO->QP+" head and gives a crisp salute!%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^GREEN%^You slide the beret on and cinch the tie "
"tight, nothing will keep you from your mission!%^RESET%^");
    return 1;
}

int remove_func(){
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+" rolls up "+ETO->QP+" beret and "
"puts it away.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^GREEN%^You slip the beret from your head and "
"roll it up before putting it away.%^RESET%^");
    return 1;
}