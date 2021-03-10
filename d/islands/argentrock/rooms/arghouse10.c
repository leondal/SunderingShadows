#include <std.h>
#include <move.h>
#include "/d/islands/argentrock/argabbr.h"

inherit ROOM;

int redset,yellowset,blueset,greenset,whiteset,lit,sword_shown,retrieved,
   guard_up;

void create() {
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set("short","%^BOLD%^%^RED%^Hidden chamber");
   set("long","%^BOLD%^%^RED%^Hidden chamber
%^RESET%^%^CYAN%^You have entered a hidden chamber under the laboratory of the mad mage Batlin. There are two %^WHITE%^can%^BOLD%^%^BLACK%^d%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^e%^RESET%^ %^WHITE%^st%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^c%^BOLD%^%^BLACK%^k%^RESET%^%^WHITE%^s%^CYAN%^ sitting on an %^BOLD%^%^BLACK%^altar%^RESET%^%^CYAN%^ made out of some sort of black materials. Strange %^BOLD%^%^CYAN%^run%^BLUE%^e%^CYAN%^s%^RESET%^%^CYAN%^ are all over the %^BOLD%^%^CYAN%^wa%^BLUE%^l%^CYAN%^ls%^RESET%^%^CYAN%^ and %^BOLD%^%^CYAN%^ce%^BLUE%^i%^CYAN%^l%^BLUE%^i%^BLUE%^n%^CYAN%^g%^BLUE%^.%^RESET%^%^CYAN%^ A large red %^BOLD%^%^RED%^p%^RESET%^%^RED%^entagon%^CYAN%^ with a small candle %^BOLD%^%^WHITE%^hold%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^ placed on each %^BOLD%^%^RED%^obelisk%^RESET%^%^CYAN%^ is drawn on the %^BOLD%^%^CYAN%^f%^BLUE%^l%^CYAN%^oo%^BLUE%^r%^CYAN%^.%^RESET%^%^CYAN%^ A strange %^ORANGE%^tali%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^m%^BOLD%^%^ORANGE%^a%^RESET%^%^ORANGE%^n%^CYAN%^ is placed on the altar. Some small %^WHITE%^c%^BOLD%^%^WHITE%^andle%^RESET%^%^WHITE%^s%^CYAN%^ are scattered on the floor.%^RESET%^
");
   set_property("indoors",1);
   set_property("light",-2);
   set_property("no teleport",1);
   set_listen("default","This room is extraordinarily quiet and peace.");
   set_smell("default","Smells of burnt candles fills your nosetrils.");
    set_items( (["candle sticks":"On each candle stick there is a small "+
      "black candle with burnt candlewick resting on it.",
       "altar": (: TO,"alt_desc" :),
       "runes":"These pagan runes draw a fearful picture in your mind. "+
      "They must be used by pagans to worship their god.",
      ({"walls","ceiling"}):"There are strange pagan runes all over the "+
      "walls and ceiling of this chamber. Yet you cannot understand "+
      "what these runes mean.",
      "pentagon": (: TO,"pen_desc" :),
      "holder":"It is used to hold a small candle.",
      "obelisk":"There are five obelisks, Aphelion the top one, Mesostel "+
      "Pa the middle right and Mesostel Ze the middle left, Perivolcan "+
      "Pa the lower right and Perivolcan Ze the lower left.",
      "floor":"A large red pentagon is drawn on the floor.",
      "talisman": (: TO,"tali_desc" :),
      "depression":"A small depression at the center of the pentagon.",
       "candles":"There are candles of five colors, red, yellow, blue, "+
      "green and white. Looks like you can place them on the different "+
      "obelisks."]) );
   set_exits( (["out":PATH+"arghouse11"]) );
}

void init() {
   ::init();
   add_action("place_candle","place");
   add_action("light_candle","light");
   add_action("put_talisman","put");
   add_action("retrieve_sword","retrieve");
}

int place_candle(string str) {
   string colour,obelisk;
   if(!str) {
      notify_fail("Place what?\n");
      return 0;
   }
   sscanf(str,"%s %*s %*s %s",colour,obelisk);
   if(colour == "white") {
      if(obelisk == "aphelion") {
         if(whiteset) {
            write("It is already there.");
            return 1;
         }
         write("You place a white candle on the Aphelion.\n"+
            "%^CYAN%^The candle holder at Aphelion starts glowing.");
         say(TPQCN+" places a white candle on the Aphellion.\n"+
            "%^CYAN%^The candle holder at Aphelion starts glowing.");
         whiteset = 1;
         return 1;
      }
      else {
         write("Choose another obelisk.");
         return 1;
      }
   }
   if(colour == "red") {
      if(obelisk == "mesostel pa") {
         if(redset) {
            write("It is already there.");
            return 1;
         }
         write("%^RED%^You place a red candle on the Mesostel Pa.\n"+
            "%^CYAN%^The candle holder at Mesostel Pa starts glowing.");
         say("%^RED%^"+TPQCN+" places a red candle on the Mesostel Pa.\n"+
            "%^CYAN%^The candle holder at Mesostel Pa starts glowing.");
         redset = 1;
         return 1;
      }
      else {
         write("Choose another obelisk.");
         return 1;
      }
   }
   if(colour == "yellow") {
      if(obelisk == "mesostel ze") {
         if(yellowset) {
            write("It is already there.");
            return 1;
         }
         write("%^YELLOW%^You place a yellow candle on the Mesostel Ze.\n"+
            "%^RESET%^CYAN%^The candle holder at Mesostel Ze starts "+
            "glowing.");
         say("%^YELLOW%^"+TPQCN+" places a yellow candle on the Mesostel "+
            "Ze.\n%^RESET%^CYAN%^The candle holder at Mesostel Ze starts "+
            "glowing.");
         yellowset = 1;
         return 1;
      }
      else {
         write("Choose another obelisk.");
         return 1;
      }
   }
   if(colour == "blue") {
      if(obelisk == "perivolcan pa") {
         if(blueset) {
            write("It is already there.");
            return 1;
         }
         write("%^BLUE%^You place a blue candle on the Perivolcan Pa.\n"+
            "%^CYAN%^The candle holder at Perivolcan Pa starts glowing.");
         say("%^BLUE%^"+TPQCN+" places a blue candle on the Perivolcan "+
            "Pa.\n%^CYAN%^The candle holder at Perivolcan Pa starts "+
            "glowing.");
         blueset = 1;
         return 1;
      }
      else {
         write("Choose another obelisk.");
         return 1;
      }
   }
   if(colour == "green") {
      if(obelisk == "perivolcan ze") {
         if(greenset) {
            write("It is already there.");
            return 1;
         }
         write("%^GREEN%^You place a green candle on the Perivolcan Ze.\n"+
            "%^CYAN%^The candle holder at Perivolcan Ze starts glowing.");
         say("%^GREEN%^"+TPQCN+" places a green candle on the Perivolcan "+
            "Ze.\n%^CYAN%^The candle holder at Perivolcan Ze starts "+
            "glowing.");
         greenset = 1;
         return 1;
      }
      else {
         write("Choose another obelisk.");
         return 1;
      }
   }
    notify_fail("You should place candles of different color on "+
      "different obelisks.\n");
   return 0;
}

int light_candle(string str) {
   if(!str) {
      notify_fail("Light what?\n");
      return 0;
   }
   if(str == "candles") {
      if(lit) {
         write("The candles are already lit.");
         return 1;
      }
      if(whiteset == redset == yellowset == blueset == greenset == 1) {
         write("%^MAGENTA%^You light the candles and the whole pentagon "+
            "starts to glow.");
         say("%^MAGENTA%^"+TPQCN+" lights the candles and the whole "+
            "pentagon starts to glow.");
         lit = 1;
         return 1;
      }
      notify_fail("You need to place all the candles first!\n");
      return 0;
   }
   notify_fail("You cannot light that!\n");
   return 0;
}

int put_talisman(string str) {
   string thing,container;
   if(!str)
      return 0;
   sscanf(str,"%s %*s %s",thing,container);
   if(thing == "talisman" && container != "depression") {
      notify_fail("Put talisman on what?\n");
      return 0;
   }
   if(thing == "talisman" && container == "depression") {
      if(!lit) {
         notify_fail("You need to light the candles first!\n");
         return 0;
      }
      write("%^CYAN%^You put the talisman on the depression at the "+
         "center of the pentagon.\nSuddenly you feel that you are "+
          "possessed by an unknown force and start staring at the "+
         "glowing pentagon!");
      say("%^CYAN%^"+TPQCN+" puts the talisman on the depression at the "+
         "center of the pentagon.\n"+TPQCN+" suddenly looks weird and "+
         "stares at the glowing pentagon.");
      call_out("release",20);
      TP->set_paralyzed(20,"You are possessed by an unknown force and "+
         "cannot find your soul!");
      call_out("special",10);
      return 1;
   }
   return 0;
}

void release() {
    write("%^CYAN%^You feel that your soul return to you.");
   say("%^CYAN%^"+TPQCN+" looks normal again.");
}

void special() {
   write("%^RED%^You close your eyes and start to chant phrases of an "+
      "unknown language.\nYour hands wave in strange motions.\nYou "+
      "shout: INVAS CORPS SADANIAN!!!");
   say("%^RED%^"+TPQCN+" closes "+TP->query_possessive()+" eyes and "+
      "starts to perform some pagan ritual.\n"+TPQCN+" chants phrases of "+
       "an unknown language, "+TP->query_possessive()+" hands wave in "+
      "srange motions.\n"+TPQCN+" shouts: INVAS CORPS SADANIAN!!!");
   tell_room(TO,"%^MAGENTA%^The whole room shakes violently and the "+
       "altar opens. A %^ORANGE%^Great sword %^MAGENTA%^raises from "+
       "beneath the altar.");
    add_item("sword","A magnificent Great sword with a symbol of the "+
       "Sun carved in the blade. You need to retrieve it.");
   sword_shown = 1;
}

int retrieve_sword(string str) {
   object mon,obj;
   if(!str) {
      notify_fail("Retrieve what?\n");
      return 0;
   }
   if(str == "sword" || str == "great sword") {
      if(sword_shown != 1) {
         notify_fail("You don't see a sword here!\n");
         return 0;
      }
      if(retrieved == 1) {
         notify_fail("The sword has been retrieved already!\n");
         return 0;
      }
      if(guard_up == 0) {
         write("%^RED%^As you try to retrieve the sword, a large shadow "+
            "raises from the center of the pentagon!");
         say("%^RED%^As "+TPQCN+" tries to retrieve the sword, a large "+
            "shadow raises from the center of the pentagon!");
         mon = new(MON+"jarkunish");
         mon->move(TO);
         guard_up = 1;
         switch( TP->query_alignment() ) {
            case 3:
            case 6:
            case 9:
               add_pre_exit_function("out","no_out");
               mon->force_me("say %^RED%^Prepare to die EVIL one!");
               mon->kill_ob(TP,1);
               break;
            case 2:
            case 5:
            case 8:
               mon->force_me("say %^RED%^What is your propose here? This "+
                  "sword will not serve you!");
               mon->force_me("say %^RED%^You better leave here at once "+
                  "or I will trash you!");
               break;
            case 1:
            case 4:
            case 7:
               add_pre_exit_function("out","no_out");
               mon->force_me("say %^RED%^Well you must defeat me first "+
                   "to show that you can truly master this sword!");
               mon->force_me("say %^RED%^But, be warned, the sword might "+
                  "refuse you.");
               mon->kill_ob(TP,1);
               break;
         }
         return 1;
      }
      if( !present("jarkunish") ) {
         write("%^CYAN%^You retrieve the %^ORANGE%^Great sword of Light "+
             "%^CYAN%^from the altar!");
         say("%^CYAN%^"+TPQCN+" retrieves the %^ORANGE%^Great sword of "+
             "Light %^CYAN%^from the altar!");
         obj = new(OBJ+"sword_light");
         if(obj->move(TP) != MOVE_OK)
            obj->move(ETP);
         else
            obj->move(TP);
         retrieved = 1;
         remove_item("sword");
         return 1;
      }
      notify_fail("Jarkunish the Great skeletal warrior will not let "+
         "you!\n");
      return 0;
   }
   notify_fail("You cannot retrieve that!\n");
   return 0;
}

int no_out() {
   if( present("jarkunish") ) {
      write("Jarkunish the Great skeletal warrior will not let you wimp "+
         "out of the battle!!");
      say("As "+TPQCN+" attempts to leave, Jarkunish the Great skeletal "+
         "warrior blocks "+TP->query_possessive()+" way out!!");
      return 0;
   }
   return 1;
}

string pen_desc() {
   if(whiteset == redset == yellowset == blueset == greenset == 0)
       return "The red pentagon is large. It occupies the whole room. "+
       "One candle holder is placed on each obelisk of the figure. A "+
      "depression is at the center of the pentagon.";
   if(sword_shown)
      return "The red pentagon is large. It occupies the whole room. "+
       "One candle holder is placed on each obelisk of the figure. A "+
      "depression is at the center of the pentagon. All the five candles "+
      "are lit. A talisman is put on the depression and the whole "+
      "pentagon is glowing.";
   if(lit)
       return "The red pentagon is large. It occupies the whole room. "+
       "One candle holder is placed on each obelisk of the figure. A "+
      "depression is at the center of the pentagon. All the five "+
      "candles placed at the obelisks are lit. You wonder what you need "+
      "to do next.";
   if(whiteset == redset == yellowset == blueset == greenset == 1)
       return "The red pentagon is large. It occupies the whole room. "+
       "One candle holder is placed on each obelisk of the figure. A "+
      "depression is at the center of the pentagon. All of the obelisks "+
       "have a candle. The candles have not been lit.";
    return "The red pentagon is large. It occupies the whole room. One "+
       "candle holder is placed on each obelisk of the figure. A "+
      "depression is at the center of the pentagon. Some of the "+
       "obelisks already have a candle.";
}

string tali_desc() {
   if(sword_shown)
      return "It is a small talisman fitted into the small depression at "+
      "the center of the pentagon.";
   return "It is a small talisman about the size of the small depression "+
       "at the center of the pentagon. It is placed on top of the altar. "+
       "You wonder what the purpose of this talisman is.";
}

string alt_desc() {
   if(sword_shown)
       return "The altar is made of some black material of an unknown nature. "+
      "A %^ORANGE%^Great sword %^RESET%^is there on top of it.";
   return "The altar is made of some black material of an unknown "+
      "nature. A strange talisman is placed on top of it.";
}

void reset() {
   object *players;
   int num,i;
   players = all_living(TO);
   num = sizeof(players);
   for(i = 0;i < num;i++) {
      if( interactive(players[i]) )
         return;
   }
   ::reset();
   whiteset = 0;
   redset = 0;
   yellowset = 0;
   greenset = 0;
   blueset = 0;
   lit = 0;
   sword_shown = 0;
   retrieved = 0;
   guard_up = 0;
   remove_pre_exit_function("out");
}
