// Chernobog (9/6/21)
// Tharis Hotel

#include "../defs.h"
inherit "/std/vendor.c";

void create() {
    ::create();
    set_name("Natalie");
    set_id(({"natalie","waitress","Natalie"}));
    set_short("%^BOLD%^%^MAGENTA%^Natalie%^RESET%^, %^MAGENTA%^a %^ORANGE%^cigar girl %^MAGENTA%^for %^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^V%^BOLD%^iole%^RESET%^%^MAGENTA%^t's %^BOLD%^%^BLACK%^Lounge%^RESET%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^She is a small, %^BOLD%^%^BLUE%^sa%^RESET%^%^CYAN%^p%^BOLD%^p%^RESET%^%^BLUE%^h%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e%^RESET%^-%^BOLD%^%^BLUE%^e%^RESET%^%^CYAN%^y%^BOLD%^e%^BLUE%^d %^RESET%^woman with %^BOLD%^%^BLACK%^ch%^RESET%^a%^BOLD%^%^BLACK%^rc%^RESET%^o%^BOLD%^%^BLACK%^al-gr%^RESET%^a%^BOLD%^%^BLACK%^y sk%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^, wrapped in a close-fitting %^MAGENTA%^violet brocade silk dress %^WHITE%^that falls just to her knees. Her %^BOLD%^p%^RESET%^a%^BOLD%^le bl%^RESET%^o%^BOLD%^nde h%^RESET%^a%^BOLD%^ir %^RESET%^falls in soft %^BOLD%^wa%^RESET%^v%^BOLD%^es %^RESET%^just to her shoulders, except for the right temple, which has been %^BOLD%^shorn %^RESET%^short. Carrying a %^BOLD%^gleaming %^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er t%^RESET%^r%^BOLD%^a%^BLACK%^y%^RESET%^, she can be seen making her way between the various customers, selling %^ORANGE%^cigars%^WHITE%^. She herself is always surrounded by a %^BOLD%^%^BLACK%^sm%^RESET%^o%^BOLD%^%^BLACK%^ky %^RESET%^scent.%^RESET%^");
    set_gender("female");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_items_allowed("tobacco");
    set_storage_room(STOR+ "natalie_storage");
}

