//Restaurant -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"indoors";

void create(){
    ::create();
    set_long((:TO,"long_desc":));
    set_smell("default",
        "The scent of baked goods overpower those of the forest."
    );
    set_listen("default",
        "It is suprisingly quiet as many of the elves come and go for "
        "provisions."
    );
    add_item(
        ({"barrels","crates"}),
            "%^BOLD%^%^BLACK%^These barrels and %^RESET%^%^RED%^crates%^BOLD%^%^BLACK%^ are filled with %^CYAN%^flour%^BLACK%^, %^WHITE%^sugar%^BLACK%^, "
            "%^YELLOW%^yeast%^BLACK%^, %^RED%^fruits%^BLACK%^, and other %^GREEN%^goods%^BLACK%^ used for baking that are "
            "being issued to the %^RESET%^%^MAGENTA%^elven%^BOLD%^%^BLACK%^ refugees.%^RESET%^"
    );
    add_item(
        ({"wall","shelves","foodstuffs"}),
            "%^ORANGE%^These shelves are made from the same %^RESET%^gray wood%^ORANGE%^ as the "
            "%^CYAN%^windscreens%^ORANGE%^ and %^BOLD%^%^BLACK%^hook%^RESET%^%^ORANGE%^ on to the top of them and hang down. "
            "They are packed full of %^BLUE%^foodstuffs%^ORANGE%^ and cover most of "
            "the %^CYAN%^wall%^ORANGE%^ space rendering the see through aspect of the "
            "%^CYAN%^windscreens%^ORANGE%^ here virtually useless.%^RESET%^"
    );
    add_item(
        ({"tables","counters"}),
            "%^ORANGE%^A few %^RESET%^gray wooden tables%^ORANGE%^ are here and make the room quite "
            "%^RED%^crowded%^ORANGE%^. Some of them have been set up as %^GREEN%^counters%^ORANGE%^ for "
            "baked goods to cool, and the others as places to eat.%^RESET%^"
    );
    add_item(
        "menu",
            "%^ORANGE%^A list of all the food and drink the chef is willing to "
            "sell to outsiders. You should try %^BOLD%^%^WHITE%^reading%^RESET%^%^ORANGE%^ it.%^RESET%^"
    );
    set_exits(([
        "east" : PATH+"platform23",
    ]));
}

string long_desc(){
    return get_base_desc()
        +"A plethora of %^BOLD%^%^BLACK%^barrels%^RESET%^%^ORANGE%^ and %^RED%^crates%^ORANGE%^ fill the edges of this room "
        "and the contents are being issued to the %^MAGENTA%^elven%^ORANGE%^ refugees as they "
        "come and go. Nearly every inch of the %^CYAN%^wall%^ORANGE%^ space is covered in "
        "shelves that are packed full of %^BLUE%^foodstuffs%^ORANGE%^. A few %^RESET%^gray wooden "
        "tables%^ORANGE%^ have been set up, some for use as %^GREEN%^counters%^ORANGE%^, and the "
        "others as a place to eat. "
        "\nThere is a menu here that you can %^BOLD%^%^WHITE%^read%^RESET%^%^ORANGE%^.%^RESET%^\n";
}

void init(){
    ::init();
    add_action("read","read");
}

void reset(){
    ::reset();
    if(!present("chef")) {
        new(MON+"chef.c")->move(TO);
    }
}

int read(string str){
    object ob = present("chef");
    int i;
    if(str == "menu"){
        if(!ob){
            write("The cook is not here at the moment.");
            return 1;
        }
        say(""+TPQCN+" reads over the menu.");
        write("  The following foods and drinks are available here.");
        write("  %^BOLD%^%^RED%^~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~%^RESET%^");
        write("                         %^BOLD%^%^BLUE%^Food%^RESET%^\n");
        write("\t%^MAGENTA%^Elven Waybread%^RESET%^                  "+
            ""+(int)ob->get_price("elven waybread") + " gold");
        write("\t%^ORANGE%^Fried Dula%^RESET%^                      "+
            ""+(int)ob->get_price("fried dula") + " gold");
        write("\t%^BOLD%^%^BLACK%^Corence and Mushroom Soup%^RESET%^       "+
            ""+(int)ob->get_price("corence and mushroom soup") + " gold");
        write("\t%^BOLD%^%^WHITE%^Voratae Bisque%^RESET%^                  "+
            ""+(int)ob->get_price("voratae bisque") + " gold\n");
        write("  %^BOLD%^%^RED%^~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~%^RESET%^");
        write("                       %^BOLD%^%^BLUE%^Desserts%^RESET%^\n");
        write("\t%^MAGENTA%^Wild Berry Pie%^RESET%^                  "+
            ""+(int)ob->get_price("wild berry pie") + " gold");
        write("\t%^BOLD%^%^BLUE%^Fruit Salad%^RESET%^                     "+
            ""+(int)ob->get_price("fruit salad") + " gold\n");
        write("  %^BOLD%^%^RED%^~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~%^RESET%^");
        write("                       %^BOLD%^%^BLUE%^Beverages%^RESET%^\n");
        write("\t%^BOLD%^%^CYAN%^Forest Water%^RESET%^                    "+
            ""+(int)ob->get_price("forest water") + " gold");
        write("\t%^ORANGE%^Iced Tea%^RESET%^                        "+
            ""+(int)ob->get_price("iced tea") + " gold");
        write("\t%^YELLOW%^Fresh Lemonade%^RESET%^                  "+
            ""+(int)ob->get_price("fresh lemonade") + " gold");
        write("\t%^GREEN%^Herbal Tea%^RESET%^                      "+
            ""+(int)ob->get_price("herbal tea") + " gold\n");
        write("  %^BOLD%^%^RED%^~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~%^RESET%^");
        write("                         %^BOLD%^%^BLUE%^Wines%^RESET%^\n");
        write("\t%^BOLD%^%^RED%^Feywine%^RESET%^                         "+
            ""+(int)ob->get_price("feywine") + " gold");
        write("\t%^RED%^Elverquisst%^RESET%^                     "+
            ""+(int)ob->get_price("elverquisst") + " gold\n");
        write("  %^BOLD%^%^RED%^~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~%^RESET%^");
        write("  <buy dish_name> will get you the food or drink.");
        return 1;
    }
    return 0;
}


