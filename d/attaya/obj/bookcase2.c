#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("bookcase");
    set_id(({"bookcase","case"}));
    set_short("Bookcase loaded with books");
    set_long(
      "A tall oak bookcase holds a variety of books.  You can 'read titles'"
    );
    set_weight(500);
    set_value(100);
}

int read(string str){
    if(!str || str != "titles") return  0;

    tell_room(environment(TO),TPQCN+" reads the book titles!",TP);
    write("\n\%^ORANGE%^A Guide to Poisons and Balms.");
    write("\n\%^BOLD%^%^RED%^How To Serve Man.");
    write("\n\%^BLUE%^French Poetry About Grapes  circa. 1047.");
    write("\n\%^GREEN%^Wicker Eyefork.");
    write("\n\%^BOLD%^%^BLUE%^Return to Torecladon.");
    write("\n\%^BOLD%^%^BLACK%^The Dark Dominion.");
    write("\n\%^YELLOW%^Diary of an Unhappy Camper.");
    write("\n\%^BOLD%^%^GREEN%^Everything You Never Needed to Know About Ferns and Silicon.");
    write("\n\%^MAGENTA%^An Autobiography of a Warrior: The Intruder Story.");
    write("\n\%^BOLD%^McMillans' Encyclopedia vol. X-Y-Z.");
    write("\n\%^CYAN%^Bang the Drum Slowly.");
    write("\n\%^BOLD%^Farmers' Almanac.");
    write("\n\%^BOLD%^%^MAGENTA%^The Unabridged NECRONOMICON.");
    write("\n\%^GREEN%^Consumer Reports Evaluates: %^RESET%^Gerbil Juicers, Storage Tubs, Shields, Construction Companies, and Cheeze Graters.");
    write("\n\%^RED%^The Walls Have Ears.");
    return 1;
}

