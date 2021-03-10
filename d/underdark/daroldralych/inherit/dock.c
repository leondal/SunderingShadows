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
   set_name("Warehouse district");
   set_short("%^RESET%^%^BLUE%^Warehouse district%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^Warehouse district%^RESET%^\n"
"%^BLUE%^The wide road runs along here, beside the edge of the warehouse district and the great %^BOLD%^black lake "
"%^RESET%^%^BLUE%^to the north.  Smooth stone forms the ground beneath your feet, allowing for ease in "
"walking.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ "
"fills the air above you, the ceiling too high up to be seen by any form of normal vision.  Upon the northern side of the "
"road are collected numerous %^RED%^w%^ORANGE%^a%^RED%^re%^ORANGE%^ho%^RED%^us%^ORANGE%^e%^RED%^s%^BLUE%^, some tightly "
"closed while others are obviously in the middle of a bustling business.  At short intervals along the southern side of "
"the street are slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each "
"supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire %^BLUE%^that sheds faint light around it.");
   set_smell("default","%^RESET%^%^ORANGE%^The %^BOLD%^%^WHITE%^cr%^CYAN%^is%^WHITE%^p%^RESET%^%^ORANGE%^, "
"clear air carries a smell reminiscent of a %^BLUE%^su%^BOLD%^rf%^CYAN%^a%^WHITE%^c%^CYAN%^e l%^BLUE%^ak%^RESET%^%^BLUE%^e"
"%^ORANGE%^.%^RESET%^");
   set_listen("default","%^RESET%^%^RED%^N%^BOLD%^oi%^RESET%^%^RED%^sy %^GREEN%^sounds of hustle and bustle "
"fill the cavern here.%^RESET%^");

   set_items(([
     ({"darkness","ceiling","air"}):"%^BLUE%^The ceiling is too high up to be seen by normal vision, as you "
"can only see %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ above "
"you.%^RESET%^",
     ({"posts","poles","post","pole","fire","globe","globes","obsidian"}):"%^BLUE%^At even intervals along "
"the street's southern side are slender posts carved from %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian"
"%^RESET%^%^BLUE%^.  Etchings of %^RED%^li%^MAGENTA%^th%^RED%^e %^BLUE%^drow figures intertwine with the "
"silhouettes of %^WHITE%^wraith%^CYAN%^li%^RESET%^ke sp%^CYAN%^i%^RESET%^ders%^BLUE%^, all the way up to the "
"pale globe of %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire %^BLUE%^at the top of each post.  The globes "
"shed faint light around the area, providing the only real illumination in the darkness.%^RESET%^",
     "lake":"%^BLUE%^The %^BOLD%^dark lake %^RESET%^%^BLUE%^stretches out toward the northern horizon, fading "
"into the distant %^BLACK%^%^BOLD%^s%^RESET%^%^BLUE%^ha%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^ow%^BOLD%^%^BLACK%^s "
"%^RESET%^%^BLUE%^of the cavern.%^RESET%^",
     ({"warehouse","warehouses"}):"%^BLUE%^Numerous %^RED%^w%^ORANGE%^a%^RED%^re%^ORANGE%^ho%^RED%^us%^ORANGE%^e%^RED%^s "
"%^BLUE%^line the northern side of the street here, storing a variety of stock for different drow houses.  "
"Some are very %^CYAN%^q%^GREEN%^uie%^CYAN%^t %^BLUE%^at the moment, perhaps not in use, although many are "
"bustling with the day's activities.%^RESET%^",
     ({"street","streets"}):"%^BLUE%^The %^ORANGE%^st%^BOLD%^%^BLACK%^on%^RESET%^%^ORANGE%^e %^BLUE%^of the "
"street is smooth beneath your feet, and clear of dirt and trash.%^RESET%^",
   ]));
}

void init() {
    ::init();
    if(!present("daroldralychaixxx",TP)) new(OBJ"cityward")->move(TP);
}