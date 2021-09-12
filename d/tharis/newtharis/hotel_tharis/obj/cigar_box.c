// Chernobog (6/8/21)
// Cigar Case/Humidor

#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create(){
    ::create();
    set_id(({"cigar box","box","humidor"}));
    set_name("cigar box");
    set_short("%^RESET%^%^MAGENTA%^A %^YELLOW%^s%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^all %^RESET%^w%^ORANGE%^o%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^d%^WHITE%^e%^BOLD%^%^BLACK%^n b%^RESET%^%^ORANGE%^o%^BOLD%^x%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^Fashioned from thin %^ORANGE%^wooden %^MAGENTA%^layers, this small box opens on a %^BOLD%^%^BLACK%^cloth %^RESET%^%^MAGENTA%^hinge in order to store a selection of cigars. The wood is %^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^a%^WHITE%^r%^BOLD%^%^BLACK%^k e%^RESET%^%^ORANGE%^b%^WHITE%^o%^ORANGE%^n%^BOLD%^%^BLACK%^y %^RESET%^%^MAGENTA%^accompanied by %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^RESET%^%^ORANGE%^d s%^BOLD%^c%^WHITE%^r%^RESET%^%^ORANGE%^ol%^BOLD%^l%^WHITE%^w%^ORANGE%^o%^RESET%^%^ORANGE%^r%^BOLD%^k %^RESET%^%^MAGENTA%^along the edges, typical of Tonovi decor. The underside of the lid is ringed by softly glowing script, a passive enchantment to keep its contents %^RED%^humid %^MAGENTA%^and %^CYAN%^f%^GREEN%^r%^CYAN%^e%^GREEN%^s%^CYAN%^h%^MAGENTA%^.%^RESET%^");
    set_weight(2);
    set_value(5000);
    set_cointype("gold");
    set_max_internal_encumbrance(10);
    set_property("repairtype",({ "woodwork" }));
}

int item_allowed(object item){
    if(!item->is_cigar()){
        write("This box is only meant for cigars.");
        return 0;
    }
    if(sizeof(all_inventory(TO)) > 10){
        write("The box is already full.");
        return 0;
    }
    return 1;
}

