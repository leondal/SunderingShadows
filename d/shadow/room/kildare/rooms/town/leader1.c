//leader1.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;
int FLAG;

void create()
{
   ::create();
   set_short("A large office");
   set_long(
      "A pine door set in the eastern wall opens into this large office.  "+
      "The northwestern portion of the room is dominated by a large fireplace set "+
      "diagonally into the corner, feeding into a curved chimney made of the "+
      "same gray stone of the mountainside.  An intricately carved %^YELLOW%^oaken desk "+
      "%^RESET%^stands parallel to the southern wall, and a %^WHITE%^cream colored "+
      "oval rug %^RESET%^lines the floor in front of it.  Two high-backed "+
      "chairs sheathed with %^BOLD%^%^BLUE%^blue wool covers %^RESET%^stand just "+
      "the other side of the rug, welcoming guests who bring business for the "+
      "town reeve.  The desk is covered with neat piles of papers and a writing "+
      "pad complete with a fantastic %^BOLD%^%^RED%^quill %^RESET%^and "+
      "%^BOLD%^%^BLACK%^bottle of ink%^RESET%^.  The chair behind the desk is "+
      "made with many-spoked wooden wheels and has a %^BOLD%^%^BLUE%^blue cushion "+
      "%^RESET%^that matches the others.  Bookshelves line the walls here, filled "+
      "with various tomes in all shapes and sizes.  There is a long tapestry "+
      "hanging from ceiling to floor along the northern wall."

   );
   set_items(([
      (({"fireplace","fire place","fire","chimney"})) : "The stone fireplace in the "+
         "northwestern corner is built in the form of a tall archway feeding into "+
         "a rounded chimney.  Looking closer, you see that eagles in flight have "+
         "been carved into the archway surrounding the fireplace and darkened "+
         "with ash and soot over time.",
      (({"desk","oaken desk","oak desk"})) : "%^YELLOW%^The massive oak desk in "+
         "the southern portion of the room has been carved with scrollwork and "+
         "polished to a high shine.  The surface is nearly reflective, the result "+
         "of much labor on the part of the one who cleans this room.",
      (({"rug","oval rug","cream rug","cream colored rug"})) : "The oval rug in front "+
         "of the desk is nearly twice as long as it is wide.  Deeper shades of cream, "+
         "almost beige, dot the rug, creating a swirling pattern that is almost "+
         "too subtle to notice.",
      (({"chairs","high-backed chairs"})) : "%^BOLD%^%^BLUE%^The two chairs sitting "+
         "in front of the desk have high backs that would reach well over any sitting "+
         "human's head.  The arms and legs are a highly-polished oak that matches the "+
         "desk and helps brighten the room, while the deep blue brings a somber quality.",
      (({"papers","piles","writing pad","pad"})) : "The bright surface of the desk "+
         "is covered with scattered evidence of the town reeve's active duties.  A "+
         "sheaf of papers is stacked on the right-hand corner, ready for the reeve's "+
         "consideration or approval.  A leather writing pad with an interesting quill "+
         "and ink bottle stand ready for the reeve's use.",
      (({"quill","fantastic quill"})) : "%^BOLD%^%^RED%^The long, elegant quill is "+
         "made of an extraordinary feather that shifts in color from the tip to the "+
         "end.  Near the tip of the quill, the feather is a deep red and moves through "+
         "various oranges and fiery reds to end in a blazing %^YELLOW%^yellow%^RED%^.  "+
         "It seems quite a fine writing implement and is very well-kept.",
      (({"ink","bottle of ink","ink bottle"})) : "%^BOLD%^%^BLACK%^The blackened "+
         "ink bottle is stoppered with a piece of waxed cork.  On the end of the "+
         "cork is a sigil of sorts set in blue wax - a stylized C surrounded by "+
         "five simple birds.",
      (({"chair","wheelchair","wheel chair"})) : "%^ORANGE%^The strange chair standing "+
         "behind the desk is set with spoked wheels that allow it to be moved easily.  "+
         "The deep blue cushion lining the chair is thick enough to provide needed "+
         "comfort for the one who sits on it, and it seems as though the chair has "+
         "seen much use.",
      (({"shelves","bookshelves","tomes","books","shelf","bookshelf"})) : "Tall, sturdy "+
         "bookshelves support hundreds of books in this room.  Either the town reeve "+
         "is quite the collector in his own right, or perhaps this serves as something "+
         "of the village library.  Either way, it seems the collection of Kildare Glen's "+
         "knowledge resides in this room.  The large tomes are kept free of dust and "+
         "many seem quite old.",
      (({"tapestry","long tapestry"})) : "%^BOLD%^%^GREEN%^The tapestry on the northern "+
         "wall is made of natural wool woven into a soft fabric.  Woven throughout the "+
         "light wool are elaborate colors and shapes forming a border much like an illuminated "+
         "manuscript.  Sheep march along the border in between various swirls and geometric "+
         "shapes, all of which form a rectangular housing for the main scene in the "+
         "center of the tapestry.  There, mountains rise high up over a valley "+
         "dominated by a lake.  The sun shines brightly on the lake's surface, causing "+
         "the deep blue water to sparkle and shimmer.  Looking closer, it seems the "+
         "tapestry may hide something behind it."
      ]));

   set_search("tapestry", (: TO, "search_tapestry" :) );
   set_exits(([
      "east" : TROOMS"leader",
      ]));
   set_door("pine door",TROOMS"leader","east",0);
}

void search_tapestry() 
{
   tell_object(TP,"You search the tapestry and find something hidden behind!  "+
      "Maybe you could lift the tapestry?");
   tell_room(ETP,""+TPQCN+" searches behind the tapestry and seems thoughtful.",TP);
}

void reset()
{
        ::reset();
        if(!present("caldon")) {
                new(MON"caldon")->move(TO);
        }
  FLAG = 0;
  remove_exit("north");
  set_exits((["east" : TROOMS"leader"]));
  add_item("tapestry","%^BOLD%^%^GREEN%^The tapestry on the northern wall is made of "+
         "natural wool woven into a soft fabric.  Woven throughout the light wool are "+
         "elaborate colors and shapes forming a border much like an illuminated "+
         "manuscript.  Sheep march along the border in between various swirls and geometric "+
         "shapes, all of which form a rectangular housing for the main scene in the "+
         "center of the tapestry.  There, mountains rise high up over a valley "+
         "dominated by a lake.  The sun shines brightly on the lake's surface, causing "+
         "the deep blue water to sparkle and shimmer.  Looking closer, it seems the "+
         "tapestry may hide something behind it.");
}

void init()
{
   ::init();
   add_action("lift","lift");
   add_action("lower","lower");
}

void lift(string str)
{
   if(str != "tapestry") {
      tell_object(TP,"Lift what?");
      return 1;
   }
   if(FLAG != 0) {
      tell_object(TP,"It is already lifted!");
      return 1;
   }
   tell_object(TP,"You lift the tapestry, revealing a hidden door.");
   tell_room(ETP,""+TPQCN+" lifts the tapestry, revealing a hidden door.",TP);
   add_exit(TROOMS"leader2","north");
   add_item("tapestry","The tapestry in the northern wall has been pushed to "+
      "the side, revealing a hidden door.");
   return 1;
}

void lower(string str)
{
   if(str != "tapestry") {
      tell_object(TP,"Lower what?");
      return 1;
   }
   if(member_array("north",ETP->query_exits()) != -1) {
      tell_object(TP,"You lower the tapestry, hiding the door once again.");
      tell_room(ETP,""+TPQCN+" lowers the tapestry, hiding the door once more.",TP);
  add_item("tapestry","%^BOLD%^%^GREEN%^The tapestry on the northern wall is made of "+
         "natural wool woven into a soft fabric.  Woven throughout the light wool are "+
         "elaborate colors and shapes forming a border much like an illuminated "+
         "manuscript.  Sheep march along the border in between various swirls and geometric "+
         "shapes, all of which form a rectangular housing for the main scene in the "+
         "center of the tapestry.  There, mountains rise high up over a valley "+
         "dominated by a lake.  The sun shines brightly on the lake's surface, causing "+
         "the deep blue water to sparkle and shimmer.  Looking closer, it seems the "+
         "tapestry may hide something behind it.");
      remove_exit("north");
      return 1;
   }
   else {
      tell_object(TP,"What exactly are you trying to lower??");
      return 1;
   }
}
