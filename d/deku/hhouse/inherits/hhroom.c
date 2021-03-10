#include <std.h>
#include <move.h>
#include <daemons.h>

#include "area_stuff.h"
#include "door_stuff.h"

#include "/d/common/common.h"


inherit HAUNTING;
int searched, myRoomState, searched_two, has_summoned, hid_state;
string original_long, sexit, dest;
string myBoss, roomdescrip;

void flicker_me_not();
void open_hidden_room()
{
    object hidroom;
    if(hid_state == 0) 
    {
        hid_state = 1;
        tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexit+"ern"+
        " wall slides to the side, revealing "+
        "an opening!%^RESET%^");
        TO->add_exit(dest, sexit);
        hidroom = find_object_or_load(dest);
        if(objectp(hidroom)) hidroom->open_hidden_room();
        return;
    }
}

void close_hidden_room()
{
    object hidroom;
    if(hid_state == 1)
    {
        tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexit+"ern"+
        " wall slides back into place!%^RESET%^");
        hid_state = 0;
        TO->remove_exit(sexit);
        hidroom = find_object_or_load(dest);
        if(objectp(hidroom)) hidroom->close_hidden_room();
        return;
    }
}

void FixupRoom()
{
    object ob;
    if(!objectp(TO)) return;
    remove_search("shelves");
    remove_search("tables");
    remove_search("vials");
    remove_search("clothing");
    remove_search("bed");
    remove_property("light");
    set_property("light", 1);
    has_summoned = 0;
    roomdescrip = "";
    if(objectp(ob = present("hhousehost", TO))) 
    {
        ob->remove();
    }
    if(objectp(ob = present("hhouseboss", TO))) 
    {
        ob->remove();
    }		
    if(objectp(ob = present("fine mirror", TO)))
    {
        ob->remove();
    }
    if(objectp(ob = present("hhouseshadow", TO))) 
    {
        ob->remove();
    }	
}

		

void pick_room()
{
    object ob;
    string *tmp_array;
    int tmp;
    tmp = myRoomState;
    myRoomState = random(20);
    if(tmp == myRoomState) return;
    FixupRoom();
    tmp_array = SAVE_D->query_array("hhouse_first_floor_boss");
    if(sizeof(tmp_array))
    {		
        if(member_array(base_name(TO)+".c", tmp_array) != -1)
        {
            myRoomState = 20;
        }
	}	
    tmp_array = SAVE_D->query_array("hhouse_second_floor_boss");
    if(sizeof(tmp_array))
    {
        if(member_array(base_name(TO)+".c", tmp_array) != -1)
        {
            myRoomState = 20;
        }
    }	

    switch(myRoomState)
    {
        case 0..5:		
            set_short("%^BOLD%^%^BLACK%^An old bedroom%^RESET%^");

            original_long = "%^BOLD%^%^WHITE%^This room is cluttered almost beyond "+
            "belief. %^BOLD%^%^CYAN%^Clothing%^BOLD%^%^WHITE%^, trash, and other "+
            "materials have been thrown all over the floor. The bed is a marvelous "+
            "%^BOLD%^%^MAGENTA%^canopy%^BOLD%^%^WHITE%^ which takes up almost the "+
            "entire center of the chamber. It looks like it might have been "+
            "quite expensive at one point in time but it has long since been "+
            "broken down and it serves very little purpose in its current state. "+
            "The walls of this chamber are made from an ancient and %^BOLD%^%^BLACK%^"+
            "warped%^RESET%^%^GREEN%^ oak%^BOLD%^%^WHITE%^. They have written on "+
            "them a phrase which repeats constantly, chaotically, as if scrawled "+
            "by someone on the verge of %^BOLD%^%^RED%^madness%^BOLD%^%^WHITE%^."+
            "%^RESET%^";

            if(!sexit)
            {
                set_search("default", "%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^clothing"+
                " %^BOLD%^%^BLACK%^and %^BOLD%^%^MAGENTA%^bed%^BOLD%^%^BLACK%^ draw "+
                "your attention.%^RESET%^");
            }
            if(sexit)
            {
                set_search("default", "%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^clothing"+
                " %^BOLD%^%^BLACK%^and %^BOLD%^%^MAGENTA%^bed%^BOLD%^%^BLACK%^ draw "+
                "your attention. Something about the "+sexit+"ern wall also draws "+
                "your attention.%^RESET%^");
            }

            set_search("bed", (:TO, "bed_search":));
            set_search("clothing", (:TO, "clothing_search":));

            set_long(original_long);

            set_smell("default","\nThe pungent odor of mold hangs heavily here.");
						
            set_listen("default","An eerie, almost tangible, silence fills the air "+
            "here.");

            set_items(([
            ({"wall", "walls"}) : ({"%^RESET%^%^GREEN%^The walls of this "+
            "room are made from an oak that has been warped by the relentless assault "+
            "of time. They have been scrawled, chaotically, with a repeating message, "+
            "that looks like it could very well have been written by someone on the "+
            "verge of madness.%^RESET%^", "Here we lie, here we die, here we'll be, "+
            "without any eyes.", "common"}),
		
            ({"clutter", "clothing", "trash", 
            "materials", "floor" }) : "%^BOLD%^%^WHITE%^"+
            "The clutter in this room defies belief. It looks as if it has taken a "+
            "long time to reach this point and it would take a long time for anyone "+
            "to sort through it all.%^RESET%^",

            ({"bed", "canopy", "canopy bed"}) : "%^BOLD%^%^MAGENTA%^This giant canopy "+
            "bed was once the envy of all. Now, however, it is mostly useless, a "+
            "collector of clutter and broken down to the point of being unuseable.%^RESET%^",

            ]) );
            roomdescrip = "bedroom";

            break;
        case 6..11:
            set_short("%^BOLD%^%^CYAN%^A dining hall%^RESET%^");

            original_long = "%^BOLD%^%^RED%^The room that you now find yourself "+
            "in is an attempt at a dining hall. The walls and ceiling here are "+
            "constructed from an %^RESET%^%^GREEN%^oak%^BOLD%^%^RED%^ that has "+
            "been splattered with copious amounts of blood! The floor is covered "+
            "by a thick %^RESET%^%^ORANGE%^brown%^BOLD%^%^RED%^ carpet that looks "+
            "as if it once cost a great deal. It is now stained, almost beyond "+
            "recognition, by thousands of droplets of blood. A %^BOLD%^%^YELLOW%^"+
            "long table%^BOLD%^%^RED%^, designed to seat ten guests and the host, "+
            "takes up the center of this room. The table and the chairs surrounding "+
            "it are in %^BOLD%^%^MAGENTA%^pristine%^BOLD%^%^RED%^ condition and "+
            "aside from the blood this chamber is in almost flawless condition. "+
            "Unfortunately though, a sinking feeling sweeps over you as you "+
            "realize that the meal laid out upon the table consists of various "+
            "%^BOLD%^%^YELLOW%^human limbs%^BOLD%^%^RED%^, all cooked in some "+
            "manner or other.%^RESET%^";

            roomdescrip = "dining hall";

            set_smell("default", "\nA sweet aroma mixes with spices in the air.");
	
            if(!sexit) 
            {
                set_search("default", "%^BOLD%^%^RED%^You see nothing that would "+
                "conceal anything you would want to find.%^RESET%^");
            }
            else
            {
                set_search("default", "%^BOLD%^%^RED%^Something about the "+sexit+"ern "+
                "wall draws your attention.%^RESET%^");
            }

            set_listen("default", "An eerie, almost tangible, silence fills the air "+
            "here.");

            set_long(original_long);	
			
            set_items(([
                ({"walls", "wall", "floor", "carpet", 
                "blood", "oak", "ceiling"}) : "%^RESET%^%^GREEN%^The walls and "+
                "ceiling of this chamber are composed of a thick sturdy oak. "+
                "They have been splattered with copious amounts of blood. "+
                "The carpet here is a thick brown and looks like it was originally "+
                "very expensive. It too has been stained by thousands of "+
                "droplets of blood. The entire room, if not for the blood, "+
                "would be quite pristine.%^RESET%^",

                ({"table", "chairs", "meal"}) : "%^BOLD%^%^YELLOW%^This finely "+
                "crafted table is large enough to seat ten guests and the "+
                "host. There are large, comfortable chairs surrounding it. "+
                "It is all in pristine condition! Unfortunately the meal "+
                "laid out upon the table gives you cause for concern. It "+
                "consists of various human limbs, all cooked in some "+
                "manner or other.%^RESET%^",

                ({"limbs", "human limbs"}) : "%^BOLD%^"+
                "%^RED%^These are the meal that has been prepared.... "+
                "You quickly wonder what manner of creature was planning "+
                "to enjoy it. You see arms, legs, a torso, and several "+
                "heads.%^RESET%^",
            ]));

            if(!present("hhousehost", TO))
            {
                switch(random(10)) 
                {
                    case 0..5:
                        ob = new(HHMON+"good_host");
                        break;
                    case 6..9:
                        ob = new(HHMON+"bad_host");
                        break;
                }
                ob->move(TO);
            }
			

            break;

        case 12..17:
        
            set_short("%^RESET%^%^ORANGE%^A tiny closet%^RESET%^");

            original_long = "%^RESET%^%^ORANGE%^This room is tiny! The walls, floor, and "+
            "ceiling are constructed from the familiar %^GREEN%^oak%^RESET%^%^ORANGE%^ that "+
            "has been %^BOLD%^%^BLACK%^warped%^RESET%^%^ORANGE%^ by the vicious assault of "+
            "time. There are %^BOLD%^%^MAGENTA%^shelves%^RESET%^%^ORANGE%^, which are "+
            "insanely cluttered, lining the walls and lights hang down from the ceiling, "+
            "taking up almost all of the available space. You wonder why in the world "+    
            "someone would put so many lights in such a small space? Judging by "+
            "the materials on the %^BOLD%^%^MAGENTA%^shelves%^RESET%^%^ORANGE%^ you "+
            "figure this room is where all the cleaning supplies were once kept, though "+
            "most of the stuff looks empty now.%^RESET%^";
	
            if(!sexit) 
            {
                set_search("default", "%^RESET%^%^ORANGE%^The %^BOLD%^%^MAGENTA%^"+
                "shelves%^RESET%^%^ORANGE%^ draw your attention.%^RESET%^");
            }
            else
            {
                set_search("default", "%^RESET%^%^ORANGE%^The %^BOLD%^%^MAGENTA%^"+
                "shelves%^RESET%^%^ORANGE%^ draw your attention. Something about the "+
                sexit+"ern wall also draws your attention.%^RESET%^");
            }

            set_search("shelves", (:TO, "shelves_search":));
			
            call_out("flicker_me_not", 60);

            set_smell("default", "\nA strong sulfur odor hangs in the air.");
	
            set_listen("default", "The lights clatter about, hitting one another "+
            "constantly.");

            set_long(original_long);	
			
            set_items(([

                ({"walls", "wall", "floor", "oak"}) : "%^RESET%^%^GREEN%^"+
                "The walls, ceiling, and floor of this tiny room are composed of "+
                "the now familiar oak that much of this has been constructed from. "+
                "They have been warped by the vicious assult of time.%^RESET%^", 

                ({"shelf", "shelves", "materials"}) : "%^BOLD%^%^MAGENTA%^Shelves line the "+
                "walls of this tiny chamber. They are insanely cluttered but "+
                "most of the items appear empty now. However, you never know "+
                "what you might find when you carefully search something.%^RESET%^", 

                ({"ceiling", "lights"}) : "%^BOLD%^%^YELLOW%^Oddly there are "+
                "multitudes of these lights, they hang down from the ceiling "+
                "and take up almost all available space. You wonder why in the "+
                "world someone would put so many lights in such a small space."+
                "%^RESET%^",				
            ]));
			
            roomdescrip = "tiny closet";
            break;
		case 18..19:
			
            set_short("%^BOLD%^%^MAGENTA%^A large laboratory%^RESET%^");

            original_long = "%^BOLD%^%^MAGENTA%^This large chamber serves as a "+
            "makeshift laboratory. It does not look like it has been used in a very "+
            "long time, however, as a thick layer of %^RESET%^%^ORANGE%^dust"+
            "%^BOLD%^%^MAGENTA%^ has settled over everything. There are "+
            "%^BOLD%^%^YELLOW%^shelves%^BOLD%^%^MAGENTA%^ and %^BOLD%^%^YELLOW%^tables"+
            "%^BOLD%^%^MAGENTA%^ scattered throughout the chamber. "+   
            "Each is literally covered with %^BOLD%^%^YELLOW%^vials%^BOLD%^%^MAGENTA%^, "+
            "most look broken or cracked and drained of anything that they might have "+
            "once contained. The walls, floor, and ceiling here have been "+
            "constructed from %^RESET%^%^GREEN%^oak%^BOLD%^%^MAGENTA%^ which is in "+
            "almost flawless condition, aside from the rather thick layer of "+
            "%^RESET%^%^ORANGE%^dust%^BOLD%^%^MAGENTA%^.%^RESET%^";
	
            if(!sexit) 
            {
                set_search("default", "%^BOLD%^%^MAGENTA%^The %^BOLD%^%^YELLOW%^shelves"+
                "%^BOLD%^%^MAGENTA%^, %^BOLD%^%^YELLOW%^tables%^BOLD%^%^MAGENTA%^, and "+
                "%^BOLD%^%^YELLOW%^vials%^BOLD%^%^MAGENTA%^ draw your attention.%^RESET%^");
            }
            else
            {
                set_search("default", "%^BOLD%^%^MAGENTA%^The %^BOLD%^%^YELLOW%^shelves"+
                "%^BOLD%^%^MAGENTA%^, %^BOLD%^%^YELLOW%^tables%^BOLD%^%^MAGENTA%^, and "+
                "%^BOLD%^%^YELLOW%^vials%^BOLD%^%^MAGENTA%^ draw your attention. Something "+
                "about the "+sexit+"ern wall also draws your attention.%^RESET%^");
            }

            set_search("shelves", (:TO, "lab_search":));
            set_search("vials", (:TO, "lab_search":));  
            set_search("tables", (:TO, "lab_search":));

            set_smell("default", "\nThe odor of ancient magic hangs in the air.");
        
            set_listen("default", "An eerie, almost tangible, silence fills the air "+
            "here.");

            set_long(original_long);	
			
            set_items(([

                ({"walls", "wall", "floor", "oak"}) : "%^RESET%^%^GREEN%^"+
                "The walls, ceiling, and floor of this chamber are composed of "+
                "a pristine oak. It is almost flawless, except for the thick "+
                "layer of dust.%^RESET%^", 

                ({"dust", "thick dust"}) : "%^RESET%^%^ORANGE%^A thick "+
                "layer of dust covers everything here. It makes you think "+
                "that this chamber has not been used in a very long time.%^RESET%^",

                ({"shelf", "shelves", "tables", "vials"}) : "%^BOLD%^%^YELLOW%^"+
                "The shelves and tables here are literally covered with vials. "+
                "Most of the vials look broken or cracked and drained of anything "+
                "that might have once been contained in them.  However, "+
                "you never know what you might find if you look carefully.%^RESET%^", 
            ]));

            ob = new("/d/magic/obj/mirror");
            ob->move(TO);   
            roomdescrip = "lab";
            break;
        case 20:
		
            set_short("%^BOLD%^%^WHITE%^An empty chamber%^RESET%^");

            original_long = "%^BOLD%^%^WHITE%^The chamber that you find yourself in is "+
            "decisively empty. You quickly realize that it has been constructed from ancient "+
            "%^BOLD%^%^RED%^bricks%^BOLD%^%^WHITE%^, instead of the %^RESET%^%^GREEN%^"+
            "oak%^BOLD%^%^WHITE%^ you have become accustomed to. The ceiling is nothing "+
            "more than a mass of %^BOLD%^%^BLACK%^blackness%^BOLD%^%^WHITE%^ "+
            "which seems to absorb all light reflected at it. The walls are "+
            "slowly crumbling with age and you believe this chamber is not very safe. "+
            "In directly the center of the floor there is a %^BOLD%^%^YELLOW%^circle"+
            "%^BOLD%^%^WHITE%^ drawn using a %^BOLD%^%^RED%^bright red%^BOLD%^%^WHITE%^ "+
            "substance, with strange %^BOLD%^%^BLUE%^runes%^BOLD%^%^WHITE%^"+
            " surrounding it.%^RESET%^";
			
            if(!sexit)
            {
                set_search("default", "%^BOLD%^%^WHITE%^You see nothing that would conceal anything, "+
                "however, the %^BOLD%^%^YELLOW%^circle%^BOLD%^%^WHITE%^ does pique your "+
                "curiosity.%^RESET%^");
            }
            else
            {
                set_search("default", "%^BOLD%^%^WHITE%^You see nothing that would conceal anything, "+
                "however, the %^BOLD%^%^YELLOW%^circle%^BOLD%^%^WHITE%^ does pique your "+
                "curiosity. Something about the "+sexit+"ern wall draws your attention.%^RESET%^");				
            }

            set_long(original_long);
		
            set_items(([
                ({"walls", "wall", "bricks", "ancient brick", 
                "oak"}) : "%^BOLD%^%^RED%^Oddly this chamber has been "+
                "constructed from ancient bricks, as opposed to the oak that "+
                "the rest of the house has been built from. The bricks "+
                "are crumbling now from age and you have a feeling that "+
                "this chamber is not very safe.%^RESET%^", 

                ({"circle", "floor", "runes"}) : "%^BOLD%^%^YELLOW%^"+
                "The circle on the floor here has been drawn using some "+
                "bright red substance. It is surrounded by strange blue "+
                "runes with occassionally pulsate. You could %^BOLD%^%^WHITE%^"+
                "<%^BOLD%^%^CYAN%^stand%^BOLD%^%^WHITE%^>%^BOLD%^%^YELLOW%^ in "+
                "it, but perhaps that would not be the wisest course of action."+
                "%^RESET%^", 

                ({"ceiling", "blackness"}) : "%^BOLD%^%^BLACK%^The ceiling here "+
                "is a monstrous mass of blackness which absorbs all light reflected "+
                "at it. You have a feeling that this blackness and the circle on "+
                "the floor are somehow related.%^RESET%^",
            ]));

            set_smell("default", "\nSulfur hangs heavily in the air here.");
            set_listen("default", "Faint screams echo through the chamber and you "+
            "almost believe they are coming from within the darkness.");
            roomdescrip = "bossroom";
            break;
			
    }	
}

string query_original_long() { return original_long; }

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("A room inside the house");
    if(sexit) 
    {
        set_search(sexit, (:TO, "lever_search":));
        set_search(sexit+"ern wall", (:TO, "lever_search":));
        set_search(sexit+" wall",(:TO, "lever_search":));		
    }
    myRoomState = -1;
    pick_room();
    searched = random(8);	
}

int lever_search(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!sexit) return 0;
    tell_object(TP, "%^BOLD%^%^RED%^You search the "+sexit+" wall and find a small lever! "+
    "You should %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^pull%^BOLD%^%^WHITE%^>%^BOLD%^%^RED%^ "+
    "it!%^RESET%^");
    return 1;
}

int clothing_search(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(searched != 2)
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^You carefully search through the clothing "+
        "but all that you find are stained or torn pieces that are worthless.%^RESET%^");
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^You carefully search through the clothing "+
        "and find a %^BOLD%^%^YELLOW%^sash%^BOLD%^%^CYAN%^ that looks interesting, "+
        "even if it is dirty.%^RESET%^");
        ob = new(HHOB+"dirty_sash");
        if(ob->move(TP) != MOVE_OK)
        {
            tell_object(TP, "%^BOLD%^%^RED%^You drop the %^BOLD%^%^YELLOW%^sash%^BOLD%^"+
            "%^CYAN%^!%^RESET%^");
            ob->move(ETP);
        }
    }
    searched = 1;
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^CYAN%^ carefully searches through "+
        "the clothing.%^RESET%^", TP);
    }
    return 1;
}


int bed_search(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(searched_two)
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the bed but "+
        "find nothing of interest.%^RESET%^");
    }
    else
    {
        searched_two = 1;
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the bed and find "+
        "a crumpled up piece of paper!%^RESET%^");
        ob = new(HHOB+"written_info");
        ob->move(TO);
    }
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ carefully searches the bed.%^RESET%^", TP);
    }		
    return 1;

}

int shelves_search(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(searched != 2) 
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+
        " but find nothing of interest.%^RESET%^");
    }
    else
    {
        searched = 1;
        switch(random(8)) 
        {
            case 0..6:
                ob = new("/d/common/obj/potion/advanced_heal.c");
                ob->set_uses(4 + random(4));
                break;
            case 7:
                ob = new("/d/common/obj/potion/legendary_heal.c");
                ob->set_uses(2 + random(2));
                break;
        }
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+
        " and find "+ob->query_short()+"%^BOLD%^%^MAGENTA%^!%^RESET%^");
        ob->move(TO);
    }
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ carefully searches the "+str+
        "!%^RESET%^", TP);
    }
    return 1;
}


int lab_search(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(searched != 2) 
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+
        " but find nothing of interest.%^RESET%^");
    }
    else
    {
        searched = 1;
        switch(random(3)) 
        {
            case 0..1:
                ob = new("/d/common/obj/potion/legendary_heal.c");
                ob->set_uses(3 + random(2));
                break;
            case 2:
                ob = new("/d/magic/scroll");
                ob->set_spell(5 + random(5));
                break;
        }
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+
        " and find "+ob->query_short()+"%^BOLD%^%^MAGENTA%^!%^RESET%^");
        ob->move(TO);
    }
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ carefully searches the "+str+
        "!%^RESET%^", TP);
    }
    return 1;

}

void flicker_me_not()
{
    object targ, mon, *liv, *tmp;
    int x;
    if(roomdescrip != "tiny closet") return;
    if(has_summoned) return;
    if(member_array(1, all_living(TO)->is_player()) == -1) 
    {
        call_out("flicker_me_not", 60);
        return;
    }
    switch(random(10)) 
    {
        case 0..8:
            tell_room(TO, "%^BOLD%^%^YELLOW%^The lights %^BOLD%^%^WHITE%^f"+
            "%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^c%^BOLD%^"+
            "%^WHITE%^k%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^ "+
            "rapidly, as if affected by an unfelt breeze....%^RESET%^");
            call_out("flicker_me_not", 60);
            break;
        case 9:
            tell_room(TO, "%^BOLD%^%^YELLOW%^The lights suddenly "+
            "go out and an %^BOLD%^%^MAGENTA%^INSANE%^BOLD%^%^YELLOW%^ "+
            "and %^BOLD%^%^MAGENTA%^MANICAL%^BOLD%^%^YELLOW%^ "+
            "laughter erupts all around you!%^RESET%^");
            tmp = all_living(TO);
            for(x = 0;x < sizeof(tmp);x++)
            {
                if(!tmp[x]->is_player()) continue;
                liv += ({tmp[x]});
            }   
            if(!sizeof(liv)) 
            {
                call_out("flicker_me_not", 60);
                return;
            }
            targ = liv[random(sizeof(liv))];
            mon = new(HHMON+"greater_hulking_shadow");
            mon->shadow_me(targ);
            mon->move(TO);
            mon->dark_bolt(targ);
            set_property("light", -2);
            has_summoned = 1;
            break;
    }
}

void init()
{
    ::init();
    add_action("circle_stand", "stand");
    add_action("pull_lever", "pull");
}

void complete_circle(object who, int step)
{
    object ob, ob2;
    if(!objectp(TO)) return 0;
    if(!objectp(who)) 
    {
        has_summoned = 0;
        return;
    }
    if(!present(who, TO)) 
    {
        has_summoned = 0;
        return;
    }
    switch(step)
    {
        case 1:
            tell_room(TO, "%^BOLD%^%^BLACK%^The darkness on the ceiling "+
            "here begins pulsating %^BOLD%^%^RED%^RAPIDLY%^BOLD%^%^BLACK%^ "+
            "and suddenly a giant hole %^BOLD%^%^RED%^RIPS%^BOLD%^%^BLACK%^ "+
            "open in it!%^RESET%^");
		
            tell_room(TO, "%^BOLD%^%^BLACK%^You see several monstrous "+
			"hands reaching through the opening..... %^BOLD%^%^WHITE%^"+
			"SOMETHING%^BOLD%^%^BLACK%^ is coming through!%^RESET%^");
			
            call_out("complete_circle", 5, who, 2);
            break;
        case 2:
            tell_room(TO, "%^BOLD%^%^BLACK%^A %^BOLD%^%^RED%^MONSTROUS"+
            "%^BOLD%^%^BLACK%^ black beast with at least "+
            "ten arms makes it way through and lands in the corner of "+
            "the room!");
            ob = new(HHMON+"black_beast");
            ob2 = new(HHOB+"dagger_part");
            if(strsrch(base_name(TO), "ff") != -1) ob2->choose_piece(2);
            else if(strsrch(base_name(TO), "sf") != -1) ob2->choose_piece(3);
            ob2->move(ob);
            ob->move(TO);
            has_summoned = 2;
            break;
    }
    return;
}

int pull_lever(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!sexit) return 0;
    tell_object(TP, "%^BOLD%^%^RED%^You easily pull the small lever!%^RESET%^");
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ pulls a small lever on the "+sexit+" wall!%^RESET%^", TP);
    }
    if(hid_state == 0) 
    {
        open_hidden_room();
        return 1;
    }
    if(hid_state == 1)
    {
        close_hidden_room();
        return 1;
    }
}

int circle_stand(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(roomdescrip != "bossroom") return 0;
    if(str != "circle" && str != "in circle") return 0;
    if(has_summoned == 1)
    {
        tell_object(TP, "%^BOLD%^%^YELLOW%^Someone else is already "+
        "standing in the circle.%^RESET%^");    
        return 1;
    }
    if(has_summoned == 2)
    {
        tell_object(TP, "%^BOLD%^%^YELLOW%^You walk over and stand "+
        "in the circle but nothing seems to happen.%^RESET%^");
        return 1;   
    }   
    tell_object(TP, "%^BOLD%^%^YELLOW%^Against better judgement you "+
    "walk over and stand in the circle.....%^RESET%^");

    tell_room(TO, TPQCN+"%^BOLD%^%^YELLOW%^ walks over and stands in "+
    "the circle.%^RESET%^", TP);
	
    call_out("complete_circle", 5, TP, 1);

    has_summoned = 1;
    return 1;
}

void reset()
{
    ::reset();
    
    if(objectp(TO)) 
    {
        if(sizeof(all_living(TO))) 
        {
            if(member_array(1, all_living(TO)->is_player()) == -1) pick_room();
        }
    }
    close_hidden_room();
    searched = random(6);
    searched_two = 0;
}
