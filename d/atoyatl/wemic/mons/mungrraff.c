//Mungraff.c The Wemic Hunter                                
// Coded by Lujke 07/09/2017
#include <std.h>
#include <daemons.h>
#include "../../tecqumin/tecqumin.h"
inherit MOB + "QNPC.c";

void set_responses();

void create(){
   ::create();
   set_name("Mungrraff, the Wemic Hunter");
   set_id( ({"mungrraff","hunter","wemic hunter", "wemic"}) );
   set_short("Mungrraff, the Wemic Hunter");
   set_long("%^RESET%^This hardy female %^ORANGE%^wemic%^RESET%^"
     +" is surrounded by birds and small animals. A young"
     +" %^ORANGE%^warthog%^RESET%^ dashes excitedly back and"
     +" forth between her feet, and a number of"
     +" %^BOLD%^%^BLUE%^co%^YELLOW%^lou%^RED%^rf%^GREEN%^ul"
     +" %^RED%^pa%^YELLOW%^rro%^BLUE%^ts%^RESET%^ flit"
     +" between perches on nearby %^GREEN%^trees%^RESET%^"
     +" and resting on the %^ORANGE%^wemic's%^RESET%^ back and"
     +" shouders. Mungrraff herself is lithe and fit-looking."
     +" Both %^BOLD%^%^YELLOW%^human%^RESET%^ and%^ORANGE%^"
     +" lion%^RESET%^ limbs are powerfully muscled, and the"
     +" abdominal muscles of her human torso are clearly"
     +" visible beneath the %^GREEN%^cropped leather"
     +" jerkin%^RESET%^ she wears. Her face has a broad,"
     +" high-cheekboned shape, reminiscent of the"
     +" %^CYAN%^Senzokuan%^RESET%^, and her alert"
     +" %^BOLD%^%^YELLOW%^yellow"
     +" e%^BOLD%^%^BLACK%^y%^YELLOW%^es%^RESET%^ have catlike"
     +" vertical pupils. She carries a %^ORANGE%^bow%^RESET%^"
     +" slung over one shoulder and a %^GREEN%^quiver of arrows"
     +"%^RESET%^ over the other, and twin %^BOLD%^%^WHITE%^short"
     +" swords%^RESET%^ are strapped at her sides. An"
     +" arrangement of straps around her lion torso hold some"
     +" gear carrying containers, but you have a sense that it"
     +" might be unwise to refer to them as 'saddlebags'.");
   set_gender("female");
   set_race("wemic");
   set_alignment(8);
   set_max_hp(350);
   set_hp(query_max_hp());
   set_overall_ac(-45);
   set_class("ranger");
   set_mlevel("ranger",45);
   set_level(45);
   set_stats("wisdom",18);
   set_stats("strength",26);
   set_stats("constitution",26);
   set_stats("intelligence",15);
   set_stats("charisma",8);
   set_stats("dexterity",30);
   set_exp(60);
   set("aggressive",0);
   will_open = 1;
   set_responses();
   set_speed(1);
}

set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday"}), 
          ({"Hello therrre, visitor to ourr lands"}) );
  set_response(({"hello" }), 
          ({"Hello therrre, visitor to ourr lands"}) );
  set_response(({"good day"}), 
          ({"Hello therrre, visitor to ourr lands"}) );
  set_response(({ "gooday"}), 
          ({"Hello therrre, visitor to ourr lands"}) );
  set_response(({"tabaxi"}), ({"Thee tabaxi are ourr cousins, in"
    +" a way. They arre catfolk, and they live in the most"
    +" northerrnn rreaches of the jungle. Tell them I said"
    +" hello, if you visit." }) );
  set_response(({"parrot"}), ({"The bright birds keep me company,"
    +" with theirr colourr  and theirr chatterr. Tell me if you"
    +" would like to %^GREEN%^take a frriend%^RESET%^ forr"
    +" yourrself..." }) );
  set_response(({"god"}), ({"I don't know anything about any gods."
    +" I did once see a %^BOLD%^%^GREEN%^trree spirit%^RESET%^, in"
    +" the eastern parrt of the jungle, between the city and the"
    +" riverr. But I think it wasn't very well."}));

  set_response(({"fountain of youth", "fountain"}), ({"Ah yes, the %^ORANGE%^legends%^RESET%^ say that the
%^BOLD%^%^YELLOW%^f%^BLUE%^ou%^CYAN%^nt%^BLUE%^a%^WHITE%^i%^CYAN%^n of
%^YELLOW%^y%^WHITE%^o%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^th%^RESET%^ is somewhere in the
%^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^,
though I never heard where. It's supposed to be on an %^BOLD%^%^GREEN%^island%^RESET%^, though, so maybe
somewhere on the %^BOLD%^%^BLUE%^river%^RESET%^?"}));
  set_response(({"not very well"}), ({"The %^BOLD%^%^GREEN%^trree"
    +" spirit%^RESET%^ I saw was not very well. Not... rright in"
    +" the head, you know? Or brranches, I suppose."}));
  set_response(({"where"}), ({"Ummm,"}), "where_is");
  set_response(({"frriend", "chatterr", "colourr", "strangerr", 
    "currse", "ourr","morrtal", "dangerr","drrama","ropebrridge", 
    "hearrt" }), ({"You speak a strange tongue, strangerr."
     +" Therre's no need to try to sound like me" }) );
  set_response(({"take a friend", "get a parrot", "find a parrot",
    "obtain a parrot"}), ({"Therre is a trree, deep in the jungle,"
      +" wherre the soil makes the fruit grow ripe and ferment on"
      +" the grround. If you meet a parrot there when it has got"
      +" a little tipsy, perrhaps it will be yourr friend? Orr"
      +" perhaps you would rather purrchase one from me?" }) );
  set_response(({"jungle"}), ({"The jungle is a dangerrous place,"
    +" forr those who know not where to tread.", "Avoid the lost"
    +" city, for ghosts dwell there. And I felt a strrange presence"
    +" one time, in the far reaches, past the ropebrridge", "The"
    +" Tabaxi to the norrth can be friendly, but watch out forr the"
    +" filthy orogs", "There are other dangerrs too, though perhaps"
    +" less drramatic"  }) );
  set_response(({"lost city"}), ({"The lost city lies in the"
    +" hearrt of the jungle. A strrange place of ruined stone and"
    +" ancient currses. I stay away, lest the ghosts visit their"
    +" currses on me as well." }));
  set_response(({"orog"}), ({"The orog are ugly creatures. Like"
    +" orrcs, but biggerr, strongerr and much morre deadly.", 
     "They have the same grreed and lust forr warr, too."})); 
  set_response(({"other dangers"}), ({"There are beasts in the"
    +" jungle, of course. Some arre fierce and some hunt humanoid"
    +" prrey. Therre are orogs, too. Like orcs of other lannds,"
    +" but bigger, fiercerr and strongerr" }));
  set_response(({"curse"}), ({"The %^BLUE%^dead%^RESET%^ do not"
    +" stay on the land, nor theirr %^CYAN%^spirits%^RESET%^ walk"
    +" in the %^BOLD%^%^YELLOW%^s%^WHITE%^u%^YELLOW%^nl%^WHITE%^i"
    +"%^YELLOW%^ght%^RESET%^, lest some currse rests upon them."
    +" In the lost city of the %^CYAN%^Tecqumin%^RESET%^, it is"
    +" said that ghosts walk abroad, and everr do they seek"
    +" morrtal souls to join them. But I do not know what the"
    +" currse that lays upon them is." }));
  set_response(({"lands", "our lands", "your lands"}), ({"This"
    +" place is known as Atoyatl Tepexitl. Not a Wemic name, but"
    +" we live just in thees corrner. Ourr village by the lake is"
    +" small, but the land is larrge" }));
  set_response(({"large land", "Atoyatl Tepexitl", "land is large"}), 
    ({"The jungle lies beyond ourr village", "It is too dangerous"
     +" forr us to travel farr" }));
  set_response(({"warthog"}), ({"My little hog frriend here was adopted"
    +" afterr he lost his motherr.", "He is cute, but he has"
    +" biggerr and morre aggressive cousins in the jungle"}) ) ;
  set_response(({"ropebridge"}), ({"The ropebrridge farr to the"
    +" norrtheast leads across a canyon. I do not know what, but"
    +" something bad is in that parrt of the jungle", "Also,"
    +" trry not to fall in the waterr", "It takes ages to drry"
    +" yourr furr" }));
  set_response(({"purchase one", "buy one", "buy a parrot", 
    "purchase a parrot", "buy parrot", "purchase parrot"}), 
    ({"I can sell you a parrot, if you want one"}), "sell"); 
}

void buy_parrot(string str){
  int gold, platinum, silver, owed;
  object parrot;
  if (str != "yes")
  {
    tell_object(TP, "You decide against buying the parrot");
    tell_room(ETO, TPQCN + " decides against buying the parrot", TP);
    return;
  }

  gold = TP->query_money("gold");
  platinum = TP->query_money("platinum");
  silver = TP->query_money("silver");
  owed = 25000;
  if (gold + (platinum*5) + (silver /10) < owed)
  {
    force_me("say Sorry, you don't have enough money there. I"
      +" only take gold, platinum or silver.");
    return;
  }
  if (platinum * 5 >= 25000)
  {
    TP->add_money("platinum", -5000);
    owed = 0;
  } else {
    TP->add_money("platinum", platinum*-1);
    owed -= platinum * 5;
  }
  if (gold >=owed){
    TP->add_money("gold", owed*-1);
    owed = 0;
  } else {
    TP->add_money("gold", gold*-1);
    owed -= gold * 5;
  }
  TP->add_money("silver", owed * -10);
  parrot = new (OBJ + "parrot");
  tell_object(TP, "Mungraff takes your money and gives you "
   + parrot->query_short() + ". She strokes its %^BOLD%^"
   +"%^BLUE%^f%^GREEN%^ea%^RED%^th%^GREEN%^er%^BLUE%^s%^RESET%^"
   +" as she hands it across, crooning slightly. She takes your"
   +" hand and guides you to stroke it gently in just the way it"
   +" seems to like. The %^BOLD%^%^BLUE%^p%^BOLD%^%^RED%^a"
   +"%^YELLOW%^rr%^RED%^o%^BLUE%^t%^RESET%^ warbles and rubs its"
   +" head against your fingers, seeming to accept you." );
  tell_room(ETO,  "Mungraff takes " + TPQCN + "%^RESET%^'s"
   +" money and gives " +TP->QO +" %^RESET%^" + parrot->query_short()
   + ". She strokes its %^BOLD%^%^BLUE%^f%^GREEN%^ea%^RED%^th"
   +"%^GREEN%^er%^BLUE%^s%^RESET%^ as she hands it across, crooning"
   +" slightly. She takes "+TPQCN+"%^RESET%^'s hand and guides "
   + TP->QO+" to stroke it gently in just the way it seems to like."
   +" The %^BOLD%^%^BLUE%^p%^BOLD%^%^RED%^a%^YELLOW%^rr%^RED%^o"
   +"%^BLUE%^t%^RESET%^ warbles and rubs its head against "+ TPQCN 
   +"%^RESET%^'s  fingers, seeming to accept "+TP->QO +".", TP );
  parrot->set_owner(TP->query_name());
  parrot->move(TP); 
}

void sell(object speaker){
  if (!objectp(speaker) || !objectp(ETO) || !present(speaker, ETO))
  {
    return;
  }
  force_me("say They are a bit hard to train, so I would"
    +" charge you 25000 gold if you want one. Do you want one?");
  force_me("emoteat " + speaker->query_name() + " looks at $N"
    +" questioningly");
  tell_object(speaker, "Type <yes> to buy a parrot, or anything"
    +" else to cancel");
  input_to("buy_parrot", 0);
}

void where(object speaker){
  string msg;
  msg = speaker->query_messages("say");
  if (!interact("where", msg))
  {
    msg = speaker->query_messages("whisper");
  }
  if (interact("atoyatl", msg))
  {
    force_me ("say You are here on the continnent of Atoyatl Tepexitl."
      +" It is the name of the whole place. We wemic live here in our"
      +" village round the lake. The jungle is much bigger, though."
      +" The Lost City is therre somewherre");
    return;
  }
  if (interact ("city", msg))
  {
    force_me("say The Lost City of the Tecqumin is deep in the jungle,"
      +" not easy to find. There is a village of the Tabaxi furrther"
      +" north. If you find them, you need to head south again.");
    return;
  }
  if (interact("lake", msg))
  {
    force_me("say The lake is by ourr village, nearr the hunting lodge");
  }
}

void heart_beat(){
  ::heart_beat();
  if (random(4)){
    set_speed(0);
  } else 
  {
    set_speed(1);
  }
}
