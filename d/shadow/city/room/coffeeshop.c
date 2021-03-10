#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("The Grind House");
   set_short("%^RESET%^%^BOLD%^%^BLACK%^The %^BLACK%^Grind %^BLACK%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^use%^RESET%^%^RESET%^");
   set_long(
"%^RESET%^%^BOLD%^%^BLACK%^The %^BLACK%^Grind %^BLACK%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^use%^RESET%^%^RESET%^
%^RESET%^%^ORANGE%^This upscale coffee shop is built from %^WHITE%^s%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^o%^RESET%^th gr%^BOLD%^%^BLACK%^a%^RESET%^y s%^BOLD%^%^BLACK%^to%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^s%^ORANGE%^, d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk w%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^d, and cool, %^BOLD%^%^WHITE%^p%^RESET%^o%^BOLD%^lis%^RESET%^he%^BOLD%^d m%^RESET%^e%^BOLD%^t%^RESET%^a%^BOLD%^l%^RESET%^%^ORANGE%^. The stone walls tower over you, strong and tall enough to accommodate any size of guest. Likewise, the seating arrangements were made with diversity in mind. A large counter sprawls from one side of the narrow room to the other. Hanging from the high ceiling at even intervals are large, cylindrical shaped %^BOLD%^%^BLACK%^lanterns %^RESET%^%^ORANGE%^that burn with a magical light and fill the atmosphere with a pleasant, %^BOLD%^w%^RESET%^a%^ORANGE%^r%^BOLD%^m gl%^RESET%^o%^YELLOW%^w%^RESET%^%^ORANGE%^. The seamless stone of the %^BOLD%^%^BLACK%^dark gray floor %^RESET%^%^ORANGE%^is kept polished to a shine, and very open and uncluttered. Wooden %^WHITE%^islands %^ORANGE%^are set throughout the space, providing small tins of %^BOLD%^%^WHITE%^s%^RESET%^u%^BOLD%^g%^RESET%^a%^BOLD%^r%^RESET%^%^ORANGE%^, %^BOLD%^%^WHITE%^m%^RESET%^il%^BOLD%^k %^RESET%^%^ORANGE%^and %^BOLD%^h%^RESET%^%^ORANGE%^o%^BOLD%^n%^RESET%^%^ORANGE%^e%^BOLD%^y%^RESET%^%^ORANGE%^. A %^CYAN%^menu %^ORANGE%^hangs on the wall behind that bar.%^WHITE%^");
   set_smell("default","The rich aroma of coffee awakens your senses.");
   set_listen("default","The soft hush of quiet conversations is all around.");
   set_exits(([
                  "north" : ROOMS"shadway2",
                  ]));
   set_items(([
                  "walls":"%^RESET%^%^CYAN%^The walls are largely made from %^BOLD%^%^BLACK%^pale gray bricks %^RESET%^%^CYAN%^that are utterly smooth and refined. However, like everything else here, they seem to capture a natural aesthetic that's both simple and elegant. The walls are largely left bare, creating a %^WHITE%^minimalist %^CYAN%^effect.%^WHITE%^",
                  "ceiling":"%^RESET%^%^CYAN%^Far above your head, %^BOLD%^%^BLACK%^black pipes %^RESET%^%^CYAN%^snake their way along the ceiling in an aimless fashion. There does not appear to be any discernible pattern nor use for the pipes beyond adding a decorative touch. Hanging from the ceiling are large, %^BOLD%^%^BLACK%^iron %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^glass cylinders %^RESET%^%^CYAN%^that serve as lanterns, glowing with an %^BOLD%^inner light%^RESET%^%^CYAN%^.%^WHITE%^",
                  ({"lights","lanterns"}):"%^RESET%^%^CYAN%^About 3 feet long and with a diameter of easily two feet, these lanterns provide plenty of %^YELLOW%^lig%^RESET%^h%^YELLOW%^t %^RESET%^%^CYAN%^and interest to the room. %^WHITE%^Frosted glass panels %^CYAN%^are tucked within the %^BOLD%^%^BLACK%^slender iron rods %^RESET%^%^CYAN%^that lend support to the frame. They're very simple in design, yet quite efficient in purpose.%^WHITE%^",
                  "counter":"%^RESET%^%^CYAN%^The counter sprawls from one side of the room to the other. It is made from %^ORANGE%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^k w%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^that appear natural and unpolished. Contrasting the rawness of the wood, a %^BOLD%^%^WHITE%^s%^RESET%^hi%^BOLD%^ni%^RESET%^n%^BOLD%^g s%^RESET%^ilve%^BOLD%^r c%^RESET%^o%^BOLD%^u%^RESET%^n%^BOLD%^t%^RESET%^e%^BOLD%^r %^RESET%^%^CYAN%^is quite contemporary. Its surface is free from clutter. Behind the counter, %^WHITE%^la%^ORANGE%^r%^GREEN%^g%^WHITE%^e gl%^ORANGE%^a%^GREEN%^s%^WHITE%^s %^ORANGE%^c%^WHITE%^yli%^GREEN%^n%^WHITE%^d%^ORANGE%^e%^GREEN%^r%^WHITE%^s %^CYAN%^hold a variety of different %^BOLD%^%^BLACK%^coffees %^RESET%^%^CYAN%^and %^ORANGE%^te%^GREEN%^a%^ORANGE%^s%^CYAN%^, and there are a few curious mechanisms in which the beverages are likely brewed.%^WHITE%^",
                  ({"tables","seating","seatings"}):"%^RESET%^%^CYAN%^There are tables for large groups to gather, and some made for no more than a party of one. Here and there is a random plush chair, or spots where two people could lounge in a pair of comfortable armchairs and discuss worldly events. Tucked in a corner, two sofas are arranged around a small coffee table. The furniture is all %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^, and designed to add a touch of comfortable class.%^WHITE%^",
                  "floor":"%^RESET%^%^CYAN%^The seamless stone of the %^BOLD%^%^BLACK%^dark gray floor %^RESET%^%^CYAN%^is kept polished to a shine, and very open and uncluttered%^WHITE%^",
                  ({"island","islands"}):"%^RESET%^%^CYAN%^Scattered throughout the room are three wooden islands. Here, patrons can take a moment to add their flavor of choice to their beverage, be it %^BOLD%^%^WHITE%^milk%^RESET%^%^CYAN%^, %^ORANGE%^honey %^CYAN%^or %^BOLD%^%^WHITE%^sugar%^RESET%^%^CYAN%^.%^WHITE%^"
                  ]));
}

void init()
{
    ::init();
    add_action("read","read");
}

void reset()
{
    ::reset();
    if(!present("cofeemaster")) {
        new(MON+"brennan.c")->move(TO);
    }
}

int read(string str)
{
    object ob = present("cofeemaster");
    int i;
    if(str == "menu")
    {
        if(!ob)
        {
            write("The shopkeeper is not here at the moment.");
            return 1;
        }
        say(""+TPQCN+" reads over the menu.");
        write(
"%^MAGENTA%^-<>-<>-<>- %^BOLD%^%^BLACK%^The Grind House %^RESET%^%^MAGENTA%^-<>-<>-<>-%^WHITE%^

        %^MAGENTA%^-<>- %^BOLD%^%^BLACK%^Fine Coffees %^RESET%^%^MAGENTA%^-<>-%^WHITE%^

  %^CYAN%^Coffee                   %^BOLD%^%^WHITE%^5 %^RESET%^Silver
  %^CYAN%^Espresso                %^BOLD%^%^WHITE%^10 %^RESET%^Silver
  %^CYAN%^Cappuccino              %^BOLD%^%^WHITE%^10 %^RESET%^Silver

     %^MAGENTA%^-<>- %^BOLD%^%^BLACK%^Specialty Drinks %^RESET%^%^MAGENTA%^-<>-%^WHITE%^

  %^CYAN%^Iced Green Tea Latte    %^BOLD%^%^WHITE%^20 %^RESET%^Silver
  %^CYAN%^Strawberry Smoothie     %^BOLD%^%^WHITE%^20 %^RESET%^Silver
  %^CYAN%^Drinking Chocolate      %^BOLD%^%^WHITE%^15 %^RESET%^Silver
  %^CYAN%^Vanilla Steamer         %^BOLD%^%^WHITE%^15 %^RESET%^Silver

         %^MAGENTA%^-<>- %^BOLD%^%^BLACK%^Bakery %^RESET%^%^MAGENTA%^-<>-%^WHITE%^

  %^CYAN%^Blueberry Muffin        %^BOLD%^%^WHITE%^15 %^RESET%^Silver
  %^CYAN%^Coffee Cake             %^BOLD%^%^WHITE%^20 %^RESET%^Silver
  %^CYAN%^Cinnamon Bun            %^BOLD%^%^WHITE%^20 %^RESET%^Silver
  %^CYAN%^Hot Oatmeal              %^BOLD%^%^WHITE%^5 %^RESET%^Silver

 %^MAGENTA%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^WHITE%^
");
        return 1;
    }
    return 0;
}




