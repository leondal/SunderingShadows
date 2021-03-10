#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit CROOM;
int has_camp, is_trapped, searched, is_ambushed, random_stuff_setup;

void set_has_camp(int x) { has_camp = x; }
int query_has_camp() { return has_camp; }
void set_is_trapped(int x) { is_trapped = x; }
int query_is_trapped() { return is_trapped; }

void camps(object where);
void remove_camps(object where);
void place_trap();

void populate_area()
{
    string *list;
    int x;
    list = ({});
    for(x = 0;x < sizeof(INV_ROOMS);x++) 
    {
        list += ({"/d/deku/forest/dforest"+INV_ROOMS[x]});
        continue;
    }
    if(member_array(base_name(TO),list) == -1) 
    {
        switch(random(14)) 
        {
            case 0..1: 
                if((string)EVENTS_D->query_time_of_day() == "night") 
                { 
                    set_monsters(({"/d/deku/keep/monster/werewolf"}),({1 + random(3)}));
                }         
                break;
            case 2..3: 
                set_monsters(({"/d/deku/monster/owlbear"}),({2 + random(3)}));
                break;
            case 4..7:
                set_monsters(({"/d/deku/monster/goblin"}),({3 + random(4)}));
                break;
            case 8..13:
                set_monsters(({}), ({}));
                break;
            }
            
            set_repop(35);           
    }
}

void setup_random_stuff()
{
    string room_name;
    object ob, drak;
    random_stuff_setup = time() + 60;
    if(!random(10)) {
        is_ambushed = 0;
    }
    FENC->dissolve_me(TO);
    if((string)EVENTS_D->query_time_of_day() == "night") {
        camps(TO);
    }
    if((string)EVENTS_D->query_time_of_day() != "night") {
        remove_camps(TO);
    }
    if(!random(100) && !query_is_trapped() && !present("ettin",TO)
    && !query_has_camp()) {
        place_trap();
    }
    if(!random(125)) {
        FENC->place_hag(TO);
    }
    if(!random(125)) {
        FENC->place_athach(TO);
    }
    if(!random(50)) {
        FENC->make_gnoll_pack(TO);
    }
    if(!random(50)) {
        FENC->make_kobold_gang(TO);
    }
    if(present("werewolf",TO) && 
      !userp(present("werewolf",TO)) && 
      (string)EVENTS_D->query_time_of_day() != "night") {
        FENC->remove_werewolf(TO);
    }
    if(!random(50)) {
        FENC->doomsday_voice(TO);
    }
    //FENC->dissolve_me(TO);

    if(!random(70)) 
    {   
        //tell_object(find_player("saide"), "It is getting here...");
        if(objectp(environment(find_object_or_load("/d/deku/monster/drakkan")))) {
            return;
        }

        room_name = replace_string(base_name(TO),"/d/deku/forest/dforest","");
        if(member_array(room_name,INV_ROOMS) != -1) {
            drak = find_object_or_load("/d/deku/monster/drakkan");
            drak->move(TO);
            ob = "/d/magic/obj/treant";
            ob->set_hp(((int)ob->query_max_hp()) + 350 + random(151));
            ob->set_attacks_num(2 + random(3));
            ob->set_overall_ac(0 - random(5));
            ob->add_attack_bonus(1 + random(3));
            ob->move(TO);    
            drak->add_follower(ob);
            ob->force_me("protect drakkan");
            ob->force_me("protect drakkan");
            ob->force_me("protect drakkan");
            ob->force_me("protect drakkan");
            ob->set_hidden(1);
            return;
        }
    }
}

void create() 
{
    if(!random(2) && strsrch(base_name(TO), "/d/deku/inherits") != -1) populate_area();
    ::create();
    set_short("%^BOLD%^%^BLACK%^Deep in Shadowlord Forest%^RESET%^");
    set_name("Deep in Shadowlord Forest");
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_long("%^BOLD%^%^BLACK%^The forest around you sprawls "+
    "into every direction as far "+
    "as the eye can see.  The %^GREEN%^trees%^BOLD%^"+
    "%^BLACK%^ here shoot upard, some of them as "+
    "far as several hundred feet, with much younger "+
    "%^RED%^saplings%^BOLD%^%^BLACK%^ dwelling beneath them.  "+
    "The once proud and powerful %^BOLD%^%^GREEN%^limbs"+
    "%^BOLD%^%^BLACK%^ of both sapling and tree are now "+
    "withered and gnarled, falling ever more frequently "+
    "to the already covered %^GREEN%^ground%^BOLD%^%^BLACK%^.  "+
    "A mysterious %^WHITE%^dark fog%^BOLD%^%^BLACK%^ seeps "+
    "up and out of the ground.  It hangs over everything in the "+
    "forest, shrouding the entire area and offering a %^BLUE%^cold "+
    "chill%^BOLD%^%^BLACK%^ to anyone having found themselves here.");
  
   
    set_listen("default","Strange sounds echo through the "+
    "forest.");
    set_smell("default","You smell the decaying of the forest.");
    
    set_items(( [
     "forest" : "You find yourself in the forest.",
     ({"trees","large trees"}) : "%^GREEN%^The large trees of "+
     "this forest sprout upward and some reach several hundred "+
     "feet into the sky.  Their once proud and powerful limbs now hang withered and "+
     "gnarled and are ever falling away to the already covered "+
     "ground.%^RESET%^",
     ({"chill","cold chill"}) : "%^BLUE%^A cold chill courses "+
     "through your body as your flesh is bathed in the "+
     "thick fog.%^RESET%^",
     ({"saplings","sapling","dead saplings"}) : "%^GREEN%^"+
     "These saplings have gnarled and withered and their once "+
     "powerful limbs now fall away ever more frequently to add "+
     "to the already covered ground.%^RESET%^",
     ({"fog","thick fog","heavy fog","dark fog"}) : 
     "%^BOLD%^%^WHITE%^This dark and thick fog seems to seep "+
     "up from the ground.  It shrouds the entire forest and "+
     "offers you a %^BLUE%^cold chill%^BOLD%^%^WHITE%^ as "+
     "it comes into contact with your flesh.%^RESET%^",
     ({"limbs","gnarled limbs","withered limbs"}) : "%^GREEN%^"+
     "The limbs of the trees and saplings here have become "+
     "withered and gnarled.  They now fall ever more "+
     "frequently to the already covered ground.%^RESET%^",
     ({"ground"}) : "%^BOLD%^%^GREEN%^The ground of the "+
     "forest is littered with rotted tree limbs and a other "+
     "debris that have found there way down to it.  It is "+
     "hard to make out the exact composition of the matter as a "+
     "thick and heavy fog seems to seep upward from it."+
     "%^RESET%^",
    ] ));
    set_search("default","%^BOLD%^%^GREEN%^Perhaps something of interest "+
    "could have fallen to the %^RESET%^%^GREEN%^ground%^BOLD%^%^GREEN%^ and mixed with the "+
    "heavy debris?%^RESET%^");
    set_search("ground",(:TO,"ground_search":));
}

int ground_search() 
{
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^BOLD%^%^GREEN%^ searches around "+
        "on the heavily covered ground.%^RESET%^",TP);
    }
    tell_object(TP,"%^BOLD%^%^BLACK%^You search around on the "+
    "heavily covered ground.%^RESET%^");
    if(searched == 0 && !random(20)) {
        tell_object(TP,"%^GREEN%^You stumble onto something of "+
        "value.%^RESET%^");
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+"%^GREEN%^ finds something of "+
            "interest buried on the covered ground.%^RESET%^",TP);
        }
        SD->find_stuff(TO,"random");
        searched = 1;
        return 1;
    }
    tell_object(TP,"%^GREEN%^You give up the search and hope "+
    "you did not disturb anything...%^RESET%^");
        
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^GREEN%^ gives up the search, quickly "+
        "pulling back "+TP->QP+" hand.%^RESET%^",TP);
    }

    searched = 1;
    return 1;
}

void bandit_ambush(string exit1, string exit2, string exit3, object where) {
    string exit;
    if(!random(30) && (string)EVENTS_D->query_time_of_day() != "night") {
        switch(random(3)) {
            case 0:
                exit = exit1;
                break;
            case 1:
                exit = exit2;
                break;
            case 2:
                exit = exit3;
                break;
        }
        if(!exit) return;
        set_pre_exit_functions(({exit}),({"bandits_ambush"}));
    }
}

int bandits_ambush() {
    int num, x;
    string msg;
    num = 2 + random(3);
    if(!present("bandit",TO) && !TP->query_invis() && !is_ambushed) {
        is_ambushed = 1;
        write("You are suprised by a group of bandits!");
        for(x = 0;x < num;x++) {
            new("/d/deku/monster/bandit")->move(TO);
        }
        return 0;
    }
    return 1;
}

void reset() 
{
    int flag;
    if(strsrch(base_name(TO), "/d/deku/inherits/") != -1) { flag = 1; }
    if(!random(3) && !flag) populate_area();
    ::reset();
    if(!flag && time() > random_stuff_setup) { setup_random_stuff(); }
}
    
void camps(object where) 
{
    string rn;
    if(member_array(base_name(where),INV_C_ROOMS) == -1) {
        rn = base_name(TO);
        rn = replace_string(rn,"/d/deku/forest/dforest","");
        if(member_array(rn,INV_ROOMS) != -1) { return; }
        if(member_array(base_name(where),SAVE_D->query_array(CAMPS)) == -1) {
            if(!random(20)) {  
                FENC->place_camps(where,1);
            }
            return;
        }
        if(member_array(base_name(where),SAVE_D->query_array(CAMPS)) != -1) {
            if((int)where->query_has_camp() != 1) {
                FENC->place_camps(where,0);
            }
            return;
        }
    }
}

void remove_camps(object where) {
    if(member_array(base_name(where),SAVE_D->query_array(CAMPS)) != -1) {
        if((int)where->query_has_camp() == 1) {
            FENC->remove_camps(where);
        }
        SAVE_D->remove_name_from_array(CAMPS,base_name(where));
    }
}

void place_trap() {
    string exit, *exits;
    exits = TO->query_exits();
    if(sizeof(exits) < 1) { 
        return;
    }
    exit = exits[random(sizeof(exits))];
    set_pre_exit_functions(({exit}),({"covert_ettin"}));
    set_is_trapped(1);
}

int covert_ettin() {
    int num, x;
    string msg;
    if(query_is_trapped()) {    
        num = 1 + random(2);
        if(num == 1) {
            msg = "A two headed giant sprints out from behind one "+
            "of the massive trees!";
        }
        else {
            msg = num+ " two headed giants sprint out from behind "+
            "some of the massive trees!";
        }
        tell_room(TO,"%^RED%^"+msg+"%^RESET%^");
        for(x = 0;x < num;x++) {
            new("/d/deku/monster/ettin")->move(TO);
        }
        set_is_trapped(0);
        return 0;
    }
    return 1;
}
