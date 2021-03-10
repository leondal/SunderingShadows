//Coded by Lujke//
#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom.c";

int numdevils;
int maxdevils;
int stream_searched;

string long_desc();
void enter_devilkin(string expression);
void enter_devilkin2(int chance, string expression);
void enter_devilkin3();
int enter_waterfall(string str);
int hum_tune(string str);
void hum_tune3(int chance, string expression);
void hum_tune4();
int lean_stalagmite(string str);
int stream_search(string str);
void stream_search2(object ob);

void create(){
  ::create();
  stream_searched = random(2);
  set_name("An underground stream");
  set_short("%^MAGENTA%^An %^BLUE%^underground stream");
  numdevils = 0;
  maxdevils = 0;
  set_long( (:TO, "long_desc":));
  
  set_property("indoors",1);
  set_property("light",2);
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","%^CYAN%^There is the scent of %^BOLD%^%^CYAN%^w"
                     +"%^BOLD%^%^WHITE%^a%^BLUE%^t%^BOLD%^%^CYAN%^er"
                     +" %^RESET%^%^CYAN%^nearby.");

  set_listen("default","The sound of the %^BOLD%^%^BLUE%^waterfall"
                      +"%^RESET%^%^GREEN%^ almost drowns out the sound of"
                      +" music from deep within the caverns.");

  set_listen("music","%^MAGENTA%^above the noise of the %^BLUE%^t%^BOLD%^"
                    +"%^WHITE%^u%^BLUE%^mbl%^CYAN%^i%^BLUE%^ng w%^BOLD%^"
                    +"%^BLUE%^a%^RESET%^%^BLUE%^terf%^BOLD%^%^WHITE%^a"
                    +"%^RESET%^%^BLUE%^ll%^RESET%^%^MAGENTA%^, you can"
                    +" hear a %^BOLD%^strange%^RESET%^%^MAGENTA%^, yet"
                    +" somehow %^BLUE%^comforting%^RESET%^%^MAGENTA%^"
                    +" tune played on deep sounding pipes somewhere"
                    +" further within the %^BOLD%^%^BLACK%^caves%^RESET%^"
                    +"%^MAGENTA%^. There is something %^CYAN%^hauntingly"
                    +" familiar%^MAGENTA%^ about the song, as if it were"
                    +" something you might hum along to.");

  set_exits( ([
	"north":TUNNELS + "tun01",
	"northwest":TUNNELS + "tun16",

    ]) );

  set_items( ([ "waterfall":"%^BOLD%^%^BLUE%^The %^CYAN%^water%^BLUE%^"
                           +" g%^WHITE%^u%^BLUE%^shes in through an"
                           +" %^BOLD%^%^BLACK%^opening %^BLUE%^near the"
                           +" top of the cavern and t%^WHITE%^u%^RESET%^"
                           +"%^CYAN%^m%^BOLD%^%^BLUE%^bl%^CYAN%^e%^BLUE%^"
                           +"s %^CYAN%^s%^BLUE%^p%^RESET%^e%^BOLD%^"
                           +"%^BLUE%^c%^WHITE%^t%^BLUE%^a%^RESET%^"
                           +"%^CYAN%^c%^BOLD%^%^BLUE%^ul%^WHITE%^ar"
                           +"%^CYAN%^l%^BLUE%^y down the %^BOLD%^"
                           +"%^BLACK%^rocks %^BLUE%^for almost a hundred"
                           +" feet, %^CYAN%^spl%^WHITE%^a%^RESET%^"
                           +"%^CYAN%^%^s%^BOLD%^%^WHITE%^h%^CYAN%^ing"
                           +"%^BLUE%^ and %^CYAN%^spraying%^BLUE%^ as it"
                           +" goes. A fine %^RESET%^%^CYAN%^m%^RESET%^i"
                           +"%^CYAN%^st%^BOLD%^%^BLUE%^ forms constantly"
                           +" around it, and the %^RESET%^s%^BOLD%^"
                           +"%^BLACK%^la%^RESET%^te %^BOLD%^"
                           +"%^BLUE%^surfaces nearby are %^RESET%^slick"
                           +"%^BOLD%^%^BLUE%^ and treacherous.",

  ({ "stalagmite", "stalagmites"}):"These strange, irregular shaped"
                                  +" %^BOLD%^%^BLACK%^pillars of rock"
                                  +"%^RESET%^ have been formed over"
                                  +" centuries from mineral deposits of"
                                  +" the %^BLUE%^dripping water%^RESET%^."
                                  +" Many of the pillars here are several"
                                  +" feet high, quite broad and smooth to"
                                  +" the touch.",

  ({ "wall", "walls", "slate"}):"%^BOLD%^%^BLACK%^The walls are of"
                               +" black s%^RESET%^l%^BOLD%^%^BLACK%^ate."
                               +" They are smooth in places, but cracked"
                               +" and uneven in others. %^MAGENTA%^Rose"
                               +" coloured %^BOLD%^%^MAGENTA%^c%^RESET%^"
                               +"%^MAGENTA%^ry%^BOLD%^%^MAGENTA%^s"
                               +"%^RESET%^%^MAGENTA%^t%^RED%^al%^BOLD%^"
                               +"%^MAGENTA%^s %^BOLD%^%^BLACK%^gl"
                               +"%^RESET%^e%^BOLD%^%^BLACK%^am in the"
                               +" light",

  ({ "shadow", "shadows",}):"%^MAGENTA%^The%^BOLD%^%^BLACK%^ s%^RESET%^h"
                           +"%^BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^"
                           +"%^BLACK%^ws%^RESET%^%^MAGENTA%^ leap and "
                           +"d%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^nce"
                           +" against the walls",

({ "bottom", "stream bottom","bottom of stream",}):
                           "%^BOLD%^%^BLUE%^The water is quite"
                          +" %^CYAN%^clear%^BLUE%^ and you can see down"
                          +" to the %^BOLD%^%^BLACK%^d%^RESET%^ORANGE%^a"
                          +"%^BOLD%^%^BLACK%^rk silt %^BLUE%^at the"
                          +" bottom of the stream. You can see"
                          +" something %^RESET%^gl%^BOLD%^%^WHITE%^i"
                          +"%^RESET%^tt%^CYAN%^e%^RESET%^ry %^BOLD%^"
                          +"%^BLUE%^down there.",


  "crystals" : "%^MAGENTA%^The rose coloured %^BOLD%^%^MAGENTA%^c"
              +"%^RESET%^%^MAGENTA%^ry%^BOLD%^%^MAGENTA%^s%^RESET%^"
              +"%^MAGENTA%^t%^RED%^al%^BOLD%^%^MAGENTA%^s%^RESET%^"
              +"%^MAGENTA%^ gl%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^tt"
              +"%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^r from the walls"
              +" in every direction",

  ({"stalactites","stalactite"}):"Way up, almost out of sight on the"
                                +" %^BOLD%^%^BLACK%^shadowy ceiling"
                                +"%^RESET%^, you can make out the pointed"
                                +" shapes of the stalactites formed over"
                                +" centuries from the mineral deposits of"
                                +" the %^BLUE%^dripping water.%^RESET%^", 

"stream":"%^CYAN%^The %^BLUE%^stream%^CYAN%^ curves this way and that as"
        +" it wanders across the floor of the %^BOLD%^%^BLACK%^cavern"
        +"%^RESET%^%^CYAN%^. The path it follows has been cut deeply into"
        +" the rocks over time, and its banks are worn smooth.", 

({ "fire", "campfire"}): "Looking closely at the %^RED%^c%^BOLD%^%^RED%^a"
                        +"%^RESET%^%^RED%^mp%^BOLD%^%^RED%^f%^YELLOW%^i"
                        +"%^RESET%^%^RED%^re%^RESET%^, you notice that"
                        +" while the %^RED%^f%^YELLOW%^l%^RED%^a%^RESET%^"
                        +"%^RED%^mes%^RESET%^ %^YELLOW%^leap%^RESET%^ and"
                        +" %^BOLD%^%^RED%^dance%^RESET%^ around the"
                        +" neatly stacked sticks, the %^ORANGE%^sticks"
                        +"%^RESET%^ themselves are not being consumed. It"
                        +" looks like an %^CYAN%^i%^BOLD%^%^CYAN%^ll"
                        +"%^RESET%^%^CYAN%^us%^RESET%^i%^CYAN%^on"
                        +" %^RESET%^of %^RED%^f%^YELLOW%^i%^RED%^r"
                        +"%^RESET%^%^RED%^e%^RESET%^, but the comforting"
                        +" %^RED%^heat%^RESET%^ and %^YELLOW%^light"
                        +"%^RESET%^ given off are real enough. The"
                        +" %^BOLD%^%^BLACK%^stalagmites%^RESET%^ gathered"
                        +" around the fire look ideally placed to"
                        +" %^MAGENTA%^lean %^RESET%^against as you sit by"
                        +" the %^RED%^f%^YELLOW%^i%^RED%^r%^RESET%^"
                        +"%^RED%^e%^RESET%^.",

"hole" : "The %^CYAN%^stream disappears%^RESET%^ into a %^BOLD%^"
        +"%^BLACK%^hole%^RESET%^ in the far west wall of the cavern.",
  ]) );

  set_search("waterfall","A close examination reveals a %^BOLD%^"
            +"%^BLACK%^dark alcove%^RESET%^ hidden behind the %^BLUE%^c"
            +"%^CYAN%^a%^BLUE%^sc%^BOLD%^%^WHITE%^a%^BLUE%^d%^RESET%^"
            +"%^BLUE%^ing w%^CYAN%^a%^BLUE%^t%^RESET%^e%^BLUE%^r%^RESET%^"
            +". It looks big enough to enter." );

  set_search("stream", "%^BOLD%^%^BLUE%^The water looks %^CYAN%^f"
                      +"%^WHITE%^r%^CYAN%^esh %^BLUE%^and %^RESET%^"
                      +"%^CYAN%^clear%^BOLD%^%^BLUE%^ as it bubbles along"
                      +" away from the w%^WHITE%^a%^BLUE%^te%^BOLD%^"
                      +"%^CYAN%^r%^WHITE%^f%^RESET%^%^BLUE%^a%^BOLD%^"
                      +"%^BLUE%^ll%^. %^RESET%^%^BLUE%^You half glimpse"
                      +" something gl%^BOLD%^%^CYAN%^i%^RESET%^"
                      +"%^BLUE%^ttery at the bottom of the stream" );

  set_property("no teleport",1);
  set_post_exit_functions(({"northwest",}),({"GoThroughDoor",}));

}

int GoThroughDoor()
{
  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }
  find_object_or_load(TUNNELS + "tun16.c")->enter_room();
  return 1;
}

void init(){
  ::init();
  add_action("enter_waterfall","enter");
  add_action("lean_stalagmite","lean");
  add_action("hum_tune","hum");
  add_action("stream_search", "search");
  add_action("mine_crystals", "mine");
}

void reset(){
  ::reset();
  if (sizeof(all_living(TO))== 0)
  {
    stream_searched=random(1);
    numdevils = 0;
    if (random(5)<1)
    {
      //allow the devilkin to be summoned again
      maxdevils = 0;
    }
  }
}

string long_desc()
{
   return   "%^MAGENTA%^A %^BOLD%^%^BLUE%^high w%^WHITE%^a%^BLUE%^te"
           +"%^BOLD%^%^CYAN%^r%^WHITE%^f%^RESET%^%^BLUE%^a%^BOLD%^"
           +"%^BLUE%^ll%^RESET%^ %^MAGENTA%^tumbles down across craggy"
           +" rocks into an underground stream far below.  The stream"
           +" runs through a vast, high ceilinged cavern whose %^BOLD%^"
           +"%^BLACK%^black slate%^RESET%^%^MAGENTA%^ walls gl%^BOLD%^"
           +"%^MAGENTA%^i%^RESET%^%^MAGENTA%^tter with rose coloured"
           +" %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^ry%^BOLD%^"
           +"%^MAGENTA%^s%^RESET%^%^MAGENTA%^t%^RED%^al%^BOLD%^"
           +"%^MAGENTA%^s%^RESET%^%^MAGENTA%^ that reflect the light,"
           +" lending their colour to the room. The floor of the cavern"
           +" is flat, and the stream flows sedately on from the bottom"
           +" of the waterfall, meandering away into a small hole in the"
           +" far end of the cavern. A number of other breaks in the"
           +" walls show where tunnels lead further into the caverns."
           +" Some large stalagmites have grown from the floor, and way"
           +" up above them you can make out the pointed shapes of"
           +" stalactites hanging from the ceiling.\n"
           +"There is glowing %^BOLD%^%^RED%^c%^RESET%^%^RED%^ampf"
           +"%^YELLOW%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e %^RESET%^"
           +"%^MAGENTA%^near the stream, with a few stalagmites gathered"
           +" around it. The %^RED%^f%^YELLOW%^l%^RED%^a%^RESET%^"
           +"%^RED%^mes%^RESET%^%^MAGENTA%^ cast flickering %^BOLD%^"
           +"%^BLACK%^shadows%^RESET%^%^MAGENTA%^ through the room, but"
           +" their dancing lights sparkle where they touch the bright"
           +" crystals in the walls, lending a magical air to this"
           +" tranquil place.%^RESET%^";
}

int enter_waterfall(string str){
  if (str != "alcove" && str !="waterfall")
  {
    tell_object(TP, "Enter where?");
    return 1;
  }
  tell_object(TP, "Edging along a narrow ridge, you make your way behind"
                 +" the waterfall, getting thoroughly %^BOLD%^%^BLUE%^spl"
                 +"%^WHITE%^a%^RESET%^%^BLUE%^s%^BOLD%^%^BLUE%^hed"
                 +"%^RESET%^ in the process.");

  tell_room(TO, "Edging along a narrow ridge, " + TPQCN 
              + " manages to make " + TP->QP 
              + " way behind the %^BLUE%^waterfall%^RESET%^.",TP);

  TP->move_player(TUNNELS + "alcove.c");  
  return 1;
}

int lean_stalagmite(string str){
  if (str != "stalagmite" && str != "against stalagmite")
  {
    tell_object(TP, "Lean against what?");
    return 1;
  }
  tell_object(TP,"Lowering yourself down, you sigh as you sit by the"
                +" %^RED%^f%^YELLOW%^i%^RED%^r%^RESET%^%^RED%^e%^RESET%^,"
                +" staring into the %^BOLD%^%^RED%^d%^RESET%^%^RED%^a"
                +"%^BOLD%^%^RED%^nc%^YELLOW%^i%^RED%^ng f%^YELLOW%^l" 
                +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes%^RESET%^ and"
                +" leaning back against one of the broad based %^BOLD%^"
                +"%^BLACK%^stalagmites%^RESET%^, which proves to be"
                +" surprisingly comfortable. You can hear the"
                +" %^MAGENTA%^music%^RESET%^ louder than ever.");
  
  tell_room(TO,"Lowering " + TP->QO + "self down, " + TPQCN + " sighs"
              +" as " + TP->QS + " sits by the %^RED%^f%^YELLOW%^i"
              +"%^RED%^r%^RESET%^%^RED%^e%^RESET%^, staring into the"
              +" %^BOLD%^%^RED%^d%^RESET%^%^RED%^a%^BOLD%^%^RED%^nc"
              +"%^YELLOW%^i%^RED%^ng f%^YELLOW%^l%^RESET%^%^RED%^a"
              +"%^BOLD%^%^RED%^mes%^RESET%^ and leaning back against one"
              +" of the broad based %^BOLD%^%^BLACK%^stalagmites.",TP);
  if (random(5)<2)
  {
    call_out("hum_tune3", 2, 40, "%^GREEN%^scowling");
  }
  return 1;
}

int hum_tune(string str){

  if (str != "tune" && str != "along" && str != "along to tune")
  {
    tell_object(TP, "hum what?");
    return 1;
  }
  if (TP->query_class_level("bard")>0)
  {
    int strlen;
    string possessive;
    possessive = TP->QP;
    possessive[0]="H";
    TP->set_property("hummed",2);  
    tell_object(TP, "Recognising fragments of the %^MAGENTA%^tune"
                   +" %^RESET%^from songs you have heard elsewhere, you"
                   +" raise your voice in a%^CYAN%^ wordless counterpoint"
                   +" melody%^RESET%^ that blends and dances around in"
                   +" %^YELLOW%^harmony%^RESET%^ with the original"
                   +" %^MAGENTA%^tune%^RESET%^.");
    tell_room(TO,"Closing " + TPQP + " eyes slightly to concentrate, " 
                + TPQCN + " start to hum along to the %^MAGENTA%^eerie"
                +" tune%^RESET%^ you can hear off in the distance." 
                +" H" + possessive + "voice raises in a"
                +" wordless counterpoint melody that blends and dances"
                +" around in %^YELLOW%^harmony%^RESET%^ with the original"
                +" %^MAGENTA%^tune%^RESET%^.", TP);
    call_out("hum_tune2", 2);
    return 1;
  }
  if (TP->query_property("hummed")<1)
  { 
    if (TP->query_class_level("bard")>10)
    {
      TP->set_property("hummed",2); 
    }
    TP->set_property("hummed",1);  
  }
  switch (TP->query_property("hummed"))
  {
  case 1:
    tell_object(TP, "Closing your eyes slightly to concentrate, you start"
                     +" to hum along to the eerie tune you can hear off"
                     +" in the distance.\n");
    tell_room(TO,"Closing " + TPQP + " eyes slightly to concentrate, " 
                + TPQCN + " starts to hum along to the eerie tune you"
                +" can hear off in the distance.\n", TP);
    break;
  case 2:
    tell_object(TP, "Recognising fragments of the %^MAGENTA%^tune"
                   +"%^RESET%^ from %^CYAN%^songs%^RESET%^ you have heard"
                   +" elsewhere, you raise your voice in a wordless"
                   +" counterpoint %^MAGENTA%^m%^BOLD%^%^MAGENTA%^e"
                   +"%^RESET%^%^MAGENTA%^lo%^BOLD%^d%^RESET%^%^MAGENTA%^y"
                   +"%^RESET%^ that blends and dances around in"
                   +" %^ORANGE%^harmony%^RESET%^ with the original"
                   +" %^MAGENTA%^tune%^RESET%^.\n");
    tell_room(TO,"Closing " + TPQP + " eyes slightly to concentrate, " 
                + TPQCN + " raises " + TPQP + " voice in a wordless"
                +" counterpoint %^MAGENTA%^m%^BOLD%^%^MAGENTA%^e%^RESET%^"
                +"%^MAGENTA%^lo%^BOLD%^d%^RESET%^%^MAGENTA%^y%^RESET%^"
                +" that blends and dances around in %^ORANGE%^harmony"
                +" %^RESET%^with the original %^MAGENTA%^tune%^RESET%^.\n"
                , TP);
    break;
  }
  call_out("hum_tune2", 2);
  return 1;
}

void hum_tune2()
{
  tell_room(TO, "%^MAGENTA%^The %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^"
               +"%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^ws %^RESET%^"
               +"%^MAGENTA%^around the edges of the room seem to"
               +" %^CYAN%^shift%^MAGENTA%^, and you hear %^BOLD%^"
               +"%^BLACK%^scuffling noises%^RESET%^%^MAGENTA%^ off in the"
               +" tunnels.\n");
  
  call_out("hum_tune3",2, 100, "grinning");
}
 
void hum_tune3(int chance, string expression)
{
  tell_room(TO, "%^MAGENTA%^You hear sharp intakes of breath from the"
               +" %^BOLD%^%^BLACK%^shadows%^RESET%^%^MAGENTA%^ around the"
               +" edges of the room, and scuffling sounds as small"
               +" creatures shuffle around out of sight.\n");
//  check to see whether the devilkin have already been summoned
  if (maxdevils>0)
  {
    return;
  }
  maxdevils = 6 + random(8);
  call_out("enter_devilkin2",3, chance, expression);
}

void enter_devilkin(string expression)
{
//  check to see whether the devilkin have already been summoned
  if (maxdevils>0)
  {
    return;
  }
  tell_room(TO, "%^MAGENTA%^You hear scuffling sounds from the %^BOLD%^"
             +"%^BLACK%^shadows%^RESET%^%^MAGENTA%^ around the edges of"
             +" the room, as small creatures shuffle around out of"
             +" sight.\n");
  maxdevils = random(6)+6;
  call_out("enter_devilkin2", random(4), 100, expression);
}

void enter_devilkin2(int chance, string expression)
{
  tell_room(TO, "%^MAGENTA%^One by one, a dozen %^BOLD%^%^BLACK%^tiny"
               +" f%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^gures%^RESET%^"
               +" %^MAGENTA%^emerge from a variety of hiding places in"
               +" the room. and gather round the %^BOLD%^%^RED%^f"
               +"%^YELLOW%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^RESET%^,"
               +" %^CYAN%^hopping %^MAGENTA%^and %^RED%^dancing "
               +"%^MAGENTA%^to the %^BLUE%^tune%^MAGENTA%^, small%^BOLD%^"
               +" %^BLACK%^batlike wings%^RESET%^%^MAGENTA%^ flapping"
               +" sometimes to assist them with balance. When their faces"
               +" turn towards you, they seem to be %^BOLD%^"
               +"%^RED%^" + expression + "%^RESET%^%^MAGENTA%^.\n");
  if (random (100)<chance)
  {
    call_out("enter_devilkin3",random(3));
  }
}

void enter_devilkin3()
{
  string hiding_place;
  numdevils+=1;
  new(MOB+"devilkin.c")->move(TO);
  if (numdevils<maxdevils)
  {
    call_out("enter_devilkin3",random(4));
  }
  switch(random(10))
  {
  case 0:
    hiding_place = " scrambles out of a %^BOLD%^%^BLACK%^crevice%^RESET%^"
                  +" overhead";
    break;
  case 1:
    hiding_place = " emerges from behind the %^BOLD%^%^BLUE%^high"
                  +" w%^WHITE%^a%^BLUE%^te%^BOLD%^%^CYAN%^r%^WHITE%^f"
                  +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^ll%^RESET%^";
    break;
  case 2:
    hiding_place = " peels away from one of the"
                  +" %^BOLD%^%^BLACK%^stalactites%^RESET%^ high overhead"
                  +" and begins flapping its way down through the air.";
    break;
  case 3:
    hiding_place = " scrambles out of a %^BOLD%^%^BLACK%^crevice%^RESET%^"
                  +" overhead";
    break;
  case 4:
    hiding_place = " steps out from the %^BOLD%^%^BLACK%^shadow%^RESET%^"
                  +" of one of the stalagmites";
    break;
  case 5:
    hiding_place = " peels away from one of the"
                  +" %^BOLD%^%^BLACK%^stalactites%^RESET%^ high overhead"
                  +" and begins flapping its way down through the air.";
    break;
  case 6:
    hiding_place = " flies in from the northwest";
    break;
  case 7:
    hiding_place = " waddles in from the north";
    break;
  case 8:
    hiding_place = " walks in from the northwest";
    break;
  case 9:
    hiding_place = " flies in from the north";
    break;

   }
  tell_room(TO,"an %^BOLD%^%^RED%^i%^RESET%^%^RED%^mp%^BOLD%^i%^RESET%^"
              +"%^RED%^sh %^BOLD%^%^BLACK%^d%^RESET%^%^RED%^e%^BOLD%^"
              +"%^BLACK%^v%^RED%^i%^BOLD%^%^BLACK%^lk%^RESET%^%^RED%^i"
              +"%^BOLD%^%^BLACK%^n%^RESET%^" + hiding_place);

}

int stream_search(string str)
{
  if (str=="bottom"||str=="bottom of stream"||str=="stream bottom")
  {
    tell_object(TP,"You climb into the stream and conduct a thorough"
                  +" search of the bottom. ");

    if (stream_searched==0 && random (3)<2)
    {
      tell_object(TP,"You manage to find some items of value!");
      new(OBJ+"r_treasure.c")->move(TO);
      stream_searched = 1;
    }
    else
    {
      tell_object(TP,"After all that, there's nothing there but a few"
                    +" splinters of worthless %^BOLD%^%^WHITE%^q"
                    +"%^RESET%^u%^BOLD%^%^WHITE%^ar%^RESET%^t%^BOLD%^"
                    +"%^WHITE%^z");
    }
    tell_room(TO,TPQCN + " splashes into the water and ducks " + TP->QP 
               +" head beneath the surface to search the stream bed",TP);
    call_out("stream_search2",2, TP);
    return 1;
  }
  return 0;
}

void stream_search2(object ob)
{
  if (!objectp(ob)){return;}
  tell_object(ob,"You are absolutely %^BLUE%^d%^BOLD%^r%^CYAN%^e%^RESET%^"
                +"%^CYAN%^n%^BLUE%^ch%^BOLD%^e%^RESET%^%^BLUE%^d%^RESET%^"
                +".");
  tell_room(TO,ob->QCN + " is absolutely %^BLUE%^d%^BOLD%^r%^CYAN%^e"
                     + "%^RESET%^%^CYAN%^n%^BLUE%^ch%^BOLD%^e%^RESET%^"
                     + "%^BLUE%^d%^RESET%^.",ob);
if (random(9)<1)
  {
    call_out("stream_search3", 2, ob);
  }
if (random(5)<1)
  {
    call_out("stream_search4",2,ob);
  }
if(random(3)<1)
  {
    call_out("enter_devilkin", random(8), "%^CYAN%^scowling");
  }
}

void stream_search3(object ob)
{
  if (!objectp(ob)){return;}
  tell_room(TO, "It suddenly occurs to you that " + ob->QCN + " bears a"
               +" startling resemblance to a %^ORANGE%^drowned rat"
               +"%^RESET%^.",ob);
}

void stream_search4(object ob)
{
  if (!objectp(ob)){return;}
  tell_object (ob, "Better warm up by the %^RED%^f%^YELLOW%^i%^RESET%^"
                +"%^RED%^r%^BOLD%^%^RED%^e");
}