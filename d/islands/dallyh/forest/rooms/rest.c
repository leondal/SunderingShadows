#include "/d/islands/dallyh/fways.h"
inherit "/std/room";
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_short("%^RESET%^%^ORANGE%^The native hospitality%^RESET%^");
    set_name("the native hospitality");
    
    set_long("%^RESET%^%^GREEN%^From here you can tell that this large shelter "+
    "has not been built up into the trees, but rather it is part of them. "+
    "It looks %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^ and %^BOLD%^%^WHITE%^sturdy"+
    "%^RESET%^%^GREEN%^. You are not sure if it was created or simply developed, it is "+
    "impossible to tell. This particular one has been set up to welcome visitors by providing them "+
    "with food and drink. There is "+
    "a makeshift counter along the western wall with a menu tacked to the front of it. "+
    "Dotting the shelter are several round %^RESET%^%^ORANGE%^wooden tables%^RESET%^%^GREEN%^ and "+
    "several longer %^RESET%^%^ORANGE%^wooden benches%^RESET%^%^GREEN%^. There are %^BOLD%^"+
    "%^MAGENTA%^plush%^RESET%^%^GREEN%^ chairs situated near all of them. The tables, benches, and "+
    "chairs all seem quite solid and sturdy.%^RESET%^");
    set_smell("default","You smell the scent of freshly cooked foods.");
    set_listen("default","The sounds of forest life echo all around you.");
    set_items(([
        ({"tables", "wooden tables", "benches", "wooden benches", "chairs", "plush chairs"}) : "%^RESET%^%^ORANGE%^"+
        "The tables, chairs, and benches are all a very solid and stury wood. The chairs have been "+
        "padded with a plush material to provide some comfort when sitting in them. This entire "+
        "shelter looks to have been set up as a means of extending hospitality to visitors. You believe that "+
        "very few natives set foot in this place except to serve visitors.%^RESET%^",
          
        ({"menu", "counter", "makeshift counter"}) : "%^RESET%^%^GREEN%^This makeshift counter rests along "+
        "the western wall of this shelter. It extends almost the entire length of it with small openings at either "+
        "end to allow the natives to walk behind it. There is a %^BOLD%^%^WHITE%^menu%^RESET%^%^GREEN%^ "+
        "tacked to the front of it that you could %^BOLD%^%^RED%^read%^RESET%^%^GREEN%^ if you were so "+
        "inclined.%^RESET%^",

        ({"shelter", "shelters", "hospitality", "trees"}) : "%^RESET%^%^GREEN%^This large "+
        "shelter has not been built up into the trees. It is actually a part of the trees. "+
        "It is almost as if it inside of them and the trees actually seem to be continually "+
        "growing around it, providing it with an enormous amount of protection. It seems very "+
        "sturdy and quite ancient.%^RESET%^",
    ]));          
    set_exits(
              (["east" : FRPATH "road3"]) );
}
void reset() 
{
    ::reset();
    if(!present("waitress")) 
    {
        new( FMPATH "waitress")->move(this_object());
    }
}

int read(string str) 
{
    object ob;
    int i;
    ob = present("hospitalitywoman");
    if(!ob) {
        write("You cannot read the sign, as it is splattered with blood.");
        return 1;
    }
    write("The following foods are served here.");
    write("-----------------------------------------------------------");
    write("Roast Boar\t\t\t"+ (int)ob->get_price("roast boar") + " gold");
    write("Leg of Lamb\t\t\t"+(int)ob->get_price("leg of lamb")+" gold");
    write("Berries\t\t\t\t"+(int)ob->get_price("berries")+" gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    write("The following drinks are served here.");
    write("-----------------------------------------------------------");
    write("Water\t\t\t\t"+(int)ob->get_price("water")+" gold");
    write("Mysterious Water\t\t"+ (int)ob->get_price("mysterious water") + " gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the drink.");
    return 1;
}
