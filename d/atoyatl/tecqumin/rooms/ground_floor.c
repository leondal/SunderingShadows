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
                "decorations", "decorated stone"}) : "The walls of"
    +" the tower reall appear unsafe. One of them has already"
    +" collapsed, and most of the rest of them look like a good"
    +" shove could bring them down. Possibly not a good idea,"
    +" though." 
   +"\nDespite their state of disrepair, the walls"
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
   add_action("shove", "shove");
   add_action("climb_up", "climb");
}



int climb_up(){
  object tower;
  tell_object(TP, "With a fair amount of scraping and struggling, you wriggle your way out through a"
        +" lucky gap in the pile of stones.");
  tell_room(TO, TPQCN +" struggles " + TP->QP + " up through a small gap between the collapsed stones.", TP );
  tower = find_object_or_load(JUNG_ROOM3 + "tower");
  if (objectp(tower)){
    tell_room(tower , "A scraping noise draws your attention to a small gap in the pile of stones. After a"
      +" moment or two, " + TPQCN + " emerges from the hole, brushing dust and debris from " + TP->QO 
      +"self.", TP);
    TP->move(tower);
    TP->force_me("look");
  }
  return 1;
}

void collapse(){
  object urn;
  set_long( (:TO, "collapse_desc":) );
      set_climb_exits(([
      "climb" : ({ROOMS + "tower",2,0,20}),
   ]));  
   remove_item(({"wall", "walls", "stone", "stones", "stairwell", "stairs", "stair"}) );
   set_pre_exit_functions(({"climb"}), ({ "climb_up"}));
  urn = new (OBJ + "urn");
  urn->move(TO);
}

string collapse_desc(){
  string result;
  result =  "You are in a space in the middle of a collapsed pile of stones and rubble. It's"
   +" quite uncomfortable, but at least you are not crushed and there is a little air to breathe."
   +" Some light filters in from above you, and a gap in the stones suggests that it may be"
   +" possible to climb out.";
  if (present("urn", TO)) result += "\nAmazingly, something else seems to have survived the"
    +" collapse. A stone urn has tumbled from a hidden space in the walls to the floor beside you";
  return result;
}


int shove(string str){
  object tower;
  if (str != "wall" && str != "the wall") {
    return notify_fail("Do you want to shove the wall?");
  }
  tell_object(TP, "You give the wall a tentative shove. Perhaps not"
   +" tentative enough, though, as the stone you were pushing"
   +" against falls out and drops to the ground outside the tower.");
  tell_room(TO, TPQCN + " gives the wall a shove. Worryingly, the"
   +" stone " + TP->QS + " pushes falls out of the wall and drops to"
   +" the ground outside of the tower.", TP);
  tower = find_object_or_load(ROOMS + "tower");
  if (objectp(tower)){
    tell_room(tower, "A large stone falls suddenly from one of the"
     +" remaining lower walls of the tower, leaving a hole.");
  }
  call_out("shove2", 3);
  return 1;
}

void shove2(){
  object tower, upper_floor;
  tell_room(TO, " ");
  tell_room(TO, "The stones of the wall %^ORANGE%^creak%^RESET%^"
   +" alarmingly, and you can see them actually moving above the"
   +" hole that was left behind by the stone that just fell.");
  tower = find_object_or_load(ROOMS + "tower");
  upper_floor = find_object_or_load(ROOMS + "upper_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "The stones of the tower %^ORANGE%^creak"
     +" %^RESET%^and %^CYAN%^groan%^RESET%^ alarmingly.");
  }
  if (objectp(upper_floor)){
    tell_room(upper_floor, " ");
    tell_room(upper_floor, "You hear an alarming %^BOLD%^"
      +"%^BLACK%^groaning%^RESET%^ sound from the stones"
      +" beneath you.");
  }
  call_out("shove3", 4);
}
void shove3(){
  object tower, upper_floor;
  tell_room(TO, " ");
  tell_room(TO, "The stones %^ORANGE%^creak%^RESET%^ again, and you"
    +" think you see more movement.");
  tower = find_object_or_load(ROOMS + "tower");
  upper_floor = find_object_or_load(ROOMS + "upper_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "There is another, quieter %^ORANGE%^creak"
      +"%^RESET%^ from the stones overhead");
  }
  if (objectp(upper_floor)){
    tell_room(upper_floor, " ");
    tell_room(upper_floor, "There is a second, quieter %^ORANGE%^"
      +"creak%^RESET%^ from beneath you.");
  }
  call_out("shove4", 3);
}


void shove4(){
  object tower, upper_floor;
  tell_room(TO, " ");
  tell_room(TO, "With a %^GREEN%^groan%^RESET%^, the stones of the"
    +" wall %^ORANGE%^collapse%^RESET%^ into the hole left behind by"
    +" the one that fell out, and then fall inwards onto the tower"
    +" floor");
  tower = find_object_or_load(ROOMS + "tower");
  upper_floor = find_object_or_load(ROOMS + "upper_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "A %^ORANGE%^CRASH%^RESET%^ from above draws"
      +" your attention to one of the upper walls of the tower,"
      +" which has just crashed inward.");
  }
  if (objectp(upper_floor)){
    tell_room(upper_floor, " ");
    tell_room(upper_floor, "A loud series of %^ORANGE%^crashes"
      +" %^RESET%^and %^BOLD%^%^BLUE%^bangs%^RESET%^ from below"
      +" suggests that something very bad is about to happen to the"
      +" dangerously unstable tower. The stone floor%^CYAN%^"
      +" trembles%^RESET%^ and %^BOLD%^%^BLUE%^quakes"
      +" %^RESET%^underfoot. ");
  }
  call_out("shove5", 3);
}

void shove5(){
  int i, num, hp;
  object tower, upper_floor, * critters, ob;
  tell_room(TO, " ");
  tell_room(TO, "With fearful inevitability, and a lot"
      +" of very loud noise, the %^ORANGE%^ceiling%^RESET%^ falls on"
      +" your head from two stories up, followed by the%^ORANGE%^"
      +" stones%^RESET%^ of the rest of the tower as it %^BOLD%^"
      +"%^BLUE%^collapses%^RESET%^ inward on top of you. You are"
      +" left with a vision of a mass of %^CYAN%^falling masonry"
      +"%^RESET%^ heading toward you at high speed, then"
      +" everything goes %^BOLD%^%^BLACK%^dark%^RESET%^.");
  tower = find_object_or_load(ROOMS + "tower");
  upper_floor = find_object_or_load(ROOMS + "upper_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "A series of loud %^BOLD%^%^BLUE%^bangs"
      +" %^RESET%^and %^ORANGE%^crashes%^RESET%^ come from the tower"
      +", which eventually collapses inward in a great cloud of"
      +" %^BOLD%^%^WHITE%^dust%^RESET%^ and %^ORANGE%^broken masonry"
      +"%^RESET%^. When the dust clears, all that remains is a mass"
      +" of rubble.");
  }
  if (objectp(upper_floor)){
    tell_room(upper_floor, " ");
    tell_room(upper_floor, "With a final %^ORANGE%^creak%^RESET%^, the floor of"
    +" the tower gives way, sending you %^BOLD%^%^BLUE%^tumbling"
    +" %^RESET%^to the ground in the middle of a mass of %^CYAN%^"
    +"falling masonry%^RESET%^.");
    tell_room(upper_floor, "You hit your head, hard, and everything goes"
   +"%^BOLD%^%^BLACK%^dark%^RESET%^.");
  }

  critters = all_living(TO);
  if (objectp(upper_floor)){
    critters += all_living(upper_floor);
  }
  num = sizeof(critters);
  if (num <1) { return;}
  for (i=0;i<num;i++){
    ob = critters[i];
    if (ob->query_true_invis()) 
    {
      tell_object(ob, "Your immortal importance saves you from implausible impropriety.");
      tell_object(ob, "All the collapsing masonry misses you");
      continue;
    }
    ob->set_hp(-1);
    ob->set_unconscious(5);
  }
  collapse();
  if (objectp(tower)){
    tower->collapse();
  }
  if (objectp(upper_floor)){
    upper_floor->collapse();
  }
}
