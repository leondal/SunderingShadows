#include <std.h>
#include <daemons.h>

#include "area_stuff.h"
#include "/d/common/common.h"

inherit HAUNTING;
int searched, myRoomState;
string original_long;

void pick_room()
{
    int tmp;
    tmp = myRoomState;
    myRoomState = random(2);
    if(tmp == myRoomState) return;
    switch(myRoomState)
    {
        case 0:		
            set_short("%^BOLD%^%^WHITE%^A decaying hallway inside the house%^RESET%^");

            original_long = "%^BOLD%^%^WHITE%^The hallway that you find yourself in is "+
            "%^BOLD%^%^RED%^collapsing%^BOLD%^%^WHITE%^ around you. "+
            "The walls and ceiling have %^BOLD%^%^BLACK%^warped%^BOLD%^%^WHITE%^ "+
            "considerably and while you can determine that they were once "+
            "constructed from a sturdy and magnificent %^RESET%^"+
            "%^GREEN%^oak%^BOLD%^%^WHITE%^ what remains is almost entirely "+
            "useless. Cracks and holes line both the walls and ceiling and "+
            "you easily conclude that is it impossible to tell what critters "+
            "might live inside them. More disturbing is the floor of this hallway. "+
            "It is littered with layer upon layer of %^BOLD%^%^BLACK%^charred "+
            "black%^BOLD%^%^WHITE%^ bones. You are literally wading through "+
            "what looks to be a mass %^BOLD%^%^RED%^graveyard%^BOLD%^%^WHITE%^ "+
            "and some of them look as if they were added rather recently.%^RESET%^";

            set_long(original_long);

            set_smell("default","\nA faint odor of something burning mixes with "+
			"a strong odor of decay.");
			
            set_items(([
            ({"wall", "walls", "ceiling", "warped", "holes", 
            "crack", "oak", "collapsing"}) : 
            "%^BOLD%^%^BLACK%^The walls "+
            "and ceiling of this hallway were once made from a magnificent %^RESET%^"+
            "%^GREEN%^oak%^BOLD%^%^BLACK%^ but they have warped to the point "+
            "of being useless. It is quite remarkable that this structure still "+
            "stands. Holes and cracks line both the ceiling and the walls and "+
            "it is impossible to tell what critters might live within them.%^RESET%^",

            ({"bones", "charred bones", "floor", "graveyard" }) : "%^BOLD%^%^BLACK%^"+
            "There is a horde of bones on the floor here. They have all been charred "+
            "black but what caused such deformation and from where they came remains "+
            "a mystery. You feel as if you are wading through a mass graveyard "+
            "and you realize that there is no telling what might be hidden within them."+
            "%^RESET%^",			
            ]) );

            break;
        case 1:
            set_short("%^BOLD%^%^MAGENTA%^A magnificent hallway inside the house%^RESET%^");

            original_long = "%^BOLD%^%^MAGENTA%^The hallway that you find yourself in is "+
            "%^BOLD%^%^RED%^exquisite%^BOLD%^%^MAGENTA%^! The walls and ceiling are "+
            "almost flawless, with not a speck of visible dust anywhere, suggesting "+
            "something very meticulous keeps this place in order. They are constructed "+
            "from a study and magnificent %^RESET%^%^GREEN%^oak%^BOLD%^%^MAGENTA%^ "+
            "and look as if they might last forever. It is suprising that such a "+
            "hallway still exists inside this place but all is not well. The floor "+
            "here is quite disturbing and makes the entire hallway seem as if it "+
            "does not belong. There are layer upon layer of %^BOLD%^%^BLACK%^charred"+
            " black%^BOLD%^%^MAGENTA%^ bones littering the floor. They serve as a "+
            "macabre carpet of sorts and some of them look as if they were "+
            "added rather recently.%^RESET%^";
	
            set_smell("default","\nVarious sweet fragrances assault your nostrils.");
	
            set_long(original_long);	

            set_listen("default","Cracking and crunching resound here as your feet "+
            "snap bone after bone.");			
			
            set_items(([
                ({"walls", "ceiling", "exquisite", "dust", "meticulous"}) : "%^RESET%^%^GREEN%^"+
                "The walls and ceiling of this hallway are exquisite. They are "+
                "constructed from a sturdy and magnificent oak that has not even a "+
                "speck of dust visible anywhere. You believe that whoever "+
                "tends to this place is very meticulous indeed. This place "+
                "seems as if it might last forever. You wonder how this "+
                "hallways even exists inside this house and an involuntary "+
                "shiver courses down your spine.%^RESET%^", 

                ({"floor", "bones", "charred bones", "carpet"}) : "%^BOLD%^"+
                "%^BLACK%^The floor here is is dramatic contrast to the "+
                "rest of the hallway. It is littered with hordes of charred "+
                "bones. From where they come and what might have charred "+
                "them remains a mystery. They serve as a macabre carpet "+
                "of sorts. You realize that there is no telling what might "+
                "be hidden within them.%^RESET%^"
            ]));
            break;
    }

    if(tmp != myRoomState)
    {
        if(objectp(TO)) 
        {
            tell_room(TO, "%^BOLD%^%^RED%^You blink and the very hallway around "+
            "you changes!!%^RESET%^");
		
            tell_room(TO, "%^BOLD%^%^BLUE%^An insane laughter erupts from the very air "+
            "around you, but quickly dies out!%^RESET%^");
		
            TO->adjust_room(myRoomState);
        }
    }
	
}

string query_original_long() { return original_long; }

void create() 
{
    if(base_name(TO) != FFH) 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({HHMON+"crazed_guard"}), ({1 + random(3)}));
                break;      			
        }
        set_repop(40);
    }
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("A hallway inside the house");
    myRoomState = -1;
    
    set_listen("default","Cracking and crunching resound here as your feet "+
    "snap bone after bone.");
    set_search("default", "%^BOLD%^%^YELLOW%^Perhaps the "+
    "%^BOLD%^%^BLACK%^bones%^BOLD%^%^YELLOW%^ hide something?%^RESET%^");
    searched = random(5);
    set_search("bones", (:TO, "mySearch":));
    pick_room();	
}


int mySearch(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(searched != 4)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You casually dig through the bones but manage "+
        "to find nothing you would want to keep...%^RESET%^");
        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ casually digs through the bones "+
            "but doesn't seem to find anything of value.%^RESET%^", TP);
        }
        return 1;
    }
    searched = 0;
    if(!random(3)) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^Uh-oh.... the bones begin stirring!%^RESET%^");
		
        if(!objectp(ob = present("saide_haunting_object", TP))) return 1;
        ob->do_random_effect(6);		    
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You casually dig through the bones but manage "+
        "to find nothing you would want to keep...%^RESET%^");
        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ casually digs through the bones "+
            "but doesn't seem to find anything of value.%^RESET%^", TP);
        }
        return 1;
    }
}


void reset()
{
    ::reset();
    pick_room();
    searched = random(5);
}