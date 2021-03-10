#include <std.h>
#include <daemons.h>
inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() 
{
    object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^MAGENTA%^T%^RESET%^%^MAGENTA%^he %^BOLD%^V%^RESET%^%^MAGENTA%^erre %^BOLD%^B%^RESET%^%^MAGENTA%^ar%^WHITE%^");
    set_long("%^BOLD%^%^MAGENTA%^T%^RESET%^%^MAGENTA%^he %^BOLD%^V%^RESET%^%^MAGENTA%^erre %^BOLD%^B%^RESET%^%^MAGENTA%^ar%^WHITE%^
%^GREEN%^This establishment has been decorated and modified over the past few years. There are several oak tables set up around the room along with a matching %^ORANGE%^bar%^GREEN%^. It has grown into a bar where both food and drink can be served and as the only one located in the town of verbobone and the safe part of the island, it brings in quite a bit of profit for the town. A %^ORANGE%^menu%^GREEN%^, showing the drinks and foods has been attached to the front of the bar. A small, dark %^ORANGE%^oak board%^GREEN%^ has been hung on the wall to the right of the doorway into the establishment. Another, lighter colored and thicker, %^ORANGE%^board%^GREEN%^ has been hung near the back of the establishment, serving as a dart board for the patrons of the bar."
        );
  
  
    set_smell("default","You smell the odor of beer and sweat.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items(
    (["pub" : "The Verre Pub.",
    "bar" : "The Verre Bar.",
    "menu" : "This is a list of foods and drinks served by the "+
    "verre bar.  You should %^BOLD%^<read menu>%^RESET%^.",
    "oak board" : "%^GREEN%^This board is a couple inches thick and "+
    "has written carved into the front of it.  It appears to be "+
    "some type of list.  You should probably read it.%^RESET%^",
    ]) );

    set_exits( ([ "south" : "/d/deku/town/road6" ]) );;
    if(!present("barkeep")) new("/d/deku/monster/barkeep")->move(TO);
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("verre_bar");
        ob->move(TO);
    }
}

void reset() {
    object ob;
  ::reset();
    if(!present("barkeep")) new("/d/deku/monster/barkeep")->move(TO);
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("verre_bar");
        ob->move(TO);
    }
    if((ob = present("kyanus galanodel")) && (string)EVENTS_D->query_time_of_day() == "night") {
        ob->force_me("say time for me to go home.");
        ob->force_me("south");
        ob->force_me("west");
        ob->remove();
        tell_room(TO,"%^RED%^Another barkeep, this one a burly "+
        "and scarred male enters the room quickly, a "+
        "sour look upon his face.%^RESET%^");
         new("/d/deku/monster/barkeep")->move(TO);
        return;
    }
    if((ob = present("durga daarlay")) && (string)EVENTS_D->query_time_of_day() != "night") {
        ob->force_me("say me go now");
        ob->force_me("south");
        ob->force_me("east");
        ob->remove();
        tell_room(TO,"%^RED%^Another barkeep, this one a young male "+
        "half-elf hurries into the bar to take over.%^RESET%^");
        new("/d/deku/monster/barkeep")->move(TO);
        return;
    }
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn, *names;
    int length, x;

    ob = present("barkeep");
    if(!ob && str == "menu") {
        write("The barkeep isn't here right now, there's no one to serve you.");
	    return 1;
    }
    if(str == "carving" || str == "sign" || str == "board" 
    || str == "oak board" && ob = present("dartboard")) {
        write("This is a list of those who are recognized by %^RED%^The "+
        "Verre Bar%^RESET%^ as being masters at the game of darts.");
        names = ob->query_mastery_list();
        if(!sizeof(names)) {
            tell_object(TP,"No names have been engraved....");
            return 1;
        }
        for(x = 0;x < sizeof(names);x++) {
            tell_object(TP,"["+(x+1)+"] %^RED%^"+names[x]+"%^RESET%^\n");
        }
        return 1;
    }
            
    if(str == "menu") {
        menu_item = ob->query_menu();
        length = sizeof(menu_item);
        message("Ninfo", "%^BOLD%^%^BLUE%^This is a menu of the food and drink sold at the Verre Bar.\n", TP);
        message("Ninfo", "%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
        while(length--){
            melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^BOLD%%^%%^WHITE%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	        write(melnmarn);
        }
        message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
        message("Ninfo", "%^RESET%^<buy menu_name> will get you that item.\n", TP);

        return 1;
    }
}
