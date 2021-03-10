#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"
#define ITEMS   "/d/shadow/obj/misc/"
#define WEAPONS "/d/shadow/obj/weapon/"
#define MAGICS  "/d/shadow/obj/magic/"
#define SPECIAL ({"/d/islands/dinosaur/obj/float_belt.c", "/d/islands/dinosaur/obj/pearl_amulet.c", "/d/islands/dinosaur/obj/trident.c", "/d/islands/dinosaur/obj/wdagger.c" })

inherit DAEMON;

object get_item(){
    object ob;
    string *items;

    switch(random(5)){
    case 0:
      //money
      ob = new("/std/obj/coins.c");
      ob->set_money("gold", 10+random(30));
      ob->set_money("platinum", 5+random(5));
      ob->set_money("electrum", 10+random(50));
      ob->set_money("silver", 20+random(50));
      ob->set_money("copper", 20+random(50));

      break;
    case 1:
      //std item
      switch(random(2)){
      case 0:
        items = get_dir(ITEMS);
        ob = new(ITEMS + items[random(sizeof(items))]);
        break;
      case 1:
        items = get_dir(WEAPONS);
        ob = new(WEAPONS + items[random(sizeof(items))]);
        break;
      }

      break;
    case 2:
      //magic item
      switch(random(2)){
      case 0:
        items = get_dir(MAGICS);
        ob = new(MAGICS + items[random(sizeof(items))]);
        break;
      case 1:
        ob = new(SPECIAL[random(sizeof(SPECIAL))]);
        break;
      }

      break;
    default:
      ob = new("/d/islands/tonerra/obj/gem.c");
      break;
    }

    return ob;
}

