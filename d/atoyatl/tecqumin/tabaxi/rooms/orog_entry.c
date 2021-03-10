#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  object * rams, ram;
  int i, flag;
  ::create();
  set_short("");
  set_long("%^GREEN%^The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l"
          +"%^BOLD%^%^GREEN%^e %^RESET%^%^GREEN%^gives way here to a %^ORANGE%^clearing%^GREEN%^ in"
          +" front of an impressive %^BOLD%^%^BLACK%^bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck"
          +" gr%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te cl%^RESET%^i%^BOLD%^"
          +"%^BLACK%^ff%^RESET%^%^GREEN%^. The clear ground in front of the cliff is churned to a"
          +" %^ORANGE%^muddy morass%^GREEN%^. A couple of %^ORANGE%^ugly mud huts%^GREEN%^ have been"
          +" constructed to the north, and a few intriguing openings can be seen in the %^BOLD%^"
          +"%^BLACK%^gr%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te cl%^RESET%^i"
          +"%^BOLD%^%^BLACK%^ff");
  set_items(([ ({"cliff", "granite", "granite cliff"}): "%^BOLD%^%^BLACK%^The cliff rises abrubtly"
                  +" from the jungle. It is grim and foreboding and cuts off any further travel to the"
                  +" south and east. Several openings can be seen in the cliff nearby." ,
               ({"opening", "openings"}) : "There are several openings in the %^BOLD%^%^BLACK%^bl"
                  +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck gr%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^n"
                  +"%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^ of the cliff. Most are well above ground"
                  +" level and hard to reach, but there is one at least that you could walk into. The"
                  +" opening at ground level is big enough for something larger than a human to enter."
                  +" Inside looks darker than a murderer's heart."
               ]));
  set_exits( ([ "east" : TABAXROOM + "jungle22" , "opening" : TABAXROOM + "orogs01.c"
             ]) );
  reset();
}

void reset(){
  object * rams, ram, ladder;
  int i, flag;
  ::reset();
  rams = children(MOB + "ram_mob");
  flag = 0;
  if (sizeof(rams)>0){
    for (i=0;i<sizeof(rams);i++){
      if (objectp(rams[i])&& objectp(environment(rams[i]))){
        flag = 1;
        break;
      }
    }
  }
  if (flag <1){
    ram = new(MOB + "ram_mob");
    ram->move(TO);
  }
  for (i=0;i<2;i++){
    ladder = new (TABAXOBJ + "ladder");
    ladder->move(TO);
  }
}

void init(){
  ::init();
  set_had_players(3);
}
