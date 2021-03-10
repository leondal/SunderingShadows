#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"inner";

void create() {
    ::create();
    set_name("A dark altar");
    set_short("%^RED%^A dark altar%^RESET%^");
    set_long("%^CYAN%^The sanctum stairs reach their summit here, at the foot of a circular platform.  "
"Directly in the centre of the platform is a wide altar, that has been darkened with what look like "
"%^RED%^bloodstains%^CYAN%^.  Marble walls surround the platform on all sides except to the north, where "
"stairs lead back down to the lower area of the sanctum.  Above the altar, mosaic tiles pattern the roof, "
"which is encircled by ornate engraved borders in the marble stone.  Tiny %^ORANGE%^golden%^CYAN%^ veins "
"trail through the %^WHITE%^milky-hued%^CYAN%^ walls, running down into the marble floor and along "
"beneath your feet.  Lit candles line the walls around the platform, "
"%^YELLOW%^illuminating%^RESET%^%^CYAN%^ the area so that no shadows can be seen.  A strange, surreal "
"feeling hangs in the air here, as though someone is watching you constantly.%^RESET%^\n");
    add_item(({ "steps","stairs" }),"%^CYAN%^Wide-spaced marble steps lead down from here, to the lower "
"sanctum.%^RESET%^");
    add_item(({ "altar" }),"%^CYAN%^A wide, flat altar rests in the centre of the platform here.  It is "
"crafted of %^WHITE%^marble%^CYAN%^ that may once have been flawless, though now it is covered in dark "
"stains the colour of %^RED%^blood%^CYAN%^.%^RESET%^");
    set_exits(([
      "north" : ROOMS+"inner2"
    ]));
    set_pre_exit_functions(({"north"}),({"gonorth_fun"}));
    if(!present("archemond")) { new(MON+"mage")->move(TO); }
}

void reset() {
    object *pplz,myroom;
    int flag,i;
    ::reset();
    pplz = all_living(TO);
    if(!pplz) flag = 0; // noone in the room
    else {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }
    myroom = find_object_or_load(ROOMS+"inner2");
    pplz = all_living(myroom);
    if(!pplz) flag = 0; // noone in the room
    else {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }
    myroom = find_object_or_load(ROOMS+"inner1");
    pplz = all_living(myroom);
    if(!pplz) flag = 0; // noone in the room
    else {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }
    if(!present("archemond") && !flag) {
      new(MON+"mage")->move(TO);
    }
}

int gonorth_fun() {
  tell_object(TP,"You slowly descend the marble stairs.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" slowly descends the marble stairs.\n",TP);
  }
  return 1;
}
