// Cart from Meadows to Offestry. Nienne, 02/10
#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_name("A tunnel opening in the mountainside");
    set_short("%^GREEN%^A tunnel opening in the mountainside");
    set_long("%^GREEN%^A tunnel opening in the mountainside\n"
"%^RESET%^The path reaches an abrupt end here amongst the foothills at the base of the %^CYAN%^Echoes Mountains%^RESET%^, "
"where the maw of a dark tunnel opens into the rocky mountainside.  A few townsfolk seem to have set up some kind of "
"temporary campsite here, and are in the process of running what appears to be a series of %^ORANGE%^small mining carts"
"%^RESET%^.  They sit upon a pair of steel rails that lead into the roughly carved stone walls that border the %^BLUE%^"
"darkness %^RESET%^beyond.  Just where it leads isn't specified, but it seems to stand as a means back to that little "
"hamlet of beginnings, Offestry.  A %^YELLOW%^sign %^RESET%^stands just where the rails turn upward at their dead end.  "
"To the southeast, a fair distance away, you can see a crossroads.");
    set_listen("default","An occasional clickety-clack of a travelling cart echoes from within the tunnel.");
    set_smell("default","The smell of freshly turned dirt is all that can be noticed here.");
    set_items(([
      "tracks":"%^BLUE%^These are old and made of what looks like steel, although it's questionable just how secure they are.%^RESET%^",
      "sign":"%^YELLOW%^There is a sign here. You should <read> it.%^RESET%^",
    ]));
    set_exits( ([
        "northeast":"/d/newbie/rooms/roadout/mtnroad41"
    ]) );
}

void init(){
    ::init();
    add_action("read","read");
    add_action("ride","ride");
}

int read(){
    write("%^YELLOW%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    write("%^BOLD%^%^CYAN%^  Ardelmir's Cart Service");
    write("%^YELLOW%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    write("%^BOLD%^%^WHITE%^\n<ride> to Offestry!\n");
    write("%^YELLOW%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    write("%^BOLD%^%^CYAN%^For those returning to days of youth.");
    write("%^YELLOW%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    return 1;
}

int ride(){
    object myroom;
    if(TP->query_level() > 9 && !avatarp(TP)) {
      write("The man running the cart shakes his head, 'I think you're a little big to go back there.'");
      return 1;
    }
    write("The man shows you to a cart. Once you're settled in, he pulls a lever and you clatter off into darkness!");
    tell_room(ETP,""+TPQCN+" is shown to a cart, which sets off into the darkness of the tunnel.",TP);
    myroom = new("/d/newbie/rooms/cartride/tabor2off");
    TP->move(myroom);
    TP->describe_current_room(1);
    return 1;
}