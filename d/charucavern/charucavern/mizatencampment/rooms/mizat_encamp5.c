#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit ROOM;
string powered_by, destination, power_file;

void create()
{ 
    ::create();
    set_name("A massive well-lit unfinished cavern chamber");
    set_short("%^BOLD%^%^WHITE%^A massive well-lit unfinished cavern chamber%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This massive chamber has been very carefully hollowed out from "+
    "%^BOLD%^%^BLACK%^gray stone%^BOLD%^%^WHITE%^. However, it appears that the excavations abruptly stopped. "+
    "There are debris of %^BOLD%^%^BLACK%^dust%^BOLD%^%^WHITE%^ and %^BOLD%^%^BLACK%^rock%^BOLD%^%^WHITE%^ "+
    "scattered all through the area, but what you most notice about this chamber is that jutting out from "+
    "the half-finished northern wall is a strange-looking %^BLUE%^archway%^BOLD%^%^WHITE%^. Next to the "+
    "%^BLUE%^archway%^BOLD%^%^WHITE%^ is a %^BOLD%^%^CYAN%^glowing receptacle%^BOLD%^%^WHITE%^. "+
    "The receptacle and the archway both appear ancient and long forgotten, until the recent "+
    "excavations %^RESET%^%^ORANGE%^unearthed%^BOLD%^%^WHITE%^ them. Floating effortlessly around "+
    "the ceiling of the chamber are %^BOLD%^%^CYAN%^orbs%^BOLD%^%^WHITE%^ which "+
    "give off enough %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^ to make this chamber "+
    "easy to see in.%^RESET%^");
   
    set_items(([
    
       ({"chamber", "walls", "wall", "ceiling", "gray stone", "floor", "excavations"}) : "%^BOLD%^%^BLACK%^"+
       "This chamber has been out hallowed from a dark gray stone. It is almost "+
       "perfectly squre. However, it is unfinished. It looks as if the excavations "+
       "abruptly stopped at the northern wall where an archway with a receptacle "+
       "next to it have been unearthed.%^RESET%^",
    
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "These orbs float effortlessly near the ceiling. They give off a constant soft "+
       "light, making this chamber easy to see in.%^RESET%^",
       
       ({"archway"}) : (:TO, "arch_desc":),
       
       ({"receptacle", "glowing receptacle"}) : (:TO, "receptacle_desc":),
       
       ({"debris", "stone debris", "dust", "dust debris"}) : "%^BOLD%^%^BLACK%^The debris from "+
       "the excavation have been carelessly left here. As if the excavactions just abruptly "+
       "stopped.%^RESET%^",
       
       
    ]));
   
    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");		
   
    add_item(({"archway","arch","ramp","spiral"}),(:TO,"arch_desc":));
    set_exits(([
        "south" : MROOMS+"mizat_encamp1",
    ]));
    
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
}

string arch_desc() 
{
    string ret;
    ret = "%^BOLD%^%^CYAN%^This archway is the most notable thing about this chamber. It is jutting "+
    "out from the unfinished northern wall, as if the excavations abruptly halted when it was discovered. "+
    "There are strange %^BOLD%^%^WHITE%^r%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^"+
    "s%^BOLD%^%^CYAN%^ scrawled over the entire visible surface of it.%^RESET%^";
        
    if(!objectp(TP)) 
    {
        return ret;
    }
    if((int)TP->query_skill("academics") > 12)
    {
        ret += "%^BOLD%^%^CYAN%^ Perhaps you could %^BOLD%^%^WHITE%^study%^BOLD%^%^CYAN%^ it closely "+
        "to determine its purpose?%^RESET%^";
    }    
    if(stringp(powered_by) && powered_by != "")
    {
        ret += "%^BOLD%^%^CYAN%^ The receptacle is currently powered. You believe that you could now "+
        "%^BOLD%^%^WHITE%^enter%^BOLD%^%^CYAN%^ the archway if you wanted to.%^RESET%^";
    }
    return ret;
}

string receptacle_desc()
{
    string ret;
    
    ret = "%^BOLD%^%^CYAN%^This strange glowing receptacle sticks out from the northern wall, right "+
    "next to the %^RESET%^%^BLUE%^archway%^BOLD%^%^CYAN%^. You believe that they are somehow connected.";
    
    if(stringp(powered_by) && powered_by != "")
    {
        ret += "%^BOLD%^%^CYAN%^ It is currently holding a "+powered_by+" and giving power to the "+
        "archway. If you wanted to, you could take the "+powered_by+" from it.%^RESET%^";
    }
    else
    {
        ret += "%^BOLD%^%^CYAN%^ It is currently empty. You believe that if you had the right item "+
        "you could power the archway by placing it in the receptacle.%^RESET%^";
    }
    return ret;   
}

void init(){
   ::init();
   add_action("portal_fun","enter");
   add_action("study_fun","study");
   add_action("place_fun", "place");
   add_action("take_fun", "take");
   add_action("say_function","say");
}

int take_fun(string str)
{
    string what;
    object ob;
    if(!stringp(str)) return 0;
    if(!objectp(TP)) return 0;
    if(sscanf(str, "%s from receptacle", what) != 1)
    {
        tell_object(TP, "Take what from receptacle?");
        return 1;
    }
    if(!stringp(powered_by) || powered_by == "")
    {
        tell_object(TP, "The receptacle is "+
        "currently empty.");
        return 1;
    }

    if(what != powered_by)
    {
        tell_object(TP, "The receptacle does not "+
        "hold a "+what+".");
        return 1;
    }
    
    tell_object(TP, "%^BOLD%^%^CYAN%^You take the "+what+" from the receptacle and "+
    "watch in awe as the %^BOLD%^%^WHITE%^r%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^"+
    "s%^BOLD%^%^CYAN%^ scrawled into the archway instantly dim!%^RESET%^");
    
    tell_room(TO, TPQCN+"%^BOLD%^%^CYAN%^ takes "+what+" from the receptacle and "+
    "you watch in awe as the %^BOLD%^%^WHITE%^r%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^"+
    "s%^BOLD%^%^CYAN%^ scrawled into the archway instantly dim!%^RESET%^", TP);
    if(!stringp(power_file))
    {
        tell_object(TP, "ERROR: Could not find the file for the object currently powering the archway.");
        return 1;
    }
    ob = new(power_file);
    if(ob->move(TP) != MOVE_OK)
    {
        tell_object(TP, "You drop "+ob->query_short()+"!");
        ob->move(TO);
    }
    powered_by = "";
    power_file = "";
    destination = "";
    return 1;
}

int place_fun(string str)
{
    string what;
    object ob;
    if(!stringp(str)) return 0;
    if(!objectp(TP)) return 0;
    if(sscanf(str, "%s in receptacle", what) != 1)
    {
        tell_object(TP, "Place what in receptacle?");
        return 1;
    }
    if(stringp(powered_by) && powered_by != "")
    {
        tell_object(TP, "There is already something in the "+
        "receptacle. You should <take it from the receptacle> "+
        "first.");
        return 1;
    }
    if(!objectp(ob = present(what, TP)))
    {
        tell_object(TP, "You don't have +"+what+".");
        return 1;
    }
    if(!ob->query_property("mizatwaygatepower"))
    {
        tell_object(TP, "Your "+what+" doesn't seem to fit in the receptacle!");
        return 1;
    }
    destination = ob->query_property("mizatwaygatepower");
    if(!stringp(destination))
    {
        tell_object(TP, "Your "+what+" doesn't seem to fit in the receptacle!");
        return 1;
    }
    
    tell_object(TP, "%^BOLD%^%^CYAN%^You place the "+what+" in the receptacle and "+
    "watch in awe as the %^BOLD%^%^WHITE%^r%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^"+
    "s%^BOLD%^%^CYAN%^ scrawled into the archway flash violently for a few moments!%^RESET%^");
    
    tell_room(TO, TPQCN+"%^BOLD%^%^CYAN%^ places "+what+" in the receptacle and "+
    "you watch in awe as the %^BOLD%^%^WHITE%^r%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^"+
    "s%^BOLD%^%^CYAN%^ scrawled into the archway flash violently for a few moments!%^RESET%^", TP);
    powered_by = ob->query_name();
    power_file = base_name(ob);
    ob->remove();    
    return 1;
}

int portal_fun(string str)
{
    string place, *rooms;
    int j;

    if(!str)
    {
        return 0;
    }
    if(str != "arch" && str != "archway")
    {
        return 0;
    }
    if(!stringp(powered_by) || powered_by == "" || !stringp(destination) || destination == "")
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^The archway is not currently powered by anything.%^RESET%^");
        return 1;
    }
    
    tell_object(TP,"%^BOLD%^%^CYAN%^You stride forward towards the archway.%^RESET%^\n");
    
    switch(destination)
    {
        case "surface":
            place = OE;
            break;
        case "mysticcaves":
            place = MCE;
            break;
        default: 
            tell_object(TP, "Something is wrong with the archway, notify Saide!");
            return 1;
            
    }
    tell_room(TO,"%^BOLD%^%^CYAN%^"+TP->QCN+" walks into the archway, and in a sudden flash of %^BOLD%^%^WHITE%^"
    "light%^BOLD%^%^CYAN%^, "+TP->QS+" is gone!%^RESET%^",TP);
    
    tell_object(TP,"%^BOLD%^%^CYAN%^A low hum builds in your ears as you pass through the "+
    "%^BOLD%^%^WHITE%^r%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^d"+
    "%^BOLD%^%^CYAN%^ archway, and with a sudden burst of %^BOLD%^%^WHITE%^bri%^YELLOW%^l"
    "%^WHITE%^liant lig%^YELLOW%^h%^WHITE%^t%^BOLD%^%^CYAN%^...%^RESET%^\n");
    tell_object(TP,"%^BOLD%^%^CYAN%^...and you find yourself elsewhere!%^RESET%^");
    TP->move_player(place);
    if(destination == "mysticcaves")
    {
        tell_object(TP, "%^RESET%^%^CYAN%^A distorted voice whispers to you: %^RESET%^rememeber where you come "+
        "in at!!! It is important!! You will need to return there and request assistance to get out!! Simply "+
        "say help or bring me home or get me out of here and we will get you out safely..... yeah, yeah... safely");
    }
    tell_room(TO, "%^BOLD%^%^BLACK%^The "+powered_by+" in the receptacle EXPLODES violently into a "+
    "shower of tiny fragments!%^RESET%^");
    
    powered_by = "";
    destination = "";
    power_file = "";
    return 1;
}

int say_function(string str)
{
    return 0;
}

int study_fun(string str)
{
    string place, *rooms;
    int j;

    if(!str)
    {
        return 0;
    }
    if(str != "arch" && str != "archway")
    {
        return 0;
    }
    if(!objectp(TP)) return 0;
    
    if((int)TP->query_skill("academics") > 12) 
    {
        tell_object(TP,"%^BOLD%^%^CYAN%^This is one of the magical creations known as way-gates. There are said "
        "to be many such gates throughout underdark, which are often made use of by drowkind in traveling across vast "
        "distances underground.  However, it seems they are only making use of items that were already there, as the "
        "origins of these gates are unknown.  It is said that they existed even before the elven crown wars, leaving "
        "scholars only to wonder at what magical creatures may have created them.\n\n"
        "You do think that this particular way-gate requires some type of power source to be placed within the "+
        "receptacle to be of any use.%^RESET%^");
    }
    else 
    {
        tell_object(TP,"%^BOLD%^%^CYAN%^Well, it's a strange thing to find here, especially given that it looks "+
        "ancient. You are not able to determine anything else about it though.%^RESET%^");
    }
    
    if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);    
    return 1;
}