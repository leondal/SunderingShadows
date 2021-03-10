//~Circe~ 11/3/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_property("indoors",1);
   set_name("Scribe's Office in Seneca");
   set_short("Scribe's Office in Seneca");
   set_long("%^BOLD%^%^WHITE%^Scribe's Office, Seneca%^RESET%^\n"+
      "%^ORANGE%^This tidy office is filled with the comforts of "+
      "a prosperous town.  A %^RED%^fireplace %^ORANGE%^set within "+
      "the northern wall has been constructed from %^BOLD%^%^GREEN%^"+
      "pale se%^RESET%^%^GREEN%^a%^BOLD%^foa%^WHITE%^m %^GREEN%^gr"+
      "%^RESET%^%^GREEN%^e%^BOLD%^en m%^WHITE%^a%^GREEN%^rble"+
      "%^RESET%^%^ORANGE%^.  The overmantle has been set with "+
      "%^CYAN%^painted tiles %^ORANGE%^depicting a scene of "+
      "a %^BOLD%^scribe %^RESET%^%^ORANGE%^hard at work while "+
      "a %^WHITE%^collection %^ORANGE%^of ancient writing implements "+
      "is displayed on the mantle.  Sitting catty-corner in the "+
      "southeast portion of the room is an exquisite walnut "+
      "%^RED%^desk %^ORANGE%^heavily carved and well-tended.  "+
      "On the southern wall are several %^RED%^bookshelves "+
      "%^ORANGE%^in matching walnut that hold %^RESET%^supplies "+
      "%^ORANGE%^for use by the scribe.  A beautiful %^BOLD%^"+
      "%^CYAN%^crystal chandelier %^RESET%^%^ORANGE%^hangs from "+
      "the center of the ceiling, fitted with %^BOLD%^%^BLUE%^"+
      "magical globes %^RESET%^%^ORANGE%^of %^BOLD%^%^WHITE%^"+
      "light %^RESET%^%^ORANGE%^to safely brighten the office.  "+
      "Facing the desk are a brace of %^GREEN%^padded chairs "+
      "%^ORANGE%^that pick up the %^GREEN%^deeper greens %^ORANGE%^"+
      "of the mantle.%^RESET%^\n");
   set_smell("default","The scent of ink and parchment mingles with "+
      "the fresh fragrance of the ocean.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"fireplace","fire"}) : "The marble fireplace has "+
         "obviously seen little use, likely from the warm climate "+
         "here in Seneca.  However, it is often lit in winter when "+
         "nights can be chilly.",
      ({"marble","mantle"}) : "%^GREEN%^The fireplace is crafted "+
         "from %^BOLD%^%^GREEN%^pale se%^RESET%^%^GREEN%^a%^BOLD%^"+
         "foa%^WHITE%^m %^GREEN%^gr%^RESET%^%^GREEN%^e%^BOLD%^en "+
         "m%^WHITE%^a%^GREEN%^rble %^RESET%^%^GREEN%^.  The "+
         "mantle is decorated with a display of ancient writing "+
         "implements.%^RESET%^",
      ({"implements","display","writing implements","ancient writing implements","collection"}) : "The "+
         "mantle is decorated with several ancient quills, brushes, "+
         "styli, and reed pens.  Each has been arranged to provide "+
         "a pleasing display for customers to study while the scribe "+
         "completes his work.",
      ({"desk","walnut desk"}) : "The walnut desk is varnished and "+
         "heavily carved, covered on the edges and sides with "+
         "swooping scrollwork.  A matching chair is behind the desk, "+
         "providing a comfortable place for the scribe to work.",
      ({"overmantle","scene","tiles","painted tiles"}) : "%^CYAN%^The "+
         "painted tiles show a scene of a scribe working against "+
         "a backdrop of a %^BOLD%^serene sky%^RESET%^%^CYAN%^ through "+
         "an open window.  The scribe is wearing %^ORANGE%^simple robes "+
         "%^CYAN%^rather like a monk's, and he works with a quiet smile "+
         "as clouds roll by.%^RESET%^",
      ({"shelves","bookshelves","supplies"}) : "The walnut bookshelves "+
         "on the southern wall are well-stocked with bottles of ink "+
         "in different colors, quills, parchment, vellum, paper...any- "+
         "and everything a scribe might need in his work.",
      ({"chandelier","globes","globe"}) : "Hanging from the ceiling is "+
         "a %^CYAN%^crystal chandelier %^RESET%^with two tiers.  Rather "+
         "than the typical candles, the beautiful chandelier features "+
         "many small %^BOLD%^%^BLUE%^globes %^RESET%^enchanted to give "+
         "off a pure white light to brighten the room safely.",
      ({"chair","chairs","padded chair","padded chairs"}) : "Two chairs "+
         "facing the walnut desk are padded with %^GREEN%^deep green "+
         "velvet %^RESET%^for the comfort of customers.  Each chair has "+
         "arms and a tall back, hinting that the scribe's work can "+
         "occasionally take time."
   ]));
   set_exits(([
      "west" : ROOMS"skyline41"
   ]));
}

void reset(){
  object ob;
  ::reset();
  if(!present("scribe")){
    ob = new("/d/shadow/mon/scribe");
    ob->set_name("Byron the scribe");
    ob->set_short("Byron, Scribe of Seneca");
    ob->set_id(({"scribe","byron the scribe","seneca scribe","byron","Byron"}));
    ob->set_long("%^RESET%^%^CYAN%^Always dressed in %^RESET%^collared white shirt "+
       "%^CYAN%^under a stylish %^RED%^jacket%^CYAN%^, Byron is a rather "+
       "young scribe who is quite proud of his work.  He has spent all the "+
       "years of his young life developing a steady hand and learning to "+
       "write in all languages known to the realms.  He has short, curly "+
       "%^BOLD%^%^BLACK%^black hair %^RESET%^%^CYAN%^and expressive "+
       "%^ORANGE%^brown eyes%^CYAN%^, and he has been known to compose "+
       "a poem or story of his own.  If you have something that needs "+
       "to be printed, you can ask him to %^WHITE%^<%^CYAN%^write%^WHITE%^> "+
       "%^CYAN%^it for you.  He can also %^WHITE%^<%^CYAN%^draw%^WHITE%^> "+
       "%^CYAN%^a map of Seneca for you, if you feel lost.%^RESET%^");
    ob->move(TO);
  }
}

void init(){
  ::init();
  add_action("buy_map","draw");
}


int buy_map(string str){
  if(!present("scribe")) return notify_fail("Nobody is here to draw you a map.\n");
  if(str != "map" && str != "seneca" && str != "map of seneca") return notify_fail("Draw what?\n");
  if (!TP->query_funds("gold",25)){
      tell_room(TO,"%^MAGENTA%^The scribe says%^RESET%^: You haven't "+
         "the funds to hire me.  It will cost 25 gold for a map.");
      return 1;
  }
  tell_object(TP,"The scribe finishes the map and rolls it carefully before handing it to you.");
  tell_room(TO,"The scribe completes a map and hands it to "+
     ""+TPQCN+".",TP);
  TP->use_funds("gold",25);
  new(OBJ"map")->move(TP);
  return 1;
}