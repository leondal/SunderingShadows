#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(35+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("City street");
   set_short("%^RESET%^%^BLUE%^City street%^RESET%^");
   set_smell("default","%^RESET%^%^ORANGE%^Somehow despite the depth underground, the air is "
"%^BOLD%^%^WHITE%^cr%^CYAN%^is%^WHITE%^p %^RESET%^%^ORANGE%^and %^GREEN%^clear%^ORANGE%^.%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^The %^MAGENTA%^m%^RED%^u%^ORANGE%^r%^MAGENTA%^m%^RED%^u"
"%^MAGENTA%^r %^GREEN%^of a busy city surrounds you on all sides.%^RESET%^");
   set_items(([
     ({"darkness","ceiling","air"}):"%^BLUE%^The ceiling is too high up to be seen by normal vision, as you "
"can only see %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ "
"above you.%^RESET%^",
     ({"posts","poles","post","pole","fire","globe","globes","obsidian"}):"%^BLUE%^At even intervals along "
"the street's length are slender posts carved from %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian"
"%^RESET%^%^BLUE%^.  Etchings of %^RED%^li%^MAGENTA%^th%^RED%^e %^BLUE%^drow figures intertwine with the "
"silhouettes of %^WHITE%^wraith%^CYAN%^li%^RESET%^ke sp%^CYAN%^i%^RESET%^ders%^BLUE%^, all the way up to the "
"pale globe of %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire %^BLUE%^at the top of each post.  The globes "
"shed faint light around the area, providing the only real illumination in the darkness.%^RESET%^",
     ({"street","streets"}):"%^BLUE%^The %^ORANGE%^st%^BOLD%^%^BLACK%^on%^RESET%^%^ORANGE%^e %^BLUE%^of the "
"street is smooth beneath your feet, and clear of dirt and trash.%^RESET%^",
   ]));
}

void init() {
    ::init();
    if(!present("daroldralychaixxx",TP)) new(OBJ"cityward")->move(TP);
}