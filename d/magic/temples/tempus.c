//updated description provided by Taeryn.  ~Circe~ 4/1/05
#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_light(2);
   set_indoors(1);
   set_short("%^RESET%^%^WHITE%^A vast military compound%^RESET%^");
   set_long("%^RESET%^%^RED%^The building that you have just "+
         "stepped foot into reminds you of a large military "+
         "compound, even though it stands alone, beyond the "+
         "limits of any nearby city.  The walls are more "+
         "than three feet thick, made from stones deep crimson in "+
         "hue.  They are adorned with the many tools of battle: "+
         "swords, bows, shields, and an array of armor are just "+
         "a few of the trophies placed here.  Looking up you can "+
         "see that the ceiling is high and domed, decorated with "+
         "an intricate mural.  The pentangular room is dim from a "+
         "lack of natural light as there are no windows.  The only "+
         "lighting is that cast from the "+
         "%^WHITE%^to%^BOLD%^%^YELLOW%^r%^RESET%^%^WHITE%^ch"+
         "%^BOLD%^%^YELLOW%^e%^RESET%^%^WHITE%^s %^RED%^that "+
         "line the walls.  At the far end of the room, a raised "+
         "dais supports a great marble statue that stands proudly "+
         "above all else.  A vast square portal leads out into what "+
         "appears to be an arena beyond.%^RESET%^\n");
   set_listen("default","%^BOLD%^%^BLACK%^You hear the sound of "+
         "steel clashing together, and grunts and laughter coming "+
         "from the training arena.%^RESET%^");
   set_smell("default","%^RESET%^%^RED%^You smell a mixture of "+
         "%^BOLD%^%^RED%^blood%^RESET%^%^RED%^, %^WHITE%^smoke%^RED%^"+
         ", and %^ORANGE%^sweat.%^RESET%^");
   set_items(([
         "statue" : "%^RESET%^%^RED%^The statue is a "+
            "massive creation carved from %^WHITE%^pale "+
            "%^RED%^marble, depicting two dire horses, one "+
            "%^BOLD%^%^BLACK%^black, %^RESET%^%^RED%^the other "+
            "%^BOLD%^%^RED%^red%^RESET%^%^RED%^, wrapped "+
            "around one another in fierce combat.%^RESET%^",
         ({"wall","walls"}) : "%^RESET%^%^RED%^The stones that "+
            "make up these massive walls are a deep crimson in "+
            "color, making them look as if they were created "+
            "from the %^BOLD%^%^RED%^blood%^RESET%^%^RED%^ "+
            "spilled in the name of battle.%^RESET%^",
         ({"dome","ceiling","mural"}) : "%^RESET%^%^RED%^This spacious "+
            "dome is decorated by a breathtaking %^CYAN%^mu"+
            "%^BLUE%^r%^ORANGE%^a%^GREEN%^l %^RED%^depicting "+
            "a huge battle scene.  Cavalry charge forward on "+
            "muscular war steeds, foot soldiers throw spears, "+
            "swing swords, and thrust daggers as archers notch "+
            "%^BOLD%^%^YELLOW%^fl%^RESET%^%^RED%^am%^RESET%^"+
            "%^RED%^in%^ORANGE%^g %^RED%^arrows to let fly.  "+
            "The scene is both grave and glorious, as men are "+
            "cut down, and the victors exalt in their victory "+
            "and pay their respects.%^RESET%^",
   ]));
   set_exits(([
      "out" : "/d/dagger/road/p8",
      "northeast" : "/d/magic/temples/tempus_training"
   ]));
   set_post_exit_functions(({"northeast"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^WHITE%^You step through the large "+
      "archway and out into the open air of the training arena.  "+
      "Your feet sink easily into the shallow sand.%^RESET%^");
   return 1;
}
