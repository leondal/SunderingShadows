#include <std.h>
#include <daemons.h>

inherit ROOM;


void create()
{
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_short("%^ORANGE%^M%^BOLD%^y%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^ORANGE%^r%^WHITE%^i%^ORANGE%^o%^WHITE%^u%^RESET%^s %^ORANGE%^P%^BOLD%^l%^WHITE%^a%^RESET%^t%^YELLOW%^e%^BLACK%^a%^RESET%^%^ORANGE%^u%^RESET%^");
    set_long("%^ORANGE%^M%^BOLD%^y%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^ORANGE%^r%^WHITE%^i%^ORANGE%^o%^WHITE%^u%^RESET%^s %^ORANGE%^P%^BOLD%^l%^WHITE%^a%^RESET%^t%^YELLOW%^e%^BLACK%^a%^RESET%^%^ORANGE%^u%^RESET%^
%^ORANGE%^You stand upon a %^RED%^pl%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^ea%^RESET%^%^RED%^u %^ORANGE%^high in the mountains of Aramanth Island. This is most likely a volcanic island with this %^RED%^pl%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^ea%^RESET%^%^RED%^u %^ORANGE%^being the surviving part of the cone. The %^WHITE%^gr%^BOLD%^ou%^RESET%^nd %^ORANGE%^up here is a thick layer of fine %^WHITE%^ash %^ORANGE%^and twenty foot %^WHITE%^walls %^ORANGE%^surround this crater. You get the feeling that if you walk around enough up here, you could find something. As you gaze across the island from here, you notice the only mountain higher is the one to the northeast. The ash has been disturbed here recently.%^BOLD%^%^BLACK%^");
    set_listen("default", "The waves crashing against the beach far below carriesover the plateau and echoes off the walls.");
    set_exits(([
        "north" : "/d/islands/common/aramanth/room8",
        "west" : "/d/islands/common/aramanth/room6",
        "east" : "/d/islands/common/aramanth/room12",
    ]));
    set_items(([
        "walls" : "They are tall formations of natural rock that surround the crater.",
        "ground" : "It is coated in a thick, black, crystalized ash.",
        "ash" : "The ash is a finely granulated crystaline powder.  It glistens oddly in the light.  There are numerous footprints here.",
        "disc" : "It is a highly reflective disc with north, south, east, and west marked upon it's face.",
        "disk" : "It is a highly reflective disc with north, south, east, and west marked upon it's face.",
        "plaque" : "It is a brass plaque set into the monument.",
        "footprints" : "They all converge on a single spot and then never lead away.  You are standing at that very spot.",
        "plateau" : "It is a volcanic crater high above sea level.  Four tall obelisks are placed around the perimeter.",
    ]));

    set_pre_exit_functions( ({"north"}), ({"earwig_pit"}) );
    set_pre_exit_functions( ({"south"}), ({"earwig_pit"}) );
    set_pre_exit_functions( ({"west"}), ({"earwig_pit"}) );
    set_pre_exit_functions( ({"east"}), ({"earwig_pit"}) );
}


int earwig_pit()
{
    if(present("earwig scorpion")) 
    {
        write("The Earwig Scorpion has you trapped!");
        return 0;
    }
    else return 1;
}


void init() 
{
    ::init();
    do_random_encounters(({"/d/attaya/mon/solstice"}),10,1);
    add_action("say", "say");
    add_action("push", "push");
}


int say(string str)
{
    str = filter_array(str, "filter_colors",FILTERS_D);
    str = lower_case(str);
    if(strsrch(str, "ashtar volkerps autarkis callista") != -1)
    {
        tell_object(TP, "You speak the names...\n""%^CYAN%^The ground begins to tremble.\n""%^BOLD%^%^BLUE%^Lightning strikes the "
            "four obelisks!\n""%^WHITE%^The disc begins to glow and you suddenly feen an intense heat!");
        tell_room(TO,TP->QCN+" mutters something under "+TP->QP+" breath.\n""%^CYAN%^The ground begins to tremble."
            "\n""%^BOLD%^%^BLUE%^Lightning strikes the four obelisks!\n""%^WHITE%^The disc begins to glow "
            "and "+TP->QCN+" is bathed in brilliant light.",TP);
        TP->move_player("/d/islands/common/aramanth/darkroom");
        tell_object(TP, "%^BOLD%^You have awaken Cruiser Tetron...  May whatever god you believe in have mercy on your soul...");
        return 1;
    }
    return 0;
}

int push(string str)
{
    if(str=="monument" || str =="disc" || str =="door")
    {
        tell_object(TP,"You push against the "+str+".");
        tell_room(TO,TP->QCN+" pushes against the "+str+".",TP);
        TP->do_damage(50);
        tell_object(TP,"%^BOLD%^Spikes fly from the ground and impale you!");
        tell_room(TO, "%^BOLD%^Spiles fly from the ground and impale "+TP->QCN+"!",TP);
        return 1;
    }
    return 0;
}

void reset()
{
    ::reset();
    if(!present("monument")) { new("/d/islands/common/obj/monument")->move(TO); }
}
