#include "../defs.h"

inherit INH+"assassin";

void create()
{
    set_short("%^BOLD%^%^BLACK%^A Scroll Shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A Scroll Shop%^RESET%^
%^RESET%^%^ORANGE%^This is perhaps the only room in the entire tower that attempts to be dry. %^GREEN%^Old books %^ORANGE%^of spells sit upon rickety shelves, and %^BOLD%^%^BLACK%^heavy sconces %^RESET%^%^ORANGE%^provide the room with ample light. A %^BOLD%^%^RED%^f%^RESET%^%^RED%^a%^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^u%^BOLD%^g %^RESET%^%^ORANGE%^beneath your feet muffles the sounds of footsteps. A %^BOLD%^desk %^RESET%^%^ORANGE%^in the corner is covered in candles, providing even more light to the scriber of scrolls, who waits here quietly for your request. Typing %^WHITE%^<help shop> %^ORANGE%^will tell you what you can do here.%^WHITE%^
");
    set_smell("default","%^RESET%^%^CYAN%^The room smells of parchment and ink.%^WHITE%^");
    set_listen("default","%^RESET%^%^MAGENTA%^It is very quiet.%^WHITE%^");
    set_items(([
                   ({"floor","wall","ceiling"}) : "%^RESET%^%^ORANGE%^The walls here are surprisingly dry. Perhaps they've been magically fortified in order to protect the precious pages of books found here.%^WHITE%^",
                   "sconces" : "%^YELLOW%^Orbs burns steadily from the heavy sconces. Likely it is through magic or alchemy that they manage to shine so bright.%^RESET%^",
                   ({"candles","desk"}) : "%^YELLOW%^The flicker of the candles casts a warm glow across the old wooden desk. Parchment and inkwells neatly line the desk.%^RESET%^",
                   "scrolls" : "%^RESET%^%^MAGENTA%^You may wish to %^WHITE%^<list scrolls> %^MAGENTA%^to get a better look.%^WHITE%^",
                   ]));
    set_indoors(1);
    set_property("no teleport",1);
    set_exits(([
                   "west":ROOMS+"/assassinhall",
                   ]));
}

void init()
{
      ::init();
      if(!present("secundia",TO))
         find_object_or_load(MON+"/secundia")->move(TO);
}
