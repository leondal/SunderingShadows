#include <std.h>

inherit LIBRARY;

void create()
{
   ::create();
   set_short("A Library of Half-elven Lore");
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("light",3);
   set_property("indoors",1);
   set_long(
   "This is the Library for Half-elven History and Lore.  Lining the cream"+
   " colored walls are tall finely crafted mahogany bookcases. In the center"+
   " book case, a large blue book catches your eye. It is titled 'The History"+
   " of the Great Half-elves of the Realm.'  In the center of this large room"+
   " there is a large desk and to either side of it a column finely carved to"+
   " represent the two parts that combine to form those who are called"+
   " half-elves.  On the base of each of the columns you see a gold gilded"+
   " plaque. To the east are several smaller tables and chairs where patrons"+
   " may read and study. To the west is a display of artifacts from legendary"+
   " half-elves.  The floor is plushly carpeted.  The ceiling is vaulted and"+
   " over 12 feet high.  Around the ceiling is a band of golden crown moulding."); 
   set_listen("default","Like any library it is quiet.");
   set_smell("default","The scent of parchment and ink fills the room.");
   set_items(([
   "desk" : "This is a large desk made from mahogany. It has an antique look"+
   " about it although it is well polished. You see an assortment of quills,"+
   " parchment, and ink here.",
   "floor" : "%^MAGENTA%^The floor is covered with plush maroon carpeting.%^RESET%^",
   "walls" : "%^YELLOW%^The walls are a soft cream color and lined with"+
   " mahogany book cases.%^RESET%^",
   "ceiling" : "The ceiling is vaulted and painted in an off white shade."+
   " Around the ceiling is a band of %^YELLOW%^golden%^RESET%^ crown moulding.",
   "plaque" : "There are 2 plaques here that you could probably read.",
   ]));
   set_exits(([
   "out" : "/d/dagger/Torm/city/c97",
   ]));

    set_public_library(1);
    set_deposit(50);
    set_library_name("The_Half_Elven_Library_of_Torm");

}

void reset() {
   string scribe;
   ::reset();
   scribe = "/d/player_stores/clerks/gwen_scribe.c";

   if(member_array("office",TO->query_exits()) != -1) {
      remove_exit("office");
   }
   if(!present("scribe")) 
      if(!objectp(environment(find_object_or_load(scribe)))) 	
	find_object_or_load(scribe)->move(TO);
}

void init()
{
   ::init();
   add_action("read","read");
   add_action("pull","pull");
}

void read(string str)
{
   if(str == "plaque") {
      tell_object(TP,"This Library was commissioned and is maintained by"+
      " Gwenhwyfar Lorvell. Its sole benfactor is Girruuth, whose kind"+
      " generosity made this endeavor possible.");
      tell_room(ETP,""+TPQCN+" reads a plaque.",TP);
      return 1;
   }
   if(str == "plaque 2") {
      tell_object(TP,"Welcome to the Library for Half-elven History and Lore."+
      " The purpose of this library is to educate, enlighten, and uplift the"+
      " world about half-elves. To see us not as just half-breeds, but as"+
      " beings with purpose, determination, intelligence, and potential. May"+
      " you find edification within these walls.");
      tell_room(ETP,""+TPQCN+" reads a plaque.",TP);
      return 1;
   }
}

void pull(string str)
{
   if(TP->query_unconscious() || TP->query_bound() || TP->query_paralyzed() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(str != "book from shelf") {
      return 0;
   }
   if(member_array("office",ETP->query_exits()) != -1) {
      tell_object(TP,"You pull the book again but nothing happens.");
      return 1;
   }
   else {
      tell_object(TP,"%^BOLD%^You pull the book away from the shelf and"+
      " suddenly part of the book shelf slides away to reveal a hidden"+
      " passage!");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" pulls a book partially from the shelf"+
      " and one of the book shelves slides aside to reveal a hidden passage!",TP);
      add_exit("/d/dagger/Torm/city/library2","office");
      return 1;
   }
}
