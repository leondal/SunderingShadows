#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_long("%^BOLD%^You enter into the personal chamber rooms of Boquillas.%^RESET%^\n"
        "%^BOLD%^%^BLACK%^The room is very dark, not one window exists, and "
        "you have only the pale glow of a candle to see by. The walls are "
        "lined with bookcases full of books, scribed out by the bishop's own "
        "hand you would assume. In the corner you see a very plain and simple "
        "bed made of straw. On the bed sits an older gentleman, hunched over "
        "with his head in his hands. He looks very weary and stressed at the "
        "moment.%^RESET%^");
 
    set_exits(([
        "south"     :TOWN+"cast11"
             ]));
  
    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","You can hear nothing within these walls.");

    set_pre_exit_functions(({"south"}),({"go_south"}));

}

int go_south()
{
    object ob;
    if(present("morock"))
    {
        tell_object(TP,"%^BOLD%^%^RED%^Get back here "+TP->QCN+", I'm not done with you "
            "yet!%^RESET%^");
        return 0;  
    }
    return 1;
}

void reset()
{
    ::reset();
    if(!present("bishop")) { new(MON"bishop")->move(TO); }
}
