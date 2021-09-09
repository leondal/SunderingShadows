// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit VAULT;

int filled;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The Grand Suite");
    set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^e G%^RESET%^%^MAGENTA%^ran%^BOLD%^%^BLACK%^d S%^RESET%^%^MAGENTA%^uit%^BOLD%^%^BLACK%^e%^RESET%^");
    set_long("The %^BOLD%^%^BLACK%^w%^RESET%^o%^BOLD%^o%^BLACK%^den fl%^RESET%^o%^BOLD%^o%^BLACK%^rs %^RESET%^of the hotel give way to smooth %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^rbl%^WHITE%^e %^RESET%^here. A large triangular %^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^tht%^WHITE%^u%^BLACK%^b %^RESET%^rests in the corner of the room, partnered by a %^BOLD%^porcelain sink %^RESET%^and %^CYAN%^mi%^BOLD%^rr%^RESET%^%^CYAN%^or%^WHITE%^. A set of %^BOLD%^towels %^RESET%^hang nearby, at the disposal of the hotel guests. \n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","There is the occasional echo of a drip of water.");
    set_items(([
        ({"sink", "mirror"}) : "The border of this oval-shaped, %^BOLD%^ivory %^RESET%^%^CYAN%^mi%^BOLD%^rr%^RESET%^%^CYAN%^or %^WHITE%^depicts two %^BOLD%^sn%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^k%^RESET%^e%^BOLD%^s %^RESET%^coiled tightly around each other, presumably engaged in the act of %^RED%^coitus%^WHITE%^. The %^CYAN%^mi%^BOLD%^rr%^RESET%^%^CYAN%^or %^WHITE%^has been suspended over a porcelain basin with elegant %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^v%^BLACK%^er h%^RESET%^a%^BOLD%^r%^BLACK%^dw%^RESET%^a%^BOLD%^%^BLACK%^r%^WHITE%^e%^RESET%^. The %^BOLD%^sink %^RESET%^is rounded and tapers to a slight stem as it reaches to the %^BOLD%^%^BLACK%^fl%^RESET%^o%^BOLD%^o%^BLACK%^r%^RESET%^.",
        "towels" : "A set of %^BOLD%^towels %^RESET%^hangs midway between the %^BOLD%^sink %^RESET%^and the %^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^tht%^WHITE%^u%^BLACK%^b%^RESET%^. They are %^BOLD%^pristine white%^RESET%^, thick and incredibly soft to the touch.%^RESET%^",
        "floor" : "The %^BOLD%^%^BLACK%^w%^RESET%^o%^BOLD%^o%^BLACK%^den fl%^RESET%^o%^BOLD%^o%^BLACK%^rs %^RESET%^of the hotel give way large tiles of %^BOLD%^polished %^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^rbl%^WHITE%^e%^RESET%^. They are %^BOLD%^%^BLACK%^ebony %^RESET%^shot through with %^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^i%^BLACK%^ns %^RESET%^of %^BOLD%^wh%^RESET%^i%^BOLD%^t%^RESET%^e.",
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        ]));
    set_exits(([
        "bedroom" : ROOMS "master_bedroom",
        "sauna" : ROOMS "sauna",
        ]));
    set_door("wooden door", ROOMS "sauna", "sauna", 0);
	set_door_description("wooden door","%^RESET%^%^ORANGE%^This is a thick wooden door, crafted entirely from cedar.%^RESET%^");
    filled = 0;
}

void init(){
    ::init();
    add_action("fill_fun","fill");
    add_action("drain_fun","drain");
    add_action("look_fun","look");
}

int look_fun(string str){
    if(str!="bathtub")
        return 0;
    if(filled){
        tell_object(TP,"%^RESET%^CYAN%^A large triangular %^BOLD%^%^WHITE%^por%^RESET%^"+
            "c%^BOLD%^el%^RESET%^a%^BOLD%^in bath%^RESET%^t%^BOLD%^ub %^RESET%^%^CYAN%^"+
            "takes up a whole corner of this bathroom, large enough to accommodate "+
            "several guests and repleat with a series of steps leading both up to the "+
            "edge and down into its depths. There are protrustions midway down that "+
            "offer a place to sit and lounge, with a ledge covered in various %^BOLD%^"+
            "%^WHITE%^so%^CYAN%^ap%^WHITE%^s%^RESET%^%^CYAN%^, %^BOLD%^%^GREEN%^b"+
            "%^ORANGE%^a%^GREEN%^lm%^RESET%^%^GREEN%^s%^CYAN%^, %^WHITE%^and %^BOLD%^"+
            "%^MAGENTA%^o%^RED%^i%^MAGENTA%^n%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^m"+
            "%^RED%^e%^MAGENTA%^n%^RESET%^%^MAGENTA%^t%^BOLD%^s%^RESET%^%^CYAN%^, but "+
            "enough empty space present for %^ORANGE%^l%^WHITE%^i%^ORANGE%^b%^BOLD%^a"+
            "%^WHITE%^t%^ORANGE%^i%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n%^RESET%^"+
            "%^ORANGE%^s %^CYAN%^to rest. A %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv"+
            "%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^t%^BOLD%^a%^RESET%^p %^CYAN%^stands "+
            "ready to the side, with simple levers available to fill and drain the "+
            "bathtub.\n\n%^BOLD%^%^BLACK%^The bathtub is full of %^MAGENTA%^r%^RED%^o"+
            "%^MAGENTA%^se s%^RED%^c%^MAGENTA%^ent%^RED%^e%^MAGENTA%^d %^CYAN%^w"+
            "%^WHITE%^a%^CYAN%^ter%^BLACK%^.%^RESET%^");
        tell_room(ETP,"%^RESET%^"+TP->QCN+" %^RESET%^looks over the bathtub.",TP);
        return 1;
    }
    else{
        tell_object(TP,"%^RESET%^%^CYAN%^A large triangular %^BOLD%^%^WHITE%^por"+
            "%^RESET%^c%^BOLD%^el%^RESET%^a%^BOLD%^in bath%^RESET%^t%^BOLD%^ub "+
            "%^RESET%^%^CYAN%^takes up a whole corner of this bathroom, large enough "+
            "to accommodate several guests and repleat with a series of steps leading "+
            "both up to the edge and down into its depths. There are protrustions "+
            "midway down that offer a place to sit and lounge, with a ledge covered "+
            "in various %^BOLD%^%^WHITE%^so%^CYAN%^ap%^WHITE%^s%^RESET%^%^CYAN%^, "+
            "%^BOLD%^%^GREEN%^b%^ORANGE%^a%^GREEN%^lm%^RESET%^%^GREEN%^s%^CYAN%^, "+
            "%^WHITE%^and %^BOLD%^%^MAGENTA%^o%^RED%^i%^MAGENTA%^n%^RESET%^%^MAGENTA%^"+
            "t%^BOLD%^%^WHITE%^m%^RED%^e%^MAGENTA%^n%^RESET%^%^MAGENTA%^t%^BOLD%^s"+
            "%^RESET%^%^CYAN%^, but enough empty space present for %^ORANGE%^l"+
            "%^WHITE%^i%^ORANGE%^b%^BOLD%^a%^WHITE%^t%^ORANGE%^i%^RESET%^%^ORANGE%^o"+
            "%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^s %^CYAN%^to rest. A %^BOLD%^"+
            "%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^t"+
            "%^BOLD%^a%^RESET%^p %^CYAN%^stands ready to the side, with simple levers "+
            "available to fill and drain the bathtub.\n\n%^BOLD%^%^BLACK%^The bathtub "+
            "is completely empty.%^RESET%^");
        tell_room(ETP,"%^RESET%^"+TP->QCN+" %^RESET%^looks over the bathtub.",TP);
        return 1;
    }
}

int fill_fun(string str){
    if((str!="bath") && (str!="bathtub")){
        write("You could try to fill the bathtub.");
        return 1;
    }
    if(filled){
        write("The bathtub is already full of warm water.");
        return 1;
    }
    else{
        tell_object(TP,"%^BOLD%^%^BLACK%^You turn the %^RESET%^t%^BOLD%^a%^RESET%^p"+
            "%^BOLD%^%^BLACK%^, letting the bathtub slowly fill with %^MAGENTA%^r"+
            "%^RED%^o%^MAGENTA%^se%^RED%^-%^MAGENTA%^sc%^RED%^e%^MAGENTA%^nt%^RED%^e"+
            "%^MAGENTA%^d %^CYAN%^w%^WHITE%^a%^CYAN%^ter%^BLACK%^.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^turns the "+
            "%^RESET%^t%^BOLD%^a%^RESET%^p%^BOLD%^%^BLACK%^, letting the bathtub "+
            "slowly fill with %^MAGENTA%^r%^RED%^o%^MAGENTA%^se%^RED%^-%^MAGENTA%^sc"+
            "%^RED%^e%^MAGENTA%^nt%^RED%^e%^MAGENTA%^d %^CYAN%^w%^WHITE%^a%^CYAN%^ter"+
            "%^BLACK%^.%^RESET%^",TP);
        filled = 1;
        return 1;
    }
}

int drain_fun(string str){
    if((str!="bath") && (str!="bathtub")){
        write("You could try to drain the bathtub.");
        return 1;
    }
    if(!filled){
        write("The bathtub is already completely empty.");
        return 1;
    }
    else{
        tell_object(TP,"%^BOLD%^%^BLACK%^You pull a small l%^RESET%^e%^BOLD%^v"+
            "%^RESET%^e%^BOLD%^%^BLACK%^r on the side, and the %^CYAN%^w%^WHITE%^a"+
            "%^CYAN%^ter %^BLACK%^flows quickly down the drain.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^pulls a small l"+
            "%^RESET%^e%^BOLD%^v%^RESET%^e%^BOLD%^%^BLACK%^r on the side, and the "+
            "%^CYAN%^w%^WHITE%^a%^CYAN%^ter %^BLACK%^flows quickly down the drain"+
            ".%^RESET%^",TP);
        filled = 0;
        return 1;
    }
}