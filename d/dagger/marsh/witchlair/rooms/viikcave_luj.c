#include <std.h>
#include "../witchlair.h"
inherit CROOM;
int searched;

void create() {
   ::create();
  set_property("light",1);
  set_property("no sticks",0);
   set_property("no teleport",0);
   set_property("no starve",0);
   set_property("no magic",0);
   set_property("no steal",0);
   set_name("Viik's lair");
   set_short("%^BOLD%^%^BLACK%^Cr%^RESET%^%^GREEN%^a"
"%^BOLD%^%^BLACK%^mp%^GREEN%^e%^BLACK%^d, da"
"%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^k%^BLUE%^e%^BLACK%^n"
"%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^d cave%^RESET%^");
   set_long((: TO, "long_desc" :) );
   set_smell("default","Smells of garbage and unwashed bodies "
"in here...");
   set_listen("default","All you can hear is the cackling and "
"growling of some unseen...thing!");
   set_items(([
     ({"piles","refuse","garbage"}) : "%^RESET%^%^ORANGE%^Heaps "
"of collected rubbish take up a large portion of the cave. The "
"closest one is made up mostly of boots, all old, most falling"
" apart. You can see a few belts and various packs in several "
"others, and...is that a pile of %^BOLD%^%^WHITE%^teeth "
"%^RESET%^%^ORANGE%^at your feet?",
     "furniture" : "There are a few chairs and a small table, "
"a bed, and you think that might be a tanning rack.",
     ({"chair","chairs","table"}) : "%^RESET%^%^ORANGE%^Set "
"up on a slightly raised section of the floor, the relatively "
"large stone table is covered in all manner of items. If you "
"had the patience, perhaps you could sift through it.",
     "bed" : "It's child-sized! However, you suspect that, "
"given the locale and previous occupant, this was never used "
"by any child.",
     ({"rack","tanning rack"}) : "%^RESET%^%^ORANGE%^Seems "
"that somebody spent quite a bit of time using this. "
"Although the wood frame appears somewhat new, the pegs and "
"spikes are quite worn from use.",
   ]));
   set_exits(([
     "east":ROOMS"path1",
   ]));
   set_search("default","Maybe be a little more specific?");
   set_search("bed",(:TO,"search_garb":));
   set_search("refuse",(:TO,"search_garb":));
   set_search("garbage",(:TO,"search_garb":));
   set_search("piles",(:TO,"search_garb":));
   set_search("table",(:TO,"table_search":));
   searched = 1;
}

string long_desc(){
  string desc = "%^BOLD%^%^BLACK%^A dark lair%^RESET%^\n\n"
"%^BOLD%^%^BLACK%^No small amount of relief washes over you as "
"you step out of the cramped tunnel and into more spacious "
"-and more well lit, thanks to some sparcely scattered "
"%^RESET%^%^ORANGE%^ca%^YELLOW%^n%^WHITE%^d%^YELLOW%^l"
"%^RESET%^%^ORANGE%^es%^BOLD%^%^BLACK%^- area. Piles of "
"%^RESET%^%^ORANGE%^re%^RED%^f%^WHITE%^u%^ORANGE%^se "
"%^BOLD%^%^BLACK%^and assorted makeshift furniture decorate "
"this little cave.";
  if (present("viik", TO)){ //If viik is present, add this line to the description 
    desc += "..but you can worry about all that later. "
"Right now, it would be best to focus on whatever it is that "
"just %^RESET%^%^RED%^attacked you%^BOLD%^%^BLACK%^!";
  }
  return desc;
}

void table_search() {
   if(searched <= 0){
     tell_object(TP,"Doesn't seem to be anything useful "
"in there right now...");
     return 1;
     }
     if (searched == 1) {
       tell_object(TP,"%^BOLD%^%^CYAN%^You find something "
"in the assorted junk that appears serviceable and wrest "
"it from the pile.%^RESET%^");
       tell_room(ETP,"%^RESET%^%^CYAN%^"+TPQCN+" heads to the "
"table and pokes around for a moment, then wrenches "
"something free of the pile of broken equipment.",TP);
         new(OBJ"shaunneck.c")->move(TO);
     searched = 0;
     return;
     }
}

void search_garb(){
   tell_object(TP,"%^RESET%^%^GREEN%^You're sorry you "
"bothered %^BOLD%^%^RED%^-URP- %^RESET%^%^GREEN%^doing "
"that...");
   tell_room(ETO,""+TPQCN+" gags and nearly loses their last"
" meal from digging through the filth.",TP);
}

void reset() {
   ::reset();
  searched = 1;
  if(!present("viik", TO))
  new(MON"viik")->move(TO);
}
