#include <std.h>
#include "../dragon.h";

inherit BPRISON;

void create() {
   ::create();
   set_short("%^BOLD%^%^YELLOW%^Warden's office%^RESET%^");
   set_long(
      "%^RESET%^%^CYAN%^This room is a small office that was once the warden's office."+
      " However, it has not fallen to neglect as the rest of the prison."+
      " The %^YELLOW%^lit lanterns%^RESET%^%^CYAN%^ on the walls are signs of recent use and the room"+
      " is kept tidy. There is a small %^ORANGE%^desk%^RESET%^%^CYAN%^ in the center with several papers"+
      " resting on the table top. There is a large %^MAGENTA%^soft chair%^RESET%^%^CYAN%^ pulled up to the"+
      " desk and two different %^ORANGE%^bookshelves%^RESET%^%^CYAN%^ framing the room from opposite walls."+
      " One bookshelf is on the south wall and the other on the"+
      " east wall. To the right of the bookshelf on the southern wall is a portal."+
      " On the north side of the room, there is a hallway connecting this office"+
      " to another structure."
   );
   set_items( ([
      "lanterns" : "There are lanterns on the wall keeping the room lit. One of them looks oddly bent, as if someone had tried to %^BOLD%^pull%^RESET%^ it.",
      "desk" : "This is an average desk with drawers. There are some papers on the desk, none of them look important at first glance.",
      "papers" : "There is a large stack of papers on the desk, none of them look important at first glance.",
      "chair" : "This is just a large soft chair.",
      "bookshelf" : "Which one do you want to look at? East or South?",
      "south bookshelf" : "This is a collection of books covering the different seperations of magic.",
      "east bookshelf" : "This is a collection of personal pleasure readings.",
      "portal" : "This is a magical portal that remains stable and open.",
   ]) );
   set_search("lanterns", "You think the lantern is a hidden lever that you can pull down.");
   set_exits( ([
      "portal" : TOWER+"prison05",
      "hallway" : TOWER+"stairs",
   ]) );
   set_pre_exit_functions(({"hallway"}),({"GoThroughDoor"}));
}

void init() {
   ::init();
   add_action("pull_lantern","pull");
}

int pull_lantern(string str) {
object ob;
   if(!str) {
      write("What do you want to pull?");
      return 1;
   }
   if(str == "lantern") {
      tell_room(ETP,""+TPQCN+" pulls a lantern and something is heard traveling down a chute in the walls. But to where?",TP);
      tell_object(TP,"You pull the lantern and something is heard traveling down a chute in the walls. But to where?");
      ob = find_object_or_load(TOWER+"bottom28");
      new(OBJ+"greenstone")->move(ob);
      return 1;

   }
}
int GoThroughDoor() {
    object obj,stone;
    if(obj=present("green stone",TP)){
            write("You pass through the invisible barrier guarding the way north.");
            return 1;
        }else{
           write("You can't seem to break the invisible barrier shielding the way north.");
            return 0;
      }
}
