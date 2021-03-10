// ferry for inland river by Styx 5/2003
/*
riverferry1 euid = Shadow
ferryroom1 euid before add_exit = Shadow
riverferry1 got past loading the room
- it bombed here before making the Shadow dock load before trying to load the lower level
ferryroom4 euid before ::create = Shadow
riverferry1 euid = Shadow
riverferry1 got past loading the room
ferryroom4 euid = Shadow
ferryroom1 euid before add_exit = Shadow
ferryroom1 euid in init = Shadow
*/

#include <std.h>

inherit OBJECT;

int clean_up() { return 1; } // this should probably return 0 so it won't get called again
object ferryroom;
string *whereto;
string ticket;
int price;

void create(){
   ::create();
   set_id(({ "ferry","ship", "river ferry" }));
   ticket = "Shadow-Tabor";
   price = 20;
   set_short("%^RESET%^%^CYAN%^Shadow-Tabor River Ferry%^RESET%^");
   set_long("This is a ferry boat that carries travelers, for a fee "
	"of course.  A sign over the boarding ramp shows the cost for "
	"this ferry ride is a mere %^YELLOW%^"+price+" gold pieces.  "
	"%^RESET%^Once you <%^BOLD%^buy ticket for "+ticket+"%^RESET%^>, "
	"you will board this ferry for that route.  "
	"The sign on this one identifies it as running between Shadow and Tabor.");
   set_weight(10000);
   set_property("no animate", 1);
//   write("riverferry1 euid = "+geteuid());
   ferryroom = find_object_or_load("/d/shadow/virtual/river/obj/r_ferryroom1");
//   write("riverferry1 got past loading the room");
   whereto = ({"shadow-tabor", "Shadow-Tabor", "tabor-shadow", "Tabor-Shadow" });
}

void init(){
    ::init();
//    write("riverferry euid in init = "+geteuid());
    if(!objectp(TP))  return;
    add_action("pay","pay");
    add_action("board","board");
    add_action("buy", "buy");
}

int board(string str) {
   if(!id(str))
     if (TO != present(str,ETO))
       return 0;
   write("%^BOLD%^The sailor stops you and holds his hand out for you to pay him.");
   return 1;
}

int buy(string str) {
    string which;
    int inc, riders;
    object *ob;
    if(TP->query_paralyzed() || TP->query_unconscious())
	return notify_fail("You can't do that in your present state!");
    if(!str) 
	return notify_fail("You need to <buy ticket for [which]>.\n");
    if(sscanf(str,"ticket for %s", which) != 1)
        return notify_fail("You need to <buy ticket for [which]>.\n");
    if(member_array(which, whereto) == -1)
        return notify_fail("You need to <buy ticket for "+ticket+">.\n");
    if(!TP->query_funds("gold", price)) {
        write("You need "+price+" gold for a ticket!\n");
        tell_room(ETO, "A burly sailor stops "+TPQCN+" and points to the sign.", TP);
	return 1;
    }
    if(!objectp(ferryroom)) { ferryroom = find_object_or_load("/d/shadow/virtual/river/obj/r_ferryroom1"); }
    if(ob = all_inventory(ferryroom)) {
        for(inc = 0; inc < sizeof(ob);inc ++)
            if(interactive(ob[inc])) riders += 1;
            if(riders > 10)
                return notify_fail("Sorry, the ferry is full!\n");
    }
    TP->use_funds("gold",price);
    write("%^CYAN%^A burly sailor takes the gold from your hand "
	   "and drops it into his pocket.  He then waves you onto the ferry "
	   "and turns away.");
    tell_room(ETO,TPQCN+" pays the sailor some money and is allowed onto the ferry.",TP);
    tell_room(ETO,"%^MAGENTA%^The sailor yells out:  %^RESET%^Ferry leaves in one minute!");
    TP->move_player(ferryroom);
    return 1;
}

int pay(string str) {
    write("You need to <buy ticket for [where]> now.");
    return 1;
}