//updated by Circe 1/9/05 with desc by Lusell
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_name("Hotel Dining Room");
    set_short("Hotel Dining Room");
/*
    set_long(
      "The dining room for the hotel is HUGE.  Used for many banquets and town conventions, this area is currently set up just for relaxed dining, but you can see how it could be set up for mass audiences.  To the north you can see a huge piano on the stage.  To the east is the bar, and to the west you can see where you order your food."
    );
*/
    set_long("%^BOLD%^%^WHITE%^This hallway leads to a fairly huge "+
       "area of the hotel.  Ornate silver %^RESET%^candelabrum%^BOLD%^"+
       "%^WHITE%^ line the teakwood %^RESET%^%^ORANGE%^walls %^BOLD%^"+
       "%^WHITE%^casting a wonderful light.  The hall is used for many "+
       "things, from banquets, town conventions, bard tales and musings "+
       "to romancing couples and relaxed dinners.  Suffice it to say it "+
       "is set up for large audiences.  Large sets of %^YELLOW%^double"+
       "-doors%^WHITE%^, both wide open, are to the east and west while "+
       "a swinging double %^YELLOW%^half-door %^WHITE%^leads to a smoke-"+
       "filled room to the south.%^RESET%^\n");
    set_smell("default", "You can smell the odor of cooking food.");
    set_listen("default", "Soft music from a piano floats in from the south.");
    set_items( ([
       ({"table","tables"}) : "Right now, the dining hall is set up "+
          "with smaller round tables.  They are set with elegant "+
          "centerpieces, and tall potted plants are placed at "+
          "various intervals around the room to give the illusion "+
          "of privacy.  Each table could sit no more than six people.",
       ({"candelabrum","candelabrums","candelabra"}) : "Shimmering "+
          "candelabrums made of ornate silver are set within the "+
          "deep teak walls.  Their candles cast a soft, pleasant "+
          "light on the room.",
       ({"wall","walls","teak"}) : "The walls are made of smooth, "+
          "deep teak wood.  Its rich surface soaks up the light "+
          "of the candles, helping to soften their glare.",
       ({"doors","double-doors","double doors"}) : "Large sets "+
          "of double doors stand to the east and west, wide "+
          "open to reveal other rooms.  To the east, you see "+
          "what seems to be a gathering place, while the western "+
          "doorway reveals the hotel bar where you could "+
          "probably order your meal.",
       "half-door" : "The half-door to the south swings open "+
          "and closed as waiters and waitresses move in and "+
          "out of the room.  You catch glimpses of a grand "+
          "piano through the smokey haze in that direction."
      ]) );
    set_exits( ([
	"east" : RPATH "hotelbar",
	"west" : RPATH "hotelfood",
	"south" : RPATH "hotelpiano",
	"north" : RPATH "hotel1"
      ]) );
}
