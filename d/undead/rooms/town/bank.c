#include "../../undead.h"
inherit BANK;

void create()  {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_name("The Bank of Graez");
    set_short("%^BOLD%^%^WHITE%^The Bank of Graez%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The Bank of Graez%^RESET%^\n"
"Perhaps one of the most %^CYAN%^quiet %^RESET%^banks you have been in, very "
"few people come through here.  Burly guards glare at each person that enters, "
"causing several customers to look noticeably nervous.  The occasional "
"%^YELLOW%^clink %^RESET%^of coins can be heard as someone offers a bag of "
"money to be deposited here, or furtively stashes their withdrawal into their "
"pockets before leaving.\n");
    set_smell("default","The fresh scent of the ocean drifts through the ruined city.");
    set_listen("default","You hear the sounds of battle in the distance.");

    set_items(([
        "sign":"Reading it will give you a list of commands.",
    ]));
    set_exits(([ 
        "west":TOWN"street16"
    ]));
}

string getBankId(){ return "graez";}
