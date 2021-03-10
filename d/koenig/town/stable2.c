#include <std.h>

inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_short("Stable Storage");
    set_long("%^RESET%^%^CYAN%^There is not much to see here. A couple of bales of %^YELLOW%^hay%^RESET%^%^CYAN%^ have been tossed about, along with some %^RESET%^pitchforks%^CYAN%^ and the stray %^ORANGE%^saddle%^CYAN%^. Bags of %^RESET%^oats%^CYAN%^ stashed in a corner are being enjoyed by some mice. A %^BOLD%^counter%^RESET%^%^CYAN%^ seems out of place here, perhaps there was once a shop here - or the dreams of one. There is a little %^BOLD%^sign%^RESET%^%^CYAN%^ atop it for you to look at.%^RESET%^\n");
    set_smell("default","You can smell leather and oil.");
    set_listen("default","It is fairly quiet here except for the sound of "
               "horses from below.");
    set_search("counter","You find two buttons hidden just inside the back "
               "of the counter.");
    set_exits( ([
       "down" : "/d/koenig/town/stable1"
    ]) );
    set_items( ([
	   "counter" : "The counter seems a bit out of place here, but isn't that always the best time to have a closer look?",
       "buttons" : "One is %^BOLD%^white%^RESET%^ and the other is %^BOLD%^%^BLUE%^blue%^RESET%^.",
       "sign" : "%^RED%^\n"+
                "******************\n"+
                "*   Stories ->   *\n"+
                "*                *\n"+
                "*   <- Poetry    *\n"+
                "******************\n"
    ]) );
}

void init()
{
  ::init();
    add_action("push","push");
    add_action("press","press");
}

int push(string str)
{
    if(str == "button")
{
    write("Which button do you want to push?");
    return 1;
}
    if(str == "blue button")
{
    write("You push the blue button and a panel along the east wall slides "
          "away to reveal an exit.");
    say(TPQCN+" pushes something and a panel along the east wall slides to "
        "one side revealing an exit to a hidden room.");
    add_exit("/d/koenig/town/board2.c","east");
    call_out("close_blue",10);
    return 1;
}
    if(str == "white button")
{
    write("You push the white button and a panel along the west wall slides "
          "away to reveal an exit.");
    say(TPQCN+" pushes something and a panel along the west wall slides to "
        "one side revealing an exit to a hidden room.");
    add_exit("/d/koenig/town/board1.c","west");
    call_out("close_white",10);
    return 1;
  }
}

int press(string str)
{
    if(str == "button")
{
    write("Which button do you want to press?");
    return 1;
}
    if(str == "blue button")
{
    write("You press the blue button and a panel along the east wall slides "
          "away to reveal an exit.");
    say(TPQCN+" presses something and a panel along the east wall slides to "
        "one side revealing an exit to a hidden room.");
    add_exit("/d/koenig/town/board2.c","east");
    call_out("close_blue",10);
    return 1;
}
    if(str == "white button")
{
    write("You press the white button and a panel along the west wall slides "
          "away to reveal an exit.");
    say(TPQCN+" presses something and a panel along the west wall slides to "
        "one side revealing an exit to a hidden room.");
    add_exit("/d/koenig/town/board1.c","west");
    call_out("close_white",10);
    return 1;
  }
}

void close_blue(string str)
{
    write("A panel in the east wall slides back into place.");
    say("A panel in the east wall slides back into place.");
    remove_exit("east");
    return 1;
}

void close_white(string str)
{
    write("A panel in the west wall slides back into place.");
    say("A panel in the west wall slides back into place.");
    remove_exit("west");
    return 1;
}
