#include <std.h>
inherit ROOM;

void create(){
    room::create();
         set_property("indoors",0);
         set_property("light",2);
         set_short("The Cursed Land's entrance.");
         set_long(
@STOP
You embarked into a realm which is unlike any others.
Prepare yourself as you enter the %^RED%^%^BOLD%^CURSED LANDS!!!%^RESET%^
You notice a %^CYAN%^sign%^RESET%^ here.      

STOP
);



         set_smell("default","You smell %^RED%^death%^RESET%^ "+
                   "%^YELLOW%^%^BOLD%^all around you.\n");
         set_listen("default","You hear whispers of a single word"+
         " whispered over and over again...\n"+
         "      %^BOLD%^%^RED%^Tarrasque... %^BOLD%^%^CYAN%^Tarrasque..."+
         " %^BOLD%^%^GREEN%^ Tarrasque...%^RESET%^");
         set_items(([
                "sign":"%^BOLD%^%^CYAN%^Welcome to the Cursed Lands!\n"+
                "This area is full of varius types of creatures"+
                " and items.\n"+
                "But be warned... many of the creatures"+
                " you will encounter are unique, and unlike any others"+
                " that you have encountered as of now...\n"+
                "May you have a prosperous journey and GOOD LUCK! :)\n\n"+
                "     %^RED%^%^BOLD%^-Apocalypse%^RESET%^",
                ]));
         set_exits((["north":"/d/cursed/cursed1.c"]));

}

