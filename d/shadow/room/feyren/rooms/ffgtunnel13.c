#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit VAULT;
int searched;

void create() 
{
    ::create();
    set_property("no teleport", 1);
    set_property("light",1);
    set_property("indoors",1);
    set_name("A small rock chamber");
    set_short("%^BOLD%^%^YELLOW%^A small rock chamber%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^WHITE%^This small rock chamber is littered "+
    "with %^MAGENTA%^debris%^BOLD%^%^WHITE%^ of all kinds. The %^BOLD%^"+
    "%^MAGENTA%^floor%^BOLD%^%^WHITE%^ is "+
    "scarcely visible and what you can see looks fractured and "+
    "fragmented so that it is mostly pieces. A makeshift %^MAGENTA%^bed, "+
    "%^BOLD%^%^WHITE%^composed mostly of thick green fuzz, has been "+
    "setup in the center of the room. The ceiling in this chamber "+
    "is low and covered in a thick unnatural %^BOLD%^%^GREEN%^moss"+
    "%^BOLD%^%^WHITE%^ that provides a pale green light to the "+
    "room. The southern and eastern walls of the room are entirely "+
    "unremarkble, save for the enormous piles of %^BOLD%^%^MAGENTA%^"+
    "filth%^BOLD%^%^WHITE%^ that have "+
    "built up around each. The outline of what appears to be "+
    "a %^BOLD%^%^BLUE%^granite door%^BOLD%^%^WHITE%^ is vaguely visible "+
    "on the northern wall but there is no obvious means by which "+
    "to open it from this side. The western wall has had a %^BOLD%^%^BLACK%^"+
    "marble door%^BOLD%^%^WHITE%^ inset into it that offers "+
    "an escape from this room.%^RESET%^");

    set_smell("default","A strong odor of filth invades your senses.");
    set_listen("default","Faint skittering sounds echo all around you.");

    set_search("default", "What do you want to search?");

    set_items(([({"debris", "floor"}) : "%^RESET%^"+
    "%^MAGENTA%^The amount of debris in this room is "+
    "quite disturbing. There are piles upon piles and "+
    "range from broken flasks, to bits of food, to pieces of "+
    "unidentifiable matter. Saying that whatever creature "+
    "calls this room home seems to not care at all about "+
    "being sanitary is a drastic understatement. %^RESET%^",

    ({"bed", "makeshift bed"}) : "%^BOLD%^%^GREEN%^"+
    "The thick fuzz that this bed is composed of "+
    "is quite stiff. You are not sure if filth is "+
    "the cause or if it was originally as stiff as it "+
    "currently is but it seems to serve its "+
    "purpose.%^RESET%^",
	
    ({"ceiling", "moss"}) : "%^RESET%^%^GREEN%^"+
    "The ceiling of this rock chamber is fairly "+
    "low and is covered "+
    "entirely with a thick unnatural moss. It offers "+
    "a faint pale green light to the room.%^RESET%^",

    ({"walls", "wall", "eastern wall", 
    "southern wall", "filth", "south wall", 
    "east wall"}) : "%^BOLD%^%^WHITE%^The eastern "+
    "and southern walls of this room are entirely unremarkble "+
    "and quite rough. A tremendous amount of filth, some "+
    "which appears to be body wastes, some which appears "+
    "to be hunks of rotting food, and some which has "+
    "decayed beyond the point of being identifiable "+
    "is piled against the eastern and southern walls. "+
    "A marble door has been set into the western room "+
    "to provide an exit from this chamber. The outline of "+
    "a granite door, with no visible means of opening "+
    "it, is visible in the northern wall.%^RESET%^", 

    ({"door", "granite door", "north wall", 
    "northern wall"}) : "%^BOLD%^%^BLUE%^"+
    "The outline of a granite door is visible "+
    "in the northern wall of this chamber. "+
    "There is no apparent means of opening it "+
    "from inside this chamber.%^RESET%^",
	
    ]) ); 
	
    set_exits((["west" : FFGTR"12"]));
    set_door("marble door",FFGTR"12","west");
    set_door_description("marble door",MARBLE_DOOR);
    searched = 0;
    set_search("room", (:TO, "mySearch":));
    set_search("filth", (:TO, "mySearch":));
    set_search("floor", (:TO, "mySearch":));
    set_search("bed", (:TO, "mySearch":));
}

int mySearch(string ob)
{
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(present("ashilla", TO)) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^Ashilla, The Mad watches "+
        "here carefully and prevents you from searching very "+
        "thoroughly!%^RESET%^");
        return 1;
    }
    if(searched) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^You carefully search around the "+
        "area but find nothing of value.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ searches around "+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	

    tell_object(TP, "%^BOLD%^%^GREEN%^You manage to find something of "+
    "value!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^GREEN%^ searches around and "+
        "seems to find something of value!%^RESET%^", TP);
    }
    searched = 1;
    RANDTREAS->find_stuff(TO,"random");
    return 1;
}

void open_hidden_room()
{
    object hidroom;
    if(searched == 0) 
    {
        searched = 1;
        tell_room(TO, "%^BOLD%^%^BLUE%^The granite door "+
        "slides to the slide, revealing "+
        "an opening to a chamber beyond!%^RESET%^");

        TO->add_exit(FFGTR"29", "north");
		
        TO->remove_item(({"north wall", "northern wall",
        "door", "granite door"}));

        TO->add_item(({"north wall", 
        "northern wall"}), "%^BOLD%^%^BLUE%^"+
        "An opening on the northern wall "+
        "leads into another chamber.%^RESET%^");

        TO->set_long("%^BOLD%^%^WHITE%^This small rock chamber is littered "+
        "with %^MAGENTA%^debris%^BOLD%^%^WHITE%^ of all kinds. The %^BOLD%^"+
        "%^MAGENTA%^floor%^BOLD%^%^WHITE%^ is "+
        "scarcely visible and what you can see looks fractured and "+
        "fragmented so that it is mostly pieces. A makeshift %^MAGENTA%^bed, "+
        "%^BOLD%^%^WHITE%^composed mostly of thick green fuzz, has been "+
        "setup in the center of the room. The ceiling in this chamber "+
        "is low and covered in a thick unnatural %^BOLD%^%^GREEN%^moss"+
        "%^BOLD%^%^WHITE%^ that provides a pale green light to the "+
        "room. The southern and eastern walls of the room are entirely "+
        "unremarkble, save for the enormous piles of %^BOLD%^%^MAGENTA%^"+
        "filth%^BOLD%^%^WHITE%^ that have "+
        "built up around each. An "+
        "opening on the northern wall leads into another "+
        "chamber beyond. The western wall has had a %^BOLD%^%^BLACK%^"+
        "marble door%^BOLD%^%^WHITE%^ inset into it that offers "+
        "an escape from this room.%^RESET%^");

        hidroom = find_object_or_load(FFGTR"29");
        if(!objectp(hidroom)) return;
        hidroom->open_hidden_room();
        return;
    }
}

void close_hidden_room()
{
    object hidroom;
    if(searched == 1)
    {
        tell_room(TO, "%^BOLD%^%^BLUE%^A granite door "+
        "slides back into place, closing access "+
        "to the chamber beyond!%^RESET%^");
        searched = 0;
        TO->remove_exit("north");

        TO->remove_item(({"door", "granite door",
        "north wall", "northern wall"}));

        TO->add_item(({"door", "granite door", 
        "north wall", "northern wall"}), "%^BOLD%^%^BLUE%^"+
        "The outline of a granite door is visible "+	
        "in the northern wall of this chamber. "+
        "There is no apparent means of opening it "+
        "from inside this chamber.%^RESET%^");

        TO->set_long("%^BOLD%^%^WHITE%^This small rock chamber is littered "+
        "with %^MAGENTA%^debris%^BOLD%^%^WHITE%^ of all kinds. The %^BOLD%^"+
        "%^MAGENTA%^floor%^BOLD%^%^WHITE%^ is "+    
        "scarcely visible and what you can see looks fractured and "+
        "fragmented so that it is mostly pieces. A makeshift %^MAGENTA%^bed, "+
        "%^BOLD%^%^WHITE%^composed mostly of thick green fuzz, has been "+
        "setup in the center of the room. The ceiling in this chamber "+
        "is low and covered in a thick unnatural %^BOLD%^%^GREEN%^moss"+
        "%^BOLD%^%^WHITE%^ that provides a pale green light to the "+
        "room. The southern and eastern walls of the room are entirely "+
        "unremarkble, save for the enormous piles of %^BOLD%^%^MAGENTA%^"+
        "filth%^BOLD%^%^WHITE%^ that have "+
        "built up around each. The outline of what appears to be "+
        "a %^BOLD%^%^BLUE%^granite door%^BOLD%^%^WHITE%^ is vaguely visible "+
        "on the northern wall but there is no obvious means by which "+
        "to open it from this side. The western wall has had a %^BOLD%^%^BLACK%^"+
        "marble door%^BOLD%^%^WHITE%^ inset into it that offers "+
        "an escape from this room.%^RESET%^");

        hidroom = find_object_or_load(FFGTR"29");
        if(!objectp(hidroom)) return;
        hidroom->close_hidden_room();
        return;
    }
}

void reset()
{
    object queen;
    ::reset();
    close_hidden_room();	
    if(random(3))
    {
        if(present("ashilla", TO)) return;
        queen = new(FFMON+"ashilla");
        queen->move(TO);	
    }
}