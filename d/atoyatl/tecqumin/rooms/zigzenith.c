#define DEST "/daemon/destinations_d.c"

#include <std.h>
#include <move.h>
#include "../tecqumin.h"
#include <daemons.h>

inherit VAULT;
object captive, * queue;
int sacrificing;

string long_desc();

void create() {
  object waystation;
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("The upper tier of a ziggurat");
  set_short("The upper tier of a ziggurat");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([ ({"roof", "pagoda"}): "The sloping pagoda style roof sits on"
                                    +" four round columns and serves to"
                                    +" give partial shade to the zenith of"
                                    +" the ziggurat",  
                "columns" : "The columns are made from the same stone as"
                           +" the rest of the ziggurat, but their round"
                           +" shape serves to distinguish them from the"
                           +" very square construction of the rest of the"
                           +" edifice",
                 "jungle" :  (:TO, "jungle_desc":),
  ({"bowl", "stone bowl", "plinth", "flame"})
                          : "The bowl is carved from simple grey"
                           +" stone, its style ancient and primitive. The"
                           +" %^ORANGE%^p%^RESET%^a%^ORANGE%^t%^RESET%^i"
                           +"%^ORANGE%^na%^RESET%^ of age colours it, and"
                           +" %^BOLD%^%^BLACK%^dark st%^RESET%^%^RED%^a"
                           +"%^MAGENTA%^i%^BOLD%^%^BLACK%^ns%^RESET%^ mat"
                           +" the inner surfaces and form %^RED%^rivulet"
                           +"%^RESET%^ patterns down the edges. The"
                           +" %^RED%^f%^BOLD%^%^RED%^l%^RESET%^%^RED%^ame"
                           +" %^RESET%^that rises from the centre of the"
                           +" bowl is red as blood. It gives off no heat,"
                           +" and burns without fuel.",
  ({"staircase", "staircases"}) : "The two broad staircases lead down"
                           +" opposite faces of the ziggurat, one to the"
                           +" north and one to the south. At the top of"
                           +" each is an %^BOLD%^%^BLACK%^ugly slab"
                           +" %^RESET%^of %^BOLD%^%^BLACK%^dark"
                           +" st%^RESET%^a%^BOLD%^%^BLACK%^in%^RESET%^"
                           +"%^RED%^e%^BOLD%^%^BLACK%^d %^RESET%^"
                           +"%^ORANGE%^stone%^RESET%^. A further"
                           +" staircase, hidden from view from the lower"
                           +" slopes of the pyramid, leads down into the"
                           +" dark interior. ",
  ({"slab", "slabs","stone", "stones", "ugly slab", "slab of stone", 
                                                  "dark stained stone"}):
                     "At the top of each of the external staircases is a"
                           +" large, ugly slab of stone. Approximately"
                           +" rectangular, they have a saddle shaped hump"
                           +" in the centre. All around the hump, and"
                           +" dribbling down the sides, are unpleasant"
                           +" looking %^BOLD%^%^BLACK%^dark st%^RESET%^"
                           +"%^RED%^a%^MAGENTA%^i%^BOLD%^%^BLACK%^ns",
  ({"statue", "statues"}) : "A stone %^BOLD%^%^BLACK%^jaguar%^RESET%^"
                           +" lounges at the edge of the platform, one leg"
                           +" dangling loose over the side. Facing it, a"
                           +" %^BOLD%^%^RED%^pl%^CYAN%^u%^GREEN%^m%^RED%^ed"
                           +" s%^BLUE%^e%^RED%^rp%^CYAN%^e%^RED%^nt"
                           +"%^RESET%^ rises in a cobralike pose, its"
                           +" %^BOLD%^%^RED%^w%^MAGENTA%^i%^RED%^ngs"
                           +" %^RESET%^flared in a broad spread behind it"
  ]));
  set_smell("default","The scent of the jungle reaches you");
  set_listen("default","The souds of the jungle are all there is to be"
             +" heard.");
   set_exits( ([ "north" : ROOMS + "step12" ,
	          "south" : ROOMS + "step6",
                 "down" : ROOMS + "guardcham"]) );

  set_climb_exits(([
       "descend":({ROOMS + "zighigh202",5,6,20})
  ]));
  captive = 0;
  queue = ({});
  sacrificing = 0;
}
void init() {
   ::init();
   add_action("do_drag", "drag");
   add_action("release", "release");
}
/*
string query_weather(){
 return (string)WEATHER_D->Check_Weather(all_living(TO)[0]);
}
*/


string jungle_desc(){

  if (query_night()){
    return "%^BOLD%^%^BLACK%^The shapes of the %^RESET%^%^GREEN%^jungle"
          +" %^BOLD%^%^BLACK%^seem a long way below you, the upper canopy"
          +" marked only as a wavy line of darkness blotting out the"
          +" tw%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^nkl%^RESET%^%^WHITE%^i"
          +"%^BOLD%^%^BLACK%^ng l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ght of"
          +" t%^BOLD%^%^WHITE%^h%^BOLD%^%^BLACK%^e st%^BOLD%^%^WHITE%^a"
          +"%^BOLD%^%^BLACK%^rs%^RESET%^";
  } else {
    return "%^GREEN%^The very top of the %^BOLD%^%^GREEN%^j%^RESET%^"
           +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
           +"%^GREEN%^e's %^RESET%^%^GREEN%^upper canopy is beneath you"
           +" here, as the ziggurat's peak breaks through into the open"
           +" %^BOLD%^%^BLUE%^s%^CYAN%^k%^BLUE%^y%^RESET%^%^GREEN%^"
           +" above%^RESET%^";
  }
}



string long_desc(){

  return "\nYou stand at the very peak of the ziggurat, where the tiered"
      +" steps level out to a broad stone platform, some 40 feet across."
      +" There is a cooling %^BOLD%^%^CYAN%^br%^RESET%^ee%^BOLD%^"
      +"%^CYAN%^ze%^RESET%^ up where, in contrast to the stifling"
      +" %^ORANGE%^humidity%^RESET%^ of the %^BOLD%^%^GREEN%^j%^RESET%^"
      +"%^GREEN%^u%^BOLD%^%^GREEN%^ngl%^RESET%^%^GREEN%^e%^RESET%^ below."
      +" A pagoda style roof, seated on four round columns, shields the"
      +" platform from the sun's rays. In the centre of this platform, a"
      +" stone bowl sits on top of a low plinth. A steady flame rises"
      +" from the centre of the bowl. To one side of the bowl, an internal"
      +" staircase, invisible from the lower levels, leads down into the"
      +" bowels of the ziggurat. To the north and south, a pair of broad"
      +" staircases lead down the opposite faces of the ziggurat."
      +" At the top of each of these staircases is a low, humped slab of"
      +" stone, covered with a great many dark stains. At the eastern"
      +" edge of the platform, a pair of unusual statues stand guard over"
      +" this forbidding place.\n\nTo the east, beyond the"
      +" dark green spread of the %^GREEN%^jungle%^RESET%^, you can make"
      +" out the %^CYAN%^sh%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^mm%^BOLD%^"
      +"%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng"
      +" %^BOLD%^%^BLUE%^bl%^CYAN%^u%^BLUE%^e%^RESET%^ of a %^BOLD%^"
      +"%^BLUE%^river%^RESET%^, and yet more %^GREEN%^jungle%^RESET%^ beyond"
      +" that.\n";
}

string night_desc(){

return "\n%^BLUE%^You stand at the very peak of the %^RESET%^ziggurat"
      +"%^BLUE%^, where the tiered steps level out to a broad stone"
      +" platform, some 40 feet across. There is a cooling %^BOLD%^"
      +"%^CYAN%^br%^RESET%^ee%^BOLD%^%^CYAN%^ze%^RESET%^%^BLUE%^ up here,"
      +" in contrast to the stifling %^ORANGE%^humidity%^RESET%^%^BLUE%^"
      +" of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngl"
      +"%^RESET%^%^GREEN%^e%^BLUE%^ down below. A pagoda style roof,"
      +" seated on four round columns, can be seen in %^BOLD%^"
      +"%^BLACK%^silhouette%^RESET%^%^BLUE%^ above you. In the centre of"
      +" the platform, a stone bowl sits on top of a low plinth. A steady"
      +" %^RED%^f%^ORANGE%^l%^RED%^ame%^BLUE%^ rises from the centre of"
      +" the bowl, giving a little light to the darkness. To one side of"
      +" the bowl, an internal staircase, invisible from the lower levels,"
      +" leads down into the %^BOLD%^%^BLACK%^bowels%^RESET%^%^BLUE%^ of"
      +" the %^RESET%^ziggurat%^BLUE%^. To the north and south, a pair of"
      +" broad staircases lead down the opposite faces of the ziggurat."
      +" At the top of each of these staircases is a low, humped slab of"
      +" stone, covered with a great many dark stains. At the eastern edge"
      +" of the platform, a pair of unusual statues stand guard over this"
      +" forbidding place.\n";
}

int do_drag(string str){
  if (!objectp(captive)){
    return 0;
  }
  if (captive->id(str)){
    tell_object(TP, captive->QCN + " is being held down over the stone"
                  +" altar by a ghostly figure. You cannot drag " 
                  + captive->QO + " unless you can first"
                  +" %^BOLD%^%^YELLOW%^release%^RESET%^ " + captive->QO);
    return 1;
  }
  return 0;
}

void begin_sacrifice(object victim){
  object priest1, priest2, highpriest;
  if (!objectp(victim)||!present(victim, TO)){
    return;
  }
  sacrificing = 1;
  if (captive !=0){
    queue += ({victim});
    return;
  }
  priest1 = present("ghost priest", TO);
  priest2 = present("ghost priest 2", TO);
  highpriest = present("highpriest", TO);
  if (!objectp(priest1)){
    tell_room(TO, "A %^CYAN%^blue light%^RESET%^ fl%^CYAN%^i%^RESET%^ck"
                 +"%^BOLD%^%^WHITE%^e%^RESET%^rs in the air and the"
                 +" %^CYAN%^translucent%^RESET%^ form of a %^BOLD%^"
                 +"%^WHITE%^g%^RESET%^%^ORANGE%^h%^BOLD%^%^WHITE%^ost"
                 +"%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^y %^RESET%^"
                 +"%^ORANGE%^pr%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^e"
                 +"%^CYAN%^s%^ORANGE%^t%^RESET%^ appears before you.");
    priest1=new(GHOST_PRIEST);
    priest1->set("aggressive", 0);
    priest1->move(TO);
  }
  if (!objectp(priest2)){
    tell_room(TO, "A %^CYAN%^blue light%^RESET%^ fl%^CYAN%^i%^RESET%^ck"
                 +"%^BOLD%^%^WHITE%^e%^RESET%^rs in the air and the"
                 +" %^CYAN%^translucent%^RESET%^ form of a %^BOLD%^"
                 +"%^WHITE%^g%^RESET%^%^ORANGE%^h%^BOLD%^%^WHITE%^ost"
                 +"%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^y %^RESET%^"
                 +"%^ORANGE%^pr%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^e"
                 +"%^CYAN%^s%^ORANGE%^t%^RESET%^ appears before you.");
    priest2=new(GHOST_PRIEST);
    priest2->set("aggressive", 0);
    priest2->move(TO);
  }
  if (!objectp(highpriest)){
    tell_room(TO, "With a high pitched %^BOLD%^%^CYAN%^screech%^RESET%^,"
                 +" the air is wrenched apart and the %^MAGENTA%^fearsome"
                 +"%^RESET%^ form of a %^BOLD%^%^WHITE%^g%^RESET%^"
                 +"%^ORANGE%^h%^BOLD%^%^WHITE%^ost%^RESET%^%^ORANGE%^l"
                 +"%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^Tecumin"
                 +" %^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^i%^RESET%^"
                 +"%^CYAN%^gh pr%^BOLD%^%^WHITE%^");
    highpriest=new(GHOST_PRIEST);
    highpriest->set("aggressive", 0);
    highpriest->move(TO);
  }
  if (victim->query_hp()<1){
    tell_object(victim, "A sudden flurry of activity brings you round");
    tell_room(TO, victim->QCN + " seems to be roused by the sudden flurry of activity", victim);
    victim->set_hp(10);
  }
  call_out("sacrifice2", 2, victim, priest1, priest2, highpriest);

}

void sacrifice2(object victim, object priest1, object priest2, object highpriest){
  object rope;
  if (!objectp(victim)||!objectp(highpriest)){
    return;
  }
  tell_room(TO, "%^ORANGE%^"+ highpriest->QCN +" %^CYAN%^grabs%^ORANGE%^ "
              + victim->QCN + "%^RESET%^%^ORANGE%^ and pushes " 
              + victim->QO +" backwards over the strangely arched"
              +" %^BOLD%^%^BLACK%^h%^RESET%^u%^BOLD%^%^BLACK%^mp"
              +" %^RESET%^%^ORANGE%^of stone.", victim);
  tell_object(victim, "%^ORANGE%^" + highpriest->QCN +  " %^CYAN%^grabs"
             +" %^ORANGE%^you and pushes you backwards over the strangely"
             +" arched %^BOLD%^%^BLACK%^h%^RESET%^u%^BOLD%^%^BLACK%^mp"
            +" %^RESET%^%^ORANGE%^of stone.");
  if (objectp(priest1) && objectp(priest2)){
    tell_room(TO, priest1->QCN + " holds firmly onto " + victim->QCN 
                 +"'s feet while the other one holds onto " + victim->QP
                 +" wrists, securing " + victim->QO + " in place."
                 , victim); 
    tell_object(victim,  priest1->QCN + " holds firmly onto your feet,"
                 +" while the other one holds onto your wrists, securing"
                + " you in place.");
    captive = victim;
    rope = new("/d/common/obj/misc/rope");
    rope->move(priest1);
    priest1->force_me("bind "+victim->QCN);
  }
  call_out("sacrifice3",3, victim, priest1, priest2, highpriest);
}

void sacrifice3(object victim, object priest1, object priest2, object highpriest){

  if (!objectp(victim)||!objectp(highpriest)){
    return;
  }
  highpriest->force_me("emote lifts " + highpriest->QP 
                     + " arms to the sky and arches " + highpriest->QP 
                     + " head back as " + highpriest->QS + " raises " 
                     + highpriest->QP + " voice in a heady chant.");
  highpriest->force_me("speech %^MAGENTA%^chants in a querulous, excited"
                      +" voice");
  call_out("sacrifice4",2, victim, priest1, priest2, highpriest);
}

void sacrifice4(object victim, object priest1, object priest2, object highpriest){

  if (!objectp(victim)||!objectp(highpriest)){
    return;
  }
  highpriest->force_me("say %^BOLD%^%^YELLOW%^S%^RESET%^%^RED%^u%^BOLD%^"
                      +"%^YELLOW%^n L%^RESET%^%^RED%^o%^BOLD%^%^YELLOW%^"
                      +"rd %^RESET%^%^CYAN%^offer thy Gaze upon thy"
                      +" sacrifice and witness the %^BOLD%^%^BLUE%^fl"
                      +"%^CYAN%^o%^BLUE%^w%^CYAN%^e%^BLUE%^ry"
                      +" d%^GREEN%^ea%^BLUE%^th %^RESET%^%^CYAN%^of the"
                      +" fortunate %^ORANGE%^slave %^CYAN%^before thee!");
  call_out("sacrifice5",3, victim, priest1, priest2, highpriest);
}

void sacrifice5(object victim, object priest1, object priest2, object highpriest){

  if (!objectp(victim)||!objectp(highpriest)){
    return;
  }
  highpriest->force_me("emote %^RED%^grips " + highpriest->QP 
                     + " %^ORANGE%^amb%^BOLD%^%^YELLOW%^e%^RESET%^"
                     + "%^ORANGE%^r bl%^BOLD%^%^YELLOW%^a%^RESET%^"
                     + "%^ORANGE%^de %^RED%^in both hands, raised high"
                     + " above " + highpriest->QP + " head.");
  call_out("sacrifice6",2, victim, priest1, priest2, highpriest);
}

void sacrifice6(object victim, object priest1, object priest2, object highpriest){
  object * players, location, player;
  string location_name;
  int i;
  if (!objectp(victim)||!objectp(highpriest)){
    return;
  }
  highpriest->force_me("emotat " + victim->QCN + " %^RED%^plunges the"
                     +" %^ORANGE%^amb%^BOLD%^%^YELLOW%^e%^RESET%^"
                     +"%^ORANGE%^r bl%^BOLD%^%^YELLOW%^a%^RESET%^"
                     +"%^ORANGE%^de %^RED%^into $P chest and removes $P"
                     +" heart in an act of shockingly savage butchery!");
  tell_room(TO, "%^RED%^A fountain of %^BOLD%^%^RED%^blood" 
               +" %^RESET%^%^RED%^erupts from " + victim->QCN 
              + "'s %^RESET%^%^RED%^chest and %^BOLD%^%^RED%^showers"
              +" %^RESET%^%^RED%^everyone present.", victim);
  tell_object(victim, "%^RED%^A fountain of %^BOLD%^%^RED%^blood" 
               +" %^RESET%^%^RED%^erupts from your chest and %^BOLD%^"
              +"%^RED%^showers %^RESET%^%^RED%^everyone present.");
// Send a message about the sacrifice to all players standing on the
// ziggurat
  players = users();
  if (sizeof(players)>0){
    for (i=0;i<sizeof(players);i++){
      location_name = "";
      player = players[i];
      if (!objectp(player)){continue;}
      location = environment(player);
      if (!objectp(location)||location == TO){continue;}
      location_name = file_name(location);
      if (location_name[0..(strlen( ROOMS + "zig")-1)]==(ROOMS + "zig")[0..(strlen( ROOMS + "zig")-1)]||location_name[0..(strlen( ROOMS + "step")-1)]==(ROOMS + "step")[0..(strlen( ROOMS + "step")-1)]){
        tell_object(player, "%^RED%^A fine %^BOLD%^%^RED%^mist"
                   +" %^RESET%^%^RED%^of red descends on you from the top"
                   +" of the %^RESET%^ziggurat%^RED%^ as %^RESET%^" 
                   + victim->QCN +"%^RED%^ is slain in sacrifice to the"
                   +" Gods of the %^ORANGE%^Tecqumin%^RESET%^");
      }
    }
  }
  call_out("sacrifice7",2, victim, priest1, priest2, highpriest);
}

void sacrifice7(object victim, object priest1, object priest2, object highpriest){
  if (!objectp(victim)||!objectp(highpriest)){
    return;
  }
  tell_object(victim, "As your vision %^BOLD%^%^BLACK%^dims%^RESET%^,"
                     +" you can barely make out the form of the%^ORANGE%^"
                     +" Tecumin%^RESET%^ high priest as it holds up your"
                     +" still beating %^BOLD%^%^RED%^h%^RESET%^ea%^BOLD%^"
                     +"%^RED%^rt%^RESET%^ in front of your face.");
  tell_room(TO, "The %^ORANGE%^Tecqumin%^RESET%^ high priest holds "
                + victim->QCN + "'s still-beating %^BOLD%^%^RED%^h"
                +"%^RESET%^%^RED%^ea%^BOLD%^%^RED%^rt%^RESET%^ up in"
                +" front of " + victim->QP + " face, the"
                +" %^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^RESET%^"
                +" dripping down " + highpriest->QCN + " arm", victim);
  if (present("unfettered", TO)){
    call_out("unfettered_feast", 1, priest1, priest2, highpriest);
  } else {
    call_out("sacrifice8",1, victim, priest1, priest2, highpriest);
  }
}

void unfettered_feast(object victim, object priest1, object priest2, object highpriest){
  object unf;
  unf =present("unfettered", TO); 
  if (!objectp(unf)){
    sacrifice8( victim, priest1, priest2, highpriest);
    return;
  }
  tell_object(victim, "%^CYAN%^A terrible, wrenching %^BOLD%^%^RED%^pain%^RESET%^%^CYAN%^tears at your %^BOLD%^soul%^RESET%^%^CYAN%^ as your life fades, and you realise that your %^BOLD%^%^CYAN%^spirit%^RESET%^%^CYAN%^ is being consumed by the %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d");
  tell_room(victim->QCN + "%^RESET%^%^CYAN%^lets out a gurgling %^BOLD%^shriek%^RESET%^%^CYAN%^ as " + victim->QS + " dies and " + victim->QP + "%^BOLD%^sp%^WHITE%^i%^CYAN%^r%^WHITE%^i%^CYAN%^t%^RESET%^%^CYAN%^ is sucked into the %^MAGENTA%^maelstrom of fury %^CYAN%^of the %^BLUE%^Un%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d%^RESET%^%^CYAN%^ and is %^BOLD%^%^BLACK%^devoured%^RESET%^%^CYAN%^.", victim);
  victim->die(highpriest);
  unf->absorb_power(5);
  unf->force_me("emote %^BOLD%^%^BLUE%^Shudders with %^RESET%^%^MAGENTA%^hideous %^BOLD%^%^BLUE%^pleasure at the %^RED%^power%^BLUE%^ that it absorbs");
  captive = 0;
  if (sizeof(queue)>0){
    begin_sacrifice(queue[0]);
    queue -= ({queue[0]});
  } else {
    sacrificing = 0;
  }
}


void sacrifice8(object victim, object priest1, object priest2, object highpriest){
  tell_object(victim, "%^BLUE%^The %^RED%^bloody%^BLUE%^ vision fades as"
                     +" the veil of death falls before your eyes.");
  victim->die(highpriest);
  captive = 0;
  if (sizeof(queue)>0){
    begin_sacrifice(queue[0]);
    queue -= ({queue[0]});
  } else {
    sacrificing = 0;
  }
}

int query_sacrificing(){
  return sacrificing;
}

void set_sacrificing(int s){
  sacrificing = s;
}
