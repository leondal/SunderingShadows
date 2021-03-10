#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("profile");
    set_id(({"profile","area profile"}));
    set_short("%^BOLD%^%^MAGENTA%^Area profile");
    set_long(
      "%^BOLD%^%^MAGENTA%^This is a general profile of this continent.  It will tell you important information about it."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "profile") return  0;

    tell_room(environment(TO),TPQCN+" reads the area profile!",TP);
    write("%^CYAN%^Area Name: %^RESET%^%^BOLD%^Attaya.\n");
    write("%^CYAN%^Area Type: %^RESET%^continent.\n");
    write("%^CYAN%^Climate: %^RESET%^temperate.\n");
    write("%^CYAN%^Location: %^RED%^<28'43>.\n\n");
    write("%^CYAN%^Difficulty Ranking: %^RESET%^substantial.\n");
    write("%^CYAN%^Monster Frequency: %^RESET%^varies/high.\n");
    write("*Fights get more difficult as you get closer to the heart of the Kinnesaruda Empire.\n");
    write("%^CYAN%^Suggested Level to Adventure Here: %^GREEN%^25+.\n\n");
    write("*Hm parties recommended.\n");
    write("%^CYAN%^Sphere of Influence: %^BOLD%^%^BLUE%^Kinnesaruda Empire.\n");
    return 1;
}

