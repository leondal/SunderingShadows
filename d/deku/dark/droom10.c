#include <std.h>
#include <objects.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Passageway to the Abyss");
    set_long("%^YELLOW%^Passageway to the Abyss%^RESET%^\n"
"This passageway provides access to a network of caverns that connects the Underdark to the surface world. "
"The tunnel comes to an abrupt dead end here, with the only item of note being a stone archway at the very "
"end of the hallway. It is worn with age and marked with several runes.\n");
    set_exits(([
       "south" : "/d/deku/dark/droom9"
    ] ));
    set_items(([
       ({"archway","arch","runes"}) : (:TO,"arch_desc":),
    ] ));
}

string arch_desc() {
   if((int)TP->query_skill("academics") > 15) {
     return("The archway is worn with age, cut from the same dull stone that "
"forms the walls and roof above. It stands alone at the end of the corridor, "
"looking particularly out of place. A series of runes mark its length, still "
"easily discerned despite the age of the archway itself. Perhaps if you "
"studied them closer you might learn their purpose.");
   }
   return("The archway is worn with age, cut from the same dull stone that "
"forms the walls and roof above. It stands alone at the end of the corridor, "
"looking particularly out of place. A series of runes mark its length, still "
"easily discerned despite the age of the archway itself.");
}

void init(){
   ::init();
   add_action("portal_fun","enter");
   add_action("study_fun","study");
}

int portal_fun(string str){
    if(!str){
      notify_fail("Enter what?\n");
      return 0;
    }
    if(str != "arch" && str != "archway"){
      notify_fail("Enter what?\n");
      return 0;
    }
// this one has no failure, unlike several in the underdark proper. I guess it was maintained!
    tell_object(TP,"%^BLUE%^You stride forward towards the stone archway.%^RESET%^\n");
    tell_room(ETP,"%^BLUE%^"+TP->QCN+" walks into the stone archway, and in a sudden flash of %^BOLD%^%^CYAN%^"
"light%^RESET%^%^BLUE%^, "+TP->QS+" is gone!%^RESET%^",TP);

    tell_object(TP,"%^BLUE%^A low hum builds in your ears as you pass under its %^MAGENTA%^r%^CYAN%^u"
"%^GREEN%^n%^CYAN%^e%^MAGENTA%^d %^BLUE%^arch, and with a sudden burst of %^BOLD%^%^WHITE%^bri%^YELLOW%^l"
"%^WHITE%^liant lig%^YELLOW%^h%^WHITE%^t%^RESET%^%^BLUE%^...%^RESET%^\n");
    tell_object(TP,"%^BLUE%^...and you find yourself elsewhere!%^RESET%^");
    TP->move_player("/d/underdark/upper/portal.c");
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
"particular gate would lead to the chasm beneath the Charu Mountains. The notes you've read suggest also that "
"there was, at least at one point, a matching gate that would allow a traveller to return the same way.%^RESET%^");
      if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);
      return 1;
    }
    if(!TP->query_invis()) tell_room(TO,"%^CYAN%^"+TP->QCN+" observes the archway closely.%^RESET%^",TP);
    tell_object(TP,"%^CYAN%^Well. It's an archway. And it's made of stone. You're not sure there's much more to "
"it than that, really.%^RESET%^");
    return 1;
}