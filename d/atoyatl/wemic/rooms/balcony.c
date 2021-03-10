//Coded by Lujke//
#include <std.h>
#include "../wemic.h"

inherit ROOM;

string night_desc();
string water_desc();
string jungle_desc();
string vista_desc();

void create(){
  ::create();
  set_name("Balcony");
  set_short("A high balcony");
  set_long( (:TO, "long_desc":) );
  set_terrain(VILLAGE);
  set_travel(FOOT_PATH);
  set_smell("default","The air is fresh and clear, pleasantly softened with the moisture of"
                     +" the lake");

  set_listen("default","The waves lap gently against the shore");

  set_exits( ([ "curtain" : ROOMS + "lodge"
  ]) );

  set_items( ([  ({"water", "lake"}) : (:TO, "water_desc":),
             ({"jungle", "trees", "silhouettes"}) : (:TO, "jungle_desc":),
            "vista" : (:TO, "vista_desc":),
            ({"rail", "sturdy rail"}) : "%^ORANGE%^A solid wooden rail has been nailed in"
                                       +" place to reduce the chances of anyone falling into"
                                       +" the lake. It has some %^RESET%^claw marks"
                                       +" %^ORANGE%^in it, but they don't look as serious as"
                                       +" the ones on the pillars inside the lodge"
  ]) );

}

void init(){
  ::init();

}

void reset(){
  string * emotes;
  ::reset();
  emotes = ({
    "A family of three %^ORANGE%^triceratops%^RESET%^ come down to the %^BOLD%^%^CYAN%^l"
   "%^BLUE%^a%^CYAN%^kes%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^de%^RESET%^ to drink",

    "A bone-chilling shriek rents the air as a peaceful %^BOLD%^%^GREEN%^ig%^RESET%^%^CYAN%^u"
    "%^BOLD%^%^BLUE%^a%^GREEN%^nad%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^n%^RESET%^ is set upon"
    " by a voracious pack of %^BOLD%^%^RED%^r%^RESET%^%^RED%^a%^BOLD%^%^RED%^pt%^RESET%^"
    "%^RED%^o%^BOLD%^%^RED%^rs%^RESET%^!",

    "Deep %^BOLD%^%^BLACK%^snuffling%^RESET%^ sounds can be heard as some large creature moves"
    " through the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l"
    "%^BOLD%^%^GREEN%^e%^RESET%^",

    "A mother %^ORANGE%^warthog%^RESET%^ leads a train of tiny %^BOLD%^%^MAGENTA%^piglets%"
    "^RESET%^ down to the %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^"
    "%^CYAN%^r%^RESET%^ to drink", 

    "%^BOLD%^%^BLACK%^A bat-winged pterodactyl circles overhead",

    "%^ORANGE%^The ground %^BOLD%^%^WHITE%^shakes%^RESET%^%^ORANGE%^ with the impact of"
    " %^RESET%^enormous feet%^ORANGE%^, and you see the tail of a mighty %^RESET%^"
    "%^CYAN%^diplodocus%^ORANGE%^ disappearing into the jungle.",

    "%^BOLD%^%^CYAN%^With a %^BOLD%^%^BLUE%^splash%^BOLD%^%^CYAN%^, a %^BOLD%^%^YELLOW%^g"
    "%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^ld%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^n %^BOLD%^"
    "%^CYAN%^coloured fish breaks the surface of the %^BOLD%^%^BLUE%^lake%^BOLD%^%^CYAN%^,"
    " then drops back in again",

    "%^BOLD%^%^BLACK%^A pair of %^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^y%^RED%^e%^BOLD%^%^RED%^s"
    " %^BOLD%^%^BLACK%^gl%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^tt%^RESET%^e%^BOLD%^%^BLACK%^r in"
    " the darkness of the %^RESET%^%^GREEN%^jungle",

    "A %^ORANGE%^monkey%^RESET%^ calls from the %^GREEN%^treetops%^RESET%^",

    "Somewhere nearby, a %^BOLD%^%^YELLOW%^s%^CYAN%^o%^YELLOW%^ngb%^BLUE%^i%^CYAN%^rd%^RESET%^"
    " trills out a complex mating song",
   
    "A startled %^BOLD%^%^BLUE%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^r%^BOLD%^%^CYAN%^r"
    "%^BLUE%^ot%^RESET%^ breaks through the sky in a flash of colour",

    "The low %^ORANGE%^hum%^RESET%^ of insect life carries on, almost unnoticed in the"
    " background", 

    "%^BOLD%^%^CYAN%^The head of a freshwater %^BOLD%^%^GREEN%^snake%^BOLD%^%^CYAN%^ breaks"
    " the surface of the %^BLUE%^lake%^RESET%^",

    "%^BOLD%^%^CYAN%^The %^BLUE%^lake%^CYAN%^ washes against the shore with gentle, lapping"
    " waves"
  });
  if (random (3)>1){
    tell_room(TO, emotes[random(sizeof(emotes))]);
  }
}

string long_desc(){
  if(query_night()){
    return night_desc();
  }

  return "%^BOLD%^%^CYAN%^This %^RESET%^%^ORANGE%^balcony%^BOLD%^%^CYAN%^ overhangs the edge"
        +" of the %^BOLD%^%^BLUE%^water%^BOLD%^%^CYAN%^, and a glorious vista spreads out"
        +" before you. The lake is bounded in the distance by the %^BOLD%^%^GREEN%^j%^RESET%^"
        +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^BOLD%^%^CYAN%^,"
        +" a gentle arc of %^RESET%^%^GREEN%^green%^BOLD%^%^CYAN%^ to contrast with the"
        +" scintillating %^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^z%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^"
        +"re %^BOLD%^%^CYAN%^of the water. The limitless %^BOLD%^%^WHITE%^sky %^BOLD%^"
        +"%^CYAN%^opens up above you, unfathomable in its size and perfection. At the far side"
        +" of the lake, the local wildlife can be observed emerging from the %^RESET%^"
        +"%^GREEN%^trees%^BOLD%^%^CYAN%^ from time to time, to take a drink. A %^RESET%^"
        +"%^ORANGE%^sturdy rail%^BOLD%^%^CYAN%^ between you and the view suggests that perhaps"
        +" even %^BOLD%^%^YELLOW%^W%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^m%^RESET%^%^ORANGE%^i"
        +"%^BOLD%^%^YELLOW%^c %^BOLD%^%^CYAN%^suffer from vertigo sometimes.";
}

string night_desc(){
  return "%^BLUE%^This %^RESET%^%^ORANGE%^balcony%^BLUE%^ overhangs the edge"
        +" of the %^BOLD%^%^BLUE%^water%^RESET%^%^BLUE%^. The area is bathed in %^BOLD%^"
        +"%^WHITE%^moonl%^RESET%^i%^BOLD%^%^WHITE%^ght%^RESET%^%^BLUE%^ and a glorious vista"
        +" spreads out before you. The lake is bounded in the distance by the"
        +" %^BOLD%^%^BLACK%^dark%^RESET%^%^BLUE%^ silhouettes of the %^GREEN%^jungle%^BLUE%^."
        +" The water lapping below you seems calm, untroubled by the nightly noises all around"
        +". The limitless %^BOLD%^%^BLUE%^sky %^RESET%^%^BLUE%^opens up above you, its"
        +" unfathomable size strewn with br%^BOLD%^%^WHITE%^i%^RESET%^%^BLUE%^ght st%^BOLD%^"
        +"%^WHITE%^a%^RESET%^%^BLUE%^rs. At the far side"
        +" of the lake, the local wildlife can dimly seen emerging from the %^RESET%^"
        +"%^GREEN%^trees%^BLUE%^ from time to time, to take a drink. A %^RESET%^"
        +"%^ORANGE%^sturdy rail%^BLUE%^ between you and the view suggests that perhaps"
        +" even %^BOLD%^%^YELLOW%^W%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^m%^RESET%^%^ORANGE%^i"
        +"%^BOLD%^%^YELLOW%^c %^RESET%^%^BLUE%^suffer from vertigo sometimes.";
}
string water_desc(){
  if (query_night()){
    return "%^BLUE%^The lake looks deep and still in the night, its surface kissed with"
          +" m%^BOLD%^%^WHITE%^o%^RESET%^%^BLUE%^o%^RESET%^n%^BLUE%^l%^BOLD%^%^WHITE%^i"
          +"%^RESET%^%^BLUE%^ght and touched by the r%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^fl"
          +"%^RESET%^e%^BLUE%^ct%^BOLD%^%^WHITE%^i%^RESET%^%^BLUE%^ons of the s%^BOLD%^"
          +"%^YELLOW%^t%^RESET%^%^BLUE%^ars.";
  } else {
    return "%^BOLD%^%^CYAN%^The lake is deep and fairly still. The shapes of the %^BOLD%^"
          +"%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
          +"%^GREEN%^e %^BOLD%^%^CYAN%^are reflected near the far shore. Animals pass fairly"
          +" frequently to drink, and water fowl circle overhead, or bob temptingly on the"
          +" waves. Every now and then, shoals of fish or larger shapes can be seen just"
          +" beneath the surface.";
  }
}

string jungle_desc(){
  if (query_night()){
    return "%^BOLD%^%^BLACK%^The twisted, gnarly shapes of the %^RESET%^%^GREEN%^trees%^BOLD%^"
          +"%^BLACK%^ look menacing, silhouetted against the stars. The crunching, crashing"
          +" movements of large creatures are somehow more threatening at night. The balcony"
          +" should be safe enough, though.";
  } else {
    return "%^GREEN%^Even at a distance, the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
          +"%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^%^GREEN%^looks vibrant,"
          +" teeming with life. The trees are twisted and gnarled with age, and thick foliage"
          +" and undergrowth fills the space between them.";
  }
}

string vista_desc(){
  if (query_night()){
    return "%^BOLD%^%^BLACK%^The st%^RESET%^a%^BOLD%^%^BLACK%^r spr%^BOLD%^%^WHITE%^i%^BOLD%^"
          +"%^BLACK%^nkl%^RESET%^e%^BOLD%^%^BLACK%^d s%^RESET%^k%^BOLD%^%^BLACK%^y casts an"
          +" exquisite %^RESET%^%^BLUE%^mantle%^BOLD%^%^BLACK%^ over the expanse of water"
          +" which drops away before you. At the far edge of the lake, the %^RESET%^"
          +"%^GREEN%^treeline%^BOLD%^%^BLACK%^ forms a dark band between the stars and their"
          +" reflections. for the most part, all is still and quiet, aside from the gentle"
          +" lapping of the waves.";
  } else {
    return "%^BOLD%^%^CYAN%^The view from the balcony is spectacular. The %^BOLD%^%^BLUE%^lake"
          +" %^BOLD%^%^CYAN%^drops away beneath you, and expands almost to the horizon,"
          +" bounded by the gentle arcing %^RESET%^%^GREEN%^line of trees %^BOLD%^%^CYAN%^that"
          +" mark the beginning of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
          +"%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^BOLD%^%^CYAN%^. Above you, the"
          +" sky is a vast empty %^RESET%^space%^BOLD%^%^CYAN%^, drawing your eyes and"
          +" inviting you to slow down and just appreciate it for some time.";
  }
}