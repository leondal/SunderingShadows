#include "/d/dagger/aketon/short.h"

int STATUE, GARGOYLES, SEARCHED;

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very large room with a high vaulted ceiling. It is shaped"+
   " like a large hexagon instead of being squre as most rooms are."+
   " In the center of the room is a large gray marble pedestal with"+
   " a black marble basin full of water sitting upon it. On the north"+
   " side of the room is a table filled with alchemy equipment, with"+
   " a potion or two still brewing. There are bookshelves along the"+
   " south wall of the room, but they appear to be guarded by a large"+
   " terra cotta statue of an elven warrior. Since this is"+
   " obviously the house of a powerful mage, it is probably safe to"+
   " assume the books are carefully guarded and the statue is probably"+
   " a guardian of some kind. There is an ebony door to the west with"+
   " two granite pedestals on either side of it, statues of gargoyles"+
   " are sitting on top of the pedestals.");
   set_smell("default","Some chemicals give off a sulfiric odor.");
   set_listen("default","The silence here is absolute.");
   set_items(([
   ({"pedestal","marble pedestal","gray marble pedestal"}) : "There is"+
   " a gray marble pedestal in the very center of the room with a large"+
   " basin made of black marble and filled with water resting atop it.",
   ({"basin","marble basin","black marble basin"}) : "The basin is made"+
   " of black marble and has been filled with water. Looking into it it"+
   " appears almost depthless and the images it reflects are perfect."+
   " Such a device is often used in ancient forms of scrying.",
   "table" : "There is a table filled with alchemy equipment off to one"+
   " side of the room.",
   "bookshelves" : "There are several large bookshelves filled with"+
   " various magical tomes. You might be able to search and find something"+
   " there, but the mage has undoubtedly laid out traps.",
   "statue" : "The terra cotta statue is that of an elven warrior wielding"+
   " two large hammers. The detail is exquisite, and the warrior appears"+
   " to be guarding the bookshelves. The statue is probably not just for"+
   " decoration, and caution might be well advised.",
   "ebony door" : "The ebony door leads to the next room.",
   "pedestals" : "There are two granite pedestals on either side of the"+
   " ebony door. A gargoyle sits atop each one.",
   "gargoyles" : "The gargoyles are made of stone and look like they"+
   " would be rather fierce opponents if they were real. There is one"+
   " on either side of the doorway.",
   ]));
   set_search("bookshelves",(:TO,"search_books":));
   set_door("door",RPATH3+"3two1","northeast","aketon key");
   set_door("ebony door",RPATH3+"3two12","west",0);
   set_locked("door",1);
   set_exits( (["northeast":RPATH3+"3two1",
      "west":RPATH3+"3two12"]) );
   set_pre_exit_functions(({"west"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   if(STATUE == 1) {
      STATUE = 0;
      add_item("statue","The terra cotta statue is that of an elven"+
      " warrior wielding two large hammers. The detail is exquisite, and"+
      " the warrior appears to be guarding the bookshelves. The statue is"+
      " probably not just for decoration, and caution might be well"+
      " advised.");
   }
   if(GARGOYLES == 1) {
      add_item("gargoyles","The gargoyles are made of stone and look like"+
      " they would be rather fierce opponents if they were real. There is"+
      " one on either side of the doorway.");
      add_item("pedestals","There are two granite pedestals on either"+
      " side of the ebony door. A gargoyle sits atop each one.");
   }
   GARGOYLES = 0;
   SEARCHED = 0;
}

int GoThroughDoor()
{
   if(query_verb() != "west") return ::GoThroughDoor();
   if(query_locked("ebony door")) {
      tell_object(TP,"The ebony door is locked.");
      return 0;
   }
   if(query_open("ebony door") == 0) {
      tell_object(TP,"You bump into the closed ebony door.");
      tell_room(ETP,""+TPQCN+" bumps into the closed ebony door.",TP);
      return 0;
   }
   if(present("gargoyle")) {
      tell_object(TP,"The gargoyle will not let you through!");
      return 0;
   }
   if(GARGOYLES != 1) {
      tell_object(TP,"As you try to walk through the doorway the gargoyles"+
      " spring to life!");
      tell_room(ETP,"As "+TPQCN+" begins to walk through the doorway the"+
      " gargoyles spring to life!",TP);
      GARGOYLES = 1;
      new(MPATH+"gargoyle")->move(TO);
      new(MPATH+"gargoyle")->move(TO);
      remove_item("gargoyles");
      add_item("pedestals","There are two granite pedestals on either"+
      " side of the ebony door. It looks as though something once set"+
      " atop them, but there is nothing there now.");
      if(STATUE != 1) {
         set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very large room with a high vaulted ceiling. It is shaped"+
   " like a large hexagon instead of being squre as most rooms are."+
   " In the center of the room is a large gray marble pedestal with"+
   " a black marble basin full of water sitting upon it. On the north"+
   " side of the room is a table filled with alchemy equipment, with"+
   " a potion or two still brewing. There are bookshelves along the"+
   " south wall of the room, but they appear to be guarded by a large"+
   " terra cotta statue of an elven warrior. Since this is"+
   " obviously the house of a powerful mage, it is probably safe to"+
   " assume the books are carefully guarded and the statue is probably"+
   " a guardian of some kind. There is an ebony door to the west with"+
   " two granite pedestals on either side of it that are strangely empty.");
      }
      else {
         set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very large room with a high vaulted ceiling. It is shaped"+
   " like a large hexagon instead of being squre as most rooms are."+
   " In the center of the room is a large gray marble pedestal with"+
   " a black marble basin full of water sitting upon it. On the north"+
   " side of the room is a table filled with alchemy equipment, with"+
   " a potion or two still brewing. There are bookshelves along the"+
   " south wall of the room. There is an ebony door to the west with"+
   " two granite pedestals on either side of it that are strangely empty.");
      }
      return 0;
   }
   return 1;
}

int search_books()
{
   object obj;

   if(present("clay golem")) {
      tell_object(TP,"The clay golem isn't going to let you search the bookshelves.");
      return 1;
   }
   if(STATUE != 1) {
      tell_object(TP,"As you move towards the bookshelves the terra"+
      " cotta statue comes to life!");
      tell_room(ETP,"As "+TPQCN+" moves towards the bookshelves the"+
      " terra cotta statue comes to life!",TP);
      new(MPATH+"cgolem")->move(TO);
      STATUE = 1;
      if(GARGOYLES != 1) {
         set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very large room with a high vaulted ceiling. It is shaped"+
   " like a large hexagon instead of being squre as most rooms are."+
   " In the center of the room is a large gray marble pedestal with"+
   " a black marble basin full of water sitting upon it. On the north"+
   " side of the room is a table filled with alchemy equipment, with"+
   " a potion or two still brewing. There are bookshelves along the"+
   " south wall of the room. There is an ebony door to the west with"+
   " two granite pedestals on either side of it, statues of gargoyles"+
   " are sitting on top of the pedestals.");
      }
      else {
         set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very large room with a high vaulted ceiling. It is shaped"+
   " like a large hexagon instead of being squre as most rooms are."+
   " In the center of the room is a large gray marble pedestal with"+
   " a black marble basin full of water sitting upon it. On the north"+
   " side of the room is a table filled with alchemy equipment, with"+
   " a potion or two still brewing. There are bookshelves along the"+
   " south wall of the room. There is an ebony door to the west with"+
   " two granite pedestals on either side of it that are strangely empty.");
      }
      remove_item("statue");
      return 1;
   }
   if(SEARCHED == 1) {
      tell_object(TP,"You search the bookshelves but find nothing, all"+
      " the good stuff has already been taken.");
      tell_room(ETP,""+TPQCN+" searches the bookshelves but finds nothing.",TP);
      return 1;
   }
   SEARCHED = 1;
   tell_object(TP,"You search the bookshelves and find a few scrolls.");
   tell_room(ETP,""+TPQCN+" searches the bookshelves and finds something.",TP);
   switch(random(3)) {
      case 0:
         obj = new("/d/magic/scroll");
         obj->set_spell(random(4)+3);
         obj->move(TO);
         obj = new("/d/magic/scroll");
         obj->set_spell(random(3)+4);
         obj->move(TO);
         break;
      case 1:
         obj = new("/d/magic/scroll");
         obj->set_spell(random(4)+5);
         obj->move(TO);
         obj = new("/d/magic/scroll");
         obj->set_spell(random(4)+5);
         obj->move(TO);
         break;
      case 2:
         obj = new("/d/magic/scroll");
         obj->set_spell(random(3)+7);
         obj->move(TO);
         obj = new("/d/magic/scroll");
         obj->set_spell(random(4)+3);
         obj->move(TO);
         break;
   }
   return 1;
}
