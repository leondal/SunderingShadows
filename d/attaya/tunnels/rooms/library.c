//library.c - Library of stefano's tower.  Coded by Circe 10/5/03
//Messed around with by Lujke 10/05/05
#include <std.h>
//#include "/d/player_houses/stefano/stefano.h"
#include "../tunnel.h"
#include <daemons.h>

inherit VAULT;

#define SCRY_D "/daemon/ic_scry_locate_d"
object blocker;

#define POWNERS ({ "gaius" }) //controls access to most secure parts of the house
#define PGUESTS ({ "nymeria", "testlackey" }) //controls access to the house in general



int books_touched;
int open_exit;
string set_long();

void create() {
  // variable deliberately set before ::create, to help ensure guardians
  // load on first creation. Variable is reset to 0 during the reset
  // function ~ Lujke
        books_touched=5;
        ::create();

        set_property("indoors",1);
        set_property("light",4);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A brightly lit library");
        set_short("A brightly lit library");
        set_long( (:TO,"long_desc":)); 
        set_smell("default","The musty scent of old books lingers in the"
                           +" air.");
        set_listen("default","You can hear the sound of your own"
                            +" breathing");
        set_items(([
           ({"lantern", "lanterns"}) : "Despite their%^BOLD%^%^WHITE%^"
                 +" bright glow%^RESET%^, you cannot make out any sign of"
                 +" a flame within the lanterns, and you have to assume"
                 +" they are lit by magical means - probably not a bad"
                 +" idea in a room full of wood and paper.",
           ({"wall", "walls"}) : "The walls are made of %^BOLD%^"
                 +"%^BLACK%^dark grey slate%^RESET%^, which is very"
                 +" smooth and shines slightly in the light of the"
                 +" lanterns."+
                 "\nThere is a small notice pinned discreetly to one of"
                 +" the walls",
		"desks" : "The desks have comfortable chairs beside them, and"
                +" enough space to rest a book, or perhaps make a few"
                +" notes while reading.",
            "notice" : "Do not touch the books. They don't like it, and"
                +" some of them bite. Stefano.\n\nden vershz garhleng"
                +" vashud durghzd. Vahor den vershz gruk glt unz klex"
                +" flsh vahux klurrng. Storrlzzorg",
		({"filing cabinets","cabinets"}) : "The filing cabinets are"
                +" made of metal. They are locked.",
		"bookcases" : "The bookcases are carved from%^YELLOW%^"
                +"polished walnut%^RESET%^ and display the books"
                +" elegantly. They appear to be full without being"
                +" cramped, and there is plenty of room in the library"
                +" for additional cases to be brought in if more space is"
                +" needed.",
		"books" : "The books in the collection are quite varied. Many"
                +" are old, and quite a few have covers made from strange"
                +" skins, or metal bindings. They are carefully arranged"
                +"and indexed, but some of the collection seem to have"
                +" been given extra spaces all of their own. All the"
                +" books, as far as you can see, relate to the study of"
                +" magic and the workings of the weave. There is a"
                +" noticeably large section on summoning.",
		"summoning" : "The books on summoning are displayed near the"
               +" east wall, and take up a whole bookcase on their own.",
		"east wall" : "The east wall is made of %^BOLD%^%^BLACK%^dark"
              +" grey slate%^RESET%^ like the rest, and has a few"
              +" handprints on it.",
		"handprints" : "The handprints mostly cluster around a"
             +" particular point on the wall.",
            ({"summoning","section"}) : "The section on summoning is"
              +" quite extensive. You could probably try to examine the"
              +" books if you wanted."
        ]));
        set_search("default", (: TO, "search_em" :));
        set_search("ceiling", (: TO, "search_ceiling" :));
        set_search("walls","You find a few handprints on the east wall.");
        set_search("wall","You find a few handprints on the east wall.");
        set_search("filing cabinets","How can you search the cabinets?"
                                    +"  They're locked.");
        set_search("cabinets","How can you search the cabinets?  They're"
                                   +" locked.");
        set_search("desks","You find nothing in the desks, not even a"
                          +" speck of dust.");
        set_search("reading desks","You find nothing in the desks, not"
                  +" even a speck of dust.");
        set_search("books",(: TO, "search_shelves" :));
        set_search("shelves",(: TO, "search_shelves" :));
        set_search("bookshelves", (: TO, "search_shelves" :));
        set_search("summoning", (: TO, "search_sum" :));
        set_search("summoning section", (: TO, "search_sum" :));
        set_search("section", (: TO, "search_sum" :));
        set_post_exit_functions(({"east"}),({"go_east"}));

open_exit = 0;
//        set_exits(([
//           "up" : "/d/player_houses/stefano/cog_room", 
//   ])); //changing to a function.  Circe 1/2/04
}

int go_east(){
   object other_room;
   if (!objectp(TP)||!objectp(TO)){return 0;}
   other_room = find_object_or_load(TUNNELS+"summoning");
   tell_object(TP,"As you move through the secret door, it slides shut"
                 +" behind you, hiding the exit.");
   if (!TP->query_true_invs()){
     tell_room(TO,"As "+TPQCN+" moves through the secret door, it closes"
                  +" behind "+TP->query_objective()+".",TP);
     tell_room(ETP,""+TPQCN+" arrives"+" through a secret door in the"
                  +" west wall, which slides closed behind " 
                  +TP->query_objective()+".",TP);
     other_room->remember_door();
     TP->set_property("remember_door",1);
     if(query_exit("east")) remove_exit("east");
     if(other_room->query_exit("west")){other_room->remove_exit("west");}
     other_room->add_item("door","You look at the wall, but you can't"
                         +" seem to remember where the door was.");
   }
   return 1;
}

string long_desc(){ 
         return   "The %^YELLOW%^lanterns %^RESET%^hanging around the "
                 +"walls and ceiling blaze brightly, and every corner of"
                 +" the room is well illuminated, despite being below"
                 +" ground level.  A number of elegantly carved"
                 +" %^ORANGE%^wooden bookcases %^RESET%^display their"
                 +" contents to good effect. There are a couple of"
                 +" %^BLUE%^reading desks%^RESET%^, and some"
                 +" %^YELLOW%^filing cabinets %^RESET%^as well.  The soft"
                 +" %^GREEN%^green carpet %^RESET%^muffles your footsteps"
                 +" and the air of quiet is almost eerie. The ceiling is"
                 +" thick enough to completely cut out the sounds from"
                 +" the room above. The walls are plain, appearing to be"
                 +" made of %^BOLD%^%^BLACK%^smooth dark slate%^RESET%^,"
                 +"as is the ceiling.  There is a small %^ORANGE%^notice"
                 +" %^RESET%^on one of the walls.\n";
}
 
void reset() {
   ::reset();   // looking for the guards file and noticed this was missing ::reset *Styx* 5/21/06
   if(present("unseen guardian") || (random (3)==0) && books_touched<5){
     books_touched = 0;
     return;
   }
   new("/d/player_houses/mons/guardian")->move(TO);
   new("/d/player_houses/mons/guardian")->move(TO);

   if (books_touched == 5)
   {
     books_touched = 0;
   }
   if (random (5)<4)
   {
     books_touched = 0;
   }
   if(!present("blockerx111")){
      blocker = SCRY_D->add_block_scrying(TO);
      if(!objectp(blocker)) {
         tell_room(TO,"Something has gone wrong with "
            "the scry protection! Please tell Circe.");
         return;
      }
      blocker->set_block_power(70);
   }
}

void init(){
   ::init();

   add_action("push_em","push");
   add_action("push_em","press");
   add_action("push_em","touch");
   add_action("close_em","close");
   add_action("pull_em","pull");
   add_action("examine_books", "examine");
   add_action("examine_books", "read");
   add_action("examine_books", "touch");
   add_action("examine_books", "get");
   add_action("examine_books", "take");
   add_action("examine_books", "grab");
   add_action("examine_books", "explore");
   add_action("examine_books", "approach");
}

int push_em(string str){
  object mob, mob2, other_room;
  int okay;
  string mname;
  if (!objectp(TO)||!objectp(TP)){return 0;}
  mname  = TP->query_name();
  mob = present("unseen guardian",TO);
  mob2 = present("unseen guardian 2",TO);
  other_room = find_object_or_load(TUNNELS+"summoning");
  if (!objectp(other_room)){
    tell_object(TP,"ERROR - please tell a WIZ that the next room failed"
                  +" to load.");
  }
  if(!str){
    tell_object(TP,"What are you trying to push?");
    return 1;
  }
   if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1){
      okay = 1;
   }
  if(str == "east wall"){
//    if(mname != "stefano"){
   if(!okay){
      if(objectp(mob)||objectp(mob2)){
        tell_object(TP,"You push against the east wall and hear a"
                      +" rustling sound behind you.");
        tell_room(ETP,""+TPQCN+" pushes against the east wall and you"
                     +" hear a rustling sound.",TP);
        if(objectp(mob)){
          mob->force_me("stab "+TPQN+"");
        }
        if(objectp(mob2)){
          mob2->force_me("stab "+TPQN+"");
        }
        return 1;
      }
    }
    tell_object(TP,"You push against the east wall but nothing happens.");
    tell_room(ETP,""+TPQCN+" pushes against the east wall.",TP);
    return 1;
  }
  if(str == "handprint" || str == "handprints"){
//    if(!TO->query_property("activated") || mname == "stefano" || wizardp(TP)){
     if(!TO->query_property("activated") && !okay){
      if(mob||mob2) {
        tell_object(TP,"You push against the handprint on the east wall"
                    +" and hear a rustling sound behind you before"
                    +" anything happens.");
        tell_room(ETP,""+TPQCN+" pushes against the handprint on the"
                     +" east wall and you hear a rustling sound.",TP);
        if (mob){ mob->force_me("stab "+TPQN+"");}
        if(mob2) { 
          mob2->force_me("stab "+TPQN+"");
        }
      return 1;
      }
    }
    if(member_array("east",query_exits()) == -1){
      tell_object(TP,"You put your hand against the largest of the"
                    +" handprints on the east wall and push. There"
                    +" is a moment's resistance, and then a secret"
                    +" door swings open before you.");
      tell_room(ETP,""+TPQCN+" puts "+TP->query_possessive()+" hand"
                   +" against the largest handprint on the east wall"
                   +" and pushes, opening a secret door.",TP);
      other_room->add_exit(TUNNELS + "library","west");
      add_exit(TUNNELS + "summoning","east");
      return 1;
    }
    tell_object(TP,"The secret door is already open!");
    return 1;
  }
  return 0;
}

int close_em(string str){
  object other_room;
  if (!objectp(TP)||!objectp(TO)){return 0;}
  if(!str){
    tell_object(TP,"What are you trying to close?");
    return 1;
 }
 if(str == "door"){
   other_room = find_object_or_load(TUNNELS+"summoning");
   if(member_array("west", other_room->query_exits())== -1){
     tell_object(TP,"The secret door is already closed!");
     return 1;
   }
   tell_object(TP,"You press your hand against the largest"
                 +" handprint in the east wall and push.  After a"
                 +" moment's pause, the secret door swings shut.");
   tell_room(ETP,""+TPQCN+" puts "+TP->query_possessive()+" hand"
                +" against the largest handprint on the east wall"
                +" and pushes, closing a secret door.",TP);
   other_room->remove_exit("west");
   remove_exit("east");
   return 1;
 }
 if(str == "slab" || str == "up") {
   other_room = find_object_or_load("/d/player_houses/stefano/cog_room");
   if(member_array("down", other_room->query_exits()) == -1){
      tell_object(TP,"The slab is already closed!");
      return 1;
    }
    tell_object(TP,"You pull a lever disguised as a book and the"
                 +" slab swings quietly shut.");
    tell_room(ETP,""+TPQCN+" runs "+TP->query_possessive()+" fingers"
                 +" along a row of books.\nThe slab above swings"
                 +" silently closed.",TP);
    other_room->remove_exit("down");
    remove_exit("up");
    open_exit = 0;
    return 1;
  }
  return 0;
}

int pull_em(string str){
  object other_room;
  if (!objectp(TP)||!objectp(TO)){return 0;}
  other_room = find_object_or_load("/d/player_houses/stefano/cog_room");
  if(!str||(str != "lever" && str != "book")){
    tell_object(TP,"What are you trying to pull?");
    return 1;
 }
 else{
   if(open_exit){
     tell_object(TP,"You pull on the book but nothing happens!");
     return 1;
   }
   tell_object(TP,"You pull on the book-shaped lever and the slab"
                 +" in the ceiling swings down, revealing an exit up.");
   tell_room(ETP,""+TPQCN+" runs "+TP->query_possessive()+" fingers"
                +" along a row of books.\nThe slab above swings silently"
                +" open.",TP);
         add_exit("/d/player_houses/stefano/cog_room","up");
         other_room->add_exit(TUNNELS + "library","down");
         tell_room("/d/player_houses/stefano/cog_room","A slab in the"
                  +" floor slides down, revealing an exit!");
         open_exit = 1;
         return 1;
   }
   tell_object(TP,"You can't pull that!");
   return 1;
}

void search_em(){
   switch(random(5)){
   case 0:  tell_object(TP,"Looking more closely around the room, you"
                          +" realize that the east wall looks a little"
                          +" different from the others.");
            break;
   case 1:  tell_object(TP,"There seems to be something strange about the"
                          +" ceiling.");
            break;
   case 2:  tell_object(TP,"With so many books on the shelves, you wonder"
                          +" if they couldn't be hiding something.");
            break;
   case 3:  tell_object(TP,"The desks look plain enough, but you never"
                          +" know...they could hold something.");
            break;
   case 4:  tell_object(TP,"The filing cabinets certainly look"
                          +" interesting.");
            break;
  }
  tell_room(ETP,""+TPQCN+" looks carefully around the room, checking"
               +" various things.",TP);
  return;
}

void search_ceiling(){
   tell_object(TP,"You notice that there is one slab in the ceiling which"
                 +"is different to the others. It looks like it could be"
                 +" opened.");
   tell_room(ETP,""+TPQCN+" stares at the ceiling.",TP);
   add_item("ceiling","One slab in the ceiling looks different from the"
                     +" others.  It could perhaps be opened, if you could"
                     +" find the means.");
   add_item("slab","One slab in the ceiling looks different from the"
                  +" others.  It could perhaps be opened, if you could"
                  +" find the means.");
   return;
}

void search_shelves(){
   tell_object(TP,"Taking the time to carefully look over the bookshelves"
                 +", you notice that one book seems strange.");
   tell_room(ETP,""+TPQCN+" peers intently at the bookshelves.",TP);
   set_search("book","It doesn't seem to be a book at all!  It looks like"
                    +" some kind of lever you might be able to pull.");
   return;
}

void search_sum(){
   tell_object(TP,"The books in the summoning section look interesting. As you get closer, you think you can hear the sound of"
                  +"rustling, though there is no breeze in the room. Maybe some of the summoning books would be work reading?");
   tell_room(ETP,""+TPQCN+" wanders across for a closer look at the summoning section of the bookshelves.",TP);
   return;
}
int examine_books(string str)
{
  object * ob;
  int i, num;
  if (str!="books" && str!="summoning" && str!="section" 
   && str!="the books" && str != "summoning section" 
   && str!="summoning books" && str != "summoning book" )
  {
    return 0;
  }
  if (books_touched == 1)
  {
  tell_object(TP, "The books on these shelves appear to have been"
                 +" disturbed");
    return 0;
  }
  tell_object(TP, "As you reach for one of the books on the summoning"
                 +" shelves, there is a sudden %^BOLD%^%^CYAN%^flurry"
                 +"%^RESET%^ of activity as several books jump from the"
                 +" shelves and attack!");
  tell_room(TO, "As " + TPQCN + " reaches for one of the books on the"
               +" summoning shelves, there is a sudden %^BOLD%^"
               +"%^CYAN%^flurry%^RESET%^ of activity as several books"
               +" jump from the shelves and attack!",TP);
  num = 2 + random(3)+ random (2);
  for (i = 0;i<num;i++)
  {
    ob = new(MOB + "book");
    ob->move(TO);
    ob->kill_ob(TP,1);
  }
  books_touched = 1;
  return 1;
}
