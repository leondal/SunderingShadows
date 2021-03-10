//updated by ~Circe~ 7/21/19 to remove temple functions and change description
#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
//   set_temple("oghma");
   set_name("A Gathering Hall");
   set_short("A Gathering Hall");
   set_long("%^BOLD%^%^WHITE%^This %^RESET%^grey stone%^BOLD%^%^WHITE%^ "
      "building houses a well-stocked library arranged in %^RESET%^%^ORANGE%^"
      "bookshelves%^BOLD%^%^WHITE%^ along the walls. The center of the space "
      "is dominated by %^RESET%^%^GREEN%^couches %^BOLD%^%^WHITE%^and "
      "%^RESET%^%^MAGENTA%^armchairs%^BOLD%^%^WHITE%^, while one corner of "
      "the room has a small raised %^RESET%^%^ORANGE%^stage%^BOLD%^%^WHITE%^ "
      "for both practice and performance. Sages come here to read more from the wealth of "
      "information housed here, while scribes work hard to copy the "
      "texts. Entertainers mill about playing a variety of songs and "
      "melodies for all within this large structure. Large, pale rectangles "
      "of stone on the walls indicate that something must have once hung there, "
      "and a threadbare %^YELLOW%^gold velvet %^WHITE%^rug leads to a "
      "%^RESET%^%^ORANGE%^wooden table %^BOLD%^%^WHITE%^surrounded by "
      "matching %^RESET%^%^ORANGE%^benches%^BOLD%^%^WHITE%^. Decorative elements "
      "throughout the room hint that it once had a much grander purpose than "
      "it now serves.%^RESET%^\n");
   set_items(([
      ({"library","books","bookshelves"}) : "While the official library of Tabor "
         "is just across the street, this building houses an impressive collection "
         "of books, both old and new. Wooden bookshelves line the walls, some more "
         "recently constructed than others. The books have been arranged by subject, "
         "and scribes often volunteer their time to make copies for distribution or preservation.",
      ({"couch","couches","armchair","armchairs","chair"}) : "Plush couches and "
         "armchairs are arranged in a circle around a woven rug in the center of "
         "the room. They are often occupied by various individuals reading, drawing, or talking.",
      "stage" : "The wooden stage in the corner of the room seems newer than "
         "the other furnishings. Several stools are placed along the wall behind it, "
         "and a trunk to the side holds props and instruments for anyone to use.",
      ({"table","benches","bench"}) : "The long wooden table has been polished to a "
         "high shine. It has some knicks and scratches along with a few burn marks, "
         "but it is otherwise in good shape. A bench lines each side, providing space "
         "for many people to sit around the table at once.",
      ({"rug","velvet rug"}) : "The velvet of the threadbare rug has been crushed under "
         "many feet. Looking closer, you see that embroidery has been picked out and "
         "some gems removed. The missing embroider seems to have been vaguely scroll-shaped."
   ]));
   set_exits(([
      "east" : "/d/darkwood/tabor/room/math4"
   ]));
   set_smell("default","The smell of wet ink is heavy in the air.");
   set_listen("default","Among the various discussions you can hear a variety of different melodies being played.");
}

void init(){
   ::init();
//   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
"%^BOLD%^Oghma charges his followers with this message:%^RESET%^\n\n"+
"%^YELLOW%^"+
"Knowledge, particularly the raw knowledge of ideas, "+
"is supreme. An idea has no weight, but it can move "+
"mountains. The greatest gift of humankind, an idea "+
"outweighs anything made by mortal hands. Knowledge "+
"is power and must be used with care, but hiding it "+
"away from others is never a good thing. Stifle no "+
"new ideas, no matter how false or crazed they seem, "+
"rather, let them be heard and considered.  Never slay "+
"a singer, nor stand by as others do so. Spread knowledge "+
"wherever it is prudent to do so. Curb and deny falsehoods, "+
"rumors, and deceitful tales whenever you encounter them. "+
"Write or copy lore of great value at least once a year "+
"and give it away. Sponsor and teach bards, scribes and "+
"record keepers. Spread truth and knowledge so that all "+
"folk know more. Never deliver a message falsely or "+
"incompletely. Teach reading and writing to those who "+
"ask, if time permits, and charge no fee."+
"   Above all else, let knowledge flow, let the songs sing out, and you"+
" will know the Binder."
   );
   if((string)TP->query_diety() == "oghma" || avatarp(TP))
   write(
@EXTRA
============================================================================
%^BOLD%^As a follower of Oghma ...
%^RED%^  Allied deities are: %^RESET%^Mystra, Lathander, Sune, Auppenser, Grumbar
%^RED%^  enemy deities are: %^RESET%^Mask, Bane, Cyric, Talos, Malar

%^BOLD%^This is information only followers of Oghma should know.
EXTRA
   );
   return 1;
}
