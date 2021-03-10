#include <std.h>
      
inherit STABLE;
#define HOR "/d/common/mounts/"+

void update_stable_hand()
{
    object ob;
    if(present("stable hand")) 
    {
        ob = present("stable hand");
        ob->set_long("%^RESET%^This short man is absolutely "+
        "filthy.  His light hair is matted with sweat and littered "+
        "with straw and dark spots that you hope to be dirt.  "+
        "His body is very well toned, his exposed torso the result "+
        "of years of hard work with his massive hands.  "+
        "His eyes are a pale green and offer a continually "+
        "hopefully look, a look that has probably encouraged "+
        "more than one person in his time.  A warm smile "+
        "commonly and easily finds its way to his lips.  The "+
        "charm and kindness that seem to linger about this "+
        "man almost allow for you to forget to extreme filth "+
        "that covers him.");
        ob->set_short("A dirt encrusted stable boy");
        ob->set_id(({"boy","young boy","stable hand","hand","man"}));
    }
}

void create() 
{
    ::create();
    set_light(2);
    set_indoors(1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
  	set_short("%^YELLOW%^V%^RESET%^%^ORANGE%^erbobone %^BOLD%^S%^RESET%^%^ORANGE%^tables%^WHITE%^");
    set_name("verbobone stables");
 set_long("%^YELLOW%^V%^RESET%^%^ORANGE%^erbobone %^BOLD%^S%^RESET%^%^ORANGE%^tables%^WHITE%^
%^ORANGE%^This small building serves as the main room of the stables for the town of verbobone. The front of the building opens to the east and leads out to the southern street of the small town. The back of the building is lined with %^CYAN%^stall%^ORANGE%^s that house different breeds of mounts. The dirt %^GREEN%^floor %^ORANGE%^of this building is littered with straw and in some places the straw is covered piles of manure. A makeshift %^CYAN%^counter %^ORANGE%^has been set up near the front of the building. A haphazard %^BOLD%^sign%^RESET%^%^ORANGE%^, with surprisingly legible writing stands just to the right of the open entrance.%^WHITE%^");
    
    set_items(([
    "counter" : "This makeshift counter is compased of a slab of "+
    "oak that sits on two four foot oak logs that have been stood "+
    "on their ends.  A small wooden chair rests directly to the side "+
    "of it.",
    "floor" : "The dirt floor of this building is covered almost "+
    "entirely with straw and piles of manure.  Cleaning it is "+
    "obviously not a very high priority.",
    "stalls" : "These lines the west wall of this makeshift "+
    "stables.  They are used to house various breeds of mounts.",
    //"sign" :  "This wooden sign bears the types of horses for sell, "+
    //"the asking price, and the available horses.  You should read "+
    //"it.",
    ]));

    set_smell("default","The odor of manure and hay mingle together "+
    "and fill the air.");
    
    set_listen("default","The sounds of the animals mix "+
    "with the slight bustle of the town.");

    set_animal(
        ({"horse","donkey","mare","stallion","pony","charger"}),
        ({HOR"horse",HOR"donkey",HOR"mare",HOR"stallion",
        HOR"pony",HOR"charger"})
    );
    

   set_animal_price(
        ({"horse","donkey","mare","stallion","pony","charger"}),
        ({75,50,100,150,80,180})
    );
   set_exits(([
   "east" : "/d/deku/town/sroad2",
   ]));
   set_stalls(10);
   ::fill_stalls();
   update_stable_hand();
}

void reset()
{
    ::reset();
    update_stable_hand();
}
