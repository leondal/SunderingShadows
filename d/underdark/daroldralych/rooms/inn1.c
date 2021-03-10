#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("The Black Eclipse");
   set_short("%^BLUE%^The Black Eclipse%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The Black Eclipse%^RESET%^\n"
"%^BLUE%^This broad room, while obviously only a bar, is surprising by its %^CYAN%^e%^GREEN%^l%^CYAN%^eg%^GREEN%^an"
"%^CYAN%^t %^BLUE%^furnishings.  Beautifully carved %^RED%^zurk%^MAGENTA%^hw%^RED%^ood tables %^BLUE%^with a dark glossed "
"finish have been placed around the near side of the room, allowing plenty of space for patrons to sit and relax.  Upon "
"the walls, several tapestries of varied imagery adorn the walls, between the glowing torches of %^MAGENTA%^fae%^BOLD%^r"
"%^RESET%^%^MAGENTA%^ie fire %^BLUE%^that add only dim lighting to the room.  Running the length of the back wall is a "
"half-arc %^ORANGE%^stage%^BLUE%^, only marginally better lit than the rest of the room, and probably designed to hold "
"whatever form of entertainment this bar employs.  On the lefthand side of the room, towards the rear, is a short bartop "
"carved of the same %^RED%^gl%^MAGENTA%^os%^RED%^sed wo%^MAGENTA%^o%^RED%^d%^BLUE%^ as the tables, where all kinds of "
"food and drink are served.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The room is filled with a %^RESET%^sm%^BOLD%^%^BLACK%^ok%^RESET%^y h%^BOLD%^%^BLACK%^a"
"%^RESET%^ze %^ORANGE%^that is strangely %^MAGENTA%^so%^RED%^o%^MAGENTA%^thing%^ORANGE%^.");
   set_listen("default","%^GREEN%^The sound of quiet, %^CYAN%^exo%^BOLD%^t%^RESET%^%^CYAN%^ic %^GREEN%^music drifts "
"through the room.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^The walls and roof here, while of the same %^BOLD%^%^BLACK%^bleak st%^RESET%^"
"%^ORANGE%^on%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^as the rest of the city's buildings, has been dressed up for far greater "
"appeal.  The walls are spaced with torches of %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^, that shed only "
"dim light around the area.  Placed sporadically between these are a few tapestries of varied imagery, adding a splash of "
"color to the room.%^RESET%^",
     ({"torches","faerie fire"}):"%^BLUE%^At evenly-spaced intervals around the walls are torches of glowing %^MAGENTA%^"
"fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^, which shed a soft light upon the otherwise %^BOLD%^%^BLACK%^dimly-lit "
"%^RESET%^%^BLUE%^room.  A few extra torches have been placed around the stage, giving it slightly better visibility "
"than the rest of the bar.%^RESET%^",
     "stage":"%^BLUE%^Running the length of the room's rear wall is a %^RED%^broad stage%^BLUE%^, presumably for the use "
"in whatever kind of entertainment this barroom employs.  It is raised from the floor and somewhat %^MAGENTA%^better l"
"%^BOLD%^i%^RESET%^%^MAGENTA%^t %^BLUE%^than the rest of the area, drawing greater focus to itself than the rest of the "
"room's %^BOLD%^%^BLACK%^shad%^RESET%^%^MAGENTA%^ow%^BOLD%^%^BLACK%^y recesses%^RESET%^%^BLUE%^.%^RESET%^",
     ({"bar","bartop"}):"%^BLUE%^Near the left rear of the room is a decently sized bar, with a top of carved and glossed "
"%^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^that is obviously either new or very well-tended.  Various bottles of drink "
"line orderly shelves upon the wall behind it, and a small door leads back to what you can imagine must be a %^YELLOW%^k"
"%^RESET%^%^ORANGE%^i%^YELLOW%^t%^RESET%^%^ORANGE%^ch%^YELLOW%^e%^RESET%^%^ORANGE%^n%^BLUE%^, by the sounds and smells "
"emanating from it.  A carefully-written menu has been placed upon the wall behind the bartop, which you could probably "
"%^WHITE%^read%^BLUE%^.%^RESET%^",
     "menu":"%^BLUE%^A carefully-written menu has been placed upon the wall behind the bartop, which you could "
"probably %^WHITE%^read%^BLUE%^.%^RESET%^",
     ({"tapestry","tapestries"}):"%^BLUE%^Numerous tapestries of fine quality and detail adorn the walls of the bar, each "
"subdued in tone enough that they don't distract the eye without intent.  Each depicts a single drow figure, immersed in "
"some manner of performance or artistry, whether that be the %^ORANGE%^sc%^RED%^ar%^MAGENTA%^f-%^BLUE%^cl%^GREEN%^ad "
"%^BLUE%^female dancer poised gracefully in mid-motion, the tall male whose arms lie in full embrace around the smooth "
"outline of a %^ORANGE%^ca%^YELLOW%^v%^RESET%^%^ORANGE%^eh%^RESET%^ar%^ORANGE%^p%^BLUE%^, his fingers lightly at play "
"across its strings, or so many others as your gaze passes across each in turn.  They add a further touch of class to "
"the already refined nature of the establishment.%^RESET%^",
   ]));
   set_exits(([
     "west":ROOMS"outer2",
   ]));
}

void init() {
    ::init();
    add_action("read", "read");
}

void reset(){
   object ob;
   ::reset();
   if(!present("phyrrae")) new(MON"phyrrae")->move(TO);
   if(present("bardess")){
     if(random(3)) {
       ob = present("bardess");
       if(ob->query_property("quietly")) return;
       ob->move("/d/shadowgate/void");
       ob->remove();
       tell_room(TO,"%^CYAN%^The drow maiden finishes her performance and dips into a graceful bow, and "
"disappears behind a curtain.%^RESET%^");
     }
   }
   else {
     new(MON"bardess")->move(TO);
     switch(random(3)) {
       case 0:
       tell_room(TO,"%^CYAN%^A lithe drow maiden takes a place upon the stage, and begins a slow winding dance "
"to nothing more than the sound of her own %^MAGENTA%^melodious %^CYAN%^voice.");
       break;
       case 1:
       tell_room(TO,"%^MAGENTA%^From behind the curtains emerges a slender female drow, already moving in the "
"first steps of a sinuous dance, as the gentle strains of a %^ORANGE%^pipe %^MAGENTA%^begin to drift through "
"the room.%^RESET%^");
       break;
       case 2:
       tell_room(TO,"%^ORANGE%^The curtains part, revealing a drow woman garbed in flattering, yet revealing, "
"silks of many colors.  With graceful movements she begins a lone dance upon the stage, her lips parting in an "
"exotic, wordless %^CYAN%^melody%^ORANGE%^.%^RESET%^");
       break;
     }
   }
   return;
}

int read(string str) {
   object ob;
   int i;

   if(str!="menu") return notify_fail("Read what?");
   ob=present("phyrrae");
   if (!ob){
     write("There's noone here to serve you right now.");
     return 1;
   }
   else{
write("%^RESET%^%^MAGENTA%^\n\t  /~\\_/~\\_/~\\_/~\\_/~\\ %^CYAN%^FOOD %^MAGENTA%^/~\\_/~\\_/~\\_/~\\_/~\\");
write("%^RESET%^%^CYAN%^\n\tGrilled aboleth\t\t\t\t %^WHITE%^"+ (int)ob->get_price("grilled aboleth")+" gold");
write("%^RESET%^%^CYAN%^\tRaw pyrimo\t\t\t\t %^WHITE%^"+ (int)ob->get_price("raw pyrimo")+" gold");
write("%^RESET%^%^CYAN%^\tRothe steak\t\t\t\t %^WHITE%^"+ (int)ob->get_price("rothe steak") + " gold");
write("%^RESET%^%^CYAN%^\tSeafood platter\t\t\t\t %^WHITE%^"+ (int)ob->get_price("seafood platter") + " gold");
write("%^RESET%^%^CYAN%^\tCrushed bloodfruit ice\t\t\t %^WHITE%^"+ (int)ob->get_price("crushed bloodfruit ice") + " gold");

write("%^RESET%^%^MAGENTA%^\n\t  /~\\_/~\\_/~\\_/~\\_/~ %^CYAN%^DRINKS %^MAGENTA%^~\\_/~\\_/~\\_/~\\_/~\\");
write("%^RESET%^%^CYAN%^\n\tWater\t\t\t\t\t  %^WHITE%^"+(int)ob->get_price("water")+" gold");
write("%^RESET%^%^CYAN%^\tHerbal tea\t\t\t\t %^WHITE%^"+(int)ob->get_price("herbal tea")+" gold");
write("%^RESET%^%^CYAN%^\tBlack coffee\t\t\t\t %^WHITE%^"+(int)ob->get_price("black coffee")+" gold");
write("%^RESET%^%^CYAN%^\tMorimatra\t\t\t\t %^WHITE%^"+(int)ob->get_price("morimatra")+" gold");
write("%^RESET%^%^CYAN%^\tLuurden wine\t\t\t\t %^WHITE%^"+(int)ob->get_price("luurden wine")+" gold");
write("%^RESET%^%^MAGENTA%^\n\t  _/~\\_/~\\_/~\\_/~\\_/~\\_/~\\_/~\\_/~\\_/~\\_/~\\_/~\\_");
     return 1;
   }
}
