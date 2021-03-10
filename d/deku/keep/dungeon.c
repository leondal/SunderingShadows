#include <std.h>
#include "keep.h"
#include <daemons.h>

#define DUNGEONS ({ "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",\
"16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","32",\
"33","34","35","36","37","38","39","40","41","42","43","44","45","46","47" })

#define BONE_ROOMS ({ "blacktonguelair6","blacktonguelair7","blacktonguelair8",\
 "blacktonguelair9","blacktonguelair10","dungeon5","dungeon6","dungeon7","dungeon8",\
 "dungeon12","dungeon13","dungeon14","dungeon18","dungeon19","dungeon20","dungeon24",\
 "dungeon25","dungeon26","dungeon30","dungeon32","dungeon36","dungeon37",\
"dungeon38","dungeon42","dungeon43","dungeon44" }) 

#define LAIRS ({ "1","2","3","4","5","6","7","8","9","10" })

inherit CVAULT;
string shaltul_loc, parch_loc;
string *place_parch; 
int searched;
void place() 
{
    switch(random(2)) 
    {
        case 0:
            shaltul_loc = KEEPR + "dungeon" + DUNGEONS[random(sizeof(DUNGEONS))];
            break;
        case 1:
            shaltul_loc = KEEPR + "blacktonguelair" + LAIRS[random(sizeof(LAIRS))];
            break;
    }
    return shaltul_loc;
}

void create() 
{
    if(base_name(TO) != DUNGEON && !random(2)) 
    {
        set_monsters(({KEEPM +"werewolf"}), ({random(2) + 3})); 
        set_repop(55);
    }
   	set_no_clean(1);
    ::create();
    if(!random(2)) set_property("no sticks",1);
    set_property("no teleport",1);
    set_property("light",0);
    set_property("indoors",1);
    set_name("marble corridor");
    set_short("%^BOLD%^%^WHITE%^Marble Corridor%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_long("%^BOLD%^%^WHITE%^You find yourself in a narrow and forboding "+
    "corridor that is made entirely from %^BOLD%^%^BLACK%^dull marble"+
    "%^BOLD%^%^WHITE%^, etched with numerous %^CYAN%^hieroglyphic symbols"+
    "%^BOLD%^%^WHITE%^.  A very thick and %^RESET%^%^BLUE%^cold %^BOLD%^"+
    "%^BLACK%^darkness%^BOLD%^%^WHITE%^ lingers here, "+
    "permeating your very %^RED%^being%^BOLD%^%^WHITE%^.  You have found yourself "+
    "in an obviously very unnatural and very %^RED%^evil%^BOLD%^%^WHITE%^ dwelling place "+
    "of creatures you hope not to encounter.  Looking down you notice that the floor "+
    "of this corridor is littered with %^BOLD%^%^BLACK%^bones%^BOLD%^%^WHITE%^, "+
    "some of which still have bits and pieces of %^RED%^flesh%^BOLD%^%^WHITE%^ "+
    "attached.%^RESET%^");

    set_smell("default","The stench of decay lingers here.");
    set_listen("default","%^BOLD%^Growls echo from deep within the darkness.%^RESET%^");

    set_property("traps_known_to_monsters", KEEPM);
    set_property("random trap frequency", 30);
    set_property("random traps", "mid");

    set_items(([
    ({"hieroglyphics","symbols","hieroglyphic symbols","hieroglyphic"}) : "%^BOLD%^"+
    "%^BLACK%^These symbols depict the transformation of what appears to be a "+
    "%^RED%^human%^BOLD%^%^BLACK%^ into an upright wolf-like creature.  The various "+
    "stages of its transformation look quite painful as both bone and flesh are "+
    "manipulated in a very unnatural manner.  The author of these symbols paid "+
    "special attention to detail.  An uneasy feeling stirs within you.%^RESET%^",
    "bones" : "%^BOLD%^%^WHITE%^These bones are obviously the remains of the meal "+
    "or several meals of some type of beast.  Some of them still have pieces "+
    "of flesh attached, causing you to believe that the meals were rather recent.%^RESET%^",
    "walls" : "%^BOLD%^%^BLACK%^The walls of this corridor are covered with "+
    "numerous %^CYAN%^hieroglyphic symbols%^BOLD%^%^BLACK%^.  The symbols are "+
    "in strikingly vivid detail.%^RESET%^",
    "flesh" : "%^RED%^There are still bits and pieces of flesh on some of the "+
    "bones that lay here.%^RESET%^",
    ({"cold darkness","darkness"}) : "%^BOLD%^%^BLACK%^This darkness is thick "+
    "and very cold.  It permeates your being, soaking into you, and sending "+
    "chills through your body.  You fear what may be concealed by it as growls "+
    "echo from deep within.%^RESET%^",
    "evil" : "%^RED%^Yes... evil and evil alone could dwell in this place...%^RESET%^",
    "being" : "%^RED%^Your very being is assaulted by this "+
    "%^RESET%^%^BLUE%^cold%^RED%^, thick, darkness.%^RESET%^",
    "marble" : "%^BOLD%^%^BLACK%^This entire corridor is made from dull "+
    "marble.  It is etched with numerous %^RESET%^%^CYAN%^hieroglyphic "+
    "symbols%^BOLD%^%^BLACK%^.%^RESET%^",
    "floor" : "%^BOLD%^%^BLACK%^The floor of this corridor is littered "+
    "with the %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ of various creatures.%^RESET%^",
    ] ));

    set_search("default","You wonder if the bones could possibly conceal anything.");
    set_search("bones",(:TO,"bone_search":));
}

int bone_search(object ob) 
{
    object ob1;
    int find;
    tell_room(TO,TP->query_cap_name() + "%^BOLD%^%^WHITE%^ "+
    "searches through a pile of bones.%^RESET%^",TP);
    if(searched == 1) 
    {
        write("%^BOLD%^%^WHITE%^You search through the bones but "+
        "find nothing of value.%^RESET%^");
        return 1;
    }
    find = random(100);
    if(find >= 80) 
    {
        ob1 = SEARCH_D->do_found_object();
        write("%^BOLD%^%^WHITE%^You search through the bones "+
        "and find " + ob1->query_short() +"%^BOLD%^%^WHITE%^"+
        "!%^RESET%^");
        ob1->move(TO);
        searched = 1;
        return 1;
    }
    write("%^BOLD%^%^WHITE%^You search through the bones but "+
    "find nothing of value.%^RESET%^");
    searched = 1;
    return 1;
}

int jbone_search() 
{
    place_parch = SAVE_D->query_array(BPA);
    if(member_array(base_name(TO),place_parch) == -1) 
    {
        bone_search(TO);
        return 1;
    }
    tell_room(TO,TPQCN+"%^BOLD%^%^WHITE%^ digs through a pile "+
    "of bones.%^RESET%^",TP);
    write("%^BOLD%^%^WHITE%^You dig through a pile of bones and find "+
    "a piece of parchment!%^RESET%^");
    SAVE_D->remove_array(BPA);
    new(KEEPO + "journal2")->move(TO);
    return 1;
}

void reset() 
{
    object myob;
    int flag;
    ::reset();
    if(base_name(TO) == DUNGEON) 
    {
        if(!sizeof(SAVE_D->query_array(BPA))) 
        {
            parch_loc = KEEPR + BONE_ROOMS[random(sizeof(BONE_ROOMS))];
            SAVE_D->set_value(BPA,parch_loc);
        }
        if(!stringp(shaltul_loc)) place();
        KEEP_ENCOUNTERS_D->place_monster(KEEPM+"shaltul", shaltul_loc);		
    }
}
