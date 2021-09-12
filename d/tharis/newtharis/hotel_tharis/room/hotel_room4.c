// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"hotel_room";

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS "hallway2",
        ]));
    set_door("oak door", ROOMS "hallway2", "west", 0);
	set_door_description("oak door","%^RESET%^Fashioned from %^ORANGE%^solid oak%^RESET%^, this door is massive and sturdy in construction. The door is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^.");
}

void init(){
    ::init();
    add_action("read_fun","read");
    add_action("ring_fun","ring");
    add_action("dismiss_fun","dismiss");
}

int ring_fun(string str){
    if((str!="the bell") && (str!="bell"))
        return 0;
    if(present("roomservice")){
        write("Room service is already here!");
        return 1;
    }
    else{
        new(MON"roomservice1.c")->move(TO);
        new(OBJ"serving_cart.c")->move(TO);
    }
    tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short %^RESET%^r%^BOLD%^i"+
        "%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters with a "+
        "serving cart laden with covered dishes. They set a few %^RESET%^menus%^BOLD%^"+
        "%^BLACK%^ out and await your pleasure.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" gives the small bell a %^RESET%^r"+
        "%^BOLD%^i%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters "+
        "pushing a serving cart laden with covered plates and dishes. They set a few "+
        "%^RESET%^menus%^BOLD%^%^BLACK%^ out and await your pleasure.%^RESET%^",TP);
    tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss room service %^RESET%^when you "+
        "are finished ordering.");
    return 1;
}

int dismiss_fun(string str){
    object ob, ob2;
    
    if((str!="room service") && (str!="servant"))
        return 0;
    if(!present("roomservice"))
        return 0;
    ob=present("roomservice");
    ob2=present("servingcart");
    tell_room(ETP,"%^RESET%^The servant bows their head in subservience, turning to "+
        "push the cart from the room.");
    ob->move("/d/shadowgate/void.c");
    ob->remove();
    ob2->move("/d/shadowgate/void.c");
    ob2->remove();
    return 1;
}

int read_fun(string str){
    object ob;
    
    if(str!="menu")
        return 0;
    if(!present("roomservice")){
        write("You should summon room service first.");
        return 1;
    }
    
    ob=present("roomservice");
    
    write("\n");
    write("%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~ %^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^V%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^BLACK%^Restaurant %^RESET%^%^MAGENTA%^& %^BOLD%^%^BLACK%^Bar %^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^WHITE%^");
    write("\n");
    write("\n");
    write("                   %^RESET%^%^MAGENTA%^Appetizers%^RESET%^                   %^RESET%^");
    write("%^BOLD%^%^BLACK%^Pumpkin Cream Soup%^WHITE%^\t\t\t"+(int)ob->get_price("soup")+" gold");
    write("%^BOLD%^%^BLACK%^Tharisian Salad%^WHITE%^\t\t\t\t"+(int)ob->get_price("salad")+" gold");
    write("%^BOLD%^%^BLACK%^Fried Calamari%^WHITE%^\t\t\t\t"+(int)ob->get_price("calamari")+" gold");
    write("\n");
    write("                   %^RESET%^%^MAGENTA%^Main Course%^RESET%^");
    write("%^BOLD%^%^BLACK%^Filet Mignon%^WHITE%^\t\t\t\t"+(int)ob->get_price("filet mignon")+" gold");
    write("%^BOLD%^%^BLACK%^Rosemary Braised Lamb Shank%^WHITE%^\t\t"+(int)ob->get_price("lamb")+" gold");
    write("%^BOLD%^%^BLACK%^Dijon-Crusted Halibut%^WHITE%^\t\t\t"+(int)ob->get_price("halibut")+" gold");
    write("\n");
    write("                   %^RESET%^%^MAGENTA%^Desserts%^WHITE%^");
    write("%^BOLD%^%^BLACK%^Creme Brulee%^WHITE%^\t\t\t\t"+(int)ob->get_price("creme brulee")+" gold");
    write("%^BOLD%^%^BLACK%^Peach Cobbler%^WHITE%^\t\t\t\t"+(int)ob->get_price("cobbler")+" gold");
    write("%^BOLD%^%^BLACK%^Chocolate Cake%^WHITE%^\t\t\t\t"+(int)ob->get_price("cake")+" gold");
    write("\n");
    write("              %^RESET%^%^MAGENTA%^Non-Alcoholic Drinks%^RESET%^");
    write("%^BOLD%^%^BLACK%^Water%^WHITE%^\t\t\t\t\t"+(int)ob->get_price("water")+" gold");
    write("%^BOLD%^%^BLACK%^Lavender Tea%^WHITE%^\t\t\t\t"+(int)ob->get_price("tea")+" gold");
    write("%^BOLD%^%^BLACK%^Lemonade%^WHITE%^\t\t\t\t"+(int)ob->get_price("lemonade")+" gold");
    write("\n");
    write("             %^RESET%^%^MAGENTA%^Alcoholic Beverages%^RESET%^");
    write("%^BOLD%^%^BLACK%^Tequila Twilight%^WHITE%^\t\t\t"+(int)ob->get_price("tequila twilight")+" gold");
    write("%^BOLD%^%^BLACK%^Whiskey Sour%^WHITE%^\t\t\t\t"+(int)ob->get_price("whiskey sour")+" gold");
    write("%^BOLD%^%^BLACK%^Vodka Martini%^WHITE%^\t\t\t\t"+(int)ob->get_price("vodka martini")+" gold");
    write("%^BOLD%^%^BLACK%^Blood Wine%^WHITE%^\t\t\t\t"+(int)ob->get_price("blood wine")+" gold");
    write("%^BOLD%^%^BLACK%^Chardonnay%^WHITE%^\t\t\t\t"+(int)ob->get_price("chardonnay")+" gold");
    write("\n");
    write("%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^BOLD%^*%^RESET%^%^MAGENTA%^~%^WHITE%^");
    return 1;
}

