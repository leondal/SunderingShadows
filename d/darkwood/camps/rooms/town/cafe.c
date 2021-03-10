#include <std.h>
#include "../../elfisland1.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 2);
   set("short", "%^BOLD%^%^YELLOW%^Cafe%^RESET%^");
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^This establishment is built in the common theme as the rest of"+
      " the building scheme in this village. The walls lack corners and are rather rounded"+
      " out to create a smooth transition between walls and floor. The floor is well kept and seamlessly"+
      " blend in with the walls the surround the room."+
      " A wonderful scent drifts from the oven at the back of the cafe. People"+
      " are able to sit here in the cafe at one of the small tables crafted magically"+
      " from the floor of the tree. Patterned cloths in %^YELLOW%^v%^RED%^i%^MAGENTA%^"+
      "b%^BLUE%^r%^GREEN%^a%^WHITE%^n%^CYAN%^t%^RESET%^%^GREEN%^ colors cover each table,"+
      " adding a bit of flair to the cafe. Several plates of freshly baked cakes and loaves"+
      " are displayed on the"+
      " counter. A menu hangs on the wall written in an elegant and flowing elven script. A newly"+
      " placed list hangs next to the menu and a %^RED%^bright dart board%^RESET%^%^GREEN%^ hangs"+
      " on one of the round walls out of the way of the patrons.  Garlands of %^MAGENTA%^f%^BOLD%^"+
      "%^WHITE%^l%^YELLOW%^o%^CYAN%^w%^BLUE%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^s%^RESET%^"+
      " %^GREEN%^hang around the cafe, adding a cheerful touch to the room.%^RESET%^"
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell freshly baked elven waybread.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of village life outside.%^RESET%^");
   set_items( ([ 
      "tables": "The tables sit dispersed throughout the room.  Each table is covered with a patterened"+
         " cloth in %^YELLOW%^v%^RED%^i%^MAGENTA%^b%^BLUE%^r%^GREEN%^a%^WHITE%^n%^CYAN%^t"+
         "%^RESET%^colors.", 
      "floor":"The floor is clean and well kept.", 
      "walls":"The walls are crafted from the tree itself.  Garlands of flowers hang around the room,"+
        " making the place seem more cheerful and inviting.",
      "loaves":"The selection of elven waybread appears to be freshly baked.",
      "menu":"A menu you should read.",
   ]) );
   set_exits( ([
      "out" : TOWN+"road11",
   ]) );

}

void reset()
{
    object dartboard,bboard;
    ::reset();
   if(!present("alleteirana")) new(MON+"alleteirana")->move(TO);
   if(!present("synoria board"))
   {
       bboard=new("/std/bboard");
       bboard->set_name("board");
       bboard->set_id(({"board","bulletin board","synoria board"}));
       bboard->set_board_id("synoria_board");
       bboard->set_max_posts(20);
       bboard->set_short("%^BOLD%^%^GREEN%^Notice board of Synoria%^RESET%^");
       bboard->set_long("%^RESET%^%^ORANGE%^A wooden board is set upon the distant wall "
                    "of the room, pinned with a few notices.%^RESET%^");
       bboard->set_location("/d/darkwood/camps/rooms/town/cafe.c");   

   }
    if(!present("dartboard")) {
        dartboard = new("/d/common/obj/misc/dart_board");
        dartboard->set_mastery_list("synoria_cafe");
        dartboard->move(TO);
    }
}

void init() {
   ::init();
   add_action("read", "read");
}

 int read(string str) {
    object ob; 
    string *menu_item,stuff,*names;
    int length, x;
    ob = present("alleteirana");
    if(!ob && str == "menu") {
        write("There is no one here to take your order.");
        return 1;
    }
    if(str == "list" && ob = present("dartboard")) {
        write("This is a list of those who have been witnessed achieving a mastery at darts here in synoria.");
        names = ob->query_mastery_list();
        if(!sizeof(names)) { 
            return 1;
        }
        for(x = 0;x < sizeof(names);x++) {
            tell_object(TP,"%^BOLD%^%^GREEN%^"+capitalize(names[x])+"%^RESET%^\n");
        }
        return 1;
    }

   if(str == "menu") {
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
    message("Ninfo", "This is a list of the food and drink sold at the cafe.\n", TP);
    message("Ninfo", "%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
    while(length--){
        stuff = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ electrum pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
        write(stuff);
    }
    message("Ninfo", "%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
    message("Ninfo", "<buy menu_name> will get you that item.\n", TP);
    return 1;
   }
}
