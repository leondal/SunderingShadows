#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit ROOM;

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_climate("desert");
    set_name("Eastern oasis barracks");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis barracks%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are %^BOLD%^beds%^RESET%^"+
    "%^ORANGE%^ lined up through out the tent. At the foot of each bed is a %^BOLD%^container%^RESET%^%^ORANGE%^. "+
    "There is no visible means of opening any of the containers. You notice that on top of each there seems to be a "+
    "%^BOLD%^palm print%^RESET%^%^ORANGE%^. Each of the beds is always well made and in perfect order and you are "+
    "not sure if anyone actually ever sleeps in them or if this tent is simply for show. You get some strange feeling "+
    "about this place when looking over them, as if something is not right, though you cannot explain it. "+
    "It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent, surprisingly none have been broken or if they have been, they were "+
    "replaced. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nBody odor hangs heavily in the air here, mixing with the smell of strong ale, and "+
    "burnt food.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^There are beds lined up throughout this tent. At the foot of "+
        "each is a container with no visible means of opening it. There is, however, a palm print on the top and in "+
        "the center of each.%^RESET%^",
                   
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. Surprisingly none of them have been broken or if they have been "+
        "they were replaced. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"beds"}) : "%^BOLD%^%^YELLOW%^These beds are lined up throughout the entire tent. They are always well made and in "+
        "perfect order. You are not sure if anyone actually ever sleeps in them or if this tent is simply for show. "+
        "You get a strange feeling as you look over them. You don't exactly understand it but you get the sense that "+
        "something isn't right about this place.%^RESET%^",
        
        ({"containers", "container"}) : "%^RESET%^%^ORANGE%^These containers are at the foot of each bed. There is no visible means of "+
        "opening any of them. On top and in the center of each there is a palm print. You have no way of knowing what is contained "+
        "within any of them.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"3"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();

}

void init() 
{
    ::init();
    add_action("read", "read");
}


int read(string str) 
{
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
