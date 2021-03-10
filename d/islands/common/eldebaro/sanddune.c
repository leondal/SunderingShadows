#include <std.h>
#include <daemons.h>
#include "area_stuff.h"
inherit CROOM;
int which_rune;

void populate_area()
{
    if(base_name(TO) != ELDUNE) 
    { 
        switch(random(11)) 
        {
            case 0..3:
                set_monsters(({}), ({}));
                break;
            case 4..6:
                set_monsters( ({ELMON+"desert_ogre", ELMON+"desert_ogre_shaman"}), ({2 + random(2), 1 + random(2)}) );
                break;
            case 7..10:
                set_monsters( ({ELMON+"desert_ogre"}), ({2 + random(3)}) );
                break;      			
        }
        set_repop(35);   
    }    
}


void check_rune_placement()
{
    string targ_array, rune_timer, MY_PLACE, *possible_rooms, *tmp;
    int TIMER;
    object MyOb;
    
    if(!objectp(TO)) return;
    if(!intp(which_rune)) return;
    if(which_rune < 0 || which_rune > 4) return;
    switch(which_rune)
    {
        case 1:
            targ_array = "1_eldebaro_rune";
            rune_timer = "1_eldebaro_rune_delay";
            tmp = SAVE_D->query_array(rune_timer);
            if(!sizeof(tmp)) TIMER = 0;
            else TIMER = to_int(tmp[0]);
            //tell_object("/std/user#1536569", "it is returning here....");
            if(TIMER > time()) return;
            possible_rooms = get_dir(ELROOMS+"sand_dune1*.c");
            break;
        case 2:
            targ_array = "2_eldebaro_rune";
            rune_timer = "2_eldebaro_rune_delay";
            tmp = SAVE_D->query_array(rune_timer);
            if(!sizeof(tmp)) TIMER = 0;
            else TIMER = to_int(tmp[0]);
            if(TIMER > time()) return;
            possible_rooms = get_dir(ELROOMS+"sand_dune2*.c");
            break;
        case 3:
            targ_array = "3_eldebaro_rune";
            rune_timer = "3_eldebaro_rune_delay";
            tmp = SAVE_D->query_array(rune_timer);
            if(!sizeof(tmp)) TIMER = 0;
            else TIMER = to_int(tmp[0]);
            if(TIMER > time()) return;
            possible_rooms = get_dir(ELROOMS+"sand_dune3*.c");
            break;
        case 4:
            targ_array = "4_eldebaro_rune";
            rune_timer = "4_eldebaro_rune_delay";
            tmp = SAVE_D->query_array(rune_timer);
            if(!sizeof(tmp)) TIMER = 0;
            else TIMER = to_int(tmp[0]);
            if(TIMER > time()) return;
            possible_rooms = get_dir(ELROOMS+"sand_dune4*.c");
            break;
    }
    //tell_object("/std/user#1536569", "possible rooms = "+identify(possible_rooms));
    //possible_rooms = get_dir(ELROOMS+"*.c");
    //tell_object("/std/user#1536569", "possible rooms = "+identify(possible_rooms));
    tmp = SAVE_D->query_array(targ_array);
    if(!sizeof(tmp)) 
    {
        if(!sizeof(possible_rooms)) return;
        MY_PLACE = ELROOMS + possible_rooms[random(sizeof(possible_rooms))];
        SAVE_D->delete_array(targ_array);
        SAVE_D->set_value(targ_array, MY_PLACE);
    }
    else MY_PLACE = tmp[0];
    if(base_name(TO) != MY_PLACE && base_name(TO)+".c" != MY_PLACE) return;
    if(present("eldebarodarkrune", TO)) return;
    MyOb = new(ELOB+"runestone");
    MyOb->set_which_rune(which_rune);
    MyOb->move(TO);    
}

varargs void dreadhorn_arrives(int step)
{
    if(!objectp(TO)) return;
    if(!step) 
    {
        tell_object(TO, "%^BOLD%^%^RED%^A massive portal opens in the sky right above you!! You see %^BOLD%^"+
        "%^BLACK%^ebon hooves%^BOLD%^%^RED%^ dangling through it!%^RESET%^");
        step++;
        call_out("dreadhorn_arrives", 10, step);
        return;
    }
    if(step)
    {
        tell_object(TO, "%^BOLD%^%^RED%^With a mighty %^BOLD%^%^BLACK%^ROAR%^BOLD%^%^RED%^ a massive "+
        "minotaur, the %^BOLD%^%^BLACK%^D%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^e%^BOLD%^%^RED%^a%^BOLD%^%^BLACK%^d"+
        "%^BOLD%^%^RED%^h%^BOLD%^%^BLACK%^o%^BOLD%^%^RED%^r%^BOLD%^%^RED%^n "+
        "falls out of the portal and it closes instantly behind him!%^RESET%^");
        new(ELMON+"dreadhorn")->move(TO);
        return;
    }    
}

string cloud_desc()
{
    string current_location, ret;
    current_location = RUNEPLACE->get_current_location();
    ret = "%^BOLD%^%^BLACK%^The clouds "+
        "that hang over the island look nightmarish. Simply looking up at them you get a terribly feeling in "+
        "the pit of your stomach. It is even worse from this vantage point. You are able to make out two "+
        "violet colored faces, one of a male and the other of a female that appear to be continually "+
        "disappearing and reappearing in the clouds. It seems like something is keeping the storm "+
        "that is surely coming at bay, at least for the time being, but you are "+
        "unsure of what or for how long that will last.%^RESET%^";
    
    if(stringp(current_location))
    {
        if(current_location != "" && current_location != "NIL")
        {
            ret += "%^BOLD%^%^BLACK%^ Bolts of %^BOLD%^%^YELLOW%^lightning%^BOLD%^%^BLACK%^"+
            " zap toward "+current_location+"!%^RESET%^";
        }
    }
    return ret;
}

void create()
{
    populate_area();
    ::create();
	set_property("light",2);
	set_property("indoors",0);
    set_climate("desert");
    set_property("no teleport", 1);
    set_property("scry proof", 1);
    set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
    set_name("Atop a vast sand dune");
    set_short("%^RESET%^%^ORANGE%^Atop a vast s%^BOLD%^a%^RESET%^%^ORANGE%^nd%^BOLD%^u%^RESET%^%^ORANGE%^n%^BOLD%^e%^RESET%^");
    
    
    set_long("%^RESET%^%^ORANGE%^You are traveling atop a large s%^BOLD%^a"+
    "%^RESET%^%^ORANGE%^nd d%^BOLD%^u%^RESET%^%^ORANGE%^n%^BOLD%^e%^RESET%^%^ORANGE%^. It stretches out all around "+
    "you and is difficult to traverse. The wind here is even more "+
    "v%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
    "n%^BOLD%^%^MAGENTA%^t%^RESET%^%^ORANGE%^, if that were possible. The sand up here has been dried out by "+
    "it. It is much finer and is blown "+
    "around ch%^BOLD%^%^BLACK%^ao%^BOLD%^%^WHITE%^tica%^RESET%^%^ORANGE%^lly which "+
    "makes it difficult to see very far in front of you at all. You are afforded a spectacular view of "+
    "the %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^"+
    "l%^BOLD%^%^BLACK%^y%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^"
    " cl%^BOLD%^%^WHITE%^ou%^RESET%^%^ORANGE%^ds up here and it is not hopeful. You believe now, more than "+
    "ever, that something is controlling the wind. You can actually make out faces in the cl%^BOLD%^%^WHITE%^ou%^RESET%^%^ORANGE%^ds"+
    " from up here. It looks like two faces disappearing and reappearing constantly, both of them a deep "+
    "%^RESET%^%^MAGENTA%^violet%^RESET%^%^ORANGE%^ hue, one appears to be the face of a male and the other of "+
    "a female.%^RESET%^");

    set_listen("default", "%^CYAN%^\nThe loud slapping of water echoes all around you "
        "here, as the winds continue to increase in ferocity.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA tranquil odor from the sea assaults you and mixes "
        "with something else that you are not quite able to discern.%^RESET%^");

    set_items(([
               
        ({"dune", "vast sand dune", "sand dune", "sand", "fine sand", "dry sand"}) : "%^RESET%^%^ORANGE%^"+
        "This sand dune is large, much larger than what you thought from down below. It stretches out all "+
        "around you. The wind is much more violet up here and has dried out the sand. The sand is much "+
        "finer and blows about chaotically in the wind, making see in front of you much more difficult.%^RESET%^", 
        
        ({"storm", "clouds", "storm clouds", "heavy storm clouds"}) : (:TO, "cloud_desc":),

        ({"faces", "male face", "female face", "face"}) : "%^RESET%^%^MAGENTA%^These faces appear to be "+
        "continually disappearing and reappearing in the clouds overhead. One of them is obviously feminine and the "+
        "other masculine. You can discern very little about them, but you are able to tell that they are massive, "+
        "perhaps they belong to a giant. Each has very intelligent deep purple eyes and hair that is almost "+
        "%^BOLD%^%^CYAN%^blue%^RESET%^%^MAGENTA%^ in appearance.",        
    ]));

    check_rune_placement();
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
    RUNEPLACE->place_rune(TO);
    check_rune_placement();
    populate_area();
}