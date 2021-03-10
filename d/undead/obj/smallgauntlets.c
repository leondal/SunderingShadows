#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("gauntlets");
    set_id(({"gauntlets","bluish silver gauntlets","silver gauntlets","bluish gauntlets","plated mesh gauntlets","mesh gauntlets","plated gauntlets"}));
    set_short("%^RESET%^P%^BOLD%^%^BLUE%^l%^RESET%^a%^CYAN%^t%^BOLD%^%^BLUE%^e%^RESET%^d M%^BOLD%^%^BLUE%^e%^RESET%^%^CYAN%^s%^RESET%^h G%^BOLD%^%^BLUE%^a%^RESET%^u%^CYAN%^n%^BOLD%^%^BLUE%^t%^RESET%^le%^CYAN%^t%^RESET%^s");
    set_obvious_short("%^BOLD%^%^BLUE%^a set of %^RESET%^b%^BOLD%^%^BLUE%^l%^RESET%^u%^CYAN%^i%^BOLD%^%^BLUE%^s%^RESET%^h s%^BOLD%^%^BLUE%^i%^RESET%^l%^CYAN%^v%^BOLD%^%^BLUE%^e%^RESET%^r %^BOLD%^%^BLUE%^gauntlets%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Tiny diamond shaped links form a lightweight "
"mesh of strong %^RESET%^mithril chain %^CYAN%^under the series of interlocking"
", %^BOLD%^%^BLUE%^titanium plates %^RESET%^%^CYAN%^that make up this pair of "
"gauntlets.  Working together, the mesh catches and counters stabs and jabs, "
"while the plates deflect cutting slices.  A %^RESET%^b%^BOLD%^%^BLUE%^l"
"%^RESET%^u%^CYAN%^i%^BOLD%^%^BLUE%^s%^RESET%^h s%^BOLD%^%^BLUE%^i%^RESET%^l"
"%^CYAN%^v%^BOLD%^%^BLUE%^e%^RESET%^r %^CYAN%^in color, the gauntlets are lined "
"with a soft %^BOLD%^%^BLACK%^black cotton %^RESET%^%^CYAN%^padding to give a "
"bit of added comfort and grip, while the plates are etched in %^RESET%^silver "
"scrollwork %^CYAN%^and riveted with %^BOLD%^%^BLUE%^sapphire studs%^RESET%^"
"%^CYAN%^.%^RESET%^\n");
    set_lore("Anstrong Berkus is credited with creating these mesh and plate "
"gauntlets.  Anstrong served in the dwarven army of Barak Morndin during the "
"mindflayer wars.  Many of his fellow warriors complained that the large, heavy "
"gauntlets they wore were cumbersome and heavy, especially in light of how "
"their enemy favored the stab-and-jab methods of fighting with small, "
"lightweight weapons.  In response to this, Anstrong spent many of his off "
"hours perfecting a gauntlet that combined the protectiveness of the thick "
"plated gauntlets the dwarves were used to, with a finer layer of chain mesh, "
"similar to the breastplate and mesh combinations that many wore to protect "
"their bodies.  The gauntlets proved to be a popular success resulting in "
"Anstrong's promotion off the front lines and into the smithies to create more "
"of his plated mesh gauntlets.");
    set_property("lore difficulty",18);
    set_weight(5);
    set_value(3000);
    set_type("armor");
    set_limbs(({"left arm","right arm"}));
    set_size(1);
    set_ac(1);
    set_property("enchantment",5);
    while (query_property("enchantment") != 5) {
      remove_property("enchantment");
      set_property("enchantment",5);
    }
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}

int wear_func(){
    if((int)TP->query_lowest_level() < 30) {
       tell_object(TP,"You may not wear those yet. Only those who earn them may.");
       return 0;
    }
    if(!TP->is_class("cavalier") && !TP->is_class("paladin") && !TP->is_class("fighter") && !TP->is_class("cleric") && !TP->is_class("antipaladin")) {
      tell_object(ETO,"The magic of the gauntlets refuses to be worn by you.");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^The soft cotton lining makes these "
"gauntlets quite comfortable actually.%^RESET%^");
    return 1;
}

int remove_func(){
    tell_object(ETO,"%^BOLD%^%^BLACK%^You slide the gauntlets off and stretch "
"your fingers a bit.%^RESET%^");
    return 1;
}
