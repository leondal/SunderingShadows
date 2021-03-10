#include <std.h>
inherit "std/room";

#define FENCE_D "/daemon/fence_d"
#define STORE_INH_ROOM "/std/obj/fence_store_int"
#define MASTER_STORE_ROOM "/std/obj/fence_store"

int flag;
int save_contents() { return 1;}

void create() {
    ::create();
    set_properties((["light":1, "indoors":1, "no teleport":1]));
    set_properties((["storage room":1, "save contents":1]));
    set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
}

int clean_up(){ return 0;}

void reset() {
   int flag;
   int i;
   int count = 5; //tuned back to 5, from 10, from 5 originally. Since the fence won't store misc rubbish. -N, 9/10.
   object ob;
   ::reset();
   if(base_name(TO) == STORE_INH_ROOM ) return;
   if(base_name(TO) == MASTER_STORE_ROOM ) return;

   if(sizeof(all_inventory(TO)) > 25)   return;
   flag = FENCE_D->restore_item(TO);
   while (--count && --flag) FENCE_D->restore_item(TO);

    if(!present("rope")) new("/d/common/obj/misc/rope")->move(TO);
    if(!present("bullseye")) new("/d/common/obj/misc/bullseye")->move(this_object());
    if(!present("tools")) new("d/common/obj/misc/thief_tools.c")->move(this_object());
    if(!present("tools 2")) new("d/common/obj/misc/thief_tools.c")->move(this_object());
    i=0;
    while(i<5) {
        i++;
        if(!present("vial "+i)) {
            ob = new ("/d/common/obj/potion/healing");
            ob->set_uses(15 + random(5));
            ob->move(TO);
        }
    }
    count = 3;
}
