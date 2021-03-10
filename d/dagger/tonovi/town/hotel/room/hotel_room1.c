// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit INH+"hotel_room";

void create(){
    ::create();
    set_exits(([
        "east" : ROOMS "hallway1",
        ]));
    set_door("ebony door", ROOMS "hallway1", "east", 0);
	set_door_description("ebony door","%^RESET%^%^CYAN%^Fashioned from %^BOLD%^%^BLACK%^"+
        "solid ebony%^RESET%^%^CYAN%^, this door is massive and sturdy in construction. "+
        "A %^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k"+
        "%^RESET%^%^ORANGE%^n%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^"+
        "%^ORANGE%^e%^BOLD%^yh%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been "+
        "inset to one side.%^RESET%^");
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
        switch(random(15)){
            case 0..5:
                new(MON"roomservice1.c")->move(TO);
                new(OBJ"serving_cart.c")->move(TO);
                break;
            case 6..12:
                new(MON"roomservice2.c")->move(TO);
                new(OBJ"serving_cart.c")->move(TO);
                break;
            default:
                new(MON"roomservice3.c")->move(TO);
                new(OBJ"serving_cart.c")->move(TO);
                break;
        }
    }
    tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short %^RESET%^r%^BOLD%^i"+
        "%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters with a "+
        "serving cart laden with covered dishes. They set a few %^RESET%^menu%^BOLD%^"+
        "%^BLACK%^s out and await your pleasure.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" gives the small bell a %^RESET%^r"+
        "%^BOLD%^i%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters "+
        "pushing a serving cart laden with covered plates and dishes. They set a few "+
        "%^RESET%^menu%^BOLD%^%^BLACK%^s out and await your pleasure.%^RESET%^",TP);
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
    write("%^GREEN%^--%^BOLD%^<%^RESET%^%^GREEN%^--%^BOLD%^{%^RED%^@  %^ORANGE%^G%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n%^BOLD%^d T%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^no%^RESET%^%^ORANGE%^v%^BOLD%^i H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^l R%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^staura%^RESET%^%^ORANGE%^n%^BOLD%^t  %^RED%^@%^GREEN%^}%^RESET%^%^GREEN%^--%^BOLD%^>%^RESET%^%^GREEN%^--%^WHITE%^");
    write("\n");
    write("%^BOLD%^%^GREEN%^-----------------------------------------------");
    write("\n");
    write("                   %^YELLOW%^A%^RESET%^%^ORANGE%^ppetizers                   %^RESET%^");
    write("%^BOLD%^Lamb Barley Soup\t\t\t"+(int)ob->get_price("soup")+" gold");
    write("%^RESET%^Grilled Prawns\t\t\t\t"+(int)ob->get_price("prawns")+" gold");
    write("%^BOLD%^Mushroom Medley\t\t\t\t"+(int)ob->get_price("mushroom medley")+" gold");
    write("\n");
    write("                   %^YELLOW%^M%^RESET%^%^ORANGE%^ain %^YELLOW%^C%^RESET%^%^ORANGE%^ourse%^RESET%^");
    write("%^BOLD%^Pan-seared Salmon\t\t\t"+(int)ob->get_price("salmon")+" gold");
    write("%^RESET%^Grilled Chicken\t\t\t\t"+(int)ob->get_price("chicken")+" gold");
    write("%^BOLD%^Steak and Garlic Butter\t\t\t"+(int)ob->get_price("steak")+" gold");
    write("\n");
    write("                    %^YELLOW%^D%^RESET%^%^ORANGE%^esserts%^RESET%^");
    write("%^BOLD%^Creme Brulee\t\t\t\t"+(int)ob->get_price("creme brulee")+" gold");
    write("%^RESET%^Sticky Toffee Pudding\t\t\t"+(int)ob->get_price("pudding")+" gold");
    write("%^BOLD%^Chocolate Drambuie Trifle\t\t"+(int)ob->get_price("trifle")+" gold");
    write("\n");
    write("                     %^YELLOW%^D%^RESET%^%^ORANGE%^rinks%^RESET%^");
    write("%^BOLD%^Lemon Water\t\t\t\t"+(int)ob->get_price("water")+" gold");
    write("%^RESET%^Chamomile Tea\t\t\t\t"+(int)ob->get_price("tea")+" gold");
    write("\n");
    write("                    %^YELLOW%^N%^RESET%^%^ORANGE%^ightcaps%^RESET%^");
    write("%^BOLD%^Iced Brandy\t\t\t\t"+(int)ob->get_price("brandy")+" gold");
    write("%^RESET%^Smoked Sherry\t\t\t\t"+(int)ob->get_price("sherry")+" gold");
    write("%^BOLD%^Aged Scotch\t\t\t\t"+(int)ob->get_price("scotch")+" gold");
    write("%^RESET%^Golden Chardonnay\t\t\t"+(int)ob->get_price("chardonnay")+" gold");
    write("\n");
    write("%^BOLD%^%^GREEN%^-----------------------------------------------");
    return 1;
}

