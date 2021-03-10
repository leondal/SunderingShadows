//mystra_hidden.c - Hidden library of Mystra.  Designed by Isaiah, Kirin, and Trevize.
//coded by Circe 12/29/03
#include <std.h>
inherit "/std/templemisc";

//int open_exit;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_short("Secret Library");
        set_name("Secret Library");
        set_long(
/*
"Below the temple of mystra lies this secret library.  "+
           "Dozens of rows of shelves which are made of stone that go from "+
           "floor to ceiling contain many books and stored items.  The ceiling "+
           "is not high perhaps a little under seven feet.  In the center of the "+
           "area there is a ladder that leads up to a trap door.  Nearby the trap "+
           "door sits a large white marble table with several stools around it."+
*/
@CIRCE
%^BOLD%^%^BLUE%^Coming through the trapdoor, the room unfolds before you.  
Pillars of stone rise up to the ceiling, supporting this room, 
carved to resemble famous %^RESET%^%^BLUE%^mages %^BOLD%^and %^RED%^priests %^BLUE%^of Mystra's faith.
Dozens of rows of shelves made of stone line the walls, 
seeming never to end.  On the shelves various %^RESET%^tomes%^BOLD%^%^BLUE%^, %^WHITE%^scrolls%^BLUE%^, 
and %^RED%^sheets of paper %^BLUE%^rest.  Housed in %^WHITE%^rune etched crystal %^BLUE%^display 
cases are various rings, staves, and other odd magical artifacts, 
kept safe by the faith.  A large %^WHITE%^white table %^BLUE%^is set in the center 
of the room surrounded by several stools.  Illuminating the room 
is the illusion of a ring of %^CYAN%^seven tw%^WHITE%^i%^CYAN%^nk%^WHITE%^l%^CYAN%^ing stars %^BLUE%^with a 
%^RED%^red mist %^BLUE%^that flows from the center.  A series of levitating 
platforms lead back up to the main part of the temple. 
CIRCE
        );
        set_items(([
           ({"pillar","pillars"}) : "The pillars have been carved to resemble "+
              "famous priests and mages of Mystran lore.  A wide variety of races, "+
              "from gnome to half-elf, elven, and human fill the halls.  "+
              "The pillars continue on out of sight, seemingly nearly as endless as the "+
              "room itself.  Each pillar is set with a plaque bearing the famed Mystran's name.",
           ({"shelves", "shelf"}) : "The shelves are made of a gray stone and "+
              "have been formed into shelves.  The masonry is of excellent quality "+
              "and done with great detail.  Whoever must made these shelves had "+
              "to have a great deal of time on their hands.",
           "stone" : "The theme of this underground library is a cool gray stone "+
              "as the base with several items made of a lighter polished marble.",
           "floor" : "The stone floor is also a matching cool gray stone like the "+
              "shelves but like the ceiling there are several swirling patterns of "+
              "polished marble.  They could be for decoration or perhaps magical runes.",
           "ceiling" : "Like the floor, the ceiling is also made of a gray stone "+
              "with lighter polished marble patterns.  The ceiling arches slightly "+
              "upward in the middle of the area where the marble table sits the "+
              "most, perhaps up to eight feet.  Between the rows, the ceiling is "+
              "arched slightly as well.  It is less than the center perhaps only "+
              "half a foot higher. Because of the height of ceiling, this area "+
              "looks to not be designed for the taller races but perhaps crafted "+
              "by dwarves or elves.",
           "table" : "The marble table has but one massive pillar that supports it "+
              "in the center.  The stone seems to have grown up out of the ground and "+
              "not been taken down and set here.  Because of this, the table cannot "+
              "be moved.  It is shaped oval and has several stools around it.",
           ({"stool", "stools"}) : "These stools are the unlike the rest of the "+
              "furnishings in this room.  They are not made of stone but rather a "+
              "blackened metal with swirling patterns along the metal of the legs.  "+
              "On top of them is a gray padded place for someone to sit.",
           "trap door" : "A series of floating platforms leads up to a similarly stone trap door.  "+
              "The trap door is fairly large so a giant could make it in here, but "+
              "anyone over six foot wouldn't be comfortable.",
//          "ladder" : "The ladder, like most everything else is made of a gray stone "+
//              "and leads up out of the secret library.",
          ({"platform","platforms"}) : "This series of circular platforms rises "+
                "from the ground and hangs suspended in mid-air, providing the "+
                "only means of entering or leaving the library.",
          ({"paper","tomes","parchment","scrolls","books"}) : "Placed neatly on the "+
              "shelves are countless tomes and scrolls that house much forgotten "+
              "lore.  Many of these are written in the language of spellcasters, and "+
              "some are in scripts long since forgotten by men.",
          ({"symbol","stars","mist","illusion"}) : "Floating in the air is a breath-taking "+
              "illusion of the symbol of %^BOLD%^%^BLUE%^Mystra%^RESET%^.  A circle "+
              "of %^BOLD%^%^CYAN%^seven tw%^WHITE%^i%^CYAN%^nk%^WHITE%^l%^CYAN%^ing "+
              "stars %^RESET%^hangs suspended in the air.  From their center, "+
              "a %^BOLD%^%^RED%^deep red mist %^RESET%^flows, dissipating a few "+
              "feet from its source.  The illusion provides %^YELLOW%^light "+
              "%^RESET%^for the otherwise dark library and reminds all those here "+
              "that the watchful eye of the %^BOLD%^%^BLUE%^Lady of Mysteries "+
              "%^RESET%^is upon you."
       ]));
//       set_exits(([
//          "up" : "/d/magic/temples/mystra"
//       ]));
       set_smell("default","The air carries a magical charge.");
       set_listen("default","You hear the rustling of paper and quiet murmurs in the library.");
//open_exit = 0;
       set_temple("mystra");
}

void init(){
   ::init();
   add_action("close_em","close");
   add_action("open_em","open");
}

void reset() {
   ::reset();
   switch(random(11)){
      case 0:  tell_room(TO,"You have the feeling of being watched.");
               break;
      case 1:  tell_room(TO,"The sound of footsteps resound from another corner of library.");
               break;
      case 2:  tell_room(TO,"You hear a frantic whisper from seemingly right "+
                  "behind you but, turning around, you see nothing there.");
               break;
      case 3:  tell_room(TO,"It sounds like several drops of water just fell nearby.");
               break;
      case 4:  tell_room(TO,"A soft musical laugh of an elf can be heard but the source of it remains a mystery.");
               break;
      case 5:  tell_room(TO,"You feel someone brush up against you but see nothing.");
               break;
      case 6:  tell_room(TO,"A sound of a small metallic object dropping echoes through the area.");
               break;
      case 7:  tell_room(TO,"Several quiet plucks of a harp sing through library.");
               break;
      case 8:  tell_room(TO,"A quiet low sound of a flute can be heard nearby, but where it is coming from is unknown.");
               break;
      case 9:  tell_room(TO,"From seemingly all around you a high-pitched giggle can be heard.");
               break;
      case 10:  tell_room(TO,"The sound of a door closing can be heard nearby.");
               break;
      case 11:  tell_room(TO,"The sound of a door opening can be heard nearby.");
               break;
      default:  break;
   }
}

int close_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to close?");
      return 1;
   }
   if(str == "door" || str == "trap door" || str == "trapdoor"){
      if(member_array("down","/d/magic/temples/mystra"->query_exits()) == -1){
         tell_object(TP,"The trap door is already closed!");
         return 1;
      }
      tell_object(TP,"Standing atop the platforms, you press gently against the base "+
         "of the trap door, and it slides silently shut.");
      tell_room(ETP,""+TPQCN+" stands on the platforms and gently presses against "+
         "the base of the trap door, making it shut.",TP);
      tell_room("/d/magic/temples/mystra","The trap door is closed from below, and "+
         "the attached carpet covers it perfectly.");
      "/d/magic/temples/mystra"->remove_exit("down");
      remove_exit("up");
//      open_exit = 0;
      return 1;
      }
   return 0;
}

int open_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to open?");
      return 1;
   }
   if(str == "door" || str == "trap door" || str == "trapdoor"){
      if(member_array("down","/d/magic/temples/mystra"->query_exits()) == -1){
         tell_object(TP,"Standing atop the platforms, you press gently against the base "+
            "of the trap door, and it slides silently open.");
         tell_room(ETP,""+TPQCN+" stands on the platforms and gently presses against "+
            "the base of the trap door, making it open.",TP);
         tell_room("/d/magic/temples/mystra","The carpet flips up as a trap door is opened from below!");
         "/d/magic/temples/mystra"->add_exit("/d/magic/temples/mystra_hidden","down");
         add_exit("/d/magic/temples/mystra","up");
//         open_exit = 1;
         return 1;
         }
         tell_object(TP,"The trap door is already open!");
         return 1;
   }
   return 0;
}
