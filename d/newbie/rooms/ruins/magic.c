//magic.c

#include <std.h>
#include <move.h>
#include "../../newbie.h"

#define COMPONENTS ({ "adders stomach", "aluminum chaff", "bat guano", "bit of bone", "blessed leather", "clear crystal", "colored sand", "corn extract", "crystal", "dart", "drop of blood", "dung scrapings", "earth from grave", "iron rod", "eyelash", "feather", "firefly", "flint", "gum arabic", "minute tarts", "owlfeather", "parchment", "pearl", "piece of bone", "phosphorus", "phosphorescent moss", "piece of iron", "piece of reed", "pinch of special dust", "powdered rhubarb leaf", "powdered silver", "rod of iron", "rose petals", "small candle", "spider web", "strip of parchment", "sulfur", "talc", "tiny bag", "zinc" })

inherit ROOM;

void find_item(object who);
int flag;

void create() {
    ::create();
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_short("The ruins of a town.");
    set_long(
@NEWBIE
You are standing amid the rubble of a ruined building with the roof open
to the sky. Rotten wood that once served as shelving line the remains of
walls. Various broken items litter the floor - pieces of paper, metal,
wood, glass, and other materials.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_search("default", "You don't see much but rubble unless you're going to search more thoroughly.");
    set_search("rubble",(:TO,"__Search":));
    set_items(([
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "east":N_RUINS"eroad4",
        "south":N_RUINS"bpath",
    ]));
}

void reset() {
    ::reset();
    flag = 0;
}

int __Search() {
    object ob;

    write("You dig through the rubble.");
    tell_room(TO,TPQCN+" searches through the rubble.",TP);
    if(flag){
        write("You find nothing.");
        return 1;
    }
    else{
        switch(random(10)) {
        case 0..2:
            write("You pull something out of the pile!");
            tell_room(TO,TPQCN+" finds something in the rubble.",TP);
            find_item(TP);
            flag = 1;
            break;
        case 3..6:
            write("You cut yourself on some sharp debris!");
            TP->do_damage("right hand",random(3)+1);
            break;
        default:
            write("You find nothing.");
            break;
        }
    }
    if(!flag && random(2)) flag = 1;
    return 1;
}

void find_item(object who){
    object ob;
    int i;

    switch(random(15)){
    case 0..3:
        ob = new("/d/magic/scroll");
        ob->set_spell(random(3)+1);
        break;
    case 4..8:
        ob = new("d/magic/store_comp");
        i = random(sizeof(COMPONENTS));
//setting id, name, & short added by Styx 7/10
        ob->set_name(COMPONENTS[i]);
        ob->set_id(({COMPONENTS[i],"component"}));
        ob->set_short(capitalize(COMPONENTS[i])+" (a spell component)");
// was -  ob->set_name(keys(COMPONENTS)[random(sizeof(keys(COMPONENTS)))]);
// and was using #define <components.h> which was in /adm/include
// It might have worked if the name and short had been set but I made a 
// shorter list to include here and made it a simple array instead.
        ob->set_comp_quantity(random(10)+1);
        break;
    case 9:
        ob = new(CPOTION"invisible");
        break;
    case 10:
        ob = new(CPOTION"paralyze");
        break;
    case 11:
        ob = new(CPOTION"poison");
        break;
    case 12:
	ob = new("/d/magic/safe_scroll");
        ob->set_spell(3);
	break;
    default:
        ob = new(HEALKIT);
        ob->set_uses(random(5)+1);
        break;
    }
    if(!ob->move(who) == MOVE_OK) ob->move(TO);
}
