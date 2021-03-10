#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

#define BASE "/d/laerad/cavern1/"
#define NOTROOMS ({\
   "/d/laerad/cavern1/cave.c",\
   "/d/laerad/cavern1/cav001.c",\
   "/d/laerad/cavern1/cav002.c",\
   "/d/laerad/cavern1/cav003.c",\
   "/d/laerad/cavern1/cav004.c",\
   "/d/laerad/cavern1/cav005.c",\
})

void create(){ 
   ::create();
   set_name("A small side-cavern");
   set_short("%^BLUE%^A small side-cavern%^RESET%^");
   set_long("%^BLUE%^A small side-cavern%^RESET%^\n"
"%^CYAN%^You have found your way into a small side-alcove from the greater %^RESET%^limestone cavern %^CYAN%^"
"beyond, which stretches away northwest to be lost in the %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.  The air "
"is filled with %^BLUE%^moisture %^CYAN%^and what at first appear to be motes of dust, floating all around.  "
"Only a moment's observation, however, reveals them to be %^ORANGE%^tiny spores %^CYAN%^from the myriad of "
"mushrooms and fungi that fill the cavern, coating the floor and climbing any available stone surface.  Taking "
"even a few steps in any direction is difficult, as much for the numerous mushrooms as for the stalagmites "
"that dot the floor in all directions.  Above you hang the tapered points of countless stalactites, reaching "
"down from the %^BOLD%^%^BLACK%^shadow-swept %^RESET%^%^CYAN%^ceiling toward their counterparts on the floor "
"below. However, most prominent in this small side-cavern, is a stone ramp that spirals up around itself once "
"to reach a strange-looking %^BLUE%^archway %^CYAN%^at its pinnacle.%^RESET%^\n");
   add_item(({"archway","arch","ramp","spiral"}),(:TO,"arch_desc":));
   set_exits(([
     "northwest":MID"cavernr1",
   ]));
}

string arch_desc() {
   if((int)TP->query_skill("academics") > 20) {
     return("%^CYAN%^Most prominent here, and taking up the centre of the room, is a large stone ramp.  It "
"spirals around itself, traveling upwards to its peak at which rests an archway covered in strange %^MAGENTA%^"
"r%^CYAN%^u%^GREEN%^n%^CYAN%^e%^MAGENTA%^s%^CYAN%^.  Perhaps if you %^BOLD%^%^WHITE%^study %^RESET%^%^CYAN%^"
"it closely, you could discern its purpose?%^RESET%^");
   }
   return("%^CYAN%^Most prominent here, and taking up the centre of the room, is a large stone ramp.  It "
"spirals around itself, traveling upwards to its peak at which rests an archway covered in strange %^MAGENTA%^"
"r%^CYAN%^u%^GREEN%^n%^CYAN%^e%^MAGENTA%^s%^CYAN%^.%^RESET%^");
}

void init(){
   ::init();
   add_action("portal_fun","enter");
   add_action("study_fun","study");
}

string *get_rooms() {
    string *rooms, *rooms2;
    int i;

    rooms = get_dir(BASE);
    rooms2 = ({});
    for (i=0;i<sizeof(rooms);i++) { rooms2 += ({BASE + rooms[i]}); }
    rooms2 -= NOTROOMS;
    return rooms2;
}

int portal_fun(string str){
    string place, *rooms;
    int j;

    if(!str){
      notify_fail("Enter what?\n");
      return 0;
    }
    if(str != "arch" && str != "archway"){
      notify_fail("Enter what?\n");
      return 0;
    }
    tell_object(TP,"%^BLUE%^You stride forward towards the stone archway.%^RESET%^\n");
    tell_room(ETP,"%^BLUE%^"+TP->QCN+" walks into the stone archway, and in a sudden flash of %^BOLD%^%^CYAN%^"
"light%^RESET%^%^BLUE%^, "+TP->QS+" is gone!%^RESET%^",TP);
    if(!random(10)){
      tell_object(TP,"%^BLUE%^A low hum builds in your ears as you pass under its %^MAGENTA%^r%^CYAN%^u"
"%^GREEN%^n%^CYAN%^e%^MAGENTA%^d %^BLUE%^arch, and a sudden %^ORANGE%^un%^RED%^ea%^ORANGE%^sy %^BLUE%^feeling "
"grows in your stomach as a %^WHITE%^sickly-hued light %^BLUE%^bursts into being around you...%^RESET%^\n");
      tell_object(TP,"%^BLUE%^...and you find yourself elsewhere!%^RESET%^");
      rooms = get_rooms();
      place = rooms[random(sizeof(rooms))];
      TP->move_player(place);
    }
    else {
      tell_object(TP,"%^BLUE%^A low hum builds in your ears as you pass under its %^MAGENTA%^r%^CYAN%^u"
"%^GREEN%^n%^CYAN%^e%^MAGENTA%^d %^BLUE%^arch, and with a sudden burst of %^BOLD%^%^WHITE%^bri%^YELLOW%^l"
"%^WHITE%^liant lig%^YELLOW%^h%^WHITE%^t%^RESET%^%^BLUE%^...%^RESET%^\n");
      tell_object(TP,"%^BLUE%^...and you find yourself elsewhere!%^RESET%^");
      TP->move_player("/d/laerad/cavern1/cav021.c");
    }
    return 1;
}

int study_fun(string str){
    string place, *rooms;
    int j;

    if(!str){
      notify_fail("Study what?\n");
      return 0;
    }
    if(str != "arch" && str != "archway"){
      notify_fail("Study what?\n");
      return 0;
    }
    if((int)TP->query_skill("academics") > 20) {
      tell_object(TP,"%^CYAN%^This is probably one of the magical creations known as way-gates. There are said "
"to be many such gates throughout underdark, which are often made use of by drowkind in traveling across vast "
"distances underground.  However, it seems they are only making use of items that were already there, as the "
"origins of these gates are unknown.  It is said that they existed even before the elven crown wars, leaving "
"scholars only to wonder at what magical creatures may have created them.\n\n"
"You do think that you could probably %^YELLOW%^<enter archway>%^RESET%^%^CYAN%^ and be taken to a whole new "
"place, though there is no telling where you might end up.  It is best done with caution, though, as it is "
"known that such gates grow fickle with age.  While documents suggest they originally worked with flawless "
"precision, many more recent studies have recorded inaccuracies within their magic, sometimes leaving a "
"traveler close to where they should be, but not exactly there.%^RESET%^");
      if((int)TP->query_skill("academics") > 25)
        tell_object(TP,"%^CYAN%^Given the location of this way-gate, from your studies you suspect this "
"particular gate would once have led to the cavern systems beneath the eastern peninsula of Shadow, a "
"region that was long ago sundered from the mainland to form the isle of Laerad.%^RESET%^");
      if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);
      return 1;
    }
    if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);
    tell_object(TP,"%^CYAN%^Well. It's an archway. And it's made of stone. You're not sure there's much more to "
"it than that, really.%^RESET%^");
    return 1;
}