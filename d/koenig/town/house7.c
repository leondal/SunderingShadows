#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Strange Bedroom");
set_long("%^RESET%^%^CYAN%^This is a bedroom. The sister that occupies this room appears to have some strange tastes indeed. On the floor lie %^RESET%^skins%^RESET%^%^CYAN%^ and %^RESET%^furs%^RESET%^%^CYAN%^ that you don't recognize right off, and some strange %^BOLD%^statues%^RESET%^%^CYAN%^ line the shelf near the bed. The %^ORANGE%^bed%^RESET%^%^CYAN%^ occupies the majority of the room, but there appears to be a dresser along the far wall. There is a %^MAGENTA%^painting%^RESET%^%^CYAN%^ above the bed that gives you the feeling you are being watched. The eyes seem to follow your every move.\n");
  set_smell("default", "You can smell strange incense in this room.");
    set_listen("default", "You can hear the crackling fire from the other room.");
  set_items( ([
       "skins" : "If you didn't know any better you'd say they match those you saw in the restaurant.",
     "furs" : "The furs appear to be those of various animals but mostly of wolves and black panthers.",
     "shelf" : "This shelf is lined with strange statues...hmmm they almost resemble toys and torture devices...ACK",
     "statues" : "There are too many to describe but let's say you don't want to find out if they are really statues or toys or torture devices.",
     "bed" : "This bed is HUGE. It is a four poster bed with a canaopy. Maybe you should take a closer look at the posters of the bed?",
     "posters" : "There appear to be shackles attached to each poster of the bed. Now might be a good time to leave before the occupant of this room returns!",
     "dresser" : "The dresser is very large and there are many things scattered about its surface, including a very beautiful jewelry box.",
       "painting" : "The background appears to be a banquet of some kind, and the painting's dominating figure is trying to look powerful and regal.",
     "design" : "The design on the jewelry box is of some climbing ivy and spider webs. In the center of one of the webs sits a black widow spider."
]) );
  set_exits( ([
     "north" : "/d/koenig/town/house4",
     "enter" : "/d/koenig/town/tower32.c"
]) );
  set_invis_exits( ({"enter"}) );
  set_pre_exit_functions( ({"enter"}),({"GoThroughDoor"}) );
}
int GoThroughDoor() {
if((int)TP->query_lowest_level() < 19) {
    write("Your lack of experience causes failure in your attempt to enter the painting!");
    return 0;
}
tell_room(environment(this_player()), "%^CYAN%^"+ this_player()->query_cap_name() +" looks intently at the painting and vanishes!");
tell_object(this_player(),"%^BOLD%^%^CYAN%^You look intently at the painting and suddenly realize that you have become a part of it!");
set_items( ([
     "painting" : "The background appears to be a banquet of some kind, and the painting's dominating figure looks to be fighting "+ this_player()->query_cap_name() +"!"
]) );
return 1;
}
void reset()
{
  ::reset();
  if(!present("jewelry box"))
  new("/d/koenig/town/items/jewelbx1.c")->move(this_object());
}
