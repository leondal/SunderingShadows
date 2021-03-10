#include <std.h> 
inherit VAULT;

#define GUILD_MEMBERS ({ "tara", "sherlock" })

void create() { 
    ::create(); 
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(OLD_MOUNTS);
    set_travel(FOOT_PATH);
    set_name("Old looking Stronghold");
    set_short("%^BOLD%^%^BLACK%^Old looking Stronghold%^RESET%^"); 
    set_long("The rushing %^BLUE%^stream%^RESET%^ flows under this %^ORANGE%^"
"drawbridge%^RESET%^. On the other side of the drawbridge are two huge "
"%^BOLD%^%^BLACK%^stone doors%^RESET%^. The walls look to have seen a lot of "
"%^BOLD%^%^WHITE%^combat%^RESET%^ but have been replaced in any spots that "
"needed it."); 
    set_smell("default","The smell from the city lingers down here as well.");
    set_listen("default","The sounds of people can be heard all around here.");
    set_exits(([ 
      "northeast":"/d/guilds/order/hall/path3",
      "south":"/d/guilds/order/hall/main",
    ])); 
    set_door("stone doors","/d/guilds/order/hall/main","south","ihasnokeylawl");
    set_door_description("stone doors","%^BOLD%^%^BLACK%^These huge stone "
"doors could only have been made by some of the greatest smiths around. "
"Almost 8 inches thick, and with no visible locks on or around the door. "
"Small words are engraved onto the door, which reads '%^YELLOW%^In Memory of "
"the Metallic Dragons%^BLACK%^'.%^RESET%^");
    set_locked("stone doors",1);
}

void init() {
    ::init();
    add_action("say_func","say");
}

int say_func(string str) {
    string str2;
    object theroom;
    if(TP->query_property("passwordsuspend")) return 0;
    if(member_array(TP->query_name(), GUILD_MEMBERS) == -1 && !avatarp(TP))
      return 0;
    str2 = "/daemon/filters_d"->filter_colors(str);
    if(str2 != "Bill" && str2 != "bill") return 0;
    TP->set_property("passwordsuspend",1);
    TP->force_me("say "+str);
    if(TP->query_property("passwordsuspend"))
      TP->remove_property("passwordsuspend");
    theroom = find_object_or_load("/d/guilds/order/hall/main");

    if(!query_locked("stone doors")) {
      tell_room(TO,"%^BOLD%^%^BLACK%^A heavy clunk echoes from the doors' "
"locking mechanism as "+TP->QCN+" utters the word.%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^%^BLACK%^A heavy clunk echoes from the doors' "
"locking mechanism as you utter the word and they unlock.%^RESET%^");
      TO->set_open("stone doors",0);
      TO->set_locked("stone doors",1);
      theroom->set_locked("stone doors",1);
      theroom->set_open("stone doors",0);
      return 1;
    }
    tell_room(TO,"%^BOLD%^%^BLACK%^A heavy clunk echoes from the doors' "
"locking mechanism as "+TP->QCN+" utters the word.%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^%^BLACK%^A heavy clunk echoes from the doors' "
"locking mechanism as you utter the word and they lock again.%^RESET%^");
    TO->set_open("stone doors",0);
    TO->set_locked("stone doors",1);
    theroom->set_locked("stone doors",1);
    theroom->set_open("stone doors",0);
    return 1;
}