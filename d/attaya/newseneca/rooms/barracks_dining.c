//barracks_dining - Barracks for new Seneca
//~Circe~ 12/4/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

object ob;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Dining Hall of the Guard Barracks, Seneca");
   set_short("%^BOLD%^%^WHITE%^Dining Hall of the Guard Barracks, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Dining Hall of the Guard Barracks, Seneca%^RESET%^\n"+
      "%^ORANGE%^Wooden panels %^RESET%^lining this long hall have "+
      "been draped with %^BOLD%^%^RED%^banners %^RESET%^that seem "+
      "to depict companies within the Guard.  Hanging above a "+
      "%^ORANGE%^door %^RESET%^in the northern wall is a large "+
      "%^BOLD%^%^RED%^banner %^RESET%^depicting the %^BOLD%^symbol "+
      "%^RESET%^of the Seneca Guard.  The floor space here has been "+
      "taken up by three long %^ORANGE%^tables %^RESET%^with %^ORANGE%^"+
      "low stools %^RESET%^lining both their sides.  The floor is "+
      "left bare otherwise, likely to ease in the cleaning when dealing "+
      "with food for the entire Guard.  At any given time, soldiers "+
      "can be found eating here, though naturally crowds are heavier "+
      "during the normal meal times.\n");
   set_smell("default","The clean fragrance of the ocean is masked somewhat by the aroma of soldiers.");
   set_listen("default","Chatter from the guardsmen mixes with the noise of Seneca.");
   set_items(([
      ({"panels","walls"}) : "The wooden panels seem rather cheap upon "+
         "close inspection, but they cover the brick of the walls and "+
         "add a bit of insulation.  Much of the paneling has been covered "+
         "with banners of different companies.",
      ({"banners","banner"}) : "Various banners have been hung along the "+
         "walls, revealing all sorts of shapes, colors, and symbols.  "+
         "The main banner hangs over the kitchen door and bears the "+
         "%^BOLD%^symbol %^RESET%^of the Seneca Guard.",
      ({"symbol","main banner","Seneca Guard banner","seneca guard banner","guard banner"}) :
         (:TO,"look_banner":),
      ({"door","kitchen","kitchen door"}) : "The door to the kitchens "+
         "swings open and closed often as guardsmen retrieve food "+
         "from the fires there.  Several guardsmen are on kitchen duty "+
         "any any given time, a task that's shared just like every other.",
      ({"table","tables","stool","stools"}) : "The long wooden tables "+
         "are fairly rough and liable to give splinters.  They are "+
         "lined on each side by three-legged stools that provide ample "+
         "seating for guardsmen at meals."
   ]));
   set_exits(([
      "south" : ROOMS"barracks_entry"
   ]));
}

int look_banner(){
   return("An %^BOLD%^eagle %^RESET%^in flight has been stitched onto a "+
      "%^YELLOW%^golden background%^RESET%^ with a %^BOLD%^%^RED%^red "+
      "border%^RESET%^.\n\n"+
"%^BOLD%^%^RED%^==================================================================\n"+
"||    %^RESET%^%^ORANGE%^/(                                                 (/     %^BOLD%^%^RED%^||\n"+
"||    %^RESET%^%^ORANGE%^6@(                                               /@6     %^BOLD%^%^RED%^||\n"+
"||    %^RESET%^%^ORANGE%^6@@Q                                             /@@6     %^BOLD%^%^RED%^||\n"+
"||   %^RESET%^%^ORANGE%^6@@@@@(                                          6@@Q(@(   %^BOLD%^%^RED%^||\n"+
"||   %^RESET%^%^ORANGE%^Q@QQ@@Q/                                        (Q@@66@(   %^BOLD%^%^RED%^||\n"+
"||   %^RESET%^%^ORANGE%^Q@@6Q@@@(                                      6@@@QQ@Q(   %^BOLD%^%^RED%^||\n"+
"||   %^RESET%^%^ORANGE%^6@@@66@@@Q/                                  (Q@@@@@@@@@   %^BOLD%^%^RED%^||\n"+
"||   %^RESET%^%^ORANGE%^6@@@@6@@@@6                                 /Q@@@@@@@@@@   %^BOLD%^%^RED%^||\n"+
"||   %^RESET%^%^ORANGE%^/Q@@@@6Q@@@@(                              6@@@@@@@@@@@(   %^BOLD%^%^RED%^||\n"+
"||    %^RESET%^%^ORANGE%^/Q@@@@66@@@@Q/                          /Q@@@@@@@@@@@(    %^BOLD%^%^RED%^||\n"+
"||     %^RESET%^%^ORANGE%^Q@@@@@Q@@@@@6/                         6@@@@@@@@@@@Q     %^BOLD%^%^RED%^||\n"+
"||      %^RESET%^%^ORANGE%^(@@@@@@@@@@@@Q(                     (Q@@@@@@@@@@@QQ/    %^BOLD%^%^RED%^||\n"+
"||      %^RESET%^%^ORANGE%^/6@@@@@@@@@@@@@(                   /Q@@@@@@@@@@QQ@Q/    %^BOLD%^%^RED%^||\n"+
"||      %^RESET%^%^ORANGE%^QQ(Q@@@@@@@@@@@@Q(                /@@@@@@@@@@@Q@@6      %^BOLD%^%^RED%^||\n"+
"||       %^RESET%^%^ORANGE%^6@QQ@@@@@@@@@@@@@Q/             (@@@@@@@@@@@@@6/       %^BOLD%^%^RED%^||\n"+
"||        %^RESET%^%^ORANGE%^Q@QQ@@@@@@@@@@@@@6            /Q@@@@@@@@@@@@6/        %^BOLD%^%^RED%^||\n"+
"||       %^RESET%^%^ORANGE%^6QQ@@@@@@@@@@@@@@@@6           (@@@@@@@@@@@Q6@/        %^BOLD%^%^RED%^||\n"+
"||       %^RESET%^%^ORANGE%^/@@@@@@@@@@@@@@@@@@@/          6@@@@@@@@@@@@Q          %^BOLD%^%^RED%^||\n"+
"||        %^RESET%^%^ORANGE%^6@@@@@@@@@@@@@@@@@@/          (@@@@@@@@@@@Q/          %^BOLD%^%^RED%^||\n"+
"||         %^RESET%^%^ORANGE%^/Q@@@@@@@@@@@@@@@6           6@@@@@@@@@Q(            %^BOLD%^%^RED%^||\n"+
"||         %^RESET%^%^ORANGE%^(@@Q@@@@@@@@@@@@@(           6@@@@@@@@@(             %^BOLD%^%^RED%^||\n"+
"||         %^RESET%^%^ORANGE%^(@@@@@@@@@@@@@@@/   %^BOLD%^%^WHITE%^ (QQQQQ\\%^RESET%^%^ORANGE%^@@@@@@@@@@6              %^BOLD%^%^RED%^||\n"+
"||          %^RESET%^%^ORANGE%^(@@@@@@@@@@@@@Q %^BOLD%^%^WHITE%^/QQ(/////\\%^BLACK%^6%^WHITE%^)%^RESET%^%^ORANGE%^Q@@@@@@@@               %^BOLD%^%^RED%^||\n"+
"||           %^RESET%^%^ORANGE%^Q@@@@@@@@@@@@Q%^BOLD%^%^WHITE%^6@Q///////(%^YELLOW%^@%^RESET%^%^ORANGE%^ (Q@@@@@@(               %^BOLD%^%^RED%^||\n"+
"||           %^RESET%^%^ORANGE%^(@@@@@@@@@@@@@@%^BOLD%^%^WHITE%^(///////(%^YELLOW%^\\) %^RESET%^%^ORANGE%^ (Q@@@Q/                %^BOLD%^%^RED%^||\n"+
"||            %^RESET%^%^ORANGE%^/Q@@@@@@@@@@@@@%^BOLD%^%^WHITE%^//////Q%^RESET%^%^ORANGE%^@@@@@@@@@(                  %^BOLD%^%^RED%^||\n"+
"||             %^RESET%^%^ORANGE%^/Q@@@@@@@@@@@@%^BOLD%^%^WHITE%^6(////Q%^RESET%^%^ORANGE%^@@@@@@@@6/                  %^BOLD%^%^RED%^||\n"+
"||               %^RESET%^%^ORANGE%^/Q@@@@@@@@@@@@@%^BOLD%^%^WHITE%^(/Q%^RESET%^%^ORANGE%^@@@@Q((/                     %^BOLD%^%^RED%^||\n"+
"||                %^RESET%^%^ORANGE%^/6@@@@@@@@@@@@@%^BOLD%^%^WHITE%^Q%^RESET%^%^ORANGE%^@@@@@(                        %^BOLD%^%^RED%^||\n"+
"||              %^RESET%^%^ORANGE%^//6@@@@@@@@@@@@@@@(                             %^BOLD%^%^RED%^||\n"+
"||      %^BOLD%^%^WHITE%^(@@QQ6(/(Q%^RESET%^%^ORANGE%^@@@@@@@@@@@@@@@Q                              %^BOLD%^%^RED%^||\n"+
"||      %^BOLD%^%^WHITE%^(@6(///(6QQ%^RESET%^%^ORANGE%^@@@@@@@@@@@@@@@/                             %^BOLD%^%^RED%^||\n"+
"||        %^BOLD%^%^WHITE%^6@Q  (Q@(/%^RESET%^%^ORANGE%^@@@@@@@@@@@@@@%^BOLD%^%^WHITE%^@6/                           %^BOLD%^%^RED%^||\n"+
"||          %^BOLD%^%^WHITE%^6@@6 /QQ 66Q@@@@@@%^BOLD%^%^WHITE%^6//6@@@Q/                         %^BOLD%^%^RED%^||\n"+
" \\\\           %^BOLD%^%^WHITE%^6@Q6@Q (Q/Q@@@@Q@@%^BOLD%^%^WHITE%^6Q@6((/                        %^BOLD%^%^RED%^//\n"+
"  \\\\           %^BOLD%^%^WHITE%^/6Q@@@Q//66( /@@@/(                            %^BOLD%^%^RED%^//\n"+
"   \\\\              %^BOLD%^%^WHITE%^6Q6(                                     %^BOLD%^%^RED%^ //\n"+
"    \\\\                                                      //\n"+
"     ========================================================%^RESET%^\n");
   return 1;
}

void reset(){
   ::reset();
   if(!present("seneca guard 4") && !random(2)){
      ob = new(MON"city_guard");
      ob->set_speec(0);
      ob->move(TO);
   }
}