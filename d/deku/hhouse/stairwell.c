#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(STAIRWAY);
    set_name("A wooden stairwell");
    set_short("A wooden stairwell");
    set_property("no sticks",1);

    set_long("%^YELLOW%^You find yourself in a stairwell made "+
    "from a %^RED%^crimson stained%^BOLD%^%^GREEN%^ oak%^YELLOW%^.  "+
    "The %^BOLD%^%^BLACK%^stairs%^YELLOW%^ are not sturdy and "+
    "you fear they may give away at any moment.  Strangely, they "+
    "have been kept free of any debris and not even a speck of dust "+
    "disturbs their slow decay.  They continue downward and eventually "+
    "meet an %^BOLD%^%^GREEN%^oak door%^YELLOW%^.  Upward the stairs "+
    "meet with an opening that you could probably %^RED%^"+
    "climb%^YELLOW%^ out of with the proper skill or equipment."+
    "%^RESET%^");
       
    set_items(([
    ({"oak","stained oak","crimson stained oak"}) : "%^BOLD%^%^GREEN%^"+
    "The thick oak boards that have been carefully pieced together to "+
    "construct this stairwell are stained with %^RED%^crimson%^BOLD%^"+
    "%^GREEN%^.%^RESET%^",
    ({"stains","crimson stains"}) : "%^RED%^These stains adorn "+
    "the wood that constructs this stairwell.  They could "+
    "very well be the last remaining evidence of some massive "+
    "slaughter.%^RESET%^",
    ({"stairs","stairwell"}) : "%^GREEN%^The stairs you are "+
    "traveling on are flimsy and may give away at any moment.  "+
    "Oddly, someone has kept them free of debris and even dust.  "+
    "You wonder of their reasoning and wonder who would "+
    "risk spending time here to do such a thing.%^RESET%^",
    ({"opening","open"}) : "%^BOLD%^%^BLACK%^This opening leads out "+
    "of the decaying stairwell you find yourself in.  You will need "+
    "to %^RED%^climb%^BOLD%^%^BLACK%^ out to make it and to do that "+
    "you will need to either have the proper tools or the proper "+
    "skills.%^RESET%^",
    ]));
    
    set_exits(([
    "exit": BH_ROOMS+"hideout6",
    ]));
    set_climb_exits((["climb":({HH_ROOMS+"living_3",20,30,100})]));
    set_fall_desc("You fall and land forcefully on the top of the wooden stairwell!");
    set_door("oak door",BH_ROOMS+"hideout6", "exit");
    set_locked("oak door",0);
    set_door_description("oak door","%^GREEN%^This door is made "+
    "from four slabs of oak that have been tightly bound together "+
    "with a thick and coarse rope.%^RESET%^");
    
    set_search("default","%^RED%^There is nothing that offers "+
    "concealment here.%^RESET%^");

    set_listen("default","The stairs you are on creak loudly.");
    set_smell("default","You catch a strong scent of soured water.");
}


