// Chernobog (1/5/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Hotel Restaurant");
    set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e"+
        "%^BOLD%^l R%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^staura%^RESET%^%^ORANGE%^n"+
        "%^BOLD%^t%^RESET%^");
    set_long("%^RESET%^This dining room is small and intimate. A half dozen circular "+
        "%^ORANGE%^tables %^WHITE%^take up the center of the room over a bare "+
        "%^ORANGE%^wo%^RED%^o%^ORANGE%^de%^RED%^n %^ORANGE%^f%^RED%^l%^ORANGE%^oor"+
        "%^WHITE%^, while a row of %^ORANGE%^booths %^WHITE%^take up the far wall.  "+
        "The tables and booths have been decked out in %^MAGENTA%^dark wine livery"+
        "%^WHITE%^. Potted %^GREEN%^p%^BOLD%^l%^RESET%^%^ORANGE%^a%^GREEN%^n%^BOLD%^t"+
        "%^RESET%^%^GREEN%^s %^WHITE%^in the corners of the room smooth out the "+
        "atmosphere, while a few muted %^BOLD%^gl%^RESET%^o%^BOLD%^ws%^ORANGE%^t"+
        "%^WHITE%^o%^RESET%^n%^BOLD%^es %^RESET%^in the ceiling provide the ambient "+
        "lighting. An archway leads back into the %^YELLOW%^m%^RESET%^%^ORANGE%^a"+
        "%^BOLD%^%^BLACK%^i%^ORANGE%^n h%^BLACK%^a%^RESET%^%^ORANGE%^l%^BOLD%^l "+
        "%^RESET%^of the hotel. A few menus have been left out on the tables.\n");
    set_smell("default","The aroma of gourmet cooking fills the air.");
    set_listen("default","You can hear the soft murmur of other patrons' conversations.");
    set_items(([
        ({"wall", "walls"}) : "%^RESET%^%^CYAN%^Uneven %^BOLD%^%^BLACK%^stones "+
            "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^WHITE%^"+
            "d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^"+
            "%^BLACK%^y %^RESET%^%^CYAN%^comprise these walls. The black stone is a "+
            "common element of Tonovi construction, mined from the north.%^RESET%^",
        "floor" : "%^RESET%^%^CYAN%^The floors have been left bare, with the %^ORANGE%^"+
            "r%^RED%^i%^ORANGE%^ch mah%^RED%^o%^ORANGE%^gan%^RED%^y %^CYAN%^polished "+
            "and buffed to a brilliant %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^i%^RESET%^n"+
            "%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^.%^RESET%^",
        ({"tables", "chairs"}) : "%^RESET%^%^CYAN%^The tables have been adorned with "+
            "%^MAGENTA%^dark wine tablecloths%^CYAN%^, and feature a simple centerpiece"+
            ". Fine %^BOLD%^%^WHITE%^plates %^RESET%^%^CYAN%^have been placed before each"+
            " seat, with a selection of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e"+
            "%^BOLD%^%^BLACK%^r c%^RESET%^u%^BOLD%^tle%^RESET%^r%^BOLD%^%^BLACK%^y "+
            "%^RESET%^%^CYAN%^laying on folded %^YELLOW%^b%^RESET%^%^ORANGE%^l%^BOLD%^"+
            "%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^k n%^RESET%^%^ORANGE%^a%^BOLD%^"+
            "%^BLACK%^pki%^RESET%^%^ORANGE%^n%^BOLD%^s %^RESET%^%^CYAN%^with golden "+
            "borders. The chairs are tall backed and exquisitely carved from %^BOLD%^"+
            "%^WHITE%^vi%^RESET%^b%^BOLD%^ra%^RESET%^n%^BOLD%^t b%^RESET%^i%^BOLD%^rc"+
            "%^RESET%^h%^CYAN%^, delicately contrasting with the %^MAGENTA%^cushions "+
            "%^CYAN%^in that same %^MAGENTA%^dark wine hue%^CYAN%^.%^RESET%^",
        "centerpiece" : "%^RESET%^%^CYAN%^Three %^BOLD%^%^BLACK%^black candles "+
            "%^RESET%^%^CYAN%^of varying height are gathered at the center of the "+
            "table. Flowery %^YELLOW%^g%^WHITE%^o%^ORANGE%^l%^RESET%^%^ORANGE%^d "+
            "%^BOLD%^le%^RESET%^%^ORANGE%^a%^BOLD%^f %^RESET%^%^CYAN%^designs trace "+
            "their way up the sides of each candle.%^RESET%^",
        "booths" : "%^RESET%^%^CYAN%^Several booths line the far wall. They are "+
            "%^MAGENTA%^upholstered %^CYAN%^in a %^MAGENTA%^dark wine fabric %^CYAN%^"+
            "and nicely padded for comfort. The %^BOLD%^%^WHITE%^vi%^RESET%^b%^BOLD%^"+
            "ra%^RESET%^n%^BOLD%^t b%^RESET%^i%^BOLD%^rc%^RESET%^h %^CYAN%^tabletop "+
            "has been left bare, with %^BOLD%^%^WHITE%^fine plates %^RESET%^%^CYAN%^"+
            "and %^BOLD%^%^BLACK%^c%^RESET%^u%^BOLD%^tle%^RESET%^r%^BOLD%^%^BLACK%^y "+
            "%^RESET%^%^CYAN%^set out on folded %^YELLOW%^b%^RESET%^%^ORANGE%^l%^BOLD%^"+
            "%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^k n%^RESET%^%^ORANGE%^a%^BOLD%^"+
            "%^BLACK%^pki%^RESET%^%^ORANGE%^n%^BOLD%^s%^RESET%^%^CYAN%^. A simple "+
            "centerpiece is featured to add to the decor.%^RESET%^",
        "piano" : "%^RESET%^%^CYAN%^A %^BOLD%^%^BLACK%^grand piano %^RESET%^%^CYAN%^"+
            "sits in the corner of the room. The lid has been lifted, held in place "+
            "by a metal spacer to reveal the intricate workings within. %^BOLD%^"+
            "%^WHITE%^Iv%^RESET%^o%^BOLD%^ry %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^"+
            "ebo%^RESET%^n%^BOLD%^%^BLACK%^y k%^WHITE%^e%^BLACK%^y%^WHITE%^s %^RESET%^"+
            "%^CYAN%^sit at the ready, facing off against a simple %^BOLD%^%^BLACK%^"+
            "black stool%^RESET%^%^CYAN%^. A few sheets of music lean against the "+
            "front of the piano.%^RESET%^",
        "glowstones" : "%^RESET%^%^CYAN%^These are small %^BOLD%^g%^WHITE%^l%^CYAN%^"+
            "ass o%^WHITE%^r%^CYAN%^bs %^RESET%^%^CYAN%^set into the ceiling. A simple "+
            "enchantment allows them to %^WHITE%^g%^BOLD%^l%^ORANGE%^o%^WHITE%^w "+
            "%^RESET%^s%^BOLD%^o%^ORANGE%^f%^WHITE%^t%^RESET%^l%^BOLD%^y %^RESET%^"+
            "%^CYAN%^and provide a relaxing illumination.%^RESET%^",
        "plants" : "%^RESET%^%^CYAN%^Large %^ORANGE%^ea%^RED%^r%^ORANGE%^the%^RED%^n "+
            "%^ORANGE%^u%^RED%^r%^ORANGE%^ns %^CYAN%^sit in the corners of the room, "+
            "supporting broad and magnificent %^GREEN%^ca%^BOLD%^%^WHITE%^l%^RESET%^"+
            "%^GREEN%^at%^BOLD%^%^WHITE%^h%^RESET%^%^GREEN%^ea p%^BOLD%^l%^RESET%^"+
            "%^ORANGE%^a%^GREEN%^n%^BOLD%^t%^RESET%^%^GREEN%^s%^CYAN%^. The broad "+
            "leaves are a %^GREEN%^deep green %^CYAN%^with vibrant %^WHITE%^w%^BOLD%^"+
            "hi%^RESET%^t%^BOLD%^e %^RESET%^%^CYAN%^stripes along the width."+
            "%^RESET%^",
        ]));
    set_exits(([
        "hall" : ROOMS "hall",
        ]));
}

void reset(){
    ::reset();
    if(!present("waiter")) new(MON "kean")->move(TO);
}

void init(){
    ::init();
    add_action("read_fun","read");
}

int read_fun(string str){
    object ob;
    
    if(str!="menu")
        return 0;
    if(!present("waiter")){
        write("What is the point, there isn't a waiter here to take your order?");
        return 1;
    }
    
    ob=present("waiter");
    
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

