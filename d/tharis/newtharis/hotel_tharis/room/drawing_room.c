// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The Grand Suite");
    set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^e G%^RESET%^%^MAGENTA%^ran%^BOLD%^%^BLACK%^d S%^RESET%^%^MAGENTA%^uit%^BOLD%^%^BLACK%^e %^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The drawing room for the suite is meant for entertaining guests, and it appears the decor has been carefully curated to appeal to the upper class. A brace of couches frames an impressive %^RESET%^%^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^h%^BOLD%^y%^RESET%^s%^BOLD%^%^MAGENTA%^t qu%^RESET%^%^MAGENTA%^a%^WHITE%^r%^BOLD%^%^MAGENTA%^tz c%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^f%^RESET%^%^MAGENTA%^e%^BOLD%^e t%^RESET%^%^MAGENTA%^a%^WHITE%^b%^BOLD%^l%^MAGENTA%^e%^BLACK%^, and a large f%^RESET%^i%^BOLD%^%^BLACK%^r%^RESET%^e%^BOLD%^%^BLACK%^pl%^WHITE%^a%^BLACK%^c%^RESET%^e %^BOLD%^%^BLACK%^dominates the northern wall. A thick %^RESET%^%^MAGENTA%^rug %^BOLD%^%^BLACK%^covers most of the eb%^RESET%^o%^BOLD%^%^BLACK%^ny w%^RESET%^o%^BOLD%^o%^BLACK%^d fl%^RESET%^o%^BOLD%^o%^BLACK%^r, %^RESET%^muffling %^BOLD%^%^BLACK%^any footsteps and absorbing the %^RESET%^%^RED%^w%^BOLD%^a%^RESET%^%^RED%^rmth %^BOLD%^%^BLACK%^of the %^RED%^f%^RESET%^%^ORANGE%^i%^RED%^r%^BOLD%^e%^BLACK%^. A few potted %^RESET%^%^GREEN%^pl%^ORANGE%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^ts %^BOLD%^%^BLACK%^serve to disrupt the expanse of the m%^RESET%^a%^BOLD%^%^BLACK%^rbl%^WHITE%^e %^BLACK%^w%^RESET%^a%^BOLD%^l%^BLACK%^ls, parting for an archway that leads further into the bedroom.%^RESET%^\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is pleasantly quiet in here.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        "fireplace" : "%^BOLD%^%^BLACK%^Dominating the northern wall, this massive f%^RESET%^i%^BOLD%^%^BLACK%^r%^WHITE%^e%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^c%^WHITE%^e %^BLACK%^juts out in a hearth that could be a platform all its own. Within, there is a circle of %^ORANGE%^r%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e%^BOLD%^s %^BLACK%^and strange %^RESET%^s%^BOLD%^%^BLACK%^y%^RESET%^m%^BOLD%^b%^BLACK%^o%^WHITE%^l%^RESET%^s %^BOLD%^%^BLACK%^carved and inlaid with %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld %^BLACK%^and s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^e%^BOLD%^a%^BLACK%^f%^RESET%^. %^BOLD%^%^BLACK%^A small %^RED%^f%^RESET%^%^RED%^i%^YELLOW%^r%^RED%^e %^RESET%^%^RED%^e%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^m%^RESET%^%^RED%^e%^BOLD%^nt%^ORANGE%^a%^RED%^l %^BLACK%^stands within the %^ORANGE%^c%^RESET%^i%^BOLD%^%^BLACK%^r%^ORANGE%^cl%^WHITE%^e%^BLACK%^, coaxed and coerced into an %^RESET%^%^RED%^alluring %^BOLD%^%^BLACK%^female form. It dances and performs from the boundaries of its prison, only the %^RESET%^%^RED%^w%^BOLD%^a%^RESET%^%^RED%^rmth %^BOLD%^%^BLACK%^of its living %^RED%^fl%^RESET%^%^RED%^a%^YELLOW%^m%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^escaping into the room.%^RESET%^",
        ({"table", "coffee table"}) : "%^RESET%^A large block of %^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^h%^BOLD%^y%^RESET%^s%^BOLD%^%^MAGENTA%^t qu%^RESET%^%^MAGENTA%^a%^WHITE%^r%^BOLD%^%^MAGENTA%^tz %^RESET%^serves as the %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^f%^RESET%^%^MAGENTA%^e%^BOLD%^e t%^RESET%^%^MAGENTA%^a%^WHITE%^b%^BOLD%^l%^MAGENTA%^e%^RESET%^. The %^BOLD%^%^MAGENTA%^top %^RESET%^has been shorn off and levelled, then %^BOLD%^polished %^RESET%^to a r%^BOLD%^e%^RESET%^fl%^BOLD%^e%^RESET%^ct%^BOLD%^i%^RESET%^v%^BOLD%^e %^RESET%^sh%^BOLD%^i%^RESET%^n%^BOLD%^e%^RESET%^. The %^BOLD%^%^BLACK%^sm%^RESET%^o%^BOLD%^%^BLACK%^k%^WHITE%^e%^BLACK%^y %^RESET%^%^MAGENTA%^v%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t cr%^BOLD%^y%^RESET%^%^MAGENTA%^st%^BOLD%^a%^RESET%^%^MAGENTA%^ls %^WHITE%^offer a muted %^BOLD%^%^MAGENTA%^sparkle %^RESET%^in the light of the %^BOLD%^%^BLACK%^f%^RESET%^i%^BOLD%^%^BLACK%^r%^RESET%^e%^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^c%^WHITE%^e%^BLACK%^. %^RESET%^",
        ({"couch", "couches"}) : "%^RESET%^Two long %^BOLD%^%^BLACK%^black suede %^RESET%^couches oppose each other across the %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^f%^RESET%^%^MAGENTA%^e%^BOLD%^e t%^RESET%^%^MAGENTA%^a%^WHITE%^b%^BOLD%^l%^MAGENTA%^e%^RESET%^, each having a sidelong view of the %^BOLD%^%^BLACK%^f%^RESET%^i%^BOLD%^%^BLACK%^r%^RESET%^e%^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^c%^WHITE%^e%^RESET%^. The %^BOLD%^%^BLACK%^cushions %^RESET%^are thickly padded and comfortable, throw pillows in various %^BOLD%^%^MAGENTA%^h%^RESET%^%^MAGENTA%^ue%^BOLD%^s %^RESET%^of %^MAGENTA%^v%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t %^WHITE%^rest against each arm for extra comfort. %^RESET%^",
        ({"floor", "rug"}) : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^. Central to the room and resting beneath the %^BOLD%^%^BLACK%^couches %^RESET%^and %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^f%^RESET%^%^MAGENTA%^e%^BOLD%^e t%^RESET%^%^MAGENTA%^a%^WHITE%^b%^BOLD%^l%^MAGENTA%^e%^RESET%^, a luxuriously thick, %^MAGENTA%^deep violet %^WHITE%^area rug covers most of the %^BOLD%^%^BLACK%^fl%^RESET%^o%^BOLD%^o%^BLACK%^r%^RESET%^. ",
        ({"bells", "bell", "iron bell", "silver bell"}) : "%^RESET%^Two delicate bells rest on the %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^f%^RESET%^%^MAGENTA%^e%^BOLD%^e t%^RESET%^%^MAGENTA%^a%^WHITE%^b%^BOLD%^l%^MAGENTA%^e%^RESET%^. A %^BOLD%^note %^RESET%^indicates you could %^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^the %^BOLD%^%^BLACK%^iron bell %^RESET%^to call for a charcuterie board, or you could %^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^the %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^l%^BLACK%^l %^RESET%^to summon room service.",
        ({"plants", "ferns"}) : "%^RESET%^Large, expansive %^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns %^WHITE%^are located along the walls. They have been planted in large %^ORANGE%^ceramic pots%^WHITE%^, which have been painted a %^BOLD%^pristine%^RESET%^, %^BOLD%^m%^RESET%^a%^BOLD%^tt%^RESET%^e %^BOLD%^wh%^RESET%^i%^BOLD%^t%^RESET%^e.%^RESET%^",
        ]));
    set_exits(([
        "south" : ROOMS "stairs3",
        "west" : ROOMS "master_bedroom",
        ]));
    set_door("oak door", ROOMS "stairs3", "south", 0);
	set_door_description("oak door","%^RESET%^Fashioned from %^ORANGE%^solid oak%^RESET%^, this door is massive and sturdy in construction. The door is adorned with a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er l%^RESET%^o%^BOLD%^c%^BLACK%^ks%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^.");
}

void init(){
    ::init();
    add_action("read_fun","read");
    add_action("ring_fun","ring");
    add_action("dismiss_fun","dismiss");
}

int ring_fun(string str){
    if((str!="the silver bell") && (str!="the iron bell") && (str!="silver bell") && (str!="iron bell")){
        return 0;
    }
    switch(str){
        case "the silver bell":
            if(present("roomservice")){
                write("Room service is already here!");
                return 1;
            }
            else{
                new(MON"roomservice1.c")->move(TO);
                new(OBJ+"serving_cart.c")->move(TO);
                tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short r%^RESET%^i%^BOLD%^n%^BLACK%^g. A few moments later, a servant enters with a serving cart laden with covered dishes. They set a few menus out and await your pleasure.%^RESET%^");
                tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+"%^BOLD%^%^BLACK%^ gives the bell a short r%^RESET%^i%^BOLD%^n%^BLACK%^g. A few moments later, a servant enters with a serving cart laden with covered dishes. They set a few menus out and await your pleasure.%^RESET%^",TP);
                tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss room service %^RESET%^when you "+
                    "are finished ordering.");
                return 1;
            }
            break;
        case "silver bell":
            if(present("roomservice")){
                write("Room service is already here!");
                return 1;
            }
            else{
                new(MON"roomservice1.c")->move(TO);
                new(OBJ+"serving_cart.c")->move(TO);
                tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short r%^RESET%^i%^BOLD%^n%^BLACK%^g. A few moments later, a servant enters with a serving cart laden with covered dishes. They set a few menus out and await your pleasure.%^RESET%^");
                tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+"%^BOLD%^%^BLACK%^ gives the bell a short r%^RESET%^i%^BOLD%^n%^BLACK%^g. A few moments later, a servant enters with a serving cart laden with covered dishes. They set a few menus out and await your pleasure.%^RESET%^",TP);
                tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss room service %^RESET%^when you "+
                    "are finished ordering.");
                return 1;
            }
            break;
        case "the iron bell":
            new(OBJ"charcuterie.c")->move(TO);
            tell_object(TP,"%^RESET%^You give the bell a short %^BOLD%^%^BLACK%^ring%^RESET%^. A few moments later, a servant arrives and places a charcuterie board on the coffee table.%^RESET%^");
            tell_room(ETP,"BOLD%^%^BLACK%^"+TP->QCN+"%^BOLD%^%^BLACK%^ gives the bell a short %^BOLD%^%^BLACK%^ring%^RESET%^. A few moments later, a servant arrives and places a charcuterie board on the coffee table.%^RESET%^",TP);
            tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss charcuterie %^RESET%^"+
                "when you are finished with it.");
            return 1;
            break;
        case "iron bell":
            new(OBJ"charcuterie.c")->move(TO);
            tell_object(TP,"%^RESET%^You give the bell a short %^BOLD%^%^BLACK%^ring%^RESET%^. A few moments later, a servant arrives and places a charcuterie board on the coffee table.%^RESET%^");
            tell_room(ETP,"BOLD%^%^BLACK%^"+TP->QCN+"%^BOLD%^%^BLACK%^ gives the bell a short %^BOLD%^%^BLACK%^ring%^RESET%^. A few moments later, a servant arrives and places a charcuterie board on the coffee table.%^RESET%^",TP);
            tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss charcuterie %^RESET%^"+
                "when you are finished with it.");
            return 1;
            break;
        default:
            tell_object(TP,"%^BOLD%^%^BLACK%^The bells make a tinkling sound.");
            return 1;
            break;
    }
            
}

int dismiss_fun(string str){
    object ob, ob2;
    
    if((str!="room service") && (str!="servant") && (str!="charcuterie"))
        return 0;
    switch(str){
        case "room service":
            if(!present("roomservice"))
                return 0;
            else{
                ob=present("roomservice");
                ob2=present("servingcart");
                tell_room(ETP,"%^RESET%^The servant bows their head in subservience, "+
                    "turning to push the cart from the room.");
                ob->move("/d/shadowgate/void.c");
                ob->remove();
                ob2->move("/d/shadowgate/void.c");
                ob2->remove();
                return 1;
            }
            break;
        case "servant":
            if(!present("roomservice"))
                return 0;
            else{
                ob=present("roomservice");
                ob2=present("servingcart");
                tell_room(ETP,"%^RESET%^The servant bows their head in subservience, "+
                    "turning to push the cart from the room.");
                ob->move("/d/shadowgate/void.c");
                ob->remove();
                ob2->move("/d/shadowgate/void.c");
                ob2->remove();
                return 1;
            }
            break;
        case "charcuterie":
            if(present("charcuterie")){
                ob=present("charcuterie");
                tell_room(ETP,"%^BOLD%^%^BLACK%^A servant quietly enters, gathering "+
                    "up the charcuterie board and taking it away.%^RESET%^");
                ob->remove();
                return 1;
            }
            break;
        default:
            return 1;
            break;
    }
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

