#include "../../undead.h"

inherit VAULT;

void create() 
{
    ::create();

    set_name("A battlefield");
    set_terrain(BARREN);
    set_travel(RUTTED_TRACK);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^BOLD%^%^RED%^You are in the middle of a Battle Field%^RESET%^");
    
    set_long("%^BOLD%^%^RED%^You are in the middle of a Battle Field.%^RESET%^\n"
        "%^RED%^All around you bodies lay strewen as if they were dolls, "  
        "tossed aside by an angry god. Pieces of flesh litter the landscape "
        "for as far as you can see. Faces of noble warriors fallen in battle "
        "stare at you with bloodshot eyes and terrifying expressions. This "
        "sight probably brings Kartakass great pleasure, but it just makes "
        "you sick to your stomach.  You are now between two archer towers and "
        "you see the gates to the city of Graez to your west. The guards call "
        "to you to hurry through the gates before you get hurt.  You are now "
        "between two archer towers and you see the gates to the city of Graez "
        "to your west. The guards call to you to hurry through the gates before "
        "you get hurt.");

    set_exits(([
        "gate"      :TOWN+"street8",
        "east"      :BF+"room9"
            ]));


    set_smell("default","You are made sick by the stench of death.");
    set_listen("default","You hear the sounds of war being waged.");

    set_door("gate",TOWN+"street8","gate","open_gate");
    set_open("gate",0);
    set_string("gate","open", "The massive gate creeks on its hinges as it opens!");
    set_door_description("gate","These towering gates are fashioned from felled "
        "oak trees from the ancient Peth Forest.  They are held together with "
        "thick steel bands and heavy rivets.  Each door must weight close to a "
        "thousand pounds and is large enough for two wagons to pass through side "
        "by side.");

}
