// Chernobog (1/23/21)
// Tonovi Hotel

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
    set_name("The Duchal Suite");
    set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^h%^BOLD%^e D%^RESET%^%^ORANGE%^u%^BOLD%^"+
        "%^BLACK%^ch%^RESET%^%^ORANGE%^a%^BOLD%^l S%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^"+
        "i%^RESET%^%^ORANGE%^t%^BOLD%^e%^RESET%^");
    set_long("%^RESET%^The wooden floors of the hotel give way to %^BOLD%^%^BLACK%^s"+
        "%^RESET%^%^ORANGE%^m%^BOLD%^o%^BLACK%^ot%^RESET%^%^ORANGE%^h %^BOLD%^"+
        "%^BLACK%^mar%^ORANGE%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e %^RESET%^here. "+
        "A large triangular %^BOLD%^bat%^RESET%^h%^BOLD%^tub %^RESET%^lurks in the "+
        "corner of the room, partnered by a %^BOLD%^po%^RESET%^r%^BOLD%^cel%^RESET%^a"+
        "%^BOLD%^in si%^RESET%^n%^BOLD%^k %^RESET%^and %^BOLD%^%^BLACK%^m%^RESET%^i"+
        "%^BOLD%^rr%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^. A set of %^YELLOW%^t"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^we%^RESET%^%^ORANGE%^l%^BOLD%^s "+
        "%^RESET%^hang nearby, at the disposal of the hotel guests.\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","There is the occasional echo of a drip of water.");
    set_items(([
        ({"sink", "mirror"}) : "%^RESET%^CYAN%^The %^BOLD%^%^BLACK%^m%^RESET%^i%^BOLD%^r"+
            "r%^RESET%^o%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^is oblong and oval, "+
            "bordered in a flowery %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^d l%^WHITE%^e"+
            "%^ORANGE%^a%^RESET%^%^ORANGE%^f%^CYAN%^. It has been suspended over a "+
            "%^BOLD%^%^WHITE%^po%^RESET%^r%^BOLD%^cel%^RESET%^a%^BOLD%^in ba%^RESET%^s"+
            "%^BOLD%^in%^RESET%^%^CYAN%^, with a silver tap present. The sink is "+
            "rounded and tapers to a slight stem as it reaches to the %^BOLD%^"+
            "%^BLACK%^f%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^o%^ORANGE%^o%^BLACK%^r"+
            "%^RESET%^%^CYAN%^.%^RESET%^",
        "towels" : "%^RESET%^%^CYAN%^A set of %^YELLOW%^t%^RESET%^%^ORANGE%^o%^BOLD%^"+
            "%^BLACK%^we%^RESET%^%^ORANGE%^l%^BOLD%^s %^RESET%^%^CYAN%^hangs midway "+
            "between the sink and the bathtub. They are %^BOLD%^%^BLACK%^black "+
            "%^RESET%^%^CYAN%^with %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^"+
            "%^ORANGE%^n %^CYAN%^accents, a common color scheme within the hotel."+
            "%^RESET%^",
        "floor" : "%^RESET%^%^CYAN%^The %^ORANGE%^wooden floors %^CYAN%^of the hotel "+
            "give way to %^BOLD%^%^BLACK%^ma%^RESET%^%^ORANGE%^r%^BOLD%^b%^BLACK%^le "+
            "%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^l%^BOLD%^e"+
            "%^BLACK%^s%^RESET%^%^CYAN%^. They are %^BOLD%^%^BLACK%^ebon black"+
            "%^RESET%^%^CYAN%^, and the veins twisting their way along their cool "+
            "surface are %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^"+
            "n %^CYAN%^threads.%^RESET%^",
        ]));
    set_exits(([
        "bedroom" : ROOMS "master_bedroom",
        "sauna" : ROOMS "sauna",
        ]));
    set_door("wooden door", ROOMS "sauna", "sauna", 0);
	set_door_description("wooden door","%^RESET%^%^CYAN%^This is a simple %^ORANGE%^"+
        "wooden door%^CYAN%^, crafted from %^ORANGE%^oaken planks%^CYAN%^.%^RESET%^");
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