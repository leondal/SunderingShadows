// Chernobog (9/6/21)
// Tharis Hotel

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
    set_short("%^MAGENTA%^H%^BOLD%^%^BLACK%^ote%^RESET%^%^MAGENTA%^l R%^BOLD%^%^BLACK%^estauran%^RESET%^%^MAGENTA%^t%^WHITE%^");
    set_long("%^BOLD%^%^BLACK%^This dining room is small and intimate. A half dozen circular tables take up the center of the room, while a row of %^RESET%^%^MAGENTA%^booths %^BOLD%^%^BLACK%^occupies the far wall. The tables and booths have been decked out in %^RESET%^%^MAGENTA%^deep violet %^BOLD%^%^BLACK%^livery. %^WHITE%^Potted %^BLACK%^pl%^RESET%^%^GREEN%^a%^MAGENTA%^n%^BOLD%^%^BLACK%^ts rest in the corners of the room and a few m%^RESET%^u%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^d %^MAGENTA%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^wst%^RESET%^%^MAGENTA%^o%^BOLD%^n%^RESET%^%^MAGENTA%^e%^BOLD%^s %^BLACK%^in the ceiling provide %^MAGENTA%^amb%^RESET%^%^MAGENTA%^i%^WHITE%^e%^BOLD%^%^MAGENTA%^nt l%^RESET%^%^MAGENTA%^i%^WHITE%^g%^BOLD%^h%^MAGENTA%^t%^RESET%^%^MAGENTA%^i%^BOLD%^ng%^BLACK%^. An archway leads back into the main hall of the hotel. A beautiful piano occupies one corner of the room. A few %^WHITE%^menus %^BLACK%^have been left out on the tables.%^RESET%^\n");
    set_smell("default","The aroma of gourmet cooking fills the air.");
    set_listen("default","You can hear the soft murmur of other patrons' conversations.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        "floor" : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^.",
        ({"tables", "chairs"}) : "%^RESET%^The %^BOLD%^%^BLACK%^tables %^RESET%^have been adorned with %^MAGENTA%^deep violet %^WHITE%^tablecloths, and feature a simple %^BOLD%^centerpiece%^RESET%^. Fine %^BOLD%^pl%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^s %^RESET%^have been placed before each seat, with a selection of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^BLACK%^v%^WHITE%^e%^BLACK%^r c%^RESET%^u%^BOLD%^t%^BLACK%^l%^RESET%^e%^BOLD%^r%^BLACK%^y %^RESET%^laying on folded %^BOLD%^%^BLACK%^black cloth napkins %^RESET%^with %^BOLD%^white borders%^RESET%^. The %^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^hair%^BOLD%^%^BLACK%^s %^RESET%^are tall backed and exquisitely carved from %^BOLD%^%^BLACK%^ebony wood%^RESET%^, delicately %^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ntr%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^st%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ng %^RESET%^with the cushions in the same %^MAGENTA%^dark violet hue %^WHITE%^as the %^MAGENTA%^tablecloths%^WHITE%^.",
        "centerpiece" : "Three %^BOLD%^iv%^RESET%^o%^BOLD%^ry sk%^RESET%^u%^BOLD%^ll%^RESET%^-shaped candle holders with dainty %^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^ts %^WHITE%^resting in their %^BOLD%^%^BLACK%^eye sockets %^RESET%^serve as the table %^BOLD%^c%^RESET%^e%^BOLD%^nt%^RESET%^e%^BOLD%^rp%^RESET%^%^MAGENTA%^i%^WHITE%^e%^BOLD%^c%^RESET%^e%^BOLD%^s%^RESET%^. %^BOLD%^%^BLACK%^Black candles %^RESET%^rest within the holders, their %^MAGENTA%^v%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t fl%^BOLD%^a%^RESET%^%^MAGENTA%^m%^BOLD%^e%^RESET%^%^MAGENTA%^s %^WHITE%^casting %^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^e sh%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^d%^MAGENTA%^o%^BLACK%^ws %^RESET%^across the %^BOLD%^%^BLACK%^tables%^RESET%^.",
        "booths" : "%^RESET%^Several %^MAGENTA%^booths %^WHITE%^line the far wall. They are upholstered in a %^MAGENTA%^deep violet velvet %^WHITE%^and nicely padded for comfort. The %^BOLD%^%^BLACK%^ebony wood %^RESET%^tabletop has been left bare, with %^BOLD%^f%^RESET%^i%^BOLD%^n%^RESET%^e %^BOLD%^pl%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^s %^RESET%^and %^BOLD%^%^BLACK%^c%^RESET%^ut%^BOLD%^l%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^set out on folded %^BOLD%^%^BLACK%^black cloth napkins. %^RESET%^A simple %^BOLD%^c%^RESET%^e%^BOLD%^nt%^RESET%^e%^BOLD%^rp%^RESET%^%^MAGENTA%^i%^WHITE%^e%^BOLD%^ce %^RESET%^is featured to add to the ambiance.",
        "piano" : "%^RESET%^A %^BOLD%^%^BLACK%^grand piano %^RESET%^sits in the corner of the room. The lid has been lifted, held in place by a %^BOLD%^%^BLACK%^metal spacer %^RESET%^to reveal the intricate workings within. %^BOLD%^Ivory %^RESET%^and %^BOLD%^%^BLACK%^ebony %^RESET%^k%^BOLD%^e%^BLACK%^y%^RESET%^s sit at the ready, facing off against a simple %^BOLD%^%^BLACK%^black stool. %^RESET%^A few %^BOLD%^sheets %^RESET%^of music lean against the front of the %^BOLD%^%^BLACK%^piano%^RESET%^.",
        "glowstones" : "These are small %^BOLD%^%^MAGENTA%^gl%^RESET%^%^MAGENTA%^a%^BOLD%^ss %^RESET%^%^MAGENTA%^o%^BOLD%^rbs %^RESET%^set into the ceiling. A simple enchantment allows them to %^BOLD%^%^MAGENTA%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^w s%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^t%^RESET%^%^MAGENTA%^l%^BOLD%^y%^RESET%^, casting the features and patrons of the restaurant in a soft %^BOLD%^%^MAGENTA%^v%^RESET%^%^MAGENTA%^io%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^t l%^RESET%^i%^BOLD%^g%^RESET%^%^MAGENTA%^h%^BOLD%^t%^RESET%^.",
        "plants" : "Large %^BOLD%^wh%^RESET%^i%^BOLD%^t%^RESET%^e %^BOLD%^c%^RESET%^e%^BOLD%^r%^RESET%^a%^BOLD%^m%^RESET%^i%^BOLD%^c p%^RESET%^o%^BOLD%^ts %^RESET%^sit in the corners of the room, containing magnificent %^GREEN%^e%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^ph%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^nt %^RESET%^%^GREEN%^e%^MAGENTA%^a%^BOLD%^%^BLACK%^r pl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^nts %^RESET%^in an exotic %^BOLD%^%^BLACK%^black hue%^RESET%^, their broad %^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^e%^GREEN%^a%^BOLD%^%^MAGENTA%^v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s %^RESET%^laced with %^GREEN%^v%^MAGENTA%^e%^BOLD%^i%^RESET%^%^MAGENTA%^n%^GREEN%^s %^WHITE%^of %^GREEN%^green %^WHITE%^and %^MAGENTA%^violet%^WHITE%^.",
        ]));
    set_exits(([
        "hall" : ROOMS "hall",
        ]));
}

void reset(){
    ::reset();
    if(!present("waiter")) new(MON "connor")->move(TO);
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

