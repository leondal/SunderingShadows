#include <std.h>
#include "/d/common/common.h"
#include "../inherit/keep.h"
inherit ROOM;

int FLAG, OPEN;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A hidden room");
   set_short("%^ORANGE%^A hidden room%^RESET%^");
   set_long("%^ORANGE%^A hidden room%^RESET%^\n"
"The corridor leads to a dead end here in this hidden room, arrayed much "
"like a lounge.  A worn-out %^ORANGE%^couch %^RESET%^rests against the "
"northern wall, and a tiny %^RED%^desk %^RESET%^stands in the southwestern "
"corner.  The floor is covered in numerous overlapping %^ORANGE%^rugs "
"%^RESET%^and there is an %^YELLOW%^oil lamp %^RESET%^on a %^BLUE%^stand "
"%^RESET%^to the south. There is a small iron %^BOLD%^%^BLACK%^chest "
"%^RESET%^against the western wall, flanked by two granite "
"%^BOLD%^%^BLACK%^pedestals%^RESET%^.\n");
   set_smell("default","The sulfuric scent from the passage lingers in this room.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
     ({"floor","rugs"}) : "%^GREEN%^Several thick rugs cover the entire "
"floor, preventing you from having to walk on the cold stone blocks "
"beneath.%^RESET%^",
     "desk" : "%^RED%^There is a tiny writing desk in the southwestern "
"corner.  A %^ORANGE%^journal %^RED%^is on top of it.  A cushioned "
"%^RESET%^chair %^RED%^is next to the desk.%^RESET%^",
     "journal" : ({"%^ORANGE%^This is a well worn, leather-bound journal "
"that probably belonged to a mage. It has a few notes about spells and "
"traps, but nothing that's very decipherable or of much interest.  You "
"could probably %^YELLOW%^read%^RESET%^%^ORANGE%^ a few parts if you really "
"wanted to.%^RESET%^","%^RED%^Most of the pages are now long decayed from "
"age, the writing long faded, but the occasional passage of text can be "
"understood here and there...\n\n%^ORANGE%^'...the keep for my family.  No "
"longer will the Kilgore name be listed among the commoners!'\n\n\t"
"%^ORANGE%^'...progress on the summoning spells.  Already I can control the "
"smallest of elementals, made of steam and ice...'\n\n%^ORANGE%^'..."
"intrinsic art of psionics and mentalists still eludes me.  Me, a great "
"wizard of arcana, confounded by mere tricks of the...'\n\n%^ORANGE%^'... "
"Daily she ails, as the sickness eats her from within.  But I will not "
"stoop to crawling back before the priesthood, I will not!\n\n\t%^ORANGE%^"
"...left my guardians to protect against intruders, for they will not steal "
"what was mine.  Never will my work fall into the hands of...'\n\n%^RED%^"
"There is nothing more beyond this page, the rest of the book is empty"
".%^RESET%^","wizish"}),
     "chair" : "%^ORANGE%^This is a comfortable looking chair.  Whoever "
"used this place seems to have liked comfort.%^RESET%^",
     "couch" : "%^ORANGE%^This is a very cozy looking couch. It appears to "
"have gotten a lot of use, and was perhaps even used as a bed more than "
"once.%^RESET%^",
     ({"lamp","oil lamp"}) : "%^YELLOW%^There is an oil lamp with a pretty "
"stained glass lampshade, sitting on the %^RESET%^%^BLUE%^night stand "
"%^YELLOW%^on the south side of the room.%^RESET%^",
     ({"stand","night stand","nightstand"}) : "%^BLUE%^The night stand is "
"made of ebony and was probably on the expensive side.  Whoever used this "
"place must have been rich.%^RESET%^",
     "chest" : "%^BOLD%^%^BLACK%^There is a simple iron chest against the "
"west wall of the room, flanked by two granite %^RESET%^pedestals"
"%^BOLD%^%^BLACK%^.  You could probably attempt to %^YELLOW%^open "
"%^BLACK%^it.%^RESET%^",
     ({"pedestal","granite pedestal","pedestals"}) : "%^BOLD%^%^BLACK%^The "
"pedestals are ornately worked granite, which is unusual by itself.  But "
"what is more unusual are their flat tops, where a statue or some other "
"item might usually be set, that is completely empty.%^RESET%^",
   ]));
   set_exits(([
     "east" : ROOMS"floor7",
   ]));
}

void reset() {
   ::reset();
   if(random(2)) {
      OPEN = 0;
      FLAG = 0;
      add_item("chest","%^BOLD%^%^BLACK%^There is a simple iron chest "
"against the west wall of the room, flanked by two granite %^RESET%^"
"pedestals%^BOLD%^%^BLACK%^.  You could probably attempt to %^YELLOW%^open "
"%^BLACK%^it.%^RESET%^");
   }
}

void init() {
   ::init();
   add_action("open","open");
}

int open(string str) {
   object ob;

   if(str != "chest") {
      tell_object(TP,"Open what?");
      return 0;
   }
   if(OPEN) {
      tell_object(TP,"The chest has already been opened.");
      return 1;
   }
   if(!FLAG) {
     tell_object(TP,"%^BOLD%^%^WHITE%^As you move towards the chest, a hiss "
"heralds the sudden appearance of two monsters, which attack you!%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^WHITE%^As "+TPQCN+" moves toward the chest, a "
"hiss heralds the sudden appearance and attack of two monsters"
"!%^RESET%^",TP);
     new(MONS+"mephit")->move(TO); 
     new(MONS+"mephit")->move(TO); 
     FLAG = 1;
     return 1;
   }
   if(present("steam mephit")) {
      tell_object(TP,"%^BOLD%^%^WHITE%^You can't gear near the chest, the "
"mephit is in the way!%^RESET%^");
      return 1;
   }
   else {
     tell_object(TP,"%^YELLOW%^You open the chest and discover a key and "
"some other items inside.%^RESET%^");
     tell_room(ETP,"%^YELLOW%^"+TPQCN+" opens the chest and finds a few "
"things.%^RESET%^",TP);
     new(OBJ2+"key")->move(TO);
     new(OBJ2+"staffbands")->move(TO);
     switch(random(8)) {
       case 0..1:
         ob = new("/d/magic/scroll");
         ob->set_spell(1);
         ob->move(TO);
         break;
       case 2:
         RANDSTUFF->find_stuff(TO, "component", random(5)+1);
         break;
       case 3:
         RANDSTUFF->find_stuff(TO, "psi_component", random(5)+1);      
         break;
       case 4..5:
         RANDSTUFF->find_stuff(TO, "coins", random(50)+10);      
         break;
       case 6..7:
         ob = new(CPOTION"newbie_healing");
         ob->set_uses(random(5)+1);
         ob->move(TO);
         break;
     }
     add_item("chest","%^BOLD%^%^BLACK%^The iron chest appears to be open "
"and cleaned out.%^RESET%^");
     OPEN = 1;
     return 1;
   }
}
