//First Level Template  - LoKi - 12-02-2008


#include <std.h>
#include "../ogres.h"

// changing this to croom instead of cvault.  I don't see any doors in the ogre caves 
// and vault rooms don't get cleaned up -Ares
//inherit CVAULT;
inherit CROOM;

object ob;
void pick_critters();



void create() {
    pick_critters();
    set_repop(30);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_name("dark cavern");
    set_short("%^RESET%^%^ORANGE%^d%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^"+
"%^ORANGE%^rk cave%^RESET%^%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^n%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The cav%^RESET%^%^RED%^e%^RESET%^%^ORANGE%^rn "+
"around you is huge, the ceiling towering high above you and the walls %^RESET%^"+
"%^BOLD%^%^BLACK%^shadowed%^RESET%^%^ORANGE%^. Very lit%^RESET%^%^RED%^tl%^RESET%^"+
"%^ORANGE%^e light illuminates the a%^RESET%^%^RED%^r%^RESET%^%^ORANGE%^ea, just "+
"enough to let you navigate around ro%^RESET%^%^RED%^c%^RESET%^%^ORANGE%^k "+
"outcroppings, and various piles of %^RESET%^%^BOLD%^%^RED%^m%^RESET%^%^BOLD%^"+
"%^BLACK%^u%^RESET%^%^BOLD%^%^RED%^til%^RESET%^%^RED%^a%^RESET%^%^BOLD%^%^RED%^ted"+
" c%^RESET%^%^RED%^o%^RESET%^%^BOLD%^%^RED%^rpses%^RESET%^%^ORANGE%^. Th%^RESET%^"+
"%^RED%^e%^RESET%^%^ORANGE%^ air is very still and h%^RESET%^%^RED%^e%^RESET%^"+
"%^ORANGE%^avy with moisture.\n\n%^RESET%^");
    set_smell("default","%^RESET%^%^ORANGE%^You smell fetid moisture...%^RESET%^");
    set_listen("default","%^RED%^%^BOLD%^You hear the distant sounds of skirmishes?%^RESET%^");

    set_items
    (([
        ({"floor", "ground", "outcroppings"}) : "%^RESET%^%^ORANGE%^The ground here is"+
"rough, uneven, and random outcroppings of rock make navigating difficult.%^RESET%^",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls here are rough, and"+
" mostly cloaked in shadows.%^RESET%^",
        ({"corpses"}) : "%^RESET%^%^ORANGE%^corpses of what look to be both ogres"+
" and various demons lay in varied stages of mutilation and decomposition. "+
"%^RESET%^%^YELLOW%^Rats %^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^%^WHITE%^maggots"+
" %^RESET%^%^ORANGE%^swarm over the more recent piles...%^RESET%^",
    ]));
}

void pick_critters(){
   switch(random(6)){
         case 0:   set_monsters(
({MOBS"ogre1",MOBS"ogre2"}),({random(2),random(2)}) );
                   break;
         case 1:   set_monsters(
({MOBS"ogre1",MOBS"ogre3"}),({random(2),random(1)}) );
                   break;
         case 2:   set_monsters(
({MOBS"ogre1",MOBS"ogre2"}),({1,random(1)+1,random(2)}) );
                   break;
         case 3:   set_monsters(
({MOBS"ogre1",MOBS"ogre2",MOBS"ogre4"}),({random(3),1,1}) );
                   break;
         case 4..5: break;
   }
}

//BEGIN TRAP CODE
int cavein(){
    string verb, exit;
    object *followers;
    int i;

    if(!interactive(TP)) return 1;
    verb = query_verb();
    followers = TP->query_followers();
    if(!followers) followers = ({});
    
    tell_object(TP, "As you move "+verb+" your foot catches on a wire and
you trip forward as the room starts to collapse down around you!");
    TP->do_damage("torso", roll_dice(5,10));
    if(followers != ({})){
        tell_object(TP, "Some of your companions try to dive through after
you!");
    }
 
    for(i = 0;i<sizeof(followers);i++){
     if(!objectp(followers[i])) continue;
        if(followers[i]->query_stats("dexterity") > random(30)) continue;
        followers -= ({followers[i]});
    }
    
    exit = query_exit(verb);

    for(i = 0;i<sizeof(followers);i++){
      if(!objectp(followers[i])) continue;
        tell_object(followers[i], "As "+TPQCN+" moves "+verb+", you quickly
dive after "+TP->query_objective()+", the ceiling collapsing down on top of
you!");
        followers[i]->do_damage("torso", roll_dice(5,10));
        followers[i]->move_player(exit);
    }
    TP->move_player(exit);
    tell_room(TO, "You cover your eyes as the ceiling comes crashing down
around you!", ({TP})+followers);
    
    collapse_exit(verb, 400);

    return 1;
}

//END TRAP CODE
