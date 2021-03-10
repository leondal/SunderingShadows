#include <std.h>
inherit ROOM;

string time;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_short("Bloody Mary's Restaurant");
  set_long("%^RESET%^%^CYAN%^This is the restaurant and it smells of %^MAGENTA%^exotic foods%^RESET%^%^CYAN%^ and other delicious "+
"things to eat. You find that your mouth is %^RESET%^watering%^RESET%^%^CYAN%^ and your stomach is %^ORANGE%^growling%^RESET%^%^CYAN%^ "+
"from hunger. The decor is a bit unusual, but somewhat pleasant all the same. "+
"The %^BOLD%^bar%^RESET%^%^CYAN%^ is to your west if you would prefer a drink. Go ahead and read the menu, treat yourself to something yummy.%^RESET%^\n");
  set_smell("default","You smell exotic foods and other enticements.");
  set_listen("default", "You hear low-key conversation.");
  set_items( ([
    "Restaurant" : "Bloody Mary's Restaurant",
    "sign" : "The menu is posted here.",
    "menu" : "Maybe you should try reading it.",
    "decor" : "The decor consists mostly of colorful shields, but there's a few curious hides as well.",
    "shields" : "Each one is of a different shape. You also notice that each one has a different coat of arms painted on it.",
    "hides" : "OH DEAR GOD! THEY LOOK TO BE OF HUMAN SKIN!!"
  ]) );
  set_exits( ([
     "bar":"/d/koenig/town/bar1",
     "out":"/d/koenig/town/room1"
  ]) );
}

void init()
{
  ::init();
  add_action("read", "read");
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "dawn" || time == "day")
{
  if(!present("waiter"))
    new("/d/koenig/town/mon/slacker.c")->move(this_object());
  if(!present("patron"))
    new("/d/koenig/town/mon/scarlet.c")->move(this_object());
    return 1;
}
}

int read(string str)
{
    object ob = present("waiter");
    int i;
    if(str == "menu")
    {
        if(!ob)
        {
            write("The waiter is not here at the moment.");
            return 1;
        }
        say(""+TPQCN+" reads over the menu.");
        write(
"%^RED%^>->>- %^BOLD%^%^RED%^Bloody Mary's Restaurant %^RESET%^%^RED%^-<<-<%^WHITE%^

   %^BOLD%^%^RED%^House Special    %^BOLD%^%^WHITE%^30 %^RESET%^Silver
   %^BOLD%^%^RED%^Rare Steak       %^BOLD%^%^WHITE%^25 %^RESET%^Silver
   %^BOLD%^%^RED%^Heart            %^BOLD%^%^WHITE%^20 %^RESET%^Silver
   %^BOLD%^%^RED%^Liver and Onions %^BOLD%^%^WHITE%^15 %^RESET%^Silver
   %^BOLD%^%^RED%^Blood Cake       %^BOLD%^%^WHITE%^15 %^RESET%^Silver
   %^BOLD%^%^RED%^Bread Basket     %^BOLD%^%^WHITE%^10 %^RESET%^Silver

 %^RED%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^WHITE%^");
        return 1;
    }
    return 0;
}