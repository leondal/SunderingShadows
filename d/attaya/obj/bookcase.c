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
    write("\n\%^ORANGE%^The Best of Times.");
    write("\n\%^RED%^Taxidermy Made Easy Using Chemicals and Equipment You Probably Already Have.");
    write("\n\%^BOLD%^%^RED%^The Ground Squid.");
    write("\n\%^BLUE%^Escape from Tharis.");
    write("\n\%^GREEN%^How to Get Great Looking Stats Without Sweating.");
    write("\n\%^BOLD%^%^BLUE%^Doom Book II.");
    write("\n\%^BOLD%^%^BLACK%^A Night to Dismember.");
    write("\n\%^YELLOW%^Everything I Ever Wanted to Know About the Occult but was Afraid to Ask.");
    write("\n\%^BOLD%^%^GREEN%^The Sign.");
    write("\n\%^MAGENTA%^Macbeth II The Return of Banquo.");
    write("\n\%^BOLD%^McMillans' Encyclopedia vol. T.");
    write("\n\%^CYAN%^A Disney Reunion.");
    write("\n\%^RED%^BLOOD FLOWS RED ON THE SIDEWALK and other psalms.");
    write("\n\%^BOLD%^Dr. Ruth's Guide to Pleasing Your Partner.");
    write("\n\%^BOLD%^%^MAGENTA%^Citadel of Whispers.");
    write("\n\%^GREEN%^Mein Kamph.");
    write("\n\%^BLUE%^Mein Hund ist Unter die Koffer Kuli.");
    return 1;
}

