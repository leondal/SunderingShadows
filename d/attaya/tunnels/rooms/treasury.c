//Coded by Lujke//
#include <std.h>
#include "../tunnel.h"
#define DAY 24000
#define TREASURY_D "/daemon/treasury_d.c"
#define MUSICALS ({"harmonica",\
"banjolele",\
"drum",\
"lap-harp",\
"hautbois",\
"fiddle",\
"lute",\
"bongodrums",\
"panpipes",\
"shawm",\
"tabor",\
"instrument_case",\
"clavichord",\
"drum"})

inherit VAULT;

// last_hoard tracks the time the last hoard was added to the room. The
// hoard is not replaced more than once per SG day, other than at reboots.

int piles_searched;
int chests_searched;
int cabinets_searched;

int last_hoard;
void make_hoard();
int decipher_rune(string str);

void create(){
  ::create();
  set_name("A glittering treasure trove");
  set_short("%^BOLD%^%^YELLOW%^A gl%^WHITE%^i%^YELLOW%^tter%^WHITE%^i"
           +"%^YELLOW%^ng tr%^RESET%^%^ORANGE%^ea%^YELLOW%^s%^RESET%^"
           +"%^ORANGE%^u%^YELLOW%^re tr%^RESET%^%^ORANGE%^o%^YELLOW%^ve");

  set_long((:TO, "long_desc":) );

  set_items( ([

({ "cabinet", "cabinets"}): "%^RED%^Several tall, redwood cased cabinets"
                           +" stand around the room, each of them fronted"
                           +" with %^BOLD%^%^WHITE%^cr%^CYAN%^y%^WHITE%^"
                           +"st%^CYAN%^a%^WHITE%^l %^CYAN%^gl%^WHITE%^a"
                           +"%^CYAN%^ss %^RESET%^%^RED%^and displaying"
                           +" %^MAGENTA%^st%^BLUE%^r%^MAGENTA%^an"
                           +"%^BLUE%^g%^MAGENTA%^e %^RED%^and %^BOLD%^"
                           +"%^GREEN%^w%^RESET%^%^GREEN%^o%^BOLD%^"
                           +"%^GREEN%^ndr%^RESET%^%^GREEN%^ou%^BOLD%^"
                           +"%^GREEN%^s%^RESET%^%^RED%^ items from around"
                           +" the Realms.",
({ "chest", "chests"}): "%^ORANGE%^A number of %^BOLD%^%^BLACK%^ir"
                       +"%^RESET%^o%^BOLD%^%^BLACK%^n bound%^RESET%^"
                       +"%^ORANGE%^ treasure chests line walls, in"
                       +" amongst the general piles of valuables.",

({ "mosaic", "rune"}): "%^YELLOW%^The %^RESET%^%^GREEN%^r%^BOLD%^%^GREEN"
                      +"%^u%^RESET%^%^GREEN%^ne%^YELLOW%^ in the ceiling"
                      +" is picked out in the centre of a more general"
                      +" %^RESET%^%^CYAN%^m%^ORANGE%^o%^RESET%^s%^ORANGE"
                      +"%^a%^RESET%^i%^CYAN%^c %^YELLOW%^pattern. If you"
                      +" know about such things, you might be able to"
                      +" decipher the rune.",

({ "pile", "piles", "wealth"}):"Gems and jewelry are scattered amongs"
                              +" piles of coins, with paintings, statues"
                              +" and art treasures dotted in amongst the"
                              +" general wealth"

  ]) );

  set_search("cabinet", (:TO, "search_cabinets":) );
  set_search( "cabinets",(:TO, "search_cabinets":) );
  set_search("chest", (:TO, "search_chests":) );
  set_search("chests", (:TO, "search_chests":) );
  set_search("pile", (:TO, "search_piles":) );
  set_search("piles", (:TO, "search_piles":) );

  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("indoors",1);
  set_property("light",2);
  set_smell("default","The air smells of money");
  set_listen("default","You can hear your own breathing, and the"
                      +" occasional chink of a coin.");

 set_exits( ([
        "out":TUNNELS+ "d_cauldron",
    ]) );
  if (time() > TREASURY_D->last_hoard()+DAY) {
    make_hoard();
    TREASURY_D->set_last_hoard(time());
  }
}

void init(){
  ::init();
  add_action("decipher", "decipher");
}

string long_desc(){
  return    "%^BOLD%^%^YELLOW%^Br%^BOLD%^%^WHITE%^i%^YELLOW%^ght"
           +" l%^BOLD%^%^WHITE%^i%^YELLOW%^ghts and gleaming %^BOLD%^"
           +"%^WHITE%^white marble%^YELLOW%^ surfaces assault your eyes"
           +" here. The l%^BOLD%^%^WHITE%^i%^YELLOW%^ghts come from"
           +" %^BOLD%^%^BLACK%^black iron lanterns%^BOLD%^%^YELLOW%^"
           +" hanging on the walls, and the walls, floor and table tops"
           +" are all faced in the polished marble. The ceiling bears a"
           +" %^RESET%^%^CYAN%^m%^ORANGE%^o%^RESET%^s%^ORANGE%^a"
           +"%^RESET%^i%^CYAN%^c %^BOLD%^%^YELLOW%^pattern of a single,"
           +" elaborate %^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^u%^RESET%^"
           +"%^GREEN%^ne%^BOLD%^%^YELLOW%^. A number of tall display"
           +" cabinets hold various items of worth, and there are a"
           +" couple of large, intriguing looking chests on the floor. A"
           +" considerable amount of w%^RESET%^%^ORANGE%^ea%^BOLD%^"
           +"%^YELLOW%^lth is stored here.";
}

void reset()
{
  ::reset();
  if (!present("wand",TO)&&!present("staff",TO)  &&!present("instrument",TO)
       && !present("boots",TO) && !present("phylactery",TO) && time() > TREASURY_D->last_hoard()+DAY)
  {
    make_hoard();
    TREASURY_D->set_last_hoard(time());
  }
}

void make_hoard()
{
  object ob;
  piles_searched = 0;
  cabinets_searched = 0;
  chests_searched = 0;

  ob = new("/std/obj/coins");
  ob->set_money("gold",5000 + random (5000));
  ob->set_money("platinum",2000 + random (3000));
  ob->move(TO);
  last_hoard = time();
}

int decipher(string str){
  int skill, diff;
  if (!str){return notify_fail("decipher what?");}
  if (str!="rune" && str !="the rune"&&str!="mosaic"){
    return notify_fail("decipher what?");
  }
  // Check to see if the person can decipher the rune (code robbed from
  // scroll.c
  if (interactive(TP)){
      skill = TP->query_skill("spellcraft");
      diff = 7+(9*3);
      if (!TP->is_class("mage")&&!TP->is_class("bard")
             &&!wizardp(TP)    &&!TP->is_class("thief")){
        tell_object(TP, "You don't have the training to read it. Maybe"
          +" if you'd worked harder in school...");
        return 1;
      }
      if((skill+roll_dice(1,20)) >= diff) {
        tell_object(TP,"The rune says, very simply, %^BOLD%^%^GREEN%^'M"
                  +"%^RESET%^%^ORANGE%^i%^YELLOW%^ne'%^RESET%^");

      return 1;
    }
  }
  tell_object(TP, "You don't have the training to read it!");
}

int search_chests()
{
  object ob;
  int i;
  if (!objectp(TO)){return 0;}
  if (chests_searched>2) {
    tell_object(TP,"You don't find anything in the chests this time.");
    tell_room(TO, TPQCN + " searches through the chests but doesn't seem"
                  +" to find anything of interest",TP);
    return 0;
  }
  i = random(sizeof(MUSICALS));
  switch(random(6)){
  case 0:
    ob = new(OBJ+"r_wand");
    break;
  case 1:
    ob = new(INSTRUMENT+MUSICALS[i]);
    break;
  case 2:
    ob = new("/d/common/obj/rand/cloak");
    break;
  case 3:
    ob = new(OBJ+"satchel");
    break;
  case 4:
    ob = new(OBJ+"devil_pants");
    break;
  case 5:
    ob = new(OBJ+"bracelets_o_c");
    break;
  }
  ob->move(TO);
  if (objectp(ob)){
    tell_object(TP,"You find a "+ ob->query_short() + " in one of the"
                  +" chests!");
    tell_room(TO,TPQCN + " pulls a  "+ ob->query_short() + " out from one"
                        +" of the chests!",TP);
  }
  chests_searched++;
}

int search_cabinets()
{
  object ob;
  if (!objectp(TO)||!objectp(TP)){return 0;}
  if (cabinets_searched>2) {
   tell_object(TP,"The most interesting items seem to have been taken"
                 +" from the cabinets already");
   tell_room(TO, TPQCN + " searches through the cabinets but doesn't seem"
                +" to find anything of interest",TP);
   return 0;
  }
  switch(random(15)){
    case 0:
      ob = new(OBJ+"magestaff");
      break;
    case 1..2:
      ob = new(OBJ+"serrated_glaive");
      break;
    case 3..4:
      ob = new(OBJ+"hobnail_boots");
      break;
    case 5..6:
      ob = new(OBJ+"firewhip");
      break;
    case 7..8:
      ob = new (OBJ+"statue");
      break;
    case 9..10:
      ob = new (OBJ+"scythe_of_gathering");
      break;
    case 11..12:
      ob = new (OBJ+"spiked_banded");
      break;
    case 13:
      ob = new(OBJ+"bane_chess");
      ob->move(TO);
      break;
    case 14:
      ob = new(OBJ + "circlet_of_c");
      break;
  }
 ob->move(TO);

  if (objectp(ob)){
    tell_object(TP,"You find a "+ ob->query_short() + " in one of the"
                  +" cabinets!");
    tell_room(TO,TPQCN + " looks through the display cabinets and finds "
                        + ob->query_short() + "!", TP);
  }

  cabinets_searched++;
}


int search_piles()
{
  object ob;
  if (!objectp(TO)||!objectp(TP)){return 0;}
  if (piles_searched>2) {
   tell_object(TP,"The choice things have been taken from the piles"
                 +" already");
   tell_room(TO, TPQCN + " searches through the piles of coin but doesn't"
                +" seem to find anything of interest",TP);
   return 0;
  }
  switch(random(10)){
    case 0..5:
      ob = new(OBJ+"gem");
       break;
    case 6..7:
      ob = new(OBJ+"statue");
      break;
    case 8:
      ob = new(OBJ+"bane_chess");
      break;
    case 9:
      ob = new (OBJ+"scythe_of_gathering");
      break;
  }
  if (objectp(ob)){
    ob->move(TO);
    tell_object(TP,"You find a "+ ob->query_short() + " in one of the"
                  +" piles of treasure!");
    tell_room(TO,TPQCN + " rummages through the piles of wealth and finds"
                        +" a "  + ob->query_short() + "!", TP);
  }
  piles_searched++;
}
