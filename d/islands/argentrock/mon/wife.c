//Wife of the elven leader, questgiver eventually -- Yves
#include <std.h>
#include "../argabbr.h"
inherit NPC;

void create() {
    ::create();
    set_id(({
        "ivesa",
        "torellios",
        "ivesa torellios"
    }));
    set_name("Ivesa");
    set_short("%^BOLD%^%^RED%^Ivesa Torellios, a lithe %^MAGENTA%^female%^RED%^ elf with %^GREEN%^emerald%^RED%^ eyes and "
        "%^YELLOW%^golden%^RED%^ hair%^RESET%^");
    set_long((:TO,"long_desc":));
    set_hd(35,10);
    set("aggressive", 0);
    set_level(35);
    set_gender("female");
    set_class("fighter");
    set_mlevel("fighter", 35);
    set_guild_level("fighter",35);
    set_alignment(4);
    set_race("elf");
    add_money("gold", random(25));
    set_body_type("elf");
    set_mob_magic_resistance("low");
    set_overall_ac(-20);
    set_stats("strength",19);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("dexterity",19);
    set_stats("constitution",17);
    set_stats("charisma",16);
    set_max_hp(350+random(50));
    set_hp(query_max_hp());
    set_exp(100);
    set_property("swarm",0);
    force_me("speech intone with a harmonic inflection");
}

string long_desc(){
    return
        "%^GREEN%^Ivesa is small even as %^MAGENTA%^elves%^GREEN%^ go, but her size does not diminish "
        "her aura of %^CYAN%^confidence%^GREEN%^. Her smooth %^ORANGE%^olive skin%^GREEN%^ is without "
        "blemish and almost appears to be %^YELLOW%^glowing%^RESET%^%^GREEN%^ when the light catches "
        "it. She has large %^BOLD%^green eyes%^RESET%^%^GREEN%^ that seem to bore into the very "
        "center of your %^BOLD%^%^BLACK%^soul%^RESET%^%^GREEN%^, but nothing about it strikes you as evil "
        "in the slightest. Her hair is the color of the %^YELLOW%^morning sun%^RESET%^%^GREEN%^, and "
        "it spills gloriously to the small of her back in flowing %^BLUE%^waves%^GREEN%^. "
        "She wears a sleeveless forest green gown that %^MAGENTA%^hugs%^GREEN%^ every "
        "contour of her %^RED%^lithe%^GREEN%^ frame, and a wreath of %^RED%^red%^GREEN%^ and %^BOLD%^%^GREEN%^green%^RESET%^%^GREEN%^ "
        "leaves adorns her head.%^RESET%^";
}

void catch_say(string msg){
  ::catch_say(msg);
  if(interactive(TP)) {
    if(strsrch(msg,"ello") != -1 || strsrch(msg,"reeting") != -1) {
      call_out("response",1,TP);
    }
  }
}

void response(object live) {
  if(!objectp(live)) return;
  force_me("say Greetings traveller. Our efforts to retake this forest "+
    "from the cursed Fey'ri are underway and we are currently trying to "+
    "collect and destroy as many of their demonic armements as possible. "+
    "Bring such objects of evil to me and a more fitting armament will "+
    "be provided.");
}

void receive_given_item(object obj) {
  string name, *ids;
  object obj2;

  if(!objectp(obj) || !objectp(TP) || !objectp(ETO)) return;
  switch(obj->query_name()){
    case "jet scythe": // => pearl sword
      if(obj->query_size() == 3) obj2 = new(OBJ+"pearl_2hsword");
      else obj2 = new(OBJ+"pearl_longsword");
      trade_em(obj, obj2);
      break;
    case "demon claws": // => lightblade
      obj2 = random(2) ? new(OBJ+"feline_lblade") : new(OBJ+"serpent_lblade");
      trade_em(obj, obj2);
      break;
    case "leather coil": // => thinblade
      obj2 = random(2) ? new(OBJ+"leaf_tblade") : new(OBJ+"vine_tblade");
      trade_em(obj, obj2);
      break;
    case "demon's tail whip": // => electrified longknife
      obj2 = new(OBJ+"elec_knife");
      trade_em(obj, obj2);
      break;
    case "blade of the tortured soul": // => diamond star
        obj2 = new(OBJ+"diamond_star");
        trade_em(obj, obj2);
        break;
    case "raven plate": // => lion plate
        obj2 = new(OBJ+"lion_plate");
        trade_em(obj, obj2);
        break;
    case "watcher glaive": // => hey halberd
        obj2 = new(OBJ+"feyhalberd");
        trade_em(obj, obj2);
        break;
    case "bloodstone amulet": // => moonstone amulet
        obj2 = new(OBJ+"moon_amulet");
        trade_em(obj, obj2);
        break;
    default:
      ids = obj->query_id();
      force_me("say We have no need of this item.\n");
      force_me("drop "+ids[0]);
      break;
  }
}

void trade_em(object obj, object obj2) {
  int ench;
  if(!objectp(obj) || !objectp(obj2)) return;
  if(!objectp(TP) || !objectp(ETO)) return;

  force_me("say This is an evil armament of the Fey'ri. Thank you for "+
    "bringing it to me to be destroyed.\n");

  force_me("emoteat ivesa %^GREEN%^$M whispers a quiet prayer and one of "+
    "the %^ORANGE%^branches%^GREEN%^ envelops the "+obj->query_name()+" and "+
    "it is gone!%^RESET%^\n");
  obj->remove();

  force_me("say For the help in seeing such an object of evil destroyed, I "+
    "give you this "+obj2->query_name()+" of our own making.\n");

  ench = (int)obj2->query_property("enchantment");
  if(ench < 0) { // no cursed items allowed!
    obj2->remove_property("enchantment");
    obj2->set_property("enchantment", (ench * -1));
  }
  if((int)obj2->move(TP) != 0) {
    obj2->move(ETO);
    force_me("emote sets the "+obj2->query_name()+" down.");
  }
  else {
    obj2->move(TP);
    force_me("emoteat "+TPQN+" hands the "+obj2->query_name()+" to $N.");
  }
}
