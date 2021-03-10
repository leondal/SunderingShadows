// code update, adding some new items too 03/19/17 -Ares
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"

inherit TROOM;
int FLAG;


void init() 
{
    ::init();
    add_action("purchase_func","purchase");
}


void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default", "A mysterious smell is in the air.");
    set_listen("default", "You hear a deal about to be made.");
    set_items(([
        "box":"The large box is covered in black paper with glowing white stars "
        "all over it's surface. A large red ribbon is tied around it.",
    ]));
    set_exits(([
        "west": RPATH "b9",
    ]));
}


string lng_fun(string str) 
{
    str =
    "%^RESET%^%^RED%^The small and narrow chamber is "
    "made of the same %^BOLD%^"
    "blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
    "The stone calls out to you as though it is alive and held captive in "
    "an endless state of torment. A few small black %^CYAN%^candles%^RED%^ "
    "lay flickering on the floor creating an array of %^BLUE%^shadows%^RED%^ "
    "which dance wildly upon the walls. %^RED%^";
    if(present("baba")) { str += "\n%^BLUE%^A very short and funny looking humanoid imp stands grinning at you. %^RED%^"; }
    if(FLAG == 0) {	str += "\n%^GREEN%^A large box with glowing runes covering it sits in the center of the room.%^RESET%^"; }
    return str;
}


string shrt_fun(string str) 
{
    str = "%^RED%^Baba Yaga's House of Random Bargains%^RESET%^";
    return str;
}


void reset() 
{
    ::reset();
    if(!present("baba")) 
    {
        new( MPATH "baba.c" )->move(TO);
    }
}


int purchase_func(string str) 
{
    object baba;
    int i;
    string ITEM;
    
    if(!str) 
    {
        notify_fail("Purchase what?\n");
        return 0;
    }
    if(str != "box") 
    {
        notify_fail("Purchase what?\n");
        return 0;
    }
    if(!present("baba")) 
    {
        notify_fail("Baba Yaga seems to have left the building!\n");
        return 0;
    }
    if(FLAG == 1) 
    {
        notify_fail("The deal has already been made, the box is gone!\n");
        return 0;
    }
    if((int)TP->query_money("gold") < 10000) 
    {
        notify_fail("You don't have 10000 gold to make any deals!\n");
        return 0;
    }
    i = random(16);
    switch(i)
    {
    case 0:
        ITEM = "Sphere";
        new("/d/tharis/barrow/obj/sphere.c")->move(TO);
        break;

    case 1:
        ITEM = "Bloody Hand";
        new( "/d/dagger/drow/obj/hand.c")->move(TO);
        break;
        
    case 2:
        ITEM = "Krykoth";
        new("/d/dagger/marsh/tower/mon/krykoth.c")->move(TO);
        break;

    case 3:
        ITEM = "Sword of Ty'relk";
        new("/d/tharis/barrow/obj/tyrelk.c")->move(TO);
        break;

    case 4:
        ITEM = "Sphere";
        new("/d/dagger/drow/obj/sphere.c")->move(TO);
        break;

    case 5:
        ITEM = "Bag of Powder";
        new("/d/tharis/obj/bpowder.c")->move(TO);
        break;

    case 6:
        ITEM = "Sphere";
        new("/d/tharis/barrow/obj/sphere.c")->move(TO);
        break;
        
    case 7:
        ITEM = "Ring";
        new("/d/dagger/marsh/tower/obj/ring.c")->move(TO);
        break;

    case 8:
        ITEM = "Cylinder";
        new("/d/dagger/drow/obj/cylinder.c")->move(TO);
        break;
        
    case 9:
        ITEM = "Well of Many Worlds";
        new("/d/dagger/drow/temple/obj/worwell.c")->move(TO);
        break;
        
    case 10:
        ITEM = "Tablet";
        new("/d/dagger/marsh/tower/obj/tablet.c")->move(TO);
        break;
        
    case 11:
        ITEM = "Staff";
        new("/d/dagger/drow/obj/staff.c")->move(TO);
        break;
        
    case 12:
        ITEM = "Stone";
        new("/d/dagger/marsh/tower/obj/stone.c")->move(TO);
        break;
        
    case 13:
        ITEM = "Key";
        new("/d/dagger/marsh/tower/obj/mistkey.c")->move(TO);
        break;
        
    case 14:
        ITEM = "Cloak";
        new("/d/koenig/town/items/cloak_p2.c")->move(TO);
        break;
        
    case 15:
        ITEM = "Axe";
        new("/d/attaya/obj/axe.c")->move(TO);
        break;        
    }
    
    if(baba = present("baba",TO)) 
    {
        baba->force_me("say OH GOODY! Another deal made!");
        baba->force_me("say Welp...let's see what the surprise today is!");
        baba->force_me("emote lifts up the box and dumps out the contents on the ground.");
        baba->force_me("say Woo woo...Your the proud owner of a lovely new "+ITEM+"!!!");
        baba->force_me("cackle");
        baba->force_me("chuckle");
        TP->add_money("gold",-10000);
        baba->remove();
        FLAG = 1;
        return 1;
    }
}
