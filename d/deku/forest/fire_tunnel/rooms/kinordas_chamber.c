#include <std.h>
#include <daemons.h>
#include <party.h>
#include "/d/deku/inherits/forest.h"
inherit ROOM;

string *WantedHeads = ({"head of Hound keeper", "head of Golem master", "head of Imp king", "head of Fire Elemental King"});
int *HasHeads = ({}), max_resets = 15, resets_so_far = 0;

void create() {
    int x;
    ::create();
    set_short("%^BOLD%^%^BLACK%^A chamber of stone%^RESET%^");
    set_name("A chamber of stone");
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("no teleport",1);
    set_property("no sticks",1);
    set_long("You are inside of a chamber made entirely from a "+
    "dull white stone.  The chamber isn't overly large, but is "+
    "big enough for a group of men to be comfortable.  The floor "+
    "has been stained a blood red, though not by means of "+
    "any dye.  Thrown about casually, as if without a "+
    "care in the world, are intestines and various "+
    "other internal organs, all of which have "+
    "began to rot.  A broken canopy bed rests turned "+
    "over in the direct center of this chamber.  "+
    "Next to it, outlined in a dark %^RED%^red"+
    "%^RESET%^ glow, is a vacant and inactive "+
    "%^BLUE%^portal%^RESET%^.  The ceiling here is several "+
    "dozen feet overhead and %^YELLOW%^globes%^RESET%^ of "+
    "%^YELLOW%^dull light%^RESET%^ float carelessly near it.  "+
    "The walls of this room have been soaked with a shower "+
    "of blood and written in the blood is what appears "+
    "to be a very short message.  An opening in the east wall "+
    "leads out of the chamber.");         
    set_exits(([
        "opening" : FTUN_ROOMS"firetemple5",
    ]));

    set_listen("default","Silence hangs heavy in the air here, a "+
    "tranquility that borders on the edge of disturbing.");
    set_smell("default","The odor in the air here is one of lingering "+
    "decay mixed with a very strong scent of sulfur.");
        
    set_items(( [       
        "ceiling" : "The ceiling here is a sort of dome shape, "+
        "it hangs several dozen feet overhead.  The room is "+
        "lit by dull globes of light which float carelessly near it.",
        "floor" : "The floor here is littered with intestines and "+
        "other various internal organs, all of them "+
        "rotting away without a care.",
        "portal" : "%^BLUE%^This portal rests just next to the "+
        "bed, it is outlined with a %^RED%^dark red%^RESET%^%^BLUE%^ "+
        "glow.  It is inactive, its magic long since ceased."+
        "%^RESET%^",
        ({"globes","light"}) : "%^YELLOW%^These globes of light "+
        "float carelessly near the ceiling here, barely "+
        "lighting up the room.%^RESET%^",
        ({"walls","wall"}) : "%^RED%^The walls of this room have "+
        "been soaked with a shower of blood.  Scrawled in the "+
        "blood is a very short message.  You could try reading "+
        "it.%^RESET%^"] ));
}

void init() {
    ::init();
    add_action("__Read_me","read");
    //add_action("enter_portal","enter");
    add_action("toss_portal", "toss");	
}

int enter_portal(string str) 
{
    if(str == "portal") 
    {
        tell_object(TP,"%^BLUE%^You bravely step up to the "+
        "portal and step through it.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO,TPQCN+"%^BLUE%^ bravely walks up to the portal "+
            "and steps through it!%^RESET%^",TP);
        }
        if(TP->query_invis()) 
        {
            tell_room(TO,"%^BLUE%^The portal wavers for a second "+
            "as if something just passed through it!%^RESET%^",TP);
        }
        TP->move_player(F_ROOMS"32-16");
        tell_room(ETP,"%^RED%^A flash of fire erupts and leaves "+
        TPQCN+"%^RED%^ behind!%^RESET%^",TP);
        return 1;
    }
    return 0;
}

int check_is_wanted(object ob)
{
    int x = -1;
    if(!objectp(ob)) return -1;
    x = member_array(ob->query_short(), WantedHeads);
    return x;
}

int check_has_head(int which)
{
    if(member_array(which, HasHeads) == -1) return 0;
    return 1;
}

void check_has_all_heads()
{
    object *mems = ({});
    string part;
    int x;		
    if(sizeof(HasHeads) == sizeof(WantedHeads)) 
    {
        tell_room(TO, "%^BOLD%^%^RED%^With a thunderous roar the portal "+
        "splits wide open, a smell of death and decay "+
        "assaulting you, a sense of doom and "+
        "dread overcoming all your other senses, and a cruel, viscious "+
        "laughter echoing in your mind!%^RESET%^");

        tell_room(TO, "%^BOLD%^%^RED%^A voice from within the portal "+
        "screams: %^RESET%^I AM HUNGRY!!! COME FACE ME AND BE DEVOURED FOOL!!%^RESET%^");
        remove_item("portal");
        add_items(({"portal"}), "%^BOLD%^%^BLUE%^This portal has been split "+
        "wide open.  A strong sense of death and decay flows out from it "+
        "and simply looking at it almost weighs you down with a "+
        "sense of dread and doom.%^RESET%^");
        add_exit(FTUN_ROOMS"war_mongrels_tunnel1", "portal");		
        if(objectp(TP))
        {
            if(!(part = TP->query_party()))
            {
                if(member_array("Altar of Fire", TP->query_mini_quests()) == -1)
                {
                    TP->set_mini_quest("Altar of Fire", 1000000, 
                    "Servitude:  %^BOLD%^%^RED%^Served "+
                    "The War Mongrel!%^RESET%^");
                }
            }
            mems = PARTY_OB->query_party_members(part);
            if(!sizeof(mems)) 
            {
                if(member_array("Altar of Fire", TP->query_mini_quests()) == -1)
                {
                    TP->set_mini_quest("Altar of Fire", 100000, 
                    "Servitude:  %^BOLD%^%^RED%^Served "+
                    "The War Mongrel!%^RESET%^");
                }
            }
            else
            {
                for(x = 0;x < sizeof(mems);x++)
                {
                    if(!objectp(mems[x])) continue;
                    if(member_array("Altar of Fire", 
                    mems[x]->query_mini_quests()) == -1)
                    {
                        mems[x]->set_mini_quest("Altar of Fire", 100000,
                        "Servitude:  %^BOLD%^%^RED%^Served "+
                        "The War Mongrel!%^RESET%^");
                        continue;
                    }
                }
            }   
        }
        return;
    }
    return;
}

int toss_portal(string str)
{
    string what;
    object ob;
    int x;
    if(!str) 
    {
        tell_object(TP, "Try <toss [head] into the portal>.");
        return 1;
    }
    if(sscanf(str, "%s into the portal", what) != 1)
    {
        tell_object(TP, "Try <toss [head] into the portal>.");
        return 1;
    }
    if(!(ob = present(what, TP)))
    {
        tell_object(TP, "You dont have that!");
        return 1;
    }
    if(!ob->id("head")) 
    {
        tell_object(TP, "That is not a head and you think it "+
        "unwise to toss into the portal!");
        return 1;
    }
    tell_object(TP, "You walk up to the portal and toss the "+
    ob->query_short() + " into it!");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+" walks up to the portal and tosses the "+
        ob->query_short() + " into it!", ({TP}));
    }
    if((x = check_is_wanted(ob)) == -1) 
    {
        tell_room(TO, "%^BOLD%^%^RED%^A voice from within the portal "+
        "screams: %^RESET%^THAT IS NOT WHAT I ASKED FOR!!");
        ob->remove();
        return 1;
    }
    if(check_has_head(x) == 1)
    {
        tell_room(TO, "%^BOLD%^%^RED%^A voice from within the portal "+
        "screams: %^RESET%^I ALREADY HAVE THAT HEAD!!! BRING ME THE OTHERS!!!!");
        ob->remove();
        return 1;
    }
    resets_so_far = 0;		
    HasHeads += ({x});
    tell_object(TO, "%^BOLD%^%^RED%^A voice cackles insanely from within "+
    "the portal: %^RESET%^ yes, yes, that's it, that's it!!");
    ob->remove();
    check_has_all_heads();
    return 1;
}

void reset()
{
    if(resets_so_far >= max_resets && sizeof(HasHeads))
    {
        resets_so_far = 0;
        if(sizeof(HasHeads) == sizeof(WantedHeads)) 
        {
            tell_room(TO, "%^BOLD%^%^BLUE%^With a strange hissing sound, "+
            "the portal in this room seals itself!%^RESET%^");
            remove_item("portal");
            add_items(({"portal"}), "%^BLUE%^This portal rests just next to the "+
            "bed, it is outlined with a %^RED%^dark red%^RESET%^%^BLUE%^ "+
            "glow.  It is inactive, its magic long since ceased."+
            "%^RESET%^");
        }
        if(sizeof(HasHeads)) 
        {
            HasHeads = ({});
            remove_exit("portal");
        }
    }
		
		
    if(resets_so_far < max_resets)
    {
        resets_so_far++;
    }
    ::reset();
    return;
}

int __Read_me(string str) 
{
    if(str == "walls" || str == "wall") 
    {
        if(objectp(TP)) 
        {
            if(!TP->query("second_burial_name")) 
            {
                TP->set("second_burial_name", "enagmus");
            }
        }
		
    write(
@SAIDE
%^RED%^Kinorda lays dead, I have eaten his bones and feasted 
on his flesh.  If you are to ever leave this place, bring the four
rended heads of the fire generals, the imp king, the elemental lord, 
the golem master, and last, but not least, the hound keeper.  Toss 
them into the portal and it will open, but not before then. %^RESET%^

The War Mongrel

%^BOLD%^%^WHITE%^Another word rests beneath this disturbing message, written in a more
careful script, it is simply '%^RESET%^Enagmus%^BOLD%^%^WHITE%^'.%^RESET%^
SAIDE
);
    if(!TP->query_invis()) 
    {
        tell_room(TO,TPQCN+"%^RED%^ walks up to the walls, examining them"+
        " and frowning slightly as "+TP->QS+
        " reads the message.%^RESET%^", TP);
    }
    return 1;
    }
    return 0;
}


