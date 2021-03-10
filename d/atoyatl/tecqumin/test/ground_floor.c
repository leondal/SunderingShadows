#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("The ground floor of a ruined tower.");
  set_short("The ground floor of a ruined tower.");
  set_long( "The ground floor of the tower is a mess. A stone stairway has collapsed, along with the"
   +" first ceiling, leaving only the second floor ceiling high above, the stairwell sitting"
   +" open and empty in one corner of it. The piles of rubble on the floor block access to the"
   +" doorway that once lead outside. The walls are built of decorated gray stone, but some event"
   +" in the past appears to have wrenched and shifted the stones quite badly, causing gaps and"
   +" openings through which various %^ORANGE%^branches%^RESET%^ and %^GREEN%^tendrils%^RESET%^ of"
   +" plant life have poked their way inside. The once sturdy structure now appears distinctly"
   +" unsafe." );
  set_items(([({"wall", "walls", "stone", "stones", "decorated stones", "decoration", 
                "decorations", "decorated stone"}) : "Despite their state of disrepair, the walls"
   +" bear intricate carvings that suggest this building was once a structure of some status and"
   +" significance. No other clues remain as to what that significance might have been, however.",
       ({"stairwell", "stairs", "stair"}) : "The pile of rubble that is all that remains of the"
   +" stairway sits below an open stairwell in the corner of the second ceiling, high overhead."
   +" It is a long way up, but the uneven state of the walls make it seem a possible, if perilous"
   +" climb to reach it.",
                ({"branches", "branch", "tendril", "tendrils", "plant", "plants"}) : 
     "%^ORANGE%^Branches%^RESET%^, %^GREEN%^creepers%^RESET%^ and other bits of%^BOLD%^%^GREEN%^"
   +" plant life%^RESET%^ have exploited the gaps and cracks in the stone to make their way inside"
   +" the tower. With more time it seems likely that the forces of nature will prevail and collapse"
   +" the tower completely.", 
               ({"carving", "carvings"}) : "The carvings on the walls are clearly of some"
   +" significance, but their precise meaning is lost on you. They appear to relate to themes of"
   +" some past civilisation that must have once thrived in the %^GREEN%^j%^BOLD%^%^GREEN%^u"
   +"%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^. You can make out"
   +" suggestions of apparently religious icons that are unknown to you, including %^BOLD%^%^RED%^"
   +"f%^RESET%^%^RED%^ea%^BOLD%^%^BLUE%^t%^GREEN%^h%^RESET%^%^RED%^er%^BOLD%^%^RED%^ed %^GREEN%^s"
   +"%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^pe%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^ts%^RESET%^,"
   +" %^BOLD%^%^BLACK%^jaguar spirits%^RESET%^ and other apparently animist interpretations of"
   +" life in the jungle. A great stepped pyramid dominates one wall, with two of the %^BOLD%^"
   +"%^RED%^f%^RESET%^%^RED%^ea%^BOLD%^%^BLUE%^t%^GREEN%^h%^RESET%^%^RED%^er%^BOLD%^%^RED%^ed"
   +" %^GREEN%^s%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^pe%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^ts"
   +" %^RESET%^depicted flying above it, and the %^BOLD%^%^YELLOW%^sun%^RESET%^ cresting"
   +" magnificently at its zenith. In one cracked and almost defaced section of the wall, you"
   +" notice a depiction of an ugly, threatening %^BLUE%^pre%^BOLD%^%^BLACK%^se%^RESET%^%^BLUE%^nce"
   +" %^RESET%^that appears to be steadily devouring everything that is near it. " 
        ]));
  set_smell("default","It is a bit musty in the tower, but the heady scents of the"
    +" jungle still reach you here.");
  set_listen("default","The sounds of the jungle drift into the tower.");
}
void init() {
   ::init();

}



int climb_up(){
  object tower;
  tell_object(TP, "With a fair amount of scraping and struggling, you wriggle your way out through a"
        +" lucky gap in the pile of stones.");
  tell_room(TO, TPQCN +" struggles " + TP->QP + " up through a small gap between the collapsed stones.", TP );
  tower = find_object_or_load(ROOMS + "tower");
  if (objectp(tower)){
    tell_room(tower , "A scraping noise draws your attention to a small gap in the pile of stones. After a"
      +" moment or two, " + TPQCN + " emerges from the hole, brushing dust and debris from " + TP->QO 
      +"self.", TP);
  }
  return 1;
}

void collapse(){
  set_long( "You are in a space in the middle of a collapsed pile of stones and rubble. It's"
   +" quite uncomfortable, but at least you are not crushed and there is a little air to breathe."
   +" Some light filters in from above you, and a gap in the stones suggests that it may be"
   +" possible to climb out." );
      set_climb_exits(([
      "climb" : ({ROOMS + "tower",2,0,20}),
   ]));  
   remove_item(({"wall", "walls", "stone", "stones", "stairwell", "stairs", "stair"}) );
   set_pre_exit_functions(({"climb"}), ({ "climb_up"}));
}
