#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("statue");
   set_id(({ "statue", "oak statue" }));
   set_short("%^ORANGE%^An oak crafted statue of five elves.");
   set_obvious_short("%^ORANGE%^An oak crafted statue of five elves");
   set_long(
        "A female elf with long hair and dressed in a flowing gown stands predominately in"+
        " the center of this beautifully carved %^ORANGE%^oak%^RESET%^ statue. Her"+
        " hand outstretched defiantly showing her symbol to"+
        " her unseen enemy. \n\n To her left is a male elf in %^BOLD%^%^BLACK%^leather"+
        " %^RESET%^armor weilding scimitars, standing poised and ready for action. A"+
        " symbol is worn loosely around his neck, and"+
        " a wolf sits obediantly at his feet. \n\nBehind and slightly to the right of the"+
        " central figure is a female elf with long hair wearing %^BOLD%^%^GREEN%^platemail%^RESET%^, her"+
        " hands are clasping a symbol and she stands"+
        " firmly in prayer. \n\nImmediately right of the center figure a male elf covered"+
        " in %^BOLD%^%^BLUE%^ta%^CYAN%^tt%^BLUE%^oos%^RESET%^ and wearing"+
        " a holy symbol is slightly crouched and peering"+
        " into the distance, holding a bow in his hands that has an arrow notched and ready"+
        " to fire.\n\n Kneeling in front protectively is a male elf with long hair, wearing"+
        " what appears to be plate mail, holding a symbol"+
        " in one hand and a mace in the other, the head of which rests on the"+
        " ground. There are some elven %^GREEN%^symbols%^RESET%^ written into the base of the statue."
   );
   set_weight(1000);
   set_value(0);
   set_property("no animate", 1);
}

   void init() {
      ::init();
      add_action("read_symbols","read");
}

int read_symbols(string str) {
   if(str != "symbols") {
   return 0;
   }
   if( (string)TP->query_race() != "elf") {
      tell_object(TP,"The symbols are only gibberish.");
      tell_room(ETP,""+TPQCN+" reads the symbols.",TP);
      return 1;
   }
   tell_object(TP,
        "%^BOLD%^Shuko, %^CYAN%^Aramel,%^YELLOW%^Shrydelhi, %^BLUE%^Alveric,%^RESET%^%^YELLOW%^ and Iaido.\n"+
        "%^YELLOW%^Together in faith we unite.");
   tell_room(ETP,""+TPQCN+" reads the symbols.",TP);
   return 1;
}
