#include <std.h>
#include "../defs.h" 
inherit ROOM;

#define BASE "/d/deku/mausoleum/rooms/"
//d/deku/dark directory is going away - I HATE that area :P - Saide, December 2016
#define NOTROOMS ({"hidden28", "hidden5"}) // add any rooms here from the /d/deku/dark directory that shouldn't be ok for players to randomly drop into!

void create() 
{
    ::create();
    set_property("indoors",1);  
    set_property("light",0); 
    set_terrain(NAT_CAVE);
    set_travel(PAVED_ROAD);
    set_name("A short hallway");    
    set_short("%^BOLD%^%^WHITE%^A short hallway%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A short hallway%^RESET%^\n"
"%^BOLD%^%^BLACK%^This short hallway seems to have once been part of a bigger "
"underground complex of some sort, but the shifting of the %^RESET%^%^ORANGE%^mountains "
"%^BOLD%^%^BLACK%^has long since destroyed the remains of that ancient city.  What is "
"left is this narrow hall that ends in a towering %^RESET%^%^CYAN%^archway "
"%^BOLD%^%^BLACK%^complete with %^YELLOW%^ancient runes%^BLACK%^ that seem strangely out "
"of place.  Looking around, you see no other sign of such careful artistry, for while the "
"hall itself is neatly carved from the granite stone, there are no other symbols to be "
"seen, and no clue as to the identity of the people that once lived here.  A small crack "
"in the wall provides the only means of leaving this chamber.%^RESET%^\n");
        set_smell("default","A deep earthy smell fills the air.");
        set_listen("default","The hallway is silent except for your footfalls.");

        set_items(([
           ({"granite","walls"}) : "%^BOLD%^%^BLACK%^The walls of this hallway are "
"carved from the granite stone of the mountain.  Plain and unadorned, there is "
"little of interest to see on them except for the small crack that provides access "
"in an out of this closed area.%^RESET%^",
           ({"city","passage"}) : "%^RESET%^%^ORANGE%^A very old landslide appears "
"to have blocked all access to wherever this hallway once left.  Judging by the cut "
"stone of the walls and the neat order of the hall itself, you imagine there was "
"once an underground city here, but it has long been sealed off.",
           ({"archway","arch","runes"}) : (:TO,"arch_desc":),
           ({"crack","wall"}) : "%^BOLD%^%^BLACK%^Damage caused by the shifting of "
"an earthquake, the crack provides the only access to or from this hallway.%^RESET%^",
        ]));

        set_exits(([
	"out":UPPER"chasm19",
        ]));
}

string arch_desc() {
   if((int)TP->query_skill("academics") > 15) {
     return("%^RESET%^%^CYAN%^A large stone archway, carved from the same "
"granite that the rest of the room is made from, stands prominently at the "
"end of the hall, almost as if there were plans to continue the hallway "
"through the rune covered arch. Perhaps if you studied them closer you might "
"learn their purpose.%^RESET%^");
   }
   return("%^RESET%^%^CYAN%^A large stone archway, carved from the same "
"granite that the rest of the room is made from, stands prominently at the "
"end of the hall, almost as if there were plans to continue the hallway "
"through the rune covered arch.%^RESET%^");
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
      TP->move_player("/d/deku/mausoleum/rooms/enter.c");
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
    if(str != "arch" && str != "archway" && str != "runes"){
      notify_fail("Study what?\n");
      return 0;
    }
    if((int)TP->query_skill("academics") > 15) {
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
      if((int)TP->query_skill("academics") > 20)
        tell_object(TP,"%^CYAN%^Given the location of this way-gate, from your studies you suspect this "
"particular gate would lead to the caverns beneath the isle of Deku. The notes you've read suggest also that "
"there was, at least at one point, a matching gate that would allow a traveller to return the same way.%^RESET%^");
      if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);
      return 1;
    }
    if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);
    tell_object(TP,"%^CYAN%^Well. It's an archway. And it's made of stone. You're not sure there's much more to "
"it than that, really.%^RESET%^");
    return 1;
}