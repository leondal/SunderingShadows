#include <std.h>
#include <magic.h>
inherit ROOM;

#define DARKWOOD "/d/darkwood/room/"
#define TABOR "/d/darkwood/tabor/road/"
#define THARIS "/d/tharis/road/"
#define SHADOW "/d/shadow/room/forest/"
#define DAGGER "/d/dagger/road/"
#define CHARU "/d/shadow/room/pass/"

#define NOTDARKWOOD ({\
   "/d/darkwood/room/rhapsody.c",\
   "/d/darkwood/room/rhapsody.bak",\
   "/d/darkwood/room/backstage.c",\
   "/d/darkwood/room/backstage.bak",\
   "/d/darkwood/room/backroom.c",\
   "/d/darkwood/room/roof.c",\
   "/d/darkwood/room/tetherarea.c",\
})
#define NOTTHARIS ({\
   "/d/tharis/road/cave1.c",\
   "/d/tharis/road/cave2.c",\
   "/d/tharis/road/cave3.c",\
   "/d/tharis/road/mill.c",\
   "/d/tharis/road/road.c",\
   "/d/tharis/road/sroad1.c",\
   "/d/tharis/road/sroad2.c",\
   "/d/tharis/road/sroad3.c",\
   "/d/tharis/road/sroad4.c",\
   "/d/tharis/road/sroad5.c",\
   "/d/tharis/road/sroad6.c",\
})
#define NOTSHADOW ({\
   "/d/shadow/room/forest/forest.h",\
})
#define NOTCHARU ({\
   "/d/shadow/room/pass/pass16.old",\
})
#define NOTDAGGER ({\
   "/d/dagger/road/hut.c",\
   "/d/dagger/road/bridge2.c",\
   "/d/dagger/road/monsters_d.bkp",\
   "/d/dagger/road/monsters_d.c",\
   "/d/dagger/road/road2.bak.saide",\
   "/d/dagger/road/road2b.bak.saide",\
   "/d/dagger/road/road3.bak.saide",\
   "/d/dagger/road/road1.c",\
   "/d/dagger/road/road2.c",\
   "/d/dagger/road/road2b.c",\
   "/d/dagger/road/road3.c",\
   "/d/dagger/road/road4.c",\
   "/d/dagger/road/tollbooth.c",\
   "/d/dagger/road/tollbooth2.c",\
   "/d/dagger/road/short.h",\
   "/d/dagger/road/tsrroom.c",\
   "/d/dagger/road/templeportal.c",\
})

int running;
string destination;
void activate_fun();
void get_rooms();

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_name("A glittering bubble of force");
   set_short("%^BOLD%^%^CYAN%^A gl%^WHITE%^i%^CYAN%^ttering bubble of for%^BLUE%^c%^CYAN%^e%^RESET%^");
   set_long("%^RESET%^%^CYAN%^You appear to be standing inside a massive orb that obscures all view of the world beyond.  "
"Its surface %^BOLD%^%^WHITE%^gl%^YELLOW%^i%^WHITE%^tters %^RESET%^%^CYAN%^in shifting opalescent shades of azure, "
"shedding faint %^YELLOW%^light %^RESET%^%^CYAN%^around.  Smooth to the touch, the bubble seems impenetrable to all "
"attempts at %^BOLD%^%^MAGENTA%^force%^RESET%^%^CYAN%^.%^RESET%^");
   running = 0;
   destination = "/d/shadow/room/forest/road16";
   get_rooms();
   while(!objectp(find_object_or_load(destination))) get_rooms();
}

void init() {
   ::init();
   if(!running) {
     running = 1;
     call_out("activate_fun",1);
   }
   add_action("quit_func","quit");
}

int quit_func(string str) {
   tell_object(TP,"%^BOLD%^%^CYAN%^The bubble s%^WHITE%^h%^CYAN%^imm%^BLUE%^e"
"%^CYAN%^rs and vanishes, leaving you somewhere else entirely!%^RESET%^");
   TP->move(destination);
   TP->force_me("quit");
   return 1;
}

void activate_fun() {
   object *inhabitants;
   int i;
   switch(running+random(3)) {
     case 0..3:
     tell_room(TO,"%^BOLD%^%^CYAN%^The orb gl%^WHITE%^i%^CYAN%^tters, its azure sheen shifting slightly.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^BOLD%^%^CYAN%^The surface of the bubble glistens, refracting faint hints of %^YELLOW%^l%^WHITE%^i"
"%^YELLOW%^ght%^CYAN%^.%^RESET%^");
     break;
     case 5:
     tell_room(TO,"%^BOLD%^%^CYAN%^A r%^BLUE%^i%^CYAN%^pple runs across the surface of the bubble, as if it were "
"becoming unstable.%^RESET%^");
     break;
     default:
     tell_room(TO,"%^BOLD%^%^CYAN%^The bubble s%^WHITE%^h%^CYAN%^imm%^BLUE%^e%^CYAN%^rs and vanishes, leaving you "
"somewhere else entirely!%^RESET%^");
     inhabitants = all_living(TO);
     for(i = 0;i< sizeof(inhabitants);i++) inhabitants[i]->move_player(destination);
     running = 0;
     return;
     break;
   }
   running++;
   call_out("activate_fun",ROUND_LENGTH);
}

void get_rooms() {
    string *rooms, *rooms2, thisroom;
    int i;

    rooms = ({});
    rooms2 = ({});
    switch(random(6)) {
      case 0:
      rooms = get_dir(DARKWOOD);
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = DARKWOOD+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTDARKWOOD;
      break;

      case 1:
      rooms2 = get_dir(TABOR);
      break;

      case 2:
      rooms = get_dir(THARIS);
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = THARIS+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTTHARIS;
      break;

      case 3:
      rooms = get_dir(SHADOW);
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = SHADOW+rooms[i];
        if(strsrch(rooms[i],"owagon") == -1)
          rooms2 += ({thisroom});
      }
      rooms2 -= NOTSHADOW;
      break;

      case 4:
      rooms = get_dir(CHARU);
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = CHARU+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTCHARU;
      break;

      case 5:
      rooms = get_dir(DAGGER);
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = DAGGER+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTDAGGER;
      break;
    }
    destination = rooms2[random(sizeof(rooms2))];
}
