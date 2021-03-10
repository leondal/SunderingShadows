//Octothorpe (2/5/17)
//Three Coins Inn Restaurant
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Three Coins Restaurant, Three Coins Inn, Shadow");
   set_short("%^BOLD%^Three Coins Restaurant, Three Coins Inn, "+
      "Shadow%^RESET%^");
   set_long("%^BOLD%^Three Coins Restaurant, Three Coins Inn, Shadow%^RESET%^
%^RESET%^%^MAGENTA%^Here atop the %^CYAN%^Thr%^BLUE%^e%^BLUE%^e %^ORANGE%^Coin%^BOLD%^%^ORANGE%^s%^RESET%^ %^CYAN%^Inn,%^MAGENTA%^ you have a spectacular view of the %^CYAN%^city.%^MAGENTA%^ A %^CYAN%^w%^BLUE%^a%^CYAN%^ll%^MAGENTA%^ made entirely of %^BOLD%^%^WHITE%^g%^RESET%^%^WHITE%^lass%^MAGENTA%^ opens onto a patio, where diners can enjoy the fresh air. An impressive %^BLUE%^b%^CYAN%^ar%^MAGENTA%^ sits off to one side, its ebony surface gleaming. Plush %^BLUE%^c%^CYAN%^ouches%^MAGENTA%^ and %^CYAN%^chai%^BLUE%^r%^BLUE%^s%^MAGENTA%^ are arranged near the bar, situated around an enclosed %^ORANGE%^f%^RED%^i%^ORANGE%^re%^MAGENTA%^ pit. %^ORANGE%^Tables%^MAGENTA%^ of varying sizes are arranged around the room, and some private %^CYAN%^bo%^BLUE%^o%^CYAN%^ths%^MAGENTA%^ sit upon a raised dais. Bound %^BOLD%^%^ORANGE%^m%^WHITE%^enu%^RESET%^%^MAGENTA%^ rest on each table. A large %^ORANGE%^s%^BLUE%^tage%^MAGENTA%^ stands in front of the windowed wall, which provides a wonderful backdrop to the shows performed here. A small door off to the side gives access to the balcony. The walls are cool gray wood with bright blue veins, adding an interesting texture to the room. They are decorated in vivid %^CYAN%^pictures%^MAGENTA%^ and random memorabilia. But what captures the eye the most is the stunning %^ORANGE%^f%^WHITE%^l%^WHITE%^o%^ORANGE%^or%^MAGENTA%^ which is covered in shining gold, silver, and copper coins.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^The %^WHITE%^enticing %^CYAN%^"+
      "smell of food makes your mouth water.%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^Soft piano music provides a "+
      "pleasant backdrop to the %^RESET%^susurration %^BOLD%^%^CYAN%^of "+
      "conversations.%^RESET%^");
   set_items(([
      "city" : "This appears to be one of the highest points in the "+
         "city, which spreads out far below.",
      ({"windows","glass","patio","balcony","glass wall"}) : "%^RESET%^"+
         "This wall is made entirely from %^BOLD%^glass%^RESET%^, "+
         "giving a clear look out to the rooftop lounge and the "+
         "%^BOLD%^%^BLACK%^city %^RESET%^and %^BOLD%^%^CYAN%^sky "+
         "%^RESET%^beyond.",
      "bar" : "This is a traditional bar made from %^BOLD%^%^BLACK%^"+
         "polished ebony%^RESET%^. The %^BOLD%^mirrored wall %^RESET%^"+
         "behind the bar reflects the rows of bottles set up here. "+
         "%^BOLD%^%^BLACK%^Wooden stools %^RESET%^are neatly arranged "+
         "in front of the bar, their soft %^BOLD%^%^BLUE%^blue cushions "+
         "%^RESET%^and high backs providing a relaxing place to sit.",
      "menu" : "A bound menu lies on each table. You can read it.",
      ({"couches","chairs"}) : "Set up in a lounge area near the bar, "+
         "the %^BOLD%^%^BLUE%^blue couches %^RESET%^and %^BOLD%^%^BLUE%^"+
         "chairs %^RESET%^are delectably soft and cozy. They're all "+
         "arranged around an enclosed %^BOLD%^%^BLACK%^fire pit %^RESET%^"+
         "which is always burning.",
      ({"fire","pit","fire pit"}) : "%^RESET%^This %^BOLD%^%^BLACK%^"+
         "stone %^RED%^f%^RESET%^%^RED%^i%^BOLD%^re %^BLACK%^pit "+
         "%^RESET%^is a marvelous centerpiece to the lounge area, as "+
         "well as being a source of %^YELLOW%^w%^RESET%^%^ORANGE%^a"+
         "%^BOLD%^rmth %^RESET%^and %^YELLOW%^lig%^RESET%^%^ORANGE%^h"+
         "%^BOLD%^t%^RESET%^. The fire is built on a large stone "+
         "platform, and is encircled by a %^BOLD%^glass shield%^RESET%^. "+
         "An attached metal %^BOLD%^%^BLACK%^chimney %^RESET%^carries "+
         "the smoke up and away.",
      ({"tables","booths"}) : "The tables vary in sizes, able to "+
         "accommodate parties of two up to a dozen or so. They are "+
         "covered in %^BOLD%^%^BLUE%^soft blue linens%^RESET%^. The "+
         "booths are tucked away in their own section, and feature "+
         "%^BOLD%^%^BLUE%^blue leather seating %^RESET%^and %^BOLD%^"+
         "%^BLACK%^gleaming ebony %^RESET%^table tops.",
      "stage" : "%^RESET%^The stage is placed in front of the wide "+
         "windows, allowing the %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^t"+
         "%^BOLD%^unn%^RESET%^%^CYAN%^in%^BOLD%^g s%^RESET%^%^CYAN%^"+
         "k%^BOLD%^y %^RESET%^to be its backdrop. The stage itself is "+
         "rather simple and plain, featuring a %^ORANGE%^hardwood floor "+
         "%^WHITE%^and a few %^BOLD%^%^GREEN%^trees %^RESET%^lining its "+
         "sides to add some elegance. It would be large enough to "+
         "support a small band.",
      ({"walls","pictures","memorabilia"}) : "Many adventurers have "+
         "passed through Shadow over time, stopping by the %^BOLD%^"+
         "Three Coins Inn %^RESET%^to rest and relax, and to enjoy a "+
         "warm meal or some laughter with their friends. Over time, "+
         "they've donated quite the collection of %^ORANGE%^artifacts "+
         "%^WHITE%^and %^ORANGE%^oddities%^WHITE%^, that have since "+
         "found their way to the walls here.",
      "floor" : "The floor is nicely polished %^ORANGE%^w%^BOLD%^"+
         "%^BLACK%^o%^RESET%^%^ORANGE%^od%^WHITE%^, which is kept quite "+
         "clean and clutter-free."
   ]));
   set_exits(([
      "down" : ROOMS"3coinsbalcony",
      "north" : ROOMS"3coinspatio"
   ]));
   set_door("glass door",ROOMS"3coinspatio","north",0,0);
   set_door_description("copper door","%^RESET%^This %^BOLD%^glass "+
      "door %^RESET%^leads outside to the patio.");
}

void reset()
{
   ::reset();
   if(!present("waitress"))
   {
      find_object_or_load(MON"waitress")->move(TO);
   }
}

int __Read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

    if(str != "menu")
        return 0;
    ob = present("waitress");
    if(!ob) {
        write("%^RED%^You cannot read the menu, as it is splattered with blood.%^RESET%^");
        return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
    write("%^BOLD%^%^BLUE%^The Specials of Today at the Three Coins Restaurant%^RESET%^");
    write("%^CYAN%^--------------------------------------------------------------------");
    while(length--){
        melnmarn = sprintf("  %%^GREEN%%^%-18s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	    write(melnmarn);
    }
    write("%^CYAN%^--------------------------------------------------------------------");
    write("<buy dish_name> gets you the food or drink.");
    return 1;
}


