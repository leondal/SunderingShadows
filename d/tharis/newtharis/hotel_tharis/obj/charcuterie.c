// Chernobog (1/23/21)
// Tonovi Hotel

#include <std.h>
inherit OBJECT;

void create(){
    ::create();
    set_id(({ "charcuterie","charcuterie board","board" }));
    set_name("Charcuterie Board");
    set_short("%^BOLD%^%^BLACK%^An enticing %^ORANGE%^c%^RESET%^%^ORANGE%^h%^BOLD%^a"+
        "%^RESET%^%^RED%^r%^BOLD%^cu%^RESET%^%^RED%^t%^MAGENTA%^e%^BOLD%^ri%^RESET%^"+
        "%^MAGENTA%^e %^ORANGE%^board%^RESET%^");
    set_long("%^RESET%^%^CYAN%^The large %^ORANGE%^cherry wood board %^CYAN%^has "+
        "beveled edges with a shallow trench running along the border. Various %^BOLD%^"+
        "%^BLACK%^sm%^RESET%^o%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^"+
        "%^CYAN%^and %^RED%^c%^MAGENTA%^u%^RED%^re%^MAGENTA%^d %^CYAN%^slices of "+
        "%^BOLD%^%^RED%^meat %^RESET%^%^CYAN%^have been arrayed in a gentle curve on "+
        "one side of the board, mirrored by a variety of sliced and cubed %^YELLOW%^ch"+
        "%^WHITE%^e%^ORANGE%^es%^WHITE%^e%^ORANGE%^s%^RESET%^%^CYAN%^. Several "+
        "dollops of different types of %^ORANGE%^mu%^BOLD%^s%^RESET%^%^ORANGE%^ta"+
        "%^BOLD%^r%^RESET%^%^ORANGE%^d %^CYAN%^rest in the center, along with some "+
        "%^MAGENTA%^p%^BOLD%^i%^RESET%^%^MAGENTA%^ck%^BOLD%^le%^RESET%^%^MAGENTA%^d "+
        "%^BOLD%^%^WHITE%^on%^RESET%^i%^BOLD%^o%^RESET%^n%^BOLD%^s%^RESET%^%^CYAN%^, "+
        "so that one can mix several flavors. One can %^BOLD%^sample %^RESET%^%^CYAN%^"+
        "the %^BOLD%^meats %^RESET%^%^CYAN%^and %^BOLD%^cheeses %^RESET%^%^CYAN%^at "+
        "their leisure.%^RESET%^");
    set_weight(1000000);
    set("value",0);
    set_property("no animate",1);
}

void init(){
    ::init();
    add_action("sample_fun","sample");
}

void sample_fun(string str){
    if((str!="meats") && (str!="cheeses") && (str!="meat") && (str!="cheese")){
        tell_object(TP,"You could try to %^BOLD%^sample %^RESET%^the %^BOLD%^meats "+
            "%^RESET%^or %^BOLD%^cheeses%^RESET%^.");
        return 0;
    }
    switch(str){
        case "meats":
            tell_object(TP,"%^RESET%^%^MAGENTA%^The %^RED%^p%^WHITE%^r%^BOLD%^o"+
                "%^RESET%^%^RED%^sc%^WHITE%^i%^RED%^u%^WHITE%^t%^BOLD%^t%^RESET%^"+
                "%^RED%^o %^MAGENTA%^and %^RED%^p%^BOLD%^e%^RESET%^%^RED%^p%^BOLD%^"+
                "pe%^RESET%^%^RED%^r%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^i %^RESET%^"+
                "%^MAGENTA%^are delightfully salty.%^RESET%^");
            TP->add_stuffed(50000);
            break;
        case "meat":
            tell_object(TP,"%^RESET%^%^MAGENTA%^The %^RED%^p%^WHITE%^r%^BOLD%^o"+
                "%^RESET%^%^RED%^sc%^WHITE%^i%^RED%^u%^WHITE%^t%^BOLD%^t%^RESET%^"+
                "%^RED%^o %^MAGENTA%^and %^RED%^p%^BOLD%^e%^RESET%^%^RED%^p%^BOLD%^"+
                "pe%^RESET%^%^RED%^r%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^i %^RESET%^"+
                "%^MAGENTA%^are delightfully salty.%^RESET%^");
            TP->add_stuffed(50000);
            break;
        case "cheeses":
            tell_object(TP,"%^RESET%^%^MAGENTA%^The %^YELLOW%^p%^WHITE%^e%^RESET%^"+
                "%^ORANGE%^p%^BOLD%^pe%^WHITE%^r%^RESET%^%^ORANGE%^j%^BOLD%^ac"+
                "%^WHITE%^k %^RESET%^%^MAGENTA%^and %^ORANGE%^c%^BOLD%^he%^RESET%^"+
                "%^ORANGE%^d%^BOLD%^da%^RESET%^%^ORANGE%^r %^MAGENTA%^are smooth and "+
                "delicious.%^RESET%^");
            TP->add_stuffed(50000);
            break;
        case "cheese":
            tell_object(TP,"%^RESET%^%^MAGENTA%^The %^YELLOW%^p%^WHITE%^e%^RESET%^"+
                "%^ORANGE%^p%^BOLD%^pe%^WHITE%^r%^RESET%^%^ORANGE%^j%^BOLD%^ac"+
                "%^WHITE%^k %^RESET%^%^MAGENTA%^and %^ORANGE%^c%^BOLD%^he%^RESET%^"+
                "%^ORANGE%^d%^BOLD%^da%^RESET%^%^ORANGE%^r %^MAGENTA%^are smooth and "+
                "delicious.%^RESET%^");
            TP->add_stuffed(50000);
            break;
        default:
            tell_object(TP,"%^RESET%^%^MAGENTA%^You pick at a few savory pieces.%^RESET%^");
            TP->add_stuffed(50000);
            break;
    }
    return 1;
}

