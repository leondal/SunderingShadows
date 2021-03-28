// Chernobog (1/23/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The Duchal Suite");
    set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^h%^BOLD%^e D%^RESET%^%^ORANGE%^u%^BOLD%^"+
        "%^BLACK%^ch%^RESET%^%^ORANGE%^a%^BOLD%^l S%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^"+
        "i%^RESET%^%^ORANGE%^t%^BOLD%^e%^RESET%^");
    set_long("The drawing room for the suite is meant for entertaining guests, and it "+
        "appears the decor has been carefully dictated to appeal to the upper class. A "+
        "brace of %^BOLD%^co%^RESET%^u%^BOLD%^ch%^RESET%^e%^BOLD%^s %^RESET%^frame an "+
        "impressive %^BOLD%^%^BLACK%^cr%^RESET%^y%^BOLD%^%^BLACK%^st%^RESET%^a%^BOLD%^"+
        "%^BLACK%^l q%^RESET%^u%^BOLD%^%^BLACK%^art%^RESET%^z coffee table, and an "+
        "impressive %^RED%^f%^BOLD%^i%^ORANGE%^r%^RED%^e%^RESET%^%^RED%^p%^BOLD%^l"+
        "%^ORANGE%^a%^RED%^c%^RESET%^%^RED%^e %^WHITE%^dominates the northern wall. "+
        "Resting on the mantle, a %^BOLD%^ma%^RESET%^r%^BOLD%^ble b%^RESET%^u%^BOLD%^"+
        "st %^RESET%^of an %^MAGENTA%^im%^RED%^p%^MAGENTA%^er%^RED%^i%^MAGENTA%^ou"+
        "%^RED%^s %^WHITE%^woman peers down at the room proper. A thick %^BOLD%^"+
        "%^BLACK%^rug %^RESET%^covers "+
        "most of the %^ORANGE%^ma%^RED%^h%^ORANGE%^og%^RED%^a%^ORANGE%^ny fl%^RED%^o"+
        "%^ORANGE%^or%^WHITE%^, muffling any footsteps and absorbing the %^RED%^"+
        "warmth %^WHITE%^of the %^RED%^f%^BOLD%^i%^ORANGE%^r%^RED%^e%^RESET%^. A few "+
        "potted %^GREEN%^p%^BOLD%^l%^RESET%^%^GREEN%^a%^ORANGE%^n%^BOLD%^%^GREEN%^t"+
        "%^RESET%^%^GREEN%^s %^WHITE%^serve to disrupt the expanse of %^BOLD%^"+
        "%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne wal%^RESET%^l%^BOLD%^%^BLACK%^s"+
        "%^RESET%^, parting for an archway that leads further into the bedroom.\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is pleasantly quiet in here.");
    set_items(([
        ({"wall", "walls"}) : "%^RESET%^%^CYAN%^Uneven %^BOLD%^%^BLACK%^stones "+
            "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^WHITE%^"+
            "d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^"+
            "%^BLACK%^y %^RESET%^%^CYAN%^comprise these walls. The black stone is a "+
            "common element of Tonovi construction, mined from the north.%^RESET%^",
        "fireplace" : "%^RESET%^%^CYAN%^Dominating the northern wall, this massive "+
            "%^BOLD%^%^RED%^f%^ORANGE%^i%^WHITE%^r%^RED%^ep%^WHITE%^l%^ORANGE%^a%^RED%^"+
            "ce %^RESET%^%^CYAN%^juts out in a hearth that could be a platform all its "+
            "own. Within, there is a circle of %^ORANGE%^r%^BOLD%^u%^WHITE%^n%^RESET%^e"+
            "%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^and strange %^ORANGE%^s%^BOLD%^ym"+
            "%^WHITE%^b%^RESET%^ol%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^picked out in "+
            "%^YELLOW%^g%^WHITE%^o%^ORANGE%^l%^RESET%^%^ORANGE%^d %^CYAN%^and %^BOLD%^"+
            "%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^ORANGE%^l"+
            "%^WHITE%^e%^RESET%^a%^BOLD%^%^BLACK%^f%^RESET%^%^CYAN%^. A small %^RED%^f"+
            "%^BOLD%^i%^ORANGE%^r%^RESET%^%^RED%^e e%^BOLD%^l%^ORANGE%^e%^RED%^m"+
            "%^RESET%^%^RED%^e%^BOLD%^n%^ORANGE%^t%^RESET%^%^RED%^a%^BOLD%^l %^RESET%^"+
            "%^CYAN%^stands within the circle, coaxed and coerced into an alluring "+
            "female form. It %^MAGENTA%^d%^BOLD%^a%^WHITE%^n%^MAGENTA%^c%^RESET%^"+
            "%^MAGENTA%^e%^BOLD%^s %^RESET%^%^CYAN%^and performs from the boundaries "+
            "of its prison, only the %^RED%^warmth %^CYAN%^of its living flames "+
            "escaping into the room.%^RESET%^",
        ({"table", "coffee table"}) : "%^RESET%^%^CYAN%^A large polished slab of "+
            "%^BOLD%^%^BLACK%^sm%^RESET%^o%^BOLD%^%^BLACK%^ke%^RESET%^y %^BOLD%^"+
            "%^BLACK%^q%^RESET%^u%^BOLD%^%^BLACK%^ar%^RESET%^t%^BOLD%^%^BLACK%^z "+
            "%^RESET%^%^CYAN%^comprises the surface of the coffee table, an oblong "+
            "oval of %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^ou%^RESET%^d%^BOLD%^"+
            "%^BLACK%^y cr%^RESET%^y%^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^al "+
            "%^RESET%^%^CYAN%^that offers a muted s%^WHITE%^p%^BOLD%^%^CYAN%^a"+
            "%^RESET%^%^CYAN%^r%^WHITE%^k%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^e in the "+
            "light of the %^RED%^f%^BOLD%^i%^ORANGE%^r%^RED%^e%^RESET%^%^RED%^p"+
            "%^BOLD%^l%^ORANGE%^a%^RED%^c%^RESET%^%^RED%^e%^CYAN%^. It rests on four "+
            "%^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r "+
            "%^RESET%^%^CYAN%^legs that have been moulded into the shape of kneeling "+
            "elven figures, their backs and arms bent in support of the weight. The "+
            "figures appear to wear simple shifts, with ornate collars at their necks"+
            ". Two bells sit at attention on the table, one %^BOLD%^%^BLACK%^s"+
            "%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^and "+
            "one %^YELLOW%^g%^WHITE%^o%^ORANGE%^l%^RESET%^%^ORANGE%^d%^CYAN%^."+
            "%^RESET%^",
        ({"couch", "couches"}) : "%^RESET%^%^CYAN%^Two long %^BOLD%^%^WHITE%^c"+
            "%^RESET%^o%^BOLD%^u%^RESET%^c%^BOLD%^h%^RESET%^e%^BOLD%^s %^RESET%^"+
            "%^CYAN%^oppose each other across the coffee table, each having a "+
            "sidelong view of the %^RED%^f%^BOLD%^i%^ORANGE%^r%^RED%^e%^RESET%^"+
            "%^RED%^p%^BOLD%^l%^ORANGE%^a%^RED%^c%^RESET%^%^RED%^e%^CYAN%^. The "+
            "cushions are overly padded and comfortable, covered in %^BOLD%^%^WHITE%^"+
            "white cloth %^RESET%^%^CYAN%^with %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv"+
            "%^RESET%^e%^BOLD%^%^BLACK%^r f%^RESET%^l%^BOLD%^e%^RESET%^u%^BOLD%^"+
            "%^BLACK%^r %^WHITE%^d%^RESET%^e l%^BOLD%^i%^RESET%^s %^CYAN%^embroidered "+
            "in a dignified pattern. The same material and pattern cover the couches "+
            "proper, which stand on small %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv"+
            "%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^clawed feet.%^RESET%^",
        "bust" : "%^RESET%^%^CYAN%^Carved from %^BOLD%^%^WHITE%^alabaster marble"+
            "%^RESET%^%^CYAN%^, this bust is in the likeness of %^BOLD%^Aesa "+
            "Langenberg%^RESET%^%^CYAN%^, the Duchess of Tonovi. Her hair has been "+
            "drawn back up into a complex braid that loops up along the back of her "+
            "head. She peers down from the mantle with an impressive level of "+
            "%^MAGENTA%^h%^RED%^au%^MAGENTA%^gh%^RED%^t%^MAGENTA%^i%^RED%^n"+
            "%^MAGENTA%^e%^RED%^ss %^CYAN%^and %^MAGENTA%^d%^RED%^i%^MAGENTA%^s"+
            "%^RED%^da%^MAGENTA%^i%^RED%^n%^CYAN%^.%^RESET%^",
        ({"floor", "rug"}) : "%^RESET%^%^CYAN%^The floors are a warm %^ORANGE%^ma"+
            "%^RED%^h%^ORANGE%^oag%^RED%^a%^ORANGE%^ny%^CYAN%^, polished and "+
            "burnished to a shine. Central to the room and supporting the couches "+
            "and coffee table, a thick rug spreads to cover most of the floor. It is "+
            "a %^BOLD%^%^BLACK%^deep black%^RESET%^%^CYAN%^, with an intricate and "+
            "flowing border picked out in %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^de"+
            "%^RESET%^%^ORANGE%^n t%^BOLD%^hr%^WHITE%^e%^ORANGE%^a%^RESET%^%^ORANGE%^d"+
            "%^CYAN%^.%^RESET%^",
        ({"bells", "bell", "gold bell", "silver bell"}) : "%^RESET%^%^CYAN%^Two "+
            "delicate %^ORANGE%^b%^BOLD%^e%^WHITE%^l%^RESET%^l%^BOLD%^%^BLACK%^s "+
            "%^RESET%^%^CYAN%^rest on the coffee table. A note indicates you could "+
            "%^BOLD%^ring the gold bell %^RESET%^%^CYAN%^to call for a charcuterie "+
            "board, or you could %^BOLD%^ring the silver bell %^RESET%^%^CYAN%^to "+
            "summon room service.%^RESET%^",
        ({"plants", "ferns"}) : "%^RESET%^%^CYAN%^Large, expansive %^GREEN%^f%^BOLD%^e"+
            "%^RESET%^%^ORANGE%^r%^GREEN%^n%^BOLD%^s %^RESET%^%^CYAN%^are located along"+
            " the walls. They have been planted in large %^RED%^sp%^ORANGE%^he%^RED%^"+
            "ri%^ORANGE%^ca%^RED%^l p%^ORANGE%^ot%^RED%^s%^CYAN%^, which have been "+
            "painted in alternating bands of %^ORANGE%^ochre %^CYAN%^and %^RED%^red"+
            "%^CYAN%^.%^RESET%^",
        ]));
    set_exits(([
        "south" : ROOMS "stairs3",
        "west" : ROOMS "master_bedroom",
        ]));
    set_door("oak door", ROOMS "stairs3", "south", 0);
	set_door_description("oak door","%^RESET%^%^CYAN%^Fashioned from %^ORANGE%^solid oak"+
        "%^CYAN%^, this door is massive and sturdy in construction. A %^YELLOW%^br"+
        "%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^%^ORANGE%^s %^BOLD%^k%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^ob %^RESET%^%^CYAN%^and %^YELLOW%^k%^RESET%^%^ORANGE%^e%^BOLD%^yh"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^le %^RESET%^%^CYAN%^have been inset to one side.");
}

void init(){
    ::init();
    add_action("read_fun","read");
    add_action("ring_fun","ring");
    add_action("dismiss_fun","dismiss");
}

int ring_fun(string str){
    if((str!="the silver bell") && (str!="the gold bell") && (str!="silver bell") && (str!="gold bell")){
        return 0;
    }
    switch(str){
        case "the silver bell":
            if(present("roomservice")){
                write("Room service is already here!");
                return 1;
            }
            else{
                new(MON"roomservice4.c")->move(TO);
                new(OBJ+"serving_cart.c")->move(TO);
                tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short %^RESET%^r%^BOLD%^i"+
                    "%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters with a "+
                    "serving cart laden with covered dishes. They set a few %^RESET%^menu%^BOLD%^"+
                    "%^BLACK%^s out and await your pleasure.%^RESET%^");
                tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^gives the small bell a %^RESET%^r"+
                    "%^BOLD%^i%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters "+
                    "pushing a serving cart laden with covered plates and dishes. They set a few "+
                    "%^RESET%^menu%^BOLD%^%^BLACK%^s out and await your pleasure.%^RESET%^",TP);
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
                new(MON"roomservice4.c")->move(TO);
                new(OBJ+"serving_cart.c")->move(TO);
                tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short %^RESET%^r%^BOLD%^i"+
                    "%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters with a "+
                    "serving cart laden with covered dishes. They set a few %^RESET%^menu%^BOLD%^"+
                    "%^BLACK%^s out and await your pleasure.%^RESET%^");
                tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^gives the small bell a %^RESET%^r"+
                    "%^BOLD%^i%^RESET%^n%^BOLD%^%^BLACK%^g. A few moments later, a servant enters "+
                    "pushing a serving cart laden with covered plates and dishes. They set a few "+
                    "%^RESET%^menu%^BOLD%^%^BLACK%^s out and await your pleasure.%^RESET%^",TP);
                tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss room service %^RESET%^when you "+
                    "are finished ordering.");
                return 1;
            }
            break;
        case "the gold bell":
            new(OBJ"charcuterie.c")->move(TO);
            tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short %^ORANGE%^r"+
                "%^WHITE%^i%^ORANGE%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^. A few "+
                "moments later, a servant arrives and places a charcuterie board "+
                "on the coffee table.%^RESET%^");
            tell_room(ETP,"BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^gives the "+
                "bell a short %^ORANGE%^r%^WHITE%^i%^ORANGE%^n%^RESET%^%^ORANGE%^"+
                "g%^BOLD%^%^BLACK%^. A few moments later, a servant arrives and "+
                "places a charcuterie board on the coffee table.%^RESET%^",TP);
            tell_object(TP,"\n%^RESET%^You can %^BOLD%^dismiss charcuterie %^RESET%^"+
                "when you are finished with it.");
            return 1;
            break;
        case "gold bell":
            new(OBJ"charcuterie.c")->move(TO);
            tell_object(TP,"%^BOLD%^%^BLACK%^You give the bell a short %^ORANGE%^r"+
                "%^WHITE%^i%^ORANGE%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^. A few "+
                "moments later, a servant arrives and places a charcuterie board "+
                "on the coffee table.%^RESET%^");
            tell_room(ETP,"BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^gives the "+
                "bell a short %^ORANGE%^r%^WHITE%^i%^ORANGE%^n%^RESET%^%^ORANGE%^"+
                "g%^BOLD%^%^BLACK%^. A few moments later, a servant arrives and "+
                "places a charcuterie board on the coffee table.%^RESET%^",TP);
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

