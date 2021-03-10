// scaling the default items for thieves guilds; higher area guilds have better availabilities. N, 10/15.
#include <std.h>
#include <brewing.h>
#include <daemons.h>
inherit "std/room";

#define FENCE_D "/daemon/fence_d"
#define OKSCROLLS ({ "identify","fog cloud","siphon magic","monster summoning iii","cats grace","eagles splendor" })

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
   int flag, i, val;
   object ob, *inven;
   mapping datamap;
   string elixirname;
   ::reset();

   inven = all_inventory(TO);
   if(sizeof(inven)) {
     for(i=0;i<sizeof(inven);i++) {
       if(userp(inven[i])) continue;
       inven[i]->move("/d/shadowgate/void");
       inven[i]->remove();
     }
   }

   flag = FENCE_D->restore_item(TO); // lesser fences only attempt to restore one item at a time.

   if(!present("rope")) new("/d/common/obj/misc/rope")->move(TO);
   if(!present("tools")) new("/d/common/obj/misc/thief_tools.c")->move(TO);
   if(!present("tools 2")) new("/d/common/obj/misc/thief_tools.c")->move(TO);
   if(!present("blinding powder") && random(2)) new("/d/common/obj/brewing/powders/blinding_powder")->move(TO);
   i=0;
   while(i<5) {
        i++;
        if(!present("vial "+i)) {
            ob = new("/d/common/obj/potion/healing");
            ob->set_uses(15 + random(5));
            ob->move(TO);
        }
    }
    for(i=0;i<6;i++) { // scroll time!
		if(!present("safe scroll 6")){
			ob = new("/d/magic/safe_scroll");
			ob->set_spell_name(OKSCROLLS[random(sizeof(OKSCROLLS))]);
            ob->set_clevel(10);
			ob->move(TO);
		}
    }

    if(!present("vial 6")) { // first five should be kits!
      datamap = ELIXIRS;
      switch(random(4)) {
        case 0:
          ob = new("/d/common/obj/brewing/elixirs/elixir_of_bless");
          elixirname = "elixir of bless";
        break;
        case 1:
          ob = new("/d/common/obj/brewing/elixirs/elixir_of_sticky_fingers");
          elixirname = "elixir of sticky fingers";
        break;
        case 2:
          ob = new("/d/common/obj/brewing/elixirs/elixir_of_water_breathing");
          elixirname = "elixir of water breathing";
        break;
        default:
          ob = new("/d/common/obj/brewing/elixirs/elixir_of_spider_climb");
          elixirname = "elixir of spider climb";
        break;
      }
      ob->set_myname(elixirname);
      ob->set_dc(datamap[elixirname]["dc"]);
      ob->set_strength(25);
      ob->set_hue(datamap[elixirname]["color"]);
      ob->set_value((datamap[elixirname]["value"] * roll_dice(3,4)));
      ob->move(TO);
    }

    if(!present("poison")) POISON_D->QueryPoisonObject("any", "injury")->move(TO);

    if(!present("playersettabletrapkit")) {
      i = 2 + random(2);
      while(i) {
        ob = TRAP_D->get_trap_object("low", "random");
        val = 300 + random(201);
        if(objectp(ob)) {
          tell_room(TO, "Trap object is valid");
          ob->move(TO);
          ob->set_value(val);
        }
        i--;
        continue;
      }
    }
}
