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
    set_name("Eastern oasis watering hole");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis watering hole%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are numerous %^BOLD%^tables%^RESET%^"+
    "%^ORANGE%^ which line the walls of it. Near each table there are four large %^BOLD%^%^MAGENTA%^plush%^RESET%^%^ORANGE%^"+
    " chairs. They all look quite worn, as if they have seen lots of use. In fact, some of the tables as well as the "+
    "chairs sit lopsidedly. In what you think is "+
    "probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening. There are stools which sit in front of the counter, facing "+
    "it. A large %^BOLD%^%^GREEN%^menu%^RESET%^%^ORANGE%^ has been lopsidedly attached to the front of it. "
    "A section of wall in the back corner is free of tables and a large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests there. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs this place also sleeps here. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent, surprisingly none have been broken or if they have been, they were "+
    "replaced. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nBody odor hangs heavily in the air here, mixing with the smell of strong ale, and "+
    "burnt food.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^There are numerous tables lining the walls of this "+
        "tent. There are four large plush chairs sitting near each table. In the center of the tent is a large wooden "+
        "counter in the shape of a half circle, with stools in front. A large menu has been attached lopsidedly to it.%^RESET%^",
        
        ({"tables", "numerous tables", "plush chairs", "large chairs", "stools"}) : "%^BOLD%^%^YELLOW%^"+
        "These tables line the walls of the tent. There are four large plush chair chairs sitting near each one. "+
        "Both the tables and the chairs look quite worn, as if they have seen lots of use. Some of them actually "+
        "sit lopsidedly. The stools near the counter seem to be in better condition for the most part.%^RESET%^",
        
        ({"counter", "wooden counter", "large counter"}) : "%^RESET%^%^GREEN%^This large wooden counter is in "+
        "the shape of a half circle and faces the opening of the tent. Remarkably it is kept mostly clear, if not exactly "+
        "clean. There are stools sitting in front of it, facing it. A large menu has been attached to the front of it. "+
        "Perhaps you could read it.%^RESET%^",
        
        ({"menu"}) : "%^BOLD%^%^GREEN%^This large menu is attached to the front of the counter. You could read it.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. Surprisingly none of them have been broken or if they have been "+
        "they were replaced. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent, in a "+
        "section that is away from the tables. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this place also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"13"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
    if(!present("oasis barkeep")) find_object_or_load(ELMON+"barkeep")->move(TO);
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

    ob = present("oasis barkeep");
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
            melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^BOLD%%^%%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ gold pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	        write(melnmarn);
        }
        message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
        message("Ninfo", "%^RESET%^<buy menu_name> will get you that item.\n", TP);

        return 1;
    }
}
