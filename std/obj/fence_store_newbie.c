// scaling the default items for thieves guilds; higher area guilds have better availabilities. N, 10/15.
#include <std.h>
inherit "std/room";

#define FENCE_D "/daemon/fence_d"

int flag;
int save_contents() { return 1;}

void create() {
    ::create();
    set_properties((["light":1, "indoors":1, "no teleport":1]));
    set_properties((["storage room":1, "save contents":1]));
    set("short","A storage room for the thieves guild.");
    set("long", "Supplies and such are stored here.\n");
}

int clean_up(){ return 0;}

// stocking of the guild done here. Note: please add a relevant lantern or dark lantern depending on the location.
void reset() {
   int flag, i, count = 5;
   object ob;
   ::reset();

   if(sizeof(all_inventory(TO)) > 25) return;

   if(!present("rope")) new("/d/common/obj/misc/rope")->move(TO);
   if(!present("lantern")) new("d/common/obj/misc/beacon.c")->move(TO);
   if(!present("dark lantern")) new("d/common/obj/misc/darkbeacon.c")->move(TO);
   if(!present("tools")) new("d/common/obj/misc/thief_tools.c")->move(TO);
   if(!present("tools 2")) new("d/common/obj/misc/thief_tools.c")->move(TO);
   i=0;
   while(i<5) {
        i++;
        if(!present("vial "+i)) {
            ob = new ("/d/common/obj/potion/newbie_healing");
            ob->set_uses(15 + random(5));
            ob->move(TO);
        }
    }
}