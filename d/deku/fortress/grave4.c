#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

int amt;

/*void remove_hole() {
    if(pointerp(TO->query_exits()) &&
    member_array("hole",TO->query_exits()) != -1) { 
        tell_room(TO,"%^YELLOW%^Enough loose dirt is suddenly "+
        "wiped into the %^BOLD%^%^BLACK%^dark hole%^RESET%^"+
        "%^YELLOW%^ to fill it up!%^RESET%^");
        tell_room(TO,"%^CYAN%^The outline of a giant disembodied "+
        "hand is briefly visible, before it vanishes into thin "+
        "air!%^RESET%^");
         remove_item(({"hole","dark hole"})); 
         amt = 15 + random(16);
         remove_exit("hole");
    }
}

void add_hole() {
    TO->add_exit("/d/deku/fortress/hole1","hole");
    TO->add_item(({"hole","dark hole"}),"%^BOLD%^%^BLACK%^This "+
    "dark hole is at the bottom of one of the nearby graves, "+
    "it appears to be the results of something recent digging."+
    "%^RESET%^");
}*/

void create() {
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  A %^RESET%^stone wall%^BOLD%^%^WHITE%^"+
    " runs along the outside of the graveyard here.%^RESET%^");
    
    add_item(SW_ITEM,"%^BOLD%^%^WHITE%^This pathetic stone wall is only around two feet "+
    "high and is mostly in a state of ruin.  It runs toward the north and the south here, "+    
    "serving as a marker for the territory of the graveyard.%^RESET%^");
    
    set_exits(([
    "north" : GY_ROOMS +"grave5",
    "south":GY_ROOMS +"grave3",
    "west" : GY_ROOMS +"grave4-1"
    ] ));
    amt = 15 + random(16);
       
}

void reset() {
    ::reset();
   /* if(!random(3)) {
        remove_hole();
        find_object_or_load(GY_ROOMS+"hole1.c")->remove_hole();
    }*/
}

int lost_balance(object who, int mod) {
    if(who->query_stats("dexterity") < (roll_dice(5,5) - mod)) { 
        return 1;
    }
    return 0;
}

/*void do_fall(int x, object who) {
    if(!objectp(who)) return;
    if(!lost_balance(who, x)) {
        if(x) {
            tell_object(who,"%^BLUE%^You manage to grab hold "+
            "of something and stop your fall!%^RESET%^");
            if(!who->query_invis()) {
                tell_room(environment(who),who->QCN+" %^BLUE%^ "+
                "suddenly reaches out and manages to grab hold of "+
                "something to break "+who->QP+" fall!%^RESET%^",who);
            }
            who->remove_paralyzed();
        }
        return;
    }
    else {
        who->set_paralyzed(10000,"%^RED%^You are tumbling down "+
        "into the dark hole!%^RESET%^");
        if(!x) {
            tell_object(who,"%^RED%^To your sudden horror "+
            "you lose your balance and tumble "+
            "head first into the %^BOLD%^%^BLACK%^dark hole!%^RESET%^");
            if(!who->query_invis()) {
                tell_room(environment(who),who->QCN+"%^RED%^ suddenly "+
                "loses "+who->QP+" balance and tumbles head first "+
                "into the %^BOLD%^%^BLACK%^dark hole!%^RESET%^",who);
            }
        }
        else {
            tell_object(who,"%^RED%^You scream loudly as your body "+
            "begins to tear from the force of the descent!%^RESET%^");
            who->do_damage("torso",roll_dice(1,10));
            tell_room(environment(who),who->QCN+"%^RED%^ screams "+
            "loudly as "+who->QS+" tumbles down the hole!%^RESET%^",who);
        }
    }
       
    switch(x) {
        case 0:
            who->move(find_object_or_load(GY_ROOMS+"hole1"));
            break;
        case 1:
            who->move(find_object_or_load(GY_ROOMS+"hole2"));
            break;
        case 2:
            who->move(find_object_or_load(GY_ROOMS+"hole3"));
            break;
        case 3:
            who->move(find_object_or_load(GY_ROOMS+"hole4"));
            break;
        case 4:
            who->move(find_object_or_load(GY_ROOMS+"narameons_chamber2"));
            tell_object(who,"%^YELLOW%^With a loud %^RED%^THUD"+
            "%^YELLOW%^ you land in a heap on a "+
            "packed dirt floor!%^RESET%^");
            if(!who->query_invis()) {
                tell_room(environment(who),who->QCN+"%^YELLOW%^ "+
                "lands on the packed dirt floor with a loud %^RED%^"+
                "THUD%^YELLOW%^!%^RESET%^",who);
            }
            else {
                tell_room(environment(who),"%^YELLOW%^A loud "+
                "%^RED%^THUD%^YELLOW%^ echoes through the chamber!"+
                "%^RESET%^",who);
            }
            who->remove_paralyzed();
            break;
    }
    if(x < 4) {
        x++;
        call_out("do_fall",2 + random(3),x,who);
    }

}*/

int do_dig_hole(object who) {
    object room;
    //if(member_array("hole",TO->query_exits()) != -1) {
        return ::do_digging(who);        
    /*}
    if(amt) {
        tell_object(who,"You continue digging down into the "+
        "grave.... ");
        if(!random(4)) {
            tell_object(who,"%^RED%^You scrape against something "+
            "sharp in the soil!%^RESET%^");
            who->do_damage("left hand",3 + random(6));
        }
        if(!who->query_invis()) {
            tell_room(TO,who->QCN +" continues digging down into "+
            "one of the open graves...",who);
        }
        if(who->query_invis()) {
            tell_room(TO,"Dirt continues flying up from one "+
            "of the open graves and it appears to be getting "+
            "%^BOLD%^%^BLACK%^deeper!%^RESET%^",TP);
        }
        amt--;;
        call_out("do_dig_hole",2 + random(4),who);
        return 1;
    }
    add_hole();
    room = find_object_or_load(GY_ROOMS+"hole1.c");
    if(objectp(room)) {
        room->add_hole();
        tell_room(room,"%^YELLOW%^The thick, clumped dirt above "+
        "your head suddenly gives away!%^RESET%^");
    }
    tell_object(who,"%^RED%^Through your continued efforts you "+
    "manage to uncover a %^BOLD%^%^BLACK%^dark hole%^RESET%^%^RED%^"+
    ".....");
    if(who->query_invis()) {
        tell_room(TO,"%^RED%^Suddenly one of the graves gives away "+
        "to reveal a %^BOLD%^%^BLACK%^dark hole!%^RESET%^",who);
    }
    if(!who->query_invis()) {
        tell_room(TO,who->QCN+"%^RED%^ continues digging and suddenly "+
        "stumbles upon a %^BOLD%^%^BLACK%^dark hole!%^RESET%^",who);
    }
    
    do_fall(0, who);
    digging = 0;
    who->remove_paralyzed();*/
}

int dig_function(string str) {
    if(!str) {
        dig_where();        
        return 1;
    }
    if(str == "in graves" || str == "graves" || str == "grave" 
    || str == "burial places") {
        if(digging == 1) {
            write("Someone is already digging in that grave!");
            return 1;
        }
        write("You drop to the ground and begin digging down "+
        "into one of the open graves!");
        write("press <RETURN> to stop digging.");
        input_to("dig_activity",1);
        TP->set_paralyzed(10000,"You are busy digging into one of "+
        "the graves!");
        digging = 1;
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+" drops to the ground and begins "+
            "digging down into one of the open graves!",TP);
        }
        if(TP->query_invis()) {
            tell_room(TO,"You notice dirt begin flying out of "+
            "one of the open graves and you almost think "+
            "that someone is digging down into it.",TP);
        }
        call_out("do_dig_hole",2 + random(4),TP);
        return 1;
    }
    return 0;
}



