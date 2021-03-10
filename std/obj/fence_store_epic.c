// scaling the default items for thieves guilds; higher area guilds have better availabilities. N, 10/15.
#include <std.h>
#include <brewing.h>
#include <daemons.h>
inherit "std/room";

#define FENCE_D "/daemon/fence_d"
#define OKSCROLLS ({ "foresight","armor of darkness","screen","protection from spells","magic mirror","greater dispel magic","fiery body" })

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

void reset() {
   int flag, i, val, count;
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

   flag = FENCE_D->restore_item(TO);
   count = 2; // how many items (+1 from the line above) are spawned from the fence daemon
   while (--count && --flag) FENCE_D->restore_item(TO);

   if(!present("rope")) new("/d/common/obj/misc/rope")->move(TO);
   if(!present("lantern")) new("/d/common/obj/misc/beacon.c")->move(TO);
   if(!present("dark lantern")) new("/d/common/obj/misc/darkbeacon.c")->move(TO);
   if(!present("tools")) new("/d/common/obj/misc/thief_tools.c")->move(TO);
   if(!present("tools 2")) new("/d/common/obj/misc/thief_tools.c")->move(TO);
   if(!present("blinding powder")) new("/d/common/obj/brewing/powders/blinding_powder")->move(TO);
   if(!present("powder of life") && random(2)) new("/d/common/obj/brewing/powders/powder_of_life")->move(TO);
   if(!present("caltrops")) new("/d/tharis/obj/caltrops")->move(TO);
   i=0;
   while(i<5) {
        i++;
        if(!present("vial "+i)) {
            ob = new ("/d/common/obj/potion/legendary_heal");
            ob->set_uses(15 + random(5));
            ob->move(TO);
        }
    }
    for(i=0;i<9;i++) { // scroll time!
      if(!present("safe scroll 9")) {
        ob = new("/d/magic/safe_scroll");
		ob->set_spell_name(OKSCROLLS[random(sizeof(OKSCROLLS))]);
        ob->move(TO);
      }
    }

    if(!present("vial 6")) { // first five should be kits!
      datamap = ELIXIRS;
      switch(random(4)) {
        case 0:
          ob = new("/d/common/obj/brewing/elixirs/elixir_of_regeneration");
          elixirname = "elixir of regeneration";
        break;
        case 1:
          ob = new("/d/common/obj/brewing/elixirs/elixir_of_displacement");
          elixirname = "elixir of displacement";
        break;
        case 2:
          datamap = OILS;
          ob = new("/d/common/obj/brewing/oils/oil_of_curse_removal");
          elixirname = "oil of curse removal";
        break;
        default:
          datamap = POTIONS;
          ob = new("/d/common/obj/brewing/potions/potion_of_remove_blindness");
          elixirname = "potion of remove blindness";
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
    if(!present("poison 2")) POISON_D->QueryPoisonObject("any", "contact")->move(TO);
    if(!present("poison 3")) POISON_D->QueryPoisonObject("any", "ingested")->move(TO);

    if(!present("playersettabletrapkit")) {
      i = 2;
      while(i) {
        ob = TRAP_D->get_trap_object("epic", "random");
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
