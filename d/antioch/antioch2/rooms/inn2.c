#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("%^BOLD%^White Dragon Inn");
    set_long(
        "%^WHITE%^This room is small and cozy, it is for the guests of the inn to relax and sit down to enjoy a good meal. On the northern wall is a large %^ORANGE%^f%^BOLD%^%^BLACK%^irep%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ac%^RESET%^%^ORANGE%^e%^WHITE%^ that is lit to keep the room warm in the high altitudes of the Charu Mountains. Most of the citizens here are accustomed to the colder temperatures, but they realize that their guests might not be. The %^GREEN%^car%^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^et%^WHITE%^ extends half way across the room and there are a few %^BOLD%^%^WHITE%^co%^RESET%^%^WHITE%^u%^BOLD%^%^WHITE%^ches%^RESET%^%^WHITE%^ and comfortable %^ORANGE%^chairs%^WHITE%^ for guests to relax in. On the other half of the room is the dining area, a few long %^ORANGE%^ta%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^le%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ with %^ORANGE%^chairs%^WHITE%^ around them have been set up. On each %^ORANGE%^table%^WHITE%^ is a %^BOLD%^menu%^RESET%^ for you to read. From the smells wafting out of the kitchen, the food here is probably quite good. On the far wall is a %^ORANGE%^door%^WHITE%^ that leads to the kitchen. The southern wall holds the continuation of the large %^BOLD%^%^WHITE%^m%^RESET%^%^WHITE%^u%^BOLD%^%^WHITE%^ra%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^.%^RESET%^%^WHITE%^ The wings of the great wyrm stretch out to the top of the ceiling and its claws look incredibly sharp. Staring closely you almost think you see its tail twitch, but that must be a figment of your imagination.
"
        );
    set_smell("default", "Delicious scents waft in from the kitchen," +
              " tantalizing your taste buds.");
    set_listen("default", "The clank and clatter of the dishes comes" +
               " from the kitchen.");
    set_items(([
                   "fireplace" : "%^BOLD%^%^RED%^A large red brick fireplace takes up part of the" +
                   " northern wall. It is lit to bring warmth to the guests and" +
                   " provides light to the room.",
                   "floor" : "Half the floor is covered in the plush %^GREEN%^green" +
                   " carpet%^RESET%^ and the other half is a hardwood floor that is" +
                   " cleanly swept where the dining tables are.",
                   ({ "carpet", "green carpet", "plush carpet" }) : "%^GREEN%^The dark" +
                   " green carpet stretches over half the room and several couches" +
                   " and more comfortable chairs are set on it for the guests to" +
                   " relax in.",
                   "door" : "On the eastern wall there is a door that leads to the" +
                   " kitchen",
                   ({ "table", "tables", "dining tables" }) : "Long dining tables are" +
                   " set up on half of the room. Chairs are placed around them, this" +
                   " is where the guests of the inn can sit down for a nice meal.",
                   ({ "chair", "chairs" }) : "There are several comfortable looking" +
                   " chairs scattered about on the carpet. Around the dining tables" +
                   " are several matching wooden chairs.",
                   ({ "couch", "couches", "sofa", "sofas" }) : "Several very comfortable" +
                   " couches are arranged on the carpet. They are there for guests" +
                   " to relax in and chat with one another.",
                   ({ "lamp", "lamps", "oil lamps", "oil lamp" }) : "Oil lamps are hung" +
                   " on the walls around the room to provide more light.",
                   ({ "mural", "dragon", "white dragon", "white wyrm", "great dragon", "great wyrm" }) : "%^BOLD%^The" +
                   " tail end of the mural stretches across the southern wall here." +
                   " it shows half the body of a great white wyrm. Its wings stretch" +
                   " up to the ceiling and its feet rest on the floor. Razor sharp" +
                   " claws extend out, you get the impression the wyrm would love" +
                   " to sink them into your skin. The tail of the dragon stretches" +
                   " to the end of the wall and for a moment you could swear that it" +
                   " moved. You have to forcefully remind yourself that this image" +
                   " is only a magical creation of a powerful mage.",
                   ]));
    set_exits(([
                   "west" : ROOMS + "inn1",
                   "east" : ROOMS + "inn3",
                   ]));
    set_door("door", ROOMS + "inn3", "east", 0);
}

void reset()
{
    ::reset();
    if (!present("waitress")) {
        new(MONS + "waitress.c")->move(TO);
    }
}

void init()
{
    ::init();
    add_action("read", "read");
    add_action("sit", "sit");
}

int read(string str)
{
    object obj;
    int i;

    obj = present("waitress");

    if (!present("waitress")) {
        write("Someone seems to have killed the waitress!");
        return 1;
    }
    if (str == "menu") {
        say("" + TP->query_cap_name() + " reads over the menu.");
        message("Ninfo", "The waitress shows you the menu she carries, it reads:\n", TP);
        message("Ninfo", "%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n", TP);
        message("Ninfo", "\tWild goose seasoned with herbs \t" +
                " " + (int)obj->get_price("wild goose") + " silver pieces\n", TP);
        message("Ninfo", "\tRack of lamb with mint sauce \t" +
                " " + (int)obj->get_price("rack of lamb") + " silver pieces\n", TP);
        message("Ninfo", "\tBeef and potato stew \t\t" +
                " " + (int)obj->get_price("beef stew") + " silver pieces\n", TP);
        message("Ninfo", "\tSplit pea soup \t\t\t" +
                " " + (int)obj->get_price("split pea soup") + " silver pieces\n", TP);
        message("Ninfo", "\tButtered bread \t\t\t" +
                "  " + (int)obj->get_price("bread") + " silver pieces\n", TP);
        message("Ninfo", "\tSlice of hot apple pie \t\t" +
                " " + (int)obj->get_price("apple pie") + " silver pieces\n", TP);
        message("Ninfo", "\tSpiced custard \t\t\t" +
                " " + (int)obj->get_price("spiced custard") + " silver pieces\n", TP);
        message("Ninfo", "\tChocolate strawberries \t\t" +
                " " + (int)obj->get_price("chocolate strawberries") + " silver pieces\n", TP);
        message("Ninfo", "\tWater \t\t\t\t" +
                "  " + (int)obj->get_price("water") + " silver pieces\n", TP);
        message("Ninfo", "\tMint tea\t\t\t" +
                "  " + (int)obj->get_price("mint tea") + " silver pieces\n", TP);
        message("Ninfo", "\tGlass of red wine \t\t" +
                "  " + (int)obj->get_price("red wine") + " silver pieces\n", TP);
        message("Ninfo", "\tMug of ale \t\t\t" +
                " " + (int)obj->get_price("ale") + " silver pieces\n", TP);
        message("Ninfo", "%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n", TP);
        message("Ninfo", "<buy dish_name> gets you the food.\n", TP);
        return 1;
    }
}

int sit(string str)
{
    if (str == "fireplace" || str == "fire place") {
        tell_object(TP, "%^BOLD%^%^RED%^You sit down in front of the fireplace," +
                    " warming yourself in front of the fire.");
        tell_room(ETP, "%^BOLD%^%^RED%^" + TP->query_cap_name() + " sits down in" +
                  " front of the fireplace, warming " + TP->query_objective() + "self in front" +
                  " of the fire.", TP);
        return 1;
    }
    if (str == "couch") {
        tell_object(TP, "%^BOLD%^You sink down onto one of the many comfortable" +
                    " couches that are scattered about the room.");
        tell_room(ETP, "%^BOLD%^" + TP->query_cap_name() + " sinks down onto one of" +
                  " the many comfortable couches.", TP);
        return 1;
    }
    if (str == "chair") {
        tell_object(TP, "You sit down on one of the large, plush chairs that have" +
                    " been placed here for the comfort of the inn's guests.");
        tell_room(ETP, "" + TP->query_cap_name() + " sits down on one of the large," +
                  " plush chairs.", TP);
        return 1;
    }
    if (str == "table" || str == "table top") {
        tell_object(TP, "You boldly sit down on the top of one of the tables.");
        tell_room(ETP, "" + TP->query_cap_name() + " rudely sits on top of one of the" +
                  " dining tables.", TP);
        return 1;
    }
    if (str == "floor" || str == "carpet") {
        tell_object(TP, "%^GREEN%^You choose to sit down on the thick carpet that" +
                    " covers the floor.");
        tell_room(ETP, "%^GREEN%^" + TP->query_cap_name() + " sits down on the thick" +
                  " carpet that covers the floor.", TP);
        return 1;
    }
    if (str == "wooden chair") {
        tell_object(TP, "%^ORANGE%^You seat yourself in one of the wooden chairs" +
                    " at the dining table.");
        tell_room(ETP, "%^ORANGE%^" + TP->query_cap_name() + " seats " + TP->query_objective() + "self" +
                  " at one of the wooden chairs at the dining table.", TP);
        return 1;
    }
}
