// Chernobog (6/8/21)
// Cigarette Case

#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create(){
    ::create();
    set_id(({"cigarette case","case"}));
    set_name("cigarette case");
    set_short("%^RESET%^%^MAGENTA%^A %^WHITE%^s%^BOLD%^m%^RESET%^a%^BOLD%^l%^RESET%^l %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^c%^BOLD%^a%^RESET%^s%^BOLD%^e%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^This %^WHITE%^s%^BOLD%^m%^RESET%^a%^BOLD%^l%^RESET%^l c%^BOLD%^a%^RESET%^s%^BOLD%^e %^RESET%^%^MAGENTA%^is shaped from %^WHITE%^l%^BOLD%^um%^RESET%^i%^BOLD%^n%^RESET%^o%^BOLD%^us %^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^, the polished surface displaying fine %^BOLD%^%^BLACK%^etchings %^RESET%^%^MAGENTA%^of vines and blooming roses along its periphery. A simple catch snaps the case open for the retrieval or storage of slender cigarettes.%^RESET%^");
    set_weight(2);
    set_value(5000);
    set_cointype("gold");
    set_max_internal_encumbrance(10);
    set_property("repairtype",({ "jeweller" }));
}

int item_allowed(object item){
    if(!item->is_cigarette()){
        write("This case is only meant for cigarettes.");
        return 0;
    }
    if(sizeof(all_inventory(TO)) > 10){
        write("The case is already full.");
        return 0;
    }
    return 1;
}

